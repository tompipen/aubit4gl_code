database test1
main

create temp table xx (a integer)

load from "m1.unl" insert into xx

display sqlca.sqlerrd[3]

if sqlca.sqlerrd[3]!=4 then
	display "Wasn't expecting that.."
	exit program 1
end if

load from "mempty.unl" insert into xx

display sqlca.sqlerrd[3]
if sqlca.sqlerrd[3]!=0 then
	display "Wasn't expecting that.."
	exit program 1
end if

display "Happy.."
exit program 0
end main
