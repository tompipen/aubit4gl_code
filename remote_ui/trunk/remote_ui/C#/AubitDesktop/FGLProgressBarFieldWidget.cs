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
    class FGLProgressBarFieldWidget : FGLWidget
    {

        ProgressBar pb ;

        internal override void ContextTypeChanged()
        {

            // We dont care...

        }


        public override int tabIndex
        {
            set
            {
                // Cant tabIndex into a Label...
            }
        }

        public override bool hasFocus
        {
            get
            {
                return false;
            }
        }


        public override void gotFocus()
        {

        }

        public override void setFocus()
        {

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
                return pb.Value.ToString();

            }
            set
            {
                pb.Value = Convert.ToInt32(value);
            }
        }


        void b_Click(object sender, EventArgs e)
        {
            if (this.onActionID != "" && this.onUIEvent != null && _ContextType != FGLContextType.ContextNone)
            {
                this.onUIEvent(this, this.onActionID, "",null);
            }
        }

        public FGLProgressBarFieldWidget(AubitDesktop.Xml.XMLForm.FormField ff, AubitDesktop.Xml.XMLForm.ProgressBar xmlPb, string config, int index,AubitDesktop.Xml.XMLForm.Matrix ma)
        {
            ATTRIB a;
            a = createAttribForWidget(ff);
            createWidget(a, ma,Convert.ToInt32(xmlPb.posY) , index, Convert.ToInt32(xmlPb.posX), 1, Convert.ToInt32(xmlPb.gridWidth), "", config, -1, ff.sqlTabName + "." + ff.colName, "", Convert.ToInt32(ff.fieldId), ff.include);
            this.pb.Enabled = true;
            this.pb.Visible = true;
            if (xmlPb.valueMax != null)
            {
                this.pb.Maximum = Convert.ToInt32(xmlPb.valueMax);
            }

            if (xmlPb.valueMin != null)
            {
                this.pb.Minimum= Convert.ToInt32(xmlPb.valueMin);

            }
            

            if (configSettings.ContainsKey("MAX")) { this.pb.Maximum = Convert.ToInt32((string)configSettings["MAX"]); }
            if (configSettings.ContainsKey("MIN")) { this.pb.Minimum= Convert.ToInt32((string)configSettings["MIN"]); }
            if (configSettings.ContainsKey("MAXIMUM")) { this.pb.Maximum = Convert.ToInt32((string)configSettings["MAXIMUM"]); }
            if (configSettings.ContainsKey("MINIMUM")) { this.pb.Minimum = Convert.ToInt32((string)configSettings["MINIMUM"]); }
        
            setPixelSize(xmlPb.pixelWidth, xmlPb.pixelHeight);

        }




        private void createWidget(ATTRIB thisAttribute, AubitDesktop.Xml.XMLForm.Matrix ma, int row, int index, int column, int rows, int columns, string widget, string config, int id, string tabcol, string action, int attributeNo, string incl)
        {
            this.SetWidget(thisAttribute, ma,row, 0,column, rows, columns, widget, config, id, tabcol, action, attributeNo, incl);
            pb = new ProgressBar();
            SizeControl(ma,index,pb);
            pb.Click += new EventHandler(b_Click);
            
        }
    }
}

