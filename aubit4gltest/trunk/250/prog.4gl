
main
define a smallint
 open window w at 2,2 with form "f_t"
 let a = 1000
 display by name a
 call aclfgl_dump_screen("out")
 close window w
exit program 0
end main
