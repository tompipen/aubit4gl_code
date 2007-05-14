{**
 * @file
 * insert row=false is not working in HL_*
 *
 * @process TEST_GENERAL
 *}
 
DEFINE ma_head ARRAY[20] OF record
	    t CHAR(1),
	    desc CHAR(40)
	END RECORD,
	m_k_head SMALLINT

MAIN
OPTIONS NEXT KEY CONTROL-A
OPEN WINDOW v_iarr AT 1,1 WITH FORM "iarrf1" ATTRIBUTE(DIM)
FOR m_k_head = 1 TO 10
    LET ma_head[m_k_head].desc = "this is row ", m_k_head
END FOR
LET m_k_head = 7
CALL set_count(m_k_head)
INPUT ARRAY ma_head WITHOUT DEFAULTS FROM sa_head.* 
     ATTRIBUTE(CURRENT ROW DISPLAY="REVERSE",BOLD,
               INSERT ROW=FALSE,DELETE ROW=FALSE)
     ON KEY (CONTROL-B)
         {! call aclfgl_dump_screen("out") }
END INPUT
END MAIN
