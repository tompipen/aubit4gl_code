main
define c,d char(30)
define lv_a array[10] of record
	c,d char(30)
end record
define a integer
define s1 char(255)

for a=1 to 10 
	let lv_a[a].c=a using "<<<"
	let lv_a[a].d="Desc for ",a using "<<<"
end for
open window w1 at 2,2 with form "v1" 
defer interrupt

let int_flag=false
display "Input" at 13,1
input c,d from code_i,desc_i
after field code_i
	message ">code_i" sleep 1
after field desc_i
	message ">desc_i" sleep 1

before field code_i
	message "<code_i"
before field desc_i
	message "<desc_i"

end input


display int_flag at 1,1

let int_flag=false

display "Construct" at 13,1
construct s1 on code_i,desc_i from code_i,desc_i
after field code_i
	message ">code_i" sleep 1
after field desc_i
	message ">desc_i" sleep 1

before field code_i
	message "<code_i"
before field desc_i
	message "<desc_i"

end construct


let int_flag=false

call set_count(8)

display "display array" at 13,1
display array lv_a to srec1.*

display int_flag at 2,1
let int_flag=false

display "Input array  " at 13,1
input array lv_a from srec1.*
display int_flag at 3,1


sleep 2
end main
