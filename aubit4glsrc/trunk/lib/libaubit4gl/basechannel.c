#include "a4gl_libaubit4gl_int.h"

struct channel_data {
	char filename[512];
	char delimiter[2];
	char dir;
	FILE *handle;
};


static int base_channel_create(long *objectID, int nparam) {
	struct sObject *obj;
	struct channel_data *data;

	obj=new_object("base.channel");
	if (obj==NULL) {
		A4GL_push_objectID(0);
		return 1;
	}

	data=malloc(sizeof(struct channel_data));
	strcpy(data->filename,"");
	strcpy(data->delimiter,"");
	data->dir=0;
	data->handle=NULL;
	obj->objData=data;

	A4GL_push_objectID(obj->objHeapId);
	return 1;
}

static int base_channel_setdelimiter(long *objectID, int nParam) {
	char *delim;
	struct channel_data *data;
	struct sObject *ptr;

	if (!ensureObject("base.channel",*objectID,&ptr)) {
		A4GL_exitwith("Not an object of type base.channel - or not initialized");
		return 0;
	}
	if (nParam!=1) {
		A4GL_exitwith("expects 1 parameter");
		return 0;
	}
	data=ptr->objData;
	delim=A4GL_char_pop();
	strncpy(data->delimiter,delim,1);
	data->delimiter[1]=0;

	return 0;
}


static int base_channel_open(long *objectID, int nParam) {
	char *dir;
	char *filename;
	struct channel_data *data;
	struct sObject *ptr;

	if (!ensureObject("base.channel",*objectID, &ptr)) {
		A4GL_exitwith("Not an object of type base.channel - or not initialized");
		return 0;
	}

	if (nParam!=2) {
			A4GL_exitwith("Expects 2 parameters");
			return 0;
	}

	data=ptr->objData;
	dir=A4GL_char_pop();
	filename=A4GL_char_pop();
	A4GL_trim(filename);

	strcpy(data->delimiter," ");
	data->dir=dir[0];
	strcpy(data->filename,filename);
	data->handle=fopen(data->filename,dir);

A4GL_debug("opened %p",data->handle);
	free(dir);
	free(filename);

	return 0;
}

static int base_channel_read (long *objectID,  int nParam) {
        struct channel_data *data=NULL;
	struct BINDING *obind=NULL;
	struct sObject *ptr=NULL;
	int no=0;
	char buff[20000];
	char *ptrBuff=NULL;

	if (!ensureObject("base.channel",*objectID,&ptr)) {
                A4GL_exitwith("Not an object of type base.channel - or not initialized");
                return 0;
        }
	data=ptr->objData;
	if (data->handle==0) {
		A4GL_exitwith("File is not open");
		return 0;
	}
	if (nParam!=1) {
		A4GL_exitwith("Expected 1 parameter");
		return 0;
	}


	if (!A4GL_pop_binding_from_stack(&obind,&no,'o')) { // Its an output binding when reading...
        	//A4GL_push_int(0);
		  A4GL_exitwith("Parameter is not a reference");
        	return 0;
	}

	A4GL_debug("Reading from %p",data->handle);

        if (!fgets(buff,19998,data->handle)) {
                int a;
                for (a=0;a<no;a++) {
                                A4GL_setnull(obind[a].dtype,obind[a].ptr,obind[a].size);
                 }
                if (obind) free(obind);
                A4GL_push_int(0);
                return 1;

        }
        buff[19999]=0;

        if (!A4GL_isno(acl_getenv("KEEPNLONREAD"))) {
                int x;
                x=strlen(buff);
                if (buff[x-1]=='\n' || buff[x-1]=='\r') {buff[x-1]=0; x--;}
                if (buff[x-1]=='\n' || buff[x-1]=='\r') {buff[x-1]=0; x--;}
        }

        if (no==1 ) {
                A4GL_push_char(buff);
                A4GL_pop_param(obind[0].ptr,obind[0].dtype, obind[0].size); // Its all into one variable - put the whole line there
        } else {
                int a;
                ptrBuff=buff;

                for (a=0;a<no;a++) {
                        A4GL_setnull(obind[a].dtype,obind[a].ptr,obind[a].size);
                }

                for (a=0;a<no;a++) {
                        char *optr;
                        optr=ptrBuff;
                        ptrBuff=strchr(optr,data->delimiter[0]);
                        if (ptrBuff==0) {
                                A4GL_push_char(optr);
                                A4GL_pop_param(obind[a].ptr,obind[a].dtype,obind[a].size);
                                break;
                        } else {
                                *ptrBuff=0;
                                A4GL_push_char(optr);
                                A4GL_pop_param(obind[a].ptr,obind[a].dtype,obind[a].size);
                                ptrBuff++;
                        }
                }

        }


        if (obind) free(obind);
        A4GL_push_int(1);
        return 1;
}


