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
        //FGLContextType _ContextType;
        /*
        private FGLWidget _WidgetDetails;

        public FGLWidget WidgetDetails
        {
            get
            {
                return _WidgetDetails;
            }
        }
         * */

        public override int tabIndex
        {
            set
            {
                t.TabIndex = value;
            }
        }

        public override bool hasFocus
        {
            get
            {
                if (t.Enabled && t.Focused) return true;
                return false;
            }
        }


        public override void ContextTypeChanged()
        {  // The current ContextType - a field may appear differently if its used in a construct or input..
            

                //_ContextType = value;
                if (_ContextType == FGLContextType.ContextNone)
                {
                    l.Visible = true;
                    t.Visible = false;
                }
                else
                {
                    l.Visible = false;
                    t.Visible = true;
                }


            
        }

        DateTimePicker t;
        Panel p;
        Label l;

        public override Control WindowsWidget
        {
            get
            {
                return (Control)p;
            }
        }

        public override void setFocus()
        {
           t.Focus();
        }

        public new bool Enabled
        {
            get
            {
                return t.Enabled;
            }
            set
            {
                t.Enabled = value;
            }
        }


        public override string Text // The current fields value
        {
            get
            {
                return t.Text;
            }
            set
            {
                if (value != t.Text)
                {
                    this.FieldTextChanged = true;
                }
                l.Text = value;
                t.Text = value;
            }
        }

        public FGLDateFieldWidget(AubitDesktop.Xml.XMLForm.FormField ff, AubitDesktop.Xml.XMLForm.DateEdit edit,string config)
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

            

            createWidget(a, Convert.ToInt32(edit.posY), Convert.ToInt32(edit.posX), 1, Convert.ToInt32(edit.gridWidth), "", config, -1, ff.sqlTabName + "." + ff.colName, "", Convert.ToInt32(ff.fieldId), ff.include);
        }



        public FGLDateFieldWidget(AubitDesktop.Xml.XMLForm.FormField ff, AubitDesktop.Xml.XMLForm.Edit edit,string config)
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

            createWidget(a, Convert.ToInt32(edit.posY), Convert.ToInt32(edit.posX), 1, Convert.ToInt32(edit.gridWidth), "",config, -1, ff.sqlTabName + "." + ff.colName, "", Convert.ToInt32(ff.fieldId), ff.include);
        }


        public FGLDateFieldWidget(ATTRIB thisAttribute, int row, int column, int rows, int columns, string widget, string config, int id, string tabcol, string action, int attributeNo,string incl)
        {

            createWidget(thisAttribute, row, column, rows, columns, widget, config, id, tabcol, action, attributeNo, incl);

        }

        private void createWidget(ATTRIB thisAttribute, int row, int column, int rows, int columns, string widget, string config, int id, string tabcol, string action, int attributeNo, string incl)
        {

            this.SetWidget(thisAttribute, row, column, rows, columns, widget, config, id, tabcol, action, attributeNo, incl);

            p = new Panel();
            l = new Label();
            l.TextAlign = ContentAlignment.MiddleLeft;
            t = new System.Windows.Forms.DateTimePicker();
            t.Format = DateTimePickerFormat.Custom;
            t.CustomFormat = FGLUtils.DBDATEFormat_dotnet; //@ FIXME - DBDATE Dependant..
            t.Visible = true;
            t.Enabled = true;
            p.Location = new System.Drawing.Point(GuiLayout.get_gui_x(column), GuiLayout.get_gui_y(row));
            p.AutoSize = true;

            t.Size = new Size(GuiLayout.get_gui_w(columns), GuiLayout.get_gui_h(rows));

            if (columns > 2)
            {
                t.Width = GuiLayout.get_gui_w(columns + 2);
            }
            else
            {
                t.Width = GuiLayout.get_gui_w(3);
            }

            l.Size = t.Size;

            l.Visible = true;
            l.BorderStyle = BorderStyle.Fixed3D;
            p.Controls.Add(t);
            p.Controls.Add(l);
            p.Size = t.Size;

            t.LostFocus += new EventHandler(t_LostFocus);
            t.GotFocus += new EventHandler(t_GotFocus);
            t.Validating += new System.ComponentModel.CancelEventHandler(t_Validating);
        }

       
    }


}

