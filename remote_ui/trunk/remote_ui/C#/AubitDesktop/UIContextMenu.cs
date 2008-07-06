using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Forms;

namespace AubitDesktop2
{

    class UIMenuBarButton : Button
    {
        string _ID;

        public string ID
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
        }
    }


    class UIMenuContext : UIContext
    {
        //private List<Button> MenuButtons;
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

        public string getAcceptString()
        {
            // Not needed for a menu...
                throw new NotImplementedException();
        
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

            foreach (MENUCOMMAND a in m.MENUCOMMANDS)
            {
                Button btn;
                string txt;
                txt = a.TEXT;
                if (txt.Length == 0) txt = null;

                if (txt == null)
                {
                    string[] menukeys;
                    menukeys = a.KEYS.Split(',');
                    foreach (string s in menukeys) {
                        ONKEY_EVENT e = new ONKEY_EVENT();
                        e.ID = a.ID;
                        e.KEY = s;
                        keyList.Add(e);
                    }
                }
                else
                {
                    
                    btn = new UIMenuBarButton(txt, a.ID);

                    if (a.DESCRIPTION != null)
                    {
                        tooltips.SetToolTip(btn, a.DESCRIPTION);
                    }

                    btn.Click += new EventHandler(b_Click);
                    btn.Top = top;
                    btn.AutoSize = true;
                    btn.Left = 10;
                    menuPanel.Controls.Add(btn);
                    top += btn.Height;
                }
            }


        }


        public void showOption(string text)
        {
            for (int a = 0; a < menuPanel.Controls.Count; a++)
            {
                if (menuPanel.Controls[a].Text == text || text == "ALL")
                {
                    menuPanel.Controls[a].Enabled = true;
                }
            }
        }


        public void hideOption(string text)
        {
            for (int a = 0; a < menuPanel.Controls.Count; a++)
            {
                if (menuPanel.Controls[a].Text == text || text == "ALL")
                {
                    menuPanel.Controls[a].Enabled = false;
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
            eventText = "<TRIGGERED ID=\"" + a.ID + "\"/>";
            if (EventTriggered != null)
            {
                EventTriggered(a, a.ID, eventText);
                DeactivateContext();
            }

        }






        public void ActivateContext(UIEventHandler UIMenuContext_EventTriggered, VALUE[] values)
        {
            mainWin.setActiveToolBarKeys(keyList,false);
            EventTriggered += new UIEventHandler(UIMenuContext_EventTriggered);
            if (!_contextIsActive)
            {
                _contextIsActive = true;
                mainWin.SetMenuBarButtons(this.menuPanel);
            }
            menuPanel.Enabled = true;
        }

        public void NavigateAwayTab()
        {
            mainWin.SetMenuBarButtons(null);
        }

        public void NavigateToTab()
        {
            mainWin.SetMenuBarButtons(this.menuPanel);
        }


        public void DeactivateContext()
        {
            mainWin.SetMenuBarButtons(null);
            _contextIsActive = false;
            EventTriggered = null;
            menuPanel.Enabled = false;
        }

        public void FreeContext()
        {
            menuPanel.Dispose();
            menuPanel = null;
        }
    }

}
