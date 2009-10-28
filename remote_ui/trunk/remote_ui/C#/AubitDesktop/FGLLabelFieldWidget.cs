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
    class FGLLabelFieldWidget : FGLWidget
    {

        

        internal override void ContextTypeChanged()
        {

            // We dont care...
     
        }


        public override int tabIndex
        {
            set
            {
                // Cant tabIndex into a Label...
            }
        }

        public override bool hasFocus
        {
            get
            {
                return false;
            }
        }


        Label l;

        public override void setFocus()
        {
            
        }

        internal override Control WindowsWidget
        {
            get
            {
                return (Control)l;
            }
        }

        public new bool Enabled
        {
            get
            {
                return l.Enabled;
            }
            set
            {
                l.Enabled = value;
            }
        }

        public override  void gotFocus()
        {

        }

        public override void AttributeChanged()
        {
            int attr;
            attr=this.Attribute;
            if (attr==-1) attr=0;
            
            if ((attr & 4096) != 0) // Reverse...
            {
                this.BackColor = System.Drawing.Color.Bisque;

            }
            else
            {
                this.BackColor = System.Drawing.SystemColors.Control;
            }
            //Program.Show("Attrib changed");
        }

        public override string Text // The current fields value
        {
            get
            {
                return l.Text;

            }
            set
            {
                l.Text = value;
                //if (this.Attribute!=0 && this.Attribute!=-1)
                //{
                //    Program.Show("ATTRIB");
                //}
            }
        }

        void b_Click(object sender, EventArgs e)
        {
            if (this.onActionID != "" && this.onUIEvent != null && _ContextType != FGLContextType.ContextNone)
            {
                this.onUIEvent(this, this.onActionID, "",null);
            }
        }

        /*
        override internal void setKeyList(List<ONKEY_EVENT> keyList, List<ON_ACTION_EVENT> actionList, UIContext currContext)
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
        */

        public FGLLabelFieldWidget(AubitDesktop.Xml.XMLForm.FormField ff, AubitDesktop.Xml.XMLForm.Label label, string config, int index, AubitDesktop.Xml.XMLForm.Matrix ma)
        {
            ATTRIB a;
            
            a = createAttribForWidget(ff);
            createWidget(a, ma,Convert.ToInt32(label.posY), index, Convert.ToInt32(label.posX), 1, Convert.ToInt32(label.gridWidth), "", config, -1, ff.sqlTabName + "." + ff.colName, label.action, Convert.ToInt32(ff.fieldId), ff.include,label.text);
            setPixelSize(label.pixelWidth, label.pixelHeight);
            if (label.justify != null && label.justify.Length>0)
            {
                if (label.justify=="left") {
                    l.TextAlign = ContentAlignment.MiddleLeft;
                }
                if (label.justify == "right")
                {
                    l.TextAlign = ContentAlignment.MiddleRight;
                }
                if (label.justify == "center")
                {
                    l.TextAlign = ContentAlignment.MiddleCenter;
                }
            }
        }

        public FGLLabelFieldWidget(AubitDesktop.Xml.XMLForm.FormField ff, AubitDesktop.Xml.XMLForm.RipLABEL label, string config, int index, AubitDesktop.Xml.XMLForm.Matrix ma)
        {
            ATTRIB a;
            a = createAttribForWidget(ff);
            createWidget(a, ma,Convert.ToInt32(label.posY),index, Convert.ToInt32(label.posX), 1, Convert.ToInt32(label.gridWidth), "", config, -1, ff.sqlTabName + "." + ff.colName, "", Convert.ToInt32(ff.fieldId), ff.include,"");
            setPixelSize(label.pixelWidth, label.pixelHeight);
        }


        public FGLLabelFieldWidget(ATTRIB thisAttribute, int row, int column, int rows, int columns, string widget, string config, int id, string tabcol, string action, int attributeNo, string incl)
        {

            createWidget(thisAttribute,null, row,0, column, rows, columns, widget, config, id, tabcol, action, attributeNo, incl,"");
        }

        private void createWidget(ATTRIB thisAttribute, AubitDesktop.Xml.XMLForm.Matrix ma, int row, int index, int column, int rows, int columns, string widget, string config, int id, string tabcol, string action, int attributeNo, string incl, string origText)
        {
            this.SetWidget(thisAttribute, ma,row,index, column, rows, columns, widget, config, id, tabcol, action, attributeNo, incl);
            l = new Label();
            l.TextAlign = ContentAlignment.MiddleLeft;
            l.BackColor = System.Drawing.SystemColors.Control;
            l.ForeColor = System.Drawing.SystemColors.ControlText;
            SizeControl(ma,index,l);
            if (origText != "")
            {
                this.Text = origText;
            }

            if (configSettings.ContainsKey("TEXT")) { this.Text = (string)configSettings["TEXT"]; }
            //if (this.Text == "") this.Text = tabcol;
            l.Click += new EventHandler(b_Click);
            ContextTypeChanged();
        }
    }
}

