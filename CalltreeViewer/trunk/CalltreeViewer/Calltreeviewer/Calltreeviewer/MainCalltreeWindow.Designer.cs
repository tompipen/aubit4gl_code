namespace Calltreeviewer
{
    partial class MainCalltreeWindow
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainCalltreeWindow));
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.mnLoad = new System.Windows.Forms.ToolStripMenuItem();
            this.tsFileLoadMainRecursive = new System.Windows.Forms.ToolStripMenuItem();
            this.tsFileLoadMain = new System.Windows.Forms.ToolStripMenuItem();
            this.mnExit = new System.Windows.Forms.ToolStripMenuItem();
            this.treeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.collapseToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.showAllToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.expandShowAllToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.expandCurrentNodeShowToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.simpleModeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.findFunctionToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.functionToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.referencesToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.tscbFindFunction = new System.Windows.Forms.ToolStripComboBox();
            this.referencesToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.findAllExternalReferencesToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.findExternalReferencesForThisModuleToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.findFunctionsThatAreNotCalledToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.cbModules = new System.Windows.Forms.ToolStripComboBox();
            this.cRUDToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.updatesToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.deleteToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.insertToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.selectToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.dEFINELIKEToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.eXECUTEPROCEDUREToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.environmentVariablesToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.RunsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.formsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.filesToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.mnLocationBack = new System.Windows.Forms.ToolStripMenuItem();
            this.mnLocationForward = new System.Windows.Forms.ToolStripMenuItem();
            this.test1ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.tslblLine = new System.Windows.Forms.ToolStripStatusLabel();
            this.lblNoOfLines = new System.Windows.Forms.ToolStripStatusLabel();
            this.tsLblSearching = new System.Windows.Forms.ToolStripStatusLabel();
            this.lblLoaded = new System.Windows.Forms.ToolStripStatusLabel();
            this.tslSrchText = new System.Windows.Forms.ToolStripStatusLabel();
            this.panel3 = new System.Windows.Forms.Panel();
            this.splitContainer1 = new System.Windows.Forms.SplitContainer();
            this.treeView1 = new System.Windows.Forms.TreeView();
            this.panel1 = new System.Windows.Forms.Panel();
            this.lblTreeView = new System.Windows.Forms.Label();
            this.splitContainer2 = new System.Windows.Forms.SplitContainer();
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.panel2 = new System.Windows.Forms.Panel();
            this.lblListbox = new System.Windows.Forms.Label();
            this.unparsedDynamicSQLToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.textBox1 = new SearchableControls.SearchableTextBox();
            this.menuStrip1.SuspendLayout();
            this.statusStrip1.SuspendLayout();
            this.panel3.SuspendLayout();
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.Panel2.SuspendLayout();
            this.splitContainer1.SuspendLayout();
            this.panel1.SuspendLayout();
            this.splitContainer2.Panel1.SuspendLayout();
            this.splitContainer2.Panel2.SuspendLayout();
            this.splitContainer2.SuspendLayout();
            this.panel2.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.treeToolStripMenuItem,
            this.findFunctionToolStripMenuItem,
            this.tscbFindFunction,
            this.referencesToolStripMenuItem1,
            this.toolStripMenuItem1,
            this.cbModules,
            this.cRUDToolStripMenuItem,
            this.mnLocationBack,
            this.mnLocationForward,
            this.test1ToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(1564, 27);
            this.menuStrip1.TabIndex = 2;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.mnLoad,
            this.tsFileLoadMainRecursive,
            this.tsFileLoadMain,
            this.mnExit});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 23);
            this.fileToolStripMenuItem.Text = "&File";
            // 
            // mnLoad
            // 
            this.mnLoad.Name = "mnLoad";
            this.mnLoad.Size = new System.Drawing.Size(214, 22);
            this.mnLoad.Text = "Load";
            this.mnLoad.Visible = false;
            this.mnLoad.Click += new System.EventHandler(this.mnLoad_Click);
            // 
            // tsFileLoadMainRecursive
            // 
            this.tsFileLoadMainRecursive.Name = "tsFileLoadMainRecursive";
            this.tsFileLoadMainRecursive.Size = new System.Drawing.Size(214, 22);
            this.tsFileLoadMainRecursive.Text = "Load MAIN (recursively)";
            this.tsFileLoadMainRecursive.Click += new System.EventHandler(this.loadXmlMainRecursive);
            // 
            // tsFileLoadMain
            // 
            this.tsFileLoadMain.Name = "tsFileLoadMain";
            this.tsFileLoadMain.Size = new System.Drawing.Size(214, 22);
            this.tsFileLoadMain.Text = "Load Main (non-recursive)";
            this.tsFileLoadMain.Visible = false;
            this.tsFileLoadMain.Click += new System.EventHandler(this.loadXmlFileMain);
            // 
            // mnExit
            // 
            this.mnExit.Name = "mnExit";
            this.mnExit.Size = new System.Drawing.Size(214, 22);
            this.mnExit.Text = "E&xit";
            this.mnExit.Click += new System.EventHandler(this.mnExit_Click);
            // 
            // treeToolStripMenuItem
            // 
            this.treeToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.collapseToolStripMenuItem,
            this.showAllToolStripMenuItem,
            this.expandShowAllToolStripMenuItem,
            this.expandCurrentNodeShowToolStripMenuItem,
            this.simpleModeToolStripMenuItem});
            this.treeToolStripMenuItem.Name = "treeToolStripMenuItem";
            this.treeToolStripMenuItem.Size = new System.Drawing.Size(42, 23);
            this.treeToolStripMenuItem.Text = "Tree";
            // 
            // collapseToolStripMenuItem
            // 
            this.collapseToolStripMenuItem.Name = "collapseToolStripMenuItem";
            this.collapseToolStripMenuItem.Size = new System.Drawing.Size(232, 22);
            this.collapseToolStripMenuItem.Text = "Collapse";
            this.collapseToolStripMenuItem.Click += new System.EventHandler(this.collapseToolStripMenuItem_Click);
            // 
            // showAllToolStripMenuItem
            // 
            this.showAllToolStripMenuItem.Name = "showAllToolStripMenuItem";
            this.showAllToolStripMenuItem.Size = new System.Drawing.Size(232, 22);
            this.showAllToolStripMenuItem.Text = "Show All";
            this.showAllToolStripMenuItem.Click += new System.EventHandler(this.showAllToolStripMenuItem_Click);
            // 
            // expandShowAllToolStripMenuItem
            // 
            this.expandShowAllToolStripMenuItem.Name = "expandShowAllToolStripMenuItem";
            this.expandShowAllToolStripMenuItem.Size = new System.Drawing.Size(232, 22);
            this.expandShowAllToolStripMenuItem.Text = "Expand All Nodes && Show";
            this.expandShowAllToolStripMenuItem.Click += new System.EventHandler(this.expandShowAllToolStripMenuItem_Click);
            // 
            // expandCurrentNodeShowToolStripMenuItem
            // 
            this.expandCurrentNodeShowToolStripMenuItem.Name = "expandCurrentNodeShowToolStripMenuItem";
            this.expandCurrentNodeShowToolStripMenuItem.Size = new System.Drawing.Size(232, 22);
            this.expandCurrentNodeShowToolStripMenuItem.Text = "Expand Current Node && Show";
            this.expandCurrentNodeShowToolStripMenuItem.Click += new System.EventHandler(this.expandCurrentNodeShowToolStripMenuItem_Click);
            // 
            // simpleModeToolStripMenuItem
            // 
            this.simpleModeToolStripMenuItem.CheckOnClick = true;
            this.simpleModeToolStripMenuItem.Name = "simpleModeToolStripMenuItem";
            this.simpleModeToolStripMenuItem.Size = new System.Drawing.Size(232, 22);
            this.simpleModeToolStripMenuItem.Text = "Simple Mode";
            this.simpleModeToolStripMenuItem.ToolTipText = "Show only CALLs if enabled";
            // 
            // findFunctionToolStripMenuItem
            // 
            this.findFunctionToolStripMenuItem.Alignment = System.Windows.Forms.ToolStripItemAlignment.Right;
            this.findFunctionToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.functionToolStripMenuItem1,
            this.referencesToolStripMenuItem});
            this.findFunctionToolStripMenuItem.Name = "findFunctionToolStripMenuItem";
            this.findFunctionToolStripMenuItem.Size = new System.Drawing.Size(42, 23);
            this.findFunctionToolStripMenuItem.Text = "Find";
            // 
            // functionToolStripMenuItem1
            // 
            this.functionToolStripMenuItem1.Name = "functionToolStripMenuItem1";
            this.functionToolStripMenuItem1.Size = new System.Drawing.Size(131, 22);
            this.functionToolStripMenuItem1.Text = "Function";
            this.functionToolStripMenuItem1.Click += new System.EventHandler(this.functionToolStripMenuItem1_Click);
            // 
            // referencesToolStripMenuItem
            // 
            this.referencesToolStripMenuItem.Name = "referencesToolStripMenuItem";
            this.referencesToolStripMenuItem.Size = new System.Drawing.Size(131, 22);
            this.referencesToolStripMenuItem.Text = "References";
            this.referencesToolStripMenuItem.Click += new System.EventHandler(this.referencesToolStripMenuItem_Click);
            // 
            // tscbFindFunction
            // 
            this.tscbFindFunction.Alignment = System.Windows.Forms.ToolStripItemAlignment.Right;
            this.tscbFindFunction.AutoCompleteMode = System.Windows.Forms.AutoCompleteMode.Append;
            this.tscbFindFunction.AutoCompleteSource = System.Windows.Forms.AutoCompleteSource.ListItems;
            this.tscbFindFunction.BackColor = System.Drawing.SystemColors.Menu;
            this.tscbFindFunction.Items.AddRange(new object[] {
            "                                                                                 " +
                "               "});
            this.tscbFindFunction.Name = "tscbFindFunction";
            this.tscbFindFunction.Size = new System.Drawing.Size(121, 23);
            this.tscbFindFunction.Sorted = true;
            this.tscbFindFunction.Text = "<function>";
            // 
            // referencesToolStripMenuItem1
            // 
            this.referencesToolStripMenuItem1.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.findAllExternalReferencesToolStripMenuItem,
            this.findExternalReferencesForThisModuleToolStripMenuItem,
            this.findFunctionsThatAreNotCalledToolStripMenuItem});
            this.referencesToolStripMenuItem1.Name = "referencesToolStripMenuItem1";
            this.referencesToolStripMenuItem1.Size = new System.Drawing.Size(76, 23);
            this.referencesToolStripMenuItem1.Text = "References";
            // 
            // findAllExternalReferencesToolStripMenuItem
            // 
            this.findAllExternalReferencesToolStripMenuItem.Enabled = false;
            this.findAllExternalReferencesToolStripMenuItem.Name = "findAllExternalReferencesToolStripMenuItem";
            this.findAllExternalReferencesToolStripMenuItem.Size = new System.Drawing.Size(301, 22);
            this.findAllExternalReferencesToolStripMenuItem.Text = "Find all external references";
            this.findAllExternalReferencesToolStripMenuItem.Click += new System.EventHandler(this.findAllExternalReferencesToolStripMenuItem_Click);
            // 
            // findExternalReferencesForThisModuleToolStripMenuItem
            // 
            this.findExternalReferencesForThisModuleToolStripMenuItem.Enabled = false;
            this.findExternalReferencesForThisModuleToolStripMenuItem.Name = "findExternalReferencesForThisModuleToolStripMenuItem";
            this.findExternalReferencesForThisModuleToolStripMenuItem.Size = new System.Drawing.Size(301, 22);
            this.findExternalReferencesForThisModuleToolStripMenuItem.Text = "Find external references for current module";
            // 
            // findFunctionsThatAreNotCalledToolStripMenuItem
            // 
            this.findFunctionsThatAreNotCalledToolStripMenuItem.Enabled = false;
            this.findFunctionsThatAreNotCalledToolStripMenuItem.Name = "findFunctionsThatAreNotCalledToolStripMenuItem";
            this.findFunctionsThatAreNotCalledToolStripMenuItem.Size = new System.Drawing.Size(301, 22);
            this.findFunctionsThatAreNotCalledToolStripMenuItem.Text = "Find functions that are not called";
            this.findFunctionsThatAreNotCalledToolStripMenuItem.Click += new System.EventHandler(this.findFunctionsThatAreNotCalledToolStripMenuItem_Click);
            // 
            // toolStripMenuItem1
            // 
            this.toolStripMenuItem1.Alignment = System.Windows.Forms.ToolStripItemAlignment.Right;
            this.toolStripMenuItem1.Name = "toolStripMenuItem1";
            this.toolStripMenuItem1.Size = new System.Drawing.Size(89, 23);
            this.toolStripMenuItem1.Text = "Load Module";
            this.toolStripMenuItem1.Click += new System.EventHandler(this.toolStripMenuItem1_Click);
            // 
            // cbModules
            // 
            this.cbModules.Alignment = System.Windows.Forms.ToolStripItemAlignment.Right;
            this.cbModules.BackColor = System.Drawing.SystemColors.Menu;
            this.cbModules.Name = "cbModules";
            this.cbModules.Size = new System.Drawing.Size(121, 23);
            this.cbModules.Sorted = true;
            this.cbModules.Text = "<module>";
            this.cbModules.SelectedIndexChanged += new System.EventHandler(this.cbModules_SelectedIndexChanged);
            // 
            // cRUDToolStripMenuItem
            // 
            this.cRUDToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.updatesToolStripMenuItem,
            this.deleteToolStripMenuItem,
            this.insertToolStripMenuItem,
            this.selectToolStripMenuItem,
            this.dEFINELIKEToolStripMenuItem,
            this.eXECUTEPROCEDUREToolStripMenuItem,
            this.environmentVariablesToolStripMenuItem,
            this.RunsToolStripMenuItem,
            this.formsToolStripMenuItem,
            this.filesToolStripMenuItem,
            this.unparsedDynamicSQLToolStripMenuItem});
            this.cRUDToolStripMenuItem.Name = "cRUDToolStripMenuItem";
            this.cRUDToolStripMenuItem.Size = new System.Drawing.Size(93, 23);
            this.cRUDToolStripMenuItem.Text = "Symbols/Data";
            this.cRUDToolStripMenuItem.Visible = false;
            // 
            // updatesToolStripMenuItem
            // 
            this.updatesToolStripMenuItem.Name = "updatesToolStripMenuItem";
            this.updatesToolStripMenuItem.Size = new System.Drawing.Size(198, 22);
            this.updatesToolStripMenuItem.Text = "Updates";
            // 
            // deleteToolStripMenuItem
            // 
            this.deleteToolStripMenuItem.Name = "deleteToolStripMenuItem";
            this.deleteToolStripMenuItem.Size = new System.Drawing.Size(198, 22);
            this.deleteToolStripMenuItem.Text = "Delete";
            // 
            // insertToolStripMenuItem
            // 
            this.insertToolStripMenuItem.Name = "insertToolStripMenuItem";
            this.insertToolStripMenuItem.Size = new System.Drawing.Size(198, 22);
            this.insertToolStripMenuItem.Text = "Insert";
            // 
            // selectToolStripMenuItem
            // 
            this.selectToolStripMenuItem.Name = "selectToolStripMenuItem";
            this.selectToolStripMenuItem.Size = new System.Drawing.Size(198, 22);
            this.selectToolStripMenuItem.Text = "Select";
            // 
            // dEFINELIKEToolStripMenuItem
            // 
            this.dEFINELIKEToolStripMenuItem.Name = "dEFINELIKEToolStripMenuItem";
            this.dEFINELIKEToolStripMenuItem.Size = new System.Drawing.Size(198, 22);
            this.dEFINELIKEToolStripMenuItem.Text = "DEFINE .. LIKE";
            this.dEFINELIKEToolStripMenuItem.Visible = false;
            // 
            // eXECUTEPROCEDUREToolStripMenuItem
            // 
            this.eXECUTEPROCEDUREToolStripMenuItem.Name = "eXECUTEPROCEDUREToolStripMenuItem";
            this.eXECUTEPROCEDUREToolStripMenuItem.Size = new System.Drawing.Size(198, 22);
            this.eXECUTEPROCEDUREToolStripMenuItem.Text = "EXECUTE PROCEDURE";
            // 
            // environmentVariablesToolStripMenuItem
            // 
            this.environmentVariablesToolStripMenuItem.Name = "environmentVariablesToolStripMenuItem";
            this.environmentVariablesToolStripMenuItem.Size = new System.Drawing.Size(198, 22);
            this.environmentVariablesToolStripMenuItem.Text = "Environment Variables";
            // 
            // RunsToolStripMenuItem
            // 
            this.RunsToolStripMenuItem.Name = "RunsToolStripMenuItem";
            this.RunsToolStripMenuItem.Size = new System.Drawing.Size(198, 22);
            this.RunsToolStripMenuItem.Text = "RUNs";
            // 
            // formsToolStripMenuItem
            // 
            this.formsToolStripMenuItem.Name = "formsToolStripMenuItem";
            this.formsToolStripMenuItem.Size = new System.Drawing.Size(198, 22);
            this.formsToolStripMenuItem.Text = "Forms";
            // 
            // filesToolStripMenuItem
            // 
            this.filesToolStripMenuItem.Name = "filesToolStripMenuItem";
            this.filesToolStripMenuItem.Size = new System.Drawing.Size(198, 22);
            this.filesToolStripMenuItem.Text = "Files";
            // 
            // mnLocationBack
            // 
            this.mnLocationBack.Name = "mnLocationBack";
            this.mnLocationBack.Size = new System.Drawing.Size(27, 23);
            this.mnLocationBack.Text = "<";
            this.mnLocationBack.Click += new System.EventHandler(this.mnLocationBack_Click);
            // 
            // mnLocationForward
            // 
            this.mnLocationForward.Name = "mnLocationForward";
            this.mnLocationForward.Size = new System.Drawing.Size(27, 23);
            this.mnLocationForward.Text = ">";
            this.mnLocationForward.Click += new System.EventHandler(this.mnLocationForward_Click);
            // 
            // test1ToolStripMenuItem
            // 
            this.test1ToolStripMenuItem.Name = "test1ToolStripMenuItem";
            this.test1ToolStripMenuItem.Size = new System.Drawing.Size(47, 23);
            this.test1ToolStripMenuItem.Text = "Test1";
            this.test1ToolStripMenuItem.Visible = false;
            this.test1ToolStripMenuItem.Click += new System.EventHandler(this.test1ToolStripMenuItem_Click);
            // 
            // statusStrip1
            // 
            this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tslblLine,
            this.lblNoOfLines,
            this.tsLblSearching,
            this.lblLoaded,
            this.tslSrchText});
            this.statusStrip1.Location = new System.Drawing.Point(0, 583);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(1564, 24);
            this.statusStrip1.TabIndex = 3;
            this.statusStrip1.Text = "statusStrip1";
            // 
            // tslblLine
            // 
            this.tslblLine.AutoSize = false;
            this.tslblLine.BorderSides = ((System.Windows.Forms.ToolStripStatusLabelBorderSides)((((System.Windows.Forms.ToolStripStatusLabelBorderSides.Left | System.Windows.Forms.ToolStripStatusLabelBorderSides.Top)
                        | System.Windows.Forms.ToolStripStatusLabelBorderSides.Right)
                        | System.Windows.Forms.ToolStripStatusLabelBorderSides.Bottom)));
            this.tslblLine.BorderStyle = System.Windows.Forms.Border3DStyle.Sunken;
            this.tslblLine.Name = "tslblLine";
            this.tslblLine.Size = new System.Drawing.Size(100, 19);
            this.tslblLine.Text = " ";
            // 
            // lblNoOfLines
            // 
            this.lblNoOfLines.AutoSize = false;
            this.lblNoOfLines.BorderSides = ((System.Windows.Forms.ToolStripStatusLabelBorderSides)((((System.Windows.Forms.ToolStripStatusLabelBorderSides.Left | System.Windows.Forms.ToolStripStatusLabelBorderSides.Top)
                        | System.Windows.Forms.ToolStripStatusLabelBorderSides.Right)
                        | System.Windows.Forms.ToolStripStatusLabelBorderSides.Bottom)));
            this.lblNoOfLines.BorderStyle = System.Windows.Forms.Border3DStyle.Sunken;
            this.lblNoOfLines.Name = "lblNoOfLines";
            this.lblNoOfLines.Size = new System.Drawing.Size(150, 19);
            this.lblNoOfLines.Text = "# Lines";
            // 
            // tsLblSearching
            // 
            this.tsLblSearching.Name = "tsLblSearching";
            this.tsLblSearching.Size = new System.Drawing.Size(84, 19);
            this.tsLblSearching.Text = "tsLblSearching";
            this.tsLblSearching.Visible = false;
            // 
            // lblLoaded
            // 
            this.lblLoaded.AutoSize = false;
            this.lblLoaded.BorderSides = ((System.Windows.Forms.ToolStripStatusLabelBorderSides)((((System.Windows.Forms.ToolStripStatusLabelBorderSides.Left | System.Windows.Forms.ToolStripStatusLabelBorderSides.Top)
                        | System.Windows.Forms.ToolStripStatusLabelBorderSides.Right)
                        | System.Windows.Forms.ToolStripStatusLabelBorderSides.Bottom)));
            this.lblLoaded.BorderStyle = System.Windows.Forms.Border3DStyle.Sunken;
            this.lblLoaded.Name = "lblLoaded";
            this.lblLoaded.Size = new System.Drawing.Size(1200, 19);
            this.lblLoaded.Text = "-";
            this.lblLoaded.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // tslSrchText
            // 
            this.tslSrchText.Name = "tslSrchText";
            this.tslSrchText.Size = new System.Drawing.Size(12, 19);
            this.tslSrchText.Text = "_";
            // 
            // panel3
            // 
            this.panel3.Controls.Add(this.splitContainer1);
            this.panel3.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panel3.Location = new System.Drawing.Point(0, 27);
            this.panel3.Name = "panel3";
            this.panel3.Size = new System.Drawing.Size(1564, 556);
            this.panel3.TabIndex = 4;
            // 
            // splitContainer1
            // 
            this.splitContainer1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer1.Location = new System.Drawing.Point(0, 0);
            this.splitContainer1.Name = "splitContainer1";
            // 
            // splitContainer1.Panel1
            // 
            this.splitContainer1.Panel1.Controls.Add(this.treeView1);
            this.splitContainer1.Panel1.Controls.Add(this.panel1);
            // 
            // splitContainer1.Panel2
            // 
            this.splitContainer1.Panel2.Controls.Add(this.splitContainer2);
            this.splitContainer1.Panel2.Controls.Add(this.panel2);
            this.splitContainer1.Size = new System.Drawing.Size(1564, 556);
            this.splitContainer1.SplitterDistance = 229;
            this.splitContainer1.TabIndex = 2;
            // 
            // treeView1
            // 
            this.treeView1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.treeView1.HideSelection = false;
            this.treeView1.Location = new System.Drawing.Point(0, 23);
            this.treeView1.Name = "treeView1";
            this.treeView1.Size = new System.Drawing.Size(229, 533);
            this.treeView1.TabIndex = 0;
            this.treeView1.BeforeSelect += new System.Windows.Forms.TreeViewCancelEventHandler(this.treeView1_BeforeSelect);
            this.treeView1.AfterSelect += new System.Windows.Forms.TreeViewEventHandler(this.treeView1_AfterSelect);
            this.treeView1.Click += new System.EventHandler(this.treeView1_Click);
            this.treeView1.DoubleClick += new System.EventHandler(this.treeView1_DoubleClick);
            this.treeView1.MouseMove += new System.Windows.Forms.MouseEventHandler(this.treeView1_MouseMove);
            // 
            // panel1
            // 
            this.panel1.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.panel1.Controls.Add(this.lblTreeView);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel1.Location = new System.Drawing.Point(0, 0);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(229, 23);
            this.panel1.TabIndex = 1;
            // 
            // lblTreeView
            // 
            this.lblTreeView.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblTreeView.Location = new System.Drawing.Point(0, 0);
            this.lblTreeView.Name = "lblTreeView";
            this.lblTreeView.Size = new System.Drawing.Size(225, 19);
            this.lblTreeView.TabIndex = 0;
            this.lblTreeView.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // splitContainer2
            // 
            this.splitContainer2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer2.Location = new System.Drawing.Point(0, 23);
            this.splitContainer2.Name = "splitContainer2";
            this.splitContainer2.Orientation = System.Windows.Forms.Orientation.Horizontal;
            // 
            // splitContainer2.Panel1
            // 
            this.splitContainer2.Panel1.Controls.Add(this.textBox1);
            // 
            // splitContainer2.Panel2
            // 
            this.splitContainer2.Panel2.Controls.Add(this.listBox1);
            this.splitContainer2.Size = new System.Drawing.Size(1331, 533);
            this.splitContainer2.SplitterDistance = 389;
            this.splitContainer2.TabIndex = 4;
            // 
            // listBox1
            // 
            this.listBox1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.listBox1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.5F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.listBox1.FormattingEnabled = true;
            this.listBox1.HorizontalScrollbar = true;
            this.listBox1.Location = new System.Drawing.Point(0, 0);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(1331, 140);
            this.listBox1.TabIndex = 4;
            this.listBox1.SelectedIndexChanged += new System.EventHandler(this.listBox1_SelectedIndexChanged);
            this.listBox1.DoubleClick += new System.EventHandler(this.dblClickListbox);
            this.listBox1.MouseMove += new System.Windows.Forms.MouseEventHandler(this.listBox1_MouseMove);
            // 
            // panel2
            // 
            this.panel2.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.panel2.Controls.Add(this.lblListbox);
            this.panel2.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel2.Location = new System.Drawing.Point(0, 0);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(1331, 23);
            this.panel2.TabIndex = 1;
            // 
            // lblListbox
            // 
            this.lblListbox.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblListbox.Location = new System.Drawing.Point(0, 0);
            this.lblListbox.Name = "lblListbox";
            this.lblListbox.Size = new System.Drawing.Size(1327, 19);
            this.lblListbox.TabIndex = 0;
            this.lblListbox.Text = "______";
            this.lblListbox.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // unparsedDynamicSQLToolStripMenuItem
            // 
            this.unparsedDynamicSQLToolStripMenuItem.Name = "unparsedDynamicSQLToolStripMenuItem";
            this.unparsedDynamicSQLToolStripMenuItem.Size = new System.Drawing.Size(198, 22);
            this.unparsedDynamicSQLToolStripMenuItem.Text = "Unparsed Dynamic SQL";
            // 
            // textBox1
            // 
            this.textBox1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.textBox1.Font = new System.Drawing.Font("Courier New", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBox1.HideSelection = false;
            this.textBox1.Location = new System.Drawing.Point(0, 0);
            this.textBox1.Multiline = true;
            this.textBox1.Name = "textBox1";
            this.textBox1.ReadOnly = true;
            this.textBox1.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.textBox1.Size = new System.Drawing.Size(1331, 389);
            this.textBox1.TabIndex = 3;
            this.textBox1.WordWrap = false;
            this.textBox1.searchStarted += new SearchableControls.SearchableTextBox.searchStartedArgs(this.textBox1_searchStarted);
            this.textBox1.searchRelated += new SearchableControls.SearchableTextBox.searchForLineArgs(this.textBox1_searchRelated);
            this.textBox1.searchForFunctionCall += new SearchableControls.SearchableTextBox.searchForFunctionCallArgs(this.textBox1_searchForFunctionCall);
            this.textBox1.clickContext += new System.EventHandler(this.textBox1_clickContext);
            this.textBox1.DoubleClick += new System.EventHandler(this.textBox1_DoubleClick);
            this.textBox1.MouseMove += new System.Windows.Forms.MouseEventHandler(this.textBox1_MouseMove);
            this.textBox1.MouseUp += new System.Windows.Forms.MouseEventHandler(this.textBox1_MouseUp);
            // 
            // MainCalltreeWindow
            // 
            this.AllowDrop = true;
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1564, 607);
            this.Controls.Add(this.panel3);
            this.Controls.Add(this.statusStrip1);
            this.Controls.Add(this.menuStrip1);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "MainCalltreeWindow";
            this.Text = "Calltree Viewer";
            this.Load += new System.EventHandler(this.MainCalltreeWindow_Load);
            this.DragDrop += new System.Windows.Forms.DragEventHandler(this.MainCalltreeWindow_DragDrop);
            this.DragEnter += new System.Windows.Forms.DragEventHandler(this.MainCalltreeWindow_DragEnter);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.statusStrip1.ResumeLayout(false);
            this.statusStrip1.PerformLayout();
            this.panel3.ResumeLayout(false);
            this.splitContainer1.Panel1.ResumeLayout(false);
            this.splitContainer1.Panel2.ResumeLayout(false);
            this.splitContainer1.ResumeLayout(false);
            this.panel1.ResumeLayout(false);
            this.splitContainer2.Panel1.ResumeLayout(false);
            this.splitContainer2.Panel1.PerformLayout();
            this.splitContainer2.Panel2.ResumeLayout(false);
            this.splitContainer2.ResumeLayout(false);
            this.panel2.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem mnLoad;
        private System.Windows.Forms.ToolStripMenuItem mnExit;
        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.ToolStripStatusLabel tslblLine;
        private System.Windows.Forms.ToolStripStatusLabel lblLoaded;
        private System.Windows.Forms.ToolStripMenuItem tsFileLoadMainRecursive;
        private System.Windows.Forms.ToolStripMenuItem tsFileLoadMain;
        private System.Windows.Forms.ToolStripMenuItem treeToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem collapseToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem showAllToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem expandShowAllToolStripMenuItem;
        private System.Windows.Forms.ToolStripStatusLabel lblNoOfLines;
        private System.Windows.Forms.ToolStripMenuItem findFunctionToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem functionToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem referencesToolStripMenuItem;
        private System.Windows.Forms.ToolStripComboBox tscbFindFunction;
        private System.Windows.Forms.ToolStripMenuItem expandCurrentNodeShowToolStripMenuItem;
        private System.Windows.Forms.ToolStripStatusLabel tsLblSearching;
        private System.Windows.Forms.ToolStripMenuItem referencesToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem findAllExternalReferencesToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem findExternalReferencesForThisModuleToolStripMenuItem;
        private System.Windows.Forms.ToolStripComboBox cbModules;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem simpleModeToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem findFunctionsThatAreNotCalledToolStripMenuItem;
        private System.Windows.Forms.ToolStripStatusLabel tslSrchText;
        private System.Windows.Forms.ToolStripMenuItem cRUDToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem updatesToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem deleteToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem insertToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem selectToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem dEFINELIKEToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem eXECUTEPROCEDUREToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem environmentVariablesToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem mnLocationBack;
        private System.Windows.Forms.ToolStripMenuItem mnLocationForward;
        private System.Windows.Forms.ToolStripMenuItem RunsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem formsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem filesToolStripMenuItem;
        private System.Windows.Forms.Panel panel3;
        private System.Windows.Forms.SplitContainer splitContainer1;
        private System.Windows.Forms.TreeView treeView1;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Label lblTreeView;
        private System.Windows.Forms.SplitContainer splitContainer2;
        private SearchableControls.SearchableTextBox textBox1;
        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Label lblListbox;
        private System.Windows.Forms.ToolStripMenuItem test1ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem unparsedDynamicSQLToolStripMenuItem;
    }
}

