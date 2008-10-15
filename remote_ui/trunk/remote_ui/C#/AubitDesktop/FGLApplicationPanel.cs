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
using System.Drawing;
using System.IO;



namespace AubitDesktop
{
    public class FGLApplicationPanel : Panel
    {
        private FGLOptions options;
        public int ApplicationEnvelopeID;
        private List<UIContext> contexts;
        private List<AubitTSBtn> Fkeys;
        private string _errortext;
        private string _commenttext;
        private string _messagetext;
        private string _linedisplaytext;
        private List<ToolStripItem> toolStrip1;
        private string ApplicationName;
        private string Username;
        private ToolTip tooltips;
        FGLWindow winScreen;
        // Toolstrip buttons....
        private AubitTSBtn tsBtnAccept;
        private AubitTSBtn tsBtnCancel;

        private AubitTSBtn tsBtnUp;
        private AubitTSBtn tsBtnDown;

        private AubitTSBtn tsBtnPgUp;
        private AubitTSBtn tsBtnPgDown;
        private AubitTSBtn tsBtnInsert;
        private AubitTSBtn tsBtnDelete;
        private DateTime lastPing;
        private bool lastPingIsSet = false;
        private TimeSpan pingInterval = new TimeSpan(0, 0, 20);

        public List<object> commands;
        FGLWindowStack ApplicationWindows;
        private Hashtable serverEnviron;

        public Hashtable ServerEnviron
        {
            get { return serverEnviron; }
            set { serverEnviron = value; }
        }
        FGLOpenedForms OpenForms;
        private List<AubitTSBtn> programButtons;
        //private Control parentControl;
        private frmMainAppWindow TopWindow; // The window containing the tabpage control
        public  string lastKey;


        public string getApplicationKey(string keyType)
        {
            switch (keyType)
            {
                case "ACCEPT": return options.AcceptKey;
                case "INSERT": return options.InsertKey;
                case "DELETE": return options.DeleteKey;
            }

            throw new ApplicationException("Invalid keytype for getApplicationKey " + keyType);
        }

        public string LineDisplayText
        {
            get
            {
                return _linedisplaytext;
            }
            set
            {
                _linedisplaytext = value;
                TopWindow.LineDisplayText =value;
            }
        }

        public string ErrorText
        {
            get
            {
                return _errortext;
            }
            set
            {
                _errortext = value;
                TopWindow.ErrorText = value;
            }
        }

        public string CommentText
        {
            get
            {
                return _commenttext;
            }
            set
            {
                _commenttext = value;
                TopWindow.CommentText = value;
            }
        }

        public string MessageText
        {
            get
            {
                return _messagetext;
            }
            set
            {
                _messagetext = value;
                TopWindow.MessageText = value;
            }

        }

        UIContext _currentContext;

        UIContext currentContext {
            get
            {
                return _currentContext;
            }
            set
            {
                _currentContext = value;
                TopWindow.currentContext = value;
            }
        }
        

        public FGLApplicationPanel(frmMainAppWindow topwin, string pUsername, string pApplication,int ID)
        {
           
            TopWindow = topwin;
            this.ApplicationEnvelopeID = ID;
            this.OpenForms = new FGLOpenedForms();
            tooltips = new ToolTip();
            contexts = new List<UIContext>();
            commands = new List<object>();
            //this.parentControl = parentControl;
            this.ApplicationName = pApplication;
            this.Username = pUsername;
            ApplicationWindows = new FGLWindowStack(this);
            winScreen = new FGLWindow("SCREEN");
            this.programButtons = new List<AubitTSBtn>();
            this.options = new FGLOptions();

            
            this.Controls.Add(winScreen.WindowWidget);
            ApplicationWindows.PushWindow(winScreen);
            this.toolStrip1 = new List<ToolStripItem>();
            this.AutoScroll = true;
            this.SetAutoScrollMargin(5, 5);
            
            this.Fkeys = new List<AubitTSBtn>();
            this.AutoSize = true;
            this.Dock = DockStyle.Fill;
            this.Visible = true;
            this.Enabled = true;
            /*
            for (int a = 1; a <= 36; a++)
            {
                AddToolBarKey("F" + a, "");
            }
             * */
            //parentControl.Controls.Add(this);

        }


        public void SetMenuBarButtons(Control a)
        {
            TopWindow.SetMenuBarButtons(a);
        }

        public void AddToolBarKey(string Key, string ID)
        {
            string txt;

            txt = FGLUtils.getKeyNameFromFGLKeyCode(Key);

            AddToolBarKey(Key, txt, ID);
        }



        void UIContext_EventTriggered(object source, string ID, string TriggeredText)
        {
            if (TriggeredText == "")
            {
                TriggeredText="<TRIGGERED ID=\""+ID+"\"/>";
            }
           TopWindow.SendString(TriggeredText,true);
        }


        public bool hasKeyInOnkeyEventList(List<ONKEY_EVENT> keylist, string key)
        {
            foreach (ONKEY_EVENT e in keylist)
            {
                if (e.KEY == key)
                {
                    return true;
                }
            }
            return false;
        }

        public bool hasKeyInToolbar(string key)
        {
            foreach (AubitTSBtn o in Fkeys)
            {
                if (o.ActiveKey == key) return true;
            }
            return false;
        }

        internal AubitTSBtn getKeyFromToolbar(string key)
        {
            foreach (AubitTSBtn o in Fkeys)
            {
                if (o.ActiveKey == key) return o;
            }
            return null;
        }


        public void setActiveToolBarKeys(List<ONKEY_EVENT> keys, bool showAcceptInterrupt)
        {
            setActiveToolBarKeys(keys,showAcceptInterrupt,false,false);
        }

