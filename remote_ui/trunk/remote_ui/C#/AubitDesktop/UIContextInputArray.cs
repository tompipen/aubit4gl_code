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
    class UIInputArrayContext : UIContext
    {
        /// <summary>
        /// Stores whether ths current context is currently active
        /// </summary>
        private bool _contextIsActive;
        private FGLApplicationPanel mainWin;
        private List<Int32> PendingEvents;

        /// <summary>
        /// Set when we want to monitor for focus changes.
        /// Typically - we dont care when setting up/activating the fields
        /// </summary>
        private bool inputFocusActive;
        private List<BEFORE_FIELD_EVENT> beforeFieldList;
        private List<AFTER_FIELD_EVENT> afterFieldList;
        private List<ON_ACTION_EVENT> onActionList;

        private enum MoveType
        {
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
        /// Total maximum size of the 4gl array
        /// </summary>
        private int maxRows;

        private bool allowInsert;
        private bool allowDelete;
        private bool noNewLines;

        /// <summary>
        /// The number of columns/fields in one row of the display array screen record
        /// </summary>
        private int nCols;

        /// <summary>
        /// The current screen line
        /// </summary>
        private int scrLine;
        private string [,]Data;
        private bool []rowDataChanged;


        /// <summary>
        /// The current array line (from 1 to nRows)
        /// </summary>
        private int arrLine;

        private int lastarrLine;

        /// <summary>
        /// Number of lines in the screen record
        /// </summary>
        private int scrRecLines;

        
        private FGLFoundField[,] screenRecord;
        private List<ONKEY_EVENT> KeyList;
        private event UIEventHandler EventTriggered;

        private BEFORE_ROW_EVENT beforeRow;
        private AFTER_ROW_EVENT afterRow;
        

        private List<FGLFoundField> activeFields;
        private FGLFoundField setCurrentField;
        private FGLFoundField CurrentField;
            private int CurrentFieldNo=-1;

        private bool doneBeforeRowForFirst = false;

        public bool contextIsActive()
        {
            return _contextIsActive;
        }



        private string getTriggeredText(string ID)
        {
            string cfield;
            if (CurrentField != null)
            {
                cfield = " INFIELD=\"" + CurrentField.useName + "\"";
            }
            else
            {
                cfield = "";
            }
            

            return "<TRIGGERED ID=\"" + ID + "\" ARRLINE=\"" + this.arrLine + "\" SCRLINE=\"" + this.scrLine + "\" " + cfield +  " LASTKEY=\"" + mainWin.lastKey + "\">"+ getSyncValues() +"</TRIGGERED>";
        }

        public void DeletekeyPressed()
        {
            if (!allowDelete)
            {
                mainWin.setErrorTextFromFieldValidation("ARR_DEL_MSG");
                return;
            }
            for (int a = arrLine; a <= nRows; a++)
            {
                for (int col = 0; col < nCols; col++)
                {
                    Data[a-1, col] = Data[a , col];
                }
                rowDataChanged[a-1] = true;

            
            }
            for (int col = 0; col < nCols; col++)
            {
                Data[nRows, col] = "";
            }
            rowDataChanged[nRows - 1] = true;
            nRows--;
            drawArrAll();   
        }

        public void InsertkeyPressed()
        {
            if (!allowInsert)
            {
                mainWin.setErrorTextFromFieldValidation("ARR_INS_MSG");
                return;
            }

            if (nRows >= maxRows)
            {
                mainWin.setErrorTextFromFieldValidation("INPARRAY_FULL_MSG");
                return;
            }

            for (int a = nRows; a >= arrLine; a--)
            {
                for (int col=0;col<nCols;col++) {
                    Data[a , col] = Data[a-1, col];
                }
                rowDataChanged[a] = true;
            }

            rowDataChanged[arrLine - 1] = true;
            for (int col = 0; col < nCols; col++)
            {   
                    Data[arrLine-1, col] = activeFields[col].fglField.defaultValue;
            }
            drawArrAll();
        }

        public void downkeyPressed()
        {
            mainWin.clrErrorTextFromFieldValidation();
            copyFieldData();
            if (arrLine < nRows || (arrLine<maxRows && allowInsert && !noNewLines))
            {
                
                // If we've got a before row *and* an after row - we need to send to packets back - but 
                // we can only send the 'before' packet - after we've send the 'after' - and got the 'waitforevent' back again...
                // so - we'll store the movement and do it later...
                if (beforeRow != null && afterRow != null)
                {
                    // We've got to send the before/after row triggers..
                    nextMove = MoveType.MoveTypeDown;
                    this.EventTriggered(null, afterRow.ID, getTriggeredText(afterRow.ID));

                }
                else
                {
                    if (afterRow != null)
                    {
                        if (this.EventTriggered != null)
                        {
                            this.EventTriggered(null, afterRow.ID, getTriggeredText(afterRow.ID));
                        }
                    }

                    moveDown();
                    if (arrLine >= nRows)
                    {
                        nRows = arrLine;
                    }
                    if (beforeRow != null)
                    {
                        if (this.EventTriggered != null)
                        {
                            this.EventTriggered(null, beforeRow.ID, getTriggeredText(beforeRow.ID));
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
            while (arrLine < scrLine) scrLine--;
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
            copyFieldData();
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
                    this.EventTriggered(null, afterRow.ID, getTriggeredText(afterRow.ID));

                }
                else
                {
                    if (afterRow != null)
                    {

                        this.EventTriggered(null, afterRow.ID, getTriggeredText(afterRow.ID));
                    }

                    moveUp();

                    if (beforeRow != null)
                    {
                        this.EventTriggered(null, beforeRow.ID, getTriggeredText(beforeRow.ID));
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


        private void copyFieldData()
        {
            
            int topline;
            
            
            
            topline = arrLine - scrLine + 1;

            for (int row = 0; row < scrRecLines; row++)
            {
                for (int col = 0; col < nCols; col++)
                {
                    string olddata;
                    string newdata;
                    olddata = Data[row + topline - 1, col];
                    newdata=this.screenRecord[row,col].fglField.Text;
                    if (olddata!=newdata) {
                        rowDataChanged[row+topline-1]=true;
                        Data[row+topline-1, col] =newdata;
                    
                    }
                }
            }
        }

        public void pgUpkeyPressed()
        {
            copyFieldData();
            mainWin.clrErrorTextFromFieldValidation();

            if (arrLine > scrRecLines)
            {

                // If we've got a before row *and* an after row - we need to send to packets back - but 
                // we can only send the 'before' packet - after we've send the 'after' - and got the 'waitforevent' back again...
                // so - we'll store the movement and do it later...
                if (beforeRow != null && afterRow != null)
                {
                    // We've got to send the before/after row triggers..
                    nextMove = MoveType.MoveTypePageUp;
                    this.EventTriggered(null, afterRow.ID, getTriggeredText(afterRow.ID));

                }
                else
                {
                    if (afterRow != null)
                    {
                        if (this.EventTriggered != null)
                        {
                            this.EventTriggered(null, afterRow.ID, getTriggeredText(afterRow.ID));
                        }
                    }

                    movePgUp();
                    if (beforeRow != null)
                    {
                        if (this.EventTriggered != null)
                        {
                            this.EventTriggered(null, beforeRow.ID, getTriggeredText(beforeRow.ID));
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
            copyFieldData();
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
                    this.EventTriggered(null, afterRow.ID, getTriggeredText(afterRow.ID));

                }
                else
                {
                    if (afterRow != null)
                    {
                        if (this.EventTriggered != null)
                        {
                            this.EventTriggered(null, afterRow.ID, getTriggeredText(afterRow.ID));
                        }
                    }

                    movePgDown();
                    if (beforeRow != null)
                    {
                        if (this.EventTriggered != null)
                        {
                            this.EventTriggered(null, beforeRow.ID, getTriggeredText(beforeRow.ID));
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
            return getTriggeredText("ACCEPT");
            
        }

        public UIInputArrayContext(FGLApplicationPanel f, INPUTARRAY p)
        {
            int cnt;
            PendingEvents = new List<int>();
            nCols = Convert.ToInt32(p.ARRVARIABLES);
            KeyList = new List<ONKEY_EVENT>();
            mainWin = f;
            this.arrLine = 1;
            this.scrLine = 1;
            this.nextMove = 0;
            this.lastarrLine = -1;
            this.nRows = Convert.ToInt32(p.ARRCOUNT);
            this.maxRows = Convert.ToInt32(p.MAXARRSIZE);
            
                this.noNewLines = decode_bool_from_xml(p.NONEWLINES);

                this.allowInsert = decode_bool_from_xml(p.ALLOWINSERT);
                this.allowDelete = decode_bool_from_xml(p.ALLOWDELETE);

            

            setCurrentField = null;
            CurrentField = null;
            CurrentFieldNo = -1;
            
            beforeRow = null;
            afterRow = null;

            afterFieldList = new List<AFTER_FIELD_EVENT>();
            beforeFieldList = new List<BEFORE_FIELD_EVENT>();
            onActionList = new List<ON_ACTION_EVENT>();


            this.Data=new string[Convert.ToInt32(p.MAXARRSIZE),nCols];
            this.rowDataChanged = new bool[Convert.ToInt32(p.MAXARRSIZE)];

            for (int a = 0; a < Convert.ToInt32(p.MAXARRSIZE); a++)
            {
                for (int b = 0; b < nCols; b++)
                {
                    this.Data[a, b] = null;
                }
                this.rowDataChanged[a] = false;
            }

            foreach (object evt in p.EVENTS)
            {
                if (evt is ONKEY_EVENT)
                {
                    ONKEY_EVENT e;
                    e = (ONKEY_EVENT)evt;
                    KeyList.Add(e);
                    continue;
                }

                if (evt is AFTER_FIELD_EVENT)
                {
                    AFTER_FIELD_EVENT e;
                    e = (AFTER_FIELD_EVENT)evt;
                    afterFieldList.Add(e);
                    continue;
                }
                if (evt is BEFORE_FIELD_EVENT)
                {
                    BEFORE_FIELD_EVENT e;
                    e = (BEFORE_FIELD_EVENT)evt;
                    beforeFieldList.Add(e);
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

                if (evt is AFTER_INPUT_EVENT)
                {
                    continue;
                }
                MessageBox.Show("Unhandled Event for INPUT ARRAY");
            }


            activeFields = f.FindFieldArray(p.FIELDLIST);
            scrRecLines = activeFields.Count / nCols;
            cnt = 0;
            screenRecord = new FGLFoundField[scrRecLines,nCols];
            for (int a = 0; a < scrRecLines; a++)
            {
                //screenRecord[a] = new FGLFoundField[nCols];
                for (int b = 0; b < nCols; b++)
                {
                    screenRecord[a,b] = activeFields[cnt++];
                }
            }

        }

        private bool decode_bool_from_xml(string p)
        {
            if (p == null) return false;
            if (p.Length == 0) return false;
            if (Convert.ToInt32(p) > 0) return true;
            return false;

            
        }


        private void clrScrRecordLine(int scr_line)
        {
            for (int a = 0; a < nCols; a++)
            {
                screenRecord[scr_line - 1,a].fglField.Text = "";
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
                screenRecord[scr_line - 1,a].fglField.Text = this.Data[lineno - 1,a];
            }

        }

        private void redisplay_arr(bool redisp_all)
        {
            if (redisp_all == false)
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
            topline = arrLine - scrLine + 1;

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
            setContextForCurrentRow();
            Console.WriteLine("set focus : CurrentFieldNo=" + CurrentFieldNo);


            for (int row = 0; row < this.scrRecLines; row++)
            {
                for (int col = 0; col < this.nCols; col++)
                {
                    if (row == scrLine - 1)
                    {
                        screenRecord[row,col].fglField.isOnSelectedRow = true;
                    }
                    else
                    {
                        screenRecord[row,col].fglField.isOnSelectedRow = false;
                    }
                }
            }

            if (CurrentFieldNo == -1) CurrentFieldNo = 0;
            screenRecord[scrLine - 1,CurrentFieldNo].fglField.setFocus();



        }

        public void setNextField(string fieldName)
        {
            foreach (FGLFoundField f in activeFields)
            {
                if (f.isField(fieldName) )
                {
                    setCurrentField = f;
                }
            }
            //throw new ApplicationException("INPUT ARRAY cant do nextfields");
        }

        public void NavigateToTab()
        {
        }

        public void NavigateAwayTab()
        {
        }

        void inputFieldValidationHandler(object source, string failedText, out bool ignore)
                {
            ignore = false;
            mainWin.setErrorTextFromFieldValidation(failedText);
            
        }


        void inputGotFocus(object source,string comment)
        {
            int a;

            


            Console.WriteLine("In input got focus");
            mainWin.CommentText = comment;

            if (!inputFocusActive)
            {
                Console.WriteLine("Ignoreing field change - we're messing with the fields...");
                return;
            }

            a = 0;
            foreach (FGLFoundField f in activeFields)
            {
                
                if (f.fglField == source)
                {
                    Console.WriteLine("Found current field... @ "+a);
                    CurrentField = f;
                    break;
                }
                a++;
            }
            

            // Now work out what field we're on..
            CurrentFieldNo = -1;
            for (int row = 0; row < this.scrRecLines; row++)
            {
                for (int col = 0; col < this.nCols; col++)
                {
                    if (this.screenRecord[row, col] == CurrentField)
                    {
                        Console.WriteLine("Found current field no col="+col+" row="+row);
                        CurrentFieldNo = col;
                        break;
                    }
                }
                if (CurrentFieldNo >= 0) break;
            }
            //if (CurrentFieldNo == 1)
            //{
            //    MessageBox.Show("Somewhere");
            //}

            Console.WriteLine("Triggered a currentfieldno "+CurrentFieldNo);
        }



        public void befAftFieldTriggered(object source, string ID, string TriggeredText)
        {
            foreach (FGLFoundField f in activeFields)
            {
                if (f.fglField == source)
                {
                    CurrentField = f;
                    break;
                }
            }

            if (TriggeredText == "")
            {
                TriggeredText = getTriggeredText(ID);
                //getTriggeredTag(ID) + getSyncValues() + "</TRIGGERED>";
            }

            this.EventTriggered(source, ID, TriggeredText);

            foreach (FGLFoundField f in activeFields)
            {
                if (f.fglField == source)
                {
                    CurrentField = f;
                    break;
                }
            }

        }


        public string getSyncValues()
        {
            string s;
            
            copyFieldData();

            s = "<SYNCROWS>";
            for (int row = 0; row < this.nRows; row++)
            {
                

                if (rowDataChanged[row])
                {
                    s += "<ROW SUBSCRIPT=\"" + (row + 1) + "\">";
                    s += "<SYNCVALUES>";
                     
                    for (int col = 0; col < this.nCols; col++)
                    {
                        FGLFoundField i;
                            i = activeFields[col]; // we can just use the first set of fields - should be duplicated for the subsequent rows...
                            s += "<SYNCVALUE FIELDNAME=\"" + i.useName + "\">" + System.Security.SecurityElement.Escape(Data[row,col]) + "</SYNCVALUE>";

                    }
                    s += "</SYNCVALUES>";
                    s += "</ROW>";
                }
            }
            s += "</SYNCROWS>";

            return s;
        }

        /*
        public string getTriggeredTag(string ID)
        {
            string cfield;
            if (CurrentField != null)
            {
                cfield = " INFIELD=\"" + CurrentField.useName + "\"";
            }
            else
            {
                cfield = "";
            }
            return "<TRIGGERED ID=\"" + ID + "\" " + cfield + " LASTKEY=\"" + mainWin.lastKey + "\"" + ">";
        }
        */



        public void onActionTriggered(object source, string ID, string TriggeredText)
        {
            if (TriggeredText == "")
            {
                TriggeredText = getTriggeredText(ID);
            }

            this.EventTriggered(source, ID, TriggeredText);
        }


        

        public void ActivateContext(UIEventHandler UInputArrayContext_EventTriggered, VALUE[] val, ROW[] rows)
        {
            //int cnt = 0;

            inputFocusActive = false;

            for (int row = 0; row < this.nRows; row++)
            {
                rowDataChanged[row] = false;
            }

            
            mainWin.setActiveToolBarKeys(KeyList, true, true, true);







            if (nextMove != MoveType.MoveTypeNoPendingMovement)
            {
                // Theres a pending movement...
                switch (nextMove)
                {
                    case MoveType.MoveTypeUp:
                        moveUp();
                        if (beforeRow != null)
                        {
                            this.EventTriggered(null, beforeRow.ID, getTriggeredText(beforeRow.ID));
                        }
                        nextMove = MoveType.MoveTypeNoPendingMovement;
                        break;

                    case MoveType.MoveTypePageUp:
                        movePgUp();
                        if (beforeRow != null)
                        {
                            this.EventTriggered(null, beforeRow.ID, beforeRow.ID);
                        }
                        nextMove = MoveType.MoveTypeNoPendingMovement;
                        break;

                    case MoveType.MoveTypePageDown:
                        movePgDown();
                        if (beforeRow != null)
                        {
                            this.EventTriggered(null, beforeRow.ID, getTriggeredText(beforeRow.ID));
                        }
                        nextMove = MoveType.MoveTypeNoPendingMovement;
                        break;

                    case MoveType.MoveTypeDown:
                        moveDown();
                        if (beforeRow != null)
                        {
                            this.EventTriggered(null, beforeRow.ID, getTriggeredText(beforeRow.ID));
                        }
                        nextMove = MoveType.MoveTypeNoPendingMovement;
                        break;

                }
            }
            redisplay_arr(true);

            this.EventTriggered = UInputArrayContext_EventTriggered;
            if (beforeRow != null && doneBeforeRowForFirst ==false)
            {
                doneBeforeRowForFirst = true;
                this.EventTriggered(null, beforeRow.ID, getTriggeredText(beforeRow.ID));
            }

            // Clear the context on all fields
            mainWin.SetContext(FGLContextType.ContextNone);


            #region Set up field validation for active fields
            foreach (FGLFoundField f in activeFields)
            {
                f.fglField.fieldValidationFailed = inputFieldValidationHandler;
                f.fglField.onGotFocus = inputGotFocus;
            }
            #endregion

            #region set the current field
            if (setCurrentField != null) // Next field has been registered..
            {
                CurrentField = setCurrentField;
                CurrentField.fglField.setFocus();
                setCurrentField = null;
            }

            if (CurrentField == null)
            {
                CurrentField = activeFields[0];
                CurrentFieldNo = 0;
                CurrentField.fglField.setFocus();
            }
            #endregion


            #region setup after field event IDs
            // We might want to cache these results....
            // Set up the after fields by setting the afterFieldID property of the widget..
            //
            foreach (AFTER_FIELD_EVENT e in afterFieldList)
            {
                List<FGLFoundField> ff = mainWin.FindField(e.FIELD);

                if (ff == null)
                {
                    throw new ApplicationException("field not found :" + e.FIELD);
                }
                if (ff.Count == 0)
                {
                    throw new ApplicationException("field not found : " + e.FIELD);
                }

                foreach (FGLFoundField ffield in ff)
                {
                    ffield.fglField.afterFieldID = e.ID;
                    ffield.fglField.onUIEvent = befAftFieldTriggered;
                }

            }
            #endregion

            #region set up before field event IDs
            // Set up the after fields by setting the afterFieldID property of the widget..
            //
            foreach (BEFORE_FIELD_EVENT e in beforeFieldList)
            {
                List<FGLFoundField> ff = mainWin.FindField(e.FIELD);

                if (ff == null)
                {
                    throw new ApplicationException("field not found :" + e.FIELD);
                }
                if (ff.Count == 0)
                {
                    throw new ApplicationException("field not found : " + e.FIELD);
                }

                foreach (FGLFoundField ffield in ff)
                {
                    ffield.fglField.beforeFieldID = e.ID;
                    ffield.fglField.onUIEvent = befAftFieldTriggered;
                }

            }
            #endregion

            #region set up "on action" event IDs
            // Set up the actions by setting the onActionID property of the widget..
            //
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
            #endregion

            #region Copy data from WAITFOREVENT packet
            if (rows != null)
            {
                bool needRedisplay = false;
                for (int row= 0; row < rows.Length; row++)
                {
                    // We should always get a full set of values
                    for (int a=0;a<this.nCols;a++) {
                        //bool isNew=false;
                        
                        //if (rows[row].VALUES[a].Text == null) isNew = true;

                        if (row>this.nRows) {
                            Data[Convert.ToInt32(rows[row].SUBSCRIPT)-1,a]=activeFields[a].fglField.defaultValue;
                        } else {
                            Data[Convert.ToInt32(rows[row].SUBSCRIPT)-1,a]=rows[row].VALUES[a].Text;
                        }
                        activeFields[a].fglField.Text = Data[Convert.ToInt32(rows[row].SUBSCRIPT)-1, a];
                        needRedisplay = true;
                    }
                }

                if (needRedisplay)
                {
                    redisplay_arr(true);
                }
            }
            #endregion

            if (!_contextIsActive)
            {
                _contextIsActive = true;
            }




                //setContextForCurrentRow();
                setFocusToCurrentRow();
                inputFocusActive = true;

                if (CurrentField.subscript == scrLine)
                {
                if (!CurrentField.fglField.hasFocus)
                {
                    CurrentField.fglField.setFocus();
                }
            }
            
        }

        private void setContextForCurrentRow()
        {
            int a;
            bool wasinputFocusActive;
            wasinputFocusActive = inputFocusActive;
            inputFocusActive = false;
            List<FGLFoundField> currrow=new List<FGLFoundField>();
            for (a=0;a<this.nCols;a++) {
            currrow.Add(screenRecord[this.scrLine - 1,a]);
            }
            
            mainWin.SetContext(FGLContextType.ContextInputArray, currrow, this);
            inputFocusActive = wasinputFocusActive;
        }



        public void DeactivateContext()
        {
            mainWin.setActiveToolBarKeys(null, false);

            mainWin.SetContext(FGLContextType.ContextNone);

            EventTriggered = null;
            _contextIsActive = false;
            inputFocusActive = false;
        }

        public void FreeContext()
        {
            _contextIsActive = false;
        }


    }



}