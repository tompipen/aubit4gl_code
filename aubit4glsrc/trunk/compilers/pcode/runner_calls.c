#include "npcode.h"
#include "npcode_defs.h"
/* void print_module(void) ; */
module this_module;
static int chk_func_sigs(void) ;

char *get_string(int a) {
        return this_module.string_table.string_table_val[a].s;
}



int open_and_run(char *lv_progname) {
	int a;
	int ok=1;
	a=process_xdr('I',&this_module,lv_progname);
	
	if (a) {
		A4GL_debug("Opened OK\n");
	} else {
		printf("Failed to open\n");
		exit(1);
	}
	
	if (chk_func_sigs()) {
		run_module();
	} else {
		ok=0;
	}
return ok;
}


// Here we need to define our call functions
// It'll probably cause **lots** of warnings!
//

int printfmt(char *s,int a) {
printf("s=%p a=%d\n",s,a);
printf("s=%s\n Here goes :\n",s);
printf(s,a);
printf("\n\n");
return 0;
}



struct call_funcs {
	void *ptr;
	char *name;
	char *signiature;
};


#include "calls.h"



long handle_44(void *end_func,struct param *p) {
int params[1];
long rval;
long (*func)(long);
func=end_func;
evaluate_param(&p->param_u.p_list->list.list_val[0],&params[0]);
rval=func(params[0]);
return rval;
}


long handle_4(void *end_func,struct param *p) {
long rval;
long (*func)(void);
func=end_func;
rval=func();
return rval;
}



long handle_444(void *end_func,struct param *p) {
int params[2];
long rval;
long (*func)(long,long);
func=end_func;
evaluate_param(&p->param_u.p_list->list.list_val[0],&params[0]);
evaluate_param(&p->param_u.p_list->list.list_val[1],&params[1]);
rval=func(params[0],params[1]);
return rval;
}



long handle_4444(void *end_func,struct param *p) { 
int params[3];
long rval;
long (*func)(long,long,long);
func=end_func;
evaluate_param(&p->param_u.p_list->list.list_val[0],&params[0]);
evaluate_param(&p->param_u.p_list->list.list_val[1],&params[1]);
evaluate_param(&p->param_u.p_list->list.list_val[2],&params[2]);
rval=func(params[0],params[1],params[2]);
return rval;


}

long handle_444444(void *end_func,struct param *p) {
int params[5];
long rval;
long (*func)(long,long,long,long,long);
func=end_func;
evaluate_param(&p->param_u.p_list->list.list_val[0],&params[0]);
evaluate_param(&p->param_u.p_list->list.list_val[1],&params[1]);
evaluate_param(&p->param_u.p_list->list.list_val[2],&params[2]);
evaluate_param(&p->param_u.p_list->list.list_val[3],&params[3]);
evaluate_param(&p->param_u.p_list->list.list_val[4],&params[4]);
rval=func(params[0],params[1],params[2],params[3],params[4]);
return rval;
}


long handle_44444444444(void *end_func,struct param *p) { 
int params[10];
long rval;
long (*func)(long,long,long,long,long,long,long,long,long,long);
func=end_func;
evaluate_param(&p->param_u.p_list->list.list_val[0],&params[0]);
evaluate_param(&p->param_u.p_list->list.list_val[1],&params[1]);
evaluate_param(&p->param_u.p_list->list.list_val[2],&params[2]);
evaluate_param(&p->param_u.p_list->list.list_val[3],&params[3]);
evaluate_param(&p->param_u.p_list->list.list_val[4],&params[4]);
evaluate_param(&p->param_u.p_list->list.list_val[5],&params[5]);
evaluate_param(&p->param_u.p_list->list.list_val[6],&params[6]);
evaluate_param(&p->param_u.p_list->list.list_val[7],&params[7]);
evaluate_param(&p->param_u.p_list->list.list_val[8],&params[8]);
evaluate_param(&p->param_u.p_list->list.list_val[9],&params[9]);
rval=func(
params[0],params[1],params[2],params[3],params[4],
params[5],params[6],params[7],params[8],params[9]
);
return rval;
}


long handle_0(void *end_func,struct param *p) { 
void (*func)(void);
func=end_func;
func();
return 0;
}

long handle_014(void *end_func,struct param *p) {
printf("handle_014 not implemented\n");
return 0;
}

long handle_02(void *end_func,struct param *p) {
short params[1];
int p1;
void (*func)(long);
func=end_func;
evaluate_param(&p->param_u.p_list->list.list_val[0],&p1);
params[0]=p1;
func(params[0]);
return 0;
}

long handle_04(void *end_func,struct param *p) {
int params[1];
void (*func)(long);
func=end_func;
evaluate_param(&p->param_u.p_list->list.list_val[0],&params[0]);
func(params[0]);
return 0;

}

long handle_044(void *end_func,struct param *p) {
int params[2];
void (*func)(long,long);
func=end_func;
evaluate_param(&p->param_u.p_list->list.list_val[0],&params[0]);
evaluate_param(&p->param_u.p_list->list.list_val[1],&params[1]);
func(params[0],params[1]);
return 0;
}

long handle_0444(void *end_func,struct param *p) {
int params[3];
void (*func)(long,long,long);
func=end_func;
evaluate_param(&p->param_u.p_list->list.list_val[0],&params[0]);
evaluate_param(&p->param_u.p_list->list.list_val[1],&params[1]);
evaluate_param(&p->param_u.p_list->list.list_val[2],&params[2]);
func(params[0],params[1],params[2]);
return 0;
}

