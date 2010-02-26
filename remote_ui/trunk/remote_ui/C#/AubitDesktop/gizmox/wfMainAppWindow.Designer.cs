namespace AubitDesktop
{
    partial class frmMainAppWindow
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
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmMainAppWindow));
            this.statusBar1 = new Gizmox.WebGUI.Forms.StatusBar();
            this.sbLineDisplayText = new Gizmox.WebGUI.Forms.StatusBarPanel();
            this.sbErrorText = new Gizmox.WebGUI.Forms.StatusBarPanel();
            this.sbMessageText = new Gizmox.WebGUI.Forms.StatusBarPanel();
            this.sbCommentText = new Gizmox.WebGUI.Forms.StatusBarPanel();
            this.btnPanel = new Gizmox.WebGUI.Forms.StatusBarPanel();
            this.topWindowToolStrip = new Gizmox.WebGUI.Forms.ToolBar();
            this.toolBarButton1 = new Gizmox.WebGUI.Forms.ToolBarButton();
            this.About = new Gizmox.WebGUI.Forms.ToolBarButton();
            this.timer1 = new Gizmox.WebGUI.Forms.Timer(this.components);
            this.timer2 = new Gizmox.WebGUI.Forms.Timer(this.components);
            this.mainAppPanel = new Gizmox.WebGUI.Forms.Panel();
            this.gbWinQuestion = new Gizmox.WebGUI.Forms.GroupBox();
            this.buttonBox = new Gizmox.WebGUI.Forms.FlowLayoutPanel();
            this.lblText = new Gizmox.WebGUI.Forms.Label();
            this.lblPb = new Gizmox.WebGUI.Forms.Label();
            this.loginPanel = new Gizmox.WebGUI.Forms.Panel();
            this.panel2 = new Gizmox.WebGUI.Forms.Panel();
            this.cbApplications = new Gizmox.WebGUI.Forms.ComboBox();
            this.label4 = new Gizmox.WebGUI.Forms.Label();
            this.btnLogin = new Gizmox.WebGUI.Forms.Button();
            this.label1 = new Gizmox.WebGUI.Forms.Label();
            this.label2 = new Gizmox.WebGUI.Forms.Label();
            this.txtUsername = new Gizmox.WebGUI.Forms.TextBox();
            this.txtPassword = new Gizmox.WebGUI.Forms.TextBox();
            this.label3 = new Gizmox.WebGUI.Forms.Label();
            this.button1 = new Gizmox.WebGUI.Forms.Button();
            this.groupBox1 = new Gizmox.WebGUI.Forms.GroupBox();
            this.iconPB = new Gizmox.WebGUI.Forms.PictureBox();
            this.MenuBarPanel = new Gizmox.WebGUI.Forms.Panel();
            this.gbDebugDump = new Gizmox.WebGUI.Forms.GroupBox();
            this.button2 = new Gizmox.WebGUI.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.sbLineDisplayText)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.sbErrorText)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.sbMessageText)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.sbCommentText)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.btnPanel)).BeginInit();
            this.SuspendLayout();
            // 
            // statusBar1
            // 
            this.statusBar1.Anchor = Gizmox.WebGUI.Forms.AnchorStyles.None;
            this.statusBar1.Dock = Gizmox.WebGUI.Forms.DockStyle.Bottom;
            this.statusBar1.Location = new System.Drawing.Point(0, 554);
            this.statusBar1.Name = "statusBar1";
            this.statusBar1.Panels.AddRange(new Gizmox.WebGUI.Forms.StatusBarPanel[] {
            this.sbLineDisplayText,
            this.sbErrorText,
            this.sbMessageText,
            this.sbCommentText,
            this.btnPanel});
            this.statusBar1.ShowPanels = true;
            this.statusBar1.Size = new System.Drawing.Size(847, 22);
            this.statusBar1.TabIndex = 0;
            this.statusBar1.Click += new System.EventHandler(this.statusBar1_Click);
            // 
            // sbLineDisplayText
            // 
            this.sbLineDisplayText.AutoSize = Gizmox.WebGUI.Forms.StatusBarPanelAutoSize.Contents;
            this.sbLineDisplayText.Text = "LD";
            // 
            // sbErrorText
            // 
            this.sbErrorText.AutoSize = Gizmox.WebGUI.Forms.StatusBarPanelAutoSize.Spring;
            this.sbErrorText.Text = "ErrorText";
            // 
            // sbMessageText
            // 
            this.sbMessageText.AutoSize = Gizmox.WebGUI.Forms.StatusBarPanelAutoSize.Spring;
            this.sbMessageText.Text = "M";
            // 
            // sbCommentText
            // 
            this.sbCommentText.AutoSize = Gizmox.WebGUI.Forms.StatusBarPanelAutoSize.Spring;
            this.sbCommentText.Text = "C";
            // 
            // btnPanel
            // 
            this.btnPanel.AutoSize = Gizmox.WebGUI.Forms.StatusBarPanelAutoSize.None;
            this.btnPanel.Text = "btnPanel";
            // 
            // topWindowToolStrip
            // 
            this.topWindowToolStrip.Anchor = Gizmox.WebGUI.Forms.AnchorStyles.None;
            this.topWindowToolStrip.Appearance = Gizmox.WebGUI.Forms.ToolBarAppearance.Normal;
            this.topWindowToolStrip.Buttons.AddRange(new Gizmox.WebGUI.Forms.ToolBarButton[] {
            this.toolBarButton1,
            this.About});
            this.topWindowToolStrip.ButtonSize = new System.Drawing.Size(25, 25);
            this.topWindowToolStrip.Dock = Gizmox.WebGUI.Forms.DockStyle.Top;
            this.topWindowToolStrip.DragHandle = true;
            this.topWindowToolStrip.DropDownArrows = false;
            this.topWindowToolStrip.ImageList = null;
            this.topWindowToolStrip.ImageSize = new System.Drawing.Size(16, 16);
            this.topWindowToolStrip.Location = new System.Drawing.Point(0, 0);
            this.topWindowToolStrip.MenuHandle = true;
            this.topWindowToolStrip.Name = "topWindowToolStrip";
            this.topWindowToolStrip.ShowToolTips = true;
            this.topWindowToolStrip.Size = new System.Drawing.Size(847, 42);
            this.topWindowToolStrip.TabIndex = 2;
            this.topWindowToolStrip.Click += new System.EventHandler(this.topWindowToolStrip_Click);
            this.topWindowToolStrip.ButtonClick += new Gizmox.WebGUI.Forms.ToolBarButtonClickEventHandler(this.topWindowToolStrip_ButtonClick);
            // 
            // toolBarButton1
            // 
            this.toolBarButton1.CustomStyle = "";
            this.toolBarButton1.Font = new System.Drawing.Font("Tahoma", 8.25F);
            this.toolBarButton1.Name = "toolBarButton1";
            this.toolBarButton1.Pushed = true;
            this.toolBarButton1.Size = 24;
            this.toolBarButton1.Style = Gizmox.WebGUI.Forms.ToolBarButtonStyle.Separator;
            this.toolBarButton1.ToolTipText = "";
            // 
            // About
            // 
            this.About.CustomStyle = "";
            this.About.Font = new System.Drawing.Font("Tahoma", 8.25F);
            this.About.Image = ((Gizmox.WebGUI.Common.Resources.ResourceHandle)(resources.GetObject("About.Image")));
            this.About.Name = "About";
            this.About.Pushed = true;
            this.About.Size = 24;
            this.About.Text = "About";
            this.About.ToolTipText = "About the viewer";
            // 
            // timer1
            // 
            this.timer1.Interval = 10000;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // timer2
            // 
            this.timer2.Interval = 10000;
            this.timer2.Tick += new System.EventHandler(this.timer2_Tick);
            // 
            // mainAppPanel
            // 
            this.mainAppPanel.Anchor = Gizmox.WebGUI.Forms.AnchorStyles.None;
            this.mainAppPanel.BorderStyle = Gizmox.WebGUI.Forms.BorderStyle.Clear;
            this.mainAppPanel.Controls.Add(this.gbWinQuestion);
            this.mainAppPanel.Controls.Add(this.loginPanel);
            this.mainAppPanel.Dock = Gizmox.WebGUI.Forms.DockStyle.Fill;
            this.mainAppPanel.Location = new System.Drawing.Point(0, 28);
            this.mainAppPanel.Name = "mainAppPanel";
            this.mainAppPanel.Size = new System.Drawing.Size(847, 512);
            this.mainAppPanel.TabIndex = 4;
            // 
            // gbWinQuestion
            // 
            this.gbWinQuestion.BackColor = System.Drawing.SystemColors.Control;
            this.gbWinQuestion.BorderStyle = Gizmox.WebGUI.Forms.BorderStyle.Fixed3D;
            this.gbWinQuestion.Controls.Add(this.buttonBox);
            this.gbWinQuestion.Controls.Add(this.lblText);
            this.gbWinQuestion.Controls.Add(this.lblPb);
            this.gbWinQuestion.FlatStyle = Gizmox.WebGUI.Forms.FlatStyle.Flat;
            this.gbWinQuestion.Location = new System.Drawing.Point(139, 26);
            this.gbWinQuestion.Name = "gbWinQuestion";
            this.gbWinQuestion.Size = new System.Drawing.Size(323, 100);
            this.gbWinQuestion.TabIndex = 1;
            this.gbWinQuestion.TabStop = false;
            this.gbWinQuestion.Text = "winQuestion";
            this.gbWinQuestion.Visible = false;
            this.gbWinQuestion.VisibleChanged += new System.EventHandler(this.gbWinQuestion_VisibleChanged);
            // 
            // buttonBox
            // 
            this.buttonBox.Anchor = Gizmox.WebGUI.Forms.AnchorStyles.None;
            this.buttonBox.AutoSize = true;
            this.buttonBox.Dock = Gizmox.WebGUI.Forms.DockStyle.Bottom;
            this.buttonBox.FlowDirection = Gizmox.WebGUI.Forms.FlowDirection.LeftToRight;
            this.buttonBox.Location = new System.Drawing.Point(3, 97);
            this.buttonBox.Name = "buttonBox";
            this.buttonBox.Size = new System.Drawing.Size(250, 0);
            this.buttonBox.TabIndex = 2;
            this.buttonBox.WrapContents = false;
            // 
            // lblText
            // 
            this.lblText.Anchor = Gizmox.WebGUI.Forms.AnchorStyles.None;
            this.lblText.Dock = Gizmox.WebGUI.Forms.DockStyle.Fill;
            this.lblText.Location = new System.Drawing.Point(3, 16);
            this.lblText.Name = "lblText";
            this.lblText.Size = new System.Drawing.Size(250, 81);
            this.lblText.TabIndex = 0;
            this.lblText.Text = "label5";
            // 
            // lblPb
            // 
            this.lblPb.Anchor = Gizmox.WebGUI.Forms.AnchorStyles.None;
            this.lblPb.Dock = Gizmox.WebGUI.Forms.DockStyle.Right;
            this.lblPb.Location = new System.Drawing.Point(253, 16);
            this.lblPb.Name = "lblPb";
            this.lblPb.Size = new System.Drawing.Size(67, 81);
            this.lblPb.TabIndex = 1;
            // 
            // loginPanel
            // 
            this.loginPanel.BorderStyle = Gizmox.WebGUI.Forms.BorderStyle.Clear;
            this.loginPanel.Controls.Add(this.panel2);
            this.loginPanel.Controls.Add(this.label3);
            this.loginPanel.Location = new System.Drawing.Point(139, 132);
            this.loginPanel.Name = "loginPanel";
            this.loginPanel.Size = new System.Drawing.Size(319, 184);
            this.loginPanel.TabIndex = 0;
            // 
            // panel2
            // 
            this.panel2.BorderStyle = Gizmox.WebGUI.Forms.BorderStyle.Clear;
            this.panel2.Controls.Add(this.cbApplications);
            this.panel2.Controls.Add(this.label4);
            this.panel2.Controls.Add(this.btnLogin);
            this.panel2.Controls.Add(this.label1);
            this.panel2.Controls.Add(this.label2);
            this.panel2.Controls.Add(this.txtUsername);
            this.panel2.Controls.Add(this.txtPassword);
            this.panel2.Location = new System.Drawing.Point(51, 38);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(230, 108);
            this.panel2.TabIndex = 5;
            // 
            // cbApplications
            // 
            this.cbApplications.BorderStyle = Gizmox.WebGUI.Forms.BorderStyle.Fixed3D;
            this.cbApplications.Location = new System.Drawing.Point(98, 55);
            this.cbApplications.MaxDropDownItems = 8;
            this.cbApplications.Name = "cbApplications";
            this.cbApplications.Size = new System.Drawing.Size(121, 21);
            this.cbApplications.TabIndex = 3;
            this.cbApplications.Text = "comboBox1";
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
            this.btnLogin.Location = new System.Drawing.Point(142, 82);
            this.btnLogin.Name = "btnLogin";
            this.btnLogin.Size = new System.Drawing.Size(75, 23);
            this.btnLogin.TabIndex = 4;
            this.btnLogin.Text = "Login";
            this.btnLogin.Click += new System.EventHandler(this.frm_doLoginHandler);
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
            this.txtUsername.BorderStyle = Gizmox.WebGUI.Forms.BorderStyle.Fixed3D;
            this.txtUsername.Location = new System.Drawing.Point(98, 8);
            this.txtUsername.Name = "txtUsername";
            this.txtUsername.Size = new System.Drawing.Size(119, 20);
            this.txtUsername.TabIndex = 0;
            // 
            // txtPassword
            // 
            this.txtPassword.BorderStyle = Gizmox.WebGUI.Forms.BorderStyle.Fixed3D;
            this.txtPassword.Location = new System.Drawing.Point(98, 31);
            this.txtPassword.Name = "txtPassword";
            this.txtPassword.PasswordChar = '*';
            this.txtPassword.Size = new System.Drawing.Size(119, 20);
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
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(515, 426);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 1;
            this.button1.Text = "button1";
            // 
            // groupBox1
            // 
            this.groupBox1.Anchor = Gizmox.WebGUI.Forms.AnchorStyles.None;
            this.groupBox1.Controls.Add(this.iconPB);
            this.groupBox1.Controls.Add(this.MenuBarPanel);
            this.groupBox1.Controls.Add(this.gbDebugDump);
            this.groupBox1.Dock = Gizmox.WebGUI.Forms.DockStyle.Right;
            this.groupBox1.FlatStyle = Gizmox.WebGUI.Forms.FlatStyle.Flat;
            this.groupBox1.Location = new System.Drawing.Point(691, 42);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(156, 512);
            this.groupBox1.TabIndex = 5;
            this.groupBox1.TabStop = false;
            // 
            // iconPB
            // 
            this.iconPB.Anchor = Gizmox.WebGUI.Forms.AnchorStyles.None;
            this.iconPB.Dock = Gizmox.WebGUI.Forms.DockStyle.Bottom;
            this.iconPB.Image = ((Gizmox.WebGUI.Common.Resources.ResourceHandle)(resources.GetObject("iconPB.Image")));
            this.iconPB.Location = new System.Drawing.Point(3, 414);
            this.iconPB.Name = "iconPB";
            this.iconPB.Size = new System.Drawing.Size(150, 95);
            this.iconPB.SizeMode = Gizmox.WebGUI.Forms.PictureBoxSizeMode.CenterImage;
            this.iconPB.TabIndex = 0;
            this.iconPB.TabStop = false;
            // 
            // MenuBarPanel
            // 
            this.MenuBarPanel.Anchor = Gizmox.WebGUI.Forms.AnchorStyles.None;
            this.MenuBarPanel.BorderStyle = Gizmox.WebGUI.Forms.BorderStyle.Clear;
            this.MenuBarPanel.Dock = Gizmox.WebGUI.Forms.DockStyle.Fill;
            this.MenuBarPanel.Location = new System.Drawing.Point(3, 53);
            this.MenuBarPanel.MinimumSize = new System.Drawing.Size(167, 449);
            this.MenuBarPanel.Name = "MenuBarPanel";
            this.MenuBarPanel.Size = new System.Drawing.Size(167, 455);
            this.MenuBarPanel.TabIndex = 1;
            this.MenuBarPanel.Click += new System.EventHandler(this.MenuBarPanel_Click);
            // 
            // gbDebugDump
            // 
            this.gbDebugDump.Anchor = Gizmox.WebGUI.Forms.AnchorStyles.None;
            this.gbDebugDump.Controls.Add(this.button2);
            this.gbDebugDump.Dock = Gizmox.WebGUI.Forms.DockStyle.Top;
            this.gbDebugDump.FlatStyle = Gizmox.WebGUI.Forms.FlatStyle.Flat;
            this.gbDebugDump.Location = new System.Drawing.Point(3, 16);
            this.gbDebugDump.Name = "gbDebugDump";
            this.gbDebugDump.Size = new System.Drawing.Size(150, 37);
            this.gbDebugDump.TabIndex = 2;
            this.gbDebugDump.TabStop = false;
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(6, 8);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(135, 23);
            this.button2.TabIndex = 0;
            this.button2.Text = "Debug Dump";
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // frmMainAppWindow
            // 
            this.AcceptButton = this.btnLogin;
            this.AutoScroll = true;
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.mainAppPanel);
            this.Controls.Add(this.topWindowToolStrip);
            this.Controls.Add(this.statusBar1);
            this.Size = new System.Drawing.Size(847, 576);
            this.Text = "wfMainAppWindow";
            this.Load += new System.EventHandler(this.frmMainAppWindow_Load);
            ((System.ComponentModel.ISupportInitialize)(this.sbLineDisplayText)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.sbErrorText)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.sbMessageText)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.sbCommentText)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.btnPanel)).EndInit();
            this.ResumeLayout(false);

        }



        #endregion

        public Gizmox.WebGUI.Forms.StatusBar statusBar1;
        public Gizmox.WebGUI.Forms.StatusBarPanel sbLineDisplayText;
        public Gizmox.WebGUI.Forms.StatusBarPanel sbErrorText;
        public Gizmox.WebGUI.Forms.StatusBarPanel sbMessageText;
        public Gizmox.WebGUI.Forms.StatusBarPanel sbCommentText;
        public Gizmox.WebGUI.Forms.ToolBar topWindowToolStrip;
        private Gizmox.WebGUI.Forms.ToolBarButton toolBarButton1;
        private Gizmox.WebGUI.Forms.Timer timer1;
        private Gizmox.WebGUI.Forms.Timer timer2;
        private Gizmox.WebGUI.Forms.Panel mainAppPanel;
        public Gizmox.WebGUI.Forms.Panel loginPanel;
        public Gizmox.WebGUI.Forms.Panel panel2;
        public Gizmox.WebGUI.Forms.Label label4;
        public Gizmox.WebGUI.Forms.Button btnLogin;
        public Gizmox.WebGUI.Forms.Label label1;
        public Gizmox.WebGUI.Forms.Label label2;
        public Gizmox.WebGUI.Forms.TextBox txtUsername;
        public Gizmox.WebGUI.Forms.TextBox txtPassword;
        public Gizmox.WebGUI.Forms.Label label3;
        private Gizmox.WebGUI.Forms.ToolBarButton About;
        private Gizmox.WebGUI.Forms.StatusBarPanel btnPanel;
        private Gizmox.WebGUI.Forms.Button button1;
        private Gizmox.WebGUI.Forms.GroupBox groupBox1;
        private Gizmox.WebGUI.Forms.PictureBox iconPB;
        public Gizmox.WebGUI.Forms.Panel MenuBarPanel;
        private Gizmox.WebGUI.Forms.GroupBox gbDebugDump;
        private Gizmox.WebGUI.Forms.Button button2;
        private Gizmox.WebGUI.Forms.ComboBox cbApplications;
        private Gizmox.WebGUI.Forms.GroupBox gbWinQuestion;
        private Gizmox.WebGUI.Forms.FlowLayoutPanel buttonBox;
        private Gizmox.WebGUI.Forms.Label lblPb;
        private Gizmox.WebGUI.Forms.Label lblText;


    }
}
