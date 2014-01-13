using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using Newtonsoft.Json;
using WebApplication5.TabelModel.BLL;
using System.IO;
using System.Net.Mail;
using System.Net;

namespace WebApplication5.Account
{
    public partial class facebookcallback : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            string url = "";
            oAuthFacebook oAuth = new oAuthFacebook();

            if (Request["code"] == null)
            {
                //Redirect the user back to Facebook for authorization.
                Response.Redirect(oAuth.AuthorizationLinkGet());
            }
            else
            {
                //Get the access token and secret.
                oAuth.AccessTokenGet(Request["code"]);

                if (oAuth.Token.Length > 0)
                {
                    //We now have the credentials, so we can start making API calls
                    url = "https://graph.facebook.com/me?access_token=" + oAuth.Token;
                    string data = "";
                    string json = oAuth.WebRequest(oAuthFacebook.Method.GET, url, data);
                    json = oAuth.convert(json);

                    var c = JsonConvert.DeserializeObject<Perfil>(json);

                    string primeiro_nome = c.first_name;
                    string ultimo_nome = c.last_name;
                    string pais = c.locale;
                    string facebook = c.link;
                    string username = c.username;
                    string mail = c.username + "@facebook.com"; 
                    string password = Path.GetRandomFileName();
                    password = password.Replace(".", "");
                    Users.InsereUtilizador(username, password, mail , primeiro_nome, ultimo_nome, "", pais);

                    // Gmail Address from where you send the mail
                    string fromAddress = "uvm054@gmail.com";
                    // any address where the email will be sending
                    const string fromPassword = "uvm054.dei";
                    string toAddress = mail;
                    // Passing the values and make a email formate to display
                    string subject = "Registo pelo Facebook";
                    string body = "Obrigado por se registar! \n";
                    body += "Utilizador: "+username+"\n";
                    body += "Password: "+password +"\n\n";
                    body += "Já pode fazer login e editar a sua informação pessoal! http://wvm054.dei.isep.ipp.pt\n";
                    


                    // smtp settings
                    var smtp = new System.Net.Mail.SmtpClient();
                    {
                        smtp.Host = "smtp.gmail.com";
                        smtp.Port = 587;
                        smtp.EnableSsl = true;
                        smtp.DeliveryMethod = System.Net.Mail.SmtpDeliveryMethod.Network;
                        smtp.Credentials = new NetworkCredential(fromAddress, fromPassword);
                        smtp.Timeout = 20000;
                    }
                    // Passing values to smtp object
                    smtp.Send(fromAddress, toAddress, subject, body);
                    Response.AddHeader("REFRESH", "5;URL=Login.aspx");
                }
            }
        }
    }
}