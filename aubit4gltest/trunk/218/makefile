all: rpc_server rpc_client

rpc_server: rpc_server.4gl
	4glpc rpc_server.4gl -o rpc_server

rpc_client: rpc_client.4gl
	4glpc rpc_client.4gl -o rpc_client

run: all
	./run_test
	
clean:
	rm -f rpc_client rpc_server
