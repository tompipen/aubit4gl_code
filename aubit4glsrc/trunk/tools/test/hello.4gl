main
define env, varname char (60)

define axxx integer
define bxxx record
	a integer,
	b integer
end record

let axxx=1
menu "Hello test"
    command "window" "Open a new window"
		#display "Window"
		open window w1 at 10,30 with 3 rows,20 columns attribute(border)
		display "   Hello  World   " at 2,2 attribute(cyan,reverse)
        sleep 2
		close window w1

	command "form" "Open a form "
		#display "Form"
        	open window w2 at 2,2 with form "form" attribute(border)

        #display "This is a line in the form" to s_info[1].info_line
		#sleep 2
        #display "This is line 2 in the form" to s_info[2].info_line
        sleep 2
		close window w2


    command "config"


		    let varname = "AUBITDIR"
			let env = fgl_getenv(varname)
			display "Using variable: ", varname clipped, " = ", env clipped at 5,5

			
			let env = fgl_getenv("AUBITDIR")
			display "Using string  : ","AUBITDIR = ", env clipped at 6,5


			let env = fgl_getenv("MY__impossible_TEST")
			#this will display empty line, since fgl_getenv will fail to assign "env"
		    #variable because it is not defined anywhere, and set it to NULL string (bug #470960)
			display "MY_TEST = ", env clipped at 7,5 #6


	command "exit"
		#display "Exit"
        exit menu
end menu

#message "Exiting.."
end main



