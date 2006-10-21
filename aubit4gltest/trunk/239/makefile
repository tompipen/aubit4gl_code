
#why non-standard makefile? 

compile: prog.4ae

prog.4ae: v1.o prog.4gl
	${FGLC} prog.4gl v1.afr.o -o prog.4ae
	
v1.o: v1.per
	(export A4GL_FORMTYPE=GENERIC; export A4GL_PACKER=PACKED; fcompile -c v1.per)
	${FGLC} -o v1.afr.o --verbose -c v1.afr.c 
	
clean:
	rm -f prog.4ae prog.c prog.glb prog.h v1.afr v1.afr.c v1.afr.dat v1.c v1.err *.o


run: prog.4ae
	export A4GL_KEYFILE=keys.in ; ./prog.4ae
	

ansi_sql_compat:
	@echo "1"


desc:
	@echo "Test of compiling a form into an executable (using fcompile -c)"

sql_features_used:		; @echo "DATABASE_USED DEFINE_CHAR DEFINE_INTEGER DEFINE_SMALLINT DDL_DATETIME CREATE_TEMP_TABLE ANSI_INSERT LET_MANY FOR UI_DISPLAY_LINE_MODE DISPLAY IF EXIT_PROGRAM_EXPR "

