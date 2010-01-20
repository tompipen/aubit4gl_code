using System;
using System.Collections.Generic;
using System.Text;

using Gizmox.WebGUI.Forms;
using Gizmox.WebGUI.Common;
using Gizmox.WebGUI.Common.Interfaces;
using Gizmox.WebGUI.Common.Gateways;

using System.IO;
using System.Web;



// Code lifed from a post on the VWG forums 
// by  	 awesterhold
// Under "Downloading file problem" in the  Forum  General Visual ...  How do I...?  forum
//
// (dont think a direct link will work)
//
namespace ISupportTrack
{
    [MetadataTag("KonectCommonVWG.FileDownloadGateway")]
    public class FileDownloadGateway : Control , IGatewayComponent
    {
        private string contenttype;
        private ContainerControl container;
        private Stream stream;
        private string filepath;
        private Byte[] bytes;

        public string Filename;
        public LinkParameters linkparameters = new LinkParameters();
        public Boolean downloadattachment = true;

        public FileDownloadGateway()
        {
            linkparameters.Target = "_self";
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
            container = argContainer;
            container.Controls.Add(this);
            Link.Open(new GatewayReference(this, "Download"), linkparameters);
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
           
        }

        private string getContentType(DownloadContentType arg)
        {
            switch(arg)
            {
              
                case DownloadContentType.MicrosoftWord:
                    return "application/x-msword";
                    break;
                case DownloadContentType.MicrosoftExcel:
                    return "application/x-msexcel";
                    break;
                case DownloadContentType.PlainText:
                    return "text/plain";
                default:
                    return "application/octet-stream";
                    break;

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



     static class FGLWebUtils
    {

    }
}
