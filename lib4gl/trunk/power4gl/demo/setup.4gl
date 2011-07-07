##########################################################################
# setup.4gl Creates and populates 'powdemo' database, only used for      #
#           this demo, NOT needed for production.                        #
#                                                                        #
# If using Informix RDBS use dbimport script in setup.sh, this program   #
# is used por postgresql, mysql, odbc or even Informix using built-in    #
# convertsql.                                                            #
#                                                                        #
##########################################################################
main

define lv_com, lv_dialect char(80)

whenever error continue
database powdemo
whenever error stop

if sqlca.sqlcode!=0 then
    display "Creating powdemo database"
    whenever error continue
    let lv_dialect = dbms_dialect()
    if lv_dialect[1,8] = "POSTGRES" then
        database template1
    end if
    
    let lv_com= "create database powdemo"
    execute immediate lv_com
    database powdemo
    whenever error stop
    
    if sqlca.sqlcode!=0 then
        display "Error:"
        display "   Unable to connect to or create the powdemo database"
        display "   ------------------------------------------------------"
        display " "
        display "Please manually create a database called powdemo "
        display "and rerun this program to create/populates tables."
        exit program 1
    end if
end if
    
display "setting DBDATE environment for load"
code
{
static char buff[256];

    sprintf(buff,"DBDATE=DMY4.");
    putenv(buff);
}
endcode



{ TABLE state row size = 22 number of columns = 2 index size = 9 }
{ unload file name = state__100.unl number of rows = 2 }

display "creating table state ..."
create table state 
  (
    stcode char(2),
    name char(20) not null,
    primary key (stcode) 
  );
display "loading table state ..."
load from "powdemo.exp/state__100.unl" insert into state

{ TABLE bank row size = 110 number of columns = 6 index size = 21 }
{ unload file name = bank___101.unl number of rows = 1 }

display "creating table bank ..."
create table bank 
  (
    banknr serial not null,
    name char(32) not null,
    address1 char(24),
    address2 char(24),
    address3 char(24),
    stcode char(2),
    primary key (banknr) 
  );
display "loading table bank ..."
load from "powdemo.exp/bank___101.unl" insert into bank

{ TABLE acctgrp row size = 100 number of columns = 3 index size = 12 }
{ unload file name = acctgrp102.unl number of rows = 3 }

display "creating table acctgrp ..."
create table acctgrp 
  (
    grpnr serial not null,
    name char(32) not null,
    descr char(64),
    primary key (grpnr) 
  );
display "loading table acctgrp ..."
load from "powdemo.exp/acctgrp102.unl" insert into acctgrp

{ TABLE irate row size = 12 number of columns = 3 index size = 30 }
{ unload file name = irate__103.unl number of rows = 3 }

display "creating table irate ..."
create table irate 
  (
    grpnr integer,
    datch date,
    rate decimal(6,2),
    primary key (grpnr,datch) 
  );
display "loading table irate ..."
load from "powdemo.exp/irate__103.bis" insert into irate

{ TABLE account row size = 56 number of columns = 6 index size = 24 }
{ unload file name = account104.unl number of rows = 2 }

display "creating table account ..."
create table account 
  (
    acctnr serial not null,
    code char(8),
    name char(32),
    grpnr integer,
    datopen date,
    datclose date,
    primary key (acctnr) 
  );
display "loading table account ..."
load from "powdemo.exp/account104.unl" insert into account

{ TABLE acctran row size = 52 number of columns = 5 index size = 24 }
{ unload file name = acctran105.unl number of rows = 4 }

display "creating table acctran ..."
create table acctran 
  (
    atrnr serial not null,
    acctnr integer not null,
    dat date not null,
    amount decimal(14,2) not null,
    comment char(32),
    primary key (atrnr)
  );
display "loading table acctran ..."
load from "powdemo.exp/acctran105.bis" insert into acctran

{ TABLE prntype row size = 100 number of columns = 3 index size = 12 }
{ unload file name = prntype109.unl number of rows = 2 }

display "creating table prntype ..."
create table prntype 
  (
    prntnr serial not null,
    name char(32) not null,
    pipe char(64),
    primary key (prntnr)
  );
display "loading table prntype ..."
load from "powdemo.exp/prntype109.unl" insert into prntype

{ TABLE prnadj row size = 78 number of columns = 3 index size = 39 }
{ unload file name = prnadj_110.unl number of rows = 29 }

display "creating table prnadj ..."
create table prnadj 
  (
    prntnr integer not null,
    adjcode char(10),
    adjstr char(64),
    primary key (prntnr,adjcode)
  );
display "loading table prnadj ..."
load from "powdemo.exp/prnadj_110.unl" insert into prnadj

{ TABLE printer row size = 110 number of columns = 4 index size = 33 }
{ unload file name = printer111.unl number of rows = 1 }

display "creating table printer ..."
create table printer 
  (
    code char(10),
    name char(32) not null,
    prntnr integer not null,
    pipe char(64) not null,
    primary key (code)
  );
display "loading table printer ..."
load from "powdemo.exp/printer111.unl" insert into printer

if lv_dialect[1,8] = "POSTGRES" then
    display "In postgresql database you still need:"
    display ""
    display "To enable some Informix compatible views/functions"
    display "psql powdemo -f <aubitdir_src>/lib/libsql/postgresql/pg8.sql"
    display ""
    display "To simulate SERIAL datatypes as SEQUENCE, generate trigger"
    display "cd <aubitdir_src>/lib/libsql/postgresql"
    display "4glpc -k fix_serial.4gl -o fix_serial.4ae "
    display "./fix_serial.4ae powdeeo"
end if

display "You can compile now the forms"
display "./form_compile.sh"
#run "./form_compile.sh"

display "and then, compile the demo program"
display "./a4gl_compile.sh"
#run "./a4gl_compile.sh"

end main
