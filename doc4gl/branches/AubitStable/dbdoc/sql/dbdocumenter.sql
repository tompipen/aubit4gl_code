-- This DDL is now integrated in doc4gl/manager/P4glRepository.pm, since
-- this Doc4GL module is used to create Doc4GL database repository, and we
-- want to use Dbdoc together with Doc4GL, as one tool, so we want to have
-- integrated database.

-- Use this script ONLY if you want to use Dbdoc WITHOUT the rest of the Doc4GL

-- also see p4gl_rep.sql

create table systableext
(
  owner char(32),
  tabname char(32),
  extowner char(32),
  tabalias char(32),
  remarks char(254),
  primary key (owner,tabname)
);


create table syscolumnext
(
  owner char(32),
  tabname char(32),
  colname char(32),
  extowner char(32),
  colalias char(32),
  collabel char(32),
  coltitle char(32),
  remarks char(254),
  subtype char(4),
  class char(32),
  primary key (owner,tabname,colname)
);


create table d_modulos
(
  codigo char(5),
  nome char(40)
);


create table d_mod_tab
(
  codmod char(5),
  tabname char(19)
);


create unique index mod_prim on d_modulos (codigo);
create unique index modtab_prim on d_mod_tab (codmod,tabname);

-- found this in one of dbdoc cgi scripts:
create table sysmodules
(
	codigo char(5) not null primary key,
	nome char(40) not null,
	cod_projecto char(5),
	sub_modulo_de char(5)
);


-- ****************************************************************************
-- New: tables for jdbdoc
-- (from dbdoc/jdbcdoc/src/org/aubit4gl/dbdocumenter/repository/RepositoryStructure.java)
-- ****************************************************************************

--     * Create the table where we can identify how to access to the operational
--     * databases that are refered in the repository.
        
create table ext_database
(
	database char(64) not null primary key,
	jdbc_driver_class varchar(255,64),
	url varchar(255,64)
);

--     * Create the table where the extended information about each table
--     * should be stored.

create table ext_table
(
	database char(64) not null references ext_database (database),
	owner char(32) not null,
	table_name char(64) not null,
	alias char(64),
	remarks varchar(255,32),
	primary key (database,owner,table_name)
);


--	 * Create the table where the extended information about each column it will
--     * be stored.

create table ext_column
(
	database char(64) not null,
	owner char(32) not null,
	table_name char(64) not null,
	column_name char(64) not null,
	alias char(64),
	label char(64),
	title char(64),
	remarks varchar(255,32),
	primary key (database,owner,table_name,column_name),
	foreign key (database,owner,table_name) 
		references ext_table (database,owner,table_name)
);


--     * Create the table where the process will be defined


create table process
(
	id_process char(20) not null primary key,
	disp_process char(20) not null,
	den_process char(64) not null,
	sub_process_of char(20),
	comments varchar(255,32)
);


--     * Create the table where a process is asociated to a table

create table table_process
(
	id_process char(20) not null references process (id_process),
	database char(64) not null,
	owner char(64) not null,
	table_name char(64) not null,
		primary key (id_process,database,owner,table_name)

-- so where is table "ext_process" ?
--		,
--		foreign key (database,owner,table_name)
--			references ext_process (database,owner,table_name)
);

-- #end new


