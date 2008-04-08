{**
 * @file
 * nested INPUTs, cursor remain in second input
 * @process TEST_GENERAL
 *}
 
#Use 	
# test on nested INPUTs
# Test description:
# User inputs some information in first INPUT operator, 
# then presses PgDn and moves to the nested INPUT operator, 
# inputs some information here and then returns back by pressing F10. 
# But cursor still is in a field in the nested 'subform' 
# despite we leave the nested INPUT operator. If user leaves 
# field (by Enter or arrow keys) then cursor jumps into the proper 
# field in the first 'subform'.
#
# The bug is the next: 
# cursor should jump to the field in the first 'subform' 
# immediately after exiting of nested INPUT operator. 
DEFINE    head       RECORD
              str1  CHAR(40),
              str2  CHAR(40)
          END RECORD    ,
          sub_form   RECORD
              sub1  CHAR(40),
              sub2  CHAR(40)
          END RECORD

MAIN    
    INITIALIZE head.*, sub_form.* TO NULL
    CALL Form1()
END MAIN

FUNCTION Form1()
    OPEN WINDOW Window1 AT 3,8 WITH FORM "anaresti"
         ATTRIBUTE (BORDER, CYAN, FORM LINE FIRST, COMMENT LINE LAST,
                    MESSAGE LINE LAST, PROMPT LINE LAST)
    OPTIONS      DELETE KEY F36,
                 INSERT KEY F36,      
                 ACCEPT KEY F36,      
                 NEXT KEY F36,
                 PREVIOUS KEY F36,
                 INPUT WRAP    
    INPUT BY NAME head.* WITHOUT DEFAULTS
	ON KEY (INTERRUPT,ESCAPE,F10)
	    LET int_flag = 0
	    EXIT INPUT
	ON KEY (CONTROL-B)
            CALL Form2()
    END INPUT
    {! call aclfgl_dump_screen("out") !}
    IF head.str1 <> "55" THEN 
        DISPLAY "bad str1:", head.str1, ":"
        EXIT PROGRAM 1 
    END IF
    IF head.str2 <> "22" THEN 
        DISPLAY "bad str2:", head.str2, ":"
        EXIT PROGRAM 1 
    END IF
    IF sub_form.sub1 <> "33" THEN 
        DISPLAY "bad sub1:", sub_form.sub1, ":"
        EXIT PROGRAM 1 
    END IF
    IF sub_form.sub2 <> "44" THEN 
        DISPLAY "bad sub2:", sub_form.sub2, ":"
        EXIT PROGRAM 1 
    END IF
    CLOSE WINDOW Window1
END FUNCTION

FUNCTION Form2()
    INPUT BY NAME sub_form.* WITHOUT DEFAULTS
	ON KEY (INTERRUPT,ESCAPE,F10)
	   LET int_flag = 0
	    EXIT INPUT
    END INPUT
END FUNCTION
