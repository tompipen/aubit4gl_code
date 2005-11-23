main
define a record
	a char(10),
	b char(20)
end record
open window w1 at 1,1 with form "f1"
input by name a
if a.a=" " or a.a is null then
	exit program 0
else
	exit program 1
end if

end main
