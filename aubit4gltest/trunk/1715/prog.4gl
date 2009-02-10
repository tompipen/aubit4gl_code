define lc_f4 constant "f4"
main
define a record
	a char(10),
	b char(20)
end record
open window w1 at 1,1 with form "f1"
options insert key control-b

input by name a.*
	before input
		display "X" to srec1.a

	on key(lc_f4) # Should exit on F4...
		exit program 0
end input

display a.a
display a.b
exit program 1

end main