        public void setActiveToolBarKeys(List<ONKEY_EVENT> keys,bool showAcceptInterrupt,bool showUpDownButtons,bool showInsertDeleteButtons)
        {
            // We dont want any keys active ? 
            if (keys == null)
            {
                foreach (AubitTSBtn o in Fkeys)
                {
                    o.Visible = false;
                }
                tsBtnCancel.Visible = false;
                tsBtnAccept.Visible = false;
            }
            else
            {
                ensureAcceptInterruptButtonsOnToolStrip();

                
                        if (showAcceptInterrupt)
                        {
                            tsBtnAccept.Visible=true;
                            tsBtnCancel.Visible=true;
                        }
                        else
                        {
                            tsBtnAccept.Visible=false;
                            tsBtnCancel.Visible=false;
                        }

                        if (showInsertDeleteButtons)
                        {
                             tsBtnDelete.Visible = true;
                            tsBtnInsert.Visible=true;
                        } else {
                            tsBtnDelete.Visible = false;
                            tsBtnInsert.Visible = false;
                        }

                        if (showUpDownButtons)
                        {
                            tsBtnPgUp.Visible = true;
                            tsBtnPgDown.Visible = true;
                            tsBtnUp.Visible = true;
                            tsBtnDown.Visible = true;
                        }
                        else
                        {
                            tsBtnPgUp.Visible = false;
                            tsBtnPgDown.Visible = false;
                            tsBtnUp.Visible = false;
                            tsBtnDown.Visible = false;
                        }


                // Ok - there are some keys - but not all of them will be used..
                // so we need to remove any that are not in use by making them invisible
                foreach (AubitTSBtn o in Fkeys)
                {
                    
                    
                        if (!hasKeyInOnkeyEventList(keys, o.ActiveKey))
                        {
                            o.Visible = false;
                        }
                    
                }


                // we'll move through our keys and enable them...
                foreach (ONKEY_EVENT key in keys)
                {
                    AubitTSBtn o;

                    // Has the key already been added ? 
                    if (!hasKeyInToolbar(key.KEY))
                    {
                        // Dang - we need to add it..
                        AddToolBarKey(key.KEY, key.ID);
                    }

                    // This should never fail - because we've added it if it was missing!
                    o=getKeyFromToolbar(key.KEY);
                    if (o == null)
                    {
                        throw new Exception("This shouldn't happen - key is missing from menubar");
                    }
                    else
                    {
                        o.Visible = true;
                        o.ID = key.ID;
                    }
                }

            }
            TopWindow.setToolbar(toolStrip1);
        }


        void tsBtnUp_Click(object sender, EventArgs e)
        {
            this.ErrorText = "";
            if (currentContext is UIDisplayArrayContext)
            {
                UIDisplayArrayContext dc;
                dc = (UIDisplayArrayContext)currentContext;
                dc.upkeyPressed();
                return;
                
            }
            if (currentContext is UIInputArrayContext)
            {
                UIInputArrayContext dc;
                dc = (UIInputArrayContext)currentContext;
                dc.upkeyPressed();
                return;

            }
            throw new NotImplementedException();
        }

        void tsBtnDown_Click(object sender, EventArgs e)
        {
            this.ErrorText = "";
            if (currentContext is UIDisplayArrayContext)
            {
                UIDisplayArrayContext dc;
                dc = (UIDisplayArrayContext)currentContext;
                dc.downkeyPressed();
                return;
            }
            if (currentContext is UIInputArrayContext)
            {
                UIInputArrayContext dc;
                dc = (UIInputArrayContext)currentContext;
                dc.downkeyPressed();
                return;
            }


            throw new NotImplementedException();
            
        }


        void tsBtnInsert_Click(object sender, EventArgs e)
        {
            this.ErrorText = "";
            if (currentContext is UIInputArrayContext)
            {
                UIInputArrayContext dc;
                dc = (UIInputArrayContext)currentContext;
                dc.InsertkeyPressed();
                return;
            }
        }

        void tsBtnDelete_Click(object sender, EventArgs e)
        {
            this.ErrorText = "";
            this.ErrorText = "";
            if (currentContext is UIInputArrayContext)
            {
                UIInputArrayContext dc;
                dc = (UIInputArrayContext)currentContext;
                dc.DeletekeyPressed();
                return;
            }
        }

        void tsBtnPgDown_Click(object sender, EventArgs e)
        {
            this.ErrorText = "";
            if (currentContext is UIDisplayArrayContext)
            {
                UIDisplayArrayContext dc;
                dc = (UIDisplayArrayContext)currentContext;
                dc.pgDownkeyPressed();
                return;
            }

            if (currentContext is UIInputArrayContext)
            {
                UIInputArrayContext dc;
                dc = (UIInputArrayContext)currentContext;
                dc.pgDownkeyPressed();
                return;
            }
            throw new NotImplementedException();
        }

        void tsBtnPgUp_Click(object sender, EventArgs e)
        {
            this.ErrorText = "";
            if (currentContext is UIDisplayArrayContext)
            {
                UIDisplayArrayContext dc;
                dc = (UIDisplayArrayContext)currentContext;
                dc.pgUpkeyPressed();
                return;
            }
            if (currentContext is UIInputArrayContext)
            {
                UIInputArrayContext dc;
                dc = (UIInputArrayContext)currentContext;
                dc.pgUpkeyPressed();
                return;
            }
            throw new NotImplementedException();
        }


        void b_Click(object sender, EventArgs e)
        {
            string reply;
            AubitTSBtn o;
            this.ErrorText = "";
            o = (AubitTSBtn)sender;
            reply = null;
            if (o.ID == null)
            {
               
                if (o.ActiveKey == "DIE")
                {
                    reply = o.ActiveKey;
                }
            } else {
                reply = o.ID;
            }
            if (reply == null) return;
            TopWindow. stdNetworkConnection.SendString("<TRIGGERED ID=\"" + reply + "\"/>");

        }

        public void ensureAcceptInterruptButtonsOnToolStrip()
        {
            if (tsBtnAccept==null) {
            
                addDefaultToolstripItems();
            }

        }

        public void AddToolBarKey(string Key, string Text, string ID)
        {
            AubitTSBtn b;

            ensureAcceptInterruptButtonsOnToolStrip();

            // Does it already exist ? 
            for (int a = 0; a < Fkeys.Count; a++)
            {
                if (Fkeys[a].ActiveKey == Key)
                {
                    //Fkeys[a].Text = Text;
                    return;
                }
            }

            // No - Create a new one..
            b = new AubitTSBtn();
            b.isProgramAdded = false;
            b.ActiveKey = Key;
            b.Text = Text;
            b.ID = ID;
            
            b.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.ImageAndText;
            b.Visible = false;
            //b.Click += new EventHandler(b_Click);
            b.clickHandler = b_Click;
            Fkeys.Add(b);
            this.toolStrip1.Add(b);
        }

