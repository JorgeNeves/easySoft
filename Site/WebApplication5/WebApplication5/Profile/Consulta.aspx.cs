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
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                carregar_tags_utilizadores();
                carregar_tags_relacoes();
                leaderboard();
                lbldimrede.Text = Users.getUsersCount().ToString();


            }
        }

        protected void carregar_tags_utilizadores()
        {
            //lbltipotag.Text = "Tags de utilizador existentes";
            DataSet ds = Users.getAllUserTags();
            string temp = "";

            foreach (DataRow data in ds.Tables[0].Rows)
            {

                foreach (object item in data.ItemArray)
                {
                    temp += "<u>" + item.ToString() + "</u> ";
                }

            }
            lbltagutilizadores.Text = temp;
        }

        protected void carregar_tags_relacoes()
        {
            DataSet ds = Users.getAllRelationsTags();
            string temp = "";

            foreach (DataRow data in ds.Tables[0].Rows)
            {

                foreach (object item in data.ItemArray)
                {
                    temp += "<u>" + item.ToString() + "</u> ";
                }

            }
            lbltagrelacoes.Text = temp;
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

        protected void leaderboard()
        {
        
        //DataTable Baseado em:
        //http://www.dotnetobject.com/Thread-Generate-dynamic-DataTable-c
            ViewState["dt"] = DynamicColumns();
            DataTable datat = DynamicColumns();
            DataSet ds = Users.getAllUsernames();
            int c = 1;
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
                c++;

            }
            
            DataView dv = new DataView(datat);
            dv.Sort = "Pontuation DESC";

            datat = dv.ToTable();
            int position=1;

            foreach (DataRow DRow in datat.Rows)
            {
                TableRow tRow = new TableRow();
                foreach (DataColumn dCol in datat.Columns)
                {
                    
                    DRow["Position"]=position;
                    
                }
                position++;
                               
            }

            GridView1.Visible = true;
            GridView1.DataSource = datat;
            GridView1.DataBind();
            

        }

    }
}