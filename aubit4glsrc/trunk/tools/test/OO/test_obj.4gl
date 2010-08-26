main
call test_objects()
call aclfgl_dump_objects()
end main

function test_objects()
define m object(math)
define f object(fglobject)

	let m= math.new()

	display "OBjectname=", m.getobjectname()


	display m.add(2,1)
	display m.sub(2,1)

	display "Now cast to fglobject"
	let f=m

	display "Object name now = ",f.getobjectname()

	display f.add(2,1)
	display f.sub(2,1)

	display "Polymorphism..."
	display "Numeric parameters:", f.poly_Add(1,2)
	display "String parameters :",f.poly_Add("1","2")
	

end function
