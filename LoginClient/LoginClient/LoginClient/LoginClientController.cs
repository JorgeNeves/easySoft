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
            try
            {
                string result = wc.DownloadString(ConfigurationManager.AppSettings["WebServiceUrl"] + Uri);
                return (result == "\"Login failed\"" ? null : result);
            }
            catch(Exception ex)
            {
                MessageBox.Show("Could not connect to login endpoint", "Critical Error", MessageBoxButtons.OKCancel, MessageBoxIcon.Error);
                return null;
            }
        }
    }
}
