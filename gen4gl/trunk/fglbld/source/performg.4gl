{
	WHATSTR
	@(#)Built by: FGLBLDSTR
	@(#)Global definitions for SPI on Xtable
}

DATABASE Xdbase

GLOBALS

	DEFINE
		wr_xtable	RECORD LIKE Xtable.*, { Working record }
#Xinput		nr_xtable	RECORD LIKE Xtable.*, { Null record }
#Xinput		cp_xtable	RECORD LIKE Xtable.*, { Previous record }
		ct_xtable	RECORD
					list_number	INTEGER,	{ List number }
					active_set	INTEGER,	{ Number of rows in active set }
					active_row	INTEGER,	{ Current row in active set }
					direction	INTEGER,	{ Moving forwards/backwards }
#Xopt_rep					rep_query	INTEGER,	{ Report enquiry constructed? }
#Xpkey_dec					rowid		INTEGER,	{ Rowid is not part of wr_xtable }
					query_done	SMALLINT	{ General query constructed? }
					END RECORD

END GLOBALS
