using System;
using System.Collections.Generic;
using System.Collections;
using System.Windows.Forms;
using System.Text;
using System.IO;
using System.Xml.Serialization;
using System.Xml;
using System.Data;
using System.ComponentModel;

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
        internal bool isPassword;
        internal bool readOnly;


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
            isPassword = false;
            readOnly = false;
        }

    }


    public class FormattedGridView : DataGridView
    {
        internal Xml.XMLForm.Table table;
        FormattedCellSettings[] widgetSettings;
        private int __RowsToDisplay;
        private EventHandler _onDblClick;
        internal bool addedNewRowBelow = false;
        internal DataTable defaultData;
        //internal int enteredCellColumn = -1;
        //internal int enteredCellRow = -1;
        //internal int enteredRow = -1;
        //internal int leftCellColumn = -1;
        //internal int leftCellRow = -1;
        internal bool rowChanged = false;
        //internal bool ignEvents = false;
        private int _maxRows;
        internal int movingCellsInternally=0;

        private int currentRowId = -1;
        private int currentColId = -1;
        private bool rowIsNew = false;

        internal int rowId
        {
            set
            {
                currentRowId=value;
            }
            get
            {
                return currentRowId;
            }
        }

        internal int colId
        {
            get
            {
                return currentColId;
            }
            set
            {
                currentColId=value;
            }
        }

     

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




        //    private bool doIgnore;
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
        internal UIArrayTableRowHandler AfterRow = null;
        internal UIArrayTableRowHandler BeforeRow = null;

        internal UIArrayTableHandler beforeFieldHandler = null;
        internal UIArrayTableHandler afterFieldHandler = null;

        FGLContextType _context = FGLContextType.ContextNone;

        internal int getCellNumberForField(string fieldName)
        {
            if (table == null) return -1;

            int dim;
            if (fieldName.Contains("["))
            {
                int idx;
                idx = fieldName.IndexOf("[");
                string sDim = fieldName.Substring(idx + 1);
                string srest;
                srest = sDim.Substring(sDim.IndexOf("]") + 1);
                sDim = sDim.Substring(0, sDim.IndexOf("]"));
                //Replace("]", "");

                dim = Convert.ToInt32(sDim);
                fieldName = fieldName.Substring(0, idx) + srest;

            }

            for (int a = 0; a < table.TableColumn.Length; a++)
            {


                if (table.TableColumn[a].name.ToLower() == fieldName.ToLower()) return a;
                if (table.TableColumn[a].colName.ToLower() == fieldName.ToLower()) return a;
                if (table.tabName.ToLower() + "." + table.TableColumn[a].colName.ToLower() == fieldName.ToLower()) return a;
                if (table.TableColumn[a].sqlTabName.ToLower() + "." + table.TableColumn[a].colName.ToLower() == fieldName.ToLower()) return a;
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
                FGLUtils.setCellValue(this.Rows[line].Cells[a + 1], Data[line, a], 0);

            }
        }

        internal string getCellData(int row, int col)
        {
            if (Rows[row].Cells[col].ValueType == typeof(string))
            {
                return ((string)Rows[row].Cells[col].Value).Trim();
            }
            if (Rows[row].Cells[col].Value == null)
            {
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
            DefaultValuesNeeded += new DataGridViewRowEventHandler(FormattedGridView_DefaultValuesNeeded);
            CellValidating +=new DataGridViewCellValidatingEventHandler(FormattedGridView_CellValidating);
            this.RowEnter += new DataGridViewCellEventHandler(FormattedGridView_RowEnter);
            this.CausesValidation = true;
            CellEnter += new DataGridViewCellEventHandler(FormattedGridView_CellEnter);
            CellFormatting += new DataGridViewCellFormattingEventHandler(FormattedGridView_CellFormatting);
            EditingControlShowing += new DataGridViewEditingControlShowingEventHandler(FormattedGridView_EditingControlShowing);
            this.RowsRemoved += new DataGridViewRowsRemovedEventHandler(FormattedGridView_RowsRemoved);
            CellBeginEdit += new DataGridViewCellCancelEventHandler(FormattedGridView_CellBeginEdit);
            
        }

        void FormattedGridView_CellBeginEdit(object sender, DataGridViewCellCancelEventArgs e)
        {
            
            if (Rows[e.RowIndex].Cells[e.ColumnIndex].ReadOnly) {
                e.Cancel = true;
            }
                if (e.ColumnIndex>0) {
            if (widgetSettings[e.ColumnIndex - 1].readOnly)
            {
                e.Cancel = true;
            }
                }
        }

        void FormattedGridView_RowEnter(object sender, DataGridViewCellEventArgs e)
        {
            if (this.CurrentRow != null)
            {
                if (this.CurrentRow.IsNewRow)
                {
                    rowIsNew = true;
                    cellMoved(-1, -1); // we want to trigger any before row/before fields as its a new row..
                }
                else
                {
                    rowIsNew = false;
                }
            }
            else
            {
                rowIsNew = false;
            }
        }

     
        

        internal void processPgDn()
        {
            base.ProcessNextKey(Keys.PageDown);
        }

        internal void processPgUp()
        {
            base.ProcessPriorKey(Keys.PageUp);
        }
       
        internal void processDown()
        {
            base.ProcessDownKey(Keys.Down);
        }

        internal void processUp()
        {
            base.ProcessUpKey(Keys.Up);
        }




        void FormattedGridView_RowsRemoved(object sender, DataGridViewRowsRemovedEventArgs e)
        {
            cellMoved(-1, -1); // We want to trigger any before field/before rows...
            //setAllowUserToAddRows();
        }







        /// <summary>
        /// Set the AllowUserToAddRows depending on the current number of rows, the current context
        /// and whether the program has 'NONEWLINES' etc
        /// </summary>
        private void setAllowUserToAddRows()
        {
            


            if (context != FGLContextType.ContextInputArray && context != FGLContextType.ContextDisplayArray)
            {
                this.Enabled = false;
            }
            else
            {
                this.Enabled = true;
            }

            if (context != FGLContextType.ContextInputArray && context != FGLContextType.ContextInputArrayInactive)
            {

                if (AllowUserToAddRows != false) // Only set this if we need to..
                {
                    this.CancelEdit();
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

            if (CurrentRow!=null)
            {
                if (CurrentRow.IsNewRow)
                {
                    // We are the new row !
                    return;
                }
            }

            // Have we run out of space ? 
            if (Rows.Count >= maxRows)
            {
                if (AllowUserToAddRows != false) // Only set this if we need to..
                {
                    AllowUserToAddRows = false;

                }
                return;
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

                DataGridViewCell c = Rows[e.RowIndex].Cells[e.ColumnIndex];
                if (c is DataGridViewCheckBoxCell)
                {
                    DataGridViewCheckBoxCell ch;
                    ch = (DataGridViewCheckBoxCell)c;
                    if (ch.EditedFormattedValue == null)
                    {
                        s = "";
                    }
                    else
                    {
                        if (ch.EditedFormattedValue is Boolean)
                        {

                            if ((Boolean)ch.EditedFormattedValue)
                            {
                                s = (string)ch.TrueValue;
                            }
                            else
                            {
                                s = (string)ch.FalseValue;
                            }
                        }
                        else
                        {
                            s = (string)ch.EditedFormattedValue;
                        }
                    }
                }
                else
                {
                    //s = (string)Rows[e.RowIndex].Cells[e.ColumnIndex].Value;
                    if (Rows[e.RowIndex].Cells[e.ColumnIndex].Value is DBNull)
                    {
                        s = "";
                    }
                    else
                    {
                        s = (string)Rows[e.RowIndex].Cells[e.ColumnIndex].Value;
                    }
                }
            }
            catch
            {
                s = "";
            }



            if (!validateField(e.RowIndex, e.ColumnIndex, s))
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

                if (this.widgetSettings[CurrentCell.ColumnIndex - 1].isPassword)
                {
                    tb.PasswordChar = '*';
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
            if (e.ColumnIndex - 1 > this.widgetSettings.Length) return;

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

        void ForceBackToCurrentCell()
        {
            this.CurrentCell = Rows[currentRowId].Cells[currentColId];
        }


        void cellMoved(int rowId, int colId)
        {
            if (rowId == currentRowId && colId == currentColId)
            {
                return;
            }

            if (movingCellsInternally>0 && false)
            {
                currentRowId = rowId;
                currentColId = colId;
                return;
            }


            // Do we have an old field to validate ? 
            if (currentColId != -1 && currentRowId != -1)
            {
        

                // So - we're moving...
                if (afterFieldHandler != null)
                {
                    afterFieldHandler(currentRowId, currentColId - 1);
                }
            }

            // Are we changing Rows too ? 
            if (rowId != currentRowId)
            {
                if (currentRowId != -1)
                {
                    if (AfterRow != null)
                    {
                        AfterRow(currentRowId);
                    }
                }

                if (BeforeRow != null && rowId!=-1)
                {
                    BeforeRow(rowId);
                }
                currentRowId = rowId;
            }



            if (colId != -1)
            {
                if (this.beforeFieldHandler != null)
                {
                    beforeFieldHandler(rowId, colId - 1);
                }
            }
            currentColId = colId;
        }

        /*
        protected override void  OnCellEnter(DataGridViewCellEventArgs e)
        {
            cellMoved(e.RowIndex, e.ColumnIndex);
            //base.OnCellEnter(e);
        }
         * */


        void FormattedGridView_CellEnter(object sender, DataGridViewCellEventArgs e)
        {
           // setAllowUserToAddRows();
            cellMoved(e.RowIndex, e.ColumnIndex);
        }


        


        internal void FormattedGridView_DefaultValuesNeeded(object sender, DataGridViewRowEventArgs e)
        {
            e.Row.Cells[0].Value = "XXX"; // First column was to hold the subscript - but its currently not used....


            for (int a = 0; a < table.TableColumn.Length; a++)
            {
                if (table.TableColumn[a].defaultValue != null && table.TableColumn[a].defaultValue != "")
                {
                    FGLUtils.setCellValue(e.Row.Cells[a + 1], table.TableColumn[a].defaultValue, 0);
                    //e.Row.Cells[a+1].Value=table.TableColumn[a].defaultValue;
                }
                else
                {
                    FGLUtils.setCellValue(e.Row.Cells[a + 1], "", 0);
                }
            }
            EndEdit();
        }





        private bool validateField(int row, int col, string Text)
        {
            bool ign = false;
            FormattedCellSettings w;
            //FGLWidget w = null;
            if (col == 0) return true;
            if (movingCellsInternally>0) return true;


            w = widgetSettings[col - 1];
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
                if (!FGLUtils.IsValidForType(w.datatype, Text, w.format,w.datatype_length))
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
                            if (s == Text)
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
            DataGridViewCell c;
            c = this.Rows[e.RowIndex].Cells[e.ColumnIndex];

            s = GetStringToValidate(c);
        
            if (!validateField(e.RowIndex, e.ColumnIndex, s))
            {
                e.Cancel = true;
            }
        }

        private string GetStringToValidate(DataGridViewCell c)
        {
            string s;
            if (c.EditedFormattedValue is DBNull)
            {
                s = "";
            }
            else
            {
                if (c.FormattedValueType == typeof(Boolean))
                {
                    DataGridViewCheckBoxCell ch;
                    ch = (DataGridViewCheckBoxCell)c;
                    if (ch.EditedFormattedValue == null)
                    {
                        s = null;
                    }
                    else
                    {
                        if (c.EditedFormattedValue is string)
                        {
                            s = (string)c.EditedFormattedValue;
                        }
                        else
                        {
                            if ((Boolean)c.EditedFormattedValue)
                            {

                                s = (string)ch.TrueValue;
                            }
                            else
                            {
                                s = (string)ch.FalseValue;
                            }
                        }
                    }
                }
                else
                {
                    s = (string)c.EditedFormattedValue;
                }
            }
            return s;
        }


        public void copyFromDataset() {
            string value;
            DataTable dt;
            int rcnt = 0;
            

            if (DataSource == defaultData) return;

            if (!(DataSource is DataTable))    return;

            dt= (DataTable)DataSource;

            clearDefaultData();

            defaultData.BeginLoadData();
            
            for (int  row = 0; row < Convert.ToInt32(table.pageSize); row++)
            {
                System.Data.DataRow r;
                r = null;
                try
                {
                    r = dt.Rows[row];
                }
                catch (Exception Ex)
                {
                    //MessageBox.Show(Ex.Message);
                }
                if (r == null) continue;
                if (r.RowState == DataRowState.Deleted) continue;
                
                
                for (int col = 0; col <= table.TableColumn.Length; col++)
                {
                    value = "";


                    if (row >= dt.Rows.Count)
                    {
                        value = "";
                    }
                    else
                    {
                        
                        try
                        {
                            


                            if (r[col] is DBNull)
                            {
                                value = "";
                            }
                            else
                            {
                                value = (string)r[col];

                            }
                        }
                        catch (Exception Ex)
                        {
                            MessageBox.Show("Borked @ " + Ex.Message);
                        }
                    }
                    
                    defaultData.Rows[rcnt][col]=value;
                }
                rcnt++;
            }

            DataSource = null;
            defaultData.EndLoadData();
            DataSource = defaultData;
        }

        public FormattedGridView(Xml.XMLForm.Table t)
        {
            int len;
            if (t.TableColumn == null)
            {
                MessageBox.Show("Internal error : " + t.tabName + " is not in the XML form");
                Application.Exit();
                return;
            }
            len = t.TableColumn.Length;
            
            this.table = t;
            //            this.ReadOnly = true;
            //          this.Enabled = false;
            widgetSettings = new FormattedCellSettings[len];
            defaultData = new DataTable();
            defaultData.Columns.Add("subscript");
            for (int cols = 1; cols <= len; cols++)
            {
                defaultData.Columns.Add("col"+(cols));
            }
            

            for (int rows = 0; rows < Convert.ToInt32(t.pageSize); rows++)
            {
                defaultData.Rows.Add();
                for (int cols = 0; cols <= len; cols++)
                {
                    defaultData.Rows[rows][cols] = "";
                }
            }

            //DataSource = defaultData;
            

            for (int a = 0; a < len; a++)
            {
                widgetSettings[a] = new FormattedCellSettings();
                widgetSettings[a].Required = (t.TableColumn[a].required != null && t.TableColumn[a].required == "1");
                widgetSettings[a].datatype = (FGLUtils.FGLDataTypes)FGLWidget.decode_datatype(t.TableColumn[a].sqlType);
                widgetSettings[a].datatype_length = FGLWidget.decode_datatype_size(t.TableColumn[a].sqlType);
                widgetSettings[a].format = null;

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

                widgetSettings[a].defaultValue = t.TableColumn[a].defaultValue;
            }
            this.MultiSelect = false;
            EditMode = DataGridViewEditMode.EditOnEnter;
            AutoGenerateColumns = false;
            setUpHandlers();
            //setAllowUserToAddRows();
            this.Enabled = false;
            //DataSource = defaultData;
        }






        

        
        void Grid_DoubleClick(object sender, EventArgs e)
        {
            if (this.onDblClick != null)
            {
                this.onDblClick(sender, e);
            }
        }
        

        public int RowsToDisplay
        {

            get { return __RowsToDisplay; }

            set { __RowsToDisplay = value; }

        }

        public void sizeGrid()
        {
            MaximumSize = new System.Drawing.Size(1024, GetMaxGridSize());
            Height = MaximumSize.Height;
            if (DataSource == null)
            {
                DataSource = defaultData;
            }

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
            if (this.CurrentCell.ColumnIndex == 0)
            {
                // This field is normally hidden - it contains the subscript
                // but its sometimes 'visible' whilst debugging...
                return "";
            }

            return " INFIELD=\"" + table.TableColumn[this.CurrentCell.ColumnIndex - 1].colName + "\"";
        }

        internal string getFieldName(int columnIndex)
        {
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


        internal void setReadonly(int a,bool isReadOnly)
        {
            this.widgetSettings[a].readOnly = isReadOnly;
        }


        internal void setIsPassword(int a, bool isPassword)
        {
            this.widgetSettings[a].isPassword = isPassword;
        }


        internal string getComments(int columnId)
        {
            return widgetSettings[columnId].comments;
        }

        internal void init()
        {
            onDblClick = null;
            AfterRow = null;
            BeforeRow = null;
            beforeFieldHandler = null;
            afterFieldHandler = null;
            CurrentCell = null;
            movingCellsInternally = 0;
            currentRowId = -1;
            currentColId = -1;
            SelectionMode = DataGridViewSelectionMode.FullRowSelect;
        }


        internal bool okToMove()
        {
            if (CurrentCell!=null) {
                return validateField(CurrentCell.RowIndex, CurrentCell.ColumnIndex,GetStringToValidate(CurrentCell));
            }
            return true;
        }

        internal void setActiveFocus()
        {
            bool incMovingCellsInternally = false;
            if (currentColId == -1 && currentRowId == -1)
            {
               // first move - need to trigger the before fields/rows... 
            }
            else
            {
                incMovingCellsInternally = true;
                this.movingCellsInternally++;
            }

            if (CurrentCell == null)
            {
                if (currentColId >= 0 && currentRowId >= 0)
                {
                    this.CurrentCell = Rows[currentRowId].Cells[currentColId];
                }
            }
            else
            {

                if (this.CurrentCell.ColumnIndex != currentColId || this.CurrentCell.RowIndex != currentRowId)
                {
                    if (currentRowId == -1 && currentColId == -1)
                    {
                    }
                    else
                    {
                        this.CurrentCell = Rows[currentRowId].Cells[currentColId];
                    }
                }
            }

            if (incMovingCellsInternally)
            {
                movingCellsInternally --;
            }
            /*
            this.Parent.Focus();
            if (!this.Focused)
            {
                this.Focus();
            }
            this.Select();
             * */

            if (CurrentCell == null)
            {
                try
                {
                    CurrentCell = Rows[0].Cells[1];
                }
                catch (Exception)
                {
                    Console.WriteLine("Couldn't set currentcell");
                }
            }

            if (CurrentCell != null)
            {
                this.CurrentCell.Selected = true;
            }

        }








        internal void clearDefaultData()
        {
            for (int rows = 0; rows < Convert.ToInt32(table.pageSize); rows++)
            {

                for (int cols = 0; cols <= table.TableColumn.Length; cols++)
                {
                    defaultData.Rows[rows][cols] = "";
                }
            }
        }
    }

}
