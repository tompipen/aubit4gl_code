#include "a4gl_libaubit4gl_int.h"
struct _data {
	char data[256];
};
 
static int new_obj(char *newData) {
struct sObject *obj;
struct _data *data;
obj=new_object("ui.gantt");
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
 
 
 
 
static int ui_gantt_create(long *objectID_IgnoredAsAlways0,int n) {
int okToProcess=1;
int _no=1;
struct BINDING _obind[1]={
    {NULL,0,0,0,0,0,NULL}
};
char data[256];
 
/* END OF DEFINE SECTION */
 
 
  if (n!=0) { 
    A4GL_pop_args(n);
    okToProcess=0;
  }
 
 
  // Set up output binding for our parameters
  if (okToProcess) {
    _obind[0].ptr=&data;
    _obind[0].size=255;
  }
 
  if (okToProcess) {
      A4GL_ui_frontcall("INTERNAL","ui.gantt.create",NULL,0,_obind,_no );
  }
 
  if (!okToProcess) {
    A4GL_push_objectID(0);
  } else {
    if (strlen(data)) {
        A4GL_trim(data);
        return new_obj(data);
    } else {
        A4GL_push_objectID(0);
    }
  }
  return 1;
}
 
 
 
 
static int ui_gantt_readcsv(long *objectID,int n) {
int okToProcess=1;
struct _data *data;
struct sObject *ptr;
int _ni=2;
struct BINDING _ibind[2]={
    {NULL,0,0,0,0,0,NULL},
    {NULL,0,0,0,0,0,NULL}
};
int _no=1;
struct BINDING _obind[1]={
    {NULL,0,0,0,0,0,NULL}
};
int rval_0;
char *filename=NULL;
 
/* END OF DEFINE SECTION */
 
  if (!ensureObject("ui.gantt",*objectID,&ptr)) {
     A4GL_exitwith("Not an object of type (ui.gantt) or not initialized");
     return 0;
  }
  data=ptr->objData;
 
  if (n!=1) { 
    A4GL_pop_args(n);
    okToProcess=0;
  }
 
  // Set up input binding for our parameters
  if (okToProcess) {
 
    filename=A4GL_char_pop();
    _ibind[1].ptr=filename;
    _ibind[1].size=strlen(filename);
    _ibind[0].ptr=data->data;
    _ibind[0].size=strlen(data->data);
  }
 
  // Set up output binding for our parameters
  if (okToProcess) {
    _obind[0].ptr=&rval_0;
    _obind[0].size=4;
    _obind[0].dtype=DTYPE_INT;
  }
 
  if (okToProcess) {
      A4GL_ui_frontcall("INTERNAL","ui.gantt.readcsv",_ibind,_ni,_obind,_no );
  }
 
 
  // Set up output binding for our parameters
    if (filename ) {
        free(filename);
    }
  if (!okToProcess) {
    A4GL_push_null(DTYPE_INT,0);
  } else {
    A4GL_push_int(rval_0);
  }
  return 1;
}
 
 
 
 
static int ui_gantt_settitle(long *objectID,int n) {
int okToProcess=1;
struct _data *data;
struct sObject *ptr;
int _ni=2;
struct BINDING _ibind[2]={
    {NULL,0,0,0,0,0,NULL},
    {NULL,0,0,0,0,0,NULL}
};
char *title=NULL;
 
/* END OF DEFINE SECTION */
 
  if (!ensureObject("ui.gantt",*objectID,&ptr)) {
     A4GL_exitwith("Not an object of type (ui.gantt) or not initialized");
     return 0;
  }
  data=ptr->objData;
 
  if (n!=1) { 
    A4GL_pop_args(n);
    okToProcess=0;
  }
 
  // Set up input binding for our parameters
  if (okToProcess) {
 
    title=A4GL_char_pop();
    _ibind[1].ptr=title;
    _ibind[1].size=strlen(title);
    _ibind[0].ptr=data->data;
    _ibind[0].size=strlen(data->data);
  }
 
  if (okToProcess) {
      A4GL_ui_frontcall("INTERNAL","ui.gantt.settitle",_ibind,_ni,NULL,0 );
  }
 
 
  // Set up output binding for our parameters
    if (title ) {
        free(title);
    }
  return 0;
}
 
void add_ui_gantt_support(void) {
A4GL_add_object_type("ui.gantt");
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.gantt.create", (void *)  ui_gantt_create);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.gantt.readcsv", (void *)  ui_gantt_readcsv);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.gantt.settitle", (void *)  ui_gantt_settitle);
}
