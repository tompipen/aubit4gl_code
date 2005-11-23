database test1

main

call do_call()

end main

function do_call()
define
   t_rec record like systables.*

call do_receive(t_rec.*)

end function

function do_receive(r_rec)
define
   r_rec record like systables.*

end function
