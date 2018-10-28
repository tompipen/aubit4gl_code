#include "a4gl_libaubit4gl_int.h"

int numObjs=1;
static int initialized=0;

#define MAXOBJECTS 1000

char **objectNames=0;
int nObjectNames=0;

struct sObject heapOfObjects[MAXOBJECTS];
static int find_head_slot_forobject_id(long objectId) ;

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

int find_head_slot_forobject_id(long objectId) {
int a;
        for (a=0;a<MAXOBJECTS;a++) {
                if (heapOfObjects[a].objHeapId==objectId) {
			return a;
		}
	}
return 0;
}



static void  dump_objects(void) {
	int a;


	printf("Current objects\n");
	printf("---------------\n");
	for (a=0;a<MAXOBJECTS;a++) {
		if (heapOfObjects[a].objType && heapOfObjects[a].objHeapId) {
			printf("%d ObjectId=%d Type=%s - reference count=%d\n", a, heapOfObjects[a].objHeapId, heapOfObjects[a].objType, heapOfObjects[a].refCnt);
			if (strcmp(heapOfObjects[a].objType,"STRING")==0) {
				if (heapOfObjects[a].objData) {
					printf("    %s\n", (char *)heapOfObjects[a].objData);
				}
			}
		}
	}
	printf("\n");
}



int aclfgl_aclfgl_dump_objects(int n) {
	dump_objects();

return 0;
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



	if (A4GL_isyes(acl_getenv("DUMPOBJECT"))) {
	dump_objects();
	}


	//printf("found = %d\n",found);
	return o;
}

int getObject(long objectId, struct sObject **o, char *preferredObjectType) {
long objectSlotId;
	init_objects();

	if (objectId==0) return 0;
	if (A4GL_isyes(acl_getenv("DUMPOBJECT"))) {
		dump_objects();
	}

	objectSlotId=find_head_slot_forobject_id(objectId);
	if (objectSlotId==0) {
		// Object Not found...
		A4GL_assertion(1,"Object not found");
		return 0;
	}
	if (heapOfObjects[objectSlotId].objType==NULL ) return 0;

	//printf("objectSlotId=%ld for ObjectId=%ld\n",objectSlotId, objectId);
	*o=&heapOfObjects[objectSlotId];


	if (preferredObjectType &&  (*o)->objType) {
		if (strcmp(preferredObjectType, (*o)->objType)==0) {
			return 1;
		} else {
			char buff[3000];
			int a;
			// Should search down the parentage to find this clsss...
			SPRINTF1(buff,"%s.castTo", (*o)->objType);
			
			A4GL_push_char(preferredObjectType);
			a=A4GL_call_datatype_function_i(&objectId,99,buff,1);

			if (a==0) {
				// Cant be cast..
				//a4gl_yyerror("Unable to cast to the requested object type");
				return 0;
			} else {
				int b;
				b=find_head_slot_forobject_id(a);
				if (b>0) {
					*o=&heapOfObjects[b];
					return 1;
				} else {
				return 0;
				}
			}
			
		}
		return 0;
	}
	return 1;
}

int ensureObject(char *type,long objectId, struct sObject **o) {
long objectSlotId;
	init_objects();

	objectSlotId=find_head_slot_forobject_id(objectId);

	if (objectId==0) return 0;
	if (heapOfObjects[objectSlotId].objType==NULL ) return 0;
	if (type) {
		if (strcmp(heapOfObjects[objectSlotId].objType,type)!=0) return 0;
	}
	if (heapOfObjects[objectSlotId].objData==NULL ) return 0;

	*o=&heapOfObjects[objectSlotId];
	return 1;
}


static void A4GL_call_object_destructor(long objectID) 
{
  int (*ptr) (long *,int nparam);
  char buff[256];
  struct sObject *obj;
long objectSlotId;
  if (objectID<=0) {
	return;
  }

	objectSlotId=find_head_slot_forobject_id(objectID);

  obj=&heapOfObjects[objectSlotId];
  if (heapOfObjects[objectSlotId].objType==NULL) return ;
  if (heapOfObjects[objectSlotId].objData==NULL) return ;

  SPRINTF1 (buff, ":%s.~", A4GL_null_as_null (obj->objType));

  ptr = A4GL_get_datatype_function_i (DTYPE_OBJECT, buff);

  if (ptr == 0)
    {
      return ;
    }

  ptr (&objectID,0);

}

/*
void A4GL_object_increfcnt(long objectId) {
int slot;
	slot=find_head_slot_forobject_id(objectId);
	if (heapOfObjects[slot].objType!=NULL) {
		if (A4GL_isyes(acl_getenv("DUMPOBJECT"))) {
			printf("increment refCnt\n");
		}
		heapOfObjects[slot].refCnt++;
	}
}
*/


