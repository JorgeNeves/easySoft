﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.ServiceModel.Web;
using System.Text;
using System.Configuration;
using SocialiteWebService.TabelModel.BLL;
using System.Data;
using System.Collections;

namespace SocialiteWebService
{
    [ServiceBehavior(InstanceContextMode = InstanceContextMode.Single)]
    public class SocialiteWS : SocialiteOperations
    {
        private easysoftdbEntities db = new easysoftdbEntities();
        private Dictionary<string, Users> LoggedUsers = new Dictionary<string, Users>();

        /* Efetua o login de um utilizador via REST utilizando uma username e password
         * Em caso de sucesso é incrementado o valor de numero de utilizadores a utilizar a API 
         * de acesso a dados da rede social (ou seja, pessoas a utilizar o client).
         * Verifica se um utilizador se encontra na base de dados, caso contrário, a verificação devolve null 
         * e o login falha. Caso sucesso, verifica a password. Se sucesso, cria um access token,
         * e guarda o utilizador num dicionario de token|utilizador para controlo de acessos.
         * o uri é /login?user=[username]&pw=[password]
         */
        [WebInvoke(Method = "GET", ResponseFormat = WebMessageFormat.Json, UriTemplate = "/login?user={username}&pw={password}")]
        public String Login(string username, string password)
        {
            Users user = db.Users.FirstOrDefault(u => u.Nick == username);
            if(user != null && user.Password == password)
            {
                string token =  Guid.NewGuid().ToString();
                LoggedUsers.Add(token, user);
                return token;
            }
            return "fail";
        }

        /* Efetua logout de um utilizador via token. Caso token se encontre no dicionario de utilizadores
         * ligados, remove o utilizador da lista, bloqueando o seu acesso sem proceder a um novo login
         * a fim de obter um novo token.
         * O URI é /logout/[token do utilizador]
         */
        [WebInvoke(Method = "GET", ResponseFormat = WebMessageFormat.Json, UriTemplate = "/logout/{token}")]
        public String Logout(string token)
        {
            if(LoggedUsers.ContainsKey(token))
            {
                LoggedUsers.Remove(token);
                return "ok";
            }
            return "fail";
        }

        /* Devolve o estado do serviço em Json, contendo o estado do mesmo, utilizadores totais
         * e numero de utilizadores ligados.
         * Uri é /status
         */
        [WebInvoke(Method = "GET", ResponseFormat = WebMessageFormat.Json, UriTemplate = "/status")]
        public ServiceStatus Status()
        {
            ServiceStatus payload =
                new ServiceStatus()
                {
                    Status = "OK",
                    TotalUsers = db.Users.Count(),
                    OnlineUsers = LoggedUsers.Count
                };
            return payload;
        }

        /* Devolve os dados relativos ao utilizador, incluindo nome, estado de espirito, tags e IDs dos seus amigos
         * 
         */
        [WebInvoke(Method = "GET", ResponseFormat = WebMessageFormat.Json, UriTemplate = "/userdata?id={userid}&token={token}")]
        public UserData GetUserData(int userid, string token)
        {
            if (LoggedUsers.ContainsKey(token) || token == "debug")
            {
                Users user = db.Users.FirstOrDefault(u => u.UserID == userid);
                if(user != null)
                {
                    UserData ud = new UserData()
                    {
                        UserID = user.UserID,
                        UserName = user.PrimeiroNome + " " + user.PrimeiroNome,
                        UserMood = db.EstadoDeHumors.FirstOrDefault(eh => eh.EstadoDeHumorID == user.EstadoDeHumorID).Sentimento,

                        // para todas as user_tags do utilizador, juntar a tabela de tags, ir buscar o campo Palavra (nome da tag)
                        // estado de ligação == 1 pedido de amizade, == 2 ja sao amigos
                        Usertags = (from usertag in db.User_Tag
                                    join tag in db.Tags on usertag.TagID equals tag.TagID
                                    where usertag.UserID == user.UserID
                                    select tag.Palavra).ToList(),
                        // para todas as ligacoes em que o User1 e o utilizador atual, ir buscar o ID do User2 (o amigo)
                        UserFriendsIDs = (from lig in db.Ligacaos
                                          where lig.User1ID == user.UserID && lig.EstadoDaLigacaoID == 2
                                          select lig.User2ID).ToList()
                    };
                    // o mesmo que o de cima, mas no sentido contrario
                    ud.UserFriendsIDs.AddRange((from lig in db.Ligacaos
                                                where lig.User2ID == user.UserID && lig.EstadoDaLigacaoID == 2
                                                select lig.User1ID).ToList());
                    return ud;
                }
            }
            return null;
        }

