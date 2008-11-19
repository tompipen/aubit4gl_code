#if (defined(__CYGWIN__)) || defined(__MINGW32__)
	/* missing from rpcgen generated .h on CygWin: */
	#define bool_t int
	#define u_int unsigned int
#endif

#ifdef RPCGEN_HEADERS
	#include "npcode.h"
#else
	#include "npcode.xs.h"
#endif

#include "npcode_defs.h"

#include <stdio.h>
#include <string.h>

#if defined(__hpux__) //HP-UX UNIX OS
	#define USE_SHL 1
#endif

#if USE_SHL
	#include <dl.h>
#endif

//this 3 should be determined by configure and defined in a4gl_incl_config.h/.in
//if not, assume defaults
#ifndef CAN_DLOPEN_SELF
	#define CAN_DLOPEN_SELF 1
#endif

#ifndef HAVE_DLFCN_H
	#define HAVE_DLFCN_H 1
#endif

#ifndef NEED_DL_UNDERSCORE
	#define NEED_DL_UNDERSCORE 0
#endif	


#if HAVE_DLFCN_H
	#include <dlfcn.h>
#endif

#ifdef RTLD_GLOBAL
#  define LT_DLGLOBAL           RTLD_GLOBAL
#else
#  ifdef DL_GLOBAL
#    define LT_DLGLOBAL         DL_GLOBAL
#  else
#    define LT_DLGLOBAL         0
#  endif
#endif


/* We may have to define LT_DLLAZY_OR_NOW in the command line if we
   find out it does not work in some platform. */
#ifndef LT_DLLAZY_OR_NOW
#  ifdef RTLD_LAZY
#    define LT_DLLAZY_OR_NOW            RTLD_LAZY
#  else
#    ifdef DL_LAZY
#      define LT_DLLAZY_OR_NOW          DL_LAZY
#    else
#      ifdef RTLD_NOW
#        define LT_DLLAZY_OR_NOW        RTLD_NOW
#      else
#        ifdef DL_NOW
#          define LT_DLLAZY_OR_NOW      DL_NOW
#        else
#          define LT_DLLAZY_OR_NOW      0
#        endif
#      endif
#    endif
#  endif




/* void print_module(void) ; */
module this_module;
module *this_module_ptr;
static int chk_func_sigs (void);
extern FILE *logfile;

void nullfunc();
static void * find_by_dlself(char *s);

char *
get_string (int a)
{
  return this_module_ptr->string_table.string_table_val[a].s;
}



void log_err(char *s) {
FILE *f;
f=fopen("/tmp/pcode.run.errs","a");
if (f) {
	fprintf(f,"%s\n",s);
	fclose(f);
}

}


int
open_and_run (char *lv_progname)
{
  int a;
  int ok = 1;

  this_module_ptr=&this_module;
  a = process_xdr ('I', this_module_ptr, lv_progname);

  
  if (a)
    {
      A4GL_debug ("Opened OK\n");
    }
  else
    {
      fprintf (stderr,"Failed to open\n");
      exit (1);
    }

  if (chk_func_sigs ())
    {
      run_module ();
    }
  else
    {
      ok = 0;
    }
  return ok;
}


struct call_funcs
{
  void *ptr;
  char *name;
  char *signiature;
};


#include "calls.h"


long
handle_44 (void *end_func, struct param *p)
{
  long params[1];
  long rval;
  long (*func) (long);
  func = end_func;
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[0], &params[0]);
  rval = func (params[0]);
  return rval;
}

void
handle_014 (void *end_func, struct param *p)
{
  long param1_i;
  char param1;
  long param2;
  void (*func) (char,long);
  func = end_func;
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[0], &param1_i);
  param1=(char )param1_i;
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[0], &param2);
  func (param1,param2);
}


long
handle_4 (void *end_func, struct param *p)
{
  long rval;
  long (*func) (void);
  func = end_func;
  rval = func ();
  return rval;
}



long
handle_444 (void *end_func, struct param *p)
{
  long params[2];
  long rval;
  long (*func) (long, long);
  func = end_func;
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[0], &params[0]);
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[1], &params[1]);
  rval = func (params[0], params[1]);
  return rval;
}



