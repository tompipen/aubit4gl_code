../../../libLOGREP_TXT.so : layout_txt.c
	cc -rdynamic -shared -g $^ -o $@ -I$(AUBITDIR)/lib/libaubit4gl -I$(AUBITDIR)/incl  -laubit4gl `pkg-config --libs --cflags gtk+-2.0`

