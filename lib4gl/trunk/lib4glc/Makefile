
Surprise! Not a real Makefile, but a rough overview of the important points.

LIB = somelibname.a
FGLGO = nameOfIFXfglgo
FGLDB = nameOfIFXfgldb
FGLRUN = nameOf4jsRunner

Make sure the include directory list (-I for most C compilers) includes

INFINC1 = $(INFORMIXDIR)/incl
INFINC2 = $(INFORMIXDIR)/incl/tools
4JSINC = $(FGLDIR)/include
INCL = -I$(INFINC2) -I$(INFINC1) -I$(4JSINC)

if using gcc, try this:
CC=gcc
FGLCC=gcc
CFLAGS=-O

if using SCO, try this:
CFLAGS='-O -b elf -w3'

if using HP-UX, try this:
CFLAGS='-O -ae'

If HP-UX on the PA-RISC2, add:
    -DBIG_MUTHA_HP

.c.o:
	@echo $(CC) $<
	$(CC) -c $(CFLAGS) $(DEFINES) $(INCL) $<

# I disable this rule to prevent a slow compile-and-archive
.c.a:;

OBJFILES =\
	cfun4gl.o  c_alarm.o    c_bits.o   c_daemon.o c_direct.o
	c_errno.o  c_getkey.o   c_getprg.o c_getpsh.o c_is4js.o
	c_math.o   c_md5.o      c_memory.o c_msg.o    c_passwd.o
	c_printf.o c_process.o  c_rawio.o  c_regex.o  c_sem.o
	c_socket.o c_statfile.o c_stdio.o  c_string.o c_stub4j.o
	c_time.o   j_getkey.o   j_is4js.o

SRCFILES = $(OBJFILES:.o=.c)

# this is mildly aggravating - is there some special make feature to 
# build this list automagically?
#
LIBFILES =\
	$(LIB)(cfun4gl.o)    $(LIB)(c_alarm.o)   $(LIB)(c_bits.o)   \
	$(LIB)(c_daemon.o)   $(LIB)(c_direct.o)  $(LIB)(c_errno.o)  \
	$(LIB)(c_getkey.o)   $(LIB)(c_getprg.o)  $(LIB)(c_getpsh.o) \
	$(LIB)(c_is4js.o)    $(LIB)(c_math.o)    $(LIB)(c_md5.o)    \
	$(LIB)(c_memory.o)   $(LIB)(c_msg.o)     $(LIB)(c_passwd.o) \
	$(LIB)(c_printf.o)   $(LIB)(c_process.o) $(LIB)(c_rawio.o)  \
	$(LIB)(c_regex.o)    $(LIB)(c_sem.o)     $(LIB)(c_socket.o) \
	$(LIB)(c_statfile.o) $(LIB)(c_stdio.o)   $(LIB)(c_string.o) \
	$(LIB)(c_stub4j.o)   $(LIB)(c_time.o)    $(LIB)(j_getkey.o) \
	$(LIB)(j_is4js.o)

functions:
	big_fun.ksh

fdecls.h: $(SRCFILES)
	echo creating fdecls.h
	functions.pl --fdecls $(SRCFILES) > fdecls.h

fgiusr.inc: $(SRCFILES)
	echo creating fgiusr.inc
	functions.pl --fgiusr $(SRCFILES) > fgiusr.inc

fglext.inc: $(SRCFILES)
	echo creating fglext.inc
	functions.pl --fglext $(SRCFILES) > fglext.inc

$(OBJFILES): cfun4gl.h

$(LIBFILES): cfun4gl.h

$(LIB)(c_errno.o): c_errno.h

$(LIB)(c_socket.o): c_socket.h

$(LIB)(c_md5.o): md5.h md5glob.h

$(LIB): $(LIBFILES)
	@echo $(CC) $(?:.o=.c)
	$(CC) -c $(CFLAGS) $(INCL) $(?:.o=.c)
	@echo updating $(LIB)
	ar r $(LIB) $?
	rm $?

$(FGLGO): fgiusr.c fgiusr.h fdecls.h $(LIB)
	echo Creating custom $@
	cfglgo $(DEFINES) -DCFGL_FGLGO -o $@ fgiusr.c $(LIB) -lm -lsocket -lc
	strip $@

$(FGLDB): fgiusr.c fgiusr.h fdecls.h $(LIB)
	echo Creating custom $@
	cfgldb $(DEFINES) -DCFGL_FGLDB -o $@ fgiusr.c $(LIB) -lm -lsocket -lc
	strip $@

$(FGLRUN): fglext.c fglext.h fdecls.h $(LIB)
	echo Creating custom $@
	[[ $(ENGINE) -ge 700 ]] || fglmkrun -o $(FGLRUN) -d ix410 fglext.c $(LIB)
	[[ $(ENGINE) -lt 700 ]] || fglmkrun -o $(FGLRUN) -d ix711 fglext.c $(LIB)
