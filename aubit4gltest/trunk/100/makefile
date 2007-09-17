
rep.4ae: rep.4gl
	$(FGLC) rep.4gl -o rep.4ae

compile: rep.4ae
	
run: rep.4ae
	sh ./run_rep
	
desc:
	@echo "insert cursor (in a similar way to an order by report)"
	
	
################
#If database this test runs against MUST have transactions support, set to "1"
#If database this test runs against MUST NOT have transactions support, set to "2"
#"0" means "don't care"
transaction:
	@echo "1"
	
db_test:
	@echo "1"

#################
#List here any SQL dialect-specific features that may be incompatible
#with some database back-ends, like:
#ALTER_INDEX CREATE_AUDIT CREATE_DATABASE CREATE_SYNONYM CREATE_TEMP_TABLE 
#CREATE_VIEW DROP_AUDIT DROP_INDEX DROP_SYNONYM GRANT RECOVER_TABLE 
#RENAME_COLUMN RENAME_TABLE REVOKE ROLLFORWARD_DATABASE SELECT_INTO_TEMP 
#SET_EXPLAIN SET_LOG START_DATABASE UPDATE_STATISTICS
#SERIAL ROWID PUT_CURSOR
#...etc...
#See run_tests script for full list of features the are checked against
sql_features_used:
	@echo "PUT_CURSOR  DEFINE_CHAR DEFINE_INTEGER UI_DISPLAY_LINE_MODE DISPLAY CREATE_TEMP_TABLE PREPARE CURSOR_SELECT OPEN_CURSOR FOR CLOSE_CURSOR FOREACH ANSI_DELETE IFX_SYSTABLES INSERT_INTO_SELECT_FROM ANSI_INSERT USE_REPORT REPORT_ORDER_BY ON_EVERY_ROW  BEGIN_WORK COMMIT_WORK"


ansi_sql_compat:
	@echo "0"

