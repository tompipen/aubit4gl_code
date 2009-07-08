using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
//using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace AubitDesktop
{
    public partial class ScratchPad : Form
    {
        public ScratchPad()
        {
            InitializeComponent();
        }

        private void tabPage1_Click(object sender, EventArgs e)
        {

        }
/*
        private void ScratchPad_Load(object sender, EventArgs e)
        {
            dataGridView1.ColumnCount = 5;
      //      dataGridView1.RowCount = 0;
            dataGridView1.EditMode = DataGridViewEditMode.EditProgrammatically;
           

            dataGridView1.Columns[0].Name = "Release Date";
            dataGridView1.Columns[1].Name = "Track";
            dataGridView1.Columns[2].Name = "Title";
            dataGridView1.Columns[3].Name = "Artist";
            dataGridView1.Columns[4].Name = "Album";
            dataGridView1.Columns[4].DefaultCellStyle.Font =
                new Font(dataGridView1.DefaultCellStyle.Font, FontStyle.Italic);

            string[] row0 = { "11/22/1968", "29", "Revolution 9", 
            "Beatles", "The Beatles [White Album]" };
            string[] row1 = { "1960", "6", "Fools Rush In", 
            "Frank Sinatra", "Nice 'N' Easy" };
            string[] row2 = { "11/11/1971", "1", "One of These Days", 
            "Pink Floyd", "Meddle" };
            string[] row3 = { "1988", "7", "Where Is My Mind?", 
            "Pixies", "Surfer Rosa" };
            string[] row4 = { "5/1981", "9", "Can't Find My Mind", 
            "Cramps", "Psychedelic Jungle" };
            string[] row5 = { "6/10/2003", "13", 
            "Scatterbrain. (As Dead As Leaves.)", 
            "Radiohead", "Hail to the Thief" };
            string[] row6 = { "6/30/1992", "3", "Dress", "P J Harvey", "Dry" };

            dataGridView1.Rows.Add(row0);
            dataGridView1.Rows.Add(row1);
            dataGridView1.Rows.Add(row2);
            dataGridView1.Rows.Add(row3);
            dataGridView1.Rows.Add(row4);
            dataGridView1.Rows.Add(row5);
            dataGridView1.Rows.Add(row6);

            dataGridView1.Columns[0].DisplayIndex = 3;
            dataGridView1.Columns[1].DisplayIndex = 4;
            dataGridView1.Columns[2].DisplayIndex = 0;
            dataGridView1.Columns[3].DisplayIndex = 1;
            dataGridView1.Columns[4].DisplayIndex = 2;

        }

        private void button1_Click(object sender, EventArgs e)
        {
            textBox1.Text = "Blah";
        }
 * */
    }
}
