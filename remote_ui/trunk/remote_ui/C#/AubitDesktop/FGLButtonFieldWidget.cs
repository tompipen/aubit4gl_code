using System;
using System.Collections.Generic;
using System.Collections;
using System.Windows.Forms;
using System.Text;
using System.Drawing;

namespace AubitDesktop
{
    // A picture widget fgl field widget...
    class FGLButtonFieldWidget : FGLWidget, IFGLField
    {

        string _ContextType;

        public string ContextType
        {  // The current ContextType - a field may appear differently if its used in a construct or input..
            set
            {
                _ContextType = value;
                if (_ContextType == "")
                {
                    this.Enabled = false;
                }
                else
                {
                    this.Enabled = true;
                }
            }
        }


        public int tabIndex
        {
            set
            {
                b.TabIndex = value;
            }
        }

        public bool hasFocus
        {
            get
            {
                return false;
            }
        }


        Button b;

        public void setFocus()
        {
            b.Focus();
        }

        public Control WindowsWidget
        {
            get
            {
                return (Control)b;
            }
        }

        public new bool Enabled
        {
            get
            {
                
                return b.Enabled;
            }
            set
            {
                b.Enabled=value;

            }
        }

        public new string Text // The current fields value
        {
            get
            {
                return b.Text;

            }
            set
            {
                b.Text=value;
            }
        }

        void b_Click(object sender, EventArgs e)
        {
            if (this.onActionID != "" && this.onUIEvent != null && _ContextType != "")
            {
                this.onUIEvent(this, this.onActionID, "");
            }
        }

        public FGLButtonFieldWidget(ATTRIB thisAttribute, int row, int column, int rows, int columns, string widget, string config, int id, string tabcol, string action, int attributeNo, string incl)
        {

            this.SetWidget(thisAttribute, row, column, rows, columns, widget, config, id, tabcol, action, attributeNo, incl);
            b = new Button();
            SizeControl(b);
            if (configSettings.ContainsKey("TEXT")) { this.Text = (string)configSettings["TEXT"]; }
            b.Click+=new EventHandler(b_Click);
        }
    }
}
