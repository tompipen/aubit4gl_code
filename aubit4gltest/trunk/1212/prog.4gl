

#============================================================
# LABELS configuration file will need review
#============================================================

define pr record
	f1 char(40),
	f2 char(40),
	f3 char(40),
	f4 char(40),
	f5 char(40)
	end record

main
	options menu line first,
		form line first,
		prompt line last,
		message line last-1,
		comment line last,
		input wrap,
		field order unconstrained,
		accept KEY RETURN

	let pr.f1='first'
	let pr.f2='second'
	let pr.f3='third'
	let pr.f4='fourth'
	let pr.f5='fifth'

	open window w1 at 2,2 with form "iwrap" attributes(border)
	display pr.* to sr.*
	input by name pr.f1, pr.f2, pr.f3, pr.f4, pr.f5
			without defaults
	after field f2
		if pr.f2='second' then 
			next field next 
			end if
	on key(f1)
		if infield(f3) then
			exit program 0
		else
			exit program 1
		end if
	end input
end main

