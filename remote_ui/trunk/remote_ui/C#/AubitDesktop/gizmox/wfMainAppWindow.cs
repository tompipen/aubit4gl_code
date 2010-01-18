#region Using

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;

using Gizmox.WebGUI.Common;
using Gizmox.WebGUI.Forms;
using System.Xml.Serialization;
using System.IO;
using System.Web;
using ISupportTrack;

#endregion

namespace AubitDesktop
{
    public partial class frmMainAppWindow : Form
    {
        public UIContext currentContext = null;

        public  showMode showMenuBar;
        public showMode showToolbar;
        public showMode showApplicationLauncher;
        private event EventHandler EnvelopeReadyForConsumption;
        private bool updating;
        private List<FGLApplicationPanel> RunningApplications;
        AubitNetwork networkConnection;
        //frmWebLogin frm;
        private bool hasQuit=false;
        Goodbye gwin = null;
        private bool _amWaitingForEvent = false;

        private AubitDesktop.Xml.Authentication.Configuration appsConfig=null;

        private bool amWaitingForEvent
        {
            get
            {
                return _amWaitingForEvent;
            }
            set
            {
                log("amWaitingForEvent set to " + value);
                _amWaitingForEvent = value;
            }
        }


        static public void log(string s)
        {
            StreamWriter sw;

            try
            {

                sw = File.AppendText("/tmp/run.log");
                sw.WriteLine("Log:" + s);
                sw.Flush();
                sw.Close();
            }
            catch (Exception) { }       
        }

        public string LineDisplayText
        {
            get
            {
                return sbLineDisplayText.Text;
            }
            set
            {
                sbLineDisplayText.Text = value;
            }
        }

        public string MessageText
        {
            get
            {
                return sbMessageText.Text;
            }
            set
            {
                sbMessageText.Text = value;
            }
        }


        public string ErrorText
        {
            get
            {
                return sbErrorText.Text;
            }
            set
            {
                sbErrorText.Text = value;
            }
        }

        public string CommentText
        {
            get
            {
                return sbCommentText.Text;
            }
            set
            {
                sbCommentText.Text = value;
            }
        }

        public frmMainAppWindow()
        {
            InitializeComponent();
        }

        internal void SendString(string TriggeredText, bool callSetWaitCursor)
        {
            

            string finalString;
            if (callSetWaitCursor) { setWaitCursor(); }

            if (Program.AppSettings.defaultEncoding.Trim() == "")
            {
                Program.AppSettings.defaultEncoding = "ISO8859-1";
                Program.SaveSettings();
            }

            finalString = TriggeredText;
            try
            {
                if (Program.AppSettings.defaultEncoding != "UTF8")
                {
                    Encoding enc = ASCIIEncoding.GetEncoding(Program.AppSettings.defaultEncoding);
                    ASCIIEncoding ascii = new ASCIIEncoding();
                    byte[] byteArray = Encoding.UTF8.GetBytes(TriggeredText);
                    byte[] asciiArray = Encoding.Convert(Encoding.UTF8, enc, byteArray);
                    finalString = ascii.GetString(asciiArray);

                }
            }
            catch { }


            networkConnection.SendString(finalString);
            amWaitingForEvent = true;


            log("Enable timer1");
            timer1.Interval = 100;
            timer1.Enabled = true;
        }

        void timer1_Tick(object sender, System.EventArgs e)
        {
            log("Timer1Tick");
            if (hasQuit)
            {
                doQuit();
            }

            if (amWaitingForEvent)
            {
                log("Stopping timer - as I'm waiting for an event");
                timer1.Enabled = false;
            }
        }

        string exitMsg = "";

        /// <summary>
        /// Sets an exit message to display on the 'goodbye' screen..
        /// 
        /// </summary>
        /// <param name="errMsg">Error Message from 4gl program</param>
        /// <returns>Always returns true to inhibit the Program.Show</returns>
        public bool setExitMessage(string errMsg) {
            exitMsg = errMsg;
            return true;
        }

	public bool isWebUI=true;


        private void doQuit()
        {

       
          
            if (gwin == null)
            {
                this.Enabled = false;
                gwin = new Goodbye(exitMsg);
                gwin.Closed += new EventHandler(amb_Closed);
                gwin.ShowDialog();
            }
            timer2.Enabled = false;

        }

