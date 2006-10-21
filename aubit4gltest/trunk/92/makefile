

test_271.4ae: test_271.4gl
	$(FGLC) test_271.4gl -o test_271.4ae
	fcompile test_271.per

compile: test_271.4ae
	
run: test_271.4ae
	sh ./run_test_271
	
clean:
	rm -f 271.errlog
	

ansi_sql_compat:
	@echo "1"


sql_features_used:		; @echo "DATABASE_USED DEFINE_DATETIME DDL_DATETIME CREATE_TEMP_TABLE UI_DISPLAY_LINE_MODE DISPLAY ANSI_INSERT INITIALIZE_NULL "

