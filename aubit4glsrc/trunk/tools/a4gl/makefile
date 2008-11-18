ROOT                    =../..
################
#All stuff common to more then one Aubit compiler make file is there:
include                 ${ROOT}/incl/Makefile-common


%.ao:%.4gl
	4glpc -g -c $<


#FORMS=prog.afr.dat

all: $(ROOT)/bin/a4gl.4ae 

$(ROOT)/bin/a4gl.4ae: a4gl.ao form.ao main.ao module.ao program.ao ../asql/pick.ao  ../asql/filehand.ao ../asql/generic_db.ao subrouts.ao times.ao prog.afr.o settings.afr.o entities.afr.o
	4glpc -g -o $@ $^


%.afr.c:%.per
	fcompile -c $<

%.afr.dat:%.per
	fcompile  $<

clean:
	rm -f a4gl.ao filehand.ao form.ao generic_db.ao main.ao module.ao pick.ao program.ao subrouts.ao  times.ao a4gl.4ae *.afr.*  ../asql/pick.ao  ../asql/filehand.ao ../asql/generic_db.ao
