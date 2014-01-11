using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.ServiceModel.Web;
using System.Text;

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
            return "Login failed";
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
                return "Logged out";
            }
            return "Logout failed";
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
                        Usertags = null,//db.User_Tag.Where(t => t.User_TagID == user.UserID).Select(s => s.ToString()).ToList(),
                        UserFriendsIDs = null,//db.Ligacaos.Where(l => l.User1ID == user.UserID).Select(u => u.User2ID).ToList()
                    };
                    //ud.UserFriendsIDs.AddRange(db.Ligacaos.Where(l => l.User2ID == user.UserID).Select(u => u.User1ID).ToList());

                    return ud;
                }
            }
            return null;
        }

    }
}
