database test1

main
define
   q_txt    char(100),
   paultest_r record 
      column1   char(10),
      column2   char(10),
      column3   char(10)
   end record

options
   input wrap

whenever error continue
drop table paultest
whenever error stop

create temp table paultest
( column1   char(10),
  column2   char(10),
  column3   char(10)
)

open window win1 at 2,3 with 21 rows, 76 columns
   attribute (border, red)
open form screen1 from "screen"
display form screen1

construct by name q_txt on paultest.column1, paultest.column2, paultest.column3

if q_txt!="paultest.column1='1' and paultest.column2='1' and paultest.column3='1'" then
	display q_txt
	display "paultest.column1='1' and paultest.column2='1' and paultest.column3='1'" 
	exit program 1
else
	exit program 0
end if

end main
