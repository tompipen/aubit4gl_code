

r1.4ae: r1.4gl
	$(FGLC) r1.4gl -o r1.4ae

compile: r1.4ae
	
run: r1.4ae
	sh ./run_r1
	
clean:
	rm -f p.rpt
	

ansi_sql_compat:
	@echo "1"


sql_features_used:		; @echo "DATABASE_USED DEFINE_DATE DEFINE_DATETIME CREATE_TEMP_TABLE ANSI_INSERT UI_DISPLAY_LINE_MODE DISPLAY "

