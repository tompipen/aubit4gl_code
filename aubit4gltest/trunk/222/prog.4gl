main
define xdt date
define xi int
define xf decimal(10,0)

open window main_win at 3, 2 with 20 rows, 78 columns
    attribute(green, border) 
open form main_form from "g6" 
display form main_form attribute (cyan)

let xdt = null

input xdt,xi,xf from dt,i,f
on key (f1)
	exit input
end input

close form main_form
close window main_win

display xdt,'|',xi,'|',xf

end main

