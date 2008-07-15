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
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Diagnostics;
using System.Windows.Forms;



namespace AubitDesktop
{


    public partial class frmMainAppWindow : Form
    {

        public AubitNetwork stdNetworkConnection;
        
        public UIContext currentContext = null;
        private bool showEvelopeProgress = false;
        private bool updating;
        //private bool connectionTypeSSH;
        private List<FGLApplicationPanel> RunningApplications;
        FGLApplicationPanel currentPanel;
        private showMode _showApplicationLauncher;
        bool _hasApplicationtree;
      

        bool hasApplicationTree
        {
            get
            {
                return _hasApplicationtree;
            }
            set
            {
                _hasApplicationtree = value;
                showOrHideApplicationLauncher();
            }
        }

        showMode showApplicationLauncher
        {
            get
            {
                return _showApplicationLauncher;
            }
            set
            {
                _showApplicationLauncher = value;
                showOrHideApplicationLauncher();
            }
        }

        showMode _showToolbar; 

        showMode showToolbar
        {
            get
            {
                return _showToolbar;
            }
            set
            {
                _showToolbar = value;
                showOrHideToolbar();
            }
        }

        private void showOrHideToolbar()
        {
            switch (this.showToolbar)
            {
                case showMode.ShowAlways:
                    alwaysToolbarToolStripMenuItem.Checked = true;
                    autoToolbarToolStripMenuItem.Checked = false;
                    neverToolbarToolStripMenuItem.Checked = false;
                    break;
                case showMode.ShowNever:
                    alwaysToolbarToolStripMenuItem.Checked = false;
                    autoToolbarToolStripMenuItem.Checked = false;
                    neverToolbarToolStripMenuItem.Checked = true;
                    break;
                case showMode.ShowAuto:
                    alwaysToolbarToolStripMenuItem.Checked = false;
                    autoToolbarToolStripMenuItem.Checked = true;
                    neverToolbarToolStripMenuItem.Checked = false;
                    break;
            }

            if (this.showToolbar == showMode.ShowAlways)
            {
                topWindowToolStrip.Visible = true;
            }
            if (this.showToolbar == showMode.ShowNever)
            {
                topWindowToolStrip.Visible = false;
            }
            if (this.showToolbar == showMode.ShowAuto)
            {
                if (topWindowToolStrip.Items.Count > 0)
                {
                    topWindowToolStrip.Visible = true;
                }
                else
                {
                    topWindowToolStrip.Visible = false;
                }
            }
            
        }


        showMode _showMenuBar;
        showMode showMenuBar
        {
            get
            {
                return _showMenuBar;
            }
            set
            {
                _showMenuBar = value;
                showOrHideMenubar();
            }
        }
        

        public string CommentText 
        {
            set
            {
                this.lblComment.Text = value;
            }
        }

        public string ErrorText
        {
            set
            {
                this.lblError.Text = value;
            }
        }

        public string LineDisplayText
        {
            set {
            this.lblLineDisplay.Text = value;
            }
        }

        public string MessageText
        {
            set {
                this.lblMessage.Text = value;
            }
        }


        void b_Click(object sender, EventArgs e)
        {
            AubitTSBtn o;
            o=(AubitTSBtn)sender;
            stdNetworkConnection.SendString("<TRIGGERED ID=\"" + o.ID + "\"/>");
        }




        /*
        public frmMainAppWindow(System.Net.Sockets.TcpClient c, frmConsole mainConsole,string app,string username, string password)
        {
            InitializeComponent();
            setUpMainAppWindow(mainConsole);

            this. Application = app;
            this.Username = username;
            this.Password = password;
            stdNetworkConnection = new AubitNetwork(AubitNetwork.SocketStyle.SocketStyleEnvelope);
        }
        */

