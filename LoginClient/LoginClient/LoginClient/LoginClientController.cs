using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using System.Configuration;
using System.Windows.Forms;

namespace LoginClient
{
    class LoginClientController
    {
        public LoginClientController()
        {

        }

        public string Login(string username, string password)
        {
            WebClient wc = new WebClient();
            string Uri = "/login?user=" + username + "&pw=" + password;
            string result = wc.DownloadString(ConfigurationManager.AppSettings["WebServiceUrl"] + Uri);
            result = result.Substring(1, result.Length - 2); // remover as aspas iniciais e finais
            return result;
        }
    }
}
