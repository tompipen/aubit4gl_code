main
define b char(20)
display "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" at 1,1
display "Hello","" at 1,1

let b="World"
display "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" at 2,1
display "Hello",b at 2,1

let b=" "
display "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" at 3,1
display "Hello",b at 3,1

let b=""
display "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" at 4,1
display "Hello",b at 4,1

initialize b to null
display "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" at 5,1
display "Hello",b at 5,1

call aclfgl_dump_screen("out")
end main
