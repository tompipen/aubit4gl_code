
main
define a record
	a char(10),
	b char(20)
end record
open window w1 at 1,1 with form "f1"
input by name a
	on key (f1)
		next field b
		display "WE SHOULD NEVER GET TO HERE"
		exit program 1
end input
display a.a
display a.b

end main
