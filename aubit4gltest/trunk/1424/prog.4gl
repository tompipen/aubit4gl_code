main
    define envvar, val char(80)

    let envvar = "MEE"
    let val = "you"

    call aclfgl_setenv(envvar, val)
    let val = fgl_getenv(envvar)
	if val!="you" then
		display "BAD"
		exit program 1
	end if
	display "Good"
end main
