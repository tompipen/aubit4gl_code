main
define lv_details  record
	server char(40),
	userid char(20),
	passwd char(20)
end record

open window w1 at 10,20 with form "test" attribute(border)
input by name lv_details 
close window w1


if int_flag=false then
	call display_messages(lv_details.*)
end if


end main



function display_messages(lv_details)
define lv_details  record
	server char(20),
	userid char(20),
	passwd char(20)
end record

	display "Connecting to server...."

	if A4GL_pop::popbegin(lv_details.server,lv_details.userid,lv_details.passwd) then
		display "OK"
	else
		display A4GL_pop::poperr()
		return
	end if



display "You have", A4GL_pop::popnum() using "####&"," Messages"

end function
