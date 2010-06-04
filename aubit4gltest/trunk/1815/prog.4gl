main
define a,b,c date
open form p1 from "p1"
display form p1
input a,b,c from fec_hoy, fec_ini, fec_fin
if a!=mdy(1,4,2001) then
	exit program 1
end if
end main
