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
    public class FGLDateFieldWidget : FGLWidget
    {
        //FGLContextType _ContextType;
        private int id;
        DateTimePicker t;
        Panel p;
      //  Label l;
        Button b;



        internal override void setIsOnSelectedRow(bool isSelected)
        {
            isOnSelectedRow = isSelected;
            adjustDisplayPropertiesForContext();            
        }


        override internal void setKeyList(List<ONKEY_EVENT> keyList)
        {
            if (Action == "") return;  
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

        public new void setToolTip(ToolTip t, string s)
        {
            //t.SetToolTip(this.l, s);
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
             //   l.Width = value;
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
            
        }

        override public Color BackColor
        {
            set
            {
                this.t.BackColor = value;
               // this.l.BackColor = value;
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
            t.ForeColor = SystemColors.WindowText;
            //t.TabStop = true;
            switch (_ContextType)
            {
                case FGLContextType.ContextNone:
                    
                 //   l.Visible = true;
                    t.Enabled = false;
                    break;


                case FGLContextType.ContextDisplayArray:
                case FGLContextType.ContextDisplayArrayInactive:
                    t.Enabled = false;


                    if (isOnSelectedRow)
                    {
                        t.BackColor = SystemColors.Highlight;
                        t.ForeColor = SystemColors.HighlightText;
                    }
                    else
                    {



                    }
                    break;

                case FGLContextType.ContextConstruct:
                    t.Enabled= true;
                    
                    break;


                case FGLContextType.ContextInput:
                    if (this.NoEntry)
                    {
                        t.Enabled = false;
                        
                    }
                    else
                    {
                        t.Enabled = true;
                        
                    }
                    // We can't trap the tabstops if this is true..
                    //t.TabStop = false;
                    break;

                case FGLContextType.ContextInputArray:
                    if (this.NoEntry)
                    {
                        t.Enabled = false;
                        
                    }
                    else
                    {
                        if (isOnSelectedRow)
                        {
                           // t.BackColor =Color.White;
                            t.Enabled = true;
                            
                        }
                        else
                        {
                            t.Enabled = false;
                            
                        }
                    }
                    break;

                default:
                    if (this.NoEntry)
                    {
                        t.Enabled = false;
                        
                    }
                    else
                    {
                        t.Enabled = false;
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

                
                t.Text = val;
            }
        }




        public FGLDateFieldWidget(AubitDesktop.Xml.XMLForm.FormField ffx, AubitDesktop.Xml.XMLForm.Edit edit, string config, int index, AubitDesktop.Xml.XMLForm.Matrix ma)
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




            
            createTextWidget(a,ma,
                Convert.ToInt32(edit.posY),index, Convert.ToInt32(edit.posX),1, Convert.ToInt32(edit.gridWidth), "", config, -1, ffx.sqlTabName + "." + ffx.colName, "", Convert.ToInt32(ffx.fieldId), ffx.include,false,"");
            
        }





        public FGLDateFieldWidget(AubitDesktop.Xml.XMLForm.FormField ffx, AubitDesktop.Xml.XMLForm.ButtonEdit edit, string config, int index, AubitDesktop.Xml.XMLForm.Matrix ma)
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

        }

        

        public FGLDateFieldWidget(AubitDesktop.Xml.XMLForm.FormField ffx, AubitDesktop.Xml.XMLForm.DateEdit edit, string config, int index, AubitDesktop.Xml.XMLForm.Matrix ma)
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



            
            createTextWidget(a, ma,Convert.ToInt32(edit.posY),index, Convert.ToInt32(edit.posX), 1, Convert.ToInt32(edit.gridWidth), "", edit.config, -1, ffx.sqlTabName + "." + ffx.colName, "", Convert.ToInt32(ffx.fieldId), ffx.include,false,"");
            
            
        }
        

     
        public FGLDateFieldWidget(ATTRIB thisAttribute, int row, int column, int rows, int columns, string widget, string config, int id, string tabcol, string action, int attributeNo,string incl)
        {
            createTextWidget(thisAttribute, null,row, 0,column, rows, columns, widget, config, id, tabcol, action, attributeNo, incl, false, "");
        }
        

        private void createTextWidget(ATTRIB thisAttribute,  AubitDesktop.Xml.XMLForm.Matrix ma,int row,int index, int column, int rows, int columns, string widget, string config, int id, string tabcol, string action, int attributeNo, string incl, bool buttonEdit, string buttonImage)
        {

            int bcol=0;

            this.SetWidget(thisAttribute, ma,row, index,column, rows, columns, widget, config, id, tabcol, action, attributeNo, incl);
           
            p = new Panel();
          
            p.BorderStyle = BorderStyle.Fixed3D;
          
                        t = new System.Windows.Forms.DateTimePicker();
            t.Format = DateTimePickerFormat.Custom;
            t.CustomFormat = FGLUtils.DBDATEFormat_dotnet; 
            t.Visible = true;
            t.Enabled = true;
            

            p.Margin = new Padding(0, 0, 0, 0);
            p.Padding = new Padding(0, 0, 0, 0);
          
            t.Margin = new Padding(0, 0, 0, 0);
            t.Padding = new Padding(0, 0, 0, 0);


            t.Visible = true;
            t.Enabled = true;
            SizeControl(ma,index,p);
            //p.Location = new System.Drawing.Point(GuiLayout.get_gui_x(column), GuiLayout.get_gui_y(row));
            p.AutoSize = true;
            p.Name = "DTPP_" + tabcol;
            t.Name = "DTPT_" + tabcol;

            //t.BackColor = Color.Red;
            //l.BackColor = Color.Blue;



            


            // Any columns used for the button must be subtracted from the length of the 
            // textbox..
               
            t.Size = new Size(GuiLayout.get_gui_w(columns-bcol), GuiLayout.get_gui_h(rows));
           
            p.Size = new Size(GuiLayout.get_gui_w(columns), GuiLayout.get_gui_h(rows));



            if (columns > 2)
            {
                t.Width = GuiLayout.get_gui_w(columns + 1);
            }
            else
            {
                t.Width = GuiLayout.get_gui_w(3);
            }

            
            //t.KeyDown += new KeyEventHandler(t_KeyDown);
            //t.KeyPress += new KeyPressEventHandler(t_KeyPress);
            





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

            if (b!=null)
            {
                p.Controls.Add(b);
            }

           // p.Size = l.Size;
            
            t.CausesValidation = true;
            t.KeyDown += new KeyEventHandler(t_KeyDown);
            t.KeyPress += new KeyPressEventHandler(t_KeyPress);
            t.Validating +=new System.ComponentModel.CancelEventHandler(t_Validating);
            t.Enter += new EventHandler(t_GotFocus);
            t.TextChanged += new EventHandler(t_TextChanged);
            //t.Validating += new System.ComponentModel.CancelEventHandler(t_Validating);
            if (b != null)
            {
                b.Click += new EventHandler(t_Click);
            }
            else
            {
                t.Click += new EventHandler(t_Click);
            }
            t.Visible = true;

            this.id = id;
            this.ContextType = FGLContextType.ContextNone;
            adjustDisplayPropertiesForContext();

        }

        void t_KeyPress(object sender, KeyPressEventArgs e)
        {

        }



        public override void gotFocus()
        {
            

            
            //Program.Show("Here...");
        }

        void t_KeyDown(object sender, KeyEventArgs e)
        {


        }

        void t_TextChanged(object sender, EventArgs e)
        {


        }







    }


}

/*


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

*/


