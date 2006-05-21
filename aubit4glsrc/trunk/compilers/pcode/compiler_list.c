#if (defined(__CYGWIN__)) || defined(__MINGW32__)
	/* missing from rpcgen generated .h on CygWin: */
	#define bool_t int
	#define u_int unsigned int
	
	
	#include "a4gl_libaubit4gl.h" //ENTRY
#endif

#ifdef RPCGEN_HEADERS
	#include "npcode.h"
#else
	#include "npcode.xs.h"
#endif

#include "npcode_defs.h"
#include "a4gl_memhandling.h"

#if HAVE_SEARCH_H
	#include <search.h>		/* VISIT-used in pointers.c */
#else
	  
	#include "../../tools/search.h"		/* VISIT-used in pointers.c */
	  /* For tsearch */
	  /*
	  typedef enum
	  {
	    preorder,
	    postorder,
	    endorder,
	    leaf
	  }
	  VISIT;
        */
#endif
#include <string.h>

struct npfunction *current_function;


extern module *this_module_ptr;
int created = 0;

void
add_label (char *label)
{
  ENTRY e, *ep;

  current_function =
    &this_module_ptr->functions.functions_val[this_module_ptr->functions.functions_len -
					 1];

  if (created == 1)
    {
      if (find_label (label) >= 0)
	{
	  printf ("Label already exists (%s)\n", label);
	  exit (1);
	}
    }
  else
    {
	  hcreate (100000);
    }




  e.key = acl_strdup (label);
  e.data = (char *) current_function->cmds.cmds_len;

  ep = (ENTRY *)hsearch (e, ENTER);

  if (!ep)
    {
      printf ("Unable to append to hash list\n");
      exit (10);
    }

  //  labels[labels_cnt].str = acl_strdup (label);
  //labels[labels_cnt].pc = current_function->cmds.cmds_len;
}


long
find_label (char *label)
{
  ENTRY e, *ep;
  e.key = label;

  ep = (ENTRY *)hsearch (e, FIND);
  if (!ep)
    return -1;
  return (long) ep->data;

}



char *
acl_strdup_full (void *a, char *r, char *f, int l)
{
	  char *p;
	    p = strdup (a);
	      if (p == 0)
		          {
				        printf ("Unable to allocate memory\n");
					      exit (1);
					          }
	        return p;
}

