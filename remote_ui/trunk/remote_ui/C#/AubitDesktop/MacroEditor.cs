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
using System.ComponentModel;
using System.Data;
using System.Drawing;

using System.Text;
using System.Windows.Forms;

namespace AubitDesktop
{
    public partial class MacroEditor : Form
    {
        Eval ev; 

        public MacroEditor()
        {
            InitializeComponent();
           ev = new Eval();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (ev.CompilerErrors == null)
            {
                ev.Execute();
            }
            else
            {
                Program.Show("Didn't compile");
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string t;
            ev.Compile(textBox1.Text);
            t=this.Text;
            this.Text = t + " Compiling Macro....";
            if (ev.CompilerErrors != null)
            {
                string s = "";
                foreach (System.CodeDom.Compiler.CompilerError ce in ev.CompilerErrors)
                {
                    s += ce.ToString() + "\n";
                }
                Program.Show(s, "Compile error");

            }
            else
            {
            //    Program.Show("Compiled ok");
            }
            this.Text = t;

        }

        private void button3_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void MacroEditor_Load(object sender, EventArgs e)
        {
            Program.setWindowPosition(this.GetType().ToString(), this);
        }

        private void MacroEditor_FormClosed(object sender, FormClosedEventArgs e)
        {
            Program.saveWindowPosition(this.GetType().ToString(), this);
        }
    }
}
