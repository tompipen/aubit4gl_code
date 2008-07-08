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
using System.Collections;
using System.Windows.Forms;
using System.Text;
using System.Drawing;

namespace AubitDesktop
{
    // A picture widget fgl field widget...
    class FGLButtonFieldWidget : FGLWidget, IFGLField
    {

        FGLContextType _ContextType;

        public FGLContextType ContextType
        {  // The current ContextType - a field may appear differently if its used in a construct or input..
            set
            {
                _ContextType = value;
                if (_ContextType == FGLContextType.ContextNone)
                {
                    this.Enabled = false;
                }
                else
                {
                    this.Enabled = true;
                }
            }
        }


        public int tabIndex
        {
            set
            {
                b.TabIndex = value;
            }
        }

        public bool hasFocus
        {
            get
            {
                return false;
            }
        }


        Button b;

        public void setFocus()
        {
            b.Focus();
        }

        public Control WindowsWidget
        {
            get
            {
                return (Control)b;
            }
        }

        public new bool Enabled
        {
            get
            {
                
                return b.Enabled;
            }
            set
            {
                b.Enabled=value;

            }
        }

        public new string Text // The current fields value
        {
            get
            {
                return b.Text;

            }
            set
            {
                b.Text=value;
            }
        }

        void b_Click(object sender, EventArgs e)
        {
            if (this.onActionID != "" && this.onUIEvent != null && _ContextType != FGLContextType.ContextNone)
            {
                this.onUIEvent(this, this.onActionID, "");
            }
        }

        public FGLButtonFieldWidget(ATTRIB thisAttribute, int row, int column, int rows, int columns, string widget, string config, int id, string tabcol, string action, int attributeNo, string incl)
        {

            this.SetWidget(thisAttribute, row, column, rows, columns, widget, config, id, tabcol, action, attributeNo, incl);
            b = new Button();
            SizeControl(b);
            if (configSettings.ContainsKey("TEXT")) { this.Text = (string)configSettings["TEXT"]; }
            b.Click+=new EventHandler(b_Click);
        }
    }
}
