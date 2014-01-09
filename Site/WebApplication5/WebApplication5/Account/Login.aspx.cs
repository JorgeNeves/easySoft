using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using WebApplication5.TabelModel.BLL;


namespace WebApplication5.Account
{
    public partial class Login : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            string user = TextBox1.Text;
            string pass = TextBox2.Text;
            int userID = Users.verifyuser(user, pass);
            if (userID != -1)
            {
                //string type = Users.userType(user);
                string type = "normal";
                Session["userID"] = userID;
                Session["username"] = user;
                Session["userType"] = type;
                Application.Lock();
                Application["UsersOnline"] = (int)Application["UsersOnline"] + 1;
                Application.UnLock();
                if (type.Equals("normal")) { Response.Redirect("~/Profile/Profile.aspx"); }
               
                
            }else { Label3.Visible = true; }

        }
        }
    }
