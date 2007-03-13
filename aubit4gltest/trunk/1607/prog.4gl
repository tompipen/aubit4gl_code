{**
 * @file
 * A 'basic' input array fails with LEXTYPE=EC and works in C mode
 * need certain (unidentified) variables module scope, and some SQL code
 * to be reproduced
 * @process TEST_GENERAL
 *}
 
database test1
DEFINE  ma_abon ARRAY[10] OF RECORD
	   edlinucl   int,
	   d_edlinucl char(20),
	   edlidocu   char(10),
	   w_sald     money,
	   w_x        CHAR(1),
	   w_abon     Decimal(10,2),    
	   w_ppag     Decimal(10,2),     
	   edlibaem   smallint,
	   edlinuch   smallint,
	   w_a        CHAR(1)
	END RECORD,
	m_fech date

main
define i,j, w_cant int

create temp table clelinea (edlifech date, edlidocu char(10))
OPEN WINDOW v_abon AT 1,1 WITH FORM "abon" ATTRIBUTE(DIM)
LET m_fech = today
LET ma_abon[1].edlinucl = 123
LET ma_abon[1].d_edlinucl = "el 123"
LET ma_abon[1].edlidocu = "AAAA"
LET ma_abon[1].w_sald   = 10000
LET ma_abon[1].w_x      = 1
LET ma_abon[1].w_abon   = 10000
LET ma_abon[1].w_ppag   = 0
LET ma_abon[1].edlibaem = 0
LET ma_abon[1].edlinuch = 0
call set_count(1)
INPUT ARRAY ma_abon WITHOUT DEFAULTS FROM w_array.* ATTRIBUTE(UNDERLINE,BOLD)
	BEFORE ROW
	    LET i = arr_curr()
	    LET j = scr_line()
        AFTER FIELD w_fabon
	       SELECT COUNT(*) INTO w_cant FROM clelinea
	          WHERE edlifech = m_fech AND edlidocu = "AAAA"
END INPUT
CLOSE WINDOW v_abon
end main
