# This is an example of using 
# dynamic datatypes.
# 
# In this case we're using the mpz 
# integer type from the gmp package...
#
import datatype mpz

main	
define a mpz
define b integer
call load_datatype("mpz")

let a="400000000001"

for b=1 to 10
	# This one returns a value...
	call a:nextprime() returning a
	display a
end for


display "Setting fib numbers"

for b=1 to 10
	call a:setfib(b)  # This has been defined as an 'inplace' function
	display a
end for


end main

