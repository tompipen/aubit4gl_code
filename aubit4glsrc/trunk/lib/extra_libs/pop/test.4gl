main

display "Connecting to server...."


if libpop::popbegin("someserver.com","username","*****") then
	display "OK"
else
	display libpop::poperr()
	exit program
end if



display "You have", libpop::popnum() using "####&"," Messages"

end main
