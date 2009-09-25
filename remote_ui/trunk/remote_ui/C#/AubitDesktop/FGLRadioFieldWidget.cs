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
using System.Windows.Forms;
using System.Text;
using System.Drawing;

namespace AubitDesktop
{

    // A checkbox widget fgl field widget...
    public class FGLRadioFieldWidget : FGLWidget
    {
        //FGLContextType _ContextType;
        private int id;
        RadioButton[] rbFieldWidget;
        string[] strValues;
        FlowLayoutPanel p;
      //  bool notNull;


        new public bool Enabled
        {
            get
            {
                return p.Enabled;
            }
            set
            {
                p.Enabled = value;
            }
        }

        internal override void setIsOnSelectedRow(bool isSelected)
        {
            isOnSelectedRow = isSelected;
            adjustDisplayPropertiesForContext();
        }

        public new void setToolTip(ToolTip t, string s)
        {
            t.SetToolTip(this.p, s);
        }

        public override int tabIndex
        {
            set
            {
                p.TabIndex = value;
                rbFieldWidget[0].TabIndex = value;
            }
        }

        public override bool hasFocus
        {
            get
            {

                if (p.Enabled == false) return false;
                if (p.Focused) return true;
                foreach (RadioButton rb in rbFieldWidget)
                {
                    if (rb.Focused) return true;
                }
                return false;
            }
        }

        public override void setFocus()
        {
            p.Focus();
            foreach (RadioButton rb in rbFieldWidget)
            {
                if (rb.Checked)
                {
                    rb.Focus();
                    return;
                }
            }
        }


        internal override void ContextTypeChanged()
        {  // The current ContextType - a field may appear differently if its used in a construct or input..
            adjustDisplayPropertiesForContext();
        }

        public override void gotFocus()
        {
        }


        private void setFocusColor(bool hasFocus)
        {
        }

        private void adjustDisplayPropertiesForContext()
        {
            switch (_ContextType)
            {
                case FGLContextType.ContextNone:
                    p.Enabled = false;
                    
                    break;


                case FGLContextType.ContextDisplayArray:
                    p.Enabled=false;
                    

                    
                    break;


                case FGLContextType.ContextConstruct:
                    if (this.Enabled && !this.NoEntry)
                    {
                        p.Enabled = true;
                    }
                    else
                    {
                        p.Enabled = false;
                    }
                    break;

                case FGLContextType.ContextInput:
                    if (this.NoEntry)
                    {
                        p.Enabled = false;
                    }
                    else
                    {
                        p.Enabled = true;
                    }
                    
                    break;

                case FGLContextType.ContextInputArray:

                    if (isOnSelectedRow)
                    {
                        if (this.NoEntry)
                        {
                            p.Enabled = false;
                        }
                        else
                        {
                            p.Enabled = true;
                        }
                        
                    }
                    else
                    {
                        p.Enabled = false;
                    }
                    
                    break;


                default:
                    
                    if (this.NoEntry)
                    {
                        p.Enabled = false;
                    }
                    else
                    {
                        p.Enabled=false;
                    }
                    break;

            }
        }

