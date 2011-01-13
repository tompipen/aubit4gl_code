namespace SearchableControls
{
    partial class SearchableTextBox
    {
        /// <summary> 
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary> 
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.contextMenuStrip = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.findToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.miFindCursor = new System.Windows.Forms.ToolStripMenuItem();
            this.miCursorDeclare = new System.Windows.Forms.ToolStripMenuItem();
            this.miCursorOpen = new System.Windows.Forms.ToolStripMenuItem();
            this.miCursorFetch = new System.Windows.Forms.ToolStripMenuItem();
            this.miCursorClose = new System.Windows.Forms.ToolStripMenuItem();
            this.miFindWindow = new System.Windows.Forms.ToolStripMenuItem();
            this.miWindowOpen = new System.Windows.Forms.ToolStripMenuItem();
            this.miWindowClose = new System.Windows.Forms.ToolStripMenuItem();
            this.miWindowShow = new System.Windows.Forms.ToolStripMenuItem();
            this.miWindowHide = new System.Windows.Forms.ToolStripMenuItem();
            this.miWindowMove = new System.Windows.Forms.ToolStripMenuItem();
            this.miFindVariable = new System.Windows.Forms.ToolStripMenuItem();
            this.miVariableDefinition = new System.Windows.Forms.ToolStripMenuItem();
            this.miVariableAssign = new System.Windows.Forms.ToolStripMenuItem();
            this.miVariableRead = new System.Windows.Forms.ToolStripMenuItem();
            this.miFindForm = new System.Windows.Forms.ToolStripMenuItem();
            this.miFormOpen = new System.Windows.Forms.ToolStripMenuItem();
            this.miFormDisplay = new System.Windows.Forms.ToolStripMenuItem();
            this.miFormClose = new System.Windows.Forms.ToolStripMenuItem();
            this.miFindStatement = new System.Windows.Forms.ToolStripMenuItem();
            this.miStatementPrepare = new System.Windows.Forms.ToolStripMenuItem();
            this.miStatementExecute = new System.Windows.Forms.ToolStripMenuItem();
            this.miStatementDeclare = new System.Windows.Forms.ToolStripMenuItem();
            this.miStatementSQL = new System.Windows.Forms.ToolStripMenuItem();
            this.miFindFunction = new System.Windows.Forms.ToolStripMenuItem();
            this.miFunctionDefine = new System.Windows.Forms.ToolStripMenuItem();
            this.miFunctionCalled = new System.Windows.Forms.ToolStripMenuItem();
            this.miVariableValue = new System.Windows.Forms.ToolStripMenuItem();
            this.findDialog1 = new SearchableControls.FindDialog();
            this.contextMenuStrip.SuspendLayout();
            this.SuspendLayout();
            // 
            // contextMenuStrip
            // 
            this.contextMenuStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.findToolStripMenuItem,
            this.miFindCursor,
            this.miFindWindow,
            this.miFindVariable,
            this.miFindForm,
            this.miFindStatement,
            this.miFindFunction});
            this.contextMenuStrip.Name = "contextMenuStrip1";
            this.contextMenuStrip.RenderMode = System.Windows.Forms.ToolStripRenderMode.System;
            this.contextMenuStrip.ShowImageMargin = false;
            this.contextMenuStrip.Size = new System.Drawing.Size(104, 158);
            this.contextMenuStrip.Opening += new System.ComponentModel.CancelEventHandler(this.contextMenuStrip1_Opening);
            // 
            // findToolStripMenuItem
            // 
            this.findToolStripMenuItem.Name = "findToolStripMenuItem";
            this.findToolStripMenuItem.Size = new System.Drawing.Size(103, 22);
            this.findToolStripMenuItem.Text = "&Find";
            // 
            // miFindCursor
            // 
            this.miFindCursor.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.miCursorDeclare,
            this.miCursorOpen,
            this.miCursorFetch,
            this.miCursorClose});
            this.miFindCursor.Name = "miFindCursor";
            this.miFindCursor.Size = new System.Drawing.Size(103, 22);
            this.miFindCursor.Text = "Cursor";
            // 
            // miCursorDeclare
            // 
            this.miCursorDeclare.Name = "miCursorDeclare";
            this.miCursorDeclare.Size = new System.Drawing.Size(113, 22);
            this.miCursorDeclare.Text = "Declare";
            // 
            // miCursorOpen
            // 
            this.miCursorOpen.Name = "miCursorOpen";
            this.miCursorOpen.Size = new System.Drawing.Size(113, 22);
            this.miCursorOpen.Text = "Open";
            // 
            // miCursorFetch
            // 
            this.miCursorFetch.Name = "miCursorFetch";
            this.miCursorFetch.Size = new System.Drawing.Size(113, 22);
            this.miCursorFetch.Text = "Fetch";
            // 
            // miCursorClose
            // 
            this.miCursorClose.Name = "miCursorClose";
            this.miCursorClose.Size = new System.Drawing.Size(113, 22);
            this.miCursorClose.Text = "Close";
            // 
            // miFindWindow
            // 
            this.miFindWindow.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.miWindowOpen,
            this.miWindowClose,
            this.miWindowShow,
            this.miWindowHide,
            this.miWindowMove});
            this.miFindWindow.Name = "miFindWindow";
            this.miFindWindow.Size = new System.Drawing.Size(103, 22);
            this.miFindWindow.Text = "Window";
            // 
            // miWindowOpen
            // 
            this.miWindowOpen.Name = "miWindowOpen";
            this.miWindowOpen.Size = new System.Drawing.Size(104, 22);
            this.miWindowOpen.Text = "Open";
            // 
            // miWindowClose
            // 
            this.miWindowClose.Name = "miWindowClose";
            this.miWindowClose.Size = new System.Drawing.Size(104, 22);
            this.miWindowClose.Text = "Close";
            // 
            // miWindowShow
            // 
            this.miWindowShow.Name = "miWindowShow";
            this.miWindowShow.Size = new System.Drawing.Size(104, 22);
            this.miWindowShow.Text = "Show";
            // 
            // miWindowHide
            // 
            this.miWindowHide.Name = "miWindowHide";
            this.miWindowHide.Size = new System.Drawing.Size(104, 22);
            this.miWindowHide.Text = "Hide";
            // 
            // miWindowMove
            // 
            this.miWindowMove.Name = "miWindowMove";
            this.miWindowMove.Size = new System.Drawing.Size(104, 22);
            this.miWindowMove.Text = "Move";
            // 
            // miFindVariable
            // 
            this.miFindVariable.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.miVariableDefinition,
            this.miVariableAssign,
            this.miVariableRead,
            this.miVariableValue});
            this.miFindVariable.Name = "miFindVariable";
            this.miFindVariable.Size = new System.Drawing.Size(103, 22);
            this.miFindVariable.Text = "Variable";
            // 
            // miVariableDefinition
            // 
            this.miVariableDefinition.Name = "miVariableDefinition";
            this.miVariableDefinition.Size = new System.Drawing.Size(180, 22);
            this.miVariableDefinition.Text = "Define";
            // 
            // miVariableAssign
            // 
            this.miVariableAssign.Name = "miVariableAssign";
            this.miVariableAssign.Size = new System.Drawing.Size(180, 22);
            this.miVariableAssign.Text = "Assign";
            // 
            // miVariableRead
            // 
            this.miVariableRead.Name = "miVariableRead";
            this.miVariableRead.Size = new System.Drawing.Size(180, 22);
            this.miVariableRead.Text = "Read";
            // 
            // miFindForm
            // 
            this.miFindForm.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.miFormOpen,
            this.miFormDisplay,
            this.miFormClose});
            this.miFindForm.Name = "miFindForm";
            this.miFindForm.Size = new System.Drawing.Size(103, 22);
            this.miFindForm.Text = "Form";
            // 
            // miFormOpen
            // 
            this.miFormOpen.Name = "miFormOpen";
            this.miFormOpen.Size = new System.Drawing.Size(112, 22);
            this.miFormOpen.Text = "Open";
            // 
            // miFormDisplay
            // 
            this.miFormDisplay.Name = "miFormDisplay";
            this.miFormDisplay.Size = new System.Drawing.Size(112, 22);
            this.miFormDisplay.Text = "Display";
            // 
            // miFormClose
            // 
            this.miFormClose.Name = "miFormClose";
            this.miFormClose.Size = new System.Drawing.Size(112, 22);
            this.miFormClose.Text = "Close";
            // 
            // miFindStatement
            // 
            this.miFindStatement.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.miStatementPrepare,
            this.miStatementExecute,
            this.miStatementDeclare,
            this.miStatementSQL});
            this.miFindStatement.Name = "miFindStatement";
            this.miFindStatement.Size = new System.Drawing.Size(103, 22);
            this.miFindStatement.Text = "Statement";
            // 
            // miStatementPrepare
            // 
            this.miStatementPrepare.Name = "miStatementPrepare";
            this.miStatementPrepare.Size = new System.Drawing.Size(114, 22);
            this.miStatementPrepare.Text = "Prepare";
            // 
            // miStatementExecute
            // 
            this.miStatementExecute.Name = "miStatementExecute";
            this.miStatementExecute.Size = new System.Drawing.Size(114, 22);
            this.miStatementExecute.Text = "Execute";
            // 
            // miStatementDeclare
            // 
            this.miStatementDeclare.Name = "miStatementDeclare";
            this.miStatementDeclare.Size = new System.Drawing.Size(114, 22);
            this.miStatementDeclare.Text = "Declare";
            // 
            // miStatementSQL
            // 
            this.miStatementSQL.Name = "miStatementSQL";
            this.miStatementSQL.Size = new System.Drawing.Size(114, 22);
            this.miStatementSQL.Text = "<>";
            // 
            // miFindFunction
            // 
            this.miFindFunction.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.miFunctionDefine,
            this.miFunctionCalled});
            this.miFindFunction.Name = "miFindFunction";
            this.miFindFunction.Size = new System.Drawing.Size(103, 22);
            this.miFindFunction.Text = "Function";
            // 
            // miFunctionDefine
            // 
            this.miFunctionDefine.Name = "miFunctionDefine";
            this.miFunctionDefine.Size = new System.Drawing.Size(126, 22);
            this.miFunctionDefine.Text = "Definition";
            // 
            // miFunctionCalled
            // 
            this.miFunctionCalled.Name = "miFunctionCalled";
            this.miFunctionCalled.Size = new System.Drawing.Size(126, 22);
            this.miFunctionCalled.Text = "Find Calls";
            // 
            // miVariableValue
            // 
            this.miVariableValue.Name = "miVariableValue";
            this.miVariableValue.Size = new System.Drawing.Size(180, 22);
            this.miVariableValue.Text = "toolStripMenuItem1";
            this.miVariableValue.ToolTipText = "Possible value";
            // 
            // findDialog1
            // 
            this.findDialog1.ParentControl = this;
            this.findDialog1.ReplaceAvailable = false;
            this.findDialog1.SearchRegularExpression = null;
            this.findDialog1.SearchRequested += new SearchableControls.SearchEventHandler(this.findDialog1_SearchRequested);
            // 
            // SearchableTextBox
            // 
            this.ContextMenuStrip = this.contextMenuStrip;
            this.ReadOnlyChanged += new System.EventHandler(this.SearchableTextBox_ReadOnlyChanged);
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.SearchableTextBox_KeyDown);
            this.contextMenuStrip.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ContextMenuStrip contextMenuStrip;
        private System.Windows.Forms.ToolStripMenuItem findToolStripMenuItem;
        private FindDialog findDialog1;
        private System.Windows.Forms.ToolStripMenuItem miFindCursor;
        private System.Windows.Forms.ToolStripMenuItem miCursorDeclare;
        private System.Windows.Forms.ToolStripMenuItem miCursorOpen;
        private System.Windows.Forms.ToolStripMenuItem miCursorFetch;
        private System.Windows.Forms.ToolStripMenuItem miCursorClose;
        private System.Windows.Forms.ToolStripMenuItem miFindWindow;
        private System.Windows.Forms.ToolStripMenuItem miWindowOpen;
        private System.Windows.Forms.ToolStripMenuItem miWindowClose;
        private System.Windows.Forms.ToolStripMenuItem miWindowShow;
        private System.Windows.Forms.ToolStripMenuItem miWindowHide;
        private System.Windows.Forms.ToolStripMenuItem miWindowMove;
        private System.Windows.Forms.ToolStripMenuItem miFindVariable;
        private System.Windows.Forms.ToolStripMenuItem miVariableDefinition;
        private System.Windows.Forms.ToolStripMenuItem miVariableAssign;
        private System.Windows.Forms.ToolStripMenuItem miVariableRead;
        private System.Windows.Forms.ToolStripMenuItem miFindForm;
        private System.Windows.Forms.ToolStripMenuItem miFormOpen;
        private System.Windows.Forms.ToolStripMenuItem miFormDisplay;
        private System.Windows.Forms.ToolStripMenuItem miFormClose;
        private System.Windows.Forms.ToolStripMenuItem miFindStatement;
        private System.Windows.Forms.ToolStripMenuItem miStatementPrepare;
        private System.Windows.Forms.ToolStripMenuItem miStatementExecute;
        private System.Windows.Forms.ToolStripMenuItem miStatementDeclare;
        private System.Windows.Forms.ToolStripMenuItem miFindFunction;
        private System.Windows.Forms.ToolStripMenuItem miFunctionDefine;
        private System.Windows.Forms.ToolStripMenuItem miFunctionCalled;
        private System.Windows.Forms.ToolStripMenuItem miStatementSQL;
        private System.Windows.Forms.ToolStripMenuItem miVariableValue;
    }
}
