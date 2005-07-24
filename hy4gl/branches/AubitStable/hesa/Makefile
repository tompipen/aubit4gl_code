
all: hesa

.c.o:
	gcc  -c $<

hesa: est_dat.o  genera.o  herram.o lexico.o gramat.o
	gcc -o hesa est_dat.o genera.o herram.o lexico.o gramat.o -lfl
	strip hesa

gramat.c: gramat.y
#	yacc -d -ogramat.c gramat.y
	bison  -d -ogramat.c gramat.y

lexico.c: lexico.l yytab.h
	lex  -olexico.c lexico.l

yytab.h: gramat.c

clean:
	rm -f hesa *.o gramat.c lexico.c gramat.h *.bak

install: hesa
	cp hesa /usr/local/bin
