//#include "menu_x.h"
#include "../../lib/libincl/menuxw.h"


#include "../../lib/libincl/compiler.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "../../lib/libincl/debug.h"
#ifdef __CYGWIN__
#include <rpc/rpc.h>
#endif
int as_c=1;

int ignorekw = 0;
int lineno = 0;
int colno = 0;
int scr = 0;
int cmaxcol = 0;
int cmaxline = 0;
int maxcol;
int maxline;
int newscreen = 0;
int fldno;
int fstart;
int openwith = 0;

char currftag[256];

struct struct_screen_record *curr_rec;
char buff_xdr[30000];

extern char *outputfilename;

struct menu_list the_menus;
struct struct_scr_field *fld;

char *chk_alias (char *s);
FILE *fxx;
FILE *fyy;

char *
char_val (char *s)
{
  static char str[80];
  int a;
  strcpy (str, &s[1]);
  str[strlen (str) - 1] = 0;
  for (a = 0; a < strlen (str); a++)
    {
      if (str[a] == '\t')
	str[a] = ' ';
    }
  return str;
}



error_with (char *s, char *a, char *b)
{
  static char z[2];
  z[0] = 0;
  if (a == 0)
    a = z;
  if (b == 0)
    b = z;
   printf (s, a, b);

  debug ("\n");
  exit (0);
}

write_menu ()
{
  char fname[132];
  char fname2[132];
  int a;
  int outfile;
  XDR xdrp;
  menu_list *ptr;
  ptr=&the_menus;
  strcpy (fname, outputfilename);
  strcat (fname, ".mnu");

  strcpy (fname2, outputfilename);
  strcat (fname2, ".c");


  fxx=fopen(fname,"wb");

  printf("has %d menus\n",the_menus.menus.menus_len);
 
  if (fxx == 0)
    {
      error_with ("Couldnt open file for write (%s)\n", fname, 0);
    }

        xdrstdio_create(&xdrp, fxx, XDR_ENCODE);
        a=xdr_menu_list(&xdrp,ptr);

	if (!a) {
		debug("*** Write FAILED ***\n");
		error_with("Unable to write data\n",0,0);
	}

	xdr_destroy(&xdrp);
	fclose(fxx);

	if (as_c) {
		int cnt=0;
		int a;
		debug("Asc...\n");
		fxx=fopen(fname,"r");
		fyy=fopen(fname2,"w");
		fprintf(fyy,"char compiled_menu_%s[]={\n",outputfilename);

		while (!feof(fxx)) {
			a=fgetc(fxx);
			if (feof(fxx)) break;
			if (cnt>0) fprintf(fyy,",");
			if (cnt%16==0&&cnt) {fprintf(fyy,"\n");}
			if (a==-1) {break;}
			fprintf(fyy,"0x%02x",a);
			cnt++;
		}
		fprintf(fyy,"};\n");
		fclose(fxx);
		fclose(fyy);
		//unlink(fname);
	}
	
}