        void amb_Closed(object sender, EventArgs e)
        {
            this.Close();
            
        }


        public void SetMenuBarButtons(Control a)
        {
            MenuBarPanel.Controls.Clear();

            if (a != null)
            {
                MenuBarPanel.Controls.Add(a);
            }
            showOrHideMenubar();
            MenuBarPanel.Width = MenuBarPanel.Width;
            mainAppPanel.Width = mainAppPanel.Width;
            log("SET MENUBARBUTTONS Sizeof a=" + a.Width + " " + a.Height);
            

        }


        public void ShowDialog(Control f)
        {

        }

        public void showOrHideMenubar()
        {

            MenuBarPanel.Visible = true;
            return;
            /*

            if (MenuBarPanel.Controls.Count > 0 || true)
            {
                MenuBarPanel.Visible = true;

            }
            else
            {
                MenuBarPanel.Visible = false;

                
            }
             * */

        }


        public void setWaitCursor()
        {
            this.Cursor = Cursors.WaitCursor;
            
          //  timer1.Enabled = false;
        }

        public void clrWaitCursor()
        {
            amWaitingForEvent = true;
            this.Cursor = Cursors.Arrow;
            
            //Application.DoEvents();
        //      if (timer1.Enabled == false)
        //     {
        //        timer1.Enabled = true;
        //    }
            /*
            if (timer1.Enabled == false)
            {
                timer1.Interval = 100;
                timer1.Enabled = true;
                this.Error.WriteLineText = "T...";
            }
            else
            {
                timer1.Enabled = false;
                timer1.Interval = 100;
                timer1.Enabled = true;
            }
             * */
        }

        internal void setToolbar(List<AubitTSBtn> toolStrip)
        {

            this.topWindowToolStrip.Buttons.Clear();
            if (toolStrip.Count > 0)
            {
                for (int a = 0; a < toolStrip.Count; a++)
                {

                    this.topWindowToolStrip.Buttons.Add(toolStrip[a]);
                }
            }
            showOrHideToolbar();

        }

        private void showOrHideToolbar()
        {
            if (topWindowToolStrip.Buttons.Count > 0)
            {
                topWindowToolStrip.Visible = true;
            }
            else
            {
                topWindowToolStrip.Visible = false;
            }
        }

        internal void setProgress(int p, int cnt)
        {
            // Ignore for this one..
        }

        internal void loadApplicationLauncherTree(string oname,int applicationID)
        {
            // Does nothing on purpose..
        }

        internal void setTabTitle(FGLApplicationPanel fGLApplicationPanel, string p)
        {
            
        }


        internal void setActiveTab(FGLApplicationPanel fGLApplicationPanel)
        {
            // Does nothing on purpose..
        }

	internal void setToolstripHeight(int p) {
            // Does nothing on purpose..
	}

	internal void setToolstripImageSize(int p) {
            // Does nothing on purpose..
	}

        private void topWindowToolStrip_Click(object objSource, ToolBarItemEventArgs objArgs)
        {
            wfAbout abt;
            abt = new wfAbout();
            abt.Show();
        }

        internal void addNewTabPage(int p, string progname, FGLApplicationPanel fGLApplicationPanel)
        {
            this.SuspendLayout();
            mainAppPanel.AutoSize = true;
            mainAppPanel.Visible = true;
            
           
            mainAppPanel.Controls.Add(fGLApplicationPanel);
            this.Width = this.Width;
            mainAppPanel.Focus();
            //mainAppPanel.BackColor = Color.Red;
            //fGLApplicationPanel.BackColor = Color.Beige;
            fGLApplicationPanel.AutoSize = true;


        }

        internal void AddTextToConsole(string p)
        {
            log(p);
        }

        internal void removeTabPage(FGLApplicationPanel fGLApplicationPanel)
        {
            mainAppPanel.Controls.Clear();
            if (VWGContext.Current != null)
            {
                MessageBox.Show("Application has exited");
            }
            hasQuit = true;
        }

