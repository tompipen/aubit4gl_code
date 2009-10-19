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
            this.statusStrip1 = new Gizmox.WebGUI.Forms.StatusStrip();
            this.lblComment = new Gizmox.WebGUI.Forms.ToolStripStatusLabel();
            this.lblMessage = new Gizmox.WebGUI.Forms.ToolStripStatusLabel();
            this.lblError = new Gizmox.WebGUI.Forms.ToolStripStatusLabel();
            this.lblLineDisplay = new Gizmox.WebGUI.Forms.ToolStripStatusLabel();
            this.menuStrip1 = new Gizmox.WebGUI.Forms.MenuStrip();
            this.fileToolStripMenuItem = new Gizmox.WebGUI.Forms.ToolStripMenuItem();
            this.exitToolStripMenuItem = new Gizmox.WebGUI.Forms.ToolStripMenuItem();
            this.editToolStripMenuItem = new Gizmox.WebGUI.Forms.ToolStripMenuItem();
            this.copyToolStripMenuItem = new Gizmox.WebGUI.Forms.ToolStripMenuItem();
            this.pasteToolStripMenuItem = new Gizmox.WebGUI.Forms.ToolStripMenuItem();
            this.cutToolStripMenuItem = new Gizmox.WebGUI.Forms.ToolStripMenuItem();
            this.enableEditModeToolStripMenuItem = new Gizmox.WebGUI.Forms.ToolStripMenuItem();
            this.helpToolStripMenuItem = new Gizmox.WebGUI.Forms.ToolStripMenuItem();
            this.applicationHelpToolStripMenuItem = new Gizmox.WebGUI.Forms.ToolStripMenuItem();
            this.aubit4GLGUIHelpToolStripMenuItem = new Gizmox.WebGUI.Forms.ToolStripMenuItem();
            this.aboutToolStripMenuItem = new Gizmox.WebGUI.Forms.ToolStripMenuItem();
            this.viewToolStripMenuItem = new Gizmox.WebGUI.Forms.ToolStripMenuItem();
            this.menubarToolStripMenuItem = new Gizmox.WebGUI.Forms.ToolStripMenuItem();
            this.alwaysMenubarToolStripMenuItem = new Gizmox.WebGUI.Forms.ToolStripMenuItem();
            this.neverMenubarToolStripMenuItem = new Gizmox.WebGUI.Forms.ToolStripMenuItem();
            this.autoMenubarToolStripMenuItem = new Gizmox.WebGUI.Forms.ToolStripMenuItem();
            this.applicationLauncherToolStripMenuItem = new Gizmox.WebGUI.Forms.ToolStripMenuItem();
            this.alwaysALToolStripMenuItem1 = new Gizmox.WebGUI.Forms.ToolStripMenuItem();
            this.neverALToolStripMenuItem1 = new Gizmox.WebGUI.Forms.ToolStripMenuItem();
            this.autoALToolStripMenuItem1 = new Gizmox.WebGUI.Forms.ToolStripMenuItem();
            this.loadToolStripMenuItem = new Gizmox.WebGUI.Forms.ToolStripMenuItem();
            this.toolbarToolStripMenuItem = new Gizmox.WebGUI.Forms.ToolStripMenuItem();
            this.alwaysToolbarToolStripMenuItem = new Gizmox.WebGUI.Forms.ToolStripMenuItem();
            this.neverToolbarToolStripMenuItem = new Gizmox.WebGUI.Forms.ToolStripMenuItem();
            this.autoToolbarToolStripMenuItem = new Gizmox.WebGUI.Forms.ToolStripMenuItem();
            this.saveWindowToolStripMenuItem = new Gizmox.WebGUI.Forms.ToolStripMenuItem();
            this.macroEditorToolStripMenuItem = new Gizmox.WebGUI.Forms.ToolStripMenuItem();
            this.topWindowToolStrip = new Gizmox.WebGUI.Forms.ToolStrip();
            this.splitContainer1 = new Gizmox.WebGUI.Forms.SplitContainer();
            this.splitContainer2 = new Gizmox.WebGUI.Forms.SplitContainer();
            this.applicationLauncherPanel = new Gizmox.WebGUI.Forms.Panel();
            this.applicationLauncherTreeView = new Gizmox.WebGUI.Forms.TreeView();
            this.panel1 = new Gizmox.WebGUI.Forms.Panel();
            this.tabControl1 = new Gizmox.WebGUI.Forms.TabControl();
            this.MenuBarPanel = new Gizmox.WebGUI.Forms.Panel();
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
            this.statusStrip1.Items.AddRange(new Gizmox.WebGUI.Forms.Control[] {
            this.lblComment,
            this.lblMessage,
            this.lblError,
            this.lblLineDisplay});
            this.statusStrip1.LayoutStyle = Gizmox.WebGUI.Forms.ToolStripLayoutStyle.HorizontalStackWithOverflow;
            this.statusStrip1.Location = new System.Drawing.Point(0, 617);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(1073, 22);
            this.statusStrip1.TabIndex = 1;
            this.statusStrip1.Text = "statusStrip1";
            // 
            // toolStripProgressBar2
            // 
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
            this.menuStrip1.Items.AddRange(new Gizmox.WebGUI.Forms.MenuItem[] {
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
            this.fileToolStripMenuItem.MenuItems.AddRange(new Gizmox.WebGUI.Forms.MenuItem[] {
            this.exitToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Text = "File";
            // 
            // exitToolStripMenuItem
            // 
            this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
            this.exitToolStripMenuItem.Text = "Exit";
            this.exitToolStripMenuItem.Click += new System.EventHandler(this.exitToolStripMenuItem_Click);
            // 
            // editToolStripMenuItem
            // 
            this.editToolStripMenuItem.MenuItems.AddRange(new Gizmox.WebGUI.Forms.MenuItem[] {
            this.copyToolStripMenuItem,
            this.pasteToolStripMenuItem,
            this.cutToolStripMenuItem,
            this.enableEditModeToolStripMenuItem});
            this.editToolStripMenuItem.Name = "editToolStripMenuItem";
            this.editToolStripMenuItem.Text = "Edit";
            // 
            // copyToolStripMenuItem
            // 
            this.copyToolStripMenuItem.Name = "copyToolStripMenuItem";
            this.copyToolStripMenuItem.Text = "Copy";
            this.copyToolStripMenuItem.Click += new System.EventHandler(this.copyToolStripMenuItem_Click);
            // 
            // pasteToolStripMenuItem
            // 
            this.pasteToolStripMenuItem.Name = "pasteToolStripMenuItem";
            this.pasteToolStripMenuItem.Text = "Paste";
            this.pasteToolStripMenuItem.Click += new System.EventHandler(this.pasteToolStripMenuItem_Click);
            // 
            // cutToolStripMenuItem
            // 
            this.cutToolStripMenuItem.Name = "cutToolStripMenuItem";
            this.cutToolStripMenuItem.Text = "Cut";
            this.cutToolStripMenuItem.Click += new System.EventHandler(this.cutToolStripMenuItem_Click);
            // 
            // enableEditModeToolStripMenuItem
            // 
            this.enableEditModeToolStripMenuItem.Name = "enableEditModeToolStripMenuItem";
            this.enableEditModeToolStripMenuItem.Text = "Enable Edit Mode";
            this.enableEditModeToolStripMenuItem.Click += new System.EventHandler(this.enableEditModeToolStripMenuItem_Click);
            // 
            // helpToolStripMenuItem
            // 
            this.helpToolStripMenuItem.Alignment = Gizmox.WebGUI.Forms.ToolStripItemAlignment.Right;
            this.helpToolStripMenuItem.MenuItems.AddRange(new Gizmox.WebGUI.Forms.MenuItem[] {
            this.applicationHelpToolStripMenuItem,
            this.aubit4GLGUIHelpToolStripMenuItem,
            this.aboutToolStripMenuItem});
            this.helpToolStripMenuItem.Name = "helpToolStripMenuItem";
            this.helpToolStripMenuItem.ShortcutKeys = Gizmox.WebGUI.Forms.Keys.F1;
            this.helpToolStripMenuItem.Text = "Help";
            // 
            // applicationHelpToolStripMenuItem
            // 
            this.applicationHelpToolStripMenuItem.Name = "applicationHelpToolStripMenuItem";
            this.applicationHelpToolStripMenuItem.Text = "Application Help";
            // 
            // aubit4GLGUIHelpToolStripMenuItem
            // 
            this.aubit4GLGUIHelpToolStripMenuItem.Name = "aubit4GLGUIHelpToolStripMenuItem";
            this.aubit4GLGUIHelpToolStripMenuItem.Text = "Aubit4GL GUI Help";
            // 
            // aboutToolStripMenuItem
            // 
            this.aboutToolStripMenuItem.Name = "aboutToolStripMenuItem";
            this.aboutToolStripMenuItem.Text = "About";
            this.aboutToolStripMenuItem.Click += new System.EventHandler(this.aboutToolStripMenuItem_Click);
            // 
            // viewToolStripMenuItem
            // 
            this.viewToolStripMenuItem.MenuItems.AddRange(new Gizmox.WebGUI.Forms.MenuItem[] {
            this.menubarToolStripMenuItem,
            this.applicationLauncherToolStripMenuItem,
            this.toolbarToolStripMenuItem,
            this.saveWindowToolStripMenuItem,
            this.macroEditorToolStripMenuItem});
            this.viewToolStripMenuItem.Name = "viewToolStripMenuItem";
            this.viewToolStripMenuItem.Text = "View";
            // 
            // menubarToolStripMenuItem
            // 
            this.menubarToolStripMenuItem.MenuItems.AddRange(new Gizmox.WebGUI.Forms.MenuItem[] {
            this.alwaysMenubarToolStripMenuItem,
            this.neverMenubarToolStripMenuItem,
            this.autoMenubarToolStripMenuItem});
            this.menubarToolStripMenuItem.Name = "menubarToolStripMenuItem";
            this.menubarToolStripMenuItem.Text = "Menubar";
            // 
            // alwaysMenubarToolStripMenuItem
            // 
            this.alwaysMenubarToolStripMenuItem.Name = "alwaysMenubarToolStripMenuItem";
            this.alwaysMenubarToolStripMenuItem.Text = "Always";
            this.alwaysMenubarToolStripMenuItem.Click += new System.EventHandler(this.alwaysToolStripMenuItem_Click);
            // 
            // neverMenubarToolStripMenuItem
            // 
            this.neverMenubarToolStripMenuItem.Name = "neverMenubarToolStripMenuItem";
            this.neverMenubarToolStripMenuItem.Text = "Never";
            this.neverMenubarToolStripMenuItem.Click += new System.EventHandler(this.neverMenubarToolStripMenuItem_Click);
            // 
            // autoMenubarToolStripMenuItem
            // 
            this.autoMenubarToolStripMenuItem.Name = "autoMenubarToolStripMenuItem";
            this.autoMenubarToolStripMenuItem.Text = "Auto";
            this.autoMenubarToolStripMenuItem.Click += new System.EventHandler(this.autoMenubarToolStripMenuItem_Click);
            // 
            // applicationLauncherToolStripMenuItem
            // 
            this.applicationLauncherToolStripMenuItem.MenuItems.AddRange(new Gizmox.WebGUI.Forms.MenuItem[] {
            this.alwaysALToolStripMenuItem1,
            this.neverALToolStripMenuItem1,
            this.autoALToolStripMenuItem1,
            this.loadToolStripMenuItem});
            this.applicationLauncherToolStripMenuItem.Name = "applicationLauncherToolStripMenuItem";
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
            // 
            // toolbarToolStripMenuItem
            // 
            this.toolbarToolStripMenuItem.MenuItems.AddRange(new Gizmox.WebGUI.Forms.MenuItem[] {
            this.alwaysToolbarToolStripMenuItem,
            this.neverToolbarToolStripMenuItem,
            this.autoToolbarToolStripMenuItem});
            this.toolbarToolStripMenuItem.Name = "toolbarToolStripMenuItem";
            this.toolbarToolStripMenuItem.Text = "Toolbar";
            // 
            // alwaysToolbarToolStripMenuItem
            // 
            this.alwaysToolbarToolStripMenuItem.Name = "alwaysToolbarToolStripMenuItem";
            this.alwaysToolbarToolStripMenuItem.Text = "Always";
            this.alwaysToolbarToolStripMenuItem.Click += new System.EventHandler(this.alwaysToolbarToolStripMenuItem_Click);
            // 
            // neverToolbarToolStripMenuItem
            // 
            this.neverToolbarToolStripMenuItem.Name = "neverToolbarToolStripMenuItem";
            this.neverToolbarToolStripMenuItem.Text = "Never";
            this.neverToolbarToolStripMenuItem.Click += new System.EventHandler(this.neverToolbarToolStripMenuItem_Click);
            // 
            // autoToolbarToolStripMenuItem
            // 
            this.autoToolbarToolStripMenuItem.Name = "autoToolbarToolStripMenuItem";
            this.autoToolbarToolStripMenuItem.Text = "Auto";
            this.autoToolbarToolStripMenuItem.Click += new System.EventHandler(this.autoToolbarToolStripMenuItem_Click);
            // 
            // saveWindowToolStripMenuItem
            // 
            this.saveWindowToolStripMenuItem.Name = "saveWindowToolStripMenuItem";
            this.saveWindowToolStripMenuItem.Text = "Save Window";
            this.saveWindowToolStripMenuItem.Click += new System.EventHandler(this.saveWindowToolStripMenuItem_Click);
            // 
            // macroEditorToolStripMenuItem
            // 
            this.macroEditorToolStripMenuItem.Name = "macroEditorToolStripMenuItem";
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
            this.splitContainer1.Dock = Gizmox.WebGUI.Forms.DockStyle.Fill;
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
            this.splitContainer2.Dock = Gizmox.WebGUI.Forms.DockStyle.Fill;
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
            this.applicationLauncherPanel.BorderStyle = Gizmox.WebGUI.Forms.BorderStyle.Fixed3D;
            this.applicationLauncherPanel.Controls.Add(this.applicationLauncherTreeView);
            this.applicationLauncherPanel.Dock = Gizmox.WebGUI.Forms.DockStyle.Fill;
            this.applicationLauncherPanel.Location = new System.Drawing.Point(0, 0);
            this.applicationLauncherPanel.Name = "applicationLauncherPanel";
            this.applicationLauncherPanel.Size = new System.Drawing.Size(339, 568);
            this.applicationLauncherPanel.TabIndex = 18;
            // 
            // applicationLauncherTreeView
            // 
            this.applicationLauncherTreeView.BackColor = System.Drawing.SystemColors.Window;
            this.applicationLauncherTreeView.Dock = Gizmox.WebGUI.Forms.DockStyle.Fill;
            this.applicationLauncherTreeView.Location = new System.Drawing.Point(0, 0);
            this.applicationLauncherTreeView.Name = "applicationLauncherTreeView";
            this.applicationLauncherTreeView.Size = new System.Drawing.Size(335, 564);
            this.applicationLauncherTreeView.TabIndex = 0;
            this.applicationLauncherTreeView.DoubleClick += new System.EventHandler(this.applicationLauncherTreeView_DoubleClick);
            this.applicationLauncherTreeView.AfterSelect += new Gizmox.WebGUI.Forms.TreeViewEventHandler(this.treeView1_AfterSelect);
            // 
            // panel1
            // 
            this.panel1.BorderStyle = Gizmox.WebGUI.Forms.BorderStyle.Fixed3D;
            this.panel1.Controls.Add(this.tabControl1);
            this.panel1.Dock = Gizmox.WebGUI.Forms.DockStyle.Fill;
            this.panel1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.panel1.Location = new System.Drawing.Point(0, 0);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(536, 568);
            this.panel1.TabIndex = 7;
            // 
            // tabControl1
            // 
            this.tabControl1.Dock = Gizmox.WebGUI.Forms.DockStyle.Fill;
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
            this.MenuBarPanel.BorderStyle = Gizmox.WebGUI.Forms.BorderStyle.Fixed3D;
            this.MenuBarPanel.Dock = Gizmox.WebGUI.Forms.DockStyle.Fill;
            this.MenuBarPanel.Location = new System.Drawing.Point(0, 0);
            this.MenuBarPanel.Name = "MenuBarPanel";
            this.MenuBarPanel.Padding = new Gizmox.WebGUI.Forms.Padding(5);
            this.MenuBarPanel.Size = new System.Drawing.Size(190, 568);
            this.MenuBarPanel.TabIndex = 7;
            // 
            // frmMainAppWindow
            // 
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
            this.KeyPress += new Gizmox.WebGUI.Forms.KeyPressEventHandler(this.frmMainAppWindow_KeyPress);
            this.FormClosing += new Gizmox.WebGUI.Forms.FormClosingEventHandler(this.frmMainAppWindow_FormClosing);
            this.KeyDown += new Gizmox.WebGUI.Forms.KeyEventHandler(this.frmMainAppWindow_KeyDown);
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

        private Gizmox.WebGUI.Forms.StatusStrip statusStrip1;
        private Gizmox.WebGUI.Forms.MenuStrip menuStrip1;
        private Gizmox.WebGUI.Forms.ToolStripStatusLabel lblComment;
        private Gizmox.WebGUI.Forms.ToolStripStatusLabel lblMessage;
        private Gizmox.WebGUI.Forms.ToolStripStatusLabel lblError;
        private Gizmox.WebGUI.Forms.ToolStripStatusLabel lblLineDisplay;
        private Gizmox.WebGUI.Forms.SplitContainer splitContainer1;
        private Gizmox.WebGUI.Forms.Panel MenuBarPanel;
        private Gizmox.WebGUI.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private Gizmox.WebGUI.Forms.ToolStripMenuItem exitToolStripMenuItem;
        private Gizmox.WebGUI.Forms.ToolStripMenuItem editToolStripMenuItem;
        private Gizmox.WebGUI.Forms.ToolStripMenuItem copyToolStripMenuItem;
        private Gizmox.WebGUI.Forms.ToolStripMenuItem pasteToolStripMenuItem;
        private Gizmox.WebGUI.Forms.ToolStripMenuItem cutToolStripMenuItem;
        private Gizmox.WebGUI.Forms.ToolStripMenuItem enableEditModeToolStripMenuItem;
        private Gizmox.WebGUI.Forms.ToolStripMenuItem helpToolStripMenuItem;
        private Gizmox.WebGUI.Forms.ToolStripMenuItem applicationHelpToolStripMenuItem;
        private Gizmox.WebGUI.Forms.ToolStripMenuItem aubit4GLGUIHelpToolStripMenuItem;
        private Gizmox.WebGUI.Forms.ToolStripMenuItem aboutToolStripMenuItem;
        private Gizmox.WebGUI.Forms.ToolStripProgressBar toolStripProgressBar2;
        private Gizmox.WebGUI.Forms.ToolStrip topWindowToolStrip;
        private Gizmox.WebGUI.Forms.SplitContainer splitContainer2;
        private Gizmox.WebGUI.Forms.Panel applicationLauncherPanel;
        private Gizmox.WebGUI.Forms.Panel panel1;
        private Gizmox.WebGUI.Forms.TabControl tabControl1;
        private Gizmox.WebGUI.Forms.TreeView applicationLauncherTreeView;
        private Gizmox.WebGUI.Forms.ToolStripMenuItem viewToolStripMenuItem;
        private Gizmox.WebGUI.Forms.ToolStripMenuItem menubarToolStripMenuItem;
        private Gizmox.WebGUI.Forms.ToolStripMenuItem alwaysMenubarToolStripMenuItem;
        private Gizmox.WebGUI.Forms.ToolStripMenuItem neverMenubarToolStripMenuItem;
        private Gizmox.WebGUI.Forms.ToolStripMenuItem autoMenubarToolStripMenuItem;
        private Gizmox.WebGUI.Forms.ToolStripMenuItem applicationLauncherToolStripMenuItem;
        private Gizmox.WebGUI.Forms.ToolStripMenuItem alwaysALToolStripMenuItem1;
        private Gizmox.WebGUI.Forms.ToolStripMenuItem neverALToolStripMenuItem1;
        private Gizmox.WebGUI.Forms.ToolStripMenuItem autoALToolStripMenuItem1;
        private Gizmox.WebGUI.Forms.ToolStripMenuItem toolbarToolStripMenuItem;
        private Gizmox.WebGUI.Forms.ToolStripMenuItem alwaysToolbarToolStripMenuItem;
        private Gizmox.WebGUI.Forms.ToolStripMenuItem neverToolbarToolStripMenuItem;
        private Gizmox.WebGUI.Forms.ToolStripMenuItem autoToolbarToolStripMenuItem;
        private Gizmox.WebGUI.Forms.ToolStripMenuItem loadToolStripMenuItem;
        private Gizmox.WebGUI.Forms.ToolStripMenuItem saveWindowToolStripMenuItem;
        private Gizmox.WebGUI.Forms.ToolStripMenuItem macroEditorToolStripMenuItem;

    }
}
