{

This is new SHARED handling - removed the old method
(which looked bad) and introduced the "::" syntax as per perl (as someone
here suggested a while ago)

This library in lib/extra_libs/string for string handling as an example.
}



#**************************************************************************
#    Split a line by spaces - return first n fields
#    Eg split("A   B C ",3) Would return "A", "B","C"
#**************************************************************************
FUNCTION split(p_line,n)
DEFINE p_line CHAR(256)
DEFINE n INTEGER
DEFINE a INTEGER
DEFINE b integer
DEFINE c INTEGER

DEFINE lv_arr ARRAY[100] OF CHAR(256)
LET b=0
LET c=0

FOR a=1 TO 20
        LET lv_arr[a]=" "
END FOR

FOR  a=1 TO length(p_line)

        IF p_line[a]!=' ' AND b=0 THEN
                LET b=1
                LET c=c+1
        END IF

        IF p_line[a]=' ' AND b=1 THEN
                LET b=0
        END IF

        IF b=1 THEN
                LET lv_arr[c]=lv_arr[c] CLIPPED,p_line[a]
        END IF
END FOR

CASE n
        WHEN 1 RETURN lv_arr[1]
        WHEN 2 RETURN lv_arr[1],lv_arr[2]
        WHEN 3 RETURN lv_arr[1],lv_arr[2],lv_arr[3]
        WHEN 4 RETURN lv_arr[1],lv_arr[2],lv_arr[3],lv_arr[4]
        WHEN 5 RETURN lv_arr[1],lv_arr[2],lv_arr[3],lv_arr[4],lv_arr[5]
        WHEN 6 RETURN lv_arr[1],lv_arr[2],lv_arr[3],lv_arr[4],lv_arr[5],lv_arr[6]
        WHEN 7 RETURN lv_arr[1],lv_arr[2],lv_arr[3],lv_arr[4],lv_arr[5],lv_arr[6],lv_arr[7]
        WHEN 8 RETURN lv_arr[1],lv_arr[2],lv_arr[3],lv_arr[4],lv_arr[5],lv_arr[6],lv_arr[7],lv_arr[8]
        WHEN 9 RETURN lv_arr[1],lv_arr[2],lv_arr[3],lv_arr[4],lv_arr[5],lv_arr[6],lv_arr[7],lv_arr[8],lv_arr[9]
        WHEN 10 RETURN lv_arr[1],lv_arr[2],lv_arr[3],lv_arr[4],lv_arr[5],lv_arr[6],lv_arr[7],lv_arr[8],lv_arr[9],lv_arr[10]
END CASE

END FUNCTION
