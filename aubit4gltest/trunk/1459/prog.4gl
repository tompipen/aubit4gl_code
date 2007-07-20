main
define a record
	a char(10),
	b char(20)
end record
define lv_str char(200)
open window w1 at 1,1 with form "up"
construct lv_str on a,b from a,b
display lv_str
if lv_str="a='ABCDEF'" then
	exit program 0
else
	exit program 1
end if


end main
