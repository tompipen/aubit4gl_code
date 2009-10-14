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
using System.Data;
using System.Collections.Generic;
using System.Text;
using System.Windows.Forms;



namespace AubitDesktop
{




    class UIInputArrayInTableContext : UIContext
    {
        private bool _contextIsActive;
        private FGLApplicationPanel mainWin;
        FormattedGridView inputArrayGrid;
        private bool currLineIsInserted;
      //  private bool []rowWasAutoInserted;
        private bool firstTime = true;
        private int maxRows;
        private string[] lastRowData;

        class s_pending {
            public s_pending(string ID, int scrLine,int arrLine)
            {
                //this.triggeredText = text;
                this.scrLine = scrLine;
                this.ID = ID;
                this.arrLine = arrLine;
            }

            //public string triggeredText;
            public int scrLine;
            public int arrLine;
            public string ID;
        };
        List<s_pending> PendingEvents;


        private string lastKey="";
        private bool allowInsert=true;
        private bool allowDelete=true;
        private int rowLeft = -1;
        

        /// <summary>
        /// Number of variables across the screen array..
        /// </summary>
        private int nCols;

        //private bool[] rowDataChanged;
        private DataTable Data;

        private enum MoveType {
            MoveTypeNoPendingMovement,
            MoveTypeInsert,
            MoveTypeDelete
        };

        private MoveType nextMove =  MoveType.MoveTypeNoPendingMovement;

        private int _arrLine=1;

        internal int arrLine
        {
            get
            {
                return _arrLine;
            }
            set
            {
                _arrLine = value;
            }
        }
       



        /// <summary>
        /// Number of lines in the screen record
        /// </summary>


        
        




        #region event handlers
        private List<ONKEY_EVENT> KeyList;
        private event UIEventHandler EventTriggered;

        private BEFORE_ROW_EVENT beforeRow;
        private AFTER_ROW_EVENT afterRow;
        private List<ON_ACTION_EVENT> onActionList;

        private BEFORE_DELETE_EVENT beforeDelete;
        private BEFORE_INSERT_EVENT beforeInsert;

        private AFTER_DELETE_EVENT afterDelete;
        private AFTER_INSERT_EVENT afterInsert;
        private int[] beforeFieldEventIds;
        private int[] afterFieldEventIds;
#endregion




      
        public bool contextIsActive()
        {
            return _contextIsActive;
        }


        public bool useKeyPress(KeyEventArgs ke)
        {
            return false;
        }


        public void toolBarAcceptClicked()
        {
            //setLines();

            lastKey = "ACCEPT";
            sendTrigger("ACCEPT", -1);
        }

        public bool externallyTriggeredID(string ID)
        {
            sendTrigger(ID, -1);
            return false;
        }


