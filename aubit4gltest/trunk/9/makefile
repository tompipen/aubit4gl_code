#OK
m.4ae: m1.4gl g1.4gl
	${FGLC} -c m1.4gl -o m1.o
	${FGLC} -c g1.4gl  -o g1.o
	${FGLC} m1.o g1.o -o m.4ae
	

#Parser not reset correctly after allready processing the same GLOBALS
#file, it will choke when it goes to actually compile it.
#cat 9/g1.err	
#globals
#        define global1 integer
#define grec record
#        aa char(10)
#end record
#end globals
#|^
#| Error at line 36, character 1
#| Variable is already defined (int_flag)
__BAD__m.4ae: m1.4gl g1.4gl	
	${FGLC} $^ -o $@

#OK
yyyyym.4ae: m1.4gl g1.4gl
	${FGLC} -c m1.4gl -o m1.ao
	${FGLC} -c g1.4gl  -o g1.ao
	${FGLC} m1.ao g1.ao -o m.4ae

compile: m.4ae
	
run: m.4ae
	sh ./run_m

ansi_sql_compat:
	@echo "1"

