database test1

main
define
   seq_p    smallint,
   scratch  char(200),
   p_table  record 
	trm  smallint,
  	trmnm  char(30),
   	seq    smallint
	end record,
   query_s  char(200)

open window win1 at 2,3 with 20 rows, 70 columns
   attribute (border, red)
open form test32 from "test32b"
display form test32


create temp table testtabb
( trm  smallint,
  trmnm  char(30),
   seq    smallint
);

insert into testtabb values (50,'111111111111111111111111111111',1);
call startlog("out")


let scratch = "select * from testtabb  where seq = ?"
prepare stmt1 from scratch
declare curs1 cursor for stmt1

message "Construct 1"
construct by name query_s on testtabb.trm, testtabb.trmnm
if query_s="testtabb.trm='50'" then
else
	display "Error in Construct 1 :", query_s
	exit program 1
end if

call errorlog(query_s)
let seq_p = 1
open curs1 using seq_p
fetch curs1 into p_table.*

display by name p_table.*

message "Input 1"
input by name p_table.* without defaults

message "Construct 2"
construct by name query_s on testtabb.trm, testtabb.trmnm
call errorlog(query_s)
if query_s="testtabb.trm='50'" then
else
	display "Error in Construct 2:", query_s
	exit program 1
end if

exit program 0
end main