        public void SetToolBarKeyLabel(string Key, string Text)
        {
            

            ensureAcceptInterruptButtonsOnToolStrip();

            // Does it already exist ? 
            for (int a = 0; a < Fkeys.Count; a++)
            {
                if (Fkeys[a].ActiveKey == Key)
                {
                    Fkeys[a].Text = Text;
                    return;
                }
            }
            AddToolBarKey(Key, Text, "");
        }

        private void addDefaultToolstripItems()
        {
            
                
                tsBtnAccept = new AubitDesktop.AubitTSBtn();
                tsBtnCancel = new AubitDesktop.AubitTSBtn();
                tsBtnUp = new AubitTSBtn();
                tsBtnDown = new AubitTSBtn();
                tsBtnPgUp = new AubitTSBtn();
                tsBtnPgDown = new AubitTSBtn();
                tsBtnInsert = new AubitTSBtn();
                tsBtnDelete = new AubitTSBtn();
                

                // 
                // tsBtnAccept
                // 
                this.tsBtnAccept.ActiveKey = "ACCEPT";
                this.tsBtnAccept.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
                this.tsBtnAccept.ID = "ACCEPT";
                this.tsBtnAccept.Image = global::AubitDesktop.ToolBarImages.accept;
                this.tsBtnAccept.ImageTransparentColor = System.Drawing.Color.Magenta;
                this.tsBtnAccept.Name = "tsBtnAccept";
                this.tsBtnAccept.Size = new System.Drawing.Size(23, 22);
                this.tsBtnAccept.Text = "Accept";
                this.tsBtnAccept.clickHandler= new System.EventHandler(this.tsBtnAccept_Click);
            
                // 
                // tsBtnCancel
                // 
                this.tsBtnCancel.ActiveKey = "INTERRUPT";
                this.tsBtnCancel.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
                this.tsBtnCancel.ID = "INTERRUPT";
                this.tsBtnCancel.Image = global::AubitDesktop.ToolBarImages.cancel;
                this.tsBtnCancel.ImageTransparentColor = System.Drawing.Color.Magenta;
                this.tsBtnCancel.Name = "tsBtnCancel";
                this.tsBtnCancel.Size = new System.Drawing.Size(23, 22);
                this.tsBtnCancel.Text = "Cancel";
                this.tsBtnCancel.clickHandler = new System.EventHandler(this.tsBtnCancel_Click);

                this.tsBtnAccept.Visible = true;
                this.tsBtnCancel.Visible = true;
                this.toolStrip1.Add(tsBtnAccept);
                this.toolStrip1.Add(tsBtnCancel);
                // tsBtnUp
                //
                this.tsBtnUp.ActiveKey = "Up";
                this.tsBtnUp.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
                this.tsBtnUp.ID = "Up";
                this.tsBtnUp.Image = global::AubitDesktop.ToolBarImages.arrup;
                this.tsBtnUp.ImageTransparentColor = System.Drawing.Color.Magenta;
                this.tsBtnUp.Name = "tsBtnUp";
                this.tsBtnUp.Size = new System.Drawing.Size(23, 22);
                this.tsBtnUp.Text = "Up";
                this.tsBtnUp.clickHandler = new System.EventHandler(tsBtnUp_Click);

                this.tsBtnUp.Visible = true;
                this.toolStrip1.Add(tsBtnUp);

                // tsBtnDown
                //
                this.tsBtnDown.ActiveKey = "Down";
                this.tsBtnDown.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
                this.tsBtnDown.ID = "Down";
                this.tsBtnDown.Image = global::AubitDesktop.ToolBarImages.arrdown;
                this.tsBtnDown.ImageTransparentColor = System.Drawing.Color.Magenta;
                this.tsBtnDown.Name = "tsBtnDown";
                this.tsBtnDown.Size = new System.Drawing.Size(23, 22);
                this.tsBtnDown.Text = "Down";
                this.tsBtnDown.clickHandler = new System.EventHandler(this.tsBtnDown_Click);

                this.tsBtnDown.Visible = true;
                this.toolStrip1.Add(tsBtnDown);


                // tsBtnPgDown
                //
                this.tsBtnPgDown.ActiveKey = "PgDn";
                this.tsBtnPgDown.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
                this.tsBtnPgDown.ID = "PgDn";
                this.tsBtnPgDown.Image = global::AubitDesktop.ToolBarImages.arrpgdown;
                this.tsBtnPgDown.ImageTransparentColor = System.Drawing.Color.Magenta;
                this.tsBtnPgDown.Name = "tsBtnPgDown";
                this.tsBtnPgDown.Size = new System.Drawing.Size(23, 22);
                this.tsBtnPgDown.Text = "PgDn";
                this.tsBtnPgDown.clickHandler = new System.EventHandler(this.tsBtnPgDown_Click);

                this.tsBtnPgDown.Visible = true;
                this.toolStrip1.Add(tsBtnPgDown);
                // tsBtnPgUp
                //
                this.tsBtnPgUp.ActiveKey = "PgUp";
                this.tsBtnPgUp.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
                this.tsBtnPgUp.ID = "PgUp";
                this.tsBtnPgUp.Image = global::AubitDesktop.ToolBarImages.arrpgup;
                this.tsBtnPgUp.ImageTransparentColor = System.Drawing.Color.Magenta;
                this.tsBtnPgUp.Name = "tsBtnPgUp";
                this.tsBtnPgUp.Size = new System.Drawing.Size(23, 22);
                this.tsBtnPgUp.Text = "PgUp";
                this.tsBtnPgUp.clickHandler = new System.EventHandler(this.tsBtnPgUp_Click);

                this.tsBtnPgUp.Visible = true;
                this.toolStrip1.Add(tsBtnPgUp);

                // tsBtnInsert
                //
                this.tsBtnInsert.ActiveKey = "INSERT";
                this.tsBtnInsert.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
                this.tsBtnInsert.ID = "Insert";
                this.tsBtnInsert.Image = global::AubitDesktop.ToolBarImages.neu;
                this.tsBtnInsert.ImageTransparentColor = System.Drawing.Color.Magenta;
                this.tsBtnInsert.Name = "tsBtnInsert";
                this.tsBtnInsert.Size = new System.Drawing.Size(23, 22);
                this.tsBtnInsert.Text = "Insert";
                this.tsBtnInsert.clickHandler = new System.EventHandler(this.tsBtnInsert_Click);

                this.tsBtnInsert.Visible = true;
                this.toolStrip1.Add(tsBtnInsert);


                // tsBtnDelete
                //
                this.tsBtnDelete.ActiveKey = "DELETE";
                this.tsBtnDelete.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
                this.tsBtnDelete.ID = "Delete";
                this.tsBtnDelete.Image = global::AubitDesktop.ToolBarImages.delete;
                this.tsBtnDelete.ImageTransparentColor = System.Drawing.Color.Magenta;
                this.tsBtnDelete.Name = "tsBtnDelete";
                this.tsBtnDelete.Size = new System.Drawing.Size(23, 22);
                this.tsBtnDelete.Text = "Delete";
                this.tsBtnDelete.clickHandler = new System.EventHandler(this.tsBtnDelete_Click);

                this.tsBtnDelete.Visible = true;
                this.toolStrip1.Add(tsBtnDelete);





        }


