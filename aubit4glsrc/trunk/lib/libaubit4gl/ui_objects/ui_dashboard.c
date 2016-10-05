#include "a4gl_libaubit4gl_int.h"
struct _data {
	char data[256];
};
 
static int new_obj(char *newData) {
struct sObject *obj;
struct _data *data;
obj=new_object("ui.dashboard");
if (obj==NULL) {
        A4GL_push_objectID(0);
        return 1;
}
data=malloc(sizeof(struct _data));
strcpy(data->data,newData);
obj->objData=data;
A4GL_push_objectID(obj->objHeapId);
return 1;
 
}
 
 
 
 
static int ui_dashboard_additem(long *objectID_IgnoredAsAlways0,int n) {
int okToProcess=1;
int _ni=4;
struct BINDING _ibind[4]={
    {NULL,0,0,0,0,0,NULL},
    {NULL,0,0,0,0,0,NULL},
    {NULL,0,0,0,0,0,NULL},
    {NULL,0,0,0,0,0,NULL},
};
int _no=1;
struct BINDING _obind[1]={
    {NULL,0,0,0,0,0,NULL},
};
int rval_0;
char rval_1[512];
char *param1=NULL;
char *param2=NULL;
char *param3=NULL;
char *param4=NULL;
 
/* END OF DEFINE SECTION */
 
 
  if (n!=4) { 
    A4GL_pop_args(n);
    okToProcess=0;
  }
 
  // Set up input binding for our parameters
  if (okToProcess) {
 
    param4=A4GL_char_pop();
    _ibind[3].ptr=param4;
    _ibind[3].size=strlen(param4);

    param3=A4GL_char_pop();
    _ibind[2].ptr=param3;
    _ibind[2].size=strlen(param3);
 
    param2=A4GL_char_pop();
    _ibind[1].ptr=param2;
    _ibind[1].size=strlen(param2);
    param1=A4GL_char_pop();
    _ibind[0].ptr=param1;
    _ibind[0].size=strlen(param1);
  }
 
  // Set up output binding for our parameters
  if (okToProcess) {
    _obind[0].ptr=&rval_0;
    _obind[0].size=4;
    _obind[0].dtype=DTYPE_INT;
  }
 
  if (okToProcess) {
      A4GL_ui_frontcall("INTERNAL","ui.dashboard.additem",_ibind,_ni,_obind,_no );
  }
 
 
  // Set up output binding for our parameters
    if (param1 ) {
        free(param1);
    }
    if (param2 ) {
        free(param2);
    }
    if (param3 ) {
        free(param3);
    }
    if (param4 ) {
        free(param4);
    }

if (!okToProcess) {
    A4GL_push_null(DTYPE_INT,0);
  } else {
    A4GL_push_int(rval_0);
  }
  return 1;
}

static int ui_dashboard_getabonnements(long *objectID_IgnoredAsAlways0,int n) {
char rval_1[512];
int okToProcess=1;
int _no=1;
struct BINDING _obind[1]={
    {NULL,0,0,0,0,0,NULL}
};

/* END OF DEFINE SECTION */


if (n!=0) {
    A4GL_pop_args(n);
    okToProcess=0;
}

if (okToProcess) {
    _obind[0].ptr=&rval_1;
    _obind[0].size=255;
}

if (okToProcess) {
    A4GL_ui_frontcall("INTERNAL","ui.dashboard.getabonnements",NULL,0,_obind,_no );
}

if (!okToProcess) {
    A4GL_push_null(DTYPE_CHAR,1);
} else {
    A4GL_push_char(rval_1);
}
return 1;
}

void add_ui_dashboard_support(void) {
        A4GL_add_object_type("ui.dashboard");
        A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.dashboard.additem", (void *)  ui_dashboard_additem);
        A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.dashboard.getabonnements", (void *)  ui_dashboard_getabonnements);
}

