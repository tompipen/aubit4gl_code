using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace AubitDesktop
{

    public partial class AubitMessageBox : Form
    {
        private WINQUESTION winQuestion;
        private string result="";
        public delegate void AubitMessageBoxResponse(object sender, string result);
        public event AubitMessageBoxResponse responseHandler;

        public AubitMessageBox(WINQUESTION wq)
        {
            InitializeComponent();
            winQuestion=wq;
            
        }

        private void AubitMessageBox_Load(object sender, EventArgs e)
        {
            
            lbltext.Text = winQuestion.TEXT;
            this.Text = winQuestion.TITLE;
            if (winQuestion.ICON != "")
            {
                this.lblPb.Image = FGLUtils.getImageFromName(winQuestion.ICON);
            }
            string[] s=winQuestion.POS.Split('|');
            for (int a=0;a<s.Length;a++) {
                Button b;
                b = new Button();
                b.Text = s[a];
                b.Click += new EventHandler(b_Click);
                if (s[a] == winQuestion.DEFAULT)
                {
                    b.Select();
                }
                buttonBox.Controls.Add(b);
            }
        }

        void b_Click(object sender, EventArgs e)
        {
            Button b;
            b = (Button)sender;
            result = b.Text;
            this.Close();
        }

        private void middlePanel_Paint(object sender, PaintEventArgs e)
        {

        }

        private void AubitMessageBox_FormClosed(object sender, FormClosedEventArgs e)
        {
            if (responseHandler != null)
            {
                responseHandler(sender, this.result);
            }
        }
    }

}