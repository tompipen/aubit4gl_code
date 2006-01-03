main
define
lv_cnt  integer,
i integer

let lv_cnt = 0

for i = 0 to 2000
let lv_cnt = lv_cnt + 1
display lv_cnt
if lv_cnt is null then
 	exit for
end if
end for

display "lv_cnt = ", lv_cnt
display " i = ", i
if i!=2001 then
	exit program 1
else
	exit program 0
end if

end main



