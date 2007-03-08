main
     define
        p_test record
            test char(80)
        end record,
        scratch char(80)
 
     open window win2 at 1,1 with 20 rows, 76 columns
     open form screen1 from "screen"
     display form screen1
 
     let scratch = "0011223344556677889900112233445566778899"
     let p_test.test = scratch clipped
 
     input p_test.* without defaults from s_test.*
         before field test
             exit input
     end input
 
     if scratch <> p_test.test
     then
         display "failed"
         exit program 1
     end if
 
     display "success"
 end main
