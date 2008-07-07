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
        List<FGLKeyEvent> KeyEvents;

        public PromptWindow(string text, int FieldAttr, int PromptAttr, string promptStyle, bool charMode,string attribtext)
        {

            InitializeComponent();
            this.promptLabel.Text = text;
            this.promptStyle = promptStyle;
            this.charMode = charMode;
            this.KeyEvents = new List<FGLKeyEvent>();
            this.NonWindowPromptPanel = null;
            if (attribtext.Length>0)
            {
                this.Text = attribtext;
            }
            if ((FieldAttr & 0x20000) > 0)
            { // Invisible
                promptTextBox.PasswordChar = '*';
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
                    EventTriggered(this, "ACCEPT", "<TRIGGERED ID=\"ACCEPT\"><SYNCVALUES><SYNCVALUE>" + System.Security.SecurityElement.Escape( getPromptResult()) + "</SYNCVALUE></SYNCVALUES></TRIGGERED>");
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
                    EventTriggered(this, k.ID.ToString(), "<TRIGGERED ID=\"" + k.ID.ToString() + "\"><SYNCVALUES><SYNCVALUE>" + System.Security.SecurityElement.Escape(getPromptResult()) + "</SYNCVALUE></SYNCVALUES></TRIGGERED>");
                    return;
                }
            }
        }
    }
}
