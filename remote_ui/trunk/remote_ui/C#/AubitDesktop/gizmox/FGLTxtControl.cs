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
using System.Drawing;
using System.Data;
using System.Text;
using Gizmox.WebGUI.Forms;

namespace AubitDesktop
{
    public partial class FGLTxtControl : UserControl
    {
        public FGLTxtControl()
        {
            InitializeComponent();
        }

        private void FGLTxtControl_Load(object sender, EventArgs e)
        {

        }

        private void FGLTxtControl_Resize(object sender, EventArgs e)
        {
            textBox1.Height = this.Height;
            textBox1.Width = this.Width;
            label1.Height = this.Height;
            label1.Width = this.Width;
        }
    }
}
