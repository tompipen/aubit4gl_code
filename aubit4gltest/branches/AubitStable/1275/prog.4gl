main
define b integer
define a integer
define d,e,f integer
define p1,m1 integer
let p1=1
let m1=-1


display "Loop 1"
for a=1 to 20 		display a end for

display "Loop 2"
for a=1 to 20 step 1	display a end for

display "Loop 3"
for a=20 to 1 step -1 	display a end for

let d=1 
let e=10

display "Loop 4"
for a=1 to e 	 	display a end for
display "Loop 5"
for a=1 to e step 1 	display a end for
display "Loop 6"
for a=e to 1 step -1 	display a end for

display "Loop 7"
for a=d to 10 	 	display a end for
display "Loop 8"
for a=d to 10 step 1 	display a end for
display "Loop 9"
for a=10 to d step -1 	display a end for

display "Loop 10"
for a=d to e 	 	display a end for
display "Loop 11"
for a=d to e step 1 	display a end for
display "Loop 12"
for a=e to d step -1 	display a end for

#----------------------------------------------------------

display "Loop 13"
for a=1 to 20 		display a end for

display "Loop 14"
for a=1 to 20 step p1	display a end for

display "Loop 15"
for a=20 to 1 step m1 	display a end for

let d=1 
let e=10

display "Loop 16"
for a=1 to e 	 	display a end for
display "Loop 17"
for a=1 to e step p1 	display a end for
display "Loop 18"
for a=e to 1 step m1 	display a end for

display "Loop 19"
for a=d to 10 	 	display a end for
display "Loop 20"
for a=d to 10 step p1 	display a end for
display "Loop 21"
for a=10 to d step m1 	display a end for

display "Loop 22"
for a=d to e 	 	display a end for
display "Loop 23"
for a=d to e step p1 	display a end for
display "Loop 24"
for a=e to d step m1 	display a end for

end main
