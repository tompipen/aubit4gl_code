{
	@(#)fglbldr.4gl	6.1 89/08/04
	@(#)FGLBLD: Produce shell script that produces code
	@(#)Author: JL
}

{
****************************************************************
This seems to be a relatively simple way of handling the problem
of generating a shell script with a diverse set of variables to
be initialised from random variables.  It is a great improvement
over what went before, which was 100% unmaintainable.
****************************************************************
}

GLOBALS "fglbldg.4gl"

DEFINE
	sccs		CHAR(1),
	filename	CHAR(40)

{ Produce SPI }
FUNCTION rd_fglbld1()

	DEFINE
		ans				CHAR(1),
		retval			INTEGER,
		i				INTEGER,
		ncolumns		INTEGER,
		pkvalue			CHAR(40),
		control_line	CHAR(80)

	LET sccs = "@(#)fglbldr.4gl	6.1 89/08/04"
	LET filename = mkfilename("/tmp/fglbldXXXXXX")
	START REPORT rf_fglbld1 TO filename

	{ Output variants of database name }
	OUTPUT TO REPORT rf_fglbld1(1, "Xdbase", UPSHIFT(dbase))
	OUTPUT TO REPORT rf_fglbld1(1, "xdbase", DOWNSHIFT(dbase))

	{ Output variants of table name }
	LET details.tabname = DOWNSHIFT(details.tabname)
	OUTPUT TO REPORT rf_fglbld1(1, "xtabname", details.tabname)
	OUTPUT TO REPORT rf_fglbld1(1, "xtable", details.tabname)
	LET details.tabname[1] = UPSHIFT(details.tabname[1])
	OUTPUT TO REPORT rf_fglbld1(1, "Xtable", details.tabname)

	{ Output details of Primary Key column }
	LET details.pkcol = DOWNSHIFT(details.pkcol)
	OUTPUT TO REPORT rf_fglbld1(1, "xpkey", details.pkcol)
	IF details.pkcol = "rowid" THEN
		LET pkvalue = "ct_", details.tabname clipped, ".rowid"
		LET pkvalue = DOWNSHIFT(pkvalue)
		OUTPUT TO REPORT rf_fglbld1(1, "xpkvalue", pkvalue)
		OUTPUT TO REPORT rf_fglbld1(1, "Xpkey_dec", "Y")
	END IF
	LET details.pkcol[1] = UPSHIFT(details.pkcol[1])
	OUTPUT TO REPORT rf_fglbld1(1, "Xpkey", details.pkcol)
	OUTPUT TO REPORT rf_fglbld1(1, "Xpktype", typestr)

	{ Output details of menu name and program name }
	OUTPUT TO REPORT rf_fglbld1(1, "Xmenu", details.menuname)
	OUTPUT TO REPORT rf_fglbld1(1, "Xform", details.basename)
	OUTPUT TO REPORT rf_fglbld1(1, "program", details.basename)

	{ Output complete list of columns }
	{ "Column 1" is "ROWID" -- do not print it }
	OUTPUT TO REPORT rf_fglbld1(1, "Xcollist", "")	# Empty list
	LET ncolumns = num_columns()
	FOR i = 2 TO ncolumns
		OUTPUT TO REPORT rf_fglbld1(2, "Xcollist", get_colname(i))
	END FOR

	{ Output options required }
	OUTPUT TO REPORT rf_fglbld1(1, "Xopt_ins", optlist.opt_ins)
	OUTPUT TO REPORT rf_fglbld1(1, "Xopt_del", optlist.opt_del)
	OUTPUT TO REPORT rf_fglbld1(1, "Xopt_upd", optlist.opt_upd)
	OUTPUT TO REPORT rf_fglbld1(1, "Xopt_rep", optlist.opt_rep)
	OUTPUT TO REPORT rf_fglbld1(1, "Xopt_sh", optlist.opt_sh)
	OUTPUT TO REPORT rf_fglbld1(1, "Xafterfield", optlist.afterfield)
	OUTPUT TO REPORT rf_fglbld1(1, "Xbeforefield", optlist.beforefield)
	OUTPUT TO REPORT rf_fglbld1(1, "Xcontrolp", optlist.controlp)
	OUTPUT TO REPORT rf_fglbld1(1, "Xcontrolb", optlist.controlb)

	{ Specify program to be run }
	OUTPUT TO REPORT rf_fglbld1(3, "fglbld.alt", "")

	FINISH REPORT rf_fglbld1

	LET control_line = "sh ", filename CLIPPED
	RUN control_line RETURNING retval
	PROMPT "Hit return to continue" FOR CHAR ans
	RETURN retval

END FUNCTION {rd_fglbld1}

{ Produce select code }
FUNCTION rd_fglbld2(progname)

	DEFINE
		ans				CHAR(1),
		progname		CHAR(14),
		retval			INTEGER,
		i				INTEGER,
		ncolumns		INTEGER,
		control_line	CHAR(80)

	LET filename = mkfilename("/tmp/fglbldXXXXXX")
	START REPORT rf_fglbld1 TO filename

	{ Output variants of database name }
	OUTPUT TO REPORT rf_fglbld1(1, "Xdbase", UPSHIFT(dbase))

	{ Output variants of table name }
	LET details.tabname = DOWNSHIFT(details.tabname)
	OUTPUT TO REPORT rf_fglbld1(1, "xtabname", details.tabname)
	OUTPUT TO REPORT rf_fglbld1(1, "xtable", details.tabname)
	LET details.tabname[1] = UPSHIFT(details.tabname[1])
	OUTPUT TO REPORT rf_fglbld1(1, "Xtable", details.tabname)

	{ Output details of Primary Key column }
	LET details.tabname = DOWNSHIFT(details.pkcol)
	OUTPUT TO REPORT rf_fglbld1(1, "xpkey", details.pkcol)
	LET details.pkcol[1] = UPSHIFT(details.pkcol[1])
	OUTPUT TO REPORT rf_fglbld1(1, "Xpkey", details.pkcol)
	OUTPUT TO REPORT rf_fglbld1(1, "Xpktype", typestr)
	IF details.pkcol = "ROWID" THEN
		OUTPUT TO REPORT rf_fglbld1(1, "ROWID", "yes")
	END IF

	{ Output details of program name }
	OUTPUT TO REPORT rf_fglbld1(1, "program", details.basename)

	{ Specify program to be run }
	OUTPUT TO REPORT rf_fglbld1(3, progname, "")

	FINISH REPORT rf_fglbld1

	LET control_line = "sh ", filename CLIPPED
	RUN control_line RETURNING retval
	PROMPT "Hit return to continue" FOR CHAR ans
	RETURN retval

END FUNCTION {rd_fglbld2}

{ Produce lookup code }
FUNCTION rd_fglbld3(progname)

	DEFINE
		ans				CHAR(1),
		progname		CHAR(14),
		retval			INTEGER,
		i				INTEGER,
		ncolumns		INTEGER,
		control_line	CHAR(80)

	LET filename = mkfilename("/tmp/fglbldXXXXXX")
	START REPORT rf_fglbld1 TO filename

	{ Output variants of database name }
	OUTPUT TO REPORT rf_fglbld1(1, "Xdbase", UPSHIFT(dbase))
	OUTPUT TO REPORT rf_fglbld1(1, "xdbase", DOWNSHIFT(dbase))

	{ Output variants of table name }
	LET details.tabname = DOWNSHIFT(details.tabname)
	OUTPUT TO REPORT rf_fglbld1(1, "xtabname", details.tabname)
	OUTPUT TO REPORT rf_fglbld1(1, "xtable", details.tabname)
	LET details.tabname[1] = UPSHIFT(details.tabname[1])
	OUTPUT TO REPORT rf_fglbld1(1, "Xtable", details.tabname)

	{ Output details of Primary Key column }
	LET details.tabname = DOWNSHIFT(details.pkcol)
	OUTPUT TO REPORT rf_fglbld1(1, "xpkey", details.pkcol)
	LET details.pkcol[1] = UPSHIFT(details.pkcol[1])
	OUTPUT TO REPORT rf_fglbld1(1, "Xpkey", details.pkcol)
	OUTPUT TO REPORT rf_fglbld1(1, "Xpktype", typestr)
	IF details.pkcol = "ROWID" THEN
		OUTPUT TO REPORT rf_fglbld1(1, "ROWID", "yes")
	END IF

	{ Output details of menu name and program name }
	OUTPUT TO REPORT rf_fglbld1(1, "Xmenu", details.menuname)
	OUTPUT TO REPORT rf_fglbld1(1, "Xform", details.basename)
	OUTPUT TO REPORT rf_fglbld1(1, "program", details.basename)
	OUTPUT TO REPORT rf_fglbld1(1, "Xselected", name_selected)

	{ Specify program to be run }
	OUTPUT TO REPORT rf_fglbld1(3, progname, "")

	FINISH REPORT rf_fglbld1

	LET control_line = "sh ", filename CLIPPED
	RUN control_line RETURNING retval
	PROMPT "Hit return to continue" FOR CHAR ans
	RETURN retval

END FUNCTION {rd_fglbld3}

{ Generic report for producing code }
REPORT rf_fglbld1(tag, varname, varvalue)

	DEFINE
		tag			INTEGER,
		varname		CHAR(20),
		varvalue	CHAR(40),
		progname	CHAR(14)

	OUTPUT
		PAGE LENGTH 1
		TOP MARGIN 0
		BOTTOM MARGIN 0
		LEFT MARGIN 0

	FORMAT

	ON EVERY ROW
		CASE tag
		WHEN 1	{ Ordinary variable }
			PRINT
				varname CLIPPED, "=", ASCII(34),
				varvalue CLIPPED, ASCII(34),
				" export ", varname CLIPPED
		WHEN 2	{ Cumulative variable }
			PRINT
				varname CLIPPED, "=", ASCII(34),
				"$", varname CLIPPED, " ",
				varvalue  CLIPPED, ASCII(34)
		WHEN 3 { Command to be executed }
			LET progname = varname CLIPPED
		END CASE

	ON LAST ROW
		{ Output code to be executed }
		PRINT "trap 'rm -f ", filename CLIPPED, "; exit 1' 1 2 3 14 15"
		PRINT progname CLIPPED
		PRINT "if [ $DEBUG ] ; then echo ", filename CLIPPED
		PRINT "else rm -f ", filename CLIPPED, " ; fi"

END REPORT {rf_fglbld1}
