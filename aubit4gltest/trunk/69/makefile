
dt.4ae: dt.4gl
	$(FGLC) dt.4gl -o dt.4ae
	fcompile dt.per

compile: dt.4ae
	
run: dt.4ae
	sh ./run_dt

ansi_sql_compat:
	@echo "1"


sql_features_used:		; @echo "DATABASE_USED DEFINE_DATE DEFINE_DATETIME CREATE_TEMP_TABLE ANSI_INSERT UI_DISPLAY_LINE_MODE DISPLAY "

