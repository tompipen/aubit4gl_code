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

