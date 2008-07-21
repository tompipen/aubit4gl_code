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
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = false)]
    public class StartMenu
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string text;

        /// <remarks/>
        [System.Xml.Serialization.XmlElementAttribute()]
        public StartMenuGroup[] StartMenuGroup;
    }
}