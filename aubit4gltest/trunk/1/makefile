
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
	@echo "CREATE_TEMP_TABLE DDL_MONEY DDL_DATE DDL_DATETIME DROP_TABLE"
	
