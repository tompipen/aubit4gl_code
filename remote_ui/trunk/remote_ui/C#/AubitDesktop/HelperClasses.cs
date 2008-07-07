using System;
using System.Collections.Generic;
using System.Collections;
using System.Windows.Forms;
using System.Text;

namespace AubitDesktop
{
    class resourceInterface
    {
        static System.Resources.ResourceManager rm = null;
        public static object getObject(string name)
        {
            object obj = null;
            
            if (rm == null) rm = new System.Resources.ResourceManager("AubitDesktop.Properties.Resources", typeof( AubitDesktop.Properties.Settings).Assembly);
            try
            {
                obj = rm.GetObject(name);
            }
            catch
            {
                obj = null;
            }
            return obj;
        }
    }

    class GuiLayout
    {

        public static int get_gui_y(int y)
        {
            return (y * 22) + 5;
        }

        public static int get_gui_x(int x)
        {
            return (x * 9) + 5;
        }

        public static int get_gui_h(int p)
        {
            return (p * 22);
        }

        internal static int get_gui_w(int x)
        {
            return (x * 9);
        }

    }

    class FGLKeyEvent
    {
        string KeyId;
        public int ID;

        public FGLKeyEvent(string Key, int ID)
        {
            this.KeyId = Key;
            this.ID = ID;
        }

        public bool isKey(string key)
        {
            // @todo  Add tests for numeric Key IDs..
            if (this.KeyId == key) return true;
            return false;
        }
    }

    // We'll abstract all our widget implementation behind an interface
    public interface IFGLField
    {

        string ColumnName
        {
            get;
        }
        string format
        {
            get;
        }
        FGLUtils.FGLDataTypes datatype
        {
            get;
        }
        string TableName
        {
            get;
        }
        string Action
        {
            get;
        }
        int attributeNo
        {
            get;
        }
        string defaultValue
        {
            get;
        }

        string afterFieldID
        {
            get;
            set;
        }

        string beforeFieldID
        {
            get;
            set;
        }

        string onActionID
        {
            get;
            set;
        }

        UIEventHandler onUIEvent
        {
            get;
            set;
        }

        bool hasFocus
        {
            get;
        }

        /* FGLWidget WidgetDetails
        {
            get;
        }
         * */
        
        string ContextType
        {  // The current ContextType - a field may appear differently if its used in a construct or input..
            set;
        }


        string Text // The current fields value
        {
            get;
            set;
        }


        Control WindowsWidget
        {
            get;
        }

        bool Enabled
        {
            get;
            set;
        }

        string comment
        {
            get;
        }

        void setFocus();

        int tabIndex
        {
            set;
        }


        void setToolTip(ToolTip tooltips, string p);
    }

    
    class FGLScreenRecordAttributes
    {
        public int AttributeNo;
        public string Name;

        public FGLScreenRecordAttributes(ATTRIBUTE a)
        {
            this.AttributeNo = Convert.ToInt32(a.ATTRIBUTE_NO);
            this.Name = a.NAME;
        }

        FGLScreenRecordAttributes()
        {

        }

    }

    class FGLWidgetConfigSettings
    {



        public static Hashtable GetSettings(string _Config)
        {
            string[] configArr;
            Hashtable configSettings;
            configArr = _Config.Split(';');
            configSettings = new Hashtable();

            for (int a = 0; a < configArr.Length; a++)
            {
                string s;
                s = configArr[a];
                string[] lr = s.Split('=');
                if (lr.Length == 1)
                {
                    configSettings[lr[0].ToUpper()] = "Y";
                }

                if (lr.Length == 2)
                {
                    string s2;
                    s2 = lr[1];
                    if (s2.Substring(0, 1) == "'" || s2.Substring(0, 1) == "\"")
                    {
                        s2 = s2.Substring(1, s2.Length - 2);
                    }
                    configSettings[lr[0].ToUpper()] = s2;

                }
            }
            return configSettings;
        }

    }

