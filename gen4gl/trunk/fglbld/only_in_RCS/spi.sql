{
	@(#)$Id: spi.sql,v 1.1.1.1 2002-06-15 05:07:14 afalout Exp $
	@(#)Shadow table used for building SPI input function
}

create table spi
(
	tabname		CHAR(18),
	pkcol		CHAR(18),
	menuname	CHAR(18),
	basename	CHAR(7),
	opt_ins		CHAR(1),
	afterfield	CHAR(1),
	beforefield	CHAR(1),
	controlb	CHAR(1),
	controlp	CHAR(1),
	opt_del		CHAR(1),
	opt_upd		CHAR(1),
	opt_rep		CHAR(1),
	opt_sh		CHAR(1)
);
