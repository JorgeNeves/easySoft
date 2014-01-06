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
           DataSet ds=Relationships.checkPedidos(Users.getUserID(Session["username"].ToString()));
           GridView1.DataSource = ds.Tables[0];
           GridView1.DataBind();
        }
    }
}