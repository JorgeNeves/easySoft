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
    public partial class Search : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            string nome = Request.Params[0];
            DataSet d = new DataSet();
            if (nome != null)
            {
                d = Users.searchUser(nome);
            }

            if (d != null && nome != "")
            {
                for (int i = 0; i < d.Tables[0].Rows.Count; i++)
                {
                    string imagem = d.Tables[0].Rows[i][9].ToString();
                    string nom = d.Tables[0].Rows[i][1].ToString();
                    string email = d.Tables[0].Rows[i][3].ToString();
                    string p = d.Tables[0].Rows[i][7].ToString();
                    Response.Write("<div class='display_box' align='left' ><img src='" + imagem + "' style='width:50px; height:50px; float:left; margin-right:6px;' /><span class='name'>" + nom + "</span>&nbsp;<br/>" + email + "<br/><span style='font-size:9px; color:#999999'>" + p + "</span></div>");
                }
            }
        }
    }
}