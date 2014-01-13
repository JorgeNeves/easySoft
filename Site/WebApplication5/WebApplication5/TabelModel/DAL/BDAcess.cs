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
        //http://msdn.microsoft.com/en-us/library/system.data.sqlclient.sqlcommand.parameters(v=vs.110).aspx
        //http://stackoverflow.com/questions/19227663/sql-error-converting-data-type-datetime-to-smalldatetime
        public void Downloads(int iduser)
        {
            
            DateTime Time = DateTime.Now;
            string commandText = "Insert Into Downloads values(" + iduser + ",@time);";
            
            SqlConnection conn = new SqlConnection(connectionString);
            SqlCommand cmd = new SqlCommand(commandText, conn);
           //cmd.Parameters.Add("@time",SqlDbType.SmallDateTime);
            cmd.Parameters.AddWithValue("@time", Time);
            conn.Open();
            cmd.ExecuteNonQuery();
            //SqlDataAdapter adp = new SqlDataAdapter(cmd);
            //DataSet ds = new DataSet();
            //adp.Fill(ds);
            
            conn.Close();
            //return ds;
        }

    }
}