using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
using System.Windows.Forms;

namespace AubitDesktop
{
    public class FGLWidget : ContainerControl
    {
        int _attributeNo;
        string _TableName;
        string _ColumnName;
        string _Action;
        string _Config;
        string _Widget;
        string _comment;

        int _row;
        int _column;
        int _rows;
        int _columns;
        int _id;
        bool _FieldTextChanged;
        public Hashtable configSettings;
        ATTRIB attrib;
        


        private UIFieldValidationHandler _fieldValidationFailed;
        private UIEventHandler _onUIEvent;

        public string _afterFieldID;
        public string _beforeFieldID;
        public string _onActionID;

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

        public UIFieldValidationHandler fieldValidationFailed
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


        public List<string> includeValues;

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


        internal void SetWidget(ATTRIB thisAttribute, int row, int column, int rows, int columns, string widget, string config, int id, string tabcol, string action, int attributeNo, string incl)
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
                    this.includeValues.AddRange(incl.Split('\n'));
                }

            }

            /*
            if (configSettings["INCLUDE"] != null)
            {
                MessageBox.Show("Here");
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

        public void SizeControl(Control c)
        {
            c.Height = GuiLayout.get_gui_h(_rows);
            if (_columns > 2)
            {
                c.Width = GuiLayout.get_gui_w(_columns + 1);
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
            c.Location = new System.Drawing.Point(GuiLayout.get_gui_x(_column - 1), GuiLayout.get_gui_y(_row));
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

    }

}
