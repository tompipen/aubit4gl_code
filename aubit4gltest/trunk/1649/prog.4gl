{**
 * @file
 * Check for lastkey() in an input array
 *   failing (MID 1041) prevpage and nextpage
 * @process TEST_GENERAL
 *}
 
DEFINE ma_head ARRAY[20] OF record
            t1, t2 CHAR(5)
        END RECORD,
        m_k_head SMALLINT

MAIN
DEFINE w_file CHAR(15)
OPEN WINDOW v_iarr AT 1,1 WITH FORM "lastkey" ATTRIBUTE(DIM)
FOR m_k_head = 1 TO 10
    LET ma_head[m_k_head].t1 = "row", m_k_head USING "<<"
    LET ma_head[m_k_head].t2 = "f2 ", m_k_head USING "<<"
END FOR
LET m_k_head = 7
LET w_file = "out.expected"
{! LET w_file = "out" !}
START REPORT alog TO w_file
CALL set_count(m_k_head)
INPUT ARRAY ma_head WITHOUT DEFAULTS FROM sa_head.* ATTRIBUTE(BOLD)
     BEFORE FIELD t1
        CALL logkey()
     BEFORE FIELD t2
        CALL logkey()
END INPUT
FINISH REPORT alog
END MAIN

FUNCTION logkey()
DEFINE lv_d_key CHAR(10),
       lv_i_key INT
LET lv_i_key = fgl_lastkey()
CASE lv_i_key
    WHEN fgl_keyval("prevpage")  LET lv_d_key = "prevpage"
    WHEN fgl_keyval("nextpage")  LET lv_d_key = "nextpage"
    WHEN fgl_keyval("up")        LET lv_d_key = "up"
    WHEN fgl_keyval("down")      LET lv_d_key = "down"
    WHEN fgl_keyval("tab")       LET lv_d_key = "tab"
    WHEN fgl_keyval("left")      LET lv_d_key = "left"
    WHEN fgl_keyval("right")     LET lv_d_key = "right"
    WHEN fgl_keyval("accept")    LET lv_d_key = "accept"
    WHEN fgl_keyval("return")    LET lv_d_key = "return"
    WHEN fgl_keyval("next")      LET lv_d_key = "next"
    WHEN fgl_keyval("previous")  LET lv_d_key = "previous"
    WHEN fgl_keyval("help")      LET lv_d_key = "help"
    WHEN fgl_keyval("delete")    LET lv_d_key = "delete"
    WHEN fgl_keyval("insert")    LET lv_d_key = "insert"
    WHEN fgl_keyval("interrupt") LET lv_d_key = "interrupt"
    WHEN fgl_keyval("esc")       LET lv_d_key = "esc"
    OTHERWISE                    LET lv_d_key = "other"
END CASE
OUTPUT TO REPORT alog(lv_d_key)
END FUNCTION

REPORT alog(p_key)
DEFINE p_key CHAR(10)
OUTPUT LEFT MARGIN 0 TOP MARGIN 0 BOTTOM MARGIN 0 PAGE LENGTH 1
FORMAT
ON EVERY ROW PRINT p_key
END REPORT
