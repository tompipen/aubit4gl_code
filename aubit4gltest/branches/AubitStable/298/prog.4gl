main
define lv_arr array[10] of char(1)
define lv_mydb char(64)
	let lv_mydb="test1"
	
	database lv_mydb
	create temp table bibble( a integer)
	insert into bibble values(1)
	
	select a into lv_arr[4] from bibble
	
	display lv_arr[4]
end main


