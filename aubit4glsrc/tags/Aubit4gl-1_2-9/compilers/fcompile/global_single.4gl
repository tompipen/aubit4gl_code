{----------------------------------------------------------------------+
| GLOBAL variable definition                                           |
+----------------------------------------------------------------------}

{ $Id: global_single.4gl,v 1.1 2010-01-14 13:25:35 mikeaubury Exp $ }

  DEFINE
	ga_rec_found SMALLINT,
	ga_rec_no SMALLINT,
	ga_table_name ARRAY[2] OF CHAR(32),
	ga_screen_name ARRAY[3] OF CHAR(32),
	gv_attribute CHAR(32),
	end_flag INTEGER,
	abort_flag INTEGER,
	answer CHAR(1)