        private void frmMainAppWindow_Load(object sender, EventArgs e)
        {
            showOrHideToolbar();
            showOrHideMenubar();

            MessageText = "";
            ErrorText = "";
            CommentText = "";
            LineDisplayText = "";

            About.Click += new EventHandler(About_Click);



            gbDebugDump.Visible = false; // Make the debug box invisible for normal users...

            string settingsFile = AubitDesktop.Xml.Authentication.ConfigurationSettings.settingsFile;

            if (settingsFile == null)
            {
                log("No settings file loaded");
                //Program.Show("Settings file = null");
            }
            else
            {
                log("settings file :" + settingsFile);
                //Program.Show("Settings File = " + settingsFile);
            }





            log("Username was : " + txtUsername.Text);

            if (txtUsername.Text == "")
            {
                string uname;



                String[] arr1 = HttpContext.Current.Request.ServerVariables.AllKeys;
                for (int loop1 = 0; loop1 < arr1.Length; loop1++)
                {
                    log("Key: " + arr1[loop1]);
                    String[] arr2 = HttpContext.Current.Request.ServerVariables.GetValues(arr1[loop1]);
                    for (int loop2 = 0; loop2 < arr2.Length; loop2++)
                    {
                        log("Value " + loop2 + ": " + arr2[loop2]);
                    }
                }


                log("Checking for LOGON_USER");
                uname = HttpContext.Current.Request.ServerVariables["LOGON_USER"];
                if (uname == null || uname == "")
                {
                    uname = HttpContext.Current.Request.ServerVariables["AUTH_USER"];
                }
                if (uname == null || uname == "")
                {
                    uname=HttpContext.Current.Request.ServerVariables["REMOTE_USER"];
                }

                if (uname != null)
                {

                    log("Checking for LOGON_USER was " + uname);
                    if (uname.Contains("\\"))
                    {
                        uname = uname.Substring(uname.IndexOf("\\") + 1);
                    }

                    txtUsername.Text = uname;
                    log("Checking for LOGON_USER fixed to " + uname);

                }
                else
                {
                    log("Checking for LOGON_USER = null");
                }

            }


            // MessageBox.Show("Auth_user=" + HttpContext.Current.Request.ServerVariables["AUTH_USER"]);

            if (settingsFile == null || settingsFile == "")
            {
                log("No settings file specified - trying default");
                settingsFile = "settings.xml";
            }
            else
            {
                log("Settings file : " + settingsFile);
            }

              
                cbApplications.Items.Clear();
              
                cbApplications.Text = "";
              
            

            try
            {
                log("Loading " + settingsFile + " CWD=" + Directory.GetCurrentDirectory());
             
                appsConfig = loadAuthenticationSettings(settingsFile);
                if (appsConfig == null)
                {
                    log("appsConfig=null");
                   
                }
                if (appsConfig != null)
                {
                    log("Got a config file");
                    
                    log("Got a config...");
                    // Lets add all of our applications into the combobox..

                    foreach (AubitDesktop.Xml.Authentication.Application app in appsConfig.Applications)
                    {
                        log("Adding Item " + app.Name);
                        cbApplications.Items.Add(app.Name);
                    }


                    // If we've got some items - select the first one..
                    if (cbApplications.Items.Count > 0)
                    {
                        cbApplications.SelectedIndex = 0;
                    }

                    if (appsConfig.AuthMode != "F")
                    {
                        if (cbApplications.Items.Count == 1)
                        {
                            // Its pre-authenticated & selected...

                            doLogin();
                        }
                        else
                        {
                            txtUsername.Enabled = false;
                            txtPassword.Enabled = false;
                        }
                    }
                }
            }
            catch
            {
                log("Unable to open settings file " + settingsFile);
                Program.Show("Unable to open settings file " + settingsFile);
            }



            // this.Context.CurrentTheme = new Theme("Black");

            RunningApplications = new List<FGLApplicationPanel>();
            Program.AppSettings = new AubitDesktop.Xml.Settings();
            Program.AppSettings.AllowEdit = false;
            Program.AppSettings.allowExec = false;
            Program.AppSettings.interruptKey = "Control-C";
            Program.AppSettings.ListenMode = false;
            Program.AppSettings.Shortcuts = new List<AubitDesktop.Xml.Shortcut>();
            Program.AppSettings.StartMinimized = false;
            Program.AppSettings.WindowPositions = new List<AubitDesktop.Xml.WindowPosition>();
            Program.AppSettings.xscale = 9;
            Program.AppSettings.defaultEncoding = "ISO8859-1";
            Program.AppSettings.yscale = 23;

            log("Enable timer1");

            timer2.Enabled = true; /* Slow timer  - just to keep it pinging updates */
            txtUsername.SelectAll();
            txtUsername.Focus();
            this.MenuBarPanel.BackColor = Color.FromArgb(240, 240, 240);
            this.mainAppPanel.BackColor = Color.FromArgb(240, 240, 240);
            toolBarButton1.Click += new EventHandler(toolBarButton1_Click);

            btnPanel.Text = "";
        }

