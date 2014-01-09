using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using WebApplication5.TabelModel.BLL;

namespace WebApplication5.Profile
{
    public partial class Consulta : System.Web.UI.Page
    {


        protected void btnuserstags_Click(object sender, EventArgs e)
        {
            lbltipotag.Text = "Tags de utilizador existentes";
            DataSet ds = Users.getAllUserTags();
            string temp = "";

            foreach (DataRow data in ds.Tables[0].Rows)
            {

                foreach (object item in data.ItemArray)
                {
                    temp += "<u>" + item.ToString() + "</u> ";
                }

            }
            lbltag.Text = temp;
        }

        protected void Button4_Click1(object sender, EventArgs e)
        {
            lbltipotag.Text = "Tags de Relações existentes";
            DataSet ds = Users.getAllRelationsTags();
            string temp = "";

            foreach (DataRow data in ds.Tables[0].Rows)
            {

                foreach (object item in data.ItemArray)
                {
                    temp += "<u>" + item.ToString() + "</u> ";
                }

            }
            lbltag.Text = temp;
        }

        protected void btnusertag_Click(object sender, EventArgs e)
        {
            //int userID =(int) Session["userID"];
            DataSet ds = Users.getUserTags(1);
            lbltipotag.Text = "Tags do Utilizador";
            string temp = "";

            foreach (DataRow data in ds.Tables[0].Rows)
            {

                foreach (object item in data.ItemArray)
                {
                    temp += "<u>" + item.ToString() + "</u> ";
                }

            }
            lbltag.Text = temp;
        }

        protected void btnusertagsrelacoes_Click(object sender, EventArgs e)
        {
            lbltipotag.Text = "Tags das suas relações";
            DataSet ds = Users.getRelationsTags(1);
            string temp = "";

            foreach (DataRow data in ds.Tables[0].Rows)
            {

                foreach (object item in data.ItemArray)
                {
                    temp += "<u>" + item.ToString() + "</u> ";
                }

            }
            lbltag.Text = temp;
        }

    }
}