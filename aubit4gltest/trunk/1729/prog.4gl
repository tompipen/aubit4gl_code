


function callback(copyof a, copyof b)
define a,b integer
if a>b then return 1 end if
if a=b then return 0 end if
return -1
end function


main

define lv_a array[10] of integer

let lv_a[1]= 4
let lv_a[2]= 3
let lv_a[3]= 1
let lv_a[4]= 2
let lv_a[5]= 5
let lv_a[6]= 2
let lv_a[7]= 9
let lv_a[8]= 8
let lv_a[9]= 1
let lv_a[10]= 7

sort lv_a using callback

display lv_a[1]
display lv_a[2]
display lv_a[3]
display lv_a[4]
display lv_a[5]
display lv_a[6]
display lv_a[7]
display lv_a[8]
display lv_a[9]
display lv_a[10]


end main
