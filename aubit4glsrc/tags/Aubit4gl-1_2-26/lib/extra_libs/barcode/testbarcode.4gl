
main 
define lv_description char(80)
define lv_code char(40)
while true
	prompt "Scan> " for lv_code

	if int_flag=true then
		exit while
	end if
	
	display lv_code at 3,2
	whenever error continue
	call barcode::A4GL_lookup_barcode("http://dev.upcdatabase.com/rpc","lookupEAN", lv_code ) returning lv_description
	if status<0 then
		error "Unable to get details"
	else
	display "=", lv_description clipped, "" at 4,2
	sleep 2
	end if
	
end while

end main

