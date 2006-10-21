

select.4ae: select.4gl
	$(FGLC) select.4gl -o select.4ae

compile: select.4ae
	
run: select.4ae
	sh ./run_select

ansi_sql_compat:
	@echo "0"

desc:
	@echo "Simple test of what happens when a row is not returned from a select"
	
sql_features_used:
	@echo "CREATE_TEMP_TABLE  DEFINE_CHAR UI_DISPLAY_LINE_MODE DISPLAY"
	
db_test:
	@echo "1"
