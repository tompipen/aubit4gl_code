#include <stdlib.h>

enum callstates {
	INITIALIZED,
	CALLING,
	CALL_RESULT,
	CALL_RESULT_MALLOC
};


struct client_result {
	char *func;
	long result;
	enum callstates state;
};



struct client_result *client_call(char *func, int expectresult, char *fmt,...);

char *client_decode_str (char *ptr);

int client_connect (char *host, char *p);

int
client_result_ok (struct client_result *result);



void client_get_value (struct client_result *result, char *fmt, void *p);
void client_free_result (struct client_result *result);
int SendFile(char *s) ;


int init_client(void);
void A4GL_LL_out_linemode_internal( char* s);
void A4GL_LL_opening_form_xml( char* a, char* filename, char* b);
void A4GL_LL_use_direct_to_ui( char* t, char* s);
