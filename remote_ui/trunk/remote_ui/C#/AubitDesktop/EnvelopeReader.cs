
using System.Xml.Serialization;
using System.Xml;
using System.IO;
using System.Collections;

namespace AubitDesktop
{   
    //
    //  *** NOTE TO SELF ***
    //
    // This class uses a ENVELOPE c# module which is automatically generated on my DELL2800 server by a script
    // in the ~aubit4gl/cm/proxy/xml2cs directory called 'xml2cs'
    // that script converts an XML document to a DTD, then converts that to a XSD
    // then uses mono to generate the C# class code to deserialize the whole thing...
    // The output from that command is copied to /tmp and should then be copied into the Application source
    // directory (its called samp.cs)


    public class EnvReader
    {
        static private string theXmlString;
        public static ENVELOPE ReadFromXml(string s)
        {
            ENVELOPE newEnvelope;
            System.Type t;
            t = typeof(ENVELOPE);
            XmlSerializer ser;

            ser= new XmlSerializer(t);
            theXmlString = s;

            //s = "<ENVELOPE><COMMANDS><PROGRAMSTOP/></COMMANDS></ENVELOPE>";
            TextReader r = new StringReader(s);

            
            
            ser.UnknownAttribute += new XmlAttributeEventHandler(ser_UnknownAttribute);
            ser.UnknownElement += new XmlElementEventHandler(ser_UnknownElement);
            ser.UnknownNode += new XmlNodeEventHandler(ser_UnknownNode);
            newEnvelope = (ENVELOPE)ser.Deserialize(r);
            return newEnvelope;
        }

        static void ser_UnknownNode(object sender, XmlNodeEventArgs e)
        {
            throw new System.Exception("Unknown Node in Node : "+e.Name+" Line Position "+e.LinePosition+" Line Number : "+e.LineNumber+" in \n"+theXmlString);
        }

        static void ser_UnknownElement(object sender, XmlElementEventArgs e)
        {
            throw new System.Exception("Unknown Element");
        }

        static void ser_UnknownAttribute(object sender, XmlAttributeEventArgs e)
        {
            throw new System.Exception("Unknown Attribute");
        }
    }
}
