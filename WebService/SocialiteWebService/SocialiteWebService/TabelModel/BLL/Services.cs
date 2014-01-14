using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using SocialiteWebService.TabelModel.DAL;
using System.Data;
using System.Collections;

namespace SocialiteWebService.TabelModel.BLL
{
    public class Services
    {
        public static ArrayList suggestedFriends(int username)
        {
            DataBase dal = new DataBase();
            string sql = "select User2ID from Ligacaos where User1ID = " + username + "and EstadoDaLigacaoID=2";
            sql += " UNION select User1ID from Ligacaos where User2ID = " + username + " and EstadoDaLigacaoID=2;";
            //Amigos do utilizador
            DataSet rs = dal.ReturnDataSet(sql);
            string[] amigos = new string[rs.Tables[0].Rows.Count];
            for(int x=0;x<rs.Tables[0].Rows.Count;x++){
                amigos[x]=""+rs.Tables[0].Rows[x][0];
            }
            int id;
            ArrayList myAL = new ArrayList();
            for (int i = 0; i < rs.Tables[0].Rows.Count; i++)
            {
                id = ((int)rs.Tables[0].Rows[i][0]);
                DataBase dal2 = new DataBase();
                string sql2 = "select User2ID from Ligacaos where User1ID = " + id + " and EstadoDaLigacaoID=2 and User2ID <> "+username;
                sql2 += " UNION select User1ID from Ligacaos where User2ID = " + id + " and EstadoDaLigacaoID=2 and User1ID <> " + username;
               
                DataSet rs2 = dal2.ReturnDataSet(sql2);
                
                for (int x = 0; x < rs2.Tables[0].Rows.Count; x++)
                {
                    int existe = 0;
                    for (int y = 0; y < rs.Tables[0].Rows.Count; y++)
                    {
                        
                        if (rs2.Tables[0].Rows[x][0].ToString() == amigos[y].ToString())
                        {
                            existe = 1;
                            
                        }
                    }
                    if (existe == 0)
                    {
                        myAL.Add(rs2.Tables[0].Rows[x][0].ToString());
                    }
                    

                }
            }
            return myAL;
            

        }
    }
}