{**
 * @file
 * test for statemetn re-use without closing
 * @process TEST_GENERAL
 *}
 
database test1

main
define a smallint


	create temp table abc(x char(10), y char(10))
	call q ()
	call q () # on second call - ECPG_WARNING_PORTAL_EXISTS         -605
	
end main

function q ()
define 	query_text char (100)

	let query_text = " select * from abc where 1=1"
	
   prepare s_customer from query_text
   declare c_customer scroll cursor for s_customer
   open c_customer

end function 