long
handle_4444 (void *end_func, struct param *p)
{
  long params[3];
  long rval;
  long (*func) (long, long, long);
  func = end_func;
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[0], &params[0]);
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[1], &params[1]);
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[2], &params[2]);
  rval = func (params[0], params[1], params[2]);
  return rval;


}

long
handle_44444 (void *end_func, struct param *p)
{
  long params[4];
  long rval;
  long (*func) (long, long, long,long);
  func = end_func;
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[0], &params[0]);
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[1], &params[1]);
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[2], &params[2]);
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[3], &params[3]);
  rval = func (params[0], params[1], params[2],params[3]);
  return rval;


}

long
handle_444444 (void *end_func, struct param *p)
{
  long params[5];
  long rval;
  long (*func) (long, long, long, long, long);
  func = end_func;
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[0], &params[0]);
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[1], &params[1]);
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[2], &params[2]);
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[3], &params[3]);
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[4], &params[4]);
  rval = func (params[0], params[1], params[2], params[3], params[4]);
  return rval;
}

long
handle_444444444 (void *end_func, struct param *p)
{
  long params[9];
  long rval;
  long (*func) (long, long, long, long, long, long, long, long);
  func = end_func;
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[0], &params[0]);
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[1], &params[1]);
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[2], &params[2]);
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[3], &params[3]);
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[4], &params[4]);
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[5], &params[5]);
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[6], &params[6]);
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[7], &params[7]);
  rval = func (params[0], params[1], params[2], params[3], params[4], params[5], params[6], params[7]);
  return rval;
}

long
handle_44444444444 (void *end_func, struct param *p)
{
  long params[10];
  long rval;
  long (*func) (long, long, long, long, long, long, long, long, long, long);
  func = end_func;
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[0], &params[0]);
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[1], &params[1]);
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[2], &params[2]);
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[3], &params[3]);
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[4], &params[4]);
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[5], &params[5]);
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[6], &params[6]);
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[7], &params[7]);
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[8], &params[8]);
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[9], &params[9]);
  rval = func (params[0], params[1], params[2], params[3], params[4],
	       params[5], params[6], params[7], params[8], params[9]);
  return rval;
}


long
handle_0 (void *end_func, struct param *p)
{
  void (*func) (void);
  func = end_func;
  func ();
  return 0;
}


long
handle_02 (void *end_func, struct param *p)
{
  short params[1];
  long p1;
  void (*func) (long);
  func = end_func;
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[0], &p1);
  params[0] = p1;
  func (params[0]);
  return 0;
}

long
handle_04 (void *end_func, struct param *p)
{
  long params[1];
  void (*func) (long);
  func = end_func;
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[0], &params[0]);
  func (params[0]);
  return 0;

}

long
handle_044 (void *end_func, struct param *p)
{
  long params[2];
  void (*func) (long, long);
  func = end_func;
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[0], &params[0]);
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[1], &params[1]);
  func (params[0], params[1]);
  return 0;
}

long
handle_0444 (void *end_func, struct param *p)
{
  long params[3];
  void (*func) (long, long, long);
  func = end_func;
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[0], &params[0]);
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[1], &params[1]);
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[2], &params[2]);
  func (params[0], params[1], params[2]);
  return 0;
}

long
handle_0444444 (void *end_func, struct param *p)
{
  long params[6];
  void (*func) (long, long, long, long, long, long);
  func = end_func;
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[0], &params[0]);
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[1], &params[1]);
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[2], &params[2]);
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[3], &params[3]);
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[4], &params[4]);
  evaluate_param_i_into_integer (p->param_u.p_list->list_param_id.list_param_id_val[5], &params[5]);
  func (params[0], params[1], params[2], params[3], params[4], params[5]);

  return 0;
}

long
handle_044V (void *end_func, struct param *p, struct param *r)
{
	log_err("handle_044V not implemented");
  exit (0);
  return 0;
}


struct func_sigs
{
  void *ptr;
  char *name;
};

