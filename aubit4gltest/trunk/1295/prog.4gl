main
define P_LINE char(21),
    DUMMY char(1)

  open window W_TEST at 1,1 with form "f_test"
  let P_LINE = "SOME LONG MESSAGE BLAH BLAH BLAH,    PRESS RETURN"
  prompt P_LINE clipped for char DUMMY
  close window W_TEST
  display "windows closed"
end main
