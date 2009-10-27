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
    public class FGLApplicationPanel  : Panel
    {
        private FGLOptions options;
        public int ApplicationEnvelopeID;
        private List<UIContext> contexts;
      //  private List<AubitTSBtn> Fkeys;
        private string _errortext;
        private string _commenttext;
        private string _messagetext;
        private string _linedisplaytext;
        private List<AubitTSBtn> toolStrip1;
        private string ApplicationName;
        private string Username;
        private UIContext immediateContext = null;
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
        internal frmMainAppWindow TopWindow; // The window containing the tabpage control
        private string lastKey;

        public string LastKey
        {
            get { return lastKey; }
            set { lastKey = value; }
        }


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
            this.toolStrip1 = new List<AubitDesktop.AubitTSBtn>();


            this.AutoScroll = true;
            this.SetAutoScrollMargin(5, 5);
            
          //  this.Fkeys = new List<AubitTSBtn>();
            this.AutoSize = true;
            this.Dock = DockStyle.Fill;
            this.Visible = true;
            this.Enabled = true;


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



        void UIContext_EventTriggered(object source, string ID, string TriggeredText,UIContext u)
        {
            if (u == null) u = currentContext;

            if (u != currentContext) { Console.WriteLine("Trigger for non current context"); return; }
            if (TriggeredText == null)
            {
                TriggeredText = "";
            }

            if (TriggeredText == "")
            {
                TriggeredText="<TRIGGERED ID=\""+ID+"\"/>";
            }


            // Add in our socket definition...
            TriggeredText = TriggeredText.Replace("<TRIGGERED ", "<TRIGGERED ENVELOPEID=\"" + this.ApplicationEnvelopeID + "\" ");

           TopWindow.SendString(TriggeredText,true);
           if (immediateContext != null)
           {
               immediateContext.FreeContext();
               immediateContext = null;
           }
           u.DeactivateContext();
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
            foreach (AubitTSBtn i in toolStrip1) {

                    if (i.ActiveKey == key) return true;

            }
            return false;
        }


        public bool hasActionInToolbar(string action)
        {
            int keyCode;
            keyCode = FGLUtils.getKeyCodeFromKeyName(action);
            if (keyCode != -1)
            {
                action = "" + keyCode;
            }

            foreach (AubitTSBtn i in toolStrip1)
            {


                if (i.ActiveKey == action) return true;
                if (i.ActiveKey == ""+FGLUtils.getKeyCodeFromKeyName(action)) return true;

            }
            return false;
        }



        internal AubitTSBtn getKeyFromToolbar(string key)
        {

            foreach (AubitTSBtn i in toolStrip1)
            {
               
               
                    if (i.ActiveKey == key) return i;
                    if (i.ActiveKey == ""+FGLUtils.getKeyCodeFromKeyName(key)) return i;
                
            }



            return null;
        }


        public void setActiveToolBarKeys(List<ONKEY_EVENT> keys, List<ON_ACTION_EVENT> actions, bool showAcceptInterrupt)
        {
            setActiveToolBarKeys(keys,actions, showAcceptInterrupt,false,false);
        }

        public void setActiveToolBarKeys(List<ONKEY_EVENT> keys, List<ON_ACTION_EVENT> actions, bool showAcceptInterrupt, bool showUpDownButtons, bool showInsertDeleteButtons)
        {
            this.SuspendLayout();



            // We dont want any keys active ? 
            if (keys == null && actions==null)
            {
                foreach (AubitTSBtn o in toolStrip1)
                {
                    if (AubitTSBtn.isSystemAction(o.ID)) continue;
                        o.ID = null;
                    
                }

                if (tsBtnCancel!=null)
                {
                    tsBtnCancel.Visible = false;
                    tsBtnAccept.Visible = false;
                    setStockButtons(false, false, false);
                }
            }
            else
            {



                ensureAcceptInterruptButtonsOnToolStrip();
                setStockButtons(showAcceptInterrupt, showUpDownButtons, showInsertDeleteButtons);


                // Ok - there are some keys - but not all of them will be used..
                // so we need to remove any that are not in use by making them invisible
                foreach (AubitTSBtn o in toolStrip1)
                {
                        if (AubitTSBtn.isSystemAction(o.ID)) continue;
                        o.ID = null;

                }

                if (keys != null)
                {
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
                        o = getKeyFromToolbar(key.KEY);
                        if (o == null)
                        {
                            throw new Exception("This shouldn't happen - key is missing from menubar");
                        }
                        else
                        {
                            o.ID = key.ID;
                        }
                    }
                }

                if (actions != null)
                {
                    // we'll move through our keys and enable them...
                    foreach (ON_ACTION_EVENT action in actions)
                    {
                        AubitTSBtn o;

                        // Has the key already been added ? 
                        if (!hasActionInToolbar(action.ACTION))
                        {
                            // Dang - we need to add it..
                            AddToolBarAction(action.ACTION, action.ID);
                        }

                        // This should never fail - because we've added it if it was missing!
                        o = getKeyFromToolbar(action.ACTION);
                        if (o == null)
                        {
                            MessageBox.Show("Program error : No toolbar button exists for action " + action.ACTION);
                           // throw new Exception("This shouldn't happen - key is missing from menubar");
                        }
                        else
                        {
                            o.ID = action.ID;
                        }
                    }
                }
            }

            // Ensure that there are no options which are disabled by a HIDE OPTION or SHOW OPTION
            // These will be disabled in the ActivateContext of the Menu itself *AFTER* this function has been 
            // called...
            foreach (AubitTSBtn a in toolStrip1)
            {
                a.forceDisable = false;
            }
            TopWindow.setToolbar(toolStrip1);
            this.ResumeLayout();
        }




        private void setStockButtons(bool showAcceptInterrupt, bool showUpDownButtons, bool showInsertDeleteButtons)
        {
            if (showAcceptInterrupt)
            {
                if (tsBtnCancel != null)
                {
                    
                    tsBtnAccept.Visible = true;
                    tsBtnCancel.Visible = true;
                }
            }
            else
            {
                tsBtnAccept.Visible = false;
                tsBtnCancel.Visible = false;
            }

            if (showInsertDeleteButtons)
            {
                tsBtnDelete.Visible = true;
                tsBtnInsert.Visible = true;
            }
            else
            {
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
        }


        void tsBtnUp_Click(object sender, EventArgs e)
        {
            this.ErrorText = "";
            KeyEventArgs ke = null;
            if (e != null)
            {
                if (e.GetType() == typeof(KeyEventArgs))
                {
                    ke = (KeyEventArgs)e;
                }
            }
            if (currentContext is UIDisplayArrayContext)
            {
                UIDisplayArrayContext dc;
                dc = (UIDisplayArrayContext)currentContext;
                dc.upkeyPressed();
                if (ke != null)
                {
                    ke.Handled = true;
                    ke.SuppressKeyPress = true;
                }
                return;
                
            }
            if (currentContext is UIInputArrayContext)
            {
                UIInputArrayContext dc;
                dc = (UIInputArrayContext)currentContext;
                dc.upkeyPressed();
                if (ke != null)
                {
                    ke.Handled = true;
                    ke.SuppressKeyPress = true;
                }
                return;
            }

            if (currentContext is UIInputArrayInTableContext)
            {
                if (e != null)
                {
                    // Its a real button click - if it was a fake click because of a 
                    // matched keypress e would be null...
                    UIInputArrayInTableContext ic;
                    ic = (UIInputArrayInTableContext)currentContext;
                    ic.upkeyPressed();
                }
                return;
            }

            if (currentContext is UIDisplayArrayInTableContext)
            {
                // Let the ui handle it..
                if (e != null)
                {
                    // Its a real button click - if it was a fake click because of a 
                    // matched keypress e would be null...
                    //Program.Show("Null");
                    UIDisplayArrayInTableContext dc;
                    dc = (UIDisplayArrayInTableContext)currentContext;
                    dc.upkeyPressed();
                }
                return;
            }

            throw new NotImplementedException();
        }

        void tsBtnDown_Click(object sender, EventArgs e)
        {
           
            this.ErrorText = "";

            KeyEventArgs ke = null;
            if (e!=null)
            {
                if (e.GetType() == typeof(KeyEventArgs))
                {
                    ke = (KeyEventArgs)e;
                }
            }
            if (currentContext is UIDisplayArrayContext)
            {
                UIDisplayArrayContext dc;
                dc = (UIDisplayArrayContext)currentContext;
                dc.downkeyPressed();
                if (ke!=null)
                {
                    ke.Handled = true;
                    ke.SuppressKeyPress = true;
                }
                return;
            }
            if (currentContext is UIInputArrayContext)
            {
                UIInputArrayContext dc;
                dc = (UIInputArrayContext)currentContext;
                dc.downkeyPressed();
                if (ke!=null)
                {
                    ke.Handled = true;
                    ke.SuppressKeyPress = true;
                }
                return;
            }


            if (currentContext is UIDisplayArrayInTableContext)
            {
                // Let the ui handle it..
                if (e != null)
                {
                    // Its a real button click - if it was a fake click because of a 
                    // matched keypress e would be null...
                    //Program.Show("Null");
                    UIDisplayArrayInTableContext dc;
                    dc = (UIDisplayArrayInTableContext)currentContext;
                    dc.downkeyPressed();
                }
                // Let the ui handle it..
                return;
            }

            if (currentContext is UIInputArrayInTableContext)
            {
                // Let the ui handle it..
                if (e != null)
                {
                    // Its a real button click - if it was a fake click because of a 
                    // matched keypress e would be null...
                    UIInputArrayInTableContext ic;
                    ic = (UIInputArrayInTableContext)currentContext;
                    ic.downkeyPressed();
                }
                // Let the ui handle it..
                return;
            }

            throw new NotImplementedException();
            
        }


        void tsBtnInsert_Click(object sender, EventArgs e)
        {
            this.ErrorText = "";
            KeyEventArgs ke = null;
            if (e != null)
            {
                if (e.GetType() == typeof(KeyEventArgs))
                {
                    ke = (KeyEventArgs)e;
                }
            }
            if (currentContext is UIInputArrayContext)
            {
                UIInputArrayContext dc;
                dc = (UIInputArrayContext)currentContext;
                dc.InsertkeyPressed();
                if (ke != null)
                {
                    ke.Handled = true;
                    ke.SuppressKeyPress = true;
                }
                return;
            }

            if (currentContext is UIInputArrayInTableContext)
            {
                UIInputArrayInTableContext dc;
                dc = (UIInputArrayInTableContext)currentContext;
                dc.InsertkeyPressed();
                if (ke != null)
                {
                    ke.Handled = true;
                    ke.SuppressKeyPress = true;
                }
                return;
            }
        }

        void tsBtnDelete_Click(object sender, EventArgs e)
        {
            KeyEventArgs ke = null;
            if (e != null)
            {
                if (e.GetType() == typeof(KeyEventArgs))
                {
                    ke = (KeyEventArgs)e;
                }
            }
            this.ErrorText = "";
            this.ErrorText = "";
            if (currentContext is UIInputArrayContext)
            {
                UIInputArrayContext dc;
                dc = (UIInputArrayContext)currentContext;
                dc.DeletekeyPressed();
                if (ke != null)
                {
                    ke.Handled = true;
                    ke.SuppressKeyPress = true;
                }
                return;
            }

            if (currentContext is UIInputArrayInTableContext)
            {
                UIInputArrayInTableContext dc;
                dc = (UIInputArrayInTableContext)currentContext;
                dc.DeletekeyPressed();
                if (ke != null)
                {
                    ke.Handled = true;
                    ke.SuppressKeyPress = true;
                }
                return;
            }
        }

        void tsBtnPgDown_Click(object sender, EventArgs e)
        {
            KeyEventArgs ke = null;
            if (e != null)
            {
                if (e.GetType() == typeof(KeyEventArgs))
                {
                    ke = (KeyEventArgs)e;
                }
            }
            this.ErrorText = "";
            if (currentContext is UIDisplayArrayContext)
            {
                UIDisplayArrayContext dc;
                dc = (UIDisplayArrayContext)currentContext;
                dc.pgDownkeyPressed();
                if (ke != null)
                {
                    ke.Handled = true;
                    ke.SuppressKeyPress = true;
                }
                return;
            }

            if (currentContext is UIInputArrayContext)
            {
                UIInputArrayContext dc;
                dc = (UIInputArrayContext)currentContext;
                dc.pgDownkeyPressed();
                if (ke != null)
                {
                    ke.Handled = true;
                    ke.SuppressKeyPress = true;
                }
                return;
            }

            if (currentContext is UIInputArrayInTableContext)
            {
                UIInputArrayInTableContext dc;
                dc = (UIInputArrayInTableContext)currentContext;
                dc.pgDownkeyPressed();
                if (ke != null)
                {
                    ke.Handled = true;
                    ke.SuppressKeyPress = true;
                }
                return;
            }

            if (currentContext is UIDisplayArrayInTableContext)
            {
                // Let the ui handle it..
                // Let the ui handle it..
                if (e != null)
                {
                    // Its a real button click - if it was a fake click because of a 
                    // matched keypress e would be null...
                    //Program.Show("Null");
                    UIDisplayArrayInTableContext dc;
                    dc = (UIDisplayArrayInTableContext)currentContext;
                    dc.pgDownkeyPressed();
                }
                return;
            }
            throw new NotImplementedException();
        }

        void tsBtnPgUp_Click(object sender, EventArgs e)
        {
            KeyEventArgs ke = null;
            if (e != null)
            {
                if (e.GetType() == typeof(KeyEventArgs))
                {
                    ke = (KeyEventArgs)e;
                }
            }
            this.ErrorText = "";
            if (currentContext is UIDisplayArrayContext)
            {
                UIDisplayArrayContext dc;
                dc = (UIDisplayArrayContext)currentContext;
                dc.pgUpkeyPressed();
                if (ke != null)
                {
                    ke.Handled = true;
                    ke.SuppressKeyPress = true;
                }
                return;
            }
            if (currentContext is UIInputArrayContext)
            {
                UIInputArrayContext dc;
                dc = (UIInputArrayContext)currentContext;
                dc.pgUpkeyPressed();
                if (ke != null)
                {
                    ke.Handled = true;
                    ke.SuppressKeyPress = true;
                }
                return;
            }

            if (currentContext is UIInputArrayInTableContext)
            {
                UIInputArrayInTableContext dc;
                dc = (UIInputArrayInTableContext)currentContext;
                dc.pgUpkeyPressed();
                if (ke != null)
                {
                    ke.Handled = true;
                    ke.SuppressKeyPress = true;
                }
                return;
            }

            if (currentContext is UIDisplayArrayInTableContext)
            {

                // Let the ui handle it..

                if (e != null)
                {
                    // Its a real button click - if it was a fake click because of a 
                    // matched keypress e would be null...
                    //Program.Show("Null");
                    UIDisplayArrayInTableContext dc;
                    dc = (UIDisplayArrayInTableContext)currentContext;
                    dc.pgUpkeyPressed();
                }

                return;
            }
            throw new NotImplementedException();
        }


        void b_Click(object sender, EventArgs e)
        {
            string reply;
            AubitTSBtn o;
            KeyEventArgs ke = null;
            if (e != null)
            {
                if (e.GetType() == typeof(KeyEventArgs))
                {
                    ke = (KeyEventArgs)e;
                }
            }
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


           currentContext.externallyTriggeredID(reply);

            //currentContext.useKeyPress


     
            try
            {
                currentContext.DeactivateContext();
            }
            catch (Exception Ex)  { }


            if (ke != null)
            {
                ke.Handled = true;
                ke.SuppressKeyPress = true;
            }
            
        }

        public void ensureAcceptInterruptButtonsOnToolStrip()
        {
            //if (tsBtnAccept==null) {            
                addDefaultToolstripItems();
            //}

        }


        public void AddToolBarAction(string action, string ID)
        {
            AubitTSBtn b;
            int keyCode;
            string key;
            keyCode=FGLUtils.getKeyCodeFromKeyName(action);
            if (keyCode != -1)
            {

                AddToolBarKey(action, action, ID);
            }
            else
            {
                AddToolBarKey(""+keyCode, action, ID);
            }

            /*
            ensureAcceptInterruptButtonsOnToolStrip();

            // No - Create a new one..
            b = new AubitTSBtn();
            b.isProgramAdded = false;
            b.Action = action;
            b.Text = action;
            b.ID = ID;
            b.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.ImageAndText;
            b.Visible = false;
            
            b.clickHandler = b_Click;

            this.toolStrip1.Add(b);
            */
        }


        public void AddToolBarKey(string Key, string Text, string ID)
        {
            AubitTSBtn b;

            ensureAcceptInterruptButtonsOnToolStrip();

            // Does it already exist ? 
            for (int a = 0; a < toolStrip1.Count; a++)
            {
                Console.WriteLine(toolStrip1[a].ActiveKey + " " + Key);
                if (toolStrip1[a].ActiveKey == Key)
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
           // Fkeys.Add(b);
            this.toolStrip1.Add(b);
        }

        public void SetToolBarKeyLabel(string Key, string Text)
        {
            

            ensureAcceptInterruptButtonsOnToolStrip();

            // Does it already exist ? 
            for (int a = 0; a < toolStrip1.Count; a++)
            {
                if (toolStrip1[a].ActiveKey == Key)
                {
                    toolStrip1[a].Text = Text;
                    return;
                }
            }
            AddToolBarKey(Key, Text, "");
        }

        private void addDefaultToolstripItems()
        {
            // If we've got no cancel button - 
            // has the user added one in the default toolbar ?
            if (tsBtnCancel == null && hasActionInToolbar("INTERRUPT")) {
                tsBtnCancel = getKeyFromToolbar("INTERRUPT");
                this.tsBtnCancel.clickHandler = new System.EventHandler(this.tsBtnCancel_Click);
            }

            // If we've got no accept button - 
            // has the user added one in the default toolbar ?
            if (tsBtnAccept == null && hasActionInToolbar("ACCEPT"))
            {
                tsBtnAccept = getKeyFromToolbar("ACCEPT");
                this.tsBtnAccept.clickHandler = new System.EventHandler(this.tsBtnAccept_Click);
            }




            // If we've got no insert button - 
            // has the user added one in the default toolbar ?
            if (tsBtnInsert == null && hasActionInToolbar("INSERT"))
            {
                tsBtnInsert = getKeyFromToolbar("INSERT");
                this.tsBtnInsert.clickHandler = new System.EventHandler(this.tsBtnInsert_Click);
            }

            // If we've got no delete button - 
            // has the user added one in the default toolbar ?
            if (tsBtnDelete == null && hasActionInToolbar("DELETE"))
            {
                tsBtnDelete = getKeyFromToolbar("DELETE");
                this.tsBtnDelete.clickHandler = new System.EventHandler(this.tsBtnDelete_Click);
            }




            // If we've got no delete button - 
            // has the user added one in the default toolbar ?
            if (tsBtnUp == null && hasActionInToolbar("UP"))
            {
                tsBtnUp= getKeyFromToolbar("UP");
                this.tsBtnUp.clickHandler = new System.EventHandler(this.tsBtnUp_Click);
            }

            // If we've got no delete button - 
            // has the user added one in the default toolbar ?
            if (tsBtnPgUp == null && hasActionInToolbar("PGUP"))
            {
                tsBtnPgUp = getKeyFromToolbar("PGUP");
                this.tsBtnPgUp.clickHandler = new System.EventHandler(this.tsBtnPgUp_Click);
            }

            // If we've got no delete button - 
            // has the user added one in the default toolbar ?
            if (tsBtnDown == null && hasActionInToolbar("DOWN"))
            {
                tsBtnDown = getKeyFromToolbar("DOWN");
                this.tsBtnDown.clickHandler = new System.EventHandler(this.tsBtnDown_Click);
            }

            // If we've got no delete button - 
            // has the user added one in the default toolbar ?
            if (tsBtnPgDown == null && hasActionInToolbar("PGDN"))
            {
                tsBtnPgDown = getKeyFromToolbar("PGDN");
                this.tsBtnPgDown.clickHandler = new System.EventHandler(this.tsBtnPgDown_Click);
            }


                if (tsBtnAccept==null)
                {
                    tsBtnAccept = new AubitDesktop.AubitTSBtn(true);
                    // 
                    // tsBtnAccept
                    // 
                    this.tsBtnAccept.ActiveKey = "ACCEPT";
                    this.tsBtnAccept.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
                    this.tsBtnAccept.ID = "ACCEPT";
                    this.tsBtnAccept.Image = global::AubitDesktop.ToolBarImages.accept; // NOTWEBGUI
                    // WEBGUI this.tsBtnAccept.Image = "Icons.accept.png";
                    this.tsBtnAccept.ImageTransparentColor = System.Drawing.Color.Magenta;
                    this.tsBtnAccept.Name = "tsBtnAccept";
                    this.tsBtnAccept.Size = new System.Drawing.Size(23, 22);
                    this.tsBtnAccept.Text = "Accept";
                    this.tsBtnAccept.clickHandler = new System.EventHandler(this.tsBtnAccept_Click);
                    this.tsBtnAccept.Visible = true;
                    this.toolStrip1.Add(tsBtnAccept);
                }

            


                if (tsBtnCancel==null)
                {
                    // 
                    // tsBtnCancel
                    // 
                    tsBtnCancel = new AubitDesktop.AubitTSBtn(true);
                    this.tsBtnCancel.ActiveKey = "INTERRUPT";
                    this.tsBtnCancel.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
                    this.tsBtnCancel.ID = "INTERRUPT";
                    this.tsBtnCancel.Image = global::AubitDesktop.ToolBarImages.cancel; // NOTWEBGUI
                    // WEBGUI this.tsBtnCancel.Image = "Icons.cancel.png";
                    this.tsBtnCancel.ImageTransparentColor = System.Drawing.Color.Magenta;
                    this.tsBtnCancel.Name = "tsBtnCancel";
                    this.tsBtnCancel.Size = new System.Drawing.Size(23, 22);
                    this.tsBtnCancel.Text = "Cancel";
                    this.tsBtnCancel.clickHandler = new System.EventHandler(this.tsBtnCancel_Click);
                    this.tsBtnCancel.Visible = true;
                    this.toolStrip1.Add(tsBtnCancel);
                }




                if (tsBtnUp == null)
                {
                    // tsBtnUp
                    //
                    tsBtnUp = new AubitTSBtn(true);
                    this.tsBtnUp.ActiveKey = "UP";
                    this.tsBtnUp.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
                    this.tsBtnUp.ID = "UP";
                    this.tsBtnUp.Image = global::AubitDesktop.ToolBarImages.arrup; // NOTWEBGUI
                    // WEBGUI this.tsBtnUp.Image = "Icons.arrup.png";
                    this.tsBtnUp.ImageTransparentColor = System.Drawing.Color.Magenta;
                    this.tsBtnUp.Name = "tsBtnUp";
                    this.tsBtnUp.Size = new System.Drawing.Size(23, 22);
                    this.tsBtnUp.Text = "Up";
                    this.tsBtnUp.clickHandler = new System.EventHandler(tsBtnUp_Click);

                    this.tsBtnUp.Visible = true;
                    this.toolStrip1.Add(tsBtnUp);
                }

                if (tsBtnDown == null)
                {
                    // tsBtnDown
                    //
                    tsBtnDown = new AubitTSBtn(true);
                    this.tsBtnDown.ActiveKey = "DOWN";
                    this.tsBtnDown.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
                    this.tsBtnDown.ID = "DOWN";
                    this.tsBtnDown.Image = global::AubitDesktop.ToolBarImages.arrdown; // NOTWEBGUI
                    // WEBGUI this.tsBtnDown.Image = "Icons.arrdown.png";
                    this.tsBtnDown.ImageTransparentColor = System.Drawing.Color.Magenta;
                    this.tsBtnDown.Name = "tsBtnDown";
                    this.tsBtnDown.Size = new System.Drawing.Size(23, 22);
                    this.tsBtnDown.Text = "Down";
                    this.tsBtnDown.clickHandler = new System.EventHandler(this.tsBtnDown_Click);

                    this.tsBtnDown.Visible = true;
                    this.toolStrip1.Add(tsBtnDown);
                }


                if (tsBtnPgDown == null)
                {
                    // tsBtnPgDown
                    //
                    tsBtnPgDown = new AubitTSBtn(true);
                    this.tsBtnPgDown.ActiveKey = "PGDN";
                    this.tsBtnPgDown.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
                    this.tsBtnPgDown.ID = "PGDN";
                    this.tsBtnPgDown.Image = global::AubitDesktop.ToolBarImages.arrpgdown; // NOTWEBGUI
                    // WEBGUI this.tsBtnPgDown.Image = "Icons.arrpgdown.png";
                    this.tsBtnPgDown.ImageTransparentColor = System.Drawing.Color.Magenta;
                    this.tsBtnPgDown.Name = "tsBtnPgDown";
                    this.tsBtnPgDown.Size = new System.Drawing.Size(23, 22);
                    this.tsBtnPgDown.Text = "PgDn";
                    this.tsBtnPgDown.clickHandler = new System.EventHandler(this.tsBtnPgDown_Click);

                    this.tsBtnPgDown.Visible = true;
                    this.toolStrip1.Add(tsBtnPgDown);
                }


                if (tsBtnPgUp == null)
                {
                    // tsBtnPgUp
                    //
                    tsBtnPgUp = new AubitTSBtn(true);
                    this.tsBtnPgUp.ActiveKey = "PGUP";
                    this.tsBtnPgUp.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
                    this.tsBtnPgUp.ID = "PGUP";
                    this.tsBtnPgUp.Image = global::AubitDesktop.ToolBarImages.arrpgup; // NOTWEBGUI
                    // WEBGUI this.tsBtnPgUp.Image = "Icons.arrpgup.png";
                    this.tsBtnPgUp.ImageTransparentColor = System.Drawing.Color.Magenta;
                    this.tsBtnPgUp.Name = "tsBtnPgUp";
                    this.tsBtnPgUp.Size = new System.Drawing.Size(23, 22);
                    this.tsBtnPgUp.Text = "PgUp";
                    this.tsBtnPgUp.clickHandler = new System.EventHandler(this.tsBtnPgUp_Click);

                    this.tsBtnPgUp.Visible = true;
                    this.toolStrip1.Add(tsBtnPgUp);
                }

                if (tsBtnInsert == null)
                {
                    // tsBtnInsert
                    //
                    tsBtnInsert = new AubitTSBtn(true);
                    this.tsBtnInsert.ActiveKey = "INSERT";
                    this.tsBtnInsert.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
                    this.tsBtnInsert.ID = "Insert";
                    this.tsBtnInsert.Image = global::AubitDesktop.ToolBarImages.neu; // NOTWEBGUI
                    // WEBGUI this.tsBtnInsert.Image = "Icons.insert.png";
                    this.tsBtnInsert.ImageTransparentColor = System.Drawing.Color.Magenta;
                    this.tsBtnInsert.Name = "tsBtnInsert";
                    this.tsBtnInsert.Size = new System.Drawing.Size(23, 22);
                    this.tsBtnInsert.Text = "Insert";
                    this.tsBtnInsert.clickHandler = new System.EventHandler(this.tsBtnInsert_Click);

                    this.tsBtnInsert.Visible = true;
                    this.toolStrip1.Add(tsBtnInsert);
                }

                if (tsBtnDelete == null)
                {
                    // tsBtnDelete
                    //
                    tsBtnDelete = new AubitTSBtn(true);
                    this.tsBtnDelete.ActiveKey = "DELETE";
                    this.tsBtnDelete.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
                    this.tsBtnDelete.ID = "Delete";
                    this.tsBtnDelete.Image = global::AubitDesktop.ToolBarImages.delete; // NOTWEBGUI
                    //WEBGUI this.tsBtnDelete.Image ="Icons.delete.png";
                    this.tsBtnDelete.ImageTransparentColor = System.Drawing.Color.Magenta;
                    this.tsBtnDelete.Name = "tsBtnDelete";
                    this.tsBtnDelete.Size = new System.Drawing.Size(23, 22);
                    this.tsBtnDelete.Text = "Delete";
                    this.tsBtnDelete.clickHandler = new System.EventHandler(this.tsBtnDelete_Click);

                    this.tsBtnDelete.Visible = true;
                    this.toolStrip1.Add(tsBtnDelete);
                }
            //





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
            KeyEventArgs ke = null;
            if (e != null)
            {
                if (e.GetType() == typeof(KeyEventArgs))
                {
                    ke = (KeyEventArgs)e;
                }
            }
            string eventText = "<TRIGGERED ENVELOPEID=\"" + this.ApplicationEnvelopeID + "\" ID=\"INTERRUPT\"/>";
            TopWindow.SendString(eventText,true);
            currentContext.DeactivateContext();
            if (ke != null)
            {
                ke.Handled = true;
                ke.SuppressKeyPress = true;
            }
        }


        private void tsBtnAccept_Click(object sender, EventArgs e)
        {
            KeyEventArgs ke = null;
            if (e != null)
            {
                if (e.GetType() == typeof(KeyEventArgs))
                {
                    ke = (KeyEventArgs)e;
                }
            }
            this.ErrorText = "";
            /*
            string eventText = currentContext.getAcceptString();
            if (eventText != null)
            {
                TopWindow.SendString(eventText,true);
            }
            currentContext.DeactivateContext();
             * */
            setLastKey("ACCEPT");
            
            currentContext.toolBarAcceptClicked();
            if (ke != null)
            {
                ke.Handled = true;
                ke.SuppressKeyPress = true;
            }
            return ;
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
                    //Program.Show("Ping!");


                //    TopWindow.SendString("<PING ENVELOPEID=\"" + this.ApplicationEnvelopeID+"\"/>", false);


                  //  TopWindow.SendString("<PING/>", false);
                }
            }
            
        }


        public void ConsumeEnvelopeCommands()
        {
            int cnt = 0;
            DateTime stime = System.DateTime.Now;
            List<object> run_commands;
            SendPing();

            if (this.commands == null) return;
            if (this.commands.Count == 0) return;
            this.SuspendLayout();

            // Make a copy of our commands to run through
            run_commands = new List<object>();
            foreach (object a in this.commands)
            {
                run_commands.Add(a);
            }



            cnt = 0;
            // Go through one at a time...
            foreach (object a in run_commands)
            {
                Console.WriteLine("Cumtime before : " + (System.DateTime.Now - stime)+" "+a.GetType().ToString());


                TopWindow.setProgress( run_commands.Count,cnt);
                cnt++;

                #region PROGRAMSTARTUP
                if (a is PROGRAMSTARTUP)
                {
                    PROGRAMSTARTUP p;
                    string progname;
                    p = (PROGRAMSTARTUP)a;
                    this.Text = "Running : " + p.PROGRAMNAME + ", Logged in as " + this.Username + ", UniqID :" + p.ID;
                    progname = p.PROGRAMNAME;
                    if (progname.StartsWith("/") || progname.StartsWith("./"))
                    {
                        progname = progname.Substring(progname.LastIndexOf("/") + 1);
                    }
                    
                    this.TopWindow.addNewTabPage(Convert.ToInt32(p.ID), progname, this);
                    Console.Write("Looking for 4tb files in "+ System.IO.Directory.GetCurrentDirectory());
                    if (System.IO.File.Exists(progname + ".4tb"))
                    {
                        loadToolbar(progname + ".4tb", this.ApplicationEnvelopeID);
                    }
                    else
                    {
                        if (System.IO.File.Exists("default.4tb"))
                        {
                            loadToolbar("default.4tb", this.ApplicationEnvelopeID);
                        }
                    }

                    SetServerEnviron ( p.ENV);
                    commands.Remove(a);
                    //Program.Show("Application would like to start! Program=" + p.PROGRAMNAME + " ID=" + p.ID);
                    continue;
                }
                #endregion

                #region FIELDDELIMITERS
                if (a is FIELDDELIMITERS)
                {
                    // Ignore field delimiters command...
                    commands.Remove(a);
                    continue;
                }
                #endregion

                #region FILE
                if (a is FILE)
                {
                    if (Program.AppSettings.allowReceiveFile)
                    {
                        FILE f;
                        string oname="";
                        FileStream fs = null;
                        BinaryWriter sw;
                        byte[] data;
                        f = (FILE)a;
                        if (f.CLIENTNAME != null && f.CLIENTNAME.Length > 0)
                        {
                            oname = f.CLIENTNAME;
                            if (System.IO.File.Exists(f.CLIENTNAME))
                            {
                                System.IO.File.Delete(f.CLIENTNAME);
                            }
                            fs = new FileStream(f.CLIENTNAME, FileMode.Create, FileAccess.Write);
                        }
                        else
                        {
                            try
                            {
                                if (System.IO.File.Exists(f.NAME))
                                {
                                    System.IO.File.Delete(f.NAME);
                                }
                                fs = new FileStream(f.NAME, FileMode.Create, FileAccess.Write);
                                oname = f.NAME;
                            }
                            catch (Exception Ex)
                            {
                                Program.Show(Ex.ToString(),"Error opening file : "+f.NAME);
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
                            if (oname.EndsWith(".4sm"))
                            {
                                this.TopWindow.loadApplicationLauncherTree(oname, this.ApplicationEnvelopeID);
                            }

                            if (oname.EndsWith(".4tb"))
                            {
                                this.loadToolbar(oname, this.ApplicationEnvelopeID);
                            }
                        }
                        else
                        {
                            MessageBox.Show("File coult not be opened : "+oname);
                        }
                    }
                    else
                    {
                        Program.Show("The 4GL program tried to send a file " + ((FILE)a).NAME + " but this is disallowed by the Aubit Desktop Client settings");
                    }
                    commands.Remove(a);
                    continue;
                }
                #endregion
                #region EXECUTE
                if (a is EXECUTE)
                {
                    //Program.Show(((EXECUTE)a).Text,"EXECUTE");
                    if (Program.AppSettings.allowExec)
                    {
                        string prog;
                        string args;
                        prog = ((EXECUTE)a).Text.Trim();
                        if (prog.StartsWith("'"))
                        {
                            int n;
                            prog = prog.Substring(1);
                            n = prog.IndexOf("'");
                            args = prog.Substring(n + 1);
                            prog = prog.Substring(0, n);
                        }
                        else
                        {
                            int n;
                            n = prog.IndexOf(" ");
                            args = prog.Substring(n + 1);
                            prog = prog.Substring(0, n );
                        }
                        System.Diagnostics.Process.Start(prog,args);
                    }
                    else
                    {
                        Program.Show("The 4GL program tried to execute " + ((EXECUTE)a).Text + " but this is disallowed by the Aubit Desktop Client settings");
                    }
                    commands.Remove(a);
                    continue;
                }
                #endregion
                #region UIDIRECT
                if (a is UIDIRECT)
                {
                    Program.Show(((UIDIRECT)a).Text,"UIDIRECT");
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
                #region SETAPPLICATIONLAUNCHERXML
                if (a is SETAPPLICATIONLAUNCHERXML)
                {
                    this.TopWindow.loadApplicationLauncherTree(((SETAPPLICATIONLAUNCHERXML)a).FILE,this.ApplicationEnvelopeID);
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
                    ApplicationWindows.clearForm();
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
                    createToolbarButton((ADDTOTOOLBAR)a);
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
                        Program.Show("Unable to find form " + d.FORMNAME);
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
                        Program.Show("Unable to find form " + d.FORMNAME);
                    }
                    commands.Remove(a);
                    continue;
                }
                #endregion
                #region DISPLAYAT
                if (a is DISPLAYAT)
                {
                    Console.WriteLine("DISPLAY .. AT is not support for GUI - please recode your application");
                 //   Program.Show("DISPLAY .. AT is not support for GUI - please recode your application");
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
                            s = "<TRIGGERED ENVELOPEID=\"" + this.ApplicationEnvelopeID + "\" ID=\"FILEREQUEST\" FILEID=\"" + System.Security.SecurityElement.Escape(fileID) + "\" FILELEN=\"" + flen + "\">";
                            s += "<SYNCVALUES><SYNCVALUE>";
                            s += Convert.ToBase64String(fileContents);
                            s += "</SYNCVALUE></SYNCVALUES>";
                            s += "</TRIGGERED>";
                            TopWindow.SendString(s,true);
                        }
                    }
                    else
                    {
                        Program.Show("The 4GL program tried to request a file  " + ((REQUESTFILE)a).FILEID + " but this is disallowed by the Aubit Desktop Client settings");
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
                            TopWindow.loadApplicationLauncherTree(u.VALUE,this.ApplicationEnvelopeID);
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
                        if (o.FORM == null)
                        {
                            Program.Show("Unable to open form..." + o.FORMNAME);
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
                    FGLForm frm=null;
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
                        if (w.FORM == null)
                        {
                            MessageBox.Show("Unable to open form - is it compiled ? ");
                            Application.Exit();
                        }
                        else
                        {
                            frm = new FGLForm(w.FORM);
                        }
                    }
                    if (frm != null)
                    {
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
                          frmMainAppWindow.ensureSizeWindow(win.WindowWidget, "");
                        }

                        if (win.isModal && win.WindowFormWidget != null)
                        {
                            // This doesn't seem to work atm - gettting errors 
                            // saying you cant show it as its already visible - even though its not!
                            win.WindowWidget.Visible = false;
                            TopWindow.ShowDialog(win.WindowFormWidget);
                        }

                        ApplicationWindows.PushWindow(win);
                    }
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
                    DataGridView v;

                    v = FindRecord(ia.FIELDLIST);
                    if (v != null)
                    {
                        contexts.Insert(Convert.ToInt32(ia.CONTEXT), new UIInputArrayInTableContext(this, ia));
                    }
                    else
                    {
                        contexts.Insert(Convert.ToInt32(ia.CONTEXT), new UIInputArrayContext(this, ia));
                    }
                    commands.Remove(a);
                    continue;
                }
                #endregion
                #region DISPLAYARRAY
                if (a is DISPLAYARRAY)
                {
                    DataGridView v;
                    DISPLAYARRAY da = (DISPLAYARRAY)a;
                    v = FindRecord(da.FIELDLIST);
                    if (v!=null)
                    {
                        contexts.Insert(Convert.ToInt32(da.CONTEXT), new UIDisplayArrayInTableContext(this, da));
                    }
                    else
                    {
                        contexts.Insert(Convert.ToInt32(da.CONTEXT), new UIDisplayArrayContext(this, da));
                    }

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
                        Program.Show(b.Text,"Application Message");
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
                #region SETINTR
                if (a is SETINTR)
                {
                    //Program.Show("Backend Interrupted");
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
                        if (p.line != null)
                        {
                            for (idx = 0; idx < p.line.Length; idx++)
                            {
                                txt += p.line[idx].Text + "\n";
                            }
                        }
                        Program.Show("Program Exited with non-zero exit status\n" + txt);
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

                #region SETARRLINE
                if (a is SETARRLINE)
                {
                    if (currentContext is UIInputArrayContext)
                    {
                        UIInputArrayContext ia;
                        ia = (UIInputArrayContext)currentContext;
                        ia.setArrLine(((SETARRLINE)a).LINE);
                    }

                    if (currentContext is UIDisplayArrayContext)
                    {
                        UIDisplayArrayContext da;
                        da = (UIDisplayArrayContext)currentContext;
                        da.setArrLine(((SETARRLINE)a).LINE);
                    }

                    if (currentContext is UIDisplayArrayInTableContext)
                    {
                        UIDisplayArrayInTableContext da;
                        da = (UIDisplayArrayInTableContext)currentContext;
                        da.setArrLine(((SETARRLINE)a).LINE);
                    }
                    commands.Remove(a);
                    continue;

                }
                #endregion

                #region SETSCRLINE
                if (a is SETSCRLINE)
                {
                    if (currentContext is UIInputArrayContext)
                    {
                        UIInputArrayContext ia;
                        ia = (UIInputArrayContext)currentContext;
                        ia.setScrLine(((SETSCRLINE)a).LINE);
                    }

                    if (currentContext is UIDisplayArrayContext)
                    {
                        UIDisplayArrayContext da;
                        da = (UIDisplayArrayContext)currentContext;
                        da.setScrLine(((SETSCRLINE)a).LINE);
                    }

                    if (currentContext is UIDisplayArrayInTableContext)
                    {
                        UIDisplayArrayInTableContext da;
                        da = (UIDisplayArrayInTableContext)currentContext;
                        da.setScrLine(((SETSCRLINE)a).LINE);
                    }
                    commands.Remove(a);
                    continue;
                }
                #endregion
                #region FRONTCALL
                if (a is FRONTCALL)
                {
                    FRONTCALL call;
                    call = (FRONTCALL)a;

                    // If we've got a 'RETURN' value - then we need to generate a context for it
                    // so that we can send back the RETURN values when we get a WAITFOREVENT..
                    //
                    // If we *dont* have any RETURN values - we'll never get a WAITFOREVENT
                    // so we need to call the frontcall *now*...
                    if (call.EXPECT != "0")
                    {
                        immediateContext = new UIMiscContext(this, call);
                    }
                    else
                    {
                        UIMiscContext.FrontCallNoReturns(this, call);
                    }
                    commands.Remove(a);
                    continue;
                }
                #endregion
                #region WINQUESTION
                if (a is WINQUESTION)
                {
                    WINQUESTION i;
                    i = (WINQUESTION)a;
                    immediateContext=new UIMiscContext(this, i);
                    commands.Remove(a);
                    continue;
                }
                #endregion
                #region GETKEY
                if (a is GETKEY)
                {
                        GETKEY i;
                        i = (GETKEY)a;
                        immediateContext= new UIMiscContext(this, i);
                        commands.Remove(a);
                        continue;
                }
                #endregion
                #region DRAWBOX
                if (a is DRAWBOX)
                {
                    Console.WriteLine("Application error - DRAWBOX is not supported by the UI");
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
                    if (w.CONTEXT == null)
                    {
                        currentContext = immediateContext;
                        // An immediateContext is basically a UIContextMisc which just returns something
                        // Atm - we've got GETKEY and WINQUESTION in this category..
                        immediateContext.ActivateContext(UIContext_EventTriggered, w.VALUES, w.ROWS);
                        // We only activate it once - so we can clear it now...

                    }
                    else
                    {
                     
                        //Program.Show("Here" );
                        int idx;
                        for (idx = 0; idx < contexts.Count; idx++)
                        {
                            {
                                if (idx == Convert.ToInt32(w.CONTEXT))
                                { // This is the active context
                                    if (contexts[idx] != null)
                                    {
                                       
                                        TopWindow.clrWaitCursor();
                                      
                                        currentContext = contexts[idx];
                                        //Console.WriteLine("Cumtime before ActivateContext: " + (System.DateTime.Now - stime));
                                        this.TopWindow.setActiveTab(this);
                                        contexts[idx].ActivateContext(UIContext_EventTriggered, w.VALUES, w.ROWS);
                                       // Console.WriteLine("Cumtime after ActivateContext: " + (System.DateTime.Now - stime));
                                    }
                                    else
                                    {
                                        Program.Show("Internal error - no context object");
                                    }
                                }
                                else
                                {
                                    if (contexts[idx] != null)
                                    {
                                        contexts[idx].DeactivateContext();
                                    }
                                }
                            }

                        }
                    }
                    commands.Remove(a);
                    this.TopWindow.clrWaitCursor();
                    continue;
                }
                #endregion
                commands.Remove(a);
                this.TopWindow.AddTextToConsole(" Unhandled: " + a.ToString());
                Program.Show(" Unhandled: " + a.ToString());
            }
            try {
              //  Console.WriteLine("Cumtime after : " + (System.DateTime.Now - stime));
                // This may fail if the window is closed because the application that
                // was in it is now closed - but we dont care about updating the progress bar in an invisible window ;-)
                          TopWindow.setProgress(0,0);
                }
            catch (Exception ) {
                }

            // We might get to here if we're waiting for an event - but thats ok - because it will stay in the queue...
            this.ResumeLayout();
            Console.WriteLine("Consumed:"+(DateTime.Now-stime));
        }

        private void createToolbarButton(ADDTOTOOLBAR o)
        {
            AubitTSBtn btn;

            if (o == null)
            {
                o = new ADDTOTOOLBAR();
                o.TOOLTIP = "";
                o.TAG = "";
                o.KEYVAL = "";
                o.IMAGE = "";
                o.ALWAYSSHOW = "0";
                o.BUTTON = "|";
                o.ALTHOTKEY = "";
            }
            btn = null;

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

            int keyCode = FGLUtils.getKeyCodeFromKeyName(o.KEYVAL);
            if (keyCode == -1)
            {
                btn.ActiveKey = o.KEYVAL;
            }
            else
            {
                btn.ActiveKey = "" + keyCode;
            }
            btn.isProgramAdded = true;
            btn.Text = o.BUTTON;
            btn.programTag = o.TAG;
            btn.clickHandler = b_Click;
            btn.alwaysShow=showMode.ShowAlways;
            btn.altHotKey = o.ALTHOTKEY;

            switch (o.ALWAYSSHOW)
            {
                case "1": btn.alwaysShow = showMode.ShowAlways; break;
                case "0": btn.alwaysShow = showMode.ShowNever; break;
                case "2": btn.alwaysShow = showMode.ShowAuto; break;
            }


            try
            {
                //Image i = getImageFromName(o.IMAGE);
                btn.Image = FGLUtils.getImageFromName(o.IMAGE);
            }
            catch (Exception Ex)
            {
            }
            btn.ToolTipText = o.TOOLTIP;
            toolStrip1.Add(btn);
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
            TopWindow.currentContext = currentContext;
        }

        internal void NavigateAwayTab()
        {
            if (currentContext != null)
            {
                currentContext.NavigateAwayTab();
            }
            else
            {
                setActiveToolBarKeys(null, null, false);
            }
        }







        

        internal void setPrompt(Control p)
        {
            
            //p.Width = this.TopWindow.Width-10;
           
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

        public void SetContext(FGLContextType contextType, List<FGLWidget> pfields, UIContext currContext, List<ONKEY_EVENT> keyList, List<ON_ACTION_EVENT> actionList, UIEventHandler _EventTriggered)
        {
            ApplicationWindows.SetContext(contextType, pfields, currContext, keyList,actionList,_EventTriggered);
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


        internal void SetContext(FGLContextType p, List<FGLFoundField> activeFields, UIContext currContext, List<ONKEY_EVENT> keyList, List<ON_ACTION_EVENT> actionList,UIEventHandler _evtHandler)
        {
           
            int cnt = 0;
            
            List<FGLWidget> l = new List<FGLWidget>();
            foreach (FGLFoundField fld in activeFields) {
                fld.fglField.tabIndex = cnt++;
                l.Add(fld.fglField);
            }
            
            SetContext(p, l,currContext,keyList,actionList,_evtHandler);
           
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

        internal FormattedGridView FindRecord(FIELD[] fIELD)
        {
            return ApplicationWindows.FindRecord(fIELD);
        }



        public void loadToolbar(string XMLFile, int applicationLauncherId)
        {
            AubitDesktop.Xml.ToolBar sToolbar = null;
            System.IO.StreamReader file = null;
            System.Xml.Serialization.XmlSerializer reader = new
            System.Xml.Serialization.XmlSerializer(typeof(AubitDesktop.Xml.ToolBar));
            try
            {
                file =
                   new System.IO.StreamReader(XMLFile);
            }
            catch (Exception e)
            {
                Program.Show(e.ToString(), "Error getting XML application launcher file");
                return;
            }

            try
            {
                // Deserialize the content of the file into the settings...
                sToolbar = (AubitDesktop.Xml.ToolBar)reader.Deserialize(file);
                
            }
            catch (Exception e)
            {
                file.Close();
                Program.Show(e.ToString(), "Unable to load toolbar");
            }
            file.Close();


            if (sToolbar != null)
            {
                toolStrip1.Clear();
                if (sToolbar.height != null)
                {
                    TopWindow.setToolstripHeight(Convert.ToInt32(sToolbar.height));
                }
                if (sToolbar.imageSize!=null)
                {
                    TopWindow.setToolstripImageSize(Convert.ToInt32(sToolbar.imageSize));
                }
                loadButtonsInToolbar(sToolbar, applicationLauncherId);
                addDefaultToolstripItems();
            }
        }

        internal bool hasToolbarButton(string text)
        {
            foreach (AubitTSBtn a in toolStrip1) {
                if (a.ActiveKey == text) return true;
            }

            return false;
        }

        private void loadButtonsInToolbar(AubitDesktop.Xml.ToolBar sToolbar, int applicationLauncherId)
        {
            if (sToolbar == null) return;
            if (sToolbar.Items == null) return;
            if (sToolbar.Items.Length == 0) return;


            for (int a = 0; a < sToolbar.Items.Length; a++)
            {
                if (sToolbar.Items[a] is AubitDesktop.Xml.ToolBarItem)
                {
                    AubitDesktop.Xml.ToolBarItem tbi;
                    tbi = (AubitDesktop.Xml.ToolBarItem)sToolbar.Items[a];
                    ADDTOTOOLBAR addToToolBar;

                    addToToolBar = new ADDTOTOOLBAR();
                    switch (tbi.hidden)
                    {
                        case "1":
                            addToToolBar.ALWAYSSHOW = "0";
                            break;

                        case "0":
                            addToToolBar.ALWAYSSHOW = "1";
                            break;

                        case "2":
                            addToToolBar.ALWAYSSHOW = "2";
                            break;
                    }
                    addToToolBar.BUTTON = tbi.text;
                    addToToolBar.IMAGE=tbi.image;
                    addToToolBar.ALTHOTKEY = tbi.hotKey;

                    if (tbi.name != "ACCEPT")
                    {
                        addToToolBar.KEYVAL = FGLUtils.getKeyCodeFromKeyName(tbi.name).ToString();
                    }
                    else
                    {
                        addToToolBar.KEYVAL = "ACCEPT";
                    }

                    if (addToToolBar.KEYVAL == "-1")
                    {
                        addToToolBar.KEYVAL = tbi.name;
                    }

                    addToToolBar.TAG = "tb_" + addToToolBar.KEYVAL;
                    addToToolBar.TOOLTIP=tbi.comment;
                    createToolbarButton(addToToolBar);
                }

                if (sToolbar.Items[a] is AubitDesktop.Xml.ToolBarSeparator) {
                    createToolbarButton(null);
                }
            }
           
        }



        internal void setToolBarEnabled(string ID, bool hidden)
        {
            foreach (AubitTSBtn a in toolStrip1) {
                if (a.ID == ID)
                {
                    if (hidden)
                    {
                        // Its not enabled in the MENU 
                        // so it should not be enabled in the toolbar either...
                        a.forceDisable = true;
                    }
                    else
                    {

                        a.forceDisable = false;
                    }
                }
            }
        }

    }

}