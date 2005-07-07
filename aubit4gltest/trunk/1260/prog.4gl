{**
 * @file
 * Decribe the test here
 * @process TEST_GENERAL
 *}
 
#if you need to use database, use "test1"
#database test1
main
define a integer
define b integer
	display "RED    " at 1,20 attribute(red)
	display "BLUE   " at 2,20 attribute(blue)
	display "GREEN  " at 3,20 attribute(green)
	display "YELLOW " at 4,20 attribute(yellow)
	display "MAGENTA" at 5,20 attribute(magenta)
	display "CYAN   " at 6,20 attribute(cyan)
	display "WHITE  " at 7,20 attribute(white)
	display "BLACK  " at 8,20 attribute(black)


	for b=1 to 10 
		for a=1 to 8
			call aclfgl_set_color(a,aclfgl_random(1000),aclfgl_random(1000),aclfgl_random(1000))
		end for
		sleep 1
		# we need to display something
		# incase the screen needs a refresh...
		display " " at 24,1
	end for

end main
