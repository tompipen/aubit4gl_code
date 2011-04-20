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
    class UIConstructContext : UIContext
    {
        private event UIEventHandler EventTriggered;
        private bool _contextIsActive;
        private FGLFoundField setCurrentField;
        private FGLFoundField _currentField;
        private bool careAboutFocus;
        private bool isBeforeInput;

        private FGLFoundField CurrentField
        {
            get
            {
                return _currentField;
            }
            set
            {
                _currentField = value;
            }
        }

        private FGLApplicationPanel mainWin;
        private List<ONKEY_EVENT> KeyList;

        private List<FGLFoundField> activeFields;

        private List<BEFORE_FIELD_EVENT> beforeFieldList;
        private List<AFTER_FIELD_EVENT> afterFieldList;
        private List<ON_ACTION_EVENT> onActionList;
        private COLUMN []constructColumnList ;


        List<string> PendingEvents;




        public bool contextIsActive()
        {
            return _contextIsActive;
        }

        public bool useKeyPress(KeyEventArgs ke)
        {
            return false;
        }

        private void sendTrigger(string ID)
        {
            

            if (this.EventTriggered != null)
            {
                this.EventTriggered(null, ID, getTriggeredTag(ID), this);
                this.EventTriggered = null;
            }
            else
            {
                PendingEvents.Add(ID);
            }
        }

        public bool externallyTriggeredID(string ID)
        {
            switch (ID)
            {
                case "ACCEPT": toolBarAcceptClicked(); return true;
                // INTERRUPT can pass through - we dont mind ;-)
            }
            sendTrigger(ID);
            return true;
        }

        public UIConstructContext(FGLApplicationPanel f, CONSTRUCT c)
        {
            bool haveAccept = false;
            bool haveInterrupt = false;
            KeyList = new List<ONKEY_EVENT>();
            KeyList.Clear();
            afterFieldList = new List<AFTER_FIELD_EVENT>();
            beforeFieldList = new List<BEFORE_FIELD_EVENT>();
            onActionList = new List<ON_ACTION_EVENT>();
            setCurrentField = null;
            CurrentField = null;
            PendingEvents = new List<string>();
            isBeforeInput = true;

           
            foreach (object evt in c.EVENTS)
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
                    KeyList.Add(e);
                    continue;
                }

                if (evt is BEFORE_FIELD_EVENT)
                {
                    BEFORE_FIELD_EVENT e;
                    e = (BEFORE_FIELD_EVENT)evt;
                    beforeFieldList.Add(e);
                    continue;
                }

                if (evt is AFTER_FIELD_EVENT)
                {
                    AFTER_FIELD_EVENT e;
                    e = (AFTER_FIELD_EVENT)evt;
                    afterFieldList.Add(e);
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
                    //Just ignore it...
                    continue;
                }
                Program.Show("Unhandled Event for CONSTRUCT");
            }

            if (!haveAccept)
            {
                KeyList.Add(new ONKEY_EVENT("ACCEPT"));

            }
            if (!haveInterrupt)
            {

                
                KeyList.Add(new ONKEY_EVENT("INTERRUPT"));
            }

            mainWin = f;

            activeFields = f.FindFields(c.FIELDLIST);
            if (activeFields.Count != c.COLUMNS.Length)
            {
                Program.Show("Field count mismatch in CONSTRUCT");
                Application.Exit();
                constructColumnList = null;
            }
            else
            {
                constructColumnList = c.COLUMNS;
            }
            foreach (FGLFoundField fld in activeFields)
            {
                fld.fglField.Text = "";
            }
            activeFields[0].fglField.setFocus();

        }



        public void NavigateToTab()
        {
            mainWin.setActiveToolBarKeys(KeyList,onActionList); //, false);
        }

        public void NavigateAwayTab()
        {
            
        }

        public string getSyncValues()
        {
            string s;
            s = "<SVS>";
            foreach (FGLFoundField i in activeFields)
            {
                s += "<SV FN=\"" + i.useName + "\""+ " FT=\""+(int)i.fglField.datatype+"\">" + System.Security.SecurityElement.Escape(i.fglField.Text) + "</SV>";
            }
            s += "</SVS>";
            return s;
        }

        public void toolBarAcceptClicked()
        {
            // Check the current field

            if (fieldsAreAllOk())
            {
                if (CurrentField.fglField.afterFieldID != "")
                {
                    sendTrigger(CurrentField.fglField.afterFieldID);
                }

                sendTrigger("ACCEPT");
            }
        }


        private bool fieldsAreAllOk()
        {
            System.ComponentModel.CancelEventArgs ce;
            ce = new System.ComponentModel.CancelEventArgs();
            ce.Cancel = false;
            foreach (FGLFoundField f in activeFields)
            {
                f.fglField.t_Validating(f, ce);
                if (ce.Cancel)
                {
                    CurrentField = f;

                    CurrentField.fglField.setFocus();
                    return false;
                }
            }
            return true;
      
        }


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

            if (ID == "ACCEPT")
            {
                return "<TRIGGERED ID=\"ACCEPT\" LASTKEY=\"ACCEPT\">" + getSyncValues() + "</TRIGGERED>";
            }
            else
            {
                return "<TRIGGERED ID=\"" + ID + "\" " + cfield + " LASTKEY=\"" + mainWin.LastKey + "\"" + ">" + getSyncValues() + "</TRIGGERED>";
            }

        }



        public void setNextField(string fieldName)
        {
            foreach (FGLFoundField f in activeFields)
            {
                if (f.isField(fieldName))
                {
                    setCurrentField = f;
                }
            }
            PendingEvents.Clear();
        }




        public void ActionFieldTriggered(object source, string ID, string TriggeredText, UIContext u)
        {
            foreach (FGLFoundField f in activeFields)
            {
                if (f.fglField == source)
                {
                    CurrentField = f;
                    break;
                }
            }

            if (ID != "")
            {
                sendTrigger(ID);
            }


        }





        public void onActionTriggered(object source, string ID, string TriggeredText, UIContext u)
        {

            sendTrigger(ID);
        }


        void inputFieldValidationHandler(object source, string failedText, out bool ignore)
        {
            ignore = false;
            mainWin.setErrorTextFromFieldValidation(failedText);
        }


        void inputGotFocus(object source, string comment)
        {
            bool setField = false;


            FGLFoundField field = null;


            if (!careAboutFocus) return;


            foreach (FGLFoundField f in activeFields)
            {
                if (f.fglField == source)
                {
                    field = f;
                    break;
                }
            }

            mainWin.CommentText = comment;

            if (CurrentField == field) return;
            if (field == setCurrentField) return;

            if (CurrentField != null)
            {
                if (CurrentField.fglField.afterFieldID != "")
                {
                    sendTrigger(CurrentField.fglField.afterFieldID);
                    setField = true;
                }
            }

            CurrentField = field;


            if (CurrentField != null)
            {
                if (CurrentField.fglField.beforeFieldID != "")
                {
                    setField = true;
                    sendTrigger(CurrentField.fglField.beforeFieldID);
                }
            }

            if (setField)
            {
                // The context will be deactivated - so we need to say where we're going next...
                setCurrentField = field;
            }

        }



        public void ActivateContext(UIEventHandler UIInputContext_EventTriggered, V[] values, ROW[] rows)
        {
            int cnt = 0;
            int tstop = 0;

            careAboutFocus = false;

            Console.WriteLine("Activating context..");

            if (!_contextIsActive)
            {
                _contextIsActive = true;
            }
            // We should always get a set of values


            foreach (FGLFoundField f in activeFields)
            {
                Console.WriteLine(f.fullName);
                if (values == null)
                {
                    //
                }
                else
                {
                    if (f.fglField.Text == "" || true)
                    {
                        f.fglField.Text = values[cnt++].Text;
                    }
                    else
                    {
                        cnt++;
                    }

                }
                f.fglField.tabIndex = tstop++;
                f.fglField.afterFieldID = "";
                f.fglField.beforeFieldID = "";
                f.fglField.onActionID = "";
            }

            this.EventTriggered = UIInputContext_EventTriggered;
            if (PendingEvents.Count > 0)
            {
                string s = PendingEvents[0];
                PendingEvents.RemoveAt(0);
                sendTrigger(s);
                return;
            }


            mainWin.SetContext(FGLContextType.ContextConstruct, activeFields, this, KeyList, onActionList, UIInputContext_EventTriggered);
            mainWin.setActiveToolBarKeys(KeyList,onActionList); //, true);



            int fieldCnt = 0;
            foreach (FGLFoundField f in activeFields)
            {
                
                f.fglField.fieldValidationFailed = inputFieldValidationHandler;
                f.fglField.onGotFocus = inputGotFocus;
                f.fglField.onUIEvent = onActionTriggered;
                if (constructColumnList!=null) {
                    f.fglField.constructName = constructColumnList[fieldCnt++].NAME;
                }

            }


            if (setCurrentField != null) // Next field has been registered..
            {

                CurrentField = setCurrentField;

                CurrentField.fglField.setFocus();
                setCurrentField = null;

            }


            if (CurrentField == null)
            {
                CurrentField = activeFields[0];
                CurrentField.fglField.setFocus();
            }

            CurrentField.fglField.setFocus();


            //mainWin.CommentText = CurrentField.fglField.comment;


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

                    ffield.fglField.Enabled = true;
                    ffield.fglField.ContextType = FGLContextType.ContextConstruct;
                }

            }
            #endregion







            if (isBeforeInput)
            {
                if (CurrentField.fglField.beforeFieldID != "")
                {
                    sendTrigger(CurrentField.fglField.beforeFieldID);
                }

                isBeforeInput = false;
            }

            careAboutFocus = true;

        }




        public void DeactivateContext()
        {
            careAboutFocus = false;
            EventTriggered = null;
            if (_contextIsActive)
            {
                mainWin.setActiveToolBarKeys(null,null); //, false);
                mainWin.SetContext(FGLContextType.ContextNone);
                _contextIsActive = false;
                EventTriggered = null;
                mainWin.CommentText = "";
            }
        }

        public void FreeContext()
        {
            //mainWin.setActiveToolBarKeys(null);
            _contextIsActive = false;
            EventTriggered = null;

        }
    }
}
