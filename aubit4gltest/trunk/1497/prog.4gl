database test1
main
define axl char(20)
define lv_s char(300)
define lv_s2 char(300)

declare c1 cursor for select * from systables

let lv_s= cursor_name("c1")
display lv_s clipped

let axl="c1"
let lv_s2= cursor_name(axl)
display lv_s2 clipped
if lv_s=lv_s2 then
	exit program 0
else
	exit program 1
end if
end main