struct func_sigs function_signiatures[] = {
  {&handle_4, "4"},
  {&handle_44, "44"},
  {&handle_444, "444"},
  {&handle_4444, "4444"},
  {&handle_44444, "44444"},
  {&handle_444444, "444444"},
  {&handle_44444444444, "44444444444"},
  {&handle_0, "0"},
  {&handle_014, "014"},
  {&handle_02, "02"},
  {&handle_04, "04"},
  {&handle_044, "044"},
  {&handle_0444, "0444"},
  {&handle_0444444, "0444444"},
  {&handle_044V, "044V"},
  {&handle_444444444, "444444444"},
  {0, 0}
};



static void *
find_sig (char *s)
{
  int a;
  //void *ptr;
  if (s == 0)
    {
	
      log_err("Find sig passed null\n");

      return 0;
    }
  for (a = 0; function_signiatures[a].ptr; a++)
    {
      if (strcmp (s, function_signiatures[a].name) == 0)
	return function_signiatures[a].ptr;
    }
  return 0;
}

static void *
find_function_ptr (char *s)
{
  int a;
  for (a = 0; system_funcs[a].ptr; a++)
    {
      if (strcmp (s, system_funcs[a].name) == 0)
	return system_funcs[a].ptr;
    }
  return find_by_dlself(s) ;
  return 0;
}

static char *
find_function_sig (char *s)
{
  int a;
  for (a = 0; system_funcs[a].ptr; a++)
    {
      if (strcmp (s, system_funcs[a].name) == 0)
	return system_funcs[a].signiature;
    }
  return 0;
}



long
call_c_function (char *s, struct param *p, long *r)
{
  struct param_list *list;
  char *sig;
  //long pc;
  long (*ptr) (void *end_func, struct param * p);
  void *ptr_function;
  long x;

  if (p)
    {
      if (p->param_type != PARAM_TYPE_LIST)
	{
		char buff[256];
	  sprintf(buff,"Was expecting a list (Got %d)\n",p->param_type);
	log_err(buff);
	  exit (20);
	}

      list = p->param_u.p_list;
      A4GL_debug ("Have %d values...", list->list_param_id.list_param_id_len);
    }
  else
    {
      list = 0;
    }


  sig = find_function_sig (s);

  if (sig == 0)
    {
      int a;
      static char buff[256];
      int ok = 1;
      sprintf (buff, "4");
      //printf("Sig not found - try to guess.. \n");
      if (list)
	{
	  for (a = 0; a < list->list_param_id.list_param_id_len; a++)
	    {

	      //printf("Param %d - %d\n",a,list->list.list_param_id_val[a]);
		struct param *p;
		if (list->list_param_id.list_param_id_val[a]>0) {
			p=&PARAM_ID(this_module_ptr, list->list_param_id.list_param_id_val[a]);
		} else {
			p=nget_param(list->list_param_id.list_param_id_val[a]);
		}
	      switch (p->param_type)
		{
		case PARAM_TYPE_LITERAL_CHAR:
		  strcat (buff, "1");
		  break;
		case PARAM_TYPE_LITERAL_STRING:
		  strcat (buff, "4");
		  break;
		case PARAM_TYPE_LITERAL_INT:
		  strcat (buff, "4");
		  break;
		case PARAM_TYPE_USE_VAR:
		  strcat (buff, "4");
		  break;	// A guess...
		case PARAM_TYPE_CALL:
		  strcat (buff, "4");
		  break;	// A guess...
		case PARAM_TYPE_OP:
		  strcat (buff, "4");
		  break;	// A guess...
		default:
		  ok = 0;
		
		  sprintf (buff,"Can't figure it out...%d %p\n",p->param_type,p);
			log_err(buff);
		  exit (2);
		}

	    }
	}

      if (ok)
	{
	  sig = buff;
	}
      else
	fprintf (stderr,"Darn..\n");
    }


  if (sig == 0)
    {
	char buff[256];
      sprintf (buff,"C Function not found... %s\n", s);
	log_err(buff);

      return 0;
    }
  A4GL_debug ("sig=%s\n", sig);
  fprintf (logfile, "     Calling C function : %s\n", s);
  if (list)
    {
      if (strlen (sig) - 1 != list->list_param_id.list_param_id_len)
	{
	char buff[256];
	  sprintf (buff,"Mismatch in parameters to function %s - expecting %d got %d\n",s, strlen (sig) - 1, list->list_param_id.list_param_id_len);
	log_err(buff);
	  exit (21);
	}
    }
  else
    {
      if (strlen (sig) - 1 != 0)
	{
	char buff[256];
	  sprintf
	    (buff,"Mismatch in parameters to function %s - expecting %d got %d\n",s,
	     strlen (sig) - 1, list->list_param_id.list_param_id_len);
		log_err(buff);
	  exit (21);
	}
    }

  ptr_function = find_function_ptr (s);

  ptr = find_sig (sig);
  if (!ptr)
    {
	char buff[256];
      	sprintf (buff,"Can't find signiature... (%s for %s)\n",sig,s);
	log_err(buff);
      exit (1);

    }
  if (ptr_function == 0)
    {
	char buff[256];
      	sprintf (buff,"Function was not declared...'%s'\n", s);
	log_err(buff);
      exit (1);
    }
  x = ptr (ptr_function, p);
  *r = x;

  return x;
}



