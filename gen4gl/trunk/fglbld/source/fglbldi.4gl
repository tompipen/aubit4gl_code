{
	@(#)fglbldi.4gl	6.6 89/10/16
	@(#)FGLBLD: Get details of SPI to be created
	@(#)Adapted from a generated input file for a table called spi
	@(#)Author: JL
}

GLOBALS "fglbldg.4gl"

{ Module variables -- not accessible outside this file }
DEFINE
	prev_field	INTEGER,				{ Number of previous field }
	n_fields	INTEGER,
	iomode		CHAR(1),	{ I for input, U for update }
	sccs		CHAR(32)	{ Identifier string }

{ Display working record }
FUNCTION dis_spi()

	DISPLAY BY NAME details.*, optlist.*

END FUNCTION {dis_spi}

{ Help function }
FUNCTION help_spi()

	CASE
	WHEN INFIELD(tabname)		CALL SHOWHELP(100)
	WHEN INFIELD(pkcol)			CALL SHOWHELP(101)
	WHEN INFIELD(menuname)		CALL SHOWHELP(102)
	WHEN INFIELD(basename)		CALL SHOWHELP(103)
	WHEN INFIELD(opt_ins)		CALL SHOWHELP(104)
	WHEN INFIELD(afterfield)	CALL SHOWHELP(105)
	WHEN INFIELD(beforefield)	CALL SHOWHELP(106)
	WHEN INFIELD(controlb)		CALL SHOWHELP(107)
	WHEN INFIELD(controlp)		CALL SHOWHELP(108)
	WHEN INFIELD(opt_del)		CALL SHOWHELP(109)
	WHEN INFIELD(opt_upd)		CALL SHOWHELP(110)
	WHEN INFIELD(opt_rep)		CALL SHOWHELP(111)
	WHEN INFIELD(opt_sh)		CALL SHOWHELP(112)
	OTHERWISE
		LET sccs = "@(#)fglbldi.4gl	6.6 89/10/16"
		ERROR "Sorry -- no help is defined for this field"
		SLEEP 3
	END CASE

END FUNCTION {help_spi}

{
	Both you and I would dearly love to avoid the perishing
	GOTO statements that litter this code.  However, until
	Informix supply a portable method of going to a variable
	field name (eg, a function nextfield('fieldname') where
	the field name could be a string variable), this code is
	doomed to remain as it is, GOTOs and all.
}

FUNCTION do_fglbld()

	DEFINE
		field_no	INTEGER,
		retval		INTEGER,
		i			INTEGER,
		tabid		INTEGER

	LET retval = 1
	OPEN WINDOW w_fglbld AT 7, 11
		WITH FORM "fglbld"
		ATTRIBUTE (BORDER, MESSAGE LINE FIRST)

	DISPLAY banner TO FORMONLY.heading
	DISPLAY "Generate Simplified Perform Interface" TO FORMONLY.subheading

	{ Let user choose database; once set, cannot be changed }
	LET dbase = get_dbase()
	IF dbase IS NULL THEN
		LET dbase = inp_dbase()
		IF dbase IS { still } NULL THEN
			CLOSE WINDOW w_fglbld
			RETURN retval
		END IF
	END IF
	DISPLAY BY NAME dbase

	LET retval = TRUE { OK }
	CALL sdf_spi()
	LET prev_field = NULL

	MESSAGE "Enter details of SPI.  ESC to accept."
	INPUT details.*, optlist.* FROM s_input.* HELP 40

	ON KEY (F7, CONTROL-F)
		CALL help_spi()

	ON KEY (F6, CONTROL-P)
		CASE
		WHEN INFIELD(tabname)
			LET field_no = val_1_spi("^P")
		WHEN INFIELD(pkcol)
			LET field_no = val_2_spi("^P")
		WHEN INFIELD(menuname)
			LET field_no = val_3_spi("^P")
		WHEN INFIELD(basename)
			LET field_no = val_4_spi("^P")
		WHEN INFIELD(opt_ins)
			LET field_no = val_5_spi("^P")
		WHEN INFIELD(afterfield)
			LET field_no = val_6_spi("^P")
		WHEN INFIELD(beforefield)
			LET field_no = val_7_spi("^P")
		WHEN INFIELD(controlb)
			LET field_no = val_8_spi("^P")
		WHEN INFIELD(controlp)
			LET field_no = val_9_spi("^P")
		WHEN INFIELD(opt_del)
			LET field_no = val_10_spi("^P")
		WHEN INFIELD(opt_upd)
			LET field_no = val_11_spi("^P")
		WHEN INFIELD(opt_rep)
			LET field_no = val_12_spi("^P")
		WHEN INFIELD(opt_sh)
			LET field_no = val_13_spi("^P")
		END CASE
		GOTO nxfgo_spi

	ON KEY (F5, CONTROL-B)
		CASE
		WHEN INFIELD(tabname)
			LET field_no = val_1_spi("F5")
		WHEN INFIELD(pkcol)
			LET field_no = val_2_spi("F5")
		OTHERWISE
			ERROR "Sorry -- no pop-up facility is defined for this field"
		END CASE
		GOTO nxfgo_spi

		BEFORE FIELD tabname
			LET field_no = val_1_spi("BF")
			GOTO nxfgo_spi

		AFTER FIELD tabname
			LET field_no = val_1_spi("AF")
			GOTO nxfgo_spi

		BEFORE FIELD pkcol
			LET field_no = val_2_spi("BF")
			GOTO nxfgo_spi

		AFTER FIELD pkcol
			LET field_no = val_2_spi("AF")
			GOTO nxfgo_spi

		BEFORE FIELD menuname
			LET field_no = val_3_spi("BF")
			GOTO nxfgo_spi

		AFTER FIELD menuname
			LET field_no = val_3_spi("AF")
			GOTO nxfgo_spi

		BEFORE FIELD basename
			LET field_no = val_4_spi("BF")
			GOTO nxfgo_spi

		AFTER FIELD basename
			LET field_no = val_4_spi("AF")
			GOTO nxfgo_spi

		BEFORE FIELD opt_ins
			LET field_no = val_5_spi("BF")
			GOTO nxfgo_spi

		AFTER FIELD opt_ins
			LET field_no = val_5_spi("AF")
			GOTO nxfgo_spi

		BEFORE FIELD afterfield
			LET field_no = val_6_spi("BF")
			GOTO nxfgo_spi

		AFTER FIELD afterfield
			LET field_no = val_6_spi("AF")
			GOTO nxfgo_spi

		BEFORE FIELD beforefield
			LET field_no = val_7_spi("BF")
			GOTO nxfgo_spi

		AFTER FIELD beforefield
			LET field_no = val_7_spi("AF")
			GOTO nxfgo_spi

		BEFORE FIELD controlb
			LET field_no = val_8_spi("BF")
			GOTO nxfgo_spi

		AFTER FIELD controlb
			LET field_no = val_8_spi("AF")
			GOTO nxfgo_spi

		BEFORE FIELD controlp
			LET field_no = val_9_spi("BF")
			GOTO nxfgo_spi

		AFTER FIELD controlp
			LET field_no = val_9_spi("AF")
			GOTO nxfgo_spi

		BEFORE FIELD opt_del
			LET field_no = val_10_spi("BF")
			GOTO nxfgo_spi

		AFTER FIELD opt_del
			LET field_no = val_10_spi("AF")
			GOTO nxfgo_spi

		BEFORE FIELD opt_upd
			LET field_no = val_11_spi("BF")
			GOTO nxfgo_spi

		AFTER FIELD opt_upd
			LET field_no = val_11_spi("AF")
			GOTO nxfgo_spi

		BEFORE FIELD opt_rep
			LET field_no = val_12_spi("BF")
			GOTO nxfgo_spi

		AFTER FIELD opt_rep
			LET field_no = val_12_spi("AF")
			GOTO nxfgo_spi

		BEFORE FIELD opt_sh
			LET field_no = val_13_spi("BF")
			GOTO nxfgo_spi

		AFTER FIELD opt_sh
			LET field_no = val_13_spi("AF")
			GOTO nxfgo_spi

		LABEL nxfgo_spi:
			IF field_no IS NOT NULL THEN
				CASE
				WHEN field_no = 1
					NEXT FIELD  tabname
				WHEN field_no = 2
					NEXT FIELD  pkcol
				WHEN field_no = 3
					NEXT FIELD  menuname
				WHEN field_no = 4
					NEXT FIELD  basename
				WHEN field_no = 5
					NEXT FIELD  opt_ins
				WHEN field_no = 6
					NEXT FIELD  afterfield
				WHEN field_no = 7
					NEXT FIELD  beforefield
				WHEN field_no = 8
					NEXT FIELD  controlb
				WHEN field_no = 9
					NEXT FIELD  controlp
				WHEN field_no = 10
					NEXT FIELD  opt_del
				WHEN field_no = 11
					NEXT FIELD  opt_upd
				WHEN field_no = 12
					NEXT FIELD  opt_rep
				WHEN field_no = 13
					NEXT FIELD  opt_sh
				END CASE
				LET field_no = NULL
			END IF

	END INPUT

	CLOSE WINDOW w_fglbld
	CALL show_file()

	IF INT_FLAG != 0 THEN
		MESSAGE "Interrupt detected -- input abandoned"
		SLEEP 2
		MESSAGE ""
		LET INT_FLAG = 0
		LET retval = 1
	ELSE
		LET retval = 0
		{ Check for completeness }
		IF retval = 0 AND details.tabname IS NULL THEN
			LET retval = 1
			ERROR "You did not specify the table name"
		END IF
		IF retval = 0 AND details.pkcol IS NULL THEN
			LET retval = 1
			ERROR "You did not specify the primary key column"
		END IF
		IF retval = 0 AND details.menuname IS NULL THEN
			LET retval = 1
			ERROR "You did not specify the menu name"
		END IF
		IF retval = 0 AND details.basename IS NULL THEN
			LET retval = 1
			ERROR "You did not specify the basename for the files"
		END IF

		IF retval = 1 THEN
			SLEEP 2 { Let them see the error message }
		ELSE
			LET cp_details.* = details.*
			LET cp_optlist.* = optlist.*
			LET retval = rd_fglbld1()
		END IF
	END IF

	RETURN retval

END FUNCTION {do_fglbld}

{ Validation code for Shadow.tabname }
FUNCTION val_1_spi(vcode)

	DEFINE
		vcode		CHAR(2),
		ltabname	CHAR(18),
		retval		INTEGER

	LET retval = NULL

	CASE
	WHEN vcode = "^P"
		LET details.tabname = cp_details.tabname
		LET retval = nxf_spi(1, 1)
	WHEN vcode = "F5"
		LET details.tabname = ch_systables()
		LET retval = nxf_spi(1, 1)
	WHEN vcode = "BF"
		LET pr_details.tabname = details.tabname
		RETURN retval
	END CASE


	CASE
	WHEN details.tabname IS NULL
		ERROR "You must specify the table next"
		LET details.tabname = pr_details.tabname
		LET retval = 1
	WHEN details.tabname != pr_details.tabname OR pr_details.tabname IS NULL
		LET ltabname = DOWNSHIFT(details.tabname)
		SELECT Systables.Tabid INTO tabid FROM Systables
			WHERE Systables.Tabname = ltabname
			  AND (Systables.Tabtype = 'T' OR Systables.Tabtype = 'V')
		IF STATUS != 0 THEN
			ERROR "Failed to find table ", details.tabname CLIPPED
			LET retval = 1
		END IF
		LET details.pkcol = NULL
		LET typestr = NULL
		DISPLAY typestr TO FORMONLY.pktype
		CALL fetch_columns(tabid)
	END CASE

	CALL dis_spi()

	IF retval != 1 THEN
		LET prev_field = 1
	END IF

	RETURN retval

END FUNCTION {val_1_spi}

{ Validation code for Shadow.pkcol }
FUNCTION val_2_spi(vcode)

	DEFINE
		vcode	CHAR(2),
		retval	INTEGER

	LET retval = NULL

	CASE
	WHEN vcode = "^P"
		LET details.pkcol = cp_details.pkcol
		LET retval = nxf_spi(2, 1)
	WHEN vcode = "F5"
		CALL ch_syscolumns(details.tabname)
			returning details.pkcol, typestr
		DISPLAY details.pkcol, typestr TO formonly.pkcol, formonly.pktype
		LET retval = nxf_spi(2, 1)
	WHEN vcode = "BF"
		LET pr_details.pkcol = details.pkcol
		RETURN retval
	END CASE

	CASE
	WHEN details.pkcol IS NULL
		ERROR "You must specify the primary key column next"
		LET details.pkcol = pr_details.pkcol
		DISPLAY details.pkcol TO s_details.pkcol
		LET retval = 2
	WHEN details.pkcol != pr_details.pkcol OR pr_details.pkcol IS NULL
		LET typestr = chk_column(details.pkcol)
		IF typestr IS NULL THEN
			ERROR "Unknown column ", details.pkcol CLIPPED
			LET retval = 2
		ELSE
			DISPLAY typestr TO FORMONLY.pktype
		END IF
	END CASE

	CALL dis_spi()

	IF retval != 2 THEN
		LET prev_field = 2
	END IF

	RETURN retval

END FUNCTION {val_2_spi}

{ Validation code for Shadow.menuname }
FUNCTION val_3_spi(vcode)

	DEFINE
		vcode	CHAR(2),
		retval	INTEGER

	LET retval = NULL
	CASE
	WHEN vcode = "^P"
		LET details.menuname = cp_details.menuname
		LET retval = nxf_spi(3, 1)
	WHEN vcode = "BF"
		LET pr_details.menuname = details.menuname
		RETURN retval
	END CASE
	LET prev_field = 3

	CALL dis_spi()

	RETURN retval

END FUNCTION {val_3_spi}

{ Validation code for Shadow.basename }
FUNCTION val_4_spi(vcode)

	DEFINE
		vcode	CHAR(2),
		retval	INTEGER

	LET retval = NULL
	CASE
	WHEN vcode = "^P"
		LET details.basename = cp_details.basename
		LET retval = nxf_spi(4, 1)
	WHEN vcode = "BF"
		LET pr_details.basename = details.basename
		RETURN retval
	END CASE
	CALL set_file(details.basename)
	LET prev_field = 4

	CALL dis_spi()

	RETURN retval

END FUNCTION {val_4_spi}

{ Validation code for Shadow.opt_ins }
FUNCTION val_5_spi(vcode)

	DEFINE
		vcode	CHAR(2),
		retval	INTEGER

	LET retval = NULL
	CASE
	WHEN vcode = "^P"
		LET optlist.opt_ins = cp_optlist.opt_ins
		LET retval = nxf_spi(5, 1)
	WHEN vcode = "BF"
		LET pr_optlist.opt_ins = optlist.opt_ins
		RETURN retval
	END CASE
	LET prev_field = 5

	CALL dis_spi()

	RETURN retval

END FUNCTION {val_5_spi}

{ Validation code for Shadow.afterfield }
FUNCTION val_6_spi(vcode)

	DEFINE
		vcode	CHAR(2),
		retval	INTEGER

	LET retval = NULL
	CASE
	WHEN vcode = "^P"
		LET optlist.afterfield = cp_optlist.afterfield
		LET retval = nxf_spi(6, 1)
	WHEN vcode = "BF"
		LET pr_optlist.afterfield = optlist.afterfield
		RETURN retval
	END CASE
	LET prev_field = 6

	CALL dis_spi()

	RETURN retval

END FUNCTION {val_6_spi}

{ Validation code for Shadow.beforefield }
FUNCTION val_7_spi(vcode)

	DEFINE
		vcode	CHAR(2),
		retval	INTEGER

	LET retval = NULL
	CASE
	WHEN vcode = "^P"
		LET optlist.beforefield = cp_optlist.beforefield
		LET retval = nxf_spi(7, 1)
	WHEN vcode = "BF"
		LET pr_optlist.beforefield = optlist.beforefield
		RETURN retval
	END CASE
	LET prev_field = 7

	CALL dis_spi()
	RETURN retval

END FUNCTION {val_7_spi}

{ Validation code for Shadow.controlb }
FUNCTION val_8_spi(vcode)

	DEFINE
		vcode	CHAR(2),
		retval	INTEGER

	LET retval = NULL
	CASE
	WHEN vcode = "^P"
		LET optlist.controlb = cp_optlist.controlb
		LET retval = nxf_spi(8, 1)
	WHEN vcode = "BF"
		LET pr_optlist.controlb = optlist.controlb
		RETURN retval
	END CASE
	LET prev_field = 8

	CALL dis_spi()

	RETURN retval

END FUNCTION {val_8_spi}

{ Validation code for Shadow.controlp }
FUNCTION val_9_spi(vcode)

	DEFINE
		vcode	CHAR(2),
		retval	INTEGER

	LET retval = NULL
	CASE
	WHEN vcode = "^P"
		LET optlist.controlp = cp_optlist.controlp
		LET retval = nxf_spi(9, 1)
	WHEN vcode = "BF"
		LET pr_optlist.controlp = optlist.controlp
		RETURN retval
	END CASE
	LET prev_field = 9

	CALL dis_spi()

	RETURN retval

END FUNCTION {val_9_spi}

{ Validation code for Shadow.opt_del }
FUNCTION val_10_spi(vcode)

	DEFINE
		vcode	CHAR(2),
		retval	INTEGER

	LET retval = NULL
	CASE
	WHEN vcode = "^P"
		LET optlist.opt_del = cp_optlist.opt_del
		LET retval = nxf_spi(10, 1)
	WHEN vcode = "BF"
		LET pr_optlist.opt_del = optlist.opt_del
		RETURN retval
	END CASE
	LET prev_field = 10

	CALL dis_spi()

	RETURN retval

END FUNCTION {val_10_spi}

{ Validation code for Shadow.opt_upd }
FUNCTION val_11_spi(vcode)

	DEFINE
		vcode	CHAR(2),
		retval	INTEGER

	LET retval = NULL
	CASE
	WHEN vcode = "^P"
		LET optlist.opt_upd = cp_optlist.opt_upd
		LET retval = nxf_spi(11, 1)
	WHEN vcode = "BF"
		LET pr_optlist.opt_upd = optlist.opt_upd
		RETURN retval
	END CASE
	LET prev_field = 11

	CALL dis_spi()

	RETURN retval

END FUNCTION {val_11_spi}

{ Validation code for Shadow.opt_rep }
FUNCTION val_12_spi(vcode)

	DEFINE
		vcode	CHAR(2),
		retval	INTEGER

	LET retval = NULL
	CASE
	WHEN vcode = "^P"
		LET optlist.opt_rep = cp_optlist.opt_rep
		LET retval = nxf_spi(12, 1)
	WHEN vcode = "BF"
		LET pr_optlist.opt_rep = optlist.opt_rep
		RETURN retval
	END CASE
	LET prev_field = 12

	CALL dis_spi()

	RETURN retval

END FUNCTION {val_12_spi}

{ Validation code for Shadow.opt_sh }
FUNCTION val_13_spi(vcode)

	DEFINE
		vcode	CHAR(2),
		retval	INTEGER

	LET retval = NULL
	CASE
	WHEN vcode = "^P"
		LET optlist.opt_sh = cp_optlist.opt_sh
		LET retval = nxf_spi(13, 1)
	WHEN vcode = "BF"
		LET pr_optlist.opt_sh = optlist.opt_sh
		RETURN retval
	END CASE
	LET prev_field = 13

	CALL dis_spi()

	RETURN retval

END FUNCTION {val_13_spi}

FUNCTION nxf_spi(field_no, move)

	DEFINE
		field_no	INTEGER,
		move		INTEGER

	RETURN next_field(field_no, prev_field, 13)

END FUNCTION {nxf_spi}

{ Set defaults }
FUNCTION sdf_spi()

	LET details.tabname     = NULL
	LET details.pkcol       = NULL
	LET details.menuname    = NULL
	LET details.basename    = NULL
	LET optlist.opt_ins     = NULL
	LET optlist.afterfield  = NULL
	LET optlist.beforefield = NULL
	LET optlist.controlb    = NULL
	LET optlist.controlp    = NULL
	LET optlist.opt_del     = NULL
	LET optlist.opt_upd     = NULL
	LET optlist.opt_rep     = NULL
	LET optlist.opt_sh      = NULL

END FUNCTION {sdf_spi}
