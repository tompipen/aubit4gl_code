namespace AubitDesktop
{
    partial class mainfrm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(mainfrm));
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.exitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.connectionsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.enableListeningModeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tpShortcuts = new System.Windows.Forms.TabPage();
            this.lstShortcuts = new System.Windows.Forms.ListBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.btnShortcutExecute = new System.Windows.Forms.Button();
            this.btnShortcutEdit = new System.Windows.Forms.Button();
            this.btnShortcutRemove = new System.Windows.Forms.Button();
            this.btnShortcutAdd = new System.Windows.Forms.Button();
            this.tpOptions = new System.Windows.Forms.TabPage();
            this.lstIPAddress = new System.Windows.Forms.ListBox();
            this.tpConnections = new System.Windows.Forms.TabPage();
            this.lstConnections = new System.Windows.Forms.DataGridView();
            this.grName = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.grId = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.grDate = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Direction = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.cbAllowExec = new System.Windows.Forms.CheckBox();
            this.cbSendFile = new System.Windows.Forms.CheckBox();
            this.cbReceiveFile = new System.Windows.Forms.CheckBox();
            this.tbInterruptKey = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.lblKeyCode = new System.Windows.Forms.Label();
            this.menuStrip1.SuspendLayout();
            this.tabControl1.SuspendLayout();
            this.tpShortcuts.SuspendLayout();
            this.groupBox2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.tpOptions.SuspendLayout();
            this.tpConnections.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.lstConnections)).BeginInit();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.connectionsToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(399, 24);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.exitToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(35, 20);
            this.fileToolStripMenuItem.Text = "&File";
            // 
            // exitToolStripMenuItem
            // 
            this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
            this.exitToolStripMenuItem.Size = new System.Drawing.Size(103, 22);
            this.exitToolStripMenuItem.Text = "E&xit";
            this.exitToolStripMenuItem.Click += new System.EventHandler(this.exitToolStripMenuItem_Click);
            // 
            // connectionsToolStripMenuItem
            // 
            this.connectionsToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.enableListeningModeToolStripMenuItem});
            this.connectionsToolStripMenuItem.Name = "connectionsToolStripMenuItem";
            this.connectionsToolStripMenuItem.Size = new System.Drawing.Size(78, 20);
            this.connectionsToolStripMenuItem.Text = "&Connections";
            // 
            // enableListeningModeToolStripMenuItem
            // 
            this.enableListeningModeToolStripMenuItem.Name = "enableListeningModeToolStripMenuItem";
            this.enableListeningModeToolStripMenuItem.Size = new System.Drawing.Size(188, 22);
            this.enableListeningModeToolStripMenuItem.Text = "Enable &listening mode";
            this.enableListeningModeToolStripMenuItem.Click += new System.EventHandler(this.enableListeningModeToolStripMenuItem_Click);
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tpShortcuts);
            this.tabControl1.Controls.Add(this.tpOptions);
            this.tabControl1.Controls.Add(this.tpConnections);
            this.tabControl1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tabControl1.Location = new System.Drawing.Point(0, 24);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(399, 275);
            this.tabControl1.TabIndex = 1;
            // 
            // tpShortcuts
            // 
            this.tpShortcuts.Controls.Add(this.lstShortcuts);
            this.tpShortcuts.Controls.Add(this.groupBox2);
            this.tpShortcuts.Location = new System.Drawing.Point(4, 22);
            this.tpShortcuts.Name = "tpShortcuts";
            this.tpShortcuts.Padding = new System.Windows.Forms.Padding(3);
            this.tpShortcuts.Size = new System.Drawing.Size(391, 249);
            this.tpShortcuts.TabIndex = 0;
            this.tpShortcuts.Text = "Shortcuts";
            this.tpShortcuts.UseVisualStyleBackColor = true;
            // 
            // lstShortcuts
            // 
            this.lstShortcuts.FormattingEnabled = true;
            this.lstShortcuts.Location = new System.Drawing.Point(3, 6);
            this.lstShortcuts.Name = "lstShortcuts";
            this.lstShortcuts.Size = new System.Drawing.Size(290, 238);
            this.lstShortcuts.TabIndex = 2;
            this.lstShortcuts.SelectedIndexChanged += new System.EventHandler(this.lstShortcuts_SelectedIndexChanged);
            this.lstShortcuts.DoubleClick += new System.EventHandler(this.lstShortcuts_DoubleClick);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.pictureBox1);
            this.groupBox2.Controls.Add(this.btnShortcutExecute);
            this.groupBox2.Controls.Add(this.btnShortcutEdit);
            this.groupBox2.Controls.Add(this.btnShortcutRemove);
            this.groupBox2.Controls.Add(this.btnShortcutAdd);
            this.groupBox2.Location = new System.Drawing.Point(299, 0);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(86, 245);
            this.groupBox2.TabIndex = 3;
            this.groupBox2.TabStop = false;
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = global::AubitDesktop.Properties.Resources.Aubit;
            this.pictureBox1.Location = new System.Drawing.Point(17, 192);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(54, 47);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox1.TabIndex = 10;
            this.pictureBox1.TabStop = false;
            // 
            // btnShortcutExecute
            // 
            this.btnShortcutExecute.Location = new System.Drawing.Point(6, 128);
            this.btnShortcutExecute.Name = "btnShortcutExecute";
            this.btnShortcutExecute.Size = new System.Drawing.Size(75, 23);
            this.btnShortcutExecute.TabIndex = 3;
            this.btnShortcutExecute.Text = "Execute";
            this.btnShortcutExecute.UseVisualStyleBackColor = true;
            this.btnShortcutExecute.Click += new System.EventHandler(this.btnShortcutExecute_Click);
            // 
            // btnShortcutEdit
            // 
            this.btnShortcutEdit.Location = new System.Drawing.Point(6, 77);
            this.btnShortcutEdit.Name = "btnShortcutEdit";
            this.btnShortcutEdit.Size = new System.Drawing.Size(75, 23);
            this.btnShortcutEdit.TabIndex = 2;
            this.btnShortcutEdit.Text = "Edit";
            this.btnShortcutEdit.UseVisualStyleBackColor = true;
            this.btnShortcutEdit.Click += new System.EventHandler(this.btnShortcutEdit_Click);
            // 
            // btnShortcutRemove
            // 
            this.btnShortcutRemove.Location = new System.Drawing.Point(6, 48);
            this.btnShortcutRemove.Name = "btnShortcutRemove";
            this.btnShortcutRemove.Size = new System.Drawing.Size(75, 23);
            this.btnShortcutRemove.TabIndex = 1;
            this.btnShortcutRemove.Text = "Remove";
            this.btnShortcutRemove.UseVisualStyleBackColor = true;
            // 
            // btnShortcutAdd
            // 
            this.btnShortcutAdd.Location = new System.Drawing.Point(6, 19);
            this.btnShortcutAdd.Name = "btnShortcutAdd";
            this.btnShortcutAdd.Size = new System.Drawing.Size(75, 23);
            this.btnShortcutAdd.TabIndex = 0;
            this.btnShortcutAdd.Text = "Add";
            this.btnShortcutAdd.UseVisualStyleBackColor = true;
            this.btnShortcutAdd.Click += new System.EventHandler(this.btnShortcutAdd_Click);
            // 
            // tpOptions
            // 
            this.tpOptions.Controls.Add(this.lblKeyCode);
            this.tpOptions.Controls.Add(this.label1);
            this.tpOptions.Controls.Add(this.tbInterruptKey);
            this.tpOptions.Controls.Add(this.cbReceiveFile);
            this.tpOptions.Controls.Add(this.cbSendFile);
            this.tpOptions.Controls.Add(this.cbAllowExec);
            this.tpOptions.Controls.Add(this.lstIPAddress);
            this.tpOptions.Location = new System.Drawing.Point(4, 22);
            this.tpOptions.Name = "tpOptions";
            this.tpOptions.Padding = new System.Windows.Forms.Padding(3);
            this.tpOptions.Size = new System.Drawing.Size(391, 249);
            this.tpOptions.TabIndex = 1;
            this.tpOptions.Text = "Options";
            this.tpOptions.UseVisualStyleBackColor = true;
            // 
            // lstIPAddress
            // 
            this.lstIPAddress.FormattingEnabled = true;
            this.lstIPAddress.Location = new System.Drawing.Point(8, 6);
            this.lstIPAddress.Name = "lstIPAddress";
            this.lstIPAddress.Size = new System.Drawing.Size(375, 95);
            this.lstIPAddress.TabIndex = 11;
            // 
            // tpConnections
            // 
            this.tpConnections.Controls.Add(this.lstConnections);
            this.tpConnections.Location = new System.Drawing.Point(4, 22);
            this.tpConnections.Name = "tpConnections";
            this.tpConnections.Size = new System.Drawing.Size(391, 249);
            this.tpConnections.TabIndex = 2;
            this.tpConnections.Text = "Connections";
            this.tpConnections.UseVisualStyleBackColor = true;
            // 
            // lstConnections
            // 
            this.lstConnections.AllowUserToAddRows = false;
            this.lstConnections.AllowUserToDeleteRows = false;
            this.lstConnections.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.lstConnections.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.grName,
            this.grId,
            this.grDate,
            this.Direction});
            this.lstConnections.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lstConnections.EditMode = System.Windows.Forms.DataGridViewEditMode.EditProgrammatically;
            this.lstConnections.EnableHeadersVisualStyles = false;
            this.lstConnections.Location = new System.Drawing.Point(0, 0);
            this.lstConnections.Name = "lstConnections";
            this.lstConnections.ReadOnly = true;
            this.lstConnections.RowHeadersVisible = false;
            this.lstConnections.Size = new System.Drawing.Size(391, 249);
            this.lstConnections.TabIndex = 1;
            // 
            // grName
            // 
            this.grName.FillWeight = 50F;
            this.grName.HeaderText = " Name";
            this.grName.Name = "grName";
            this.grName.ReadOnly = true;
            // 
            // grId
            // 
            this.grId.FillWeight = 10F;
            this.grId.HeaderText = "Id";
            this.grId.Name = "grId";
            this.grId.ReadOnly = true;
            this.grId.Width = 50;
            // 
            // grDate
            // 
            this.grDate.FillWeight = 10F;
            this.grDate.HeaderText = "Date";
            this.grDate.Name = "grDate";
            this.grDate.ReadOnly = true;
            this.grDate.Width = 75;
            // 
            // Direction
            // 
            this.Direction.FillWeight = 10F;
            this.Direction.HeaderText = "Direction";
            this.Direction.Name = "Direction";
            this.Direction.ReadOnly = true;
            this.Direction.Width = 60;
            // 
            // timer1
            // 
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // cbAllowExec
            // 
            this.cbAllowExec.AutoSize = true;
            this.cbAllowExec.Location = new System.Drawing.Point(270, 107);
            this.cbAllowExec.Name = "cbAllowExec";
            this.cbAllowExec.Size = new System.Drawing.Size(93, 17);
            this.cbAllowExec.TabIndex = 12;
            this.cbAllowExec.Text = "Allow Execute";
            this.cbAllowExec.UseVisualStyleBackColor = true;
            // 
            // cbSendFile
            // 
            this.cbSendFile.AutoSize = true;
            this.cbSendFile.Location = new System.Drawing.Point(270, 128);
            this.cbSendFile.Name = "cbSendFile";
            this.cbSendFile.Size = new System.Drawing.Size(98, 17);
            this.cbSendFile.TabIndex = 13;
            this.cbSendFile.Text = "Allow Send File";
            this.cbSendFile.UseVisualStyleBackColor = true;
            // 
            // cbReceiveFile
            // 
            this.cbReceiveFile.AutoSize = true;
            this.cbReceiveFile.Location = new System.Drawing.Point(270, 149);
            this.cbReceiveFile.Name = "cbReceiveFile";
            this.cbReceiveFile.Size = new System.Drawing.Size(113, 17);
            this.cbReceiveFile.TabIndex = 14;
            this.cbReceiveFile.Text = "Allow Receive File";
            this.cbReceiveFile.UseVisualStyleBackColor = true;
            // 
            // tbInterruptKey
            // 
            this.tbInterruptKey.Location = new System.Drawing.Point(81, 111);
            this.tbInterruptKey.Name = "tbInterruptKey";
            this.tbInterruptKey.Size = new System.Drawing.Size(100, 20);
            this.tbInterruptKey.TabIndex = 15;
            this.tbInterruptKey.TextChanged += new System.EventHandler(this.tbInterruptKey_TextChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(8, 111);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(67, 13);
            this.label1.TabIndex = 16;
            this.label1.Text = "Interrupt Key";
            // 
            // lblKeyCode
            // 
            this.lblKeyCode.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.lblKeyCode.Location = new System.Drawing.Point(81, 134);
            this.lblKeyCode.Name = "lblKeyCode";
            this.lblKeyCode.Size = new System.Drawing.Size(100, 23);
            this.lblKeyCode.TabIndex = 17;
            // 
            // mainfrm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(399, 299);
            this.Controls.Add(this.tabControl1);
            this.Controls.Add(this.menuStrip1);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "mainfrm";
            this.Text = "Aubit Desktop";
            this.Load += new System.EventHandler(this.mainfrm_Load);
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.mainfrm_FormClosed);
            this.Move += new System.EventHandler(this.mainfrm_Move);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.tabControl1.ResumeLayout(false);
            this.tpShortcuts.ResumeLayout(false);
            this.groupBox2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.tpOptions.ResumeLayout(false);
            this.tpOptions.PerformLayout();
            this.tpConnections.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.lstConnections)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem connectionsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem enableListeningModeToolStripMenuItem;
        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tpShortcuts;
        private System.Windows.Forms.TabPage tpOptions;
        private System.Windows.Forms.TabPage tpConnections;
        private System.Windows.Forms.ListBox lstShortcuts;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Button btnShortcutExecute;
        private System.Windows.Forms.Button btnShortcutEdit;
        private System.Windows.Forms.Button btnShortcutRemove;
        private System.Windows.Forms.Button btnShortcutAdd;
        private System.Windows.Forms.DataGridView lstConnections;
        private System.Windows.Forms.DataGridViewTextBoxColumn grName;
        private System.Windows.Forms.DataGridViewTextBoxColumn grId;
        private System.Windows.Forms.DataGridViewTextBoxColumn grDate;
        private System.Windows.Forms.DataGridViewTextBoxColumn Direction;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.ListBox lstIPAddress;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox tbInterruptKey;
        private System.Windows.Forms.CheckBox cbReceiveFile;
        private System.Windows.Forms.CheckBox cbSendFile;
        private System.Windows.Forms.CheckBox cbAllowExec;
        private System.Windows.Forms.Label lblKeyCode;
    }
}