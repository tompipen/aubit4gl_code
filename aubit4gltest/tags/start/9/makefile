
m.4ae: m1.4gl g1.4gl
	4glpc -c m1.4gl -o m1.o
	4glpc -c g1.4gl  -o g1.o
	4glpc m1.o g1.o -o m.4ae

compile: m.4ae
	
run: m.4ae
	sh ./run_m
