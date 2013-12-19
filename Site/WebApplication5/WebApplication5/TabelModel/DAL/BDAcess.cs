using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data;
using System.Data.SqlClient;
namespace WebApplication5.TabelModel.DAL
{
    public class BDAcess
    {
        private string connectionString = "Data Source=wvm054.dei.isep.ipp.pt\\sqlexpress;Initial Catalog=easysoftdb;User ID=easysoft;Password=es@Lapr5";

        public DataSet ReturnDataSet(string Sql)
        {
            SqlConnection conn = new SqlConnection(connectionString);
            SqlDataAdapter adp = new SqlDataAdapter(Sql, conn);
            DataSet ds = new DataSet();
            adp.Fill(ds);
            conn.Close();
            return ds;
        }
    }
}