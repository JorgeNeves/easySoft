using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using WebApplication2.TabelModel.BLL;
namespace WebApplication2.Profile
{
    public partial class Profile : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
           DataSet dt= Users.getUser(Session["username"].ToString());

           string Mail=dt.Tables[0].Rows[0][3].ToString();
           string FirstName = dt.Tables[0].Rows[0][4].ToString();
           string LastName = dt.Tables[0].Rows[0][5].ToString();
           string date = dt.Tables[0].Rows[0][6].ToString();
           string Pais = dt.Tables[0].Rows[0][7].ToString();
           int EstadoHumor = int.Parse(dt.Tables[0].Rows[0][8].ToString());
           string avatar = dt.Tables[0].Rows[0][9].ToString();
           string facebook = dt.Tables[0].Rows[0][10].ToString();
           string LinkedIn = dt.Tables[0].Rows[0][11].ToString();

           Label1.Text = Session["username"].ToString();
           Label2.Text = FirstName + " " + LastName;
           Label4.Text = Mail;
           Label5.Text = facebook;
           Label6.Text = LinkedIn;
           Label7.Text = LinkedIn;
            Image1.ImageUrl = avatar;

        }
    }
}