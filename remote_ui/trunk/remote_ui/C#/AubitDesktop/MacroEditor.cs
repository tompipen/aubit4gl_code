using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;

using System.Text;
using System.Windows.Forms;

namespace AubitDesktop2
{
    public partial class MacroEditor : Form
    {
        Eval ev; 

        public MacroEditor()
        {
            InitializeComponent();
           ev = new Eval();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (ev.CompilerErrors == null)
            {
                ev.Execute();
            }
            else
            {
                MessageBox.Show("Didn't compile");
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string t;
            ev.Compile(textBox1.Text);
            t=this.Text;
            this.Text = t + " Compiling Macro....";
            if (ev.CompilerErrors != null)
            {
                string s = "";
                foreach (System.CodeDom.Compiler.CompilerError ce in ev.CompilerErrors)
                {
                    s += ce.ToString() + "\n";
                }
                MessageBox.Show(s, "Compile error");

            }
            else
            {
            //    MessageBox.Show("Compiled ok");
            }
            this.Text = t;

        }

        private void button3_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
