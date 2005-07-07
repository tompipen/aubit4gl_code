main
define la_colors array[8] of char(20)
define lv_attrib char(50)
define lv_i smallint

let la_colors[1] = "red"
let la_colors[2] = "blue"
let la_colors[3] = "green"
let la_colors[4] = "white"
let la_colors[5] = "black"
let la_colors[6] = "cyan"
let la_colors[7] = "magenta"
let la_colors[8] = "yellow"
open window w1 at 1, 1 with 24 rows, 80 columns

for lv_i = 1 to 8
  let lv_attrib = la_colors[lv_i] || ", normal"
  display "hello (" || lv_attrib clipped || ")" at lv_i + 1 ,2 attribute(lv_attrib)
  let lv_attrib = la_colors[lv_i] || ", reverse"
  display "hello (" || lv_attrib clipped || ")" at lv_i + 1 ,40 attribute(lv_attrib)
end for
call aclfgl_dump_screen("out")
sleep 1
close window w1

end main