    class FGLOpenedForms
    {
        Hashtable OpenForms = new Hashtable();

        public void addForm(string name, FGLForm f)
        {
            OpenForms.Add(name, f);
        }

        public FGLForm getForm(string name)
        {
            FGLForm frm;
            frm = (FGLForm)OpenForms[name];
            return frm;
        }

        public void removeForm(string name)
        {
            OpenForms.Remove(name);
        }

    }

    class FGLWindowStack
    {
        List<FGLWindow> windows;
        Control ParentControl;
        int _minWidth;
        int _minHeight;

        private void ensureHeightAndWidth()
        {
            int min_w = 0;
            int min_h = 0;
            foreach (FGLWindow f in windows)
            {
                int w, h;
                w = f.x + f.CharWidth;
                h = f.y + f.LineHeight;
                if (f.border) { w++; h++; }
                if (w > min_w) min_w = w;
                if (h > min_h) min_h = h;
            }
            _minHeight = min_h;
            _minWidth = min_w;

        }


        public int minimumScreenWidth
        {
            get
            {
                ensureHeightAndWidth();
                return _minWidth;
            }
        }

        public int minimumScreenHeight
        {
            get
            {
                ensureHeightAndWidth();
                return _minHeight;
            }
        }

        public FGLWindowStack(Control Parent)
        {
            ParentControl = Parent;
            windows = new List<FGLWindow>();
        }

        public void DisplayTo(DISPLAYTO d)
        {
            if (!windows[0].hasForm) // Top level window...
            {
                MessageBox.Show("No form has been display in the window"); return;
            }
            windows[0].DisplayTo(d);

        }
        /*
        public void doInput(INPUT i)
        {
            if (!windows[0].hasForm) // Top level window...
            {
                MessageBox.Show("No form has been display in the window"); return;
            }
            windows[0].doInput(i);
        }
         * */


        /// <summary>
        ///  Sets the form on the current window
        /// </summary>
        /// <param name="f">The form to be displayed</param>
        public void setForm(FGLForm f)
        {
            windows[0].setForm(f, true);
        }


        internal void setPrompt(Control p)
        {
            p.Top = 15;
            p.Left = 5;
            windows[0].WindowWidget.Controls.Add(p);
            p.Visible = true;
            p.BringToFront();
        }



        public void PushWindow(FGLWindow w)
        {
            // Look for our exact object
            if (windows.Contains(w))
            {
                windows.Remove(w);
                windows.Insert(0, w);
            }
            else
            {
                bool found = false;
                // Not found - look for our window name...
                foreach (FGLWindow wtest in windows)
                {
                    if (wtest.windowName.ToLower() == w.windowName.ToLower())
                    { // We've found it too..
                        windows.Remove(wtest);
                        windows.Insert(0, w);
                        found = true;
                    }
                }
                if (!found)
                {
                    windows.Insert(0, w);
                }
            }

            setZOrder();
        }


        public void setZOrder()
        {
            for (int a = 0; a < windows.Count; a++)
            {
                if (ParentControl.Controls.Contains(windows[a].WindowWidget))
                {
                    ParentControl.Controls.SetChildIndex(windows[a].WindowWidget, a);
                }
            }
        }

        public void ClearWindow(string windowName)
        {
            foreach (FGLWindow wtest in windows)
            {
                if (wtest.windowName.ToLower() == windowName.ToLower())
                {
                    if (wtest.hasForm)
                    {
                        wtest.RemoveForm();

                    }
                    return;
                }
            }
            MessageBox.Show("Window not found for ClearWindow");
        }

        public void MoveWindowToTop(string windowName)
        {
            // Not found - look for our window name...
            foreach (FGLWindow wtest in windows)
            {
                if (wtest.windowName.ToLower() == windowName.ToLower())
                {
                    // We've found it - remove it from where it was...
                    windows.Remove(wtest);


                    // Add it at the start
                    windows.Insert(0, wtest);
                    setZOrder();
                    return;
                }
            }
            // If we get to here - we've not found the window at all
            MessageBox.Show("Window " + windowName + " not found");
        }


