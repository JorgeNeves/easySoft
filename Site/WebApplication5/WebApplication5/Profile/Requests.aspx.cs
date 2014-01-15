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
    public partial class Requests : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Session["userID"] == null) { Response.Redirect("~/Account/Login.aspx"); }

                if (!IsPostBack)
                {
                    DataSet ds = Relationships.checkPedidos(Users.getUserID(Session["username"].ToString()));

                    if (ds != null)
                    {
                        GridView1.DataSource = ds.Tables[0];
                        GridView1.DataBind();
                    }
                    else
                    {
                        Response.Redirect("Profile.aspx");
                    }

                }
            
        }

        protected void GridView1_DataBound(object sender, EventArgs e)
        {
            
        }

        protected void GridView1_RowDataBound(object sender, GridViewRowEventArgs e)
        {
            
        }

        protected void GridView1_SelectedIndexChanged(object sender, EventArgs e)
        {
            
        }

        protected void GridView1_RowCommand(object sender, GridViewCommandEventArgs e)
        {
            int index = Convert.ToInt32(e.CommandArgument);

            // Retrieve the row that contains the button clicked 
            // by the user from the Rows collection.
            GridViewRow row = GridView1.Rows[index];
            string nome = row.Cells[2].Text;
            int id = Users.getUserID(Session["username"].ToString());
            int id_friend = Users.getUserID(nome);
            if (e.CommandName == "Aceitar")
            {
                
                Relationships.confirmFriendship(id, id_friend);
            }
            else if (e.CommandName == "Recusar")
            {
               
                Relationships.deleteRequest(id, id_friend);
            }

            DataSet ds = Relationships.checkPedidos(Users.getUserID(Session["username"].ToString()));
            if (ds != null)
            {
                GridView1.DataSource = ds.Tables[0];
                GridView1.DataBind();
            }
            else
            {
                Response.Redirect("Profile.aspx");
            }
            
            
        }
    }
}