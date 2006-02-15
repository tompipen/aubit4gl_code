#database sample

define  x,y     smallint

main
        defer interrupt
        options accept key control-q
        #set isolation to dirty read
        #set lock mode to wait
        call startlog("errors")

        open window v1 at 09,02 with form "form1"
        attribute (border,form line first,comment line last,
        prompt line last,message line last-1)

        initialize x to null
        input by name x
                on key (control-w)
                        open window v2 at 14,06 with form "form2"
                        attribute (border,form line first,comment line last,
                        prompt line last,message line last-1)

                        initialize y to null
                        input by name y
                                on key (esc, interrupt)
                                        exit input
                        end input

                        close window v2
		on key(control-b) 
			exit program 0

                on key (esc, interrupt)
                        exit input
        end input
	exit program 1
        close window v1
end main
