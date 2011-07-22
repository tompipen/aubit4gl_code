using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Drawing.Printing;

namespace AubitDesktop
{
    public partial class frmTxtFileViewer : Form
    {

        const int MaximumPages = 20;

        int linesPerPage = 66;
        private enum epageMode
        {
            pageModeFile,
            pageModePage

        };

        private epageMode _pagemode = epageMode.pageModeFile;


        private epageMode PageMode
        {
            set
            {
                _pagemode = value;
                setVisuals();
            }
            get
            {
                return _pagemode;
            }
        }

        private void setVisuals()
        {
            if (_pagemode == epageMode.pageModeFile)
            {
                tbFileContents.Visible = true;
                tabControl1.Visible = false;
                

            }
            else
            {
                tbFileContents.Visible = false;
                tabControl1.Visible = true;
            }

            fileModeToolStripMenuItem.Checked = tbFileContents.Visible;
            pageModeToolStripMenuItem.Checked = tabControl1.Visible;
        }
        List<string[]> pages;
        int currprintingpage = 0;
        string Mode;

        public frmTxtFileViewer()
        {
            InitializeComponent();
            Mode = "SCREEN";
        }

        public frmTxtFileViewer(string pMode)
        {
            InitializeComponent();
            Mode = pMode.ToUpper();
        }

        

        public void setText(string str, int pLinesPerPage)
        {
            if (str.Contains("\r\n"))
            {
                tbFileContents.Text = str;
                
            }
            else
            {
                tbFileContents.Text = str.Replace("\n", "\r\n");
            }
            linesPerPage = pLinesPerPage;
            tbFileContents.SelectionStart = 0;
            tbFileContents.SelectionLength = 0;
            Paginate();
            tabControl1.Controls.Clear();

            for (int a = 0; a < pages.Count; a++)
            {
                if (a > MaximumPages)
                {
                    addPage("...", "" + (pages.Count - MaximumPages) + " more pages");
                    break;
                }
                string[] s=pages[a];
                StringBuilder sb=new StringBuilder();
                for (int b=0;b<s.Length;b++) {
                    if (b > 0) sb.Append("\r\n");
                    sb.Append((b+1).ToString("00000")+" "+ s[b]);
                }
                addPage("Page " + (a + 1), sb.ToString());
            }
        }

        private void addPage(string title, string tbContents)
        {
            TabPage tp=new TabPage(title);
            TextBox tb=new TextBox();
            tb.Font=tbFileContents.Font;
            tb.Multiline=true;
            tb.BackColor=tbFileContents.BackColor;
            tb.ForeColor=tbFileContents.ForeColor;
            tb.ScrollBars=tbFileContents.ScrollBars;
            tb.Text = tbContents;
            tb.SelectionLength = 0;
            tb.Dock = DockStyle.Fill;
            tp.Controls.Add(tb);
            tabControl1.Controls.Add(tp);
        }


        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private string[] newPage()
        {
            string[] newPageArray=new string[linesPerPage];
            for (int a = 0; a < linesPerPage; a++)
            {
                newPageArray[a] = null;
            }
            return newPageArray;
        }




