main
	set pause mode on
	hide window _variable("screen")
	set pause mode off
	open form calc using calchandler
	call set_window_title("4GL Calculator");

	#open form list using listhandler
	#call set_window_title("Previous results");

code
while (1) {
	gui_run_til_no_more();
}
endcode
end main


formhandler calchandler
define lv_line char(12)
define lv_entered char(12)
define lv_doing char(1)
define lv_num1 float
define lv_num2 float

BEFORE OPEN FORM
	let lv_line=" "
	initialize lv_entered to null
	enable b1,b2,b3,b4,b5,b6,b7,b8,b9,b0
	enable bplus, bminus, bdot,bdiv,btimes,bequals

input lv_line from entered
	on b0 
		if lv_doing="X" then let lv_line="" let lv_doing="" end if
		let lv_line=lv_line clipped,"0" 
		display lv_line to entered
		message "OK0"
	on b1 
		if lv_doing="X" then let lv_line="" let lv_doing="" end if
		let lv_line=lv_line clipped,"1" 
		display lv_line to entered  
		message "OK1"
	on b2 
		if lv_doing="X" then let lv_line="" let lv_doing="" end if
		let lv_line=lv_line clipped,"2" 
		display lv_line to entered  
	on b3 
		if lv_doing="X" then let lv_line="" let lv_doing="" end if
		let lv_line=lv_line clipped,"3" 
		display lv_line to entered 
	on b4 
		if lv_doing="X" then let lv_line="" let lv_doing="" end if
		let lv_line=lv_line clipped,"4" 
		display lv_line to entered 
	on b5 	
		if lv_doing="X" then let lv_line="" let lv_doing="" end if
		let lv_line=lv_line clipped,"5" 
		display lv_line to entered 
	on b6 
		if lv_doing="X" then let lv_line="" let lv_doing="" end if
		let lv_line=lv_line clipped,"6" 
		display lv_line to entered 
	on b7 
		if lv_doing="X" then let lv_line="" let lv_doing="" end if
		let lv_line=lv_line clipped,"7" 
		display lv_line to entered 
	on b8 
		if lv_doing="X" then let lv_line="" let lv_doing="" end if
		let lv_line=lv_line clipped,"8" 
		display lv_line to entered 
	on b9 
		if lv_doing="X" then let lv_line="" let lv_doing="" end if
		let lv_line=lv_line clipped,"9" 
		display lv_line to entered 
	on bdot
		if lv_doing="X" then let lv_line="0" let lv_doing="" end if
		if lv_line not matches "*.*" then
		let lv_line=lv_line clipped,"." 
		end if
		display lv_line to entered 

	on bplus 
		let lv_entered=lv_line
		let lv_line=""
		let lv_doing="+"
		display "+" to entered


	on bminus
		let lv_entered=lv_line
		let lv_line=""
		let lv_doing="-"
		display "-" to entered

	on btimes
		let lv_entered=lv_line
		let lv_line=""
		let lv_doing="*"
		display "*" to entered


	on bdiv
		let lv_entered=lv_line
		let lv_line=""
		let lv_doing="/"
		display "/" to entered

	on bequals

		let lv_num1=lv_entered
		let lv_num2=lv_line

		case lv_doing
			when "+" let lv_num1=lv_num1 + lv_num2
			when "-" let lv_num1=lv_num1 - lv_num2
			when "*" let lv_num1=lv_num1 * lv_num2
			when "/" let lv_num1=lv_num1 / lv_num2
		end case

		let lv_doing=""
		let lv_line=lv_num1  using "<<<<<<<<.<<<<"

code
debug("************************************* CURRENT WINDOW *********************");
endcode
		#current window is calc
		display lv_line clipped to entered
		#current window is _variable("list")

		#display lv_line clipped to entered
		#current window is _variable("calc")
		
		let lv_doing="X"
end input

BEFORE CLOSE FORM
	exit program


end formhandler

formhandler listhandler
#BEFORE OPEN FORM
	#enable clearlist

input lv_line from entered
	
	on entered
		call list_delete(id_to_int(entered),0);
end input

end formhandler



