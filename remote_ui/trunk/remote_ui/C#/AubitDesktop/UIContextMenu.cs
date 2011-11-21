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
using System.Text;
using System.Windows.Forms;

namespace AubitDesktop
{


    class UIMenuContext : UIContext
    {
        MENU thismenu;
        private bool _contextIsActive;
        FGLApplicationPanel mainWin;
        private ToolTip tooltips = new ToolTip();


        GroupBox menuPanel;
        public event UIEventHandler EventTriggered;

        public bool contextIsActive()
        {
            return _contextIsActive;
        }
        List<ONKEY_EVENT> keyList;
        List<ON_ACTION_EVENT> onActionList;

        public void toolBarAcceptClicked()
        {
            // Does nothing for a menu....
        }

        public bool externallyTriggeredID(string ID)
        {
            string eventText = "<TRIGGERED ID=\"" + ID + "\"/>";
            if (EventTriggered != null)
            {
                EventTriggered(null, ID, eventText, this);
                //DeactivateContext();
                return true;
            }
            return false;
        }

        public bool isNormalKey(KeyEventArgs ke, int asciiVal)
        {
            if (asciiVal > 255) return false;
            if (asciiVal <= 0) return false;
            char []b=new char[1];
            b[0] = (char)asciiVal;
            string s = new string(b);
            return isNormalKey(ke, s);
        }

        public bool isNormalKey(KeyEventArgs ke, string s)
        {
            if (ke.Alt) return false;
            if (ke.Control) return false;
            s = s.ToUpper();
            if (ke.KeyCode == Keys.A && s == "A") { return true; }
            if (ke.KeyCode == Keys.B && s == "B") { return true; }
            if (ke.KeyCode == Keys.C && s == "C") { return true; }
            if (ke.KeyCode == Keys.D && s == "D") { return true; }
            if (ke.KeyCode == Keys.E && s == "E") { return true; }
            if (ke.KeyCode == Keys.F && s == "F") { return true; }
            if (ke.KeyCode == Keys.G && s == "G") { return true; }
            if (ke.KeyCode == Keys.H && s == "H") { return true; }
            if (ke.KeyCode == Keys.I && s== "I") { return true; }
            if (ke.KeyCode == Keys.J && s == "J") { return true; }
            if (ke.KeyCode == Keys.K && s == "K") { return true; }
            if (ke.KeyCode == Keys.L && s == "L") { return true; }
            if (ke.KeyCode == Keys.M && s == "M") { return true; }
            if (ke.KeyCode == Keys.N && s== "N") { return true; }
            if (ke.KeyCode == Keys.O && s == "O") { return true; }
            if (ke.KeyCode == Keys.P && s == "P") { return true; }
            if (ke.KeyCode == Keys.Q && s== "Q") { return true; }
            if (ke.KeyCode == Keys.R && s == "R") { return true; }
            if (ke.KeyCode == Keys.S && s == "S") { return true; }
            if (ke.KeyCode == Keys.T && s== "T") { return true; }
            if (ke.KeyCode == Keys.U && s== "U") { return true; }
            if (ke.KeyCode == Keys.V && s == "V") { return true; }
            if (ke.KeyCode == Keys.W && s == "W") { return true; }
            if (ke.KeyCode == Keys.X && s == "X") { return true; }
            if (ke.KeyCode == Keys.Y && s == "Y") { return true; }
            if (ke.KeyCode == Keys.Z && s == "Z") { return true; }
            if (ke.KeyCode == Keys.D0 && s == "0") { return true; }
            if (ke.KeyCode == Keys.D1 && s == "1") { return true; }
            if (ke.KeyCode == Keys.D2 && s == "2") { return true; }
            if (ke.KeyCode == Keys.D3 && s == "3") { return true; }
            if (ke.KeyCode == Keys.D4 && s == "4") { return true; }
            if (ke.KeyCode == Keys.D5 && s == "5") { return true; }
            if (ke.KeyCode == Keys.D6 && s == "6") { return true; }
            if (ke.KeyCode == Keys.D7 && s == "7") { return true; }
            if (ke.KeyCode == Keys.D8 && s == "8") { return true; }
            if (ke.KeyCode == Keys.D9 && s == "9") { return true; }
            return false;

        }

