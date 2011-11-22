using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Data;

namespace AubitDesktop
{
    class UIConstructInTableContext : UIContext
    {
      //  private List<FGLFoundField> activeFields;
        private List<ONKEY_EVENT> KeyList;
        private FGLApplicationPanel mainWin;
        private AFTER_INPUT_EVENT afterInput;
        private List<BEFORE_FIELD_EVENT> beforeFieldList;
        private List<AFTER_FIELD_EVENT> afterFieldList;
        private List<ON_ACTION_EVENT> onActionList;
        private COLUMN[] constructColumnList;
        private FGLFoundField setCurrentField;
        List<string> PendingEvents;
        private bool isBeforeInput;
        private FGLFoundField _currentField;
        FormattedGridView constructGrid;
        DataTable dt;
        private event UIEventHandler EventTriggered;
        private bool _contextIsActive;
        List<DataGridViewCell> RecordFields;


        private FGLFoundField CurrentField
        {
            get
            {
                return _currentField;
            }
            set
            {
                _currentField = value;
            }
        }

      //  private List<FGLFoundField> activeFields;

        public UIConstructInTableContext(FGLApplicationPanel f, CONSTRUCT c, FormattedGridView pConstructGrid, List<DataGridViewCell> pRecordFields)
        {
            bool haveAccept = false;
            bool haveInterrupt = false;
            KeyList = new List<ONKEY_EVENT>();
            KeyList.Clear();
            RecordFields = pRecordFields;
            afterFieldList = new List<AFTER_FIELD_EVENT>();
            beforeFieldList = new List<BEFORE_FIELD_EVENT>();
            onActionList = new List<ON_ACTION_EVENT>();
            setCurrentField = null;
            CurrentField = null;
            PendingEvents = new List<string>();
            isBeforeInput = true;

           // activeFields = f.FindFieldArray(c.FIELDLIST);

            foreach (object evt in c.EVENTS)
            {
                if (evt is ONKEY_EVENT)
                {
                    ONKEY_EVENT e;
                    e = (ONKEY_EVENT)evt;
                    if (e.KEY == "" + FGLUtils.getKeyCodeFromKeyName("ACCEPT"))
                    {
                        haveAccept = true;
                    }
                    if (e.KEY == "" + FGLUtils.getKeyCodeFromKeyName("INTERRUPT"))
                    {
                        haveInterrupt = true;
                    }
                    KeyList.Add(e);
                    continue;
                }

                if (evt is BEFORE_FIELD_EVENT)
                {
                    BEFORE_FIELD_EVENT e;
                    e = (BEFORE_FIELD_EVENT)evt;
                    beforeFieldList.Add(e);
                    continue;
                }

                if (evt is AFTER_FIELD_EVENT)
                {
                    AFTER_FIELD_EVENT e;
                    e = (AFTER_FIELD_EVENT)evt;
                    afterFieldList.Add(e);
                    continue;
                }

                if (evt is ON_ACTION_EVENT)
                {
                    ON_ACTION_EVENT e;
                    e = (ON_ACTION_EVENT)evt;
                    onActionList.Add(e);
                    continue;
                }

                if (evt is AFTER_INPUT_EVENT)
                {
                    afterInput = (AFTER_INPUT_EVENT)evt;
                    continue;
                }
                Program.Show("Unhandled Event for CONSTRUCT");
            }

            if (!haveAccept)
            {
                KeyList.Add(new ONKEY_EVENT("ACCEPT"));

            }
            if (!haveInterrupt)
            {


                KeyList.Add(new ONKEY_EVENT("INTERRUPT"));
            }

            mainWin = f;



        //    constructGrid = f.FindRecord(c.FIELDLIST);

            constructGrid = pConstructGrid;

            if (constructGrid == null)
            {
                constructGrid=(FormattedGridView)pRecordFields[0].DataGridView;
            }
            constructGrid.init();
            constructGrid.DataSource = null;
            dt = new DataTable();
            dt.Columns.Add("subscript");
            for (int cols = 1; cols <= c.COLUMNS.Length; cols++)
            {
                dt.Columns.Add("col" + (cols));
            }



            constructColumnList = c.COLUMNS;
            
            constructGrid.allowInsertRow = false;


            DataGridViewRow r;
            string[] data;
            data = new string[c.COLUMNS.Length + 1];
            r = new DataGridViewRow();

            // We'll use the first column to store the index
            // for the current row...
            data[0] = "1";

            for (int col = 0; col < c.COLUMNS.Length; col++)
            {
                object itm;
                AubitDesktop.Xml.XMLForm.TableColumn tc = constructGrid.table.TableColumn[col];
                itm = tc.Item;
                data[col + 1] = "";
            }
            dt.Rows.Add(data);

            constructGrid.Columns[0].Visible = false;
            constructGrid.DataSource = dt;
            constructGrid.AutoResizeColumnHeadersHeight();
            constructGrid.AutoResizeRow(0);

            for (int col = 0; col < c.COLUMNS.Length; col++)
            {
                constructGrid.AutoResizeColumn(col);
            }

            constructGrid.Enabled = false;
            
            // WEBGUI displayArrayGrid.sizeGrid(); 

        }

