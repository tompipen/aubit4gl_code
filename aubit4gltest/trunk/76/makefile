

datetime.4ae: datetime.4gl
	$(FGLC) datetime.4gl -o datetime.4ae

compile: datetime.4ae
	
db_test:
	@echo "1"
run: datetime.4ae
	sh ./run_datetime

ansi_sql_compat:
	@echo "0"


desc:
	@echo "Basic DB exercising of Datetimes"
	
sql_features_used:
	@echo "CREATE_TEMP_TABLE DDL_DATETIME  DEFINE_DATETIME UI_DISPLAY_LINE_MODE DISPLAY ANSI_INSERT INITIALIZE_NULL"
	
