all: libUI_HLGENERIC.so testit libUI_HL_TUI.so libUI_HL_GTK.so

GTK_INC_PATH    =-I/usr/local/include/gtk-2.0 -I/usr/local/lib/gtk-2.0/include -I/usr/local/include/atk-1.0 -I/usr/local/include/pango-1.0 -I/usr/X11R6/include -I/usr/local/include/glib-2.0 -I/usr/local/lib/glib-2.0/include
GTK_LIB_PATH    =-L/usr/local/lib
GTKLIBS                 =-lgtk-x11-2.0 -lgdk-x11-2.0 -latk-1.0 -lgdk_pixbuf-2.0 -lm -lpangox-1.0 -lpango-1.0 -lgobject-2.0 -lgmodule-2.0 -ldl -lglib-2.0

CFLAGS+=-I/home/aubit4gl/sourceforge/aubit4glsrc/incl -I.. -g -I../../libaubit4gl



API_lowlevel.c: ../../libaubit4gl/API_lowlevel.spec API_lowlevel.h
	(cd ../../libaubit4gl && ../bin/dlmagic ./API_lowlevel.spec > ../libui/ui_highlevel/API_lowlevel.c)


API_lowlevel.h: ../../libaubit4gl/API_lowlevel.spec
	(cd ../../libaubit4gl && ../bin/dlmagic ./API_lowlevel.spec -h > ../libui/ui_highlevel/API_lowlevel.h)

OBJS= forms.o generic_ui.o menu.o display_array.o formcntrl.o input_array.o misc.o 

libUI_HLGENERIC.so: $(OBJS) API_lowlevel.o
	gcc -rdynamic -shared $(OBJS) API_lowlevel.o -o libUI_HLGENERIC.so -laubit4gl 
	cp *.so ../..

lowlevel_tui.o: lowlevel/lowlevel_tui.c
	gcc -c -I$(AUBITDIR)/incl -I. -Ilowlevel lowlevel/lowlevel_tui.c  -o lowlevel_tui.o


	
libUI_HL_TUI.so: $(OBJS) lowlevel_tui.o
	gcc -rdynamic -shared $(OBJS) lowlevel_tui.o -o libUI_HL_TUI.so -laubit4gl -lform -lpanel -lcurses
	cp *.so ../..



lowlevel_gtk.o: lowlevel/lowlevel_gtk.c
	gcc -g -c -I$(AUBITDIR)/incl -I. -Ilowlevel lowlevel/lowlevel_gtk.c  -o lowlevel_gtk.o $(GTK_INC_PATH) 



widget_gtk.o: lowlevel/widget_gtk.c
	gcc -g -c -I$(AUBITDIR)/incl -I. -Ilowlevel lowlevel/widget_gtk.c  -o widget_gtk.o $(GTK_INC_PATH) 



libUI_HL_GTK.so: $(OBJS) lowlevel_gtk.o widget_gtk.o
	gcc -rdynamic -shared $(OBJS) lowlevel_gtk.o widget_gtk.o  -o libUI_HL_GTK.so -laubit4gl $(GTK_INC_PATH) $(GTK_LIB_PATH) $(GTKLIBS)
	cp *.so ../..


testit:  $(OBJS)
	gcc testit.c $(OBJS) API_lowlevel.o -o testit -laubit4gl -lform -lpanel -lcurses