        /// <summary>
        /// Copy the data from the 'rows' passed in with the WAITFOREVENT
        /// into a copy of the program array
        /// 
        /// We maintain a copy on this side for easier processing...
        /// </summary>
        /// <param name="rows"></param>
        public void setUpData(ROW[] rows)
        {
            DataGridViewCell c;
            c = inputArrayGrid.CurrentCell;


            Data.BeginLoadData();


            for (int row = 0; row < rows.Length; row++)
            {
                int subscript = Convert.ToInt32(rows[row].SUBSCRIPT) - 1;
                while (subscript >= Data.Rows.Count)
                {
                    string[] newData;
                    newData = new string[nCols + 1];
                    for (int cnt = 0; cnt <= nCols; cnt++)
                    {
                        newData[cnt] = null;
                    }
                    Data.Rows.Add(newData);

                }
            }


            for (int row = 0; row < rows.Length; row++)
            {
                int subscript = Convert.ToInt32(rows[row].SUBSCRIPT) - 1;

                // We'll use the first column to store the index
                // for the current row...


                Data.Rows[subscript][0] = "XXX"; // First column was to hold the subscript - but its currently not used....
                for (int col = 0; col < rows[row].VALUES.Length; col++)
                {
                    Data.Rows[subscript][col + 1] = (string)rows[row].VALUES[col].Text;

                }
                // as we've been passed these values in - 
                // it makes sense not to send them back straight away again
                // so we call 'AcceptChanges' to mark the rows as 'unchanged' after we've just
                // changed them ;-)
                Data.Rows[subscript].AcceptChanges();
            }


            inputArrayGrid.CurrentCell = c;
            Data.EndLoadData();
        }


       

       
        public UIInputArrayInTableContext(FGLApplicationPanel f, INPUTARRAY p)
        {

           
            KeyList = new List<ONKEY_EVENT>();
            mainWin = f;
            nCols = p.ARRVARIABLES;
            maxRows = p.MAXARRSIZE;
           

            Data = new DataTable();  //new string[p.MAXARRSIZE, p.ARRVARIABLES];
            
            for (int a = 0; a <= nCols; a++) // One extra for the subscript....
            {
                if (a == 0)
                {
                    Data.Columns.Add("subscript");
                }
                else
                {
                    Data.Columns.Add("col"+a);
                }
            }

            

          //  rowWasAutoInserted = new bool[maxRows];
       //     rowDataChanged = new bool[maxRows];

          //  inputArrayGrid.maxRows = maxRows;


            PendingEvents = new List<s_pending>();

            lastRowData = new string[maxRows];
            for (int a = 0; a < maxRows; a++)
            {
                lastRowData[a] = "";
            }

            

            // Set up the 'blank' event IDs for before
            // and after fields for the Cell number
            // this will make it easier to check if we need to action
            // a before or after field event
            beforeFieldEventIds = new int[nCols];
            afterFieldEventIds = new int[nCols];
            for (int a = 0; a < nCols; a++)
            {
                beforeFieldEventIds[a] = -1;
                afterFieldEventIds[a] = -1;
            }


            onActionList = new List<ON_ACTION_EVENT>();

            
            beforeRow = null;
            afterRow = null;

            inputArrayGrid = f.FindRecord(p.FIELDLIST);

            if (inputArrayGrid == null)
            {
                MessageBox.Show("Screen record " + p.FIELDLIST + " not found - fix your 4gl!");
                Application.Exit();
            }


            // Make sure the array is completely cleared down..
            inputArrayGrid.Rows.Clear();
            inputArrayGrid.init();

            foreach (object evt in p.EVENTS)
            {
                if (evt is ONKEY_EVENT)
                {
                    ONKEY_EVENT e;
                    e = (ONKEY_EVENT)evt;
                    KeyList.Add(e);
                    continue;
                }

                if (evt is BEFORE_ROW_EVENT)
                {
                    BEFORE_ROW_EVENT e;
                    e = (BEFORE_ROW_EVENT)evt;
                    beforeRow = e;
                    continue;
                }

                if (evt is BEFORE_DELETE_EVENT)
                {
                    BEFORE_DELETE_EVENT e;
                    e = (BEFORE_DELETE_EVENT)evt;
                    beforeDelete = e;
                }

                if (evt is BEFORE_INSERT_EVENT)
                {
                    BEFORE_INSERT_EVENT e;
                    e = (BEFORE_INSERT_EVENT)evt;
                    beforeInsert = e;
                }


                if (evt is AFTER_DELETE_EVENT)
                {
                   AFTER_DELETE_EVENT e;
                    e = (AFTER_DELETE_EVENT)evt;
                    afterDelete = e;
                }

                if (evt is AFTER_INSERT_EVENT)
                {
                    AFTER_INSERT_EVENT e;
                    e = (AFTER_INSERT_EVENT)evt;
                    afterInsert = e;
                }

                if (evt is AFTER_ROW_EVENT)
                {
                    AFTER_ROW_EVENT e;
                    e = (AFTER_ROW_EVENT)evt;
                    afterRow = e;
                    continue;
                }

                if (evt is ON_ACTION_EVENT)
                {
                    ON_ACTION_EVENT e;
                    e = (ON_ACTION_EVENT)evt;
                    onActionList.Add(e);
                    continue;
                }

                if (evt is BEFORE_FIELD_EVENT)
                {
                    BEFORE_FIELD_EVENT e;
                    e = (BEFORE_FIELD_EVENT)evt;
                    int a = getCellNumberForField(e.FIELD);

                    if (a>=0) {
                        beforeFieldEventIds[a] = Convert.ToInt32(e.ID);
                    }
                    else
                    {
                        MessageBox.Show("BEFORE FIELD " + e.FIELD + " - field not found");
                    }
                    continue;

                }

                if (evt is AFTER_FIELD_EVENT)
                {
                    AFTER_FIELD_EVENT e;
                    e = (AFTER_FIELD_EVENT)evt;
                    int a = getCellNumberForField(e.FIELD);
                    if (a >= 0)
                    {
                        afterFieldEventIds[a] = Convert.ToInt32(e.ID);
                    }
                    else
                    {
                        MessageBox.Show("AFTER FIELD " + e.FIELD + " - field not found");
                    }
                    
                    continue;
                }

                Program.Show("Unhandled Event for INPUT ARRAY");
            }





            if (p.NONEWLINES==1 || p.ALLOWINSERT==0)      {
                allowInsert = false;
            }
            else
            {

                    allowInsert = true;
            }

            if (p.ALLOWDELETE == 1)
            {
                allowDelete = true;
            }
            else
            {
                allowDelete = false;
            }
        }


