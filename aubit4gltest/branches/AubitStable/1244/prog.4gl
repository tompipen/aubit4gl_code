
MAIN
DEFINE
	x		CHAR(1)

OPEN WINDOW w1 AT 4, 4 WITH 12 ROWS, 50 COLUMNS 

ATTRIBUTE (BORDER)
OPTIONS 
	PROMPT LINE 7, 
	MESSAGE LINE 8


call disp1()
MESSAGE "Is this line 8?"
PROMPT "Is this line 7?" FOR x
on key(control-b) call aclfgl_dump_screen("w0")
end prompt

CALL another ()

call disp1()
MESSAGE "Is this line 8?"
PROMPT "Is this line 7?" FOR x
on key(control-b) call aclfgl_dump_screen("w1")
end prompt

CLOSE WINDOW w1

END MAIN


FUNCTION another ()
DEFINE
	x		CHAR(1)

OPEN WINDOW w2 AT 6, 6 WITH 12 ROWS, 50 COLUMNS ATTRIBUTE (BORDER)
call disp1()
message "Where is this"
PROMPT "Where is this ?" FOR x
on key(control-b) call aclfgl_dump_screen("w2")
end prompt

OPTIONS
	PROMPT LINE 3,
	MESSAGE LINE 4

call disp1()
MESSAGE "Is this line 4?"
PROMPT "Is this line 3?" FOR x
on key(control-b) call aclfgl_dump_screen("w3")
end prompt

CLOSE WINDOW w2

call disp1()
message "Where is this2"
PROMPT "Where is this2 ?" FOR x
on key(control-b) call aclfgl_dump_screen("w4")
end prompt

END FUNCTION


function disp1()
display "XXXXXXXXXXXXXX" at 1,1
display "XXXXXXXXXXXXXX" at 2,1
display "XXXXXXXXXXXXXX" at 3,1
display "XXXXXXXXXXXXXX" at 4,1
display "XXXXXXXXXXXXXX" at 5,1
display "XXXXXXXXXXXXXX" at 6,1
display "XXXXXXXXXXXXXX" at 7,1
display "XXXXXXXXXXXXXX" at 8,1
end function
