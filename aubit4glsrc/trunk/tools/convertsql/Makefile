#	@(#)$Id: Makefile,v 1.1 2003-02-01 21:47:30 psterry Exp $
#
#	Makefile for convertsql

PROGRAM   = convertsql
ROOT      = ../..

all:	$(PROGRAM)

$(PROGRAM):	main.o convertsql.o
	${CC} -o $@ -L${ROOT}/lib main.o convertsql.o -laubit4gl

%.o:	%.c
	${CC} -I${ROOT}/incl -c $<

install: $(PROGRAM)
	cp $(PROGRAM) ${ROOT}/bin
	cd ${ROOT}/bin ; chmod 755 $(PROGRAM)

clean:
	rm -f *.o $(PROGRAM)

