
all4ae: dtblank.4gl
	${FGLC} dtblank.4gl -o dtblank.4ae
	
compile: all4ae
	
run: compile
	sh ./run_dtblank

ansi_sql_compat:
	@echo "0"

sql_features_used:
	@echo "CREATE_TEMP_TABLE"


desc: 
	@echo  "Null string date/datetime checking"
