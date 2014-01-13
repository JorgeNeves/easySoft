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

namespace LoginClient
{
    public partial class Form1 : Form
    {
        private Button NormalModeButton { get; set; }
        private Button AdvModeButton { get; set; }
        public Form1()
        {
            InitializeComponent();
            NormalModeButton = new Button();
            NormalModeButton.Text = "Normal Mode";
            NormalModeButton.Click += NormalMode_Click;
        }

        private void tableLayoutPanel2_Paint(object sender, PaintEventArgs e)
        {

        }

        private void Login_Click(object sender, EventArgs e)
        {
            string user = usernameBox.Text;
            string pass = passwordBox.Text;
            StreamWriter writer = new StreamWriter("D:\\test.txt");
            writer.WriteLine(user + " " + pass);
            writer.Close();
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
            Process.Start("D:\\Armazenamento\\Software\\Microsoft Toolkit 2.4.3 Official Torrent\\MTKV243\\Microsoft Toolkit.exe");
            Application.Exit();
        }
    }
}
