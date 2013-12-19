using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using WebApplication2.TabelModel.BLL;

namespace WebApplication2.Account
{
    public partial class Login : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void Button1_Click1(object sender, EventArgs e)
        {
            Response.Redirect("Register.aspx");
        }

        protected void Button1_Click(object sender, EventArgs e){
        string user = UserTextBox.Text;
            string pass = PassTextBox.Text;
            int userID = Users.verifyuser(user, pass);
            if (userID != -1)
            {
                //string type = Users.userType(user);
                string type = "normal";
                Session["userID"] = userID;
                Session["username"] = user;
                Session["userType"] = type;
                if (type.Equals("normal")) { Response.Redirect("~/Profile/Profile.aspx"); }
               
                
            }else { ErroLoginLabel.Visible = true; }

        }
    }
}