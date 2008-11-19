main
define lv_a char(512)
define lv_read integer

let lv_read=1

while true
code
	lv_read=0;
	if (gets(lv_a)) {
		lv_read++;
		A4GL_trim_nl(lv_a); // remove any trailing NL
	}
endcode
	if not lv_read then
		exit while
	end if
	LET lv_a=lv_a  # make sure its all padded properly..

	###### PROCESS
	display lv_a clipped
	# Ok - thats not much processing - but you get the idea...

end while

end main