        public void PopWindow(string windowName)
        {

            // Not found - look for our window name...
            foreach (FGLWindow wtest in windows)
            {
                if (wtest.windowName.ToLower() == windowName.ToLower())
                { // We've found it too..
                    windows.Remove(wtest);
                    if (wtest.isContainable)
                    {
                        ParentControl.Controls.Remove(wtest.WindowWidget);
                    }
                    setZOrder();
                    return;
                }
            }
            // If we get to here - we've not found the window at all
            MessageBox.Show("Window " + windowName + " not found");
        }


        public void PopWindow(FGLWindow w)
        {   // Look for our exact object
            if (windows.Contains(w))
            {
                windows.Remove(w);
                if (w.isContainable)
                {
                    ParentControl.Controls.Remove(w.WindowWidget);
                }
                setZOrder();
                return;
            }
            else
            {

                // Not found - look for our window name...
                foreach (FGLWindow wtest in windows)
                {
                    if (wtest.windowName.ToLower() == w.windowName.ToLower())
                    { // We've found it too..
                        windows.Remove(wtest);
                        if (wtest.isContainable)
                        {
                            ParentControl.Controls.Remove(wtest.WindowWidget);
                        }
                        setZOrder();
                        return;
                    }
                }
            }
            // If we get to here - we've not found the window at all
            MessageBox.Show("Window " + w.windowName + " not found");
        }

        internal void ClearPrompt(Control p)
        {
            windows[0].WindowWidget.Controls.Remove(p);

        }

        internal void SetContext(string contextType)
        {
            windows[0].SetContext(contextType);
        }

        internal void SetContext(string contextType, List<IFGLField> pfields, UIContext currContext)
        {
            windows[0].SetContext(contextType,pfields,  currContext);
        }

        internal List<FGLFoundField> FindFields(FIELD[] fieldlist)
        {
            return windows[0].FindFields(fieldlist);
        }

        internal List<FGLFoundField> FindFields(string[] fieldlist)
        {
            return windows[0].FindFields(fieldlist);
        }


        internal void setNextField(string NextField)
        {
             windows[0].setNextField(NextField);
        }

        internal List<FGLFoundField> FindAction(string actionName)
        {
            return windows[0].FindAction(actionName);
        }

        internal List<FGLFoundField> FindFieldArray(FIELD[] fieldlist)
        {
            return windows[0].FindFieldArray(fieldlist);
        }
    }

    public class FGLFoundField
    {
        public IFGLField fglField;
        public string shortName;
        public string fullName;
        public string useName;
        

        public FGLFoundField(string useName, string shortName,string fullName, IFGLField f)
        {
            this.fglField = f;
            
            this.shortName = shortName;
            this.fullName = fullName;
            this.useName = useName;
        }

        internal bool isField(string fieldName)
        {
            if (useName == fieldName) return true;
            if (fullName == fieldName) return true;
            if (shortName == fieldName) return true;
            return false;
        }

    };

    class FGLWindow
    {
        FGLForm CurrentForm;
        public string windowName;
        public int x;
        public int y;
        int attribute;
        string text;
        string style;
        public bool isModal;
        int error_line;
        int prompt_line;
        int menu_line;
        int comment_line;
        int message_line;
        public bool border;
        public int LineHeight;
        public int CharWidth;
        public bool isContainable;
        public Control WindowWidget;
        bool KeepFormOpenWhenWindowCloses;

        public bool hasForm
        {
            get
            {
                return (CurrentForm != null);
            }
        }


