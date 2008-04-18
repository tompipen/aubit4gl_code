database test1

define	p_sel			record
	cao_item		char(1),
	fr_create_dt		date,
	to_create_dt		date
end record

#===============================================================================

main
	clear	screen
	call	main_info_print()
end main

#===============================================================================

function main_info_print()

	define	xcnt		smallint,
		xexit		smallint

	open window main_inf_win at 3, 2 with 20 rows, 78 columns
			attribute(green, border)
	open form main_inf_form from "f"
	display form main_inf_form attribute(cyan)
	
		clear form
		initialize p_sel.* to null
		let   p_sel.fr_create_dt = mdy(10,14,2000)
		let   p_sel.cao_item 	 = "B"
		input by name p_sel.* without defaults attribute(white)
				
			on key(f3)
				if	p_sel.cao_item is null then
					next field cao_item
				end if
				call get_fldbuf(fr_create_dt, to_create_dt) returning p_sel.fr_create_dt, p_sel.to_create_dt
				display "ddd2 to_create_dt=*",p_sel.to_create_dt,"*"
				if  p_sel.fr_create_dt is null then
				    error "Is null"
				    next field fr_create_dt
				end if
				if  p_sel.to_create_dt is null then
				    let p_sel.to_create_dt = mdy(10,14,2000)
				    display by name p_sel.to_create_dt
				end if
				if  p_sel.to_create_dt < p_sel.fr_create_dt then
					error "Invalid date"
				    next field fr_create_dt
				end if
	
			on key(f1)		#quit
				let xexit = true
				exit input
		end input
	close window main_inf_win

	display p_sel.*
	if p_sel.to_create_dt=mdy(10,13,2000) and p_sel.to_create_dt=p_sel.fr_create_dt then
		exit program 0
	end if

end function

