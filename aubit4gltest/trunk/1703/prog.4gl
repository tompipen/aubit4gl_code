database test1
main
    define l_control int
    define l_orderno int
	create temp table access (
		orderno integer
	)
	insert into access values(1)
	insert into access values(0)
	insert into access values(2)
	insert into access values(NULL)
	
     
    declare c1 cursor for
    select
        case
            when orderno = 0 then 1
            when orderno IS NULL THEN 0
            else 0
        end,
        orderno
        FROM access

    foreach c1 into l_control, l_orderno
        display l_control, " ", l_orderno
    end foreach
end main
