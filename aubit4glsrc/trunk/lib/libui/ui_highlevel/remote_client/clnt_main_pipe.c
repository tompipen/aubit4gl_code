#include "a4gl_libaubit4gl.h"
#include "ui_lowlevel.h"

char url[256] = "";

static int inited=0;

/* Initialize our error-handling environment. */

int init_client(void) {
	int ok;
	if (!inited) {
		char *ptr;
		inited=1;
		printf("Init client\n");
		ptr=acl_getenv_not_set_as_0("AFGLSERVER");
		if (ptr) {
			strcpy(url,ptr);
		ok=client_connect(ptr,"1300");
		}   else {
			printf("No server specified - please set AFGLSERVER\n");
			ok=0;
		}

		if (ok==0) {
			A4GL_fgl_die_with_msg(45,"Cannot connect");
			exit(1);
		}
		return ok;
	}
	return 1;
}


char *get_UI_url(void) {
	if (!inited)  {
		if (!init_client()) {
			printf("Aborting...\n");
			exit(0);
		}
	}
	printf("Returning %s\n",url);
	return url;
}

int A4GL_LL_decode_aubit_attr(int a) {
	return a;
}

int A4GL_LL_colour_code(int a) {
		return a;
}


void A4GL_LL_switch_to_line_mode(void) {
	 client_call("A4GL_LL_switch_to_line_mode", "");
	//if (client_result_ok(resultP)) { client_free_result(resultP); return; /* no return value */ }
}


int A4GL_LL_getch_swin( void* window_ptr,char *why) {
	ret_23 ret;
	init_client();
	struct client_result *resultP;
	resultP = (struct client_result *)client_call("A4GL_LL_getch_swin", "is",(long)window_ptr,why);
	if (client_result_ok(resultP)) {

		   client_get_value( resultP, "i", &ret);

		   if (ret==A4GLKEY_ACCEPT) {
			   return std_dbscr.acckey;
		   }

		   if (ret==A4GLKEY_INTERRUPT) {
#if (defined(WIN32) && ! defined(__CYGWIN__))
			     set_intr_win32 (SIGINT);
#else
			     kill (0, SIGINT);
#endif
		   }
		   return ret;
	        client_free_result(resultP);
	}
	return 0;
}

