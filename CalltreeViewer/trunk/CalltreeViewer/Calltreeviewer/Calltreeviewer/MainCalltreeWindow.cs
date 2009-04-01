using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.Xml.Serialization;

namespace Calltreeviewer
{
    public partial class MainCalltreeWindow : Form
    {
        private AubitCalltreeViewer.PROGRAM curr_program;
        int currentModuleNo = -1;
        //TreeNode fullyExpandedTree = null;
        TreeNode foundTreeNode = null;
        private int lastHighlightedLine = -1;
        private bool actioningUserInteraction = false;
        private TreeNode lastSelectedNode=null;
        private int spinCnt = 0;

        private enum TreeStyle
        {
            TreeStyleNormal,
            TreeStyleMainRecurse,
            TreeStyleMain
        };

        public MainCalltreeWindow()
        {
            InitializeComponent();
        }



        private void mnLoad_Click(object sender, EventArgs e)
        {
            loadXMLFile(TreeStyle.TreeStyleNormal);
        }

        private void loadXMLFile(TreeStyle style)
        {
            OpenFileDialog f = new OpenFileDialog();
            
            // Set up the dialog box..
            f.DefaultExt = "xml";
            f.AddExtension = true;
            f.CheckFileExists = true;
            f.CheckPathExists = true;
            f.Filter = "Calltree file|*.xml";

            // Show the dialog box - and check the OK button was
            // clicked...
            if (f.ShowDialog() == DialogResult.OK)
            {
                curr_program = null;

                // Get the filename from the dialog box..
                if (f.FileName != null)
                {
                    string fileXML = null;
                    
                    
                    AubitCalltreeViewer.PROGRAM p;
                    try
                    {
                      
                     
                        this.Cursor = Cursors.WaitCursor;
                        // We've got the filename - so use it
                        // with our XML deserializer to get a PROGRAM
                        //
                        fileXML = File.ReadAllText(f.FileName);
                        System.Type t;
                        t = typeof(AubitCalltreeViewer.PROGRAM);
                        XmlSerializer ser;
                        ser = new XmlSerializer(t);

                        TextReader r = new StringReader(fileXML);

                        p = (AubitCalltreeViewer.PROGRAM)ser.Deserialize(r);
                        curr_program = p;
                        

                        // Now - show the tree..
                        loadTree(p, style);
                        this.Cursor = Cursors.Default;
                    }
                    catch (Exception ex)
                    {
                        // Something went wrong - tell the user
                        // and dont worry about it...
                        MessageBox.Show(ex.ToString());
                    }
                }
            }
            lblLoaded.Text = "";
        }

        private void loadTree(AubitCalltreeViewer.PROGRAM p, TreeStyle style)
        {
            TreeNode mainNode = null;
//            fullyExpandedTree = null;
            // We'll be making a lot of changes - so
            // 'BeginUpdate' so they all get entered in one go..
            treeView1.BeginUpdate();
            treeView1.Nodes.Clear();

            
            // Clear down our 'quickfind' lists...
            tscbFindFunction.Items.Clear();
            cbModules.Items.Clear();
            listBox1.Items.Clear();
            listBox1.Sorted = false;

            if (style == TreeStyle.TreeStyleNormal || style == TreeStyle.TreeStyleMainRecurse || style == TreeStyle.TreeStyleMain)
            {
                lblListbox.Text = "Module";
                lblTreeView.Text = "Program";
            }


            if (style == TreeStyle.TreeStyleMainRecurse)
            {
                // These menu options are only available if the tree
                // is a fully recursed MAIN style tree...
                findAllExternalReferencesToolStripMenuItem.Enabled = true;
                findExternalReferencesForThisModuleToolStripMenuItem.Enabled = true;
                findFunctionsThatAreNotCalledToolStripMenuItem.Enabled = true;
            }
            else
            {
                // Disable them as they are not compatible with this tree type
                findAllExternalReferencesToolStripMenuItem.Enabled = false;
                findExternalReferencesForThisModuleToolStripMenuItem.Enabled = false;
                findFunctionsThatAreNotCalledToolStripMenuItem.Enabled = false;
            }



            // Add all the module names to our module 'quicklist'...
            for (int a = 0; a < p.MODULES.Length; a++)
            {
                moduleForList li;
                
                li = new moduleForList(p.MODULES[a].MODULENO, p.MODULES[a].NAME, p.MODULES[a].FULLNAME);
                cbModules.Items.Add(li);
            }


            for (int a = 0; a < p.FUNCTION.Length; a++)
            {
                TreeNode newNode = null;
                tscbFindFunction.Items.Add(p.FUNCTION[a].NAME);

                if (style == TreeStyle.TreeStyleNormal)
                {
                    newNode = treeView1.Nodes.Add(a.ToString(), p.FUNCTION[a].NAME);
                }

                if ((style==TreeStyle.TreeStyleMain || style==TreeStyle.TreeStyleMainRecurse) && p.FUNCTION[a].NAME == "MAIN" && mainNode == null) {
                    newNode = treeView1.Nodes.Add(a.ToString(), p.FUNCTION[a].NAME);
                    if (style == TreeStyle.TreeStyleMainRecurse)
                    {
                        expandNode(newNode, true);
                    }
                }
                
                if (p.FUNCTION[a].NAME == "MAIN" && mainNode == null)
                {    
                    mainNode = newNode;
                }
            }


            if (style == TreeStyle.TreeStyleNormal)
            {
                treeView1.Sort();
            }

            
            tscbFindFunction.Sorted = true;


            if (mainNode != null)
            {
                treeView1.CollapseAll();
                selectNode(mainNode);
                //treeView1.SelectedNode = mainNode;
                displayModuleForSelectedNode();
            }
            
            treeView1.EndUpdate();
        }

