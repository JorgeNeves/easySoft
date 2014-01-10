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

        protected DataTable DynamicColumns()
        {
            // Define the new datatable
            DataTable dt = new DataTable();

            // Define 3 columns

            DataColumn dc;
            dc = new DataColumn("Position");
            dt.Columns.Add(dc);
            dc = new DataColumn("Username");
            dt.Columns.Add(dc);
            dc = new DataColumn("Pontuation");
            dt.Columns.Add(dc);
            return dt;
        }

        protected void btnleaderamigos_Click(object sender, EventArgs e)
        {
        //Baseado em:
        //http://www.dotnetobject.com/Thread-Generate-dynamic-DataTable-c
            ViewState["dt"] = DynamicColumns();
            DataTable datat = DynamicColumns();
            DataSet ds = Users.getAllUsernames();

            foreach (DataRow data in ds.Tables[0].Rows)
            {
                DataRow nrow = datat.NewRow();
                foreach (object item in data.ItemArray)
                {
                    nrow["Position"] = 1;
                    nrow["Username"] = item.ToString();
                    
                    int idUser = Users.getUserID(item.ToString());
                    int amigos = 0;
                    
                    DataSet rs = Relationships.checkAmigos(idUser);
                    if (rs != null)
                    {
                       amigos = rs.Tables[0].Rows.Count;
                    }
                    nrow["Pontuation"] = amigos;
                    datat.Rows.Add(nrow);
                }

            }
            GridView1.Visible = true;
            GridView1.DataSource = datat;
            GridView1.DataBind();
            

        }

    }
}