#include "ui_lowlevel.h"

CLIENT *UI_clnt=0;


int init_client(void) {
	char *host="localhost";
	UI_clnt = clnt_create (host, FGL_RPC, FGL_RPC_VER, "udp");
	if (UI_clnt == NULL) {
		clnt_pcreateerror (host);
		return 0;
	}
	return 1;
}

CLIENT *get_UI_clnt(void) {
	if (UI_clnt==0)  {
		init_client();
		if (UI_clnt==0) {
			printf("Aborting...\n");
			exit(0);
		}
	}
	return UI_clnt;
}


chk_result(void *x) {
	if (x==0) {
		printf("Unexpected return code from RPC call\n");
		exit(0);
	}
}
