/*
 *  Copyright (c) 2008 The Aubit Development Team. 
 *  All rights reserved. See CREDITS file.
 *  
 *  
 *  This file is part of Aubit 4gl.
 *
 *  Aubit 4gl is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as 
 *  published by the Free Software Foundation.
 *
 *  Aubit 4gl is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Aubit 4gl.  If not, see <http://www.gnu.org/licenses/>.
 */

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
