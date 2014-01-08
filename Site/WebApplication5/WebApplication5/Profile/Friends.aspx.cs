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
    public partial class Friends : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
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
        }
    }
}