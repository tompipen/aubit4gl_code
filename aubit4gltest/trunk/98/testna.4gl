database test1
main
define a integer
	create temp table t_ser (
		a serial)
		
	insert into t_ser values(0)
	
	display "status: ", status
	display "sqlca.sqlerrd[2] (last serial): ", sqlca.sqlerrd[2]
	display "sqlca.sqlerrd[6] (last rowid): ", sqlca.sqlerrd[6]
	
	let a=sqlca.sqlerrd[2]

	if a!=1 then
		exit program 1
	else
		exit program 0
	end if
end main


