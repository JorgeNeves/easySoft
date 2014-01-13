using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using System.Configuration;
using System.Windows.Forms;
using System.IO;

namespace LoginClient
{
    class LoginClientController
    {
        private string token;
        public bool isLogged { get; set; }
        public LoginClientController()
        {
            token = null;
            isLogged = false;
        }

        public void Login(string username, string password)
        {
            WebClient wc = new WebClient();
            string Uri = "/login?user=" + username + "&pw=" + password;
            string result = wc.DownloadString(ConfigurationManager.AppSettings["WebServiceUrl"] + Uri);
            token = result.Substring(1, result.Length - 2); // remover as aspas iniciais e finais
            if (token == "fail")
            {
                throw new Exception("The username or password were incorrect.");
            }
            isLogged = true;
            try
            {
                SaveToken();
            }
            catch(Exception)
            {
                Logout();
            }
        }

        public void Logout()
        {
            WebClient wc = new WebClient();
            string Uri = "/logout/" + token;
            string result = wc.DownloadString(ConfigurationManager.AppSettings["WebServiceUrl"] + Uri);
            if (result == "\"fail\"")
            {
                throw new Exception("Could not logout.");
            }
            isLogged = false;
        }

        private void SaveToken()
        {
            // %AppData%\SocialiteData\token.cfg
            string datadir = Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData) + "\\";
            datadir += ConfigurationManager.AppSettings["DataDir"];
            StreamWriter writer = new StreamWriter(datadir + "token.cfg");
            writer.WriteLine(token);
            writer.Close();
        }

        public void SafeClose()
        {
            if(isLogged)
                Logout();
        }
    }
}
