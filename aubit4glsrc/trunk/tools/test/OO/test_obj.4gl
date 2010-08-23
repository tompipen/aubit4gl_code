main
define m object(math)
define f object(fglobject)

	let m= math.new()
	let m= math.new()

	display "OBjectname=", m.getobjectname()


	display m.add(2,1)
	display m.sub(2,1)

	display "Now cast to fglobject"
	let f=m

	display "Object name now = ",f.getobjectname()

	display f.add(2,1)
	display f.sub(2,1)


end main
