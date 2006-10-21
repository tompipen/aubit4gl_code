
simple_null.4ae: simple_null.4gl
	echo "ODBCINI=$(ODBCINI)"
	$(FGLC) simple_null.4gl -o simple_null.4ae

compile: simple_null.4ae
	
run: simple_null.4ae
	sh ./run_simple_null

db_test: 
	@echo "1"

ansi_sql_compat:
	@echo "0"

desc:
	@echo "Test setting some basic types to null"
	
	
sql_features_used:
	@echo "CREATE_TEMP_TABLE DDL_MONEY DDL_DATE DDL_DATETIME DROP_TABLE  DEFINE_LIKE DDL_DECIMAL ANSI_INSERT ANSI_DELETE DEFINE_CHAR DEFINE_SMALLINT DEFINE_INTEGER DEFINE_FLOAT DEFINE_DECIMAL DEFINE_DATE DEFINE_MONEY DEFINE_DATETIME STATUS IF UI_DISPLAY_LINE_MODE DISPLAY"
	
