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
using System.IO;

namespace AubitDesktop
{



    // A picture widget fgl field widget...
    public class FGLPixmapFieldWidget : FGLWidget
    {

        internal override void ContextTypeChanged()
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

        internal override Control WindowsWidget
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

        private Image bytetoimg(byte[] bytearr)
        {
            Image newImage;
            MemoryStream ms = new MemoryStream(bytearr, 0, bytearr.Length);
            ms.Write(bytearr, 0, bytearr.Length);
            newImage = Image.FromStream(ms, true);
            return newImage;
        }

        public override string Text // The current fields value
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


                if (value == null)
                {
                    pb.Image = null;
                }
                else
                {
                    
                    pb.Image = FGLUtils.getImageFromName(value);
                    if (pb.Image == null)
                    {
                        byte[]file=Convert.FromBase64String(value);
                        pb.Image = bytetoimg(file);
                    }
                }
            }
        }




        public FGLPixmapFieldWidget(AubitDesktop.Xml.XMLForm.FormField ff, AubitDesktop.Xml.XMLForm.Image pixmap, string config, int index, AubitDesktop.Xml.XMLForm.Matrix ma)
        {
            ATTRIB a;
            a = createAttribForWidget(ff);


            createWidget(a, ma,Convert.ToInt32(pixmap.posY),index, Convert.ToInt32(pixmap.posX), 1, Convert.ToInt32(pixmap.gridWidth), "", config, -1, ff.sqlTabName + "." + ff.colName, "", Convert.ToInt32(ff.fieldId), ff.include);
            
        }

        public FGLPixmapFieldWidget(ATTRIB thisAttribute, int row, int column, int rows, int columns, string widget, string config, int id, string tabcol, string action, int attributeNo, string incl)
        {
            
            createWidget(thisAttribute,null, row,0, column, rows, columns, widget, config, id, tabcol, action, attributeNo, incl);
        }

        private void createWidget(ATTRIB thisAttribute, AubitDesktop.Xml.XMLForm.Matrix ma, int row, int index,int column, int rows, int columns, string widget, string config, int id, string tabcol, string action, int attributeNo, string incl)
        {
            this.SetWidget(thisAttribute, ma,row, index,column, rows, columns, widget, config, id, tabcol, action, attributeNo, incl);
            pb = new PictureBox();

            #region SetImageFromFile
            if (configSettings.ContainsKey("FILENAME"))
            {
                string dir;
                Image obj;

                obj = (Image) FGLUtils.getImageFromName((string)configSettings["FILENAME"]);
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

            SizeControl(ma,index,pb);
            pb.SizeMode = PictureBoxSizeMode.StretchImage;
            pb.Visible = true;
            pb.Location = GuiLayout.getPoint(ma, index, column - 1, row);
        }
    }
}
