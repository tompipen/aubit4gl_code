using System.Configuration;

namespace AubitDesktop.Xml.Authentication
{


    /// <remarks/>
    public class User
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute]
        public string Name;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute]
        public string Password;
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = false)]
    public class Applications
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlElementAttribute("Application")]
        public Application[] Application;
    }

    /// <remarks/>
    public class Application
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute]
        public string Name;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute]
        public string Password;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string Port;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute]
        public string ProgramName;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute]
        public string Server;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute]
        public string Username;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string cmdLine;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string cwd;


        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute]
        public string connMode;

        /// <remarks/>
        [System.Xml.Serialization.XmlArrayItem(IsNullable = false)]
        public User[] Users;

    }

    /// <remarks/>
    [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = false)]
    public class Configuration
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute]
        public string AuthMode;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute]
        public string Name;

        /// <remarks/>
        [System.Xml.Serialization.XmlArrayItem(IsNullable = false)]
        public Application[] Applications;
    }






    public class ConfigurationSettings
    {
        public static string settingsFile
        {
            get
            {
                string s;
                s = ConfigurationManager.AppSettings["settingsFile"];
                if (s == null) s="settings.xml";

                return s;
                //return ConfigurationManager.AppSettings["settingsFile"];  
                //return ConfigurationSettings.AppSettings["settingsFile"];
            }
        }
    }

}
