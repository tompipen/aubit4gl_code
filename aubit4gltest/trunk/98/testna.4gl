database test1
main
define a,exit_code,tmp integer

	let exit_code = 0
	create temp table t_ser (
		a serial)
	
	display ".............. Inserting 0... (next serial shoud be 1)"		
	insert into t_ser values(0)
	
	display "status: ", status
	display "sqlca.sqlerrd[2] (last serial): ", sqlca.sqlerrd[2]
	display "sqlca.sqlerrd[6] (last rowid): ", sqlca.sqlerrd[6]
	
	let a=sqlca.sqlerrd[2]

	if a!=1 then
		display "BAD 1"
		let exit_code = 1
	end if
	
	display ".............. Inserting 0... (next serial shoud be 2)"	
	insert into t_ser values(0)
	
	display "status: ", status
	display "sqlca.sqlerrd[2] (last serial): ", sqlca.sqlerrd[2]
	display "sqlca.sqlerrd[6] (last rowid): ", sqlca.sqlerrd[6]
	
	let a=sqlca.sqlerrd[2]

	if a!=2 then
		display "BAD 2"
		let exit_code = 2
	end if

	display ".............. Inserting 4... (next serial shoud be 4)"
	insert into t_ser values(4)
	
	display "status: ", status
	display "sqlca.sqlerrd[2] (last serial): ", sqlca.sqlerrd[2]
	display "sqlca.sqlerrd[6] (last rowid): ", sqlca.sqlerrd[6]
	
	let a=sqlca.sqlerrd[2]

	if a!=4 then
		display "BAD 3"
		let exit_code = 3
	end if

	display ".............. Inserting 0... (next serial shoud be 5)"
	insert into t_ser values(0)
	
	display "status: ", status
	display "sqlca.sqlerrd[2] (last serial): ", sqlca.sqlerrd[2]
	display "sqlca.sqlerrd[6] (last rowid): ", sqlca.sqlerrd[6]
	
	let a=sqlca.sqlerrd[2]

	if a!=5 then
		display "BAD 4"
		let exit_code = 4
	end if

	display ".............. Inserting 0... (next serial shoud be 6)"
	insert into t_ser values(0)
	
	display "status: ", status
	display "sqlca.sqlerrd[2] (last serial): ", sqlca.sqlerrd[2]
	display "sqlca.sqlerrd[6] (last rowid): ", sqlca.sqlerrd[6]
	
	let a=sqlca.sqlerrd[2]

	if a!=6 then
		display "BAD 5"
		let exit_code = 5
	end if

	display ".............. Inserting 0... (next serial shoud be 7)"
	insert into t_ser values(0)
	
	display "status: ", status
	display "sqlca.sqlerrd[2] (last serial): ", sqlca.sqlerrd[2]
	display "sqlca.sqlerrd[6] (last rowid): ", sqlca.sqlerrd[6]
	
	let a=sqlca.sqlerrd[2]

	if a!=7 then
		display "BAD 6"
		let exit_code = 6
	end if
	
	
	declare x cursor for
		select * from t_ser
		
	foreach x into tmp
		display tmp
	end foreach
	
	display "Exit program : ",exit_code
	exit program exit_code
	
end main


