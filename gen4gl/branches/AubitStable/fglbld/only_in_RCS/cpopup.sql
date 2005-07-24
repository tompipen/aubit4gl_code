{
	@(#)$Id: cpopup.sql,v 1.1.1.1 2002-06-15 05:07:13 afalout Exp $
	@(#)Shadow table used for building CPOPUP input function
}

create table cpopup
(
	tabname		CHAR(18),
	pkcol		CHAR(18),
	menuname	CHAR(18),
	basename	CHAR(7),
	selected	CHAR(18)
);
