CFLAGS=-Wall -g -fPIC -I.. -I$(AUBITDIR)/incl -I$(AUBITDIR)/lib/libui -I$(AUBITDIR)/lib/libaubit4gl -DCONFIGURED_TARGET=\"X\" -DCONFIGURED_TARGET_OS=\"X\"  
CC=gcc


all: ../../../../plugins-`aubit-config A4GL_VERSION_STRING`/libUI_client.so  server_tui server_gtk


../../../../plugins-`aubit-config A4GL_VERSION_STRING`/libUI_client.so:  ui_lowlevel_xdr.o ui_lowlevel_clnt.o clnt_main.o marshall_client.o ../width_narrow.o ../forms.o ../generic_ui.o ../menu.o ../display_array.o ../formcntrl.o ../input_array.o ../misc.o ../common_hlui.o 
	gcc -g -fPIC -shared ui_lowlevel_xdr.o ui_lowlevel_clnt.o clnt_main.o marshall_client.o ../width_narrow.o ../forms.o ../generic_ui.o ../menu.o ../display_array.o ../formcntrl.o ../input_array.o ../misc.o  ../common_hlui.o -o ../../../../plugins-`aubit-config A4GL_VERSION_STRING`/libUI_client.so


libUI_xmlclient.so:  clnt_main_xml.o marshall_xml_client.o ../width_narrow.o ../forms.o ../generic_ui.o ../menu.o ../display_array.o ../formcntrl.o ../input_array.o ../misc.o ../common_hlui.o 
	gcc -g -fPIC -shared ui_lowlevel_xdr.o clnt_main_xml.o marshall_xml_client.o ../width_narrow.o ../forms.o ../generic_ui.o ../menu.o ../display_array.o ../formcntrl.o ../input_array.o ../misc.o  ../common_hlui.o -o ../../../libUI_xmlclient.so


libLL_server.so:  ui_lowlevel_xdr.o ui_lowlevel_svc.o  marshall_server.o
	gcc -g -shared ui_lowlevel_xdr.o ui_lowlevel_svc.o  marshall_server.o -o libLL_server.so

server_tui: libLL_server.so  ../lowlevel_tui.o ../width_narrow.o common.o ../../../resource/resource.o
	gcc -g ../common_hlui.o ../lowlevel_tui.o ../width_narrow.o -lncurses -lform -lpanel -L. -lLL_server -o server_tui -L$(AUBIDTIR)/lib  common.o ../../../resource/resource.o

#-l${AUBITLIBFULL}

server_gtk: libLL_server.so ../common_hlui.o ../lowlevel_gtk.o ../menu_gtk.o ../widget_gtk.o ../width_narrow.o
	gcc -g ../common_hlui.o ../lowlevel_gtk.o ../menu_gtk.o ../widget_gtk.o ../width_narrow.o -L. -lLL_server -o server_gtk -L$(AUBITDIR)/lib -l${AUBITLIBFULL} -lgtk-x11-2.0 -lgdk-x11-2.0 -latk-1.0 -lgdk_pixbuf-2.0 -lm -lpangoxft-1.0 -lpangox-1.0 -lpango-1.0 -lgobject-2.0 -lgmodule-2.0 -ldl -lglib-2.0    -Wl,--export-dynamic -L/opt/gnome/lib  -lgtk-x11-2.0 -lgdk-x11-2.0 -latk-1.0 -lgdk_pixbuf-2.0 -lm -lpangoxft-1.0 -lpangox-1.0 -lpango-1.0 -lgobject-2.0 -lgmodule-2.0 -ldl -lglib-2.0

ui_lowlevel.x : API_lowlevel.spec dlrpc
	sh dlrpc API_lowlevel.spec 

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

marshall_xml_client.c: API_lowlevel.spec dlrpc_marshall_xml
	sh dlrpc_marshall_xml  API_lowlevel.spec  client > marshall_xml_client.c

marshall_server.c: API_lowlevel.spec dlrpc_marshall
	sh dlrpc_marshall  API_lowlevel.spec  server > marshall_server.c

marshall_xml_server.c: API_lowlevel.spec dlrpc_marshall_xml
	sh dlrpc_marshall_xml  API_lowlevel.spec  server > marshall_xml_server.c

clean: 
	rm marshall_client.c marshall_server.c *.o  libLL_server.so ui_lowlevel_clnt.c ui_lowlevel_svc.c ui_lowlevel_xdr.c ui_lowlevel.h ui_lowlevel.x server_tui  server_gtk 
