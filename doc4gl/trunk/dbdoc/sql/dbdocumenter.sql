
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


