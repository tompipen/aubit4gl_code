-- @(#)$Id: tomake.4gl,v 1.1 2004-10-21 10:23:06 afalout Exp $
--
-- :PRODUCT:
--
-- D4GL Makefile Generator

-- This version is not safe for use with MODE ANSI databases where the
-- program design database tables are not owned by the user running this
-- program.

-- A REPORT cannot be used to generate to stdout (START REPORT will
-- try to open the report viewer).

DEFINE
        QQCHAR      CHAR(1),
        TABCHAR     CHAR(1),
        version     CHAR(60),
        pname       CHAR(10),
        i4gl        SMALLINT,
        rules       SMALLINT,
        source4gl   RECORD
                    progname         CHAR(10),
                    ppath            CHAR(40),
                    fglsourcename    CHAR(10),
                    spath            CHAR(40)
                    END RECORD,
        sourceother RECORD
                    progname         CHAR(10),
                    ppath            CHAR(40),
                    othersourcename  CHAR(10),
                    extension        CHAR(3),
                    spath            CHAR(40)
                    END RECORD,
        libraries   RECORD
                    progname         CHAR(10),
                    ppath            CHAR(40),
                    libraries        CHAR(9)
                    END RECORD,
        opts        RECORD
                    progname         CHAR(10),
                    ppath            CHAR(40),
                    OPTIONS          CHAR(8)
                    END RECORD,
        otherobj    RECORD
                    progname         CHAR(10),
                    ppath            CHAR(40),
                    othername        CHAR(10),
                    opath            CHAR(40)
                    END RECORD,
        listfile    ARRAY[500] OF RECORD
                    progname         CHAR(10),
                    ppath            CHAR(40),
                    fglsourcename    CHAR(10),
                    spath            CHAR(40)
                    END RECORD,
        lf_count    INTEGER,
        lw_count    INTEGER,
        srcolist    ARRAY[500] OF RECORD
                    progname         CHAR(10),
                    ppath            CHAR(40),
                    othersourcename  CHAR(10),
                    extension        CHAR(3),
                    spath            CHAR(40)
                    END RECORD,
        so_count   INTEGER

MAIN

    DEFINE dbname   CHAR(40)
    DEFINE arg0     CHAR(40)
    DEFINE stmt     CHAR(512)
    DEFINE optval   CHAR(1)
    DEFINE optarg   CHAR(80)
    DEFINE optstr   CHAR(10)

    -- Set global variables
    LET TABCHAR = ASCII(9)  -- tab
    LET QQCHAR = ASCII(34)  -- double quote
    LET i4gl = FALSE
    LET pname = NULL
    LET rules = FALSE
    LET version = "TOMAKE Version 1.02 (1998-08-04)"

    -- Get project database name from environment variable
    LET dbname = FGL_GETENV("PROGRAM_DESIGN_DBS")
    IF dbname IS NULL OR dbname = ' ' THEN
        LET dbname = "syspgm4gl"
    END IF

    LET optstr = "d:hirV"
    CALL i4gl_getopt(optstr) RETURNING optval, optarg
    WHILE optval IS NOT NULL
        CASE optval
        WHEN "d"
            LET dbname = optarg
        WHEN "i"
            LET i4gl = TRUE
        WHEN "r"
            LET rules = TRUE
        WHEN "V"
            DISPLAY version CLIPPED
            EXIT PROGRAM 0
        WHEN "-"
            IF pname IS NOT NULL THEN
                DISPLAY "More than one program name specified"
                CALL display_usage()
                EXIT PROGRAM 1
            ELSE
                LET pname = optarg
            END IF
        OTHERWISE
            CALL display_usage()
            EXIT PROGRAM 1
        END CASE
        CALL i4gl_getopt(optstr) RETURNING optval, optarg
    END WHILE

    IF pname IS NULL THEN
       CALL display_usage()
       EXIT PROGRAM 1
    END IF

    DATABASE dbname

    -- ======= Create complete list of source code files.

    -- Note that this includes globals files for I4GL-RDS.
    -- Generated makefile does not include dependency on globals files.
    -- Allow for archaic databases where the I4GL and R4GL structures
    -- are not the same (but note that since 4.13/6.01, the databases
    -- have been identical, even though the globals table is not used
    -- by i4gl and the sourceother, opts and libraries tables are not
    -- used by r4gl).
    LET stmt = "SELECT * FROM Source4gl S WHERE S.Progname = '",
                pname CLIPPED, "'"
    IF check_table("global") THEN
        LET stmt = stmt CLIPPED, " UNION SELECT * FROM Global G",
                    " WHERE G.Progname = '", pname CLIPPED, "'"
    END IF
    PREPARE p_source FROM stmt
    DECLARE source4gl CURSOR FOR p_source
    OPEN source4gl
    LET lf_count = 1
    FETCH source4gl INTO source4gl.*
    IF STATUS = NOTFOUND THEN
        DISPLAY "Unknown program name: ", pname CLIPPED
        EXIT PROGRAM 1
    END IF
    LET listfile[lf_count].* = source4gl.*
    WHILE TRUE
        FETCH source4gl INTO source4gl.*
        IF STATUS = NOTFOUND THEN
            EXIT WHILE
        END IF
        LET lf_count = lf_count + 1
        LET listfile[lf_count].* = source4gl.*
    END WHILE

    -- ======= Create list of other sources.
    LET stmt = "SELECT * FROM SourceOther S WHERE S.Progname = '",
                pname CLIPPED, "'"
    PREPARE p_sourceother FROM stmt
    DECLARE c_sourceother CURSOR FOR p_sourceother
    LET so_count = 0
    FOREACH c_sourceother INTO srcolist[so_count+1].*
        LET so_count = so_count + 1
    END FOREACH

    -- Create the Makefile
    CALL generate_makefile()

END MAIN

FUNCTION display_usage()

    DEFINE
        progname   CHAR(40)

    LET progname = fgl_cmdarg_progname()
    DISPLAY "Usage: ", progname CLIPPED, " [-hirV] [-d database] progname"
    DISPLAY "Where options are :"
    DISPLAY "   -d database     : Use this database instead of syspgm4gl"
    DISPLAY "   -h              : Display this help message"
    DISPLAY "   -i              : Generate rules for I4GL"
    DISPLAY "   -r              : Use the d4gl.mk and i4gl.mk rules files"
    DISPLAY "   -V              : Print version and exit"

END FUNCTION {display_usage}

FUNCTION generate_makefile()

    DEFINE sline CHAR(512)

    DISPLAY "# -- Makefile for program ", pname CLIPPED
    DISPLAY "# -- Generated by: ", version CLIPPED
    DISPLAY ""
    IF rules THEN
        DISPLAY "include d4gl.mk"
        IF i4gl THEN
            DISPLAY "include i4gl.mk"
        END IF
    ELSE
        LET sline = ".SUFFIXES: .4gl .42e .42o .per .42f .42m .42r .o"
        IF i4gl THEN
            LET sline = sline CLIPPED, " .4gi .4go .o .4ge .frm"
        END IF
        DISPLAY sline CLIPPED
    END IF

    DISPLAY ""
    DISPLAY "42R = ", source4gl.progname CLIPPED, ".42r"
    DISPLAY "42E = ", source4gl.progname CLIPPED, ".42e"
    IF i4gl THEN
        DISPLAY "4GE = ", source4gl.progname CLIPPED, ".4ge"
        DISPLAY "4GI = ", source4gl.progname CLIPPED, ".4gi"
    END IF
    DISPLAY ""
    DISPLAY "# --- Add the names of the form files for this program"
    DISPLAY "FORMS_42F = "
    DISPLAY ""
    IF i4gl THEN
        DISPLAY "FORMS_FRM = "
        DISPLAY ""
    END IF

    DISPLAY "# --- List of other sources"
    CALL generate_srcolist()
    DISPLAY ""

    DISPLAY "# --- D4GL C-code Object files"
    CALL generate_objlist("OBJECTS_42O", "42o")
    DISPLAY ""

    DISPLAY "# --- D4GL P-code Module files"
    CALL generate_objlist("OBJECTS_42M", "42m")
    DISPLAY ""

    IF i4gl THEN
        DISPLAY "# --- I4GL object files"
        CALL generate_objlist("OBJECTS_O  ", "o")
        DISPLAY ""
        DISPLAY "# --- I4GL-RDS object files"
        CALL generate_objlist("OBJECTS_4GO", "4go")
        DISPLAY ""
    END IF

    # Default rule
    DISPLAY ""
    DISPLAY "# Program-specific compilation rules"
    DISPLAY "all: 42r"
    DISPLAY TABCHAR, "@echo ", QQCHAR, "Use: '${MAKE} 42e' to create D4GL c-code executable", QQCHAR
    DISPLAY TABCHAR, "@echo ", QQCHAR, "Use: '${MAKE} 4gi' to create I4GL p-code executable", QQCHAR
    DISPLAY TABCHAR, "@echo ", QQCHAR, "Use: '${MAKE} 4ge' to create I4GL c-code executable", QQCHAR

    IF rules THEN
        CALL standard_makerules()
    ELSE
        CALL inline_makerules()
    END IF

    DISPLAY ""

END FUNCTION {generate_makefile}

FUNCTION standard_makerules()

    # 42e rule
    DISPLAY ""
    DISPLAY "42e: $(42E) $(FORMS_42F)"
    DISPLAY ""
    DISPLAY "$(42E):  $(OBJECTS_42O)"
    DISPLAY TABCHAR, "$(D4GL_CL) -o $(42E) $(OBJECTS_42O) $(D4GL_CL_LDFLAGS)"

    # 42r rule
    DISPLAY ""
    DISPLAY "42r: $(42R) $(FORMS_42F)"
    DISPLAY ""
    DISPLAY "$(42R):  $(OBJECTS_42M)"
    DISPLAY TABCHAR, "$(D4GL_PL) -o $(42R) $(OBJECTS_42M) $(D4GL_PL_LDFLAGS)"

    # 4ge rule
    DISPLAY ""
    DISPLAY "4ge: $(4GE) $(FORMSFRM)"
    DISPLAY ""
    DISPLAY "$(4GE):  $(OBJECTS_O)"
    DISPLAY TABCHAR, "$(I4GL_CL) -o $(4GE) $(OBJECTS_O)   $(I4GL_CL_LDFLAGS)"

    # 4gi rule
    DISPLAY ""
    DISPLAY "4gi: $(4GI) $(FORMSFRM)"
    DISPLAY ""
    DISPLAY "$(4GI):  $(OBJECTS_4GO)"
    DISPLAY TABCHAR, "$(I4GL_PL) -o $(4GI) $(OBJECTS_4GO) $(I4GL_PL_LDFLAGS)"

END FUNCTION {standard_makerules}

FUNCTION inline_makerules()

    DISPLAY "all: 42r"

    # 42e rules
    DISPLAY ""
    DISPLAY "42e: $(42E) $(FORMS_42F)"
    DISPLAY ""
    DISPLAY "$(42E):  $(OBJECTS_42O) $(OTHERSRCS)"
    DISPLAY TABCHAR, "fgl2c -o $(42E) $(OBJECTS_42O)"

    # 42r rules
    DISPLAY ""
    DISPLAY "42r: $(42R) $(FORMS_42F)"
    DISPLAY ""
    DISPLAY "$(42R):  $(OBJECTS_42M) $(OTHERSRCS)"
    DISPLAY TABCHAR, "fgl2p -o $(42R) $(OBJECTS_42M)"

    IF i4gl THEN
        # 4ge rules
        DISPLAY ""
        DISPLAY "4ge: $(4GE) $(FORMS_FRM)"
        DISPLAY ""
        DISPLAY "$(4GE):  $(OBJECTS_O) $(OTHERSRCS)"
        DISPLAY TABCHAR, "c4gl -o $(4GE) $(OBJECTS_O)"
        # 4gi rules
        DISPLAY ""
        DISPLAY "4gi: $(4GI) $(FORMS_FRM)"
        DISPLAY ""
        DISPLAY "$(4GI):  $(OBJECTS_4GO) $(OTHERSRCS)"
        DISPLAY TABCHAR, "cat $(OBJECTS_4GO) > $(4GI)"
    END IF

    DISPLAY ""
    DISPLAY "# --- Generic suffix rules for compiling D4GL"
    DISPLAY ".per.42f:"
    DISPLAY TABCHAR, "fglform $*.per"
    DISPLAY ""
    DISPLAY ".4gl.42o:"
    DISPLAY TABCHAR, "fgl2c -c $*.4gl"
    DISPLAY ""
    DISPLAY ".4gl.42m:"
    DISPLAY TABCHAR, "fgl2p -c $*.4gl"
    DISPLAY ""

    IF i4gl THEN
        DISPLAY ""
        DISPLAY "# --- Generic suffix rules for compiling I4GL"
        DISPLAY ".per.frm:"
        DISPLAY TABCHAR, "form4gl $*.per"
        DISPLAY ""
        DISPLAY ".4gl.o:"
        DISPLAY TABCHAR, "c4gl -c $*.4gl"
        DISPLAY ""
        DISPLAY ".4gl.4go:"
        DISPLAY TABCHAR, "fglpc -c $*.4gl"
    END IF

END FUNCTION {inline_makerules}

FUNCTION generate_srcolist()

    DEFINE
        i           INTEGER,
        x           INTEGER,
        ext         CHAR(4),
        sline       CHAR(512),
        spart       CHAR(512)

  IF so_count=0 THEN

     DISPLAY "OTHERSRCS = "

  ELSE

     FOR i = 1 TO so_count

      IF i = 1 THEN
          LET sline = "OTHERSRCS = $"
      ELSE
          LET sline = "            $"
      END IF

      IF srcolist[i].spath IS NOT NULL THEN
          LET spart = srcolist[i].spath CLIPPED, "/$"
          LET sline = addstr(sline, spart)
      END IF

      LET ext   = srcolist[i].extension
      IF ext[1,1] = "." THEN
         LET ext = ext[2,4]
      END IF
      LET spart = srcolist[i].othersourcename CLIPPED, ".", ext CLIPPED, "$"
      LET sline = addstr(sline, spart)

      IF i <> so_count THEN
          LET sline = addstr(sline, " \\")
      ELSE
          LET sline = addstr(sline, "")
      END IF

      DISPLAY sline CLIPPED

     END FOR

  END IF

END FUNCTION {generate_srcolist}

FUNCTION generate_objlist(vname, ext)

    DEFINE
        vname       CHAR(30),
        ext         CHAR(3)
    DEFINE
        i           INTEGER,
        x           INTEGER,
        bfill       CHAR(40),
        sline       CHAR(512),
        spart       CHAR(512)

  LET x = LENGTH(vname) + 3
  LET bfill = " "
  LET bfill = bfill[1,x], "$"

  FOR i = 1 TO lf_count

      IF i=1 THEN
          LET sline = vname CLIPPED, " = $"
      ELSE
          LET sline = bfill CLIPPED
      END IF

      IF listfile[i].spath IS NOT NULL THEN
          LET spart = listfile[i].spath CLIPPED, "/$"
          LET sline = addstr(sline, spart)
      END IF

      LET spart = listfile[i].fglsourcename CLIPPED, ".", ext CLIPPED, "$"
      LET sline = addstr(sline, spart)

      IF i <> lf_count THEN
          LET sline = addstr(sline, " \\")
      ELSE
          LET sline = addstr(sline, "")
      END IF

      DISPLAY sline CLIPPED

  END FOR

END FUNCTION {generate_objlist}

FUNCTION check_table(tabname)

    DEFINE tabname  CHAR(18)
    DEFINE tabid    INTEGER
    DEFINE rc       INTEGER

    SELECT T.Tabid
        INTO tabid
        FROM 'informix'.systables T
        WHERE T.TabName = tabname

    LET rc = (SQLCA.SQLCODE = 0)

    RETURN rc

END FUNCTION {check_table}

-- Add string part to end of string src after chopping the last character in src
FUNCTION addstr(src,part)

    DEFINE
        src    CHAR(256),
        part   CHAR(256)
    DEFINE
        res    CHAR(512),
        x      SMALLINT

    LET x = LENGTH(src) - 1
    IF x > 0 THEN
       LET res = src[1,x], part CLIPPED
    ELSE
       LET res = part CLIPPED
    END IF

    RETURN res

END FUNCTION {addstr}

-- Determine basename of program
FUNCTION fgl_cmdarg_progname()

    DEFINE
        len         INTEGER,
        idx         INTEGER,
        start       INTEGER,
        end         INTEGER,
        fstart      SMALLINT,
        fend        SMALLINT,
        result      CHAR(50),
        pname       CHAR(50)

    LET result = NULL

    LET pname = arg_val(0)
    LET len = LENGTH(pname)
    LET start = 1
    LET end   = len
    LET fstart = FALSE
    LET fend   = FALSE

    FOR idx = len TO 1 STEP -1

        IF NOT fstart AND
           (
              (pname[idx,idx] = "/")    # UNIX separator
           OR (pname[idx,idx] = "\\")   # Windows/DOS separator
          )
        THEN
           LET start = idx + 1
           LET fstart = TRUE
        END IF

        IF NOT fend AND NOT fstart AND
           (pname[idx,idx] = ".")
        THEN
           LET end = idx - 1
           LET fend = TRUE
        END IF

        IF fstart AND fend THEN
           EXIT FOR
        END IF

    END FOR

    LET result = pname[start, end]

    RETURN result CLIPPED

END FUNCTION {fgl_cmdarg_progname}