        public frmMainAppWindow(AubitNetwork connection)
        {

            InitializeComponent();
            setUpMainAppWindow();
            


                stdNetworkConnection = connection;
                stdNetworkConnection.ReceivedEnvelopeFromServer += new ReceivedEnvelopeEventHandler(n_ReceivedEnvelopeFromServer);
                stdNetworkConnection.ConnectingFailed += new ConnectingFailedEventHandler(n_ConnectingFailed);
                stdNetworkConnection.DisconnectedFromServer += new DisconnectedEventHandler(n_DisconnectedFromServer);


        }

        private void setUpMainAppWindow()
        {
            updating = false;
            this.currentPanel = null;
            RunningApplications = new List<FGLApplicationPanel>();
            this.splitContainer1.Panel2Collapsed = true;
            this.splitContainer2.Panel1Collapsed = true;

            this.showApplicationLauncher = showMode.ShowAuto;
            this.showMenuBar = showMode.ShowAlways;
            this.showToolbar = showMode.ShowAuto;
            this.lblComment.Text = "";
            this.lblError.Text = "";
            this.lblLineDisplay.Text = "";
            this.lblMessage.Text = "";
            this.hasApplicationTree = false;
        }



        public void SetMenuBarButtons(Control a)
        {
            MenuBarPanel.Controls.Clear();

            if (a != null)
            {
                MenuBarPanel.Controls.Add(a);
            }
            showOrHideMenubar();
        }

        public void showOrHideMenubar() {

            switch (this.showMenuBar)
            {
                case showMode.ShowAlways:
                    alwaysMenubarToolStripMenuItem.Checked = true;
                    autoMenubarToolStripMenuItem.Checked = false;
                    neverMenubarToolStripMenuItem.Checked = false;
                    break;
                case showMode.ShowNever:
                    alwaysMenubarToolStripMenuItem.Checked = false;
                    autoMenubarToolStripMenuItem.Checked = false;
                    neverMenubarToolStripMenuItem.Checked = true;
                    break;
                case showMode.ShowAuto:
                    alwaysMenubarToolStripMenuItem.Checked = false;
                    autoMenubarToolStripMenuItem.Checked = true;
                    neverMenubarToolStripMenuItem.Checked = false; 
                    break;
            }


            if (MenuBarPanel.Controls.Count>0) {
                if (this.showMenuBar == showMode.ShowNever)
                {
                    this.splitContainer1.Panel2Collapsed = true;
                }
                else
                {
                    this.splitContainer1.Panel2Collapsed = false;
                }

            }
            else
            {
                if (this.showMenuBar == showMode.ShowAuto || this.showMenuBar == showMode.ShowNever)
                {
                    this.splitContainer1.Panel2Collapsed = true;
                }
                else
                {
                    this.splitContainer1.Panel2Collapsed = false;
                }
            }
           
        }


        private void showOrHideApplicationLauncher()
        {
            switch (this.showApplicationLauncher)
            {
                case showMode.ShowAlways:
                    alwaysALToolStripMenuItem1.Checked = true;
                    autoALToolStripMenuItem1.Checked = false;
                    neverALToolStripMenuItem1.Checked = false;
                    break;
                case showMode.ShowNever:
                    alwaysALToolStripMenuItem1.Checked = false;
                    autoALToolStripMenuItem1.Checked = false;
                    neverALToolStripMenuItem1.Checked = true;
                    break;
                case showMode.ShowAuto:
                    alwaysALToolStripMenuItem1.Checked = false;
                    autoALToolStripMenuItem1.Checked = true;
                    neverALToolStripMenuItem1.Checked = false;
                    break;
            }
            if (hasApplicationTree)
            {
                if (this.showApplicationLauncher == showMode.ShowNever)
                {
                    this.splitContainer2.Panel1Collapsed = true;
                }
                else
                {
                    this.splitContainer2.Panel1Collapsed = false;
                }

            }
            else
            {
                if (this.showApplicationLauncher == showMode.ShowAuto || this.showApplicationLauncher == showMode.ShowNever)
                {
                    this.splitContainer2.Panel1Collapsed = true;
                }
                else
                {
                    this.splitContainer2.Panel1Collapsed = false;
                }
            }
        }



