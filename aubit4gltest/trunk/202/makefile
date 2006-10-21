

m1.4ae: m1.4gl
	$(FGLC) m1.4gl -o m1.4ae
	fcompile d3.per

compile: m1.4ae
	
run: m1.4ae
	sh ./run_m1
	
clean:
	rm -f m1.out.nodate

ansi_sql_compat:
	@echo "1"

desc:
	@echo "Multiple input statements"

sql_features_used:		; @echo "DATABASE_USED DEFINE_SMALLINT CREATE_TEMP_TABLE DEFINE_CHAR PREPARE CURSOR_SELECT SCROLL_CURSOR OPEN_CURSOR "

