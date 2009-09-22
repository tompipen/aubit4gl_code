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
using System.Collections;
using System.Text;
using System.Windows.Forms;

namespace AubitDesktop
{
    public class FGLWidget /* : ContainerControl */
    {
       private int _attributeNo;
        private string _TableName;
        private string _ColumnName;
        private string _Action;
        private string _Config;
        private string _Widget;
        private string _comment;

        internal FGLContextType _ContextType=FGLContextType.ContextNone;
        private int _row;
        private int _column;
        private int _rows;
        private int _columns;
        private int _attribute;
        private int _id;
        private bool _FieldTextChanged;
        internal Hashtable configSettings;


        ATTRIB attrib;
        


        private UIFieldValidationHandler _fieldValidationFailed;
        private UIEventHandler _onUIEvent;
        private UIGotFocusHandler _onGotFocus;

        internal string _afterFieldID;
        internal string _beforeFieldID;
        internal string _onActionID;
        private bool _isOnSelectedRow;

        /// <summary>
        /// Used to indicate if this widget is on the current row in a
        /// display array/input array...
        /// </summary>
        internal bool isOnSelectedRow
        {
            set
            {
                if (_isOnSelectedRow != value)
                {
                    _isOnSelectedRow = value;
                    setIsOnSelectedRow(value);
                }
            }
            get
            {
                return _isOnSelectedRow;
            }
        }


        internal virtual void setIsOnSelectedRow(bool isSelected)
        {

        }

        // Virtual members - must be overriden by widget implementation...
        internal virtual void ContextTypeChanged()
        {
            throw new ApplicationException("Not implemented");

        }

        public virtual System.Drawing.Color BackColor
        {
            get
            {
                return WindowsWidget.BackColor;
            }
            set
            {
                WindowsWidget.BackColor = value;
            }
        }

        public  bool Enabled
        {
            get
            {
                return WindowsWidget.Enabled;
            }
            set
            {
                WindowsWidget.Enabled = value;
            }
        }



        public virtual string Text // The current fields value
        {
            get
            {
                return WindowsWidget.Text;

            }
            set
            {
                WindowsWidget.Text = value;
            }
        }

        public virtual void gotFocus()
        {
            throw new NotImplementedException("Should be overridden");
        }

        public virtual void setFocus()
        {
            throw new NotImplementedException("Should be overridden");
        }

        public virtual int tabIndex
        {
            set
            {

                throw new NotImplementedException("Should be overridden");
            }
        }


        public  virtual bool Visible
        {
            get
            {
                return WindowsWidget.Visible;
            }
            set
            {
                WindowsWidget.Visible = value;
            }
        }

        public   virtual int Top
        {
            get
            {
                return WindowsWidget.Top;
            }
            set
            {
                WindowsWidget.Top = value;
            }
        }

        public  virtual int Width
        {
            get
            {
                return WindowsWidget.Width;
            }
            set
            {
                WindowsWidget.Width = value;
            }
        }

        public  virtual int Left
        {
            get
            {
                return WindowsWidget.Left;
            }
            set
            {
                WindowsWidget.Left = value;
            }
        }

        public  virtual int Height
        {
            get
            {
                return WindowsWidget.Height;
            }
            set
            {
                WindowsWidget.Height = value;
            }
        }
        

        public virtual bool hasFocus
        {
            get
            {
                throw new NotImplementedException("Should be overridden");
            }
        }

        internal virtual Control WindowsWidget
        {
            get
            {
                throw new NotImplementedException("Should be overridden");
            }
        }




        public string afterFieldID
        {
            get
            {
                return _afterFieldID;
            }
            set
            {
                _afterFieldID = value;
            }
        }

        public string comment
        {
            get
            {
                return _comment;
            }
        }

        public void setToolTip(ToolTip t, string s)
        {

        }

        public string onActionID
        {
            get
            {
                return _onActionID;
            }
            set
            {
                _onActionID = value;
            }
        }


        

        public FGLContextType ContextType
        {  // The current ContextType - a field may appear differently if its used in a construct or input..
            set
            {
                if (_ContextType != value)
                {
                    _ContextType = value;
                    ContextTypeChanged();
                }
            }
        }


        
        public string beforeFieldID
        {
            get
            {
                return _beforeFieldID;
            }
            set
            {
                _beforeFieldID = value;
            }
        }

