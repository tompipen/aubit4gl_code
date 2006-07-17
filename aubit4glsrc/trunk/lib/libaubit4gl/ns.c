#include "a4gl_libaubit4gl.h"

long a4gl_htonl(long x) { return htonl(x); }
long a4gl_ntohl(long x) { return ntohl(x); }


short a4gl_htons(long x) { return htons(x); }
short a4gl_ntohs(long x) { return ntohs(x); }

long win_htonl(long x) { 
	A4GL_assertion(1,"Not implemented");
}

long win_ntohl(long x) { 
	A4GL_assertion(1,"Not implemented");
}

short win_htons(short x) { 
char buff[2];
char buff2[2];
memcpy(buff,&x,2);
buff2[0]=buff[1];
buff2[1]=buff[0];
memcpy(&x,buff2,2);
return x; 
}


short win_ntohs(short x) { 
char buff[2];
char buff2[2];
memcpy(buff,&x,2);
buff2[0]=buff[1];
buff2[1]=buff[0];
memcpy(&x,buff2,2);
	return (x); 
}

