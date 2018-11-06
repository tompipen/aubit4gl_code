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




static int ui_vdc_checkodffile(long *objectID_IgnoredAsAlways0,int n) {
int okToProcess=1;
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
char *odffile=NULL;
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
    odffile=A4GL_char_pop();
    _ibind[0].ptr=odffile;
    _ibind[0].size=strlen(odffile);
  }

  // Set up output binding for our parameters
  if (okToProcess) {
    _obind[0].ptr=&rval_0;
    _obind[0].size=4;
    _obind[0].dtype=DTYPE_INT;
  }

  if (okToProcess) {
      A4GL_ui_frontcall("INTERNAL","ui.vdc.checkodffile",_ibind,_ni,_obind,_no );
  }


  // Set up output binding for our parameters
    if (odffile ) {
        free(odffile);
    }
    if (destfile ) {
        free(destfile);
    }
  if (!okToProcess) {
    A4GL_push_null(DTYPE_INT,0);
  } else {
    A4GL_push_int(rval_0);
  }
  return 1;
}




static int ui_vdc_md5hashfile(long *objectID_IgnoredAsAlways0,int n) {
int okToProcess=1;
int _ni=1;
struct BINDING _ibind[1]={
    {NULL,0,0,0,0,0,NULL}
};
int _no=1;
struct BINDING _obind[1]={
    {NULL,0,0,0,0,0,NULL}
};
char rval_0[512];
char *filename=NULL;

/* END OF DEFINE SECTION */


  if (n!=1) {
    A4GL_pop_args(n);
    okToProcess=0;
  }

  // Set up input binding for our parameters
  if (okToProcess) {
    filename=A4GL_char_pop();
    _ibind[0].ptr=filename;
    _ibind[0].size=strlen(filename);
  }

  // Set up output binding for our parameters
  if (okToProcess) {
    _obind[0].ptr=&rval_0;
    _obind[0].size=512;
  }

  if (okToProcess) {
      A4GL_ui_frontcall("INTERNAL","ui.vdc.md5hashfile",_ibind,_ni,_obind,_no );
  }


  // Set up output binding for our parameters
    if (filename ) {
        free(filename);
    }
  if (!okToProcess) {
    A4GL_push_null(DTYPE_CHAR,1);
  } else {
    A4GL_push_char(rval_0);
  }
  return 1;
}




