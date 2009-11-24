define cnt integer
define a array[20] of record
	b char(20),
	c integer
end record

main
define b array[20] of record
	b char(20),
	c integer
end record

for cnt=1 to 20
	let a[cnt].b=cnt
	let a[cnt].c=cnt
end for

call bibble(COPYOF(a))

for cnt=1 to 20
	display ">", a[cnt].b," ",  a[cnt].c," <"
end for
end main


function bibble(COPYOF lv_a) 

define lv_a array[20] of record
	b char(20),
	c integer
end record

for cnt=1 to 20
	display ">", a[cnt].b," ",  a[cnt].c," <", lv_a[cnt].b," ",  lv_a[cnt].c
	let lv_a[cnt].b=99-cnt
end for


copyback lv_a

end function