        public FGLWindow(string windowName)
        {
            // This should only be used for 'SCREEN' 
            if (windowName.ToLower() != "screen")
            {
                MessageBox.Show("FGLWindow(windowname) should only be called for 'SCREEN'");
                return;
            }
            this.windowName = windowName;
            this.x = 0;
            this.y = 0;
            this.attribute = 0;
            this.text = "";
            this.style = "";
            this.error_line = 255;
            this.prompt_line = 255;
            this.menu_line = 255;
            this.comment_line = 255;
            this.message_line = 255;
            this.border = false;
            this.isContainable = true;
            this.isModal = false;
            this.CurrentForm = null;
            this.LineHeight = 0;
            this.CharWidth = 0;
            Panel p = new Panel();
            p.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            //p.BackColor = Color.Aqua;
            WindowWidget = p;
            WindowWidget.Visible = true;

            WindowWidget.Top = 15;
            WindowWidget.Left = 5;
            sizeWindowToFill();
        }


        public FGLWindow(string windowName, int x, int y, int attribute, string text, string style, int error_line, int prompt_line, int menu_line, int comment_line, int message_line, bool border)
        {
            this.windowName = windowName;
            this.x = x;
            this.y = y;
            this.LineHeight = 0;
            this.CharWidth = 0;
            this.attribute = attribute;
            this.text = text;
            this.style = style;
            this.error_line = error_line;
            this.prompt_line = prompt_line;
            this.menu_line = menu_line;
            this.comment_line = comment_line;
            this.message_line = message_line;
            this.border = border;
            this.isContainable = true;
            this.isModal = false;
            this.CurrentForm = null;

            switch (style)
            {
                case "":
                case "NORMAL":
                    {
                        Panel p;
                        p = new Panel();
                        WindowWidget = p;
                        if (border)
                        {
                            p.BorderStyle = BorderStyle.Fixed3D;
                        }
                        p.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
                        WindowWidget.Visible = true;
                    }
                    break;

                case "GROUPBOX":
                    {
                        GroupBox g; // Group boxes are always bordered....
                        g = new GroupBox();
                        g.Text = text;
                        WindowWidget = g;
                        WindowWidget.Visible = true;
                        g.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
                    }
                    break;


                case "WINDOW":
                    {
                        Form frm;
                        frm = new Form();
                        frm.Text = text;
                        WindowWidget = frm;
                        frm.AutoSize = true;
                        frm.Width = 10;
                        frm.Height = 10;
                        frm.StartPosition = FormStartPosition.CenterParent;
                        frm.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
                        sizeWindowToFill();
                    }

                    WindowWidget.Visible = true;
                    isContainable = false;
                    break;


                case "MODALWINDOW":
                    {
                        Form frm;

                        frm = new Form();
                        frm.Visible = false;
                        frm.Text = text;
                        WindowWidget = frm;
                        frm.AutoSize = true;
                        frm.Width = 10;
                        frm.Height = 10;
                        frm.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
                        sizeWindowToFill();
                    }

                    isContainable = false;
                    isModal = true;
                    break;



                default:
                    MessageBox.Show("Unhandled window style");
                    break;
            }


            WindowWidget.Top = GuiLayout.get_gui_y(y);
            WindowWidget.Left = GuiLayout.get_gui_x(x);


        }

        public void DisplayTo(DISPLAYTO d)
        {
            this.CurrentForm.DisplayTo(d);
        }

        /*
        public void doInput(INPUT i)
        {
            this.CurrentForm.DoInput(i);
        }
         * */


        
        public void setForm(FGLForm f, bool KeepFormOpenWhenWindowCloses)
        {
            if (this.CurrentForm != null)
            {
                if (WindowWidget != null)
                {
                    WindowWidget.Controls.Clear();
                }
            }
            this.CurrentForm = f;
            if (this.LineHeight == 0)
            {
                this.LineHeight = f.maxline;
            }
            if (this.CharWidth == 0)
            {
                this.CharWidth = f.maxcol;
            }
       
                //WindowWidget.BackColor = Color.Aqua;
                WindowWidget.Controls.Add(f.control);
       
            this.KeepFormOpenWhenWindowCloses = KeepFormOpenWhenWindowCloses;
        }


