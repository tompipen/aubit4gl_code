

prog.4ae: prog.4gl
	fcompile g1.per
	$(FGLC)  prog.4gl -o prog.4ae
desc:
	@echo "This test exercises the 'scroll' command"

compile: prog.4ae
	
run: prog.4ae
	sh ./run_prog

ansi_sql_compat:
	@echo "1"


sql_features_used:		; @echo "DATABASE_USED DROP_TABLE CREATE_TABLE ANSI_DELETE ANSI_INSERT DEFINE_LIKE VALIDATE_LIKE STATUS IF EXIT_PROGRAM_EXPR "

