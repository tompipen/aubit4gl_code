using System;
using System.Collections.Generic;
using System.Collections;
using System.Windows.Forms;
using System.Text;
using System.IO;
using System.Xml.Serialization;
using System.Xml;
using System.Data;

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





        internal FormattedCellSettings()
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
        internal Xml.XMLForm.Table table;
        FormattedCellSettings[] widgetSettings;
        private int __RowsToDisplay;
        private EventHandler _onDblClick;
        internal bool addedNewRowBelow=false;
        internal int enteredCellColumn = -1;
        internal int enteredCellRow = -1;
        internal int enteredRow = -1;
        internal int leftCellColumn = -1;
        internal int leftCellRow = -1;
        private int _maxRows;
        internal int maxRows
        {
            get
            {
                return _maxRows;
            }
            set
            {
                if (_maxRows != value)
                {
                    _maxRows = value;
                    setAllowUserToAddRows();
                }

            }
        }

        private bool _allowInsertRow;
        internal bool allowInsertRow
        {
            get
            {
                return _allowInsertRow;
            }
            set
            {
                _allowInsertRow = value;
                setAllowUserToAddRows();
            }
        }


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

        /*
        internal UIArrayTableHandler beforeInsert = null;
        internal UIArrayTableHandler beforeDelete = null;

        internal UIArrayTableHandler afterInsert = null;
        internal UIArrayTableHandler afterDelete = null;
        */

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
    
            RowValidated += new DataGridViewCellEventHandler(Grid_RowLeave);
            CellValidating += new DataGridViewCellValidatingEventHandler(FormattedGridView_CellValidating);
            RowValidating += new DataGridViewCellCancelEventHandler(FormattedGridView_RowValidating);
            DefaultValuesNeeded += new DataGridViewRowEventHandler(FormattedGridView_DefaultValuesNeeded);

      

            CellEnter += new DataGridViewCellEventHandler(FormattedGridView_CellEnter);
            CellLeave += new DataGridViewCellEventHandler(FormattedGridView_CellLeave);
            CellFormatting += new DataGridViewCellFormattingEventHandler(FormattedGridView_CellFormatting);
            EditingControlShowing += new DataGridViewEditingControlShowingEventHandler(FormattedGridView_EditingControlShowing);
            //this.Rows.CollectionChanged += new System.ComponentModel.CollectionChangeEventHandler(Rows_CollectionChanged);
            //RowsAdded += new DataGridViewRowsAddedEventHandler(FormattedGridView_RowsAdded);
        }



        

        /// <summary>
        /// Set the AllowUserToAddRows depending on the current number of rows, the current context
        /// and whether the program has 'NONEWLINES' etc
        /// </summary>
        private void setAllowUserToAddRows()
        {

            if (context != FGLContextType.ContextInputArray && context != FGLContextType.ContextInputArrayInactive)
            {
                if (AllowUserToAddRows != false) // Only set this if we need to..
                {
                    AllowUserToAddRows = false;
                }
                return;
            }

            // Is it disallowed in the program ? 
            if (allowInsertRow == false)
            {
                if (AllowUserToAddRows != false) // Only set this if we need to..
                {
                    AllowUserToAddRows = false;
                }
                return;
            }

            // Have we run out of space ? 
            if (Rows.Count > maxRows)
            {
                if (AllowUserToAddRows != false) // Only set this if we need to..
                {
                    AllowUserToAddRows = false;
                    return;
                }
            }

            if (AllowUserToAddRows != true) // Only set this if we need to..
            {
                AllowUserToAddRows = true;
            }
        }
    


        void FormattedGridView_RowValidating(object sender, DataGridViewCellCancelEventArgs e)
        {

            string s;
            s = "";

            try
            {
                s = (string)Rows[e.RowIndex].Cells[e.ColumnIndex].Value;
            }
            catch
            {
                s = "";
            }



                if (!validateField(e.RowIndex, e.ColumnIndex,s))
                {
                    e.Cancel = true;
                } 
            
        }

        void FormattedGridView_EditingControlShowing(object sender, DataGridViewEditingControlShowingEventArgs e)
        {
            if (CurrentCell.ColumnIndex == 0) return;

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
            if (e.ColumnIndex == 0) return;

            // Are we just setting up ? 
            if (e.ColumnIndex -1 > this.widgetSettings.Length) return;

            if (e.Value == null) return;


            if (this.widgetSettings[e.ColumnIndex - 1].format != null && this.widgetSettings[e.ColumnIndex - 1].format.Trim() != "")
            {
                string val;
                try
                {
                    val = (string)e.Value;
                }
                catch
                {
                    val = "";
                }
                e.Value = FGLUsing.A4GL_func_using(widgetSettings[e.ColumnIndex - 1].format, val, widgetSettings[e.ColumnIndex - 1].datatype);
                e.FormattingApplied = true;
            }         
            
                
        }


        void FormattedGridView_CellLeave(object sender, DataGridViewCellEventArgs e)
        {
            string val;
       //     DataGridViewCellValidatingEventArgs e_val;


            if (e.ColumnIndex == 0) return;

            try
            {
                val = (string)this.Rows[e.RowIndex].Cells[e.ColumnIndex].Value;
            }
            catch
            {
                val = null;
            }
            
            if (afterFieldHandler != null)
            {
                if (leftCellColumn != e.ColumnIndex || leftCellRow != e.RowIndex)
                {
                    leftCellColumn = e.ColumnIndex;
                    leftCellRow = e.RowIndex;
                    afterFieldHandler(e.RowIndex, e.ColumnIndex - 1);

                }
            }

            



        }

        void FormattedGridView_CellEnter(object sender, DataGridViewCellEventArgs e)
        {
            if (e.ColumnIndex == 0) return;


            if (this.beforeFieldHandler != null)
            {
                Console.WriteLine("Enter cell : " + e.RowIndex + " " + e.ColumnIndex);
                if (enteredCellColumn != e.ColumnIndex || enteredCellRow != e.RowIndex)
                {
                    Console.WriteLine("not the same as old cell :  " + enteredCellRow + " " + enteredCellColumn);
                    enteredCellRow = e.RowIndex;
                    enteredCellColumn = e.ColumnIndex;
                    
                    beforeFieldHandler(e.RowIndex, e.ColumnIndex - 1);

                }
            }
            


        }

        internal void FormattedGridView_DefaultValuesNeeded(object sender, DataGridViewRowEventArgs e)
        {
            e.Row.Cells[0].Value = "XXX";
            for (int a = 0; a < table.TableColumn.Length; a++)
            {
                if (table.TableColumn[a].defaultValue != null && table.TableColumn[a].defaultValue != "")
                {
                    FGLUtils.setCellValue(e.Row.Cells[a + 1], table.TableColumn[a].defaultValue);
                    //e.Row.Cells[a+1].Value=table.TableColumn[a].defaultValue;
                }
                else
                {
                    FGLUtils.setCellValue(e.Row.Cells[a + 1], "");
                }
            }
            EndEdit();
        }





        private bool validateField(int row, int col,string Text)
        {
            bool ign = false;
            FormattedCellSettings w;
            //FGLWidget w = null;
            if (col == 0) return true;

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
                
                widgetSettings[a].defaultValue=t.TableColumn[a].defaultValue;
            }
            this.MultiSelect = false;
            EditMode = DataGridViewEditMode.EditOnEnter;
            AutoGenerateColumns = false;
            setUpHandlers();
            
        }



        #region EventForwarders
        void Grid_RowEnter(object sender, DataGridViewCellEventArgs e)
        {

            setAllowUserToAddRows();
           
            if (BeforeRow != null && enteredRow!=e.RowIndex)
            {
                enteredRow = e.RowIndex;
                BeforeRow(sender, e);
            }


        }

        void Grid_RowLeave(object sender, DataGridViewCellEventArgs e)
        {
            setAllowUserToAddRows();
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
            if (this.CurrentCell.ColumnIndex == 0) { 
                // This field is normally hidden - it contains the subscript
                // but its sometimes 'visible' whilst debugging...
                return ""; }

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

        internal void init()
        {
            enteredCellColumn = -1;
            enteredCellRow = -1;
            leftCellColumn = -1;
            leftCellRow = -1;
            onDblClick = null;
            AfterRow = null;
            BeforeRow = null;
            beforeFieldHandler = null;
            afterFieldHandler = null;
            CurrentCell = null;
        }
    }






    
}
