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
using System.Net;

namespace LoginClient
{
    public partial class LoginForm : Form
    {
        private Button NormalModeButton { get; set; }
        private Button AdvModeButton { get; set; }
        private Button LogoutButton { get; set; }
        private LoginClientController controller;
        public LoginForm()
        {
            InitializeComponent();
            controller = new LoginClientController();

            NormalModeButton    = new Button();
            AdvModeButton       = new Button();
            LogoutButton        = new Button();

            username_label.Text     = strings.username_str;
            password_label.Text     = strings.password_str;
            Login.Text              = strings.login_str;
            NormalModeButton.Text   = strings.normal_str;
            AdvModeButton.Text      = strings.advanced_str;
            LogoutButton.Text       = strings.logout_str;
            LogoutButton.Click      += Logout_Click;
            NormalModeButton.Click += NormalMode_Click;
            AdvModeButton.Click += AdvMode_Click;


            NormalModeButton.Width = 200;
            AdvModeButton.Width = 200;
            LogoutButton.Width = 200;
        }

        private void ShowLoggedMenu()
        {
            mainTable.Controls.Clear();
            mainTable.Controls.Add(LogoutButton);
            mainTable.Controls.Add(NormalModeButton);
            mainTable.Controls.Add(AdvModeButton);
        }

        private void Login_Click(object sender, EventArgs e)
        {
            string user = usernameBox.Text;
            string pass = passwordBox.Text;
            try
            {
                controller.Login(user, pass);
            }
            catch(WebException ex)
            {
                MessageBox.Show("Failed to connect. " + ex.Message, "Critical Error", MessageBoxButtons.OKCancel, MessageBoxIcon.Error);
                return;
            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.Message, "Critical Error", MessageBoxButtons.OKCancel, MessageBoxIcon.Error);
                return;
            }
            ShowLoggedMenu();
            return;
        }

        private void Logout_Click(object sender, EventArgs e)
        {
            try
            {
                controller.Logout();
            }
            catch (WebException ex)
            {
                MessageBox.Show("Failed to connect. " + ex.Message, "Critical Error", MessageBoxButtons.OKCancel, MessageBoxIcon.Error);
                return;
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Critical Error", MessageBoxButtons.OKCancel, MessageBoxIcon.Error);
                return;
            }
        }

        private void NormalMode_Click(object sender, EventArgs e)
        {
            //Process.Start(ConfigurationManager.AppSettings["GameCorePath"]);
            MessageBox.Show("3D APP START HERE");
           // Application.Exit();
        }

        private void AdvMode_Click(object sender, EventArgs e)
        {
            //Process.Start(ConfigurationManager.AppSettings["GameCorePath"]);
            MessageBox.Show("3D ADV APP START HERE");
            // Application.Exit();
        }

        private void LoginForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            controller.SafeClose();
        }
    }
}
