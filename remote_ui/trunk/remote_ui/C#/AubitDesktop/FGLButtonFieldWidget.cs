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
    class FGLButtonFieldWidget : FGLWidget
    {

        //FGLContextType _ContextType;

        internal override void ContextTypeChanged()
        {  // The current ContextType - a field may appear differently if its used in a construct or input..
            
                
                if (_ContextType == FGLContextType.ContextNone)
                {
                    this.Enabled = false;
                    b.Enabled = false;
                }
                else
                {
                    this.Enabled = true;
                    b.Enabled = true;
                }
            
        }


        public override int tabIndex
        {
            set
            {
                b.TabIndex = value;
            }
        }

        public override bool hasFocus
        {
            get
            {
                return false;
            }
        }


        Button b;

        public override void setFocus()
        {
            b.Focus();
        }

        internal override Control WindowsWidget
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

        public override string Text // The current fields value
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
                this.onUIEvent(this, this.onActionID, "",null);
            }
        }


        override internal void setKeyList(List<ONKEY_EVENT> keyList)
        {

            foreach (ONKEY_EVENT a in keyList)
            {
                if (Convert.ToInt32(a.KEY) == FGLUtils.getKeyCodeFromKeyName(Action))
                {
                    // The action is really a fake keypress...
                    onActionID = a.ID;



                    break;
                }
            }

        }

        public FGLButtonFieldWidget(AubitDesktop.Xml.XMLForm.FormField ff, AubitDesktop.Xml.XMLForm.ButtonEdit button, string config, int index, AubitDesktop.Xml.XMLForm.Matrix ma)
        {

            ATTRIB a;
            a = createAttribForWidget(ff);


            createWidget(a, ma,Convert.ToInt32(button.posY),index, Convert.ToInt32(button.posX), 1, Convert.ToInt32(button.gridWidth), "", config, -1, ff.sqlTabName + "." + ff.colName, button.action, Convert.ToInt32(ff.fieldId), ff.include);
            
        }


        public FGLButtonFieldWidget(AubitDesktop.Xml.XMLForm.FormField ff, AubitDesktop.Xml.XMLForm.Button button, string config, int index, AubitDesktop.Xml.XMLForm.Matrix ma)
        {

            ATTRIB a;
            a = createAttribForWidget(ff);


            createWidget(a, ma, Convert.ToInt32(button.posY), index, Convert.ToInt32(button.posX), 1, Convert.ToInt32(button.gridWidth), "", config, -1, ff.sqlTabName + "." + ff.colName, button.action, Convert.ToInt32(ff.fieldId), ff.include);

        }

        public override void gotFocus()
        {

        }


        public FGLButtonFieldWidget(ATTRIB thisAttribute, int row, int column, int rows, int columns, string widget, string config, int id, string tabcol, string action, int attributeNo, string incl)
        {

            createWidget(thisAttribute,null, row,0, column, rows, columns, widget, config, id, tabcol, action, attributeNo, incl);
        }

        private void createWidget(ATTRIB thisAttribute, AubitDesktop.Xml.XMLForm.Matrix ma, int row, int index,int column, int rows, int columns, string widget, string config, int id, string tabcol, string action, int attributeNo, string incl)
        {
            this.SetWidget(thisAttribute, ma,row, index,column, rows, columns, widget, config, id, tabcol, action, attributeNo, incl);
            b = new Button();
            SizeControl(ma,index,b);
            if (configSettings.ContainsKey("TEXT")) { this.Text = (string)configSettings["TEXT"]; }
            b.Click += new EventHandler(b_Click);
            ContextTypeChanged();
        }
    }
}
