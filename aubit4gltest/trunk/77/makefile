
getfld.4ae: getfld.4gl
	$(FGLC) getfld.4gl -o getfld.4ae
	fcompile getfld.per

compile: getfld.4ae
	
run: getfld.4ae
	sh ./run_getfld
	
clean:
	rm -f gf.log.nodate


ansi_sql_compat:
	@echo "1"


sql_features_used:		; @echo "DATABASE_USED DEFINE_DATETIME DDL_DATETIME CREATE_TEMP_TABLE UI_DISPLAY_LINE_MODE DISPLAY ANSI_INSERT INITIALIZE_NULL "

