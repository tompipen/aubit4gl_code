{**
 * @file
 * Opening resource files from DBPATH
 * @process TEST_GENERAL
 *}
 

main 
    open window w_info
        at 10, 10
            with form "p1" #in test 23
                attribute
				    (border, green,
				    menu line last - 1,
					form line first)

	sleep 3

#TODO: also test help files and menu files
	
end main