        private void selectNode(TreeNode node)
        {

            if (node == null) return;
            // Highlight the selected node..
            // because of the way the Focus works - we
            // need to manually highlight the node
            // so its always visible...

            /*if (lastSelectedNode!=null && lastSelectedNode!=node)
            {
                lastSelectedNode.BackColor = SystemColors.Window;
                lastSelectedNode.ForeColor = SystemColors.WindowText;
                lastSelectedNode = null;
            }
             * 
            if (node == null) return;
            */

            /*
            node.BackColor = SystemColors.Highlight;
            node.ForeColor = SystemColors.HighlightText;
             * */
            if (treeView1.SelectedNode != node)
            {
                treeView1.SelectedNode = null;
                treeView1.SelectedNode = node;
                treeView1.Focus();
                treeView1.SelectedNode.EnsureVisible();
            }
            
            
            lastSelectedNode = node;
            Application.DoEvents();
        }


        private void displayModuleForSelectedNode()
        {

            tsLblSearching.Text = "tsLblSearching:  "+treeView1.SelectedNode.Name;

            if (treeView1.SelectedNode.Name.StartsWith("->"))
            {
                displayCall(treeView1.SelectedNode.Name);
                return;
            }

            if (treeView1.SelectedNode.Name.StartsWith(":"))
            {
                LocationInFile lif = new LocationInFile(treeView1.SelectedNode.Name.Substring(1));
                if (lif != null)
                {
                    lblLoaded.Text=lif.ModuleNo+" "+lif.LineNo+" "+curr_program.MODULES[lif.ModuleNo].FULLNAME;
                    loadModule(lif.ModuleNo);
                    setModuleLine(lif.LineNo);
                    return;
                }
                // does nothing...
                return;
            }

            if (treeView1.SelectedNode.Name == "")
            {
                return;
            }

            // must be a function...
            int findex = Convert.ToInt32(treeView1.SelectedNode.Name);
            loadModule(curr_program.FUNCTION[findex].MODULENO);
            setModuleLine(curr_program.FUNCTION[findex].LINE);
        }

        private void displayCall(string p)
        {
            int functionNo;
            functionNo = findFunctionNo(p);
            if (functionNo == -1) return;
            loadModule(curr_program.FUNCTION[functionNo].MODULENO);
            setModuleLine(curr_program.FUNCTION[functionNo].LINE);
        }

        private void setModuleLine(int line)
        {
            int index;
            string b4;

            

            // Scroll back to the top - so we always scroll down to
            // our selected line...
            textBox1.Select(0,1);
            textBox1.ScrollToCaret();
            textBox1.Focus();
            Application.DoEvents();





            tslblLine.Text = "Line :" + line;



            if (lastHighlightedLine >= 0)
            {
                if (textBox1.Lines[lastHighlightedLine].Substring(6, 3) == "-->")
                {
                    index = textBox1.GetFirstCharIndexFromLine(lastHighlightedLine);
                    textBox1.Select(index, textBox1.Lines[lastHighlightedLine].Length);
                    textBox1.SelectedText = textBox1.Lines[lastHighlightedLine].Substring(0, 5) + "     " + textBox1.Lines[lastHighlightedLine].Substring(10);
                }
            }

            Application.DoEvents();
            // Highlight our current row..
            index = textBox1.GetFirstCharIndexFromLine(line - 1);

            if (index >= 0)
            {
                textBox1.Select(index, textBox1.Lines[line - 1].Length);
                b4 = textBox1.SelectedText;

                // The 'select' doesn't always work (if we select from the tree for example)
                // so add a '-->' to point to our line...
                textBox1.SelectedText = textBox1.Lines[line - 1].Substring(0, 5) + " --> " + textBox1.Lines[line - 1].Substring(10);
                lastHighlightedLine = line - 1;
                textBox1.Select(index, textBox1.Lines[line - 1].Length);
                textBox1.ScrollToCaret();

                textBox1.Focus();

                Application.DoEvents();
            }
            else
            {
                MessageBox.Show("Unable to go to line " + line + " of " + textBox1.Lines.Length);
            }
        }

