using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using Gizmox.WebGUI.Forms;

namespace AubitDesktop
{
    public partial class AubitMessageBox : Form
    {
        private WINQUESTION winQuestion;
        private string result="";


        public static string Show(WINQUESTION wq)
        {
            AubitMessageBox b;
            string res;
            b = new AubitMessageBox(wq);
            b.ShowDialog();
            res= b.result;
            b.Dispose();
            return res;
        }

        public AubitMessageBox(WINQUESTION wq)
        {
            winQuestion=wq;
            InitializeComponent();
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
    }
}