        void About_Click(object sender, EventArgs e)
        {
             wfAbout abt;
             abt = new wfAbout();
             abt.ShowDialog();
            
        }



    AubitDesktop.Xml.Authentication.Configuration loadAuthenticationSettings(string fileName)
    {
        XmlSerializer ser;
        System.Type t;
        AubitDesktop.Xml.Authentication.Configuration localAppsConfig;


        t=typeof(AubitDesktop.Xml.Authentication.Configuration);
        ser = new XmlSerializer(t);
       // ser.UnknownAttribute += new XmlAttributeEventHandler(ser_UnknownAttribute);
       // ser.UnknownElement += new XmlElementEventHandler(ser_UnknownElement);
       // ser.UnknownNode += new XmlNodeEventHandler(ser_UnknownNode);

        System.IO.StreamReader file =
                new System.IO.StreamReader(fileName);
        

        

        try
        {
            localAppsConfig = (AubitDesktop.Xml.Authentication.Configuration)ser.Deserialize(file);
        }
        catch (Exception e)
        {
            Program.Show("Unable to process XML file:" + e.ToString());
            return null;
        }
        return localAppsConfig;
    }


    void toolBarButton1_Click(object sender, EventArgs e)
    {
        wfAbout abt;
        abt = new wfAbout();
        abt.Show();

    }



        void frm_doLoginHandler(object sender, EventArgs e)
        {
            if (cbApplications.Text=="")
            {
                Program.Show("No application has been selected!");
            }
            else
            {
                doLogin();
            }
            return;
        }



