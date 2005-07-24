{
	@(#)fglbldg.4gl	6.2 89/09/25
	@(#)FGLBLD: Globals
	@(#)Author: JL
}

GLOBALS

	DEFINE
		banner		CHAR(50),		{ Banner identifying program on screens }
		tabid		INTEGER,		{ Table number of table }
		dbase		CHAR(10),		{ Database currently in use }
		typestr		CHAR(30),		{ Type of primary key column }
		name_selected	CHAR(30),	{ Name of what a popup is selecting }
		cp_details,
		pr_details,
		details		RECORD
					tabname		CHAR(18),	{ Table name }
					pkcol		CHAR(18),	{ Column name }
					menuname	CHAR(18),	{ Menu title }
					basename	CHAR(8)		{ Base name for generated files }
					END RECORD,
		cp_optlist,
		pr_optlist,
		optlist		RECORD					{ Options for SPI }
					opt_ins		CHAR(1),
					afterfield	CHAR(1),
					beforefield	CHAR(1),
					controlb	CHAR(1),
					controlp	CHAR(1),
					opt_del		CHAR(1),
					opt_upd		CHAR(1),
					opt_rep		CHAR(1),
					opt_sh		CHAR(1)
					END RECORD

END GLOBALS
