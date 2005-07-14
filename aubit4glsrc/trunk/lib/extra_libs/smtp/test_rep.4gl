main
define lv_email char(80)
define lv_server char(80)
	display "Starting"
	let lv_server=fgl_getenv("SMTPSERVER")

	if lv_server is null or lv_server matches " " then
		display "No SMTP server set..."
		exit program
	end if

	let lv_email=fgl_getenv("EMAIL_RECIPIENT")
	if lv_email is null or lv_email matches " " then
		call aclfgl_setenv("EMAIL_RECIPIENT","report_test@aubit.com")
		display "Set recipients"
	end if
	start report r1 as convertable
	output to report r1 ("Hello")
	display "Finished"
	finish report r1 converting TO EMAIL as "PDF"
end main


report r1(a)
define a char(10)
format
page header
print "TEST REPORT : Generated : ",today
on every row 
print a
end report
