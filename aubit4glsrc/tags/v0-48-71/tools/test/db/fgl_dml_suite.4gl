{**
 * Data manipulation language unit testing.
 *
 * @todo : Test null values to
 *
 * The confirmation that the information is OK is made using a linked 
 * ESQL/C linked utilities function.
 *}

database test

{**
 * Clear the test table.
 * This should be checked to.
 *
 * @todo : Return the error(s) if ocurr.
 *}
function clearTestTable()
  delete from test_table
end function

{**
 * Test an insert in a test table.
 *}
function test_insert()
  define int_var  integer
  define char_var char(10)
  define smint_var smallint
  define float_var float
  define smfloat_var smallfloat
  define decimal_var decimal
  --define serial_var serial
  define date_var date
  define money_var money
  define dtyme_var datetime year to minute
  define byte_var byte
  define text_var text
  define vchar_var varchar(255,10)
  define interval_var interval year to minute

  {** @todo : Use all the other datatypes too *}

  call clearTestTable()
  insert into test_table (an_int, a_char) 
    values (1,'TEST')
  {
  call assertCountTable(
    1,
    "test_table",
    "The number of rows in tes_table is not 1"
  )
  }

  let int_var  = 2
  let char_var = "Test 2"
  insert into test_table (an_int, a_char) 
    values (int_var,char_var)
end function

{**
 * Test if a select into is working.
 *
 * @todo Test every data type
 *}
function test_select_into()
  define the_char char(25)

  select a_char
    into the_char
    from test_table
    --where an_int =1
  if the_char = "TEST" then
    display "Select OK"
    return
  else
    display "Select NOT OK: ", the_char
  end if
  display "========================"
end function

{**
 * Test the execution of an prepared insert in the test_table.
 *}
function test_bind_insert()
  define insertStr char(128)
  define i integer
  define ch char(10)
  define rc smallint

  call clearTestTable()
  let i = 1
  let ch = "One"
  let insertStr = "insert into test_table (an_int, a_char) values (?,?)"
  prepare stInsert from insertStr
  execute stInsert using i, ch
  # Test sqlca.sqlerrd[3]
end function

{**
 * Test if aubit gives error when we make a prepared insert without good
 * number of variables in using.
 *}
function test_wrong_bind_insert()
  define insertStr char(128)
  define i integer
  define ch char(10)
  define flt float

  call clearTestTable()
  let i = 1
  let ch = "One"
  let insertStr = "insert into test_table (an_int, a_char) values (?,?)"
  prepare stInsert from insertStr
  whenever error continue
  execute stInsert using i
  call assert(status != 0,"Execute with less variables does not give any error")
  execute stInsert using i, ch, flt
  call assert(status != 0,"Execute with more variables does not give any error")
  whenever error stop
end function

function test_update()
end function

function test_bind_update()
end function

function test_wrong_bind_update()
end function

function test_delete()
end function

function test_bind_delete()
end function

function test_wrong_bind_delete()
end function

{**
 * Open declare and fetch a simple cursor with open, fetch close
 * @todo : Do not depend on test_insert values (insert them in the function)
 * @todo : Test all the datatypes
 *}
function test_simple_cursor_fetch()
  define the_char char(25)

  declare cr_testCursor cursor for
    select a_char
      from test_table
  open cr_testCursor
  while (1=1)
    fetch cr_testCursor into the_char
    if status = notfound then
      exit while
    end if
    display "FOUND ", the_char
  end while
  close cr_testCursor
end function

{**
 * Test the usage of a cursor but use the foreach iteration insted the
 * fetch
 *}
function test_simple_cursor_foreach()
  define the_char char(25)

  declare cr_testForeachCursor cursor for
    select a_char
      from test_table
  foreach cr_testForeachCursor into the_char
    display "FOUND ", the_char
  end foreach
  close cr_testForeachCursor
end function

{**
 * Test a simple cursor usage but using a prepared statement.
 * The iteration is made using fetch.
 *}
function test_prepared_cursor()
  define the_char char(25)
  define strSql char(512)

  let strSql = "select a_char from test_table"
  prepare stTestPreparedStatement from strSql
  declare cr_testCursor cursor for stTestPreparedStatement
  open cr_testCursor
  while (1=1)
    fetch cr_testCursor into the_char
    if status = notfound then
      exit while
    end if
    display "FOUND ", the_char
  end while
  close cr_testCursor
end function

{**
 * Insert rows for proper cursor test.
 *}
