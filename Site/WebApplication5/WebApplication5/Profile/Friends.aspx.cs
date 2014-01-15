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
    public partial class Friends : System.Web.UI.Page
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

            if (!IsPostBack)
            {
                DataSet ds = Relationships.checkAmigos(Users.getUserID(Session["username"].ToString()));

                if (ds != null)
                {
                    GridView1.DataSource = ds.Tables[0];
                    GridView1.DataBind();
                }
                else
                {
                    Response.Redirect("Profile.aspx");
                }
                for (int i = 0; i < GridView1.Rows.Count; i++)
                {
                    GridViewRow gvRow = GridView1.Rows[i];


                    ((ImageButton)gvRow.Cells[2].Controls[0]).ImageUrl = gvRow.Cells[4].Text;


                    ((ImageButton)gvRow.Cells[2].Controls[0]).Width = 60;
                    ((ImageButton)gvRow.Cells[2].Controls[0]).Height = 60;
                    gvRow.Cells[4].Visible = false;


                }
                WebClient wc = new WebClient();
                string result = wc.DownloadString("http://localhost:7077/SocialiteWS.svc/friends?id=" + Session["userID"].ToString());
                result = result.Replace("\"", "").Trim();
                string[] amigos = result.Split(' ');
                DataTable datat = DynamicColumns();
                for (int i = 0; i < amigos.Length; i++)
                {
                    DataRow nrow = datat.NewRow();
                    nrow["Name"] = amigos[i].ToString();
                    datat.Rows.Add(nrow);

                }
                GridView2.DataSource = datat;
                GridView2.DataBind();


            }

        }

        protected void GridView1_RowDataBound(object sender, GridViewRowEventArgs e)
        {







        }

        protected void GridView1_RowCommand(object sender, GridViewCommandEventArgs e)
        {
            int index = Convert.ToInt32(e.CommandArgument);

            // Retrieve the row that contains the button clicked 
            // by the user from the Rows collection.
            GridViewRow row = GridView1.Rows[index];
            string nome = row.Cells[3].Text;
            int id = Users.getUserID(Session["username"].ToString());
            int id_friend = Users.getUserID(nome);
            if (e.CommandName == "Ver Perfil")
            {

                Response.Redirect("FriendProfile.aspx?nome=" + nome);
            }
            else if (e.CommandName == "Remover")
            {

                Relationships.deleteRequest(id, id_friend);
            }

            DataSet ds = Relationships.checkAmigos(Users.getUserID(Session["username"].ToString()));

            if (ds != null)
            {
                GridView1.DataSource = ds.Tables[0];
                GridView1.DataBind();
            }
            else
            {
                Response.Redirect("Profile.aspx");
            }
            for (int i = 0; i < GridView1.Rows.Count; i++)
            {
                GridViewRow gvRow = GridView1.Rows[i];

                ((ImageButton)gvRow.Cells[2].Controls[0]).ImageUrl = gvRow.Cells[4].Text;
                ((ImageButton)gvRow.Cells[2].Controls[0]).Width = 60;
                ((ImageButton)gvRow.Cells[2].Controls[0]).Height = 60;
                gvRow.Cells[4].Visible = false;
            }

        }

        protected void GridView1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        protected void GridView2_RowCommand(object sender, GridViewCommandEventArgs e)
        {

            
            if (e.CommandName == "butao")
            {
                int index = Convert.ToInt32(e.CommandArgument);

                // Retrieve the row that contains the button clicked 
                // by the user from the Rows collection.
                GridViewRow row = GridView2.Rows[index];
                Response.Redirect("~/Profile/FriendProfile.aspx?nome=" + row.Cells[1].Text);
            }


        }
    }
}
