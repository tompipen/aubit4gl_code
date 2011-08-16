
#include "a4gl_libaubit4gl_int.h"



int A4GL_destroy_object(char *type, long objectID) {
//struct sObject *objPtr;
char buff[2000];
int (*ptr) (int);
//Calls the default destructor to free any previously allocated memory..
sprintf(buff,":%s.-",type);
ptr=A4GL_get_datatype_function_i(DTYPE_OBJECT, buff);
if (ptr) { return ptr(objectID); }
return 0;
}

int A4GL_create_object(char *type, int nparam) {
char buff[2000];
struct {
	long objectID;
} m;
// The construct takes the standard *objId and nparam
// but - as its a constructor - we'll never pass in a real objID..
// it will always be NULL....
int (*ptr) (long *objectID,int nparam);

//Calls the default destructor to free any previously allocated memory..
sprintf(buff,":%s.new",type);
ptr=A4GL_get_datatype_function_i(DTYPE_OBJECT, buff);
if (ptr) { 
	int x;
	x=ptr(&m.objectID,nparam);
	if (x) {
		A4GL_pop_object(type,&m,99,0,0);
		return m.objectID;
	} else {
		return 0;
	}
}
return 0;

}
