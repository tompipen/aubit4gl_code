
{**
 * @file
 *
 * Test if two update(s) using a cursor for update works fine.
 * This was based on a bug found.
 *}

database desp
#database test1

main
  define lv_r_xpto  record 
    anInt INTEGER,
    aString CHAR(20)
  end record

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

  declare cr_update cursor for 
    select xpto.an_int, xpto.a_string
      from xpto
      for update
  begin work
  open cr_update
  fetch cr_update into lv_r_xpto.*
  update xpto set a_string = "The One"
    where current of cr_update
  close cr_update
  commit work

  declare cr_update cursor for 
    select xpto.an_int, xpto.a_string
      from xpto
      for update
  begin work
  open cr_update
  fetch cr_update into lv_r_xpto.*
  update xpto set a_string = "The One"
    where current of cr_update
  close cr_update
  commit work
  drop table xpto
end main

