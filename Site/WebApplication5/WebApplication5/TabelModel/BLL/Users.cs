using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data;
using WebApplication5.TabelModel.DAL;

namespace WebApplication5.TabelModel.BLL
{
    public class Users
    {
        public static bool InsereUtilizador(string username, string password, string mail,string nome, string apelido, string birthday, string country)
        {
            bool existe = verifyuser(username);
            bool done;
            if (existe == true)
            {
                BDAcess db = new BDAcess();
                string sql = "Insert INTO Users (Nick,Password,Mail,PrimeiroNome,UltimoNome,DataDeNascimento,Pais,EstadoDeHumorID) VALUES ('" + username + "','" + password + "','"+mail+"','"+nome+"','"+apelido+"','"+birthday+"','"+country+"',1)";
                DataSet rs = db.ReturnDataSet(sql);
                done = true;
            }
            else
            {
                done = false;
            }
            return done;

        }
        public static bool verifyuser(string username)
        {
            BDAcess dal = new BDAcess();
            string sql = "select * from Users where Nick = '" + username + "'";
            DataSet rs = dal.ReturnDataSet(sql);
            if (rs.Tables[0].Rows.Count > 0)
            {
                return false;
            }
            else return true;


        }

        public static int verifyuser(string username, string pass)
        {
            BDAcess dal = new BDAcess();
            string sql = "select * from Users where Nick = '" + username + "' and password ='" + pass + "'";
            DataSet rs = dal.ReturnDataSet(sql);
            if (rs.Tables[0].Rows.Count == 0)
            {
                return -1;
            }
            return (int)rs.Tables[0].Rows[0][0];


        }

        public static string userType(string username)
        {
            BDAcess dal = new BDAcess();
            string sql = "select * from Users where nick = '" + username + "'";
            DataSet rs = dal.ReturnDataSet(sql);

            return (string)rs.Tables[0].Rows[0]["tipo"];

        }

        public static DataSet getUser(string username)
        {
            BDAcess dal = new BDAcess();
            string sql = "select * from Users where Nick = '" + username + "'";
            DataSet rs = dal.ReturnDataSet(sql);
            if (rs.Tables[0].Rows.Count > 0)
            {
                return rs;
            }
            else return null;


        }
    }
}