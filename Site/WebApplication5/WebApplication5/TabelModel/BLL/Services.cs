using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data;
using WebApplication5.TabelModel.DAL;
using System.Data.SqlClient;

namespace WebApplication5.TabelModel.BLL
{
    public class Services
    {
        public static string downloadsthishour()
        {
            BDAcess dal = new BDAcess();
            string sql = "Select Count(*) From Downloads Where DATEDIFF(HH,DownloadTime,CURRENT_TIMESTAMP)<1;";
            DataSet rs = dal.ReturnDataSet(sql);
            return rs.Tables[0].Rows[0]["Column1"].ToString();
        }
        public static void suggestedFriends(int username)
        {
            BDAcess dal = new BDAcess();
            string sql = "select User2ID from Ligacaos where User1ID = " + username + "and EstadoDaLigacaoID=2";
            sql += " UNION select User1ID from Ligacaos where User2ID = " + username + " and EstadoDaLigacaoID=2;";

            DataSet rs = dal.ReturnDataSet(sql);
            int id;
            for (int i = 0; i < rs.Tables[0].Rows.Count; i++)
            {
                id = ((int)rs.Tables[0].Rows[i][0]);
                BDAcess dal2 = new BDAcess();
                string sql2 = "select User2ID from Ligacaos where User1ID = " + id + "and EstadoDaLigacaoID=2";
                sql2 += " UNION select User1ID from Ligacaos where User2ID = " + id + " and EstadoDaLigacaoID=2;";
                DataSet rs2 = dal2.ReturnDataSet(sql2);

            }
                
        }

        public static void logDownload(int iduser)
        {
             BDAcess dal = new BDAcess();
             dal.Downloads(iduser);
        }
    }
}