        private void loadModule(int module_no)
        {
  
            

            if (module_no == currentModuleNo)
            {
                return;
            }

           
            string line;
            lastHighlightedLine = -1;
            line = "";
            for (int a = 0; a < curr_program.MODULES[module_no].LINE.Length; a++)
            {
                string s;
                int b;
                s = curr_program.MODULES[module_no].LINE[a].Text;
                if (s == null)
                {
                    s = "";

                }
                b = a + 1;
                line += b.ToString("00000")+"     "+ s + "\r\n";
            }
            textBox1.Text = line;

            currentModuleNo = module_no;
            lblNoOfLines.Text = "Total of "+curr_program.MODULES[module_no].LINE.Length+" Lines in module";
            lblListbox.Text = curr_program.MODULES[module_no].NAME+ " Full Path :"  + curr_program.MODULES[module_no].FULLNAME;
            textBox1.SelectionLength = 0;
            textBox1.SelectionStart = 0;
            Application.DoEvents();
        }

        private void treeView1_AfterSelect(object sender, TreeViewEventArgs e)
        {
            displayModuleForSelectedNode();
            selectNode(treeView1.SelectedNode);
        }

        private void treeView1_DoubleClick(object sender, EventArgs e)
        {
            TreeNode selectedNode;
            if (actioningUserInteraction) return; // Already busy...
            treeView1.SuspendLayout();
            actioningUserInteraction = true;



            selectedNode = treeView1.SelectedNode;
            selectNode(selectedNode);
            if (selectedNode.Name == null) { actioningUserInteraction = false; return; }
            if (selectedNode.Name == "") { actioningUserInteraction = false; return; }
            
            if (selectedNode.Name.StartsWith(":")) { actioningUserInteraction = false; return; }

            expandNode(selectedNode, false);

            actioningUserInteraction = false;
            treeView1.ResumeLayout();
        }


        private int findFunctionNo(string name)
        {
            int functionNo = -1;
            if (name.StartsWith(":"))
            {
                return -1;
            }
         
            if (name.StartsWith("->"))
            {
                for (int a = 0; a < curr_program.FUNCTION.Length; a++)
                {
                    if (curr_program.FUNCTION[a].NAME == name.Substring(2))
                    {
                        functionNo = a;
                        break;
                    }
                }
            }
            else
            {
                functionNo = Convert.ToInt32(name);
            }
            return functionNo;
        }

        private void expandNode(TreeNode selectedNode,bool recurse)
        {
            int functionNo = findFunctionNo(selectedNode.Name);
            Application.DoEvents();
            selectedNode.Nodes.Clear();
            treeView1.SuspendLayout();

            spin();
            if (functionNo == -1) return;

            if (curr_program.FUNCTION[functionNo].COMMANDS.Items != null)
            {
                for (int a = 0; a < curr_program.FUNCTION[functionNo].COMMANDS.Items.Length; a++)
                {
                    //toolStripProgressBar.Maximum = treeView1.GetNodeCount(true);
                    //toolStripProgressBar.Value = selectedNode.Index;

                    buildNodes(curr_program.FUNCTION[functionNo].MODULENO, selectedNode, curr_program.FUNCTION[functionNo].COMMANDS.Items[a], recurse,simpleModeToolStripMenuItem.Checked);
                    Application.DoEvents();
                }
            }
            treeView1.ResumeLayout();
        }

