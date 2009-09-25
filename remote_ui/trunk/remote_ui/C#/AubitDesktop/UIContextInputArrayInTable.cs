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
using System.Text;
using System.Windows.Forms;

namespace AubitDesktop
{
    class UIInputArrayInTableContext : UIContext
    {
        private bool _contextIsActive;
        private FGLApplicationPanel mainWin;
        FormattedGridView inputArrayGrid;
        

        class s_pending {
            public s_pending(string text, int scrLine)
            {
                this.triggeredText = text;
                this.scrLine = scrLine;
            }
            public string triggeredText;
            public int scrLine;
        };
        List<s_pending> PendingEvents;

        private int []beforeFieldEventIds;
        private int []afterFieldEventIds;
        private string lastKey="";
        private bool allowInsert=true;
        private bool allowDelete=true;


        /// <summary>
        /// Number of variables across the screen array..
        /// </summary>
        private int nCols;

        //private int currentRow;
        
        private enum MoveType {
            MoveTypeNoPendingMovement,
            MoveTypeDown,
            MoveTypeUp,
            MoveTypeTo,
            MoveTypePageDown,
            MoveTypePageUp
        };


        int arrLine=0;




        /// <summary>
        /// Number of lines in the screen record
        /// </summary>


        private string[,] Data;
        private bool[] rowDataChanged;

        private List<ONKEY_EVENT> KeyList;
        private event UIEventHandler EventTriggered;

        private BEFORE_ROW_EVENT beforeRow;
        private AFTER_ROW_EVENT afterRow;
        private List<ON_ACTION_EVENT> onActionList;
      
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

            for (int row = 0; row < rows.Length; row++)
            {
                int subscript;
                subscript = Convert.ToInt32(rows[row].SUBSCRIPT) - 1;
                while (subscript >= inputArrayGrid.Rows.Count)
                {
                    string[] data = new string[nCols + 1];
                    data[0] = "" + inputArrayGrid.Rows.Count;      
                    inputArrayGrid.Rows.Add(data);
                }
            }


            for (int row = 0; row < rows.Length; row++)
            {
                DataGridViewRow r;
                int subscript;
                r = new DataGridViewRow();
                subscript = Convert.ToInt32(rows[row].SUBSCRIPT) - 1;


                // We'll use the first column to store the index
                // for the current row...
                //  Data[subscript,0] = "" + (row + 1);

                for (int col = 0; col < rows[row].VALUES.Length; col++)
                {
                    Data[subscript, col] = rows[row].VALUES[col].Text;
                }


                inputArrayGrid.syncData(subscript,nCols, Data);
            }
        }


       

       
        public UIInputArrayInTableContext(FGLApplicationPanel f, INPUTARRAY p)
        {

           
            KeyList = new List<ONKEY_EVENT>();
            mainWin = f;
           // this.arrLine = 1;
           // this.scrLine = 1;
            nCols = p.ARRVARIABLES;

            
            Data=new string[p.MAXARRSIZE, p.ARRVARIABLES];
            rowDataChanged = new bool[p.MAXARRSIZE];
            PendingEvents = new List<s_pending>();
            
            for (int a = 0; a < p.MAXARRSIZE; a++)
            {
                rowDataChanged[a] = false;
                for (int b = 0; b < p.ARRVARIABLES; b++)
                {
                    Data[a,b] = null;
                }
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
            inputArrayGrid.Rows.Clear();
            inputArrayGrid.Columns[0].Visible = false;


            
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

                  //  MessageBox.Show("Before field needs fixing");
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





            if (p.NONEWLINES==1
                || p.ALLOWINSERT==0)
            {
                inputArrayGrid.AllowUserToAddRows = false;
                allowInsert = false;
            }
            else
            {
                inputArrayGrid.AllowUserToAddRows = true;
                allowInsert = true;
            }

            if (p.ALLOWDELETE == 1)
            {
                inputArrayGrid.AllowUserToDeleteRows = true;
                allowDelete = true;
            }
            else
            {
                inputArrayGrid.AllowUserToDeleteRows = false;
                allowDelete = false;
            }


            
            inputArrayGrid.setFieldToStart(); 

            //inputArrayGrid.Enabled = false;
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
            inputArrayGrid.setField(arrLine, fieldName);
        }

        public void NavigateToTab()
        {
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

            copyFieldData();

            s = "<SYNCROWS>";
            for (int row = 0; row < rowDataChanged.Length; row++)
            {
                if (rowDataChanged[row])
                {
                    s += "<ROW SUBSCRIPT=\"" + (row + 1) + "\">";
                    s += "<SYNCVALUES>";

                    for (int col = 0; col < this.nCols; col++)
                    {
                        s += "<SYNCVALUE FIELDNAME=\"" + inputArrayGrid.getFieldName(col) + "\">" + System.Security.SecurityElement.Escape(Data[row, col]) + "</SYNCVALUE>";
                    }

                    s += "</SYNCVALUES>";
                    s += "</ROW>";
                }
            }
            s += "</SYNCROWS>";

            return s;
        }

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
                        if (Data[row, col] != null) rowDataChanged[row] = true;
                        Data[row, col] = null;
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


        public void ActivateContext(UIEventHandler UIInputArrayContext_EventTriggered, VALUE[] values, ROW[] rows)
        {

            stopHandlers();
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
            if (inputArrayGrid.CurrentCell != null)
            {
                crow = inputArrayGrid.CurrentCell.RowIndex;
                ccol = inputArrayGrid.CurrentCell.ColumnIndex;
            }
            if (rows != null)
            {
                setUpData(rows);
            }
            if (crow != -1 && ccol != -1)
            {
                if (inputArrayGrid.CurrentCell != null)
                {
                    if (crow != inputArrayGrid.CurrentCell.RowIndex || ccol != inputArrayGrid.CurrentCell.ColumnIndex)
                    {
                        inputArrayGrid.CurrentCell = inputArrayGrid.Rows[crow].Cells[ccol];
                    }
                }
                else
                {
                    inputArrayGrid.CurrentCell = inputArrayGrid.Rows[crow].Cells[ccol];
                }
            }

            startHandlers();
            mainWin.setActiveToolBarKeys(KeyList,true ,true,true);

            if (!_contextIsActive)
            {
                _contextIsActive = true;
            }


            inputArrayGrid.context = FGLContextType.ContextInputArray;
            
            if (PendingEvents.Count > 0)
            {
                s_pending p;
                p = PendingEvents[0];
                arrLine = p.scrLine;

                string s = p.triggeredText;
                PendingEvents.RemoveAt(0);
                sendPendingTrigger(s);
                
                return;
            }

          
            inputArrayGrid.Enabled = true;
        }

        private void startHandlers( )
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
            inputArrayGrid.beforeFieldHandler += new UIArrayTableHandler(beforeFieldHandler);
            inputArrayGrid.afterFieldHandler += new UIArrayTableHandler(afterFieldHandler);
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
                arrLine = Convert.ToInt32((string)inputArrayGrid.Rows[rowIndex].Cells[0].Value);
                scrLine = arrLine;
            }
            else
            {
                arrLine = Convert.ToInt32((string)inputArrayGrid.Rows[inputArrayGrid.CurrentRow.Index].Cells[0].Value);
                scrLine = arrLine;
            }



