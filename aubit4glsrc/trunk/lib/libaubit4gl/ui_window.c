
#include "a4gl_libaubit4gl_int.h"

static int new_ui_form(char *formID) ;
struct ui_window_data {
	char windowID[33];
};

struct ui_form_data {
	char formID[33];
};


static int ui_window_getcurrent(long *objectID, int nparam) {
        struct sObject *obj;
        struct ui_window_data *data;
	struct BINDING obind[]= {
   		{NULL,0,32,0,0,0}
   	};



        obj=new_object("ui.window");
        if (obj==NULL) {
                A4GL_push_objectID(0);
                return 1;
        }

        data=malloc(sizeof(struct ui_window_data));

        strcpy(data->windowID,"");
   	obind[0].ptr=&data->windowID;
	A4GL_ui_frontcall("INTERNAL","ui.window.getcurrent", NULL,0,obind,1);
        obj->objData=data;
        A4GL_push_objectID(obj->objHeapId);


        return 1;

}

static int ui_window_repgen(long *objectID, int nparam) {
        //struct sObject *obj;
        //struct ui_window_data *data;
	char odfdatei[256];
	char seddatei[256];
	int rval;
	struct BINDING ibind[]= {
   		{NULL,0,256,0,0,0},
   		{NULL,0,256,0,0,0}
   	};

	struct BINDING obind[]= {
   		{NULL,2,0,0,0,0}
   	};


        /*obj=new_object("ui.window");
        if (obj==NULL) {
                A4GL_push_objectID(0);
                return 1;
        }

        data=malloc(sizeof(struct ui_window_data));
	*/

        //strcpy(data->windowID,"");
	A4GL_pop_char(seddatei,255);
	A4GL_pop_char(odfdatei,255);
	A4GL_trim(seddatei);
	A4GL_trim(odfdatei);
   	ibind[0].ptr=odfdatei;
   	ibind[1].ptr=seddatei;
	obind[0].ptr=&rval;
	A4GL_ui_frontcall("INTERNAL","ui.window.repgen", ibind,2,obind,1);
        //obj->objData=data;
        A4GL_push_int(rval);
        return 1;
}

static int ui_window_getform(long *objectID, int nParam) {
        struct ui_window_data *data;
        struct sObject *ptr;
	char formID[33];
        struct BINDING ibind[]= {
                {NULL,0,32,0,0,0}
        };
	struct BINDING obind[]= {
   		{NULL,0,32,0,0,0}
   	};


        if (!ensureObject("ui.window",*objectID,&ptr)) {
                A4GL_exitwith("Not an object of type ui.window - or not initialized");
                return 0;
        }

        if (nParam!=0) {
                A4GL_exitwith("expects 0 parameter");
                return 0;
        }

        data=ptr->objData;
   	ibind[0].ptr=&data->windowID;
   	obind[0].ptr=&formID;
	strcpy(formID,"");
	A4GL_ui_frontcall("INTERNAL","ui.window.getform", ibind,1,obind,1);
	if (strlen(formID)) {
		return new_ui_form(formID);
	}
        return 0;
}



static int new_ui_form(char *formID) {
        struct sObject *obj;
        struct ui_form_data *data;

        obj=new_object("ui.form");
        if (obj==NULL) {
                A4GL_push_objectID(0);
                return 1;
        }

        data=malloc(sizeof(struct ui_form_data));

        strcpy(data->formID,formID);
        obj->objData=data;
        A4GL_push_objectID(obj->objHeapId);
        return 1;

}



static int ui_form_setelementhidden(long *objectID, int nParam) {
        struct ui_form_data *data;
        struct sObject *ptr;
	long vis;
	char *field;
        struct BINDING ibind[]= {
                {NULL,0,32,0,0,0},
                {NULL,0,32,0,0,0},
                {NULL,2,0,0,0,0}
        };


        if (!ensureObject("ui.form",*objectID,&ptr)) {
                A4GL_exitwith("Not an object of type ui.form - or not initialized");
                return 0;
        }

        if (nParam!=2) {
                A4GL_exitwith("expects 1 parameter");
                return 0;
        }
	vis=A4GL_pop_int();
	field=A4GL_char_pop();
	A4GL_trim(field);
        data=ptr->objData;
	ibind[0].ptr=&data->formID;
	ibind[1].ptr=field;
	ibind[2].ptr=&vis;
	
	A4GL_ui_frontcall("INTERNAL","ui.form.setelementhidden", ibind,3,NULL,0);

	free(field);
	return 0;
}