        public void RemoveForm()
        {
            if (this.CurrentForm != null)
            {
                WindowWidget.Controls.Clear();
                this.CurrentForm.Dispose();
                this.CurrentForm = null;
            }
        }


        public void sizeWindow(int x, int y)
        {
            LineHeight = y;
            CharWidth = x;
            WindowWidget.Height = GuiLayout.get_gui_y(y);
            WindowWidget.Width = GuiLayout.get_gui_x(x);
        }

        public void sizeWindow(FGLForm f)
        {
            LineHeight = f.maxline;
            CharWidth = f.maxcol;

            if (isContainable)
            {
                WindowWidget.Height = GuiLayout.get_gui_y(f.maxline) + 20;
                WindowWidget.Width = GuiLayout.get_gui_x(f.maxcol) + 20;

            }
        }

        public void sizeWindowToFill()
        {
            WindowWidget.Dock = DockStyle.Fill;
        }


        internal void SetContext(string contextType)
        {
            CurrentForm.SetContext(contextType);
        }

        internal void SetContext(string contextType, List<IFGLField> pfields, UIContext currContext)
        {
            CurrentForm.SetContext(contextType, pfields);
        }

        internal List<FGLFoundField> FindFields(FIELD[] fieldlist)
        {
            return CurrentForm.FindFields(fieldlist);
        }

        internal List<FGLFoundField> FindFields(string[] fieldlist)
        {
            return CurrentForm.FindFields(fieldlist);
        }



        internal void setNextField(string NextField)
        {
            CurrentForm.setNextField(NextField);
        }

        internal List<FGLFoundField> FindAction(string actionName)
        {
            return CurrentForm.FindAction(actionName);
        }

        internal List<FGLFoundField> FindFieldArray(FIELD[] fieldlist)
        {
            return CurrentForm.FindFieldArray(fieldlist);
        }
    }



    public enum showMode
    {
        ShowAlways,
        ShowNever,
        ShowAuto

    };


    public static class FGLUtils
    {

        static string _dbdate="MDY4/";

        public static string DBDATE
        {
            get
            {
                return _dbdate;
            }
            set
            {
                _dbdate = value;
            }

           }

        public static char a4gl_convfmts_ui_decfmt_decsep
        {
            get
            {
                return '.';
            }
        }

        public static char a4gl_convfmts_ui_decfmt_thsep
        {
            get
            {
                return ',';
            }
        }
        

