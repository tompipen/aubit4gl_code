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
    // A text widget fgl field widget...
    class FGLDateFieldWidget : FGLWidget
    {

        DateTimePicker dateTimePicker_t;
        Panel p;
        Label l;





        internal override void setIsOnSelectedRow(bool isSelected)
        {
            isOnSelectedRow = isSelected;
            adjustDisplayPropertiesForContext();
        }

        public new void setToolTip(ToolTip t, string s)
        {
            t.SetToolTip(this.l, s);
            t.SetToolTip(this.p, s);
            t.SetToolTip(this.dateTimePicker_t, s);
        }


        public override int Left
        {
            get
            {
                return p.Left;
            }
            set
            {
                p.Left = value;

            }
        }

        public override int Width
        {
            get
            {
                return p.Width;
            }
            set
            {
                p.Width = value;
                l.Width = value;
                dateTimePicker_t.Width = value;
            }
        }


        public override int tabIndex
        {
            set
            {
                dateTimePicker_t.TabIndex = value;
            }
        }

        public override bool hasFocus
        {
            get
            {
                if (dateTimePicker_t.Enabled && dateTimePicker_t.Focused) return true;
                return false;
            }
        }


        public override void setFocus()
        {
            dateTimePicker_t.Focus();
            dateTimePicker_t.Select();
            
        }

        override public Color BackColor
        {
            set
            {
                this.dateTimePicker_t.BackColor = value;
                this.l.BackColor = value;
            }
            get
            {
                return this.dateTimePicker_t.BackColor;
            }

        }

        internal override void ContextTypeChanged()
        {  // The current ContextType - a field may appear differently if its used in a construct or input..




            //_ContextType = value;
            adjustDisplayPropertiesForContext();

        }

        private void adjustDisplayPropertiesForContext()
        {
            p.BorderStyle = BorderStyle.None;

            switch (_ContextType)
            {
                case FGLContextType.ContextNone:
                    l.Visible = true;
                    dateTimePicker_t.Visible = false;
                    break;


                case FGLContextType.ContextDisplayArray:
                    if (dateTimePicker_t.Visible != true)
                    {
                        dateTimePicker_t.Visible = true;
                    }
                    if (l.Visible != false)
                    {
                        l.Visible = false;
                    }

                    if (isOnSelectedRow)
                    {
                        p.BorderStyle = BorderStyle.FixedSingle;

                        //t.BorderStyle = BorderStyle.FixedSingle;
                        //l.BorderStyle = BorderStyle.FixedSingle;
                    }
                    else
                    {
                        p.BorderStyle = BorderStyle.None;
                        //t.BorderStyle = BorderStyle.Fixed3D;
                        //l.BorderStyle = BorderStyle.Fixed3D;
                    }
                    break;


                case FGLContextType.ContextConstruct:
                    dateTimePicker_t.Visible = true;
                    l.Visible = false;
                    
                    break;

                default:
                    if (this.NoEntry)
                    {
                        dateTimePicker_t.Visible = false;
                        l.Visible = true;
                        
                    }
                    else
                    {
                        dateTimePicker_t.Visible = true;
                        l.Visible = false;
                        
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

        new public bool Enabled
        {
            get
            {
                return dateTimePicker_t.Enabled;
            }
            set
            {
                dateTimePicker_t.Enabled = value;
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


        public override  void  gotFocus()
        {
        }

        override public string Text // The current fields value
        {
            get
            {
                return dateTimePicker_t.Text;
            }
            set
            {
                string val;
                val = value;
                if (val != dateTimePicker_t.Text)
                {
                    this.FieldTextChanged = true;
                }


                if (_ContextType == FGLContextType.ContextInput || _ContextType==FGLContextType.ContextInputArray ||  _ContextType == FGLContextType.ContextDisplayArray)
                {
                    if (this.format != null)
                    {





                        if (this.format.Length > 0 && val != null)
                        {
                            val = FGLUsing.A4GL_func_using(this.format, val, this.datatype);
                        }
                    }

                }

                if (_ContextType == FGLContextType.ContextNone)
                {
                    if (val != null)
                    {
                        val = val.TrimEnd(null);
                    }

                }


                    l.Text = val;
                dateTimePicker_t.Text = val;

            }
        }











        public FGLDateFieldWidget(AubitDesktop.Xml.XMLForm.FormField ff, AubitDesktop.Xml.XMLForm.DateEdit edit,string config,int index,AubitDesktop.Xml.XMLForm.Matrix ma)
        {
            ATTRIB a;
            a = createAttribForWidget(ff);
            if (edit.format != null)
            {
                a.ATTRIB_FORMAT = new ATTRIB_FORMAT();
                a.ATTRIB_FORMAT.Text = edit.format;
            }



            if (edit.comments != null)
            {
                a.ATTRIB_COMMENTS = new ATTRIB_COMMENTS();
                a.ATTRIB_COMMENTS.Text = edit.comments;
            }

            if (edit.autoNext != null && edit.autoNext == "1")
            {
                a.ATTRIB_AUTONEXT = new ATTRIB_AUTONEXT();
            }

            

            createWidget(a, ma,Convert.ToInt32(edit.posY),index, Convert.ToInt32(edit.posX), 1, Convert.ToInt32(edit.gridWidth), "", config, -1, ff.sqlTabName + "." + ff.colName, "", Convert.ToInt32(ff.fieldId), ff.include);
        }



        public FGLDateFieldWidget(AubitDesktop.Xml.XMLForm.FormField ff, AubitDesktop.Xml.XMLForm.Edit edit,string config,int index, AubitDesktop.Xml.XMLForm.Matrix ma)
        {
            ATTRIB a;
            a = createAttribForWidget(ff);
            if (edit.format != null)
            {
                a.ATTRIB_FORMAT = new ATTRIB_FORMAT();
                a.ATTRIB_FORMAT.Text = edit.format;
            }



            if (edit.comments != null)
            {
                a.ATTRIB_COMMENTS = new ATTRIB_COMMENTS();
                a.ATTRIB_COMMENTS.Text = edit.comments;
            }

            if (edit.autoNext != null && edit.autoNext == "1")
            {
                a.ATTRIB_AUTONEXT = new ATTRIB_AUTONEXT();
            }

            if (edit.shift != null)
            {
                if (edit.shift == "down")
                {
                    a.ATTRIB_DOWNSHIFT = new ATTRIB_DOWNSHIFT();
                }
                else
                {
                    a.ATTRIB_UPSHIFT = new ATTRIB_UPSHIFT();
                }
            }

            createWidget(a, ma,Convert.ToInt32(edit.posY),index, Convert.ToInt32(edit.posX), 1, Convert.ToInt32(edit.gridWidth), "",config, -1, ff.sqlTabName + "." + ff.colName, "", Convert.ToInt32(ff.fieldId), ff.include);
        }


        public FGLDateFieldWidget(ATTRIB thisAttribute, int row, int column, int rows, int columns, string widget, string config, int id, string tabcol, string action, int attributeNo,string incl)
        {

            createWidget(thisAttribute, null,row, 0,column, rows, columns, widget, config, id, tabcol, action, attributeNo, incl);

        }

        private void createWidget(ATTRIB thisAttribute, AubitDesktop.Xml.XMLForm.Matrix ma, int row, int index,int column, int rows, int columns, string widget, string config, int id, string tabcol, string action, int attributeNo, string incl)
        {

            this.SetWidget(thisAttribute, ma,row, index,column, rows, columns, widget, config, id, tabcol, action, attributeNo, incl);

            p = new Panel();
            l = new Label();
            l.TextAlign = ContentAlignment.MiddleLeft;
            dateTimePicker_t = new System.Windows.Forms.DateTimePicker();
            dateTimePicker_t.Format = DateTimePickerFormat.Custom;
            dateTimePicker_t.CustomFormat = FGLUtils.DBDATEFormat_dotnet; 
            dateTimePicker_t.Visible = true;
            dateTimePicker_t.Enabled = true;

            p.Location = GuiLayout.getPoint(ma,index, column, row);
            p.AutoSize = true;

            dateTimePicker_t.Size = new Size(GuiLayout.get_gui_w(columns), GuiLayout.get_gui_h(rows));

            if (columns > 2)
            {
                dateTimePicker_t.Width = GuiLayout.get_gui_w(columns + 2);
            }
            else
            {
                dateTimePicker_t.Width = GuiLayout.get_gui_w(3);
            }

            l.Size = dateTimePicker_t.Size;

            l.Visible = true;
            l.BorderStyle = BorderStyle.Fixed3D;
            p.Controls.Add(dateTimePicker_t);
            p.Controls.Add(l);
            p.Size = dateTimePicker_t.Size;

            dateTimePicker_t.Validating += new System.ComponentModel.CancelEventHandler(t_Validating);
            dateTimePicker_t.Enter+= new EventHandler(t_GotFocus);
            dateTimePicker_t.Validating += new System.ComponentModel.CancelEventHandler(t_Validating);
            adjustDisplayPropertiesForContext();
        }

       
    }


}

