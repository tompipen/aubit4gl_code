using System;
using System.Collections.Generic;
using System.Collections;
using System.Windows.Forms;
using System.Text;
using System.Drawing;

namespace AubitDesktop
{



    // A picture widget fgl field widget...
    class FGLPixmapFieldWidget : FGLWidget, IFGLField
    {

        string _ContextType;

        public string ContextType
        {  // The current ContextType - a field may appear differently if its used in a construct or input..
            set
            {

                _ContextType = value;

            }
        }


        public int tabIndex
        {
            set
            {
                pb.TabIndex = value;
            }
        }

        public bool hasFocus
        {
            get
            {
                return false;
            }
        }


        PictureBox pb;

        public void setFocus()
        {
            pb.Focus();
        }

        public Control WindowsWidget
        {
            get
            {

                return (Control)pb;
            }
        }

        public new bool Enabled
        {
            get
            {
                return false;
            }
            set
            {

            }
        }

        public new string Text // The current fields value
        {
            get
            {
                return pb.ImageLocation;

            }
            set
            {
                if (value != pb.ImageLocation)
                {
                    this.FieldTextChanged = true;
                }
                pb.ImageLocation = value;
            }
        }

        public FGLPixmapFieldWidget(ATTRIB thisAttribute, int row, int column, int rows, int columns, string widget, string config, int id, string tabcol, string action, int attributeNo, string incl)
        {
            //this._WidgetDetails = new FGLWidget();
            this.SetWidget(thisAttribute, row, column, rows, columns, widget, config, id, tabcol, action, attributeNo, incl);
            pb = new PictureBox();

            #region SetImageFromFile
            if (configSettings.ContainsKey("FILENAME"))
            {
                string dir;
                Image obj;

                obj = (Image)resourceInterface.getObject((string)configSettings["FILENAME"]);
                //pb.BackColor = Color.AliceBlue;


                if (obj != null)
                {
                    pb.Image = obj;
                }
                else
                {
                    dir = "c:/images" ; //Properties.  Resources.ImageDirectory;
                    if (!dir.EndsWith("/") && !dir.EndsWith("\\"))
                    {
                        dir = dir + "/";
                    }
                    try
                    {
                        pb.Load(dir + "/" + (string)configSettings["FILENAME"]);
                    }
                    catch
                    {
                        ;
                    }
                }
            }
            #endregion

            pb.Height = GuiLayout.get_gui_h(rows);
            if (columns > 2)
            {
                pb.Width = GuiLayout.get_gui_w(columns + 1);
            }
            else
            {
                pb.Width = GuiLayout.get_gui_w(3);
            }

            if (configSettings.ContainsKey("HEIGHT"))
            {
                pb.Height = GuiLayout.get_gui_h(Convert.ToInt32((string)configSettings["HEIGHT"]));
            }
            if (configSettings.ContainsKey("WIDTH"))
            {
                pb.Width = GuiLayout.get_gui_w(Convert.ToInt32((string)configSettings["WIDTH"]));
            }
            pb.SizeMode = PictureBoxSizeMode.StretchImage;
            pb.Visible = true;
            pb.Location = new System.Drawing.Point(GuiLayout.get_gui_x(column - 1), GuiLayout.get_gui_y(row));
        }
    }
}
