#include "a4gl_libaubit4gl_int.h"
struct _data {
	char data[256];
};
 
static int new_obj(char *newData) {
struct sObject *obj;
struct _data *data;
obj=new_object("ui.combobox");
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
 
 
 
 
static int ui_combobox_forname(long *objectID_IgnoredAsAlways0,int n) {
int okToProcess=1;
int _ni=1;
struct BINDING _ibind[1]={
    {NULL,0,0,0,0,0,NULL}
};
int _no=1;
struct BINDING _obind[1]={
    {NULL,0,0,0,0,0,NULL}
};
char data[256];
char *fieldname=NULL;
 
/* END OF DEFINE SECTION */
 
 
  if (n!=1) { 
    A4GL_pop_args(n);
    okToProcess=0;
  }
 
  // Set up input binding for our parameters
  if (okToProcess) {
    fieldname=A4GL_char_pop();
    _ibind[0].ptr=fieldname;
    _ibind[0].size=strlen(fieldname);
  }
 
  // Set up output binding for our parameters
  if (okToProcess) {
    _obind[0].ptr=&data;
    _obind[0].size=255;
  }
 
  if (okToProcess) {
      A4GL_ui_frontcall("INTERNAL","ui.combobox.forname",_ibind,_ni,_obind,_no );
  }
 
 
  // Set up output binding for our parameters
    if (fieldname ) {
        free(fieldname);
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
 
 
 
 
static int ui_combobox_additem(long *objectID,int n) {
int okToProcess=1;
struct _data *data;
struct sObject *ptr;
int _ni=3;
struct BINDING _ibind[3]={
    {NULL,0,0,0,0,0,NULL},
    {NULL,0,0,0,0,0,NULL},
    {NULL,0,0,0,0,0,NULL}
};
char *name=NULL;
char *text=NULL;
 
/* END OF DEFINE SECTION */
 
  if (!ensureObject("ui.combobox",*objectID,&ptr)) {
     A4GL_exitwith("Not an object of type (ui.combobox) or not initialized");
     return 0;
  }
  data=ptr->objData;
 
  if (n!=2) { 
    A4GL_pop_args(n);
    okToProcess=0;
  }
 
  // Set up input binding for our parameters
  if (okToProcess) {
 
    text=A4GL_char_pop();
    _ibind[2].ptr=text;
    _ibind[2].size=strlen(text);
 
    name=A4GL_char_pop();
    _ibind[1].ptr=name;
    _ibind[1].size=strlen(name);
    _ibind[0].ptr=data->data;
    _ibind[0].size=strlen(data->data);
  }
 
  if (okToProcess) {
      A4GL_ui_frontcall("INTERNAL","ui.combobox.additem",_ibind,_ni,NULL,0 );
  }
 
 
  // Set up output binding for our parameters
    if (name ) {
        free(name);
    }
    if (text ) {
        free(text);
    }
  return 0;
}
 
 
 
 
static int ui_combobox_clear(long *objectID,int n) {
int okToProcess=1;
struct _data *data;
struct sObject *ptr;
int _ni=1;
struct BINDING _ibind[1]={
    {NULL,0,0,0,0,0,NULL}
};
 
/* END OF DEFINE SECTION */
 
  if (!ensureObject("ui.combobox",*objectID,&ptr)) {
     A4GL_exitwith("Not an object of type (ui.combobox) or not initialized");
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
      A4GL_ui_frontcall("INTERNAL","ui.combobox.clear",_ibind,_ni,NULL,0 );
  }
 
 
  // Set up output binding for our parameters
  return 0;
}
 
 
 
 
static int ui_combobox_getcolumnname(long *objectID,int n) {
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
char rval_0[512];
 
/* END OF DEFINE SECTION */
 
  if (!ensureObject("ui.combobox",*objectID,&ptr)) {
     A4GL_exitwith("Not an object of type (ui.combobox) or not initialized");
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
    _obind[0].size=512;
  }
 
  if (okToProcess) {
      A4GL_ui_frontcall("INTERNAL","ui.combobox.getcolumnname",_ibind,_ni,_obind,_no );
  }
 
 
  // Set up output binding for our parameters
  if (!okToProcess) {
    A4GL_push_null(DTYPE_CHAR,1);
  } else {
    A4GL_push_char(rval_0);
  }
  return 1;
}
 
 
 
 
static int ui_combobox_getindexof(long *objectID,int n) {
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
char rval_0[512];
char *name=NULL;
 
/* END OF DEFINE SECTION */
 
  if (!ensureObject("ui.combobox",*objectID,&ptr)) {
     A4GL_exitwith("Not an object of type (ui.combobox) or not initialized");
     return 0;
  }
  data=ptr->objData;
 
  if (n!=1) { 
    A4GL_pop_args(n);
    okToProcess=0;
  }
 
  // Set up input binding for our parameters
  if (okToProcess) {
 
    name=A4GL_char_pop();
    _ibind[1].ptr=name;
    _ibind[1].size=strlen(name);
    _ibind[0].ptr=data->data;
    _ibind[0].size=strlen(data->data);
  }
 
  // Set up output binding for our parameters
  if (okToProcess) {
    _obind[0].ptr=&rval_0;
    _obind[0].size=512;
  }
 
  if (okToProcess) {
      A4GL_ui_frontcall("INTERNAL","ui.combobox.getindexof",_ibind,_ni,_obind,_no );
  }
 
 
  // Set up output binding for our parameters
    if (name ) {
        free(name);
    }
  if (!okToProcess) {
    A4GL_push_null(DTYPE_CHAR,1);
  } else {
    A4GL_push_char(rval_0);
  }
  return 1;
}
 
 
 
 
static int ui_combobox_getitemcount(long *objectID,int n) {
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
 
  if (!ensureObject("ui.combobox",*objectID,&ptr)) {
     A4GL_exitwith("Not an object of type (ui.combobox) or not initialized");
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
      A4GL_ui_frontcall("INTERNAL","ui.combobox.getitemcount",_ibind,_ni,_obind,_no );
  }
 
 
  // Set up output binding for our parameters
  if (!okToProcess) {
    A4GL_push_null(DTYPE_INT,0);
  } else {
    A4GL_push_long(rval_0);
  }
  return 1;
}
 
 
 
 
static int ui_combobox_getitemname(long *objectID,int n) {
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
char rval_0[512];
int index;
 
/* END OF DEFINE SECTION */
 
  if (!ensureObject("ui.combobox",*objectID,&ptr)) {
     A4GL_exitwith("Not an object of type (ui.combobox) or not initialized");
     return 0;
  }
  data=ptr->objData;
 
  if (n!=1) { 
    A4GL_pop_args(n);
    okToProcess=0;
  }
 
  // Set up input binding for our parameters
  if (okToProcess) {
 
    index=A4GL_pop_int();
    _ibind[1].ptr=&index;
    _ibind[1].size=4;
    _ibind[1].dtype=DTYPE_INT;
    _ibind[0].ptr=data->data;
    _ibind[0].size=strlen(data->data);
  }
 
  // Set up output binding for our parameters
  if (okToProcess) {
    _obind[0].ptr=&rval_0;
    _obind[0].size=512;
  }
 
  if (okToProcess) {
      A4GL_ui_frontcall("INTERNAL","ui.combobox.getitemname",_ibind,_ni,_obind,_no );
  }
 
 
  // Set up output binding for our parameters
  if (!okToProcess) {
    A4GL_push_null(DTYPE_CHAR,1);
  } else {
    A4GL_push_char(rval_0);
  }
  return 1;
}
 
 
 
 
static int ui_combobox_getitemtext(long *objectID,int n) {
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
char rval_0[512];
int index;
 
/* END OF DEFINE SECTION */
 
  if (!ensureObject("ui.combobox",*objectID,&ptr)) {
     A4GL_exitwith("Not an object of type (ui.combobox) or not initialized");
     return 0;
  }
  data=ptr->objData;
 
  if (n!=1) { 
    A4GL_pop_args(n);
    okToProcess=0;
  }
 
  // Set up input binding for our parameters
  if (okToProcess) {
 
    index=A4GL_pop_int();
    _ibind[1].ptr=&index;
    _ibind[1].size=4;
    _ibind[1].dtype=DTYPE_INT;
    _ibind[0].ptr=data->data;
    _ibind[0].size=strlen(data->data);
  }
 
  // Set up output binding for our parameters
  if (okToProcess) {
    _obind[0].ptr=&rval_0;
    _obind[0].size=512;
  }
 
  if (okToProcess) {
      A4GL_ui_frontcall("INTERNAL","ui.combobox.getitemtext",_ibind,_ni,_obind,_no );
  }
 
 
  // Set up output binding for our parameters
  if (!okToProcess) {
    A4GL_push_null(DTYPE_CHAR,1);
  } else {
    A4GL_push_char(rval_0);
  }
  return 1;
}
 
 
 
 
static int ui_combobox_gettablename(long *objectID,int n) {
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
char rval_0[512];
 
/* END OF DEFINE SECTION */
 
  if (!ensureObject("ui.combobox",*objectID,&ptr)) {
     A4GL_exitwith("Not an object of type (ui.combobox) or not initialized");
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
    _obind[0].size=512;
  }
 
  if (okToProcess) {
      A4GL_ui_frontcall("INTERNAL","ui.combobox.gettablename",_ibind,_ni,_obind,_no );
  }
 
 
  // Set up output binding for our parameters
  if (!okToProcess) {
    A4GL_push_null(DTYPE_CHAR,1);
  } else {
    A4GL_push_char(rval_0);
  }
  return 1;
}
 
 
 
 
static int ui_combobox_gettag(long *objectID,int n) {
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
char rval_0[512];
 
/* END OF DEFINE SECTION */
 
  if (!ensureObject("ui.combobox",*objectID,&ptr)) {
     A4GL_exitwith("Not an object of type (ui.combobox) or not initialized");
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
    _obind[0].size=512;
  }
 
  if (okToProcess) {
      A4GL_ui_frontcall("INTERNAL","ui.combobox.gettag",_ibind,_ni,_obind,_no );
  }
 
 
  // Set up output binding for our parameters
  if (!okToProcess) {
    A4GL_push_null(DTYPE_CHAR,1);
  } else {
    A4GL_push_char(rval_0);
  }
  return 1;
}
 
 
 
 
static int ui_combobox_gettextof(long *objectID,int n) {
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
char rval_0[512];
char *name=NULL;
 
/* END OF DEFINE SECTION */
 
  if (!ensureObject("ui.combobox",*objectID,&ptr)) {
     A4GL_exitwith("Not an object of type (ui.combobox) or not initialized");
     return 0;
  }
  data=ptr->objData;
 
  if (n!=1) { 
    A4GL_pop_args(n);
    okToProcess=0;
  }
 
  // Set up input binding for our parameters
  if (okToProcess) {
 
    name=A4GL_char_pop();
    _ibind[1].ptr=name;
    _ibind[1].size=strlen(name);
    _ibind[0].ptr=data->data;
    _ibind[0].size=strlen(data->data);
  }
 
  // Set up output binding for our parameters
  if (okToProcess) {
    _obind[0].ptr=&rval_0;
    _obind[0].size=512;
  }
 
  if (okToProcess) {
      A4GL_ui_frontcall("INTERNAL","ui.combobox.gettextof",_ibind,_ni,_obind,_no );
  }
 
 
  // Set up output binding for our parameters
    if (name ) {
        free(name);
    }
  if (!okToProcess) {
    A4GL_push_null(DTYPE_CHAR,1);
  } else {
    A4GL_push_char(rval_0);
  }
  return 1;
}
 
 
 
 
static int ui_combobox_removeitem(long *objectID,int n) {
int okToProcess=1;
struct _data *data;
struct sObject *ptr;
int _ni=2;
struct BINDING _ibind[2]={
    {NULL,0,0,0,0,0,NULL},
    {NULL,0,0,0,0,0,NULL}
};
char *name=NULL;
 
/* END OF DEFINE SECTION */
 
  if (!ensureObject("ui.combobox",*objectID,&ptr)) {
     A4GL_exitwith("Not an object of type (ui.combobox) or not initialized");
     return 0;
  }
  data=ptr->objData;
 
  if (n!=1) { 
    A4GL_pop_args(n);
    okToProcess=0;
  }
 
  // Set up input binding for our parameters
  if (okToProcess) {
 
    name=A4GL_char_pop();
    _ibind[1].ptr=name;
    _ibind[1].size=strlen(name);
    _ibind[0].ptr=data->data;
    _ibind[0].size=strlen(data->data);
  }
 
  if (okToProcess) {
      A4GL_ui_frontcall("INTERNAL","ui.combobox.removeitem",_ibind,_ni,NULL,0 );
  }
 
 
  // Set up output binding for our parameters
    if (name ) {
        free(name);
    }
  return 0;
}
 
void add_ui_combobox_support(void) {
A4GL_add_object_type("ui.combobox");
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.combobox.forname", (void *)  ui_combobox_forname);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.combobox.additem", (void *)  ui_combobox_additem);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.combobox.clear", (void *)  ui_combobox_clear);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.combobox.getcolumnname", (void *)  ui_combobox_getcolumnname);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.combobox.getindexof", (void *)  ui_combobox_getindexof);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.combobox.getitemcount", (void *)  ui_combobox_getitemcount);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.combobox.getitemname", (void *)  ui_combobox_getitemname);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.combobox.getitemtext", (void *)  ui_combobox_getitemtext);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.combobox.gettablename", (void *)  ui_combobox_gettablename);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.combobox.gettag", (void *)  ui_combobox_gettag);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.combobox.gettextof", (void *)  ui_combobox_gettextof);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.combobox.removeitem", (void *)  ui_combobox_removeitem);
}
