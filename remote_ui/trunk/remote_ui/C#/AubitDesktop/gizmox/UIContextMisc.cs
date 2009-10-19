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
    class UIMiscContext : UIContext
    {
        public enum MiscContextType
        {
            MiscContextWinquestion,
            MiscContextGetKey,
            MiscContextFrontCall
        };


        private MiscContextType contextType;
        private WINQUESTION wq;
        private GETKEY gk;
        private FRONTCALL frontCall;
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



        public bool externallyTriggeredID(string ID)
        {
            return false;
        }

        public bool useKeyPress(KeyEventArgs ke)
        {
            if (contextType == MiscContextType.MiscContextGetKey)
            {
                string lastKey = null;
                if (ke.KeyValue >= 1 && ke.KeyValue <= 255)
                {
                    if (!ke.Alt)
                    {
                        lastKey = ke.KeyValue.ToString();
                    }
                }
                if (lastKey == null)
                {
                    lastKey = FGLUtils.decodeKeycode(ke.Control, ke.Shift, ke.Alt, ke.KeyCode);
                }
                //   Program.Show("KEYVALYE : "+ke.KeyValue);
                appPanel.setLastKey(lastKey);
                //appsetLastKeyInApplication(lastKey);
                lastKey = FGLUtils.getKeyCodeFromKeyName(lastKey).ToString();

                this.EventTriggered(null, "ACCEPT", "<TRIGGERED ID=\"ACCEPT\" LASTKEY=\"" + lastKey + "\"/>", this);
                return true;
            }
            return false;
        }

        public UIMiscContext(FGLApplicationPanel f, FRONTCALL p)
        {
            frontCall = p;
            appPanel = f;
            contextType = MiscContextType.MiscContextFrontCall;

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
            appPanel.setActiveToolBarKeys(null, null, false);
        }

        public void NavigateAwayTab()
        {
        }




        private string doFrontCall(string module, string name, VALUE[] values, string expectReturn)
        {
            int numberOfReturnValues = 0; // total number of return values expected
            string[] retStrings = null;        // string array to store the return values

            string rval;                // string containing the complete TRIGGERED...

            if (expectReturn != null)
            {
                try
                {
                    numberOfReturnValues = Convert.ToInt32(expectReturn);
                }
                catch { }
            }

            if (numberOfReturnValues > 0)
            {
                retStrings = new string[numberOfReturnValues];
                for (int a = 0; a < numberOfReturnValues; a++)
                {
                    retStrings[a] = "";
                }
            }



            // Code to actually set 'retStrings' based on whats been called!

            switch (module)
            {
                case "INTERNAL":

                    if (name.StartsWith("ui.combobox."))
                    {
                        retStrings = ui_combo_frontcall(appPanel, name, values, retStrings);
                        if (retStrings != null)
                        {
                            break;
                        }
                    }


                    MessageBox.Show("Unhandled INTERNAL :" + name + " in frontcall");
                    break;

                default:
                    MessageBox.Show("Unhandled module :" + module + " in frontcall");
                    break;
            }




            rval = "<TRIGGERED ID=\"FRONTCALLRETURN\">";
            if (numberOfReturnValues > 0 && retStrings != null)
            {
                rval += "<SYNCVALUES>";
                for (int a = 0; a < numberOfReturnValues; a++)
                {
                    rval += "<SYNCVALUE>" + retStrings[a] + "</SYNCVALUE>";
                }
                rval += "</SYNCVALUES>";
            }
            rval += "</TRIGGERED>";
            return rval;
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
                case MiscContextType.MiscContextFrontCall:
                    {
                        string rval = doFrontCall(frontCall.MODULE, frontCall.NAME, frontCall.VALUES, frontCall.EXPECT);
                        this.EventTriggered(null, "FRONTCALLRETURN", rval, this);
                    }
                    break;


                case MiscContextType.MiscContextWinquestion:
                    string r = AubitMessageBox.Show(wq);
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
                        this.EventTriggered(null, r, "<TRIGGERED ID=\"ACCEPT\" LASTKEY=\"" + r + "\"/>", this);
                    }
                    else
                    {
                        this.EventTriggered(null, r, "<TRIGGERED ID=\"" + rd + "\"/>", this);
                    }
                    //this.DeactivateContext();
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




        #region FRONTCALLS

        private static string[] ui_combo_frontcall(FGLApplicationPanel appPanel, string name, VALUE[] values, string[] retStrings)
        {
            switch (name)
            {
                case "ui.combobox.forname":
                    {
                        List<FGLFoundField> f = appPanel.FindField(values[0].Text);
                        if (f == null) return null;
                        if (f.Count == 0) return null;
                        retStrings[0] = f[0].fullName;
                        return retStrings;
                    }


                case "ui.combobox.additem":
                    {
                        List<FGLFoundField> f = appPanel.FindField(values[0].Text);
                        if (f == null) return null;
                        if (f.Count == 0) return null;
                        if (f[0].fglField is FGLComboListBoxFieldWidget)
                        {
                            FGLComboListBoxFieldWidget widget = (FGLComboListBoxFieldWidget)f[0].fglField;
                            widget.ui_combobox_additem(values[1].Text, values[2].Text);
                        }
                        return null; // no return values...
                    }

                case "ui.combobox.clear":
                    {
                        List<FGLFoundField> f = appPanel.FindField(values[0].Text);
                        if (f == null) return null;
                        if (f.Count == 0) return null;
                        if (f[0].fglField is FGLComboListBoxFieldWidget)
                        {
                            FGLComboListBoxFieldWidget widget = (FGLComboListBoxFieldWidget)f[0].fglField;
                            widget.ui_combobox_clear();
                            return null;
                        }
                        break;
                    }

                case "ui.combobox.removeitem":
                    {
                        List<FGLFoundField> f = appPanel.FindField(values[0].Text);
                        if (f == null) return null;
                        if (f.Count == 0) return null;

                        if (f[0].fglField is FGLComboListBoxFieldWidget)
                        {
                            FGLComboListBoxFieldWidget widget = (FGLComboListBoxFieldWidget)f[0].fglField;
                            widget.ui_combobox_removeitem(values[1].Text);
                            return null;
                        }
                    }
                    break;


                case "ui.combobox.getcolumnname":
                    {
                        List<FGLFoundField> f = appPanel.FindField(values[0].Text);
                        if (f == null) return null;
                        if (f.Count == 0) return null;
                        retStrings[0] = f[0].getColumnName();
                    }
                    break;

                case "ui.combobox.getindexof":
                    throw new ApplicationException("Combo." + name + " not implemented yet");
                    return null;

                case "ui.combobox.getitemcount":
                    {
                        List<FGLFoundField> f = appPanel.FindField(values[0].Text);
                        if (f[0].fglField is FGLComboListBoxFieldWidget)
                        {
                            FGLComboListBoxFieldWidget widget = (FGLComboListBoxFieldWidget)f[0].fglField;
                            retStrings[0] = widget.ui_combobox_getitemcount();
                            return null;
                        }
                    }
                    break;

                case "ui.combobox.getitemname":
                    throw new ApplicationException("Combo." + name + " not implemented yet");
                    return null;

                case "ui.combobox.getitemtext":
                    throw new ApplicationException("Combo." + name + " not implemented yet");
                    return null;

                case "ui.combobox.gettablename":
                    {
                        List<FGLFoundField> f = appPanel.FindField(values[0].Text);
                        if (f == null) return null;
                        if (f.Count == 0) return null;
                        retStrings[0] = f[0].getTableName();
                    }
                    break;

                case "ui.combobox.gettag":
                    throw new ApplicationException("Combo." + name + " not implemented yet");
                    return null;

                case "ui.combobox.gettextof":

                    throw new ApplicationException("Combo." + name + " not implemented yet");
                    return null;


                default:
                    return null;

            }

            return retStrings;
        }



        internal static void FrontCallNoReturns(FGLApplicationPanel appPanel, FRONTCALL call)
        {
            switch (call.MODULE)
            {
                case "INTERNAL":
                    if (call.NAME.StartsWith("ui.combobox."))
                    {
                        ui_combo_frontcall(appPanel, call.NAME, call.VALUES, null);
                        return;
                    }
                    
                    MessageBox.Show("Unhandled INTERNAL frontcall : " + call.NAME);
                    break;

                default:
                    MessageBox.Show("Unhandled module call : " + call.MODULE + " " + call.NAME);
                    break;
            }
        }
        #endregion
    }
}
