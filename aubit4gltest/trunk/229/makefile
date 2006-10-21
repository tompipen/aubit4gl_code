
prog.4ae: prog.4gl
	fcompile v5.per 
	$(FGLC) prog.4gl -o prog.4ae

compile: prog.4ae
	
desc:
	@echo "This test checks that the comments are removed after an input/input array"
run: prog.4ae
	sh ./run_prog

ansi_sql_compat:
	@echo "1"


sql_features_used:		; @echo "DATABASE_USED DEFINE_CHAR DEFINE_INTEGER DEFINE_SMALLINT DDL_DATETIME CREATE_TEMP_TABLE ANSI_INSERT LET_MANY FOR UI_DISPLAY_LINE_MODE DISPLAY IF EXIT_PROGRAM_EXPR "

