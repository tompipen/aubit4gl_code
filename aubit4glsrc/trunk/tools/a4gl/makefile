
%.ao:%.4gl
	4glpc -g -c $<


#FORMS=prog.afr.dat

all: a4gl.4ae 

a4gl.4ae: a4gl.ao form.ao main.ao module.ao program.ao ../asql/pick.ao  ../asql/filehand.ao ../asql/generic_db.ao subrouts.ao times.ao prog.afr.o settings.afr.o entities.afr.o
	4glpc -g -o $@ $^


%.afr.c:%.per
	fcompile -c $<

%.afr.dat:%.per
	fcompile  $<

