#database isp
main
	define	xans		char(1)

	clear screen
	prompt "Press F1 to Quit, F3 to show screen:" for char xans
		on key(f1)   display "" at 1,1
			
		on key (f3) call show_screen2()
	end prompt


	prompt "Another Prompt: F1 to Quit, F3 to show screen:" for char xans
		on key(f1)  display "" at 1,1
		on key (f3) call show_screen2()
	end prompt

end main

function show_screen2()

	define	dummy		char(10)

	open window rptwin2 at 5, 5 with 15 rows, 60 columns
		attribute (form line first + 1, green, border,
			   prompt line last, comment line last,
			   message line last)

	open form rptform2 from "prompt"
	display form rptform2 attribute (cyan)
	let dummy = ""
	input by name dummy without defaults
		
		on key (f1)
			exit input
	end input
	close  window rptwin2

end function
