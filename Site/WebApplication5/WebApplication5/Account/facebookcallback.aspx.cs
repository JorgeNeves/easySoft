using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

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
                    string json = oAuth.WebRequest(oAuthFacebook.Method.GET, url, String.Empty);
                    Response.Write(json);
                }
            }
        }
    }
}