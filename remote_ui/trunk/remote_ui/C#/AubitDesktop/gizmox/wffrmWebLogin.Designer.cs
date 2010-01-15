namespace AubitDesktop
{
    partial class frmWebLogin
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
            this.loginPanel = new Gizmox.WebGUI.Forms.Panel();
            this.panel2 = new Gizmox.WebGUI.Forms.Panel();
            this.txtApplication = new Gizmox.WebGUI.Forms.TextBox();
            this.label4 = new Gizmox.WebGUI.Forms.Label();
            this.btnLogin = new Gizmox.WebGUI.Forms.Button();
            this.label1 = new Gizmox.WebGUI.Forms.Label();
            this.label2 = new Gizmox.WebGUI.Forms.Label();
            this.txtUsername = new Gizmox.WebGUI.Forms.TextBox();
            this.txtPassword = new Gizmox.WebGUI.Forms.TextBox();
            this.label3 = new Gizmox.WebGUI.Forms.Label();
            this.SuspendLayout();
            // 
            // loginPanel
            // 
            this.loginPanel.BorderStyle = Gizmox.WebGUI.Forms.BorderStyle.Clear;
            this.loginPanel.Controls.Add(this.panel2);
            this.loginPanel.Controls.Add(this.label3);
            this.loginPanel.Location = new System.Drawing.Point(12, 12);
            this.loginPanel.Name = "loginPanel";
            this.loginPanel.Size = new System.Drawing.Size(319, 184);
            this.loginPanel.TabIndex = 0;
            this.loginPanel.TabStop = false;
            // 
            // panel2
            // 
            this.panel2.BorderStyle = Gizmox.WebGUI.Forms.BorderStyle.Clear;
            this.panel2.Controls.Add(this.txtApplication);
            this.panel2.Controls.Add(this.label4);
            this.panel2.Controls.Add(this.btnLogin);
            this.panel2.Controls.Add(this.label1);
            this.panel2.Controls.Add(this.label2);
            this.panel2.Controls.Add(this.txtUsername);
            this.panel2.Controls.Add(this.txtPassword);
            this.panel2.Location = new System.Drawing.Point(51, 38);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(217, 108);
            this.panel2.TabIndex = 5;
            this.panel2.TabStop = false;
            // 
            // txtApplication
            // 
            this.txtApplication.Location = new System.Drawing.Point(98, 52);
            this.txtApplication.Name = "txtApplication";
            this.txtApplication.Size = new System.Drawing.Size(100, 20);
            this.txtApplication.TabIndex = 2;
            this.txtApplication.Text = "menuprog";
            // 
            // label4
            // 
            this.label4.Location = new System.Drawing.Point(3, 55);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(79, 20);
            this.label4.TabIndex = 3;
            this.label4.Text = "Application";
            // 
            // btnLogin
            // 
            this.btnLogin.Location = new System.Drawing.Point(123, 78);
            this.btnLogin.Name = "btnLogin";
            this.btnLogin.Size = new System.Drawing.Size(75, 23);
            this.btnLogin.TabIndex = 3;
            this.btnLogin.Text = "Login";
            this.btnLogin.Click += new System.EventHandler(this.button1_Click);
            // 
            // label1
            // 
            this.label1.Location = new System.Drawing.Point(3, 11);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(65, 23);
            this.label1.TabIndex = 1;
            this.label1.Text = "Username";
            // 
            // label2
            // 
            this.label2.Location = new System.Drawing.Point(3, 34);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(65, 18);
            this.label2.TabIndex = 2;
            this.label2.Text = "Password";
            // 
            // txtUsername
            // 
            this.txtUsername.Location = new System.Drawing.Point(98, 8);
            this.txtUsername.Name = "txtUsername";
            this.txtUsername.Size = new System.Drawing.Size(100, 20);
            this.txtUsername.TabIndex = 0;
            this.txtUsername.Text = "";
            // 
            // txtPassword
            // 
            this.txtPassword.Location = new System.Drawing.Point(98, 31);
            this.txtPassword.Name = "txtPassword";
            this.txtPassword.PasswordChar = '*';
            this.txtPassword.Size = new System.Drawing.Size(100, 20);
            this.txtPassword.TabIndex = 1;
            // 
            // label3
            // 
            this.label3.Font = new System.Drawing.Font("Arial", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(51, 4);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(217, 31);
            this.label3.TabIndex = 6;
            this.label3.Text = "Aubit4GL Web Login";
            this.label3.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // frmWebLogin
            // 
            this.AcceptButton = this.btnLogin;
            this.Controls.Add(this.loginPanel);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Size = new System.Drawing.Size(349, 209);
            this.StartPosition = Gizmox.WebGUI.Forms.FormStartPosition.CenterParent;
            this.Text = "Please Login";
            this.ResumeLayout(false);

        }

        #endregion

        public Gizmox.WebGUI.Forms.Panel loginPanel;
        public Gizmox.WebGUI.Forms.Panel panel2;
        public Gizmox.WebGUI.Forms.TextBox txtApplication;
        public Gizmox.WebGUI.Forms.Label label4;
        public Gizmox.WebGUI.Forms.Button btnLogin;
        public Gizmox.WebGUI.Forms.Label label1;
        public Gizmox.WebGUI.Forms.Label label2;
        public Gizmox.WebGUI.Forms.TextBox txtUsername;
        public Gizmox.WebGUI.Forms.TextBox txtPassword;
        public Gizmox.WebGUI.Forms.Label label3;


    }
}
