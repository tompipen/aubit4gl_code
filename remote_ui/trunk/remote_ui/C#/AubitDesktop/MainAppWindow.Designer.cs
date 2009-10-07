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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmMainAppWindow));
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.toolStripProgressBar2 = new System.Windows.Forms.ToolStripProgressBar();
            this.lblComment = new System.Windows.Forms.ToolStripStatusLabel();
            this.lblMessage = new System.Windows.Forms.ToolStripStatusLabel();
            this.lblError = new System.Windows.Forms.ToolStripStatusLabel();
            this.lblLineDisplay = new System.Windows.Forms.ToolStripStatusLabel();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.exitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.editToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.copyToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.pasteToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.cutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.enableEditModeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.helpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.applicationHelpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.aubit4GLGUIHelpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.aboutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.viewToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menubarToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.alwaysMenubarToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.neverMenubarToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.autoMenubarToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.applicationLauncherToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.alwaysALToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.neverALToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.autoALToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.loadToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolbarToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.alwaysToolbarToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.neverToolbarToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.autoToolbarToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.saveWindowToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.macroEditorToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.topWindowToolStrip = new System.Windows.Forms.ToolStrip();
            this.splitContainer1 = new System.Windows.Forms.SplitContainer();
            this.splitContainer2 = new System.Windows.Forms.SplitContainer();
            this.applicationLauncherPanel = new System.Windows.Forms.Panel();
            this.applicationLauncherTreeView = new System.Windows.Forms.TreeView();
            this.panel1 = new System.Windows.Forms.Panel();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.MenuBarPanel = new System.Windows.Forms.Panel();
            this.statusStrip1.SuspendLayout();
            this.menuStrip1.SuspendLayout();
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.Panel2.SuspendLayout();
            this.splitContainer1.SuspendLayout();
            this.splitContainer2.Panel1.SuspendLayout();
            this.splitContainer2.Panel2.SuspendLayout();
            this.splitContainer2.SuspendLayout();
            this.applicationLauncherPanel.SuspendLayout();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // statusStrip1
            // 
            this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripProgressBar2,
            this.lblComment,
            this.lblMessage,
            this.lblError,
            this.lblLineDisplay});
            this.statusStrip1.LayoutStyle = System.Windows.Forms.ToolStripLayoutStyle.HorizontalStackWithOverflow;
            this.statusStrip1.Location = new System.Drawing.Point(0, 617);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(1073, 22);
            this.statusStrip1.TabIndex = 1;
            this.statusStrip1.Text = "statusStrip1";
            // 
            // toolStripProgressBar2
            // 
            this.toolStripProgressBar2.Alignment = System.Windows.Forms.ToolStripItemAlignment.Right;
            this.toolStripProgressBar2.Name = "toolStripProgressBar2";
            this.toolStripProgressBar2.Size = new System.Drawing.Size(100, 16);
            this.toolStripProgressBar2.Click += new System.EventHandler(this.toolStripProgressBar2_Click);
            // 
            // lblComment
            // 
            this.lblComment.Name = "lblComment";
            this.lblComment.Size = new System.Drawing.Size(55, 17);
            this.lblComment.Text = "comments";
            this.lblComment.TextChanged += new System.EventHandler(this.lblComment_TextChanged);
            // 
            // lblMessage
            // 
            this.lblMessage.Name = "lblMessage";
            this.lblMessage.Size = new System.Drawing.Size(49, 17);
            this.lblMessage.Text = "message";
            this.lblMessage.Click += new System.EventHandler(this.lblMessage_Click);
            this.lblMessage.TextChanged += new System.EventHandler(this.lblMessage_TextChanged);
            // 
            // lblError
            // 
            this.lblError.BackColor = System.Drawing.SystemColors.Control;
            this.lblError.Font = new System.Drawing.Font("Arial", 8.25F, System.Drawing.FontStyle.Bold);
            this.lblError.Name = "lblError";
            this.lblError.Size = new System.Drawing.Size(36, 17);
            this.lblError.Text = "error";
            this.lblError.TextChanged += new System.EventHandler(this.lblError_TextChanged);
            // 
            // lblLineDisplay
            // 
            this.lblLineDisplay.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.lblLineDisplay.Name = "lblLineDisplay";
            this.lblLineDisplay.Size = new System.Drawing.Size(60, 17);
            this.lblLineDisplay.Text = "LineDisplay";
            this.lblLineDisplay.TextChanged += new System.EventHandler(this.lblLineDisplay_TextChanged);
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.editToolStripMenuItem,
            this.helpToolStripMenuItem,
            this.viewToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(1073, 24);
            this.menuStrip1.TabIndex = 3;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.exitToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(35, 20);
            this.fileToolStripMenuItem.Text = "File";
            // 
            // exitToolStripMenuItem
            // 
            this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
            this.exitToolStripMenuItem.Size = new System.Drawing.Size(103, 22);
            this.exitToolStripMenuItem.Text = "Exit";
            this.exitToolStripMenuItem.Click += new System.EventHandler(this.exitToolStripMenuItem_Click);
            // 
            // editToolStripMenuItem
            // 
            this.editToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.copyToolStripMenuItem,
            this.pasteToolStripMenuItem,
            this.cutToolStripMenuItem,
            this.enableEditModeToolStripMenuItem});
            this.editToolStripMenuItem.Name = "editToolStripMenuItem";
            this.editToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.editToolStripMenuItem.Text = "Edit";
            // 
            // copyToolStripMenuItem
            // 
            this.copyToolStripMenuItem.Name = "copyToolStripMenuItem";
            this.copyToolStripMenuItem.Size = new System.Drawing.Size(167, 22);
            this.copyToolStripMenuItem.Text = "Copy";
            this.copyToolStripMenuItem.Click += new System.EventHandler(this.copyToolStripMenuItem_Click);
            // 
            // pasteToolStripMenuItem
            // 
            this.pasteToolStripMenuItem.Name = "pasteToolStripMenuItem";
            this.pasteToolStripMenuItem.Size = new System.Drawing.Size(167, 22);
            this.pasteToolStripMenuItem.Text = "Paste";
            this.pasteToolStripMenuItem.Click += new System.EventHandler(this.pasteToolStripMenuItem_Click);
            // 
            // cutToolStripMenuItem
            // 
            this.cutToolStripMenuItem.Name = "cutToolStripMenuItem";
            this.cutToolStripMenuItem.Size = new System.Drawing.Size(167, 22);
            this.cutToolStripMenuItem.Text = "Cut";
            this.cutToolStripMenuItem.Click += new System.EventHandler(this.cutToolStripMenuItem_Click);
            // 
            // enableEditModeToolStripMenuItem
            // 
            this.enableEditModeToolStripMenuItem.Name = "enableEditModeToolStripMenuItem";
            this.enableEditModeToolStripMenuItem.Size = new System.Drawing.Size(167, 22);
            this.enableEditModeToolStripMenuItem.Text = "Enable Edit Mode";
            this.enableEditModeToolStripMenuItem.Click += new System.EventHandler(this.enableEditModeToolStripMenuItem_Click);
            // 
            // helpToolStripMenuItem
            // 
            this.helpToolStripMenuItem.Alignment = System.Windows.Forms.ToolStripItemAlignment.Right;
            this.helpToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.applicationHelpToolStripMenuItem,
            this.aubit4GLGUIHelpToolStripMenuItem,
            this.aboutToolStripMenuItem});
            this.helpToolStripMenuItem.Name = "helpToolStripMenuItem";
            this.helpToolStripMenuItem.ShortcutKeys = System.Windows.Forms.Keys.F1;
            this.helpToolStripMenuItem.Size = new System.Drawing.Size(40, 20);
            this.helpToolStripMenuItem.Text = "Help";
            // 
            // applicationHelpToolStripMenuItem
            // 
            this.applicationHelpToolStripMenuItem.Name = "applicationHelpToolStripMenuItem";
            this.applicationHelpToolStripMenuItem.Size = new System.Drawing.Size(173, 22);
            this.applicationHelpToolStripMenuItem.Text = "Application Help";
            // 
            // aubit4GLGUIHelpToolStripMenuItem
            // 
            this.aubit4GLGUIHelpToolStripMenuItem.Name = "aubit4GLGUIHelpToolStripMenuItem";
            this.aubit4GLGUIHelpToolStripMenuItem.Size = new System.Drawing.Size(173, 22);
            this.aubit4GLGUIHelpToolStripMenuItem.Text = "Aubit4GL GUI Help";
            // 
            // aboutToolStripMenuItem
            // 
            this.aboutToolStripMenuItem.Name = "aboutToolStripMenuItem";
            this.aboutToolStripMenuItem.Size = new System.Drawing.Size(173, 22);
            this.aboutToolStripMenuItem.Text = "About";
            this.aboutToolStripMenuItem.Click += new System.EventHandler(this.aboutToolStripMenuItem_Click);
            // 
            // viewToolStripMenuItem
            // 
            this.viewToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.menubarToolStripMenuItem,
            this.applicationLauncherToolStripMenuItem,
            this.toolbarToolStripMenuItem,
            this.saveWindowToolStripMenuItem,
            this.macroEditorToolStripMenuItem});
            this.viewToolStripMenuItem.Name = "viewToolStripMenuItem";
            this.viewToolStripMenuItem.Size = new System.Drawing.Size(41, 20);
            this.viewToolStripMenuItem.Text = "View";
            // 
            // menubarToolStripMenuItem
            // 
            this.menubarToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.alwaysMenubarToolStripMenuItem,
            this.neverMenubarToolStripMenuItem,
            this.autoMenubarToolStripMenuItem});
            this.menubarToolStripMenuItem.Name = "menubarToolStripMenuItem";
            this.menubarToolStripMenuItem.Size = new System.Drawing.Size(184, 22);
            this.menubarToolStripMenuItem.Text = "Menubar";
            // 
            // alwaysMenubarToolStripMenuItem
            // 
            this.alwaysMenubarToolStripMenuItem.Name = "alwaysMenubarToolStripMenuItem";
            this.alwaysMenubarToolStripMenuItem.Size = new System.Drawing.Size(119, 22);
            this.alwaysMenubarToolStripMenuItem.Text = "Always";
            this.alwaysMenubarToolStripMenuItem.Click += new System.EventHandler(this.alwaysToolStripMenuItem_Click);
            // 
            // neverMenubarToolStripMenuItem
            // 
            this.neverMenubarToolStripMenuItem.Name = "neverMenubarToolStripMenuItem";
            this.neverMenubarToolStripMenuItem.Size = new System.Drawing.Size(119, 22);
            this.neverMenubarToolStripMenuItem.Text = "Never";
            this.neverMenubarToolStripMenuItem.Click += new System.EventHandler(this.neverMenubarToolStripMenuItem_Click);
            // 
            // autoMenubarToolStripMenuItem
            // 
            this.autoMenubarToolStripMenuItem.Name = "autoMenubarToolStripMenuItem";
            this.autoMenubarToolStripMenuItem.Size = new System.Drawing.Size(119, 22);
            this.autoMenubarToolStripMenuItem.Text = "Auto";
            this.autoMenubarToolStripMenuItem.Click += new System.EventHandler(this.autoMenubarToolStripMenuItem_Click);
            // 
            // applicationLauncherToolStripMenuItem
            // 
            this.applicationLauncherToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.alwaysALToolStripMenuItem1,
            this.neverALToolStripMenuItem1,
            this.autoALToolStripMenuItem1,
            this.loadToolStripMenuItem});
            this.applicationLauncherToolStripMenuItem.Name = "applicationLauncherToolStripMenuItem";
            this.applicationLauncherToolStripMenuItem.Size = new System.Drawing.Size(184, 22);
            this.applicationLauncherToolStripMenuItem.Text = "Application Launcher";
            // 
            // alwaysALToolStripMenuItem1
            // 
            this.alwaysALToolStripMenuItem1.Name = "alwaysALToolStripMenuItem1";
            this.alwaysALToolStripMenuItem1.Size = new System.Drawing.Size(119, 22);
            this.alwaysALToolStripMenuItem1.Text = "Always";
            this.alwaysALToolStripMenuItem1.Click += new System.EventHandler(this.alwaysALToolStripMenuItem1_Click);
            // 
            // neverALToolStripMenuItem1
            // 
            this.neverALToolStripMenuItem1.Name = "neverALToolStripMenuItem1";
            this.neverALToolStripMenuItem1.Size = new System.Drawing.Size(119, 22);
            this.neverALToolStripMenuItem1.Text = "Never";
            this.neverALToolStripMenuItem1.Click += new System.EventHandler(this.neverALToolStripMenuItem1_Click);
            // 
            // autoALToolStripMenuItem1
            // 
            this.autoALToolStripMenuItem1.Name = "autoALToolStripMenuItem1";
            this.autoALToolStripMenuItem1.Size = new System.Drawing.Size(119, 22);
            this.autoALToolStripMenuItem1.Text = "Auto";
            this.autoALToolStripMenuItem1.Click += new System.EventHandler(this.autoALToolStripMenuItem1_Click);
            // 
            // loadToolStripMenuItem
            // 
            this.loadToolStripMenuItem.Name = "loadToolStripMenuItem";
            this.loadToolStripMenuItem.Size = new System.Drawing.Size(119, 22);
            this.loadToolStripMenuItem.Text = "Load";
            this.loadToolStripMenuItem.Click += new System.EventHandler(this.loadToolStripMenuItem_Click);
            // 
            // toolbarToolStripMenuItem
            // 
            this.toolbarToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.alwaysToolbarToolStripMenuItem,
            this.neverToolbarToolStripMenuItem,
            this.autoToolbarToolStripMenuItem});
            this.toolbarToolStripMenuItem.Name = "toolbarToolStripMenuItem";
            this.toolbarToolStripMenuItem.Size = new System.Drawing.Size(184, 22);
            this.toolbarToolStripMenuItem.Text = "Toolbar";
            // 
            // alwaysToolbarToolStripMenuItem
            // 
            this.alwaysToolbarToolStripMenuItem.Name = "alwaysToolbarToolStripMenuItem";
            this.alwaysToolbarToolStripMenuItem.Size = new System.Drawing.Size(119, 22);
            this.alwaysToolbarToolStripMenuItem.Text = "Always";
            this.alwaysToolbarToolStripMenuItem.Click += new System.EventHandler(this.alwaysToolbarToolStripMenuItem_Click);
            // 
            // neverToolbarToolStripMenuItem
            // 
            this.neverToolbarToolStripMenuItem.Name = "neverToolbarToolStripMenuItem";
            this.neverToolbarToolStripMenuItem.Size = new System.Drawing.Size(119, 22);
            this.neverToolbarToolStripMenuItem.Text = "Never";
            this.neverToolbarToolStripMenuItem.Click += new System.EventHandler(this.neverToolbarToolStripMenuItem_Click);
            // 
            // autoToolbarToolStripMenuItem
            // 
            this.autoToolbarToolStripMenuItem.Name = "autoToolbarToolStripMenuItem";
            this.autoToolbarToolStripMenuItem.Size = new System.Drawing.Size(119, 22);
            this.autoToolbarToolStripMenuItem.Text = "Auto";
            this.autoToolbarToolStripMenuItem.Click += new System.EventHandler(this.autoToolbarToolStripMenuItem_Click);
            // 
            // saveWindowToolStripMenuItem
            // 
            this.saveWindowToolStripMenuItem.Name = "saveWindowToolStripMenuItem";
            this.saveWindowToolStripMenuItem.Size = new System.Drawing.Size(184, 22);
            this.saveWindowToolStripMenuItem.Text = "Save Window";
            this.saveWindowToolStripMenuItem.Click += new System.EventHandler(this.saveWindowToolStripMenuItem_Click);
            // 
            // macroEditorToolStripMenuItem
            // 
            this.macroEditorToolStripMenuItem.Name = "macroEditorToolStripMenuItem";
            this.macroEditorToolStripMenuItem.Size = new System.Drawing.Size(184, 22);
            this.macroEditorToolStripMenuItem.Text = "Macro Editor";
            this.macroEditorToolStripMenuItem.Click += new System.EventHandler(this.macroEditorToolStripMenuItem_Click);
            // 
            // topWindowToolStrip
            // 
            this.topWindowToolStrip.Location = new System.Drawing.Point(0, 24);
            this.topWindowToolStrip.Name = "topWindowToolStrip";
            this.topWindowToolStrip.Size = new System.Drawing.Size(1073, 25);
            this.topWindowToolStrip.TabIndex = 1;
            this.topWindowToolStrip.Text = "toolStrip1";
            // 
            // splitContainer1
            // 
            this.splitContainer1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer1.Location = new System.Drawing.Point(0, 49);
            this.splitContainer1.Name = "splitContainer1";
            // 
            // splitContainer1.Panel1
            // 
            this.splitContainer1.Panel1.Controls.Add(this.splitContainer2);
            this.splitContainer1.Panel1MinSize = 250;
            // 
            // splitContainer1.Panel2
            // 
            this.splitContainer1.Panel2.Controls.Add(this.MenuBarPanel);
            this.splitContainer1.Size = new System.Drawing.Size(1073, 568);
            this.splitContainer1.SplitterDistance = 879;
            this.splitContainer1.TabIndex = 7;
            this.splitContainer1.TabStop = false;
            // 
            // splitContainer2
            // 
            this.splitContainer2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer2.Location = new System.Drawing.Point(0, 0);
            this.splitContainer2.Name = "splitContainer2";
            // 
            // splitContainer2.Panel1
            // 
            this.splitContainer2.Panel1.Controls.Add(this.applicationLauncherPanel);
            // 
            // splitContainer2.Panel2
            // 
            this.splitContainer2.Panel2.Controls.Add(this.panel1);
            this.splitContainer2.Size = new System.Drawing.Size(879, 568);
            this.splitContainer2.SplitterDistance = 339;
            this.splitContainer2.TabIndex = 18;
            this.splitContainer2.TabStop = false;
            // 
            // applicationLauncherPanel
            // 
            this.applicationLauncherPanel.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.applicationLauncherPanel.Controls.Add(this.applicationLauncherTreeView);
            this.applicationLauncherPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.applicationLauncherPanel.Location = new System.Drawing.Point(0, 0);
            this.applicationLauncherPanel.Name = "applicationLauncherPanel";
            this.applicationLauncherPanel.Size = new System.Drawing.Size(339, 568);
            this.applicationLauncherPanel.TabIndex = 18;
            // 
            // applicationLauncherTreeView
            // 
            this.applicationLauncherTreeView.BackColor = System.Drawing.SystemColors.Window;
            this.applicationLauncherTreeView.Dock = System.Windows.Forms.DockStyle.Fill;
            this.applicationLauncherTreeView.Location = new System.Drawing.Point(0, 0);
            this.applicationLauncherTreeView.Name = "applicationLauncherTreeView";
            this.applicationLauncherTreeView.Size = new System.Drawing.Size(335, 564);
            this.applicationLauncherTreeView.TabIndex = 0;
            this.applicationLauncherTreeView.DoubleClick += new System.EventHandler(this.applicationLauncherTreeView_DoubleClick);
            this.applicationLauncherTreeView.AfterSelect += new System.Windows.Forms.TreeViewEventHandler(this.treeView1_AfterSelect);
            // 
            // panel1
            // 
            this.panel1.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.panel1.Controls.Add(this.tabControl1);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panel1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.panel1.Location = new System.Drawing.Point(0, 0);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(536, 568);
            this.panel1.TabIndex = 7;
            // 
            // tabControl1
            // 
            this.tabControl1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tabControl1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.tabControl1.Location = new System.Drawing.Point(0, 0);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.ShowToolTips = true;
            this.tabControl1.Size = new System.Drawing.Size(532, 564);
            this.tabControl1.TabIndex = 15;
            this.tabControl1.SelectedIndexChanged += new System.EventHandler(this.tabControl1_SelectedIndexChanged);
            // 
            // MenuBarPanel
            // 
            this.MenuBarPanel.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.MenuBarPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.MenuBarPanel.Location = new System.Drawing.Point(0, 0);
            this.MenuBarPanel.Name = "MenuBarPanel";
            this.MenuBarPanel.Padding = new System.Windows.Forms.Padding(5);
            this.MenuBarPanel.Size = new System.Drawing.Size(190, 568);
            this.MenuBarPanel.TabIndex = 7;
            // 
            // frmMainAppWindow
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoScroll = true;
            this.AutoSize = true;
            this.ClientSize = new System.Drawing.Size(1073, 639);
            this.Controls.Add(this.splitContainer1);
            this.Controls.Add(this.topWindowToolStrip);
            this.Controls.Add(this.statusStrip1);
            this.Controls.Add(this.menuStrip1);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.KeyPreview = true;
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "frmMainAppWindow";
            this.Text = "Aubit4GL Desktop Client";
            this.Load += new System.EventHandler(this.frmMainAppWindow_Load);
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.frmMainAppWindow_FormClosed);
            this.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.frmMainAppWindow_KeyPress);
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.frmMainAppWindow_KeyDown);
            this.statusStrip1.ResumeLayout(false);
            this.statusStrip1.PerformLayout();
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.splitContainer1.Panel1.ResumeLayout(false);
            this.splitContainer1.Panel2.ResumeLayout(false);
            this.splitContainer1.ResumeLayout(false);
            this.splitContainer2.Panel1.ResumeLayout(false);
            this.splitContainer2.Panel2.ResumeLayout(false);
            this.splitContainer2.ResumeLayout(false);
            this.applicationLauncherPanel.ResumeLayout(false);
            this.panel1.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripStatusLabel lblComment;
        private System.Windows.Forms.ToolStripStatusLabel lblMessage;
        private System.Windows.Forms.ToolStripStatusLabel lblError;
        private System.Windows.Forms.ToolStripStatusLabel lblLineDisplay;
        private System.Windows.Forms.SplitContainer splitContainer1;
        private System.Windows.Forms.Panel MenuBarPanel;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem editToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem copyToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem pasteToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem cutToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem enableEditModeToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem helpToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem applicationHelpToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem aubit4GLGUIHelpToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem aboutToolStripMenuItem;
        private System.Windows.Forms.ToolStripProgressBar toolStripProgressBar2;
        private System.Windows.Forms.ToolStrip topWindowToolStrip;
        private System.Windows.Forms.SplitContainer splitContainer2;
        private System.Windows.Forms.Panel applicationLauncherPanel;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TreeView applicationLauncherTreeView;
        private System.Windows.Forms.ToolStripMenuItem viewToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem menubarToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem alwaysMenubarToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem neverMenubarToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem autoMenubarToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem applicationLauncherToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem alwaysALToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem neverALToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem autoALToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem toolbarToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem alwaysToolbarToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem neverToolbarToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem autoToolbarToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem loadToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem saveWindowToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem macroEditorToolStripMenuItem;

    }
}