using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace WebApplication5.Game
{
    
    public partial class Download : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

            escreve();
        }

        private void escreve()
        {
            Label3.Text = WebApplication5.TabelModel.BLL.Services.downloadsthishour();
            Label3.Text += " Downloads esta hora";
           
        }

        protected void Button1_Click1(object sender, EventArgs e)
        {

            Response.Clear();
            Response.ContentType = "application/octet-stream";
            Response.AddHeader("Content-Disposition", "attachment; filename=Jogo.rar");
            Response.WriteFile(Server.MapPath("Jogo.rar"));
            WebApplication5.TabelModel.BLL.Services.logDownload(1);
            escreve();
            Response.End();
            Response.Redirect(Request.Url.AbsoluteUri);
            
        }
    }
}