            if (this.EventTriggered != null)
            {
                this.EventTriggered(null, ID, getTriggeredTag(ID,arrLine,scrLine), this);
                this.EventTriggered = null;
            }
            else
            {
                PendingEvents.Add(new s_pending(getTriggeredTag(ID,arrLine,arrLine),arrLine));
            }
        }

        private string getTriggeredTag(string ID,int arrLine, int scrLine)
        {
            string infieldStr = inputArrayGrid.getInfield();

            return "<TRIGGERED ID=\"" + ID + "\" ARRLINE=\"" + arrLine + "\" SCRLINE=\"" + scrLine + "\" LASTKEY=\""+this.lastKey+"\""+infieldStr+">"+
                getSyncValues()+
                "</TRIGGERED>";
        }


        void RowLeave(object sender, DataGridViewCellEventArgs e)
        {
            if (inputArrayGrid.CurrentRow != null)
            {
                if (afterRow != null)
                {
                    if (afterRow.ID != "")
                    {
                        sendTrigger(afterRow.ID, e.RowIndex);
                    }
                }
            }
        }

        void RowEnter(object sender, DataGridViewCellEventArgs e)
        {
            if (inputArrayGrid.CurrentRow != null)
            {
                if (beforeRow != null)
                {
                    if (beforeRow.ID != "")
                    {
                        sendTrigger(beforeRow.ID, e.RowIndex);
                    }
                }
            }
        }



        public void DeactivateContext()
        {
            mainWin.setActiveToolBarKeys(null, false);
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

            try {
                int r;
                r = inputArrayGrid.CurrentRow.Index;
                inputArrayGrid.Rows.Insert(inputArrayGrid.CurrentRow.Index, 1);
                  // now put the cursor back to the current row..
                inputArrayGrid.setField(r+1, null);  

                // Setup any default values..
                inputArrayGrid.FormattedGridView_DefaultValuesNeeded(null,new DataGridViewRowEventArgs(inputArrayGrid.CurrentRow));
              
                

            //throw new Exception("The method or operation is not implemented.");
            }
            catch (Exception e)
            {
                MessageBox.Show(e.Message);
            }
        }

        internal void DeletekeyPressed()
        {
            if (!allowDelete) return;

            try
            {
                inputArrayGrid.Rows.RemoveAt(inputArrayGrid.CurrentRow.Index);
            }
            catch (Exception e)
            {
                MessageBox.Show(e.Message);
            }

            //throw new Exception("The method or operation is not implemented.");
        }
    }



}