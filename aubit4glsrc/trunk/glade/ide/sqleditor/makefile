CFLAGS+=-g -I${AUBITDIR}/incl


sqleditor: editor.ao infx.ao ../common/pick.ao ../common/about.ao execute.ao simple_parse.o lex.yy.o main.ao
	4glpc -debug  editor.ao infx.ao ../common/pick.ao ../common/about.ao execute.ao main.ao simple_parse.o lex.yy.o -o sqleditor

editor.ao: editor.4gl
	4glpc -debug  editor.4gl -c -o editor.ao 

infx.ao: infx.4gl
	4glpc -debug  infx.4gl -c -o infx.ao 


../common/pick.ao: ../common/pick.4gl 
	(cd ../common; 4glpc pick.4gl -c -o pick.ao)

main.ao: main.4gl
	4glpc -debug  main.4gl -c -o main.ao 

../common/about.ao: ../common/about.4gl
	(cd ../common; 4glpc about.4gl -c -o ../common/about.ao )

edtprog.ao: edtprog.4gl
	4glpc -debug  edtprog.4gl -c -o edtprog.ao

execute.ao: execute.4gl
	4glpc -debug  execute.4gl -c -o execute.ao

lex.yy.c: parse.l
	flex -i parse.l

clean:
	rm about.ao editor.ao edtprog.ao execute.ao ide1.ao infx.ao pick.ao about.ec editor.ec edtprog.ec execute.ec ide1.ec infx.ec pick.ec *.glb *.o lex.yy.c about.c about.h editor.c editor.h edtprog.c edtprog.h execute.c execute.h ide1.c ide1.h infx.c infx.h lex.yy.c pick.c pick.h



