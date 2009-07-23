main
define lv_var char(20)
# Pick up our language from the environment
#
display "Select Language for the following message by setting the variable"
display "'LANGUAGE'"
display "eg "
display "$ export LANGUAGE=english"
display " "
display "Possible languages are : english, french, german, italian, spanish"
display "(please use lowercase!)"
display " "
let lv_var=fgl_getenv("LANGUAGE")

if lv_var = " " or lv_var IS NULL then
	LET lv_var="english"
end if

let lv_var=lv_var clipped,".hlp"

options language file lv_var


DISPLAY "Hello" 
DISPLAY "World" 

end main
