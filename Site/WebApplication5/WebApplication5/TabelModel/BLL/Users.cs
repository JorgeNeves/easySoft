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
                string sql = "Insert INTO Users (Nick,Password,Mail,PrimeiroNome,UltimoNome,DataDeNascimento,Pais,EstadoDeHumorID,AvatarUrl) VALUES ('" + username + "','" + password + "','" + mail + "','" + nome + "','" + apelido + "','" + birthday + "','" + country + "',1,'http://www.netocar.com.br/includes/tng/styles/img_not_found.gif')";
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
        public static void updateUserInfo(string username, string nome, string apelido, string email,string pais, int estado, string facebook, string LinkedIn)
        {
            BDAcess dal = new BDAcess();
            string sql = "UPDATE Users SET PrimeiroNome='"+nome+"', UltimoNome='"+apelido+"', Mail='"+email+"',Pais='"+pais+"',EstadoDeHumorID="+estado+" ,PerfilFacebook='"+facebook+"',PerfilLinkedIn='"+LinkedIn+"' WHERE Nick='"+username+"'";
            DataSet rs = dal.ReturnDataSet(sql);


        }

        public static void updateUserPass(string username, string password)
        {
            BDAcess dal = new BDAcess();
            string sql = "UPDATE Users SET Password='" + password + "' WHERE Nick='" + username + "'";
            DataSet rs = dal.ReturnDataSet(sql);


        }

        public static void updateUserAvatar(string username, string avatar)
        {
            BDAcess dal = new BDAcess();
            string sql = "UPDATE Users SET AvatarUrl='" + avatar + "' WHERE Nick='" + username + "'";
            DataSet rs = dal.ReturnDataSet(sql);


        }

        public static string getEstado(int estado)
        {
            BDAcess dal = new BDAcess();
            string sql = "select Sentimento from EstadoDeHumors where EstadoDeHumorID = '" + estado + "'";
            DataSet rs = dal.ReturnDataSet(sql);
            return (string)rs.Tables[0].Rows[0][0];


        }

        public static int getUserID(string username)
        {
            BDAcess dal = new BDAcess();
            string sql = "select UserID from Users where Nick = '" + username + "'";
            DataSet rs = dal.ReturnDataSet(sql);
            return (int)rs.Tables[0].Rows[0][0];


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
        public static int getTAGID(string Palavra)
        {
            BDAcess dal = new BDAcess();
            string sql = "select Tags.TagID FROM Tags Where Tags.Palavra='" + Palavra + "';";
            DataSet rs = dal.ReturnDataSet(sql);
            if (rs.Tables[0].Rows.Count > 0)
            {
                return (int)rs.Tables[0].Rows[0]["TagID"];
            }
            return -1;
        }

        public static void addTAGUSER(int idtag, int userid)
        {
            BDAcess dal = new BDAcess();
            string sql = "Insert Into User_Tag values("+userid +","+ idtag+");";
            dal.ReturnDataSet(sql);
        }

        public static void addTAGORIGINAL(string original,string nova)
        {
            
            BDAcess dal = new BDAcess();
            string sql = "select TagOriginals.TagOriginalID FROM TagOriginals Where TagOriginals.PalavraOriginal='"+original+"';";
            DataSet rs =dal.ReturnDataSet(sql);
            if (rs.Tables[0].Rows.Count == 0)
            {
                sql = "Insert Into TagOriginals values('" + original + "');";
                dal.ReturnDataSet(sql);
                sql = "select TagOriginals.TagOriginalID FROM TagOriginals Where TagOriginals.PalavraOriginal='" + original + "';";
                rs = dal.ReturnDataSet(sql);
            }
            //sql = "select TagOriginals.TagOriginalID FROM TagOriginals Where TagOriginals.PalavraOriginal='" + original + "';";
            //rs = dal.ReturnDataSet(sql);
            if (rs.Tables[0].Rows.Count > 0)
            {
                int ntagid = (int)rs.Tables[0].Rows[0]["TagOriginalID"];
                sql = "Insert Into Tags values ("+ntagid+",'"+nova+"');";
                dal.ReturnDataSet(sql);
            }
        }

        public static void deleteTAGfromUSER(int iduser,int TAGID)
        {
            BDAcess dal = new BDAcess();
            string sql = "Delete FROM User_Tag Where TagID=" + TAGID + ";";
            DataSet rs = dal.ReturnDataSet(sql);
        }

        public static int getUsersCount()
        {
            BDAcess dal = new BDAcess();
            string sql = "select * from Users ";
            DataSet rs = dal.ReturnDataSet(sql);
            return rs.Tables[0].Rows.Count;

        }

        

        public static DataSet searchUser(string username)
        {
            BDAcess dal = new BDAcess();
            string sql = "select * from Users where Nick like '%" + username + "%'";
            DataSet rs = dal.ReturnDataSet(sql);
            if (rs.Tables[0].Rows.Count > 0)
            {
                return rs;
            }
            else return null;
        }

        public static DataSet getAllUsernames()
        {
            BDAcess dal = new BDAcess();
            string sql = "Select Users.Nick From Users";
            DataSet rs = dal.ReturnDataSet(sql);
            if (rs.Tables[0].Rows.Count > 0)
            {
                return rs;
            }
            else return null;

        }
        public static DataSet getUserTags(int idUser)
        {
            BDAcess dal = new BDAcess();
            string sql = "Select distinct Tags.Palavra as UserTags FROM Tags,Users,User_Tag where (Tags.TagID=User_Tag.TagID and User_Tag.UserID=" + idUser + ")";
            DataSet rs = dal.ReturnDataSet(sql);
            if (rs.Tables[0].Rows.Count > 0)
            {
                return rs;
            }
            else return null;
        }

        public static DataSet getAllUserTags()
        {
            BDAcess dal = new BDAcess();
            string sql = "Select distinct Tags.Palavra FROM Tags,Users,User_Tag where Tags.TagID=User_Tag.TagID";
            DataSet rs = dal.ReturnDataSet(sql);
            if (rs.Tables[0].Rows.Count > 0)
            {
                return rs;
            }
            else return null;
        }

        public static DataSet getRelationsTags(int idUser)
        {
            BDAcess dal = new BDAcess();
            string sql = "Select distinct Tags.Palavra FROM Tags,Users,Ligacao_Tag,Ligacaos where ((Ligacaos.LigacaoID=Ligacao_Tag.LigacaoID) and (Tags.TagID=Ligacao_Tag.TagID) and (Ligacaos.User1ID=" + idUser + " OR Ligacaos.User2ID=" + idUser + "))";
            DataSet rs = dal.ReturnDataSet(sql);
            if (rs.Tables[0].Rows.Count > 0)
            {
                return rs;
            }
            else return null;
        }

        public static DataSet getAllRelationsTags()
        {
            BDAcess dal = new BDAcess();
            string sql = "Select distinct Tags.Palavra FROM Tags,Users,Ligacao_Tag,Ligacaos where ((Ligacaos.LigacaoID=Ligacao_Tag.LigacaoID) and (Tags.TagID=Ligacao_Tag.TagID))";
            DataSet rs = dal.ReturnDataSet(sql);
            if (rs.Tables[0].Rows.Count > 0)
            {
                return rs;
            }
            else return null;
        }
        
    }
}