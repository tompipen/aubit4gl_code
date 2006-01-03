database test1
main
define lv_rec record
	tabname char(18)
end record
open form f1 from "p1"
display form f1

display "tabname1" to tabname
call aclfgl_dump_screen("t1.out")
sleep 1


let lv_rec.tabname="tabname2"
display lv_rec.tabname to tabname
call aclfgl_dump_screen("t2.out")
sleep 1
let lv_rec.tabname="tabname3"

input by name lv_rec.* without defaults
call aclfgl_dump_screen("t3.out")
display lv_rec.tabname to a4gl_syscolatt.tabname
call aclfgl_dump_screen("t4.out")
sleep 1


end main