static int
chk_func_sigs ()
{
  int a;
  int ok = 1;
  for (a = 0; system_funcs[a].ptr; a++)
    {
      if (system_funcs[a].signiature == 0)
	continue;
      if (!find_sig (system_funcs[a].signiature))
	{
	  if (system_funcs[a].signiature[0] == '0')
	    {
	      fprintf (stderr,"void ");
	    }
	  if (system_funcs[a].signiature[0] == '2')
	    {
	      fprintf (stderr,"short ");
	    }
	  if (system_funcs[a].signiature[0] == '4')
	    {
	      fprintf (stderr,"long ");
	    }
	  if (system_funcs[a].signiature[0] == '8')
	    {
	      fprintf (stderr,"double ");
	    }
	  fprintf (stderr,"handle_%s(struct param *p) {  }\n",
		  system_funcs[a].signiature);
	  ok = 0;
	}
    }
  return ok;
}


int aa() {
	printf("Hello World\n");
	return 1;
}

void * find_by_dlself(char *s)
{
  static void *so_libs[10]={
	  		(void *)-1,
	  		(void *)-1,
	  		(void *)-1,
	  		(void *)-1,
	  		(void *)-1,
	  		(void *)-1,
	  		(void *)-1,
	  		(void *)-1,
	  		(void *)-1,
	  		(void *)-1
					};


  void *ptr=0;
  char buff[255];
  //char *ptr1;
  int a;
  char *fname;


  if ((long)so_libs[0]==-1) {
  	for (a=0;a<10;a++) {
	  	if (a==0) {
		  	fname=0;
 	  	}  else {
		  	sprintf(buff,"FGLRUNNER_LIB%d",a);
#ifdef STDCALLS
		  	fname=getenv(buff);
#else
		  	fname=acl_getenv(buff);
#endif
		  	if (fname==0||strlen(fname)==0) {
				A4GL_debug("No variable defined at %d",a);
			  	so_libs[a]=0;
			  	continue;
		  	} else {
			}
	  	}
	

		A4GL_debug("Try to open %s @ %d",fname,a);
		so_libs[a] = (void *)dlopen (fname, RTLD_LAZY);

		if (fname) {
			A4GL_debug("Opening %s -> %p",fname,so_libs[a]);
		
		} else {
			A4GL_debug("Opening self -> %p",so_libs[a]);
		}
  	}
   }
		  
  for (a=0;a<10;a++) {
  	if (so_libs[a]) {
#if NEED_DL_UNDERSCORE
		sprintf(buff,"_%s",s);
#else
		strcpy(buff,s);
#endif
		A4GL_debug("Looking for %s\n",buff);
      		ptr=dlsym (so_libs[a],buff);
		if (ptr) {
			A4GL_debug("Found in lib %d",a);
			return ptr;
		}
	}
    }

    return 0;
}
#else

void *find_by_dlself(char *s) {
	return 0;
}
#endif

