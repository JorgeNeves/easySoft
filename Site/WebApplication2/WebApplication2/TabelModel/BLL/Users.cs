using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data;
using WebApplication2.TabelModel.DAL;

namespace WebApplication2.TabelModel.BLL
{
    public class Users
    {
        public static bool InsereUtilizador(string username, string password, string mail)
        {
            bool existe = verifyuser(username);
            bool done;
            if (existe == true)
            {
                DataBaseAcess db = new DataBaseAcess();
                string sql = "Insert INTO Users (Nick,Password,Mail) VALUES ('" + username + "','" + password + "','"+mail+"')";
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
            DataBaseAcess dal = new DataBaseAcess();
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
            DataBaseAcess dal = new DataBaseAcess();
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
            DataBaseAcess dal = new DataBaseAcess();
            string sql = "select * from Users where nick = '" + username + "'";
            DataSet rs = dal.ReturnDataSet(sql);

            return (string)rs.Tables[0].Rows[0]["tipo"];

        }

        public static DataSet getUser(string username)
        {
            DataBaseAcess dal = new DataBaseAcess();
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