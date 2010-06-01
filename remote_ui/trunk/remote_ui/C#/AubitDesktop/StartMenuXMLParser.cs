using System;
using System.Collections.Generic;
using System.Text;

namespace AubitDesktop.Xml
{


    /// <remarks/>
    public class StartMenuGroup
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string text;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string name;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public int disabled;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string image;


        /// <remarks/>
        [System.Xml.Serialization.XmlElementAttribute("StartMenuCommand", Type = typeof(StartMenuCommand))]
        [System.Xml.Serialization.XmlElementAttribute("StartMenuGroup", Type = typeof(StartMenuGroup))]
        public object[] Items;
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
    public class StartMenuCommand
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string exec;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string text;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string image;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string name;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public int disabled;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public int waiting;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public int isEvent;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string hotKey;

    }

    /// <remarks/>
    [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = false)]
    public class StartMenu
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string text;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string name;

        /// <remarks/>
        [System.Xml.Serialization.XmlElementAttribute()]
        public StartMenuGroup[] StartMenuGroup;
    }









    /// <remarks/>
    public class ToolBarItem
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "NMTOKEN")]
        public string image;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "NMTOKEN")]
        public string name;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "NMTOKEN")]
        public string text;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "NMTOKEN")]
        public string comment;


        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "NMTOKEN")]
        public string hidden;

        /// <summary>
        /// hotKey allows you to define an alternate hotkey for this button..
        /// Should be in the format [Control-][Shift-][Alt-]Keyname
        /// </summary>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "NMTOKEN")]
        public string hotKey;
    }

    /// <remarks/>
    public class ToolBarSeparator
    {
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "NMTOKEN")]
        public string hidden;
    }


    /// <remarks/>
    [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = false)]
    public class ToolBar
    {
        /// <summary>
        /// height of the toolbar (Aubit Extension)
        /// </summary>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "NMTOKEN")]
        public string height;

        /// <summary>
        /// Size of the images on the toolbar (Aubit Extension)
        /// </summary>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "NMTOKEN")]
        
        public string imageSize;

        /// <remarks/>
        [System.Xml.Serialization.XmlElementAttribute("ToolBarItem", Type = typeof(ToolBarItem))]
        [System.Xml.Serialization.XmlElementAttribute("ToolBarSeparator", Type = typeof(ToolBarSeparator))]
        public object[] Items;
    }

   
}