        private void buildNodes(int moduleNo, TreeNode selectedNode, object o, bool recurse, bool callsOnly)
        {
            TreeNode newNode;
            TreeNode rNode;
            string type;
            Application.DoEvents();
            AubitCalltreeViewer.CALLS callcmd;
            AubitCalltreeViewer.IF ifcmd;
            AubitCalltreeViewer.CASE casecmd;
            AubitCalltreeViewer.CONSTRUCT constructcmd;
            AubitCalltreeViewer.DISPLAYARRAY displayarraycmd;
            AubitCalltreeViewer.FINISH finishcmd;
            AubitCalltreeViewer.START startcmd;
            AubitCalltreeViewer.FOR forcmd;
            AubitCalltreeViewer.FOREACH foreachcmd;
            AubitCalltreeViewer.INPUT inputcmd;
            AubitCalltreeViewer.INPUTARRAY inputarraycmd;
            AubitCalltreeViewer.MENU menucmd;
            AubitCalltreeViewer.OUTPUT outputcmd;
            AubitCalltreeViewer.PROMPT promptcmd;
            AubitCalltreeViewer.WHILE whilecmd;
            AubitCalltreeViewer.COMMANDS cmds;
            AubitCalltreeViewer.WHENEVER whenever;
            //AubitCalltreeViewer.EVENT events;


            spin();

            type = o.GetType().ToString();
            switch (type)
            {

                case "AubitCalltreeViewer.CALLS":
                    callcmd = (AubitCalltreeViewer.CALLS)o;
                    
                    newNode = selectedNode.Nodes.Add(":" + LocationInFile.getString(moduleNo, callcmd.LINE), "CALLS " + callcmd.FUNCTIONNAME);
                    rNode = newNode.Nodes.Add("->" + callcmd.FUNCTIONNAME, callcmd.FUNCTIONNAME);
                    if (!isRecursing(selectedNode, callcmd.FUNCTIONNAME) && recurse)
                    {
                        expandNode(rNode, true);
                    }
                    break;

                case "AubitCalltreeViewer.COMMANDS":
                    cmds = (AubitCalltreeViewer.COMMANDS)o;
                    if (cmds.Items != null)
                    {
                        for (int a = 0; a < cmds.Items.Length; a++)
                        {
                            buildNodes(moduleNo, selectedNode, cmds.Items[a], recurse, callsOnly);
                        }
                    }
                    break;

                case "AubitCalltreeViewer.CASE":
                    casecmd = (AubitCalltreeViewer.CASE)o;
                    if (!callsOnly)
                    {
                        newNode = selectedNode.Nodes.Add(":" + LocationInFile.getString(moduleNo, casecmd.LINE), "CASE " + casecmd.TESTAGAINST);
                    }
                    else
                    {
                        newNode = selectedNode;
                    }

                    if (casecmd.WHEN != null)
                    {
                        for (int a = 0; a < casecmd.WHEN.Length; a++)
                        {
                            TreeNode whenNode;
                            if (!callsOnly)
                            {
                                whenNode = newNode.Nodes.Add(":" + LocationInFile.getString(moduleNo, casecmd.WHEN[a].LINE), "WHEN " + casecmd.WHEN[a].CONDITION);
                            }
                            else
                            {
                                whenNode = selectedNode;
                            }
                            buildNodes(moduleNo, whenNode, casecmd.WHEN[a].COMMANDS, recurse, callsOnly);
                        }
                    }
                    break;

                case "AubitCalltreeViewer.WHILE":
                    whilecmd = (AubitCalltreeViewer.WHILE)o;
                    if (!callsOnly)
                    {
                        newNode = selectedNode.Nodes.Add(":" + LocationInFile.getString(moduleNo, whilecmd.LINE), "WHILE " + whilecmd.CONDITION);
                    }
                    else
                    {
                        newNode = selectedNode;
                    }

                    buildNodes(moduleNo, newNode, whilecmd.COMMANDS, recurse, callsOnly);
                    break;

                case "AubitCalltreeViewer.IF":
                    ifcmd = (AubitCalltreeViewer.IF)o;
                    if (!callsOnly)
                    {
                        newNode = selectedNode.Nodes.Add(":" + LocationInFile.getString(moduleNo, ifcmd.LINE), "IF " + ifcmd.CONDITION);
                    }
                    else
                    {
                        newNode = selectedNode;
                    }

                    for (int a = 0; a < ifcmd.Items.Length; a++)
                    {
                        object onew;
                        onew = ifcmd.Items[a];
                        if (onew.GetType().ToString() == "AubitCalltreeViewer.ONTRUE")
                        {
                            //TreeNode ontrue;
                            //ontrue=newNode.Nodes.Add("TRUE");
                            buildNodes(moduleNo, newNode, ((AubitCalltreeViewer.ONTRUE)ifcmd.Items[a]).COMMANDS, recurse, callsOnly);
                            continue;
                        }
                        if (onew.GetType().ToString() == "AubitCalltreeViewer.ONFALSE")
                        {
                            AubitCalltreeViewer.ONFALSE of;
                            TreeNode onfalse;
                            of = (AubitCalltreeViewer.ONFALSE)onew;
                            if (!callsOnly)
                            {
                                onfalse = newNode.Nodes.Add(":" + LocationInFile.getString(moduleNo, of.LINE), "ELSE");
                            }
                            else
                            {
                                onfalse = selectedNode;
                            }
                            buildNodes(moduleNo, onfalse, ((AubitCalltreeViewer.ONFALSE)ifcmd.Items[a]).COMMANDS, recurse, callsOnly);
                            continue;
                        }
                        MessageBox.Show("Unexpected IF contents..");
                        //buildNodes(newNode, ifcmd.Items[a]);
                    }
                    break;

                case "AubitCalltreeViewer.FOR":
                    forcmd = (AubitCalltreeViewer.FOR)o;
                    if (!callsOnly)
                    {
                        newNode = selectedNode.Nodes.Add(":" + LocationInFile.getString(moduleNo, forcmd.LINE), "FOR " + forcmd.START + " " + forcmd.END + " STEP " + forcmd.STEP);
                    }
                    else
                    {
                        newNode = selectedNode;
                    }
                    buildNodes(moduleNo, newNode, forcmd.COMMANDS, recurse, callsOnly);
                    break;

                case "AubitCalltreeViewer.FOREACH":
                    foreachcmd = (AubitCalltreeViewer.FOREACH)o;
                    if (!callsOnly)
                    {
                        newNode = selectedNode.Nodes.Add(":" + LocationInFile.getString(moduleNo, foreachcmd.LINE), "FOREACH ");
                    }
                    else
                    {
                        newNode = selectedNode;
                    }
                    buildNodes(moduleNo, newNode, foreachcmd.COMMANDS, recurse, callsOnly);
                    break;


                case "AubitCalltreeViewer.FINISH":
                    finishcmd = (AubitCalltreeViewer.FINISH)o;
                    newNode = selectedNode.Nodes.Add("->" + finishcmd.REPORT, "FINISH REPORT " + finishcmd.REPORT);
                    rNode = newNode.Nodes.Add("->" + finishcmd.REPORT, finishcmd.REPORT);
                    if (!isRecursing(selectedNode, finishcmd.REPORT) && recurse)
                    {
                        expandNode(rNode, true);
                    }
                    break;

                case "AubitCalltreeViewer.START":
                    startcmd = (AubitCalltreeViewer.START)o;
                    newNode = selectedNode.Nodes.Add("->" + startcmd.REPORT, "START REPORT " + startcmd.REPORT);

                    rNode = newNode.Nodes.Add("->" + startcmd.REPORT, startcmd.REPORT);
                    if (!isRecursing(selectedNode, startcmd.REPORT) && recurse)
                    {
                        expandNode(rNode, true);
                    }

                    break;

                case "AubitCalltreeViewer.OUTPUT":
                    outputcmd = (AubitCalltreeViewer.OUTPUT)o;
                    newNode = selectedNode.Nodes.Add("->" + outputcmd.REPORT, "OUTPUT TO REPORT " + outputcmd.REPORT);

                    rNode = newNode.Nodes.Add("->" + outputcmd.REPORT, outputcmd.REPORT);
                    if (!isRecursing(selectedNode, outputcmd.REPORT) && recurse)
                    {
                        expandNode(rNode, true);
                    }
                    break;


                case "AubitCalltreeViewer.CONSTRUCT":
                    constructcmd = (AubitCalltreeViewer.CONSTRUCT)o;
                    if (!callsOnly)
                    {
                        newNode = selectedNode.Nodes.Add(":" + LocationInFile.getString(moduleNo, constructcmd.LINE), "CONSTRUCT");
                    }
                    else
                    {
                        newNode = selectedNode;
                    }
                    buildNodes(moduleNo, newNode, constructcmd.EVENTS, recurse, callsOnly);
                    break;


                case "AubitCalltreeViewer.INPUT":
                    inputcmd = (AubitCalltreeViewer.INPUT)o;
                    if (!callsOnly)
                    {
                        newNode = selectedNode.Nodes.Add(":" + LocationInFile.getString(moduleNo, inputcmd.LINE), "INPUT");
                    }
                    else
                    {
                        newNode = selectedNode;
                    }
                    buildNodes(moduleNo, newNode, inputcmd.EVENTS, recurse, callsOnly);
                    break;



                case "AubitCalltreeViewer.INPUTARRAY":
                    inputarraycmd = (AubitCalltreeViewer.INPUTARRAY)o;
                    if (!callsOnly)
                    {
                        newNode = selectedNode.Nodes.Add(":" + LocationInFile.getString(moduleNo, inputarraycmd.LINE), "INPUTARRAY");
                    }
                    else
                    {
                        newNode = selectedNode;
                    }
                    buildNodes(moduleNo, newNode, inputarraycmd.EVENTS, recurse, callsOnly);
                    break;

                case "AubitCalltreeViewer.DISPLAYARRAY":

                    displayarraycmd = (AubitCalltreeViewer.DISPLAYARRAY)o;
                    if (!callsOnly)
                    {
                        newNode = selectedNode.Nodes.Add(":" + LocationInFile.getString(moduleNo, displayarraycmd.LINE), "DISPLAYARRAY");
                    }
                    else
                    {
                        newNode = selectedNode;
                    }
                    buildNodes(moduleNo, newNode, displayarraycmd.EVENTS, recurse, callsOnly);
                    break;

                case "AubitCalltreeViewer.MENU":
                    menucmd = (AubitCalltreeViewer.MENU)o;
                    if (!callsOnly)
                    {
                        newNode = selectedNode.Nodes.Add(":" + LocationInFile.getString(moduleNo, menucmd.LINE), "MENU");
                    }
                    else
                    {
                        newNode = selectedNode;
                    }
                    buildNodes(moduleNo, newNode, menucmd.EVENTS, recurse, callsOnly);
                    break;

                case "AubitCalltreeViewer.PROMPT":
                    promptcmd = (AubitCalltreeViewer.PROMPT)o;
                    if (!callsOnly)
                    {
                        newNode = selectedNode.Nodes.Add(":" + LocationInFile.getString(moduleNo, promptcmd.LINE), "PROMPT");
                    }
                    else
                    {
                        newNode = selectedNode;
                    }
                    buildNodes(moduleNo, newNode, promptcmd.EVENTS, recurse, callsOnly);
                    break;

                case "AubitCalltreeViewer.EVENT[]":
                    AubitCalltreeViewer.EVENT[] events;
                    events = (AubitCalltreeViewer.EVENT[])o;
                    if (events != null)
                    {
                        for (int a = 0; a < events.Length; a++)
                        {
                            string nodeText;
                            AubitCalltreeViewer.EVENT e;
                            e = events[a];
                            if (e.EVENT_TYPE == "MENU_COMMAND")
                            {
                                if (e.SHORT != null && e.SHORT != "")
                                {
                                    nodeText = e.SHORT;
                                }
                                else
                                {
                                    nodeText = "Key(" + e.KEYS + ")";
                                }
                            }
                            else
                            {
                                nodeText = e.EVENT_TYPE + " " + e.DATA;
                            }
                            if (!callsOnly)
                            {
                                newNode = selectedNode.Nodes.Add(":" + LocationInFile.getString(moduleNo, e.LINE), nodeText);
                            }
                            else
                            {
                                newNode = selectedNode;
                            }
                            buildNodes(moduleNo, newNode, e.COMMANDS, recurse, callsOnly);
                        }
                    }

                    break;

                case "AubitCalltreeViewer.WHENEVER":
                    whenever = (AubitCalltreeViewer.WHENEVER)o;
                    if (!callsOnly)
                    {
                        newNode = selectedNode.Nodes.Add(":" + LocationInFile.getString(moduleNo, whenever.CALLS.LINE), "WHENEVER ERROR");
                    }
                    else
                    {
                        newNode = selectedNode;
                    }
                    buildNodes(moduleNo, newNode, whenever.CALLS, recurse, callsOnly);
                    break;

                default:
                    MessageBox.Show("Unexpected type:" + type);
                    break;

            }
            selectedNode.ExpandAll();
        }

