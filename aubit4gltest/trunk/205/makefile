m2.4ae: m2.4gl
	$(FGLC) m2.4gl -o m2.4ae
	amkmessage m2.msg m2.iem

compile: m2.4ae
	
run: m2.4ae
	sh ./run_m2
	

ansi_sql_compat:
	@echo "1"


desc:
	@echo "Simple test of 'showhelp' function"

sql_features_used:		; @echo "DATABASE_USED DEFINE_SMALLINT CREATE_TEMP_TABLE DEFINE_CHAR PREPARE CURSOR_SELECT SCROLL_CURSOR OPEN_CURSOR "

