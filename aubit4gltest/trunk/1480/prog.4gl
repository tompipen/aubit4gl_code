database  test1

main
define
   qry_txt   char(200)


options form line 3, comment line last - 1, message line last - 1,
   prompt line last - 1, input wrap

initialize qry_txt to null

open window win1 at 2,3 with 21 rows, 76 columns
   attribute (border)
open form test51 from "test51"
display form test51

let int_flag=false
construct by name qry_txt on sysdatabases.created, sysdatabases.name

if int_flag=true
then
	exit program 1
end if

close form test51
close window win1

display qry_txt

if qry_txt!="sysdatabases.created between '07/01/2006' and '07/07/2006'"
then
	exit program 1
end if
end main
