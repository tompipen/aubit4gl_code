#4GLPC=4glpc -verbose
4GLPC=4glpc

#all: prog.4ae libprog2.so

prog.4ae: prog.4gl libprog2.so
	export A4GL_NOCLOBBER=Y && ${4GLPC} $< -L. -lprog2 -o $@

libprog2.so: prog2.4gl
	export A4GL_NOCLOBBER=N && ${4GLPC} -as-dll $^ -o $@

run: prog.4ae
	sh ./run_prog
	
clean:

