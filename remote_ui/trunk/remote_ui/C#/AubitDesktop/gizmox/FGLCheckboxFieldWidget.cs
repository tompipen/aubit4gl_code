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
using Gizmox.WebGUI.Forms;
using System.Text;
using System.Drawing;

namespace AubitDesktop
{

    // A checkbox widget fgl field widget...
    public class FGLCheckboxFieldWidget : FGLWidget
    {
        //FGLContextType _ContextType;
        private int id;
        CheckBox cbFieldWidget;
       // Panel p;

        string strIndeterminate;
        string strTrue;
        string strFalse;
        bool notNull;

        new public bool Enabled
        {
            get
            {
                return cbFieldWidget.Enabled;
            }
            set
            {
                cbFieldWidget.Enabled = value;
            }
        }

        internal override void setIsOnSelectedRow(bool isSelected)
        {
            isOnSelectedRow = isSelected;
            adjustDisplayPropertiesForContext();
        }

        public new void setToolTip(ToolTip t, string s)
        {
            t.SetToolTip(this.cbFieldWidget, s);
        }

        public override int tabIndex
        {
            set
            {
                cbFieldWidget.TabIndex = value;
            }
        }

        public override bool hasFocus
        {
            get
            {
                if (cbFieldWidget.Enabled && cbFieldWidget.Focused) return true;
                return false;
            }
        }

        public override void setFocus()
        {
            cbFieldWidget.Focus();
        }

        private void setThreeState()
        {
            if (notNull)
            {
                cbFieldWidget.ThreeState = false;
            }
            else
            {
                cbFieldWidget.ThreeState = true;
            }
        }

        internal override void ContextTypeChanged()
        {  // The current ContextType - a field may appear differently if its used in a construct or input..
            adjustDisplayPropertiesForContext();
        }

        public override void gotFocus()
        {
            Console.WriteLine("gotfocus");
            setFocusColor(true);
        }


        private void setFocusColor(bool hasFocus)
        {
            if (hasFocus)
            {
                // Do we have anything to set focus on ?
                if (cbFieldWidget.Text.Length==0) {
                    // No - so make the background black 
                    // so we can see this has focus..
                    this.BackColor = Color.Black;
                }

            }
            else
            {
                this.BackColor = SystemColors.Control;
            }
        }

        private  void adjustDisplayPropertiesForContext()
        {
            switch (_ContextType)
            {
                case FGLContextType.ContextNone:
                    if (onActionID != "")
                    {
                        cbFieldWidget.Enabled = true;
                    }
                    else
                    {
                        cbFieldWidget.Enabled = false;
                    }
                    cbFieldWidget.ThreeState=false;
                    break;


                case FGLContextType.ContextDisplayArray:
                    if (onActionID != "")
                    {
                        cbFieldWidget.Enabled = true;
                    }
                    else
                    {
                        cbFieldWidget.Enabled = false;
                    }
                    cbFieldWidget.ThreeState=false;

                    
                    break;


                case FGLContextType.ContextConstruct:
                    cbFieldWidget.Enabled=true;
                    cbFieldWidget.ThreeState=true;
                    break;

                case FGLContextType.ContextInput:
                    if (this.NoEntry)
                    {

                        cbFieldWidget.Enabled = false;
                    }
                    else
                    {
                        cbFieldWidget.Enabled = true;
                    }
                    setThreeState();
                    //cb.ThreeState=false;
                    break;

                case FGLContextType.ContextInputArray:

                    if (isOnSelectedRow)
                    {
                        if (this.NoEntry)
                        {
                            cbFieldWidget.Enabled = false;
                        }
                        else
                        {
                            cbFieldWidget.Enabled = true; // ??????
                        }
                        setThreeState();
                    }
                    else
                    {
                        cbFieldWidget.Enabled = false;
                    }
                    //cb.ThreeState=false;
                    break;


                default:
                    //cb.ThreeState=false;
                    setThreeState();
                    if (this.NoEntry)
                    {
                        cbFieldWidget.Enabled = false;
                    }
                    else
                    {
                        cbFieldWidget.Enabled=false;
                    }
                    break;

            }
        }

