{ DATABASE powdemo  delimiter | }

grant dba to "john";
grant dba to "public";

{ TABLE "john".state row size = 22 number of columns = 2 index size = 9 }
{ unload file name = state__100.unl number of rows = 2 }

create table "john".state 
  (
    stcode char(2),
    name char(20) not null,
    primary key (stcode) constraint "john".u100_1
  );
revoke all on "john".state from "public";

{ TABLE "john".bank row size = 110 number of columns = 6 index size = 21 }
{ unload file name = bank___101.unl number of rows = 1 }

create table "john".bank 
  (
    banknr serial not null,
    name char(32) not null,
    address1 char(24),
    address2 char(24),
    address3 char(24),
    stcode char(2),
    primary key (banknr) constraint "john".u101_2
  );
revoke all on "john".bank from "public";

{ TABLE "john".acctgrp row size = 100 number of columns = 3 index size = 12 }
{ unload file name = acctgrp102.unl number of rows = 3 }

create table "john".acctgrp 
  (
    grpnr serial not null,
    name char(32) not null,
    descr char(64),
    primary key (grpnr) constraint "john".u102_4
  );
revoke all on "john".acctgrp from "public";

{ TABLE "john".irate row size = 12 number of columns = 3 index size = 30 }
{ unload file name = irate__103.unl number of rows = 3 }

create table "john".irate 
  (
    grpnr integer,
    datch date,
    rate decimal(6,2),
    primary key (grpnr,datch) constraint "john".u103_5
  );
revoke all on "john".irate from "public";

{ TABLE "john".account row size = 56 number of columns = 6 index size = 24 }
{ unload file name = account104.unl number of rows = 2 }

create table "john".account 
  (
    acctnr serial not null,
    code char(8),
    name char(32),
    grpnr integer,
    datopen date,
    datclose date,
    primary key (acctnr) constraint "john".u104_7
  );
revoke all on "john".account from "public";

{ TABLE "john".acctran row size = 52 number of columns = 5 index size = 24 }
{ unload file name = acctran105.unl number of rows = 4 }

create table "john".acctran 
  (
    atrnr serial not null,
    acctnr integer not null,
    dat date not null,
    amount decimal(14,2) not null,
    comment char(32),
    primary key (atrnr) constraint "john".u105_9
  );
revoke all on "john".acctran from "public";

{ TABLE "john".prntype row size = 100 number of columns = 3 index size = 12 }
{ unload file name = prntype109.unl number of rows = 2 }

create table "john".prntype 
  (
    prntnr serial not null,
    name char(32) not null,
    pipe char(64),
    primary key (prntnr) constraint "john".u109_16
  );
revoke all on "john".prntype from "public";

{ TABLE "john".prnadj row size = 78 number of columns = 3 index size = 39 }
{ unload file name = prnadj_110.unl number of rows = 29 }

create table "john".prnadj 
  (
    prntnr integer not null,
    adjcode char(10),
    adjstr char(64),
    primary key (prntnr,adjcode) constraint "john".u110_17
  );
revoke all on "john".prnadj from "public";

{ TABLE "john".printer row size = 110 number of columns = 4 index size = 33 }
{ unload file name = printer111.unl number of rows = 1 }

create table "john".printer 
  (
    code char(10),
    name char(32) not null,
    prntnr integer not null,
    pipe char(64) not null,
    primary key (code) constraint "john".u111_19
  );
revoke all on "john".printer from "public";


alter table "john".bank add constraint (foreign key (stcode) 
    references "john".state  constraint "john".r101_3);

alter table "john".irate add constraint (foreign key (grpnr) 
    references "john".acctgrp  constraint "john".r103_6);

alter table "john".account add constraint (foreign key (grpnr) 
    references "john".acctgrp  constraint "john".r104_8);

alter table "john".acctran add constraint (foreign key (acctnr) 
    references "john".account  constraint "john".r105_10);

alter table "john".prnadj add constraint (foreign key (prntnr) 
    references "john".prntype  constraint "john".r110_18);

alter table "john".printer add constraint (foreign key (prntnr) 
    references "john".prntype  constraint "john".r111_20);


grant select on "john".state to "public" as "john";
grant update on "john".state to "public" as "john";
grant insert on "john".state to "public" as "john";
grant delete on "john".state to "public" as "john";
grant index on "john".state to "public" as "john";
grant select on "john".bank to "public" as "john";
grant update on "john".bank to "public" as "john";
grant insert on "john".bank to "public" as "john";
grant delete on "john".bank to "public" as "john";
grant index on "john".bank to "public" as "john";
grant select on "john".acctgrp to "public" as "john";
grant update on "john".acctgrp to "public" as "john";
grant insert on "john".acctgrp to "public" as "john";
grant delete on "john".acctgrp to "public" as "john";
grant index on "john".acctgrp to "public" as "john";
grant select on "john".irate to "public" as "john";
grant update on "john".irate to "public" as "john";
grant insert on "john".irate to "public" as "john";
grant delete on "john".irate to "public" as "john";
grant index on "john".irate to "public" as "john";
grant select on "john".account to "public" as "john";
grant update on "john".account to "public" as "john";
grant insert on "john".account to "public" as "john";
grant delete on "john".account to "public" as "john";
grant index on "john".account to "public" as "john";
grant select on "john".acctran to "public" as "john";
grant update on "john".acctran to "public" as "john";
grant insert on "john".acctran to "public" as "john";
grant delete on "john".acctran to "public" as "john";
grant index on "john".acctran to "public" as "john";
grant select on "john".prntype to "public" as "john";
grant update on "john".prntype to "public" as "john";
grant insert on "john".prntype to "public" as "john";
grant delete on "john".prntype to "public" as "john";
grant index on "john".prntype to "public" as "john";
grant select on "john".prnadj to "public" as "john";
grant update on "john".prnadj to "public" as "john";
grant insert on "john".prnadj to "public" as "john";
grant delete on "john".prnadj to "public" as "john";
grant index on "john".prnadj to "public" as "john";
grant select on "john".printer to "public" as "john";
grant update on "john".printer to "public" as "john";
grant insert on "john".printer to "public" as "john";
grant delete on "john".printer to "public" as "john";
grant index on "john".printer to "public" as "john";






 




 

