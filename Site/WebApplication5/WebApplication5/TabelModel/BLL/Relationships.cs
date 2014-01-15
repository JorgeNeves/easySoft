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
        private static DataSet convertID(int[] ids)
        {
            BDAcess dal = new BDAcess();
            string ids_pedidos = "";
            for (int i = 0; i < ids.Length; i++)
            {
                if (i == ids.Length - 1)
                {
                    ids_pedidos += "UserID = " + ids[i] + ";";
                }
                else
                {
                    ids_pedidos += "UserID = " + ids[i] + " OR ";
                }
                
            }
            string sql = "SELECT Nick FROM Users WHERE "+ids_pedidos;
            DataSet rs = dal.ReturnDataSet(sql);
            return rs;
        }

        private static DataSet convertID_2(int[] ids)
        {
            BDAcess dal = new BDAcess();
            string ids_pedidos = "";
            for (int i = 0; i < ids.Length; i++)
            {
                if (i == ids.Length - 1)
                {
                    ids_pedidos += "UserID = " + ids[i] + ";";
                }
                else
                {
                    ids_pedidos += "UserID = " + ids[i] + " OR ";
                }

            }
            string sql = "SELECT Nick, AvatarUrl FROM Users WHERE " + ids_pedidos;
            DataSet rs = dal.ReturnDataSet(sql);
            return rs;
        }
        public static DataSet checkPedidos(int userid)
        {
            BDAcess dal = new BDAcess();
            string sql = "select User1ID from Ligacaos where User2ID = " + userid + " and EstadoDaLigacaoID=1;";
            DataSet rs = dal.ReturnDataSet(sql);
            if(rs.Tables[0].Rows.Count == 0)
            {
                return null;
            }
            int[] ids;
            ids = new int[rs.Tables[0].Rows.Count];
            for (int i = 0; i < rs.Tables[0].Rows.Count;i++)
            {
                ids[i]=((int)rs.Tables[0].Rows[i][0]);

            }
            DataSet final = convertID(ids);
            
            return final;
            
            


        }
        public static DataSet checkAmigos(int userid)
        {
            BDAcess dal = new BDAcess();
            string sql = "select User2ID from Ligacaos where User1ID = " + userid + "and EstadoDaLigacaoID=2";
            sql += " UNION select User1ID from Ligacaos where User2ID = " + userid + " and EstadoDaLigacaoID=2;";
            DataSet rs = dal.ReturnDataSet(sql);
            if (rs.Tables[0].Rows.Count == 0)
            {
                return null;
            }
            int[] ids;
            ids = new int[rs.Tables[0].Rows.Count];
            for (int i = 0; i < rs.Tables[0].Rows.Count; i++)
            {
                ids[i] = ((int)rs.Tables[0].Rows[i][0]);

            }
            DataSet final = convertID_2(ids);

            return final;
        }
        public static void confirmFriendship(int id, int id_friend)
        {
            BDAcess dal = new BDAcess();
            string sql = "UPDATE Ligacaos SET EstadoDaLigacaoID = 2  WHERE (User1ID = " + id + " and User2ID= " + id_friend + ") OR (User1ID = " + id_friend + " and User2ID= " + id + ");";
            DataSet rs = dal.ReturnDataSet(sql);
        }

        public static void deleteRequest(int id, int id_friend)
        {
            BDAcess dal = new BDAcess();
            string sql = "Delete from Ligacaos WHERE (User1ID = " + id + " and User2ID= " + id_friend + ") OR (User1ID = " + id_friend + " and User2ID= " + id + ");";
            DataSet rs = dal.ReturnDataSet(sql);
        }
    }
}