        internal override Control WindowsWidget
        {
            get
            {
                return (Control)cbFieldWidget;
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

            foreach (ON_ACTION_EVENT a in actionList)
            {
                if (a.ACTION == Action)
                {
                    onActionID = a.ID;
                }
            }

            adjustDisplayPropertiesForContext();

        }
        */


        override public string Text // The current fields value
        {
            get
            {
                switch (cbFieldWidget.CheckState) {

                    case CheckState.Checked:
                    return strTrue;
                    
                    case CheckState.Unchecked:
                           return strFalse;
                    case CheckState.Indeterminate:
                        return strIndeterminate;
                    default:
                        throw new ApplicationException("Invalid checkbox state");
                }
            }
            set
            {
                CheckState oldvalue = cbFieldWidget.CheckState;
                if (value == strTrue)
                {
                    cbFieldWidget.CheckState = CheckState.Checked;
                }

                if (value == strFalse)
                {
                    cbFieldWidget.CheckState = CheckState.Unchecked;
                }

                if (value == strIndeterminate)
                {
                    cbFieldWidget.CheckState = CheckState.Indeterminate;
                }


                if (oldvalue != cbFieldWidget.CheckState)
                {
                    this.FieldTextChanged = true;
                }
            }
        }




        public FGLCheckboxFieldWidget(AubitDesktop.Xml.XMLForm.FormField ffx, AubitDesktop.Xml.XMLForm.CheckBox cbox, string config, int index, AubitDesktop.Xml.XMLForm.Matrix ma)
        {
            ATTRIB a;
            a = createAttribForWidget(ffx);

            if (ffx.notNull!=null && ffx.notNull=="1") notNull = true;
            else notNull = false;


            if (cbox.comments != null)
            {
                a.ATTRIB_COMMENTS = new ATTRIB_COMMENTS();
                a.ATTRIB_COMMENTS.Text = cbox.comments;
            }


            createCheckBoxWidget(a,ma,
                Convert.ToInt32(cbox.posY) , index, Convert.ToInt32(cbox.posX), Convert.ToInt32(cbox.gridWidth), "", config, -1, ffx.sqlTabName + "." + ffx.colName, cbox.action, Convert.ToInt32(ffx.fieldId), ffx.include,cbox.text);

            setPixelSize(cbox.pixelWidth, cbox.pixelHeight);

            this.strTrue = cbox.valueChecked;
            this.strFalse = cbox.valueUnchecked;
            this.strIndeterminate = "";
            adjustDisplayPropertiesForContext();

        }



        private void createCheckBoxWidget(ATTRIB thisAttribute, AubitDesktop.Xml.XMLForm.Matrix ma, int row, int index,int column, int columns, string widget, string config, int id, string tabcol, string action, int attributeNo, string incl, string cbText)
        {

            this.SetWidget(thisAttribute,ma, row, index,column, 1, columns, widget, config, id, tabcol, action, attributeNo, incl);

            cbFieldWidget = new CheckBox();
            
           
            SizeControl(ma,index,cbFieldWidget);
            if (cbText != null)
            {
                cbFieldWidget.Text = cbText;
            }
            cbFieldWidget.AutoCheck = true;
            cbFieldWidget.Visible = true;
            cbFieldWidget.AutoSize = true;
            cbFieldWidget.Padding = new Padding(1,1,0,1);
            setFocusColor(false);
            //cbFieldWidget.Text = "#";
            //cb.Location = new System.Drawing.Point(GuiLayout.get_gui_x(column), GuiLayout.get_gui_y(row));
            
            cbFieldWidget.Enter += new EventHandler(t_GotFocus);
            cbFieldWidget.Leave += new EventHandler(cbFieldWidget_Leave);
            cbFieldWidget.TabStop = true;
            cbFieldWidget.Click += new EventHandler(t_Click);
           
           // cbFieldWidget.KeyPress += new KeyPressEventHandler(cbFieldWidget_KeyPress);
           
            this.id = id;
        }


        void cbFieldWidget_Leave(object sender, EventArgs e)
        {
            setFocusColor(false);
        }







    }


}
