main
define a char(2)
	let a="ee"

	if a in ("a","b","c","d","ee") then
		display "IN (GOOD)"
	else
		display "Not in (BAD)"
	end if

	let a="ef"

	if a in ("a","b","c","d","ee") then
		display "IN (BAD)"
	else
		display "Not in (GOOD)"
	end if



end main

