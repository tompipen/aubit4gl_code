using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Forms;

namespace AubitDesktop2
{
        class UIPromptContext : UIContext
        {
            //public event UIEventHandler EventTriggered;
            private bool _contextIsActive;
            private FGLApplicationPanel mainWin;
            private List<ONKEY_EVENT> KeyList;
            private PromptWindow promptForm;
            private string promptStyle;
            public bool contextIsActive()
            {
                return _contextIsActive;
            }


            public string getAcceptString()
            {
                // Not needed for a prompt...
                throw new NotImplementedException();
                
            }

            public UIPromptContext(FGLApplicationPanel f, PROMPT p)
            {
                //Label l;
                //TextBox tb;
                bool charMode;
                KeyList = new List<ONKEY_EVENT>();
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

                promptForm = new PromptWindow(p.TEXT, Convert.ToInt32(p.FIELDATTRIBUTE), Convert.ToInt32(p.PROMPTATTRIBUTE), promptStyle, charMode,p.ATTRIB_TEXT);

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

                    MessageBox.Show("Unhandled Event for PROMPT");
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
            }

            public void NavigateAwayTab()
            {
            }

            public void ActivateContext(UIEventHandler UIPromptContext_EventTriggered, VALUE[] values)
            {
                promptForm.EventTriggered += new UIEventHandler(UIPromptContext_EventTriggered);
                promptForm.SetPromptFocus();
                mainWin.setActiveToolBarKeys(KeyList,false);
                
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
                mainWin.setActiveToolBarKeys(null,false);

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
                    promptForm.Dispose();
                    promptForm = null;
                }
                _contextIsActive = false;
              
                
            }


        }



}