        private void spin()
        {
            spinCnt++;
            if (spinCnt > 1000)
            {
                spinCnt = 0;

                switch (lblLoaded.Text)
                {
                    case "/":
                        lblLoaded.Text = "-"; break;
                    case "-":
                        lblLoaded.Text = "\\"; break;
                    case "\\":
                        lblLoaded.Text = "|"; break;
                    case "|":
                        lblLoaded.Text = "/"; break;
                    default:
                        lblLoaded.Text = "-"; break;
                }
                Application.DoEvents();
            }
        }

        /// <summary>
        /// invert the tree to see all the callers of a function
        /// </summary>
        /// <param name="selectedNode">node to invert</param>
        private void invertTree(string name)
        {
            /*
            TreeView v;
            string fnName;
            int functionNo;
            functionNo=findFunctionNo(name);

            if (functionNo == -1)  {
                            MessageBox.Show("Only looking for functions atm...");
                return;
            }

            fnName = curr_program.FUNCTION[functionNo].NAME;
            
            if (fullyExpandedTree == null)
            {
                fullyExpandedTree = new TreeNode();
                for (int a = 0; a < curr_program.FUNCTION.Length; a++)
                {
                    

                    if (curr_program.FUNCTION[a].NAME == "MAIN")
                    {
                        TreeNode newNode=fullyExpandedTree.Nodes.Add(a.ToString(),"MAIN");
                        
                        //newNode.Nodes.Add(a.ToString(), p.FUNCTION[a].NAME);
                        expandNode(fullyExpandedTree.Nodes[0], true);
                        break;
                    }
                }
            }
            v = new TreeView();
            v.Nodes.Clear();
            v.Nodes.Add(fullyExpandedTree);
            v.PathSeparator = "-->";
            */

            // Firstly  - lets find all occurences in our current tree
            TreeNode[] callees = treeView1.Nodes.Find("->"+name, true);
            listBox1.Sorted = false;
            listBox1.Items.Clear();
            for (int a = 0; a < callees.Length; a++)
            {
                listBox1.Items.Add( new treeNodeForList( callees[a]));
            }

            if (callees.Length == 0)
            {
                MessageBox.Show("That function does not appear to be directly or indirectly called from 'MAIN'");
            } 


        }


