/*
//This script is used to create 'test1' database, used by testing script
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
 
insert into systables (tabname,tabid) values ("systables", 1);
insert into systables (tabname,tabid) values ("syscolumns", 2);
insert into systables (tabname,tabid) values ("sysindexes", 3);
insert into systables (tabname,tabid) values ("systabauth", 4);
insert into systables (tabname,tabid) values ("syscolauth", 5);
insert into systables (tabname,tabid) values ("sysviews", 6);
insert into systables (tabname,tabid) values ("sysusers", 7);
insert into systables (tabname,tabid) values ("sysdepend", 8);
insert into systables (tabname,tabid) values ("syssynonyms", 9);
insert into systables (tabname,tabid) values ("syssyntable", 10);
insert into systables (tabname,tabid) values ("sysconstraints", 11);
insert into systables (tabname,tabid) values ("sysreferences", 12);
insert into systables (tabname,tabid) values ("syschecks", 13);
insert into systables (tabname,tabid) values ("sysdefaults", 14);
insert into systables (tabname,tabid) values ("syscoldepend", 15);
insert into systables (tabname,tabid) values ("sysprocedures", 16);
insert into systables (tabname,tabid) values ("sysprocbody", 17);
insert into systables (tabname,tabid) values ("sysprocplan", 18);
insert into systables (tabname,tabid) values ("sysprocauth", 19);
insert into systables (tabname,tabid) values ("sysblobs", 20);
insert into systables (tabname,tabid) values ("sysopclstr", 21);
insert into systables (tabname,tabid) values ("systriggers", 22);
insert into systables (tabname,tabid) values ("systrigbody", 23);
insert into systables (tabname,tabid) values ("sysdistrib", 24);
insert into systables (tabname,tabid) values ("sysfragments", 25);
insert into systables (tabname,tabid) values ("sysobjstate", 26);
insert into systables (tabname,tabid) values ("sysviolations", 27);
insert into systables (tabname,tabid) values ("sysfragauth", 28);
insert into systables (tabname,tabid) values ("sysroleauth", 29);
insert into systables (tabname,tabid) values (" GL_COLLATE", 90);
insert into systables (tabname,tabid) values (" GL_CTYPE", 91);
insert into systables (tabname,tabid) values (" VERSION", 99);
insert into systables (tabname,tabid) values ("a", 100);
insert into systables (tabname,tabid) values ("djp", 101);
insert into systables (tabname,tabid) values ("zz9", 102);


 create table sysusers (
 	username char(32),
	usertype char(1),
	priority smallint,
	password char(16)
	);
 
CREATE TABLE update_table_perm (
  firstColumn SMALLINT,
  secondColumn CHAR(10),
  thirdColumn INTEGER
);

CREATE VIEW v_update_table_perm AS SELECT * FROM update_table_perm;

/* ======================== EOF ===========================*/
