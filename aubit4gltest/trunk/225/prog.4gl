main
define a char(20)
define d date

	let d=mdy(02,13,1970)

	let a=d+1
	display "+",a

	let a=d-1
	display "-",a

	let a=d*1
	display "*",a

	let a=d/1
	display "/",a

	let a=d mod 2000
	display "mod ",a


	let a=d**1
	display "pow",a




	let a=1+d
	display a,"+"

	let a=25615-d
	display a,"-"

	let a=1*d
	display a,"*"

	let a=25611/d
	display a,"/"

	let a=2000 mod d
	display "mod ",a



end main