        /*
        public void ShowAcceptInterruptButtons()
        {

            tsBtnAccept.Visible = true;
            tsBtnCancel.Visible = true;

        }
         * */

        private void tsBtnCancel_Click(object sender, EventArgs e)
        {
            this.ErrorText = "";
            string eventText = "<TRIGGERED ID=\"INTERRUPT\"/>";
            TopWindow.SendString(eventText,true);
            currentContext.DeactivateContext();
        }


        private void tsBtnAccept_Click(object sender, EventArgs e)
        {
            this.ErrorText = "";
            string eventText = currentContext.getAcceptString();
            if (eventText != null)
            {
                TopWindow.SendString(eventText,true);
            }
            currentContext.DeactivateContext();
        }

        public void TabSelected()
        {
            TopWindow.MessageText = this.MessageText;
            TopWindow.ErrorText = this.ErrorText;
            TopWindow.CommentText = this.CommentText;
            TopWindow.LineDisplayText = this.LineDisplayText;
            
        }

        public void setErrorTextFromFieldValidation(string s)
        {
            switch (s)
            {
                case "CLEAR": clrErrorTextFromFieldValidation();return; /* We want to clear the error - not generate a new one */
                case "ARR_DIR_MSG": s = " There are no more rows in the direction you are going "; break;
                case "FIELD_ERROR_MSG": s = " Error in field "; break;
                case "FIELD_INCL_MSG": s = " This value is not among the valid possibilities "; break;
                case "FIELD_REQD_MSG": s = " This field required an entered value "; break;
                case "FIELD_PICTURE_MSG": s = " You cannot use this editing feature because a picture exists "; break;
                
                case "INPARRAY_FULL_MSG": s = " Cannot insert another row - the input array is full "; break;

            }
            // May want to do this some other way...
            this.ErrorText = s;
        }

        /*
        public void resetPing() {
            lastPing = DateTime.Now;
        }
        */


        /// <summary>
        /// Force a response every n seconds to ensure that the line is kept alive
        /// This is called from 'ConsumeEnvelopeCommands' which in turn is called from a timer...
        /// </summary>
        public void SendPing()
        {

            DateTime n;
            
            n=DateTime.Now;
            if (lastPingIsSet == false)
            {
                lastPing = n;
                lastPingIsSet = true;
            }
            else
            {
                if (n.Subtract(lastPing) > pingInterval)
                {
                    lastPing = n;
                    //MessageBox.Show("Ping!");
                    TopWindow.SendString("<PING/>",false);
                }
            }
            
        }


