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

        public String Login(string username, string pwhash)
        {
            string rightUser = "user";
            string rightPw = "pw";
            if(username == rightUser && pwhash == rightPw)
            {
                CurrentUsersLoggedIn++;
                return Guid.NewGuid().ToString();
            }
            else
            {
                return "0";
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
