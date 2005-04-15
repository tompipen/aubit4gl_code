
{**
 * @file
 *
 * Test if two update(s) using a cursor for update works fine.
 * This was based on a bug found.
 *}

database test1

main
  whenever error continue
  drop table xpto
  whenever error stop

  create table xpto (
    an_int integer,
    a_string char(20)
  )

  insert into xpto values (1,"One")
  insert into xpto values (2,"Two")
  insert into xpto values (3,"Three")

  display "U1"
  call use_cursor()
  display "U2"
  call use_cursor()
  display "U3"
  drop table xpto
end main

function use_cursor()
  define lv_r_xpto  record 
    anInt INTEGER,
    aString CHAR(20)
  end record

  prepare px from "select xpto.an_int, xpto.a_string from xpto for update"
  declare cr_update cursor for  px

  begin work
  open cr_update

  fetch cr_update into lv_r_xpto.*

  update xpto set a_string = "The One" where current of cr_update

  close cr_update
  commit work
end function

