using System;
using System.Collections.Generic;
using System.Text;


namespace AubitCalltreeViewer
{


    /// <remarks/>
    public class MENU
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public int LINE;

        /// <remarks/>
        [System.Xml.Serialization.XmlArrayItem(IsNullable = false)]
        public EVENT[] EVENTS;
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
    public class EVENT
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string EVENT_TYPE;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public int LINE;

        /// <remarks>Data for a normal event (if any) </remarks>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "NMTOKEN")]
        public string DATA;


        /// <remarks>Keys for a MENU option</remarks>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "NMTOKEN")]
        public string KEYS;

        /// <remarks>Menu option text</remarks>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "NMTOKEN")]
        public string SHORT;

        /// <remarks>Description for a MENU option</remarks>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "NMTOKEN")]
        public string LONG;
       

        /// <remarks/>
        public COMMANDS COMMANDS;
    }

    /// <remarks/>
    public class COMMANDS
    {



        /// <remarks/>
        [System.Xml.Serialization.XmlElementAttribute("CALLS", Type = typeof(CALLS))]
        [System.Xml.Serialization.XmlElementAttribute("CASE", Type = typeof(CASE))]
        [System.Xml.Serialization.XmlElementAttribute("CONSTRUCT", Type = typeof(CONSTRUCT))]
        [System.Xml.Serialization.XmlElementAttribute("DISPLAYARRAY", Type = typeof(DISPLAYARRAY))]
        [System.Xml.Serialization.XmlElementAttribute("FINISH", Type = typeof(FINISH))]
        [System.Xml.Serialization.XmlElementAttribute("FOR", Type = typeof(FOR))]
        [System.Xml.Serialization.XmlElementAttribute("FOREACH", Type = typeof(FOREACH))]
        [System.Xml.Serialization.XmlElementAttribute("WHENEVER", Type = typeof(WHENEVER))]
        [System.Xml.Serialization.XmlElementAttribute("IF", Type = typeof(IF))]
        [System.Xml.Serialization.XmlElementAttribute("INPUT", Type = typeof(INPUT))]
        [System.Xml.Serialization.XmlElementAttribute("INPUTARRAY", Type = typeof(INPUTARRAY))]
        [System.Xml.Serialization.XmlElementAttribute("MENU", Type = typeof(MENU))]
        [System.Xml.Serialization.XmlElementAttribute("OUTPUT", Type = typeof(OUTPUT))]
        [System.Xml.Serialization.XmlElementAttribute("PROMPT", Type = typeof(PROMPT))]
        [System.Xml.Serialization.XmlElementAttribute("START", Type = typeof(START))]
        [System.Xml.Serialization.XmlElementAttribute("WHILE", Type = typeof(WHILE))]
        public object[] Items;
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
    public class CALLS
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "NMTOKEN")]
        public string FUNCTIONNAME;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public int LINE;
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
    public class CASE
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public int LINE;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string TESTAGAINST;

        /// <remarks/>
        [System.Xml.Serialization.XmlElementAttribute()]
        public WHEN[] WHEN;
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
    public class WHEN
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string CONDITION;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public int LINE;

        /// <remarks/>
        public COMMANDS COMMANDS;
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
    public class CONSTRUCT
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public int LINE;

        /// <remarks/>
        [System.Xml.Serialization.XmlArrayItem(IsNullable = false)]
        public EVENT[] EVENTS;
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
    public class DISPLAYARRAY
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public int LINE;

        /// <remarks/>
        [System.Xml.Serialization.XmlArrayItem(IsNullable = false)]
        public EVENT[] EVENTS;
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
    public class FINISH
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public int LINE;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "NMTOKEN")]
        public string REPORT;
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
    public class FOR
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string END;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public int LINE;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string START;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string STEP;

        /// <remarks/>
        public COMMANDS COMMANDS;
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
    public class FOREACH
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public int LINE;

        /// <remarks/>
        public COMMANDS COMMANDS;
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
    public class WHENEVER
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string TYPE;

        /// <remarks/>
        public CALLS CALLS;
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
    public class IF
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string CONDITION;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public int LINE;

        /// <remarks/>
        [System.Xml.Serialization.XmlElementAttribute("ONFALSE", Type = typeof(ONFALSE))]
        [System.Xml.Serialization.XmlElementAttribute("ONTRUE", Type = typeof(ONTRUE))]
        public object[] Items;
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
    public class ONFALSE
    {

        /// <remarks/>
        public COMMANDS COMMANDS;
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public int LINE;
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
    public class ONTRUE
    {

        /// <remarks/>
        public COMMANDS COMMANDS;
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
    public class INPUT
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public int LINE;

        /// <remarks/>
        [System.Xml.Serialization.XmlArrayItem(IsNullable = false)]
        public EVENT[] EVENTS;
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
    public class INPUTARRAY
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public int LINE;

        /// <remarks/>
        [System.Xml.Serialization.XmlArrayItem(IsNullable = false)]
        public EVENT[] EVENTS;
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
    public class OUTPUT
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public int LINE;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "NMTOKEN")]
        public string REPORT;
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
    public class PROMPT
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public int LINE;

        /// <remarks/>
        [System.Xml.Serialization.XmlArrayItem(IsNullable = false)]
        public EVENT[] EVENTS;
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
    public class START
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public int LINE;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "NMTOKEN")]
        public string REPORT;
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
    public class WHILE
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string CONDITION;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public int LINE;

        /// <remarks/>
        public COMMANDS COMMANDS;
    }

    /// <remarks/>
    public class LINE
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlTextAttribute()]
        public string Text;

    }

    /// <remarks/>
    [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = false)]
    public class PROGRAM
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlArrayItem(IsNullable = false)]
        public MODULE[] MODULES;

        /// <remarks/>
        [System.Xml.Serialization.XmlElementAttribute()]
        public FUNCTION[] FUNCTION;


        /// <remarks/>
        [System.Xml.Serialization.XmlArrayItem(IsNullable = false)]
        public SYMBOL[] SYMBOLS;
    }

    [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
    public class SYMBOL
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string NAME;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string  MODULE;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public int LINE;

        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string TYPE;

        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string OPERATION;

        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string SCOPE;
        
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
    public class MODULE
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public int MODULENO;

        /// Relative filename for the file<remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string NAME;

                /// <remarks>Full filename for the code</remarks>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string FULLNAME;

         [System.Xml.Serialization.XmlArrayItem(IsNullable = false)]
        public VARIABLE[] GLOBAL_VARIABLES;

         [System.Xml.Serialization.XmlArrayItem(IsNullable = false)]
        public VARIABLE[] MODULE_VARIABLES;
        /// <remarks/>
        [System.Xml.Serialization.XmlElementAttribute()]
        public LINE[] LINE;
    }

    [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
    public class VARIABLE
    {
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string NAME;
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public int LINE;
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
    public class FUNCTION
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public int LINE;

        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string TYPE;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string MODULE;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public int  MODULENO;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute(DataType = "NMTOKEN")]
        public string NAME;

        [System.Xml.Serialization.XmlArrayItem(IsNullable = false)]
        public VARIABLE[] LOCAL_VARIABLES;

        /// <remarks/>
        public COMMANDS COMMANDS;
    }
}

