# Does a file exist ?

use a4gl_file
main
        if fopen("m1.txt","r") then
                display "OK"
        else
                display "Not ok"
        end if
end main