        private void doLogin()
        {
            string appName;
            string host="";
            string port="";
            string programName = "";
            string userName="";
            string passWord="";
            string protocol="";
            bool foundApp = false;

          //  MessageBox.Show("Logon_user = " + HttpContext.Current.Request.ServerVariables["LOGON_USER"]);
          //  MessageBox.Show("Auth_user=" + HttpContext.Current.Request.ServerVariables["AUTH_USER"]);

            if (cbApplications.Text.Trim()=="") return;


            
            appName=(string)cbApplications.Text;

            if (appsConfig == null)
            {
                host = "192.168.2.217";
                port= "3490";
                userName=txtUsername.Text;
                passWord=txtPassword.Text;
                protocol = "PROXY";
                programName = appName;
                foundApp = true;
            } else {

                

                for (int appNo = 0; appNo < appsConfig.Applications.Length; appNo++)
                {
                    if (appsConfig.Applications[appNo].Name == appName)
                    {
                        programName = appsConfig.Applications[appNo].ProgramName;

                        foundApp = true;
                        // We've found our application...
                        if (appsConfig.AuthMode == "F")
                        {
                            // We need to check the username/password...
                            for (int user = 0; user < appsConfig.Applications[appNo].Users.Length; user++)
                            {
                                if (appsConfig.Applications[appNo].Users[user].Name == txtUsername.Text)
                                {
                                    string plainTextPassword=decipher(appsConfig.Applications[appNo].Users[user].Password);

                                    if (plainTextPassword != txtPassword.Text)
                                    {
                                        //Program.Show("Invalid username/password : "+plainTextPassword+"!="+txtPassword.Text);
                                        Program.Show("Invalid username/password");
                                        return;
                                    }
                                    else
                                    {
                                       

                                        // A Match! 
                                        //
                                        host = appsConfig.Applications[appNo].Server;
                                        port = appsConfig.Applications[appNo].Port;

                                        if (appsConfig.Applications[appNo].connMode == "S")
                                        {
                                            // We'll use the tunnelling ssh...
                                            protocol = "SSHT";
                                        }

                                        if (appsConfig.Applications[appNo].connMode == "P")
                                        {
                                            protocol = "PROXY";
                                        }
                                        // The username we use to connect to the sshd or proxy
                                        // might well be different from the username entered for
                                        // authentication
                                        // If the Username in the application configuration is "-"
                                        // then we want to re-use the entered password....
                                        if (appsConfig.Applications[appNo].Username == "-" || appsConfig.Applications[appNo].Username == "" || appsConfig.Applications[appNo].Username == null)
                                        {
                                            userName = txtUsername.Text;
                                        }
                                        else
                                        {
                                            userName = appsConfig.Applications[appNo].Username;
                                        }

                                        if (appsConfig.Applications[appNo].Password == "-" || appsConfig.Applications[appNo].Password == "" || appsConfig.Applications[appNo].Password == null)
                                        {
                                            passWord = txtPassword.Text;
                                        }
                                        else
                                        {
                                            passWord = appsConfig.Applications[appNo].Password;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }

            if (!foundApp)
            {
                Program.Show("Application not found");
                return;
            }


            setWaitCursor();
            networkConnection = new AubitNetwork(AubitNetwork.SocketStyle.SocketStyleLine);
            networkConnection.ReceivedEnvelopeFromServer += new ReceivedEnvelopeEventHandler(n_ReceivedEnvelopeFromServer);
            networkConnection.ConnectingFailed += new ConnectingFailedEventHandler(n_ConnectingFailed);
            networkConnection.DisconnectedFromServer += new DisconnectedEventHandler(n_DisconnectedFromServer);
            networkConnection.ConnectionDied += new EventHandler(networkConnection_ConnectionDied);
            EnvelopeReadyForConsumption += new EventHandler(frmMainAppWindow_EnvelopeReadyForConsumption);

            try
            {
                networkConnection.NewConnection(host, port, userName, passWord, programName, protocol, this);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                return;
            }

            if (networkConnection != null && networkConnection.connectionFailed)
            {
                MessageBox.Show("Connection Failed");
                clrWaitCursor();

            }
            else
            {
                loginPanel.Visible = false;
                log("Enable timer1");
                timer1.Interval = 100;
                timer1.Enabled = true;
            }


        }

        private string decipher(string p)
        {
            
            return A4GL_tea_string_decipher(p);
            
        }





        uint hexToInt(string h)
        {
            switch (h.ToLower())
            {
                case "0": return 0;
                case "1": return 1;
                case "2": return 2;
                case "3": return 3;
                case "4": return 4;
                case "5": return 5;
                case "6": return 6;
                case "7": return 7;
                case "8": return 8;
                case "9": return 9;
                case "a": return 10;
                case "b": return 11;
                case "c": return 12;
                case "d": return 13;
                case "e": return 14;
                case "f": return 15;
            }
            return 0;

        }



        string
        A4GL_tea_string_decipher(string s)
        {
            string buff;
            string buff_out;
            string smbuff;
            int a;
            uint[] key = new uint[4];
            string rbuff;
            uint l;
            byte[] outb = new byte[8];
            uint[] lgptr = new uint[2];


            key[0] = 0x12447469;
            key[1] = 0x87873739;
            key[2] = 0x908acd69;
            key[3] = 0xfc892782;
            buff = s;
            buff_out = "";

            for (a = 0; a < buff.Length; a += 16)
            {
                l = hexToInt(buff.Substring(a, 1));
                l = (l * 16) + hexToInt(buff.Substring(a + 1, 1));
                l = (l * 16) + hexToInt(buff.Substring(a + 2, 1));
                l = (l * 16) + hexToInt(buff.Substring(a + 3, 1));
                l = (l * 16) + hexToInt(buff.Substring(a + 4, 1));
                l = (l * 16) + hexToInt(buff.Substring(a + 5, 1));
                l = (l * 16) + hexToInt(buff.Substring(a + 6, 1));
                l = (l * 16) + hexToInt(buff.Substring(a + 7, 1));
                lgptr[0] = l;

                l = hexToInt(buff.Substring(a + 8, 1));
                l = (l * 16) + hexToInt(buff.Substring(a + 9, 1));
                l = (l * 16) + hexToInt(buff.Substring(a + 10, 1));
                l = (l * 16) + hexToInt(buff.Substring(a + 11, 1));
                l = (l * 16) + hexToInt(buff.Substring(a + 12, 1));
                l = (l * 16) + hexToInt(buff.Substring(a + 13, 1));
                l = (l * 16) + hexToInt(buff.Substring(a + 14, 1));
                l = (l * 16) + hexToInt(buff.Substring(a + 15, 1));
                lgptr[1] = l;

                tea_8c_decipher(lgptr, key);


                outb[3] = (byte)((lgptr[0] >> 24) & 0xff);
                outb[2] = (byte)((lgptr[0] >> 16) & 0xff);
                outb[1] = (byte)((lgptr[0] >> 8) & 0xff);
                outb[0] = (byte)(lgptr[0] & 0xff);

                outb[7] = (byte)((lgptr[1] >> 24) & 0xff);
                outb[6] = (byte)((lgptr[1] >> 16) & 0xff);
                outb[5] = (byte)((lgptr[1] >> 8) & 0xff);
                outb[4] = (byte)(lgptr[1] & 0xff);


               int len = outb.Length;
                for (int cnt = 0; cnt < 8; cnt++)
                {
                    if (outb[cnt] == 0)
                    {
                        len = cnt ;
                        break;
                    }
                }

                smbuff = System.Text.ASCIIEncoding.ASCII.GetString(outb,0, len);

                buff_out = buff_out + smbuff;

            }
            return buff_out.TrimEnd();
        }

        void tea_8c_decipher(uint[] v, uint[] k)
        {
            
            uint y = v[0], z = v[1], sum = 0xC6EF3720, delta = 0x9E3779B9, n = 32;

            

            while (n-- > 0)
            {
                z -= (y << 4 ^ y >> 5) + (y ^ sum) + k[sum >> 11 & 3];
                sum -= delta;
                y -= (z << 4 ^ z >> 5) + (z ^ sum) + k[sum & 3];
            }

            v[0] = y;
            v[1] = z;

            
        }


        void networkConnection_ConnectionDied(object sender, EventArgs e)
        {
            this.mainAppPanel.Controls.Clear();
            this.ErrorText = "Connection died";

            //throw new NotImplementedException();
        }

        private void frmMainAppWindow_EnvelopeReadyForConsumption(object sender, EventArgs e)
        {
            //MessageBox.Show("Ready for consumption");
            ConsumeEnvelopeHandler();
            //this.ConsumeEnvelopeCommands();
        }

        public void ConsumeEnvelopeHandler()
        {
            DateTime s;
            s = System.DateTime.Now;
            //log("CONSUMING: " + System.DateTime.Now);
            ConsumeEnvelopeCommands();
            log("CONSUMED in " + (System.DateTime.Now - s));
        }

        private void ConsumeEnvelopeCommands()
        {
            int a = 0;
            if (updating)
            {
                log("Cant consume - updating");
                return;
            }

            //log("Consume1");
            while (a < RunningApplications.Count)
            {
                RunningApplications[a].ConsumeEnvelopeCommands();
                a++;
            }
            
        }

        void n_ConnectingFailed(object sender, EventArgs e)
        {
            this.MessageText=("Connection failed");
        //    this.Close();
        }

        void n_DisconnectedFromServer(object sender, EventArgs e)
        {
            EnvelopeReadyForConsumption(null, null);
            this.MessageText = "Server disconnected";
            //MessageBox.Show("Server disconnect");
           // this.Close();
        }

        void n_ReceivedEnvelopeFromServer(object sender, ReceivedEventArgs e)
        {
            ENVELOPE enew;
            int a;
            int ID;


            FGLApplicationPanel appPanel;

            if (e.Data == "") return;
            updating = true;

            enew = EnvReader.ReadFromXml(e.Data);
            ID = Convert.ToInt32(enew.ID);

            foreach (FGLApplicationPanel p in RunningApplications)
            {
                if (p.ApplicationEnvelopeID == ID)
                { // We've found it..
                    for (a = 0; a < enew.COMMANDS.Length; a++)
                    {

                        p.commands.Add(enew.COMMANDS[a]);
                    }
                    updating = false;

                    if (EnvelopeReadyForConsumption != null)
                    {
                        EnvelopeReadyForConsumption(null, null);
                    }
                    return;
                }
            }

            // If we get to here - we have no FGLApplication panel to use :-(
            appPanel = new FGLApplicationPanel(this, this.networkConnection.username, this.networkConnection.application, Convert.ToInt32(enew.ID));
            RunningApplications.Add(appPanel);
            for (a = 0; a < enew.COMMANDS.Length; a++)
            {
                appPanel.commands.Add(enew.COMMANDS[a]);

            }

            updating = false;
            if (EnvelopeReadyForConsumption != null)
            {
                EnvelopeReadyForConsumption(null, null);
            }

        }


        private void button1_Click(object sender, EventArgs e)
        {
            
        }

        internal void ShowApplication()
        {
            this.MessageText = ("Connected!");
            mainAppPanel.Controls.Clear();
           // Application.DoEvents();
        }

        internal bool FailedToStart()
        {
            ErrorText = "Failed to start";
            return true;
        }

        private void mainAppPanel_Resize(object sender, EventArgs e)
        {
            //
        }

        private void mainAppPanel_GotFocus(object sender, EventArgs e)
        {

        }


        private void mainAppPanel_Click(object sender, EventArgs e)
        {

        }


        private static void ensureParentSize(Control c, int maxWidth, int maxHeight)
        {
            if (c.Parent == null) return; 
            if (c.Parent.Width < maxWidth || c.Parent.Height < maxHeight)
            {
                ensureParentSize(c.Parent, maxWidth, maxHeight);
                c.Parent.Width = maxWidth;
                c.Parent.Height = maxHeight;
            }
        }


        public static int nmCounter = 0;
        /// <summary>
        /// Debug routine to print out the sizes of the various controls..
        /// </summary>
        /// <param name="control"></param>
        /// <param name="level"></param>
        public static void ensureSizeWindow(Control control, string level)
        {



            if (control.Width == 2000)
            {
                control.Width = 100;
                control.Height = 100;
            }

            int maxWidth = control.Width;
            int maxHeight = control.Height;

            //  ContainerControl c=null;
            if (control.Name == "")
            {
                control.Name = "Cntrl" + nmCounter;
            }

            if (control.Height < 0 || control.Left < 0 || control.Width < 0 || control.Top < 0)
            {
                throw new ApplicationException("Invalid control size/location");
            }

            log(level + " " + control.Name + " " + control.Height + " " + control.Width + " " + control.Left + " " + control.Top);
            if (control.HasChildren)
            {
                foreach (Control d in control.Controls)
                {
                    ensureSizeWindow(d, level + " ");
                    if (d.Height + d.Top > maxHeight)
                    {
                        maxHeight = d.Height + d.Top;
                    }
                    if (d.Width + d.Left > maxWidth)
                    {
                        maxWidth = d.Width + d.Left;
                    }


                }
            }

            if (control.Height < maxHeight || control.Width < maxWidth)
            {
                control.MinimumSize = new Size(maxWidth, maxHeight);
               frmMainAppWindow. ensureParentSize(control, maxWidth, maxHeight);
                control.Size = new Size(maxWidth, maxHeight);
            }



            if (control.Width == 100 && control.Height == 100)
            {
                log("Failed");
                //Program.Show((Gizmox.WebGUI.Forms.Form) null,"Unfixed");
            }



        }

        private void timer2_Tick(object sender, EventArgs e)
        {
            //log("Timer2Tick");
            if (hasQuit)
            {
                doQuit();
            }
        }

        int cntrl_cnt = 0;

        string doDump(Control c, string lvl)
        {
            string rval="";

            if (c.GetType().Name == "AubitDesktop.UIMenuBarButton") return "";

            if (c.Name == "")
            {
                c.Name = "nm_" + cntrl_cnt++;
            }

           
                rval += lvl+c.GetType().ToString() + " " + c.Name + "= new " + c.GetType().ToString() + "();\n";
                if (c.Text!="")
                {
                    rval+=lvl+c.Name+".Text=\""+c.Text+"\";\n";
                }
                rval += lvl + c.Name + ".Left=" + c.Left + ";\n";
                rval += lvl + c.Name + ".Top=" + c.Top + ";\n";
                rval += lvl + c.Name + ".Width=" + c.Width + ";\n";
                rval += lvl + c.Name + ".Height=" + c.Height + ";\n";
                rval += lvl + c.Name + ".BorderStyle=BorderStyle." + c.BorderStyle + ";\n";
                if (c.Enabled)
                {
                    rval += lvl + c.Name + ".Enabled=true;\n";
                }
                else
                {
                    rval += lvl + c.Name + ".Enabled=false;\n";
                }
                if (c.Visible)
                {
                    rval += lvl + c.Name + ".Visible=true;\n";
                }
                else
                {
                    rval += lvl + c.Name + ".Visible=false;\n";
                }
                if (c.AutoSize)
                {
                    rval += lvl + c.Name + ".Width=2000;\n";
                    rval += lvl + c.Name + ".Height=2000;\n";
                    //rval += lvl + c.Name + ".AutoSize=true;\n";
                }
                else
                {
                    rval += lvl + c.Name + ".AutoSize=false;\n";
                }

                rval += lvl + c.Name + ".Dock=DockStyle." + c.Dock + ";\n";

                //rval=(lvl+c.GetType().ToString()+"("+c.Name +","+ c.Text+")\n");
            

            if (c is Panel)
            {
                Panel p;
                p = (Panel)c;
                rval += lvl + c.Name + ".BorderStyle=BorderStyle." + p.BorderStyle + ";\n";
                foreach (Control n in p.Controls)
                {
                    rval += doDump(n, lvl + " ");
                    rval += lvl + c.Name + ".Controls.Add(" + n.Name + ");\n";
                }
                if (c.AutoSize)
                {
                    rval += lvl + c.Name + ".AutoSize=true;\n";
                }
                return rval;
            }

            if (c is GroupBox)
            {
                GroupBox p;
                p = (GroupBox)c;
                rval += lvl + c.Name + ".BorderStyle=BorderStyle." + p.BorderStyle + ";\n";
                foreach (Control n in p.Controls)
                {
                    rval += doDump(n, lvl + " ");
                    rval += lvl + c.Name + ".Controls.Add(" + n.Name + ");\n";
                }
                if (c.AutoSize)
                {
                    rval += lvl + c.Name + ".AutoSize=true;\n";
                }
                return rval;
            }

            if (c is FlowLayoutPanel)
            {
                FlowLayoutPanel p;
                p = (FlowLayoutPanel)c;
                rval += lvl + c.Name + ".FlowDirection=FlowDirection." + p.FlowDirection + ";\n";
                foreach (Control n in p.Controls)
                {
                    rval += doDump(n, lvl + " ");
                    rval += lvl + c.Name + ".Controls.Add(" + n.Name + ");\n";
                }
                if (c.AutoSize)
                {
                    rval += lvl + c.Name + ".AutoSize=true;\n";
                }
                return rval;
            }

            
            if (c is frmMainAppWindow)
            {
                frmMainAppWindow p;
                p = (frmMainAppWindow)c;
                foreach (Control n in p.Controls)
                {
                    rval += doDump(n, lvl + " ");
                    rval += lvl +  "topPanel.Controls.Add(" + n.Name + ");\n";
                }
                if (c.AutoSize)
                {
                    rval += lvl + c.Name + ".AutoSize=true;\n";
                }
                return rval;
            }

            if (c.AutoSize)
            {
                rval += lvl + c.Name + ".AutoSize=true;\n";
            }
            return rval;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string str;
            str=doDump(this,"");
            MessageBox.Show(str);
        }

        private void MenuBarPanel_Click(object sender, EventArgs e)
        {

        }

        private void statusBar1_Click(object sender, EventArgs e)
        {
        }

        private void topWindowToolStrip_Click_1(object objSource, ToolBarItemEventArgs objArgs)
        {

        }







        internal void sendFileToClient(FILE file)
        {

            //Program.Show("Cant send files to the client yet..");
            return;


            FileDownloadGateway oDownloader = new FileDownloadGateway();

            
            if (file.CLIENTNAME != null && file.CLIENTNAME.Length > 0)
            {
                oDownloader.Filename = file.CLIENTNAME;
            }
            else
            {
                oDownloader.Filename = file.NAME;
            }
            
           
            oDownloader.StartBytesDownload(this,Convert.FromBase64String(file.Text));
        }
    }


}
