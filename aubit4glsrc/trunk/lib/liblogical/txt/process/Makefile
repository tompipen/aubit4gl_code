CFLAGS=-g

../../../libLOGREPPROC_TXT.so : process_txt.c
	cc -rdynamic -shared -g $^ -o $@ -I$(AUBITDIR)/lib/libaubit4gl -I$(AUBITDIR)/incl  -laubit4gl 

