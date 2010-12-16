using System;
using System.ComponentModel;
using System.Text.RegularExpressions;
using System.Windows.Forms;
using System.Collections.Generic;

namespace SearchableControls
{
    /// <summary>
    /// An extension of the Framework's TextBox control that allows the user to search for text in the
    /// control by pressing CTRL-F or by using the context menu.
    /// It also returns the standard CTRL-A shortcut to select all the text in the control.
    /// </summary>
    /// <remarks>
    /// <para>Part of SearchableControls written by Jim Blackler (jimblackler@gmail.com), August 2006</para>
    /// 
    /// <para>To use, simply build the SearchableControls library and add a reference it in your project. The
    /// SearchableTextBox control should appear in the SearchableControls tab of the Visual Studio
    /// toolbox. Drag this control to your forms in the way you would a standard TextBox.</para>
    /// 
    /// <para>You may wish to give your forms an Edit/Find menu item with a specified shortcut of Ctrl-F. 
    /// This should call the OpenFindDialog() function of the main searchable control, or in the case of
    /// multiple searchable controls, the focused control. You could provide the same option from toolbars.</para>
    /// 
    /// <para>As you can see the class is derived directly from TextBox so can do everything that the standard
    /// TextBox can do.</para>
    ///</remarks>
    public partial class SearchableTextBox : TextBox, ISearchable
    {
        /// <summary>
        /// Delegate for the searchStartedEvent
        /// </summary>
        /// <param name="searchTerm"></param>
        public delegate void searchStartedArgs(string searchTerm);
        /// <summary>
        /// Event for search started (used to update the symbol lookups at the top of the page)
        /// </summary>
        public event searchStartedArgs searchStarted;

        /// <summary>
        /// Construct a SearchableTextBox textbox
        /// </summary>
        public SearchableTextBox()
        {
            InitializeComponent();

            findDialog1.ReplaceAvailable = false; // Find is not offered if the control is read-only

            // Currently there is no designer support for adding menu item event handlers
            //undoToolStripMenuItem.Click += new EventHandler(undoToolStripMenuItem_Click);
            //cutToolStripMenuItem.Click += new EventHandler(cutToolStripMenuItem_Click);
            //copyToolStripMenuItem.Click += new EventHandler(copyToolStripMenuItem_Click);
            //pasteToolStripMenuItem.Click += new EventHandler(pasteToolStripMenuItem_Click);
            //deleteToolStripMenuItem.Click += new EventHandler(deleteToolStripMenuItem_Click);
            //selectAllToolStripMenuItem.Click += new EventHandler(selectAllToolStripMenuItem_Click);
            findToolStripMenuItem.Click += new EventHandler(findToolStripMenuItem_Click);
            miStatementSQL.Click += new EventHandler(miStatementSQL_Click);
            //replaceToolStripMenuItem.Click += new EventHandler(replaceToolStripMenuItem_Click);

        }

        void miStatementSQL_Click(object sender, EventArgs e)
        {
            MessageBox.Show(miStatementSQL.Text);
        }


        public int currentLineNo
        {

            get { return this.GetLineFromCharIndex(this.SelectionStart) + 1; }
        }
        /// <summary>
        /// Handle key events
        /// </summary>
        /// <remarks>
        /// Used to process custom shortcuts
        /// </remarks>
        /// <param name="sender">Standard system parameter</param>
        /// <param name="e">Standard system parameter</param>
        protected void SearchableTextBox_KeyDown(object sender, KeyEventArgs e)
        {
            // Control A pressed, for 'Select All'?
            if (e.KeyCode == Keys.A && e.Modifiers == Keys.Control)
            {
                SelectAll();
                e.SuppressKeyPress = true; // don't pass the event down
            }
            // Control F pressed, for 'Find'?
            else if (e.KeyCode == Keys.F && e.Modifiers == Keys.Control)
            {
                NewSearch(false);
                e.SuppressKeyPress = true; // don't pass the event down
            }
            else if (e.KeyCode == Keys.H && e.Modifiers == Keys.Control)
            {
                if (!ReadOnly) // Ctrl-H only available in for non read-only controls
                {
                    NewSearch(true);
                    e.SuppressKeyPress = true;
                }
            }
            // F3 pressed, for search again?
            else if (e.KeyCode == Keys.F3 && e.Modifiers == Keys.None)
            {
                findDialog1.FindNext();
                e.SuppressKeyPress = true; // don't pass the event down
            }
            // First press of Escape removes the search dialog if it's present
            else if (e.KeyCode == Keys.Escape && e.Modifiers == Keys.None)
            {
                if (findDialog1.Visible)
                {
                    findDialog1.Close();
                    e.SuppressKeyPress = true;
                }
            }
            else if (e.KeyCode == Keys.Z && e.Modifiers == Keys.Control)
            {
                // Undo - intercepted to give the control a chance to undo replace operations
                Undo(); // Local version called
                e.SuppressKeyPress = true; // don't pass the event down
            }
            
        }