        private bool isRecursing(TreeNode selectedNode, string p)
        {
            string s;
            if (selectedNode.Parent == null) return false;
            if (selectedNode.Parent.Text == p) return true;

            s = "\\"+selectedNode.FullPath+"\\";
            return (s.Contains("\\" + p + "\\"));
            
        }






        private void loadXmlFileMain(object sender, EventArgs e)
        {
            loadXMLFile(TreeStyle.TreeStyleMain);
        }




        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }



        private void dblClickListbox(object sender, EventArgs e)
        {


            if (actioningUserInteraction) return; // Already busy...


            actioningUserInteraction = true;


            foundTreeNode = null;
            if (listBox1.SelectedIndex >= 0)
            {



                if (listBox1.Items[listBox1.SelectedIndex].GetType()== typeof(functionForList))
                {
                    functionForList f;
                    f=(functionForList)listBox1.SelectedItem;
                    loadModule(f.ModuleNo);
                    setModuleLine(f.LineNo);
                    actioningUserInteraction = false;
                        return;
                }


                if (listBox1.Items[listBox1.SelectedIndex].GetType() == typeof(treeNodeForList))
                {
                    treeNodeForList tnl;
                    tnl = (treeNodeForList)listBox1.SelectedItem;
                    //tnl.selectNode();
                    selectNode(tnl.getNodeForSelection());


                    //treeView1.SelectedNode = tnl.getNodeForSelection();
                    
                    actioningUserInteraction = false;
                    return;
                }
                
                string path=listBox1.Items[listBox1.SelectedIndex].ToString();
                for (int a = 0; a < treeView1.Nodes.Count; a++)
                {
                    if (selectPath(treeView1.Nodes[a], path.Substring(3)))
                    {
                        if (foundTreeNode!=null)
                        {
                            
                            //treeView1.SelectedNode = null;

                            if (foundTreeNode.Text.StartsWith("CALLS"))
                            {
                                selectNode(foundTreeNode);
                                //treeView1.SelectedNode = foundTreeNode;
                            }
                            else
                            {
                                selectNode(foundTreeNode.Parent);
                                //treeView1.SelectedNode = foundTreeNode.Parent;
                            }
                            
                            treeView1.Focus();
                            Application.DoEvents();
                            //MessageBox.Show("Is it highlighted???");
                        }
                    }
                }
            }

            actioningUserInteraction = false;
        }

