main
start report xrpt to "rep.out"
output to report xrpt ()
finish report xrpt
end main

REPORT xrpt () 
FORMAT ON EVERY ROW PRINT "x" 
END REPORT 
