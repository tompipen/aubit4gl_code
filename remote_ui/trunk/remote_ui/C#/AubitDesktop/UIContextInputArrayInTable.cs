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
        DataGridView inputArrayGrid;
        private bool initialRow=false;

        //private int currentRow;
        
        private enum MoveType {
            MoveTypeNoPendingMovement,
            MoveTypeDown,
            MoveTypeUp,
            MoveTypeTo,
            MoveTypePageDown,
            MoveTypePageUp
        };





        /// <summary>
        /// The current screen line
        /// </summary>
        private int scrLine;

        /// <summary>
        /// The current array line (from 1 to nRows)
        /// </summary>
        private int arrLine;



        /// <summary>
        /// Number of lines in the screen record
        /// </summary>


        private ROW[] Data;

        private List<ONKEY_EVENT> KeyList;
        private event UIEventHandler EventTriggered;

        private BEFORE_ROW_EVENT beforeRow;
        private AFTER_ROW_EVENT afterRow;
        private List<ON_ACTION_EVENT> onActionList;

        //private List<FGLFoundField> activeFields;
        
      
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
            setLines();
            string txt= "<TRIGGERED ID=\"ACCEPT\" ARRLINE=\"" + this.arrLine + "\" SCRLINE=\"" + this.scrLine + "\" LASTKEY=\"ACCEPT\"></TRIGGERED>";
            this.EventTriggered(null, "ACCEPT", txt, this);
        }

        public bool externallyTriggeredID(string ID)
        {
            setLines();
            string txt = "<TRIGGERED ID=\""+ID+"\" ARRLINE=\"" + this.arrLine + "\" SCRLINE=\"" + this.scrLine + "\" LASTKEY=\"ACCEPT\"></TRIGGERED>";
            this.EventTriggered(null, ID, txt, this);
            return false;
        }

        public void setUpData(ROW[] rows) {
            for (int row = 0; row < rows.Length; row++)
            {
                DataGridViewRow r;
                string[] data;
                data = new string[rows[row].VALUES.Length + 1];
                r = new DataGridViewRow();

                // We'll use the first column to store the index
                // for the current row...
                data[0] = "" + (row + 1);

                for (int col = 0; col < rows[row].VALUES.Length; col++)
                {
                    data[col + 1] = rows[row].VALUES[col].Text;
                    inputArrayGrid.AutoResizeColumn(col);
                }
                inputArrayGrid.Rows.Add(data);

                inputArrayGrid.AutoResizeRow(row);
                inputArrayGrid.AutoResizeColumnHeadersHeight();
            }
        }

        public UIInputArrayInTableContext(FGLApplicationPanel f, INPUTARRAY p)
        {

           
            KeyList = new List<ONKEY_EVENT>();
            mainWin = f;
            this.arrLine = 1;
            this.scrLine = 1;

            onActionList = new List<ON_ACTION_EVENT>();

            //Data = p.ROWS;
            
            beforeRow = null;
            afterRow = null;
            initialRow = true;
            
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
                Program.Show("Unhandled Event for DISPLAY ARRAY");
            }


            inputArrayGrid = f.FindRecord(p.FIELDLIST);
            inputArrayGrid.Rows.Clear();



            inputArrayGrid.Columns[0].Visible = false;

            if (beforeRow != null)
            {
                inputArrayGrid.RowEnter += new DataGridViewCellEventHandler(displayArrayGrid_RowEnter);
            }

            if (afterRow != null)
            {
                inputArrayGrid.RowLeave += new DataGridViewCellEventHandler(displayArrayGrid_RowLeave);
            }

            inputArrayGrid.Enabled = false;
        }










        private void setFocusToCurrentRow()
        {
            Program.Show("Fixme");
        }


        public void setNextField(string fieldName)
        {
            throw new ApplicationException("DISPLAY ARRAY cant do nextfields");
        }

        public void NavigateToTab()
        {
        }

        public void NavigateAwayTab()
        {

        }


        public void onActionTriggered(object source, string ID, string TriggeredText,UIContext u)
        {
            if (TriggeredText == "")
            {
                TriggeredText =    "<TRIGGERED ID=\""+ID+"\" ARRLINE=\"" + this.arrLine + "\" SCRLINE=\"" + this.scrLine + "\"></TRIGGERED>";
            }
            this.EventTriggered(source, ID, TriggeredText,this);
        }

        public void ActivateContext(UIEventHandler UIDisplayArrayContext_EventTriggered, VALUE[] values, ROW[] rows)
        {
            
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
            inputArrayGrid.Enabled = true;

            
            mainWin.setActiveToolBarKeys(KeyList, true,true,false);
           
            
            this.EventTriggered = UIDisplayArrayContext_EventTriggered;

            if (!_contextIsActive)
            {
                _contextIsActive = true;
            }

            if (initialRow)
            {
                initialRow = false;
                if (beforeRow != null)
                {
                    this.EventTriggered(null, beforeRow.ID, "<TRIGGERED ID=\"" + beforeRow.ID + "\" ARRLINE=\"" + this.arrLine + "\" SCRLINE=\"" + this.scrLine + "\"></TRIGGERED>",this);
                }
            }

        }

        void displayArrayGrid_RowLeave(object sender, DataGridViewCellEventArgs e)
        {
            if (inputArrayGrid.CurrentRow != null)
            {


                if (afterRow.ID != "")
                {
                    setLines(e.RowIndex);
                    if (this.EventTriggered != null)
                    {
                        this.EventTriggered(null, afterRow.ID, "<TRIGGERED ID=\"" + afterRow.ID + "\" ARRLINE=\"" + this.arrLine + "\" SCRLINE=\"" + this.scrLine + "\"></TRIGGERED>",this);
                    }
                }
            }
        }

        void displayArrayGrid_RowEnter(object sender, DataGridViewCellEventArgs e)
        {
            if (inputArrayGrid.CurrentRow != null)
            {
                if (beforeRow.ID != "")
                {
                    setLines(e.RowIndex);
                    if (this.EventTriggered != null)
                    {
                        this.EventTriggered(null, beforeRow.ID, "<TRIGGERED ID=\"" + beforeRow.ID + "\" ARRLINE=\"" + this.arrLine + "\" SCRLINE=\"" + this.scrLine + "\"></TRIGGERED>",this);
                    }
                }
            }
        }

        private void setLines(int n)
        {
            this.arrLine = Convert.ToInt32((string)inputArrayGrid.Rows[n].Cells[0].Value);
            this.scrLine = this.arrLine;
        }


        private void setLines()
        {
            this.arrLine = Convert.ToInt32((string)inputArrayGrid.Rows[ inputArrayGrid.CurrentRow.Index].Cells[0].Value);
            this.scrLine = this.arrLine;
        }

        public void DeactivateContext()
        {
            mainWin.setActiveToolBarKeys(null, false);
            inputArrayGrid.Enabled = false;
            mainWin.SetContext(FGLContextType.ContextNone);
            
            EventTriggered = null;
            _contextIsActive = false;
           
        }

        public void FreeContext()
        {
            _contextIsActive = false;
        }



        internal void upkeyPressed()
        {
            if (inputArrayGrid.CurrentRow.Index > 0)
            {
                inputArrayGrid.CurrentCell=inputArrayGrid.Rows[inputArrayGrid.CurrentRow.Index-1].Cells[1];
            }
        }

        internal void downkeyPressed()
        {
            if (inputArrayGrid.CurrentRow.Index<inputArrayGrid.Rows.Count-1)
            {
                inputArrayGrid.CurrentCell = inputArrayGrid.Rows[inputArrayGrid.CurrentRow.Index + 1].Cells[1];
            }
            
        }

        internal void pgDownkeyPressed()
        {
            int n;
            n= inputArrayGrid.CurrentRow.Index+ inputArrayGrid.DisplayedRowCount(false);
            if (n < inputArrayGrid.Rows.Count-1)
            {
                inputArrayGrid.CurrentCell = inputArrayGrid.Rows[n].Cells[1];
              
            }
        }

        internal void pgUpkeyPressed()
        {
            int n;
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
    }



}