database test1
main
define lv_sys record like systables.*

display "Cursor into:"

declare c1 cursor for select * into lv_sys.* from systables order by tabid
foreach c1 
	display "1:",lv_sys.tabname clipped
	exit foreach 
end foreach

display "foreach into:"

declare c2 cursor for select * from systables order by tabid
foreach c2  into lv_sys.*
	display "2:",lv_sys.tabname clipped
	exit foreach 
end foreach

display "End"

end main
