
compile: prog.4ae

prog.4ae: v1.o prog.4gl
	4glpc prog.4gl v1.o -o prog.4ae
	
v1.o: v1.per
	(export A4GL_FORMTYPE=GENERIC; export A4GL_PACKER=PACKED; fcompile -c v1.per)
	4glpc -c v1.afr.c -o v1.o
	
clean:
	rm -f prog.4ae prog.c prog.glb prog.h v1.afr v1.afr.c v1.afr.dat v1.c v1.err v1.o


run: prog.4ae
	export A4GL_KEYFILE=keys.in ; ./prog.4ae
	
