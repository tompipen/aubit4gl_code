
main
define pid,id,pzip,zip char(20)
define a integer
let pid="1"
let id="1"
let zip="XX123"


if NOT (pid=id and pzip=zip) then
	exit program 1
else
	display "Blah"
end if


end main