static int ui_form_setattributes(long *objectID, int n) {
int okToProcess=1;
int _ni=3;
struct BINDING _ibind[3]={
    {NULL,0,0,0,0,0,NULL},
    {NULL,0,0,0,0,0,NULL},
    {NULL,0,0,0,0,0,NULL}
};
char *fieldname=NULL;
char *attributename=NULL;
char *value=NULL;

/* END OF DEFINE SECTION */


  if (n!=3) {
    A4GL_pop_args(n);
    okToProcess=0;
  }

  // Set up input binding for our parameters
  if (okToProcess) {

    value=A4GL_char_pop();
    _ibind[2].ptr=value;
    _ibind[2].size=strlen(value);

    attributename=A4GL_char_pop();
    _ibind[1].ptr=attributename;
    _ibind[1].size=strlen(attributename);

    fieldname=A4GL_char_pop();
    _ibind[0].ptr=fieldname;
    _ibind[0].size=strlen(fieldname);
  }

  if (okToProcess) {
      A4GL_ui_frontcall("INTERNAL","ui.form.setattributes",_ibind,_ni,NULL,0 );
  }


  // Set up output binding for our parameters
    if (fieldname ) {
        free(fieldname);
    }
    if (attributename ) {
        free(attributename);
    }
    if (value ) {
        free(value);
    }
  return 0;
}

static int ui_form_setfieldhidden(long *objectID, int nParam) {
        struct ui_form_data *data;
        struct sObject *ptr;
	long vis;
	char *field;
        struct BINDING ibind[]= {
                {NULL,0,32,0,0,0},
                {NULL,0,32,0,0,0},
                {NULL,2,0,0,0,0}
        };


        if (!ensureObject("ui.form",*objectID,&ptr)) {
                A4GL_exitwith("Not an object of type ui.form - or not initialized");
                return 0;
        }

        if (nParam!=2) {
                A4GL_exitwith("expects 1 parameter");
                return 0;
        }
	vis=A4GL_pop_int();
	field=A4GL_char_pop();
	A4GL_trim(field);
        data=ptr->objData;
	ibind[0].ptr=&data->formID;
	ibind[1].ptr=field;
	ibind[2].ptr=&vis;
	
	A4GL_ui_frontcall("INTERNAL","ui.form.setfieldhidden", ibind,3,NULL,0);
	free(field);

	return 0;
}


static int ui_window_settext(long *objectID, int nParam) {
        struct ui_window_data *data;
	char *text;
        struct sObject *ptr;
        struct BINDING ibind[]= {
                {NULL,0,0,0,0,0},
                {NULL,0,0,0,0,0}
        };


	

        if (!ensureObject("ui.window",*objectID,&ptr)) {
                A4GL_exitwith("Not an object of type ui.window - or not initialized");
                return 0;
        }

        if (nParam!=1) {
                A4GL_exitwith("expects 1 parameter");
                return 0;
        }

        text=A4GL_char_pop();
        A4GL_trim(text);

        data=ptr->objData;

        ibind[0].ptr=data->windowID;
        ibind[0].size=strlen(data->windowID);
        ibind[1].size=strlen(text);
        ibind[1].ptr=text;
	
	A4GL_ui_frontcall("INTERNAL","ui.window.settext", ibind,2,NULL,0);
	free(text);

	return 0;
}

static int ui_form_setpagetitle(long *objectID_IgnoredAsAlways0,int n) {
int okToProcess=1;
int _ni=2;
struct BINDING _ibind[2]={
    {NULL,0,0,0,0,0,NULL},
    {NULL,0,0,0,0,0,NULL}
};
char *pagename=NULL;
char *title=NULL;

/* END OF DEFINE SECTION */


  if (n!=2) {
    A4GL_pop_args(n);
    okToProcess=0;
  }

  // Set up input binding for our parameters
  if (okToProcess) {

    title=A4GL_char_pop();
    _ibind[1].ptr=title;
    _ibind[1].size=strlen(title);
    pagename=A4GL_char_pop();
    _ibind[0].ptr=pagename;
    _ibind[0].size=strlen(pagename);
  }

  if (okToProcess) {
      A4GL_ui_frontcall("INTERNAL","ui.form.setpagetitle",_ibind,_ni,NULL,0 );
  }


  // Set up output binding for our parameters
    if (pagename ) {
        free(pagename);
    }
    if (title ) {
        free(title);
    }
  return 0;
}


void add_ui_window_support(void) {
	A4GL_add_object_type("ui.window");
	A4GL_add_object_type("ui.form");

	A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.window.getcurrent", (void *) ui_window_getcurrent);
	A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.window.settext", (void *) ui_window_settext);
	A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.window.getform", (void *) ui_window_getform);
	A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.window.repgen", (void *) ui_window_repgen);
	A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.form.setelementhidden", (void *) ui_form_setelementhidden);
	A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.form.setfieldhidden", (void *) ui_form_setfieldhidden);
	A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.form.setattributes", (void *) ui_form_setattributes);
        A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.form.setpagetitle", (void *)  ui_form_setpagetitle);
}
