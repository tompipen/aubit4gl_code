using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;

namespace AubitDesktop
{
    public partial class FGLTxtControl : UserControl
    {
        public FGLTxtControl()
        {
            InitializeComponent();
        }

        private void FGLTxtControl_Load(object sender, EventArgs e)
        {

        }

        private void FGLTxtControl_Resize(object sender, EventArgs e)
        {
            textBox1.Height = this.Height;
            textBox1.Width = this.Width;
            label1.Height = this.Height;
            label1.Width = this.Width;
        }
    }
}
