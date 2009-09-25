using System;
using System.Collections.Generic;
using System.Collections;
using System.Windows.Forms;
using System.Text;
using System.IO;
using System.Xml.Serialization;
using System.Xml;

namespace AubitDesktop
{
     class FormattedCellSettings
    {
        internal string format;
        internal bool Required;
         internal List<string> includeValues;
         internal FGLUtils.FGLDataTypes datatype;
         internal int datatype_length;
         internal string defaultValue;
         internal bool upshift;
         internal bool downshift;
         internal string comments;


        
        internal FormattedCellSettings( )
        {
            format = null;
            Required = false;
            datatype = FGLUtils.FGLDataTypes.DTYPE_CHAR;
            includeValues = null;
            defaultValue = "";
            upshift = false;
            downshift = false;
            comments = "";
        }

    }

    public class FormattedGridView : DataGridView
    {
       // DataGridView internalDataGrid;

        Xml.XMLForm.Table table;
        FormattedCellSettings[] widgetSettings;


        private bool __FirstPaint = true;
        private int __RowsToDisplay;
        private EventHandler _onDblClick;

        



        public EventHandler onDblClick
        {
            get
            {
                return _onDblClick;
            }
            set
            {
                _onDblClick = value;
            }
        }


        private UIFieldValidationHandler _fieldValidationFailed;
        internal UIFieldValidationHandler fieldValidationFailed
        {
            set
            {
                _fieldValidationFailed = value;
            }
            get
            {
                return _fieldValidationFailed;
            }
        }
        internal DataGridViewCellEventHandler AfterRow = null;
        internal DataGridViewCellEventHandler BeforeRow = null;

        internal UIArrayTableHandler beforeFieldHandler = null;
        internal UIArrayTableHandler afterFieldHandler = null; 

        FGLContextType _context = FGLContextType.ContextNone;

        internal int getCellNumberForField(string s)
        {
            if (table == null) return -1;

            for (int a = 0; a < table.TableColumn.Length; a++)
            {
                if (table.TableColumn[a].name.ToLower() == s.ToLower()) return a;
                if (table.TableColumn[a].colName.ToLower() == s.ToLower()) return a;
                if (table.TableColumn[a].sqlTabName.ToLower() + "." + table.TableColumn[a].colName.ToLower() == s.ToLower()) return a;
            }
            return -1;
        }

        internal FGLContextType context
        {
            get
            {
                return _context;
            }
            set
            {
                _context = value;
                setForContext();
            }
        }


        /// <summary>
        /// Copy the data from our 'Data' array into the cells on the datagrid..
        /// </summary>
        internal void syncData(int line, int nCols, string[,] Data)
        {

            //Data[,].Length;
            for (int a = 0; a < nCols; a++)
            {
                object o;

                o = this.Rows[line].Cells[a + 1];

                /*
                if (o.GetType() == typeof(DataGridViewCheckBoxCell))
                {
                    DataGridViewCheckBoxCell c;
                    c = (DataGridViewCheckBoxCell)o;
                    if ((string)c.TrueValue == Data[line, a])
                    {
                        c.Value = true;
                    }
                    else
                    {
                        c.Value = false;
                    }
                    continue;
                }
                */

                FGLUtils.setCellValue(this.Rows[line].Cells[a + 1], Data[line, a]);
                
            }
        }

        internal string getCellData(int row, int col)
        {
            if (Rows[row].Cells[col].ValueType==typeof(string)) {
                return ((string)Rows[row].Cells[col].Value).Trim();
            }
            if (Rows[row].Cells[col].Value==null) {
                return "";
            }
            return Rows[row].Cells[col].Value.ToString().Trim();
        }



