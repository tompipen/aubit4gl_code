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
    class UIDisplayArrayContext : UIContext
    {
        private bool _contextIsActive;
        private FGLApplicationPanel mainWin;
        //private int currentRow;
        
        private enum MoveType {
            MoveTypeNoPendingMovement,
            MoveTypeDown,
            MoveTypeUp,
            MoveTypeTo,
            MoveTypePageDown,
            MoveTypePageUp
        };
        private MoveType nextMove;
        /// <summary>
        /// Total number of rows in the dataset
        /// </summary>
        private int nRows;

        /// <summary>
        /// The number of columns/fields in one row of the display array screen record
        /// </summary>
        private int nCols;

        /// <summary>
        /// The current screen line
        /// </summary>
        private int scrLine;

        /// <summary>
        /// The current array line (from 1 to nRows)
        /// </summary>
        private int arrLine;

        private int lastarrLine;

        /// <summary>
        /// Number of lines in the screen record
        /// </summary>
        private int scrRecLines;

        private ROW[] Data;
        private FGLFoundField[][] screenRecord;
        private List<ONKEY_EVENT> KeyList;
        private event UIEventHandler EventTriggered;

        private BEFORE_ROW_EVENT beforeRow;
        private AFTER_ROW_EVENT afterRow;
        private List<ON_ACTION_EVENT> onActionList;

        private List<FGLFoundField> activeFields;
        
        public bool contextIsActive()
        {
            return _contextIsActive;
        }


        public void downkeyPressed()
        {
            mainWin.clrErrorTextFromFieldValidation();

            if (arrLine < nRows)
            {
                // If we've got a before row *and* an after row - we need to send to packets back - but 
                // we can only send the 'before' packet - after we've send the 'after' - and got the 'waitforevent' back again...
                // so - we'll store the movement and do it later...
                if (beforeRow != null && afterRow != null)
                {
                    // We've got to send the before/after row triggers..
                    nextMove = MoveType.MoveTypeDown;
                    this.EventTriggered(null, afterRow.ID, "<TRIGGERED ID=\"" + afterRow.ID + "\" ARRLINE=\"" + this.arrLine + "\" SCRLINE=\"" + this.scrLine + "\"></TRIGGERED>");

                }
                else
                {
                    if (afterRow != null)
                    {
                        if (this.EventTriggered != null)
                        {
                            this.EventTriggered(null, afterRow.ID, "<TRIGGERED ID=\"" + afterRow.ID + "\" ARRLINE=\"" + this.arrLine + "\" SCRLINE=\"" + this.scrLine + "\"></TRIGGERED>");
                        }
                    }

                    moveDown();
                    if (beforeRow != null)
                    {
                        if (this.EventTriggered != null)
                        {
                            this.EventTriggered(null, beforeRow.ID, "<TRIGGERED ID=\"" + beforeRow.ID + "\" ARRLINE=\"" + this.arrLine + "\" SCRLINE=\"" + this.scrLine + "\"></TRIGGERED>");
                        }

                    }

                }
            }
            else
            {
                // Tried to move off the top...
                mainWin.setErrorTextFromFieldValidation("ARR_DIR_MSG");
            }
        }

        private void moveDown()
        {
            arrLine++;
            scrLine++;
            if (scrLine > scrRecLines)
            {
                scrLine = scrRecLines;
                redisplay_arr(true);
            }
            else
            {
                redisplay_arr(false);
            }
            lastarrLine = arrLine;
            setFocusToCurrentRow();
        }


        private void movePgDown()
        {
            arrLine += this.scrRecLines;
            if (arrLine > this.nRows)
            {
                arrLine = this.nRows;
            }
            while (arrLine<scrLine) scrLine--;
            redisplay_arr(true);
            lastarrLine = arrLine;
            setFocusToCurrentRow();
        }

        private void movePgUp()
        {
            if (arrLine <= scrLine) scrLine = 1;
            arrLine = arrLine - this.scrRecLines;
            while (arrLine - scrLine < 0) arrLine++;
            if (arrLine < 1)
            {
                throw new ApplicationException("ArrLine < 1 shouldn't happen");
            }
            redisplay_arr(true);
            lastarrLine = arrLine;
            setFocusToCurrentRow();
        }

        public void upkeyPressed()
        {
            mainWin.clrErrorTextFromFieldValidation();

            if (arrLine > 1)
            {
                // If we've got a before row *and* an after row - we need to send to packets back - but 
                // we can only send the 'before' packet - after we've send the 'after' - and got the 'waitforevent' back again...
                // so - we'll store the movement and do it later...
                if (beforeRow != null && afterRow != null)
                {
                    // We've got to send the before/after row triggers..
                    nextMove = MoveType.MoveTypeUp;
                    this.EventTriggered(null, afterRow.ID, "<TRIGGERED ID=\"" + afterRow.ID + "\" ARRLINE=\"" + this.arrLine + "\" SCRLINE=\"" + this.scrLine + "\"></TRIGGERED>");

                }
                else
                {
                    if (afterRow != null)
                    {
                        this.EventTriggered(null, afterRow.ID, "<TRIGGERED ID=\"" + afterRow.ID + "\" ARRLINE=\"" + this.arrLine + "\" SCRLINE=\"" + this.scrLine + "\"></TRIGGERED>");
                    }

                    moveUp();

                    if (beforeRow != null)
                    {
                        this.EventTriggered(null, beforeRow.ID, "<TRIGGERED ID=\"" + beforeRow.ID + "\" ARRLINE=\"" + this.arrLine + "\" SCRLINE=\"" + this.scrLine + "\"></TRIGGERED>");

                    }

                }
            }
            else
            {
                // Tried to move off the top...
                mainWin.setErrorTextFromFieldValidation("ARR_DIR_MSG");
            }
        }

        private void moveUp()
        {
            scrLine--;
            arrLine--;
            if (scrLine == 0)
            {
                scrLine = 1;
                redisplay_arr(true);
            }
            else
            {
                redisplay_arr(false);
            }
            lastarrLine = arrLine;
            setFocusToCurrentRow();
        }

        public void pgUpkeyPressed()
        {
            mainWin.clrErrorTextFromFieldValidation();

            if (arrLine >scrRecLines)
            {

                // If we've got a before row *and* an after row - we need to send to packets back - but 
                // we can only send the 'before' packet - after we've send the 'after' - and got the 'waitforevent' back again...
                // so - we'll store the movement and do it later...
                if (beforeRow != null && afterRow != null)
                {
                    // We've got to send the before/after row triggers..
                    nextMove = MoveType.MoveTypePageUp;
                    this.EventTriggered(null, afterRow.ID, "<TRIGGERED ID=\"" + afterRow.ID + "\" ARRLINE=\"" + this.arrLine + "\" SCRLINE=\"" + this.scrLine + "\"></TRIGGERED>");

                }
                else
                {
                    if (afterRow != null)
                    {
                        if (this.EventTriggered != null)
                        {
                            this.EventTriggered(null, afterRow.ID, "<TRIGGERED ID=\"" + afterRow.ID + "\" ARRLINE=\"" + this.arrLine + "\" SCRLINE=\"" + this.scrLine + "\"></TRIGGERED>");
                        }
                    }

                    movePgUp();
                    if (beforeRow != null)
                    {
                        if (this.EventTriggered != null)
                        {
                            this.EventTriggered(null, beforeRow.ID, "<TRIGGERED ID=\"" + beforeRow.ID + "\" ARRLINE=\"" + this.arrLine + "\" SCRLINE=\"" + this.scrLine + "\"></TRIGGERED>");
                        }

                    }

                }
            }
            else
            {
                // Tried to move off the top...
                mainWin.setErrorTextFromFieldValidation("ARR_DIR_MSG");
            }
        }

        public void pgDownkeyPressed()
        {
            mainWin.clrErrorTextFromFieldValidation();

            if (arrLine < nRows)
            {
               
                // If we've got a before row *and* an after row - we need to send to packets back - but 
                // we can only send the 'before' packet - after we've send the 'after' - and got the 'waitforevent' back again...
                // so - we'll store the movement and do it later...
                if (beforeRow != null && afterRow != null)
                {
                    // We've got to send the before/after row triggers..
                    nextMove = MoveType.MoveTypePageDown;
                    this.EventTriggered(null, afterRow.ID, "<TRIGGERED ID=\"" + afterRow.ID + "\" ARRLINE=\"" + this.arrLine + "\" SCRLINE=\"" + this.scrLine + "\"></TRIGGERED>");

                }
                else
                {
                    if (afterRow != null)
                    {
                        if (this.EventTriggered != null)
                        {
                            this.EventTriggered(null, afterRow.ID, "<TRIGGERED ID=\"" + afterRow.ID + "\" ARRLINE=\"" + this.arrLine + "\" SCRLINE=\"" + this.scrLine + "\"></TRIGGERED>");
                        }
                    }

                    movePgDown();
                    if (beforeRow != null)
                    {
                        if (this.EventTriggered != null)
                        {
                            this.EventTriggered(null, beforeRow.ID, "<TRIGGERED ID=\"" + beforeRow.ID + "\" ARRLINE=\"" + this.arrLine + "\" SCRLINE=\"" + this.scrLine + "\"></TRIGGERED>");
                        }

                    }

                }
            }
            else
            {
                // Tried to move off the top...
                mainWin.setErrorTextFromFieldValidation("ARR_DIR_MSG");
            }
        }



        public string getAcceptString()
        {
            return "<TRIGGERED ID=\"ACCEPT\" ARRLINE=\"" + this.arrLine + "\" SCRLINE=\"" + this.scrLine + "\"></TRIGGERED>";
        }

        public UIDisplayArrayContext(FGLApplicationPanel f, DISPLAYARRAY p)
        {
            int cnt;
            nCols = Convert.ToInt32(p.ARRVARIABLES);
            KeyList = new List<ONKEY_EVENT>();
            mainWin = f;
            this.arrLine = 1;
            this.scrLine = 1;
            this.nextMove= 0;
            this.lastarrLine = -1;
            this.nRows = Convert.ToInt32(p.ARRCOUNT);
            onActionList = new List<ON_ACTION_EVENT>();
            Data = p.ROWS;
            
            beforeRow = null;
            afterRow = null;
            
            
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
                MessageBox.Show("Unhandled Event for DISPLAY ARRAY");
            }

            
            activeFields = f.FindFieldArray(p.FIELDLIST);
            scrRecLines = activeFields.Count / nCols;
            cnt = 0;
            screenRecord=new FGLFoundField[scrRecLines][];
            for (int a = 0; a < scrRecLines; a++)
            {
                screenRecord[a] = new FGLFoundField[nCols];
                for (int b = 0; b < nCols; b++)
                {
                    screenRecord[a][b] = activeFields[cnt++];
                }
            }
            
        }


        private void clrScrRecordLine(int scr_line)
        {
            for (int a = 0; a < nCols; a++)
            {
                screenRecord[scr_line-1][a].fglField.Text = "";
            }
        }

        private void drawArr(bool currentRow, int lineno)
        {
            int topline;
            int scr_line;
            topline = arrLine - scrLine + 1;
            scr_line = lineno - topline + 1;
            for (int a = 0; a < nCols; a++)
            {
                screenRecord[scr_line-1][a].fglField.Text=this.Data[lineno-1].VALUES[a].Text;
            }
            
        }

        private void redisplay_arr(bool redisp_all)
        {
            if (redisp_all==false)
            {
                if (lastarrLine >= 0)
                {
                    drawArr(false, lastarrLine);
                }
                drawArr(true, arrLine);
            }
            else
            {
                drawArrAll();
            }
        }

        private void drawArrAll()
        {
            int topline;
            topline=arrLine-scrLine+1;

            for (int a = 0; a < scrRecLines; a++)
            {
                if (a + topline <= nRows)
                {
                    drawArr(a + topline == arrLine, a + topline);
                }
                else
                {
                    clrScrRecordLine(a + 1);
                }
            }
            //setFocusToCurrentRow();
        }


        private void setFocusToCurrentRow()
        {
                    screenRecord[scrLine-1][0].fglField.setFocus();
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



        public void onActionTriggered(object source, string ID, string TriggeredText)
        {
            if (TriggeredText == "")
            {
                TriggeredText =    "<TRIGGERED ID=\""+ID+"\" ARRLINE=\"" + this.arrLine + "\" SCRLINE=\"" + this.scrLine + "\"></TRIGGERED>";
            }

            this.EventTriggered(source, ID, TriggeredText);
        }

        public void ActivateContext(UIEventHandler UIDisplayArrayContext_EventTriggered, VALUE[] values, ROW[] rows)
        {
            //mainWin.SetContext(FGLContextType.ContextNone);
            mainWin.SetContext(FGLContextType.ContextDisplayArray, activeFields, this);

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

            mainWin.setActiveToolBarKeys(KeyList, true,true,false);
            if (nextMove == MoveType.MoveTypeNoPendingMovement)
            {
                setFocusToCurrentRow();
            }

            if (nextMove != MoveType.MoveTypeNoPendingMovement)
            {
                // Theres a pending movement...
                switch (nextMove)
                {
                    case MoveType.MoveTypeUp:
                        moveUp();
                        if (beforeRow != null)
                        {
                            this.EventTriggered(null, beforeRow.ID, "<TRIGGERED ID=\"" + beforeRow.ID + "\" ARRLINE=\"" + this.arrLine + "\" SCRLINE=\"" + this.scrLine + "\"></TRIGGERED>");
                        }
                        nextMove = MoveType.MoveTypeNoPendingMovement;
                        break;

                    case MoveType.MoveTypePageUp:
                        movePgUp();
                        if (beforeRow != null)
                        {
                            this.EventTriggered(null, beforeRow.ID, "<TRIGGERED ID=\"" + beforeRow.ID + "\" ARRLINE=\"" + this.arrLine + "\" SCRLINE=\"" + this.scrLine + "\"></TRIGGERED>");
                        }
                        nextMove = MoveType.MoveTypeNoPendingMovement;
                        break;

                    case MoveType.MoveTypePageDown:
                        movePgDown();
                        if (beforeRow != null)
                        {
                            this.EventTriggered(null, beforeRow.ID, "<TRIGGERED ID=\"" + beforeRow.ID + "\" ARRLINE=\"" + this.arrLine + "\" SCRLINE=\"" + this.scrLine + "\"></TRIGGERED>");
                        }
                        nextMove = MoveType.MoveTypeNoPendingMovement;
                        break;

                    case MoveType.MoveTypeDown:
                        moveDown();
                        if (beforeRow != null)
                        {
                            this.EventTriggered(null, beforeRow.ID, "<TRIGGERED ID=\"" + beforeRow.ID + "\" ARRLINE=\"" + this.arrLine + "\" SCRLINE=\"" + this.scrLine + "\"></TRIGGERED>");
                        }
                        nextMove = MoveType.MoveTypeNoPendingMovement;
                        break;

                }
            }
            redisplay_arr(true);
            
            this.EventTriggered = UIDisplayArrayContext_EventTriggered;

            if (!_contextIsActive)
            {
                _contextIsActive = true;
            }
        }



        public void DeactivateContext()
        {
            mainWin.setActiveToolBarKeys(null, false);

            mainWin.SetContext(FGLContextType.ContextNone);
            
            EventTriggered = null;
            _contextIsActive = false;
           
        }

        public void FreeContext()
        {
            _contextIsActive = false;
        }


    }



}