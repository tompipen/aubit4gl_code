

function callback(copyof a, copyof b)
define a,b record
	tabname char(18),
	tabid integer
end record

if a.tabname>b.tabname then return 1 end if
if a.tabname=b.tabname then return 0 end if
return -1
end function


main

define lv_a array[5] of record
	tabname char(18),
	tabid integer
end record

let lv_a[1].tabname="systables"
let lv_a[2].tabname="syscolumns"
let lv_a[3].tabname="sysindicies"
let lv_a[4].tabname="systabauth"
let lv_a[5].tabname="sysviews"

let lv_a[1].tabid=1
let lv_a[2].tabid=2
let lv_a[3].tabid=3
let lv_a[4].tabid=4
let lv_a[5].tabid=5


sort lv_a using callback

display lv_a[1].tabname
display lv_a[2].tabname
display lv_a[3].tabname
display lv_a[4].tabname
display lv_a[5].tabname


end main