        public bool contextIsActive()
        {
            throw new NotImplementedException();
        }

        public bool useKeyPress(System.Windows.Forms.KeyEventArgs ke)
        {
            return false;
            //throw new NotImplementedException();
        }

        public void toolBarAcceptClicked()
        {
                
                if (afterInput != null)
                {
                    
                    sendTrigger(afterInput.ID);
                }
                sendTrigger("ACCEPT");
        }

        public string getSyncValues()
        {
            string s;
            s = "<SVS>";
            
//            constructGrid.syncData(0,
            
            for (int a=0;a<this.constructGrid.Columns.Count-1;a++) 
            {

                dt.Rows[0].EndEdit();
                //FGLFoundField i=activeFields[a];
                s += "<SV FN=\"" + constructGrid.getFieldName(a) + "\">" + System.Security.SecurityElement.Escape(FGLUtils.GetString(constructGrid.Rows[0].Cells[a+1].EditedFormattedValue))  + "</SV>";
            }
            
            s += "</SVS>";
            return s;
        }

        string getTriggeredText(string ID)
        {
            string cfield;
            if (CurrentField != null)
            {
                cfield = " INFIELD=\"" + CurrentField.useName + "\"";
            }
            else
            {
                cfield = "";
            }

            return "<TRIGGERED ID=\"" + ID + "\" " + cfield + " LASTKEY=\"" + mainWin.LastKey + "\">" + getSyncValues() + "</TRIGGERED>";
        }

        void sendTrigger(string id) {
            //string TriggeredText = "TriggeredText";
            this.EventTriggered(null, id, getTriggeredText(id), this);
        }

        

        public bool externallyTriggeredID(string ID)
        {

            switch (ID)
            {
                case "ACCEPT": toolBarAcceptClicked(); return true;
                // INTERRUPT can pass through - we dont mind ;-)
            }
            sendTrigger(ID);
            return false;
        }

        public void onActionTriggered(object source, string ID, string TriggeredText, UIContext u)
        {
            if (TriggeredText == "")
            {
                TriggeredText = "<TRIGGERED ID=\"" + ID + "\"></TRIGGERED>";
            }
            this.EventTriggered(source, ID, TriggeredText, this);
        }

        public void ActivateContext(UIEventHandler UIDisplayArrayContext_EventTriggered, V[] values, ROW[] rows)
        {
            foreach (ON_ACTION_EVENT e in onActionList)
            {
                foreach (FGLFoundField ffield in mainWin.FindAction(e.ACTION))
                {
                    ffield.fglField.onActionID = e.ID;
                    ffield.fglField.onUIEvent = onActionTriggered;
                    ffield.fglField.Enabled = true;
                    ffield.fglField.ContextType = FGLContextType.ContextInput;
                }

            }
            constructGrid.ReadOnly = false;
            constructGrid.Enabled = true;

            mainWin.setActiveToolBarKeys(KeyList, onActionList); //, true,true,false);


            this.EventTriggered = UIDisplayArrayContext_EventTriggered;

            if (!_contextIsActive)
            {
                _contextIsActive = true;
            }

            constructGrid.allowInsertRow = false;
            constructGrid.setActiveFocus();

            constructGrid.context = FGLContextType.ContextDisplayArray;
        }

        public void DeactivateContext()
        {
            mainWin.setActiveToolBarKeys(null, null); //, false);
            mainWin.SetContext(FGLContextType.ContextConstructArrayInactive);
            _contextIsActive = false;
        }

        public void FreeContext()
        {
            _contextIsActive = false;
        }

        public void NavigateToTab()
        {
            mainWin.setActiveToolBarKeys(KeyList, onActionList);
        }

        public void NavigateAwayTab()
        {
            
        }

        public void setNextField(string p)
        {
            throw new NotImplementedException();
        }
    }
}
