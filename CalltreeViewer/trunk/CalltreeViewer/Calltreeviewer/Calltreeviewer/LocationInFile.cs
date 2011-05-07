using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Forms;

namespace Calltreeviewer
{

    class moduleForList
    {
        int _moduleno;
        string _fullName;
        string _name;

        public int moduleNo
        {
            get
            {
                return _moduleno;
            }
        }

        public string fullName
        {
            get
            {
                return _fullName;
            }
        }
        public string name
        {
            get
            {
                return _name;
            }
        }

        public moduleForList(int moduleNo,string name,string fullName)
        {
            _moduleno = moduleNo;
            _name = name;
            _fullName = fullName;
        }

        public override string ToString()
        {
            return _name;

        }
    }




    class offsetTreeNodeForList : treeNodeForList
    {
        private int _lineNumber;

        public int LineNumber
        {
            get { return _lineNumber; }
            set { _lineNumber = value; }
        }
        private bool lastIsSuggestion = false;
        private string _lineText;
        private int _functionNo;

        public offsetTreeNodeForList(int functionNo, System.Windows.Forms.TreeNode node, int actualLineNumber, string lineText) : base(node)
        {
            _lineNumber = actualLineNumber;
            _lineText = lineText;
            _functionNo = functionNo;

            if (t is MyLocationNode)
            {
                MyLocationNode mln = t as MyLocationNode;
                if (mln.LineNumber == actualLineNumber)
                {
                    // Yeah - its an exact match! 
                }
                else
                {
                    lastIsSuggestion = true;
                }
            }
        }


        public override string ToString()
        {
            string path;

            if (t == null) return "";
            try
            {
                if (!lastIsSuggestion)
                {
                    path = t.FullPath;
                    path = path.Replace("\\", "-->");
                }
                else
                {
                    if (t is MyLocationNode)
                    {
                        MyLocationNode mln = t as MyLocationNode;
                        
                        if (mln.LineIsInBlock(_functionNo, LineNumber)) {
                            // We in the last command...
                            path = t.FullPath;
                            path = path.Replace("\\", "-->");
                        }
                        else
                        {
                            // We're after the last command
                            path = t.FullPath;
                            path = path.Replace("\\", "-->");
                            // We now need to remove the last portion and replace it with our own line..
                            int l = path.LastIndexOf("-->");
                            path = path.Substring(0, l + 3);
                            path += _lineText;
                        }
                    }
                    else
                    {
                        path = t.FullPath;
                        path = path.Replace("\\", "-->");
                        // We now need to remove the last portion and replace it with our own line..
                        int l = path.LastIndexOf("-->");
                        path = path.Substring(0, l + 3);
                        path += _lineText;
                    }
                }
                return path;
            }
            catch (Exception e)
            {
                return "";
            }
        }
    }


    class treeNodeForList
    {
        internal System.Windows.Forms.TreeNode t;

        public treeNodeForList(System.Windows.Forms.TreeNode node)
        {
            t = node;
        }

            


        public System.Windows.Forms.TreeNode getNodeForSelection()
        {


            return t;


            if (t.Text.StartsWith("CALLS") || t.Text.StartsWith("OUTPUT TO REPORT") || t.Text.StartsWith("START REPORT") || t.Text.StartsWith("FINISH REPORT"))
            {
                return t;
            }
            else
            {
                return t.Parent;
            }
           
        }


        public override string ToString()
        {
            //string oldPathSep;
            string path;
            //oldPathSep=t.TreeView.PathSeparator;
            //t.TreeView.PathSeparator = "-->";
            if (t==null) return "";
            try {
            path=t.FullPath;
            path=path.Replace("\\","-->");
            //t.TreeView.PathSeparator = oldPathSep;
            return path;
            } catch (Exception e) {
                return "";
            }
        }
    }


    class functionForList
    {
        string _functionName;
        int moduleNo;

        public int ModuleNo
        {
            get { return moduleNo; }
            
        }
        int lineNo;

        public int LineNo
        {
            get { return lineNo; }
            
        }

        public string functionName
        {
            get
            {
                return _functionName;
            }
        }




        public functionForList(string functionName, int p_moduleNo, int p_lineNo)
        {
            _functionName = functionName;
            this.moduleNo = p_moduleNo;
            this.lineNo = p_lineNo;
        }

        public override string ToString()
        {
            return _functionName;

        }
    }

    public class NLocationInFile
    {
        private int lineNumber;
        private int module;

        public NLocationInFile(string s)
        {
            string[] arr = s.Split('\t');
            if (arr.Length != 2)
            {

                throw new ApplicationException("Invalid location in file");
            }
            module = Convert.ToInt32(arr[0]);
            lineNumber = Convert.ToInt32(arr[1]);
        }


        public NLocationInFile(int mno, int l)
        {

            module = mno;
            lineNumber = l;
        }


        public static string getString(int mod, int ln)
        {
            if (mod == 0 && ln == 0)
            {
                System.Windows.Forms.MessageBox.Show("0 & 0");
            }
            return mod + "\t" + ln;
        }


        public static void decodeString(string s, out int mod, out int ln)
        {
            string[] arr = s.Split('\t');
            if (arr.Length != 2)
            {

                throw new ApplicationException("Invalid location in file");
            }
            mod = Convert.ToInt32(arr[0]);
            ln = Convert.ToInt32(arr[1]);
        }



