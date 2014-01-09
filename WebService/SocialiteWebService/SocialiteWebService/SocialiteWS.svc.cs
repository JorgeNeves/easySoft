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

        private int CurrentUsersLoggedIn;

        /* Efetua o login de um utilizador via REST utilizando uma username e password
         * Em caso de sucesso é incrementado o valor de numero de utilizadores a utilizar a API 
         * de acesso a dados da rede social (ou seja, pessoas a utilizar o client)
         */
        public String Login(string username, string password)
        {
            string rightUser = "user";
            string rightPw = "pw";
            string hashed = EncryptionHelpers.MD5.GetHash(password);
            if(username == rightUser && password == rightPw)
            {
                CurrentUsersLoggedIn++;
                return Guid.NewGuid().ToString();
            }
            else
            {
                return hashed;
            }
        }

        public String Logout(string username)
        {
            if(CurrentUsersLoggedIn > 0)
            {
                CurrentUsersLoggedIn--;
                return "OK";
            }
            else
            {
                return "ERROR";
            }
        }

        public String CheckStatus()
        {
            return "OK - WS Running";
        }

        public int CurrentOnlineUsers()
        {
            return CurrentUsersLoggedIn;
        }

    }
}
