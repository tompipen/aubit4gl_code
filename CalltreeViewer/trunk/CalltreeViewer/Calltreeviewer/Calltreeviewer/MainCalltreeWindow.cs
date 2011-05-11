using System;
using System.Collections.Generic;
using System.Windows.Forms;
using System.IO;
using System.Xml.Serialization;
using SearchableControls;
using System.IO.Compression;
using System.Text;

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
        private bool loading;
        private TreeNode lastSelectedNode=null;
        private int spinCnt = 0;
        private string loadFile = null;
        int currentFunctionStart=-1;
        int currentFunctionEnd=-1;




        List<symbolFunction> allFunctions = new List<symbolFunction>();
        //List<SymbolLocation> allCalls = new List<SymbolLocation>();

        List<NLocationInFile> previousLocations = new List<NLocationInFile>();
        int previousLocationIndicator = 0;


        private List<AubitCalltreeViewer.SYMBOL> current_global_variables = null;
        private List<AubitCalltreeViewer.SYMBOL> current_module_variables = null;
        private List<AubitCalltreeViewer.SYMBOL> current_local_variables = null;


        private enum TreeStyle
        {
            TreeStyleNormal,
            TreeStyleMainRecurse,
            TreeStyleMain
        };

        public MainCalltreeWindow(string[] args)
        {
            InitializeComponent();


            if (args.Length>0) {
                loadFile = args[0];
            
            }
            
        }



        private void mnLoad_Click(object sender, EventArgs e)
        {
            loadXMLFile(TreeStyle.TreeStyleNormal,null);
        }

        private void loadXMLFile(TreeStyle style, string fileName)
        {
            TreeNode mainNode = null;
            loading = true;

            currentModuleNo = -1;


            if (fileName == null)
            {
                OpenFileDialog f = new OpenFileDialog();

                // Set up the dialog box..
                f.DefaultExt = "xml";
                f.AddExtension = true;
                f.CheckFileExists = true;
                f.CheckPathExists = true;
                f.Filter = "Calltree file|*.xml|Compressed Calltree file|*.calltree.xml.gz;calltree.xml.gz|Other Files|*.*";

                // Show the dialog box - and check the OK button was
                // clicked...
                if (f.ShowDialog() == DialogResult.OK)
                {
                    curr_program = null;

                    // Get the filename from the dialog box..
                    if (f.FileName != null)
                    {

                        fileName = f.FileName;
                    }
                }
            }


            treeView1.Enabled = false;

            if (fileName != null)
            {
                string fileXML = null;


                AubitCalltreeViewer.PROGRAM p;
                try
                {
                    textBox1.Text = "Please wait - loading file";

                    this.Cursor = Cursors.WaitCursor;
                    // We've got the filename - so use it
                    // with our XML deserializer to get a PROGRAM

                    if (fileName.EndsWith(".gz"))
                    {
                        byte[] gzBuffer = File.ReadAllBytes(fileName);
                        StringBuilder stringBuilder = new StringBuilder();

                        using (MemoryStream ms = new MemoryStream())
                        {
                            int gzlen;
                            gzlen = gzBuffer.Length;
                            //int msgLength = BitConverter.ToInt32(gzBuffer, 0);
                            ms.Write(gzBuffer, 0, gzlen);
                            ms.Position = 0;
                            byte[] byteArray = new byte[1024];
                            using (GZipStream zip = new GZipStream(ms, CompressionMode.Decompress))
                            {
                                int readBytes;
                                while ((readBytes = zip.Read(byteArray, 0, byteArray.Length)) != 0)
                                {
                                    for (int i = 0; i < readBytes; i++)
                                        stringBuilder.Append((char)byteArray[i]);
                                }
                            }

                            fileXML =  stringBuilder.ToString();

                        }
                    }
                    else
                    {
                        fileXML = File.ReadAllText(fileName);
                    }
                    
                    System.Type t;
                    t = typeof(AubitCalltreeViewer.PROGRAM);
                    XmlSerializer ser;
                    ser = new XmlSerializer(t);

                    TextReader r = new StringReader(fileXML);

                    p = (AubitCalltreeViewer.PROGRAM)ser.Deserialize(r);
                    curr_program = p;


                    allFunctions.Clear();
                    

                    
                    current_global_variables = new List<AubitCalltreeViewer.SYMBOL>();
                    for (int module_no = 0; module_no < curr_program.MODULES.Length; module_no++)
                    {
                        if (curr_program.MODULES[module_no].GLOBAL_VARIABLES != null)
                        {
                            appendVariables(current_global_variables, curr_program.MODULES[module_no].NAME, curr_program.MODULES[module_no].GLOBAL_VARIABLES); 
                        }
                    }
                    setCRUD();

                    // Now - show the tree..
                    mainNode=loadTree(p, style);
                    this.Cursor = Cursors.Default;
                    this.Text = "Calltree for " + fileName;
                }
                catch (Exception ex)
                {
                    textBox1.Text = "";
                    // Something went wrong - tell the user
                    // and dont worry about it...
                    MessageBox.Show(ex.ToString());
                }

            }
            lblLoaded.Text = "";
            treeView1.Enabled = true;
            
            previousLocations.Clear();
            previousLocationIndicator = 0;
            textBox1.Text = "";
            loading = false;

            if (mainNode!=null)
            {
                treeView1.CollapseAll();
                selectNode(mainNode);
                
                displayModuleForSelectedNode();
            }
            loading = false;
        }





        private TreeNode loadTree(AubitCalltreeViewer.PROGRAM p, TreeStyle style)
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
            cRUDToolStripMenuItem.Visible = false;

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
                cRUDToolStripMenuItem.Visible = true;
            }
            else
            {
                // Disable them as they are not compatible with this tree type
                findAllExternalReferencesToolStripMenuItem.Enabled = false;
                findExternalReferencesForThisModuleToolStripMenuItem.Enabled = false;
                findFunctionsThatAreNotCalledToolStripMenuItem.Enabled = false;
                cRUDToolStripMenuItem.Visible = false;
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

                if (!p.FUNCTION[a].CALLED) continue;

                tscbFindFunction.Items.Add(p.FUNCTION[a].NAME);

                if (style == TreeStyle.TreeStyleNormal)
                {
                    //newNode = treeView1.Nodes.Add(a.ToString(), p.FUNCTION[a].NAME);
                    newNode = new MyFunctionNode(p.FUNCTION[a].NAME,p.FUNCTION[a].MODULENO, a, p.FUNCTION[a].LINE, get_line(p.FUNCTION[a].MODULE, p.FUNCTION[a].LINE), p.FUNCTION[a].LINE, p.FUNCTION[a].LASTLINE);
                    treeView1.Nodes.Add(newNode);
                }

                if ((style==TreeStyle.TreeStyleMain || style==TreeStyle.TreeStyleMainRecurse) && p.FUNCTION[a].NAME == "MAIN" && mainNode == null) {
                   // newNode = treeView1.Nodes.Add(a.ToString(), p.FUNCTION[a].NAME);
                    newNode = new MyFunctionNode(p.FUNCTION[a].NAME, p.FUNCTION[a].MODULENO, a, p.FUNCTION[a].LINE, get_line(p.FUNCTION[a].MODULE, p.FUNCTION[a].LINE), p.FUNCTION[a].LINE, p.FUNCTION[a].LASTLINE);
                    treeView1.Nodes.Add(newNode);
                    if (style == TreeStyle.TreeStyleMainRecurse)
                    {
                        treeView1.SuspendLayout();
                        treeView1.BeginUpdate();
                        expandNode(newNode, true);
                        treeView1.EndUpdate();
                        treeView1.ResumeLayout();
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


            if (mainNode != null && false)
            {
                treeView1.CollapseAll();
                selectNode(mainNode);
                displayModuleForSelectedNode();
            }
            
            treeView1.EndUpdate();
            //selectedNode.ExpandAll();
            return mainNode;
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

            if (treeView1.SelectedNode is MyCallNode)
            {
                displayCall((MyCallNode)treeView1.SelectedNode);
                return;
            }

            if (treeView1.SelectedNode is MyLocationNode)
            {
                MyLocationNode lnode = treeView1.SelectedNode as MyLocationNode;

                
                if (lnode != null)
                {
                    lblLoaded.Text = lnode.Module + " " + lnode.LineNumber + " " + curr_program.MODULES[lnode.Module].FULLNAME;


                    loadModuleLine(lnode.Module, lnode.LineNumber, true);
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
            loadModuleLine(curr_program.FUNCTION[findex].MODULENO,curr_program.FUNCTION[findex].LINE,true);
        }

        private void displayCall(MyCallNode p)
        {
            int functionNo;
            functionNo = findFunctionNo(p);
            if (functionNo == -1) return;
            loadModuleLine(curr_program.FUNCTION[functionNo].MODULENO,curr_program.FUNCTION[functionNo].LINE,true);
        }


        private void loadModuleLine(int moduleNo, int line,bool saveMove)
        {
            if (loadModule(moduleNo))
            {
                setModuleLine(line);
            }

            NLocationInFile l = new NLocationInFile(moduleNo, line);
            //previousLocations.Add(l);
            if (saveMove) addLocation(l);
        }


        private void addLocation(NLocationInFile l)
        {
            if (previousLocations.Count > 0 && previousLocations.Count-1 == previousLocationIndicator)
            {
                if (previousLocations[previousLocationIndicator].ModuleNo == l.ModuleNo && previousLocations[previousLocationIndicator].LineNo == l.LineNo) return;
            }
            while (previousLocations.Count > previousLocationIndicator+1)
            {
                previousLocations.RemoveAt(previousLocations.Count-1);
            }
            previousLocations.Add(l);
            previousLocationIndicator = previousLocations.Count - 1;

            EnableLocationButtons();
        }

        private void loadModuleLine(string module, int line,bool saveMove)
        {
            
                for (int a = 0; a < curr_program.MODULES.Length; a++)
                {
                    if (module == curr_program.MODULES[a].NAME)
                    {
                        loadModuleLine(a, line,saveMove);
                        return;
                    }
                }
                MessageBox.Show("Unable to find module:" + module);
            
        }




        private void setModuleLine(int line)
        {
            int index;
            string b4;

            if (line == 0)
            {
                MessageBox.Show("Invalid line passed in");
                return;
            }
            if (textBox1.Text.StartsWith("Please wait"))
            {
                return;
            }
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
            if (line > 0)
            {
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
        }

        private bool loadModule(int module_no)
        {


            currentFunctionStart = -1;
            currentFunctionEnd = -1;

            if (module_no == currentModuleNo)
            {
                return true;
            }


            current_module_variables = new List<AubitCalltreeViewer.SYMBOL>();
            if (curr_program.MODULES[module_no].MODULE_VARIABLES!=null)
            {
                appendVariables(current_module_variables, curr_program.MODULES[module_no].NAME, curr_program.MODULES[module_no].MODULE_VARIABLES); 
                //current_module_variables.AddRange(curr_program.MODULES[module_no].MODULE_VARIABLES);
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
            return true;
        }

        private void appendVariables(List<AubitCalltreeViewer.SYMBOL> variables, string moduleName, AubitCalltreeViewer.VARIABLE[] vARIABLE)
        {
            for (int a = 0; a < vARIABLE.Length; a++)
            {
                AubitCalltreeViewer.SYMBOL s;
                s = new AubitCalltreeViewer.SYMBOL();
                s.LINE = vARIABLE[a].LINE;
                s.MODULE = moduleName;
                s.NAME = vARIABLE[a].NAME;
                s.OPERATION = "DEFINE";
                s.TYPE = "VARIABLE";
                s.SCOPE = "-";
                variables.Add(s);
            }
        }

        private void treeView1_AfterSelect(object sender, TreeViewEventArgs e)
        {
            if (!loading)
            {
                displayModuleForSelectedNode();
                selectNode(treeView1.SelectedNode);
            }
            else
            {
                MessageBox.Show("The program has not finished loading yet!");
            }
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
            
            if (selectedNode is MyLocationNode) { actioningUserInteraction = false; return; }

            expandNode(selectedNode, false);

            actioningUserInteraction = false;
            treeView1.ResumeLayout();
        }




        private int findFunctionNo(MyCallNode mycall)
        {
            int functionNo = -1;
         
            
                for (int a = 0; a < curr_program.FUNCTION.Length; a++)
                {
                    if (curr_program.FUNCTION[a].NAME == mycall.functionName)
                    {
                        functionNo = a;
                        break;
                    }
                }
            
            
            return functionNo;
        }




        private void expandNode(TreeNode selectedNode,bool recurse)
        {
            int functionNo=-1;
            if (selectedNode is MyCallNode)
            {
                functionNo = findFunctionNo((MyCallNode)selectedNode);
            }


            if (selectedNode is MyFunctionNode)
            {
                MyFunctionNode mfn = selectedNode as MyFunctionNode;
                if (mfn.FunctionName == "MAIN")
                {
                    functionNo = findFunctionNo(new MyCallNode("MAIN"));
                }
            }


            
            
            selectedNode.Nodes.Clear();
            //treeView1.SuspendLayout();

            spin();
            //spin(selectedNode.FullPath);
            //tslSrchText.Text = "Expanding : " + selectedNode.FullPath;
            //Application.DoEvents();
            //tslblLine.Text = "Expanding : "+selectedNode.FullPath;
            if (functionNo == -1) return;



                if (curr_program.FUNCTION[functionNo].COMMANDS.Items != null && curr_program.FUNCTION[functionNo].CALLED)
                {

                    for (int a = 0; a < curr_program.FUNCTION[functionNo].COMMANDS.Items.Length; a++)
                    {
                        buildNodes(curr_program.FUNCTION[functionNo].MODULENO, functionNo, selectedNode, curr_program.FUNCTION[functionNo].COMMANDS.Items[a], recurse, simpleModeToolStripMenuItem.Checked, true);
                        //        Application.DoEvents();
                    }
                }
            
        }


        /// <summary>
        /// Generate TreeView nodes
        /// </summary>
        /// <param name="moduleNo">Mode to generate for</param>
        /// <param name="functionNo">Function number which contains these nodes</param>
        /// <param name="selectedNode">Nodes to append to</param>
        /// <param name="o">'command' to add to treenode</param>
        /// <param name="recurse">Recursively process ? </param>
        /// <param name="callsOnly">Include on the calls ? (no coniditionals)</param>
        /// <param name="fullExpansion">Include conditionals where there are no subsequent calls ? </param>
        private void buildNodes(int moduleNo, int functionNo, TreeNode selectedNode, object o, bool recurse, bool callsOnly, bool fullExpansion)
        {
            string type;

            /*
            TreeNode newNode;
            
            TreeNode rNode;
            
            string type;


            
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
            
            AubitCalltreeViewer.WHENEVER whenever;
            
            //AubitCalltreeViewer.EVENT events;
           

            
            */
            //spin();

            type = o.GetType().ToString();

            //newLocationNode = null;
            switch (type)
            {

                case "AubitCalltreeViewer.CALLS":
                    {
                        AubitCalltreeViewer.CALLS callcmd;
                        SymbolLocation sl;
                        MyLocationNode newLocationNode;
                        MyCallNode callNode;

                        callcmd = (AubitCalltreeViewer.CALLS)o;
                        sl = generateSymbolLocation(callcmd, curr_program.MODULES[moduleNo].NAME);

                        symbolFunction sf = getAllFunctionsEntryFor(callcmd.FUNCTIONNAME);

                        if (!sl.InList(sf))
                        {
                            sf.symbols.Add(sl);
                        }

                        newLocationNode = new MyLocationNode(moduleNo, functionNo, callcmd.LINE, "CALLS " + callcmd.FUNCTIONNAME);

                        selectedNode.Nodes.Add(newLocationNode);


                        callNode = new MyCallNode(callcmd.FUNCTIONNAME);
                        newLocationNode.Nodes.Add(callNode);
                        if (!isRecursing(selectedNode, callcmd.FUNCTIONNAME) && recurse)
                        {
                            expandNode(callNode, true);
                        }
                    }
                    break;




                case "AubitCalltreeViewer.COMMANDS":
                    {
                        AubitCalltreeViewer.COMMANDS cmds;
                        cmds = (AubitCalltreeViewer.COMMANDS)o;
                        if (cmds.Items != null)
                        {
                            for (int a = 0; a < cmds.Items.Length; a++)
                            {
                                buildNodes(moduleNo, functionNo, selectedNode, cmds.Items[a], recurse, callsOnly, fullExpansion);
                            }
                        }
                        if (selectedNode is MyLocationNode)
                        {
                            MyLocationNode mln = selectedNode as MyLocationNode;
                            mln.ensureLines(functionNo, cmds.LINE, cmds.LASTLINE);
                        }
                    }
                    break;


                case "AubitCalltreeViewer.SECTION":
                    {
                        MyLocationNode newLocationNode;
                        AubitCalltreeViewer.SECTION section;
                        section = (AubitCalltreeViewer.SECTION)o;
                        newLocationNode = new MyLocationNode(moduleNo, functionNo, section.LINE, section.TYPE.Replace("_", " "));
                        selectedNode.Nodes.Add(newLocationNode);

                        if (section.TYPE != null)
                        {
                            MyLocationNode mln = selectedNode as MyLocationNode;
                            if (mln != null && section.COMMANDS != null)
                            {
                                mln.ensureLines(functionNo, section.COMMANDS.LINE, section.COMMANDS.LASTLINE);
                            }
                            newLocationNode.ensureLines(functionNo, section.COMMANDS.LINE, section.COMMANDS.LASTLINE);

                            if (section.COMMANDS.Items != null)
                            {
                                for (int a = 0; a < section.COMMANDS.Items.Length; a++)
                                {
                                    buildNodes(moduleNo, functionNo, newLocationNode, section.COMMANDS.Items[a], recurse, callsOnly, fullExpansion);
                                }

                            }
                        }
                    }
                    break;


                case "AubitCalltreeViewer.CASE":
                    {
                        MyLocationNode newLocationNode;
                        AubitCalltreeViewer.CASE casecmd;
                        TreeNode newNode;
                        casecmd = (AubitCalltreeViewer.CASE)o;
                        if (!callsOnly)
                        {
                            newLocationNode = new MyLocationNode(moduleNo, functionNo, casecmd.LINE, "CASE " + casecmd.TESTAGAINST);
                            selectedNode.Nodes.Add(newLocationNode);
                            newNode = newLocationNode;
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
                                    whenNode = new MyLocationNode(moduleNo, functionNo, casecmd.WHEN[a].LINE, "WHEN " + casecmd.WHEN[a].CONDITION);
                                    newNode.Nodes.Add(whenNode);
                                }
                                else
                                {
                                    whenNode = selectedNode;
                                }
                                buildNodes(moduleNo, functionNo, whenNode, casecmd.WHEN[a].COMMANDS, recurse, callsOnly, fullExpansion);
                            }
                        }
                    }
                    break;

                case "AubitCalltreeViewer.WHILE":
                    {
                        MyLocationNode newLocationNode;
                        AubitCalltreeViewer.WHILE whilecmd;
                        TreeNode newNode;
                         whilecmd = (AubitCalltreeViewer.WHILE)o;
                        if (!callsOnly)
                        {
                            newLocationNode = new MyLocationNode(moduleNo, functionNo, whilecmd.LINE, "WHILE " + whilecmd.CONDITION, whilecmd.COMMANDS.LINE, whilecmd.COMMANDS.LASTLINE);
                            selectedNode.Nodes.Add(newLocationNode);
                            newNode = newLocationNode;
                        }
                        else
                        {
                            newNode = selectedNode;
                        }

                        buildNodes(moduleNo, functionNo, newNode, whilecmd.COMMANDS, recurse, callsOnly, fullExpansion);


                        if (!callsOnly && newNode.Nodes.Count == 0 && !fullExpansion)
                        {
                            newNode.Remove();
                        }
                    }

                    break;

                case "AubitCalltreeViewer.IF":
                    {
                        MyLocationNode newLocationNode;
                        AubitCalltreeViewer.IF ifcmd;

                        ifcmd = (AubitCalltreeViewer.IF)o;
                        TreeNode newNode;

                        if (!callsOnly)
                        {
                            newLocationNode = new MyLocationNode(moduleNo, functionNo, ifcmd.LINE, "IF " + ifcmd.CONDITION);
                            selectedNode.Nodes.Add(newLocationNode);
                            newNode = newLocationNode;
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

                                buildNodes(moduleNo, functionNo, newNode, ((AubitCalltreeViewer.ONTRUE)ifcmd.Items[a]).COMMANDS, recurse, callsOnly, fullExpansion);

                                continue;
                            }
                            if (onew.GetType().ToString() == "AubitCalltreeViewer.ONFALSE")
                            {
                                AubitCalltreeViewer.ONFALSE of;
                                TreeNode onfalse;
                                of = (AubitCalltreeViewer.ONFALSE)onew;
                                if (!callsOnly)
                                {
                                    onfalse = new MyLocationNode(moduleNo, functionNo, of.LINE, "ELSE");
                                    newNode.Nodes.Add(onfalse);
                                }
                                else
                                {
                                    onfalse = selectedNode;
                                }

                                buildNodes(moduleNo, functionNo, onfalse, ((AubitCalltreeViewer.ONFALSE)ifcmd.Items[a]).COMMANDS, recurse, callsOnly, fullExpansion);

                                // Dont include an empty "ELSE"
                                if (!callsOnly && onfalse.Nodes.Count == 0 && !fullExpansion)
                                {
                                    onfalse.Remove();
                                }
                                else
                                {

                                }
                                continue;
                            }
                            MessageBox.Show("Unexpected IF contents..");
                            //buildNodes(newNode, ifcmd.Items[a]);
                        }

                        if (!callsOnly && newNode.Nodes.Count == 0 && !fullExpansion)
                        {
                            // Dont show it if theres nothing under it..
                            newNode.Remove();
                        }
                    }
                    break;

                case "AubitCalltreeViewer.FOR":
                    {
                        TreeNode newNode;
                        AubitCalltreeViewer.FOR forcmd;
                        MyLocationNode newLocationNode;

                        forcmd = (AubitCalltreeViewer.FOR)o;
                        if (!callsOnly)
                        {
                            newLocationNode = new MyLocationNode(moduleNo, functionNo, forcmd.LINE, "FOR " + forcmd.START + " " + forcmd.END + " STEP " + forcmd.STEP);
                            newNode = newLocationNode;
                            selectedNode.Nodes.Add(newNode);
                        }
                        else
                        {
                            newNode = selectedNode;
                        }
                        buildNodes(moduleNo, functionNo, newNode, forcmd.COMMANDS, recurse, callsOnly, fullExpansion);
                        if (!callsOnly && newNode.Nodes.Count == 0 && !fullExpansion)
                        {
                            newNode.Remove();
                        }
                    }
                    break;



                case "AubitCalltreeViewer.FOREACH":
                    {
                        MyLocationNode newLocationNode;
                        TreeNode newNode;
                        AubitCalltreeViewer.FOREACH foreachcmd;

                        foreachcmd = (AubitCalltreeViewer.FOREACH)o;
                        if (!callsOnly)
                        {
                            newLocationNode = new MyLocationNode(moduleNo, functionNo, foreachcmd.LINE, "FOREACH ");
                            newNode = newLocationNode;
                            selectedNode.Nodes.Add(newNode);
                        }
                        else
                        {
                            newNode = selectedNode;
                        }
                        buildNodes(moduleNo, functionNo, newNode, foreachcmd.COMMANDS, recurse, callsOnly, fullExpansion);

                        if (!callsOnly && newNode.Nodes.Count == 0 && !fullExpansion)
                        {
                            newNode.Remove();
                        }
                    }
                    break;


                case "AubitCalltreeViewer.FINISH":
                    {
                        MyLocationNode newLocationNode;
                        TreeNode newNode;
                        SymbolLocation sl;
                        TreeNode rNode;
                        AubitCalltreeViewer.FINISH finishcmd;

                        finishcmd = (AubitCalltreeViewer.FINISH)o;

                        sl = generateSymbolLocation(finishcmd, curr_program.MODULES[moduleNo].NAME);

                        symbolFunction sf = getAllFunctionsEntryFor(finishcmd.REPORT);

                        if (!sl.InList(sf))
                        {
                            sf.symbols.Add(sl);
                        }

                        newLocationNode = new MyLocationNode(moduleNo, functionNo, finishcmd.LINE, "FINISH REPORT " + finishcmd.REPORT);
                        newNode = newLocationNode;

                        selectedNode.Nodes.Add(newNode);
                        rNode = new MyCallNode(finishcmd.REPORT);
                        newNode.Nodes.Add(rNode);

                        if (!isRecursing(selectedNode, finishcmd.REPORT) && recurse)
                        {
                            expandNode(rNode, true);
                        }

                    }
                    break;

                case "AubitCalltreeViewer.START":
                    {
                        MyLocationNode newLocationNode;
                        TreeNode newNode;
                        SymbolLocation sl;
                        TreeNode rNode;
                        AubitCalltreeViewer.START startcmd;

                        startcmd = (AubitCalltreeViewer.START)o;
                        sl = generateSymbolLocation(startcmd, curr_program.MODULES[moduleNo].NAME);

                        symbolFunction sf = getAllFunctionsEntryFor(startcmd.REPORT);

                        if (!sl.InList(sf))
                        {
                            sf.symbols.Add(sl);
                        }
                        newLocationNode = new MyLocationNode(moduleNo, functionNo, startcmd.LINE, "START REPORT " + startcmd.REPORT);
                        newNode = newLocationNode;
                        selectedNode.Nodes.Add(newNode);


                        rNode = new MyCallNode(startcmd.REPORT);

                        newNode.Nodes.Add(rNode);

                        if (!isRecursing(selectedNode, startcmd.REPORT) && recurse)
                        {
                            expandNode(rNode, true);
                        }



                    }
                    break;

                case "AubitCalltreeViewer.OUTPUT":
                    {
                        MyLocationNode newLocationNode;
                        TreeNode newNode;
                        SymbolLocation sl;
                        TreeNode rNode;
                        AubitCalltreeViewer.OUTPUT outputcmd;

                        outputcmd = (AubitCalltreeViewer.OUTPUT)o;
                        sl = generateSymbolLocation(outputcmd, curr_program.MODULES[moduleNo].NAME);

                        symbolFunction sf = getAllFunctionsEntryFor(outputcmd.REPORT);

                        if (!sl.InList(sf))
                        {
                            sf.symbols.Add(sl);
                        }

                        newLocationNode = new MyLocationNode(moduleNo, functionNo, outputcmd.LINE, "OUTPUT TO REPORT " + outputcmd.REPORT);
                        newNode = newLocationNode;
                        selectedNode.Nodes.Add(newNode);

                        rNode =new MyCallNode(outputcmd.REPORT);
                        newNode.Nodes.Add(rNode);

                        if (!isRecursing(selectedNode, outputcmd.REPORT) && recurse)
                        {
                            expandNode(rNode, true);
                        }


                    }
                    break;


                case "AubitCalltreeViewer.CONSTRUCT":
                    {
                        MyLocationNode newLocationNode;
                        TreeNode newNode;
                        AubitCalltreeViewer.CONSTRUCT constructcmd;
                        constructcmd = (AubitCalltreeViewer.CONSTRUCT)o;
                        if (!callsOnly)
                        {
                            newLocationNode = new MyLocationNode(moduleNo, functionNo, constructcmd.LINE, "CONSTRUCT");
                            newNode = newLocationNode;
                            selectedNode.Nodes.Add(newNode);
                        }
                        else
                        {
                            newNode = selectedNode;
                        }
                        buildNodes(moduleNo, functionNo, newNode, constructcmd.EVENTS, recurse, callsOnly, fullExpansion);
                    }
                    break;


                case "AubitCalltreeViewer.INPUT":
                    {
                        MyLocationNode newLocationNode;
                        TreeNode newNode;
                        AubitCalltreeViewer.INPUT inputcmd;
                        inputcmd = (AubitCalltreeViewer.INPUT)o;
                        if (!callsOnly)
                        {
                            newLocationNode = new MyLocationNode(moduleNo, functionNo, inputcmd.LINE, "INPUT");
                            newNode = newLocationNode;
                            selectedNode.Nodes.Add(newNode);
                        }
                        else
                        {
                            newNode = selectedNode;
                        }
                        buildNodes(moduleNo, functionNo, newNode, inputcmd.EVENTS, recurse, callsOnly, fullExpansion);
                    }
                    break;



                case "AubitCalltreeViewer.INPUTARRAY":
                    {
                        MyLocationNode newLocationNode;
                        TreeNode newNode;
                        AubitCalltreeViewer.INPUTARRAY inputarraycmd;
                        inputarraycmd = (AubitCalltreeViewer.INPUTARRAY)o;
                        if (!callsOnly)
                        {

                            newLocationNode = new MyLocationNode(moduleNo, functionNo, inputarraycmd.LINE, "INPUTARRAY");
                            newNode = newLocationNode;
                            selectedNode.Nodes.Add(newNode);
                        }
                        else
                        {
                            newNode = selectedNode;
                        }
                        buildNodes(moduleNo, functionNo, newNode, inputarraycmd.EVENTS, recurse, callsOnly, fullExpansion);
                    }
                    break;

                case "AubitCalltreeViewer.DISPLAYARRAY":
                    {
                        MyLocationNode newLocationNode;
                        TreeNode newNode;
                        AubitCalltreeViewer.DISPLAYARRAY displayarraycmd;

                        displayarraycmd = (AubitCalltreeViewer.DISPLAYARRAY)o;
                        if (!callsOnly)
                        {
                            newLocationNode = new MyLocationNode(moduleNo, functionNo, displayarraycmd.LINE, "DISPLAYARRAY");

                            newNode = newLocationNode;
                            selectedNode.Nodes.Add(newNode);
                        }
                        else
                        {
                            newNode = selectedNode;
                        }

                        buildNodes(moduleNo, functionNo, newNode, displayarraycmd.EVENTS, recurse, callsOnly, fullExpansion);
                    }
                    break;

                case "AubitCalltreeViewer.MENU":
                    {
                        MyLocationNode newLocationNode;
                        TreeNode newNode;
                        AubitCalltreeViewer.MENU menucmd;
                        menucmd = (AubitCalltreeViewer.MENU)o;
                        if (!callsOnly)
                        {
                            newLocationNode = new MyLocationNode(moduleNo, functionNo, menucmd.LINE, "MENU");
                            newLocationNode.ensureLines(functionNo, menucmd.LINE);
                            newNode = newLocationNode;
                            selectedNode.Nodes.Add(newNode);
                        }
                        else
                        {
                            newNode = selectedNode;
                        }

                        buildNodes(moduleNo, functionNo, newNode, menucmd.EVENTS, recurse, callsOnly, fullExpansion);
                    }
                    break;

                case "AubitCalltreeViewer.PROMPT":
                    {
                        MyLocationNode newLocationNode;
                        TreeNode newNode;
                        AubitCalltreeViewer.PROMPT promptcmd;
                        promptcmd = (AubitCalltreeViewer.PROMPT)o;
                        if (!callsOnly)
                        {
                            newLocationNode = new MyLocationNode(moduleNo, functionNo, promptcmd.LINE, "PROMPT");
                            newNode = newLocationNode;
                            selectedNode.Nodes.Add(newNode);
                        }
                        else
                        {
                            newNode = selectedNode;
                        }
                        buildNodes(moduleNo, functionNo, newNode, promptcmd.EVENTS, recurse, callsOnly, fullExpansion);
                    }
                    break;

                case "AubitCalltreeViewer.EVENT[]":
                    {
                        MyLocationNode newLocationNode;
                        AubitCalltreeViewer.EVENT[] events;
                        events = (AubitCalltreeViewer.EVENT[])o;
                        TreeNode newNode;
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
                                    newLocationNode = new MyLocationNode(moduleNo, functionNo, e.LINE, nodeText);
                                    newNode = newLocationNode;
                                    selectedNode.Nodes.Add(newNode);
                                }
                                else
                                {
                                    newNode = selectedNode;
                                }
                                buildNodes(moduleNo, functionNo, newNode, e.COMMANDS, recurse, callsOnly, fullExpansion);

                            }
                        }
                    }
                    break;

                case "AubitCalltreeViewer.WHENEVER":
                    {
                        MyLocationNode newLocationNode;
                        TreeNode newNode;
                        AubitCalltreeViewer.WHENEVER whenever;
                        // Ignore WHENEVER calls...
                        break;


                        whenever = (AubitCalltreeViewer.WHENEVER)o;
                        if (!callsOnly)
                        {

                            newLocationNode = new MyLocationNode(moduleNo, functionNo, whenever.CALLS.LINE, "WHENEVER ERROR");
                            newNode = newLocationNode;
                            selectedNode.Nodes.Add(newNode);
                        }
                        else
                        {
                            newNode = selectedNode;
                        }
                        buildNodes(moduleNo, functionNo, newNode, whenever.CALLS, recurse, callsOnly, fullExpansion);
                    }
                    break;

                default:
                    MessageBox.Show("Unexpected type:" + type);
                    break;

            }
           // selectedNode.ExpandAll();         
        }

        private symbolFunction getAllFunctionsEntryFor(string p)
        {
            foreach (symbolFunction sf in allFunctions) {
                if (sf.symbolName == p) return sf;
            }

            symbolFunction sf_new = new symbolFunction();
            sf_new.symbolName = p;
            sf_new.symbols = new List<SymbolLocation>();
            sf_new.hasCall = false;
            sf_new.hasDefinition = false;
            allFunctions.Add(sf_new);
            return sf_new;
        }

        private SymbolLocation generateSymbolLocation( object cmd, string moduleName)
        {
            SymbolLocation sl;
            if (cmd is AubitCalltreeViewer.CALLS)
            {
                AubitCalltreeViewer.CALLS c=cmd as AubitCalltreeViewer.CALLS;
                sl= new SymbolLocation(moduleName, c.LINE,"FUNCTION","CALLS",get_line(moduleName,c.LINE));
                return sl;
            }

            if (cmd is AubitCalltreeViewer.START)
            {
                AubitCalltreeViewer.START c = cmd as AubitCalltreeViewer.START;
                sl= new SymbolLocation(moduleName, c.LINE, "FUNCTION", "CALLS", get_line(moduleName, c.LINE));                
                return sl;
            }

            if (cmd is AubitCalltreeViewer.FINISH)
            {
                AubitCalltreeViewer.FINISH c = cmd as AubitCalltreeViewer.FINISH;
                sl= new SymbolLocation(moduleName, c.LINE, "FUNCTION", "CALLS", get_line(moduleName, c.LINE));
                return sl;
            }

            if (cmd is AubitCalltreeViewer.OUTPUT)
            {
                AubitCalltreeViewer.OUTPUT c = cmd as AubitCalltreeViewer.OUTPUT;
                sl= new SymbolLocation(moduleName, c.LINE, "FUNCTION", "CALLS", get_line(moduleName, c.LINE));
                return sl;
            }

            throw new NotImplementedException();
        }



        /*
        private bool hasCall(List<SymbolLocation> allCalls, SymbolLocation sl)
        {
            foreach (SymbolLocation l in allCalls)
            {
                if (l.lineNo == sl.lineNo && l.moduleName == sl.moduleName && l.lineText == sl.lineText && l.Operation==sl.Operation)
                {
                    return true;
                }
            }
            return false;
        }
        */


        private void spin(string s)
        {



            Console.WriteLine(s);
            lblLoaded.Text = s;
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

            // Firstly  - lets find all occurences in our current tree
            TreeNode[] callees = treeView1.Nodes.Find(MyCallNode.generateKey(name), true);
            listBox1.Sorted = false;
            listBox1.Items.Clear();
            for (int a = 0; a < callees.Length; a++)
            {
                listBox1.Items.Add( new treeNodeForList( callees[a].Parent));
            }

            if (callees.Length == 0)
            {
                MessageBox.Show("That function does not appear to be directly or indirectly called from 'MAIN'");
            } 


        }


        /// <summary>
        /// invert the tree to see all the callers of a function
        /// </summary>
        /// <param name="selectedNode">node to invert</param>
        private void findModuleLineInTree(string module, int lineno)
        {
            string curr_fname = null;

            int moduleNo=-1;
            int functionNo=-1;

            for (int a = 0; a < curr_program.MODULES.Length; a++)
            {
                if (curr_program.MODULES[a].NAME == module)
                {
                    moduleNo = a;
                    break;
                }
            }


            for (int a = 0; a < curr_program.FUNCTION.Length; a++)
            {
                if (curr_program.FUNCTION[a].MODULENO == moduleNo)
                {
                    if (curr_program.FUNCTION[a].LINE <= lineno && curr_program.FUNCTION[a].LASTLINE >= lineno)
                    {
                        functionNo = a;
                    }
                }
            }

            if (moduleNo == -1)
            {
                MessageBox.Show("Unable to find module");
                return;
            }

            if (functionNo == -1)
            {
                MessageBox.Show("Unable to find Function");
                return;
            }

            MyLocationNode  max = null;
            max = bestNode(treeView1.Nodes, max, moduleNo, functionNo, lineno);


            TreeNode[] callees;
            if (max != null)
            {
                // We've got something inside the function...
                callees = treeView1.Nodes.Find(max.Name, true);
            }
            else
            {
                // Just point to the start of the function...
                callees = treeView1.Nodes.Find(MyCallNode.generateKey(curr_program.FUNCTION[functionNo].NAME), true);
            }
      
            TreeNode baseNode=new TreeNode();
            


            listBox1.Sorted = false;
            listBox1.Items.Clear();
            for (int a = 0; a < callees.Length; a++)
            {
                listBox1.Items.Add(new offsetTreeNodeForList(functionNo, callees[a], lineno, get_line(module, lineno)));
            }
        }




        /// <summary>
        ///  Look for a node in our tree before some arbitrary line number...
        /// </summary>
        /// <param name="treeNodeCollection"></param>
        /// <param name="max"></param>
        /// <param name="moduleNo"></param>
        /// <param name="functionNo"></param>
        /// <param name="lineno"></param>
        /// <returns></returns>
        private MyLocationNode bestNode(TreeNodeCollection treeNodeCollection, MyLocationNode max, int moduleNo,int functionNo, int lineno)
        {

            foreach (TreeNode n in treeNodeCollection)
            {

                if (n.Nodes.Count > 0)
                {
                    max = bestNode(n.Nodes, max, moduleNo, functionNo,lineno);
                    //continue;
                }

                if (n is MyLocationNode)
                {
                    MyLocationNode mnode;
                    mnode = n as MyLocationNode;



                    if (mnode.Module != moduleNo) continue; // Its the wrong module...
                    if (mnode.FunctionNo != functionNo) continue;
                    if (!mnode.LineIsInBlock(functionNo, lineno)) continue;


                    if (max == null)
                    {
                        max = mnode;
                        continue;
                    }

                    // Is 'max' better than what we're trying ? 

                    if (max.LineNumber > mnode.LineNumber)
                    {
                        continue;
                    }


                    max = mnode;
                }
            }
            return max;

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
            loadXMLFile(TreeStyle.TreeStyleMain,null);
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
                    loadModuleLine(f.ModuleNo, f.LineNo,true);
                    actioningUserInteraction = false;
                        return;
                }

                if (listBox1.Items[listBox1.SelectedIndex].GetType() == typeof(offsetTreeNodeForList))
                {
                    offsetTreeNodeForList tnl;
                    tnl = (offsetTreeNodeForList)listBox1.SelectedItem;

                    selectNode(tnl.getNodeForSelection());
                    setModuleLine(tnl.LineNumber);
                   
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

                            if (foundTreeNode.Text.StartsWith("CALLS") || foundTreeNode.Text.StartsWith("OUTPUT TO REPORT") || foundTreeNode.Text.StartsWith("START REPORT") || foundTreeNode.Text.StartsWith("FINISH REPORT"))
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
            EnableLocationButtons();
            lblNoOfLines.Text = "";
            lblListbox.Text = "";
            tsLblSearching.Text = "";
            lblLoaded.Text = "";
            Application.DoEvents();
            textBox1.setContextDialog(null);
            if (loadFile!=null)
            {
                loadXMLFile(TreeStyle.TreeStyleMainRecurse, loadFile);
            }
        }

        private void findFunctionToolStripMenuItem_Click(object sender, EventArgs e)
        {
            tscbFindFunction.SelectedItem = null;
        }



        private void functionToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            int functionNo;
            if (tscbFindFunction.Text == null || tscbFindFunction.Text=="" || tscbFindFunction.Text=="<function>") return;

            functionNo = findFunctionNo( new MyCallNode(tscbFindFunction.Text));

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
                    nodes = treeView1.Nodes.Find(MyCallNode.generateKey(tscbFindFunction.Text), true);

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

            loadXMLFile(TreeStyle.TreeStyleMainRecurse,null);
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
            if (textBox1.FindDialog != null && textBox1.FindDialog.Visible) { } 
            else
            {
                if (!textBox1.Focused)
                {
                    textBox1.Focus();
                }
            }
        }

        private void treeView1_MouseMove(object sender, MouseEventArgs e)
        {
            
            if (!treeView1.Focused)
            {
                if (textBox1.FindDialog != null && textBox1.FindDialog.Visible) { } 
                else
                {
                    treeView1.Focus();
                }
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

            if (srchnode.Text.StartsWith("OUTPUT TO REPORT") || srchnode.Text.StartsWith("START REPORT") || srchnode.Text.StartsWith("FINISH REPORT"))
            {
                List<TreeNode> nodes;
                string ReportName = "<notset>";
                if (srchnode.Text.StartsWith("OUTPUT TO REPORT"))
                {
                    ReportName = srchnode.Text.Substring(17);
                }
                if (srchnode.Text.StartsWith("START REPORT"))
                {
                    ReportName = srchnode.Text.Substring(13);
                }
                if (srchnode.Text.StartsWith("FINISH REPORT"))
                {
                    ReportName = srchnode.Text.Substring(14);
                }
                nodes = (List<TreeNode>)listOfFunctionsCalled[ReportName];

                if (nodes == null)
                {
                    nodes = new List<TreeNode>();
                    listOfFunctionsCalled[ReportName] = nodes;
                }
                nodes.Add(srchnode);
            }

        }

        private void listBox1_MouseMove(object sender, MouseEventArgs e)
        {
            if (textBox1.FindDialog != null && textBox1.FindDialog.Visible) { }
            else
            {
                if (!listBox1.Focused)
                {
                    listBox1.Focus();
                }
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
                        if (curr_program.MODULES[curr_program.FUNCTION[b].MODULENO].LIBRARY == 0)
                        {
                            listBox1.Items.Add(new functionForList(curr_program.FUNCTION[b].NAME, curr_program.FUNCTION[b].MODULENO, curr_program.FUNCTION[b].LINE));
                        }
                        else
                        {
                           // MessageBox.Show("Ignore..");
                        }
                    }
                }
            }
           

        }

        private void treeView1_Click(object sender, EventArgs e)
        {
            if (!loading)
            {
                selectNode(treeView1.SelectedNode);
            }
        }

        private void treeView1_BeforeSelect(object sender, TreeViewCancelEventArgs e)
        {
            if (!loading)
            {
                selectNode(null);
            }
        }

        private void findWordToolStripMenuItem_Click(object sender, EventArgs e)
        {
            
        }


        string remove_subscripts(string s)
        {
            int bracket=0;
            string snew = "";
            for (int a = 0; a < s.Length; a++)
            {
                if (s[a] == '[') { bracket++; continue; }
                if (s[a] == ']') { bracket--; continue; }
                if (bracket == 0) { snew += s[a]; }
            }
            return snew;
        }

        bool name_match(string symbol_name, string srch_name, string type)
        {
            symbol_name = symbol_name.ToLower();
            srch_name = srch_name.ToLower();

            if (symbol_name.EndsWith("."))
            {
                symbol_name = symbol_name.Substring(0, symbol_name.Length - 1);
            }

            if (srch_name.EndsWith("."))
            {
                srch_name = srch_name.Substring(0, srch_name.Length - 1);
            }
            if (type == "VARIABLE")
            {

                


                // Special case for variables to remove any array subscripts and check for records etc..
                symbol_name=remove_subscripts(symbol_name);
                srch_name = remove_subscripts(srch_name);

                symbol_name=symbol_name.Replace(".*","");
                srch_name = srch_name.Replace(".*", "");

                if (symbol_name.Contains("."))
                {
                    // Must be looking for a specific portion of the symbol - eg mv_rec.b
                    if (srch_name.Contains("."))
                    {
                        // Must match completely
                        return srch_name == symbol_name;
                    }
                    else
                    {
                        // Remove the .xxxx from the symbol_name...
                        symbol_name = symbol_name.Substring(0, symbol_name.IndexOf('.') );
                        return symbol_name == srch_name;
                    }
                }
                else
                {
                    if (srch_name.Contains("."))
                    {
                        srch_name = srch_name.Substring(0, srch_name.IndexOf('.') );
                        return srch_name == symbol_name;
                    }
                    else
                    {
                        return srch_name == symbol_name;
                    }
                }               
            }
            return symbol_name == srch_name;
        }




        private void textBox1_searchStarted(string searchTerm)
        {
            for(int a=0;a<tscbFindFunction.Items.Count;a++) {
                string term = (string)tscbFindFunction.Items[a];
                if (term == searchTerm)
                {
                    textBox1.setContextDialog(null);
                    tscbFindFunction.SelectedIndex = a;
                    // Look for functions...
                    for (int ax = 0; ax < curr_program.FUNCTION.Length; ax++)
                    {
                        if (curr_program.FUNCTION[ax].NAME == searchTerm)
                        {

                            SearchableControls.symbolFunction sfunc = new SearchableControls.symbolFunction();

                            // Found it..
                            sfunc.hasDefinition = true;
                            sfunc.symbolName = searchTerm.ToLower();
                            tslSrchText.Text = searchTerm.ToLower() ;

                            SymbolLocation sl=new SymbolLocation(curr_program.FUNCTION[ax].MODULE, curr_program.FUNCTION[ax].LINE, "FUNCTION", "DEFINITION", get_line(curr_program.FUNCTION[ax].MODULE, curr_program.FUNCTION[ax].LINE));
                            if (!sl.InList(sfunc))
                            {
                                sfunc.symbols.Add(sl);
                            }

                            symbolFunction sfunc_calls=getAllFunctionsEntryFor(sfunc.symbolName);
                            
                            sfunc.symbols.AddRange(sfunc_calls.symbols);
                            textBox1.setContextDialog(sfunc);
                            break;
                        }
                    }
                    return;
                }
            //tscbFindFunction.Items
            }


            setCurrentFunction(textBox1.currentLineNo);
            
            // Not in the functions - maybe its a symbol or variable..
            SearchableControls.baseSymbolType type=null;
            SearchableControls.symbolCursor sc = new SearchableControls.symbolCursor();
            SearchableControls.symbolVariable sv = new SearchableControls.symbolVariable();
            sv.possibleValue = null;
            SearchableControls.symbolForm sf = new SearchableControls.symbolForm();
            SearchableControls.symbolStatement ss = new SearchableControls.symbolStatement();
            SearchableControls.symbolWindow sw = new SearchableControls.symbolWindow();

            if (searchTerm == null) return;

            searchTerm = searchTerm.Trim();
            if (searchTerm == "") return;

            /*
            if (searchTerm.Contains("["))
            {
                searchTerm = searchTerm.Substring(0, searchTerm.IndexOf("[")-1);
            }

            if (searchTerm.Contains("."))
            {
                searchTerm = searchTerm.Substring(0, searchTerm.IndexOf(".") - 1);
            }
             * */
            tslSrchText.Text = searchTerm.ToLower();


            for (int a = 0; a < curr_program.SYMBOLS.Length; a++)
            {
                if (name_match(curr_program.SYMBOLS[a].NAME.ToLower(), searchTerm.ToLower(), curr_program.SYMBOLS[a].TYPE))
                {
                    SymbolLocation sl;

                    if (!canBeCalled(curr_program.SYMBOLS[a].MODULE, curr_program.SYMBOLS[a].LINE))
                    {
                        continue;
                    }

                    if (inScope(curr_program.SYMBOLS[a].SCOPE, curr_program.SYMBOLS[a].MODULE, curr_program.SYMBOLS[a].LINE))
                    {

                        switch (curr_program.SYMBOLS[a].TYPE)
                        {
                            case "CURSOR":
                                sc.symbolName = searchTerm.ToLower();
                                type = sc;
                                sl = new SymbolLocation(curr_program.SYMBOLS[a].MODULE, curr_program.SYMBOLS[a].LINE, curr_program.SYMBOLS[a].TYPE, curr_program.SYMBOLS[a].OPERATION, get_line(curr_program.SYMBOLS[a].MODULE, curr_program.SYMBOLS[a].LINE));

                                if (!sl.InList(type))
                                {
                                    type.symbols.Add(sl);

                                }
                                switch (curr_program.SYMBOLS[a].OPERATION)
                                {
                                    case "DECLARE": sc.hasDeclare = true; break;
                                    case "CLOSE": sc.hasClose = true; break;
                                    case "FETCH": sc.hasFetch = true; break;
                                    case "OPEN": sc.hasOpen = true; break;
                                }
                                break;

                            case "VARIABLE":
                                {
                                    sv.symbolName = searchTerm.ToLower();
                                    type = sv;
                                    int line = curr_program.SYMBOLS[a].LINE;
                                    
                                    sl = new SymbolLocation(curr_program.SYMBOLS[a].MODULE, line, curr_program.SYMBOLS[a].TYPE, curr_program.SYMBOLS[a].OPERATION, get_line(curr_program.SYMBOLS[a].MODULE, line));
                                    if (!sl.InList(type))
                                    {
                                        type.symbols.Add(sl);
                                    }

                                    switch (curr_program.SYMBOLS[a].OPERATION)
                                    {
                                        case "ASSIGN": sv.hasAssign = true; 
                                           if (textBox1.currentLineNo == line && curr_program.MODULES[currentModuleNo].NAME == curr_program.SYMBOLS[a].MODULE)
                                            {
                                                sv.possibleValue = curr_program.SYMBOLS[a].VALUE;
                                            }
                                            
                                            break;
                                        case "USE": sv.hasRead = true;
                                            if (textBox1.currentLineNo == line && curr_program.MODULES[currentModuleNo].NAME == curr_program.SYMBOLS[a].MODULE)
                                            {
                                                sv.possibleValue = curr_program.SYMBOLS[a].VALUE;
                                            }
                                            break;
                                    }
                                }
                                break;

                            case "WINDOW":
                                sw.symbolName = searchTerm.ToLower();
                                type = sw;
                                sl = new SymbolLocation(curr_program.SYMBOLS[a].MODULE, curr_program.SYMBOLS[a].LINE, curr_program.SYMBOLS[a].TYPE, curr_program.SYMBOLS[a].OPERATION, get_line(curr_program.SYMBOLS[a].MODULE, curr_program.SYMBOLS[a].LINE));
                                if (!sl.InList(type))
                                {
                                    type.symbols.Add(sl);
                                }
                                switch (curr_program.SYMBOLS[a].OPERATION)
                                {
                                    case "CLOSE": sw.hasClose = true; break;
                                    case "HIDE": sw.hasHide = true; break;
                                    case "MOVE": sw.hasMove = true; break;
                                    case "OPEN": sw.hasOpen = true; break;
                                    case "SHOW": sw.hasShow = true; break;
                                }
                                break;

                            case "FORM":
                                sf.symbolName = searchTerm.ToLower();
                                type = sf;
                                sl = new SymbolLocation(curr_program.SYMBOLS[a].MODULE, curr_program.SYMBOLS[a].LINE, curr_program.SYMBOLS[a].TYPE, curr_program.SYMBOLS[a].OPERATION, get_line(curr_program.SYMBOLS[a].MODULE, curr_program.SYMBOLS[a].LINE));
                                if (!sl.InList(type))
                                {
                                    type.symbols.Add(sl);
                                }
                                switch (curr_program.SYMBOLS[a].OPERATION)
                                {
                                    case "CLOSE": sf.hasClose = true; break;
                                    case "DISPLAY": sf.hasDisplay = true; break;
                                    case "OPEN": sf.hasOpen = true; break;
                                }
                                break;

                            case "STMT":
                                if (curr_program.SYMBOLS[a].OPERATION == "CLOSE") break;
                                ss.symbolName = searchTerm.ToLower();
                                type = ss;
                                sl = new SymbolLocation(curr_program.SYMBOLS[a].MODULE, curr_program.SYMBOLS[a].LINE, curr_program.SYMBOLS[a].TYPE, curr_program.SYMBOLS[a].OPERATION, get_line(curr_program.SYMBOLS[a].MODULE, curr_program.SYMBOLS[a].LINE));
                                if (!sl.InList(type))
                                {
                                    type.symbols.Add(sl);
                                }
                                switch (curr_program.SYMBOLS[a].OPERATION)
                                {
                                    case "PREPARE": ss.hasPrepare = true;
                                        ss.likelySQL = find_sql(curr_program, ss.symbolName, curr_program.SYMBOLS[a].LINE);
                                            break;
                                    case "DECLARE": ss.hasDeclare = true; break;
                                    case "EXECUTE": ss.hasExecute = true; break;
                                }

                                break;
                        }

                    }
                }
            }




            #region Look for variables...
            if (type == null || type==sv)
            {

                bool processed = false;
                if (current_local_variables != null)
                {
                    // Maybe we're on a DEFINE ? 
                    for (int a = 0; a < current_local_variables.Count; a++)
                    {
                        if (name_match(current_local_variables[a].NAME,searchTerm,"VARIABLE"))
                        {
                            processed = true;
                            type = sv;
                            type.symbolName = searchTerm.ToLower();

                            sv.hasDefine = true;
                            SymbolLocation sl = new SymbolLocation(current_local_variables[a].MODULE, current_local_variables[a].LINE, current_local_variables[a].TYPE, current_local_variables[a].OPERATION, get_line(current_local_variables[a].MODULE, current_local_variables[a].LINE));
                            if (!sl.InList(type))
                            {
                                type.symbols.Add(sl);
                            }
                            break;
                        }
                    }
                }


                if (!processed)
                {
                    for (int a = 0; a < current_module_variables.Count; a++)
                    {
                        if (name_match(current_module_variables[a].NAME, searchTerm,"VARIABLE"))
                        {
                            processed = true;
                            type = sv;
                            type.symbolName = searchTerm.ToLower();

                            sv.hasDefine = true;
                            SymbolLocation sl = new SymbolLocation(current_module_variables[a].MODULE, current_module_variables[a].LINE, current_module_variables[a].TYPE, current_module_variables[a].OPERATION, get_line(current_module_variables[a].MODULE, current_module_variables[a].LINE));
                            if (!sl.InList(type))
                            {
                                type.symbols.Add(sl);
                            }
                                break;
                        }
                    }
                }

                if (!processed)
                {
                    for (int a = 0; a < current_global_variables.Count; a++)
                    {
                        if (name_match(current_global_variables[a].NAME,searchTerm,"VARIABLE"))
                        {
                            processed = true;
                            type = sv;
                            type.symbolName = searchTerm.ToLower();
                            sv.hasDefine = true;
                            SymbolLocation sl = new SymbolLocation(current_global_variables[a].MODULE, current_global_variables[a].LINE, current_global_variables[a].TYPE, current_global_variables[a].OPERATION, get_line(current_global_variables[a].MODULE, current_global_variables[a].LINE));
                            if (!sl.InList(type))
                            {
                                type.symbols.Add(sl);
                            }
                            break;
                        }
                    }
                }



            }
            #endregion

            


            if (type != null)
            {
                textBox1.setContextDialog(type);
            }
            else
            {
                textBox1.setContextDialog(null);
            }
        }

        private string find_sql(AubitCalltreeViewer.PROGRAM curr_program, string p,int lineno)
        {
            string sql="???";
            for (int a = 0; a < curr_program.DYNAMICSQLS.Length; a++)
            {
                if (p == curr_program.DYNAMICSQLS[a].STMTID && curr_program.DYNAMICSQLS[a].LINE<=lineno)
                {
                    sql=curr_program.DYNAMICSQLS[a].STMT;                   
                }
            }
            return sql;
        }

        private string get_line(string module, int line)
        {
            for (int a = 0; a < curr_program.MODULES.Length; a++)
            {
                if (curr_program.MODULES[a].NAME == module)
                {
                    string s = curr_program.MODULES[a].LINE[line-1].Text;
                    if (s != null) return s.Trim();
                    return "";
                    
                }
            }
            return "";
        }

        private void setCurrentFunction(int p)
        {
           


            current_local_variables = new List<AubitCalltreeViewer.SYMBOL>();

            for (int a = 0; a < curr_program.FUNCTION.Length; a++)
            {
                if (curr_program.FUNCTION[a].MODULE == curr_program.MODULES[currentModuleNo].NAME)
                {

                    if (curr_program.FUNCTION[a].LINE <= p && p<=curr_program.FUNCTION[a].LASTLINE)
                    {
                        AubitCalltreeViewer.FUNCTION f = null;                    
                        currentFunctionStart = curr_program.FUNCTION[a].LINE;
                        currentFunctionEnd = curr_program.FUNCTION[a].LASTLINE;
                        f = curr_program.FUNCTION[a];
                       
                        if (f.LOCAL_VARIABLES != null)
                        {
                            appendVariables(current_local_variables, curr_program.MODULES[currentModuleNo].NAME, f.LOCAL_VARIABLES);
                        }
                        return;
              
                    }
                    
                }
            }


        }

        private bool inScope(string scope, string module, int line)
        {
            if (scope == "G" || scope=="-") return true;

            if (currentModuleNo>=0) {
                if (scope == "M" && curr_program.MODULES[currentModuleNo].NAME == module) return true;

                if (scope == "L" && curr_program.MODULES[currentModuleNo].NAME == module) 
                {
                    if (line >= currentFunctionStart && line <= currentFunctionEnd)
                    {
                        return true;
                    }
                }
            }
            return false;
        }

        private void textBox1_DoubleClick(object sender, EventArgs e)
        {
            if (textBox1.SelectedText != null)
            {
                textBox1_searchStarted(textBox1.SelectedText);
            }
        }

        private void textBox1_clickContext(object sender, EventArgs e)
        {
            SearchableControls.ContextSearchItem c;
            if (sender is SearchableControls.ContextSearchItem)
            {
                c = (SearchableControls.ContextSearchItem)sender;


                loadModuleLine(c.sl.moduleName, c.sl.lineNo,true); 
            }
        }



        private void textBox1_searchForFunctionCall()
        {
            if (tscbFindFunction.Text != null)
            {
                invertTree(tscbFindFunction.Text);
            }
        }

        private void MainCalltreeWindow_DragDrop(object sender, DragEventArgs e)
        {

            // Handle FileDrop data.
            if (e.Data.GetDataPresent(DataFormats.FileDrop))
            {
                // Assign the file names to a string array, in 
                // case the user has selected multiple files.
                string[] files = (string[])e.Data.GetData(DataFormats.FileDrop);
                try
                {

                    loadXMLFile(TreeStyle.TreeStyleMainRecurse, files[0]);
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message);
                    return;
                }
            }

        }

        private void MainCalltreeWindow_DragEnter(object sender, DragEventArgs e)
        {
            if (e.Data.GetDataPresent(DataFormats.FileDrop))
            {
                e.Effect = DragDropEffects.Copy;
            }
        }





        /// <summary>
        /// CRUD handling...
        /// </summary>
        private void setCRUD() {
            List<string> Tables;
            List<SymbolLocation> sl;
            // Generate the menu options for the UPDATE statements...
            #region find updates
            Tables =new List<string>();
            sl = new List<SymbolLocation>();

            if (curr_program.UPDATES != null)
            {
                for (int a = 0; a < curr_program.UPDATES.Length; a++)
                {
                    if (!Tables.Contains(curr_program.UPDATES[a].TABLE))
                    {
                        Tables.Add(curr_program.UPDATES[a].TABLE);
                    }

                    sl.Add(new SymbolLocation(curr_program.UPDATES[a].MODULE, curr_program.UPDATES[a].LINE, "UPDATE", curr_program.UPDATES[a].TABLE, get_line(curr_program.UPDATES[a].MODULE, curr_program.UPDATES[a].LINE)));
                }
            }

            if (curr_program.DYNAMICSQLS != null)
            {
                for (int a = 0; a < curr_program.DYNAMICSQLS.Length; a++)
                {
                    if (curr_program.DYNAMICSQLS[a].PROCESSED ==1) continue;

                    string[] tabnames = extractTables("UPDATE", curr_program.DYNAMICSQLS[a].STMT);
                    if (tabnames != null)
                    {
                        curr_program.DYNAMICSQLS[a].PROCESSED = 1;
                        for (int b = 0; b < tabnames.Length; b++)
                        {

                            if (!Tables.Contains(tabnames[b]))
                            {
                                Tables.Add(tabnames[b]);
                            }

                            sl.Add(new SymbolLocation(curr_program.DYNAMICSQLS[a].MODULE, curr_program.DYNAMICSQLS[a].LINE, "UPDATE", tabnames[b], get_line(curr_program.DYNAMICSQLS[a].MODULE, curr_program.DYNAMICSQLS[a].LINE)));
                        }
                    }
                }
            }

            setMenuItems(updatesToolStripMenuItem, Tables,sl );
#endregion
            #region inserts
            Tables = new List<string>();
            sl = new List<SymbolLocation>();
            if (curr_program.INSERTS != null)
            {
                for (int a = 0; a < curr_program.INSERTS.Length; a++)
                {
                    if (!Tables.Contains(curr_program.INSERTS[a].TABLE))
                    {
                        Tables.Add(curr_program.INSERTS[a].TABLE);
                    }

                    sl.Add(new SymbolLocation(curr_program.INSERTS[a].MODULE, curr_program.INSERTS[a].LINE, "INSERTS", curr_program.INSERTS[a].TABLE, get_line(curr_program.INSERTS[a].MODULE, curr_program.INSERTS[a].LINE)));
                }
            }

            if (curr_program.DYNAMICSQLS != null)
            {
                for (int a = 0; a < curr_program.DYNAMICSQLS.Length; a++)
                {
                    if (curr_program.DYNAMICSQLS[a].PROCESSED == 1) continue;
                    string[] tabnames = extractTables("INSERT", curr_program.DYNAMICSQLS[a].STMT);
                    if (tabnames != null)
                    {
                        curr_program.DYNAMICSQLS[a].PROCESSED = 1;
                        for (int b = 0; b < tabnames.Length; b++)
                        {

                            if (!Tables.Contains(tabnames[b]))
                            {
                                Tables.Add(tabnames[b]);
                            }

                            sl.Add(new SymbolLocation(curr_program.DYNAMICSQLS[a].MODULE, curr_program.DYNAMICSQLS[a].LINE, "INSERT", tabnames[b], get_line(curr_program.DYNAMICSQLS[a].MODULE, curr_program.DYNAMICSQLS[a].LINE)));
                        }
                    }
                }
            }

            setMenuItems(insertToolStripMenuItem, Tables, sl);
            #endregion
            #region deletes
            Tables = new List<string>();
            sl = new List<SymbolLocation>();
            if (curr_program.DELETES != null)
            {
                for (int a = 0; a < curr_program.DELETES.Length; a++)
                {
                    if (!Tables.Contains(curr_program.DELETES[a].TABLE))
                    {
                        Tables.Add(curr_program.DELETES[a].TABLE);
                    }

                    sl.Add(new SymbolLocation(curr_program.DELETES[a].MODULE, curr_program.DELETES[a].LINE, "DELETES", curr_program.DELETES[a].TABLE, get_line(curr_program.DELETES[a].MODULE, curr_program.DELETES[a].LINE)));
                }
            }

            if (curr_program.DYNAMICSQLS != null)
            {
                for (int a = 0; a < curr_program.DYNAMICSQLS.Length; a++)
                {
                    if (curr_program.DYNAMICSQLS[a].PROCESSED == 1) continue;
                    string[] tabnames = extractTables("DELETE", curr_program.DYNAMICSQLS[a].STMT);
                    if (tabnames != null)
                    {
                        curr_program.DYNAMICSQLS[a].PROCESSED = 1;
                        for (int b = 0; b < tabnames.Length; b++)
                        {

                            if (!Tables.Contains(tabnames[b]))
                            {
                                Tables.Add(tabnames[b]);
                            }

                            sl.Add(new SymbolLocation(curr_program.DYNAMICSQLS[a].MODULE, curr_program.DYNAMICSQLS[a].LINE, "DELETE", tabnames[b], get_line(curr_program.DYNAMICSQLS[a].MODULE, curr_program.DYNAMICSQLS[a].LINE)));
                        }
                    }
                }
            }

            setMenuItems(deleteToolStripMenuItem, Tables, sl);
            #endregion


            #region selects
            Tables = new List<string>();
            sl = new List<SymbolLocation>();
            if (curr_program.SELECTS != null)
            {
                for (int a = 0; a < curr_program.SELECTS.Length; a++)
                {
                    if (!Tables.Contains(curr_program.SELECTS[a].TABLE))
                    {
                        Tables.Add(curr_program.SELECTS[a].TABLE);
                    }

                    sl.Add(new SymbolLocation(curr_program.SELECTS[a].MODULE, curr_program.SELECTS[a].LINE, "SELECT", curr_program.SELECTS[a].TABLE, get_line(curr_program.SELECTS[a].MODULE, curr_program.SELECTS[a].LINE)));
                }
            }

            if (curr_program.DYNAMICSQLS != null)
            {
                for (int a = 0; a < curr_program.DYNAMICSQLS.Length; a++)
                {
                    if (curr_program.DYNAMICSQLS[a].PROCESSED == 1) continue;
                    string[] tabnames = extractTables("SELECT", curr_program.DYNAMICSQLS[a].STMT);
                    
                    if (tabnames != null)
                    {
                        curr_program.DYNAMICSQLS[a].PROCESSED = 1;
                        for (int b = 0; b < tabnames.Length; b++)
                        {

                            if (!Tables.Contains(tabnames[b]))
                            {
                                Tables.Add(tabnames[b]);
                            }

                            sl.Add(new SymbolLocation(curr_program.DYNAMICSQLS[a].MODULE, curr_program.DYNAMICSQLS[a].LINE, "SELECT", tabnames[b], get_line(curr_program.DYNAMICSQLS[a].MODULE, curr_program.DYNAMICSQLS[a].LINE)));
                        }
                    }
                }
            }

            setMenuItems(selectToolStripMenuItem, Tables, sl);
            #endregion

            #region EXECUTE
            Tables = new List<string>();
            sl = new List<SymbolLocation>();

            if (curr_program.OTHERSQLS != null)
            {
                for (int a = 0; a < curr_program.OTHERSQLS.Length; a++)
                {
                    string[] tabnames = extractTables("EXECUTE", curr_program.OTHERSQLS[a].STMT);
                    if (tabnames != null)
                    {
                        curr_program.DYNAMICSQLS[a].PROCESSED = 1;
                        for (int b = 0; b < tabnames.Length; b++)
                        {

                            if (!Tables.Contains(tabnames[b]))
                            {
                                Tables.Add(tabnames[b]);
                            }

                            sl.Add(new SymbolLocation(curr_program.DYNAMICSQLS[a].MODULE, curr_program.DYNAMICSQLS[a].LINE, "EXECUTE", tabnames[b], get_line(curr_program.DYNAMICSQLS[a].MODULE, curr_program.DYNAMICSQLS[a].LINE)));
                        }
                    }
                }
            }


            if (curr_program.DYNAMICSQLS != null)
            {
                for (int a = 0; a < curr_program.DYNAMICSQLS.Length; a++)
                {
                    string[] tabnames = extractTables("EXECUTE", curr_program.DYNAMICSQLS[a].STMT);
                    if (tabnames != null)
                    {
                        for (int b = 0; b < tabnames.Length; b++)
                        {
                            curr_program.DYNAMICSQLS[a].PROCESSED = 1;
                            if (!Tables.Contains(tabnames[b]))
                            {
                                Tables.Add(tabnames[b]);
                            }

                            sl.Add(new SymbolLocation(curr_program.DYNAMICSQLS[a].MODULE, curr_program.DYNAMICSQLS[a].LINE, "EXECUTE", tabnames[b], get_line(curr_program.DYNAMICSQLS[a].MODULE, curr_program.DYNAMICSQLS[a].LINE)));
                        }
                    }
                }
            }

            setMenuItems(eXECUTEPROCEDUREToolStripMenuItem, Tables, sl);
            #endregion
            #region Environment variables
            Tables = new List<string>();
            sl = new List<SymbolLocation>();
            if (curr_program.ENVIRONMENTVARS != null)
            {
                for (int a = 0; a < curr_program.ENVIRONMENTVARS.Length; a++)
                {
                    if (!Tables.Contains(curr_program.ENVIRONMENTVARS[a].NAME))
                    {
                        Tables.Add(curr_program.ENVIRONMENTVARS[a].NAME);
                    }

                    sl.Add(new SymbolLocation(curr_program.ENVIRONMENTVARS[a].MODULE, curr_program.ENVIRONMENTVARS[a].LINE, "ENV", curr_program.ENVIRONMENTVARS[a].NAME, get_line(curr_program.ENVIRONMENTVARS[a].MODULE, curr_program.ENVIRONMENTVARS[a].LINE)));
                }
            }

            setMenuItems(environmentVariablesToolStripMenuItem, Tables, sl);
            #endregion

            #region RUN statements
            Tables = new List<string>();
            sl = new List<SymbolLocation>();
            if (curr_program.RUN != null)
            {

                for (int a = 0; a < curr_program.RUN.Length; a++)
                {
                    if (!Tables.Contains(curr_program.RUN[a].CMD))
                    {
                        Tables.Add(curr_program.RUN[a].CMD);
                    }

                    sl.Add(new SymbolLocation(curr_program.RUN[a].MODULE, curr_program.RUN[a].LINE, "RUN",  curr_program.RUN[a].CMD, get_line(curr_program.RUN[a].MODULE, curr_program.RUN[a].LINE)));
                }
            }
            setMenuItems(RunsToolStripMenuItem, Tables, sl);
            #endregion

            #region Dynamic SQL statements
            Tables = new List<string>();
            sl = new List<SymbolLocation>();
            if (curr_program.DYNAMICSQLS != null)
            {
                for (int a = 0; a < curr_program.DYNAMICSQLS.Length; a++) {
                    if (curr_program.DYNAMICSQLS[a].PROCESSED == 1) continue;

                    if (!Tables.Contains(curr_program.DYNAMICSQLS[a].STMTID))
                    {
                        Tables.Add(curr_program.DYNAMICSQLS[a].STMTID);
                    }

                    sl.Add(new SymbolLocation(curr_program.DYNAMICSQLS[a].MODULE, curr_program.DYNAMICSQLS[a].LINE, "DYNAMIC", curr_program.DYNAMICSQLS[a].STMTID, get_line(curr_program.DYNAMICSQLS[a].MODULE, curr_program.DYNAMICSQLS[a].LINE)));
                }
            }
            setMenuItems(unparsedDynamicSQLToolStripMenuItem, Tables, sl);
            #endregion

            #region FORM statements
            Tables = new List<string>();
            sl = new List<SymbolLocation>();
            if (curr_program.FORMS != null)
            {

                for (int a = 0; a < curr_program.FORMS.Length; a++)
                {
                    if (!Tables.Contains(curr_program.FORMS[a].SOURCE))
                    {
                        Tables.Add(curr_program.FORMS[a].SOURCE);
                    }


                        sl.Add(
                            new SymbolLocation(
                                    curr_program.FORMS[a].MODULE,
                                    curr_program.FORMS[a].LINE,
                                    "FORM",
                                    curr_program.FORMS[a].SOURCE,
                                    get_line(curr_program.FORMS[a].MODULE, curr_program.FORMS[a].LINE),
                                    curr_program.FORMS[a].Text
                            ));

                }
            }

            setMenuItems(formsToolStripMenuItem, Tables, sl);
            #endregion
            #region FILES usages...
            Tables = new List<string>();
            sl = new List<SymbolLocation>();
            if (curr_program.FILES != null)
            {

                for (int a = 0; a < curr_program.FILES.Length; a++)
                {
                    if (!Tables.Contains(curr_program.FILES[a].FILENAME))
                    {
                        Tables.Add(curr_program.FILES[a].FILENAME);
                    }


                    sl.Add(
                        new SymbolLocation(
                                curr_program.FILES[a].MODULE,
                                curr_program.FILES[a].LINE,
                                "FILE",
                                curr_program.FILES[a].FILENAME,
                                get_line(curr_program.FILES[a].MODULE, curr_program.FILES[a].LINE)
                                
                                    // , curr_program.FILES[a].OPERATION
                        ));

                }
            }

            setMenuItems(filesToolStripMenuItem, Tables, sl);
            #endregion


        }


        /// <summary>
        /// Try to determine the tables involved in an SQL statement..
        /// </summary>
        /// <param name="operation">Type of statement we're looking for...</param>
        /// <param name="sqlStatement"></param>
        /// <returns></returns>
        private string[] extractTables(string operation, string sqlStatement)
        {
            sqlStatement = sqlStatement.ToLower();

            try
            {
                switch (operation)
                {
                    case "UPDATE":
                        if (!sqlStatement.Contains("update ")) return null;
                        if (sqlStatement.IndexOf(" set ") == -1) return null;

                        sqlStatement = sqlStatement.Remove(sqlStatement.IndexOf(" set ")).Replace("update", "");
                        break;

                    case "DELETE":
                        if (!sqlStatement.Contains("delete ")) return null;
                        if (sqlStatement.IndexOf(" from ") == -1) return null;
                        sqlStatement = sqlStatement.Remove(sqlStatement.IndexOf("where")).Replace("delete", "").Replace("from", "");
                        break;

                    case "INSERT":
                        if (!sqlStatement.Contains("insert ")) return null;
                        if (sqlStatement.IndexOf(" into ") == -1) return null;
                        if (sqlStatement.IndexOf("select ") >= 0)
                        {
                            sqlStatement = sqlStatement.Remove(sqlStatement.IndexOf("select")).Replace("insert", "").Replace("values", "").Replace("into", "");
                        }


                        if (sqlStatement.IndexOf("(")>=0)
                        {
                            
                            sqlStatement = sqlStatement.Remove(sqlStatement.IndexOf("(")).Replace("insert", "").Replace("values", "").Replace("into", "");

                        }
                        break;


                    case "EXECUTE":
                        if (!sqlStatement.Contains("execute ")) return null;
                        if (sqlStatement.IndexOf("(") == -1) return null;
                        sqlStatement = sqlStatement.Remove(sqlStatement.IndexOf("(")).Replace("execute", "").Replace("procedure", "");
                        break;

                    case "SELECT":
                        if (!sqlStatement.Contains("select ")) return null;
                        if (sqlStatement.IndexOf(" where ") > 0)
                        {
                            sqlStatement = sqlStatement.Remove(sqlStatement.IndexOf(" where "));
                        }
                        if (sqlStatement.IndexOf(" order ") > 0)
                        {
                            sqlStatement = sqlStatement.Remove(sqlStatement.IndexOf(" order "));
                        }
                        if (sqlStatement.IndexOf(" group ") > 0)
                        {
                            sqlStatement = sqlStatement.Remove(sqlStatement.IndexOf(" group "));
                        }
                        if (sqlStatement.IndexOf(" having ") > 0)
                        {
                            sqlStatement = sqlStatement.Remove(sqlStatement.IndexOf(" having "));
                        }

                        if (sqlStatement.IndexOf(" from ") > 0)
                        {
                            sqlStatement = sqlStatement.Substring(sqlStatement.IndexOf(" from ") + 5);
                        }
                        else
                        {
                            return null;
                        }
                        break;

                    default:
                        throw new ApplicationException("Not implemented");
                }
            }
            catch (Exception Ex)
            {
                MessageBox.Show(Ex.Message);
            }

           sqlStatement= sqlStatement.Replace(",", " ");
           sqlStatement = sqlStatement.Replace("[", " ");
           sqlStatement = sqlStatement.Replace("]", " ");
            // If we get to gere - sqlStatement should just be a list of tabnames with the option of a possible "outer" for a select..

            string[] tabnames = sqlStatement.Split(' ');
            List<string> tnames;
            tnames=new List<string>();
            for (int a = 0; a < tabnames.Length; a++)
            {
                if (tabnames[a] == "outer") continue;
                if (tabnames[a].Trim() == "") continue;
                tnames.Add(tabnames[a]);
               
            }
            if (tnames.Count > 0)
            {
                return tnames.ToArray();
            }


            return null;
        }

        private void setMenuItems(ToolStripMenuItem tsMain, List<string> Tables, List<SymbolLocation> sl)
        {
            tsMain.DropDownItems.Clear();
            if (Tables != null)
            {
                Tables.Sort();
                for (int a = 0; a < Tables.Count; a++)
                {
                    ToolStripMenuItem ts;
                    ts = new ToolStripMenuItem(Tables[a]);
                    tsMain.DropDownItems.Add(ts);
                    for (int b = 0; b < sl.Count; b++)
                    {
                        if (sl[b].Operation == Tables[a] && canBeCalled(sl[b].moduleName, sl[b].lineNo))
                        {
                            ContextSearchItem csi = new ContextSearchItem(sl[b]);
                            csi.WhenClicked = new EventHandler(csi_Click);
                            ts.DropDownItems.Add(csi);
/*
                            if (sl[b].Description != null)
                            {
                                ToolStripMenuItem ts2;
                                ts2 = new ToolStripMenuItem(sl[b].Description);
                                ts.DropDownItems.Add(ts2);
                            }
 * */
                        }
                    }
                    if (ts.DropDownItems.Count == 0)
                    {
                        ts.Visible = false;
                    }
                }
            }
            else
            {
                for (int b = 0; b < sl.Count; b++)
                {
                    if (canBeCalled(sl[b].moduleName, sl[b].lineNo))
                    {
                        ContextSearchItem csi = new ContextSearchItem(sl[b]);
                        csi.WhenClicked = new EventHandler(csi_Click);
                        tsMain.DropDownItems.Add(csi);

                       // ToolStripMenuItem ts1;
                       // ts1=new ToolStripMenuItem(sl
                    }
                }

            }

            if (tsMain.DropDownItems.Count == 0)
            {
                tsMain.Visible = false;
            }
            else
            {
                tsMain.Visible = true;
            }
        }

        private bool canBeCalled(string moduleName, int lineNo)
        {


            for (int a = 0; a < curr_program.FUNCTION.Length; a++)
            {
                if (curr_program.FUNCTION[a].MODULE == moduleName)
                {

                    if (curr_program.FUNCTION[a].LINE <= lineNo && lineNo <= curr_program.FUNCTION[a].LASTLINE)
                    {
                        return curr_program.FUNCTION[a].CALLED;
                    }
                }
            }

            return false;
         //   throw new NotImplementedException();
        }



        void csi_Click(object sender, EventArgs e)
        {
            SearchableControls.ContextSearchItem c = (SearchableControls.ContextSearchItem)sender;

            loadModuleLine(c.sl.moduleName, c.sl.lineNo,true);

        }



        private void mnLocationBack_Click(object sender, EventArgs e)
        {

            previousLocationIndicator--;
            loadModuleLine(previousLocations[previousLocationIndicator].ModuleNo, previousLocations[previousLocationIndicator].LineNo, false);
            EnableLocationButtons();

        }

        private void EnableLocationButtons()
        {

           // mnLocationBack.Text="< "+(previousLocationIndicator+1)+" of "+previousLocations.Count;
            if (previousLocations.Count > (previousLocationIndicator+1))
            {
                mnLocationForward.Enabled = true;
            }
            else
            {
                mnLocationForward.Enabled = false;
            }

            if (previousLocationIndicator > 0)
            {
                mnLocationBack.Enabled = true;
            }
            else
            {
                mnLocationBack.Enabled = false;
            }
            
        }

        private void mnLocationForward_Click(object sender, EventArgs e)
        {
            previousLocationIndicator++;
            loadModuleLine(previousLocations[previousLocationIndicator].ModuleNo, previousLocations[previousLocationIndicator].LineNo, false);
            
            EnableLocationButtons();
        }

        private void test1ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            findModuleLineInTree("hsRFcomT06", 1966);
        }

        private void textBox1_searchRelated(int lineno)
        {
            findModuleLineInTree(curr_program.MODULES[currentModuleNo].NAME, lineno);
        }

        private void textBox1_MouseUp(object sender, MouseEventArgs e)
        {

    if (e.Button == MouseButtons.Right)
    {
        int charpos;
        SearchableTextBox box = (SearchableTextBox)sender;
        charpos= box.GetCharIndexFromPosition(e.Location);
        if (charpos < box.SelectionStart || charpos > box.SelectionStart + box.SelectionLength)
        {
            box.SelectionStart = charpos;
            box.SelectionLength = 0;
        }
    }

        }


    }
}