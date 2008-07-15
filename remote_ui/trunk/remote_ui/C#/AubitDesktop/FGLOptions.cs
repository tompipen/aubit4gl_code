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
         public int MenuLine;
         public int CommentLine;
         public int ErrorLine;
         public int PromptLine;
         public int FormLine;
         public int MessageLine;
         public string InsertKey="";
         public string DeleteKey="";
         public string NextKey="";
         public string PreviousKey="";
         public string AcceptKey="";
         public bool InputWrap = false;


        public FGLOptions()
        {
            this.MenuLine = 1;
            this.AcceptKey="Esc";
            this.InputWrap=false;
   
        }
         public void SetOption(string s, string val)
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
