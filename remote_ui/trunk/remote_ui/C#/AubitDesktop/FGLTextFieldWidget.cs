﻿/*
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
    public class FGLTextFieldWidget : FGLWidget
    {
        //FGLContextType _ContextType;
        private int id;
        TextBox t;
        Panel p;
        Label l;
        Button b;
        


        public override void setIsOnSelectedRow(bool isSelected)
        {
            isOnSelectedRow = isSelected;
            adjustDisplayPropertiesForContext();            
        }

        public new void setToolTip(ToolTip t, string s)
        {
            t.SetToolTip(this.l, s);
            t.SetToolTip(this.p, s);
            t.SetToolTip(this.t, s);
        }

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

        
        public override void setFocus()
        {
            t.Focus();
            t.Select();
            t.SelectionLength = 0;
        }

        override public Color BackColor
        {
            set
            {
                this.t.BackColor = value;
                this.l.BackColor = value;
            }
            get
            {
                return this.t.BackColor;
            }
            
        }

        public override void ContextTypeChanged()
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
                    t.Visible = false;
                    break;


                case FGLContextType.ContextDisplayArray:
                    if (t.Visible != true)
                    {
                        t.Visible = true;
                    }
                    if (l.Visible != false)
                    {
                        l.Visible = false;
                    }
                    if (t.ReadOnly != true)
                    {
                        t.ReadOnly = true;
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
                    t.Visible = true;
                    l.Visible = false;
                    t.ReadOnly = false;
                    break;

                default:
                    if (this.NoEntry)
                    {
                        t.Visible = false;
                        l.Visible = true;
                        t.ReadOnly = false;
                    }
                    else
                    {
                        t.Visible = true;
                        l.Visible = false;
                        t.ReadOnly = false;
                    }
                    break;

            }
        

        }



        public override Control WindowsWidget
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
                return t.Enabled;
            }
            set
            {
                t.Enabled = value;
            }
        }


        override public string Text // The current fields value
        {
            get
            {
                return t.Text;
            }
            set
            {
                string val;
                val = value;
                if (val != t.Text)
                {
                    this.FieldTextChanged = true;
                }


                if (_ContextType == FGLContextType.ContextInput || _ContextType == FGLContextType.ContextDisplayArray)
                {
                    if (this.format != null)
                    {
                        if (this.format.Length > 0 && val!=null)
                        {
                            val = FGLUsing.A4GL_func_using(this.format, val, this.datatype);
                        }
                    }
                    
                }

                if (_ContextType == FGLContextType.ContextNone)
                {
                    if (val!=null)
                    {
                        val = val.TrimEnd(null);
                    }
                    
                }


                l.Text = val;
                t.Text = val;
                //t.SelectionLength = 0;
                //System.Threading.Thread.Sleep(100);
            }
        }


        /*
        public FGLTextFieldWidget()
        {
            p = new Panel();
            l = new Label();
            t = new System.Windows.Forms.TextBox();
            
            //p.Margin = new Padding(0, 0, 0, 0);
            //p.Padding = new Padding(0, 0, 0, 0);
            //l.Margin = new Padding(0, 0, 0, 0);
            //l.Padding = new Padding(0, 0, 0, 0);
            //t.Margin = new Padding(0, 0, 0, 0);
            //t.Padding = new Padding(0, 0, 0, 0);
            

            l.TextAlign = ContentAlignment.MiddleLeft;
            
            t.Width = Width;
            t.Height = Height;
            l.Height = Height;
            l.Width = Width;

            this.SetWidget();
            l.TextAlign = ContentAlignment.MiddleLeft;
            
            t.Visible = false;
            t.Enabled = true;
            l.Visible = true;
            p.Location = this.Location;
            //p.AutoSize = true;
            p.Height=Height;
            p.Width = Width;
            
            this.Downshift = false;
            this.Upshift = false;
            this.AutoNext = false;
            this.format = null;
            this.NoEntry = false;

            setIsOnSelectedRow(false);
        }
        */


        public int MaxLength
        {
            get{
                   return t.MaxLength;
            } 
            set {
                t.MaxLength=value;
            }
            

        }


        public FGLTextFieldWidget(AubitDesktop.Xml.XMLForm.FormField ffx, AubitDesktop.Xml.XMLForm.TextEdit edit,string config,int index)
        {
            ATTRIB a;
            a = createAttribForWidget(ffx);
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

            
            createTextWidget(a,
                Convert.ToInt32(edit.posY)+index, Convert.ToInt32(edit.posX), Convert.ToInt32 (edit.height), Convert.ToInt32(edit.gridWidth), "", config, -1, ffx.sqlTabName + "." + ffx.colName, "", Convert.ToInt32(ffx.fieldId), ffx.include,false,"");
            
        }


        public FGLTextFieldWidget(AubitDesktop.Xml.XMLForm.FormField ffx, AubitDesktop.Xml.XMLForm.ButtonEdit edit, string config, int index)
        {
            ATTRIB a;
            string action="";
            string image="";
            a = createAttribForWidget(ffx);

            
            if (edit.format != null)
            {
                a.ATTRIB_FORMAT = new ATTRIB_FORMAT();
                a.ATTRIB_FORMAT.Text = edit.format;
            }

            if (edit.action != null)
            {
                action = (string)edit.action;
            }

            if (edit.image!=null)
            {
                image = (string)edit.image;
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


            createTextWidget(a,
                Convert.ToInt32(edit.posY) + index, Convert.ToInt32(edit.posX), 1, Convert.ToInt32(edit.gridWidth), action, config, -1, ffx.sqlTabName + "." + ffx.colName, "", Convert.ToInt32(ffx.fieldId), ffx.include, true,image);

        }




        public FGLTextFieldWidget(AubitDesktop.Xml.XMLForm.FormField ffx, AubitDesktop.Xml.XMLForm.Edit edit,int index)
        {
            ATTRIB a;
            a = createAttribForWidget(ffx);
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

            if (edit.autoNext != null && edit.autoNext=="1")
            {
                a.ATTRIB_AUTONEXT = new ATTRIB_AUTONEXT();
            }

            if (edit.shift!=null)
            {
                if (edit.shift == "aubit")
                {
                    a.ATTRIB_DOWNSHIFT = new ATTRIB_DOWNSHIFT();
                }
                else
                {
                    a.ATTRIB_UPSHIFT = new ATTRIB_UPSHIFT();
                }
            }

            
            createTextWidget(a, Convert.ToInt32(edit.posY)+index, Convert.ToInt32(edit.posX), 1, Convert.ToInt32(edit.gridWidth), "", edit.config, -1, ffx.sqlTabName + "." + ffx.colName, "", Convert.ToInt32(ffx.fieldId), ffx.include,false,"");
            
            
        }

        





        public FGLTextFieldWidget(ATTRIB thisAttribute, int row, int column, int rows, int columns, string widget, string config, int id, string tabcol, string action, int attributeNo,string incl,bool buttonEdit)
        {
            createTextWidget(thisAttribute, row, column, rows, columns, widget, config, id, tabcol, action, attributeNo, incl, buttonEdit, "");
        }



        private void createTextWidget(ATTRIB thisAttribute, int row, int column, int rows, int columns, string widget, string config, int id, string tabcol, string action, int attributeNo, string incl, bool buttonEdit, string buttonImage)
        {

            int bcol=0;

            this.SetWidget(thisAttribute, row, column, rows, columns, widget, config, id, tabcol, action, attributeNo, incl);

            p = new Panel();
            l = new Label();
            l.TextAlign = ContentAlignment.MiddleLeft;
            t = new System.Windows.Forms.TextBox();


            p.Margin = new Padding(0, 0, 0, 0);
            p.Padding = new Padding(0, 0, 0, 0);
            l.Margin = new Padding(0, 0, 0, 0);
            l.Padding = new Padding(0, 0, 0, 0);
            t.Margin = new Padding(0, 0, 0, 0);
            t.Padding = new Padding(0, 0, 0, 0);


            t.Visible = true;
            t.Enabled = true;
            p.Location = new System.Drawing.Point(GuiLayout.get_gui_x(column), GuiLayout.get_gui_y(row));
            p.AutoSize = true;



            if (rows > 1)
            {
                t.Multiline = true;
            }  else {
                t.Multiline = false;
            }

            if (buttonEdit)
            {

                if (configSettings["BUTTONWIDTH"]!=null)
                {
                    bcol = Convert.ToInt32((string)configSettings["BUTTONWIDTH"]);
                }
                else
                {

                    if (columns > 10)
                    {
                        bcol = 5;
                    }
                    else
                    {
                        if (columns > 5)
                        {
                            bcol = 2;
                        }
                        else
                        {
                            bcol = 1;
                        }
                    }
                }


            }


            // Any columns used for the button must be subtracted from the length of the 
            // textbox..
               
            t.Size = new Size(GuiLayout.get_gui_w(columns-bcol), GuiLayout.get_gui_h(rows));
            l.Size = new Size(GuiLayout.get_gui_w(columns - bcol), GuiLayout.get_gui_h(rows));
            p.Size = new Size(GuiLayout.get_gui_w(columns), GuiLayout.get_gui_h(rows));



            if (columns > 2)
            {
                t.Width = GuiLayout.get_gui_w(columns + 1);
            }
            else
            {
                t.Width = GuiLayout.get_gui_w(3);
            }

            t.MaxLength = columns;

            //t.KeyDown += new KeyEventHandler(t_KeyDown);
            //t.KeyPress += new KeyPressEventHandler(t_KeyPress);
            l.Size = t.Size;
            if (Upshift)
            {
                t.CharacterCasing = CharacterCasing.Upper;
            }

            if (Downshift)
            {
                t.CharacterCasing = CharacterCasing.Lower;
            }


            l.Visible = true;
            l.BorderStyle = BorderStyle.Fixed3D;


            if (buttonEdit)
            {

                b = new Button();
                if (configSettings["TEXT"] != null)
                {
                    b.Text = (string)configSettings["TEXT"];
                }
                else
                {
                    b.Text = "!";
                }

                b.Size = new Size(GuiLayout.get_gui_w(bcol), GuiLayout.get_gui_h(rows)-4);
                b.Top = 0;
                if (configSettings["IMAGE"] == null)
                {
                    b.Image = FGLUtils.getImageFromName("zoom");
                }
                else
                {
                    b.Image = FGLUtils.getImageFromName((string)configSettings["IMAGE"]);
                }

                b.Left = t.Width + 1;
                //b.Left = GuiLayout.get_gui_x(column) ;     /* thats 2 pixels - not 2 characters */
                b.Visible = true;
            }
            else
            {
                b = null;
            }

            p.Controls.Add(t);
            p.Controls.Add(l);
            if (b!=null)
            {
                p.Controls.Add(b);
            }

           // p.Size = l.Size;

            t.CausesValidation = true;
            t.LostFocus += new EventHandler(t_LostFocus);
            t.GotFocus += new EventHandler(t_GotFocus);
            //t.Validating += new System.ComponentModel.CancelEventHandler(t_Validating);
            if (b != null)
            {
                b.Click += new EventHandler(t_Click);
            }
            else
            {
                t.Click += new EventHandler(t_Click);
            }
            t.ReadOnly = true;
            t.Visible = true;

            this.id = id;
        }







    }


}
