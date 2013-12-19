using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using WebApplication2.TabelModel.BLL;

namespace WebApplication2.Account
{
    public partial class Register : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            string username=TextBox1.Text;
            string password = TextBox2.Text;
            string password2 = TextBox3.Text;
            string mail = TextBox4.Text;
            if (password == password2)
            {
                bool done = Users.InsereUtilizador(username, password,mail);
                if (done == false)
                {
                    TextBox3.Text = "";
                    TextBox2.Text = "";
                    Label1.Text = "Utilizador ja existe!";
                }
                else {
                    TextBox3.Text = "";
                    TextBox2.Text = "";
                    Label1.Text = "Registado com sucesso!";

                }
            }
            
        }

        protected void TextBox4_TextChanged(object sender, EventArgs e)
        {
        
        }
        }
    }
