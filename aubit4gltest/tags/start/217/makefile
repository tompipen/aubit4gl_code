all: prog.4ae libprog2.so

prog.4ae: prog.4gl libprog2.so
	export A4GL_NOCLOBBER=Y && 4glpc prog.4gl -L. -lprog2 -o prog.4ae

libprog2.so: prog2.4gl
	export A4GL_NOCLOBBER=N && 4glpc -as-dll prog2.4gl -o libprog2.so

run: prog.4ae
	sh ./run_prog
