{
	@(#)$Id: fetch.sql,v 1.1.1.1 2002-06-15 05:07:13 afalout Exp $
	@(#)Shadow table used for building FETCH input function
}

create table fetch_it
(
	tabname		CHAR(18),
	pkcol		CHAR(18),
	basename	CHAR(7)
);
