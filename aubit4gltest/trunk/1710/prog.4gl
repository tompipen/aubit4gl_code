
main
define a record
	a char(10),
	b char(20)
end record
define lv_str char(200)
open window w1 at 1,1 with form "f1"


# Here - we want to use a callback function in the
# construct to allow us to amend the CONSTRUCT string
# before the construct returns it.
#
# This can be used (for example) to automatically add
# '*' around the string, or to search an address
# (by doing something like '( addr1 MATCHES .. OR addr2 MATCHES ...)' etc etc
#
construct lv_str on a,b from a,b via c_callback

display lv_str
if lv_str="blah=123 and b='ABC'" then
else
	exit program 1
end if

end main


function c_callback(lv_tabname, lv_colname, lv_string,lv_dtype, lv_dtypelength)
define lv_tabname char(18)
define lv_colname char(18)
define lv_string char(300)
define lv_dtype,lv_dtypelength integer

# you return with no values - the construct will complain with an error in field...
if lv_colname="a" and lv_string="456" then
	return
end if

# Normally - we'd want to generate the construct portion - but with maybe different column names
# In this callback we want to map 'a' to be 'blah'...
# 
if lv_colname="a" then
	# aclfgl_get_construct_element takes 5 parameters
	# tablename, column name, search string, datatype and datatype length(eg for decimal or character length)
	let lv_string=aclfgl_get_construct_element(lv_tabname , "blah", lv_string , lv_dtype, lv_dtypelength)
else
	let lv_string=aclfgl_get_construct_element(lv_tabname , lv_colname , lv_string , lv_dtype, lv_dtypelength)
end if



return lv_string

end function
