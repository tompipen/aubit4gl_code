create table entity
  (
    entity serial not null ,
    entity_type char(1),
    progname char(16),
    justuser char(8),
    name char(60),
    flags char(60)
  );

create table dependencies
  (
    entity integer,
    depends_on integer
  );

create table afglsettings
  (
    progname char(16),
    justuser char(8),
    name char(32),
    value char(70)
  );

create table program
  (
    progname char(16),
    justuser char(8),
    progoutdir char(256),
    progmakefile char(256),
    linkflags char(70),
    compflags char(70),
    lastupd integer,
    genmakefile integer
  );


create table inlibrary
  (
    module char(256),
    libname char(256)
  );
