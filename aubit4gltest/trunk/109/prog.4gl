{**
 * @file
 * Decribe the test here
 * @process TEST_GENERAL
 *}
 
#if you need to use database, use "test1"
database test1

#It is recomended that you use temp tables
#	create temp table abc(x char(10), y char(10))

#DATABASE cis

GLOBALS
    DEFINE
    p_sftest RECORD 
          printer_name   char(8),
          last_mod       date
               end record
END GLOBALS

MAIN
define    query_text CHAR(250)

display "drop existing table"

whenever error continue
drop table sftest
whenever error stop

display "create table"
create table sftest
(
printer_name   char(8),
last_mod       date
)

display "inserting data"

let p_sftest.printer_name = "testprtr"
let p_sftest.last_mod     = "01/01/2004"

insert into sftest values(p_sftest.*)

display "begin old program"

display "select first record"
let query_text = "select * from sftest"
PREPARE utfm001tq_st FROM query_text
DECLARE utfm001tq_list SCROLL CURSOR FOR utfm001tq_st

OPEN utfm001tq_list
FETCH FIRST utfm001tq_list INTO p_sftest.*
close utfm001tq_list

display "lock that record"

declare sftest_lock cursor for
    select * from sftest
    where printer_name = p_sftest.printer_name
    for update


display "begin work"
begin work

display "open lock cursor"
open sftest_lock

#display "fetch record to lock it"
#fetch sftest_lock into p_sftest.*

display "rollback work"
rollback work


END MAIN

