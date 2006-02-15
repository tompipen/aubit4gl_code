{**
 * @file
 * Decribe the test here
 * @process TEST_GENERAL
 *}
 
#if you need to use database, use "test1"
database test1




main
  define P_RECORD record
	a char(10),
	b char(10)
  end record

  create temp table tmp (
	a char(10),
	b char(10)
  )

  insert into tmp values ("ABC","DEF")

  insert into tmp values ("ABC","DEF2")

  begin work
  declare C_RECORD cursor for
    select * into P_RECORD.* from tmp
    where a = "ABC"
  foreach C_RECORD
    display P_RECORD.a, P_RECORD.b
    update tmp set a = "SOME NAME"
    where a = "ABC"
  end foreach
  commit work
end main
