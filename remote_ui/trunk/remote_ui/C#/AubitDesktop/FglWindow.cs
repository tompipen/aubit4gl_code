using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Forms;
using System.Drawing;

namespace AubitDesktop
{
    class FGLWindow
    {
        internal FGLForm CurrentForm;
        public string windowName;
        public int x;
        public int y;
        int attribute;
        string text;
        string style;
        public bool isModal;
        internal int error_line;
        internal int prompt_line;
        internal int menu_line;
        internal int comment_line;
        internal int message_line;
        internal int form_line;
        public bool border;
        public int LineHeight;
        public int CharWidth;
        public bool isContainable;
        public Control WindowWidget;
        public Form WindowFormWidget;
        bool KeepFormOpenWhenWindowCloses;
        private Font fixedWidthFont;

        Label[,] backgroundLabels;

        

        public bool hasForm
        {
            get
            {
                return (CurrentForm != null);
            }
        }


        public FGLWindow(string windowName)
        {
            // This should only be used for 'SCREEN' 
            if (windowName.ToLower() != "screen")
            {
                Program.Show("FGLWindow(windowname) should only be called for 'SCREEN'");
                return;
            }
            this.windowName = windowName;
            this.x = 0;
            this.y = 0;
            this.attribute = 0;
            this.text = "";
            this.style = "";
            this.error_line = 255;
            this.prompt_line = 255;
            this.menu_line = 255;
            this.comment_line = 255;
            this.message_line = 255;
            this.border = false;
            this.isContainable = true;
            this.isModal = false;
            this.CurrentForm = null;
            this.LineHeight = 0;
            this.CharWidth = 0;
            Panel p = new Panel();
            p.Name = "WinPan" + windowName;
            p.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            //p.BackColor = Color.Aqua;
            WindowWidget = p;
            WindowFormWidget = null;
            WindowWidget.Visible = true;
            clrFormlabels();

            WindowWidget.Top = 15;
            WindowWidget.Left = 5;
            sizeWindowToFill();
        }


        public FGLWindow(string windowName, int x, int y, int attribute, string text, string style, int error_line, int prompt_line, int menu_line, int comment_line, int message_line, int form_line,bool border)
        {
            int colourCode;
            this.windowName = windowName;
            this.x = x;
            this.y = y;
            this.LineHeight = 0;
            this.CharWidth = 0;
            this.attribute = attribute;
            this.text = text;
            this.style = style;
            this.error_line = error_line;
            this.prompt_line = prompt_line;
            this.menu_line = menu_line;
            this.comment_line = comment_line;
            this.message_line = message_line;
            this.form_line = form_line;
            this.border = border;
            this.isContainable = true;
            this.isModal = false;
            this.CurrentForm = null;

            colourCode = (attribute & 0xf00) >> 8;

            switch (style)
            {
                case "":
                case "NORMAL":
                    {
                        Panel p;
                        p = new Panel();
                        WindowWidget = p;
                        p.Name = "PanNormal" + windowName;
                        WindowFormWidget = null;
                        if (border)
                        {
                            p.BorderStyle = BorderStyle.Fixed3D;
                        }
                        p.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
                        WindowWidget.Visible = true;
                        switch (colourCode)
                        {
                            case 1:
                                p.BackColor = System.Drawing.Color.LightCoral;
                                break;

                            case 2:
                                p.BackColor = System.Drawing.Color.LightGreen;
                                break;

                            case 3:
                                p.BackColor = System.Drawing.Color.LightGoldenrodYellow;
                                break;

                            case 4:
                                p.BackColor = System.Drawing.Color.LightBlue;
                                break;

                            case 5:
                                p.BackColor = System.Drawing.Color.Magenta;
                                break;

                            case 6:
                                p.BackColor = System.Drawing.Color.LightCyan;
                                break;
                        }
                    }
                    break;

                case "GROUPBOX":
                    {
                        GroupBox g; // Group boxes are always bordered....
                        g = new GroupBox();
                        g.Text = text;
                        WindowWidget = g;
                        WindowFormWidget = null;
                        WindowWidget.Visible = true;
                        g.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
                    }
                    break;


                case "WINDOW":
                    {
                        Form frm;
                        frm = new Form();
                        frm.Text = text;
                        WindowWidget = frm;
                        WindowFormWidget = frm;
                        frm.AutoSize = true;
                        frm.Width = 10;
                        frm.Height = 10;
                        frm.StartPosition = FormStartPosition.CenterParent;
                        frm.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
                        sizeWindowToFill();
                    }

                    WindowWidget.Visible = true;
                    isContainable = false;
                    break;


                case "MODALWINDOW":
                    {
                        Form frm;

                        frm = new Form();
                        frm.Visible = false;
                        frm.Text = text;
                        WindowWidget = frm;
                        WindowFormWidget = frm;
                        frm.AutoSize = true;
                        frm.Width = 10;
                        frm.Height = 10;
                        frm.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
                        sizeWindowToFill();
                    }

                    isContainable = false;
                    isModal = true;
                    break;



                default:
                    Program.Show("Unhandled window style");
                    break;
            }
            // WEBGUI WindowWidget.BackColor = System.Drawing.Color.FromArgb(240, 240, 240);


            WindowWidget.Top = GuiLayout.get_gui_y(y);
            WindowWidget.Left = GuiLayout.get_gui_x(x);
            WindowWidget.Name = "WindowFor" + windowName;

            clrFormlabels();
        }