        /// <summary>
        /// Find the cell number for a fieldname
        /// </summary>
        /// <param name="fieldname">fieldname of the field to find</param>
        /// <returns></returns>
        private int getCellNumberForField(string fieldname)
        {
            return inputArrayGrid.getCellNumberForField(fieldname);
        }










        private void setFocusToCurrentRow()
        {
            Program.Show("Fixme");
        }


        /// <summary>
        /// Implements 'NEXT FIELD ...' functionality..
        /// </summary>
        /// <param name="fieldName"></param>
        public void setNextField(string fieldName)
        {
            setField(arrLine, fieldName);
        }

        public void NavigateToTab()
        {
            mainWin.setActiveToolBarKeys(KeyList, onActionList, true, true, true);
        }

        public void NavigateAwayTab()
        {
            
        }


        public void onActionTriggered(object source, string ID, string TriggeredText,UIContext u)
        {

            if (TriggeredText != "")
            {
                MessageBox.Show("Got triggered text in input array");
            }

            sendTrigger(ID, -1); 
            //this.EventTriggered(source, ID, TriggeredText,this);
        }



        public string getSyncValues()
        {
            string s;
            string subscript_string;
            int row;




            
            

            // Originally - I used the DataTable - but that just doesn't sync properly
            // I'm only using that at all because otherwise the autoinsert new row
            // doesn't seem to work..
            //
            // Basically - the DataGridView isn't being very helpful...
            //
            s = "\n<SYNCROWS>\n";

            for (row = 0; row <inputArrayGrid.Rows.Count; row++)
            {
                string rowData;
                subscript_string = "" + (row + 1);
                rowData = " <ROW SUBSCRIPT=\"" +subscript_string + "\">\n";
                rowData += "  <SYNCVALUES>\n";

                for (int col = 0; col < this.nCols; col++)
                {
                    string rval = "";
                    try
                    {
                        rval = (string)inputArrayGrid.Rows[row].Cells[col + 1].Value;   // Data.Rows[row][col + 1];
                    }
                    catch
                    {
                        rval = "";
                    }

                    rowData += "   <SYNCVALUE FIELDNAME=\"" + inputArrayGrid.getFieldName(col) + "\">" + System.Security.SecurityElement.Escape(rval) + "</SYNCVALUE>\n";
                }

                rowData += "  </SYNCVALUES>\n";
                rowData += " </ROW>\n";
                if (lastRowData[row] != rowData)
                { // Is it different to last time ? 
                    lastRowData[row] = rowData;
                    s += rowData;
                }
            }

            s += "</SYNCROWS>\n";

            
            
            return s;
        }









