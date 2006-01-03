#and what is r2.4gl for?
all4ae: r1.4gl
#	${FGLC} r1.4gl -o r1.4ae
	${FGLC} --verbose r1.4gl -o r1.4ae
	${FGLC} r1.4gl -o r1.4ae
#We have -eci -ecpg , etc swhitches for this in run_tests script
#	(export A4GL_LEXTYPE=C; ${FGLC} r1.4gl -o r1_i.4ae)
#	(export A4GL_LEXTYPE=EC; export A4GL_LEXDIALECT=INFORMIX;${FGLC} r1.4gl -o r1_iec.4ae)
#	(export A4GL_LEXTYPE=EC; export A4GL_LEXDIALECT=POSTGRES;${FGLC} r1.4gl -o r1_pec.4ae)

compile: all4ae
	
run: compile
	sh ./run_r1
	
db_test:
	 @echo "1"
clean:
	rm -f test_319_iec.rpt  test_319_i.rpt  test_319_pec.rpt  test_319.rpt r1.c.17.lreg
	

ansi_sql_compat:
	@echo "1"

sql_features_used:
	@echo "REPORT_ORDER_BY "
desc:
	@echo "Simple report checking when using ORDER BY (not ORDER EXTERNAL..)"
