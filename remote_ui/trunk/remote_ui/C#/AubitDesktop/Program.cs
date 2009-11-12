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

namespace AubitDesktop
{
    static class Program
    {
        //static public mainfrm frm;
        static public mainfrm frmMain;
        static public AubitDesktop.Xml.Settings AppSettings;
        static internal frmConsole myConsole;
        static string AppSettingsFile;

        static public System.Text.Encoding remoteEncoding;

        static public string getLocalisedString(byte[] buffer,int readBytes)
        {
            try
            {
               string  s=remoteEncoding.GetString(buffer, 0, readBytes);
                return s;
            }
            catch (Exception e)
            {
                MessageBox.Show(e.Message);
            }
            return "";
        }

        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main(string[] args)
        {
            bool AllowEdit;
            string Autorun;
            string port;
            bool ListenMode = false;
            bool minimised = false;
            
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Control.CheckForIllegalCrossThreadCalls = false;
            AppSettings = null;
            AppSettingsFile=Application.UserAppDataPath+"\\AubitSettings.xml";
                
            
            // Read the XML file.
            if (System.IO.File.Exists(AppSettingsFile))
            {
                LoadSettings(AppSettingsFile);
            }
            else
            {
                DefaultSettings();
            }

            AllowEdit = AppSettings.AllowEdit;
            Autorun = AppSettings.AutoRun;
            port = AppSettings.Port;
            ListenMode = AppSettings.ListenMode;
            minimised = AppSettings.StartMinimized;
            myConsole = new frmConsole();
            myConsole.Visible = false;

            if (Program.AppSettings.interruptKey == null)
            {
                Program.AppSettings.interruptKey = "Control-C";
            }
            else
            {
                if (Program.AppSettings.interruptKey.Trim(). Length == 0)
                {
                    Program.AppSettings.interruptKey = "Control-C";
                }
            }

            for (int a = 0; a < args.Length; a++)
            {

                if (args[a] == "-a")
                {
                    AllowEdit = true;
                }

                if (args[a] == "-L")
                {
                    ListenMode = true;
                }

                if (args[a] == "-l")
                {
                    ListenMode = false;
                }

                if (args[a] == "-S")
                {
                    if (a + 1 < args.Length)
                    {
                        Autorun = args[a + 1];
                        a = a + 1;
                    }
                }

                if (args[a] == "-p")
                {
                    if (a + 1 < args.Length)
                    {
                        port = args[a + 1];
                        a = a + 1;
                    }
                }

                if (args[a] == "-M")
                {
                    minimised = true;
                }
            }

            if (Program.AppSettings.defaultEncoding==null)
            {
                Program.AppSettings.defaultEncoding = "ISO8859-1";
                Program.SaveSettings();
            }

            if (Program.AppSettings.defaultEncoding.Trim() == "")
            {
                Program.AppSettings.defaultEncoding = "ISO8859-1";
                Program.SaveSettings();
            }

            if (Program.AppSettings.defaultEncoding != "UTF8")
            {
                try
                {
                    remoteEncoding = System.Text.ASCIIEncoding.GetEncoding(Program.AppSettings.defaultEncoding);
                }
                catch (Exception e)
                {
                    remoteEncoding = System.Text.ASCIIEncoding.GetEncoding("UTF-8");
                }

            }


            
            frmMain = new mainfrm(AllowEdit, Autorun, port, minimised,ListenMode);
            if (frmMain!=null && !frmMain.IsDisposed)
            {
                    Application.Run(frmMain);
            }
        }

       

        public static void setWindowPosition(string windowtype, Form f)
        {
            AubitDesktop.Xml.WindowPosition wp;
            wp = getWindowPosition(windowtype);
            if (wp == null) return;
            f.Top = wp.y;
            f.Left = wp.x;
            f.Width = wp.w;
            f.Height = wp.h;
        }

        public static AubitDesktop.Xml.WindowPosition getWindowPosition(string key) {
            if (AppSettings.WindowPositions == null) return null;

            for (int a = 0; a < AppSettings.WindowPositions.Count; a++)
            {
                if (AppSettings.WindowPositions[a].windowName == key)
                {
                    return AppSettings.WindowPositions[a];
                }
            }
            return null;
        }

        public static void saveWindowPosition(string key, Form f)
        {
            saveWindowPosition(key, f.Left, f.Top, f.Width, f.Height);
        }


