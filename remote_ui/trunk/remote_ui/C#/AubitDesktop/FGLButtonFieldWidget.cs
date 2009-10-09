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

            adjustDisplayPropertiesForContext();
        }

        internal  void adjustDisplayPropertiesForContext()
        {
            if (_ContextType == FGLContextType.ContextNone)
            {
                if (this.onActionID == "")
                {
                    this.Enabled = false;
                    btn.Enabled = false;
                }
                else
                {
                    this.Enabled = true;
                    btn.Enabled = true;
                }
            }
            else
            {
                this.Enabled = true;
                btn.Enabled = true;
            }
        }


        public override int tabIndex
        {
            set
            {
                btn.TabIndex = value;
            }
        }

        public override bool hasFocus
        {
            get
            {
                return false;
            }
        }


        Button btn;

        public override void setFocus()
        {
            btn.Focus();
        }

        internal override Control WindowsWidget
        {
            get
            {
                return (Control)btn;
            }
        }

        public new bool Enabled
        {
            get
            {
                
                return btn.Enabled;
            }
            set
            {
                btn.Enabled=value;
            }
        }

        public override string Text // The current fields value
        {
            get
            {
                return btn.Text;

            }
            set
            {
                btn.Text=value;
            }
        }

        void b_Click(object sender, EventArgs e)
        {
            if (this.onActionID != "" && this.onUIEvent != null )
            {
                this.onUIEvent(this, this.onActionID, "",null);
            }
        }

        /*
        override internal void setKeyList(List<ONKEY_EVENT> keyList, List<ON_ACTION_EVENT> actionList, UIContext currContext)
        {
            
            if (Action == "") return;
            if (Action == null) return;

            onActionID = "";

            foreach (ONKEY_EVENT a in keyList)
            {
                if (Convert.ToInt32(a.KEY) == FGLUtils.getKeyCodeFromKeyName(Action))
                {
                    // The action is really a fake keypress...
                    onActionID = a.ID;



                    break;
                }
            }

            foreach (ON_ACTION_EVENT a in actionList) {
                if (a.ACTION.ToLower() == Action.ToLower())
                {
                    onActionID = a.ID;
                }
            }

            ContextTypeChanged();

        }
        */

        public FGLButtonFieldWidget(AubitDesktop.Xml.XMLForm.FormField ff, AubitDesktop.Xml.XMLForm.ButtonEdit button, string config, int index, AubitDesktop.Xml.XMLForm.Matrix ma)
        {

            ATTRIB a;
            a = createAttribForWidget(ff);


            createWidget(a, ma,Convert.ToInt32(button.posY),index, Convert.ToInt32(button.posX), 1, Convert.ToInt32(button.gridWidth), "", config, -1, ff.sqlTabName + "." + ff.colName, button.action, Convert.ToInt32(ff.fieldId), ff.include,button.text);
            
        }


        public FGLButtonFieldWidget(AubitDesktop.Xml.XMLForm.FormField ff, AubitDesktop.Xml.XMLForm.Button button, string config, int index, AubitDesktop.Xml.XMLForm.Matrix ma)
        {

            ATTRIB a;
            a = createAttribForWidget(ff);



            createWidget(a, ma, Convert.ToInt32(button.posY), index, Convert.ToInt32(button.posX), 1, Convert.ToInt32(button.gridWidth), "", config, -1, ff.sqlTabName + "." + ff.colName, button.action, Convert.ToInt32(ff.fieldId), ff.include,button.text);
            setPixelSize(button.pixelWidth, button.pixelHeight);
        }

        public override void gotFocus()
        {

        }


        public FGLButtonFieldWidget(ATTRIB thisAttribute, int row, int column, int rows, int columns, string widget, string config, int id, string tabcol, string action, int attributeNo, string incl)
        {

            createWidget(thisAttribute,null, row,0, column, rows, columns, widget, config, id, tabcol, action, attributeNo, incl,null);
        }

        private void createWidget(ATTRIB thisAttribute, AubitDesktop.Xml.XMLForm.Matrix ma, int row, int index,int column, int rows, int columns, string widget, string config, int id, string tabcol, string action, int attributeNo, string incl,string txt)
        {


            this.SetWidget(thisAttribute, ma, row, index, column, 1, columns, widget, config, id, tabcol, action, attributeNo, incl);

            btn = new Button();
            SizeControl(ma, index, btn);

            btn.Visible = true;
            btn.AutoSize = true;


            if (txt != null && txt.Length > 0)
            {
                this.Text = txt;
            }
            if (configSettings.ContainsKey("TEXT")) { this.Text = (string)configSettings["TEXT"]; }
            btn.Click += new EventHandler(b_Click);
            ContextTypeChanged();
        }
    }
}
