DATABASE test1
# MID : 514

main
	call xx()
end main


FUNCTION xx()
WHENEVER ERROR CONTINUE
DROP TABLE tab3
WHENEVER ERROR STOP
CREATE TEMP TABLE tab2 (t2_x   money(12, 2), t2_y   smallint)
CREATE TABLE tab3 (t2_x   money(12, 2), t2_y   smallint)
DROP TABLE tab3
END FUNCTION
