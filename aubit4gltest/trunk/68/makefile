
all4ae: dtblank.4gl
	${FGLC} dtblank.4gl -o dtblank.4ae
	
compile: all4ae
	
run: compile
	sh ./run_dtblank

ansi_sql_compat:
	@echo "0"

sql_features_used:
	@echo "CREATE_TEMP_TABLE  DEFINE_DATE DEFINE_DATETIME ANSI_INSERT UI_DISPLAY_LINE_MODE DISPLAY"


desc: 
	@echo  "Null string date/datetime checking"

db_test:
	@echo "1"
