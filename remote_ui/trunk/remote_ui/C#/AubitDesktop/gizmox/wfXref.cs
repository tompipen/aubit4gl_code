namespace
    Gizmox.WebGUI.Forms
{
    class ToolStripButton : Gizmox.WebGUI.Forms.ToolBarButton
    {
    }

    /*
    class ToolStripItem : Control
    {
       public  bool Checked;
    }
    */

    class MenuStrip : Gizmox.WebGUI.Forms.MainMenu
    {
    }


    /*
    class ToolStripMenuItem : Gizmox.WebGUI.Forms.MenuItem
    {
        public int Size;
        public string Name;
    }
     * */

    class ToolStripStatusLabel : Gizmox.WebGUI.Forms.Label
    {
    }

    class ToolStrip : Gizmox.WebGUI.Forms.ToolBar
    {
    }

    class WebBrowser : Gizmox.WebGUI.Forms.HtmlBox
    {
        
        public new System.Uri Url
        {
            set
            {
                base.Url = value.ToString();
            }
            get
            {
                if (base.Url == null) return null;
                if (base.Url == "") return null;
                return new System.Uri(base.Url);
            }
        }
        public bool ScrollBarsEnabled
        {
            set
            {
              
              //  this.ScrollBarsEnabled = value;
            }
        }
        
    }

    /*
    class ToolStripProgressBar : ToolStripStatusLabel
    {
        public int Value;
        public int Maximum;
        public int Minimum;

    }
    */

    class PictureBoxCompat : PictureBox
    {
        public string ImageLocation
        {
            get
            {
                return "..";
            }
            set
            {
            }
        }

        public void Load(string s)
        {
        }
    }


    class resourceInterface
    {
        public static object getObject(string name) {
            return null;
        }
    }


    class FGLImageSettings
    {
     static public   string ImageDirectory="/images";
    }


    /*
    class StatusStrip : Gizmox.WebGUI.Forms.StatusBarPanel
    {
        public void SuspendLayout()
        {
        }
        public void ResumeLayout()
        {
        }
        public ControlCollection Items;
        public System.Drawing.Point Location;
        public string Name;
        public System.Drawing.Size Size;
        public int TabIndex;
    }
     * */

}

namespace AubitDesktop
{
    class FormClosedEventArgs
    {
    }

    class Program
    {
        static public AubitDesktop.Xml.Settings AppSettings;
        static public System.Text.Encoding remoteEncoding = System.Text.ASCIIEncoding.GetEncoding("iso-8859-1");

        
        static public void SaveSettings()
        {
        }
        static internal bool isNumericDatatype(AubitDesktop.FGLUtils.FGLDataTypes n)
        {
            switch (n)
            {
                case AubitDesktop.FGLUtils.FGLDataTypes.DTYPE_SMINT:
                case AubitDesktop.FGLUtils.FGLDataTypes.DTYPE_INT:
                case AubitDesktop.FGLUtils.FGLDataTypes.DTYPE_SERIAL:
                case AubitDesktop.FGLUtils.FGLDataTypes.DTYPE_FLOAT:
                case AubitDesktop.FGLUtils.FGLDataTypes.DTYPE_DATE:
                case AubitDesktop.FGLUtils.FGLDataTypes.DTYPE_SMFLOAT:
                case AubitDesktop.FGLUtils.FGLDataTypes.DTYPE_DECIMAL:
                case AubitDesktop.FGLUtils.FGLDataTypes.DTYPE_MONEY:
                    return true;
            }

            return false;
        }

        internal static void Show(string p)
        {
            //MessageBox.Show(p)
            try
            {
                Gizmox.WebGUI.Forms.MessageBox.Show(p);
            }
            catch { } 
        }

        internal static void ShowMessage(string p)
        {
            try
            {
                Gizmox.WebGUI.Forms.MessageBox.Show(p);
            }
            catch { } 
        }

        internal static void Show(string p, string p_2)
        {
            Gizmox.WebGUI.Forms.MessageBox.Show(p,p_2);
        }
    }


    static class FGLWebUtils
    {

        internal static Gizmox.WebGUI.Common.Resources.ResourceHandle getImageFromName(string p)
        {
            Gizmox.WebGUI.Common.Resources.ImageResourceHandle irh;
            irh=new  Gizmox.WebGUI.Common.Resources.ImageResourceHandle(p);

            return irh;

        }
    }

}