static int base_channel_write (long *objectID, int nParam) {
        struct channel_data *data;
	struct BINDING *ibind=0;
	int ni;
	struct sObject *ptr;
	int a;
	int d1;
	int s1;
	void *ptr1;
	A4GL_get_top_of_stack (1, &d1, &s1, (void *) &ptr1);

// Setup Object stuff..
	if (!ensureObject("base.channel",*objectID,&ptr)) {
                A4GL_exitwith("Not an object of type base.channel - or not initialized");
                return 0;
        }
	data=ptr->objData;
	if (data->handle==0) {
		A4GL_exitwith("File is not open");
		return 0;
	}
	if (nParam!=1) {
		A4GL_exitwith("Expected 1 parameter");
	}
	
	if ((d1&DTYPE_MASK)==DTYPE_BINDING) {
	
// Do the actual write...
	if (!A4GL_pop_binding_from_stack(&ibind,&ni,'o')) { // Its an output binding when reading...
        	return 0;
	}

 	for (a=0;a<ni;a++) {
	char *ptrBuff;
                if (a>=1) fprintf(data->handle,"%c",data->delimiter[0]);
                A4GL_push_param(ibind[a].ptr,ibind[a].dtype+ENCODE_SIZE(ibind[a].size));
                ptrBuff=A4GL_char_pop();
                        A4GL_trim(ptrBuff);
                	fprintf(data->handle,"%s",ptrBuff);
                        free(ptrBuff);
        }
	} else {
		ptr1=A4GL_char_pop();
                fprintf(data->handle,"%s",(char *)ptr1);
		free(ptr1);
		
	}
        fprintf(data->handle,"\n");
        if (ibind) free(ibind);

	return 0;
}


static void base_channel_destructor(long *objectID) {
	struct sObject *ptr=0;
        struct channel_data *data;
	if (!ensureObject("base.channel",*objectID,&ptr)) {
                return ;
        }
	if (ptr) {
		data=ptr->objData;
		if (data) {
			if (data->handle) {
#ifdef DEBUG
				A4GL_debug("Was open - closing");
#endif
				fclose(data->handle);
			} else {
#ifdef DEBUG
				A4GL_debug("Wasn't open - dont need to close");
#endif
			}
		}
	}
}


static int base_channel_close (long *objectID, int nParam) {
        struct channel_data *data;
	struct sObject *ptr;

	if (!ensureObject("base.channel",*objectID,&ptr)) {
                A4GL_exitwith("Not an object of type base.channel - or not initialized");
                return 0;
        }

	data=ptr->objData;

	if (data->handle==0) {
		A4GL_exitwith("File is not open");
		return 0;
	}

	fclose(data->handle);
	data->handle=NULL;
	return 0;
}

void add_base_channel_support(void) {

	A4GL_add_object_type("base.channel");

	A4GL_add_datatype_function_i (DTYPE_OBJECT, ":base.channel.create", (void *) base_channel_create);
	A4GL_add_datatype_function_i (DTYPE_OBJECT, ":base.channel.openfile", (void *) base_channel_open);
	A4GL_add_datatype_function_i (DTYPE_OBJECT, ":base.channel.setdelimiter", (void *) base_channel_setdelimiter);
	A4GL_add_datatype_function_i (DTYPE_OBJECT, ":base.channel.read", (void *) base_channel_read);
	A4GL_add_datatype_function_i (DTYPE_OBJECT, ":base.channel.write", (void *) base_channel_write);
	A4GL_add_datatype_function_i (DTYPE_OBJECT, ":base.channel.close", (void *) base_channel_close);
	A4GL_add_datatype_function_i (DTYPE_OBJECT, ":base.channel.~", (void *) base_channel_destructor);
}
