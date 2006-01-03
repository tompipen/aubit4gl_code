all : in.4ae in_db.4ae

in.4ae: in.4gl
	$(FGLC) in.4gl -o in.4ae

in_db.4ae: in_db.4gl
	$(FGLC) in_db.4gl -o in_db.4ae

compile: all
	
run: all
	sh ./run_in

ansi_sql_compat:
	@echo "1"

sql_features_used:
	@echo "CREATE_TEMP_TABLE  ANSI_SELECT"

desc:
	@echo "Test of Aubit4GL extension - IN and EXISTS as 4GL expression"
db_test:
	@echo "1"
