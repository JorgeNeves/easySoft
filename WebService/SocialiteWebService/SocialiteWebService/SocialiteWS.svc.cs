using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.ServiceModel.Web;
using System.Text;

namespace SocialiteWebService
{
    public class SocialiteWS : SocialiteOperations, WSMonitor
    {
        public String Login(string username, string pwhash)
        {
            string rightUser = "user";
            string rightPw = "pw";
            if(username == rightUser && pwhash == rightPw)
            {
                return Guid.NewGuid().ToString();
            }
            else
            {
                return "0";
            }
        }

        public String CheckStatus()
        {
            return "OK - WS Running";
        }
    }
}
