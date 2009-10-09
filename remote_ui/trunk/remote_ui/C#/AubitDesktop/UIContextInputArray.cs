/*
 *  Copyright (c) 2008 The Aubit Development Team. 
 *  All rights reserved. See CREDITS file.
 *  
 *  
 *  This file is part of Aubit 4gl.
 *
 *  Aubit 4gl is free software: you can redistribute ict and/or modify
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
       // private List<string> PendingEvents;
        private int curr_line_is_new;
        /// <summary>
        /// Set when we want to monitor for focus changes.
        /// Typically - we dont care when setting up/activating the fields
        /// </summary>
        private bool inputFocusActive;
      //  private List<BEFORE_FIELD_EVENT> beforeFieldList;
       // private List<AFTER_FIELD_EVENT> afterFieldList;
        private List<ON_ACTION_EVENT> onActionList;

        DateTime ActivateStime = DateTime.Now;

        private INPUTARRAY this_input_array;
       // int CurrentFieldNo;

       // private int masterSaveFieldNo = -1;



     //   private MoveType nextMove = MoveType.MoveTypeFirst;
        /// <summary>
        /// Total number of rows in the dataset
        /// </summary>
        private int _nRows;
        private int nRows
        {
            get
            {
                return _nRows;
            }
            set
            {
                _nRows = value;
            }
        }

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
        private string[,] Data;
        private bool[] rowDataChanged;


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
        private event UIEventHandler eventTriggered;

        /*
        private BEFORE_ROW_EVENT beforeRow;
        private AFTER_ROW_EVENT afterRow;
        private BEFORE_INSERT_EVENT beforeInsert;
        private AFTER_INSERT_EVENT afterInsert;
        private BEFORE_DELETE_EVENT beforeDelete;
        private AFTER_DELETE_EVENT afterDelete;
        */
        private List<FGLFoundField> activeFields;
      //  private FGLFoundField setCurrentField;
        private FGLFoundField CurrentField;
        private int _currentFieldNo = -1;

        public int CurrentFieldNo
        {
            get { return _currentFieldNo; }
            set
            {
                if (_currentFieldNo != value)
                {
                    _currentFieldNo = value;
                }
            }
        }

        public bool contextIsActive()
        {
            return _contextIsActive;
        }

        public bool useKeyPress(KeyEventArgs ke)
        {
            return false;
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

            return "<TRIGGERED ID=\"" + ID + "\" ARRLINE=\"" + this.arrLine + "\" SCRLINE=\"" + this.scrLine + "\" " + cfield + " LASTKEY=\"" + mainWin.LastKey + "\">" + getSyncValues() + "</TRIGGERED>";
        }



        public void DeletekeyPressed()
        {
            if (!allowDelete)
            {
                mainWin.setErrorTextFromFieldValidation("ARR_DEL_MSG");
                return;
            }
            A4GL_add_to_control_stack(e_formcontrol.FORMCONTROL_AFTER_DELETE,CurrentField, null, 0);
            A4GL_add_to_control_stack(e_formcontrol.FORMCONTROL_BEFORE_DELETE,CurrentField, null, 0);
            checkControlStack();
        }

        private bool checkControlStack()
        {
            bool sentTrigger = false;
            while (fcntrl_cnt > 0)
            {
                int r;
                r = process_control_stack();
                if (r != -1)
                {
                    sentTrigger = true;
                    sendTrigger("" + r);
                    break;
                }
            }
            if (!sentTrigger)
            {
                setFocusToCurrentRow();
            }
            return sentTrigger;
        }

        void doDelete()
        {
            for (int a = arrLine; a <= nRows; a++)
            {
                for (int col = 0; col < nCols; col++)
                {
                    Data[a - 1, col] = Data[a, col];
                }
                rowDataChanged[a - 1] = true;
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

            Movement ptr = new Movement();


            ptr.scrLine = scrLine;
            ptr.arrLine = arrLine;
            ptr.attrib_no = 0;

            FGLFoundField f = screenRecord[scrLine - 1,CurrentFieldNo];
            A4GL_add_to_control_stack(e_formcontrol.FORMCONTROL_BEFORE_FIELD, f, new Movement(ptr), 0);
            A4GL_add_to_control_stack(e_formcontrol.FORMCONTROL_BEFORE_INSERT, CurrentField, null, 0);

            A4GL_add_to_control_stack(e_formcontrol.FORMCONTROL_AFTER_ROW, f, null, 0);
            A4GL_add_to_control_stack(e_formcontrol.FORMCONTROL_AFTER_FIELD, f, null, 0);

            checkControlStack();

        }


        



        void doInsert()
        {
            
            for (int a = nRows; a >= arrLine; a--)
            {
                for (int col = 0; col < nCols; col++)
                {
                    if (a >= maxRows) continue;
                    Data[a, col] = Data[a - 1, col];
                }
                rowDataChanged[a] = true;
            }

            rowDataChanged[arrLine - 1] = true;
            for (int col = 0; col < nCols; col++)
            {
                Data[arrLine - 1, col] = activeFields[col].fglField.defaultValue;

            }


            drawArrAll();
        }



        public void downkeyPressed()
        {

            mainWin.clrErrorTextFromFieldValidation();
            //copyFieldData();
            Console.WriteLine("DownKeyDetected " + (DateTime.Now - ActivateStime));
            if (arrLine < nRows || (arrLine < maxRows && allowInsert && !noNewLines))
            {
                A4GL_newMovement_single(scrLine + 1, arrLine + 1, 0, 'D');
                checkControlStack();
                
            }
            else
            {
                // Tried to move off the top...
                mainWin.setErrorTextFromFieldValidation("ARR_DIR_MSG");
            }
            Console.WriteLine("DownKeyProcessed " + (DateTime.Now - ActivateStime));
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
            //copyFieldData();
            mainWin.clrErrorTextFromFieldValidation();
            
            if (arrLine > 1)
            {
                A4GL_newMovement_single(
                           scrLine - 1, arrLine - 1,
                           CurrentFieldNo, 'U');
                checkControlStack();

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
                    newdata = this.screenRecord[row, col].fglField.Text;
                    if (olddata != newdata)
                    {
                        rowDataChanged[row + topline - 1] = true;
                        Data[row + topline - 1, col] = newdata;

                    }
                }
            }
        }

        public void pgUpkeyPressed()
        {
            //copyFieldData();
            mainWin.clrErrorTextFromFieldValidation();
            if (arrLine - scrRecLines >= 1)
            {

                A4GL_newMovement_single(
                            scrLine,
                            arrLine - scrRecLines, CurrentFieldNo, 'U');
                checkControlStack();

            }
            else
            {
                // Tried to move off the top...
                mainWin.setErrorTextFromFieldValidation("ARR_DIR_MSG");
            }
        }

        public void pgDownkeyPressed()
        {
            //copyFieldData();

            mainWin.clrErrorTextFromFieldValidation();

            if (arrLine + scrRecLines <= this.maxRows)
            {
                if (arrLine + scrRecLines > nRows)
                {
                    mainWin.setErrorTextFromFieldValidation("ARR_DIR_MSG");
                }
                else
                {
                    if (allowInsert)
                    {
                        A4GL_newMovement_single(scrLine, nRows + 1, CurrentFieldNo, 'D');
                        checkControlStack();
                    }
                    else
                    {
                        mainWin.setErrorTextFromFieldValidation("ARR_DIR_MSG");
                    }
                }

            }
            else
            {
                // Tried to move off the top...
                mainWin.setErrorTextFromFieldValidation("ARR_DIR_MSG");
            }
        }



        public void toolBarAcceptClicked()
        {
            copyFieldData();
            if (CurrentField.fglField.afterFieldID != "")
            {
                sendTrigger(CurrentField.fglField.afterFieldID);
            }
            
            sendTrigger("ACCEPT");
        }



        public UIInputArrayContext(FGLApplicationPanel f, INPUTARRAY p)
        {
            int cnt;

            nCols = Convert.ToInt32(p.ARRVARIABLES);
            KeyList = new List<ONKEY_EVENT>();
            onActionList = new List<ON_ACTION_EVENT>();
            mainWin = f;
           
            this.arrLine = -1;
            this.scrLine = -1;
           
            this.lastarrLine = -1;
            this.nRows = Convert.ToInt32(p.ARRCOUNT);
            this.maxRows = Convert.ToInt32(p.MAXARRSIZE);

            this.noNewLines = decode_bool_from_xml(p.NONEWLINES);
            this.allowInsert = decode_bool_from_xml(p.ALLOWINSERT);
            this.allowDelete = decode_bool_from_xml(p.ALLOWDELETE);
            A4GL_init_control_stack();
            this_input_array = p;

           
            CurrentField = null;
            CurrentFieldNo = -1;





            this.Data = new string[Convert.ToInt32(p.MAXARRSIZE), nCols];
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

            
                if (evt is ON_ACTION_EVENT)
                {
                    ON_ACTION_EVENT e;
                    e = (ON_ACTION_EVENT)evt;
                    onActionList.Add(e);
                    continue;
                }


            }


            activeFields = f.FindFieldArray(p.FIELDLIST);
            scrRecLines = activeFields.Count / nCols;
            cnt = 0;
            screenRecord = new FGLFoundField[scrRecLines, nCols];
            for (int a = 0; a < scrRecLines; a++)
            {
                //screenRecord[a] = new FGLFoundField[nCols];
                for (int b = 0; b < nCols; b++)
                {
                    screenRecord[a, b] = activeFields[cnt++];
                }
            }

        }


        public bool externallyTriggeredID(string ID)
        {
            sendTrigger(ID);
            return true;
        }

        private void sendTrigger(string ID)
        {
            if (this.eventTriggered != null)
            {
                this.eventTriggered(null, ID, getTriggeredText(ID), this);
                inputFocusActive = false;
            }
            else
            {
                Program.Show("Cant send now");
            }
        }

        private bool decode_bool_from_xml(int p)
        {
            if (p == 1) return true;
            return false;
        }

        private bool decode_bool_from_xml(string p)
        {
            if (p == null) return false;
            if (p.Length == 0) return false;
            if (Convert.ToInt32(p) > 0) return true;
            return false;


        }


        private void clrScrRecordLine(int scrLine)
        {
            for (int a = 0; a < nCols; a++)
            {
                screenRecord[scrLine - 1, a].fglField.Text = "";
            }
        }

        private void drawArr(bool currentRow, int lineno)
        {
            int topline;
            int scrLine;
            topline = arrLine - this.scrLine + 1;
            scrLine = lineno - topline + 1;
            for (int a = 0; a < nCols; a++)
            {
              //  Console.WriteLine("Setting " + (scrLine - 1) + "," + a + " = " + this.Data[lineno - 1, a]);
                screenRecord[scrLine - 1, a].fglField.Text = this.Data[lineno - 1, a];
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
            
        }


        private void setFocusToCurrentRow()
        {
          

            
            setContextForCurrentRow();
            
            

            // We'll do this enable/disable in two parts
            // so we always have the current row active
            // until the new row is active...
            // If we did it in one go - we'd disable the old row befor enabling the new row when moving down...
            // Enable the new row...
            for (int row = 0; row < this.scrRecLines; row++)
            {
                for (int col = 0; col < this.nCols; col++)
                {
                    if (row == scrLine - 1)
                    {
                        screenRecord[row, col].fglField.isOnSelectedRow = true;
                    }


                }
            }
            
            // Disable the old rows..
            for (int row = 0; row < this.scrRecLines; row++)
            {
                for (int col = 0; col < this.nCols; col++)
                {
                    if (row != scrLine - 1)
                    {
                        screenRecord[row, col].fglField.isOnSelectedRow = false;
                    }
                }
            }

           
            if (CurrentFieldNo == -1)
            {
                CurrentFieldNo = 0;
            }
           
            screenRecord[scrLine - 1, CurrentFieldNo].fglField.setFocus();
           
        }

        public void setNextField(string fieldName)
        {
            int a;
            int attrib = -1;

            if (CurrentField != null)
            {
                A4GL_init_control_stack();
            }

            if (fieldName == "NEXT")
            {
                attrib = CurrentFieldNo + 1;
            }
            if (fieldName == "PREVIOUS")
            {
                attrib = CurrentFieldNo - 1;
            }

            if (attrib == -1)
            {
                a = 0;
                foreach (FGLFoundField f in activeFields)
                {
                    if (f.isField(fieldName))
                    {
                        attrib = a;
                        break;
                    }
                    a++;
                }
            }
            if (attrib != CurrentFieldNo)
            {
                A4GL_newMovement_single(scrLine, arrLine, attrib, 'R');
            }
        }

        public void NavigateToTab()
        {
            mainWin.setActiveToolBarKeys(KeyList, onActionList, true, true, true);
        }

        public void NavigateAwayTab()
        {
        }

        void inputFieldValidationHandler(object source, string failedText, out bool ignore)
        {
            ignore = false;
            mainWin.setErrorTextFromFieldValidation(failedText);

        }


        void inputGotFocus(object source, string comment)
        {
    
            bool found = false;




           // Console.WriteLine("In input got focus");
            mainWin.CommentText = comment;

            if (!inputFocusActive)
            {
              //  Console.WriteLine("Ignoreing field change - we're messing with the fields...");
                return;
            }

      


            // Now work out what field we're on..
            found = false;
            for (int row = 0; row < this.scrRecLines; row++)
            {
                for (int col = 0; col < this.nCols; col++)
                {
                    if (this.screenRecord[row, col].fglField == source)
                    {
                       // Console.WriteLine("Found current field no col=" + col + " row=" + row);
                        A4GL_newMovement_single(row+1, arrLine, col, 'F');
                        found = true;
                        break;
                    }
                }
                if (found)
                {
                    checkControlStack();
                    break;
                }
            }
            Console.WriteLine("Triggered a currentfieldno " + CurrentFieldNo);
        }




        public string getSyncValues()
        {
            string s;

            //copyFieldData();

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
                        s += "<SYNCVALUE FIELDNAME=\"" + i.useName + "\">" + System.Security.SecurityElement.Escape(Data[row, col]) + "</SYNCVALUE>";

                    }
                    s += "</SYNCVALUES>";
                    s += "</ROW>";
                }
            }
            s += "</SYNCROWS>";

            return s;
        }





        public void onActionTriggered(object source, string ID, string TriggeredText, UIContext u)
        {
            /* if (TriggeredText == "")
             {
                 TriggeredText = getTriggeredText(ID);
             }*/
            sendTrigger(ID);
            //this.EventTriggered(source, ID, TriggeredText,this);
        }

        public void ActivateContext(UIEventHandler UInputArrayContext_EventTriggered, VALUE[] val, ROW[] rows)
        {
          ActivateStime = DateTime.Now;
            Console.WriteLine("Activate Context..");

            inputFocusActive = false;

            #region Copy data from WAITFOREVENT packet
            if (rows != null)
            {
                bool needRedisplay = false;
                for (int row = 0; row < rows.Length; row++)
                {
                    // We should always get a full set of values
                    for (int a = 0; a < this.nCols; a++)
                    {
                        //bool isNew=false;

                        //if (rows[row].VALUES[a].Text == null) isNew = true;

                        if (row > this.nRows)
                        {
                            Data[Convert.ToInt32(rows[row].SUBSCRIPT) - 1, a] = activeFields[a].fglField.defaultValue;
                        }
                        else
                        {
                            Data[Convert.ToInt32(rows[row].SUBSCRIPT) - 1, a] = rows[row].VALUES[a].Text;
                        }
                        activeFields[a].fglField.Text = Data[Convert.ToInt32(rows[row].SUBSCRIPT) - 1, a];
                        needRedisplay = true;
                    }
                }

                if (needRedisplay)
                {
                    redisplay_arr(true);
                }
            }
            #endregion

            this.eventTriggered = UInputArrayContext_EventTriggered;
            if (arrLine == -1 && scrLine == -1)
            {
                A4GL_newMovement_single(1, 1, 0, 'N');
            }

          

            for (int row = 0; row < this.nRows; row++)
            {
                rowDataChanged[row] = false;
            }

          
            if (!_contextIsActive)
            {
                _contextIsActive = true;
            }

            if (fcntrl_cnt>0)
            {
                checkControlStack();
                if (!_contextIsActive)
                {
                    Console.WriteLine("Activate finished early " + (DateTime.Now - ActivateStime));
                    return;
                }
            }


            mainWin.setActiveToolBarKeys(KeyList,onActionList, true, true, true);
            redisplay_arr(true);


            // clear the context context on all fields
            mainWin.SetContext(FGLContextType.ContextNone);

      
            #region Set up field validation for active fields
            foreach (FGLFoundField f in activeFields)
            {
                f.fglField.fieldValidationFailed = inputFieldValidationHandler;
                f.fglField.onGotFocus = inputGotFocus;
                f.fglField.beforeFieldID = "";
                f.fglField.afterFieldID = "";
                f.fglField.onActionID = "";
            }
            #endregion

            #region set the current field


            if (CurrentField == null)
            {
                CurrentField = activeFields[0];
                CurrentFieldNo = 0;
                CurrentField.fglField.setFocus();
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





            //setContextForCurrentRow();
            setFocusToCurrentRow();

            if (CurrentField.subscript == scrLine)
            {
                if (!CurrentField.fglField.hasFocus)
                {
           
                    CurrentField.fglField.setFocus();
                 
                }
            }
   
            inputFocusActive = true;
            Console.WriteLine("Activate finished normally " + (DateTime.Now - ActivateStime));

        }

        private void setContextForCurrentRow()
        {
            int a;

            List<FGLFoundField> currrow = new List<FGLFoundField>();
            for (int row = 0; row < scrRecLines; row++)
            {
                for (a = 0; a < this.nCols; a++)
                {
                    currrow.Add(screenRecord[row, a]);
                }
            }

            mainWin.SetContext(FGLContextType.ContextInputArray, currrow, this, KeyList, onActionList, eventTriggered);
            
        }

        public void DeactivateContext()
        {
            Console.WriteLine("Deactivate start at " + (DateTime.Now - ActivateStime));
            mainWin.setActiveToolBarKeys(null, null, false);
            inputFocusActive = false;
            mainWin.SetContext( FGLContextType.ContextInputArrayInactive);

            eventTriggered = null;
            _contextIsActive = false;
            inputFocusActive = false;
            
                Console.WriteLine("Active -> Deactive in " + (DateTime.Now-ActivateStime ));
        
        }

        public void FreeContext()
        {
            _contextIsActive = false;
        }


        internal class Movement
        {
            public int scrLine;
            public int arrLine;
            public int attrib_no;

            internal Movement()
            {
                scrLine = 0;
                arrLine = 0;
                attrib_no = 0;

            }

            internal Movement(Movement m)
            {
                this.scrLine = m.scrLine;
                this.arrLine = m.arrLine;
                this.attrib_no = m.attrib_no;
            }
        }


        enum e_formcontrol
        {
            FORMCONTROL_BEFORE_FIELD = 1,
            FORMCONTROL_AFTER_FIELD = 2,
            FORMCONTROL_BEFORE_INPUT = 3,
            FORMCONTROL_AFTER_INPUT = 4,
            FORMCONTROL_EXIT_INPUT_OK = 5,
            FORMCONTROL_EXIT_INPUT_ABORT = 6,
            FORMCONTROL_KEY_PRESS = 7,
            FORMCONTROL_BEFORE_INSERT = 8,
            FORMCONTROL_BEFORE_DELETE = 9,
            FORMCONTROL_AFTER_INSERT = 10,
            FORMCONTROL_AFTER_DELETE = 11,
            FORMCONTROL_BEFORE_ROW = 12,
            FORMCONTROL_AFTER_ROW = 13,
            /* formloop controls ? Don't know if we need these yet... */
            FORMCONTROL_REQUEST_FIELD,
            FORMCONTROL_ENABLE_FIELD,
            FORMCONTROL_DISABLE_FIELD,
            FORMCONTROL_HIDE_FIELD


        };



        enum e_event
        {
            A4GL_EVENT_BEF_ROW = -10,
            A4GL_EVENT_AFT_ROW = -11,
            A4GL_EVENT_BEFORE_DELETE = -12,
            A4GL_EVENT_AFTER_DELETE = -13,
            A4GL_EVENT_BEFORE_INSERT = -14,
            A4GL_EVENT_AFTER_INSERT = -15,
            A4GL_EVENT_BEF_INSERT_DELETE = -17,
            A4GL_EVENT_AFT_INSERT_DELETE = -18,


            A4GL_EVENT_ON_IDLE = -50,
            A4GL_EVENT_ON_INTERVAL = -51,
            A4GL_EVENT_ON_TIME = -52,


            A4GL_EVENT_KEY_PRESS = -90,
            A4GL_EVENT_ON_ACTION = -91,
            A4GL_EVENT_AFTER_INP_CLEAN = -94,
            A4GL_EVENT_AFTER_INP = -95,
            A4GL_EVENT_BEFORE_FIELD = -97,
            A4GL_EVENT_AFTER_FIELD = -98,
            A4GL_EVENT_BEFORE_INP = -99,
            A4GL_EVENT_BEFORE_FIELD_1 = -197,
            A4GL_EVENT_AFTER_FIELD_1 = -198

        };

        class formcontrol
        {
            internal e_formcontrol op;
            internal FGLFoundField field;
            internal int extent;
            internal Movement parameter;
            internal int state;
        }
        int fcntrl_cnt=0;

        formcontrol[] fcntrl;


        /* 
        * This function adds a value to the control stack
        * this is read to determine when to call before/after fields etc
        *
        */
        void
        A4GL_add_to_control_stack(e_formcontrol op, FGLFoundField field, Movement parameter, int extent)
        {
            int a;

            a = this.fcntrl_cnt;
            this.fcntrl[a].op = op;
            this.fcntrl[a].parameter = parameter;
            this.fcntrl[a].field = field;
            this.fcntrl[a].extent = extent;
            this.fcntrl[a].state = 99;
            this.fcntrl_cnt++;
        }



        /* 
        * process any waiting actions 
        *
        */
        int
       process_control_stack()
        {
            int a;
            int rval;
            int new_state;
            Movement ptr_movement;


            rval = -1;
            new_state = 99;


            a = this.fcntrl_cnt - 1;

            if (this.fcntrl[a].op == e_formcontrol.FORMCONTROL_AFTER_INPUT)
            {
                mainWin.CommentText = "";
                //A4GL_comments (0);
                if (this.fcntrl[a].state == 99)
                {
                    new_state = 50;

                    if (A4GL_has_event(e_event.A4GL_EVENT_AFTER_INP) > 0)
                        rval = A4GL_has_event(e_event.A4GL_EVENT_AFTER_INP);
                    else
                        rval = -1;
                }

                if (this.fcntrl[a].state == 50)
                {
                    mainWin.CommentText = "";
                    //A4GL_comments (0);
                    new_state = 0;
                    if (A4GL_has_event(e_event.A4GL_EVENT_AFTER_INP_CLEAN) > 0)
                        rval = A4GL_has_event(e_event.A4GL_EVENT_AFTER_INP_CLEAN);
                    else
                        rval = -1;
                }
            }


            if (this.fcntrl[a].op == e_formcontrol.FORMCONTROL_EXIT_INPUT_OK)
            {

                //A4GL_comments (0);
                mainWin.CommentText = "";
                if (this.fcntrl[a].state == 99)
                {
                    if (this.CurrentField != null)
                    {
                        A4GL_add_to_control_stack(e_formcontrol.FORMCONTROL_AFTER_ROW, this.CurrentField, null, 0);
                        if (this.curr_line_is_new == 2)
                        {
                            A4GL_add_to_control_stack(e_formcontrol.FORMCONTROL_AFTER_INSERT, this.CurrentField, null, 0);
                        }

                        if (this.curr_line_is_new == 1)
                        {		// They didn't change anything - so not a real insert...
                            this.nRows--;
                        }

                        this.curr_line_is_new = 0;
                        A4GL_add_to_control_stack(e_formcontrol.FORMCONTROL_AFTER_FIELD, this.CurrentField, null, 0);
                    }
                    new_state = 50;
                    rval = -1;
                }

                if (this.fcntrl[a].state == 50)
                {
                    new_state = 10;
                    A4GL_add_to_control_stack(e_formcontrol.FORMCONTROL_AFTER_INPUT, null, null, 0);
                    rval = -1;
                }
                if (this.fcntrl[a].state == 10)
                {
                    new_state = 0;
                    rval = -1;
                }


            }


            if (this.fcntrl[a].op == e_formcontrol.FORMCONTROL_EXIT_INPUT_ABORT)
            {
                if (this.fcntrl[a].state == 99)
                {
                    //A4GL_comments (0);
                    mainWin.CommentText = "";
                    A4GL_add_to_control_stack(e_formcontrol.FORMCONTROL_AFTER_INPUT, null, null, 0);
                    rval = -1;
                    new_state = 10;
                }


                if (this.fcntrl[a].state == 10)
                {
                    new_state = 0;
                }

            }


            if (this.fcntrl[a].op == e_formcontrol.FORMCONTROL_BEFORE_DELETE)
            {
                if (this.fcntrl[a].state == 99)
                {
                    new_state = 50;
                    if (A4GL_has_event(e_event.A4GL_EVENT_BEFORE_DELETE) > 0)
                        rval = A4GL_has_event(e_event.A4GL_EVENT_BEFORE_DELETE);
                    else
                    {
                        if (A4GL_has_event(e_event.A4GL_EVENT_BEF_INSERT_DELETE) > 0)
                            rval = A4GL_has_event(e_event.A4GL_EVENT_BEF_INSERT_DELETE);
                    }
                }

                if (this.fcntrl[a].state == 50)
                {
                    new_state = 0;
                    delete_line_in_array();
                }

            }


            if (this.fcntrl[a].op == e_formcontrol.FORMCONTROL_AFTER_DELETE)
            {
                if (this.fcntrl[a].state == 99)
                {
                    new_state = 50;
                    if (A4GL_has_event(e_event.A4GL_EVENT_AFTER_DELETE) > 0)
                        rval = A4GL_has_event(e_event.A4GL_EVENT_AFTER_DELETE);
                    else
                    {
                        if (A4GL_has_event(e_event.A4GL_EVENT_AFT_INSERT_DELETE) > 0)
                            rval = A4GL_has_event(e_event.A4GL_EVENT_AFT_INSERT_DELETE);
                    }
                }

                if (this.fcntrl[a].state == 50)
                {
                    A4GL_add_to_control_stack(e_formcontrol.FORMCONTROL_AFTER_ROW, this.CurrentField, null, 0);
                    new_state = 25;
                    rval = -1;
                }

                if (this.fcntrl[a].state == 25)
                {
                    Movement ptr=new Movement();
                    FGLFoundField next_field;

                    next_field = this.screenRecord[this.scrLine - 1, CurrentFieldNo];
                    ptr.scrLine = this.scrLine;
                    ptr.arrLine = this.arrLine;
                    ptr.attrib_no = this.CurrentFieldNo;

                    A4GL_add_to_control_stack(e_formcontrol.FORMCONTROL_BEFORE_FIELD, next_field, new Movement(ptr), 0);
                    A4GL_add_to_control_stack(e_formcontrol.FORMCONTROL_BEFORE_ROW, next_field, new Movement(ptr), 0);

                    new_state = 10;
                    rval = -1;
                }

                if (this.fcntrl[a].state == 10)
                {
                    new_state = 0;
                }



            }


            if (this.fcntrl[a].op == e_formcontrol.FORMCONTROL_BEFORE_ROW)
            {

                if (this.fcntrl[a].state == 99)
                {
                    ptr_movement = this.fcntrl[a].parameter;
                    if (ptr_movement.arrLine > this.nRows)
                    {
                        this.nRows = ptr_movement.arrLine;
                        init_arrLine(ptr_movement.arrLine);
                        this.curr_line_is_new = 1;
                    }
                    else
                    {
                        this.curr_line_is_new = 0;
                    }

                    this.scrLine = ptr_movement.scrLine;
                    // A4GL_set_scrLine (ptr_movement.scrLine);

                    this.arrLine = ptr_movement.arrLine;
                    // A4GL_set_arr_curr (ptr_movement.arrLine);


                    new_state = 50;
                    rval = -1;

                    if (A4GL_has_event(e_event.A4GL_EVENT_BEF_ROW) > 0)
                    {
                        rval = A4GL_has_event(e_event.A4GL_EVENT_BEF_ROW);
                    }
                }



                if (this.fcntrl[a].state == 50)
                {
                    ptr_movement = this.fcntrl[a].parameter;

                    if (this.curr_line_is_new > 0)
                    {


                        A4GL_add_to_control_stack(e_formcontrol.FORMCONTROL_BEFORE_INSERT, null, null, 0);
                    }
                    new_state = 25;
                }

                if (this.fcntrl[a].state == 25)
                {
                    new_state = 0;
                }
            }



            if (this.fcntrl[a].op == e_formcontrol.FORMCONTROL_AFTER_ROW)
            {
                new_state = 0;

                if (A4GL_has_event(e_event.A4GL_EVENT_AFT_ROW) > 0)
                    rval = A4GL_has_event(e_event.A4GL_EVENT_AFT_ROW);
            }





            if (this.fcntrl[a].op == e_formcontrol.FORMCONTROL_BEFORE_INSERT)
            {
                if (this.fcntrl[a].state == 99)
                {
                    // We want to do the actual insert here...
                    new_state = 80;

                }

                if (this.fcntrl[a].state == 80)
                {
                    insert_line_in_array();
                    new_state = 50;
                }

                if (this.fcntrl[a].state == 50)
                {			// BEFORE INSERT 
                    new_state = 0;
                    if (A4GL_has_event(e_event.A4GL_EVENT_BEFORE_INSERT) > 0)
                        rval = A4GL_has_event(e_event.A4GL_EVENT_BEFORE_INSERT);
                    else
                    {
                        if (A4GL_has_event(e_event.A4GL_EVENT_BEF_INSERT_DELETE) > 0)
                            rval = A4GL_has_event(e_event.A4GL_EVENT_BEF_INSERT_DELETE);
                    }
                    this.curr_line_is_new = 1;
                }


            }


            if (this.fcntrl[a].op == e_formcontrol.FORMCONTROL_AFTER_INSERT)
            {
                this.curr_line_is_new = 0;
                new_state = 0;
                if (A4GL_has_event(e_event.A4GL_EVENT_AFTER_INSERT) > 0)
                    rval = A4GL_has_event(e_event.A4GL_EVENT_AFTER_INSERT);
                else
                {
                    if (A4GL_has_event(e_event.A4GL_EVENT_AFT_INSERT_DELETE) > 0)
                        rval = A4GL_has_event(e_event.A4GL_EVENT_AFT_INSERT_DELETE);
                }
            }

            if (this.fcntrl[a].op == e_formcontrol.FORMCONTROL_KEY_PRESS)
            {

                if (this.fcntrl[a].state == 99)
                {
                    new_state = 0;
                    rval = -1;
                    if (A4GL_has_event_for_keypress(this.fcntrl[a].extent)>0)
                    {
                        rval = A4GL_has_event_for_keypress(this.fcntrl[a].extent);
                    }
                }
            }


            if (this.fcntrl[a].op == e_formcontrol.FORMCONTROL_BEFORE_FIELD)
            {
       
                if (this.fcntrl[a].state == 99)
                {
                    new_state = 50;
                    ptr_movement = this.fcntrl[a].parameter;
                    this.CurrentFieldNo = ptr_movement.attrib_no;
                    this.arrLine = ptr_movement.arrLine;
                    this.scrLine = ptr_movement.scrLine;
                    this.CurrentField = this.screenRecord[scrLine - 1,CurrentFieldNo];

                    if (A4GL_has_event_for_field(e_event.A4GL_EVENT_BEFORE_FIELD, this.fcntrl[a].field)>0)
                    {
                        rval = A4GL_has_event_for_field(e_event.A4GL_EVENT_BEFORE_FIELD, this.fcntrl[a].field);
                    }
                }


                if (this.fcntrl[a].state == 50)
                {
                    this.CurrentField = this.screenRecord[scrLine - 1,CurrentFieldNo];
                    //A4GL_LL_set_current_field (this.currform->form, arr.CurrentField);
                    new_state = 0;
                }

            }


            if (this.fcntrl[a].op == e_formcontrol.FORMCONTROL_AFTER_FIELD)
            {

                bool ffc_rval;

                ffc_rval = A4GL_form_field_chk_iarr(-1);

                if (ffc_rval)
                {
                    new_state = 0;
                    if (A4GL_has_event_for_field(e_event.A4GL_EVENT_AFTER_FIELD, this.fcntrl[a].field)>0)
                    {
                        rval = A4GL_has_event_for_field(e_event.A4GL_EVENT_AFTER_FIELD, this.fcntrl[a].field);
                    }
                }
                else
                {
                    new_state = 0;
                    A4GL_init_control_stack();
                    rval = -1;
                    return -1;
                }
            }

            if (new_state != 0)
            {
                if (this.fcntrl[a].state == new_state)
                {
                    Program.Show("Internal error - no change in state..");
                }
                this.fcntrl[a].state = new_state;
            }
            else
            {
                if (a != this.fcntrl_cnt - 1)
                {
                    Program.Show("Internal error - bad change in state ");
                    return -1;
                }
                this.fcntrl_cnt--;

            }
            return rval;
        }

        private void insert_line_in_array()
        {
            //throw new Exception("The method or operation is not implemented.");
            doInsert();
        }

        private void init_arrLine(int p)
        {
            //throw new Exception("The method or operation is not implemented.");
        }

        private void delete_line_in_array()
        {
            doDelete();
        }

        private bool A4GL_form_field_chk_iarr(int p)
        {
            return true;
        }

        private int A4GL_has_event_for_keypress(int p)
        {
            foreach (object evt in this_input_array.EVENTS)
            {
                generic_event ge;
                ge = (generic_event)evt;

                if (evt is ONKEY_EVENT)
                {
                    ONKEY_EVENT oke;
                    oke = (ONKEY_EVENT)evt;
                    if (FGLUtils.getKeyCodeFromKeyName(oke.KEY) == p) return Convert.ToInt32(ge.ID);
                }
            }
            return -1;

        }

        private int A4GL_has_event_for_field(e_event e, FGLFoundField fGLFoundField)
        {
            foreach (object evt in this_input_array.EVENTS)
            {
                generic_event ge;
                ge = (generic_event)evt;

                switch (e)
                {
                    case e_event.A4GL_EVENT_BEFORE_FIELD:
                        if (evt is BEFORE_FIELD_EVENT)
                        {
                            BEFORE_FIELD_EVENT bf_evt;
                            bf_evt = (BEFORE_FIELD_EVENT)evt;
                            List<FGLFoundField> ff = mainWin.FindField(bf_evt.FIELD);
                             
                            
                            if (isMatch(bf_evt.FIELD, fGLFoundField)) return Convert.ToInt32(bf_evt.ID);
                            

                            
                        }
                        break;

                    case e_event.A4GL_EVENT_AFTER_FIELD:
                        if (evt is AFTER_FIELD_EVENT)
                        {
                            AFTER_FIELD_EVENT af_evt;
                            af_evt = (AFTER_FIELD_EVENT)evt;

                                if (isMatch(af_evt.FIELD,fGLFoundField)) return Convert.ToInt32(af_evt.ID);
                            
                        }
                        break;
                }
            }
            return -1;
         
        }

        private bool isMatch(string f, FGLFoundField fGLFoundField)
        {
            if (f == fGLFoundField.fullName)
            {
                return true;
            }
            if (f == fGLFoundField.shortName)
            {
                return true;
            }

            return false;

        }

        private void A4GL_init_control_stack()
        {
            int a;
            fcntrl_cnt = 0;
            fcntrl = new formcontrol[10];
            for (a = 0; a < 10; a++)
            {
                fcntrl[a] = new formcontrol();
            }
            
        }

        private int A4GL_has_event(e_event e)
        {
            foreach (object evt in this.this_input_array.EVENTS)
            {
                generic_event ge;
                ge = (generic_event)evt;

                switch (e)
                {
                    case e_event.A4GL_EVENT_AFT_INSERT_DELETE:
                        if (evt is AFTER_INSERT_EVENT) return Convert.ToInt32(ge.ID);
                        if (evt is AFTER_DELETE_EVENT) return Convert.ToInt32(ge.ID);
                        break;

                    case e_event.A4GL_EVENT_AFT_ROW:
                        if (evt is AFTER_ROW_EVENT) return Convert.ToInt32(ge.ID);
                        break;

                    case e_event.A4GL_EVENT_BEF_ROW:
                        if (evt is BEFORE_ROW_EVENT) return Convert.ToInt32(ge.ID);
                        break;

                    case e_event.A4GL_EVENT_AFTER_DELETE:
                        if (evt is AFTER_DELETE_EVENT) return Convert.ToInt32(ge.ID);
                        break;

                    case e_event.A4GL_EVENT_BEFORE_DELETE:
                        if (evt is BEFORE_DELETE_EVENT) return Convert.ToInt32(ge.ID);
                        break;

                    case e_event.A4GL_EVENT_AFTER_INSERT:
                        if (evt is AFTER_INSERT_EVENT) return Convert.ToInt32(ge.ID);
                        break;

                    case e_event.A4GL_EVENT_BEFORE_INSERT:
                        if (evt is BEFORE_INSERT_EVENT) return Convert.ToInt32(ge.ID);
                        break;

                    case e_event.A4GL_EVENT_ON_ACTION:
                        if (evt is ON_ACTION_EVENT) return Convert.ToInt32(ge.ID);
                        break;
                    

                    case e_event.A4GL_EVENT_AFTER_INP:
                        if (evt is AFTER_INPUT_EVENT) return Convert.ToInt32(ge.ID);
                        break;

                    case e_event.A4GL_EVENT_AFTER_INP_CLEAN:
                        Program.Show("Used???");
                        break;
                        
                    default:
                        Console.WriteLine("Ignore : " + e.ToString());
                        break;

                }
            }
            return -1;
        }






        /*
         *  Set up a record for a desired movement...
         */
        void
        A4GL_newMovement_single(int scrLine, int arrLine, int attrib, char why)
        {
            FGLFoundField last_field = null;
            FGLFoundField next_field = null;
            //struct struct_scr_field *f;


            // Sanity check the movements....

            if (arrLine < 1)
            {

                A4GL_newMovement_single( scrLine, 1, attrib, why);
                return;
            }

            if (scrLine > arrLine)
            {
                scrLine = arrLine;
            }

            if (attrib < 0)
            {
                // attempt to move too far to the left
                // In informix - this results in just going up a line - still on field 0
                A4GL_newMovement_single(scrLine, arrLine - 1, 0, why);
                return;
            }


            if (scrLine > scrRecLines)
            {
                scrLine = scrRecLines;
                A4GL_newMovement_single(scrLine, arrLine, attrib, why);
                return;
            }

            if (scrLine <= 0)
            {
                scrLine = 1;
                A4GL_newMovement_single(scrLine, arrLine, attrib, why);
                return;
            }

            if ((arrLine + 1) - scrLine < 0)
            {
                scrLine = arrLine - scrLine + 1;
                A4GL_newMovement_single(scrLine, arrLine, attrib, why);
                return;
            }



            if (attrib >= this.nCols && attrib >= 0)
            {
                // Too far over to the right - wrap around to the start of the next line
                A4GL_newMovement_single(scrLine + 1, arrLine + 1, 0, why);
                return;
            }



            if (arrLine > maxRows)
            {				// Attempting to move off the bottom of the array...
                mainWin.setErrorTextFromFieldValidation("ARR_DIR_MSG");
                A4GL_newMovement_single(scrLine, nRows, CurrentFieldNo, why);
                // Do nothing at all...
                return;
            }


            if (arrLine > nRows)
            {				// Attempting to move off the bottom of the current set_count
                // @todo - check see if we need to do this here or later...
                if (!allowInsert || noNewLines)
                {

                    // Do nothing at all...
                    return;		// NO NEW ROWS....
                }
            }


            if (scrLine > 0)
            {
                last_field = CurrentField;
            }
            else
            {
                last_field = null;
            }

            next_field = screenRecord[scrLine - 1, attrib];
            if (next_field != CurrentField)
            {
                if (CurrentField != null)
                {
                    if (!CurrentField.fglField.validateField())
                    {
                        return;
                        //MessageBox.Show("Invalid field contents");
                    }
                }
            }

            if (next_field.fglField.NoEntry || (next_field.fglField.datatype == FGLUtils.FGLDataTypes.DTYPE_SERIAL))
            {
                while (true)
                {

                    next_field = screenRecord[0, attrib];

                    if (next_field.fglField.NoEntry)
                    {

                        if (why == 'R' || why == '0' || why == 'D' || why == 'Q')
                            attrib++;
                        else
                            attrib--;

                        if (attrib >= nCols && attrib >= 0)
                        {
                            attrib = 0;
                            scrLine++;
                            arrLine++;
                            if (arrLine > nRows)
                            {		// Attempting to move off the bottom of the array...
                                mainWin.setErrorTextFromFieldValidation("ARR_DIR_MSG");
                                A4GL_newMovement_single(scrLine - 1, arrLine - 1, 0, why);
                                return;
                            }
                        }

                        if (attrib < 0)
                        {
                            attrib = 0;	//arr->srec->attribs.attribs_len;
                            why = '0';
                            scrLine--;
                            arrLine--;
                        }
                    }
                    else
                    {
                        A4GL_newMovement_single(scrLine, arrLine, attrib, why);	// So keep going...
                        return;
                    }
                }
            }


            if (arrLine != this.arrLine)
            {
                Movement ptr = new Movement();

                if (!A4GL_double_chk_line(scrLine - 1, why))
                {			// somethings wrong with our current line
                    return;
                }
                copyFieldData();
                ptr.scrLine = scrLine;
                ptr.arrLine = arrLine;
                ptr.attrib_no = attrib;

                A4GL_add_to_control_stack(e_formcontrol.FORMCONTROL_BEFORE_FIELD, next_field, new Movement(ptr),0);
                A4GL_add_to_control_stack(e_formcontrol.FORMCONTROL_BEFORE_ROW, next_field, new Movement(ptr),0);

                if (last_field !=null || why == 'Q')
                {
                    A4GL_add_to_control_stack(e_formcontrol.FORMCONTROL_AFTER_ROW, last_field, null, 0);
                    if (curr_line_is_new > 0)
                    {
                        A4GL_add_to_control_stack(e_formcontrol.FORMCONTROL_AFTER_INSERT, last_field, null, 0);
                    }
                    curr_line_is_new = 0;

                    if (last_field != null)
                    {
                        A4GL_add_to_control_stack(e_formcontrol.FORMCONTROL_AFTER_FIELD, last_field, null, 0);
                    }

                }
               // redisplay_arr(true);
                //if (scrLine > 0)
               // {
               //     setFocusToCurrentRow();
               // }
            }
            else
            {
                Movement ptr=new Movement();
                Movement ptr_x;
          
                ptr.scrLine = scrLine;
                ptr.arrLine = arrLine;
                ptr.attrib_no = attrib;
                ptr_x = new Movement(ptr);
                A4GL_add_to_control_stack(e_formcontrol.FORMCONTROL_BEFORE_FIELD, next_field, ptr_x, 0);

                if (last_field != null)
                {
                    A4GL_add_to_control_stack(e_formcontrol.FORMCONTROL_AFTER_FIELD, last_field, null, 0);
                }
            }
        }

        private bool A4GL_double_chk_line(int p, char why)
        {
            if (arrLine == -1) return true;
     
            return true;
        }



        internal void setArrLine(int p)
        {
            if (arrLine != p)
            {
                A4GL_newMovement_single(scrLine, p, 0, 'S');
            }
            //checkControlStack();
        }

        internal void setScrLine(int p)
        {
            // Does nothing in GUI
        }
    }



}