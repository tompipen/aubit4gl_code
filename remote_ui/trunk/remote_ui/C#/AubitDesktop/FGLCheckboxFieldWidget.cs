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
    public class FGLCheckboxFieldWidget : FGLWidget
    {
        //FGLContextType _ContextType;
        private int id;
        CheckBox cb;

        string strIndeterminate;
        string strTrue;
        string strFalse;
        bool notNull;


        internal override void setIsOnSelectedRow(bool isSelected)
        {
            isOnSelectedRow = isSelected;
            adjustDisplayPropertiesForContext();
        }

        public new void setToolTip(ToolTip t, string s)
        {
            t.SetToolTip(this.cb, s);
        }



        public override int tabIndex
        {
            set
            {
                cb.TabIndex = value;
            }
        }

        public override bool hasFocus
        {
            get
            {
                if (cb.Enabled && cb.Focused) return true;
                return false;
            }
        }


        public override void setFocus()
        {
            cb.Focus();
        }



        private void setThreeState()
        {
            if (notNull)
            {
                cb.ThreeState = false;
            }
            else
            {
                cb.ThreeState = true;
            }
        }


        internal override void ContextTypeChanged()
        {  // The current ContextType - a field may appear differently if its used in a construct or input..
            adjustDisplayPropertiesForContext();
        }


        public override void gotFocus()
        {

        }

        private void adjustDisplayPropertiesForContext()
        {
            
            
            
            switch (_ContextType)
            {
                case FGLContextType.ContextNone:
                    cb.Enabled = false;
                    cb.ThreeState=false;
                    break;


                case FGLContextType.ContextDisplayArray:
                    cb.Enabled=false;
                    cb.ThreeState=false;

                    
                    break;


                case FGLContextType.ContextConstruct:
                    cb.Enabled=true;
                    cb.ThreeState=true;
                    break;

                case FGLContextType.ContextInput:
                case FGLContextType.ContextInputArray:
                   if (this.NoEntry) {
                       cb.Enabled=false;
                   } else {
                    cb.Enabled=true;
                   }
                   setThreeState();
                    //cb.ThreeState=false;
                    break;


                default:
                    //cb.ThreeState=false;
                    setThreeState();
                    if (this.NoEntry)
                    {
                        cb.Enabled = false;
                    }
                    else
                    {
                        cb.Enabled=false;
                    }
                    break;

            }
        }

        internal override Control WindowsWidget
        {
            get
            {
                return (Control)cb;
            }
        }


        override internal void setKeyList(List<ONKEY_EVENT> keyList)
        {

            foreach (ONKEY_EVENT a in keyList)
            {
                if (a.KEY == FGLUtils.getKeyCodeFromKeyName(Action))
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
                switch (cb.CheckState) {

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
                CheckState oldvalue = cb.CheckState;
                if (value == strTrue)
                {
                    cb.CheckState = CheckState.Checked;
                }

                if (value == strFalse)
                {
                    cb.CheckState = CheckState.Unchecked;
                }

                if (value == strIndeterminate)
                {
                    cb.CheckState = CheckState.Indeterminate;
                }


                if (oldvalue != cb.CheckState)
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
                Convert.ToInt32(cbox.posY) , index, Convert.ToInt32(cbox.posX), Convert.ToInt32(cbox.gridWidth), "", config, -1, ffx.sqlTabName + "." + ffx.colName, "", Convert.ToInt32(ffx.fieldId), ffx.include,cbox.text);

            this.strTrue = cbox.valueChecked;
            this.strFalse = cbox.valueUnchecked;
            this.strIndeterminate = "";
            adjustDisplayPropertiesForContext();

        }



        private void createCheckBoxWidget(ATTRIB thisAttribute, AubitDesktop.Xml.XMLForm.Matrix ma, int row, int index,int column, int columns, string widget, string config, int id, string tabcol, string action, int attributeNo, string incl, string cbText)
        {

           

            this.SetWidget(thisAttribute,ma, row, index,column, 1, columns, widget, config, id, tabcol, action, attributeNo, incl);

            cb = new CheckBox();
            SizeControl(ma,index,cb);
            if (cbText != null)
            {
                cb.Text = cbText;
            }
            cb.AutoCheck = true;
            cb.AutoEllipsis = true;
            cb.Visible = true;

            
            //cb.Location = new System.Drawing.Point(GuiLayout.get_gui_x(column), GuiLayout.get_gui_y(row));
            
            cb.CausesValidation = true;
            cb.Validating += new System.ComponentModel.CancelEventHandler(t_Validating);
            cb.Enter += new EventHandler(t_GotFocus);
            
            
            cb.Click += new EventHandler(t_Click);
            
            this.id = id;
        }







    }


}
