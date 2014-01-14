namespace LoginClient
{
    partial class LoginForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.mainTable = new System.Windows.Forms.TableLayoutPanel();
            this.buttonsTable = new System.Windows.Forms.TableLayoutPanel();
            this.passwordBox = new System.Windows.Forms.TextBox();
            this.Login = new System.Windows.Forms.Button();
            this.username_label = new System.Windows.Forms.Label();
            this.usernameBox = new System.Windows.Forms.TextBox();
            this.password_label = new System.Windows.Forms.Label();
            this.mainTable.SuspendLayout();
            this.buttonsTable.SuspendLayout();
            this.SuspendLayout();
            // 
            // mainTable
            // 
            this.mainTable.BackColor = System.Drawing.Color.Transparent;
            this.mainTable.ColumnCount = 1;
            this.mainTable.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.mainTable.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.mainTable.Controls.Add(this.buttonsTable, 0, 1);
            this.mainTable.Location = new System.Drawing.Point(12, 12);
            this.mainTable.Name = "mainTable";
            this.mainTable.RowCount = 2;
            this.mainTable.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 80.89172F));
            this.mainTable.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 19.10828F));
            this.mainTable.Size = new System.Drawing.Size(634, 314);
            this.mainTable.TabIndex = 0;
            // 
            // buttonsTable
            // 
            this.buttonsTable.ColumnCount = 3;
            this.buttonsTable.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 33.25527F));
            this.buttonsTable.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 66.74473F));
            this.buttonsTable.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 207F));
            this.buttonsTable.Controls.Add(this.passwordBox, 1, 1);
            this.buttonsTable.Controls.Add(this.Login, 2, 0);
            this.buttonsTable.Controls.Add(this.username_label, 0, 0);
            this.buttonsTable.Controls.Add(this.usernameBox, 1, 0);
            this.buttonsTable.Controls.Add(this.password_label, 0, 1);
            this.buttonsTable.Location = new System.Drawing.Point(3, 257);
            this.buttonsTable.Name = "buttonsTable";
            this.buttonsTable.RowCount = 2;
            this.buttonsTable.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.buttonsTable.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.buttonsTable.Size = new System.Drawing.Size(628, 54);
            this.buttonsTable.TabIndex = 0;
            // 
            // passwordBox
            // 
            this.passwordBox.Location = new System.Drawing.Point(143, 30);
            this.passwordBox.Name = "passwordBox";
            this.passwordBox.PasswordChar = '*';
            this.passwordBox.Size = new System.Drawing.Size(274, 20);
            this.passwordBox.TabIndex = 1;
            // 
            // Login
            // 
            this.Login.Location = new System.Drawing.Point(423, 3);
            this.Login.Name = "Login";
            this.Login.Size = new System.Drawing.Size(75, 21);
            this.Login.TabIndex = 2;
            this.Login.Text = "Login";
            this.Login.UseVisualStyleBackColor = true;
            this.Login.Click += new System.EventHandler(this.Login_Click);
            // 
            // username_label
            // 
            this.username_label.AutoSize = true;
            this.username_label.Location = new System.Drawing.Point(3, 0);
            this.username_label.Name = "username_label";
            this.username_label.Size = new System.Drawing.Size(103, 13);
            this.username_label.TabIndex = 3;
            this.username_label.Text = "strings.username_str";
            // 
            // usernameBox
            // 
            this.usernameBox.Location = new System.Drawing.Point(143, 3);
            this.usernameBox.Name = "usernameBox";
            this.usernameBox.Size = new System.Drawing.Size(274, 20);
            this.usernameBox.TabIndex = 0;
            // 
            // password_label
            // 
            this.password_label.AutoSize = true;
            this.password_label.Location = new System.Drawing.Point(3, 27);
            this.password_label.Name = "password_label";
            this.password_label.Size = new System.Drawing.Size(52, 13);
            this.password_label.TabIndex = 4;
            this.password_label.Text = "password";
            // 
            // LoginForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = global::LoginClient.Properties.Resources.facebook_open_graph;
            this.ClientSize = new System.Drawing.Size(658, 381);
            this.Controls.Add(this.mainTable);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "LoginForm";
            this.Text = "Socialite Client";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.LoginForm_FormClosing);
            this.mainTable.ResumeLayout(false);
            this.buttonsTable.ResumeLayout(false);
            this.buttonsTable.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TableLayoutPanel mainTable;
        private System.Windows.Forms.TableLayoutPanel buttonsTable;
        private System.Windows.Forms.TextBox usernameBox;
        private System.Windows.Forms.TextBox passwordBox;
        private System.Windows.Forms.Button Login;
        private System.Windows.Forms.Label username_label;
        private System.Windows.Forms.Label password_label;
    }
}