        internal UIFieldValidationHandler fieldValidationFailed
        {
            set
            {
                _fieldValidationFailed = value;
            }
            get
            {
                return _fieldValidationFailed;
            }
        }

        public UIEventHandler onUIEvent
        {
            set
            {
                _onUIEvent = value;
            }
            get
            {
                return _onUIEvent;
            }
        }




       public UIGotFocusHandler onGotFocus
        {
            set
            {
                _onGotFocus = value;
            }
            get
            {
                return _onGotFocus;
            }
        }
       


        public List<string> includeValues;

       

       
        /// <summary>
        /// current display attribute...
        /// </summary>
        public int Attribute
        {
            get
            {
                return _attribute;
            }
            set
            {
                if (_attribute != value)
                {
                    _attribute = value;
                    AttributeChanged();
                }
            }
        }

        public virtual void AttributeChanged()
        {

        }

        public bool NoEntry
        {
            get
            {
                if (attrib.ATTRIB_NOENTRY == null)
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
            set
            {
                if (value)
                {
                    attrib.ATTRIB_NOENTRY = new ATTRIB_NOENTRY();
                }
                else
                {
                    attrib.ATTRIB_NOENTRY = null;
                }
            }
        }



        public string format
        {
            get
            {
                if (attrib.ATTRIB_FORMAT == null)
                {
                    return null;
                }
                else
                {
                    return attrib.ATTRIB_FORMAT.Text;
                }
            }
            set
            {
                attrib.ATTRIB_FORMAT = new ATTRIB_FORMAT();
                attrib.ATTRIB_FORMAT.Text = value;
            }
        }

        public bool AutoNext
        {
            get
            {
                if (attrib.ATTRIB_AUTONEXT == null)
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
            set
            {
                if (value)
                {

                    attrib.ATTRIB_AUTONEXT = new ATTRIB_AUTONEXT();

                }
                else
                {
                    attrib.ATTRIB_AUTONEXT = null;
                }
            }
        }

        public bool Downshift
        {
            get
            {
                if (attrib.ATTRIB_DOWNSHIFT == null)
                {
                    return false;
                }
                else
                {
                    return true;
                }

            }
            set
            {
                if (value)
                {
                    attrib.ATTRIB_DOWNSHIFT = new ATTRIB_DOWNSHIFT();
                }
                else
                {
                    attrib.ATTRIB_DOWNSHIFT = null;
                }
            }
        }

        public bool Upshift
        {
            get
            {
                if (attrib.ATTRIB_UPSHIFT == null)
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
            set {
                if (value)
                {
                    attrib.ATTRIB_UPSHIFT = new ATTRIB_UPSHIFT();
                }
                else
                {
                    attrib.ATTRIB_UPSHIFT = null;
                }
            }
        }

        public bool Required
        {
            get
            {
                if (attrib.ATTRIB_REQUIRED == null)
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
            set
            {
                if (value)
                {
                    attrib.ATTRIB_REQUIRED = new ATTRIB_REQUIRED();
                }
                else
                {
                    attrib.ATTRIB_REQUIRED= null;
                }
            }
        }

        public FGLUtils.FGLDataTypes datatype
        {
            get
            {
                return (FGLUtils.FGLDataTypes)Convert.ToInt32(this.attrib.DATATYPE);
            }
            set
            {
                this.attrib.DATATYPE = value.ToString();
            }
        }

        public int datatype_length
        {
            get
            {
                return Convert.ToInt32(this.attrib.DATATYPE_SIZE);
            }
            set
            {
                this.attrib.DATATYPE_SIZE = value.ToString();
            }
        }

        





        public FGLWidget()
        {
         _attributeNo = -1;
         _TableName="";
         _ColumnName = "";
         _Action="";
         _Config="";
         _Widget="";

         _row=-1;
         _column=-1;
         _rows=-1;
         _columns=-1;
         _id=-1;
         _FieldTextChanged=false;
         _comment = "";
        }

        internal void SetWidget() {

            
            attrib = new ATTRIB();

        }



        internal int decode_datatype_size(string p)
        {

            return 0;
        }

        internal int decode_datatype(string p)
        {
            p=p.TrimStart(' ');
            if (p.StartsWith("DECIMAL")) return 5;
            if (p.StartsWith("CHAR")) return 0;
            if (p.StartsWith("VARCHAR")) return 13;
            if (p.StartsWith("DATETIME")) return 10;
            if (p.StartsWith("INTERVAL")) return 14;

            switch (p)
            {
                case "SERIAL": return 6;
                case "SMALLINT": return 1;
                case "INTEGER": return 2;
                case "DATE": return 7;

                case "FLOAT": return 3;
                case "SMALLFLOAT": return 4;


                default:  // probably not a great fallback but better than nothing..
                    return 0;
            }
                   
        }


        internal void SetWidget(ATTRIB thisAttribute, AubitDesktop.Xml.XMLForm.Matrix ma,  int row, int index, int column, int rows, int columns, string widget, string config, int id, string tabcol, string action, int attributeNo, string incl)
        {
            //string[] configArr;

            //System.Resources.ResourceManager rm = new System.Resources.ResourceManager("ResourceClient.Images", System.Reflection.Assembly.GetExecutingAssembly());
            attrib = thisAttribute;
            _row = row;
            _column = column;
            _rows = rows;
            _columns = columns;
            _Widget = widget;
            _Config = config;
            _id = id;
            _comment = "";
            if (thisAttribute.ATTRIB_COMMENTS != null)
            {
                
                _comment = thisAttribute.ATTRIB_COMMENTS.Text;
            }

            includeValues = null;

            this._onUIEvent = null;
            this._fieldValidationFailed = null;
            this._afterFieldID = "";
            this._onActionID = "";
            this._beforeFieldID = "";
            if (_Config == null) _Config = "";

            configSettings = FGLWidgetConfigSettings.GetSettings(_Config);

            //if (thisAttribute)

            string[] f = tabcol.Split('.');
            if (f.Length == 1)
            {
                _TableName = "";
                _ColumnName = f[0];
            }
            else
            {
                _TableName = f[0];
                _ColumnName = f[1];
            }

            _Action = action;
            _attributeNo = attributeNo;

            if (incl != null)
            {
                if (incl.Length > 0)
                {

                    this.includeValues = new List<string>();
                    string[] incvals;
                    incvals = incl.Split('\n');
                    for (int a = 0; a < incvals.Length; a++)
                    {
                        if (incvals[a].Contains("|"))
                        {
                            this.includeValues.AddRange(incvals[a].Split('|'));
                        }
                        else
                        {
                            this.includeValues.Add(incvals[a]);
                        }
                    }
                }

            }


        }



        internal ATTRIB createAttribForWidget(AubitDesktop.Xml.XMLForm.FormField ff)
        {
            ATTRIB a = new ATTRIB();


            if (ff.noEntry != null) { a.ATTRIB_NOENTRY = new ATTRIB_NOENTRY(); }
            if (ff.required != null) { a.ATTRIB_REQUIRED = new ATTRIB_REQUIRED(); }

            if (ff.hidden != null)
            {
                a.ATTRIB_INVISIBLE = new ATTRIB_INVISIBLE();
            }
            if (ff.sqlType != null)
            {
                a.DATATYPE = decode_datatype(ff.sqlType).ToString();
                a.DATATYPE_SIZE = decode_datatype_size(ff.sqlType).ToString();
            }
            a.ATTRIBUTE_NO = ff.fieldId;



            if (ff.defaultValue != null)
            {
                a.ATTRIB_DEFAULT = new ATTRIB_DEFAULT();
                a.ATTRIB_DEFAULT.Text = ff.defaultValue;
            }

            return a;
        }


        internal bool validateField() 
        {
            bool ign = false;

            
            

            if (this._ContextType == FGLContextType.ContextInput || this._ContextType == FGLContextType.ContextInputArray)
            {
                #region REQUIRED CHECK
                if (this.Required)
                {
                    if (Text.Length == 0)
                    {
                        if (this.fieldValidationFailed != null)
                        {
                            this.fieldValidationFailed(this, "FIELD_REQD_MSG", out ign);
                        }
                        if (!ign)
                        {
                            return false;
                        }
                    }

                }
                #endregion
                #region Datatype Check
                if (!FGLUtils.IsValidForType(this.datatype, Text, this.format))
                {
                    if (this.fieldValidationFailed != null)
                    {
                        this.fieldValidationFailed(this, "FIELD_ERROR_MSG", out ign);
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
                        if (s.Contains(":"))
                        {
                            string l, r;
                            string[] arr;
                            arr = s.Split(':');
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
                                break;
                            }
                            if (s == this.Text)
                            {
                                ok = true;
                                break;
                            }
                        }
                    }

                    ign = false;
                    if (!ok)
                    {
                        this.fieldValidationFailed(this, "FIELD_INCL_MSG", out ign);


                        if (!ign)
                        {
                            return false;
                        }
                    }
                }
                #endregion
            }


            
            return true;
        }

        private void clrErrorTextBeforeFieldValidation()
        {
            bool ign = false;
            if (this.fieldValidationFailed != null)
            {
                this.fieldValidationFailed(this, "CLEAR", out ign);
            }
        }


        internal void t_Click(object sender, EventArgs e)
        {
            
            this.clrErrorTextBeforeFieldValidation();
            if (this.onActionID != "" && this.onUIEvent != null && _ContextType != FGLContextType.ContextNone)
            {
                this.onUIEvent(this, this.onActionID, "",null);
            }
            
        }


        internal void t_Validating(object sender, System.ComponentModel.CancelEventArgs e)
        {         
            if (!validateField())
            {
                e.Cancel = true;
            }
            else
            {
                e.Cancel = false;
            }
        }



       

        internal void t_GotFocus(object sender, EventArgs e)
        {

            
            /*
            if (this.beforeFieldID != "" && this.onUIEvent != null && _ContextType != FGLContextType.ContextNone)
            {
                this.onUIEvent(this, this.beforeFieldID, "",null);
            }
            */

            if (this.onGotFocus != null)
            {
                this.onGotFocus(this, this.comment);
            }

            gotFocus();

        }

        internal void t_LostFocus(object sender, EventArgs e)
        {
            /*
            Console.WriteLine("Lost focus");
            if (!validateField(sender))
            {
                ((Control)sender).Focus();
            }
            else
            {
                if (this.afterFieldID != "" && this.onUIEvent != null && _ContextType != FGLContextType.ContextNone)
                {
                    this.onUIEvent(this, this.afterFieldID, "",null);
                }
            }
            */

        }

        public int attributeNo
        {
            get
            {
                return _attributeNo;
            }

        }

        public string TableName
        {
            get
            {
                return _TableName;
            }
        }

        public string ColumnName
        {
            get
            {
                return _ColumnName;
            }
        }

        public string Action
        {
            get
            {
                return _Action;
            }
        }

        public string Config
        {
            get
            {
                return _Config;
            }
        }

        public string Widget
        {
            get
            {
                return _Widget;
            }

        }




        public void SizeControl(AubitDesktop.Xml.XMLForm.Matrix ma, int index, Control c)
        {
           // int coffset = 0;
            c.Height = GuiLayout.get_gui_h(_rows);
            if (_columns > 2 || true)
            {
                c.Width = GuiLayout.get_gui_w(_columns + 1);
              //  coffset = 1;
            }
            else
            {
                c.Width = GuiLayout.get_gui_w(3);
            }

            if (configSettings.ContainsKey("HEIGHT"))
            {
                c.Height = GuiLayout.get_gui_h(Convert.ToInt32((string)configSettings["HEIGHT"]));
            }
            if (configSettings.ContainsKey("WIDTH"))
            {
                c.Width = GuiLayout.get_gui_w(Convert.ToInt32((string)configSettings["WIDTH"]));
            }


            c.Visible = true;

            c.Location = GuiLayout.getPoint(ma, index, _column , _row);
        }


        public bool FieldTextChanged
        {
            get
            {
                return _FieldTextChanged;
            }
            set
            {
                _FieldTextChanged = value;
            }
        }

        public string defaultValue
        {
            get
            {
                if (attrib.ATTRIB_DEFAULT != null)
                {
                    return attrib.ATTRIB_DEFAULT.Text;
                }
                else
                {
                    return "";
                }
            }
        }


        internal virtual void setKeyList(List<ONKEY_EVENT> keyList)
        {
            
        }
    }

}
