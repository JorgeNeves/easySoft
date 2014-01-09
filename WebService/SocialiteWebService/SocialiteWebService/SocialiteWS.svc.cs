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
         */
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
         */
        public String Logout(string token)
        {
            if(LoggedUsers.ContainsKey(token))
            {
                LoggedUsers.Remove(token);
                return "Logged out";
            }
            return "Logout failed";
        }

        public String CheckStatus()
        {
            return "OK - WS Running";
        }

        public int NumLoggedUsers()
        {
            return LoggedUsers.Count;
        }

    }
}
