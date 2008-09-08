/*
 *  Copyright (c) 2008 The Aubit Development Team. 
 *  All rights reserved. See CREDITS file.
 *  
 *  
 *  This file is part of Aubit 4gl.
 *
 *  Aubit 4gl is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as 
 *  published by the Free Software Foundation.
 *
 *  Aubit 4gl is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Aubit 4gl.  If not, see <http://www.gnu.org/licenses/>.
 */

using System;
using System.Collections.Generic;
using System.Collections;
using System.Windows.Forms;
using System.Text;
using System.Drawing;

namespace AubitDesktop
{



    // A picture widget fgl field widget...
    class FGLPixmapFieldWidget : FGLWidget
    {

        public override void ContextTypeChanged()
        {
            // Does nothing...
        }

        public override int tabIndex
        {
            set
            {
                pb.TabIndex = value;
            }
        }

        public override bool hasFocus
        {
            get
            {
                return false;
            }
        }


        PictureBox pb;

        public override void setFocus()
        {
            pb.Focus();
        }

        public override Control WindowsWidget
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

        public FGLPixmapFieldWidget(AubitDesktop.Xml.XMLForm.FormField ff,AubitDesktop.Xml.XMLForm.Image pixmap,string config)
        {
            ATTRIB a;
            a = createAttribForWidget(ff);


            createWidget(a, Convert.ToInt32(pixmap.posY), Convert.ToInt32(pixmap.posX), 1, Convert.ToInt32(pixmap.gridWidth), "", config, -1, ff.sqlTabName + "." + ff.colName, "", Convert.ToInt32(ff.fieldId), ff.include);
            
        }

        public FGLPixmapFieldWidget(ATTRIB thisAttribute, int row, int column, int rows, int columns, string widget, string config, int id, string tabcol, string action, int attributeNo, string incl)
        {
            
            createWidget(thisAttribute, row, column, rows, columns, widget, config, id, tabcol, action, attributeNo, incl);
        }

        private void createWidget(ATTRIB thisAttribute, int row, int column, int rows, int columns, string widget, string config, int id, string tabcol, string action, int attributeNo, string incl)
        {
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
                    dir = "c:/images"; //Properties.  Resources.ImageDirectory;
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

            SizeControl(pb);
            pb.SizeMode = PictureBoxSizeMode.StretchImage;
            pb.Visible = true;
            pb.Location = new System.Drawing.Point(GuiLayout.get_gui_x(column - 1), GuiLayout.get_gui_y(row));
        }
    }
}
