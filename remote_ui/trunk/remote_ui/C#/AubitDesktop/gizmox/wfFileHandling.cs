using System;
using System.Collections.Generic;
using System.Text;

using Gizmox.WebGUI.Forms;
using Gizmox.WebGUI.Common;
using Gizmox.WebGUI.Common.Interfaces;
using Gizmox.WebGUI.Common.Gateways;

using System.IO;
using System.Web;

namespace AubitDesktopWeb {
     static class FGLWebUtils
    {

    }

     class fileDownload
     {
         public string fileName;
         public byte[] bytes;

         public fileDownload(string f, byte[] b)
         {
             fileName = f;
             bytes = b;
         }
     }
}
