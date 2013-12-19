using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using WebApplication5.TabelModel.BLL;
using System.Text.RegularExpressions;

namespace WebApplication5.Account
{
    public partial class Register : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            string username = TextBox1.Text;
            string Password = TextBox2.Text;
            string Password2 = TextBox3.Text;
            string firstname = TextBox4.Text;
            string lastname = TextBox5.Text;
            string birthday = TextBox8.Text;
            string country = TextBox7.Text;
            string mail = TextBox9.Text;

            if (Password != Password2 || Password==null || Password2 ==null)
            {
                Label2.Visible = true;
                Label3.Visible = true;
                return;
            }
            string regexPattern = @"^[A-Z0-9._%+-]+@[A-Z0-9.-]+\.[A-Z]{2,4}$";

            if (!new Regex(regexPattern, RegexOptions.IgnoreCase).IsMatch(mail))
            {
                Label9.Visible = true;
                return;
            }
            if (Users.verifyuser(username))
            {
                int erro = 0;
                if (country == null)
                {
                    Label7.Visible = true; erro = 1;
                }
                if (birthday == null)
                {
                    Label6.Visible = true; erro = 1;
                }
                if (lastname == null)
                {
                    Label5.Visible = true; erro = 1;
                }
                if (firstname == null)
                {
                    Label4.Visible = true; erro = 1;
                }
                if (erro == 1)
                {
                    return;
                }
                else
                {
                    Users.InsereUtilizador(username, Password, mail, firstname, lastname, birthday, country);
                    Label8.Visible = true;
                    Response.Redirect("~/Login.aspx");
                }
                
            }
            else
            {
                Label1.Visible = true;
                return;
            }
        }
    }
}