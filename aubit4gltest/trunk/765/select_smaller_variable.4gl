{**
 * @file
 * @test 
 *
 * Three function with a fetch to a smaller variable.
 *
 * Test derivated from a production program.
 * The program have a problem in the dimension of a column, but in 
 * 4gl (RDS and i4gl) it works for years.
 *}
DATABASE test1

MAIN
  CALL first_function()
END MAIN

FUNCTION first_function()
	CALL second_function()
END FUNCTION

FUNCTION second_function()
 DEFINE lv_user_name CHAR(12)

 CREATE TEMP TABLE xx (
  user_name CHAR(16)
 ) 
 INSERT INTO xx ( user_name ) VALUES (USER)
 DECLARE cr_xx CURSOR FOR SELECT * FROM xx
 OPEN cr_xx 
 # Aubit cores here because lv_user_tabl is smaller 
 # then user_table
 FETCH cr_xx INTO lv_user_name
 CLOSE cr_xx
 DROP TABLE xx
END FUNCTION