function insertDataForCursorTest()
  call clearTestTable()

  insert into test_table (an_int,a_smallint,a_char,a_varchar,a_float,
    a_smallfloat,a_decimal,a_date,a_datetime)
    values (1,1,'ONE','VONE',1.1,1.01,1.001,'12/31/2002','2001-12-31 01:01')
  insert into test_table (an_int, a_char) 
    values (2,'TWO')
  insert into test_table (an_int, a_char) 
    values (3,'TREE')
  insert into test_table (an_int, a_char) 
    values (4,'FOUR')
  insert into test_table (an_int, a_char) 
    values (5,'FIVE')
end function

{**
 * Test a scroll cursor usage.
 * To be well tested needs to iterate with:
 *   next, previous, first, last, absolute,relative
 * Needs proper data inserted.
 *}
function test_scroll_cursor()
  define the_char char(25)
  define the_int integer

  display "Testing scroll cursor"
  call insertDataForCursorTest()
  declare cr_testScrollCursor scroll cursor for
    select a_char, an_int
      from test_table
      order by an_int

  open cr_testScrollCursor
  fetch cr_testScrollCursor into the_char, the_int
  if the_char = "ONE" then
    display "OK"
  else
    display "Error ", the_char
  end if

  # Test fetch last
  fetch last cr_testScrollCursor into the_char, the_int
  if the_char = "FIVE" then
    display "OK"
  else
    display "Error ", the_char
  end if

  # Test fetch firs
  fetch first cr_testScrollCursor into the_char, the_int
  if the_char = "ONE" then
    display "OK"
  else
    display "Error ", the_char
  end if

  # Test fetch next
  fetch next cr_testScrollCursor into the_char, the_int
  if the_char = "TWO" then
    display "OK"
  else
    display "Error ", the_char
  end if

  # Test fetch previous
  fetch previous cr_testScrollCursor into the_char, the_int
  if the_char = "ONE" then
    display "OK"
  else
    display "Error ", the_char
  end if

  # Test fetch absolute
  fetch absolute 4 cr_testScrollCursor into the_char, the_int
  if the_char = "FOUR" then
    display "OK"
  else
    display "Error ", the_char
  end if

  # Test negative fetch relative
  fetch relative -2 cr_testScrollCursor into the_char, the_int
  if the_char = "TWO" then
    display "OK"
  else
    display "Error ", the_char
  end if

  # Test positive fetch relative
  fetch relative 2 cr_testScrollCursor into the_char, the_int
  if the_char = "FOUR" then
    display "OK"
  else
    display "Error ", the_char
  end if

  close cr_testCursor
end function

{**
 * Make some database instructions, commit and see if the data is ok at 
 * the database.
 *}
function test_transaction_commit()
  define readedChar char(10)

  display "Testing commit transaction"
  call clearTestTable()

  begin work
  insert into test_table (an_int, a_char) 
    values (1,'ONE')
  update test_table set a_char = "one" where an_int = 1
  commit work
  select a_char 
    into readedChar
    from test_table
    where an_int = 1
  if readedChar = "one" then
    display "COMMIT OK : ", readedChar
  else
    display "Error ", readedChar
  end if
end function

{**
 * Make some actions in the database and rollback trying to see if the
 * information then not updated.
 *}
function test_transaction_rollback()
  define readedChar char(10)

  display "Testing commit transaction"
  call clearTestTable()

  insert into test_table (an_int, a_char) 
    values (1,'ONE')
  begin work
  update test_table set a_char = "one" where an_int = 1
  rollback work
  select a_char 
    into readedChar
    from test_table
    where an_int = 1
  if readedChar = "ONE" then
    display "ROLLBACK OK : ", readedChar
  else
    display "Error ", readedChar
  end if
end function

{**
 * The goal is to test all the cursor for update mechanism.
 * It declare, open, fetch and update where current of
 *}
function test_cursor_for_update()
  define theCharVar char(10)
  define readedChar char(10)
  
  declare cr_testCursorForUpdate cursor for
    select a_char 
      from test_table
      where an_int = 1
      for update
  open cr_testCursorForUpdate
  fetch cr_testCursorForUpdate into theCharVar
  update test_table
    set a_char = "one"
    where current of cr_testCursorForUpdate
  close cr_testCursorForUpdate

  select a_char 
    into readedChar
    from test_table
    where an_int = 1
  if readedChar = "one" then
    display "CURSOR FOR UPDATE OK : ", readedChar
  else
    display "Error ", readedChar
  end if

end function


