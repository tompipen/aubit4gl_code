using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Collections;
using System.Text;
using System.Windows.Forms;


namespace AubitDesktop.Xml
{

    /// <remarks/>
    public class Protocol
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "string")]
        public string Code;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "string")]
        public string Command;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "string")]
        public string Name;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "string")]
        public string Description;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "boolean")]
        public bool ListenMode;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "string")]
        public string DefaultPort;
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = false)]
    public class Protocols
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlElementAttribute()]
        public Protocol[] Protocol;
    }


    /// <remarks/>
    public class Shortcuts
    {

        /// <remarks/>
        public List<Shortcut> Shortcut;
    }


    /// <remarks/>
    [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
    public class Shortcut
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "string")]
        public string Application;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "string")]
        public string Password;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "boolean")]
        public bool PromptForPassword;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "string")]
        public string Protocol;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "string")]
        public string Server;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "string")]
        public string User;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "string")]
        public string Title;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "string")]
        public string Port;
    }


    public class WindowPosition
    {
        public string windowName;
        public int w, h, x, y;
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = false)]
    public class Settings
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "string")]
        public string Port;

        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "string")]
        public string defaultEncoding;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "string")]
        public string AutoRun;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "boolean")]
        public bool AllowEdit;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "boolean")]
        public bool StartMinimized;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "boolean")]
        public bool ListenMode;

        /// <remarks/>
        [System.Xml.Serialization.XmlArrayItem(IsNullable = false)]
        public Protocol[] Protocols;

        public bool allowExec;
        public bool allowSendFile;
        public bool allowReceiveFile;
        public string interruptKey;
        public int yscale;
        public int xscale;

        /// <remarks/>
        //public Shortcuts Shortcuts;
        public List<Shortcut> Shortcuts;

        public List<WindowPosition> WindowPositions;
    }

}
