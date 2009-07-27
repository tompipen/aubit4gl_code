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

    using System;
    using System.ComponentModel;
    using System.Globalization;
    using System.Runtime.InteropServices;
    using System.Threading;
    using System.Windows.Forms;

    // Copyright (c) 2005 Claudio Grazioli, http://www.grazioli.ch
    //
    // This implementation of a nullable DateTimePicker is a new implementation
    // from scratch, but it is based on ideas I took from this nullable 
    // DateTimePickers:
    // - http://www.omnitalented.com/Blog/PermaLink,guid,9ee757fe-a3e8-46f7-ad04-ef7070934dc8.aspx 
    //   from Alexander Shirshov
    // - http://www.codeproject.com/cs/miscctrl/Nullable_DateTimePicker.asp 
    //   from Pham Minh Tri
    //
    // This code is free software; you can redistribute it and/or modify it.
    // However, this header must remain intact and unchanged.  Additional
    // information may be appended after this header.  Publications based on
    // this code must also include an appropriate reference.
    // 
    // This code is distributed in the hope that it will be useful, but 
    // WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY 
    // or FITNESS FOR A PARTICULAR PURPOSE.
    //


        /// <summary>
        /// Represents a Windows date time picker control. It enhances the .NET standard <b>DateTimePicker</b>
        /// control with a ReadOnly mode as well as with the possibility to show empty values (null values).
        /// </summary>
        [ComVisible(false)]
        public class NullableDateTimePicker : System.Windows.Forms.DateTimePicker
        {
            #region Member variables
            // true, when no date shall be displayed (empty DateTimePicker)
            private bool _isNull;

            // If _isNull = true, this value is shown in the DTP
            private string _nullValue;

            // The format of the DateTimePicker control
            private DateTimePickerFormat _format = DateTimePickerFormat.Long;

            // The custom format of the DateTimePicker control
            private string _customFormat;

            // The format of the DateTimePicker control as string
            private string _formatAsString;
            #endregion

            #region Constructor
            /// <summary>
            /// Default Constructor
            /// </summary>
            public NullableDateTimePicker()
                : base()
            {
                base.Format = DateTimePickerFormat.Custom;
                NullValue = " ";
                Format = DateTimePickerFormat.Long;
            }
            #endregion

            #region Public properties

            public new string Text
            {
                get
                {
                    return base.Text;
                }
                set
                {
                    if (value == "")
                    {
                        this.Value = null;
                    }
                    else
                    {
                        base.Text = value;
                    }
                }
            }
            /// <summary>
            /// Gets or sets the date/time value assigned to the control.
            /// </summary>
            /// <value>The DateTime value assigned to the control
            /// </value>
            /// <remarks>
            /// <p>If the <b>Value</b> property has not been changed in code or by the user, it is set
            /// to the current date and time (<see cref="DateTime.Now"/>).</p>
            /// <p>If <b>Value</b> is <b>null</b>, the DateTimePicker shows 
            /// <see cref="NullValue"/>.</p>
            /// </remarks>
            public new Object Value
            {
                get
                {
                    if (_isNull)
                        return null;
                    else
                        return base.Value;
                }
                set
                {
                    if (value == null || value == DBNull.Value)
                    {
                        SetToNullValue();
                    }
                    else
                    {
                        SetToDateTimeValue();
                        base.Value = (DateTime)value;
                    }
                }
            }

            /// <summary>
            /// Gets or sets the format of the date and time displayed in the control.
            /// </summary>
            /// <value>One of the <see cref="DateTimePickerFormat"/> values. The default is 
            /// <see cref="DateTimePickerFormat.Long"/>.</value>
            [Browsable(true)]
            [DefaultValue(DateTimePickerFormat.Long), TypeConverter(typeof(Enum))]
            public new DateTimePickerFormat Format
            {
                get { return _format; }
                set
                {
                    _format = value;
                    SetFormat();
                    OnFormatChanged(EventArgs.Empty);
                }
            }

            /// <summary>
            /// Gets or sets the custom date/time format string.
            /// <value>A string that represents the custom date/time format. The default is a null
            /// reference (<b>Nothing</b> in Visual Basic).</value>
            /// </summary>
            public new String CustomFormat
            {
                get { return _customFormat; }
                set
                {
                    _customFormat = value;
                }
            }

            /// <summary>
            /// Gets or sets the string value that is assigned to the control as null value. 
            /// </summary>
            /// <value>The string value assigned to the control as null value.</value>
            /// <remarks>
            /// If the <see cref="Value"/> is <b>null</b>, <b>NullValue</b> is
            /// shown in the <b>DateTimePicker</b> control.
            /// </remarks>
            [Browsable(true)]
            [Category("Behavior")]
            [Description("The string used to display null values in the control")]
            [DefaultValue(" ")]
            public String NullValue
            {
                get { return _nullValue; }
                set { _nullValue = value; }
            }
            #endregion

            #region Private methods/properties
            /// <summary>
            /// Stores the current format of the DateTimePicker as string. 
            /// </summary>
            private string FormatAsString
            {
                get { return _formatAsString; }
                set
                {
                    _formatAsString = value;
                    base.CustomFormat = value;
                }
            }

            /// <summary>
            /// Sets the format according to the current DateTimePickerFormat.
            /// </summary>
            private void SetFormat()
            {
                CultureInfo ci = Thread.CurrentThread.CurrentCulture;
                DateTimeFormatInfo dtf = ci.DateTimeFormat;
                switch (_format)
                {
                    case DateTimePickerFormat.Long:
                        FormatAsString = dtf.LongDatePattern;
                        break;
                    case DateTimePickerFormat.Short:
                        FormatAsString = dtf.ShortDatePattern;
                        break;
                    case DateTimePickerFormat.Time:
                        FormatAsString = dtf.ShortTimePattern;
                        break;
                    case DateTimePickerFormat.Custom:
                        FormatAsString = this.CustomFormat;
                        break;
                }
            }

            /// <summary>
            /// Sets the <b>DateTimePicker</b> to the value of the <see cref="NullValue"/> property.
            /// </summary>
            private void SetToNullValue()
            {
                _isNull = true;
                base.CustomFormat = (_nullValue == null || _nullValue == String.Empty) ? " " : "'" + _nullValue + "'";
            }

            /// <summary>
            /// Sets the <b>DateTimePicker</b> back to a non null value.
            /// </summary>
            private void SetToDateTimeValue()
            {
                if (_isNull)
                {
                    SetFormat();
                    _isNull = false;
                    base.OnValueChanged(new EventArgs());
                }
            }
            #endregion

            #region OnXXXX()

            /// <summary>
            /// This member overrides <see cref="DateTimePicker.OnCloseUp"/>.
            /// </summary>
            /// <param name="e"></param>
            protected override void OnCloseUp(EventArgs e)
            {
                if (Control.MouseButtons == MouseButtons.None)
                {
                    if (_isNull)
                    {
                        SetToDateTimeValue();
                        _isNull = false;
                    }
                }
                base.OnCloseUp(e);
            }

            /// <summary>
            /// This member overrides <see cref="Control.OnKeyDown"/>.
            /// </summary>
            /// <param name="e"></param>
            protected override void OnKeyUp(KeyEventArgs e)
            {
                if (e.KeyCode == Keys.Delete)
                {
                    this.Value = null;
                    OnValueChanged(EventArgs.Empty);
                }
                base.OnKeyUp(e);
            }
            #endregion
        }
    

        public class DateTimePickerNull
 : System.Windows.Forms.DateTimePicker
        {

            public DateTimePickerNull()
            {
                this.ShowCheckBox = true;
            }

            public string BindMe
            {
                get
                {
                    if (this.Checked)
                    {
                        return base.Text;
                    }
                    else
                    {
                        return "";
                    }
                }
                set
                {
                    if (System.Convert.IsDBNull(value) || value=="")
                    {
                        this.Checked = false;
                    }
                    else
                    {
                        if (this.Checked == false)
                            this.Checked = true;

                        this.Text=value;
                    }
                }
            }

        
    }


    // A text widget fgl field widget...
    public class FGLDateFieldWidget : FGLWidget
    {

        private int id;
        NullableDateTimePicker tNullable;
        Panel p;
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
            t.SetToolTip(this.tNullable, s);
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
                tNullable.Width = value;
            }
        }


        public override int tabIndex
        {
            set
            {
                tNullable.TabIndex = value;
            }
        }

        public override bool hasFocus
        {
            get
            {
                if (tNullable.Enabled && tNullable.Focused) return true;
                return false;
            }
        }

        
        public override void setFocus()
        {
            tNullable.Focus();
            tNullable.Select();
            
        }

        override public Color BackColor
        {
            set
            {
                this.tNullable.BackColor = value;
               // this.l.BackColor = value;
            }
            get
            {
                return this.tNullable.BackColor;
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

            tNullable.BackColor = SystemColors.Window;
            tNullable.ForeColor = SystemColors.WindowText;
            //t.TabStop = true;
            switch (_ContextType)
            {
                case FGLContextType.ContextNone:
                    
                 //   l.Visible = true;
                    tNullable.Enabled = false;
                    break;


                case FGLContextType.ContextDisplayArray:
                case FGLContextType.ContextDisplayArrayInactive:
                    tNullable.Enabled = false;


                    if (isOnSelectedRow)
                    {
                        tNullable.BackColor = SystemColors.Highlight;
                        tNullable.ForeColor = SystemColors.HighlightText;
                    }
                    else
                    {



                    }
                    break;

                case FGLContextType.ContextConstruct:
                    tNullable.Enabled = true;
                    
                    break;


                case FGLContextType.ContextInput:
                    if (this.NoEntry)
                    {
                        tNullable.Enabled = false;
                        
                    }
                    else
                    {
                        tNullable.Enabled = true;
                        
                    }
                    // We can't trap the tabstops if this is true..
                    //t.TabStop = false;
                    break;

                case FGLContextType.ContextInputArray:
                    if (this.NoEntry)
                    {
                        tNullable.Enabled = false;
                        
                    }
                    else
                    {
                        if (isOnSelectedRow)
                        {
                           // t.BackColor =Color.White;
                            tNullable.Enabled = true;
                            
                        }
                        else
                        {
                            tNullable.Enabled = false;
                            
                        }
                    }
                    break;

                default:
                    if (this.NoEntry)
                    {
                        tNullable.Enabled = false;
                        
                    }
                    else
                    {
                        tNullable.Enabled = false;
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
                return tNullable.Enabled;
            }
            set
            {
                tNullable.Enabled = value;
            }
        }


        override public string Text // The current fields value
        {
            get
            {
                return tNullable.Text;
            }
            set
            {
                string val;
                val = value;
                if (val == "") val = null;
                if (val != tNullable.Text)
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

                if (val == null)
                {
                    tNullable.Text = "";
                    tNullable.Value = null;
                }
                else
                {
                    tNullable.Text = val;
                }
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

            tNullable = new NullableDateTimePicker();
            tNullable.Format = DateTimePickerFormat.Custom;
            tNullable.CustomFormat = FGLUtils.DBDATEFormat_dotnet;
            tNullable.Visible = true;
            tNullable.Enabled = true;
            

            p.Margin = new Padding(0, 0, 0, 0);
            p.Padding = new Padding(0, 0, 0, 0);

            tNullable.Margin = new Padding(0, 0, 0, 0);
            tNullable.Padding = new Padding(0, 0, 0, 0);


            tNullable.Visible = true;
            tNullable.Enabled = true;
            SizeControl(ma,index,p);
            //p.Location = new System.Drawing.Point(GuiLayout.get_gui_x(column), GuiLayout.get_gui_y(row));
            p.AutoSize = true;
            p.Name = "DTPP_" + tabcol;
            tNullable.Name = "DTPT_" + tabcol;

            //t.BackColor = Color.Red;
            //l.BackColor = Color.Blue;



            


            // Any columns used for the button must be subtracted from the length of the 
            // textbox..

            tNullable.Size = new Size(GuiLayout.get_gui_w(columns - bcol), GuiLayout.get_gui_h(rows));
           
            p.Size = new Size(GuiLayout.get_gui_w(columns), GuiLayout.get_gui_h(rows));



            if (columns > 2)
            {
                tNullable.Width = GuiLayout.get_gui_w(columns + 1);
            }
            else
            {
                tNullable.Width = GuiLayout.get_gui_w(3);
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

                b.Left = tNullable.Width + 1;
                //b.Left = GuiLayout.get_gui_x(column) ;     /* thats 2 pixels - not 2 characters */
                b.Visible = true;
            }
            else
            {
                b = null;
            }

            p.Controls.Add(tNullable);

            if (b!=null)
            {
                p.Controls.Add(b);
            }

           // p.Size = l.Size;

            tNullable.CausesValidation = true;
            tNullable.KeyDown += new KeyEventHandler(t_KeyDown);
            tNullable.KeyPress += new KeyPressEventHandler(t_KeyPress);
            tNullable.Validating += new System.ComponentModel.CancelEventHandler(t_Validating);
            tNullable.Enter += new EventHandler(t_GotFocus);
            tNullable.TextChanged += new EventHandler(t_TextChanged);
            //t.Validating += new System.ComponentModel.CancelEventHandler(t_Validating);
            if (b != null)
            {
                b.Click += new EventHandler(t_Click);
            }
            else
            {
                tNullable.Click += new EventHandler(t_Click);
            }
            tNullable.Visible = true;

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


