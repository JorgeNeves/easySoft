using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data;
using WebApplication5.TabelModel.DAL;

namespace WebApplication5.TabelModel.BLL
{
    public class Relationships
    {
        public static void addRelation(int username, int friend, int forca, string data)
        {
            
                BDAcess db = new BDAcess();
                string sql = "Insert INTO Ligacaos (User1ID,User2ID,Forca,DataDeInicio,EstadoDaLigacaoID) VALUES (" + username + "," + friend + "," + forca + ",'" + data + "',1)";
                DataSet rs = db.ReturnDataSet(sql); 

        }

        public static bool checkRelation(int userid, int friend)
        {
            BDAcess dal = new BDAcess();
            string sql = "select * from Ligacaos where User1ID = " + userid + " and User2ID =" + friend;
            DataSet rs = dal.ReturnDataSet(sql);
            if (rs.Tables[0].Rows.Count > 0)
            {
                return true;
            }
            else
            {
                BDAcess dal2 = new BDAcess();
                string sql2 = "select * from Ligacaos where User1ID = " + friend + " and User2ID =" + userid;
                DataSet rs2 = dal2.ReturnDataSet(sql2);
                if (rs2.Tables[0].Rows.Count > 0)
                {
                    return true;
                }
                else return false;
            }


        }

        public static DataSet checkPedidos(int userid)
        {
            BDAcess dal = new BDAcess();
            string sql = "select * from Ligacaos where User1ID = " + userid + " or User2ID =" + userid +"and EstadoDaLigacaoID=1";
            DataSet rs = dal.ReturnDataSet(sql);
            if (rs.Tables[0].Rows.Count > 0)
            {
                return rs;
            }
            return null;


        }
    }
}