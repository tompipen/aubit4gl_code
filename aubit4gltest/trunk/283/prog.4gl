main
define a,b,c char(3)
open window w1 at 2,2 with form "prog"
options input wrap

input by name a,b,c
display a,b,c
if a!="ABC" or b!="ABC" or c!="ABC" then exit program 1 end if
options input no wrap 

input by name a,b,c
display a,b,c
if a!="ABC" or b!="ABC" or c!="ABC" then exit program 1 end if
exit program 0
end main