        private void toolStripButton3_Click(object sender, EventArgs e)
        {

        }
        void n_DisconnectedFromServer(object sender, EventArgs e)
        {
            EnvReaderTimer_Tick(null, null);
            this.Dispose();
        }

        void n_ConnectingFailed(object sender, EventArgs e)
        {
            this.Dispose();
        }


        public void setWaitCursor()
        {
            this.Cursor = Cursors.WaitCursor;
        }

        public void clrWaitCursor()
        {
            this.Cursor = Cursors.Arrow;
        }

        void n_ReceivedEnvelopeFromServer(object sender, ReceivedEventArgs e)
        {
            ENVELOPE enew;
            int a;
            int ID;
           
            
            FGLApplicationPanel appPanel;

            updating = true;
            
            enew = EnvReader.ReadFromXml(e.Data);
            ID = Convert.ToInt32(enew.ID);
            
            foreach (FGLApplicationPanel p in RunningApplications) {
                if (p.ApplicationEnvelopeID==ID) { // We've found it..
                    for (a = 0; a < enew.COMMANDS.Length; a++)
                    {
                        p.commands.Add(enew.COMMANDS[a]);
                    }
                    updating = false;
                    return;
                }
            }

            // If we get to here - we have no FGLApplication panel to use :-(
            appPanel = new FGLApplicationPanel(this, this.stdNetworkConnection.username, this.stdNetworkConnection.application, Convert.ToInt32(enew.ID));
            RunningApplications.Add(appPanel);
            for (a = 0; a < enew.COMMANDS.Length; a++)
            {
                appPanel.commands.Add(enew.COMMANDS[a]);
            }
            updating = false;
        }

        public void addNewTabPage(int ID, string appName, FGLApplicationPanel appPanel)
        {
            TabPage tp;
            // If we get to here - we've not found any valid running application - so we need to start one...
            tabControl1.TabPages.Add(appName);
            tp = tabControl1.TabPages[tabControl1.TabPages.Count-1];
            tabControl1.TabStop = false;
            tp.Controls.Add(appPanel);
            tp.AutoScroll = true;
            
            //appPanel.AutoScroll = true;
            tabControl1.SelectTab(tp);
            
        }


        public void removeTabPage(FGLApplicationPanel appPanel)
        {
            foreach (TabPage tp in this.tabControl1.TabPages)
            {
                if (tp.Controls.Contains(appPanel))
                {
                    tabControl1.TabPages.Remove(tp);
                    appPanel.Dispose();
                    appPanel = null;
                    if (this.tabControl1.TabCount == 0)
                    {
                        this.Close();
                        this.Dispose();
                    }
                    return;
                }
            }
            
        }


        public void SendString(string text) {
            setWaitCursor();
            stdNetworkConnection.SendString(text);

        }

        void UIContext_EventTriggered(object source, string ID, string TriggeredText)
        {
            setWaitCursor();
           stdNetworkConnection.SendString(TriggeredText);
        }


        private void button1_Click(object sender, EventArgs e)
        {
            stdNetworkConnection.SendString(txtSend.Text);
            button1.Enabled = false;
        }


        private void EnvReaderTimer_Tick(object sender, EventArgs e)
        {
            if (updating) return;

            //MessageBox.Show("Timer ticked");
            EnvReaderTimer.Enabled = false;
            if (EnvReaderTimer.Interval != 100)
            {
                EnvReaderTimer.Interval = 100;
            }
            this.ConsumeEnvelopeCommands();
            EnvReaderTimer.Enabled = true;
        }

