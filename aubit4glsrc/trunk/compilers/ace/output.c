#include "report.h"
#include <stdio.h>
extern struct report this_report;
extern char *outputfilename;

FILE *fxx;
void write_report (void)
{
  char fname[132];
  char fname2[132];
  char base[132];
  char ext[132];

  int a;
//  int outfile;
  XDR xdrp;
  struct report *ptr;

  ptr = &this_report;

  strcpy(fname, outputfilename);

  bname(outputfilename, ext, base);

  if (ext[0] == 0)
  {
          strcat(fname, ".aarc");
  }

  strcpy(fname2, outputfilename);
  strcat(fname2, ".c");

  fxx = fopen(fname,"wb");

  if (fxx == 0)
  {
    printf("Couldnt open file for write (%s)\n", fname, 0);
  }
  xdrstdio_create(&xdrp, fxx, XDR_ENCODE);

  a=xdr_report(&xdrp,ptr);
  if (!a)
        {
           debug("*** Write FAILED ***\n");
                printf("Unable to write data\n",0,0);
  }

  xdr_destroy(&xdrp);
  fclose(fxx);
}