        public void ConsumeEnvelopeCommands()
        {
            int cnt = 0;
            List<object> run_commands;
            SendPing();
            //System.Diagnostics.Debug.WriteLine("In consume envelope commands (bottom level)");
            if (this.commands == null) return;
            if (this.commands.Count == 0) return;
            //System.Diagnostics.Debug.WriteLine("consuming...");
            this.SuspendLayout();

            // Make a copy of our commands to run through
            run_commands = new List<object>();
            foreach (object a in this.commands)
            {
                run_commands.Add(a);
            }
            //System.Diagnostics.Debug.WriteLine("Copied");
            ErrorText="";

            cnt = 0;
            // Go through one at a time...
            foreach (object a in run_commands)
            {
                //System.Diagnostics.Debug.WriteLine("IN foreach");
                TopWindow.setProgress( run_commands.Count,cnt);
                cnt++;
                //System.Diagnostics.Debug.WriteLine("Consuming event : " + cnt + " of " + run_commands.Count);
                #region PROGRAMSTARTUP
                if (a is PROGRAMSTARTUP)
                {
                    PROGRAMSTARTUP p;
                    string progname;
                    p = (PROGRAMSTARTUP)a;
                    this.Text = "Running : " + p.PROGRAMNAME + ", Logged in as " + this.Username + ", UniqID :" + p.ID;
                    progname = p.PROGRAMNAME;
                    if (progname.StartsWith("/"))
                    {
                        progname = progname.Substring(progname.LastIndexOf("/") + 1);
                    }
                    
                    this.TopWindow.addNewTabPage(Convert.ToInt32(p.ID), progname, this);


                    SetServerEnviron ( p.ENV);
                    commands.Remove(a);
                    //MessageBox.Show("Application would like to start! Program=" + p.PROGRAMNAME + " ID=" + p.ID);
                    continue;
                }
                #endregion
                #region FILE
                if (a is FILE)
                {
                    if (Program.AppSettings.allowReceiveFile)
                    {
                        FILE f;
                        FileStream fs = null;
                        BinaryWriter sw;
                        byte[] data;
                        f = (FILE)a;
                        if (f.CLIENTNAME != null && f.CLIENTNAME.Length > 0)
                        {
                            fs = new FileStream(f.CLIENTNAME, FileMode.Create, FileAccess.Write);
                        }
                        else
                        {
                            try
                            {
                                fs = new FileStream(f.NAME, FileMode.Create, FileAccess.Write);
                            }
                            catch (Exception Ex)
                            {
                                MessageBox.Show(Ex.ToString());
                            }
                        }
                        if (fs != null)
                        {
                            sw = new BinaryWriter(fs);
                            data = Convert.FromBase64String(f.Text);
                            sw.Write(data);
                            sw.Flush();
                            sw.Close();
                            fs.Close();
                        }
                    }
                    else
                    {
                        MessageBox.Show("The 4GL program tried to send a file " + ((FILE)a).NAME + " but this is disallowed by the Aubit Desktop Client settings");
                    }
                    commands.Remove(a);
                    continue;
                }
                #endregion
                #region EXECUTE
                if (a is EXECUTE)
                {
                    //MessageBox.Show(((EXECUTE)a).Text,"EXECUTE");
                    if (Program.AppSettings.allowExec)
                    {
                        System.Diagnostics.Process.Start(((EXECUTE)a).Text);
                    }
                    else
                    {
                        MessageBox.Show("The 4GL program tried to execute " + ((EXECUTE)a).Text + " but this is disallowed by the Aubit Desktop Client settings");
                    }
                    commands.Remove(a);
                    continue;
                }
                #endregion
                #region UIDIRECT
                if (a is UIDIRECT)
                {
                    MessageBox.Show(((UIDIRECT)a).Text,"UIDIRECT");
                    commands.Remove(a);
                    continue;
                }
                #endregion
                #region SETWINDOWTITLE
                if (a is SETWINDOWTITLE)
                {
                    this.TopWindow.setTabTitle(this,((SETWINDOWTITLE)a).TEXT);
                    commands.Remove(a);
                    continue;
                }
                #endregion
                #region SETKEYLABEL
                if (a is SETKEYLABEL)
                {
                    SETKEYLABEL k;
                    k = (SETKEYLABEL)a;
                    SetToolBarKeyLabel(k.LABEL, k.TEXT);
                    commands.Remove(a);
                    continue;
                }
                #endregion
                #region CLEARFORM
                if (a is CLEARFORM)
                {
                    commands.Remove(a);
                    continue;
                } 
                #endregion
                #region CLEARWINDOW
                if (a is CLEARWINDOW)
                {
                    CLEARWINDOW c;
                    c = (CLEARWINDOW)a;
                    ApplicationWindows.ClearWindow(c.WINDOW);
                    commands.Remove(a);
                    continue;
                } 
                #endregion
                #region NEXTFIELD
                if (a is NEXTFIELD)
                {
                    NEXTFIELD f;
                    f = (NEXTFIELD)a;
                    
                    if (Convert.ToInt32(f.CONTEXT) >= 0)
                    {
                        contexts[Convert.ToInt32(f.CONTEXT)].setNextField(f.FIELD);
                    }
                    else
                    {
                        ApplicationWindows.setNextField(f.FIELD);
                    }
                    commands.Remove(a);
                    continue;
                }
                #endregion
                #region CURRENTWINDOW
                if (a is CURRENTWINDOW)
                {
                    CURRENTWINDOW c;
                    c = (CURRENTWINDOW)a;
                    ApplicationWindows.MoveWindowToTop(c.WINDOW);
                    commands.Remove(a);
                    continue;
                } 
                #endregion
                #region CLOSEWINDOW
                if (a is CLOSEWINDOW)
                {
                    CLOSEWINDOW c;
                    c = (CLOSEWINDOW)a;
                    ApplicationWindows.PopWindow(c.WINDOW);
                    commands.Remove(a);
                    continue;
                }
                #endregion
                #region OPTIONS
                if (a is OPTIONS)
                {
                    OPTIONS o;
                    o = (OPTIONS)a;
                    options.SetOption(o.TYPE, o.VALUE);
                    commands.Remove(a);
                    continue;
                } 
                #endregion
                #region ADDTOTOOLBAR
                if (a is ADDTOTOOLBAR)
                {
                    AubitTSBtn btn;
                    ADDTOTOOLBAR o;

                    btn=null;
                    o = (ADDTOTOOLBAR)a;
                    foreach (AubitTSBtn b in programButtons)
                    {
                        if (b.programTag == o.TAG)
                        {
                            btn = b; break;
                        }
                    }
                    if (btn == null)
                    {
                        btn = new AubitTSBtn();
                        btn.programTag = o.TAG;
                        programButtons.Add(btn);
                    }
                    btn.ActiveKey = o.KEYVAL;
                    btn.isProgramAdded = true;
                    btn.Text = o.BUTTON;
                    btn.programTag = o.TAG;
                    btn.clickHandler = b_Click;
                    try
                    {
                        //Image i = getImageFromName(o.IMAGE);
                        btn.Image=FGLUtils.getImageFromName( o.IMAGE);
                    }
                    catch
                    {
                    }
                    btn.ToolTipText = o.TOOLTIP;
                    toolStrip1.Add(btn);
                    commands.Remove(a);
                    continue;
                } 

                #endregion
                #region DISPLAYFORM
                if (a is DISPLAYFORM)
                {
                    DISPLAYFORM d;
                    FGLForm frm = null;
                    d = (DISPLAYFORM)a;
                    frm = OpenForms.getForm(d.FORMNAME);
                    if (frm != null)
                    {
                        ApplicationWindows.setForm(frm);
                        this.MinimumSize = new System.Drawing.Size(GuiLayout.get_gui_w(ApplicationWindows.minimumScreenWidth), GuiLayout.get_gui_h(ApplicationWindows.minimumScreenHeight));
                        //this.BorderStyle = BorderStyle.Fixed3D;
                        //this.BackColor = System.Drawing.Color.Red;

                    }
                    else
                    {
                        MessageBox.Show("Unable to find form " + d.FORMNAME);
                    }
                    commands.Remove(a);
                    continue;

                } 
                #endregion
                #region CLOSEFORM
                if (a is CLOSEFORM)
                {
                    CLOSEFORM d;
                    FGLForm frm = null;
                    d = (CLOSEFORM)a;
                    frm = OpenForms.getForm(d.FORMNAME);
                    if (frm != null)
                    {
                        OpenForms.removeForm(d.FORMNAME);
                    }
                    else
                    {
                        MessageBox.Show("Unable to find form " + d.FORMNAME);
                    }
                    commands.Remove(a);
                    continue;
                }
                #endregion
                #region DISPLAYAT
                if (a is DISPLAYAT)
                {
                    Console.WriteLine("DISPLAY .. AT is not support for GUI - please recode your application");
                 //   MessageBox.Show("DISPLAY .. AT is not support for GUI - please recode your application");
                    commands.Remove(a);
                    continue;
                }
                #endregion
                #region REQUESTFILE
                if (a is REQUESTFILE)
                {
                    if (Program.AppSettings.allowSendFile)
                    {
                        string s = "";
                        long flen = -1;
                        string fileID;
                        FileStream f;
                        REQUESTFILE r;
                        byte[] fileContents = null;

                        r = (REQUESTFILE)a;
                        fileID = r.FILEID;
                        try
                        {
                            f = new FileStream(r.FILEID, FileMode.Open, FileAccess.Read);
                            BinaryReader sr = new BinaryReader(f);
                            flen = f.Length;
                            fileContents = sr.ReadBytes((int)f.Length);
                            sr.Close();
                            f.Close();
                        }
                        catch (Exception )
                        {
                            fileID = "";
                        }

                        if (fileContents != null)
                        {
                            s = "<TRIGGERED ID=\"FILEREQUEST\" FILEID=\"" + System.Security.SecurityElement.Escape(fileID) + "\" FILELEN=\"" + flen + "\">";
                            s += "<SYNCVALUES><SYNCVALUE>";
                            s += Convert.ToBase64String(fileContents);
                            s += "</SYNCVALUE></SYNCVALUES>";
                            s += "</TRIGGERED>";
                            TopWindow.SendString(s,true);
                        }
                    }
                    else
                    {
                        MessageBox.Show("The 4GL program tried to request a file  " + ((REQUESTFILE)a).FILEID + " but this is disallowed by the Aubit Desktop Client settings");
                    }
                    commands.Remove(a);

                    continue;
                }
                #endregion
                #region UIOPTION
                if (a is UIOPTION)
                {
                    UIOPTION u;
                    u = (UIOPTION)a;
                    switch (u.NAME)
                    {
                        case "MENUBAR":
                            switch (u.VALUE.ToUpper())
                            {
                                case "AUTO":
                                    TopWindow.showMenuBar = showMode.ShowAuto;
                                    break;
                                case "ALWAYS":
                                    TopWindow.showMenuBar = showMode.ShowAlways;
                                    break;
                                case "NEVER":
                                    TopWindow.showMenuBar = showMode.ShowNever;
                                    break;
                            }
                            break;
                        case "TOOLBAR":
                            switch (u.VALUE.ToUpper())
                            {
                                case "AUTO":
                                    TopWindow.showToolbar= showMode.ShowAuto;
                                    break;
                                case "ALWAYS":
                                    TopWindow.showToolbar = showMode.ShowAlways;
                                    break;
                                case "NEVER":
                                    TopWindow.showToolbar = showMode.ShowNever;
                                    break;
                            }
                            break;

                        case "APPLICATIONLAUNCHER":
                            switch (u.VALUE.ToUpper())
                            {
                                case "AUTO":
                                    TopWindow.showApplicationLauncher = showMode.ShowAuto;
                                    break;
                                case "ALWAYS":
                                    TopWindow.showApplicationLauncher = showMode.ShowAlways;
                                    break;
                                case "NEVER":
                                    TopWindow.showApplicationLauncher = showMode.ShowNever;
                                    break;
                            }
                            break;

                        case "SHOWAPPLICATIONTREE":
                            TopWindow.loadApplicationLauncherTree(u.VALUE);
                            break;
                        case "WORKSPACEBACKGROUND":
                            //this.BackgroundImage = FGLUtils.getImageFromName(u.VALUE);
                            //this.BackgroundImageLayout = ImageLayout.Stretch;
                            winScreen.WindowWidget.BackgroundImage = FGLUtils.getImageFromName(u.VALUE);
                            winScreen.WindowWidget.BackgroundImageLayout = ImageLayout.Center;
                            break;
                    }
                    commands.Remove(a);

                    continue;
                }
                #endregion
                #region OPENFORM
                if (a is OPENFORM)
                {
                    OPENFORM o = (OPENFORM)a;
                    if (o.XMLFORM != null)
                    {
                        FGLForm frm = new FGLForm(o.XMLFORM);
                        OpenForms.addForm(o.FORMNAME, frm);
                    }
                    else
                    {
                        if (o.FORM.ATTRIBUTES != null)
                        {
                            FGLForm frm = new FGLForm(o.FORM);
                            OpenForms.addForm(o.FORMNAME, frm);
                        }
                        else
                        {
                            Console.WriteLine("No form!!!");
                        }
                    }

                    commands.Remove(a);
                    continue;
                } 
                #endregion
                #region MENU
                if (a is MENU)
                {
                    MENU theMenu = (MENU)a;
                    contexts.Insert(Convert.ToInt32(theMenu.CONTEXT), new UIMenuContext(this, theMenu));
                    commands.Remove(a);
                    continue;
                }
                #endregion
                #region PROMPT
                if (a is PROMPT)
                {
                    PROMPT thePrompt = (PROMPT)a;
                    contexts.Insert(Convert.ToInt32(thePrompt.CONTEXT), new UIPromptContext(this, thePrompt));
                    commands.Remove(a);
                    continue;
                }
                #endregion
                #region OPENWINDOWWITHFORM
                if (a is OPENWINDOWWITHFORM)
                {
                    FGLForm frm;
                    FGLWindow win;
                    bool border;
                    OPENWINDOWWITHFORM w;
                    w = (OPENWINDOWWITHFORM)a;

                    if (w.XMLFORM != null)
                    {
                        frm = new FGLForm(w.XMLFORM);
                    }
                    else
                    {
                        frm = new FGLForm(w.FORM);
                    }
                    if (w.BORDER == "0") border = false; else border = true;
                    win = new FGLWindow(w.WINDOW, Convert.ToInt32(w.X), Convert.ToInt32(w.Y), Convert.ToInt32(w.ATTRIBUTE), w.TEXT, w.STYLE, Convert.ToInt32(w.ERROR_LINE), Convert.ToInt32(w.PROMPT_LINE), Convert.ToInt32(w.MENU_LINE), Convert.ToInt32(w.COMMENT_LINE), Convert.ToInt32(w.MESSAGE_LINE), border);

                    win.setForm(frm, false);

                    win.sizeWindow(frm);

                    // Our 'window' might be a proper windows forms window (with title bar etc)
                    // in which case - we dont want to add it to our windows panel - but just 
                    // let it float...
                    if (win.isContainable)
                    {
                        this.Controls.Add(win.WindowWidget);
                    }

                    if (win.isModal)
                    {
                        // This doesn't seem to work atm - gettting errors 
                        // saying you cant show it as its already visible - even though its not!
                            win.WindowWidget.Visible = false;
                         TopWindow.ShowDialog(win.WindowWidget);
                    }

                    ApplicationWindows.PushWindow(win);
                    this.MinimumSize = new System.Drawing.Size(GuiLayout.get_gui_w(ApplicationWindows.minimumScreenWidth), GuiLayout.get_gui_h(ApplicationWindows.minimumScreenHeight));
                    commands.Remove(a);
                    continue;

                }
                #endregion
                #region CREATEWINDOW
                if (a is CREATEWINDOW)
                {
                    FGLWindow win;
                    bool border;
                    CREATEWINDOW w;
                    w = (CREATEWINDOW)a;
                    if (w.BORDER == "0") border = false; else border = true;
                    win = new FGLWindow(w.NAME, Convert.ToInt32(w.X), Convert.ToInt32(w.Y), Convert.ToInt32(w.ATTRIBUTE), w.TEXT, w.STYLE, Convert.ToInt32(w.ERRORLINE), Convert.ToInt32(w.PROMPTLINE), Convert.ToInt32(w.MENULINE), Convert.ToInt32(w.COMMENTLINE), Convert.ToInt32(w.MESSAGELINE), border);

                    win.sizeWindow(Convert.ToInt32(w.W), Convert.ToInt32(w.H));             

                    // Our 'window' might be a proper windows forms window (with title bar etc)
                    // in which case - we dont want to add it to our windows panel - but just 
                    // let it float...
                    if (win.isContainable)
                    {
                        this.Controls.Add(win.WindowWidget);
                    }

                    if (win.isModal)
                    {
                        // This doesn't seem to work atm - gettting errors 
                        // saying you cant show it as its already visible - even though its not!
                        win.WindowWidget.Visible = false;
                        TopWindow.ShowDialog(win.WindowWidget);
                    }

                    ApplicationWindows.PushWindow(win);
                    this.MinimumSize = new System.Drawing.Size(GuiLayout.get_gui_w(ApplicationWindows.minimumScreenWidth), GuiLayout.get_gui_h(ApplicationWindows.minimumScreenHeight));
                    commands.Remove(a);
                    continue;

                }
                #endregion
                #region INPUTARRAY
                if (a is INPUTARRAY)
                {
                    INPUTARRAY ia = (INPUTARRAY)a;
                    contexts.Insert(Convert.ToInt32(ia.CONTEXT), new UIInputArrayContext(this, ia));
                    commands.Remove(a);
                    continue;
                }
                #endregion
                #region DISPLAYARRAY
                if (a is DISPLAYARRAY)
                {
                    DISPLAYARRAY da = (DISPLAYARRAY)a;
                    contexts.Insert(Convert.ToInt32(da.CONTEXT), new UIDisplayArrayContext(this,da));
                    commands.Remove(a);
                    continue;
                }
                #endregion
                #region CONSTRUCT
                if (a is CONSTRUCT)
                {
                    CONSTRUCT i;
                    i = (CONSTRUCT)a;

                    contexts.Insert(Convert.ToInt32(i.CONTEXT), new UIConstructContext(this, i));
                    commands.Remove(a);
                    continue;
                }
                #endregion
                #region INPUT
                if (a is INPUT)
                {
                    INPUT i;
                    i = (INPUT)a;
                    
                    contexts.Insert(Convert.ToInt32(i.CONTEXT), new UIInputContext(this, i));

                    commands.Remove(a);
                    continue;
                }
                #endregion
                #region DISPLAYTO
                if (a is DISPLAYTO)
                {
                    DISPLAYTO d;
                    d = (DISPLAYTO)a;
                    ApplicationWindows.DisplayTo(d);
                    commands.Remove(a);
                    continue;
                }
                #endregion
                #region ERROR
                if (a is ERROR)
                {
                    ERROR e;
                    e = (ERROR)a;
                    ErrorText = e.Text;
                    commands.Remove(a);
                    continue;
                }
                #endregion
                #region MESSAGE
                if (a is MESSAGE)
                {
                    MESSAGE b;
                    b = (MESSAGE)a;
                    if (Convert.ToInt32(b.WAIT) != 0)
                    {
                        MessageBox.Show(b.Text,"Application Message");
                    }
                    else
                    {
                        MessageText = b.Text;
                        Application.DoEvents();
                    }
                    commands.Remove(a);
                    continue;
                }
                #endregion
                #region DISPLAY
                if (a is DISPLAY)
                {
                    DISPLAY theDISPLAY = (DISPLAY)a;
                    this.TopWindow.AddTextToConsole(theDISPLAY.Text[0]);
                    commands.Remove(a);
                    continue;
                }
                #endregion
                #region HIDEOPTION
                if (a is HIDEOPTION)
                {
                    HIDEOPTION ho;
                    UIMenuContext mc;
                    ho = (HIDEOPTION)a;

                    int idx = Convert.ToInt32(ho.CONTEXT);
                    mc = (UIMenuContext)contexts[idx];
                    mc.hideOption(ho.OPTION);
                    commands.Remove(a);
                    continue;
                }

                #endregion
                #region NEXTOPTION
                if (a is NEXTOPTION)
                {
                    NEXTOPTION ho;
                    UIMenuContext mc;
                    ho = (NEXTOPTION)a;

                    int idx = Convert.ToInt32(ho.CONTEXT);
                    mc = (UIMenuContext)contexts[idx];
                    mc.nextOption(ho.OPTION);
                    commands.Remove(a);
                    continue;
                }
                #endregion
                #region PROGRAMSTOP
                if (a is PROGRAMSTOP)
                {
                    PROGRAMSTOP p;
                    p = (PROGRAMSTOP)a;
                    if (Convert.ToInt32(p.EXITCODE) != 0)
                    {
                        string txt = "";
                        int idx;
                        for (idx = 0; idx < p.line.Length; idx++)
                        {
                            txt += p.line[idx].Text + "\n";
                        }
                        MessageBox.Show("Program Exited with non-zero exit status\n" + txt);
                    }
                    commands.Remove(a);
                    TopWindow.clrWaitCursor();
                    TopWindow.removeTabPage(this);
                    continue;
                }
                #endregion
                #region FREE
                if (a is FREE)
                {
                    FREE f;
                    f = (FREE)a;
                    contexts[Convert.ToInt32(f.CONTEXT)].DeactivateContext();
                    contexts[Convert.ToInt32(f.CONTEXT)].FreeContext();
                    contexts[Convert.ToInt32(f.CONTEXT)] = null;
                    commands.Remove(a);
                    continue;
                }
                #endregion
                #region SHOWOPTION
                if (a is SHOWOPTION)
                {
                    SHOWOPTION so;
                    UIMenuContext mc;
                    so = (SHOWOPTION)a;

                    int idx = Convert.ToInt32(so.CONTEXT);
                    mc = (UIMenuContext)contexts[idx];
                    mc.showOption(so.OPTION);
                    commands.Remove(a);
                    continue;
                }
                #endregion
                #region WAITFOREVENT
                if (a is WAITFOREVENT)
                {
                    //string rval;
                    WAITFOREVENT w;

                    w = (WAITFOREVENT)a;
                    //MessageBox.Show("Here" );
                    int idx;
                    for (idx = 0; idx < contexts.Count; idx++)
                    {

                        if (idx == Convert.ToInt32(w.CONTEXT))
                        { // This is the active context
                            if (contexts[idx] != null)
                            {
                                TopWindow.clrWaitCursor();
                                contexts[idx].ActivateContext(UIContext_EventTriggered,w.VALUES, w.ROWS);
                                currentContext = contexts[idx];
                            }
                            else
                            {
                                MessageBox.Show("Internal error - no context object");
                            }
                        }
                        else
                        {
                            if (contexts[idx] != null)
                            {
                                contexts[idx].DeactivateContext();
                            }
                        }
                        commands.Remove(a);
                    }
                    continue;
                }
                #endregion
                commands.Remove(a);
                this.TopWindow.AddTextToConsole(" Unhandled: " + a.ToString());
                MessageBox.Show(" Unhandled: " + a.ToString());
            }
            try {
                // This may fail if the window is closed because the application that
                // was in it is now closed - but we dont care about updating the progress bar in an invisible window ;-)
            TopWindow.setProgress(0,0);
                }
            catch (Exception ) {
                }

            // We might get to here if we're waiting for an event - but thats ok - because it will stay in the queue...
            this.ResumeLayout();
        }



        


