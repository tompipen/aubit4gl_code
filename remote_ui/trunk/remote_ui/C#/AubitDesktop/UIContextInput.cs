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
    class UIInputContext : UIContext
    {
        private event UIEventHandler EventTriggered;

    
        private bool _contextIsActive;
        private FGLFoundField setCurrentField;
        private FGLFoundField CurrentField;
        private FGLApplicationPanel mainWin;
        private List<ONKEY_EVENT> KeyList;

        private List<FGLFoundField> activeFields;

        private List<BEFORE_FIELD_EVENT> beforeFieldList;
        private List<AFTER_FIELD_EVENT> afterFieldList;
        private List<ON_ACTION_EVENT> onActionList;
 

        public bool contextIsActive()
        {
            return _contextIsActive;
        }


        public UIInputContext(FGLApplicationPanel f, INPUT i)
        {
            KeyList = new List<ONKEY_EVENT>();
            KeyList.Clear();
            afterFieldList = new List<AFTER_FIELD_EVENT>();
            beforeFieldList = new List<BEFORE_FIELD_EVENT>();
            onActionList = new List<ON_ACTION_EVENT>();
            setCurrentField = null;
            CurrentField = null;
            foreach (object evt in i.EVENTS)
            {
                if (evt is ONKEY_EVENT)
                {
                    ONKEY_EVENT e;
                    e = (ONKEY_EVENT)evt;
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
                MessageBox.Show("Unhandled Event for INPUT");
            }

            mainWin = f;
            
            activeFields = f.FindFields(i.FIELDLIST);
            activeFields[0].fglField.setFocus();
            
        }



        public void NavigateToTab()
        {
        }

        public void NavigateAwayTab()
        {
        }

        public string getSyncValues()
        {
            string s;
            s = "<SYNCVALUES>";
            foreach (FGLFoundField i in activeFields)
            {
                s += "<SYNCVALUE FIELDNAME=\"" + i.useName + "\">" + System.Security.SecurityElement.Escape(i.fglField.Text) + "</SYNCVALUE>";
            }
            s += "</SYNCVALUES>";
            return s;
        }

        public string getAcceptString()
        {

            if (fieldsAreAllOk())
            {
                return "<TRIGGERED ID=\"ACCEPT\" LASTKEY=\"ACCEPT\">" + getSyncValues() + "</TRIGGERED>";
            }
            else
            {
                return null;
            }
        }

        private bool fieldsAreAllOk()
        {
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
            return "<TRIGGERED ID=\"" + ID + "\" "+cfield+" LASTKEY=\""+mainWin.lastKey+"\""+">";
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
                TriggeredText=getTriggeredTag(ID) + getSyncValues() + "</TRIGGERED>";
            }

            this.EventTriggered(source, ID, TriggeredText);

            foreach (FGLFoundField f in activeFields) {
                if (f.fglField==source) {
                    CurrentField = f;
                    break;
                }
            }
            
        }





        public void onActionTriggered(object source, string ID, string TriggeredText)
        {
            if (TriggeredText == "")
            {
                TriggeredText = getTriggeredTag(ID) + getSyncValues() + "</TRIGGERED>";
            }
            if (this.EventTriggered != null)
            {
                this.EventTriggered(source, ID, TriggeredText);
            }
            else
            {
                MessageBox.Show("Warning - might have missed a before field/after field");
            }
        }


        void inputFieldValidationHandler(object source, string failedText, out bool ignore)
        {
            ignore = false;
            mainWin.setErrorTextFromFieldValidation(failedText);
        }


        void inputGotFocus(object source,string comment)
        {
            mainWin.CommentText = comment;
        }

        public void ActivateContext(UIEventHandler UIInputContext_EventTriggered, VALUE[] values, ROW[] rows)
        {
            int cnt = 0;
            mainWin.SetContext(FGLContextType.ContextNone);

            mainWin.SetContext(FGLContextType.ContextInput, activeFields, this);

            mainWin.setActiveToolBarKeys(KeyList,true);
            this.EventTriggered = UIInputContext_EventTriggered;

            foreach (FGLFoundField f in activeFields) {
                f.fglField.fieldValidationFailed = inputFieldValidationHandler;
                f.fglField.onGotFocus = inputGotFocus;
            }


            if (setCurrentField != null) // Next field has been registered..
            {
                CurrentField = setCurrentField;
                CurrentField.fglField.setFocus();
                setCurrentField = null;
            }

            if (CurrentField==null) {
                CurrentField = activeFields[0];
                CurrentField.fglField.setFocus();
            }


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

                foreach (FGLFoundField ffield in ff) {
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


            // We should always get a set of values
            // if we dont - then it must be an INPUT without the WITHOUT DEFAULTS
            // and this must be the first time around - so we should set up the defaults...

            foreach (FGLFoundField f in activeFields) {
                if (values == null)
                {
                    f.fglField.Text = f.fglField.defaultValue;
                }
                else
                {
                    f.fglField.Text = values[cnt++].Text;
                }

                
                
            }

            if (!_contextIsActive)
            {
                _contextIsActive = true;
            }

            
            
        }




        public void DeactivateContext()
        {

            mainWin.setActiveToolBarKeys(null,false);
            mainWin.SetContext(FGLContextType.ContextNone);
            _contextIsActive = false;
            EventTriggered = null;
            mainWin.CommentText = "";
        }

        public void FreeContext()
        {
            //mainWin.setActiveToolBarKeys(null);
            _contextIsActive = false;
            EventTriggered = null;
            
        }
    }
}