        public static string getKeyNameFromFGLKeyCode(string key)
        {
            string txt = key;

            switch (key)
            {
                case "3000": txt = "F1"; break;
                case "3001": txt = "F2"; break;
                case "3002": txt = "F3"; break;
                case "3003": txt = "F4"; break;
                case "3004": txt = "F5"; break;
                case "3005": txt = "F6"; break;
                case "3006": txt = "F7"; break;
                case "3007": txt = "F8"; break;
                case "3008": txt = "F9"; break;
                case "3009": txt = "F10"; break;
                case "3010": txt = "F11"; break;
                case "3011": txt = "F12"; break;
                case "3012": txt = "F13"; break;
                case "3013": txt = "F14"; break;
                case "3014": txt = "F15"; break;
                case "3015": txt = "F16"; break;
                case "3016": txt = "F17"; break;
                case "3017": txt = "F18"; break;
                case "3018": txt = "F19"; break;
                case "3019": txt = "F20"; break;
                case "3020": txt = "F21"; break;
                case "3021": txt = "F22"; break;
                case "3022": txt = "F23"; break;
                case "3023": txt = "F24"; break;
                case "3024": txt = "F25"; break;
                case "3025": txt = "F26"; break;
                case "3026": txt = "F27"; break;
                case "3027": txt = "F28"; break;
                case "3028": txt = "F29"; break;
                case "3029": txt = "F30"; break;
                case "3030": txt = "F31"; break;
                case "3031": txt = "F32"; break;
                case "2000": txt = "Up"; break;
                case "2001": txt = "Down"; break;
                case "2002": txt = "Left"; break;
                case "2003": txt = "Right"; break;
                case "2008": txt = "Help"; break;
                case "2006": txt = "PrevPage"; break;
                case "2016": txt = "Accept"; break;
                case "27": txt = "Esc"; break;

                case "1": txt = "Control-A"; break;
                case "2": txt = "Control-B"; break;
                case "3": txt = "Control-C"; break;
                case "4": txt = "Control-D"; break;
                case "5": txt = "Control-E"; break;
                case "6": txt = "Control-F"; break;
                case "7": txt = "Control-G"; break;
                case "8": txt = "Control-H"; break;
                case "9": txt = "Control-I"; break;
                case "10": txt = "Control-J"; break;
                case "11": txt = "Control-K"; break;
                case "12": txt = "Control-L"; break;
                case "13": txt = "Control-M"; break;
                case "14": txt = "Control-N"; break;
                case "15": txt = "Control-O"; break;
                case "16": txt = "Control-P"; break;
                case "17": txt = "Control-Q"; break;
                case "18": txt = "Control-R"; break;
                case "19": txt = "Control-S"; break;
                case "20": txt = "Control-T"; break;
                case "21": txt = "Control-U"; break;
                case "22": txt = "Control-V"; break;
                case "23": txt = "Control-W"; break;
                case "24": txt = "Control-X"; break;
                case "25": txt = "Control-Y"; break;
                case "26": txt = "Control-Z"; break;
            }
            return txt;
        }

        public static string DBDATEFormat_dotnet
        {
            get
            {
               

                switch (_dbdate)
                {
                    case "DMY4/":
                        return "dd/MM/yyyy";
                    case "DMY":
                        return "dd/MM/yyyy";
                    case "DMY2":
                        return "dd/MM/yy";
                    case "DMY2/":
                        return "dd/MM/yy";

                    case "MDY4/":
                        return "MM/dd/yyyy";
                    case "MDY4":
                        return "MM/dd/yyyy";
                    case "MDY2":
                        return "MM/dd/yy";
                    case "MDY2/":
                        return "MM/dd/yy";

                    default :
                        throw new ApplicationException("Unhandled 4GL DBDATE format");
                }
            }
        }


        public static string fglFormatToDotNetFormat(string s) 
        {
            switch (s)
            {
                case "dd/mm/yy": return "dd/MM/yy";
                case "dd/mm/yyyy": return "dd/MM/yyyy";
                case "mm/dd/yyyy": return "MM/dd/yyyy";
                case "mm/dd/yy": return "MM/dd/yy";
                default :
                    throw new ApplicationException("Unhandled 4GL date format");
            }

        }

        public static string DBDATEFormat_fgl
        {
            get
            {

                switch (_dbdate)
                {
                    case "DMY4/":
                        return "dd/mm/yyyy";
                    case "DMY":
                        return "dd/mm/yyyy";
                    case "DMY2":
                        return "dd/mm/yy";
                    case "DMY2/":
                        return "dd/mm/yy";

                    case "MDY4/":
                        return "mm/dd/yyyy";
                    case "MDY4":
                        return "mm/dd/yyyy";
                    case "MDY2":
                        return "mm/dd/yy";
                    case "MDY2/":
                        return "mm/dd/yy";

                    default :
                        throw new ApplicationException("Unhandled 4GL DBDATE format");
                }
            }
        }


        public enum FGLDataTypes
        {

