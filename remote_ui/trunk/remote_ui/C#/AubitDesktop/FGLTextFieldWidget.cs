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
using System.Threading;

namespace AubitDesktop
{

    // A text widget fgl field widget...
    public class FGLTextFieldWidget : FGLWidget
    {
        //FGLContextType _ContextType;
        private int id;
        TextBox t;
        Panel p;


        Label lblInsteadOfTxtBox;


        Button b;
      //  int reservedButtonWidth=0;
        int _maxLength = 0;



        internal override void setIsOnSelectedRow(bool isSelected)
        {
            isOnSelectedRow = isSelected;
            adjustDisplayPropertiesForContext();            
        }


        public override void AttributeChanged()
        {

            adjustDisplayPropertiesForContext();
            
        }

        /*
        override internal void setKeyList(List<ONKEY_EVENT> keyList, List<ON_ACTION_EVENT> actionList,UIContext currContext)
        {
            if (Action == "") return;
            if (Action == null) return;
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
         * */

        public new void setToolTip(ToolTip t, string s)
        {
            t.SetToolTip(this.lblInsteadOfTxtBox, s);
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

        public override  int Width
        {
            get
            {
                return p.Width;
            }
            set
            {
                p.Width = value;
                lblInsteadOfTxtBox.Width = value;
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

            if (t.Parent != null)
            {
                if (t.Parent.GetType() == typeof(Panel))
                {
                    Panel Tab = (Panel)t.Parent;
                    //if (WOTabs.TabPages.Contains(Tab))
                    // {
                    //    WOTabs.SelectedTab = Tab;
                    //  TabSelected = true;

                    // }


                    if (Tab.Parent.GetType() == typeof(Panel))
                    {
                        Panel Tab3 = (Panel)Tab.Parent;


                        if (Tab3.Parent.GetType() == typeof(Panel))
                        {

                            Panel Tab4 = (Panel)Tab3.Parent;

                            if (Tab4.Parent.GetType() == typeof(TabPage))
                            {
                                TabPage Tab2 = (TabPage)Tab4.Parent;


                                if (Tab2.Parent.GetType() == typeof(TabControl))
                                {

                                    TabControl Tab5 = (TabControl)Tab2.Parent;

                                    Tab5.SelectedTab = Tab2;
                                }

                            }


                        }  


                    }
                }


               
            }        
            
            t.Focus();
            t.Select();
            t.SelectionLength = 0;
        }

        override public Color BackColor
        {
            set
            {
                this.t.BackColor = value;
                this.lblInsteadOfTxtBox.BackColor = value;
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

        private void adjustDisplayPropertiesForContext()
        {
            p.BorderStyle = BorderStyle.None;
            t.BackColor = SystemColors.Window;
            lblInsteadOfTxtBox.BackColor = SystemColors.Control;
          
            t.ForeColor = SystemColors.WindowText;


            if (this.Attribute != -1)
            {
                if ((this.Attribute & 4096) > 0)
                { // reverse video 
                    t.BackColor = System.Drawing.Color.Bisque;
                    lblInsteadOfTxtBox.BackColor = System.Drawing.Color.Bisque;
                }
            }



            //t.TabStop = true;
            switch (_ContextType)
            {
                case FGLContextType.ContextNone:
                    t.ReadOnly = true;
                    
                    if (false)
                    {
                         
                        lblInsteadOfTxtBox.Visible = true;
                        t.Visible = false;
                        t.ReadOnly = true;
                    }
                    break;


                case FGLContextType.ContextDisplayArray:
                case FGLContextType.ContextDisplayArrayInactive:
                    if (t.Visible != true)
                    {
                        t.Visible = true;
                    }
                    if (lblInsteadOfTxtBox.Visible != false)
                    {
                        lblInsteadOfTxtBox.Visible = false;
                    }
                    if (t.ReadOnly != true)
                    {
                        t.ReadOnly = true;
                    }

                    if (isOnSelectedRow)
                    {
                        t.BackColor = SystemColors.Highlight;
                        t.ForeColor = SystemColors.HighlightText;
                    }
                    else
                    {

                        //p.BackColor = Color.Black;
                        //p.BorderStyle = BorderStyle.None;

                    }
                    break;



                case FGLContextType.ContextConstruct:
                    if (false)
                    {
                        t.Visible = true;
                        lblInsteadOfTxtBox.Visible = false;
                    }
                    t.ReadOnly = false;
                    t.MaxLength = 0;
                    break;


                case FGLContextType.ContextInput:
                    t.MaxLength = _maxLength;
                    if (this.NoEntry)
                    {
                        t.Visible = false;
                        lblInsteadOfTxtBox.Visible = true;
                        t.ReadOnly = false;
                    }
                    else
                    {

                        if (false)
                        {
                            t.Visible = true;
                            lblInsteadOfTxtBox.Visible = false;
                        }

                        t.ReadOnly = false;
                    }
                    // We can't trap the tabstops if this is true..
                    //t.TabStop = false;
                    break;

                case FGLContextType.ContextInputArrayInactive:
                case FGLContextType.ContextInputArray:
                    t.MaxLength = _maxLength;
                    if (this.NoEntry)
                    {
                        if (false)
                        {
                            t.Visible = false;
                            lblInsteadOfTxtBox.Visible = true;
                        }
                        t.ReadOnly = false;
                    }
                    else
                    {
                        if (isOnSelectedRow)
                        {
                            if (false)
                            {
                                t.Visible = true;
                                lblInsteadOfTxtBox.Visible = false;
                            }
                            t.ReadOnly = false;
                        }
                        else
                        {
                            if (false)
                            {
                                t.Visible = false;
                                lblInsteadOfTxtBox.Visible = true;
                            }
                            t.ReadOnly = false;
                        }
                    }
                    break;

                default:
                    if (this.NoEntry)
                    {
                        if (false)
                        {
                            t.Visible = false;
                            lblInsteadOfTxtBox.Visible = true;
                        }
                        t.ReadOnly = false;
                    }
                    else
                    {
                        if (false)
                        {
                            t.Visible = true;
                            lblInsteadOfTxtBox.Visible = false;
                        }
                        t.ReadOnly = false;
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

                if (this.datatype.ToString() == "DTYPE_DECIMAL" || this.datatype.ToString() == "DTYPE_MONEY"
                    || this.datatype.ToString() == "DTYPE_FLOAT" || this.datatype.ToString() == "DTYPE_SMFLOAT")
                {
                    if (Thread.CurrentThread.CurrentCulture.NumberFormat.NumberDecimalSeparator != ".")
                    {
                        // The protocol should always use "." as the separator...
                        try
                        {
                            return t.Text.Replace(Thread.CurrentThread.CurrentCulture.NumberFormat.NumberDecimalSeparator, ".");
                        }  catch{


                        }
                    }
                }
                           
                

                return t.Text;
            }
               
            set
            {
                string val;

                 
                val = value;

                if (val != null)
                {
                    val = val.TrimEnd();

                }

              
                if (val != t.Text)
                {
                    this.FieldTextChanged = true;
                }


                if (_ContextType == FGLContextType.ContextInput || _ContextType == FGLContextType.ContextInputArray || _ContextType == FGLContextType.ContextDisplayArray)
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

                if (t.PasswordChar == '*')
                {
                    string s;
                    s = new string(t.PasswordChar, t.Text.Length);
                    lblInsteadOfTxtBox.Text = s;
                    
                }
                else
                {
                    //l.Text = val;
                }

                string convert_value;
                if (this.datatype.ToString() == "DTYPE_DECIMAL" || this.datatype.ToString() == "DTYPE_MONEY"
                    || this.datatype.ToString() == "DTYPE_FLOAT" || this.datatype.ToString() == "DTYPE_SMFLOAT")
                {
                    
                    try
                    {
                        convert_value = val.Replace(".", Thread.CurrentThread.CurrentCulture.NumberFormat.NumberDecimalSeparator);

                     //   convert_value = (Convert.ToDouble(convert_value)).ToString();
                    }
                    catch
                    {
                        convert_value = null;
                    }
                 //   MessageBox.Show(diogo_teste);

                    lblInsteadOfTxtBox.Text = convert_value;
                    
                   

                }
                t.Text = lblInsteadOfTxtBox.Text;
            }
        }


        public  int MaxLength
        {
            get{
                return _maxLength;
          
            } 
            set {
                _maxLength = value;
                
            }
        }



        public FGLTextFieldWidget(AubitDesktop.Xml.XMLForm.FormField ffx, AubitDesktop.Xml.XMLForm.TextEdit edit, string config, int index, AubitDesktop.Xml.XMLForm.Matrix ma)
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

            
            createTextWidget(a,ma,
                Convert.ToInt32(edit.posY),index, Convert.ToInt32(edit.posX), Convert.ToInt32 (edit.height), Convert.ToInt32(edit.gridWidth), "", config, -1, ffx.sqlTabName + "." + ffx.colName, edit.action, Convert.ToInt32(ffx.fieldId), ffx.include,false,"");

            setPixelSize(edit.pixelWidth, edit.pixelHeight);

            if (edit.fontPitch == "fixed")
            {
                t.Font = new Font(FontFamily.GenericMonospace, t.Font.Size);
                lblInsteadOfTxtBox.Font = t.Font;
            }
        }

        public FGLTextFieldWidget(AubitDesktop.Xml.XMLForm.FormField ffx, AubitDesktop.Xml.XMLForm.ButtonEdit edit, string config, int index, AubitDesktop.Xml.XMLForm.Matrix ma)
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


            createTextWidget(a,ma,
                Convert.ToInt32(edit.posY) , index, 
                Convert.ToInt32(edit.posX), 1, Convert.ToInt32(edit.gridWidth), 
                Widget, config,
                -1, ffx.sqlTabName + "." + ffx.colName,
                action, Convert.ToInt32(ffx.fieldId), ffx.include, true,image);

            setPixelSize(edit.pixelWidth, edit.pixelHeight);

            if (edit.fontPitch == "fixed")
            {
                t.Font = new Font(FontFamily.GenericMonospace, t.Font.Size);
                lblInsteadOfTxtBox.Font = t.Font;
            }
        }

        public FGLTextFieldWidget(AubitDesktop.Xml.XMLForm.FormField ffx, AubitDesktop.Xml.XMLForm.Edit edit, int index, AubitDesktop.Xml.XMLForm.Matrix ma)
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
                if (edit.shift == "down")
                {
                    a.ATTRIB_DOWNSHIFT = new ATTRIB_DOWNSHIFT();
                }
                else
                {
                    a.ATTRIB_UPSHIFT = new ATTRIB_UPSHIFT();
                }
            }

            
            createTextWidget(a, ma,Convert.ToInt32(edit.posY),index, Convert.ToInt32(edit.posX), 1, Convert.ToInt32(edit.gridWidth), "", edit.config, -1, ffx.sqlTabName + "." + ffx.colName, edit.action, Convert.ToInt32(ffx.fieldId), ffx.include,false,"");
            setPixelSize(edit.pixelWidth, edit.pixelHeight);
            if (edit.fontPitch == "fixed")
            {
                t.Font = new Font(FontFamily.GenericMonospace, t.Font.Size);
                lblInsteadOfTxtBox.Font = t.Font;
            }
        }

        public FGLTextFieldWidget(ATTRIB thisAttribute, int row, int column, int rows, int columns, string widget, string config, int id, string tabcol, string action, int attributeNo,string incl,bool buttonEdit)
        {
            createTextWidget(thisAttribute, null,row, 0,column, rows, columns, widget, config, id, tabcol, action, attributeNo, incl, buttonEdit, "");
        }

        private void createTextWidget(ATTRIB thisAttribute,  AubitDesktop.Xml.XMLForm.Matrix ma,int row,int index, int column, int rows, int columns, string widget, string config, int id, string tabcol, string action, int attributeNo, string incl, bool buttonEdit, string buttonImage)
        {

            int bcol=0;
            int totalWidth = 0;
            this.SetWidget(thisAttribute, ma,row, index,column, rows, columns, widget, config, id, tabcol, action, attributeNo, incl);
          
            p = new Panel();
            lblInsteadOfTxtBox = new Label();
            p.BorderStyle = BorderStyle.None;
            if (rows > 1)
            {
                lblInsteadOfTxtBox.TextAlign = ContentAlignment.TopLeft;
            }
            else
            {
                lblInsteadOfTxtBox.TextAlign = ContentAlignment.MiddleLeft;
            }
            
            t = new System.Windows.Forms.TextBox();
            if (thisAttribute.ATTRIB_INVISIBLE!=null)
            {
                t.PasswordChar = '*';
            }
           
            p.Margin = new Padding(0, 0, 0, 0);
            p.Padding = new Padding(0, 0, 0, 0);
            lblInsteadOfTxtBox.Margin = new Padding(0, 0, 0, 0);
            lblInsteadOfTxtBox.Padding = new Padding(0, 0, 0, 0);
            t.Margin = new Padding(0, 0, 0, 0);
            t.Padding = new Padding(0, 0, 0, 0);

            p.Name = "TWP_" + tabcol;
            t.Name = "TWT_" + tabcol;
            lblInsteadOfTxtBox.Name = "TWL_" + tabcol;

            if (buttonEdit)
            {

                if (configSettings["BUTTONWIDTH"] != null)
                {
                    bcol = Convert.ToInt32((string)configSettings["BUTTONWIDTH"]);
                }
                else
                {

                    bcol = 1;
                }
            }

            

            t.Visible = true;
            t.Enabled = true;
            SizeControl(ma,index,p);
            if (bcol > 0)
            {
                p.Size = new Size(GuiLayout.get_gui_w(columns + bcol+1) + 5, GuiLayout.get_gui_h(rows));
            }
 

            if (rows > 1)
            {
                t.Multiline = true;
            }  else {
                t.Multiline = false;
            }



              

            // Any columns used for the button must be subtracted from the length of the 
            // textbox..
               
           // t.Size = new Size(GuiLayout.get_gui_w(columns), GuiLayout.get_gui_h(rows));
            //l.Size = new Size(GuiLayout.get_gui_w(columns), GuiLayout.get_gui_h(rows));
           
            t.Height = GuiLayout.get_gui_h(rows);


            if (columns > 2 || true)
            {
               totalWidth = GuiLayout.get_gui_w(columns+1);
            }
            else
            {
                totalWidth = GuiLayout.get_gui_w(4);
            }

            if (rows == 1)
            {
                this.MaxLength = columns;
            }
            else
            {
                this.MaxLength = columns * rows;
            }

          
            if (Upshift)
            {
                t.CharacterCasing = CharacterCasing.Upper;
            }

            if (Downshift)
            {
                t.CharacterCasing = CharacterCasing.Lower;
            }


            if (false)
            {
                lblInsteadOfTxtBox.Visible = true;
                lblInsteadOfTxtBox.BorderStyle = BorderStyle.Fixed3D;
            }

            if (buttonEdit)
            {

                b = new Button();
                b.TabStop = false;
                if (configSettings["TEXT"] != null)
                {
                    b.Text = (string)configSettings["TEXT"];
                }
                else
                {
                    b.Text = "!";
                }

                //b.Size = new Size(GuiLayout.get_gui_w(bcol), GuiLayout.get_gui_h(rows)-4);
                b.Top = 0;
                
                if (bcol > 0)
                {
                    //reservedButtonWidth = bcol;
                    	b.Width = GuiLayout.get_gui_w(bcol); //NOTWEBGUI 
 			//WEBGUI b.Size = new System.Drawing.Size( GuiLayout.get_gui_w(bcol+1),  GuiLayout.get_gui_h(1));
                }
                else
                {
                    //reservedButtonWidth = 1;
                    b.Width = GuiLayout.get_gui_w(1); //NOTWEBGUI
 			//WEBGUI b.Size = new System.Drawing.Size( GuiLayout.get_gui_w(2),  GuiLayout.get_gui_h(1));
                }

                if (configSettings["IMAGE"] == null)
                {
                    //WEBGUI b.Image = FGLUtils.getImageFromName("zoom.png"); 
                    b.Image = FGLUtils.getImageFromName("zoom"); //NOTWEBGUI
                }
                else
                {
                    b.Image = FGLUtils.getImageFromName((string)configSettings["IMAGE"]);
                }
              
          
                b.Height = b.Image.Height+4;    // NOTWEBGUI
                b.Width = b.Image.Width + 4;    // NOTWEBGUI
                if (b.Image.Height > t.Height)  // NOTWEBGUI
                {                               // NOTWEBGUI
                    b.Height = t.Height;        // NOTWEBGUI
                }                               // NOTWEBGUI

               
                if (bcol >0 )
                {
                    t.Width = totalWidth; // -(GuiLayout.get_gui_w(bcol) + 5);
                    b.Left = totalWidth; // -b.Width;
                } else {
                    t.Width = totalWidth; //-(b.Width +5);
                    b.Left = totalWidth ; // -b.Width;    
                }
                
                //b.Left = GuiLayout.get_gui_x(column) ;     /* thats 2 pixels - not 2 characters */
                b.Visible = true;
            }
            else
            {
                b = null;
                t.Width = totalWidth;
            }
            p.Height = GuiLayout.get_gui_h(rows);
            lblInsteadOfTxtBox.Left = 0;
            lblInsteadOfTxtBox.Top = 0;
            lblInsteadOfTxtBox.Size = t.Size;
            p.Controls.Add(t);
            p.Controls.Add(lblInsteadOfTxtBox);
            p.AutoSize = true; //NOTWEBGUI
            if (b!=null)
            {
                p.Controls.Add(b);
            }

           // p.Size = l.Size;
            
            t.CausesValidation = true;
            //t.KeyDown += new KeyEventHandler(t_KeyDown);
            t.KeyPress += new KeyPressEventHandler(t_KeyPress);
            t.Validating +=new System.ComponentModel.CancelEventHandler(t_Validating);
            t.Enter += new EventHandler(t_GotFocus);
            t.TextChanged += new EventHandler(t_TextChanged);

           // EventHandler moveNext = new EventHandler(TheMethod);

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
            this.ContextType = FGLContextType.ContextNone;
            adjustDisplayPropertiesForContext();

        }




      
        
        public override void gotFocus()
        {
            
            if (format != null)
            {
                if (format != "" || Program.isNumericDatatype(datatype))
                {
                    if (t.SelectionStart == 0|| true)
                    {
                        if (t.SelectionLength == 0)
                        {
                            t.SelectionStart = 0;
                            t.SelectionLength = t.Text.Length;
                        }

                    }
                }
            }
            
  
        }


        void t_TextChanged(object sender, EventArgs e)
        {

            if (t.PasswordChar == '*')
            {
                string s;
                s = new string(t.PasswordChar, t.Text.Length);
                lblInsteadOfTxtBox.Text = s;

            }
            else
            {
                lblInsteadOfTxtBox.Text = t.Text;
            }

            if (this.AutoNext)
            {
                if (t.Text.Length == t.MaxLength && t.SelectionStart == t.MaxLength && t.SelectionLength == 0)
                {
                    SendKeys.Send("{TAB}");
                }
            }

        }


        void t_KeyPress(object sender, KeyPressEventArgs e)
        {

            if (e.KeyChar == (char)Keys.Enter)
            {
                SendKeys.Send("{TAB}");
                 }
           // 
        }







    }


}