        public bool useKeyPress(KeyEventArgs ke)
        {
            int cnt;
            MENUCOMMAND matchedCommand=null; 
            cnt = 0;


            foreach (object o  in thismenu.MENUCOMMANDS)
            {
                if (!(o is MENUCOMMAND)) continue;
                MENUCOMMAND a = o as MENUCOMMAND;

                if (a.KEYS != "")
                {
                    string[] keys = a.KEYS.Split(',');
                    for (int n = 0; n < keys.Length; n++)
                    {


                        
                            int kval=-1;
                            try
                            {
                                kval = Convert.ToInt32(keys[n]);
                            }
                            catch (Exception ) { } 

                            if (isNormalKey(ke, kval))
                            {
                                string eventText = "<TRIGGERED ID=\"" + a.ID + "\"/>";
                                if (EventTriggered != null)
                                {
                                    EventTriggered(matchedCommand, a.ID, eventText, this);
                                }
                                return true;
                            }
                        }

                    
                }
            }


            foreach (object o in thismenu.MENUCOMMANDS)
            {

                if (!(o is MENUCOMMAND)) continue;
                MENUCOMMAND a = o as MENUCOMMAND;

                string txt = a.TEXT;

                if (txt == null) continue;

                
                if (txt == "") continue;
                if (a.KEYS != "") continue;

                if (isNormalKey(ke,txt.Substring(0,1))) {
                    matchedCommand = a;
                    cnt++;
                }

            }
            if (cnt == 0) return false;
            if (cnt == 1)
            {
                string eventText = "<TRIGGERED ID=\"" +matchedCommand .ID + "\"/>";
                if (EventTriggered != null)
                {
                    EventTriggered(matchedCommand,matchedCommand.ID , eventText,this);
                    //DeactivateContext();
                    return true;
                }
            }

            Console.WriteLine("GUI can't handle multiple keys");
            return false;
        }

        public UIMenuContext(FGLApplicationPanel f, MENU m)
        {
            int top = 30;
            //  MenuButtons = new List<Button>();
            thismenu = m;
            _contextIsActive = false;
            mainWin = f;
            menuPanel = new GroupBox();
            menuPanel.Visible = true;

            menuPanel.Text = m.TITLE;
            menuPanel.Controls.Clear();
            menuPanel.Dock = DockStyle.Fill;


            keyList = new List<ONKEY_EVENT>();
            onActionList = new List<ON_ACTION_EVENT>();


            foreach (object o in m.MENUCOMMANDS)
            {
                if (o is MENUACTION)
                {
                    // Ignore for now..

                }
                if (o is MENUCOMMAND)
                {
                    MENUCOMMAND a;
                    Button btn;
                    string txt;
                    bool isOnToolbar = false;
                    a = o as MENUCOMMAND;
                    txt = a.TEXT;
                    if (txt.Length == 0) txt = null;



                    if (txt == null)
                    {

                        string[] menukeys;
                        menukeys = a.KEYS.Split(',');
                        foreach (string s in menukeys)
                        {
                            ONKEY_EVENT e = new ONKEY_EVENT();
                            e.ID = a.ID;

                            e.KEY = s;
                            keyList.Add(e);
                        }

                    }
                    else
                    {


                        string[] menukeys;
                        if (a.KEYS == "")
                        {

                            menukeys = new string[1];
                            //menukeys[0] =1;

                            char[] arr = a.TEXT.Substring(0, 1).ToCharArray();
                            menukeys[0] = ((int)(arr[0])).ToString();


                        }
                        else
                        {
                            menukeys = a.KEYS.Split(',');
                        }

                        foreach (string s in menukeys)
                        {
                            int n = -1;
                            ONKEY_EVENT e = new ONKEY_EVENT();
                            try
                            {
                                n = Convert.ToInt32(s);
                            }
                            catch (Exception) { }


                            if (s.Trim() != "" && n != -1)
                            {
                                e.ID = a.ID;

                                e.KEY = s;
                                if (n <= 26 || n > 255)
                                {
                                    keyList.Add(e);

                                }

                            }

                        }

                        if (a.TEXT != null && a.TEXT != "")
                        {
                            if (f.hasToolbarButton(a.TEXT.ToLower()))
                            {
                                ON_ACTION_EVENT e;
                                e = new ON_ACTION_EVENT();
                                e.ACTION = a.TEXT.ToLower();
                                e.ID = a.ID;

                                onActionList.Add(e);
                                isOnToolbar = true;
                                // NOTE : 
                                // We might want to add a 'continue' here - so
                                // we dont have a menubutton of we have a toolbar button...

                            }
                        }

                        btn = new UIMenuBarButton(txt, a.ID);


                        if (a.DESCRIPTION != null)
                        {
                            tooltips.SetToolTip(btn, a.DESCRIPTION);
                        }

                        btn.Click += new EventHandler(b_Click);
                        btn.Top = top;
                        btn.AutoSize = true;
                        btn.Left = 10;
                        if (btn.Image != null)
                        {
                            btn.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
                            btn.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
                        }

                        if (!isOnToolbar)
                        {
                            menuPanel.Controls.Add(btn);
                            if (btn.Height == 0)
                            {
                                top += 30;
                            }
                            else
                            {
                                top += btn.Height;
                            }
                        }
                    }
                }
            }


         //   mainWin.setActiveToolBarKeys(keyList, onActionList, false, false, false);
        }