void freeOrphanObjects() {
int a;

//printf("CHecking for freeOrphanObjects\n");
//
	for (a=0;a<MAXOBJECTS;a++) {
		if (heapOfObjects[a].objType && heapOfObjects[a].objHeapId) {
			//if (!A4GLSTK_chkObjectExists(heapOfObjects[a].objHeapId)) {
			
			if (!A4GLSTK_chkObjectExists(heapOfObjects[a].objHeapId) && heapOfObjects[a].refCnt==0) {
				A4GL_debug("Object ID %d is no longer referenced...\n", heapOfObjects[a].objHeapId);
					//A4GL_pause_execution();
				heapOfObjects[a].refCnt=0;
				A4GL_object_dispose(heapOfObjects[a].objHeapId);
			}
		}
	}
}

void A4GL_object_dispose(long objectId) {
	int slot;
	slot=find_head_slot_forobject_id(objectId);
	if (heapOfObjects[slot].objType!=NULL) {
		if (A4GL_isyes(acl_getenv("DUMPOBJECT"))) {
			printf("object dispose ? %d\n", heapOfObjects[slot].refCnt);
		}
		heapOfObjects[slot].refCnt--;
		
		// Is it still in use ? 
		if ( heapOfObjects[slot].refCnt>0) return;
		if (A4GL_isyes(acl_getenv("DUMPOBJECT"))) {
			printf("Yes..\n");
		}

		//if (objectId==2) {
			//A4GL_pause_execution();
		//}
		//printf("---> dispose objectID %ld\n", objectId);
		//sleep(3);

		A4GL_call_object_destructor(objectId);
		heapOfObjects[slot].objType=NULL;
		if (  heapOfObjects[slot].objData) {
			if (heapOfObjects[slot].objData) {
				free(heapOfObjects[slot].objData);
			}
			heapOfObjects[slot].objData=NULL;
		}
		heapOfObjects[slot].objHeapId=0;
		heapOfObjects[slot].objType=NULL;
	}
}

int A4GL_ObjectTypeExists(char *s) {
int a;
	if (objectNames==0) return 0;
	for (a=0;a<nObjectNames;a++) {
		if (strcmp(s, objectNames[a])==0) {
			return 1;
		}
	}
	return 0;
}

void A4GL_add_object_type(char *s) {
	// has it already been added ? 
	if (A4GL_ObjectTypeExists(s)) return;

	nObjectNames++;
	objectNames=realloc(objectNames, nObjectNames*sizeof(objectNames[0]));
	objectNames[nObjectNames-1]=strdup(s);
}

char *getSigForTopOfStack(int numberOfObjectsOnStack) {
int a;
static char buff[3000]="";
int d1;
int s1;
long *p;
	
strcpy(buff,"");

for (a=0;a<numberOfObjectsOnStack;a++) {
	p=0;
	A4GL_get_top_of_stack (a+1 , &d1, &s1, (void *) &p);
        if ((d1&DTYPE_MASK)==DTYPE_OBJECT) {
		long objId;
		objId=*p;
                struct sObject *o;
                if (getObject(objId,&o, NULL)) {
			strcat(buff,"P");
			strcat(buff,getDatatypeSig(d1,s1,o->objType));
		} else {
			strcat(buff,"PO");
			strcat(buff,getDatatypeSig(d1,s1,NULL));
		}
	} else {
		strcat(buff,"P");
		strcat(buff,getDatatypeSig(d1,s1,NULL));
	}
}
return buff;
}


char *getDatatypeSig(int dtype,int size,char *objectType) {
	switch (dtype & DTYPE_MASK) {
		case DTYPE_INT: 
		case DTYPE_SMINT: 
		case DTYPE_FLOAT: 
		case DTYPE_DECIMAL: 
		case DTYPE_INT8:
		case DTYPE_MONEY:
		case DTYPE_SERIAL:
		case DTYPE_SERIAL8:
		case DTYPE_SMFLOAT: return "N";

		case DTYPE_DATE: return "D";
		case DTYPE_DTIME: return "T";
		case DTYPE_INTERVAL: return "I";
		
		case DTYPE_BYTE  :
		case DTYPE_TEXT  :  return "B";
		
		case DTYPE_STRING   :
		case DTYPE_VCHAR  :
		case DTYPE_LVARCHAR  :
		case DTYPE_NCHAR  :
		case DTYPE_NVCHAR :
		case DTYPE_CHAR  : return "S";
		
		case DTYPE_OBJECT  : 
			if (objectType) {
				return objectType;
			} else {
				return "O";
			}
	}
return "O";
}
