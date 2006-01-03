main
define s1 char(200)

	open window w1 at 1,1 with form "bibble"
	construct by name s1 on  b.somecol
	on key(f1)      # Should get an error in field 
			# which means that our ACCEPT will be ignored
		display "F1 pressed"
		exit program 1
	end construct
	display "Here"
	exit program 0


end main
