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
        }

        public static void logDownload(int iduser)
        {
             BDAcess dal = new BDAcess();
             dal.Downloads(iduser);
        }
    }
}