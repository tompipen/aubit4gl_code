main

define xdttm datetime year to second,
	xout_dttm datetime year to second,
	xdiff_hr smallint, 
	xdiff_min smallint

let xdttm = current
let xdttm = "2003-08-08 12:30:00"

let xout_dttm = xdttm - 1 units hour - 1 units minute
display "Result=", xout_dttm

let xdiff_hr = 1
let xdiff_min = 30

let xdttm = "2003-08-08 12:30:00"
display "Old=", xdttm
let xout_dttm = xdttm + xdiff_hr units hour + xdiff_min units minute
display "Result=", xout_dttm

end main
