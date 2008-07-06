using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace AubitDesktop2
{
    public partial class frmConsole : Form
    {
        public frmConsole()
        {
            InitializeComponent();
        }

       public void ClearText()
        {
            this.txtConsoleText.Text = "";
            this.Visible = false;
        }

        public void AddText(string s)
        {
            this.txtConsoleText.Text += s+"\r\n";
            if (txtConsoleText.Text.Length > 0) this.Visible = true;
            else this.Visible = false;
        }
    }
}