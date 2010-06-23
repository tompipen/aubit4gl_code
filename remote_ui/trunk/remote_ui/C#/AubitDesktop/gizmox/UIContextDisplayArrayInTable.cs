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
using Gizmox.WebGUI.Forms;
using System.Data;

namespace AubitDesktop
{
    class UIDisplayArrayInTableContext : UIContext
    {
        private bool _contextIsActive;
        private FGLApplicationPanel mainWin;
        FormattedGridView displayArrayGrid;
        private bool initialRow=false;
        DataTable dt;

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
            switch (ID)
            {
                case "PGUP": pgUpkeyPressed(); return true;
                case "PGDN": pgDownkeyPressed(); return true;
                case "DOWN": downkeyPressed(); return true;
                case "UP": upkeyPressed(); return true;
                case "ACCEPT": toolBarAcceptClicked(); return true;
                // INTERRUPT can pass through - we dont mind ;-)
            }
            setLines();
            string txt = "<TRIGGERED ID=\""+ID+"\" ARRLINE=\"" + this.arrLine + "\" SCRLINE=\"" + this.scrLine + "\" LASTKEY=\"ACCEPT\"></TRIGGERED>";
            this.EventTriggered(null, ID, txt, this);
            return false;
        }


        public UIDisplayArrayInTableContext(FGLApplicationPanel f, DISPLAYARRAY p)
        {
            bool haveDown = false;
            bool haveUp = false;
            bool havePgDn = false;
            bool havePgUp = false;
            bool haveAccept = false;
            bool haveInterrupt = false;

            //nCols = Convert.ToInt32(p.ARRVARIABLES);
            KeyList = new List<ONKEY_EVENT>();
            mainWin = f;
            this.arrLine = 1;
            this.scrLine = 1;
            //this.nextMove= 0;
            //this.lastarrLine = -1;
            //this.nRows = Convert.ToInt32(p.ARRCOUNT);
            onActionList = new List<ON_ACTION_EVENT>();
            Data = p.ROWS;
            
            beforeRow = null;
            afterRow = null;
            initialRow = true;
            
            foreach (object evt in p.EVENTS)
            {
                if (evt is ONKEY_EVENT)
                {
                    ONKEY_EVENT e;
                    e = (ONKEY_EVENT)evt;
                    if (e.KEY == "" + FGLUtils.getKeyCodeFromKeyName("ACCEPT"))
                    {
                        haveAccept = true;
                    }

                    if (e.KEY == "" + FGLUtils.getKeyCodeFromKeyName("INTERRUPT"))
                    {
                        haveInterrupt = true;
                    }
                    if (e.KEY == "" + FGLUtils.getKeyCodeFromKeyName("DOWN"))
                    {
                        haveDown = true;
                    }

                    if (e.KEY == "" + FGLUtils.getKeyCodeFromKeyName("UP"))
                    {
                        haveUp = true;
                    }

                    if (e.KEY == "" + FGLUtils.getKeyCodeFromKeyName("PGUP"))
                    {
                        havePgUp = true;
                    }

                    if (e.KEY == "" + FGLUtils.getKeyCodeFromKeyName("PGDN"))
                    {
                        havePgDn = true;
                    }
                    
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

            if (!haveAccept)
            {
                KeyList.Add(new ONKEY_EVENT("ACCEPT"));
            }

            if (!haveInterrupt)
            {
                KeyList.Add(new ONKEY_EVENT("INTERRUPT"));
            }

            if (!haveDown)
            {
                KeyList.Add(new ONKEY_EVENT("DOWN"));
            }

            if (!haveUp)
            {
                KeyList.Add(new ONKEY_EVENT("UP"));
            }

            if (!havePgDn)
            {
                KeyList.Add(new ONKEY_EVENT("PGDN"));
            }

            if (!havePgUp)
            {
                KeyList.Add(new ONKEY_EVENT("PGUP"));
            }

            

            displayArrayGrid = f.FindRecord(p.FIELDLIST);
            displayArrayGrid.init();
            displayArrayGrid.DataSource = null;
            dt = new DataTable();

            dt.Columns.Add("subscript");
            for (int cols = 1; cols <= p.ROWS[0].VALUES.Length; cols++)
            {
                dt.Columns.Add("col" + (cols));
            }
            

            //displayArrayGrid.Rows.Clear();

            displayArrayGrid.allowInsertRow = false;

            for (int row = 0; row < p.ROWS.Length; row++)
            {
                DataGridViewRow r;
                string[] data;
                data=new string[p.ROWS[row].VALUES.Length+1];
                r = new DataGridViewRow();
                
                // We'll use the first column to store the index
                // for the current row...
                data[0] = "" + (row+1);

                for (int col = 0; col < p.ROWS[row].VALUES.Length;col++ )
                {
                    object itm;
                    int trimWidth = -1;
                    AubitDesktop.Xml.XMLForm.TableColumn tc = displayArrayGrid.table.TableColumn[col];
                    itm = tc.Item;


                    if (itm is AubitDesktop.Xml.XMLForm.Edit)
                    {
                        AubitDesktop.Xml.XMLForm.Edit e;
                        e = (AubitDesktop.Xml.XMLForm.Edit)itm;
                        trimWidth = Convert.ToInt32(e.width);
                    }
                    if (itm is AubitDesktop.Xml.XMLForm.Widget)
                    {
                        AubitDesktop.Xml.XMLForm.Widget e;
                        e = (AubitDesktop.Xml.XMLForm.Widget)itm;
                        trimWidth = Convert.ToInt32(e.width);
                    }

                    data[col + 1] = p.ROWS[row].VALUES[col].Text;

                    if (trimWidth > 0)
                    {
                        if (p.ROWS[row].VALUES[col].Text != null)
                        {
                            if (p.ROWS[row].VALUES[col].Text.Length > trimWidth)
                            {
                                data[col + 1] = p.ROWS[row].VALUES[col].Text.Substring(0, trimWidth);
                            }
                        }
                    }
                    
                    
                }
                dt.Rows.Add(data);
                //displayArrayGrid.Rows.Add(data);

                //displayArrayGrid.AutoResizeRow(row);
                //displayArrayGrid.AutoResizeColumnHeadersHeight();
            }

            
            displayArrayGrid.Columns[0].Visible = false;

            displayArrayGrid.DataSource = dt;
            
            displayArrayGrid.AutoResizeColumnHeadersHeight();
            for (int row = 0; row < dt.Rows.Count; row++)
            {
                displayArrayGrid.AutoResizeRow(row);

                for (int col = 0; col < p.ROWS[row].VALUES.Length; col++)
                {
                    displayArrayGrid.AutoResizeColumn(col);
                }
            }

          //  displayArrayGrid.RowCount = 5;
            displayArrayGrid.Enabled = false;
             displayArrayGrid.sizeGrid(); 
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
            mainWin.setActiveToolBarKeys(KeyList, onActionList); //, true, true, false);
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
            displayArrayGrid.Enabled = true;

            displayArrayGrid.onDblClick= new EventHandler(displayArrayGrid_DoubleClick);


            if (afterRow != null)
            {
                displayArrayGrid.AfterRow = new UIArrayTableRowHandler(displayArrayGrid_RowLeave);
            }
            if (beforeRow != null)
            {
                displayArrayGrid.BeforeRow = new UIArrayTableRowHandler(displayArrayGrid_RowEnter);
            }

            mainWin.setActiveToolBarKeys(KeyList,onActionList); //, true,true,false);
           
            
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
            displayArrayGrid.context = FGLContextType.ContextDisplayArray;
        }

        void displayArrayGrid_DoubleClick(object sender, EventArgs e)
        {
            toolBarAcceptClicked();
        }

        void displayArrayGrid_RowLeave( int rowId)
        {
            if (displayArrayGrid.CurrentRow != null)
            {


                if (afterRow.ID != "")
                {
                    setLines(rowId);
                    if (this.EventTriggered != null)
                    {
                        this.EventTriggered(null, afterRow.ID, "<TRIGGERED ID=\"" + afterRow.ID + "\" ARRLINE=\"" + this.arrLine + "\" SCRLINE=\"" + this.scrLine + "\"></TRIGGERED>",this);
                    }
                }
            }
        }

        void displayArrayGrid_RowEnter(int rowId)
        {
            if (displayArrayGrid.CurrentRow != null)
            {
                if (beforeRow.ID != "")
                {
                    setLines(rowId);
                    if (this.EventTriggered != null)
                    {
                        this.EventTriggered(null, beforeRow.ID, "<TRIGGERED ID=\"" + beforeRow.ID + "\" ARRLINE=\"" + this.arrLine + "\" SCRLINE=\"" + this.scrLine + "\"></TRIGGERED>",this);
                    }
                }
            }
        }

        private void setLines(int n)
        {
            this.arrLine = Convert.ToInt32((string)displayArrayGrid.Rows[n].Cells[0].Value);
            this.scrLine = this.arrLine;
        }


        private void setLines()
        {
            this.arrLine = Convert.ToInt32((string)displayArrayGrid.Rows[ displayArrayGrid.CurrentRow.Index].Cells[0].Value);
            this.scrLine = this.arrLine;
        }

        public void DeactivateContext()
        {
            mainWin.setActiveToolBarKeys(null, null); //,false);
            displayArrayGrid.Enabled = false;
            mainWin.SetContext(FGLContextType.ContextDisplayArrayInactive);
            displayArrayGrid.context = FGLContextType.ContextDisplayArrayInactive;
            displayArrayGrid.onDblClick = null;
            EventTriggered = null;
            _contextIsActive = false;
           
        }

        public void FreeContext()
        {
            _contextIsActive = false;
            displayArrayGrid.context = FGLContextType.ContextNone;
            displayArrayGrid.copyFromDataset();
        }



        internal void upkeyPressed()
        {
            if (displayArrayGrid.CurrentRow.Index > 0)
            {
                displayArrayGrid.CurrentCell=displayArrayGrid.Rows[displayArrayGrid.CurrentRow.Index-1].Cells[1];
            }
        }

        internal void downkeyPressed()
        {
            if (displayArrayGrid.CurrentRow.Index<displayArrayGrid.Rows.Count-1)
            {
                displayArrayGrid.CurrentCell = displayArrayGrid.Rows[displayArrayGrid.CurrentRow.Index + 1].Cells[1];
            }
            
        }

        internal void pgDownkeyPressed()
        {
            int n;
            n= displayArrayGrid.CurrentRow.Index+ displayArrayGrid.DisplayedRowCount(false);
            if (n < displayArrayGrid.Rows.Count-1)
            {
                displayArrayGrid.CurrentCell = displayArrayGrid.Rows[n].Cells[1];
              
            }
        }

        internal void pgUpkeyPressed()
        {
            int n;
            n = displayArrayGrid.CurrentRow.Index - displayArrayGrid.DisplayedRowCount(false);
            if (displayArrayGrid.CurrentRow.Index >=0)
            {
                displayArrayGrid.CurrentCell = displayArrayGrid.Rows[n].Cells[1];
         
            }
            
        }

        internal void setArrLine(int p)
        {
            displayArrayGrid.CurrentCell = displayArrayGrid.Rows[p - 1].Cells[1];
        }

        internal void setScrLine(int p)
        {
            // Doesn't need to do anything...
        }
    }



}
