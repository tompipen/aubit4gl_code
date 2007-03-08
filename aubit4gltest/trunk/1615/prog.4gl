{**
 * @file
 *  set_count() is not working for display array inside an input array.
 *
 * Master detail form, master input array, when selecting one master
 *  display array below.
 * @process TEST_GENERAL
 *}
 

DEFINE ma_head ARRAY[50] OF record
	    t CHAR(1),
	    desc CHAR(40)
	END RECORD,
	ma_deta ARRAY[50] OF record
	    desc char(40)
	END RECORD,
	m_k_head, m_k_deta SMALLINT

MAIN
DEFINE i, j, t SMALLINT
OPEN WINDOW v_cemor AT 1,1 WITH FORM "cemorf1" ATTRIBUTE(DIM)
FOR m_k_head = 1 TO 10
    LET ma_head[m_k_head].desc = "this is row ", m_k_head
END FOR
LET m_k_head = 10
CALL set_count(m_k_head)
INPUT ARRAY ma_head WITHOUT DEFAULTS FROM sa_head.* 
     ATTRIBUTE(CURRENT ROW DISPLAY="REVERSE",BOLD,
               INSERT ROW=FALSE,DELETE ROW=FALSE)
    BEFORE ROW
        LET i = arr_curr()
        LET j = scr_line()
        LET m_k_deta = i * 2
        FOR t = 1 TO m_k_deta
            LET ma_deta[t].desc = "deta ", t USING "<<", 
                                       " from head ", i USING "<<<"
        END FOR
    AFTER FIELD t
        IF ma_head[i].t = "X" THEN
	    CALL set_count(m_k_deta)
	    DISPLAY ARRAY ma_deta TO sa_deta.* 
        END IF
	LET ma_head[i].t = ""
        DISPLAY ma_head[i].* TO sa_head[j].* ATTRIBUTE(UNDERLINE)
END INPUT
{! call aclfgl_dump_screen("out") }
END MAIN
