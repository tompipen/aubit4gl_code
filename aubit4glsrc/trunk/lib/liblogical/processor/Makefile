
CFLAGS+=-Wall -g -I$(AUBITDIR)/lib/libaubit4gl -I$(AUBITDIR)/incl

process_report:  process_report.o ../common/a4gl_lle.o API_process.o API_process.h
	cc -rdynamic -g process_report.o ../common/a4gl_lle.o API_process.o -o process_report  -laubit4gl

API_process.c: API_process.spec
	../../bin/dlmagic API_process.spec > API_process.c

API_process.h: API_process.spec
	../../bin/dlmagic API_process.spec -h > API_process.h



