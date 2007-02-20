database test1

globals

   define t_str char(512),
           unl_ctr smallint

end globals


main

  call get_cnt()

end main


function get_cnt()
define lv_t integer
	select count(*) into lv_t from systables

   unload to "tm.unl" select * from systables
   let unl_ctr=sqlca.sqlerrd[3]
	if lv_t!=unl_ctr then
   		display "unl_ctr is ",unl_ctr," expecting ",lv_t
		exit program 1
	end if
	exit program 0

end function

