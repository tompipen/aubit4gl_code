#database isp
main
	define  rptinfo		array[100] of record
		rcode		smallint,
		item_rpt_desc	char(10)
	end record
	define	xrow		smallint,
		xscr		smallint,
		xcnt		smallint,
		xquit		smallint,
		counter		smallint,
		xkey		integer

	clear screen
	let xquit = false

	call startlog("271.errlog")
	open window rptwin at 3, 2 with 20 rows, 78 columns
		attribute (form line first + 1, green, border,
			   prompt line last, comment line last,
			   message line last)

	open form rptform from "test_271"
	display form rptform attribute (cyan)

	options next key f34
	options previous key f35
	options delete key control-b
options accept key control-p

	for counter = 1 to 99
		initialize rptinfo[counter].* to null
		let rptinfo[counter].rcode = counter
		let rptinfo[counter].item_rpt_desc = "Desc: ",counter
	end for
	let counter = counter - 1

	call set_count(counter)
	let xquit = false
	input array rptinfo without defaults from scr_arr.* 
		attribute (white)

		#after field rcode
			#let xkey = fgl_lastkey()
			#error "Last Key Value=",xkey, " Key val for next:",fgl_keyval("pgup")," ",fgl_keyval("pagedown")
		
		#on key(delete) call errorlog("DELETE!!!")

		before delete
			call errorlog("BEFORE DELETE")

		after delete
			call errorlog("AFTER DELETE")

		after row
			call errorlog("AFTER ROW")

		before row
			call errorlog("BEFORE ROW")

		before field rcode
			call errorlog("BEFORE RCODE")

		after field rcode
			call errorlog("AFTER RCODE")

		on key (f1)
			exit input
	end input

end main