        private void ConsumeEnvelopeCommands()
        {
            //System.Diagnostics.Debug.WriteLine("In consume envelope commands (top level)");
            int a=0;
            while (a<RunningApplications.Count)
            {
                RunningApplications[a].ConsumeEnvelopeCommands();
                a++;
            }
            
        }



        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        internal void setTabTitle(FGLApplicationPanel fGLApplicationPanel, string progname)
        {
            foreach (TabPage tp in this.tabControl1.TabPages)
            {
                if (tp.Controls.Contains(fGLApplicationPanel))
                {
                    tp.Text = progname;
                    return;
                }
            }
            MessageBox.Show("Unable to find application panel");
        }

        internal void AddTextToConsole(string p)
        {
            Program.myConsole.AddText(p);
        }

        private void tabControl1_SelectedIndexChanged(object sender, EventArgs e)
        {
            FGLApplicationPanel fGLApplicationPanel = null;
            TabPage tp = tabControl1.SelectedTab;
            if (tp == null) { return; }

            foreach (Control c in tp.Controls)
            {
                if (c is FGLApplicationPanel)
                {
                    fGLApplicationPanel = (FGLApplicationPanel)tp.Controls[0];
                }
            }

            if (currentPanel!=null)
            {
                currentPanel.NavigateAwayTab();
            }
            if (fGLApplicationPanel != null)
            {
                fGLApplicationPanel.NavigateToTab();
            }
            currentPanel = fGLApplicationPanel;
        }

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ADAboutBox ad;
            ad = new ADAboutBox();
            ad.Show();
        }

        /*
        private void tmpButtonToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FGLApplicationPanel fGLApplicationPanel = null;
            TabPage tp = tabControl1.SelectedTab;
            if (tp == null) { return; }

            foreach (Control c in tp.Controls)
            {
                if (c is FGLApplicationPanel)
                {
                    fGLApplicationPanel = (FGLApplicationPanel)tp.Controls[0];
                }
            }
            if (fGLApplicationPanel == null) return;
            fGLApplicationPanel.doTest();
        }
         * */



        internal void setProgress(int maxVal, int currVal)
        {
            if (showEvelopeProgress)
            {
                try
                {

                    if (maxVal > 0)
                    {
                        toolStripProgressBar2.Visible = true;
                        toolStripProgressBar2.Value = currVal;
                        toolStripProgressBar2.Maximum = maxVal;

                    }
                    else
                    {
                        toolStripProgressBar2.Visible = false;
                    }
                }
                catch
                {

                }
            }
            else
            {
                toolStripProgressBar2.Visible = false;
            }
        }

        internal void setToolbar(List<ToolStripItem> toolStrip)
        {
            
            this.topWindowToolStrip.Items.Clear();
            if (toolStrip.Count>0)
            {
                    for (int a = 0; a < toolStrip.Count;a++ )
                    {
                        //MessageBox.Show("Adding : " + toolStrip[a]);
                        this.topWindowToolStrip.Items.Add(toolStrip[a]);
                    }   
            }
            showOrHideToolbar();
            
        }

        private void toolStripProgressBar2_Click(object sender, EventArgs e)
        {

        }

