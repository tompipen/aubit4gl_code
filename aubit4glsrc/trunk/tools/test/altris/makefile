
LD=/usr2/develop/SCCS/objects
CFLAGS=-s -c

.SUFFIXES:
.SUFFIXES: .msg .hlp .4gl .o .per .frm .ace .arc .c .4go
.c.o:
	gcc $(CFLAGS) random.c key_press.c
.msg.hlp:
	mkmessage $< 
.4gl.o:
	4glpc  $(CFLAGS) altris.4gl
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

altris.4ae : altris.o key_press.o random.o
	4glpc altris.o key_press.o random.o -o altris1.4ae