        public void ActivateContext(UIEventHandler UIInputArrayContext_EventTriggered, VALUE[] values, ROW[] rows)
        {

            if (nextMove == MoveType.MoveTypeInsert)
            {
                doInsertRow();
                nextMove = MoveType.MoveTypeNoPendingMovement;
            }

            if (nextMove == MoveType.MoveTypeDelete)
            {
                doDeleteRow();
                if (afterDelete!=null)
                {
                    sendTrigger(afterDelete.ID, -1);
                    return;
                }
            }

            stopHandlers();
            inputArrayGrid.ignEvents = true;
            foreach (ON_ACTION_EVENT e in onActionList)
            {
                foreach (FGLFoundField ffield in mainWin.FindAction(e.ACTION))
                {
                    ffield.fglField.onActionID = e.ID;
                    ffield.fglField.onUIEvent = onActionTriggered;
                    ffield.fglField.Enabled = true;
                    ffield.fglField.ContextType = FGLContextType.ContextInput;
                }
            }

            this.EventTriggered = UIInputArrayContext_EventTriggered;

            int crow = -1;
            int ccol = -1;

            // Do we have a current cell ? 
            // If this is the first time around - assume we dont...
            if (inputArrayGrid.CurrentCell != null && firstTime==false)
            {
                
                crow = inputArrayGrid.CurrentCell.RowIndex;
                ccol = inputArrayGrid.CurrentCell.ColumnIndex;
                Console.WriteLine("Crow=" + crow + " ccol=" + ccol);
            }            

            if (rows != null)
            {
                setUpData(rows);
            }
          //  inputArrayGrid.allowInsertRow = allowInsert;
          //  inputArrayGrid.maxRows = maxRows;
  
            if (inputArrayGrid.DataSource != Data)
            {
                if (inputArrayGrid.maxRows != maxRows)
                {
                    inputArrayGrid.maxRows = maxRows;
                }
                inputArrayGrid.DataSource = Data;
            }

            if (firstTime)
            {
                inputArrayGrid.CurrentCell = null;
            }

            startHandlers();
            inputArrayGrid.ignEvents = false;



            mainWin.setActiveToolBarKeys(KeyList,onActionList, true ,true,true);

            if (!_contextIsActive)
            {
                _contextIsActive = true;
            }

            if (crow != -1 && ccol != -1 && !firstTime)
            {
                if (inputArrayGrid.CurrentCell != null)
                {
                    if (crow != inputArrayGrid.CurrentCell.RowIndex || ccol != inputArrayGrid.CurrentCell.ColumnIndex)
                    {
                        Console.WriteLine("Moving to crow:" + crow + " ccol:" + ccol);
                        inputArrayGrid.ignEvents = false;
                        inputArrayGrid.CurrentCell = inputArrayGrid.Rows[crow].Cells[ccol];
                        inputArrayGrid.ignEvents = true;
                    }
                }
                else
                {
                    
                    Console.WriteLine("Moving from nowhere to crow:" + crow + " ccol:" + ccol);
                    inputArrayGrid.CurrentCell = inputArrayGrid.Rows[crow].Cells[ccol];
                }
            }

            inputArrayGrid.context = FGLContextType.ContextInputArray;

            if (PendingEvents.Count > 0)
            {
                s_pending p;
                p = PendingEvents[0];
                arrLine = p.scrLine;

                string s = getTriggeredTag(p.ID, p.arrLine, p.scrLine); // p.triggeredText;
                PendingEvents.RemoveAt(0);
                sendPendingTrigger(s);
                
                return;
            }




            inputArrayGrid.allowInsertRow = allowInsert;
            inputArrayGrid.maxRows = maxRows;
            if ((crow == -1 && crow == -1) || firstTime)
            {
                //if (inputArrayGrid.Rows.Count == 0)
               // {

             //   }
                setField(1, null);

                firstTime = false;
            }
          
            inputArrayGrid.Enabled = true;

            
            if (allowDelete)
            {
                inputArrayGrid.AllowUserToDeleteRows = true;
            }
            else
            {
                inputArrayGrid.AllowUserToDeleteRows = false;
            }

            if (inputArrayGrid.CurrentCell == null)
            {
                inputArrayGrid.setFieldToStart(); 
            }



        }


