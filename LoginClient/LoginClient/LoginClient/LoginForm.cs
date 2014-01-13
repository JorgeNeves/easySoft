using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Diagnostics;
using System.Configuration;

namespace LoginClient
{
    public partial class LoginForm : Form
    {
        private Button NormalModeButton { get; set; }
        private Button AdvModeButton { get; set; }
        private LoginClientController controller;
        public LoginForm()
        {
            InitializeComponent();
            controller = new LoginClientController();

            NormalModeButton    = new Button();
            AdvModeButton       = new Button();

            username_label.Text     = strings.username_str;
            password_label.Text     = strings.password_str;
            Login.Text              = strings.login_str;
            NormalModeButton.Text   = strings.normal_str;
            AdvModeButton.Text      = strings.advanced_str;

            

        }

        private void tableLayoutPanel2_Paint(object sender, PaintEventArgs e)
        {

        }

        private void Login_Click(object sender, EventArgs e)
        {
            string user = usernameBox.Text;
            string pass = passwordBox.Text;
            string remote = controller.Login(user, pass);
            StreamWriter writer = new StreamWriter("D:\\test.txt");
            remote = (remote == null ? "null" : remote);
            writer.WriteLine(user + " " + pass + "->" + remote);
            writer.Close();
            if (remote == "null")
                return;
            tableLayoutPanel1.Controls.Clear();
            tableLayoutPanel1.Controls.Add(NormalModeButton);
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void tableLayoutPanel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void NormalMode_Click(object sender, EventArgs e)
        {
            //Process.Start(ConfigurationManager.AppSettings["GameCorePath"]);
            MessageBox.Show("3D APP START HERE");
            Application.Exit();
        }
    }
}
