
put.4ae: put.4gl
	$(FGLC) put.4gl -o put.4ae

compile: put.4ae
	
run: put.4ae
	sh ./run_put
	

desc:
	@echo "Old makefile"
	
	
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
	@echo "PUT_CURSOR  DEFINE_INTEGER DEFINE_CHAR CREATE_TEMP_TABLE PREPARE CURSOR_SELECT OPEN_CURSOR CLOSE_CURSOR INITIALIZE_NULL FOREACH UI_DISPLAY_LINE_MODE DISPLAY  BEGIN_WORK COMMIT_WORK"



ansi_sql_compat:
	@echo "0"