        internal void setField(int arrLine, string fieldName)
        {


            bool found = false;
            int cell = 0;
            string loweredFieldName;


            if (fieldName != null)
            {
                loweredFieldName = fieldName.ToLower();
            }
            else
            {
                // There isn't a field name - this is used if we just want to move to this
                // row. This is done when we start for example to move to the first
                // editable field....
                loweredFieldName = "";
            }

            if (loweredFieldName == "next")
            {
                cell = inputArrayGrid.CurrentCell.ColumnIndex + 1;
                if (cell > inputArrayGrid.table.TableColumn.Length) cell = inputArrayGrid.table.TableColumn.Length;
                found = true;
            }


            if (loweredFieldName.StartsWith("prev"))
            {
                cell = inputArrayGrid.CurrentCell.ColumnIndex - 1;
                if (cell <= 0) cell = 1;
                found = true;
            }


            if (loweredFieldName.StartsWith("curr"))
            {
                cell = inputArrayGrid.CurrentCell.ColumnIndex;
                found = true;
            }


            if (fieldName != null && !found)
            {
                cell = getCellNumberForField(fieldName);
                if (cell == -1)
                {
                    MessageBox.Show("Field not field "+fieldName);
                    return;
                }
            }

            while (inputArrayGrid.table.TableColumn[cell].noEntry != null && inputArrayGrid.table.TableColumn[cell].noEntry == "1")
            {
                int looped = 0;
                if (cell == inputArrayGrid.table.TableColumn.Length) // Are we at the end of the row ?
                {
                    cell = 0;
                    looped++;
                    if (looped == 2)
                    {
                        // There are just no fields which are not marked as 'noentry'...
                        MessageBox.Show("Error - Input array cannot settle on an editable field");
                        Application.Exit();
                    }

                    arrLine++;

                    if (arrLine >= inputArrayGrid.RowCount)
                    {
                        arrLine = inputArrayGrid.RowCount - 1;
                    }

                }
                cell++;
            }

            inputArrayGrid.CurrentCell = inputArrayGrid.Rows[arrLine - 1].Cells[cell + 1]; // Skip the first cell - its just the line number...
            PendingEvents.Clear();
        }





        void beforeFieldHandler(int rowid, int columnId)
        {
            mainWin.CommentText = inputArrayGrid.getComments(columnId);
            if (beforeFieldEventIds[columnId] != -1)
            {
                sendTrigger(""+beforeFieldEventIds[columnId], rowid);
            }
        }

        void afterFieldHandler(int rowid, int columnId)
        {
            if (afterFieldEventIds[columnId] != -1)
            {
                sendTrigger(""+afterFieldEventIds[columnId], rowid);
            }
        }


        void inputFieldValidationHandler(object source, string failedText, out bool ignore)
        {
            ignore = false;
            mainWin.setErrorTextFromFieldValidation(failedText);
        }

        private void sendPendingTrigger(string s)
        {
            if (this.EventTriggered != null)
            {
                this.EventTriggered(null, null, s, this);
                this.EventTriggered = null;
            }
            else
            {
                MessageBox.Show("Should have an eventtriggered variable set");
            }
        }

        private void sendTrigger(string ID,int rowIndex)
        {
            int arrLine;
            int scrLine;


            if (rowIndex>=0)
            {

                arrLine = rowIndex+1;
                scrLine = arrLine;
            }
            else
            {
                arrLine = inputArrayGrid.CurrentRow.Index+1;
                scrLine = arrLine;
            }


            if (arrLine == 0)
            {
                throw new ApplicationException("a row was found with no valid subscript");
            }

            if (this.EventTriggered != null)
            {
                UIEventHandler EventTriggeredSave;
                EventTriggeredSave=this.EventTriggered;
                this.EventTriggered = null;
                EventTriggeredSave(null, ID, getTriggeredTag(ID,arrLine,scrLine), this);
            }
            else
            {
                //PendingEvents.Add(new s_pending(getTriggeredTag(ID,arrLine,arrLine),arrLine));
                PendingEvents.Add(new s_pending(ID, arrLine, arrLine));
            }
        }


