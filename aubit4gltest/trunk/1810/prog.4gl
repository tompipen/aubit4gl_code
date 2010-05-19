
main
define zprava text
define jmsoub char(64)
define i,res int

let i = num_args()
if i > 0 then
  let jmsoub = arg_val(1)
else
  let jmsoub = "testWW.txt"
end if

locate zprava in file jmsoub
open window wokno at 1,1 with  form "testWW"

display zprava to zprava
call aclfgl_dump_screen("out")
sleep 1
close window wokno
end main
