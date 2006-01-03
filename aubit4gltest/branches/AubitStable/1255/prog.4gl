MAIN
define x integer
let x=1
START REPORT r_test TO PIPE f_testpipe()
OUTPUT TO REPORT r_test(1)
OUTPUT TO REPORT r_test(2)
OUTPUT TO REPORT r_test(3)
OUTPUT TO REPORT r_test(4)
FINISH REPORT r_test
END MAIN

REPORT r_test(lv_a)
DEFINE lv_a char(10)
FORMAT
ON EVERY ROW
PRINT lv_a
END REPORT

FUNCTION f_testpipe()
DEFINE lv_p VARCHAR(256)
LET lv_p = "grep 2" 
#lpr -Pprinter01"
RETURN lv_p
END FUNCTION
