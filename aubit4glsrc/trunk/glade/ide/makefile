CFLAGS+=-I${AUBITDIR}/incl

ide1: ide1.ao common/pick.ao common/about.ao edtprog.ao options.ao
	4glpc ide1.ao common/pick.ao common/about.ao edtprog.ao options.ao -o ide1


common/pick.ao: common/pick.4gl
	(cd common; 4glpc pick.4gl -c -o pick.ao )

options.ao: options.4gl
	4glpc options.4gl -c -o options.ao 
	
ide1.ao: ide1.4gl
	4glpc ide1.4gl -c -o ide1.ao 

common/about.ao: common/about.4gl
	(cd common; 4glpc about.4gl -c -o about.ao )

edtprog.ao: edtprog.4gl
	4glpc edtprog.4gl -c -o edtprog.ao


clean:
	rm about.ao editor.ao edtprog.ao execute.ao ide1.ao infx.ao pick.ao about.ec editor.ec edtprog.ec execute.ec ide1.ec infx.ec pick.ec *.glb *.o lex.yy.c about.c about.h editor.c editor.h edtprog.c edtprog.h execute.c execute.h ide1.c ide1.h infx.c infx.h lex.yy.c pick.c pick.h



