constru.4ae: constru.4gl
	$(FGLC) constru.4gl -o constru.4ae
	fcompile constru.per

compile: constru.4ae
	
run: constru.4ae
	sh ./run_constru
db_test:
	@echo "1"

ansi_sql_compat:
	@echo "1"

sql_features_used:
	@echo "CREATE_TEMP_TABLE ANSI_INSERT ANSI_SELECT CURSOR_SELECT"

