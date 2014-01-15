using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using WebApplication5.TabelModel.BLL;
using System.Data;

namespace WebApplication5.Profile
{
    public partial class FriendProfile : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Session["userID"] == null) { Response.Redirect("~/Account/Login.aspx"); }

            if (!IsPostBack)
            {
                int id_profile = Users.getUserID(Request.QueryString["nome"]);
                int utilizador = Users.getUserID(Session["username"].ToString());

                if (Relationships.checkRelation(utilizador, id_profile))
                {
                    Button1.Visible = false;
                }
                else if (Session["username"].ToString() == Request.QueryString["nome"])
                {
                    Button1.Visible = false;
                    Response.Redirect("Profile.aspx");
                }

                string user = "";
                if (Request.QueryString["nome"] != null)
                {
                    user = Request.QueryString["nome"];
                }
                else
                {
                    user = Session["username"].ToString();
                }

                DataSet dt = Users.getUser(user);

                string Mail = dt.Tables[0].Rows[0][3].ToString();
                string FirstName = dt.Tables[0].Rows[0][4].ToString();
                string LastName = dt.Tables[0].Rows[0][5].ToString();
                string date = dt.Tables[0].Rows[0][6].ToString();
                string Pais = dt.Tables[0].Rows[0][7].ToString();
                int EstadoHumor = int.Parse(dt.Tables[0].Rows[0][8].ToString());
                string avatar = dt.Tables[0].Rows[0][9].ToString();
                string facebook = dt.Tables[0].Rows[0][10].ToString();
                string LinkedIn = dt.Tables[0].Rows[0][11].ToString();

                Label2.Text = user;
                Label1.Text = FirstName + " " + LastName;
                Label3.Text = date;
                Label4.Text = Users.getEstado(EstadoHumor);
                Label5.Text = Mail;
                Label6.Text = facebook;
                Label7.Text = LinkedIn;
                Label8.Text = Pais;
                Image1.ImageUrl = avatar;
            }
            
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            int id_profile= Users.getUserID(Request.QueryString["nome"]);
            int utilizador= Users.getUserID(Session["username"].ToString());

            Relationships.addRelation(utilizador, id_profile, 10, System.DateTime.Today.ToString());
            Label9.Visible = true;
            Button1.Visible = false;
        }
    }
}