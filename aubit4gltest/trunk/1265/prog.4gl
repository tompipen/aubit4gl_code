database test1 
main
define a,b char(20)
let a="Hello" let b="World"
select tabname into a,b from systables where tabid=1
display a," ",b
if b!="World" or b is null then exit program 1 end if

let a="Hello" let b="World"
declare c1 cursor for
	select tabname into a,b from systables where tabid=1

open c1
fetch c1 into a,b
display a," ",b
if b!="World" or b is null then exit program 1 end if
end main