long    handle_0444444(void *end_func,struct param *p) {
int params[6];
void (*func)(long,long,long,long,long,long);
func=end_func;
evaluate_param(&p->param_u.p_list->list.list_val[0],&params[0]);
evaluate_param(&p->param_u.p_list->list.list_val[1],&params[1]);
evaluate_param(&p->param_u.p_list->list.list_val[2],&params[2]);
evaluate_param(&p->param_u.p_list->list.list_val[3],&params[3]);
evaluate_param(&p->param_u.p_list->list.list_val[4],&params[4]);
evaluate_param(&p->param_u.p_list->list.list_val[5],&params[5]);
func(
params[0],params[1],params[2],
params[3],params[4],params[5]
);

return 0;
}

long handle_044V(void *end_func,struct param *p,struct param *r) {
printf("handle_044V not implemented\n");
exit(0);
return 0;
}


struct func_sigs {
	void *ptr;
	char *name;
};

struct func_sigs function_signiatures[]={
	{&handle_4,"4"},
	{&handle_44,"44"},
	{&handle_444,"444"},
	{&handle_4444,"4444"},
	{&handle_444444,"444444"},
	{&handle_44444444444,"44444444444"},
	{&handle_0,"0"},
	{&handle_014,"014"},
	{&handle_02,"02"},
	{&handle_04,"04"},
	{&handle_044,"044"},
	{&handle_0444,"0444"},
	{&handle_0444444,"0444444"},
	{&handle_044V,"044V"},
{0,0}
};



static void *find_sig(char *s) {
int a;
void *ptr;
if (s==0) {
	printf("Find sig passed null\n");
	return 0;
}
for (a=0;function_signiatures[a].ptr;a++) {
	if (strcmp(s,function_signiatures[a].name)==0) return function_signiatures[a].ptr;
}
return 0;
}

static void *find_function_ptr(char *s) {
	int a;
	for (a=0;system_funcs[a].ptr;a++) {
		if (strcmp(s,system_funcs[a].name)==0) return system_funcs[a].ptr;
	}
	return 0;
}

static char *find_function_sig(char *s) {
	int a;
	for (a=0;system_funcs[a].ptr;a++) {
		if (strcmp(s,system_funcs[a].name)==0) return system_funcs[a].signiature;
	}
	return 0;
}



long call_c_function(char *s,struct param *p,long *r) {
struct param_list *list;
char *sig;
long pc;
long (*ptr)(void*end_func,struct param *p);
void *ptr_function;
long x;

if (p) {
	if (p->param_type!=PARAM_TYPE_LIST) {
		printf("Was expecting a list...\n");
		exit(20);
	}

	list=p->param_u.p_list;
	A4GL_debug("Have %d values...",list->list.list_len);
} else {
	list=0;
}


sig=find_function_sig(s);

if (sig==0) {
int a;
static char buff[256];
int ok=1;
	sprintf(buff,"4");
	//printf("Sig not found - try to guess.. \n");
	if (list) {
	for (a=0;a<list->list.list_len;a++) {

		//printf("Param %d - %d\n",a,list->list.list_val[a]);
		switch (list->list.list_val[a].param_type) {
			case PARAM_TYPE_LITERAL_CHAR: strcat(buff,"1");break;
			case PARAM_TYPE_LITERAL_STRING: strcat(buff,"4");break;
			case PARAM_TYPE_LITERAL_INT: strcat(buff,"4");break;
			case PARAM_TYPE_USE_VAR: strcat(buff,"4");break; // A guess...
			default: ok=0; printf("Can't figure it out...%d\n",list->list.list_val[a].param_type); exit(2);
		}

	}
	} 
		
	if (ok) {sig=buff;}
	else printf("Darn..\n");
}


if (sig==0) {
	printf("C Function not found... %s\n",s);
	
	return 0;
}
A4GL_debug("sig=%s\n",sig);
fprintf(stderr,"Calling C function : %s\n",s);
if (list) {
if (strlen(sig)-1!=list->list.list_len) {
	printf("Mismatch in parameters to function - expecting %d got %d\n",strlen(sig)-1,list->list.list_len);
	exit(21);
} 
} else {
if (strlen(sig)-1!=0) {
	printf("Mismatch in parameters to function - expecting %d got %d\n",strlen(sig)-1,list->list.list_len);
	exit(21);
}
}

ptr_function=find_function_ptr(s);

ptr=find_sig(sig);
if (!ptr) {
	printf("Can't find signiature...\n");
	exit(1);
	
}
if (ptr_function==0) {
	printf("Function was not declared...%s\n",s);
	exit(1);
}
x=ptr(ptr_function,p);
*r=x;

return x;
}



static int chk_func_sigs() {
int a;
int ok=1;
for (a=0;system_funcs[a].ptr;a++) {
	if (system_funcs[a].signiature==0) continue;
	if (!find_sig(system_funcs[a].signiature)) {
		//printf("Internal Error : Handler function for sig : %s not found (needed for %s)\n",system_funcs[a].signiature,system_funcs[a].name);
		if (system_funcs[a].signiature[0]=='0') {
			printf("void ");
		}
		if (system_funcs[a].signiature[0]=='2') {
			printf("short ");
		}
		if (system_funcs[a].signiature[0]=='4') {
			printf("long ");
		}
		if (system_funcs[a].signiature[0]=='8') {
			printf("double ");
		}
		printf("handle_%s(struct param *p) {  }\n",system_funcs[a].signiature);
		ok=0;
	}
}
return ok;
}


