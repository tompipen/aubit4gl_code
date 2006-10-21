

moneytype.4ae: moneytype.4gl
	$(FGLC) moneytype.4gl -o moneytype.4ae
	fcompile moneytype.per

compile: moneytype.4ae
	
run: moneytype.4ae
	sh ./run_moneytype

ansi_sql_compat:
	@echo "1"


sql_features_used:		; @echo "DATABASE_USED DEFINE_DATETIME DDL_DATETIME CREATE_TEMP_TABLE UI_DISPLAY_LINE_MODE DISPLAY ANSI_INSERT INITIALIZE_NULL "

