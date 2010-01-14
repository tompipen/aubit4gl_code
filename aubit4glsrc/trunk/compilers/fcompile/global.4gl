{----------------------------------------------------------------------+
| GLOBAL variable definition                                           |
+----------------------------------------------------------------------}

{ $Id: global.4gl,v 1.2 2010-01-14 07:41:44 mikeaubury Exp $ }

GLOBALS
  DEFINE
	ga_rec_found ARRAY[10] OF SMALLINT,
	ga_rec_no ARRAY[10] OF SMALLINT,
	ga_table_name ARRAY[10,2] OF CHAR(32),
	gv_table_no, gv_table_max INTEGER,
	ga_screen_name ARRAY[20,3] OF CHAR(32),
	gv_screen_no, gv_screen_max INTEGER,
	ga_table_screen ARRAY[10] OF SMALLINT,
	ga_master_of ARRAY[10] OF SMALLINT,
	gv_master_of_no, gv_master_of_max INTEGER,
	gv_show_detail SMALLINT,
	gv_attribute CHAR(32),
	end_flag INTEGER,
	abort_flag INTEGER,
	answer CHAR(1)

END GLOBALS
