    define p_test record
               test char(80),
                second_field char(80)
           end record,
       scratch char(1024)

main
    open window win2 at 1,1 with 20 rows, 76 columns
    open form screen1 from "screen"
    display form screen1

    let p_test.test = "0011223344556677889900112233445566778899"
    display p_test.test
    sleep 2

    input p_test.* without defaults from s_test.*
        before field test
	    if p_test.test!="0011223344556677889900112233445566778899" then
            	display "BAD:",p_test.test
		exit program 1
	    end if
            sleep 2
    end input

    display p_test.test
    exit program 0
end main