        /// <summary>
        /// Helper function for selecting a word
        /// </summary>
        /// <param name="p">A character from the possible word</param>
        /// <returns>True if this is a word character</returns>
        static private bool IsWordChar(char p)
        {
            if (p >= 'a' && p <= 'z')
                return true;
            if (p >= 'A' && p <= 'Z')
                return true;
            if (p >= '0' && p <= '9')
                return true;
            if (p == '_' || p=='.')
                return true;

            return false;
        }

        


        /*
        /// <summary>
        /// Overriden Undo to undo replace operations
        /// </summary>
        /// <remarks>
        /// Would be a lot simpler if the framework controls gave you access to their undo stack
        /// </remarks>
        public new void Undo()
        {
            if (Text.Equals(textAfterReplace))
            {
                Text = textBeforeReplace;
            }
            else
            {
                // Call ordinary undo
                base.Undo();
            }
        }
        */

        /*
        /// <summary>
        /// Overridden CanUndo to include local undo operation
        /// </summary>
        public new bool CanUndo
        {
            get
            {
                if (Text.Equals(textAfterReplace))
                {
                    return true; // Next undo would be our replace cancel operation
                }
                else
                {
                    // Call ordinary CanUndo
                    return base.CanUndo;
                }
            }
        }
         * */

        /*
        /// <summary>
        /// Redo to redo replace operations
        /// </summary>
        public void Redo()
        {
            if (Text.Equals(textBeforeReplace))
            {
                Text = textAfterReplace;
            }

        }
         * */

        /// <summary>
        /// Start a new search
        /// </summary>
        private void NewSearch(bool replaceMode)
        {
            

            // If no text is selected, select the word
            if (SelectedText.Length == 0)
            {
                int wordStart = SelectionStart;
                while (wordStart > 0 && IsWordChar(Text[wordStart - 1]))
                {
                    wordStart--;
                }
                int wordEnd = SelectionStart;
                while (wordEnd < Text.Length && IsWordChar(Text[wordEnd]))
                {
                    wordEnd++;
                }

                // Store the selection start position on the first search so that when all searches are complete
                // this fact can be reported to the user in the find dialog.
                originalSelectionStart = wordEnd; // matching behaviour of various MS apps
                if (searchStarted!=null)
                {
                    searchStarted(Text.Substring(wordStart, wordEnd - wordStart));
                }
                findDialog1.Show(Text.Substring(wordStart, wordEnd - wordStart), replaceMode);
            }
            else if (!SelectedText.Contains("\n")) // if selection is single line, use that as default
            {
                originalSelectionStart = SelectionStart; // matching behaviour of various MS apps
                if (searchStarted != null)
                {
                    searchStarted(SelectedText);
                }
                findDialog1.Show(SelectedText, replaceMode);
            }
            else
            {
                originalSelectionStart = SelectionStart;
                if (searchStarted != null)
                {
                    searchStarted(SelectedText);
                }
                findDialog1.Show(replaceMode);
            }
        }


        /// <summary>
        /// Start a new search
        /// </summary>
        public string  getSearchTerm()
        {
                        // If no text is selected, select the word
            if (SelectedText.Length == 0)
            {
                int wordStart = SelectionStart;
                while (wordStart > 0 && IsWordChar(Text[wordStart - 1]))
                {
                    wordStart--;
                }
                int wordEnd = SelectionStart;
                while (wordEnd < Text.Length && IsWordChar(Text[wordEnd]))
                {
                    wordEnd++;
                }

               
                    return Text.Substring(wordStart, wordEnd - wordStart);
               
            }
            else if (!SelectedText.Contains("\n")) // if selection is single line, use that as default
            {
                return SelectedText;
            }
            else
            {
              return null;  
            }
        }

