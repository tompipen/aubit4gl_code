{**
 * @file
 * MID 851. Setting an environment variable using the aclfgl_setenv function
 * @process TEST_GENERAL
 *}

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
