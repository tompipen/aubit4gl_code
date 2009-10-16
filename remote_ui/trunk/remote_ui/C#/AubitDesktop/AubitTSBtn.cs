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

namespace AubitDesktop
{
    /*
    enum showMode
    {
        showModeAlways,
        showModeNever,
        showModeAuto
    }; */

    class AubitTSBtn : System.Windows.Forms.ToolStripButton
    {
        private string activeKey;
        private string iD;

        /// <summary>
        /// Internal keys are internally managed to set the visibility
        /// so they dont have the normal 'action' ID logic for hiding/showing...
        /// These are used for things like the Accept/Interrupt/Up/Down etc etc etc
        /// </summary>
        private bool isInternalKey;

        private bool _isProgramAdded;
        private string _programTag;

        /// <summary>
        /// 
        /// This is used by a menu context to say that a menu option is SHOWN or HIDDEN.
        /// by a SHOW OPTION ... or a HIDE OPTION ....
        /// 
        /// </summary>
        private bool _forceDisable;
        internal bool forceDisable
        {
            get
            {
                return _forceDisable;
            }
            set
            {
                _forceDisable = value;
                setVisibility();
            }
        }
        showMode _alwaysShow;
        internal showMode alwaysShow
        {
            get
            {
                return _alwaysShow;
            }
            set
            {
                _alwaysShow = value;
            }
        }

        internal AubitTSBtn()
        {
            this.alwaysShow = showMode.ShowAuto;
            isInternalKey = false;
            forceDisable = false;
        }

        internal AubitTSBtn(bool isInternalKey)
        {
            this.isInternalKey = isInternalKey;
            this.alwaysShow = showMode.ShowAuto;
            forceDisable = false;
        }


        public delegate bool HandledEventHandler(object sender, EventArgs e);
        
        private EventHandler _clickHandler;

        public EventHandler clickHandler
        {
            get
            {
                return _clickHandler;
            }
            set
            {
                _clickHandler = value;
                Click += value;
            }
        }

        public string ID
        {
            get
            {
                return iD;
            }
            set
            {
                iD = value;
                setVisibility();
            }
        }

        internal void setVisibility()
        {
            bool makeVisible=true;
            if (!isInternalKey)
            {

                switch (alwaysShow)
                {
                    case showMode.ShowNever:

                        makeVisible = false;
                        break;

                    case showMode.ShowAuto:
                        if (iD == null || forceDisable == true)
                        {
                            makeVisible = false;
                        }
                        else
                        {
                            makeVisible = true;
                        }
                        break;

                    case showMode.ShowAlways:
                        makeVisible = true;
                        break;
                }


                if (isSystemAction(this.ActiveKey)) {
                    this.Visible=true;
                    this.Enabled=true;
                } else {

                // If the widget is still being displayed - do we want to disable it
                // because theres no valid ID ? 
                if (makeVisible == true)
                {
                    if (this.iD == null || forceDisable == true)
                    {
                        this.Enabled = false;
                    }
                    else
                    {
                        this.Enabled = true;
                    }
                }
                this.Visible = makeVisible;
                }
            }
        }

    //    public bool HiddenNormalKey=false;




                 /// <summary>
            /// Is the action one that is always available ?
            /// (Eg. the DIE action).
            /// Such actions are not actioned by the 4GL program but by the
            /// UI_XML handler itself...
            /// </summary>
            /// <param name="actionID">Action to check</param>
            /// <returns>true/false - if the action is always to be enabled...</returns>
        static internal bool isSystemAction(string actionID)
        {
            
            if (actionID == "DIE") return true;
            if (actionID == "quit") return true;
            return false;
        }

        public string programTag
        {
            get
            {
                return _programTag;
            }
            set
            {
                _programTag = value;
            }
        }


        public bool isProgramAdded
        {
            get
            {
                return _isProgramAdded;
            }
            set
            {
                _isProgramAdded = value;
            }
        }

        public string ActiveKey
        {
            get
            {
                return activeKey;
            }
            set
            {
                activeKey = value;
                switch (activeKey)
                {
                    case "INTERRUPT":

                    case "ACCEPT":
                    case "2016": // ACCEPT...

                    case "INSERT":
                    case "2014": // Insert...

                    case "DELETE":
                    case "2015": // Delete...
                        isInternalKey = true;
                        break;
                }
            }
        }
    }
}
