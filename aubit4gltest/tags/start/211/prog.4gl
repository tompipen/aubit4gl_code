main
define xdt date
define xi int
define xf decimal(6,3)
define xxdt datetime year to day

open window main_win at 3, 2 with 20 rows, 78 columns
    attribute(green, border) 
open form main_form from "g6" 
display form main_form attribute (cyan)

let xdt = null

input xdt,xi,xf,xxdt from dt,i,f,xxdt
on key (f1) if not infield(dt) then exit program 1 end if
on key (f2) if not infield(i) then exit program 2 end if
on key (f3) if not infield(f) then exit program 3 end if
on key (f4) if not infield(xxdt) then exit program 4 end if
end input

close form main_form
close window main_win

display xdt,'|',xi,'|',xf,"|",xxdt

end main

