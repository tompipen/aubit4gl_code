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

        [System.Xml.Serialization.XmlAttributeAttribute()]
        public int LINE;

        [System.Xml.Serialization.XmlAttributeAttribute()]
        public int LASTLINE;

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
        [System.Xml.Serialization.XmlElementAttribute("SECTION", Type = typeof(SECTION))]
        public object[] Items;
    }


    [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
    public class SECTION
    {
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public int ID;

        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string TYPE;

        [System.Xml.Serialization.XmlAttributeAttribute()]
        public int LINE;

        /// <remarks/>
        public COMMANDS COMMANDS;
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

        /// <remarks/>
        [System.Xml.Serialization.XmlArrayItem(IsNullable = false)]
        public ENV[] ENVIRONMENTVARS;

        /// <remarks/>
        [System.Xml.Serialization.XmlArrayItem(IsNullable = false)]
        public SQL[] OTHERSQLS;

        /// <remarks/>
        [System.Xml.Serialization.XmlArrayItem(IsNullable = false)]
        public PREPARE[] DYNAMICSQLS;

        /// <remarks/>
        [System.Xml.Serialization.XmlArrayItem(IsNullable = false)]
        public INSERT_STMT[] INSERTS;

        /// <remarks/>
        [System.Xml.Serialization.XmlArrayItem(IsNullable = false)]
        public DELETE_STMT[] DELETES;

        /// <remarks/>
        [System.Xml.Serialization.XmlArrayItem(IsNullable = false)]
        public UPDATE_STMT[] UPDATES;

        /// <remarks/>
        [System.Xml.Serialization.XmlArrayItem(IsNullable = false)]
        public SELECT_STMT[] SELECTS;


        /// <remarks/>
        [System.Xml.Serialization.XmlArrayItem(IsNullable = false)]
        public RUN_STMT[] RUN;

        /// <remarks/>
        [System.Xml.Serialization.XmlArrayItem(IsNullable = false)]
        public FORM[] FORMS;

        /// <remarks/>
        [System.Xml.Serialization.XmlArrayItem(IsNullable = false)]
        public FILE[] FILES;

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

        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string VALUE;
        
    }


    public class FORM
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string SOURCE;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string MODULE;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public int LINE;

        [System.Xml.Serialization.XmlTextAttribute()]
        public string Text;   

    }


    public class FILE
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string OPERATION;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string FILENAME;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string MODULE;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public int LINE;


    }


    public class RUN_STMT
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string CMD;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string MODULE;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public int LINE;

    }

    public class SELECT_STMT
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string TABLE;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string MODULE;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public int LINE;

        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string MAINACTION;
    }

    public class INSERT_STMT
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string TABLE;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string MODULE;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public int LINE;

        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string MAINACTION;
    }

    public class UPDATE_STMT
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string TABLE;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string MODULE;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public int LINE;

        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string MAINACTION;
    }


    public class PREPARE
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string STMTID;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string STMT;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string MODULE;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public int LINE;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public int PROCESSED;

    }

    public class SQL
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string STMT;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string MODULE;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public int LINE;

    }


    public class ENV
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string NAME;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string MODULE;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public int LINE;

    }



    public class DELETE_STMT
    {

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string TABLE;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string MODULE;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public int LINE;

        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string MAINACTION;
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

        /// Relative filename for the file<remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public int LIBRARY;

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

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public int LASTLINE;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public bool CALLED;

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

