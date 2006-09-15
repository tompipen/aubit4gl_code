database test1

main
   define out_p1 char(8)

   display "*** RUNNING err_prop-1 ***"

   whenever error continue
   drop table test
   whenever error stop

   create table test (p1 char(8))
   insert into test values ("row1")

whenever error continue

   declare c1 cursor for select p1 from test
   drop table test;

   foreach c1 into out_p1
     display "p1=<",out_p1,">"
   end foreach

   if sqlca.sqlcode=0 then
   	display "*** DONE OK err_prop-1 - which is bad... ***"
	exit program 1
   else
   	display "Got the error I wanted"
	exit program 0
   end if
end main
