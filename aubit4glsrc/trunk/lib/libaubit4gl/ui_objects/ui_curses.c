#include "a4gl_libaubit4gl_int.h"
struct _data {
	char data[256];
};
 

/*
static int new_obj(char *newData) {
struct sObject *obj;
struct _data *data;
obj=new_object("ui.curses");
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
*/
 
 
 
 
static int ui_curses_define_key(long *objectID_IgnoredAsAlways0,int n) {
int okToProcess=1;
int _ni=2;
struct BINDING _ibind[2]={
    {NULL,0,0,0,0,0,NULL},
    {NULL,0,0,0,0,0,NULL}
};
char *keyname=NULL;
int keycode;
 
/* END OF DEFINE SECTION */
 
 
  if (n!=2) { 
    A4GL_pop_args(n);
    okToProcess=0;
  }
 
  // Set up input binding for our parameters
  if (okToProcess) {
 
    keycode=A4GL_pop_int();
    _ibind[1].ptr=&keycode;
    _ibind[1].size=4;
    _ibind[1].dtype=DTYPE_INT;
    keyname=A4GL_char_pop();
    _ibind[0].ptr=keyname;
    _ibind[0].size=strlen(keyname);
  }
 
  if (okToProcess) {
      A4GL_ui_frontcall("INTERNAL","ui.curses.define_key",_ibind,_ni,NULL,0 );
  }
 
 
  // Set up output binding for our parameters
    if (keyname ) {
        free(keyname);
    }
  return 0;
}
 
 
 
 
static int ui_curses_fgl_setsize(long *objectID_IgnoredAsAlways0,int n) {
int okToProcess=1;
int _ni=2;
struct BINDING _ibind[2]={
    {NULL,0,0,0,0,0,NULL},
    {NULL,0,0,0,0,0,NULL}
};
int height;
int width;
 
/* END OF DEFINE SECTION */
 
 
  if (n!=2) { 
    A4GL_pop_args(n);
    okToProcess=0;
  }
 
  // Set up input binding for our parameters
  if (okToProcess) {
 
    width=A4GL_pop_int();
    _ibind[1].ptr=&width;
    _ibind[1].size=4;
    _ibind[1].dtype=DTYPE_INT;
    height=A4GL_pop_int();
    _ibind[0].ptr=&height;
    _ibind[0].size=4;
    _ibind[0].dtype=DTYPE_INT;
  }
 
  if (okToProcess) {
      A4GL_ui_frontcall("INTERNAL","ui.curses.fgl_setsize",_ibind,_ni,NULL,0 );
  }
 
 
  // Set up output binding for our parameters
  return 0;
}



static int ui_curses_getkey(long *objectID_IgnoredAsAlways0,int n) {
long x=0;
struct BINDING _obind[2]={
    {NULL,2,0,0,0,0,NULL},
};
 
/* END OF DEFINE SECTION */
 
 
  _obind[0].ptr=&x;
  if (n!=0) { 
    A4GL_pop_args(n);
  } else {
      A4GL_ui_frontcall("INTERNAL","ui.curses.getkey",NULL,0,_obind,1 );
  }
 
 A4GL_push_int(x);
  // Set up output binding for our parameters
  return 1;
}


static int ui_curses_set_ovr(long *objectID_IgnoredAsAlways0,int n) {
long x=0;
 
  if (n!=0) { 
    A4GL_pop_args(n);
  } else {
      A4GL_ui_frontcall("INTERNAL","ui.curses.setovr",NULL,0,NULL,0 );
  }
 
  // Set up output binding for our parameters
  return 0;
}

static int ui_curses_set_ins(long *objectID_IgnoredAsAlways0,int n) {
long x=0;
 
  if (n!=0) { 
    A4GL_pop_args(n);
  } else {
      A4GL_ui_frontcall("INTERNAL","ui.curses.setins",NULL,0,NULL,0 );
  }
 
  // Set up output binding for our parameters
  return 0;
}

static int ui_curses_dumpCurrentForm(long *objectID_IgnoredAsAlways0,int n) {
long x=0;
 
  if (n!=0) { 
    A4GL_pop_args(n);
  } else {
      A4GL_ui_frontcall("INTERNAL","ui.curses.dumpCurrentForm",NULL,0,NULL,0 );
  }
 
  // Set up output binding for our parameters
  return 0;
}
 
void add_ui_curses_support(void) {
A4GL_add_object_type("ui.curses");
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.curses.define_key", (void *)  ui_curses_define_key);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.curses.fgl_setsize", (void *)  ui_curses_fgl_setsize);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.curses.getkey", (void *)  ui_curses_getkey);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.curses.setovr", (void *)  ui_curses_set_ovr);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.curses.setins", (void *)  ui_curses_set_ins);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.curses.dumpcurrentform", (void *)  ui_curses_dumpCurrentForm);
}
