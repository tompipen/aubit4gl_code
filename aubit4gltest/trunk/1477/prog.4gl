database sysmaster

main
define
   qry_str   char(200),
   otrm_l    smallint

open window win1 at 2,2 with 22 rows, 77 columns
   attribute (border)
open form test48 from "test48"
display form test48

let otrm_l = 49

construct by name qry_str on a.dlvdt, a.otrm, a.shptomfg attribute (reverse)

before construct
   display otrm_l to formonly.otrm attribute (reverse)

before field otrm
   let otrm_l = 49
   display otrm_l to formonly.otrm attribute (reverse)

after field otrm
   let otrm_l = get_fldbuf(otrm)

end construct

close form test48
close window win1
clear screen
display qry_str
if qry_str="a.dlvdt between '01/01/2001' and '01/01/2001' and a.otrm='19'" then
	exit program 0
else
	exit program 1
end if

end main
