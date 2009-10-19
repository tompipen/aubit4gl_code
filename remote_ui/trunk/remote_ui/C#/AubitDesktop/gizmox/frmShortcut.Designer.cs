namespace AubitDesktop
{
    partial class frmShortcut
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
            this.groupBox1 = new Gizmox.WebGUI.Forms.GroupBox();
            this.txtPort = new Gizmox.WebGUI.Forms.TextBox();
            this.label2 = new Gizmox.WebGUI.Forms.Label();
            this.lblDescription = new Gizmox.WebGUI.Forms.Label();
            this.label7 = new Gizmox.WebGUI.Forms.Label();
            this.cbPromptPassword = new Gizmox.WebGUI.Forms.CheckBox();
            this.label1 = new Gizmox.WebGUI.Forms.Label();
            this.label6 = new Gizmox.WebGUI.Forms.Label();
            this.lblPassword = new Gizmox.WebGUI.Forms.Label();
            this.txtTitle = new Gizmox.WebGUI.Forms.TextBox();
            this.label3 = new Gizmox.WebGUI.Forms.Label();
            this.txtApplication = new Gizmox.WebGUI.Forms.TextBox();
            this.label4 = new Gizmox.WebGUI.Forms.Label();
            this.txtServer = new Gizmox.WebGUI.Forms.TextBox();
            this.lstProtocol = new Gizmox.WebGUI.Forms.ListBox();
            this.txtPassword = new Gizmox.WebGUI.Forms.TextBox();
            this.label5 = new Gizmox.WebGUI.Forms.Label();
            this.txtUser = new Gizmox.WebGUI.Forms.TextBox();
            this.btnCancel = new Gizmox.WebGUI.Forms.Button();
            this.btnOK = new Gizmox.WebGUI.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.txtPort);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.lblDescription);
            this.groupBox1.Controls.Add(this.label7);
            this.groupBox1.Controls.Add(this.cbPromptPassword);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.label6);
            this.groupBox1.Controls.Add(this.lblPassword);
            this.groupBox1.Controls.Add(this.txtTitle);
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.txtApplication);
            this.groupBox1.Controls.Add(this.label4);
            this.groupBox1.Controls.Add(this.txtServer);
            this.groupBox1.Controls.Add(this.lstProtocol);
            this.groupBox1.Controls.Add(this.txtPassword);
            this.groupBox1.Controls.Add(this.label5);
            this.groupBox1.Controls.Add(this.txtUser);
            this.groupBox1.Location = new System.Drawing.Point(5, 3);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(512, 265);
            this.groupBox1.TabIndex = 103;
            this.groupBox1.TabStop = false;
            // 
            // txtPort
            // 
            this.txtPort.Location = new System.Drawing.Point(335, 127);
            this.txtPort.Name = "txtPort";
            this.txtPort.Size = new System.Drawing.Size(100, 20);
            this.txtPort.TabIndex = 107;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(276, 130);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(26, 13);
            this.label2.TabIndex = 106;
            this.label2.Text = "Port";
            // 
            // lblDescription
            // 
            this.lblDescription.BorderStyle = Gizmox.WebGUI.Forms.BorderStyle.Fixed3D;
            this.lblDescription.Location = new System.Drawing.Point(279, 159);
            this.lblDescription.Name = "lblDescription";
            this.lblDescription.Size = new System.Drawing.Size(209, 91);
            this.lblDescription.TabIndex = 105;
            // 
            // label7
            // 
            this.label7.Location = new System.Drawing.Point(276, 13);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(104, 30);
            this.label7.TabIndex = 104;
            this.label7.Text = "Prompt for Password";
            this.label7.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.label7.Click += new System.EventHandler(this.label7_Click);
            // 
            // cbPromptPassword
            // 
            this.cbPromptPassword.AutoSize = true;
            this.cbPromptPassword.Location = new System.Drawing.Point(386, 22);
            this.cbPromptPassword.Name = "cbPromptPassword";
            this.cbPromptPassword.Size = new System.Drawing.Size(15, 14);
            this.cbPromptPassword.TabIndex = 2;
            this.cbPromptPassword.CheckedChanged += new System.EventHandler(this.checkBox1_CheckedChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(7, 59);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(55, 13);
            this.label1.TabIndex = 2;
            this.label1.Text = "Username";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(7, 19);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(78, 13);
            this.label6.TabIndex = 102;
            this.label6.Text = "Shortcut Name";
            // 
            // lblPassword
            // 
            this.lblPassword.AutoSize = true;
            this.lblPassword.Location = new System.Drawing.Point(276, 59);
            this.lblPassword.Name = "lblPassword";
            this.lblPassword.Size = new System.Drawing.Size(53, 13);
            this.lblPassword.TabIndex = 3;
            this.lblPassword.Text = "Password";
            this.lblPassword.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // txtTitle
            // 
            this.txtTitle.Location = new System.Drawing.Point(117, 19);
            this.txtTitle.Name = "txtTitle";
            this.txtTitle.Size = new System.Drawing.Size(153, 20);
            this.txtTitle.TabIndex = 1;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(16, 95);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(38, 13);
            this.label3.TabIndex = 4;
            this.label3.Text = "Server";
            // 
            // txtApplication
            // 
            this.txtApplication.Location = new System.Drawing.Point(335, 95);
            this.txtApplication.Name = "txtApplication";
            this.txtApplication.Size = new System.Drawing.Size(153, 20);
            this.txtApplication.TabIndex = 6;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(276, 95);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(59, 13);
            this.label4.TabIndex = 5;
            this.label4.Text = "Application";
            // 
            // txtServer
            // 
            this.txtServer.Location = new System.Drawing.Point(117, 92);
            this.txtServer.Name = "txtServer";
            this.txtServer.Size = new System.Drawing.Size(153, 20);
            this.txtServer.TabIndex = 5;
            // 
            // lstProtocol
            // 
            this.lstProtocol.FormattingEnabled = true;
            this.lstProtocol.Location = new System.Drawing.Point(117, 130);
            this.lstProtocol.Name = "lstProtocol";
            this.lstProtocol.Size = new System.Drawing.Size(153, 121);
            this.lstProtocol.TabIndex = 7;
            this.lstProtocol.SelectedIndexChanged += new System.EventHandler(this.lstProtocol_SelectedIndexChanged);
            // 
            // txtPassword
            // 
            this.txtPassword.Location = new System.Drawing.Point(335, 56);
            this.txtPassword.Name = "txtPassword";
            this.txtPassword.PasswordChar = '*';
            this.txtPassword.Size = new System.Drawing.Size(153, 20);
            this.txtPassword.TabIndex = 4;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(16, 130);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(46, 13);
            this.label5.TabIndex = 7;
            this.label5.Text = "Protocol";
            // 
            // txtUser
            // 
            this.txtUser.Location = new System.Drawing.Point(117, 56);
            this.txtUser.Name = "txtUser";
            this.txtUser.Size = new System.Drawing.Size(153, 20);
            this.txtUser.TabIndex = 3;
            // 
            // btnCancel
            // 
            this.btnCancel.Location = new System.Drawing.Point(418, 274);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(75, 23);
            this.btnCancel.TabIndex = 105;
            this.btnCancel.Text = "Cancel";
            this.btnCancel.Click += new System.EventHandler(this.btnCancel_Click);
            // 
            // btnOK
            // 
            this.btnOK.Location = new System.Drawing.Point(331, 274);
            this.btnOK.Name = "btnOK";
            this.btnOK.Size = new System.Drawing.Size(75, 23);
            this.btnOK.TabIndex = 104;
            this.btnOK.Text = "OK";
            this.btnOK.Click += new System.EventHandler(this.btnOK_Click);
            // 
            // frmShortcut
            // 
            this.ClientSize = new System.Drawing.Size(523, 305);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.btnCancel);
            this.Controls.Add(this.btnOK);
            this.FormBorderStyle = Gizmox.WebGUI.Forms.FormBorderStyle.FixedToolWindow;
            this.Name = "frmShortcut";
            this.Text = "Shortcut";
            this.Load += new System.EventHandler(this.frmShortcut_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private Gizmox.WebGUI.Forms.GroupBox groupBox1;
        private Gizmox.WebGUI.Forms.Label label1;
        private Gizmox.WebGUI.Forms.Label lblPassword;
        private Gizmox.WebGUI.Forms.Label label3;
        private Gizmox.WebGUI.Forms.Label label4;
        private Gizmox.WebGUI.Forms.Label label5;
        private Gizmox.WebGUI.Forms.Label label6;
        private Gizmox.WebGUI.Forms.Button btnCancel;
        private Gizmox.WebGUI.Forms.Button btnOK;
        private Gizmox.WebGUI.Forms.Label label7;
        private Gizmox.WebGUI.Forms.Label lblDescription;
        internal Gizmox.WebGUI.Forms.TextBox txtApplication;
        internal Gizmox.WebGUI.Forms.TextBox txtServer;
        internal Gizmox.WebGUI.Forms.ListBox lstProtocol;
        internal Gizmox.WebGUI.Forms.TextBox txtPassword;
        internal Gizmox.WebGUI.Forms.TextBox txtUser;
        internal Gizmox.WebGUI.Forms.TextBox txtTitle;
        internal Gizmox.WebGUI.Forms.CheckBox cbPromptPassword;
        private Gizmox.WebGUI.Forms.TextBox txtPort;
        private Gizmox.WebGUI.Forms.Label label2;
    }
}
