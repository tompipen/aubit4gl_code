database test1

main
define lv_systables record
	tabname char(18),
	tabid integer
end record
define a, cnt, counter integer,
ins_text char(180)

#display "xx"
#exit program

	declare c1 cursor for
		select tabname,tabid from systables where
			(tabid<30 or tabid>89) and tabid <> 3 and tabid < 100

#display "yy"
#exit program


	start report r1  to "rep.out"

#display "zz"
#exit program


	let counter = 0
	foreach c1 into lv_systables.*
		let counter = counter + 1

#With PG ESQL you will never see this message:
display "Counter=",counter
        if counter > 100 then
            display "ERROR: got more then 100 rows. EXIT."
            exit program (1)
        end if
		output to report r1 (lv_systables.*)
	end foreach


	finish report r1

end main

report r1 (rv_systables)
define rv_systables record
	tabname char(18),
	tabid integer
end record,
counter integer
#FIXME: ORDER BY nulls rv_systables.tabname on SQLite connection
	order by rv_systables.tabid
	format

	first page header
        let counter = 0

	on every row
        let counter = counter + 1
        if counter > 100 then
            display "ERROR: got more then 100 rows in report. EXIT."
            exit program (1)
        end if

		print rv_systables.tabid," ",rv_systables.tabname CLIPPED
end report
