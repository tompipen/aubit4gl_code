
database test

{**
 * This is a test for a bug founded by Mike Aubury in 20/1/2003.
 * When is fixed, it should go to a BUG_TESTS to serve as a suite fro testing
 * old bugs in every connector and with every version.
 *
 * I can't seem to get declare/open to work when using a variable :
 *
 * Program stopped at 't_db.4gl', line number 11.
 * Error status number -400.
 * .
 *
  * It was found using the ESQL/C connector.
 *}

main
  define a integer
  define lv_tabname char(20)
  let a=10
  declare c1 cursor for
          select tabname from systables where tabid<a
  foreach c1 into lv_tabname
          display lv_tabname
  end foreach
end main
  



