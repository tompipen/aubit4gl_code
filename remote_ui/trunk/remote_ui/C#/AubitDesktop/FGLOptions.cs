using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Forms;

namespace AubitDesktop
{
    class FGLOptions
    {
        static public int MenuLine;
        static public int CommentLine;
        static public int ErrorLine;
        static public int PromptLine;
        static public int FormLine;
        static public int MessageLine;
        static public string InsertKey="";
        static public string DeleteKey="";
        static public string NextKey="";
        static public string PreviousKey="";
        static public string AcceptKey="";
        static public bool InputWrap = false;


        static public void SetOption(string s, string val)
        {
            switch (s)
            {

                case "m":
                    MenuLine = Convert.ToInt32(val);
                    break;

                case "W":
                    if (val == "1")
                    {
                        InputWrap = true;
                    }
                    else
                    {
                        InputWrap = false;
                    }
                    break;

                case "C":
                    CommentLine = Convert.ToInt32(val);
                    break;
                case "E":
                    ErrorLine = Convert.ToInt32(val);
                    break;
                case "F":
                    FormLine = Convert.ToInt32(val);
                    break;
                case "M":
                    MessageLine = Convert.ToInt32(val);
                    break;
                case "P":
                    PromptLine = Convert.ToInt32(val);
                    break;
                case "I":
                    InsertKey = val; break;
                case "D":
                    DeleteKey = val; break;
                case "N":
                    NextKey = val; break;
                case "p":
                    PreviousKey = val; break;
                case "A":
                    AcceptKey = val; break;

                default:
                    MessageBox.Show("Option " + s + " not implemented yet");
                    break;

            }
        }
    }
}
