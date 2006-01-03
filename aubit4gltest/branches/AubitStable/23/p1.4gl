main
	define	xrec		record
		hdr		char(10),
		hdr_desc	char(10)
	end record
	define lv_flags integer

	clear screen

	open window rptwin at 3, 2 with 20 rows, 78 columns
		attribute (form line first + 1, green, border,
			   prompt line last, comment line last,
			   message line last)

	open form rptform from "p1"
	display form rptform attribute (cyan)

	let lv_flags=0
	options input no wrap
	input xrec.hdr, xrec.hdr_desc without defaults
		from scr_rec.hdr, scr_rec.hdr_desc 

		on key (f1)
			exit input

		on key (f3)
			if infield(scr_rec.hdr) then
				let lv_flags=lv_flags+1
			end if

			if infield(hdr) then
				let lv_flags=lv_flags+2
			end if

		on key (f4)
			if infield(scr_rec.hdr_desc) then
				let lv_flags=lv_flags+1
			error "No I'm not..."
			sleep 1
			end if

			if infield(hdr_desc) then
				let lv_flags=lv_flags+2
			error "No I'm not..."
			sleep 1
			end if

			if lv_flags=3 then
				exit program 0
			else
				exit program 1
			end if


	end input
end main
