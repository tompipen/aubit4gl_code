
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
    class FGLBrowserFieldWidget : FGLWidget
    {

        //FGLContextType _ContextType;

        /*
        public FGLContextType ContextType
        {  // The current ContextType - a field may appear differently if its used in a construct or input..
            set
            {

                _ContextType = value;

            }
        }
        */

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


       System.Windows.Forms.WebBrowser pb;

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



        public override string Text // The current fields value
        {
            get
            {
                
                return pb.Url.ToString();

            }
            set
            
            {
                if (pb.Url == null)
                {
                    this.FieldTextChanged = true;
                }
                else
                {
                    if (value != pb.Url.ToString())
                    {
                        this.FieldTextChanged = true;
                    }
                }
                pb.Url= new Uri(value);
            }
        }

        public override void gotFocus()
        {
            
        }


        private void createWidget(ATTRIB thisAttribute, AubitDesktop.Xml.XMLForm.Matrix ma, int row, int index, int column, int rows, int columns, string widget, string config, int id, string tabcol, string action, int attributeNo, string incl)
        {
            this.SetWidget(thisAttribute,ma, row, index,column, rows, columns, widget, config, id, tabcol, action, attributeNo, incl);
            pb = new WebBrowser();

            #region SetImageFromFile
            if (configSettings.ContainsKey("URL"))
            {

                pb.Url = new Uri((string)configSettings["URL"]);
            }
            #endregion
            pb.ScrollBarsEnabled = true;
            SizeControl(ma,index,pb);


            pb.Visible = true;
            pb.Location = GuiLayout.getPoint(ma, index, column - 1, row);
        }




        public FGLBrowserFieldWidget(AubitDesktop.Xml.XMLForm.FormField ff, AubitDesktop.Xml.XMLForm.Browser browser, string config, int index, AubitDesktop.Xml.XMLForm.Matrix ma)
        {
            ATTRIB a;
            a = createAttribForWidget(ff);

                if (browser.comments != null)
                {

                    a.ATTRIB_COMMENTS = new ATTRIB_COMMENTS();
                    a.ATTRIB_COMMENTS.Text = browser.comments;
                }


            createWidget(a, ma,Convert.ToInt32(browser.posY),index, Convert.ToInt32(browser.posX), 1, Convert.ToInt32(browser.gridWidth), "", config, -1, ff.sqlTabName + "." + ff.colName, "", Convert.ToInt32(ff.fieldId), ff.include);
            
        }


        public FGLBrowserFieldWidget(ATTRIB thisAttribute, int row, int column, int rows, int columns, string widget, string config, int id, string tabcol, string action, int attributeNo, string incl)
        {

            createWidget(thisAttribute, null,row,0, column, rows, columns, widget, config, id, tabcol, action, attributeNo, incl);
            SizeControl(null,0,pb);
        }






        
    }
}

