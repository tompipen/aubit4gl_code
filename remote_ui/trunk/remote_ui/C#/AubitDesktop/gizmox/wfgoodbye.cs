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
    public partial class Goodbye : Form
    {
        string errMsg;
        public Goodbye(string p_errMsg)
        {
            errMsg=p_errMsg;
            InitializeComponent();
        }

        private void Goodbye_Load(object sender, EventArgs e)
        {
            if (errMsg == "")
            {
                lblErrMsg.Text = "Program exited successfully";
                lblErrMsg.BorderStyle = BorderStyle.Clear;
            }
            else
            {
                this.lblErrMsg.Text = errMsg;
            }
        }
    }
}