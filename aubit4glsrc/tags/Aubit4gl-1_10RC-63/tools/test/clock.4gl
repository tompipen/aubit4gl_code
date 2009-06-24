code
#ifdef __WIN32__
#include <windows.h>
#endif
endcode

main
define lv_time, lv_oldtime char(8)
define a integer
define w integer
define h integer
define x integer
let lv_oldtime= " "

let w=(aclfgl_get_curr_width()-63)/2
let h=(aclfgl_get_curr_height()-7)/2
open window w1 at h,w with 7 rows, 63 columns attribute(border)

while true
	let lv_time=current hour to second
	if lv_time!=lv_oldtime then
		let lv_oldtime=lv_time
		set pause mode on
		let x=2
		for a=1 to 8
			call display_digit(lv_time[a],x,1)
			let x=x+8
		end for
		display " " at 1,1
		set pause mode off
	end if
code
#ifdef __WIN32__
	Sleep(50);
#else
	usleep(50000);
#endif
endcode
end while
end main


function display_digit(c,x,y)
define c char(1)
define x,y integer
define lv_r array[7] of char(6)

let lv_r[1]=" "
let lv_r[2]=" "
let lv_r[3]=" "
let lv_r[4]=" "
let lv_r[5]=" "
let lv_r[6]=" "
let lv_r[7]=" "

case c
when "0"
	let lv_r[1]=" ####"
	let lv_r[2]="#   ##"
	let lv_r[3]="#  # #"
	let lv_r[4]="# #  #"
	let lv_r[5]="##   #"
	let lv_r[6]="#    #"
	let lv_r[7]=" ####"

when "1"
	let lv_r[1]="  #"
	let lv_r[2]=" ##"
	let lv_r[3]="# #"
	let lv_r[4]="  #"
	let lv_r[5]="  #"
	let lv_r[6]="  #"
	let lv_r[7]="#####"


when "2"
	let lv_r[1]=" ###"
	let lv_r[2]="#   #"
	let lv_r[3]="#   #"
	let lv_r[4]="   #"
	let lv_r[5]="  #"
	let lv_r[6]=" #"
	let lv_r[7]="#####"
	

when "3"
	let lv_r[1]=" ###"
	let lv_r[2]="#   #"
	let lv_r[3]="    #"
	let lv_r[4]=" ###"
	let lv_r[5]="    #"
	let lv_r[6]="#   #"
	let lv_r[7]=" ###"


when "4"
	let lv_r[1]="#   #"
	let lv_r[2]="#   #"
	let lv_r[3]="#   #"
	let lv_r[4]="#####"
	let lv_r[5]="    #"
	let lv_r[6]="    #"
	let lv_r[7]="    #"


when "5"
	let lv_r[1]="#####"
	let lv_r[2]="#"
	let lv_r[3]="#"
	let lv_r[4]="#####"
	let lv_r[5]="    #"
	let lv_r[6]="    #"
	let lv_r[7]="#####"


when "6"
	let lv_r[1]=" ###"
	let lv_r[2]="#   #"
	let lv_r[3]="#"
	let lv_r[4]="####"
	let lv_r[5]="#   #"
	let lv_r[6]="#   #"
	let lv_r[7]=" ###"


when "7"
	let lv_r[1]="#####"
	let lv_r[2]="    #"
	let lv_r[3]="   #"
	let lv_r[4]="  #"
	let lv_r[5]=" #"
	let lv_r[6]=" #"
	let lv_r[7]=" #"


when "8"
	let lv_r[1]=" ###"
	let lv_r[2]="#   #"
	let lv_r[3]="#   #"
	let lv_r[4]=" ###"
	let lv_r[5]="#   #"
	let lv_r[6]="#   #"
	let lv_r[7]=" ###"


when "9"
	let lv_r[1]=" ###"
	let lv_r[2]="#   #"
	let lv_r[3]="#   #"
	let lv_r[4]=" ###"
	let lv_r[5]="   #"
	let lv_r[6]="  #"
	let lv_r[7]="#"


when ":"
	let lv_r[1]="    "
	let lv_r[2]="  # "
	let lv_r[3]="    "
	let lv_r[4]=" "
	let lv_r[5]="    "
	let lv_r[6]="  # "
	let lv_r[7]="    "

end case

display lv_r[1] at y,x
display lv_r[2] at y+1,x
display lv_r[3] at y+2,x
display lv_r[4] at y+3,x
display lv_r[5] at y+4,x
display lv_r[6] at y+5,x
display lv_r[7] at y+6,x

end function