        public void DisplayTo(DISPLAYTO d)
        {
            this.CurrentForm.DisplayTo(d);
        }

        /*
        public void doInput(INPUT i)
        {
            this.CurrentForm.DoInput(i);
        }
         * */



        public void setForm(FGLForm f, bool KeepFormOpenWhenWindowCloses)
        {
            
            if (this.CurrentForm != null)
            {
                if (WindowWidget != null)
                {
                    if (WindowWidget.Controls.Contains(CurrentForm.thisFormsPanel))
                    {
                        WindowWidget.Controls.Remove(CurrentForm.thisFormsPanel);
                    }
                }
            }

            this.CurrentForm = f;
            if (this.LineHeight == 0)
            {
                this.LineHeight = f.maxline;
            }
            if (this.CharWidth == 0)
            {
                this.CharWidth = f.maxcol;
            }

            if (this.WindowWidget.BackColor != System.Drawing.SystemColors.Control)
            {
                f.thisFormsPanel.BackColor = this.WindowWidget.BackColor;
            }

            if (this.form_line == 255) // Its the default - use the OPTIONS FORM LINE...
            {
                //f.thisFormsPanel.Top = 0;
            }
            else
            {
                Padding p;
                p = f.thisFormsPanel.Padding;
                p.Top = GuiLayout.get_gui_y(form_line );
                f.thisFormsPanel.Padding=p;
            }
            
            WindowWidget.Controls.Add(f.thisFormsPanel);


           
            //WindowWidget.BackColor = Color.Aqua;
            
            //for (int a = 1; a < 1000; a++)
            //{
             //   f.thisFormsPanel.Top = a;
              //  f.thisFormsPanel.Left = a;
               // Application.DoEvents();
                //System.Threading.Thread.Sleep(10);
           // }
          //  f.thisFormsPanel.BorderStyle = BorderStyle.Fixed3D;
            this.KeepFormOpenWhenWindowCloses = KeepFormOpenWhenWindowCloses;
        }


        public void RemoveForm()
        {
            if (this.CurrentForm != null)
            {
                WindowWidget.Controls.Clear();
                this.CurrentForm.Dispose();
                this.CurrentForm = null;
            }
        }


        public void sizeWindow(int x, int y,bool border)
        {
            LineHeight = y;
            CharWidth = x;
	    if (border) {
            	WindowWidget.Height = GuiLayout.get_gui_y(y+1);
            	WindowWidget.Width = GuiLayout.get_gui_x(x+1);
	    } else {
                WindowWidget.Height = GuiLayout.get_gui_y(y);
                WindowWidget.Width = GuiLayout.get_gui_x(x);
	    }
        }

        public void sizeWindow(FGLForm f, bool border)
        {
            if (form_line != 255)
            {
                LineHeight = f.maxline + form_line - 1; /* form line is 1 based */
            }
            else
            {
                LineHeight = f.maxline;
            }
            CharWidth = f.maxcol;

            if (isContainable)
            {

                if (f.pixelWidth > 0 && f.pixelHeight > 0)
                {
                    WindowWidget.Height = f.pixelHeight + 5 + f.thisFormsPanel.Top;
                    WindowWidget.Width = f.pixelWidth + 5 + f.thisFormsPanel.Left;
                }
                else
                {
                    if (f.maxcol >= 0 && f.maxline >= 0)
                    {

                        if (border)
                        {
                            WindowWidget.Height = GuiLayout.get_gui_y(f.maxline + form_line);
                            WindowWidget.Width = GuiLayout.get_gui_x(f.maxcol + 1);
                        }
                        else
                        {
                            WindowWidget.Height = GuiLayout.get_gui_y(f.maxline + form_line - 1) + 20;
                            WindowWidget.Width = GuiLayout.get_gui_x(f.maxcol) + 20;
                        }
                    }
                    else
                    {

                        WindowWidget.AutoSize = true;

                    }
                }

            }

        }

        public void sizeWindowToFill()
        {
            WindowWidget.Dock = DockStyle.Fill;
        }



        internal void saveForm()
        {
            if (this.CurrentForm != null)
            {
                this.CurrentForm.saveForm();
            }


        }


        internal void SetContext(FGLContextType contextType)
        {
            try
            {
                CurrentForm.SetContext(contextType);
            }
            catch (Exception) { }
        }

        internal void SetContext(FGLContextType contextType, List<FGLWidget> pfields, UIContext currContext, List<ONKEY_EVENT> keyList, List<ON_ACTION_EVENT> actionList, UIEventHandler _evtHandler)
        {
            CurrentForm.SetContext(contextType, pfields, keyList, actionList, currContext, _evtHandler);
        }

