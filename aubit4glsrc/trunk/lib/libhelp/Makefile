libHELP_std.so: helplib.4gl a4gl_xxhelp.afr.c 
	4glc --namespace "aclfgli_" helplib.4gl
	4glpc -as-dll helplib.c a4gl_xxhelp.afr.c -o libHELP_std.so
	cp libHELP_std.so ..


a4gl_xxhelp.afr.c: a4gl_xxhelp.per
	(export A4GL_PACKER=PACKED; export A4GL_FORMTYPE=GENERIC; fcompile -c a4gl_xxhelp.per)