        internal override Control WindowsWidget
        {
            get
            {
                return (Control)p;
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


        override public string Text // The current fields value
        {
            get
            {
                if (rbFieldWidget == null) return "";

                for (int a = 0; a < rbFieldWidget.Length; a++)
                {
                    if (rbFieldWidget[a].Checked == true)
                    {
                        return strValues[a];
                    }
                }
                //throw new ApplicationException("Invalid radiobutton state");
                return "";
            }

            set
            {
                string oldvalue = this.Text;
                string newvalue = null;

                for (int a = 0; a < rbFieldWidget.Length; a++)
                {
                    if (value ==strValues[a])
                    {
                        rbFieldWidget[a].Checked = true;
                        newvalue = value;
                    }
                }

                if (newvalue != null)
                {
                    if (oldvalue != newvalue)
                    {
                        this.FieldTextChanged = true;
                    }
                }
            }
        }



        public FGLRadioFieldWidget(AubitDesktop.Xml.XMLForm.FormField ffx, AubitDesktop.Xml.XMLForm.RipRADIO cbox, string config, int index, AubitDesktop.Xml.XMLForm.Matrix ma)
        {
            
            AubitDesktop.Xml.XMLForm.Radio cnew;
            cnew = new AubitDesktop.Xml.XMLForm.Radio();


            cnew.action = cbox.action;
            cnew.autoNext = cbox.autoNext;
            cnew.comments = cbox.comments;
            cnew.config = cbox.config;
            cnew.format = cbox.format;
            cnew.gridWidth = cbox.gridWidth;
            cnew.posX = cbox.posX;
            cnew.posY = cbox.posY;
            cnew.shift = cbox.shift;
            cnew.width = cbox.width;
            List<string> items = FGLUtils.splitConfig(config);
            if (items.Count == 0)
            {
                cnew.Items = new AubitDesktop.Xml.XMLForm.Item[0];
            }
            else
            {
                int b = 0;
                cnew.Items = new AubitDesktop.Xml.XMLForm.Item[(items.Count+1) / 2];
                for (int a = 0; a < cnew.Items.Length; a++)
                {
                    cnew.Items[a] = new AubitDesktop.Xml.XMLForm.Item();
                        cnew.Items[a].name = items[b++];
                        if (b < items.Count)
                        {
                            cnew.Items[a].text = items[b++];
                        }
                                    }
            }

            makeRadio(ffx, cnew, config, index,  ma);
        }

        public FGLRadioFieldWidget(AubitDesktop.Xml.XMLForm.FormField ffx, AubitDesktop.Xml.XMLForm.Radio cbox, string config, int index, AubitDesktop.Xml.XMLForm.Matrix ma)
        {
            makeRadio(ffx, cbox, config, index, ma);

        }

        private void makeRadio(AubitDesktop.Xml.XMLForm.FormField ffx, AubitDesktop.Xml.XMLForm.Radio cbox, string config, int index, AubitDesktop.Xml.XMLForm.Matrix ma)
        {
            ATTRIB a;
            a = createAttribForWidget(ffx);

            //if (ffx.notNull != null && ffx.notNull == "1") notNull = true;
            //else notNull = false;


            if (cbox.comments != null)
            {
                a.ATTRIB_COMMENTS = new ATTRIB_COMMENTS();
                a.ATTRIB_COMMENTS.Text = cbox.comments;
            }


            createRadioButtonWidget(a, ma,
                Convert.ToInt32(cbox.posY), index, Convert.ToInt32(cbox.posX), Convert.ToInt32(cbox.gridWidth), "", config, -1, ffx.sqlTabName + "." + ffx.colName, cbox.action, Convert.ToInt32(ffx.fieldId), ffx.include, cbox);


            adjustDisplayPropertiesForContext();
        }



        private void createRadioButtonWidget(ATTRIB thisAttribute, AubitDesktop.Xml.XMLForm.Matrix ma, int row, int index,int column, int columns, string widget, string config, int id, string tabcol, string action, int attributeNo, string incl, AubitDesktop.Xml.XMLForm.Radio r)
        {

            this.SetWidget(thisAttribute,ma, row, index,column, 1, columns, widget, config, id, tabcol, action, attributeNo, incl);
            int minWidth = 0;
            p = new FlowLayoutPanel();
            p.FlowDirection = FlowDirection.TopDown;
            p.AutoSize = true;
            rbFieldWidget=new RadioButton[r.Items.Length];
            strValues = new string[r.Items.Length];
            if (r.Items.Length > 0)
            {
                for (int a = 0; a < r.Items.Length; a++)
                {
                    strValues[a] = r.Items[a].name;
                    RadioButton rb = new RadioButton();
                    if (r.Items[a].text != "-")
                    {
                        rb.Text = r.Items[a].text;
                    }
                    rbFieldWidget[a] = rb;
                    p.Controls.Add(rb);
                    rb.AutoSize = true;
                    if (rb.Width>minWidth) minWidth= rb.Width;
                    rb.Visible = true;
                    rb.TabStop = true;
                    rb.Enabled = true;
                }
            }
           
            SizeControl(ma,index,p);

           // p.BackColor = Color.Red;
            p.Visible = true;
            
            p.MinimumSize = new Size(minWidth, rbFieldWidget[0].Height*r.Items.Length);
        //    p.AutoSize = true;
            
            p.CausesValidation = true;
           // p.Validating += new System.ComponentModel.CancelEventHandler(t_Validating);
            p.Enter += new EventHandler(t_GotFocus);        
            p.TabStop = true;
   
            this.id = id;
        }

        

        

     

    }


}
