#include "a4gl_libaubit4gl_int.h"
struct _data {
	char data[256];
};
 
static int new_obj(char *newData) {
struct sObject *obj;
struct _data *data;
obj=new_object("ui.progress");
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
 
 
 
 
static int ui_progress_create(long *objectID_IgnoredAsAlways0,int n) {
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
      A4GL_ui_frontcall("INTERNAL","ui.progress.create",NULL,0,_obind,_no );
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
 
 
 
 
static int ui_progress_show(long *objectID,int n) {
int okToProcess=1;
struct _data *data;
struct sObject *ptr;
int _ni=1;
struct BINDING _ibind[1]={
    {NULL,0,0,0,0,0,NULL}
};
 
/* END OF DEFINE SECTION */
 
  if (!ensureObject("ui.progress",*objectID,&ptr)) {
     A4GL_exitwith("Not an object of type (ui.progress) or not initialized");
     return 0;
  }
  data=ptr->objData;
 
  if (n!=0) { 
    A4GL_pop_args(n);
    okToProcess=0;
  }
 
  // Set up input binding for our parameters
  if (okToProcess) {
    _ibind[0].ptr=data->data;
    _ibind[0].size=strlen(data->data);
  }
 
  if (okToProcess) {
      A4GL_ui_frontcall("INTERNAL","ui.progress.show",_ibind,_ni,NULL,0 );
  }
 
 
  // Set up output binding for our parameters
  return 0;
}
 
 
 
 
static int ui_progress_hide(long *objectID,int n) {
int okToProcess=1;
struct _data *data;
struct sObject *ptr;
int _ni=1;
struct BINDING _ibind[1]={
    {NULL,0,0,0,0,0,NULL}
};
 
/* END OF DEFINE SECTION */
 
  if (!ensureObject("ui.progress",*objectID,&ptr)) {
     A4GL_exitwith("Not an object of type (ui.progress) or not initialized");
     return 0;
  }
  data=ptr->objData;
 
  if (n!=0) { 
    A4GL_pop_args(n);
    okToProcess=0;
  }
 
  // Set up input binding for our parameters
  if (okToProcess) {
    _ibind[0].ptr=data->data;
    _ibind[0].size=strlen(data->data);
  }
 
  if (okToProcess) {
      A4GL_ui_frontcall("INTERNAL","ui.progress.hide",_ibind,_ni,NULL,0 );
  }
 
 
  // Set up output binding for our parameters
  return 0;
}
 
 
 
 
static int ui_progress_settitle(long *objectID,int n) {
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
 
  if (!ensureObject("ui.progress",*objectID,&ptr)) {
     A4GL_exitwith("Not an object of type (ui.progress) or not initialized");
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
      A4GL_ui_frontcall("INTERNAL","ui.progress.settitle",_ibind,_ni,NULL,0 );
  }
 
 
  // Set up output binding for our parameters
    if (title ) {
        free(title);
    }
  return 0;
}
 
 
 
 
static int ui_progress_settext(long *objectID,int n) {
int okToProcess=1;
struct _data *data;
struct sObject *ptr;
int _ni=2;
struct BINDING _ibind[2]={
    {NULL,0,0,0,0,0,NULL},
    {NULL,0,0,0,0,0,NULL}
};
char *text=NULL;
 
/* END OF DEFINE SECTION */
 
  if (!ensureObject("ui.progress",*objectID,&ptr)) {
     A4GL_exitwith("Not an object of type (ui.progress) or not initialized");
     return 0;
  }
  data=ptr->objData;
 
  if (n!=1) { 
    A4GL_pop_args(n);
    okToProcess=0;
  }
 
  // Set up input binding for our parameters
  if (okToProcess) {
 
    text=A4GL_char_pop();
    _ibind[1].ptr=text;
    _ibind[1].size=strlen(text);
    _ibind[0].ptr=data->data;
    _ibind[0].size=strlen(data->data);
  }
 
  if (okToProcess) {
      A4GL_ui_frontcall("INTERNAL","ui.progress.settext",_ibind,_ni,NULL,0 );
  }
 
 
  // Set up output binding for our parameters
    if (text ) {
        free(text);
    }
  return 0;
}
 
 
 
 
static int ui_progress_close(long *objectID,int n) {
int okToProcess=1;
struct _data *data;
struct sObject *ptr;
int _ni=1;
struct BINDING _ibind[1]={
    {NULL,0,0,0,0,0,NULL}
};
 
/* END OF DEFINE SECTION */
 
  if (!ensureObject("ui.progress",*objectID,&ptr)) {
     A4GL_exitwith("Not an object of type (ui.progress) or not initialized");
     return 0;
  }
  data=ptr->objData;
 
  if (n!=0) { 
    A4GL_pop_args(n);
    okToProcess=0;
  }
 
  // Set up input binding for our parameters
  if (okToProcess) {
    _ibind[0].ptr=data->data;
    _ibind[0].size=strlen(data->data);
  }
 
  if (okToProcess) {
      A4GL_ui_frontcall("INTERNAL","ui.progress.close",_ibind,_ni,NULL,0 );
  }
 
 
  // Set up output binding for our parameters
  return 0;
}
 
void add_ui_progress_support(void) {
A4GL_add_object_type("ui.progress");
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.progress.create", (void *)  ui_progress_create);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.progress.show", (void *)  ui_progress_show);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.progress.hide", (void *)  ui_progress_hide);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.progress.settitle", (void *)  ui_progress_settitle);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.progress.settext", (void *)  ui_progress_settext);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.progress.close", (void *)  ui_progress_close);
}
