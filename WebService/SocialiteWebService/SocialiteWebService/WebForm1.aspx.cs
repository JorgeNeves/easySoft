using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace SocialiteWebService
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void Button1_Click(object sender, EventArgs e)
        {
           ServiceReference1.SocialiteOperationsClient proxy = new ServiceReference1.SocialiteOperationsClient();
           string s =proxy.CompareWord("JOAO", "O");
           Label1.Text = s;
        }
    }
}