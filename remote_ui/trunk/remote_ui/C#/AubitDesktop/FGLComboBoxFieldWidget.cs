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
    public class FGLComboBoxFieldWidget : FGLWidget
    {
        //FGLContextType _ContextType;
        private int id;
        ComboBox t;
        Panel p;
        Label l;
        FGLComboEntry[] cbItems;
        

        internal override void setIsOnSelectedRow(bool isSelected)
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
                t.Width = value;
            }
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

        internal override void ContextTypeChanged()
        {  // The current ContextType - a field may appear differently if its used in a construct or input..




            //_ContextType = value;
            adjustDisplayPropertiesForContext();

        }


        public override void gotFocus()
        {

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

                    if (isOnSelectedRow)
                    {
                        p.BorderStyle = BorderStyle.FixedSingle;
                    }
                    else
                    {
                        p.BorderStyle = BorderStyle.None;
                    }
                    break;


                case FGLContextType.ContextInput:
                case FGLContextType.ContextInputArray:
                case FGLContextType.ContextConstruct:
                    setItems();
                    t.Visible = true;
                    l.Visible = false;
                    break;



                default:
                    if (this.NoEntry)
                    {
                        t.Visible = false;
                        l.Visible = true;
                        
                    }
                    else
                    {
                        t.Visible = true;
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
                if (val == null) val = "";

                    l.Text = val;
               // t.Text = val;

            }
        }


        public int MaxLength
        {
            get
            {
                return t.MaxLength;
            }
            set
            {
                t.MaxLength = value;
            }
        }



        public FGLComboBoxFieldWidget(AubitDesktop.Xml.XMLForm.FormField ffx, AubitDesktop.Xml.XMLForm.ComboBox cbox, string config, int index, AubitDesktop.Xml.XMLForm.Matrix ma)
        {
            ATTRIB a;
            a = createAttribForWidget(ffx);
            if (cbox.format != null)
            {
                a.ATTRIB_FORMAT = new ATTRIB_FORMAT();
                a.ATTRIB_FORMAT.Text = cbox.format;
            }



            if (cbox.comments != null)
            {
                a.ATTRIB_COMMENTS = new ATTRIB_COMMENTS();
                a.ATTRIB_COMMENTS.Text = cbox.comments;
            }

            if (cbox.autoNext != null && cbox.autoNext == "1")
            {
                a.ATTRIB_AUTONEXT = new ATTRIB_AUTONEXT();
            }

            if (cbox.shift != null)
            {
                if (cbox.shift == "down")
                {
                    a.ATTRIB_DOWNSHIFT = new ATTRIB_DOWNSHIFT();
                }
                else
                {
                    a.ATTRIB_UPSHIFT = new ATTRIB_UPSHIFT();
                }
            }


            createComboBoxWidget(a,ma,
                Convert.ToInt32(cbox.posY) , index, Convert.ToInt32(cbox.posX), 1, Convert.ToInt32(cbox.gridWidth), "", config, -1, ffx.sqlTabName + "." + ffx.colName, "", Convert.ToInt32(ffx.fieldId), ffx.include,cbox.Item);

        }



        private void createComboBoxWidget(ATTRIB thisAttribute, AubitDesktop.Xml.XMLForm.Matrix ma, int row,int index, int column, int rows, int columns, string widget, string config, int id, string tabcol, string action, int attributeNo, string incl, AubitDesktop.Xml.XMLForm.Item[] items)
        {

            int bcol = 0;

            this.SetWidget(thisAttribute,ma, row, index,column, rows, columns, widget, config, id, tabcol, action, attributeNo, incl);

            p = new Panel();
            l = new Label();
            l.TextAlign = ContentAlignment.MiddleLeft;
            t = new System.Windows.Forms.ComboBox();
            
            p.Margin = new Padding(0, 0, 0, 0);
            p.Padding = new Padding(0, 0, 0, 0);
            l.Margin = new Padding(0, 0, 0, 0);
            l.Padding = new Padding(0, 0, 0, 0);
            t.Margin = new Padding(0, 0, 0, 0);
            t.Padding = new Padding(0, 0, 0, 0);


            t.Visible = true;
            t.Enabled = true;
            SizeControl(ma,index,p);
            
            t.Size = p.Size;

            


            // Any columns used for the button must be subtracted from the length of the 
            // textbox..


            if (columns > 2)
            {
                t.Width = GuiLayout.get_gui_w(columns + 1);
            }
            else
            {
                t.Width = GuiLayout.get_gui_w(3);
            }

            t.MaxLength = columns;


            l.Size = t.Size;

            /*
            if (Upshift)
            {
                
                t.CharacterCasing = CharacterCasing.Upper;
            }

            if (Downshift)
            {
                t.CharacterCasing = CharacterCasing.Lower;
            }
            */


            l.Visible = true;
            l.BorderStyle = BorderStyle.Fixed3D;

            t.AutoCompleteMode = AutoCompleteMode.Suggest;
            t.DropDownStyle = ComboBoxStyle.DropDown;
            
            p.Controls.Add(t);
            p.Controls.Add(l);


            cbItems = FGLComboEntry.createItems(items);

            setItems();

            // p.Size = l.Size;


            t.CausesValidation = true;
            t.LostFocus += new EventHandler(t_LostFocus);
            t.GotFocus += new EventHandler(t_GotFocus);
            t.Click += new EventHandler(t_Click);
            t.Visible = true;
            t.Enabled = true;

            this.id = id;
        }





        private void setItems()
        {
            bool hasBlank = false;

            t.BeginUpdate();
            t.Items.Clear();

            
            for (int a = 0; a < cbItems.Length; a++)
            {
                
                if (cbItems[a].ToString() == "") hasBlank = true;
                t.Items.Add(cbItems[a]);
            }

            
            
            if (_ContextType == FGLContextType.ContextConstruct && ! hasBlank)
            {
                
                t.Items.Add(""); /* Add a blank so we can do a search properly */
            }
            t.EndUpdate();
        }







    }

    class FGLComboEntry {
        string _name;
        string _text;

        FGLComboEntry(string name, string text)
        {
            _name = name;
            _text = text;
        }

        public override string ToString()
        {
            return _text;
        }

        public static FGLComboEntry[] createItems(AubitDesktop.Xml.XMLForm.Item[] items) {
            FGLComboEntry []o;
            o = new FGLComboEntry[items.Length];
            for (int a = 0; a < items.Length; a++)
            {
                o[a] = new FGLComboEntry(items[a].name, items[a].text);
            }
            return o;
        }

    }
}
