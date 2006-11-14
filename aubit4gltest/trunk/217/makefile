#all: prog.4ae libprog2.so
CFLAGS=-fPIC
prog.4ae: prog.4gl libprog2.so
	export A4GL_NOCLOBBER=Y && ${FGLC} --verbose $< -L. -lprog2 -o $@

libprog2.so: prog2.4gl
	export A4GL_NOCLOBBER=N && ${FGLC} --verbose --as-dll $^ -o $@

run: prog.4ae
	sh ./run_prog
	
clean:


ansi_sql_compat:
	@echo "1"

desc:
	@echo "_variable(...) handling test  - also tests shared library creation"

sql_features_used:		; @echo "DATABASE_USED DROP_TABLE CREATE_TABLE ANSI_DELETE ANSI_INSERT DEFINE_LIKE VALIDATE_LIKE STATUS IF EXIT_PROGRAM_EXPR "

