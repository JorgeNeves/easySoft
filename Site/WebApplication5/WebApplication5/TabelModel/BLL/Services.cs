using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data;
using WebApplication5.TabelModel.DAL;

namespace WebApplication5.TabelModel.BLL
{
    public class Services
    {
        public static void suggestedFriends(int username)
        {
            BDAcess dal = new BDAcess();
            string sql = "select User2ID from Ligacaos where User1ID = " + username + "and EstadoDaLigacaoID=2";
            sql += " UNION select User1ID from Ligacaos where User2ID = " + username + " and EstadoDaLigacaoID=2;";

            DataSet rs = dal.ReturnDataSet(sql);
        }
    }
}