using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
//using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace AubitDesktop2
{
    public partial class ScratchPad : Form
    {
        public ScratchPad()
        {
            InitializeComponent();
        }

        private void ScratchPad_Load(object sender, EventArgs e)
        {

            TextBox tb = new TextBox();
            Label l1 = new Label();
            Label l2 = new Label();
            Label l3 = new Label();
            Label l4 = new Label();


            l1.Text = "00000000000000000000000000000000000000000000000000000000000000000000000000";
            l2.Text = "is";
                l3.Text="a";
                l4.Text = "Test";

            //tableLayoutPanel1.Controls.Add(tb, 2, 2);
                tableLayoutPanel1.ColumnCount = 80;
                tableLayoutPanel1.RowCount = 25;


        }
    }
}