        public int ModuleNo
        {
            get
            {
                return module;
            }
        }
        public int LineNo
        {
            get
            {
                return lineNumber;
            }
        }

    }




    public class MyCallNode : TreeNode
    {
        public string functionName;

        public MyCallNode(string pFunctionName)
        {
            this.Name = MyCallNode.generateKey(pFunctionName);
            this.Text = pFunctionName;
            functionName = pFunctionName;
        }

        public static string generateKey(string pFunctionName) {
            return "->"+pFunctionName;
        }
    }


    public class MyFunctionNode : MyLocationNode
    {
        private string _functionName;

        public string FunctionName
        {
            get { return _functionName; }
            set { _functionName = value; }
        }
        
        public MyFunctionNode(string functionName, int mod, int pfunctionNo, int line, string text, int firstline, int lastline)
            : base(mod, pfunctionNo, line, text, firstline, lastline)
        {
            _functionName = functionName;

            if (functionName.ToUpper() == "MAIN")
            {
                this.Text = functionName;
            }
            else
            {
                this.Text = "FUNCTION " + functionName;
            }
            setBaseText(this.Text);
        }
    }

    public class MyLocationNode : TreeNode
    {
        private int _lineNumber=-1;
        private int _functionNo=-1;
        private string _text;

        private int _block_start_lineno;
        private int _block_end_lineno;



        public int FunctionNo
        {
            get { return _functionNo; }
            set { _functionNo = value; }
        }


        public int LineNumber
        {
            get { return _lineNumber; }
            set { _lineNumber = value; }
        }
        private int _module;

        public int Module
        {
            get { return _module; }
            set { _module = value; }
        }



        public void setBaseText(string text) {
            this._text = text;
        }


        public override string ToString()
        {

            return base.ToString(); // +" (" + _block_start_lineno + " " + _block_end_lineno + ")";
        }
        /// <summary>
        /// 
        /// </summary>
        /// <param name="mod"></param>
        /// <param name="pfunctionNo"></param>
        /// <param name="line"></param>
        /// <param name="text"></param>
        /// <param name="firstline">Start line of block</param>
        /// <param name="lastline">end line of block</param>
        public MyLocationNode(int mod, int pfunctionNo, int line, string text,int firstline,int lastline)
        {
            _lineNumber = line;
            _module = mod;
            this.Name = _module + "\t" + _lineNumber;
            this.Text = text;
            FunctionNo = pfunctionNo;

            _block_start_lineno = firstline;
            _block_end_lineno = lastline;
            _text = text;
            if (firstline > lastline)
            {
                throw new ApplicationException("Line must be <= lastline");
            }
            this.ensureLines(pfunctionNo, firstline, lastline);
        }


        public MyLocationNode(int mod,int pfunctionNo, int line, string text)
        {
            _lineNumber = line;
            _module = mod;
            this.Name = _module + "\t" + _lineNumber;
            this.Text = text;
            FunctionNo = pfunctionNo;
            _text = text;
       
            _block_start_lineno = line;
            _block_end_lineno = line;
        }




        internal bool LineIsInBlock(int functionNo, int LineNumber)
        {

            // Can't be in this block - its in a different function...
            if (functionNo != this._functionNo) return false;

            // Is it in this block ? 
            if (LineNumber <= _block_end_lineno && LineNumber >= _block_start_lineno)
            {
                return true;
            }

            // It it in any child blocks ?      
            if (this.Nodes!=null)
            {
                foreach (TreeNode t in this.Nodes)
                {
                    if (t is MyLocationNode)
                    {
                        MyLocationNode mln = t as MyLocationNode;
                        if (mln.LineIsInBlock(functionNo, LineNumber)) return true;
                    }
                }
            }

            // no..
            return false;
        }





        internal bool ensureLines(int functionNo, int line, int lastLine)
        {
            bool neededToUpdate = false;

            if (this._functionNo != functionNo)
            {

                return false;
            }

            if (lastLine != -1)
            {
                if (line > lastLine)
                {
                    throw new ApplicationException("Line must be <= lastline");
                }
            }
            
            if (_block_start_lineno == -1)
            {
                _block_start_lineno = line;
                neededToUpdate = true;
            }
            else
            {
                if (line < _block_start_lineno)
                {
                    _block_start_lineno = line;
                    neededToUpdate = true;
                }
            }


            if (lastLine != -1)
            {
                if (_block_end_lineno == -1)
                {
                    _block_end_lineno = lastLine;
                    neededToUpdate = true;
                }
                else
                {
                    if (_block_end_lineno < lastLine)
                    {
                        _block_end_lineno = lastLine;
                        neededToUpdate = true;
                    }
                }
            }


            if (_block_start_lineno > _block_end_lineno)
            {
                throw new ApplicationException("start > last");
            }

            this.Text = _text; // +" (" + _functionNo + ":" + _block_start_lineno + "," + _block_end_lineno + ")";

            TreeNode _parent;
            _parent = this.Parent;



            while (_parent != null)
            {
                if (_parent is MyLocationNode)
                {
                    MyLocationNode mln = _parent as MyLocationNode;

                    mln.ensureLines(functionNo, _block_start_lineno, _block_end_lineno);

                   // if (!mln.ensureLines(functionNo, _block_start_lineno, _block_end_lineno) && false) break;
                }
                _parent = _parent.Parent;
            }

            return neededToUpdate;
        }

        
        internal bool ensureLines(int functionNo, int p)
        {
            return ensureLines(functionNo, p, -1);
        }
         
    }






   
}

