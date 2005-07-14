#include "report_viewer.h"
//#include <stdio.h>
//#include <gtk/gtk.h>
//#include <string.h>
//#include "../common/a4gl_lle.h"


#include "a4gl_libaubit4gl.h"

void edit_lle ( struct r_report *report);

struct r_report *report;

/* ******************************************************************************** */

int
main (int argc, char *argv[])
{
  //int npages;
  //char buff[256];
  //int buff_i;
  //char buff_c;


  if (argc != 2)
    {
      printf ("Usage : %s filename\n", argv[0]);
      exit (1);
    }


  report = read_report_output (argv[1]);
  if (report == 0)
    {
      printf ("Unable to open input file : %s\n", argv[1]);
      exit (2);
    }

  gtk_init (&argc, &argv);

  //printf ("Time    : %s\n", ctime (&report->ctime));

  printf ("Pages : %d maximum lines/page :%d maximum column position:%d\n",
	  report->max_page, report->max_line, report->max_col);

  edit_lle (report);
  gtk_main();
  return 0;
}


void setup_entry(int b,int e,GtkWidget *evt,GtkWidget *lab) {
// Does nothing...
}

void setup_block(int b,GtkWidget *evt,GtkWidget *lab) {
// Does nothing
}

void set_clicked(int rb,int entry) {

}

void set_block_clicked(int rb) {
	
}



void *
acl_realloc_full (void *a, long b, char *r, char *f, int l)
{
	  void *p;
	    p = realloc (a, b);
	      if (p == 0)
		          {
				        printf ("Unable to allocate memory\n");
					      exit (2);
					          }
	        return p;
}