        private string getTriggeredTag(string ID,int arrLine, int scrLine)
        {
            string infieldStr = inputArrayGrid.getInfield();
            string rval="";
            try
            {
                string syncValues = getSyncValues();
                rval = "<TRIGGERED ID=\"" + ID + "\""+
                       " ARRLINE=\"" + arrLine + "\" SCRLINE=\"" + scrLine + "\" LASTKEY=\"" + this.lastKey + "\"" 
                       + infieldStr + " ARRCOUNT=\""+ inputArrayGrid.Rows.Count+"\">" + syncValues +
                    "</TRIGGERED>";
            } catch (Exception Ex) {
                MessageBox.Show("Error getting value for return:"+Ex.Message);
                Application.Exit();

            }

            return rval;
        }


        void RowLeave(object sender, DataGridViewCellEventArgs e)
        {
            if (inputArrayGrid.CurrentRow != null)
            {
                if (afterRow != null)
                {
                    if (afterRow.ID != "")
                    {
                        if (afterInsert!=null && currLineIsInserted)
                        {
                            sendTrigger(afterInsert.ID, e.RowIndex);
                        }
                        sendTrigger(afterRow.ID, e.RowIndex);
                    }
                }
            }

            currLineIsInserted = false;
            rowLeft = e.RowIndex;
        }

        void RowEnter(object sender, DataGridViewCellEventArgs e)
        {
            if (beforeRow != null)
            {
                if (beforeRow.ID != "")
                {
                    sendTrigger(beforeRow.ID, e.RowIndex);
                }
            }
        }



        public void DeactivateContext()
        {
            mainWin.setActiveToolBarKeys(null, null, false);
            mainWin.SetContext(FGLContextType.ContextInputArrayInactive);
            inputArrayGrid.context = FGLContextType.ContextInputArrayInactive;
            EventTriggered = null;
            //stopHandlers();
            _contextIsActive = false;

        }

        private void stopHandlers()
        {
            inputArrayGrid.fieldValidationFailed = null;            
            inputArrayGrid.BeforeRow = null;
            inputArrayGrid.AfterRow = null;
            inputArrayGrid.beforeFieldHandler=null;
            inputArrayGrid.afterFieldHandler = null;
        }

        private void startHandlers()
        {
            inputArrayGrid.fieldValidationFailed = inputFieldValidationHandler;


            if (beforeRow != null)
            {
                inputArrayGrid.BeforeRow = new DataGridViewCellEventHandler(RowEnter);
            }

            if (afterRow != null)
            {
                inputArrayGrid.AfterRow = new DataGridViewCellEventHandler(RowLeave);
            }
            inputArrayGrid.beforeFieldHandler = new UIArrayTableHandler(beforeFieldHandler);
            inputArrayGrid.afterFieldHandler = new UIArrayTableHandler(afterFieldHandler);

        }

        public void FreeContext()
        {
            _contextIsActive = false;
            inputArrayGrid.context = FGLContextType.ContextNone;
            stopHandlers();
        }



        internal void upkeyPressed()
        {
            lastKey = "UP";
            //if (inputArrayGrid.CurrentRow.Index > 0)
            //{
            //    inputArrayGrid.CurrentCell=inputArrayGrid.Rows[inputArrayGrid.CurrentRow.Index-1].Cells[1];
            //}
        }

        internal void downkeyPressed()
        {
            lastKey = "DOWN";
            if (inputArrayGrid.CurrentRow.Index<inputArrayGrid.Rows.Count-1)
            {
                inputArrayGrid.CurrentCell = inputArrayGrid.Rows[inputArrayGrid.CurrentRow.Index + 1].Cells[1];
            }
        }

