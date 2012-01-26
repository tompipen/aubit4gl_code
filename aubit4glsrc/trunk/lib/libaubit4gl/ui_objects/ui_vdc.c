#include "a4gl_libaubit4gl_int.h"
struct _data {
	char data[256];
};
 
static int new_obj(char *newData) {
struct sObject *obj;
struct _data *data;
obj=new_object("ui.vdc");
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
 
 
 
 
static int ui_vdc_action(long *objectID_IgnoredAsAlways0,int n) {
int okToProcess=1;
int _ni=10;
struct BINDING _ibind[10]={
    {NULL,0,0,0,0,0,NULL},
    {NULL,0,0,0,0,0,NULL},
    {NULL,0,0,0,0,0,NULL},
    {NULL,0,0,0,0,0,NULL},
    {NULL,0,0,0,0,0,NULL},
    {NULL,0,0,0,0,0,NULL},
    {NULL,0,0,0,0,0,NULL},
    {NULL,0,0,0,0,0,NULL},
    {NULL,0,0,0,0,0,NULL},
    {NULL,0,0,0,0,0,NULL}
};
int _no=2;
struct BINDING _obind[2]={
    {NULL,0,0,0,0,0,NULL},
    {NULL,0,0,0,0,0,NULL}
};
int rval_0;
char rval_1[512];
char *param1=NULL;
char *param2=NULL;
char *param3=NULL;
char *param4=NULL;
char *param5=NULL;
char *param6=NULL;
char *param7=NULL;
char *param8=NULL;
char *param9=NULL;
char *param10=NULL;
 
/* END OF DEFINE SECTION */
 
 
  if (n!=10) { 
    A4GL_pop_args(n);
    okToProcess=0;
  }
 
  // Set up input binding for our parameters
  if (okToProcess) {
 
    param10=A4GL_char_pop();
    _ibind[9].ptr=param10;
    _ibind[9].size=strlen(param10);
 
    param9=A4GL_char_pop();
    _ibind[8].ptr=param9;
    _ibind[8].size=strlen(param9);
 
    param8=A4GL_char_pop();
    _ibind[7].ptr=param8;
    _ibind[7].size=strlen(param8);
 
    param7=A4GL_char_pop();
    _ibind[6].ptr=param7;
    _ibind[6].size=strlen(param7);
 
    param6=A4GL_char_pop();
    _ibind[5].ptr=param6;
    _ibind[5].size=strlen(param6);
 
    param5=A4GL_char_pop();
    _ibind[4].ptr=param5;
    _ibind[4].size=strlen(param5);
 
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
    _obind[1].ptr=&rval_1;
    _obind[1].size=512;
  }
 
  if (okToProcess) {
      A4GL_ui_frontcall("INTERNAL","ui.vdc.action",_ibind,_ni,_obind,_no );
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
    if (param5 ) {
        free(param5);
    }
    if (param6 ) {
        free(param6);
    }
    if (param7 ) {
        free(param7);
    }
    if (param8 ) {
        free(param8);
    }
    if (param9 ) {
        free(param9);
    }
    if (param10 ) {
        free(param10);
    }
  if (!okToProcess) {
    A4GL_push_null(DTYPE_INT,0);
    A4GL_push_null(DTYPE_CHAR,1);
  } else {
    A4GL_push_int(rval_0);
    A4GL_push_char(rval_1);
  }
  return 2;
}
 
 
 
 
static int ui_vdc_repgen(long *objectID_IgnoredAsAlways0,int n) {
int okToProcess=1;
int _ni=3;
struct BINDING _ibind[3]={
    {NULL,0,0,0,0,0,NULL},
    {NULL,0,0,0,0,0,NULL},
    {NULL,0,0,0,0,0,NULL}
};
int _no=2;
struct BINDING _obind[2]={
    {NULL,0,0,0,0,0,NULL},
    {NULL,0,0,0,0,0,NULL}
};
int rval_0;
char rval_1[512];
char *odffile=NULL;
char *sedfile=NULL;
char *destfile=NULL;
 
/* END OF DEFINE SECTION */
 
 
  if (n!=3) { 
    A4GL_pop_args(n);
    okToProcess=0;
  }
 
  // Set up input binding for our parameters
  if (okToProcess) {
 
    destfile=A4GL_char_pop();
    _ibind[2].ptr=destfile;
    _ibind[2].size=strlen(destfile);
 
    sedfile=A4GL_char_pop();
    _ibind[1].ptr=sedfile;
    _ibind[1].size=strlen(sedfile);
    odffile=A4GL_char_pop();
    _ibind[0].ptr=odffile;
    _ibind[0].size=strlen(odffile);
  }
 
  // Set up output binding for our parameters
  if (okToProcess) {
    _obind[0].ptr=&rval_0;
    _obind[0].size=4;
    _obind[0].dtype=DTYPE_INT;
    _obind[1].ptr=&rval_1;
    _obind[1].size=512;
  }
 
  if (okToProcess) {
      A4GL_ui_frontcall("INTERNAL","ui.vdc.repgen",_ibind,_ni,_obind,_no );
  }
 
 
  // Set up output binding for our parameters
    if (odffile ) {
        free(odffile);
    }
    if (sedfile ) {
        free(sedfile);
    }
    if (destfile ) {
        free(destfile);
    }
  if (!okToProcess) {
    A4GL_push_null(DTYPE_INT,0);
    A4GL_push_null(DTYPE_CHAR,1);
  } else {
    A4GL_push_int(rval_0);
    A4GL_push_char(rval_1);
  }
  return 2;
}
 
 
 
 
static int ui_vdc_odftopdf(long *objectID_IgnoredAsAlways0,int n) {
int okToProcess=1;
int _ni=2;
struct BINDING _ibind[2]={
    {NULL,0,0,0,0,0,NULL},
    {NULL,0,0,0,0,0,NULL}
};
int _no=2;
struct BINDING _obind[2]={
    {NULL,0,0,0,0,0,NULL},
    {NULL,0,0,0,0,0,NULL}
};
int rval_0;
char rval_1[512];
char *srcfile=NULL;
char *destfile=NULL;
 
/* END OF DEFINE SECTION */
 
 
  if (n!=2) { 
    A4GL_pop_args(n);
    okToProcess=0;
  }
 
  // Set up input binding for our parameters
  if (okToProcess) {
 
    destfile=A4GL_char_pop();
    _ibind[1].ptr=destfile;
    _ibind[1].size=strlen(destfile);
    srcfile=A4GL_char_pop();
    _ibind[0].ptr=srcfile;
    _ibind[0].size=strlen(srcfile);
  }
 
  // Set up output binding for our parameters
  if (okToProcess) {
    _obind[0].ptr=&rval_0;
    _obind[0].size=4;
    _obind[0].dtype=DTYPE_INT;
    _obind[1].ptr=&rval_1;
    _obind[1].size=512;
  }
 
  if (okToProcess) {
      A4GL_ui_frontcall("INTERNAL","ui.vdc.odftopdf",_ibind,_ni,_obind,_no );
  }
 
 
  // Set up output binding for our parameters
    if (srcfile ) {
        free(srcfile);
    }
    if (destfile ) {
        free(destfile);
    }
  if (!okToProcess) {
    A4GL_push_null(DTYPE_INT,0);
    A4GL_push_null(DTYPE_CHAR,1);
  } else {
    A4GL_push_int(rval_0);
    A4GL_push_char(rval_1);
  }
  return 2;
}
 
void add_ui_vdc_support(void) {
A4GL_add_object_type("ui.vdc");
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.vdc.action", (void *)  ui_vdc_action);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.vdc.repgen", (void *)  ui_vdc_repgen);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.vdc.odftopdf", (void *)  ui_vdc_odftopdf);
}
