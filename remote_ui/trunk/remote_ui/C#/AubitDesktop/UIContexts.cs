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
    public delegate void UIEventHandler(object source, string ID, string TriggeredText, UIContext u);
    public delegate void UIArrayTableHandler(int RowId, int columnId);
    public delegate void UIArrayTableRowHandler(int RowId);
    public delegate void UIGotFocusHandler(object source, string comment);
    public delegate void UIFieldValidationHandler(object source, string failedText, out bool ignore);
    

    public interface UIContext
    {



        /// <summary>
        /// Returns True if we're between a 'ActivateContext' and a 'DeactivateContext'
        /// </summary>
        /// <returns></returns>
   //      bool contextIsActive();

        bool useKeyPress(KeyEventArgs ke);
        bool externallyTriggeredID(string ID);


        /// <summary>
        /// Activate a context
        /// </summary>
        /// <param name="e">Event handler to call when a TRIGGERED packet is to be returned</param>
        void ActivateContext(UIEventHandler e,V[] values,ROW[] rows);

        /// <summary>
        /// Deactivate the context - stop listening for actions
        /// </summary>
        void DeactivateContext();

        /// <summary>
        /// Free the context - it wont ever be called again
        /// (will be recreated if/when required)
        /// </summary>
        void FreeContext();

        //event UIEventHandler EventTriggered;

        /// <summary>
        /// Resets the screen to show the correct information for this
        /// context
        /// </summary>
        void NavigateToTab();

        /// <summary>
        /// Removes any details added to the top level window. Called
        /// when the tabpage is deselected (ie - remove any menubar/toolbars etc)
        /// </summary>
        void NavigateAwayTab();

        /// <summary>
        /// Gets the string to send when the 'ACCEPT' button is pressed on the toolbar.
        /// </summary>
        /// <returns></returns>
        //string getAcceptString();
    //    void toolBarAcceptClicked();
        void setNextField(string p);


    
    }

 
}
