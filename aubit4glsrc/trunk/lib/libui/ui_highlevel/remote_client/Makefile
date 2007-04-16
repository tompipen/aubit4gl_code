CFLAGS=-Wall  -g -fPIC -I.. -I$(AUBITDIR)/incl -I$(AUBITDIR)/lib/libaubit4gl -DCONFIGURED_TARGET=\"X\" -DCONFIGURED_TARGET_OS=\"X\"   
CC=gcc


all: libUI_pipeclient.so 

libUI_pipeclient.so:  clnt_main_pipe.o marshall_pipe_client.o ../width_narrow.o ../forms.o ../generic_ui.o ../menu.o ../display_array.o ../formcntrl.o ../input_array.o ../misc.o ../common_hlui.o  pipeclient.o
	gcc -g -fPIC -shared clnt_main_pipe.o marshall_pipe_client.o ../width_narrow.o ../forms.o ../generic_ui.o ../menu.o ../display_array.o ../formcntrl.o ../input_array.o ../misc.o  ../common_hlui.o pipeclient.o -o libUI_pipeclient.so 
	cp libUI_pipeclient.so `aubit-config DEFAULT_PLUGINDIR`
	


marshall_pipe_client.c: API_lowlevel.spec dlrpc_marshall_pipe
	sh dlrpc_marshall_pipe  API_lowlevel.spec  client > marshall_pipe_client.c


marshall_pipe_server.c: API_lowlevel.spec dlrpc_marshall_pipe
	sh dlrpc_marshall_pipe  API_lowlevel.spec  server > marshall_pipe_server.c

clean: 
	rm -f marshall_client.c marshall_server.c *.o  libLL_server.so ui_lowlevel_clnt.c ui_lowlevel_svc.c  ui_lowlevel.h ui_lowlevel.x server_tui  server_gtk 


clnt_main.o clnt_main_pipe.o marshall_pipe_client.o pipeclient.o: ui_lowlevel.h


ui_lowlevel.h: ui_lowlevel.x
	#rpcgen -h ui_lowlevel.x 
	rpcgen ui_lowlevel.x

ui_lowlevel.x : API_lowlevel.spec dlrpc
	sh dlrpc API_lowlevel.spec


clnt_main_pipe.o:  pipeclient.h ui_lowlevel.h
