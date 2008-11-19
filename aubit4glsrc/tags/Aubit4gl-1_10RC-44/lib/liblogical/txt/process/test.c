#include <stdlib.h>
#include <stdio.h>
#include "../../common/a4gl_lle.h"


struct r_report *report; 


main (int argc, char *argv[]) {
  if (argc != 2)
    {
      printf ("Usage : %s filename\n", argv[0]);
      exit (1);
    }


  report=read_report_output(argv[1]);

  if (report==0) {
      printf ("Unable to open input file : %s\n", argv[1]);
      exit (2);
    }

  LR_process_report(stdout,0,report);


}




