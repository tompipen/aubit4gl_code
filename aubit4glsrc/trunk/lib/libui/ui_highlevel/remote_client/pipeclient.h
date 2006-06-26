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
