
#include "a4gl_4glc_int.h"

//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>

//#include "a4gl_lib_lex_fgl_int.h"
#define ONE_NOT_ZERO(x) (x?x:1)



struct s_function_prototype *fboltons = 0;
int nboltons = 0;
//int is_bolton_function (char *s);

struct s_function_prototype
{
  int proto_type;
  char *pname;
  int nparams;
  int *param_dtypes;
  int nreturns;
  int *return_dtypes;
  char *module;
  int lineno;
};


static void
add_bolton (char *fname, char *vparams, char *vrets)
{
  char *p_params[200];
  char *p_rets[200];
  int pcnt = 0;
  int rcnt = 0;
  int l;
  int a;
  char *params;
  char *rets;
  nboltons++;
  params=strdup(vparams);
  rets=strdup(vrets);

  A4GL_trim(params);
  A4GL_trim(rets);

  fboltons = realloc (fboltons, sizeof (fboltons[0]) * nboltons);

  l = strlen (params);

  if (l == 0)
    {
      pcnt = 0;
    }
  else
    {

      pcnt = 0;
      p_params[0] = params;
      for (a = 0; a <= l; a++)
	{
	  if (params[a] == ',' || params[a] == 0)
	    {
	      params[a] = 0;
	      pcnt++;
	      p_params[pcnt] = &params[a + 1];
	      continue;
	    }
	}
    }

  l = strlen (rets);
  if (l == 0)
    {
      rcnt = 0;
    }
  else
    {

      rcnt = 0;
      p_rets[0] = rets;
      for (a = 0; a <= l; a++)
	{
	  if (rets[a] == ',' || rets[a] == 0)
	    {
	      rets[a] = 0;
	      rcnt++;
	      p_rets[rcnt] = &rets[a + 1];
	      continue;
	    }
	}
    }



  fboltons[nboltons - 1].pname = strdup (fname);
  fboltons[nboltons - 1].proto_type = 0;
  fboltons[nboltons - 1].nparams = pcnt;
  fboltons[nboltons - 1].module="<loaded>";
  fboltons[nboltons - 1].lineno=-1;

  if (pcnt)
    {
      fboltons[nboltons - 1].param_dtypes = malloc (sizeof (int) * pcnt);
      for (a = 0; a < pcnt; a++)
	{
	  fboltons[nboltons - 1].param_dtypes[a] = atoi (p_params[a]);
	}
    }
  else
    {
      fboltons[nboltons - 1].param_dtypes = 0;
    }


  fboltons[nboltons - 1].nreturns = rcnt;
  if (rcnt)
    {
      fboltons[nboltons - 1].return_dtypes = malloc (sizeof (int) * rcnt);
      for (a = 0; a < rcnt; a++)
	{
	  fboltons[nboltons - 1].return_dtypes[a] = atoi (p_rets[a]);
	}
    }
  else
    {
      fboltons[nboltons - 1].return_dtypes = 0;
    }
	//printf("Added %s with %d returns\n", fboltons[nboltons - 1].pname, fboltons[nboltons - 1].nreturns);
}


static void load_default_boltons(void) {
      add_bolton ("startlog","0", "");
      add_bolton ("errorlog","0", "");
      add_bolton ("set_count","2", "");
      add_bolton ("arr_count","", "2");
      add_bolton ("arr_curr","", "2");
      add_bolton ("scr_line","", "2");
      add_bolton ("fgl_settitle","0", "");
      add_bolton ("length","0", "2");
      add_bolton ("showhelp","2", "");
      add_bolton ("fgl_winquestion","0,0,0,0,0,2", "0");
      add_bolton ("aclfgl_add_to_toolbar","0,0,0,0,0,2", "");
      add_bolton ("fgl_drawbox","2,2,2,2", "");
      add_bolton ("err_get","2", "0");
}

static void
load_boltons (char *fname)
{
  FILE *f;
  int lineno = 0;
//char *funcname;
//int nparam;
//int nret;
//char *params;
//char *rets;
  int printed;
  char buff[2560];
  if (fname == 0)
    return;
  if (strlen (fname) == 0)
    return;
  f = fopen (fname, "r");
  if (f == 0) {
	printf("Unable to open prototypes file : %s\n",fname);
	exit(2);
    return;
	}

  while (1)
    {
      char *p[4];
      memset(buff,0,sizeof(buff));
      fgets (buff, 2550, f);
      lineno++;
      if (feof (f))
	break;
      A4GL_trim (buff);
      printed = 0;

      p[0] = buff;
      p[1] = strchr (buff, '|');
      if (p[1])
	{
	  *p[1] = 0;
	  p[1]++;
	  p[2] = strchr (p[1], '|');
	  if (p[2])
	    {
	      *p[2] = 0;
	      p[2]++;
		p[3]=strchr(p[2],'|');
		if (p[3]) {
			*p[3]=0;
		}
	      //printf("Loading : %s:%s:%s\n",p[0],p[1],p[2]);
	      printed++;
	      add_bolton (p[0], p[1], p[2]);
	    }
	}

      if (!printed)
	{
	  printf ("Bad line : %s @ %d\n", buff, lineno);
	  continue;
	}
    }
}


int
is_bolton_function (char *s)
{
  int a;
  for (a = 0; a < nboltons; a++)
    {
      if (strcmp (s, fboltons[a].pname) == 0)
        {
          return a;
        }
    }
  return -1;
}




void load_protos(void) {
  char *fname;
  load_default_boltons();
  fname = acl_getenv_not_set_as_0 ("CFUNCSFILE");
  if (fname)
    {
      	load_boltons (fname);
    } else {
		//printf("CFUNCSFILE is not set\n");
		//exit(2);
	}
}


int get_bolton_nrets(int a) {
	if (a<0 || a>=nboltons) { A4GL_assertion(1,"Bolton funcno out of range"); }
	return fboltons[a].nreturns;
}

int get_bolton_rtype(int a,int rval) {
	if (a<0 || a>=nboltons) { A4GL_assertion(1,"Bolton funcno out of range"); }
	if (fboltons[a].return_dtypes[rval]==DTYPE_SERIAL) return DTYPE_INT;
	return fboltons[a].return_dtypes[rval];
}

int get_bolton_nparam(int a) {
	if (a<0 || a>=nboltons) { A4GL_assertion(1,"Bolton funcno out of range"); }
	return fboltons[a].nparams;
}

int get_bolton_param(int a,int param) {
	if (a<0 || a>=nboltons) { A4GL_assertion(1,"Bolton funcno out of range"); }
	if (fboltons[a].param_dtypes[param]==DTYPE_SERIAL) return DTYPE_INT;
	return fboltons[a].param_dtypes[param];
}

