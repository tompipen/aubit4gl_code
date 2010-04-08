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

       // private string buttonId;
        
        TextBox t;
        Button pb;
        Panel p;
        Label l;
        int _maxLength = 0;



        public int MaxLength
        {
            get
            {
                return _maxLength;
                //return t.MaxLength;
            }
            set
            {
                _maxLength = value;
                //t.MaxLength=value;
            }
        }

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


        private  void adjustDisplayPropertiesForContext()
        {
            p.BorderStyle = BorderStyle.None;
            pb.Enabled = false;

            switch (_ContextType)
            {
                case FGLContextType.ContextNone:
                    l.Visible = true;
                    t.Visible = false;
                    if (onActionID != "")
                    {
                        pb.Enabled = true;
                    }
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
                case FGLContextType.ContextConstruct:
                    if (_ContextType == FGLContextType.ContextInput)
                    {
                        t.MaxLength = _maxLength;
                    }
                    else
                    {
                        t.MaxLength = 0;
                    }
                    t.Visible = true;
                    if (onActionID != "")
                    {   // Only enable if there is an ON_KEY event for it...
                        pb.Enabled = true;
                    }
                    else
                    {
                                                
                        
                        
                        Console.WriteLine("Not using this button - its not got an onkey");
                    }
                    l.Visible = false;
                    break;




                case FGLContextType.ContextInputArray:
                    t.MaxLength = _maxLength;
                    t.Visible = true;
                    if (isOnSelectedRow)
                    {
                        if (onActionID != "")
                        {   // Only enable if there is an ON_KEY event for it...
                            pb.Enabled = true;
                        }
                        
                    }
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


        /*
        override internal void setKeyList(List<ONKEY_EVENT> keyList, List<ON_ACTION_EVENT> actionList, UIContext currContext)
        {
            onActionID = "";

            foreach (ONKEY_EVENT a in keyList)
            {
                if (Convert.ToInt32(a.KEY) == fakeKeyId)
                {
                    if (this.Action == null || this.Action == "")
                    {
                        onActionID = a.ID;
                    }
                   // buttonId = a.ID;

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

            ContextTypeChanged();

        }
         */

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
                Convert.ToInt32(cbox.posY) , index, Convert.ToInt32(cbox.posX), 1, Convert.ToInt32(cbox.gridWidth), "", config, -1, ffx.sqlTabName + "." + ffx.colName, cbox.action, Convert.ToInt32(ffx.fieldId), ffx.include,cbox.text);
            adjustDisplayPropertiesForContext();
            setPixelSize(cbox.pixelWidth, cbox.pixelHeight);
        }



        private void createComboBoxWidget(ATTRIB thisAttribute, AubitDesktop.Xml.XMLForm.Matrix ma, int row,int index, int column, int rows, int columns, string widget, string config, int id, string tabcol, string action, int attributeNo, string incl,string txt)
        {

            this.SetWidget(thisAttribute,ma, row, index,column, rows, columns, widget, config, id, tabcol, action, attributeNo, incl);

            p = new Panel();
            l = new Label();
            pb = new Button();
            t = new System.Windows.Forms.TextBox();

            l.TextAlign = ContentAlignment.MiddleLeft;

            onActionID = "";


            string[] str = config.Split(' ');

            fakeKeyId = -1;
            if (str.Length == 2)
            {
                Image i; // NOTWEBGUI
                //WEBGUI Gizmox.WebGUI.Common.Resources.ResourceHandle i; 
                i = FGLUtils.getImageFromName(str[0]);
                if (i == null)
                {
                    i = FGLUtils.getImageFromName("zoom");
                }
                if (i != null)
                {

                    //pb.AutoSize = true;
                    pb.Image = i;
                    pb.Size = new Size(i.Width + 10, i.Height + 2); //NOTWEBGUI

                    //WEBGUI pb.AutoSizeMode = AutoSizeMode.GrowAndShrink; pb.AutoSize = true; 
                    fakeKeyId = FGLUtils.getKeyCodeFromKeyName(str[1]);
                }
  
            }

            if (txt != null && txt.Length > 0)
            {
                pb.Text = txt;
            }
            if (str.Length == 1)
            {
                Image i; // NOTWEBGUI
                //WEBGUI Gizmox.WebGUI.Common.Resources.ResourceHandle i; 
                
                i = FGLUtils.getImageFromName("zoom");
                if (i != null)
                {
                    pb.Image = i;
                    pb.ClientSize = new Size(i.Width, i.Height); //NOTWEBGUI

                }
                fakeKeyId = FGLUtils.getKeyCodeFromKeyName(str[0]);
            }

            pb.Click += new EventHandler(pb_Click);

            pb.Dock = DockStyle.Right;
            
            pb.Margin = new Padding(0, 0, 0, 0);
            pb.Padding = new Padding(0, 0, 0, 0);
            p.Margin = new Padding(0, 0, 0, 0);
            p.Padding = new Padding(0, 0, 0, 0);
            l.Margin = new Padding(0, 0, 0, 0);
            l.Padding = new Padding(0, 0, 0, 0);
            t.Margin = new Padding(0, 0, 0, 0);
            t.Padding = new Padding(0, 0, 0, 0);
            t.Visible = true;
            t.Enabled = true;
            pb.Visible = true;
            pb.TabStop = false;
            SizeControl(ma,index,p);
            
            t.Height = p.Size.Height;
            t.Width = p.Size.Width - pb.Width ;


            t.TextChanged += new EventHandler(t_TextChanged);

            // Any columns used for the button must be subtracted from the length of the 
            // textbox..

/*
            if (columns > 2)
            {
                p.Width = GuiLayout.get_gui_w(columns + 1);
            }
            else
            {
                p.Width = GuiLayout.get_gui_w(3);
            }
*/

            t.MaxLength = columns;


            l.Size = t.Size;


            l.BorderStyle = BorderStyle.Fixed3D;
           // l.Dock = DockStyle.Fill;
           

            t.AutoCompleteMode = AutoCompleteMode.Suggest;       
            p.Controls.Add(t);
            p.Controls.Add(l);
            p.Controls.Add(pb);


           
            // p.Size = l.Size;


            t.CausesValidation = true;
            t.Validating += new System.ComponentModel.CancelEventHandler(t_Validating);
            t.GotFocus += new EventHandler(t_GotFocus);
            //t.Click += new EventHandler(t_Click);


            this.id = id;
            adjustDisplayPropertiesForContext();
        }

        void pb_Click(object sender, EventArgs e)
        {

                if (this.onActionID != "")
                {
                    this.onUIEvent(this, this.onActionID, "", null);
                }
        }





        void t_TextChanged(object sender, EventArgs e)
        {
            l.Text = t.Text;
        }
    }

    class FGLComboEntry {
        string _name;
        string _text;
        internal string Name
        {
            get
            {
                return _name;
            }
        }

        internal FGLComboEntry(string name, string text)
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
            if (items!= null)
            {
                o = new FGLComboEntry[items.Length];
                for (int a = 0; a < items.Length; a++)
                {
                    o[a] = new FGLComboEntry(items[a].name, items[a].text);
                }
            }
            else
            {
                o = new FGLComboEntry[0];
            }
            return o;
        }

    }
}
