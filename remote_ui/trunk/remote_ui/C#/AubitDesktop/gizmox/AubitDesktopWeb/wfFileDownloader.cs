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

    public partial class wfFileDownloader : Form
    {
        FileDownloadGateway fdw;

        public wfFileDownloader()
        {
            InitializeComponent();
        }

        public void StartFileDownload(string argFilePath) {
            
            fdw = new FileDownloadGateway();
            fdw.downloadedHandler += new FileDownloadGateway.fileDownloadedHandler(fdw_downloadedHandler);
            fdw.StartFileDownload(this, argFilePath);
        }



        public void StartBytesDownload(string fileName, Byte[] argBytes)
        {
            fdw = new FileDownloadGateway();
            this.lblFilename.Text = fileName;
            this.lblTarget.Text = "";
            fdw.downloadedHandler += new FileDownloadGateway.fileDownloadedHandler(fdw_downloadedHandler);
            fdw.Filename = fileName;
            fdw.StartBytesDownload(this, argBytes);
        }

        void fdw_downloadedHandler(object sender, bool e)
        {
            this.Close();
        }


        
    
    }


    [MetadataTag("KonectCommonVWG.FileDownloadGateway")]
    public class FileDownloadGateway : Control , IGatewayComponent
    {
        private string contenttype;
        private ContainerControl container;
        private Stream stream;
        private string filepath;
        private Byte[] bytes;
        public delegate void fileDownloadedHandler(object sender, bool e);

        public string Filename;
        public LinkParameters linkparameters = new LinkParameters();
        public Boolean downloadattachment = true;
        public event fileDownloadedHandler downloadedHandler;


        public FileDownloadGateway()
        {
            linkparameters.Target = "_blank";
        }

        public void SetContentType(DownloadContentType argContentType)
        {
            this.contenttype = getContentType(argContentType);
        }

        public void StartFileDownload(ContainerControl argContainer, string argFilePath)
        {
            stream = null;
            filepath = argFilePath;
            StartDownload(argContainer);
        }

        public void StartStreamDownload(ContainerControl argContainer, Stream argStream)
        {
            stream = argStream;
            filepath = null;
            StartDownload(argContainer);
        }

        public void StartBytesDownload(ContainerControl argContainer, Byte[] argBytes)
        {
            bytes = argBytes;
            stream = null;
            filepath = null;
            StartDownload(argContainer);
        }

        public void StartDownload(ContainerControl argContainer)
        {
          //  argContainer.Show();
            container = argContainer;
            container.Controls.Add(this);
            Link.Open(new GatewayReference(this, "empty"), linkparameters);
        }
       
        public void ProcessRequest(IContext objContext, string strAction)
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
            container.Controls.Remove(this);

            if (downloadedHandler != null)
            {
                downloadedHandler(this, true);
            }
           
        }

        private string getContentType(DownloadContentType arg)
        {
            switch(arg)
            {
              
                case DownloadContentType.MicrosoftWord:
                    return "application/x-msword";
                   
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

        [System.Diagnostics.DebuggerNonUserCode()]
        protected override void  Dispose(bool disposing)
        {
            if (disposing && components != null)
                components.Dispose();

             base.Dispose(disposing);
        }

        private System.ComponentModel.IContainer components;

        [System.Diagnostics.DebuggerStepThrough()]
        private void InitializeComponent()
        {
            components = new System.ComponentModel.Container();
        }
    }

    public enum DownloadContentType
    {
        OctetStream,
        MicrosoftExcel,
        MicrosoftWord,
        PlainText
    }
}