        private void saveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            SaveFileDialog sfd = new SaveFileDialog();
            sfd.AddExtension = true;
            sfd.DefaultExt = ".txt";
            sfd.OverwritePrompt = true;
            DialogResult r = sfd.ShowDialog();
            if (r == DialogResult.OK)
            {
                try
                {
                    string newFileStr;

                    newFileStr = getMSFormattedString();

                    System.IO.StreamWriter file =
                              new System.IO.StreamWriter(sfd.FileName);

                    file.Write(newFileStr);
                    file.Close();
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message, "Unable to save file");
                }
            }
        }

        private string getMSFormattedString()
        {
            string newFileStr;
            if (tbFileContents.Text.Contains("\r\n"))
            {
                newFileStr = tbFileContents.Text;
            }
            else
            {
                newFileStr = tbFileContents.Text.Replace("\n", "\r\n");
            }
            return newFileStr;
        }




        private void printToolStripMenuItem_Click(object sender, EventArgs e)
        {



            printFile();


        }

        private void printFile()
        {
            // Now - we have each page divided into a separate string..
            currprintingpage = 0;

            PrintDocument pd = new PrintDocument();

            pd.PrintPage += new PrintPageEventHandler(pd_PrintPage);
            printDialog1.Document = pd;

            if (printDialog1.ShowDialog() == DialogResult.OK)
            {
                pd.Print();
            }
            
        }

        private void Paginate()
        {
            string[] separators = new string[2];
            separators[0] = "\r\n";
            pages = new List<string[]>();

            // First - lets split our big textbox string into pages..
            // We do this by first splitting into lines...
            string[] lines = tbFileContents.Text.Split(separators, StringSplitOptions.None);

            // Create a string array to store all the lines of a page...
            string[] thisPage = newPage();


            int lcnt = 0; // How far down the current page are we ?


            // Now - go through all the lines in the report, and split into pages...
            for (int a = 0; a < lines.Length; a++)
            {

                if (lines[a] == "\f")
                {
                    pages.Add(thisPage);
                    thisPage = newPage();
                    lcnt = 0;
                }
                if (lcnt >= linesPerPage)
                {
                    pages.Add(thisPage);
                    thisPage = newPage();
                    lcnt = 0;
                }

                if (lines[a].Trim().Length == 0)
                {
                    thisPage[lcnt] = null;
                }
                else
                {
                    thisPage[lcnt] = lines[a];
                }
                lcnt++;
            }

            if (lcnt > 0)
            {
                pages.Add(thisPage);
            }

            // Is the last page blank ? 
            if (pages.Count > 0)
            {
                bool isAllBlank = true;
                thisPage = pages[pages.Count - 1];
                for (int a = 0; a < linesPerPage; a++)
                {
                    if (thisPage[a] == null) continue;
                    if (thisPage[a].Trim().Length == 0) continue;
                    isAllBlank = false;
                    break;

                }
                if (isAllBlank)
                {
                    pages.RemoveAt(pages.Count - 1);
                }
            }
        }

        void pd_PrintPage(object sender, PrintPageEventArgs ev)
        {
            float ActualLinesPerPage = 0;
            float yPosition = 0;
            int count = 0;
            float leftMargin = ev.MarginBounds.Left;
            float topMargin = ev.MarginBounds.Top;
            Font printFont = tbFileContents.Font;
            SolidBrush myBrush = new SolidBrush(Color.Black);

            ActualLinesPerPage = ev.MarginBounds.Height / printFont.GetHeight(ev.Graphics);
            // Iterate over the string using the StringReader, printing each line.

            for (int a=0;a<linesPerPage;a++) {
                if (a>ActualLinesPerPage) continue; // We cant print it - theres no room... (maybe it should be in a smaller font !

                // calculate the next line position based on the height of the font according to the printing device
                yPosition = topMargin + (a * printFont.GetHeight(ev.Graphics));
                // draw the next line in the rich edit control
                string line = pages[currprintingpage][a];
                if (line != null)
                {
                    ev.Graphics.DrawString(line, printFont, myBrush, leftMargin, yPosition, new StringFormat());
                }
                count++;
            }

            currprintingpage++;

            // If there are more lines, print another page.
            if (currprintingpage>=pages.Count)
                ev.HasMorePages = false;
            else
                ev.HasMorePages = true;

            myBrush.Dispose();
        }

        private void viewToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void fileModeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            PageMode = epageMode.pageModeFile;
        }

        private void pageModeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            PageMode = epageMode.pageModePage;
        }

        private void frmTxtFileViewer_Load(object sender, EventArgs e)
        {
            tbFileContents.Dock = DockStyle.Fill;
            tabControl1.Dock = DockStyle.Fill;

            PageMode = epageMode.pageModeFile;

            if (Mode.StartsWith("PRINT"))
            {
                printFile();
            }
            if (Mode == "PRINTANDCLOSE")
            {
                this.Close();
            }
        }

    }
}
