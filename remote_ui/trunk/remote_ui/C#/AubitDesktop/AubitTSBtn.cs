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
    class AubitTSBtn : System.Windows.Forms.ToolStripButton
    {
        private string activeKey;
        private string iD;
        private bool _isProgramAdded;
        private string _programTag;
        /*
        private string _action;
        internal string Action
        {
            get
            {
                return _action;
            }
            set
            {
                _action = value;
            }
        }*/

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
                iD =value;
            }
        }

        public bool HiddenNormalKey=false;
        
       

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
            }
        }
    }
}
