DATABASE test1

main
	call xx()
end main

FUNCTION xx()
DEFINE   t_tab1   RECORD LIKE tab1.*

DECLARE cur CURSOR FOR
        SELECT x, y, z INTO t_tab1.x, t_tab1.y, t_tab1.z from tab1 where x = 10
END FUNCTION
