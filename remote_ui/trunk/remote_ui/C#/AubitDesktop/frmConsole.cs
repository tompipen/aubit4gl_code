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
    public partial class frmConsole : Form
    {
        public frmConsole()
        {
            InitializeComponent();
        }

       public void ClearText()
        {
            this.txtConsoleText.Text = "";
            this.Visible = false;
        }

        public void AddText(string s)
        {
            this.txtConsoleText.Text += s+"\r\n";
            if (txtConsoleText.Text.Length > 0) this.Visible = true;
            else this.Visible = false;
        }

        private void frmConsole_Load(object sender, EventArgs e)
        {
            Program.setWindowPosition(this.GetType().ToString(), this);
        }

        private void frmConsole_FormClosed(object sender, FormClosedEventArgs e)
        {
            Program.saveWindowPosition(this.GetType().ToString(), this);
        }
    }
}