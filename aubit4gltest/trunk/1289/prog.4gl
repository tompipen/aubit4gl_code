main

define I integer,
 P_INT integer,
 P_SMALLINT smallint,
 P_CHAR char,
 P_CHAR_10 char(10)

display "INT=",P_INT,"="
display "SMALLINT=",P_SMALLINT,"="
display "CHAR=",P_CHAR,"="
if p_char is null then
	display " AND NULL"
end if

display "CHAR_10=",P_CHAR_10,"="
if p_char_10 is null then
	display " AND NULL"
end if

for I=1 to 10
 let P_INT = P_INT + 1
display I, ": INT=",P_INT,"="
end for

end main
