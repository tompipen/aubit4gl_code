
# check rounding for decimals
main
define lv_c char(20)
define d8_0 decimal (8,0)
define d8_1 decimal (8,1)
define d8_2 decimal (8,2)
define d8_3 decimal (8,3)
define d8_4 decimal (8,4)
define d8_5 decimal (8,5)
define d8_6 decimal (8,6)

let d8_0=1.11111111111111
let d8_1=1.11111111111111
let d8_2=1.11111111111111
let d8_3=1.11111111111111
let d8_4=1.11111111111111
let d8_5=1.11111111111111
let d8_6=1.11111111111111

let lv_c=d8_0,"|" display lv_c
let lv_c= d8_1,"|" display lv_c
let lv_c= d8_2,"|" display lv_c
let lv_c= d8_3,"|" display lv_c
let lv_c= d8_4,"|" display lv_c
let lv_c= d8_5,"|" display lv_c
let lv_c= d8_6,"|" display lv_c

let d8_0=2.11151111111111
let d8_1=2.11151111111111
let d8_2=2.11151111111111
let d8_3=2.11151111111111
let d8_4=2.11151111111111
let d8_5=2.11151111111111
let d8_6=2.11151111111111

let lv_c= d8_0,"|" display lv_c
let lv_c= d8_1,"|" display lv_c
let lv_c= d8_2,"|" display lv_c
let lv_c= d8_3,"|" display lv_c
let lv_c= d8_4,"|" display lv_c
let lv_c= d8_5,"|" display lv_c
let lv_c= d8_6,"|" display lv_c

let d8_0=2.99951111111111
let d8_1=2.99951111111111
let d8_2=2.99951111111111
let d8_3=2.99951111111111
let d8_4=2.99951111111111
let d8_5=2.99951111111111
let d8_6=2.99951111111111

let lv_c= d8_0,"|" display lv_c
let lv_c= d8_1,"|" display lv_c
let lv_c= d8_2,"|" display lv_c
let lv_c= d8_3,"|" display lv_c
let lv_c= d8_4,"|" display lv_c
let lv_c= d8_5,"|" display lv_c
let lv_c= d8_6,"|" display lv_c

end main
