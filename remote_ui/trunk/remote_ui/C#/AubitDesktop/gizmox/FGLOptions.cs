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
using Gizmox.WebGUI.Forms;

namespace AubitDesktop
{
    class FGLOptions
    {
        private int _promptline;
        private int _menuline;
        private int _commentline;
        private int _errorline;
        private int _formline;
        private int _messageline;

        public int MenuLine
        {
            get
            {
                return decodeLine(_menuline);
            }
        }

        public int CommentLine
        {
            get
            {
                return decodeLine(_commentline);
            }
        }

        public int ErrorLine
        {
            get
            {
                return decodeLine(_errorline);
            }
        }

        public int PromptLine
        {
            get
            {
                return decodeLine(_promptline);
            }
        }

        public int FormLine
        {
            get
            {
                return decodeLine(_formline);
            }
        }

        public int MessageLine
        {
            get
            {
                return decodeLine(_messageline);
            }
        }


         public string InsertKey="";
         public string DeleteKey="";
         public string NextKey="";
         public string PreviousKey="";
         public string AcceptKey="";
         public bool InputWrap = false;
        public int screenHeight=25;


        public FGLOptions()
        {
            this._messageline = 1;
            this.AcceptKey="Escape";
            this.InputWrap=false;
            this._promptline = 1;
        }


        public int decodeLine(int line)
        {
            if (line > 0) return line;
            return screenHeight +line;
        }


         public void SetOption(string s, string val)
        {
            switch (s)
            {

                case "m":
                    _menuline = Convert.ToInt32(val);
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
                    _commentline = Convert.ToInt32(val);
                    break;
                case "E":
                    _errorline = Convert.ToInt32(val);
                    break;
                case "F":
                    _formline = Convert.ToInt32(val);
                    break;
                case "M":
                    _messageline = Convert.ToInt32(val);
                    break;
                case "P":
                    _promptline = Convert.ToInt32(val);
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
                    Program.Show("Option " + s + " not implemented yet");
                    break;

            }
        }
    }
}
