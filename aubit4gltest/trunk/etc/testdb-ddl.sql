/*
// This script is used to create 'test1' database, used by testing script
// It contains only DDL statements.
// Data is populated using testdb-data.sql script
// NOTE SQLITE dos not accept // or {} a comment, only fwdslash-star
//
// 	tabid integer is actually tabid serial in Informix systables
//
//	 create table systables
//      (tabid integer,
//	tabname char (100)
// );
// 'left' is reserved word in Postgres (and probably some other databases) 
// so it was renamed to xx_left - seems unused, since tests still work
*/

/*
 create table dummy (tabname char (128),tabid integer);
 
 create table systables (
 	tabname char (128),
	owner char(32),
	partnum integer,
	tabid integer,
	rowsize smallint,
	ncols smallint,
	nindexes smallint,
	nrows integer,
	created date,
	version integer,
	tabtype char(1),
	locklevel char(1),
	npused integer,
	fextsize integer,
	nextsize integer,
	flags smallint,
	site char(128),
	dbname char(128),
	type_xid integer,
	am_id integer   
 );
 
 create table sysusers (
 	username char(32),
	usertype char(1),
	priority smallint,
	password char(16)
	);
 
CREATE TABLE update_table_perm (
  firstColumn SMALLINT,
  secondColumn CHAR(30),
  thirdColumn INTEGER
);

}
--CREATE VIEW v_upd_tbl_perm AS SELECT * FROM update_table_perm;
*/

create table tab1
(   x      integer,
    y      char(10),
    z      smallint
);


create table a4gl_syscolval 
  (
    tabname char(18),
    colname char(18),
    attrname char(10),
    attrval char(64)
  );

create table a4gl_syscolatt 
  (
    tabname char(18),
    colname char(18),
    seqno serial not null ,
    color smallint,
    inverse char(1),
    underline char(1),
    blink char(1),
    xx_left char(1),
    def_format char(64),
    condition char(64)
  );
    




/* ======================== EOF ===========================*/

