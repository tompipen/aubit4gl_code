
LD=/usr2/develop/SCCS/objects
CFLAGS=-s -c

.SUFFIXES:
.SUFFIXES: .msg .hlp .4gl .o .per .frm .ace .arc .c .4go
.c.ao:
	gcc $(CFLAGS) random.c key_press.c
.msg.hlp:
	mkmessage $< 
.4gl.ao:
	${FGLPCEXEC} $(CFLAGS) altris.4gl
.per.frm: 
	fcompiple $<
.ace.arc: 
	saceprep $<
.4gl.4go:
	fglpc $<

EXE=\
altris.4ae

RDS=\
altris.4gi

EXE: $(EXE)

RDS: $(RDS)

altris.4ae : altris.ao key_press.o random.o
	${FGLPCEXEC} altris.ao key_press.o random.o -o altris1.4ae
