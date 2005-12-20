main

define a  record
	a1,a2,a3,a4,a5 integer
end record
let a.a1=1
let a.a2=2
let a.a3=3
let a.a4=4
let a.a5=5
initialize a.a2 thru a.a4 to null
if a.a1 is null then display "null" else display a.a1 end if
if a.a2 is null then display "null" else display a.a2 end if
if a.a3 is null then display "null" else display a.a3 end if
if a.a4 is null then display "null" else display a.a4 end if
if a.a5 is null then display "null" else display a.a5 end if
end main
