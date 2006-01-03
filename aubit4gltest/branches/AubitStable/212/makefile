
prog.4ae: prog.4gl
	$(FGLC) prelude.4gl -o prelude
	./prelude
	(export A4GL_SYSCOL_VAL=scv; $(FGLC) prog.4gl -o prog.4ae)

compile: prog.4ae
	
run: prog.4ae
	./prog.4ae
	
clean:
	rm -rf prelude
	

ansi_sql_compat:
	@echo "1"

sql_features_used:
	@echo "DROP_TABLE CREATE_TABLE ANSI_INSERT VALIDATE_LIKE"

desc:
	@echo "VALIDATE check"

db_test:
	@echo "1"
