using System;
using System.Collections.Generic;
using System.Windows.Forms;
using System.Text;
using System.Drawing;

namespace AubitDesktop2
{
    // A text widget fgl field widget...
    class FGLDateFieldWidget : FGLWidget, IFGLField
    {
        string _ContextType;
        /*
        private FGLWidget _WidgetDetails;

        public FGLWidget WidgetDetails
        {
            get
            {
                return _WidgetDetails;
            }
        }
         * */

        public int tabIndex
        {
            set
            {
                t.TabIndex = value;
            }
        }

        public bool hasFocus
        {
            get
            {
                if (t.Enabled && t.Focused) return true;
                return false;
            }
        }


        public string ContextType
        {  // The current ContextType - a field may appear differently if its used in a construct or input..
            set
            {

                _ContextType = value;
                if (_ContextType == ""  )
                {
                    l.Visible = true;
                    t.Visible = false;
                }
                else
                {
                    l.Visible = false;
                    t.Visible = true;
                }


            }
        }

        DateTimePicker t;
        Panel p;
        Label l;

        public Control WindowsWidget
        {
            get
            {
                return (Control)p;
            }
        }

        public void setFocus()
        {
           t.Focus();
        }

        public new bool Enabled
        {
            get
            {
                return t.Enabled;
            }
            set
            {
                t.Enabled = value;
            }
        }


        public override string Text // The current fields value
        {
            get
            {
                return t.Text;
            }
            set
            {
                if (value != t.Text)
                {
                    this.FieldTextChanged = true;
                }
                l.Text = value;
                t.Text = value;
            }
        }

        public FGLDateFieldWidget(ATTRIB thisAttribute, int row, int column, int rows, int columns, string widget, string config, int id, string tabcol, string action, int attributeNo,string incl)
        {
       
            //his._WidgetDetails = new FGLWidget();
            this.SetWidget(thisAttribute, row, column, rows, columns, widget, config, id, tabcol, action, attributeNo,incl);

            p = new Panel();
            l = new Label();
            l.TextAlign = ContentAlignment.MiddleLeft;
            t = new System.Windows.Forms.DateTimePicker();
            t.Format = DateTimePickerFormat.Custom;
            t.CustomFormat = FGLUtils.DBDATEFormat_dotnet; //@ FIXME - DBDATE Dependant..
            t.Visible = true;
            t.Enabled = true;
            p.Location = new System.Drawing.Point(GuiLayout.get_gui_x(column), GuiLayout.get_gui_y(row));
            p.AutoSize = true;

            t.Size = new Size(GuiLayout.get_gui_w(columns), GuiLayout.get_gui_h(rows));

            if (columns > 2)
            {
                t.Width = GuiLayout.get_gui_w(columns + 2);
            }
            else
            {
                t.Width = GuiLayout.get_gui_w(3);
            }

            l.Size = t.Size;

            l.Visible = true;
            l.BorderStyle = BorderStyle.Fixed3D;
            p.Controls.Add(t);
            p.Controls.Add(l);
            p.Size = t.Size;

            t.LostFocus += new EventHandler(t_LostFocus);
            t.GotFocus += new EventHandler(t_GotFocus);
            t.Validating += new System.ComponentModel.CancelEventHandler(t_Validating);

        }

        void t_Validating(object sender, System.ComponentModel.CancelEventArgs e)
        {
            // Need to copy from textfield...
        }

        void t_GotFocus(object sender, EventArgs e)
        {
            
        }

        void t_LostFocus(object sender, EventArgs e)
        {
            
        }
        /*
        public string ColumnName
        {
            get { return _WidgetDetails.ColumnName; }
        }

        public UIEventHandler onUIEvent
        {
            get { return _WidgetDetails.onUIEvent; }
        }
        public string defaultValue
        {
            get { return _WidgetDetails.defaultValue; }
        }


        public string afterFieldID
        {
            get
            {
                return _WidgetDetails.afterFieldID;
            }
            set
            {
                _WidgetDetails.afterFieldID = value;
            }
        }

        public string beforeFieldID
        {
            get
            {
                return _WidgetDetails.beforeFieldID;
            }
            set
            {
                _WidgetDetails.beforeFieldID = value;
            }
        }

        UIEventHandler IFGLField.onUIEvent
        {
            get
            {
                return _WidgetDetails.onUIEvent;
            }
            set
            {
                _WidgetDetails.onUIEvent = value;
            }
        }


        public string TableName
        {
            get { return _WidgetDetails.TableName; }
        }

        public int attributeNo
        {
            get { return _WidgetDetails.attributeNo; }
        }
        */
        #region IFGLField Members

/*
        public string onActionID
        {
            get
            {
                throw new NotImplementedException();
            }
            set
            {
                throw new NotImplementedException();
            }
        }
        */
        #endregion
    }


}