        public static void saveWindowPosition(string key, int x, int y, int w, int h)
        {
            AubitDesktop.Xml.WindowPosition wp;
            if (AppSettings.WindowPositions==null) {
                AppSettings.WindowPositions=new List<AubitDesktop.Xml.WindowPosition>();
            }
            for (int a=0;a<AppSettings.WindowPositions.Count;a++) {
                if (AppSettings.WindowPositions[a].windowName == key)
                {
                    AppSettings.WindowPositions[a].x = x;
                    AppSettings.WindowPositions[a].y = y;
                    AppSettings.WindowPositions[a].w = w;
                    AppSettings.WindowPositions[a].h = h;
                    return;
                }
            }
            // not found..
            wp = new AubitDesktop.Xml.WindowPosition();
            wp.x = x;
            wp.y = y;
            wp.w = w;
            wp.h = h;
            wp.windowName = key;
            AppSettings.WindowPositions.Add(wp);
        }

        private static void DefaultSettings()
        {
            string s;
            s = AubitDesktop.Properties.Resources.DefaultSettings;

            System.Xml.Serialization.XmlSerializer reader = new
            System.Xml.Serialization.XmlSerializer(typeof(AubitDesktop.Xml.Settings));
     
            System.IO.TextReader r = new System.IO.StringReader(s);
            AppSettings = (AubitDesktop.Xml.Settings)reader.Deserialize(r);

            /*
            AubitDesktop.Xml.Protocol[] protocols;

            protocols = new AubitDesktop.Xml.Protocol[1];
            protocols[0] = new AubitDesktop.Xml.Protocol();
            protocols[0].Code = "1";
            protocols[0].Command = "Internal";
            protocols[0].Name = "SSH";
            protocols[0].Description = "SSH description";


            AppSettings = new AubitDesktop.Xml.Settings();

            AppSettings.AllowEdit = true;
            AppSettings.AutoRun = null;
            AppSettings.ListenMode = true;
            AppSettings.Port = "1350";

            AppSettings.Protocols = protocols;
            AppSettings.Shortcuts = null;
            AppSettings.StartMinimized = false;
            AppSettings.Shortcuts = new List<AubitDesktop.Xml.Shortcut>();
             * */
            SaveSettings();
        }

        internal static void LoadSettings(string settingsFile)
        {
            //AppSettings = new AubitDesktop.Xml.Settings();
            System.Xml.Serialization.XmlSerializer reader = new
            System.Xml.Serialization.XmlSerializer(typeof(AubitDesktop.Xml.Settings));
            System.IO.StreamReader file =
                new System.IO.StreamReader(settingsFile);

            // Deserialize the content of the file into the settings...
            AppSettings = (AubitDesktop.Xml.Settings)reader.Deserialize(file);
            if (AppSettings.Shortcuts==null) {
                AppSettings.Shortcuts = new List<AubitDesktop.Xml.Shortcut>();
            }
            file.Close();
        }



        static internal bool isNumericDatatype(FGLUtils.FGLDataTypes n)
        {
            switch ( n)
            {
                case FGLUtils.FGLDataTypes.DTYPE_SMINT:
                case FGLUtils.FGLDataTypes.DTYPE_INT:
                case FGLUtils.FGLDataTypes.DTYPE_SERIAL:
                case FGLUtils.FGLDataTypes.DTYPE_FLOAT:
                case FGLUtils.FGLDataTypes.DTYPE_DATE:
                case FGLUtils.FGLDataTypes.DTYPE_SMFLOAT:
                case FGLUtils.FGLDataTypes.DTYPE_DECIMAL:
                case FGLUtils.FGLDataTypes.DTYPE_MONEY:
                    return true;
            }

            return false;
        }

        static internal void SaveSettings()
        {
            try
            {
                System.Xml.Serialization.XmlSerializer writer = new
                        System.Xml.Serialization.XmlSerializer(Program.AppSettings.GetType());

                System.IO.StreamWriter file =
                    new System.IO.StreamWriter(AppSettingsFile);

                // Serialize the content of the settings back into the XML file
                writer.Serialize(file, Program.AppSettings);
                file.Close();
            }
            catch (Exception e)
            {
                Program.Show("Unable to save settings : " + e.ToString());
            }
        }



        internal static void Show(string p)
        {
            MessageBox.Show(p);
        }

        internal static void Show(string p, string p_2)
        {
            MessageBox.Show(p, p_2);
        }

        internal static void Show(string p, string p_2, MessageBoxButtons messageBoxButtons, MessageBoxIcon messageBoxIcon)
        {
            MessageBox.Show(p, p_2, messageBoxButtons, messageBoxIcon);
        }

        internal static DialogResult Show(string p, string p_2, MessageBoxButtons messageBoxButtons)
        {
            return MessageBox.Show(p, p_2, messageBoxButtons);
        }
    }
}