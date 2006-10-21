

v.4ae: v.4gl
	${FGLC} v.4gl -o v.4ae
	fcompile v.per

compile: v.4ae
	
run: v.4ae
	sh ./run_v

ansi_sql_compat:
	@echo "1"


sql_features_used:		; @echo "DATABASE_USED DEFINE_CHAR DEFINE_INTEGER CREATE_TEMP_TABLE ANSI_INSERT CURSOR_SELECT FOREACH UI_DISPLAY_LINE_MODE DISPLAY "

