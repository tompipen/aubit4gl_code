database test1

main
        call run_server(9090)
end main


function get_tabid(lv_tabname)
define lv_tabname char(18)
define lv_id integer

select tabid  into lv_id
	from systables where tabname=lv_tabname

return lv_id

end function


local function get_blah(lv_a)
define lv_a integer

end function



function get_tabname(lv_id)
define lv_tabname char(18)
define lv_id integer

select tabname into lv_tabname
	from systables where tabid=lv_id

return lv_tabname

end function


function get_tabrecord(lv_id)
define lv_id integer
define lv_rec record like systables.*
select * into lv_rec.* from systables where tabid=lv_id

display "returning lv_rec with tabname=",lv_rec.tabname clipped
return lv_rec.*
end function


function  do_something()

end function

function  do_something_param(lv_a)
define lv_a integer
end function

function  do_something_ret()
return 1
end function