            DTYPE_CHAR = 0,
            DTYPE_SMINT = 1,
            DTYPE_INT = 2,
            DTYPE_FLOAT = 3,
            DTYPE_SMFLOAT = 4,
            DTYPE_DECIMAL = 5,
            DTYPE_SERIAL = 6,
            DTYPE_DATE = 7,
            DTYPE_MONEY = 8,
            DTYPE_NULL = 9,
            DTYPE_DTIME = 10,
            DTYPE_BYTE = 11,
            DTYPE_TEXT = 12,
            DTYPE_VCHAR = 13,
            DTYPE_INTERVAL = 14,
            DTYPE_NCHAR = 15,
            DTYPE_INT8 = 17,
            DTYPE_SERIAL8 = 18

        };

        internal static DateTime getDate(string s) {
            DateTime t;
            string[] arr_mdy;
            string sep="";
            arr_mdy = null;

            if (s.Contains("/"))
            {
                arr_mdy = s.Split('/');
                sep="/";
            }
if (s.Contains("-"))
            {
                arr_mdy = s.Split('-');
                sep="-";
            }
           
                if (arr_mdy[0].Length == 1) arr_mdy[0] = "0" + arr_mdy[0];
                if (arr_mdy[1].Length == 1) arr_mdy[1] = "0" + arr_mdy[1];
                if (FGLUtils.DBDATEFormat_dotnet.Contains("yyyy"))
                {
                    if (arr_mdy[2].Length == 2)
                    {
                        if (Convert.ToInt32(arr_mdy[2]) > 50)
                        {
                            arr_mdy[2] = "19" + arr_mdy[2];
                        }
                        else
                        {
                            arr_mdy[2] = "20" + arr_mdy[2];
                        }
                    }
                }
                if (arr_mdy!=null)
                {
                    s = arr_mdy[0] + sep + arr_mdy[1] + sep + arr_mdy[2];
                }

            t = DateTime.ParseExact(s, FGLUtils.DBDATEFormat_dotnet, null);
            return t;
        }

        internal static DateTime getDate(string s,string dotnetformat)
        {
            DateTime t;
            t = DateTime.ParseExact(s, dotnetformat, null);
            return t;
        }

        internal static bool compare_range(string p, string l, string r, FGLDataTypes datatype, int datatype_length,string fieldsFormat)
        {
            switch (datatype)
            {
                case FGLDataTypes.DTYPE_CHAR:
                case FGLDataTypes.DTYPE_VCHAR:
                case FGLDataTypes.DTYPE_TEXT:
                    return (p.CompareTo(l) >= 0 && p.CompareTo(r) <= 0);
                    

                case FGLDataTypes.DTYPE_INT:
                case FGLDataTypes.DTYPE_SMINT:
                case FGLDataTypes.DTYPE_SERIAL:
                    return (Convert.ToInt32(p) >= Convert.ToInt32(l) && Convert.ToInt32(p) <= Convert.ToInt32(r));

                case FGLDataTypes.DTYPE_SMFLOAT:
                case FGLDataTypes.DTYPE_FLOAT:
                    return (Convert.ToDouble(p) >= Convert.ToDouble(l) && Convert.ToDouble(p) <= Convert.ToDouble(r));


                case FGLDataTypes.DTYPE_DTIME:
                    return (Convert.ToDateTime(p) >= Convert.ToDateTime(l) && Convert.ToDateTime(p) <= Convert.ToDateTime(r));

                case FGLDataTypes.DTYPE_DATE:
                    DateTime ld, rd, pd;
                    
                    if (fieldsFormat == null) fieldsFormat = DBDATEFormat_fgl;
                    ld=FGLUtils.getDate(l, FGLUtils.fglFormatToDotNetFormat(fieldsFormat));
                    rd = FGLUtils.getDate(r, FGLUtils.fglFormatToDotNetFormat(fieldsFormat));
                    pd = FGLUtils.getDate(p, FGLUtils.fglFormatToDotNetFormat(fieldsFormat));
                    return (pd >= ld && pd <= rd);

                default :
                    throw new ApplicationException("Invalid Datatype: " +datatype);
            }
        }
    }
    
}
