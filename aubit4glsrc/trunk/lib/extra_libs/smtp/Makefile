ROOT    =../../..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common


all: ${PLUGINDIR}/libfgl_smtp.so test_smtp test_rep

CFLAGS+= -I. -I./src
smtpdir=./libsmtp-0.8

${PLUGINDIR}/libfgl_smtp.so: aubit_smtp.4gl 
	4glpc -g -as-dll `pkg-config --cflags glib-2.0` -I$(smtpdir)/include  aubit_smtp.4gl -o $@   -L$(smtpdir)/lib  -lsmtp -lsmtp_mime `pkg-config --libs glib-2.0`


test_smtp: test_smtp.4gl
	4glpc test_smtp.4gl -o test_smtp
test_rep: test_rep.4gl
	4glpc test_rep.4gl -o test_rep

clean: 
	rm ../../libfgl_smtp.so test_smtp *.ao
