#OK
m.4ae: m1.4gl g1.4gl
	${FGLC} -o m1.o -c m1.4gl 
	${FGLC} -o g1.o -c g1.4gl  
	${FGLC} -o m.4ae m1.o g1.o 
	

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

desc:
	@echo "Compilation and linking using GLOBALS"

sql_features_used:			; @echo "DATABASE_USED DEFINE_LIKE DDL_DECIMAL DDL_DATE DDL_MONEY DDL_DATETIME CREATE_TEMP_TABLE ANSI_INSERT ANSI_DELETE DROP_TABLE DEFINE_CHAR DEFINE_SMALLINT DEFINE_INTEGER DEFINE_FLOAT DEFINE_DECIMAL DEFINE_DATE DEFINE_MONEY DEFINE_DATETIME STATUS IF UI_DISPLAY_LINE_MODE DISPLAY "

