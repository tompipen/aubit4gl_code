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
	display "Form"
        	open window w2 at 2,2 with form "form" attribute(border)

        #display "This is a line in the form" to s_info[1].info_line
		#sleep 2
        #display "This is line 2 in the form" to s_info[2].info_line
        sleep 2
		close window w2


    command "config"

		{
		    initialize env to null
		    let env = " "
		    let varname = "AUBITDIR"

			#This fgl_getenv, using variable, will fail:
			let env = fgl_getenv(varname)

		    #this will display empty line, since fgl_getenv will fail to assign "env"
		    #veriable, and set it to NULL string (bug #470960)
			display varname clipped, " = ", env clipped
		    display varname clipped
		    display env clipped

		}
		    #this fgl_getenv will work OK:
			let env = fgl_getenv("AUBITDIR")
		    #this will display empty line, since fgl_getenv will fail to assign "env"
		    #veriable, and set it to NULL string (bug #470960)
			display "AUBITDIR = ", env clipped at 3,5


			let env = fgl_getenv("MY_TEST")
		    #this will display empty line, since fgl_getenv will fail to assign "env"
		    #veriable, and set it to NULL string (bug #470960)
			display "MY_TEST = ", env clipped at 4, 5 #6


		{
			#this DISPLAY will work OK:
			let env = "something"
		    display varname clipped, " = ", env clipped

		}




	command "exit"
		#display "Exit"
        exit menu
end menu

#message "Exiting.."
end main



