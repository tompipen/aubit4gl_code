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
        class UIMiscContext : UIContext
        {
            public enum MiscContextType {
                    MiscContextWinquestion,
                    MiscContextGetKey
            };

            private MiscContextType contextType;
            private WINQUESTION wq;
            private GETKEY gk;
            FGLApplicationPanel appPanel;
            private event UIEventHandler EventTriggered;


            private bool _contextIsActive;
            public bool contextIsActive()
            {
                return _contextIsActive;
            }


            public void toolBarAcceptClicked()
            {
                // Does nothing for this context
            }

           


            public bool useKeyPress(KeyEventArgs ke)
            {
                if (contextType == MiscContextType.MiscContextGetKey)
                {
                    string lastKey=null;
                    if (ke.KeyValue >= 1 && ke.KeyValue <= 255)
                    {
                        if (!ke.Alt)
                        {
                            lastKey = ke.KeyValue.ToString();
                        }
                    }
                        if (lastKey==null) {
                    lastKey = FGLUtils.decodeKeycode(ke.Control, ke.Shift, ke.Alt, ke.KeyCode);
                        }
                 //   MessageBox.Show("KEYVALYE : "+ke.KeyValue);
                    appPanel.setLastKey(lastKey);
                    //appsetLastKeyInApplication(lastKey);
                    lastKey=FGLUtils.getKeyCodeFromKeyName(lastKey);
                    ke.SuppressKeyPress = true;

                    this.EventTriggered( null, "ACCEPT", "<TRIGGERED ID=\"ACCEPT\" LASTKEY=\""+lastKey+"\"/>",this);
                    return true;
                }
                return false;
            }


            public UIMiscContext(FGLApplicationPanel f, WINQUESTION p)
            {
                wq = p;
                appPanel = f; 
                contextType = MiscContextType.MiscContextWinquestion;
            }

            public UIMiscContext(FGLApplicationPanel f, GETKEY p)
            {
                gk = p;
                appPanel = f;
                contextType = MiscContextType.MiscContextGetKey;
            }

            public void setNextField(string fieldName)
            {
                throw new ApplicationException("Cant cant do nextfields");
            }

            public void NavigateToTab()
            {
            }

            public void NavigateAwayTab()
            {
            }



            public void ActivateContext(UIEventHandler UIContext_EventTriggered, VALUE[] values, ROW[] rows)
            {
                EventTriggered = UIContext_EventTriggered;
                if (!_contextIsActive)
                {
                    _contextIsActive = true;
                }

                switch (contextType)
                {
                    case MiscContextType.MiscContextWinquestion:
                        string r=AubitMessageBox.Show(wq);
                        r = r.Trim();
                        string rd = "ACCEPT";
                        switch (r.ToUpper())
                        {
                            case "YES": rd = "-101"; break;
                           
                            case "IGNORE": rd = "-120"; break;
                            case "CANCEL": rd = "-118"; break;
                            case "OK": rd = "-119"; break;
                            case "RETRY": rd = "-121"; break;
                            case "NO": rd = "-102"; break;
                        }

                        if (rd == "ACCEPT")
                        { // We can't decode it do an ID - send it back as the 'LASTKEY'...
                            this.EventTriggered(null, r, "<TRIGGERED ID=\"ACCEPT\" LASTKEY=\"" + r + "\"/>",this);
                        }
                        else
                        {
                            this.EventTriggered(null, r, "<TRIGGERED ID=\"" + rd + "\"/>",this);
                        }
                        this.DeactivateContext();
                        break;
                }
            }

           

            public void DeactivateContext()
            {
                _contextIsActive = false;
            }

            public void FreeContext()
            {
                _contextIsActive = false;   
            }
        }
}
