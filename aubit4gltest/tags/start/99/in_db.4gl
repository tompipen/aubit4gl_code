database test1
main
define a char(2)
define b char(2)

let b="a"
create temp table intest (
	val char(2)
)

insert into intest values ("a")
insert into intest values ("b")
insert into intest values ("c")
insert into intest values ("d")
insert into intest values ("ee")


	let a="ee"

	if a in ( select val from intest where val>=b) then
		display "IN (GOOD)"
	else
		display "Not in (BAD)"
	end if

	let a="ef"

	if a in ( select val from intest  where val>=b) then
		display "IN (BAD)"
	else
		display "Not in (GOOD)"
	end if


	let a="ee"
	if exists (select * from intest where val=a) then
		display "Exists (GOOD)"
	else
		display "Not exists (BAD)" #fails with -ecp
	end if


	let a="ef"
	if exists (select * from intest where val=a) then
		display "Exists (BAD)"
	else
		display "Not exists (GOOD)"
	end if

end main

