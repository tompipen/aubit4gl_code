using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Xml;



namespace AubitDesktop
{
    public partial class Login : Form
    {

        private frmConsole myConsole;
        

        public Login()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            myConsole = new frmConsole();
            myConsole.Visible = false;
        }


        private void btnConnect_Click(object sender, EventArgs e)
        {
              frmMainAppWindow appWindow;
              btnConnect.Enabled = false;
              appWindow = new frmMainAppWindow(this.txtServer.Text, 3490,txtApplication.Text,txtUsername.Text, txtPassword.Text,myConsole);
              if (!appWindow.IsDisposed)
              {
                  appWindow.Show();
              }
              btnConnect.Enabled = true;
              
           
        }

        private void button1_Click(object sender, EventArgs e)
        {
            ScratchPad sp;
            sp = new ScratchPad();
            sp.Show();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            //tbResult.Text=FGLUsing.A4GL_func_using(tbFormat.Text, tbNumber.Text, FGLUtils.FGLDataTypes.DTYPE_CHAR);
        }

        private void button1_Click_2(object sender, EventArgs e)
        {
            /*
            Eval ev = new Eval();
            



            ev.Compile("System.Windows.Forms.MessageBox.Show(\"Banana\");");
            
            if (ev.CompilerErrors!=null) {
                string s="";
                foreach (System.CodeDom.Compiler.CompilerError ce in ev.CompilerErrors) {
                    s += ce.ToString()+"\n";
                }
                MessageBox.Show(s, "Compile error");
                
            } else {

                    ev.Execute();
 
            }
             * */
            MacroEditor m = new MacroEditor();
            m.ShowDialog();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            ScratchPad sp = new ScratchPad();
            sp.Show();
        }

        




    }
}