        internal void pgDownkeyPressed()
        {
            int n;

            lastKey = "PGDN";

            n= inputArrayGrid.CurrentRow.Index+ inputArrayGrid.DisplayedRowCount(false);
            if (n < inputArrayGrid.Rows.Count-1)
            {
                inputArrayGrid.CurrentCell = inputArrayGrid.Rows[n].Cells[1];
              
            }
        }

        internal void pgUpkeyPressed()
        {
            int n;
            lastKey = "PGUP";

            n = inputArrayGrid.CurrentRow.Index - inputArrayGrid.DisplayedRowCount(false);
            if (inputArrayGrid.CurrentRow.Index >=0)
            {
                inputArrayGrid.CurrentCell = inputArrayGrid.Rows[n].Cells[1];
         
            }
            
        }

        internal void setArrLine(int p)
        {
            inputArrayGrid.CurrentCell = inputArrayGrid.Rows[p - 1].Cells[1];
        }

        internal void setScrLine(int p)
        {
            // Doesn't need to do anything...
        }

        internal void InsertkeyPressed()
        {
            if (!allowInsert) return;

            if (beforeInsert != null)
            {
                sendTrigger(beforeInsert.ID, -1);
                nextMove = MoveType.MoveTypeInsert;
            }
            else
            {
                if (inputArrayGrid.Rows.Count < maxRows)
                {
                    int r = inputArrayGrid.CurrentRow.Index;
                    doInsertRow();
                    setField(r + 1, null);
                }
                else
                {
                    MessageBox.Show("Cant insert more rows - array is full");
                }
            }
        }



        private void doInsertRow()
        {
            int r;
            
            DataRow newRow;
            r = inputArrayGrid.CurrentRow.Index;
            
            newRow = Data.NewRow();

            newRow[0] = "XXX"; // First column was to hold the subscript - but its currently not used....

            
            for (int a = 0; a < inputArrayGrid. table.TableColumn.Length; a++)
            {
                if (inputArrayGrid.table.TableColumn[a].defaultValue != null && inputArrayGrid.table.TableColumn[a].defaultValue != "")
                {
                    newRow[a+1]= inputArrayGrid.table.TableColumn[a].defaultValue;
                    //e.Row.Cells[a+1].Value=table.TableColumn[a].defaultValue;
                }
                else
                {
                    newRow[a+1] = "";
                }
            }
            
          
            Data.Rows.InsertAt(newRow, r);
            

            
        }

        internal void DeletekeyPressed()
        {
            if (!allowDelete) return;

            try
            {
                doDeleteRow();
            }
            catch (Exception e)
            {
                MessageBox.Show(e.Message);
            }

           
        }

        private void doDeleteRow()
        {
            if (inputArrayGrid.CurrentRow == null)
            {
                MessageBox.Show("No row selected to remove!");
                return;
            }

            inputArrayGrid.EndEdit();
            inputArrayGrid.Rows.RemoveAt(inputArrayGrid.CurrentRow.Index);
        }
    }




    /*
        private void copyFieldData()
        {


            for (int row = 0; row < rowDataChanged.Length; row++)
            {
                // Indicate that the row is the same as last time..
                rowDataChanged[row] = false;

                // Now is our row greater than the number of rows in the datagrid ? 
                // If so - we need to pretend to get the values - we'll use "null"...
                //
                if (row >= inputArrayGrid.Rows.Count)
                {
                    for (int col = 0; col < nCols; col++)
                    {
                        if (Data[row][col] != null) rowDataChanged[row] = true;
                        Data[row][col] = null;
                    }
                }
                else
                {
                    for (int col = 0; col < nCols; col++)
                    {
                        string newVal=(string)inputArrayGrid.Rows[row].Cells[col+1].Value;
                        if (Data[row, col] != newVal)
                        {
                            rowDataChanged[row] = true;
                            Console.WriteLine("Different @ "+row+" "+col+" Data was : "+Data[row,col]+" now "+newVal);
                            Data[row, col] = newVal;
                        }
                    }
                }
            }
        }
        */

}