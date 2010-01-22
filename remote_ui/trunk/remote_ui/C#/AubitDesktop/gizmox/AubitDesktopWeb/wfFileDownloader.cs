#region Using

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;

using System.Text;

using Gizmox.WebGUI.Common;
using Gizmox.WebGUI.Forms;
using Gizmox.WebGUI.Common.Interfaces;
using System.Web;
using Gizmox.WebGUI.Common.Gateways;
using System.IO;

#endregion

namespace AubitDesktop
{

    public partial class wfFileDownloader : Form, IGatewayComponent
    {
        private string contenttype;
        private Stream stream;
        private string filepath;
        private Byte[] bytes;

        public string Filename;
        public LinkParameters linkparameters = new LinkParameters();
        public Boolean downloadattachment = true;






        public wfFileDownloader()
        {
            InitializeComponent();         
            linkparameters.Target = "_blank";
            lblTarget.Text = linkparameters.Target;
            SetContentType(DownloadContentType.OctetStream);
        }

         public void SetContentType(DownloadContentType argContentType)
        {
            this.contenttype = getContentType(argContentType);
        }

        public void StartFileDownload( string argFilePath)
        {
            stream = null;
            filepath = argFilePath;
            StartDownload();
            lblFilename.Text = argFilePath;
        }

        public void StartStreamDownload( Stream argStream)
        {
            stream = argStream;
            filepath = null;
            StartDownload();
            lblFilename.Text = "Stream";
        }

        public void StartBytesDownload(string name,  Byte[] argBytes)
        {
            bytes = argBytes;
            stream = null;
          //  Filename = name;
            //filepath = name;
            StartDownload();
            lblFilename.Text = "Bytes:"+argBytes.Length;
        }


        public void StartDownload()
        {

            Link.Open(new GatewayReference(this, "Download"), linkparameters);
   
        }
       


        private string getContentType(DownloadContentType arg)
        {
            switch(arg)
            {
              
                case DownloadContentType.MicrosoftWord:
                    return "application/x-msword";

                case DownloadContentType.PDF:
                    return "application/pdf";

                case DownloadContentType.MicrosoftExcel:
                    return "application/x-msexcel";
               
                case DownloadContentType.PlainText:
                    return "text/plain";

                default:
                    return "application/octet-stream";
              

            }
        }

        public Byte[] GetStreamAsBytes(System.IO.Stream argStream)
        {
            Int32 streamLength = Convert.ToInt32(argStream.Length);
            Byte[] filedata = new Byte[streamLength];
            argStream.Read(filedata, 0, streamLength);
            argStream.Close();
            return filedata;
        }

        #region IGatewayComponent Members

        void IGatewayComponent.ProcessRequest(IContext objContext, string strAction)
        {
            
            HttpResponse objResponse = objContext.HttpContext.Response;

     

            if (!String.IsNullOrEmpty(this.contenttype))
                objResponse.ContentType = contenttype;


       




            if (this.downloadattachment && !String.IsNullOrEmpty(Filename))
                objResponse.AddHeader("content-disposition", "attachment; filename=\"" + this.Filename + "\"");
            else if (this.downloadattachment)
                objResponse.AddHeader("content-disposition", "attachment; filename=\"" + this.Filename + "\"");
            if (! String.IsNullOrEmpty(filepath))
                objResponse.WriteFile(filepath);
            else if(stream != null)
            {
                Byte[] Bytes = GetStreamAsBytes(stream);
                objResponse.BinaryWrite(Bytes);
            }
            else
            {
                objResponse.BinaryWrite(bytes);
            }

       
            objResponse.End();

   
            this.Close();
           
        }

        #endregion
    }

    public enum DownloadContentType
    {
        OctetStream,
        MicrosoftExcel,
        MicrosoftWord,
        PDF,
        PlainText
    }



}
