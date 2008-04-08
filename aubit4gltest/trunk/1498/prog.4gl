
database test1
main 
define l_name char (10)
        create temp table names( firstname CHAR(10))
        insert into names values ('Tom')
        insert into names values ('Dick')
        insert into names values ('Harry')

        DECLARE c_name SCROLL CURSOR WITH HOLD FOR SELECT firstname from names
        OPEN c_name

	while true
                        FETCH NEXT c_name into l_name;
                        if (sqlca.sqlcode!=0) then exit while end if
                        display "NEXT : ",l_name
        end while

	while true
                        FETCH prior c_name into l_name
                        if (sqlca.sqlcode!=0) then exit while end if
                        display "PRIOR : ",l_name
        end while
	while true
                        FETCH NEXT c_name into l_name
                        if (sqlca.sqlcode!=0) then exit while end if
                        display "NEXT : ",l_name
        end while
end main
