{
	@(#)$Id: upopup.sql,v 1.1.1.1 2002-06-15 05:07:14 afalout Exp $
	@(#)Shadow table used for building UPOPUP input function
}

create table upopup
(
	tabname		CHAR(18),
	pkcol		CHAR(18),
	basename	CHAR(7),
	selected	CHAR(18)
);
