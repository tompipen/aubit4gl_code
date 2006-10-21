

arr3a.4ae: arr3a.4gl
	$(FGLC) arr3a.4gl -o arr3a.4ae
	fcompile arr3a.per

compile: arr3a.4ae
	
run: arr3a.4ae
	sh ./run_arr3a
	
clean:
	rm -f out1
	

ansi_sql_compat:
	@echo "1"


sql_features_used:		; @echo "DATABASE_USED DEFINE_DATE DEFINE_DATETIME CREATE_TEMP_TABLE ANSI_INSERT UI_DISPLAY_LINE_MODE DISPLAY "