        private void enableEditModeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Not implemented yet");
        }

        object Control_ActiveControl(object x) 
        {
            if (x is ContainerControl)
            {
                ContainerControl c;
                c = (ContainerControl)x;
                return Control_ActiveControl(c.ActiveControl);
                
            }
            return x;
        }


        private void copyToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (Control_ActiveControl(this.ActiveControl) is TextBox)
            {
                TextBox t;
                t = (TextBox)Control_ActiveControl(this.ActiveControl);
                t.Copy();
            }
        }

        private void pasteToolStripMenuItem_Click(object sender, EventArgs e)
        {


            if (Control_ActiveControl(this.ActiveControl) is TextBox)
            {
                TextBox t;
                t = (TextBox)Control_ActiveControl(this.ActiveControl);
                t.Paste();
                

            }

        }

        private void cutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (Control_ActiveControl(this.ActiveControl) is TextBox)
            {
                TextBox t;
                t = (TextBox)Control_ActiveControl(this.ActiveControl);
                t.Cut();
            }
            return;
        }

        private void frmMainAppWindow_KeyPress(object sender, KeyPressEventArgs e)
        {
            
        }



        private void frmMainAppWindow_KeyDown(object sender, KeyEventArgs e)
        {
            string key="";
            string fglKey;
            key = FGLUtils.decodeKeycode(e.Control, e.Shift, e.Alt, e.KeyCode);
            if (key == null) return;
            if (FGLUtils.getKeyCodeFromKeyName(key) == FGLUtils.getKeyCodeFromKeyName(Program.AppSettings.interruptKey))
            {
                key = "INTERRUPT";
            }

            if (FGLUtils.getKeyCodeFromKeyName(key) == getCurrentApplicationAcceptKey())
            {
                key = "ACCEPT";
            }

            
            if (key == null) return;

            setLastKeyInApplication(key);
            this.ErrorText = "";

            foreach (ToolStripItem i in topWindowToolStrip.Items)
            {

                if (i is AubitTSBtn)
                {
                    AubitTSBtn a;
                    if (i.Visible == false) continue;
                    a = (AubitTSBtn)i;
                    fglKey = FGLUtils.getKeyNameFromFGLKeyCode(a.ActiveKey);
                    if (fglKey==key)
                    {

                        a.clickHandler(a, new EventArgs());
                        e.Handled = true;
                        e.SuppressKeyPress = true;
                        return;
                    }

                }
            }
            


        }


        public void setComment(string txt)
        {
            this.CommentText = txt;
        }


        string getCurrentApplicationAcceptKey()
        {
         
            FGLApplicationPanel fGLApplicationPanel = null;
            TabPage tp = tabControl1.SelectedTab;
            if (tp == null) { return "Esc"; }

            foreach (Control c in tp.Controls)
            {
                if (c is FGLApplicationPanel)
                {
                    fGLApplicationPanel = (FGLApplicationPanel)tp.Controls[0];
                }
            }


            if (fGLApplicationPanel != null)
            {
                return fGLApplicationPanel.getAcceptKey();
            }

            return "Esc";
        }
        void setLastKeyInApplication(string keycode) {
            FGLApplicationPanel fGLApplicationPanel = null;
            TabPage tp = tabControl1.SelectedTab;
            if (tp == null) { return; }

            foreach (Control c in tp.Controls)
            {
                if (c is FGLApplicationPanel)
                {
                    fGLApplicationPanel = (FGLApplicationPanel)tp.Controls[0];
                }
            }


            if (fGLApplicationPanel != null)
            {
                fGLApplicationPanel.setLastKey(keycode);
            }
        }

        private void MenuBarPanel_Paint(object sender, PaintEventArgs e)
        {

        }

        private void alwaysToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.showMenuBar = showMode.ShowAlways;
            
        }

        private void neverMenubarToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.showMenuBar = showMode.ShowNever;
            
        }

        private void autoMenubarToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.showMenuBar = showMode.ShowAuto;
        }

        private void alwaysALToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            this.showApplicationLauncher = showMode.ShowAlways;
        }

        private void neverALToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            this.showApplicationLauncher = showMode.ShowNever;
        }

        private void autoALToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            this.showApplicationLauncher = showMode.ShowAuto;
        }

        private void alwaysToolbarToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.showToolbar = showMode.ShowAlways;
        }

        private void neverToolbarToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.showToolbar = showMode.ShowNever;
        }

        private void autoToolbarToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.showToolbar = showMode.ShowAuto;
        }

        private void frmMainAppWindow_Load(object sender, EventArgs e)
        {
            Program.setWindowPosition(this.GetType().ToString() + stdNetworkConnection.application, this);
        }

        private void frmMainAppWindow_FormClosed(object sender, FormClosedEventArgs e)
        {
            Program.saveWindowPosition(this.GetType().ToString() + stdNetworkConnection.application, this);
            stdNetworkConnection.Disconnect();
        }
            
 
        
    }
}