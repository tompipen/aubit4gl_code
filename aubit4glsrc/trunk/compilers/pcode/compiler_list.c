#if (defined(__CYGWIN__)) || defined(__MINGW32__)
	/* missing from rpcgen generated .h on CygWin: */
	#define bool_t int
	#define u_int unsigned int
#endif

#include "npcode.h"
#include "npcode_defs.h"

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

struct npfunction *current_function;


extern module this_module;
int created = 0;

void
add_label (char *label)
{
  ENTRY e, *ep;

  current_function =
    &this_module.functions.functions_val[this_module.functions.functions_len -
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
#if ! defined (__CYGWIN__) && ! defined (__MINGW32__)
	  hcreate (100000);
#endif
    }




  e.key = strdup (label);
  e.data = (char *) current_function->cmds.cmds_len;

#if ! defined (__CYGWIN__) && ! defined (__MINGW32__)
  ep = hsearch (e, ENTER);
#endif

  if (!ep)
    {
      printf ("Unable to append to hash list\n");
      exit (10);
    }

  //  labels[labels_cnt].str = strdup (label);
  //labels[labels_cnt].pc = current_function->cmds.cmds_len;
}


long
find_label (char *label)
{
  ENTRY e, *ep;
  e.key = label;

#if ! defined (__CYGWIN__) && ! defined (__MINGW32__)
  ep = hsearch (e, FIND);
#endif
  if (!ep)
    return -1;
  return (long) ep->data;

}
