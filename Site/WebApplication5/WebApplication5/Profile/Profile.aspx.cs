using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using WebApplication5.TabelModel.BLL;
namespace WebApplication5.Profile
{
    public partial class Profile : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            DataSet dt = Users.getUser(Session["username"].ToString());

            string Mail = dt.Tables[0].Rows[0][3].ToString();
            string FirstName = dt.Tables[0].Rows[0][4].ToString();
            string LastName = dt.Tables[0].Rows[0][5].ToString();
            string date = dt.Tables[0].Rows[0][6].ToString();
            string Pais = dt.Tables[0].Rows[0][7].ToString();
            int EstadoHumor = int.Parse(dt.Tables[0].Rows[0][8].ToString());
            string avatar = dt.Tables[0].Rows[0][9].ToString();
            string facebook = dt.Tables[0].Rows[0][10].ToString();
            string LinkedIn = dt.Tables[0].Rows[0][11].ToString();

            Label2.Text = Session["username"].ToString();
            Label1.Text = FirstName + " " + LastName;
            Label3.Text = date;
            Label4.Text = Users.getEstado(EstadoHumor);
            Label5.Text = Mail;
            Label6.Text = facebook;
            Label7.Text = LinkedIn;
            Label8.Text = Pais;
            Image1.ImageUrl = avatar;
            int id=Users.getUserID(Session["username"].ToString());
            DataSet data=Relationships.checkPedidos(id);
            if (data != null)
            {
                Button2.Text="Pedidos Pendentes ("+data.Tables[0].Rows.Count+")";
            }
            DataSet ds=Relationships.checkAmigos(Convert.ToInt32(Session["userID"].ToString()));
            if (ds != null)
            {
                Label10.Text =""+ ds.Tables[0].Rows.Count;
            }
           
            
        }

        protected void LinkButton3_Click(object sender, EventArgs e)
        {

        }

        protected void LinkButton1_Click(object sender, EventArgs e)
        {

        }

        protected void LinkButton2_Click(object sender, EventArgs e)
        {

        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            Response.Redirect("EditProfile.aspx");
        }

        protected void Button2_Click(object sender, EventArgs e)
        {
            int id = Users.getUserID(Session["username"].ToString());
            DataSet data = Relationships.checkPedidos(id);
            if (data==null)
            {
                Label9.Visible = true;
            }
            else
            {
                Response.Redirect("Requests.aspx");
            }
           
        }
        
    }
}