database test1

main
	define bk record like books.*
display "Running.."

create temp table "books" (
sq smallint ,
cat char(1) ,
volno smallint ,
vol char(4) ,
title char(50) ,
editor char(30) ,
yr char(20) ,
pyr char(4) ,
iss char(1) ,
retail decimal(8,2) ,
printed smallint ,
freeno smallint ,
subsno smallint ,
soldno smallint ,
stkadj smallint ,
roypc decimal(8,2) ,
cost decimal(8,2) ,
dist decimal(8,2) ,
ohds decimal(8,2) ,
subs1 decimal(8,2) ,
adjst decimal(8,2) ,
udf1 char(30) ,
udv1 decimal(8,2) ,
udf2 char(30) ,
udv2 decimal(8,2) ,
subs2 decimal(8,2) ,
roy2 decimal(8,2) ,
subsnoty smallint ,
subsnoly smallint ,
subsnopy smallint ,
subsnop1 smallint ,
subsnop2 smallint ,
subsnop3 smallint ,
soldnoty smallint ,
soldnoly smallint ,
soldnopy smallint ,
soldnop1 smallint ,
soldnop2 smallint ,
soldnop3 smallint ,
substy decimal(8,2) ,
subsly decimal(8,2) ,
subspy decimal(8,2) ,
subsp1 decimal(8,2) ,
subsp2 decimal(8,2) ,
subsp3 decimal(8,2) ,
roy2ty decimal(8,2) ,
roy2ly decimal(8,2) ,
roy2py decimal(8,2) ,
roy2p1 decimal(8,2) ,
roy2p2 decimal(8,2) ,
roy2p3 decimal(8,2) ,
lastsr char(30) ,
lastroydt date ,
laststkdt date ,
pbid char(6) 
) ;
display "Loading"
	load from "99_books.unl" insert into books;

display "Select"



	select * into bk from books where vol='FULD'
display "Done."

end main




