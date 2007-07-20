main
define xarr array[4] of record
 xdt date,
 xi int,
 xf decimal(6,3),
 xxdt datetime year to day
end record

open window main_win at 3, 2 with 20 rows, 78 columns
    attribute(green, border) 
open form main_form from "g6" 
display form main_form attribute (cyan)
options delete key f36, insert key f36

initialize xarr[1].* to null
initialize xarr[2].* to null
initialize xarr[3].* to null
initialize xarr[4].* to null
call set_count(0)
input array xarr from srec1.*
on key (f1) if not infield(dt) then exit program 1 end if
on key (f2) if not infield(i) then exit program 2 end if
on key (f3) if not infield(f) then exit program 3 end if
on key (f4) if not infield(xxdt) then exit program 4 end if
end input

close form main_form
close window main_win

display xarr[1].xdt,'|',xarr[1].xi,'|',xarr[1].xf,"|",xarr[1].xxdt

end main

