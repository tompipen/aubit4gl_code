#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define NOSTRCPYMAP
#include "a4gl_libaubit4gl.h"
#include "../common/a4gl_lle.h"
#include "API_layout.h"


struct r_report *report_internal;

/* ******************************************************************************** */

int main (int argc, char *argv[])
{
  char buff_env[256];
  //rbs = 0;
  //rbx = 0;

  if (argc != 2)
    {
      printf ("Usage %s file-name\n", argv[0]);
      exit (1);
    }

  report_internal = read_report_output (argv[1]);

  if (report_internal == 0)
    {
      printf ("Unable to open report output\n");
      exit (2);
    }

 
 if (report_internal->nblocks) {
	printf("Has %d blocks\n", report_internal->nblocks);
	exit(0);
  } else {
	printf("Has no blocks\n");
	exit(1);
  }
	
return 0;
}