        /// <summary>
        /// Put this control's HideSelection property back to normal when the FindDialog is deactivated
        /// </summary>
        /// <remarks>
        /// This unfortunately causes a slight flicker. One way to avoid this is to turn off HideSelection
        /// in individual control instances.
        /// </remarks>
        void RestoreHideSelection(object sender, EventArgs e)
        {
            HideSelection = true;
        }

        /// <summary>
        /// Enable the context menu items that can be invoked
        /// </summary>
        private void contextMenuStrip1_Opening(object sender, CancelEventArgs e)
        {
            string textUnderCursor;
            //undoToolStripMenuItem.Enabled = CanUndo;
            //cutToolStripMenuItem.Enabled = (!ReadOnly && SelectionLength > 0);
            //copyToolStripMenuItem.Enabled = (SelectionLength > 0);
            //pasteToolStripMenuItem.Enabled = !ReadOnly;
            //deleteToolStripMenuItem.Enabled = (!ReadOnly && SelectionLength > 0);
            //selectAllToolStripMenuItem.Enabled = (SelectionLength < Text.Length);
            //replaceToolStripMenuItem.Enabled = findDialog1.ReplaceAvailable;

            textUnderCursor = getSearchTerm();
            if (textUnderCursor!=null) 
            {
                if (searchStarted != null)
                {
                    searchStarted(textUnderCursor);
                }
            }
            //MessageBox.Show("Opening..");
        }

        /// <summary>
        /// Undo from context menu
        /// </summary>
        void undoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Undo();
        }

        /// <summary>
        /// Cut from context menu
        /// </summary>
        void cutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Cut();
        }

        /// <summary>
        /// Copy from context menu
        /// </summary>
        void copyToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Copy();
        }

        /// <summary>
        /// Paste from context menu
        /// </summary>
        void pasteToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Paste();
        }

        /// <summary>
        /// Delete from context menu
        /// </summary>
        void deleteToolStripMenuItem_Click(object sender, EventArgs e)
        {
            SendKeys.Send("{DELETE}"); // Send the delete key
        }

        /// <summary>
        /// Select All from context menu
        /// </summary>
        void selectAllToolStripMenuItem_Click(object sender, EventArgs e)
        {
            SelectAll();
        }

        /// <summary>
        /// Find Text from context menu
        /// </summary>
        void findToolStripMenuItem_Click(object sender, EventArgs e)
        {
            NewSearch(false);
        }

        /// <summary>
        /// Replace from context menu
        /// </summary>
        void replaceToolStripMenuItem_Click(object sender, EventArgs e)
        {
            NewSearch(true);
        }

        /// <summary>
        /// Search a sub-portion of the text
        /// </summary>
        internal bool SubSearch(Regex regularExpression, int start, int end)
        {
            Match match = regularExpression.Match(Text, start, end - start);
            if (match.Success)
            {
                // We need to show search results even when the FindDialog is active
                // This means turning off HideSelection if it is set.
                // This unfortunately causes a slight flicker. One way to avoid this is to turn off HideSelection
                // in individual control instances.
                if (HideSelection)
                {
                    // ensure that the property is restored when the FindDialog is deactivated
                    findDialog1.Deactivate += new EventHandler(RestoreHideSelection);
                    HideSelection = false;
                }

                Select(match.Index, match.Length);

                try
                {
                    ScrollToCaret(); // try/caught because this has been known to fail unexpectedly
                }
                catch (Exception exception)
                {
                    MessageBox.Show(exception.Message);
                }
                return true;
            }
            else
            {
                return false;
            }
        }

        /// <summary>
        /// Stores the selection start position on the first search so that when all searches are complete
        /// this fact can be reported to the user in the find dialog.
        /// </summary>
        protected int originalSelectionStart;

        /// <summary>
        /// Perform the search on the text box
        /// </summary>
        /// <param name="sender">Sending object</param>
        /// <param name="e">Parameters relating to the search event</param>
        protected void findDialog1_SearchRequested(object sender, SearchEventArgs e)
        {
            int startSearch;
            int endSearch;

            if (e.FirstSearch)
            {
                startSearch = originalSelectionStart;
                endSearch = Text.Length;
            }
            else
            {
                // First part of search is between character after current selection (inclusive) and the end of the
                // document (exclusive), or the original search position position (exclusive) if this is greater
                // than the current selection position
                startSearch = SelectionStart + SelectionLength;

                if (originalSelectionStart >= startSearch)
                {
                    endSearch = originalSelectionStart;
                }
                else
                {
                    endSearch = Text.Length;
                }
            }

            bool match;

            match = SubSearch(e.SearchRegularExpression, startSearch, endSearch);


            if (!match && endSearch == Text.Length) // no match? retry from the beginning if the original start position is before or equal to the current search
            {
                // second search is from the start of the document to the original search position (exclusive)

                match = SubSearch(e.SearchRegularExpression, 0, originalSelectionStart);

                if (match)
                {
                    e.RestartedFromDocumentTop = true; // The user is informed that the search started from the top
                }
            }

            if (match)
            {
                e.Successful = true;
            }
        }


