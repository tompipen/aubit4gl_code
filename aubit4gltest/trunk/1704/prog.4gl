database test1
main
    define l_control int
    define l_orderno int
define l_select char(200)


        create temp table access (
                orderno integer
        )
        insert into access values(1)
        insert into access values(0)
        insert into access values(2)
        insert into access values(NULL)




  let l_select =
    "select ",
    "   case ",
    "       when orderno = 0 then 1",
    "       when orderno IS NULL THEN 0",
    "       else 0",
    "   end,",
    "   orderno",
    "   FROM access"

 prepare p1 from l_select
 declare c1 cursor for p1
 foreach c1 into l_control, l_orderno
        display l_control, " ", l_orderno
    end foreach
end main
