all: rpc_server rpc_client

rpc_server: rpc_server.4gl
	${FGLC} rpc_server.4gl -o rpc_server

rpc_client: rpc_client.4gl
	${FGLC} rpc_client.4gl -o rpc_client

run: all
	./run_test
	
clean:
	rm -f rpc_client rpc_server

ansi_sql_compat:
	@echo "1"

desc:
	@echo "ONC RPC client/server test"
	
################################
# When test needs a non-standard Aubit plug-in (the one that depends on
# local system's depenency, so it may not be always available) list it here.
# specify only the signigicant part of plug-in name, omminting 'lib' prefix
# and library extension (eg. for libRPC_XDR.so use only "RPC_XDR".
need_plugin:
	@echo "RPC_XDR"

sql_features_used:		; @echo "DATABASE_USED DROP_TABLE CREATE_TABLE ANSI_DELETE ANSI_INSERT DEFINE_LIKE VALIDATE_LIKE STATUS IF EXIT_PROGRAM_EXPR "

