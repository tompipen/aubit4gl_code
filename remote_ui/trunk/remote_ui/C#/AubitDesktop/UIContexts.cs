using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Forms;

namespace AubitDesktop
{
    public delegate void UIEventHandler(object source, string ID, string TriggeredText);
    public delegate void UIFieldValidationHandler(object source, string failedText, out bool ignore);
    

    public interface UIContext
    {



        /// <summary>
        /// Returns True if we're between a 'ActivateContext' and a 'DeactivateContext'
        /// </summary>
        /// <returns></returns>
        bool contextIsActive();
 

        /// <summary>
        /// Activate a context
        /// </summary>
        /// <param name="e">Event handler to call when a TRIGGERED packet is to be returned</param>
        void ActivateContext(UIEventHandler e,VALUE[] values);

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
        string getAcceptString();

        void setNextField(string p);
    }

 
}
