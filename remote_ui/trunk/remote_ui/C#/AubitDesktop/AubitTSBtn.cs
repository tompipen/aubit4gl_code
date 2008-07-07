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