{**
 * Test if a cursor with hold is working.
 * The cursor with hold remains openned even if a transaction is closed.
 *}
function test_cursor_with_hold()
  define the_char char(10)

  display "Testing cursor with hold"
  call insertDataForCursorTest()
  begin work
  declare cr_testWithHold cursor with hold for
    select a_char from test_table
  open cr_testWithHold 
  fetch cr_testWithHold into the_char
  commit work
  let the_char = ""
  fetch cr_testWithHold into the_char
  if the_char = "TWO" then
    display "CURSOR WITH HOLD OK : ", the_char
  else
    display "Error ", the_char
  end if
end function

function test_scroll_cursor_with_hold()
  define the_char_var like test_table.an_int
end function

function test_insert_cursor()
  define pr_test_table record like test_table.*
end function

{**
 * Test an implicit row lock with a cursor for update.
 *}
function test_row_lock()
end function

function test_lock()
end function

{**
 * Insert one test row in the table
 *}
function insert_one_test_row()
  call clearTestTable()
  insert into test_table (an_int, a_char) 
    values (1,"ONE")
end function

{**
 * Test a select of all columns into a .* record.
 *}
function test_select_all()
  define pr_test_table record like test_table.*

  call insert_one_test_row()
  select *
    into pr_test_table.*
    from test_table
  if pr_test_table.a_char = "ONE" then
    display "SELECT * OK : ", pr_test_table.a_char
  else
    display "ERROR IN SELECT *", pr_test_table.a_char
  end if
end function

{**
 * Test if an insert with a record like * is working
 *}
function test_insert_all()
  define pr_test_table record like test_table.*
  define the_char_var char(10)

  call clearTestTable()
  let pr_test_table.an_int = 1
  let pr_test_table.a_char = "ONE"
  insert into test_table  values (pr_test_table.*)
  select a_char
    into the_char_var
    from test_table
  if the_char_var = "ONE" then
    display "INSERT * OK : ", the_char_var
  else
    display "ERROR IN INSERT *", the_char_var
  end if
end function

{**
 * Test if an update to all rows works OK
 *}
function test_update_all()
  define pr_test_table record like test_table.*
  define the_char_var char(10)

  let pr_test_table.an_int = 1
  let pr_test_table.a_char = "TWO"
  call insert_one_test_row()

  update test_table set *=pr_test_table.*
  select a_char
    into the_char_var
    from test_table
  if the_char_var = "TWO" then
    display "UPDATE * OK : ", the_char_var
  else
    display "ERROR IN UPDATE *", the_char_var
  end if
end function

{**
 * Test if an insert of null value is correctly done.
 *}
function test_insert_null()
  define the_char_var char(15)
  define numberOfRows integer

  let numberOfRows = 0
  call clearTestTable()
  initialize the_char_var to null
  insert into test_table (an_int, a_char) 
    values (1,the_char_var)

  select count(*) 
    into numberOfRows
    from test_table
    where a_char is null

  if numberOfRows = 1 then
    display "INSERT NULL OK : ", numberOfRows
  else
    display "Error ", numberOfRows
  end if
end function

{**
 * Test if an update with a null value works
 *}
function test_update_null()
  define the_char_var char(15)
  define numberOfRows integer

  let numberOfRows = 0
  call clearTestTable()
  initialize the_char_var to null
  insert into test_table (an_int, a_char) 
    values (1,"ONE")

  update test_table set a_char = the_char_var where an_int = 1
  select count(*) 
    into numberOfRows
    from test_table
    where a_char is null

  if numberOfRows = 1 then
    display "UPDATE NULL OK : ", numberOfRows
  else
    display "Error ", numberOfRows
  end if
end function

{**
 * Test if a selection ofa null value works.
 * This function should be tested after testing the insert of a null
 *}
function test_select_into_null()
  define the_char_var char(15)
  define numberOfRows integer

  let numberOfRows = 0
  call clearTestTable()
  let the_char_var = "ONE"
  insert into test_table (an_int, a_char) 
    values (1,NULL)

  select a_char
    into the_char_var
    from test_table
    where an_int = 1

  if the_char_var is null then
    display "SELECT NULL OK : ", numberOfRows
  else
    display "Error ", numberOfRows
  end if
end function

{**
 * Test if a select into with a cursor with null values work OK
 *}