        private void setForContext()
        {
            switch (_context)
            {
                case FGLContextType.ContextNone:
                case FGLContextType.ContextDisplayArray:
                case FGLContextType.ContextDisplayArrayInactive:
                    AllowUserToResizeColumns = true;
                    AllowUserToResizeRows = true;
                    ReadOnly = true;
                    SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
                    break;

                case FGLContextType.ContextInputArrayInactive:
                    AllowUserToResizeColumns = true;
                    AllowUserToResizeRows = true;
                    ReadOnly = true;
                    SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.CellSelect;
                    break;

                case FGLContextType.ContextInputArray:
                    AllowUserToResizeColumns = true;
                    AllowUserToResizeRows = true;
                    ReadOnly = false;
                    SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.CellSelect;
                    break;


            }
        }


        private void setUpHandlers()
        {
            RowEnter += new DataGridViewCellEventHandler(Grid_RowEnter);
            RowLeave += new DataGridViewCellEventHandler(Grid_RowLeave);
           // DoubleClick += new EventHandler(Grid_DoubleClick);
            CellValidating += new DataGridViewCellValidatingEventHandler(FormattedGridView_CellValidating);
            DefaultValuesNeeded += new DataGridViewRowEventHandler(FormattedGridView_DefaultValuesNeeded);
            CellEnter += new DataGridViewCellEventHandler(FormattedGridView_CellEnter);
            CellLeave += new DataGridViewCellEventHandler(FormattedGridView_CellLeave);
            CellFormatting += new DataGridViewCellFormattingEventHandler(FormattedGridView_CellFormatting);
            this.EditingControlShowing += new DataGridViewEditingControlShowingEventHandler(FormattedGridView_EditingControlShowing); 
            
        }

        void FormattedGridView_EditingControlShowing(object sender, DataGridViewEditingControlShowingEventArgs e)
        {

            if (e.Control is TextBox)
            {

                TextBox tb;
                tb = (TextBox)e.Control;
                tb.CharacterCasing = CharacterCasing.Normal;
                if (this.widgetSettings[CurrentCell.ColumnIndex - 1].upshift)
                {
                    tb.CharacterCasing = CharacterCasing.Upper;
                }
                if (this.widgetSettings[CurrentCell.ColumnIndex - 1].downshift)
                {
                    tb.CharacterCasing = CharacterCasing.Lower;
                }
                Console.WriteLine("EDITINGCONROLSHOWING - Textbox");
            }
            else
            {
                Console.WriteLine("EDITINGCONROLSHOWING - not Textbox");
            }
        }

        void FormattedGridView_CellFormatting(object sender, DataGridViewCellFormattingEventArgs e)
        {
            /*
            // Are we just setting up ? 
            if (e.ColumnIndex -1 > this.widgetSettings.Length) return;

            if (e.Value == null) return;


            if (this.widgetSettings[e.ColumnIndex-1].upshift) {
                e.Value=((string)e.Value).ToUpper();
                e.FormattingApplied=true;
            }

            if (this.widgetSettings[e.ColumnIndex - 1].downshift)
            {
                e.Value = ((string)e.Value).ToLower();
                e.FormattingApplied = true;
            }
            */
          //  Console.WriteLine("CELLFORMATTING");
        }


        void FormattedGridView_CellLeave(object sender, DataGridViewCellEventArgs e)
        {
            if (afterFieldHandler != null)
            {
                afterFieldHandler(e.RowIndex, e.ColumnIndex-1);
            }  
        }

        void FormattedGridView_CellEnter(object sender, DataGridViewCellEventArgs e)
        {
            if (this.beforeFieldHandler != null)
            {
                beforeFieldHandler(e.RowIndex, e.ColumnIndex-1);
            }
        }

        internal void FormattedGridView_DefaultValuesNeeded(object sender, DataGridViewRowEventArgs e)
        {
            e.Row.Cells[0].Value = ""+e.Row.Index;
            for (int a = 0; a < table.TableColumn.Length; a++)
            {
                if (table.TableColumn[a].defaultValue != null && table.TableColumn[a].defaultValue != "")
                {
                    FGLUtils.setCellValue(e.Row.Cells[a + 1], table.TableColumn[a].defaultValue);
                   //e.Row.Cells[a+1].Value=table.TableColumn[a].defaultValue;
                }
            }
        }





