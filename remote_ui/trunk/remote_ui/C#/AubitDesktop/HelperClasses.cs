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

    public enum FGLContextType
    {
        ContextNone,
        ContextInput,
        ContextConstruct,
        ContextDisplayArray,
        ContextInputArray,
        ContextMenu,
        ContextPrompt
    };

    class GuiLayout
    {

        public static int get_gui_y(int y)
        {
            return (y * Program.AppSettings.yscale) + 5;
        }

        public static int get_gui_x(int x)
        {
            return (x * Program.AppSettings.xscale) + 5;
        }

        public static int get_gui_h(int p)
        {
            return (p * Program.AppSettings.yscale);
        }

        internal static int get_gui_w(int x)
        {
            return (x * Program.AppSettings.xscale);
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




    /*
 
    // We'll abstract all our widget implementation behind an interface
    public interface IFGLField
    {

        UIFieldValidationHandler fieldValidationFailed
        {
            get;
            set;
        }

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

        UIGotFocusHandler onGotFocus
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


        FGLContextType ContextType
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
     * */

    
    class FGLScreenRecordAttributes
    {
        public int AttributeNo;
        public string Name;

        public FGLScreenRecordAttributes(ATTRIBUTE a)
        {
            this.AttributeNo = Convert.ToInt32(a.ATTRIBUTE_NO);
            this.Name = a.NAME;
        }


        public FGLScreenRecordAttributes(AubitDesktop.Xml.XMLForm.Link a)
        {
            this.AttributeNo = Convert.ToInt32(a.fieldIdRef);
            this.Name = a.colName;
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


        internal void setPrompt(Control p,int promptLineFromOptions)
        {
            // Try seeing if we have a specific prompt line...
            int promptLine = windows[0].prompt_line;
            if ( promptLine== 255)
            {
               promptLine = promptLineFromOptions;
            }
            p.Top = GuiLayout.get_gui_y(promptLine);
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

        internal void SetContext(FGLContextType contextType)
        {
            windows[0].SetContext(contextType);
        }

        internal void SetContext(FGLContextType contextType, List<FGLWidget> pfields, UIContext currContext)
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
        public FGLWidget fglField;
        public string shortName;
        public string fullName;
        public string useName;
        public int subscript;  

        public FGLFoundField(string useName, string shortName,string fullName, FGLWidget f,int subscript)
        {
            this.fglField = f;
            
            this.shortName = shortName;
            this.fullName = fullName;
            this.useName = useName;
            this.subscript = subscript;
            Console.WriteLine(fullName + "[" + subscript + "]");
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
        internal int error_line;
        internal int prompt_line;
        internal int menu_line;
        internal int comment_line;
        internal int message_line;
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


        internal void SetContext(FGLContextType contextType)
        {
            CurrentForm.SetContext(contextType);
        }

        internal void SetContext(FGLContextType contextType, List<FGLWidget> pfields, UIContext currContext)
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


        internal static System.Drawing.Image getImageFromName(string name)
        {
            System.Drawing.Image i = (System.Drawing.Image)resourceInterface.getObject(name.ToLower());
            if (i != null)
            {
                return i;
            }
            else
            {
                try
                {
                    i = new System.Drawing.Bitmap(name);
                } catch (Exception) {
                }
                if (i!=null) return i;
                return (System.Drawing.Image)resourceInterface.getObject("attention");
            }
        }

        internal static string decodeKeycode(bool controlkey, bool shiftkey, bool altkey, Keys keyCode)
        {
            if (shiftkey == false && altkey == false && controlkey == false)
            {
                switch (keyCode)
                {


                    case Keys.Escape:
                        return "Escape"; // Should be detected from the options...


                    case Keys.Down:
                        return "Down";
                    case Keys.Up:
                        return "Up";
                    case Keys.Left:
                        return "Left";
                    case Keys.Right:
                        return "Right";
                    case Keys.PageUp:
                        return "PgUp";
                    case Keys.PageDown:
                        return "PgDown";
                    case Keys.Insert:
                        return "Insert";
                    case Keys.Delete:
                        return "Delete";
                    case Keys.F1:
                        return "F1";
                    case Keys.F2:
                        return "F2";
                    case Keys.F3:
                        return "F3";
                    case Keys.F4:
                        return "F4";
                    case Keys.F5:
                        return "F5";
                    case Keys.F6:
                        return "F6";
                    case Keys.F7:
                        return "F7";
                    case Keys.F8:
                        return "F8";
                    case Keys.F9:
                        return "F9";
                    case Keys.F10:
                        return "F10";
                    case Keys.F11:
                        return "F11";
                    case Keys.F12:
                        return "F12";
                    case Keys.F13:
                        return "F13";
                    case Keys.F14:
                        return "F14";
                    case Keys.F15:
                        return "F15";
                    case Keys.F16:
                        return "F16";
                    case Keys.F17:
                        return "F17";
                    case Keys.F18:
                        return "F18";
                    case Keys.F19:
                        return "F19";
                    case Keys.F20:
                        return "F20";
                    case Keys.F21:
                        return "F21";
                    case Keys.F22:
                        return "F22";
                    case Keys.F23:
                        return "F23";
                    case Keys.F24:
                        return "F24";

                }

                return keyCode.ToString();
            }

            if (shiftkey == false && altkey == false && controlkey == true)
            {
                switch (keyCode)
                {
                    case Keys.A:
                        return "Control-A";
                    case Keys.B:
                        return "Control-B";
                    case Keys.C:
                        return "Control-C";
                    case Keys.D:
                        return "Control-D";
                    case Keys.E:
                        return "Control-E";
                    case Keys.F:
                        return "Control-F";
                    case Keys.G:
                        return "Control-G";
                    case Keys.H:
                        return "Control-H";
                    case Keys.I:
                        return "Control-I";
                    case Keys.J:
                        return "Control-J";
                    case Keys.K:
                        return "Control-K";
                    case Keys.L:
                        return "Control-L";
                    case Keys.M:
                        return "Control-M";
                    case Keys.N:
                        return "Control-N";
                    case Keys.O:
                        return "Control-O";
                    case Keys.P:
                        return "Control-P";
                    case Keys.Q:
                        return "Control-Q";
                    case Keys.R:
                        return "Control-R";
                    case Keys.S:
                        return "Control-S";
                    case Keys.T:
                        return "Control-T";
                    case Keys.U:
                        return "Control-U";
                    case Keys.V:
                        return "Control-V";
                    case Keys.W:
                        return "Control-W";
                    case Keys.X:
                        return "Control-X";
                    case Keys.Y:
                        return "Control-Y";
                    case Keys.Z:
                        return "Control-Z";

                }
            }
            return null;
        }


        public static string getKeyCodeFromKeyName(string keyname)
        {
            string txt = keyname;

            switch (keyname.ToUpper())
            {
                case "F1": txt = "3000"; break;
                case "F2": txt = "3001"; break;
                case "F3": txt = "3002"; break;
                case "F4": txt = "3003"; break;
                case "F5": txt = "3004"; break;
                case "F6": txt = "3005"; break;
                case "F7": txt = "3006"; break;
                case "F8": txt = "3007"; break;
                case "F9": txt = "3008"; break;
                case "F10": txt = "3009"; break;
                case "F11": txt = "3010"; break;
                case "F12": txt = "3011"; break;
                case "F13": txt = "3012"; break;
                case "F14": txt = "3013"; break;
                case "F15": txt = "3014"; break;
                case "F16": txt = "3015"; break;
                case "F17": txt = "3016"; break;
                case "F18": txt = "3017"; break;
                case "F19": txt = "3018"; break;
                case "F20": txt = "3019"; break;
                case "F21": txt = "F21"; break;
                case "F22": txt = "F22"; break;
                case "F23": txt = "F23"; break;
                case "F24": txt = "F24"; break;
                case "F25": txt = "F25"; break;
                case "F26": txt = "F26"; break;
                case "F27": txt = "F27"; break;
                case "F28": txt = "F28"; break;
                case "F29": txt = "F29"; break;
                case "F30": txt = "F30"; break;
                case "F31": txt = "F31"; break;
                case "F32": txt = "F32"; break;
                case "UP": txt = "2000"; break;
                case "DOWN": txt = "2001"; break;
                case "LEFT": txt = "2002"; break;
                case "RIGHT": txt = "2003"; break;
                case "HELP": txt = "2008"; break;
                case "PREVPAGE": txt = "2006"; break;
                case "ACCEPT": txt = "2016"; break;
                case "ESC": txt = "27"; break;
                case "ESCAPE": txt = "27"; break;

                case "CONTROL-A": txt = "1"; break;
                case "CONTROL-B": txt = "2"; break;
                case "CONTROL-C": txt = "3"; break;
                case "CONTROL-D": txt = "4"; break;
                case "CONTROL-E": txt = "5"; break;
                case "CONTROL-F": txt = "6"; break;
                case "CONTROL-G": txt = "7"; break;
                case "CONTROL-H": txt = "8"; break;
                case "CONTROL-I": txt = "9"; break;
                case "CONTROL-J": txt = "10"; break;
                case "CONTROL-K": txt = "11"; break;
                case "CONTROL-L": txt = "12"; break;
                case "CONTROL-M": txt = "13"; break;
                case "CONTROL-N": txt = "14"; break;
                case "CONTROL-O": txt = "15"; break;
                case "CONTROL-P": txt = "16"; break;
                case "CONTROL-Q": txt = "17"; break;
                case "CONTROL-R": txt = "18"; break;
                case "CONTROL-S": txt = "19"; break;
                case "CONTROL-T": txt = "20"; break;
                case "CONTROL-U": txt = "21"; break;
                case "CONTROL-V": txt = "22"; break;
                case "CONTROL-W": txt = "23"; break;
                case "CONTROL-X": txt = "24"; break;
                case "CONTROL-Y": txt = "25"; break;
                case "CONTROL-Z": txt = "26"; break;
            }
            return txt;
        }


        public static string getKeyNameFromFGLKeyCode(string key)
        {
            Int32 keycode;
            string txt = key;
            if (Int32.TryParse(key, out keycode))
            {
                if (keycode < 127 && keycode > ' ')
                {
                    char c;
                    c = Convert.ToChar(keycode);
                    return c.ToString();
                }
            }
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

                    static public Hashtable splitIntoConfig(string Line)
        {
            Hashtable Config = new Hashtable();
            return splitIntoConfig(Config, Line);
        }

        public static Hashtable splitIntoConfig(Hashtable Config, string Line)
        {
            string[] l = Line.Split(';');
            foreach (string s in l)
            {       
                string[] v = s.Split('=');
                Config[v[0].ToUpper()] = v[1];
            }
            return Config;
        }


        public static void Log(string s)
        {
            if (false)
            {
                Console.WriteLine(s);
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


        static public bool IsValidForType(FGLDataTypes datatype, string value, string format)
        {
            if (value.Trim() == "") return true;
            
            switch (datatype)
            {

                case FGLDataTypes.DTYPE_TEXT:
                case FGLDataTypes.DTYPE_NULL:
                case FGLDataTypes.DTYPE_BYTE:
                case FGLDataTypes.DTYPE_VCHAR:
                case FGLDataTypes.DTYPE_NCHAR:
                case FGLDataTypes.DTYPE_CHAR:
                    return true;


                case FGLDataTypes.DTYPE_INTERVAL:
                case FGLDataTypes.DTYPE_DTIME:
                    return true;


                case FGLDataTypes.DTYPE_DECIMAL:
                case FGLDataTypes.DTYPE_FLOAT:
                case FGLDataTypes.DTYPE_SMFLOAT:
                case FGLDataTypes.DTYPE_MONEY:
                    {
                        Double d;
                        if (Double.TryParse(value, out d))
                        {
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                    }

                case FGLUtils.FGLDataTypes.DTYPE_DATE:
                    {
                        DateTime dt;
                        bool ok = false;
                        try
                        {
                            if (format != null)
                            {
                                dt = FGLUtils.getDate(value, FGLUtils.fglFormatToDotNetFormat(format));
                                ok = true;
                            }
                            else
                            {
                                dt = FGLUtils.getDate(value);
                                ok = true;
                            }
                        }
                        catch { }

                        if (ok)
                        {
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                    }
                   

                case FGLDataTypes.DTYPE_SERIAL:
                case FGLUtils.FGLDataTypes.DTYPE_INT:
                    {
                        Int32 n;
                        if (Int32.TryParse(value, out n))
                        {
                            return true;
                        }
                        else
                        {
                            return  false;
                        }
                    }

                case FGLDataTypes.DTYPE_SERIAL8:
                case FGLDataTypes.DTYPE_INT8:
                    {
                        Int64 n;
                        if (Int64.TryParse(value, out n))
                        {
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                        
                    }


                case FGLUtils.FGLDataTypes.DTYPE_SMINT:
                    {
                        Int16 n;
                        if (Int16.TryParse(value, out n))
                        {
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                    }
             
                default:
                    throw new ApplicationException("Datatype field checking not handled for " + datatype.ToString());
            }
            
        }



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
