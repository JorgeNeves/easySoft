using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace WebApplication5
{
    public partial class _Default : Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            
        }

        protected void LinkButton1_Click(object sender, EventArgs e)
        {
            Response.Redirect("~/Account/Register.aspx");
        }

        protected void LinkButton2_Click(object sender, EventArgs e)
        {
            Response.Redirect("~/Profile/Profile.aspx");
        }

        protected void LinkButton3_Click(object sender, EventArgs e)
        {
            Response.Redirect("~/Game/Download.aspx");
        }

        protected void RadioButtonList1_SelectedIndexChanged(object sender, EventArgs e)
        {
            string pt = RadioButtonList1.SelectedValue;
            

            if (pt == "Portuguese")
            {
                Application["Linguagem"] = "PT";
            }
            else
            {
                Application["Linguagem"] = "ENG";
            }
            var master = (SiteMaster)Page.Master;
            Label mpLabel = (Label)master.FindControl("Linguagem");
            mpLabel.Text = Application["Linguagem"].ToString();
        }
        

        
    }
}