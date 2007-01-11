main
    define
        dt datetime hour to second,
        ch char(8)

    let ch = "1:0:0"
    let dt = ch

    if dt is null
    then
	display "Nope..."
        exit program 1
    end if
    display "OK"
end main
