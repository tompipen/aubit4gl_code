CFLAGS=-g -fPIC -I.. -I$(AUBITDIR)/incl


all: ../../../libUI_client.so server_tui server_gtk

../../../libUI_client.so:  ui_lowlevel_xdr.o ui_lowlevel_clnt.o clnt_main.o marshall_client.o
	gcc -g -fPIC -shared ui_lowlevel_xdr.o ui_lowlevel_clnt.o clnt_main.o marshall_client.o ../width_narrow.o ../forms.o ../generic_ui.o ../menu.o ../display_array.o ../formcntrl.o ../input_array.o ../misc.o  -o ../../../libUI_client.so


libLL_server.so:  ui_lowlevel_xdr.o ui_lowlevel_svc.o  marshall_server.o
	gcc -g -shared ui_lowlevel_xdr.o ui_lowlevel_svc.o  marshall_server.o -o libLL_server.so

server_tui: libLL_server.so
	gcc -g ../common_hlui.o ../lowlevel_tui.o ../width_narrow.o -lncurses -lform -lpanel -L. -lLL_server -o server_tui -L$(AUBIDTIR)/lib -laubit4gl

server_gtk: libLL_server.so
	gcc -g ../common_hlui.o ../lowlevel_gtk.o ../menu_gtk.o ../widget_gtk.o ../width_narrow.o -lncurses -lform -lpanel -L. -lLL_server -o server_gtk -L$(AUBIDTIR)/lib -laubit4gl -lgtk-x11-2.0 -lgdk-x11-2.0 -latk-1.0 -lgdk_pixbuf-2.0 -lm -lpangoxft-1.0 -lpangox-1.0 -lpango-1.0 -lgobject-2.0 -lgmodule-2.0 -ldl -lglib-2.0    -Wl,--export-dynamic -L/opt/gnome/lib  -lgtk-x11-2.0 -lgdk-x11-2.0 -latk-1.0 -lgdk_pixbuf-2.0 -lm -lpangoxft-1.0 -lpangox-1.0 -lpango-1.0 -lgobject-2.0 -lgmodule-2.0 -ldl -lglib-2.0

ui_lowlevel.x : API_lowlevel.spec dlrpc
	dlrpc API_lowlevel.spec 

ui_lowlevel.h: ui_lowlevel.c
	rpcgen -h ui_lowlevel.x


ui_lowlevel_clnt.c: ui_lowlevel.x
	rpcgen ui_lowlevel.x

ui_lowlevel_svc.c: ui_lowlevel.x
	rpcgen ui_lowlevel.x

ui_lowlevel_xdr.c: ui_lowlevel.x
	rpcgen ui_lowlevel.x


marshall_client.c: API_lowlevel.spec dlrpc_marshall
	sh dlrpc_marshall  API_lowlevel.spec  client > marshall_client.c

marshall_server.c: API_lowlevel.spec dlrpc_marshall
	sh dlrpc_marshall  API_lowlevel.spec  server > marshall_server.c


clean: 
	rm marshall_client.c marshall_server.c *.o  libLL_server.so ui_lowlevel_clnt.c ui_lowlevel_svc.c ui_lowlevel_xdr.c ui_lowlevel.h ui_lowlevel.x server_tui  server_gtk
