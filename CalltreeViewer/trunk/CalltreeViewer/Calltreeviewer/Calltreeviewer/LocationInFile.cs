using System;
using System.Collections.Generic;
using System.Text;

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


    

    class treeNodeForList
    {
        private System.Windows.Forms.TreeNode t;

        public treeNodeForList(System.Windows.Forms.TreeNode node)
        {
            t = node;
        }

            


        public System.Windows.Forms.TreeNode getNodeForSelection()
        {
            if (t.Text.StartsWith("CALLS"))
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
            string oldPathSep;
            string path;
            //oldPathSep=t.TreeView.PathSeparator;
            //t.TreeView.PathSeparator = "-->";
            path=t.FullPath;
            path=path.Replace("\\","-->");
            //t.TreeView.PathSeparator = oldPathSep;
            return path;
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



    class LocationInFile
    {
        private int lineNumber;
        private int module;

        public LocationInFile(string s)
        {
            string[] arr = s.Split('\t');
            if (arr.Length != 2)
            {
                
                throw new ApplicationException("Invalid location in file");
            }
            module = Convert.ToInt32(arr[0]);
            lineNumber = Convert.ToInt32(arr[1]);
        }

        

        public static string getString(int mod,int ln) {
            if (mod == 0 && ln == 0)
            {
                System.Windows.Forms.MessageBox.Show("0 & 0");
            }
            return mod + "\t" + ln;
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
}
