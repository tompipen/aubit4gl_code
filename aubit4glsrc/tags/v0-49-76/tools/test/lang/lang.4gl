main
define lv_var char(20)
# Pick up our language from the environment
#
let lv_var=fgl_getenv("LANGUAGE")

if lv_var = " " or lv_var IS NULL then
	LET lv_var="english"
end if

let lv_var=lv_var clipped,".hlp"

options language file lv_var

DISPLAY "Hello" AT 1,1
DISPLAY "World" AT 2,1
sleep 4

end main
