
main 
define ans char 
define lv_flag integer
let lv_flag=0
display " " at 1,1
prompt "abc1 - F1 to exit " for char ans 
	on key(f1) 	let lv_flag=1
	on key(f2) 	let lv_flag=1
	on key(f5)	display "F5" at 10,10 continue prompt
end prompt

prompt "abc2 - Char to exit " for char ans 
	on key(f1) 	let lv_flag=lv_flag+1
end prompt


if lv_flag!=1 then
	exit program 1
else
	exit program 0
end if
end main 

