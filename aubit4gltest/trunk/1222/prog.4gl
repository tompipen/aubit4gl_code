main
define lv_str char(200)
open window w1 at 1,1 with form "p2"
construct lv_str on tab.cnt from cnt
on key(f1) 
	exir program 1
end construct

if lv_str=" tab.cnt=0" then
	exit program 0
else
	display "'",lv_str clipped,"'"
	exit program 2
end if
end main
