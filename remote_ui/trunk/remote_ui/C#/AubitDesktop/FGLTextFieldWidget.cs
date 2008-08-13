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
    public class FGLTextFieldWidget : FGLWidget, IFGLField
    {
        FGLContextType _ContextType;
        private int id;
        TextBox t;
        Panel p;
        Label l;

        public new void setToolTip(ToolTip t, string s)
        {
            t.SetToolTip(this.l, s);
            t.SetToolTip(this.p, s);
            t.SetToolTip(this.t, s);
        }

        public int tabIndex
        {
            set
            {
                t.TabIndex = value;
            }
        }

        public bool hasFocus
        {
            get
            {
                if (t.Enabled && t.Focused) return true;
                return false;
            }
        }

        
        public void setFocus()
        {
            t.Focus();
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

        public FGLContextType ContextType
        {  // The current ContextType - a field may appear differently if its used in a construct or input..
            set
            {

                _ContextType = value;
                if (_ContextType == FGLContextType.ContextNone)
                {
                    l.Visible = true;
                    t.Visible = false;
                }
                else
                {


                    if (_ContextType == FGLContextType.ContextDisplayArray)
                    {
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

                    }
                    else
                    {
                        if (_ContextType == FGLContextType.ContextConstruct)
                        {
                            t.Visible = true;
                            l.Visible = false;
                            t.ReadOnly = false;
                        } else {
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
                        }
                    }
                }


            }

        }



        public Control WindowsWidget
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

        public FGLTextFieldWidget()
        {
            p = new Panel();
            l = new Label();
            t = new System.Windows.Forms.TextBox();
            
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
            p.Height=Height;
            p.Width = Width;

            this.Downshift = false;
            this.Upshift = false;
            this.AutoNext = false;
            this.format = null;
            this.NoEntry = false;
        }



        public int MaxLength
        {
            get{
                   return t.MaxLength;
            } 
            set {
                t.MaxLength=value;
            }
            

        }


        public FGLTextFieldWidget(ATTRIB thisAttribute, int row, int column, int rows, int columns, string widget, string config, int id, string tabcol, string action, int attributeNo,string incl)
        {

            
            this.SetWidget(thisAttribute, row, column, rows, columns, widget, config, id, tabcol, action, attributeNo,incl);

            p = new Panel();
            l = new Label();
            l.TextAlign = ContentAlignment.MiddleLeft;
            t = new System.Windows.Forms.TextBox();
            t.Visible = true;
            t.Enabled = true;
            p.Location = new System.Drawing.Point(GuiLayout.get_gui_x(column), GuiLayout.get_gui_y(row));
            p.AutoSize = true;

            t.Size = new Size(GuiLayout.get_gui_w(columns), GuiLayout.get_gui_h(rows));

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
            p.Controls.Add(t);
            p.Controls.Add(l);
            p.Size = t.Size;
            t.CausesValidation = true;
            t.LostFocus += new EventHandler(t_LostFocus);
            t.GotFocus += new EventHandler(t_GotFocus);
            //t.Validating += new System.ComponentModel.CancelEventHandler(t_Validating);
            t.Click += new EventHandler(t_Click);
            t.ReadOnly = true;
            t.Visible = true;
            
            this.id = id;
        }




        bool validateField(object field)
        {
            bool ign = false;

            if (this._ContextType == FGLContextType.ContextInput)
            {
                #region REQUIRED CHECK
                if (this.Required)
                {
                    if (t.Text.Length == 0)
                    {
                        if (this.fieldValidationFailed != null)
                        {
                            this.fieldValidationFailed(this, "REQUIRED", out ign);
                        }
                        if (!ign)
                        {
                           return false;
                        }
                    }

                }
                #endregion
                #region Datatype Check
                if (!FGLUtils.IsValidForType(this.datatype, t.Text, this.format))
                {
                    if (this.fieldValidationFailed != null)
                    {
                        this.fieldValidationFailed(this, "DATATYPE", out ign);
                    }
                    if (!ign)
                    {
                        return false;
                    }
                }
                #endregion
                #region Include value check
                if (this.includeValues != null)
                {
                    bool ok = false;
                    foreach (string s in this.includeValues)
                    {
                        if (s.Contains("\t"))
                        {
                            string l, r;
                            string[] arr;
                            arr = s.Split('\t');
                            l = arr[0];
                            r = arr[1];

                            if (FGLUtils.compare_range(this.Text, l, r, this.datatype, this.datatype_length, this.format))
                            {
                                ok = true;
                            }
                        }
                        else
                        {
                            if (s == "NULL" && this.Text == "")
                            {
                                ok = true;
                            }
                            if (s == this.Text)
                            {
                                ok = true;
                            }
                        }
                    }

                    ign = false;
                    if (!ok)
                    {
                        this.fieldValidationFailed(this, "INCLUDE", out ign);
                    }

                    if (!ign)
                    {
                        return false;
                    }


                }
                #endregion
            }
            return true;
        }


        void t_Validating(object sender, System.ComponentModel.CancelEventArgs e)
        {
            bool ign = false;
            if (!validateField(sender))
            {
                e.Cancel = true;
            }
            else
            {
                e.Cancel = false;
            }
            /*
            if (this._ContextType == FGLContextType.ContextInput)
            {
                #region REQUIRED CHECK
                if (this.Required)
                {
                    if (t.Text.Length == 0)
                    {
                        if (this.fieldValidationFailed != null)
                        {
                            this.fieldValidationFailed(this, "REQUIRED", out ign);
                        }
                        if (!ign)
                        {
                            e.Cancel = true;
                        }
                        else
                        {
                            e.Cancel = false;
                        }
                    }

                }
                #endregion
                #region Datatype Check
                if (!FGLUtils.IsValidForType(this.datatype,t.Text,this.format))
                {
                    if (this.fieldValidationFailed != null)
                    {
                        this.fieldValidationFailed(this, "DATATYPE", out ign);
                    }
                    if (!ign)
                    {
                        e.Cancel = true;
                    }
                    else
                    {
                        e.Cancel = false;
                    }
                }
                #endregion
                #region Include value check
                if (this.includeValues!=null)
                {
                    bool ok=false;
                    foreach (string s in this.includeValues)
                    {
                        if (s.Contains("\t"))
                        {
                            string l, r;
                            string[] arr;
                            arr = s.Split('\t');
                            l = arr[0];
                            r = arr[1];
                            
                            if (FGLUtils.compare_range(this.Text,l, r,this.datatype,this.datatype_length,this.format))
                            {
                                ok = true;
                            }
                        }
                        else
                        {
                            if (s == "NULL" && this.Text == "")
                            {
                                ok = true;
                            }
                            if (s == this.Text)
                            {
                                ok = true;
                            }
                        }
                    }

                    ign = false;
                    if (!ok)
                    {
                        this.fieldValidationFailed(this, "INCLUDE", out ign);
                    }

                    if (!ign)
                    {
                        e.Cancel = true;
                    }
                    else
                    {
                        e.Cancel = false;
                    }
                    
                }
#endregion
             }
             * */
          
        }

  
        void t_GotFocus(object sender, EventArgs e)
        {
            if (this.beforeFieldID != "" && this.onUIEvent != null && _ContextType != FGLContextType.ContextNone)
            {
                this.onUIEvent(this, this.beforeFieldID, "");
            }

            if (this.onGotFocus!=null)
            {
                this.onGotFocus(this,  this.comment);
            }
            
            
        }

        void t_LostFocus(object sender, EventArgs e)
        {
            if (!validateField(sender))
            {
                ((Control)sender).Focus();
            }
            else
            {
                if (this.afterFieldID != "" && this.onUIEvent != null && _ContextType != FGLContextType.ContextNone)
                {
                    this.onUIEvent(this, this.afterFieldID, "");
                }
            }
            
        }


        void t_Click(object sender, EventArgs e)
        {
            if (this.onActionID != "" && this.onUIEvent != null && _ContextType != FGLContextType.ContextNone)
            {
                this.onUIEvent(this, this.onActionID, "");
            }
        }



    }


}
