main 
define dt datetime year to second 

let dt = "A004-05-40 01:02:03" display dt 
if dt is not null then exit program 1 end if
let dt = "0004-A5-40 01:02:03" display dt 
if dt is not null then exit program 1 end if
exit program 0
end main 