        private bool validateField(int row, int col,string Text)
        {
            bool ign = false;
            FormattedCellSettings w;
            //FGLWidget w = null;
           
            w = widgetSettings[col-1];
            if (w == null) return true;

           // Text = getCellData(row, col);


            if (this.context == FGLContextType.ContextInputArray)
            {
                #region REQUIRED CHECK
                if (w.Required)
                {
                    if (Text.Length == 0)
                    {
                        if (fieldValidationFailed != null)
                        {
                            fieldValidationFailed(w, "FIELD_REQD_MSG", out ign);
                        }
                        if (!ign)
                        {
                            return false;
                        }
                    }

                }
                #endregion
                #region Datatype Check
                if (!FGLUtils.IsValidForType(w.datatype, Text, w.format))
                {
                    if (fieldValidationFailed != null)
                    {
                        fieldValidationFailed(w, "FIELD_ERROR_MSG", out ign);
                    }
                    if (!ign)
                    {
                        return false;
                    }
                }
                #endregion
                #region Include value check
                if (w.includeValues != null)
                {
                    bool ok = false;
                    foreach (string s in w.includeValues)
                    {
                        if (s.Contains(":"))
                        {
                            string l, r;
                            string[] arr;
                            arr = s.Split(':');
                            l = arr[0];
                            r = arr[1];

                            if (FGLUtils.compare_range(Text, l, r, w.datatype, w.datatype_length, w.format))
                            {
                                ok = true;
                            }
                        }
                        else
                        {
                            if (s == "NULL" && Text == "")
                            {
                                ok = true;
                                break;
                            }
                            if (s ==Text)
                            {
                                ok = true;
                                break;
                            }
                        }
                    }

                    ign = false;
                    if (!ok)
                    {
                        fieldValidationFailed(w, "FIELD_INCL_MSG", out ign);


                        if (!ign)
                        {
                            return false;
                        }
                    }
                }
                #endregion
            }



            return true;
        }


        void FormattedGridView_CellValidating(object sender, DataGridViewCellValidatingEventArgs e)
        {
            string s;
            s = "";
            s = e.FormattedValue.ToString();
            if (!validateField(e.RowIndex, e.ColumnIndex,s))

           {
                
                e.Cancel = true;
            }
        }

        public FormattedGridView(Xml.XMLForm.Table t)
        {
            int len;
            len = t.TableColumn.Length;
            this.table = t;
            setUpHandlers();
            widgetSettings = new FormattedCellSettings[len];

            for (int a = 0; a < len; a++)
            {
                widgetSettings[a] = new FormattedCellSettings();
                widgetSettings[a].Required = (t.TableColumn[a].required != null && t.TableColumn[a].required == "1");
                widgetSettings[a].datatype = (FGLUtils.FGLDataTypes)FGLWidget.decode_datatype(t.TableColumn[a].sqlType);
                widgetSettings[a].datatype_length = FGLWidget.decode_datatype_size(t.TableColumn[a].sqlType);


                widgetSettings[a].format=null;
                


                if (t.TableColumn[a].include != null)
                {
                    if (t.TableColumn[a].include.Length > 0)
                    {

                        widgetSettings[a].includeValues = new List<string>();
                        string[] incvals;
                        incvals = t.TableColumn[a].include.Split('\n');
                        for (int b = 0; b < incvals.Length; b++)
                        {
                            if (incvals[b].Contains("|"))
                            {
                                widgetSettings[a].includeValues.AddRange(incvals[b
                                    ].Split('|'));
                            }
                            else
                            {
                                widgetSettings[a].includeValues.Add(incvals[
                                    b]);
                            }
                        }
                    }

                }
                //widgetSettings[a].includeValues=t.TableColumn[a].include;
                widgetSettings[a].defaultValue=t.TableColumn[a].defaultValue;
            }

        }



        #region EventForwarders
        void Grid_RowEnter(object sender, DataGridViewCellEventArgs e)
        {
            if (BeforeRow != null)
            {
                if (CurrentCell != null)
                {
                    Console.WriteLine("Row = " + e.RowIndex + " " + CurrentCell.RowIndex);
                }
                BeforeRow(sender, e);
            }
        }