        [WebInvoke(Method = "GET", ResponseFormat = WebMessageFormat.Json, UriTemplate = "/userdata/{token}")]

        /*
         * Devolve os dados do utilizador loggado atualmente. 
         * FIXME: por isto tudo num controlador de backend.
         */ 
        public UserData GetCurrentUserData(string token)
        {
            if(LoggedUsers.ContainsKey(token))
            {
                Users current = LoggedUsers[token];
                return GetUserData(current.UserID, token); // grrrrrrrr :S
            }
            return null;
        }

        /* Devolve uma palavra gerada pelo servico de Prolog que controla o minijogo Enforcado
         * (a pedido do Sr. Neves :D)
         */

        private string GetWordAndCategory(){
            WebClient webClient = new WebClient();
            string reply = webClient.DownloadString(ConfigurationManager.AppSettings["HangmanGamePrologServiceUrl"]);
            return reply;
        }

        [WebInvoke(Method = "GET", ResponseFormat = WebMessageFormat.Json, UriTemplate = "/hangman/newword/")]
        public string GetWord()
        {
            string reply = GetWordAndCategory();
            return reply;
        }

        [WebInvoke(Method="GET",ResponseFormat=WebMessageFormat.Json,UriTemplate="/HttpAccess")]
        public string GetAccessState()
        {
            try
            {
            HttpWebRequest myHttpWebRequest = (HttpWebRequest)WebRequest.Create(ConfigurationManager.AppSettings["HttpaccessURL"]);

            // Get the associated response for the above request.
            HttpWebResponse myHttpWebResponse = (HttpWebResponse)myHttpWebRequest.GetResponse();
            myHttpWebResponse.Close();
            
                //string respostahtml = wc.DownloadString(ConfigurationManager.AppSettings["HttpaccessURL"]);
            }
            catch(WebException e) {
                if (e.Status == WebExceptionStatus.ProtocolError)
                {
                   return e.Message;
                   
                }
            }
            return "OK";   
        }

        [WebInvoke(Method = "GET", ResponseFormat = WebMessageFormat.Json, UriTemplate = "/downloads")]
        public string GetDownloads()
        {
            WebClient webClient = new WebClient();
            
            string respostahtml = webClient.DownloadString(ConfigurationManager.AppSettings["DownloadServiceUrl"]);
        

            string sstart="<span id=\"lbldowns\">";
            int start = respostahtml.IndexOf(sstart,0)+sstart.Length;
            int end = respostahtml.IndexOf("</span>",start);
            string reply=respostahtml.Substring(start,end-start);
            return reply;
        }

        [WebInvoke(Method = "GET", ResponseFormat = WebMessageFormat.Json, UriTemplate = "/friends?id={userid}")]
        public string friends(int userid)
        {
            ArrayList ds= Services.suggestedFriends(userid);
            string cenas="";
            for(int i=0;i<ds.Count;i++){
                object o =ds[i];
                string nome=TabelModel.BLL.Users.getUserNick(Convert.ToInt32(o.ToString()));
                DataSet dt = TabelModel.BLL.Users.getUserTags(Convert.ToInt32(o.ToString()));
                cenas += "utilizador(" + nome + ",L[";
                for(int u=0;u<dt.Tables[0].Rows.Count;u++){
                    if (u == dt.Tables[0].Rows.Count - 1)
                    {
                        cenas += dt.Tables[0].Rows[u][0].ToString();
                    }
                    else
                    {
                        cenas += dt.Tables[0].Rows[u][0].ToString() + ",";
                    }
                    
                }
                cenas+="]).\n";
                   
            }
                // Write the string to a file.
                System.IO.StreamWriter file = new System.IO.StreamWriter("~/users.pl");
                file.WriteLine(cenas);

                file.Close();
            
            return cenas;
        }

    }
}
