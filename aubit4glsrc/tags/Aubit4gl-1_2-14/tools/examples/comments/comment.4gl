main
define lv_isa integer
{ this is a real comment }
# Using a {! and a !} though is a comment in Informix4GL but not aubit4GL
{! display "Hello World" !}

# Should display "Hello World"

if is_aubit4gl() then
	display "Is Aubit4GL"
else
	display "Not Aubit4GL"
end if

end main

function is_aubit4gl()
# If we're not in Aubit4GL the following will be a comment
{! return 1 !}
return 0
end function