        public string getServerEnviron(string n)
        {
            if (serverEnviron.ContainsKey(n))
            {
                return (string)serverEnviron[n];
            }
            return "";
        }

        private void SetServerEnviron(ENV[] eNV)
        {
            serverEnviron = new Hashtable();
            for (int a = 0; a < eNV.Length; a++)
            {
                serverEnviron.Add(eNV[a].NAME, eNV[a].VALUE);
                if (eNV[a].NAME == "DBDATE")
                {
                    FGLUtils.DBDATE = eNV[a].VALUE;
                }
            }
        }

        internal void NavigateToTab() {
            if (currentContext!=null)
            {
                currentContext.NavigateToTab();
            }
        }

        internal void NavigateAwayTab()
        {
            if (currentContext != null)
            {
                currentContext.NavigateAwayTab();
            }
        }


        internal void setPrompt(Control p)
        {
            
            p.Width = this.Width-10;
            ApplicationWindows.setPrompt(p, this.options.PromptLine);
        }


        internal void ActivatePrompt(UIEventHandler UIPromptContext_EventTriggered)
        {
            // Not sure this needs to do anything....
        }

        internal void RemovePrompt(Control p)
        {
            ApplicationWindows.ClearPrompt(p);
        }

        /*
        internal void doTest()
        {
            ApplicationWindows.doInput(null);
        }
         * */

