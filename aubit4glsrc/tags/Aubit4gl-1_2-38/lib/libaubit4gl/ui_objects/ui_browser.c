#include "a4gl_libaubit4gl_int.h"
struct _data {
	char data[256];
};
 
static int new_obj(char *newData) {
struct sObject *obj;
struct _data *data;
obj=new_object("ui.browser");
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
 
 
 
 
static int ui_browser_create(long *objectID_IgnoredAsAlways0,int n) {
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
      A4GL_ui_frontcall("INTERNAL","ui.browser.create",NULL,0,_obind,_no );
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
 
 
 
 
static int ui_browser_openurl(long *objectID,int n) {
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
char *url=NULL;
 
/* END OF DEFINE SECTION */
 
  if (!ensureObject("ui.browser",*objectID,&ptr)) {
     A4GL_exitwith("Not an object of type (ui.browser) or not initialized");
     return 0;
  }
  data=ptr->objData;
 
  if (n!=1) { 
    A4GL_pop_args(n);
    okToProcess=0;
  }
 
  // Set up input binding for our parameters
  if (okToProcess) {
 
    url=A4GL_char_pop();
    _ibind[1].ptr=url;
    _ibind[1].size=strlen(url);
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
      A4GL_ui_frontcall("INTERNAL","ui.browser.openurl",_ibind,_ni,_obind,_no );
  }
 
 
  // Set up output binding for our parameters
    if (url ) {
        free(url);
    }
  if (!okToProcess) {
    A4GL_push_null(DTYPE_INT,0);
  } else {
    A4GL_push_int(rval_0);
  }
  return 1;
}
 
 
 
 
static int ui_browser_waitforclose(long *objectID,int n) {
int okToProcess=1;
struct _data *data;
struct sObject *ptr;
int _ni=1;
struct BINDING _ibind[1]={
    {NULL,0,0,0,0,0,NULL}
};
int _no=1;
struct BINDING _obind[1]={
    {NULL,0,0,0,0,0,NULL}
};
int rval_0;
 
/* END OF DEFINE SECTION */
 
  if (!ensureObject("ui.browser",*objectID,&ptr)) {
     A4GL_exitwith("Not an object of type (ui.browser) or not initialized");
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
 
  // Set up output binding for our parameters
  if (okToProcess) {
    _obind[0].ptr=&rval_0;
    _obind[0].size=4;
    _obind[0].dtype=DTYPE_INT;
  }
 
  if (okToProcess) {
      A4GL_ui_frontcall("INTERNAL","ui.browser.waitforclose",_ibind,_ni,_obind,_no );
  }
 
 
  // Set up output binding for our parameters
  if (!okToProcess) {
    A4GL_push_null(DTYPE_INT,0);
  } else {
    A4GL_push_int(rval_0);
  }
  return 1;
}
 
 
 
 
static int ui_browser_refresh(long *objectID,int n) {
int okToProcess=1;
struct _data *data;
struct sObject *ptr;
int _ni=1;
struct BINDING _ibind[1]={
    {NULL,0,0,0,0,0,NULL}
};
 
/* END OF DEFINE SECTION */
 
  if (!ensureObject("ui.browser",*objectID,&ptr)) {
     A4GL_exitwith("Not an object of type (ui.browser) or not initialized");
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
      A4GL_ui_frontcall("INTERNAL","ui.browser.refresh",_ibind,_ni,NULL,0 );
  }
 
 
  // Set up output binding for our parameters
  return 0;
}
 
 
 
 
static int ui_browser_backward(long *objectID,int n) {
int okToProcess=1;
struct _data *data;
struct sObject *ptr;
int _ni=1;
struct BINDING _ibind[1]={
    {NULL,0,0,0,0,0,NULL}
};
 
/* END OF DEFINE SECTION */
 
  if (!ensureObject("ui.browser",*objectID,&ptr)) {
     A4GL_exitwith("Not an object of type (ui.browser) or not initialized");
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
      A4GL_ui_frontcall("INTERNAL","ui.browser.backward",_ibind,_ni,NULL,0 );
  }
 
 
  // Set up output binding for our parameters
  return 0;
}
 
 
 
 
static int ui_browser_forward(long *objectID,int n) {
int okToProcess=1;
struct _data *data;
struct sObject *ptr;
int _ni=1;
struct BINDING _ibind[1]={
    {NULL,0,0,0,0,0,NULL}
};
 
/* END OF DEFINE SECTION */
 
  if (!ensureObject("ui.browser",*objectID,&ptr)) {
     A4GL_exitwith("Not an object of type (ui.browser) or not initialized");
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
      A4GL_ui_frontcall("INTERNAL","ui.browser.forward",_ibind,_ni,NULL,0 );
  }
 
 
  // Set up output binding for our parameters
  return 0;
}
 
 
 
 
static int ui_browser_close(long *objectID,int n) {
int okToProcess=1;
struct _data *data;
struct sObject *ptr;
int _ni=1;
struct BINDING _ibind[1]={
    {NULL,0,0,0,0,0,NULL}
};
 
/* END OF DEFINE SECTION */
 
  if (!ensureObject("ui.browser",*objectID,&ptr)) {
     A4GL_exitwith("Not an object of type (ui.browser) or not initialized");
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
      A4GL_ui_frontcall("INTERNAL","ui.browser.close",_ibind,_ni,NULL,0 );
  }
 
 
  // Set up output binding for our parameters
  return 0;
}
 
void add_ui_browser_support(void) {
A4GL_add_object_type("ui.browser");
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.browser.create", (void *)  ui_browser_create);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.browser.openurl", (void *)  ui_browser_openurl);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.browser.waitforclose", (void *)  ui_browser_waitforclose);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.browser.refresh", (void *)  ui_browser_refresh);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.browser.backward", (void *)  ui_browser_backward);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.browser.forward", (void *)  ui_browser_forward);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.browser.close", (void *)  ui_browser_close);
}