        private bool selectPath(TreeNode topnode, string path)
        {
            string thispath;
            string nextpath;

            
            if (path.IndexOf("-->")>=0) {
                thispath=path.Substring(0,path.IndexOf("-->"));

                if (topnode.Text != thispath) return false;

                nextpath=path.Substring(path.IndexOf("-->")+3);
                if (topnode.Nodes.Count == 0)
                {
                    expandNode(topnode, false);
                }
                 for (int a=0;a<topnode.Nodes.Count;a++) {
                     if (selectPath(topnode.Nodes[a], nextpath))
                     {
                         return true;
                     }
                }
                return false;
            } else {
                if (topnode.Text == path)
                {

                    //treeView1.CollapseAll();
                   
                    foundTreeNode = topnode;
                    
                  
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }

        private void collapseToolStripMenuItem_Click(object sender, EventArgs e)
        {
            treeView1.BeginUpdate();
            treeView1.CollapseAll();
            treeView1.EndUpdate();
        }

        private void showAllToolStripMenuItem_Click(object sender, EventArgs e)
        {
            treeView1.BeginUpdate();
            treeView1.ExpandAll();
            treeView1.EndUpdate();
        }

        private void expandShowAllToolStripMenuItem_Click(object sender, EventArgs e)
        {
            treeView1.BeginUpdate();
            for (int a = 0; a < treeView1.Nodes.Count; a++)
            {
                expandNode(treeView1.Nodes[a], true);
            }
            treeView1.EndUpdate();
            treeView1.ExpandAll();
        }

        private void mnExit_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void MainCalltreeWindow_Load(object sender, EventArgs e)
        {
            lblNoOfLines.Text = "";
            lblListbox.Text = "";
            tsLblSearching.Text = "";
            lblLoaded.Text = "";
        }

        private void findFunctionToolStripMenuItem_Click(object sender, EventArgs e)
        {
            tscbFindFunction.SelectedItem = null;
        }



        private void functionToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            int functionNo;
            if (tscbFindFunction.Text == null || tscbFindFunction.Text=="" || tscbFindFunction.Text=="<function>") return;
            functionNo = findFunctionNo("->"+tscbFindFunction.Text);
            if (functionNo == -1) return;

            if (tscbFindFunction.SelectedItem != null)
            {
                TreeNode[] nodes=null;
                
                if (treeView1.Nodes.Count > 1)
                {
                    nodes=treeView1.Nodes.Find(""+functionNo, false);
                }
                else
                {
                    int first=-1;
                    TreeNode firstNode=null;
                    int next=-1;
                    TreeNode nextNode=null;
                    int currentIndex;
                    TreeNode cnode = treeView1.SelectedNode;
                    currentIndex=cnode.Index;
                    nodes = treeView1.Nodes.Find("->" + tscbFindFunction.Text, true);

                    for (int a = 0; a < nodes.Length; a++)
                    {
                        if (first == -1)
                        {
                            first = nodes[a].Index;
                            firstNode=nodes[a];
                        }
                        if (nodes[a].Index < first) {first = nodes[a].Index;
                            firstNode=nodes[a];
                        }

                        if (nodes[a].Index > currentIndex && next == -1)
                        {
                            next = nodes[a].Index;
                            nextNode=nodes[a];
                        }
                        if (nodes[a].Index > currentIndex && nodes[a].Index < next)
                        {
                            next = nodes[a].Index;
                            nextNode=nodes[a];
                        }
                    }
                    if (next != -1 && next != currentIndex)
                    {
                        // We have something following..
                        nodes = new TreeNode[1];
                        nodes[0] = nextNode;
                    }
                    else
                    {
                        // No next node - should we wrap around to the start ? 
                        if (first != -1 )
                        {
                            // Of course - firstnode could be the current node - but
                            // then - no harm no foul...
                            nodes = new TreeNode[1];
                            nodes[0] = firstNode;
                        }
                    }
                }


                if (nodes.Length > 0)
                {
                    // Did we find something ?
                    // lets highlight it..
                    
                    selectNode(nodes[0]);
                    
                }
            }
        }

        private void referencesToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (tscbFindFunction.Text != null)
            {
                invertTree(tscbFindFunction.Text);
            }
        }

        private void expandCurrentNodeShowToolStripMenuItem_Click(object sender, EventArgs e)
        {
            treeView1.BeginUpdate();

                expandNode(treeView1.SelectedNode, true);

                treeView1.SelectedNode.ExpandAll();
            treeView1.EndUpdate();
            treeView1.SelectedNode.EnsureVisible();
        }

