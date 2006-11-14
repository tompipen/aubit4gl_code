

g1.4ae: g1.4gl
	$(FGLC) g1.4gl -o g1.4ae
	fcompile g1.per

compile: g1.4ae
	
run: g1.4ae
	sh ./run_g1
	
clean:
	rm -f arr.out.nodate
	

ansi_sql_compat:
	@echo "1"


sql_features_used:		; @echo "DATABASE_USED DEFINE_DATETIME DDL_DATETIME CREATE_TEMP_TABLE UI_DISPLAY_LINE_MODE DISPLAY ANSI_INSERT INITIALIZE_NULL   DISPLAY_FORM"

