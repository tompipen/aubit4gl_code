main
	define  rptinfo		array[100] of record
		rcode		smallint,
		item_rpt_desc	char(10)
	end record
	define	xrow		smallint,
		xscr		smallint,
		xcnt		smallint,
		xquit		smallint,
		counter		smallint

	define lv_flag integer
	clear screen
	let xquit = false

	open window rptwin at 3, 2 with 20 rows, 78 columns
		attribute (form line first + 1, green, border,
			   prompt line last, comment line last,
			   message line last)

	open form rptform from "test_265"
	display form rptform attribute (cyan)

	let lv_flag=0

	for counter = 1 to 99
		initialize rptinfo[counter].* to null
		let rptinfo[counter].rcode = counter
		let rptinfo[counter].item_rpt_desc = "Desc: ",counter
	end for
	let counter = counter - 1

	call startlog("test_265.log")

	call set_count(counter)
	let xquit = false
	input array rptinfo without defaults from scr_arr.* 
		attribute (white)

# comment out the following 2 lines in order to test "next field rcode"
		on key(f2)
			error "Should continue input"
			let lv_flag=1

		on key(f3) 
			error "Should next field rcode"
			let lv_flag=2

		on key(f4) 
			if infield(rcode) then
				call errorlog("In rcode")
			end if

			if infield(item_rpt_desc) then
				call errorlog("In item_rpt_desc")
			end if

		after field rcode
			if lv_flag=1 then
				continue input
			end if

			if lv_flag=2 then
				next field rcode
			end if


		on key (f1)
			exit input

	end input

end main
