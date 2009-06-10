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
using System.Windows.Forms;

namespace AubitDesktop
{
    public partial class PromptWindow : Form
    {
        public string promptStyle;
        public bool charMode;
        public event UIEventHandler EventTriggered;
        private Panel NonWindowPromptPanel;
        private UIContext context;
        List<FGLKeyEvent> KeyEvents;

        public PromptWindow(string text, int FieldAttr, int PromptAttr, string promptStyle, bool charMode,string attribtext, UIContext u)
        {

            InitializeComponent();
            this.promptLabel.Text = text;
            this.promptStyle = promptStyle;
            this.charMode = charMode;
            this.KeyEvents = new List<FGLKeyEvent>();
            this.NonWindowPromptPanel = null;
            context = u;
            if (attribtext.Length>0)
            {
                this.Text = attribtext;
            }
            if (FieldAttr != -1)
            {
                if ((FieldAttr & 0x20000) > 0)
                { // Invisible
                    promptTextBox.PasswordChar = '*';
                }
            }
            
        }

        public void SetPromptFocus()
        {
            promptTextBox.Focus();
        }

        private void promptTextBox_TextChanged(object sender, EventArgs e)
        {

        }


        public string getPromptResult()
        {
            return promptTextBox.Text;
        }

        public Control GetPromptControls()
        {
            if (promptStyle == "WINDOW")
            {
                return null;
            }
            else
            {
                
                int h;
                
                if (NonWindowPromptPanel!=null) return NonWindowPromptPanel;

                NonWindowPromptPanel = new Panel();
                //NonWindowPromptPanel.BorderStyle = BorderStyle.Fixed3D;
                h = GuiLayout.get_gui_h(1);

                this.tableLayoutPanel1.Parent = NonWindowPromptPanel;
                NonWindowPromptPanel.Height = h+2;
                
                return NonWindowPromptPanel;
            }
        }

        public void AddKeyWatch(int ID, string Key)
        {
            KeyEvents.Add(new FGLKeyEvent(Key, ID));
        }


        public void clrEventTrigger()
        {
            this.EventTriggered = null;
        }

        private void promptTextBox_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == '\n' || e.KeyChar == '\r' || charMode)
            {
                if (this.promptStyle == "WINDOW")
                {
                    this.Close();
                }

                if (EventTriggered != null)
                {
                    EventTriggered(this, "ACCEPT", "<TRIGGERED ID=\"ACCEPT\" LASTKEY=\"ACCEPT\"><SYNCVALUES><SYNCVALUE>" + System.Security.SecurityElement.Escape(getPromptResult()) + "</SYNCVALUE></SYNCVALUES></TRIGGERED>",context);
                }
            }
        }

        private void promptTextBox_KeyUp(object sender, KeyEventArgs e)
        {
            if (KeyEvents == null) return;

            string key;
            key = e.KeyCode.ToString();
            foreach (FGLKeyEvent k in KeyEvents)
            {
                if (k.isKey(key))
                {
                    EventTriggered(this, k.ID.ToString(), "<TRIGGERED ID=\"" + k.ID.ToString() + "\"><SYNCVALUES><SYNCVALUE>" + System.Security.SecurityElement.Escape(getPromptResult()) + "</SYNCVALUE></SYNCVALUES></TRIGGERED>",context);
                    return;
                }
            }
        }

        private void PromptWindow_Load(object sender, EventArgs e)
        {
            Program.setWindowPosition(this.GetType().ToString() , this);
        }

        private void PromptWindow_FormClosed(object sender, FormClosedEventArgs e)
        {
            Program.saveWindowPosition(this.GetType().ToString(), this);
        }
    }
}