        public void showOption(string text)
        {
            for (int a = 0; a < menuPanel.Controls.Count; a++)
            {
                if (menuPanel.Controls[a].Text == text || text == "ALL" || text == "_AlL_")
                {
                    UIMenuBarButton uib;
                    uib = (UIMenuBarButton)menuPanel.Controls[a];
                    uib.Hidden = false;
                  
                }
            }
        }


        public void hideOption(string text)
        {
            for (int a = 0; a < menuPanel.Controls.Count; a++)
            {
                if (menuPanel.Controls[a].Text == text || text == "ALL" || text=="_AlL_")
                {
                    UIMenuBarButton uib;
                    uib = (UIMenuBarButton)menuPanel.Controls[a];
                    uib.Hidden = true;
                   
                    
                }
            }
        }

        public void setNextField(string fieldName)
        {
            throw new ApplicationException("Menus cant do nextfields");
        }


        void b_Click(object sender, EventArgs e)
        {
            UIMenuBarButton a;
            string eventText;
            a = (UIMenuBarButton)sender;
            eventText = "<TRIGGERED ID=\"" + a.eventID + "\"/>";
            if (EventTriggered != null)
            {
                EventTriggered(a, a.eventID, eventText,this);
                //DeactivateContext();
            }

        }



        public void ActivateContext(UIEventHandler UIMenuContext_EventTriggered, V[] values, ROW[] rows)
        {
            mainWin.setActiveToolBarKeys(keyList,onActionList); //,false);
            ensureKeyAndActionsAreDisabledOrEnabled();


            EventTriggered += new UIEventHandler(UIMenuContext_EventTriggered);
            if (!_contextIsActive)
            {
                _contextIsActive = true;
                mainWin.SetMenuBarButtons(this.menuPanel);
            }
            menuPanel.Enabled = true;
            // WEBGUI menuPanel.BackColor = System.Drawing.Color.White;
        }

        private void ensureKeyAndActionsAreDisabledOrEnabled()
        {
            for (int a = 0; a < menuPanel.Controls.Count; a++)
            {
                if (menuPanel.Controls[a] is UIMenuBarButton)
                {
                    UIMenuBarButton uib;
                    uib = (UIMenuBarButton)menuPanel.Controls[a];
                    setEnabled(uib.eventID,uib.Hidden);
                }
                
            }
            
            
        }

        private void setEnabled(string ID, bool hidden)
        {
            mainWin.setToolBarEnabled(ID, hidden);
        }

        public void NavigateAwayTab()
        {
            mainWin.SetMenuBarButtons(null);
        }

        public void NavigateToTab()
        {
            mainWin.SetMenuBarButtons(this.menuPanel);
            mainWin.setActiveToolBarKeys(keyList, onActionList); //, false);
        }


        public void DeactivateContext()
        {
            //mainWin.SetMenuBarButtons(null);
            _contextIsActive = false;
            EventTriggered = null;
            menuPanel.Enabled = false;
            // WEBGUI menuPanel.BackColor = System.Drawing.Color.FromArgb(240,240,240);
        }

        public void FreeContext()
        {
            
           // menuPanel.Dispose();
            menuPanel = null;
        }

        internal void nextOption(string text)
        {
            // Does nothing...
            for (int a = 0; a < menuPanel.Controls.Count; a++)
            {
                if (menuPanel.Controls[a].Text == text)
                {
                    menuPanel.Controls[a].Focus();
                    return;
                }
            }
        }
    }

    class UIMenuBarButton : Button
    {
        string _ID;

        public string eventID
        {
            get
            {
                return _ID;
            }
        }

        public UIMenuBarButton(string ButtonText, string ID)
        {

            this.Text = ButtonText;
            this._ID = ID;
            this.TabIndex = 1;
            this.hidden = false;
        }

        private bool hidden;

        internal bool Hidden
        {
            get { return hidden; }
            set
            {
                hidden = value;


                if (hidden) Enabled = false;
                else Enabled = true;
            }
        }
    }


}