static int ui_vdc_printpdf(long *objectID_IgnoredAsAlways0,int n) {
int okToProcess=1;
int _ni=1;
struct BINDING _ibind[1]={
    {NULL,0,0,0,0,0,NULL}
};
int _no=1;
struct BINDING _obind[1]={
    {NULL,0,0,0,0,0,NULL}
};
int rval_0;
char *filename=NULL;

/* END OF DEFINE SECTION */


  if (n!=1) {
    A4GL_pop_args(n);
    okToProcess=0;
  }

  // Set up input binding for our parameters
  if (okToProcess) {
    filename=A4GL_char_pop();
    _ibind[0].ptr=filename;
    _ibind[0].size=strlen(filename);
  }

  // Set up output binding for our parameters
  if (okToProcess) {
    _obind[0].ptr=&rval_0;
    _obind[0].size=4;
    _obind[0].dtype=DTYPE_INT;
  }

  if (okToProcess) {
      A4GL_ui_frontcall("INTERNAL","ui.vdc.printpdf",_ibind,_ni,_obind,_no );
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




static int ui_vdc_execute(long *objectID_IgnoredAsAlways0,int n) {
int okToProcess=1;
int _ni=1;
struct BINDING _ibind[1]={
    {NULL,0,0,0,0,0,NULL}
};
int _no=1;
struct BINDING _obind[1]={
    {NULL,0,0,0,0,0,NULL}
};
int rval_0;
char *filename=NULL;

/* END OF DEFINE SECTION */


  if (n!=1) {
    A4GL_pop_args(n);
    okToProcess=0;
  }

  // Set up input binding for our parameters
  if (okToProcess) {
    filename=A4GL_char_pop();
    _ibind[0].ptr=filename;
    _ibind[0].size=strlen(filename);
  }

  // Set up output binding for our parameters
  if (okToProcess) {
    _obind[0].ptr=&rval_0;
    _obind[0].size=4;
    _obind[0].dtype=DTYPE_INT;
  }

  if (okToProcess) {
      A4GL_ui_frontcall("INTERNAL","ui.vdc.execute",_ibind,_ni,_obind,_no );
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




static int ui_vdc_getstdofficeprog(long *objectID_IgnoredAsAlways0,int n) {
int okToProcess=1;
int _no=1;
struct BINDING _obind[1]={
    {NULL,0,0,0,0,0,NULL}
};
int rval_0;

/* END OF DEFINE SECTION */


  if (n!=0) {
    A4GL_pop_args(n);
    okToProcess=0;
  }


  // Set up output binding for our parameters
  if (okToProcess) {
    _obind[0].ptr=&rval_0;
    _obind[0].size=4;
    _obind[0].dtype=DTYPE_INT;
  }

  if (okToProcess) {
      A4GL_ui_frontcall("INTERNAL","ui.vdc.getstdofficeprog",NULL,0,_obind,_no );
  }

  if (!okToProcess) {
    A4GL_push_null(DTYPE_INT,0);
  } else {
    A4GL_push_int(rval_0);
  }
  return 1;
}




static int ui_vdc_get_last_sort(long *objectID_IgnoredAsAlways0,int n) {
int okToProcess=1;
int _ni=1;
struct BINDING _ibind[1]={
    {NULL,0,0,0,0,0,NULL}
};
int _no=1;
struct BINDING _obind[1]={
    {NULL,0,0,0,0,0,NULL}
};
char rval_0[512];
char *modulname=NULL;

/* END OF DEFINE SECTION */


  if (n!=1) {
    A4GL_pop_args(n);
    okToProcess=0;
  }

  // Set up input binding for our parameters
  if (okToProcess) {
    modulname=A4GL_char_pop();
    _ibind[0].ptr=modulname;
    _ibind[0].size=strlen(modulname);
  }

  // Set up output binding for our parameters
  if (okToProcess) {
    _obind[0].ptr=&rval_0;
    _obind[0].size=512;
  }

  if (okToProcess) {
      A4GL_ui_frontcall("INTERNAL","ui.vdc.get_last_sort",_ibind,_ni,_obind,_no );
  }


  // Set up output binding for our parameters
    if (modulname ) {
        free(modulname);
    }
  if (!okToProcess) {
    A4GL_push_null(DTYPE_CHAR,1);
  } else {
    A4GL_push_char(rval_0);
  }
  return 1;
}

static int ui_vdc_settingonserver(long *objectID_IgnoredAsAlways0,int n) {
int okToProcess=1;

int _no=1;
struct BINDING _obind[1]={
    {NULL,0,0,0,0,0,NULL}
};
char rval_0[512];
char *modulname=NULL;

/* END OF DEFINE SECTION */

  if (n!=0) {
    A4GL_pop_args(n);
    okToProcess=0;
  }

  // Set up output binding for our parameters
  if (okToProcess) {
    _obind[0].ptr=&rval_0;
    _obind[0].size=512;
  }

  if (okToProcess) {
      A4GL_ui_frontcall("INTERNAL","ui.vdc.settingonserver",NULL,0,_obind,_no );
  }


  // Set up output binding for our parameters
  if (!okToProcess) {
    A4GL_push_null(DTYPE_CHAR,1);
  } else {
    A4GL_push_char(rval_0);
  }
  return 1;
}

static int ui_vdc_openeditor(long *objectID_IgnoredAsAlways0,int n) {
int okToProcess=1;
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
char *type=NULL;
char *htmlfile=NULL;

/* END OF DEFINE SECTION */


  if (n!=2) {
    A4GL_pop_args(n);
    okToProcess=0;
  }

  // Set up input binding for our parameters
  if (okToProcess) {

    htmlfile=A4GL_char_pop();
    _ibind[1].ptr=htmlfile;
    _ibind[1].size=strlen(htmlfile);
    type=A4GL_char_pop();
    _ibind[0].ptr=type;
    _ibind[0].size=strlen(type);
  }

  // Set up output binding for our parameters
  if (okToProcess) {
    _obind[0].ptr=&rval_0;
    _obind[0].size=4;
    _obind[0].dtype=DTYPE_INT;
  }

  if (okToProcess) {
      A4GL_ui_frontcall("INTERNAL","ui.vdc.openeditor",_ibind,_ni,_obind,_no );
  }


  // Set up output binding for our parameters
    if (type ) {
        free(type);
    }
    if (htmlfile ) {
        free(htmlfile);
    }
  if (!okToProcess) {
    A4GL_push_null(DTYPE_INT,0);
  } else {
    A4GL_push_int(rval_0);
  }
  return 1;
}




static int ui_vdc_getdevice(long *objectID_IgnoredAsAlways0,int n) {
int okToProcess=1;
int _ni=1;
struct BINDING _ibind[1]={
    {NULL,0,0,0,0,0,NULL}
};
int _no=2;
struct BINDING _obind[2]={
    {NULL,0,0,0,0,0,NULL},
    {NULL,0,0,0,0,0,NULL}
};
char rval_0[512];
char rval_1[512];
char *htmlfile=NULL;

/* END OF DEFINE SECTION */


  if (n!=1) {
    A4GL_pop_args(n);
    okToProcess=0;
  }

  // Set up input binding for our parameters
  if (okToProcess) {
    htmlfile=A4GL_char_pop();
    _ibind[0].ptr=htmlfile;
    _ibind[0].size=strlen(htmlfile);
  }

  // Set up output binding for our parameters
  if (okToProcess) {
    _obind[0].ptr=&rval_0;
    _obind[0].size=512;
    _obind[1].ptr=&rval_1;
    _obind[1].size=512;
  }

  if (okToProcess) {
      A4GL_ui_frontcall("INTERNAL","ui.vdc.getdevice",_ibind,_ni,_obind,_no );
  }


  // Set up output binding for our parameters
    if (htmlfile ) {
        free(htmlfile);
    }
  if (!okToProcess) {
    A4GL_push_null(DTYPE_CHAR,1);
    A4GL_push_null(DTYPE_CHAR,1);
  } else {
    A4GL_push_char(rval_0);
    A4GL_push_char(rval_1);
  }
  return 2;
}




static int ui_vdc_setclipboard(long *objectID_IgnoredAsAlways0,int n) {
int okToProcess=1;
int _ni=1;
struct BINDING _ibind[1]={
    {NULL,0,0,0,0,0,NULL}
};
char *content=NULL;

/* END OF DEFINE SECTION */


  if (n!=1) {
    A4GL_pop_args(n);
    okToProcess=0;
  }

  // Set up input binding for our parameters
  if (okToProcess) {
    content=A4GL_char_pop();
    _ibind[0].ptr=content;
    _ibind[0].size=strlen(content);
  }

  if (okToProcess) {
      A4GL_ui_frontcall("INTERNAL","ui.vdc.setclipboard",_ibind,_ni,NULL,0 );
  }


  // Set up output binding for our parameters
    if (content ) {
        free(content);
    }
  return 0;
}

static int ui_vdc_filebrowser(long *objectID_IgnoredAsAlways0,int n) {
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
char *function=NULL;
char *filename=NULL;

/* END OF DEFINE SECTION */


  if (n!=2) {
    A4GL_pop_args(n);
    okToProcess=0;
  }

  // Set up input binding for our parameters
  if (okToProcess) {

    filename=A4GL_char_pop();
    _ibind[1].ptr=filename;
    _ibind[1].size=strlen(filename);
    function=A4GL_char_pop();
    _ibind[0].ptr=function;
    _ibind[0].size=strlen(function);
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
      A4GL_ui_frontcall("INTERNAL","ui.vdc.filebrowser",_ibind,_ni,_obind,_no );
  }


  // Set up output binding for our parameters
    if (function ) {
        free(function);
    }
    if (filename ) {
        free(filename);
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

static int ui_vdc_openchartwindow(long *objectID_IgnoredAsAlways0,int n) {
int okToProcess=1;
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
char *type=NULL;
char *csvfile=NULL;

/* END OF DEFINE SECTION */


  if (n!=2) {
    A4GL_pop_args(n);
    okToProcess=0;
  }

  // Set up input binding for our parameters
  if (okToProcess) {

    csvfile=A4GL_char_pop();
    _ibind[1].ptr=csvfile;
    _ibind[1].size=strlen(csvfile);
    type=A4GL_char_pop();
    _ibind[0].ptr=type;
    _ibind[0].size=strlen(type);
  }

  // Set up output binding for our parameters
  if (okToProcess) {
    _obind[0].ptr=&rval_0;
    _obind[0].size=4;
    _obind[0].dtype=DTYPE_INT;
  }

  if (okToProcess) {
      A4GL_ui_frontcall("INTERNAL","ui.vdc.openchartwindow",_ibind,_ni,_obind,_no );
  }


  // Set up output binding for our parameters
    if (type ) {
        free(type);
    }
    if (csvfile ) {
        free(csvfile);
    }
  if (!okToProcess) {
    A4GL_push_null(DTYPE_INT,0);
  } else {
    A4GL_push_int(rval_0);
  }
  return 1;
}

static int ui_vdc_systraymessage(long *objectID_IgnoredAsAlways0,int n) {
int okToProcess=1;
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
char *title=NULL;
char *message=NULL;

/* END OF DEFINE SECTION */


  if (n!=2) {
    A4GL_pop_args(n);
    okToProcess=0;
  }

  // Set up input binding for our parameters
  if (okToProcess) {

    message=A4GL_char_pop();
    _ibind[1].ptr=message;
    _ibind[1].size=strlen(message);
    title=A4GL_char_pop();
    _ibind[0].ptr=title;
    _ibind[0].size=strlen(title);
  }

  // Set up output binding for our parameters
  if (okToProcess) {
    _obind[0].ptr=&rval_0;
    _obind[0].size=4;
    _obind[0].dtype=DTYPE_INT;
  }

  if (okToProcess) {
      A4GL_ui_frontcall("INTERNAL","ui.vdc.systraymessage",_ibind,_ni,_obind,_no );
  }


  // Set up output binding for our parameters
    if (title) {
        free(title);
    }
    if (message) {
        free(message);
    }
  if (!okToProcess) {
    A4GL_push_null(DTYPE_INT,0);
  } else {
    A4GL_push_int(rval_0);
  }
  return 1;
}

static int ui_vdc_texteditor(long *objectID_IgnoredAsAlways0,int n) {
int okToProcess=1;
int _ni=3;
struct BINDING _ibind[3]={
    {NULL,0,0,0,0,0,NULL},
    {NULL,0,0,0,0,0,NULL},
    {NULL,0,0,0,0,0,NULL}
};
int _no=1;
struct BINDING _obind[1]={
    {NULL,0,0,0,0,0,NULL}
};
int rval_0;
char *file=NULL;
char *wrap=NULL;
char *digits=NULL;

/* END OF DEFINE SECTION */


  if (n!=3) {
    A4GL_pop_args(n);
    okToProcess=0;
  }

  // Set up input binding for our parameters
  if (okToProcess) {

    digits=A4GL_char_pop();
    _ibind[2].ptr=digits;
    _ibind[2].size=strlen(digits);
    wrap=A4GL_char_pop();
    _ibind[1].ptr=wrap;
    _ibind[1].size=strlen(wrap);
    file=A4GL_char_pop();
    _ibind[0].ptr=file;
    _ibind[0].size=strlen(file);
  }

  // Set up output binding for our parameters
  if (okToProcess) {
    _obind[0].ptr=&rval_0;
    _obind[0].size=4;
    _obind[0].dtype=DTYPE_INT;
  }

  if (okToProcess) {
      A4GL_ui_frontcall("INTERNAL","ui.vdc.texteditor",_ibind,_ni,_obind,_no );
  }


  // Set up output binding for our parameters
    if (file) {
        free(file);
    }
    if (digits) {
        free(digits);
    }
    if (wrap) {
        free(wrap);
    }
  if (!okToProcess) {
    A4GL_push_null(DTYPE_INT,0);
  } else {
    A4GL_push_int(rval_0);
  }
  return 1;
}

static int ui_vdc_playsound(long *objectID_IgnoredAsAlways0,int n) {
int okToProcess=1;
int _ni=1;
struct BINDING _ibind[1]={
    {NULL,0,0,0,0,0,NULL}
};
int _no=1;
struct BINDING _obind[1]={
    {NULL,0,0,0,0,0,NULL}
};
int rval_0;
char *sound=NULL;

/* END OF DEFINE SECTION */


if (n!=1) {
   A4GL_pop_args(n);
   okToProcess=0;
}

if (okToProcess) {
   sound=A4GL_char_pop();
   _ibind[0].ptr=sound;
   _ibind[0].size=strlen(sound);
}

if (okToProcess) {
    _obind[0].ptr=&rval_0;
    _obind[0].size=4;
    _obind[0].dtype=DTYPE_INT;
}

if (okToProcess) {
    A4GL_ui_frontcall("INTERNAL","ui.vdc.playsound",_ibind,_ni,_obind,_no );
}

if (sound) {
    free(sound);
}

if (!okToProcess) {
    A4GL_push_null(DTYPE_INT,0);
} else {
    A4GL_push_int(rval_0);
}
return 1;
}

static int ui_vdc_dial(long *objectID_IgnoredAsAlways0,int n) {
int okToProcess=1;
int _ni=1;
struct BINDING _ibind[1]={
    {NULL,0,0,0,0,0,NULL}
};
int _no=1;
struct BINDING _obind[1]={
    {NULL,0,0,0,0,0,NULL}
};
int rval_0;
char *number=NULL;

/* END OF DEFINE SECTION */


if (n!=1) {
   A4GL_pop_args(n);
   okToProcess=0;
}

if (okToProcess) {
   number=A4GL_char_pop();
   _ibind[0].ptr=number;
   _ibind[0].size=strlen(number);
}

if (okToProcess) {
    _obind[0].ptr=&rval_0;
    _obind[0].size=4;
    _obind[0].dtype=DTYPE_INT;
}

if (okToProcess) {
    A4GL_ui_frontcall("INTERNAL","ui.vdc.dial",_ibind,_ni,_obind,_no );
}

if (number) {
    free(number);
}

if (!okToProcess) {
    A4GL_push_null(DTYPE_INT,0);
} else {
    A4GL_push_int(rval_0);
}
return 1;
}

static int ui_vdc_version(long *objectID_IgnoredAsAlways0,int n) {
int okToProcess=1;
int _no=1;
struct BINDING _obind[1]={
    {NULL,0,0,0,0,0,NULL},
};
char rval_0[512];

if (okToProcess) {
   _obind[0].ptr=&rval_0;
   _obind[0].size=512;
}

if (okToProcess) {

   A4GL_ui_frontcall("INTERNAL","ui.vdc.version",NULL,0,_obind,_no );
}


if (!okToProcess) {
   A4GL_push_null(DTYPE_CHAR,1);
} else {
   A4GL_push_char(rval_0);
}
return 1;
}

static int ui_vdc_getopenwithprogram(long *objectID_IgnoredAsAlways0,int n) {
int okToProcess=1;
int _ni=1;
struct BINDING _ibind[1]={
   {NULL,0,0,0,0,0,NULL}
};

int _no=1;
struct BINDING _obind[1]={
   {NULL,0,0,0,0,0,NULL},
};
char rval_0[512];
char *number=NULL;

if (okToProcess) {
   number=A4GL_char_pop();
   _ibind[0].ptr=number;
   _ibind[0].size=strlen(number);
}

if (okToProcess) {
   _obind[0].ptr=&rval_0;
   _obind[0].size=512;
}

if (okToProcess) {
   A4GL_ui_frontcall("INTERNAL","ui.vdc.getopenwithprogram",_ibind,_ni,_obind,_no );
}

if (number) {
   free(number);
}


if (!okToProcess) {
   A4GL_push_null(DTYPE_CHAR,1);
} else {
   A4GL_push_char(rval_0);
}
return 1;
}

static int ui_vdc_ignoreofficeversion(long *objectID_IgnoredAsAlways0,int n) {
int okToProcess=1;
int _ni=1;
struct BINDING _ibind[1]={
    {NULL,0,0,0,0,0,NULL}
};
int _no=1;
struct BINDING _obind[1]={
    {NULL,0,0,0,0,0,NULL}
};
char rval_0[512];
char *filetype=NULL;

/* END OF DEFINE SECTION */


  if (n!=1) {
    A4GL_pop_args(n);
    okToProcess=0;
  }

  // Set up input binding for our parameters
  if (okToProcess) {
    filetype=A4GL_char_pop();
    _ibind[0].ptr=filetype;
    _ibind[0].size=strlen(filetype);
  }

  // Set up output binding for our parameters
  if (okToProcess) {
    _obind[0].ptr=&rval_0;
    _obind[0].size=512;
  }

  if (okToProcess) {
      A4GL_ui_frontcall("INTERNAL","ui.vdc.ignoreofficeversion",_ibind,_ni,_obind,_no );
  }


  // Set up output binding for our parameters
    if (filetype ) {
        free(filetype);
    }
  if (!okToProcess) {
    A4GL_push_null(DTYPE_CHAR,1);
  } else {
    A4GL_push_char(rval_0);
  }
  return 1;
}


void add_ui_vdc_support(void) {
A4GL_add_object_type("ui.vdc");
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.vdc.action", (void *)  ui_vdc_action);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.vdc.repgen", (void *)  ui_vdc_repgen);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.vdc.odftopdf", (void *)  ui_vdc_odftopdf);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.vdc.checkodffile", (void *)  ui_vdc_checkodffile);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.vdc.md5hashfile", (void *)  ui_vdc_md5hashfile);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.vdc.printpdf", (void *)  ui_vdc_printpdf);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.vdc.execute", (void *)  ui_vdc_execute);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.vdc.getstdofficeprog", (void *)  ui_vdc_getstdofficeprog);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.vdc.get_last_sort", (void *)  ui_vdc_get_last_sort);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.vdc.settingsonserver", (void *)  ui_vdc_settingonserver);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.vdc.openeditor", (void *)  ui_vdc_openeditor);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.vdc.getdevice", (void *)  ui_vdc_getdevice);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.vdc.setclipboard", (void *)  ui_vdc_setclipboard);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.vdc.filebrowser", (void *)  ui_vdc_filebrowser);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.vdc.openchartwindow", (void *)  ui_vdc_openchartwindow);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.vdc.systraymessage", (void *)  ui_vdc_systraymessage);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.vdc.texteditor", (void *)  ui_vdc_texteditor);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.vdc.playsound", (void *)  ui_vdc_playsound);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.vdc.dial", (void *)  ui_vdc_dial);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.vdc.version", (void *)  ui_vdc_version);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.vdc.getopenwithprogram", (void *)  ui_vdc_getopenwithprogram);
  A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.vdc.ignoreofficeversion", (void *)  ui_vdc_ignoreofficeversion);

}
