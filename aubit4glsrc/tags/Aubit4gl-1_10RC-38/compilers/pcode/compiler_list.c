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

#if (defined(__CYGWIN__)) || defined(__MINGW32__)
#define hsearch hsearch_local
#define hcreate hcreate_local
#define FIND  1001
#define ENTER 1002
typedef struct local_entry {
	char*key;
	void *data;
} LOCAL_ENTRY;
#define ENTRY LOCAL_ENTRY
ENTRY *hsearch_local(LOCAL_ENTRY  itm, int act) ;
int hcreate_local(int n) ;

#else

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
#endif

#include <string.h>

struct npfunction *current_function;


extern module *this_module_ptr;
int created = 0;

void
add_label (char *label)
{
  ENTRY e, *ep=0;

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
	created++;
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

#if (defined(__CYGWIN__)) || defined(__MINGW32__)

struct local_entry *entries=0;
int nentries;

int hcreate_local(int n) {
int a;
entries=malloc(n*sizeof(struct local_entry));
if (entries==0) return 0;
nentries=n;
for (a=0;a<n;a++) {
	entries[a].key=0;
	entries[a].data=0;
}
return 1;
}

LOCAL_ENTRY *hsearch_local(struct local_entry  itm, int act) {
int a;
int first_zero=-1;
if (entries==0) return 0;

for (a=0;a<nentries;a++) {
  if (entries[a].key==0) {
	first_zero=a;
	break;
  }
  if (strcmp(entries[a].key,itm.key)==0) {
	return &entries[a];
  }
}
// Not found....

if (act==FIND) return 0;
if (act==ENTER) {
   	entries[first_zero].key=itm.key;
   	entries[first_zero].data=itm.data;
	return &entries[first_zero];
}
return 0;
}
#endif
