#include "npcode.h"
#include "npcode_defs.h"
#include <search.h>

struct function *current_function;

extern module this_module;
int created=0;

void add_label(char *label) {
ENTRY e, *ep;

  current_function = &this_module.functions.functions_val[this_module.functions.functions_len - 1];

  if (created==1) {
  	if (find_label (label) >= 0) {
      		printf ("Label already exists (%s)\n", label);
      		exit (1);
    	}
  } else {
		hcreate(100000);
  }




  e.key=strdup(label);
  e.data=(char *)current_function->cmds.cmds_len;
  ep=hsearch(e,ENTER);
 if (!ep) {
	printf("Unable to append to hash list\n");
	exit(10);
 }
  
   //  labels[labels_cnt].str = strdup (label);
  //labels[labels_cnt].pc = current_function->cmds.cmds_len;
}


long find_label(char *label) {
ENTRY e,*ep;
e.key=label;

ep=hsearch(e,FIND);
if (!ep) return  -1;
return (long) ep->data;

}
