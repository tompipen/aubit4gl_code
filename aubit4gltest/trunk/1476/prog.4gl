database test1

main
define
   q_txt       char(200),
   acptd       smallint,
   sel_shpdt   date,
   xit_pgm     smallint


open window w_sel at 2,2 with form "test47" attribute (border)
   display "Enter your scearch criteria ... <Ctrl-W> for help" at 1, 4
   display "Press <Esc> to scearch; <Del> to exit " at 2, 4

label inp_sel:

current window is w_sel
let acptd = false
let int_flag = false

construct by name q_txt on a.drvnbr,a.trknbr,a.ldnbr
   before construct
      let xit_pgm=0
      let sel_shpdt = null
      display sel_shpdt to shpdt attribute(reverse)
      let int_flag = false
      display " ", " ", " " to drvnbr, trknbr, ldnbr attribute(reverse)

   on key (accept)
      let acptd = true
      exit construct

   on key (control-e)
      let int_flag=0
      let xit_pgm=1
      exit construct

   on key (control-w)
      call show_help()

end construct


display q_txt

if q_txt = "a.ldnbr=12121212" then
   exit program 0
else
   exit program 1
end if

end main

function show_help()

# stub

end function
