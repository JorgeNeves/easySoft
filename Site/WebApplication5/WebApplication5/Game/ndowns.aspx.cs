using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace WebApplication5.Game
{
    public partial class ndowns : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            lbldowns.Text = WebApplication5.TabelModel.BLL.Services.downloadsthishour();
        }
    }
}