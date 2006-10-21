
testna.4ae: testna.4gl
	$(FGLC) testna.4gl -o testna.4ae

compile: testna.4ae
	
run: testna.4ae
	sh ./run_testna

ansi_sql_compat:
	@echo "0"


desc:
	@echo "Some basic testing of sqlerrd[2] and sqlerrd[6] (SERIAL)"
	
sql_features_used:
	@echo "CREATE_TEMP_TABLE DDL_SERIAL  DEFINE_INTEGER UI_DISPLAY_LINE_MODE DISPLAY ANSI_INSERT STATUS SQLCA_SQLERRD2 SQLCA_SQLERRD6 IF CURSOR_SELECT FOREACH EXIT_PROGRAM_EXPR"
	
db_test:
	@echo "1"
