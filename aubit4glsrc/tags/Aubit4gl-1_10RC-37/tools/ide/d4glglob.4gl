{
	@(#)$Id: d4glglob.4gl,v 1.1.1.1 2001-08-20 02:37:06 afalout Exp $
	@(#)Alternative D4GL compiling front-end
	@(#)Control Program and support routines
	@(#)Author: JL
}

GLOBALS

	DEFINE			{ Control information for D4GL source file }
		file_save	INTEGER,	{ Is current file saved? }
		file_mode	INTEGER,	{ Current mode of operation }
								{ 0 => editing .4gl file }
								{ 1 => editing .err file }
		file_ext1	CHAR(4),	{ Primary extension of D4GL file }
		file_ext2	CHAR(4),	{ Secondary extension of D4GL file }
		file_bext	CHAR(4),	{ Extension of back-up file }
		file_eext	CHAR(4),	{ Extension of error file }
		file_srch	CHAR(10),	{ Pattern to locate errors with vi }
		file_prog	CHAR(80),	{ Name of D4GL compiler }
		file_opts	CHAR(80),	{ Options for D4GL compiler }
		file_name	CHAR(80),	{ Name of file being edited }
		file_errs	CHAR(80),	{ Name of error file }
		file_back	CHAR(80) 	{ Name of backup file }

	DEFINE			{ Control information for D4GL form file }
		form_save	INTEGER,	{ Is current form saved? }
		form_mode	INTEGER,	{ Current mode of operation }
								{ 0 => editing .4gl form }
								{ 1 => editing .err form }
		form_ext1	CHAR(4),	{ Primary extension of D4GL form }
		form_ext2	CHAR(4),	{ Secondary extension of D4GL form }
		form_bext	CHAR(4),	{ Extension of back-up file }
		form_eext	CHAR(4),	{ Extension of error file }
		form_srch	CHAR(10),	{ Pattern to locate errors with vi }
		form_prog	CHAR(80),	{ Name of D4GL form compiler }
		form_opts	CHAR(80),	{ Options for D4GL form compiler }
		form_name	CHAR(80),	{ Name of form being edited }
		form_errs	CHAR(80),	{ Name of error form }
		form_back	CHAR(80) 	{ Name of backup form }

	DEFINE			{ Control information for build/edit operations }
		usestr		CHAR(80),	{ Correct usage }
		prog_name	CHAR(80),	{ Name of program to be run }
		make_prog	CHAR(80),	{ Name of MAKE program }
		make_targ	CHAR(80),	{ Name of target for MAKE }
		make_file	CHAR(80),	{ Name of makefile }
		make_opts	CHAR(80),	{ Options for MAKE program }
		edit_prog	CHAR(80),	{ Name of program editor }
		edit_opts	CHAR(80)	{ Options for program editor }

END GLOBALS