        void Grid_RowLeave(object sender, DataGridViewCellEventArgs e)
        {
            if (AfterRow != null)
            {
                AfterRow(sender, e);
            }

        }

        void Grid_DoubleClick(object sender, EventArgs e)
        {
            if (this.onDblClick != null)
            {
                this.onDblClick(sender, e);
            }
        }
        #endregion


        public int RowsToDisplay
        {

            get { return __RowsToDisplay; }

            set { __RowsToDisplay = value; }

        }

        public void sizeGrid()
        {
            MaximumSize = new System.Drawing.Size(1024, GetMaxGridSize());
            Height = MaximumSize.Height;

        }

        /// <summary>

        /// Adds a confirmation box on deletes.

        /// </summary>

        private void GridView_UserDeletingRow(object sender, DataGridViewRowCancelEventArgs e)
        {

            if (!e.Row.IsNewRow)
            {

                DialogResult response =

                MessageBox.Show("Are you sure you want to delete this record?", "Delete Record?", MessageBoxButtons.YesNo, MessageBoxIcon.Question,

                MessageBoxDefaultButton.Button2);

                if (response == DialogResult.No)
                {

                    e.Cancel = true;

                }

            }

        }

        private int GetGridHeight()
        {
            return MaximumSize.Height;


            /*
            int x = 0;

            foreach (DataGridViewRow row in Rows)
            {

                x += row.Height;

            }

            x += ColumnHeadersHeight;

            x += 2;

            return x;
            */
        }

        private int GetMaxGridSize()
        {

            int singleRowHeight = Rows[0].Height;

            if (__RowsToDisplay == 0)
            {

                return 300;

            }

            else
            {
                if (ColumnHeadersVisible)
                {
                    return (singleRowHeight * (__RowsToDisplay)) + ColumnHeadersHeight + 2;
                }
                else
                {
                    return (singleRowHeight * (__RowsToDisplay)) + 2;
                }

            }

        }



        internal string getInfield()
        {
            if (this.CurrentCell == null) return "";
            return " INFIELD=\"" + table.TableColumn[this.CurrentCell.ColumnIndex - 1].colName + "\"";
        }

        internal string getFieldName(int columnIndex) {
            return table.TableColumn[columnIndex].colName;
        }


        /// <summary>
        /// Set the focus to the first field in the first line...
        /// </summary>
        internal void setFieldToStart()
        {
            CurrentCell = Rows[0].Cells[1];
        }

        internal void setField(int arrLine, string fieldName)
        {
            bool found = false;
            int cell = 0;
            
            if (fieldName.ToLower() == "next")
            {
                cell = CurrentCell.ColumnIndex + 1;
                if (cell > table.TableColumn.Length) cell = table.TableColumn.Length;
                found = true;
            }

            if (fieldName.ToLower().StartsWith("prev"))
            {
                cell = CurrentCell.ColumnIndex - 1;
                if (cell <= 0) cell = 1;
                found = true;
            }


            if (fieldName.ToLower().StartsWith("curr"))
            {
                cell = CurrentCell.ColumnIndex ;               
                found = true;
            }


            if (fieldName != null && !found) { cell=getCellNumberForField(fieldName); }
            CurrentCell = Rows[arrLine - 1].Cells[cell+1]; // Skip the first cell - its just the line number...
        }


        internal void setFormat(int columnIndex, string format)
        {
            this.widgetSettings[columnIndex].format = format;
        }


        internal void setComments(int columnIndex, string commentstring)
        {
            this.widgetSettings[columnIndex].comments = commentstring;
        }

        internal void setShift(int a, string p)
        {
            if (p.ToLower() == "down")
            {
                this.widgetSettings[a].downshift = true;
            }

            if (p.ToLower() == "up")
            {
                this.widgetSettings[a].upshift = true;
            }
        }



        internal string getComments(int columnId)
        {
            return widgetSettings[columnId].comments;
        }
    }

}
