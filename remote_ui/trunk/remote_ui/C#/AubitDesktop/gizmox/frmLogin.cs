using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using Gizmox.WebGUI.Forms;

namespace AubitDesktop
{
    public partial class frmLogin : Form
    {
        //private bool _okcancel;

        private string _username;

        public string Username
        {
            get { return _username; }
            set { _username = value; this.tbUsername.Text = _username; }
        }
        private string _password;

        public string Password
        {
            get { return _password; }
            set { _password = value; this.tbPassword.Text = _password; }
        }

        public frmLogin()
        {
            InitializeComponent();
        }

        private void frmLogin_Load(object sender, EventArgs e)
        {

        }

        private void btnOk_Click(object sender, EventArgs e)
        {
            _password = tbPassword.Text;
            _username = tbUsername.Text;
            this.DialogResult = DialogResult.OK;
            
            this.Close();
        }

        private void btnCancel_Click(object sender, EventArgs e)
        {
            this.DialogResult = DialogResult.Cancel;
            this.Close();
        }
    }
}
