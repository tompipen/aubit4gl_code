
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
    class FGLBrowserFieldWidget : FGLWidget, IFGLField
    {

        FGLContextType _ContextType;

        public FGLContextType ContextType
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


       System.Windows.Forms.WebBrowser pb;

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

        public FGLBrowserFieldWidget(ATTRIB thisAttribute, int row, int column, int rows, int columns, string widget, string config, int id, string tabcol, string action, int attributeNo, string incl)
        {
            //this._WidgetDetails = new FGLWidget();
            this.SetWidget(thisAttribute, row, column, rows, columns, widget, config, id, tabcol, action, attributeNo, incl);
            pb = new WebBrowser();

            #region SetImageFromFile
            if (configSettings.ContainsKey("URL"))
            {
                string dir;
                pb.Url = new Uri((string)configSettings["URL"]);
            }
            #endregion
            pb.ScrollBarsEnabled = true;
            SizeControl(pb);


            pb.Visible = true;
            pb.Location = new System.Drawing.Point(GuiLayout.get_gui_x(column - 1), GuiLayout.get_gui_y(row));
        }
    }
}

