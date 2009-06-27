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
                if (shortcut.Port != null && shortcut.Port.Length > 0)
                {
                    txtPort.Text = shortcut.Port;
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
            shortcut.Port = txtPort.Text;
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



             