function test_select_cursor_null()
  define the_char_var char(15)

  call clearTestTable()
  call insertDataForCursorTest()
  update test_table set a_char = NULL

  declare crTSCN cursor for 
    select a_char
      from test_table
      where an_int = 1

  open crTSCN 
  fetch crTSCN into the_char_var
  if the_char_var is null then
    display "CURSOR NULL OK : ", the_char_var
  else
    display "Error ", the_char_var
  end if
  close crTSCN
end function

{**
 * Test if the select where with a null value in a variable works
 *}
function test_select_where_is_null()
  define the_char_var char(15)
  define numberOfRows integer

  let numberOfRows = 0
  call clearTestTable()
  initialize the_char_var to null
  insert into test_table (an_int, a_char) 
    values (1,the_char_var)

  select count(*) 
    into numberOfRows
    from test_table
    where a_char = the_char_var

  if numberOfRows = 1 then
    display "SELECT WHERE NULL OK : ", numberOfRows
  else
    display "ERROR IN SELECT WHERE NULL VAR", numberOfRows
  end if
end function

{** 
 * Test if an unload works
 *}
function test_unload()
  call insertDataForCursorTest()
  unload to "/tmp/xx.unl" select * from test_table
end function

{**
 * Test if the close cursor works OK(opening does not give any error
 *}
function test_close_cursor()
  define the_char_var char(15)

  call clearTestTable()
  call insertDataForCursorTest()

  declare crTSCN cursor for 
    select a_char
      from test_table
      where an_int = 1

  open crTSCN 
  fetch crTSCN into the_char_var
  close crTSCN

  whenever error continue
  open crTSCN 
  if status = 0 then
    display "CLOSE CURSOR OK : "
  else
    display "ERROR IN CLOSE CURSOR", status
  end if
  whenever error stop
  fetch crTSCN into the_char_var
  close crTSCN
end function

{**
 * Test if without close cursor it gives an error
 *}
function test_no_close_cursor()
  define the_char_var char(15)

  call clearTestTable()
  call insertDataForCursorTest()

  declare crTSCN cursor for 
    select a_char
      from test_table
      where an_int = 1

  open crTSCN 
  fetch crTSCN into the_char_var

  whenever error continue
  open crTSCN 
  if status != 0 then
    display "NO CLOSE CURSOR OK : ", status
  else
    display "ERROR IN NO CLOSE CURSOR"
  end if
  whenever error stop
  fetch crTSCN into the_char_var
  close crTSCN
end function

{**
 * Assert if a table contains a number of rows wanted
 * @todo : This function should be in ESQL/C, not in 4gl that we are testing
 *}
function assertCountTable(numRows,tableName,mess)
  define numRows      integer
  define tableName    char(25)
  define mess         char(80)
  define numRowsFound integer
  define strSql       char(256)

  let strSql = "select count(*) from ", tableName clipped
  prepare stSql from strSql
  declare crSql cursor for stSql
  open crSql 
  fetch crSql into numRowsFound
  close crSql
  call assert(numRows = numRowsFound,mess)
end function

{**
 * While not using the 4glUnit i am using this function.
 *}
function assert(result,mess)
  define result integer
  define mess char(80)

  if result = true then
    display "ERROR ", mess
  else
    display "NOT ERROR"
  end if
end function

{**
 * Setup the suite.
 * Create the test table.
 *}
function setup()
  whenever error continue
  drop table test_table;
  whenever error stop
  create table test_table (
    an_int integer,
    a_smallint smallint,
    a_char char(10), 
    a_varchar varchar(50,10),
    a_float float,
    a_smallfloat smallfloat,
    a_decimal decimal(16,2),
    a_date date,
    a_datetime datetime year to minute
  )
  #an_interval interval year to second
    #a_money money(16,2)
end function

{**
 * Terminate the test suite.
 *}
function teardown()
  drop table test_table
end function

{**
 * Create the data manipulation language tes suite
 *}
function createDmlSuite()
  call setup()
  call test_insert()
  call test_select_into()
  call test_simple_cursor_fetch()
  call test_simple_cursor_foreach()
  call test_prepared_cursor()
  call test_scroll_cursor()
  call test_bind_insert()
  call test_wrong_bind_insert()
  call test_transaction_commit()
  call test_transaction_rollback()
  #call test_cursor_for_update()
  call test_cursor_with_hold()
  call test_select_all()
  call test_insert_all()
  #call test_update_all()
  call test_insert_null()
  call test_update_null()
  call test_select_into_null()
  call test_select_cursor_null()
  call test_select_where_is_null()
  call test_no_close_cursor()
  call test_close_cursor()
  call test_unload()
  #call teardown()
end function


main
  call createDmlSuite()
end main
