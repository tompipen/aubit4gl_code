#include "a4gl_libaubit4gl.h"
#include "ui_lowlevel.h"
#include "pipeclient.h"

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
  if (A4GL_isyes (acl_getenv ("LOCALLINEOUTPUT"))) {
	} else {
	 client_call("A4GL_LL_switch_to_line_mode", 1,"");
	}
}


int A4GL_LL_getch_swin( void* window_ptr,char *why) {
	ret_A4GL_LL_getch_swin ret;
	struct client_result *resultP;
	init_client();
	resultP = (struct client_result *)client_call("A4GL_LL_getch_swin", 1,"is",(long)window_ptr,why);
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



void A4GL_LL_out_linemode (char *s)
{
  if (A4GL_isyes (acl_getenv ("LOCALLINEOUTPUT")))
    {
      printf ("%s\n", s);
    }
  else
    {
      A4GL_LL_out_linemode_internal (s);
    }
}


void A4GL_LL_opening_form(char *formfile, char *formname) {
	FILE *f;
	char *fbuff;
	char buff[2000];
	strcpy(buff,formfile);
	A4GL_trim(buff);
	strcat(buff,".xml");
	f=A4GL_open_file_dbpath(buff);
	if (f) {
		long l;
		fseek(f,0,SEEK_END);
		l=ftell(f);
		rewind(f);
		fbuff=malloc(l+1);
		fread(fbuff,l,1,f);
		fbuff[l]=0;
		fclose(f);
		printf("\n\n\n******************************fbuff='%s'\n",fbuff);
		A4GL_LL_opening_form_xml(formname,formfile,  fbuff);
		free(fbuff);
	
	}
}


void A4GL_LL_direct_to_ui(char* t,char* s) {
	init_client();
	if (strcmp(t,"SEND")==0) {
		A4GL_LL_use_direct_to_ui(t, s);
		return;
	}
	if (strcmp(t,"FILE")==0) {
		SendFile(s);
		return;
	}

	if (strcmp(t,"dialog_setkeylabel")==0) {
		int a;
		int params;
		char *p1;
		char *p2;
		p2=A4GL_char_pop();
		p1=A4GL_char_pop();
		A4GL_LL_dialog_setkeylabel(p1,p2);
		free(p1);
		free(p2);
		return;
	}
	if (strcmp(t,"setkeylabel")==0) {
		int a;
		int params;
		char *p1;
		char *p2;
		p2=A4GL_char_pop();
		p1=A4GL_char_pop();
		A4GL_LL_setkeylabel(p1,p2);
		free(p1);
		free(p2);
		return;
	}

	printf("unhandled direct to ui call\n");
}


void ActivateToolbar(char *cmd, struct aclfgl_event_list *list)  {
// does nothing but required by the API
}


void A4GL_LL_init_form(void *f) {

// does nothing but required by the API
}