        public void saveWindow()
        {
            ApplicationWindows.saveWindow();
        }

        public void SetContext(FGLContextType contextType)
        {
            ApplicationWindows.SetContext(contextType);
        }

        public void SetContext(FGLContextType contextType, List<FGLWidget> pfields, UIContext currContext)
        {
            ApplicationWindows.SetContext(contextType, pfields, currContext);
        }

        public List<FGLFoundField> FindFields(FIELD[] fieldlist)
        {
            return ApplicationWindows.FindFields(fieldlist);
        }

        public List<FGLFoundField> FindFields(string[] fieldlist)
        {
            return ApplicationWindows.FindFields(fieldlist);
        }



        /*
        internal void HideAcceptInterruptButtons()
        {
            tsBtnAccept.Visible = false;
            tsBtnCancel.Visible = false;
        }
        */


        internal void SetContext(FGLContextType p, List<FGLFoundField> activeFields, UIContext currContext)
        {
            int cnt = 0;
            List<FGLWidget> l = new List<FGLWidget>();
            foreach (FGLFoundField fld in activeFields) {
                fld.fglField.tabIndex = cnt++;
                l.Add(fld.fglField);
            }
            SetContext(p, l,currContext);
        }

        internal List<FGLFoundField> FindField(string p)
        {
            string[] arr;
            List<FGLFoundField> l;
            arr=new string[1];
            arr[0] = p;
            l=FindFields(arr);
            return l;

            
            
        }

        internal void setLastKey(string keycode)
        {
            this.lastKey = keycode;
        }


        /// <summary>
        /// Finds all fields with a specified 'Action' tag
        /// </summary>
        /// <param name="p">tag to search for</param>
        /// <returns>All matching fields with the specified action tag</returns>
        internal List<FGLFoundField> FindAction(string p)
        {
            List<FGLFoundField> l;
            
            l= ApplicationWindows.FindAction(p);
            return l;
        }

        internal List<FGLFoundField> FindFieldArray(FIELD[] fieldlist)
        {
            return ApplicationWindows.FindFieldArray(fieldlist);
            
        }

        internal void clrErrorTextFromFieldValidation()
        {
            ErrorText = "";
        }
    }

}