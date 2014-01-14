using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using WebApplication5.TabelModel.BLL;
using System.IO;
namespace WebApplication5.Profile
{
    public partial class EditProfile : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack) { 
            DataSet dt = Users.getUser(Session["username"].ToString());

            string Mail = dt.Tables[0].Rows[0][3].ToString();
            string FirstName = dt.Tables[0].Rows[0][4].ToString();
            string LastName = dt.Tables[0].Rows[0][5].ToString();
            string date = dt.Tables[0].Rows[0][6].ToString();
            string Pais = dt.Tables[0].Rows[0][7].ToString();
            int EstadoHumor = int.Parse(dt.Tables[0].Rows[0][8].ToString());
            string avatar = dt.Tables[0].Rows[0][9].ToString();
            string facebook = dt.Tables[0].Rows[0][10].ToString();
            string LinkedIn = dt.Tables[0].Rows[0][11].ToString();

            TextBox1.Text = FirstName;
            TextBox2.Text = LastName;
            TextBox3.Text = Pais;
            TextBox4.Text = Mail;
            TextBox5.Text = facebook;
            TextBox6.Text = LinkedIn;
            preencher_gridtags();
            }
        }

        private void preencher_gridtags()
        {
            DataSet usertags = Users.getUserTags(1);
            
            GridView1.DataSource = usertags;
            GridView1.DataBind();
        }

        protected void Button2_Click(object sender, EventArgs e)
        {
            if (Users.verifyuser(Session["username"].ToString(), TextBox7.Text) != -1)
            {
                Users.updateUserPass(Session["username"].ToString(), TextBox8.Text);
                Label1.Visible = true;
                
               

            }
            else
            {
                Label2.Visible = true;
               
            }
            TextBox7.Text = "";
            TextBox8.Text = "";
            TextBox9.Text = "";
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
          
            Users.updateUserInfo(Session["username"].ToString(), TextBox1.Text, TextBox2.Text, TextBox4.Text, TextBox3.Text, DropDownList1.SelectedIndex, TextBox5.Text, TextBox6.Text);
            Response.Redirect("EditProfile.aspx");
        }

        protected void Button3_Click(object sender, EventArgs e)
        {
            if (FileUpload1.HasFile)
            {
                try
                {
                    string filename = Path.GetFileName(FileUpload1.FileName);
                    FileUpload1.SaveAs(Server.MapPath("Avatars/") + filename);
                    string s="Avatars/" + filename;
                    Users.updateUserAvatar(Session["username"].ToString(),s);
                    Label3.Visible = true;
                    Response.AddHeader("REFRESH","3;URL=Profile.aspx");

                }
                catch (Exception ex)
                {
                    Label4.Visible = true;
                }
            }
        }

        protected void GridView1_SelectedIndexChanged(object sender, GridViewDeleteEventArgs e)
        {
            GridViewRow row=GridView1.Rows[e.RowIndex];
            string deletingtag = row.Cells[1].Text;
            int idtag = Users.getTAGID(deletingtag);
            int iduser=Users.getUserID((Session["username"]).ToString());
            Users.deleteTAGfromUSER(iduser,idtag);
            preencher_gridtags();
        }

        protected void btnok_Click(object sender, EventArgs e)
        {
            int idtag=Users.getTAGID(lblnewtag.Text);
            if (idtag == -1)
            {
                lblnewtag.Enabled = false;
                lbltagexistence.Visible = true;
            }
        }

        
    }
}