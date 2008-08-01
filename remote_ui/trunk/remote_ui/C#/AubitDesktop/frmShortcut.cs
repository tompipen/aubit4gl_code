using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Collections;
using System.Text;
using System.Windows.Forms;

namespace AubitDesktop
{
    public partial class frmShortcut : Form
    {
        //string Result;
        public AubitDesktop.Xml.Shortcut shortcut;

        public frmShortcut(AubitDesktop.Xml.Shortcut sc)
        {
            InitializeComponent();
            this.shortcut = sc;

                lstProtocol.Items.Clear();
                foreach (AubitDesktop.Xml.Protocol p in Program.AppSettings.Protocols)

                {
                    lstProtocol.Items.Add(p.Name);
                }


            if (this.shortcut!=null)
            {
                int cnt = 0;
                txtApplication.Text = shortcut.Application;

                txtPassword.Text = shortcut.Password;

                cbPromptPassword.Checked = shortcut.PromptForPassword;
                txtServer.Text=shortcut.Server;

                txtTitle.Text = shortcut.Title;

                txtUser.Text = shortcut.User;
                   

                lstProtocol.ClearSelected();

                for (cnt = 0; cnt < Program.AppSettings.Protocols.Length; cnt++)
                {
                    if (Program.AppSettings.Protocols[cnt].Code == shortcut.Protocol)
                    {
                        this.lstProtocol.SelectedIndex = cnt;
                        break;
                    }
                    
                }
            }
        }

        private void btnOK_Click(object sender, EventArgs e)
        {
            if (this.lstProtocol.SelectedIndex == -1)
            {
                MessageBox.Show("You must select a protocol");
                lstProtocol.Focus();
                return;
            }
            if (shortcut == null)
            {
                shortcut = new AubitDesktop.Xml.Shortcut();
            }

            shortcut.Application = txtApplication.Text;
            shortcut.Password = txtPassword.Text;
            shortcut.PromptForPassword = cbPromptPassword.Checked;
            shortcut.Protocol = Program.AppSettings.Protocols[this.lstProtocol.SelectedIndex].Code;
            shortcut.Server = txtServer.Text;
            shortcut.Title = txtTitle.Text;
            shortcut.User = txtUser.Text;

            this.Visible = false;
        }


        private void label7_Click(object sender, EventArgs e)
        {

        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            showHidePasswordEntry();
        }

        private void showHidePasswordEntry()
        {
            if (cbPromptPassword .Checked)
            {
                lblPassword.Visible = false;
                txtPassword.Visible = false;
            }
            else
            {
                lblPassword.Visible = true;
                txtPassword.Visible = true;
            }
        }

        private void showDescription()
        {
            
            if (lstProtocol.SelectedIndex >= 0)
            {
                lblDescription.Text = Program.AppSettings.Protocols[lstProtocol.SelectedIndex].Description;
                txtPort.Text = Program.AppSettings.Protocols[lstProtocol.SelectedIndex].DefaultPort;
            }

            
        }


        private void lstProtocol_SelectedIndexChanged(object sender, EventArgs e)
        {
            showDescription();
        }

        private void btnCancel_Click(object sender, EventArgs e)
        {
            //data = null;
            this.Visible = false;
        }

        private void frmShortcut_Load(object sender, EventArgs e)
        {
            showHidePasswordEntry();
            Program.setWindowPosition(this.GetType().ToString(), this);
        }

        private void frmShortcut_FormClosed(object sender, FormClosedEventArgs e)
        {
            Program.saveWindowPosition(this.GetType().ToString(), this);
        }
    }
}

namespace AubitDesktop.Xml
{

    /// <remarks/>
    public class Protocol
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "string")]
        public string Code;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "string")]
        public string Command;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "string")]
        public string Name;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "string")]
        public string Description;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "boolean")]
        public bool ListenMode;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "string")]
        public string DefaultPort;
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = false)]
    public class Protocols
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlElementAttribute()]
        public Protocol[] Protocol;
    }


    /// <remarks/>
    public class Shortcuts
    {

        /// <remarks/>
        public List<Shortcut> Shortcut;
    }
    

    /// <remarks/>
    [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
    public class Shortcut
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "string")]
        public string Application;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "string")]
        public string Password;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "boolean")]
        public bool PromptForPassword;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "string")]
        public string Protocol;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "string")]
        public string Server;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "string")]
        public string User;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "string")]
        public string Title;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "string")]
        public string Port;
    }


    public class WindowPosition
    {
        public string windowName;
        public int w, h, x, y;
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = false)]
    public class Settings
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "string")]
        public string Port;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "string")]
        public string AutoRun;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "boolean")]
        public bool AllowEdit;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "boolean")]
        public bool StartMinimized;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "boolean")]
        public bool ListenMode;

        /// <remarks/>
        [System.Xml.Serialization.XmlArrayItem(IsNullable = false)]
        public Protocol[] Protocols;

        public bool allowExec;
        public bool allowSendFile;
        public bool allowReceiveFile;
        public string interruptKey;
        public int yscale;
        public int xscale;

        /// <remarks/>
        //public Shortcuts Shortcuts;
        public List<Shortcut> Shortcuts;

        public List<WindowPosition> WindowPositions;
    }

             
}