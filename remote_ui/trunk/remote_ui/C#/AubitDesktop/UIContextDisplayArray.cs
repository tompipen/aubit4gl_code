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
        //private int nextRow;

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
            }
            else
            {
                // Tried to move off the bottom of the display array...
                mainWin.setErrorTextFromFieldValidation("ARR_DIR_MSG");
            }
        }
        

        public void upkeyPressed()
        {
            mainWin.clrErrorTextFromFieldValidation();
            if (arrLine > 1)
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
            }
            else
            {
                // Tried to move off the top...
                mainWin.setErrorTextFromFieldValidation("ARR_DIR_MSG");
            }
        }

        public void pgUpkeyPressed()
        {

        }

        public void pgDownkeyPressed()
        {

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
            this.lastarrLine = -1;
            this.nRows = Convert.ToInt32(p.ARRCOUNT);
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
            setFocusToCurrentRow();
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
            setFocusToCurrentRow();
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

        public void ActivateContext(UIEventHandler UIDisplayArrayContext_EventTriggered, VALUE[] values)
        {
            mainWin.SetContext("");
            mainWin.SetContext("DISPLAYARRAY", activeFields, this);
            mainWin.setActiveToolBarKeys(KeyList, true,true,false);
            redisplay_arr(true);
            setFocusToCurrentRow();
            this.EventTriggered = UIDisplayArrayContext_EventTriggered;

            if (!_contextIsActive)
            {
                _contextIsActive = true;
            }
        }



        public void DeactivateContext()
        {
            mainWin.setActiveToolBarKeys(null, false);
            
            mainWin.SetContext("");
            
            EventTriggered = null;
            _contextIsActive = false;
           
        }

        public void FreeContext()
        {
            _contextIsActive = false;
        }


    }



}