        private void loadXmlMainRecursive(object sender, EventArgs e)
        {

            loadXMLFile(TreeStyle.TreeStyleMainRecurse);
        }



        private void cbModules_SelectedIndexChanged(object sender, EventArgs e)
        {
            loadSelectedModule();
        }

        private void toolStripMenuItem1_Click(object sender, EventArgs e)
        {
            loadSelectedModule();
        }

        private void loadSelectedModule()
        {
            if (cbModules.Text!=null && cbModules.Text != "<module>")
            {
                moduleForList mi = (moduleForList)cbModules.SelectedItem;
                if (mi != null)
                {
                    loadModule(mi.moduleNo);
                }
            }
        }



        private void textBox1_MouseMove(object sender, MouseEventArgs e)
        {
            if (!textBox1.Focused)
            {
                textBox1.Focus();
            }
        }

        private void treeView1_MouseMove(object sender, MouseEventArgs e)
        {
            
            if (!treeView1.Focused)
            {
                treeView1.Focus();
            }
        }

        

        private void findAllExternalReferencesToolStripMenuItem_Click(object sender, EventArgs e)
        {
            string oldPathSep;
            // only enabled if MAIN/Recursive is selected..
            System.Collections.Hashtable listOfFunctionsCalled;
            listOfFunctionsCalled = new System.Collections.Hashtable();
            TreeNode n = treeView1.Nodes[0];
            scanForCallsInNodes(listOfFunctionsCalled, n,-1);


            oldPathSep = treeView1.PathSeparator;
            //treeView1.PathSeparator = "-->";

            listBox1.Sorted = false;
            listBox1.Items.Clear();

            foreach (string s in listOfFunctionsCalled.Keys)
            {
                int found = 0;
                for (int b = 0; b < curr_program.FUNCTION.Length; b++)
                {
                    if (curr_program.FUNCTION[b].NAME == s)
                    {
                        found++;
                        break;
                    }
                }

                if (found==0)
                {
                    List<TreeNode> td;
                    td=(List<TreeNode>)listOfFunctionsCalled[s];
                    
                    listBox1.Items.Add("External reference: " + s);
                    for (int a=0;a<td.Count;a++) {
                        listBox1.Items.Add(new treeNodeForList( td[a]));
                    }
                }

            }
            //treeView1.PathSeparator = oldPathSep;
        }


        /// <summary>
        /// Build a string list of all functions that are actually called...
        /// </summary>
        /// <param name="listOfFunctionsCalled">Hashtable to store the list in</param>
        /// <param name="srchnode">top level node to search</param>
        /// <param name="onlyModuleNo">search only in a single module (-1 for all modules)</param>
        private void scanForCallsInNodes(System.Collections.Hashtable listOfFunctionsCalled, TreeNode srchnode, int onlyModuleNo)
        {
            if (srchnode.Nodes.Count>0)
            {
                for (int a = 0; a < srchnode.Nodes.Count; a++)
                {
                    scanForCallsInNodes(listOfFunctionsCalled, srchnode.Nodes[a], onlyModuleNo);
                }
            }

            if (srchnode.Text.StartsWith("CALLS"))
            {
                List<TreeNode> nodes;
                nodes=(List<TreeNode>)listOfFunctionsCalled[srchnode.Text.Substring(6)];
                if (nodes==null)
                {
                    nodes = new List<TreeNode>();
                    listOfFunctionsCalled[srchnode.Text.Substring(6)] = nodes;
                }
                nodes.Add(srchnode);
            }
        }

        private void listBox1_MouseMove(object sender, MouseEventArgs e)
        {
            if (!listBox1.Focused)
            {
                listBox1.Focus();
            }
        }

        private void findFunctionsThatAreNotCalledToolStripMenuItem_Click(object sender, EventArgs e)
        {
            
            System.Collections.SortedList sl;
            // only enabled if MAIN/Recursive is selected..
            System.Collections.Hashtable listOfFunctionsCalled;
            listOfFunctionsCalled = new System.Collections.Hashtable();

            TreeNode n = treeView1.Nodes[0];
            scanForCallsInNodes(listOfFunctionsCalled, n, -1);
            sl = new System.Collections.SortedList();
            listBox1.Items.Clear();
            listBox1.Sorted = true;
            for (int b = 0; b < curr_program.FUNCTION.Length; b++)
            {
                if (!listOfFunctionsCalled.ContainsKey(curr_program.FUNCTION[b].NAME))
                {
                    if (curr_program.FUNCTION[b].NAME != "MAIN")
                    {
                        listBox1.Items.Add(new functionForList(curr_program.FUNCTION[b].NAME,curr_program.FUNCTION[b].MODULENO,curr_program.FUNCTION[b].LINE));
                    }
                }
            }
           

        }

        private void treeView1_Click(object sender, EventArgs e)
        {
            selectNode(treeView1.SelectedNode);
        }

        private void treeView1_BeforeSelect(object sender, TreeViewCancelEventArgs e)
        {
            selectNode(null);
        }
    }
}