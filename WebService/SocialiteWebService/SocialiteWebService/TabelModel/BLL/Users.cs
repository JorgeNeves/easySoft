using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using SocialiteWebService.TabelModel.DAL;
using System.Data;
namespace SocialiteWebService.TabelModel.BLL
{
    public class Users
    {
        public static string getUserNick(int username)
        {
            DataBase dal = new DataBase();
            string sql = "select Nick from Users where UserID = " + username;
            DataSet rs = dal.ReturnDataSet(sql);
            return rs.Tables[0].Rows[0][0].ToString();


        }

        public static DataSet getUserTags(int idUser)
        {
            DataBase dal = new DataBase();
            string sql = "Select distinct Tags.Palavra FROM Tags,Users,User_Tag where (Tags.TagID=User_Tag.TagID and User_Tag.UserID=" + idUser + ")";
            DataSet rs = dal.ReturnDataSet(sql);
            if (rs.Tables[0].Rows.Count > 0)
            {
                return rs;
            }
            else return null;
        }
    }
}