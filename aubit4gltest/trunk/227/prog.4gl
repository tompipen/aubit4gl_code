database test1
main
define a character(20)

define b record
   d array[4] of record
      e char(20),
	f integer
   end record
end record

define c record
   d array[4] of record
      e char(20),
	f smallint
   end record
end record
define cnt integer

	create temp table test227 ( xkey int, stamp datetime year to fraction(5) )
	
	let a = "12345678901234567890"
	let b.d[1].e = "Hello Mike!"
	let b.d[2].e = "Hello Art!"
	let b.d[3].e = "Is it working yet?"
	let b.d[4].e = "Sure as shooting!"
	let b.d[1].f = 1
	let b.d[2].f = 2
	let b.d[3].f = 3
	let b.d[4].f = 4
	
	insert into test227
	values (1, current year to fraction(5))
	
	let c.* = b.*
	for cnt=1 to 4
		display "Orig: ", b.d[cnt].e," ", b.d[cnt].f
		display "Copy: ", c.d[cnt].e," ", c.d[cnt].f
		if b.d[cnt].e!=c.d[cnt].e then exit program 1 end if
		if b.d[cnt].f!=c.d[cnt].f then exit program 2 end if
	end for
	

end main

