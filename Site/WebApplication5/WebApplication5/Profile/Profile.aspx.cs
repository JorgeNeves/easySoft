using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using WebApplication5.TabelModel.BLL;
using System.Net;
namespace WebApplication5.Profile
{
    public partial class Profile : System.Web.UI.Page
    {
        protected DataTable DynamicColumns()
        {
            // Define the new datatable
            DataTable dt = new DataTable();

            // Define 1 columns

            DataColumn dc;
            dc = new DataColumn("Name");
            dt.Columns.Add(dc);

            return dt;
        }
        protected void Page_Load(object sender, EventArgs e)
        {

            if (Session["userID"] == null) { Response.Redirect("~/Account/Login.aspx"); }

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
                int id = Users.getUserID(Session["username"].ToString());
                DataSet data = Relationships.checkPedidos(id);
                if (data != null)
                {
                    Button2.Text = "Pedidos Pendentes (" + data.Tables[0].Rows.Count + ")";
                }
                DataSet ds = Relationships.checkAmigos(Convert.ToInt32(Session["userID"].ToString()));
                if (ds != null)
                {
                    Label10.Text = "" + ds.Tables[0].Rows.Count;
                }

                preencher_usertags();
                preencher_relations_tags();
                WebClient wc = new WebClient();
                string result = wc.DownloadString("http://wvm054.dei.isep.ipp.pt/SocialLiteWS/SocialiteWS.svc/friends?id=" + Session["userID"].ToString());
                result = result.Replace("\"", "");

                amigosugeridos.Text = result;
            
        }
        protected void preencher_relations_tags()
        {
            int userID = (int)Session["userID"];
            DataSet ds = Users.getRelationsTags(userID);
            string temp = "";
            if (ds != null) { 
            foreach (DataRow data in ds.Tables[0].Rows)
            {

                foreach (object item in data.ItemArray)
                {
                    temp += "<u>" + item.ToString() + "</u> ";
                }

            }
            lblreltags.Text = temp;
            }
        }

        protected void preencher_usertags()
        {
            int userID = (int)Session["userID"];
            DataSet ds = Users.getUserTags(userID);

            string temp = "";
            if (ds != null)
            {

                foreach (DataRow data in ds.Tables[0].Rows)
                {

                    foreach (object item in data.ItemArray)
                    {
                        temp += "<u>" + item.ToString() + "</u> ";
                    }

                }
                lblusertags.Text = temp;
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