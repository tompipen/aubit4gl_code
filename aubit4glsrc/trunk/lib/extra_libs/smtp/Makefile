ROOT    =../../..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common


all: ${PLUGINDIR}/libfgl_smtp.so test_smtp test_rep 

4GLC    =${ROOT}/bin/4glc
CFLAGS+= -I. -I./src ${SMTP_INC_FLAGS} ${VERBOSE_FLAG}  `pkg-config --cflags glib-2.0` -I$(smtpdir)/include   
smtpdir=./libsmtp-0.8

${PLUGINDIR}/libfgl_smtp.so: aubit_smtp.o
	${LD} ${SMTP_LIB_FLAGS} ${SO_LDFLAGS} ${CFLAGS} -o $@ $^ -L$(smtpdir)/lib -L${ROOT}/lib -l${AUBITLIBFULL} -lsmtp -lsmtp_mime `pkg-config --libs glib-2.0`

aubit_smtp.c: aubit_smtp.4gl
	export A4GL_OBJ_EXT=.o; export A4GL_SQLTYPE=nosql; export A4GL_LEXTYPE=C; \
	                ${4GLC} $^



test_smtp: test_smtp.4gl
	${FGLPC_NAME} test_smtp.4gl -o test_smtp
test_rep: test_rep.4gl
	${FGLPC_NAME} test_rep.4gl -o test_rep

clean: 
	rm -f ${PLUGINDIR}/libfgl_smtp.so test_smtp *.ao test_rep
