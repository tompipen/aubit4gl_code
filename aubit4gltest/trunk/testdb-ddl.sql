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
//
*/

 create table dummy (tabname varchar (128,0),tabid integer);
 
 create table systables (
 	tabname varchar (128,0),
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
	site varchar(128,0),
	dbname varchar(128,0),
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

CREATE VIEW v_upd_tbl_perm AS SELECT * FROM update_table_perm;

/* ======================== EOF ===========================*/

