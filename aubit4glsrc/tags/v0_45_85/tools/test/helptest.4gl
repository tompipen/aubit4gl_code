{---------------------------------------------------------------------
help.4gl	Aubit4GL help routines (work with Informix .iem files)

2003-4-2	John O'Gorman john.ogorman@zombie.co.nz +64 (9) 521-0336

		First working version

		Note: Uses inline C code for I/O
}
define msgerrcnt integer
----------------------------------------------------------------------
{  main section: comment this out when linking into libaubit  }
main
	define filename char(128)
	define  n integer

	options
		help file "fred.iem",
		message line 2,
		prompt line 22,
		form line 3

	let msgerrcnt = 0
	prompt "Filename? " for filename
	while true
		prompt "Help No? (0 to quit) " for n
		if n = 0 then exit while end if
		call myshowhelp(filename, n)
	end while
end main