        internal List<FGLFoundField> FindFields(FIELD[] fieldlist)
        {
            return CurrentForm.FindFields(fieldlist);
        }

        internal List<FGLFoundField> FindFields(string[] fieldlist)
        {
            return CurrentForm.FindFields(fieldlist);
        }



        internal void setNextField(string NextField)
        {
            CurrentForm.setNextField(NextField);
        }

        internal List<FGLFoundField> FindAction(string actionName)
        {
            return CurrentForm.FindAction(actionName);
        }

        internal List<FGLFoundField> FindFieldArray(FIELD[] fieldlist)
        {
            return CurrentForm.FindFieldArray(fieldlist);
        }

        internal void clearForm()
        {
            this.CurrentForm.clearForm();

        }

        internal FormattedGridView findRecord(FIELD[] fIELD)
        {
            return CurrentForm.FindRecord(fIELD);
        }

        internal void Clear(CLEAR z)
        {
            this.CurrentForm.Clear(z);
        }
        private void clrFormlabels()
        {

            backgroundLabels = new Label[80, 24];

            for (int x = 0; x < 80; x++)
            {

                for (int y = 0; y < 24; y++)
                {
                    backgroundLabels[x, y] = null;
                }
            }
            fixedWidthFont = new Font(FontFamily.GenericMonospace, 10, FontStyle.Regular);
        }

        /// <summary>
        /// Display a single character at an x/y location (1 based) 
        /// create a label if required to do it.
        /// 
        /// </summary>
        /// <param name="x">X position (1 based)</param>
        /// <param name="y">Y position (1 based)</param>
        /// <param name="s">String to display (or null to remove any existsing label)</param>
        /// <param name="attr">Numeric attribute (eg. 4096 for reverse video) </param>
        private void displayAtLabel(int x, int y, string s, int attr)
        {
            Label l;


            return;



            if (s == null)
            {
                if (backgroundLabels[x - 1, y - 1] != null)
                {
                    backgroundLabels[x - 1, y - 1].Visible = false;
                    backgroundLabels[x - 1, y - 1] = null;
                }
                return;
            }

            if (backgroundLabels[x - 1, y - 1] == null)
            {
                
                l = new Label();
                l.AutoSize = false;
                l.Width = GuiLayout.get_gui_w(1);
                l.Height = GuiLayout.get_gui_h(1);
                l.Left = GuiLayout.get_gui_x(x);
                l.Top = GuiLayout.get_gui_y(y);
                l.TextAlign =  ContentAlignment.MiddleCenter;
                l.Font = fixedWidthFont;
                backgroundLabels[x - 1, y - 1] = l;
                this.WindowWidget.Controls.Add(backgroundLabels[x - 1, y - 1]);
                l.BringToFront();
            } else {
                l=backgroundLabels[x - 1, y - 1];
            }

            backgroundLabels[x - 1, y - 1].Text = s;
            if (this.CurrentForm != null)
            {
                l.Left = GuiLayout.get_gui_x(x);
                l.Top = GuiLayout.get_gui_y(y);
                if (l.Left > this.CurrentForm.thisFormsPanel.Left && l.Left < this.CurrentForm.thisFormsPanel.Right)
                {
                    if (l.Top > this.CurrentForm.thisFormsPanel.Top && l.Top < this.CurrentForm.thisFormsPanel.Bottom)
                    {
                        // Its actually in the 'current' form - not the background window...
                        l.Parent = this.CurrentForm.thisFormsPanel;
                        l.Top -= this.CurrentForm.thisFormsPanel.Top;
                        l.Left -= this.CurrentForm.thisFormsPanel.Left;
                    }
                }
            }
            else
            {
                l.Left = GuiLayout.get_gui_x(x);
                l.Top = GuiLayout.get_gui_y(y);
            }
            if ((attr & 4096) > 0)
            {
                backgroundLabels[x - 1, y - 1].BackColor = Color.Bisque;
            }
            else
            {
                backgroundLabels[x - 1, y - 1].BackColor = this.WindowWidget.BackColor;
            }
            backgroundLabels[x - 1, y - 1].BringToFront();
        }



        internal void DisplayAt(DISPLAYAT d)
        {

            if (d.Text == null)
            { // Delete to the end of the line....
                for (int x = Convert.ToInt32(d.X); x <= 80; x++)
                {
                    displayAtLabel(x, d.Y, null, Convert.ToInt32(d.ATTRIBUTE));
                }
            }
            else
            {
                for (int x = 0; x < d.Text.Length; x++)
                {
                    displayAtLabel(x + d.X, d.Y, d.Text.Substring(x,1), Convert.ToInt32(d.ATTRIBUTE));
                }
            }
        }




                internal List<DataGridViewCell> FindRecordCells(FIELD[] fieldlist)
        {
            return CurrentForm.FindRecordCells(fieldlist);
        }
        
    }

}
