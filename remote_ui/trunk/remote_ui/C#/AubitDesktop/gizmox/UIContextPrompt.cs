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

namespace AubitDesktop
{
        class UIPromptContext : UIContext
        {
            //public event UIEventHandler EventTriggered;
            private bool _contextIsActive;
            private FGLApplicationPanel mainWin;
            private List<ONKEY_EVENT> KeyList;
            private List<ON_ACTION_EVENT> onActionList;
            private PromptWindow promptForm;
            private string promptStyle;
            public bool contextIsActive()
            {
                return _contextIsActive;
            }


            public void toolBarAcceptClicked()
            {
                // Does nothing for a menu....
            }

            

            public bool useKeyPress(KeyEventArgs ke)
            {
                return false;
            }


            public bool externallyTriggeredID(string ID)
            {
                //Program.Show("Here");
                return false;
            }

            public UIPromptContext(FGLApplicationPanel f, PROMPT p)
            {
                //Label l;
                //TextBox tb;
                bool charMode;
                KeyList = new List<ONKEY_EVENT>();
                onActionList = new List<ON_ACTION_EVENT>();
                mainWin = f;


                
                promptStyle = p.ATTRIB_STYLE;
                if (promptStyle == "")
                {
                    promptStyle = "NORMAL";
                }

                if (p.CHARMODE == "0")
                {
                    charMode = false;
                }
                else
                {
                    charMode = true;
                }

                promptForm = new PromptWindow(p.TEXT, Convert.ToInt32(p.FIELDATTRIBUTE), Convert.ToInt32(p.PROMPTATTRIBUTE), promptStyle, charMode,p.ATTRIB_TEXT,this);

                foreach (object evt in p.EVENTS)
                {
                    if (evt is ONKEY_EVENT)
                    {
                        ONKEY_EVENT e;
                        e = (ONKEY_EVENT)evt;
                        KeyList.Add(e);
                        promptForm.AddKeyWatch(Convert.ToInt32(e.ID), e.KEY);
                        //f.AddToolBarKey(e.KEY, e.ID);
                        continue;
                    }
                    if (evt is ON_ACTION_EVENT)
                    {
                        ON_ACTION_EVENT e;
                        e = (ON_ACTION_EVENT)evt;
                        onActionList.Add(e);
                    }

                    Program.Show("Unhandled Event for PROMPT");
                }

                if (promptStyle == "NORMAL")
                {
                    Control promptPanel;
                    promptPanel = promptForm.GetPromptControls();
                    f.setPrompt(promptPanel);
                    
                }
            }


            public void setNextField(string fieldName)
            {
                throw new ApplicationException("Prompts cant do nextfields");
            }

            public void NavigateToTab()
            {
                mainWin.setActiveToolBarKeys(KeyList, onActionList, false);
            }

            public void NavigateAwayTab()
            {
            }



            public void ActivateContext(UIEventHandler UIPromptContext_EventTriggered, VALUE[] values, ROW[] rows)
            {
                promptForm.EventTriggered += new UIEventHandler(UIPromptContext_EventTriggered);
                promptForm.SetPromptFocus();
                mainWin.setActiveToolBarKeys(KeyList,onActionList, false);
                
                if (!_contextIsActive)
                {
                    _contextIsActive = true;
                }

                if (promptStyle == "WINDOW")
                {
                    promptForm.ShowDialog();
                }
                else
                {
                    Control promptPanel;
                    promptPanel = promptForm.GetPromptControls();
                    promptPanel.Enabled = true;
                    mainWin.ActivatePrompt(UIPromptContext_EventTriggered);
                }
            }



            public void DeactivateContext()
            {
                mainWin.setActiveToolBarKeys(null,null,false);

                _contextIsActive = false;
                promptForm.clrEventTrigger();
                if (promptStyle == "NORMAL")
                {
                    Control promptPanel;
                    promptPanel = promptForm.GetPromptControls();
                    promptPanel.Enabled = false;
                }
            }

            public void FreeContext()
            {
                promptForm.clrEventTrigger();
                //mainWin.setActiveToolBarKeys(null,false);
                if (promptStyle == "WINDOW")
                {
                    
                    promptForm.Dispose();
                }
                else
                {
                    mainWin.RemovePrompt(promptForm.GetPromptControls());
                    //promptForm.Dispose();
                    promptForm = null;
                }
                _contextIsActive = false;
                              
            }
        }
}
