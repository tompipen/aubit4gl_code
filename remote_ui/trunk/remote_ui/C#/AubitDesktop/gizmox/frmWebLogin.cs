#region Using

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;

using Gizmox.WebGUI.Common;
using Gizmox.WebGUI.Forms;

#endregion

namespace AubitDesktop
{
    public partial class frmWebLogin : Form
    {
        public bool logInClicked = false;
        public frmWebLogin()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
             logInClicked = true;
            this.Visible = false;
            this.Close();
        }
    }
}