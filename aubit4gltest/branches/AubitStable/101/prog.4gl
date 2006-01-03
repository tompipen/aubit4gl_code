database test1

main
define a smallint

	create temp table abc(x char(10), y char(10))

    select * from abc

	let a=status

	if a=notfound then
		if a=100 then
			exit program 0
        else
			display "NOTFOUND OK, but status<>100; status=",a
			exit program 1
        end if
	else
		display "status=",a
		exit program 1
	end if

end main