#if OLD

        /// <summary>
        /// The find dialog has requested a replace operation on the most recently selected text
        /// </summary>
        private void findDialog1_ReplaceRequested(object sender, ReplaceEventArgs e)
        {
            // Unfortunately it does not seem possible to register this in the TextBox's undo stack
            SelectedText = e.ReplaceText;

            if (findDialog1.ReplaceAvailable)
            {
                textAfterReplace = Text;
            }
        }
#endif
        
        public void setContextDialog(baseSymbolType type) {
            miFindCursor.Visible = false;
            miFindForm.Visible = false;
            miFindStatement.Visible = false;
            miFindVariable.Visible = false;
            miFindWindow.Visible = false;
            miFindFunction.Visible = false;
            

            if (type is symbolCursor)
            {
                symbolCursor c = (symbolCursor)type;
                
                miFindCursor.Visible = true;
                miCursorClose.Visible = c.hasClose;
                setSymbols(miCursorClose, c.symbols,"CLOSE");
                miCursorDeclare.Visible = c.hasDeclare;
                setSymbols(miCursorDeclare, c.symbols,  "DECLARE");
                miCursorFetch.Visible = c.hasFetch;
                setSymbols(miCursorFetch, c.symbols, "FETCH");
                miCursorOpen.Visible = c.hasOpen;
                setSymbols(miCursorOpen, c.symbols,  "OPEN");
            }

            if (type is symbolFunction)
            {
                symbolFunction f = (symbolFunction)type;
                miFindFunction.Visible = true;
                miFunctionCalled.Visible = true;

                miFunctionCalled.Click -= new EventHandler(miFunctionCalled_Click);
                miFunctionCalled.Click += new EventHandler(miFunctionCalled_Click);

                miFunctionDefine.Visible = f.hasDefinition;
                setSymbols(miFunctionDefine, f.symbols, "DEFINITION");
            }

            if (type is symbolForm)
            {
                symbolForm f = (symbolForm)type;
                miFindForm.Visible = true;
                miFormClose.Visible = f.hasClose;
                setSymbols(miFormClose, f.symbols, "CLOSE");
                miFormDisplay.Visible = f.hasDisplay;
                setSymbols(miFormDisplay, f.symbols, "DISPLAY");
                miFormOpen.Visible = f.hasOpen;
                setSymbols(miFormOpen, f.symbols, "OPEN");
            }

            if (type is symbolStatement)
            {
                symbolStatement s = (symbolStatement)type;
                
                miFindStatement.Visible = true;
                miStatementDeclare.Visible = s.hasDeclare;
                setSymbols(miStatementDeclare, s.symbols, "DECLARE");
                miStatementExecute.Visible = s.hasExecute;
                setSymbols(miStatementExecute, s.symbols, "EXECUTE");
                miStatementPrepare.Visible = s.hasPrepare;
                setSymbols(miStatementPrepare, s.symbols, "PREPARE");
                miStatementSQL.Text = s.likelySQL;
            }

            if (type is symbolVariable)
            {
                symbolVariable s = (symbolVariable)type;
                miFindVariable.Visible = true;
                miVariableAssign.Visible = s.hasAssign;
                setSymbols(miVariableAssign, s.symbols, "ASSIGN");
                miVariableDefinition.Visible = s.hasDefine;
                setSymbols(miVariableDefinition, s.symbols, "DEFINE");
                miVariableRead.Visible = s.hasRead;
                setSymbols(miVariableRead, s.symbols, "USE");
            }

            if (type is symbolWindow)
            {
                symbolWindow s = (symbolWindow)type;
                miFindWindow.Visible = true;
                setSymbols(miWindowClose, s.symbols, "CLOSE");
                setSymbols(miWindowHide, s.symbols, "HIDE");
                setSymbols(miWindowMove, s.symbols, "MOVE");
                setSymbols(miWindowOpen, s.symbols, "OPEN");
                setSymbols(miWindowShow, s.symbols, "SHOW");
                miWindowClose.Visible = s.hasClose;
                miWindowHide.Visible = s.hasHide;
                miWindowMove.Visible = s.hasMove;
                miWindowOpen.Visible = s.hasOpen;
                miWindowShow.Visible = s.hasShow;
            }
        }


        public delegate void searchForFunctionCallArgs();
        public event searchForFunctionCallArgs searchForFunctionCall;

        void miFunctionCalled_Click(object sender, EventArgs e)
        {
            if (searchForFunctionCall != null)
            {
                searchForFunctionCall();
            }
        }

        private void setSymbols(ToolStripMenuItem m, List<SymbolLocation> list, string operation)
        {
            List<ToolStripItem> nlist = new List<ToolStripItem>();
            for (int a = 0; a < list.Count; a++)
            {
                if (list[a].Operation == operation)
                {
                    ContextSearchItem c = new ContextSearchItem(list[a]);
                    c.Click += new EventHandler(c_Click);
                    nlist.Add(c);
                }
            }
            m.DropDownItems.Clear();
            if (nlist.Count > 0)
            {
                m.DropDownItems.AddRange(nlist.ToArray());
            }
        }


        /// <summary>
        /// Event called when a drop down context menu option is clicked
        /// </summary>
        public event EventHandler clickContext;

        void c_Click(object sender, EventArgs e)
        {
            if (clickContext != null)
            {
                clickContext(sender, e);
            }
        }

        /// <summary>
        /// The read-only property has been changed on the control
        /// </summary>
        private void SearchableTextBox_ReadOnlyChanged(object sender, EventArgs e)
        {
            findDialog1.ReplaceAvailable = !ReadOnly;
        }

        #region ISearchable Members

        /// <summary>
        /// Return the FindDialog (if any) currently associated with this control
        /// </summary>
        public FindDialog FindDialog
        {
            get { return findDialog1; }
        }

        #endregion


    }



    public class  baseSymbolType
    {
       public string symbolName;
       public List<SymbolLocation> symbols;
       public baseSymbolType()
       {
           symbols = new List<SymbolLocation>();
       }
    }

    public class symbolCRUD : baseSymbolType
    {

    }

    public class symbolFunction : baseSymbolType
    {
        public bool hasCall;
        public bool hasDefinition;
    }

    public class symbolCursor : baseSymbolType
    {
        public bool hasDeclare;
        public bool hasOpen;
        public bool hasFetch;
        public bool hasClose;
    }


    public class symbolVariable : baseSymbolType
    {
        public bool hasDefine;
        public bool hasAssign;
        public bool hasRead;
    }

    public class symbolStatement : baseSymbolType
    {
        public bool hasPrepare;
        public bool hasExecute;
        public bool hasDeclare;
        public string likelySQL;
    }

    public class symbolForm : baseSymbolType
    {
        public bool hasOpen;
        public bool hasClose;
        public bool hasDisplay;
    }

    public class symbolWindow : baseSymbolType
    {
        

        public bool hasOpen;
        
        public bool hasClose;
        public bool hasMove;
        public bool hasHide;
        public bool hasShow;
    }

    public class SymbolLocation
    {
        public string moduleName;
        public int lineNo;
        public string Type;
        public string Operation;
        public string lineText;

        public SymbolLocation(string module, int line, string type, string op,string linetext)
        {
            // TODO: Complete member initialization
            this.moduleName = module;
            this.lineNo = line;
            this.Type = type;
            this.Operation =op;
            this.lineText = linetext;
        }

        public bool InList(baseSymbolType symbols)
        {
            if (symbols == null) return false;
            for (int a = 0; a < symbols.symbols.Count; a++)
            {
                if (symbols.symbols[a].lineNo == this.lineNo &&
                        symbols.symbols[a].moduleName == this.moduleName &&
                    symbols.symbols[a].Operation == this.Operation &&
                    symbols.symbols[a].Type == this.Type)
                {
                    return true;
                }
            }
            return false;
        }
    }

    public class ContextSearchItem : ToolStripMenuItem
    {
        public SymbolLocation sl;

        public ContextSearchItem(SymbolLocation s)
        {
            sl = s;
        }

        public override string Text
        {
            get
            {
                if (sl != null) {
                    return sl.moduleName + ":" + sl.lineNo + " " + sl.lineText; 
                }
                else
                {
                    return base.Text;
                }

            }
        }
    }
    
}
