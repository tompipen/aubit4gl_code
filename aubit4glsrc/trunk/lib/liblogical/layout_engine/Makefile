CFLAGS+=-g `pkg-config --cflags gtk+-2.0`  -I$(AUBITDIR)/lib/libaubit4gl -I$(AUBITDIR)/incl

layout_engine: layout_engine.o ../common/a4gl_lle.o ../report_viewer/report_viewer.o API_layout.o file_hand.o API_layout.h
	cc -rdynamic -g layout_engine.o ../common/a4gl_lle.o ../report_viewer/report_viewer.o API_layout.o file_hand.o -o layout_engine  `pkg-config --libs gtk+-2.0` -laubit4gl

API_layout.c: API_layout.spec
	../../bin/dlmagic API_layout.spec > API_layout.c

API_layout.h: API_layout.spec
	../../bin/dlmagic API_layout.spec -h > API_layout.h

