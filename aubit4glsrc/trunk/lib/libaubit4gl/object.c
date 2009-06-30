#include "a4gl_libaubit4gl_int.h"

int numObjs=1;
static int initialized=0;

#define MAXOBJECTS 1000

struct sObject heapOfObjects[MAXOBJECTS];

static void init_objects(void) {
	int a;
	if (initialized) return;
	initialized++;
	for (a=0;a<MAXOBJECTS;a++) {
		heapOfObjects[a].objType=NULL;
		heapOfObjects[a].objData=NULL;
	}
// We'll set the value so we dont reused this - as 
// We dont want to use objectID=0;
	heapOfObjects[0].objType="RESERVED";

}

struct sObject *new_object(char *type) {
	int found=-1;
	struct sObject *o;
	int a;
	init_objects();
	for (a=0;a<MAXOBJECTS;a++) {
		if (heapOfObjects[a].objType==NULL) {
			found=a;
			break;
		}
	}

	if (found==-1) {
		A4GL_exitwith("Out of heap");
		return NULL;
	}

	o=&heapOfObjects[found];
	o->objType=type;
	o->objHeapId=numObjs++;
	o->objData=NULL;
	o->refCnt=1;
	return o;
}

int ensureObject(char *type,int objectId, struct sObject **o) {
	init_objects();

	if (objectId==0) return 0;
	if (heapOfObjects[objectId].objType==NULL ) return 0;
	if (strcmp(heapOfObjects[objectId].objType,type)!=0) return 0;
	if (heapOfObjects[objectId].objData==NULL ) return 0;

	*o=&heapOfObjects[objectId];
	return 1;
}


static void A4GL_call_object_destructor(int objectID) 
{
  int (*ptr) (int *);
  char buff[256];
  struct sObject *obj;
  if (objectID<=0) {
	return;
  }

  obj=&heapOfObjects[objectID];
  if (heapOfObjects[objectID].objType==NULL) return ;
  if (heapOfObjects[objectID].objData==NULL) return ;

  SPRINTF1 (buff, ":%s.~", A4GL_null_as_null (obj->objType));

  ptr = A4GL_get_datatype_function_i (DTYPE_OBJECT, buff);

  if (ptr == 0)
    {
      return ;
    }

  ptr (&objectID);

}

void A4GL_object_displose(int objectId) {
	
	if (heapOfObjects[objectId].objType!=NULL) {

		heapOfObjects[objectId].refCnt--;
		// Is it still in use ? 
		if ( heapOfObjects[objectId].refCnt) return;


		A4GL_call_object_destructor(objectId);
		heapOfObjects[objectId].objType=NULL;
		if (  heapOfObjects[objectId].objData) {
			free(heapOfObjects[objectId].objData);
			heapOfObjects[objectId].objData=NULL;
		}
		heapOfObjects[objectId].objHeapId=0;
	}
}
