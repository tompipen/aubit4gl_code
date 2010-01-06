/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-2005 Aubit Development Team (See Credits file)    |
# +----------------------------------------------------------------------+
# | This program is free software; you can redistribute it and/or modify |
# | it under the terms of one of the following licenses:                 |
# |                                                                      |
# |  A) the GNU General Public License as published by the Free Software |
# |     Foundation; either version 2 of the License, or (at your option) |
# |     any later version.                                               |
# |                                                                      |
# |  B) the Aubit License as published by the Aubit Development Team and |
# |     included in the distribution in the file: LICENSE                |
# |                                                                      |
# | This program is distributed in the hope that it will be useful,      |
# | but WITHOUT ANY WARRANTY; without even the implied warranty of       |
# | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        |
# | GNU General Public License for more details.                         |
# |                                                                      |
# | You should have received a copy of both licenses referred to here.   |
# | If you did not, or have any questions about Aubit licensing, please  |
# | contact licensing@aubit.com                                           |
# +----------------------------------------------------------------------+
#
# $Id: pack_xml.c,v 1.36 2009-01-23 18:24:15 mikeaubury Exp $
#*/

/**
 * @file
 * XML packer library
 *
 * This will write correct XML but will only read XML generated by these output
 * routines. This is because we didn't want to write a full XML parser, so the
 * input routines make assumptions on the data being read and its format WRT
 * whitespace
 *
 *
 *
 * @todo Doxygen comments to add to functions
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_lib_packer_xml_int.h"
#include <ctype.h>

/*
=====================================================================
                    Constants definitions
=====================================================================
*/

/* Do we want the output indented ? */
#define INDENT

/*
=====================================================================
                    Variables definitions
=====================================================================
*/


FILE *infile = 0;
FILE *outfile = 0;


char ibuff[20000];		/* Input line buffer */
int attrok = 0;
int contentok = 0;
int level = 0;
int inlineno=0;
/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

char *A4GL_find_attr (char *s, char *n);	/* Extract a specified attribute from a string */
char *A4GL_find_contents (char *s);	/* Extract the tag contents from a string */

/*
--------------------------------
 Internal helper functions
--------------------------------
*/
static void chk (void *x);

void print_level (void);
char *A4GL_pr_elem (int a, int p);


/*
=====================================================================
                    Functions definitions
=====================================================================
*/


/**
 *
 * @todo Describe function
 */
void
print_level (void)
{
  int a;
#ifdef INDENT
  for (a = 0; a < level; a++)
    {
      fprintf (outfile, "  ");
    }
#endif
}


/**
 *
 * @todo Describe function
 */
char *
A4GL_pr_elem (int a, int p)
{
  static char buff[20];

  if (p)
    {
      if (a >= 0)
	{
	  sprintf (buff, " PTR=\"1\" ELEM=\"%d\"", a);
	}
      else
	{
	  sprintf (buff, " PTR=\"1\"");
	}
    }
  else
    {
      if (a >= 0)
	{
	  sprintf (buff, " ELEM=\"%d\"", a);
	}
      else
	{
	  sprintf (buff, " ");	/*  warning: zero-length format string */
	}
    }
  return buff;
}



/**
 *
 * @todo Describe function
 */
char *
A4GL_find_attr (char *s, char *n)
{
  static char buff[2000];
  char *ptr;
  attrok = 0;
  sprintf (buff, "%s=\"", n);

  ptr = strstr (s, n);
  if (ptr == 0)
    return "";

  attrok = 1;
  ptr += strlen (buff);


  strcpy (buff, ptr);

  ptr = strchr (buff, '"');

  if (ptr == 0)
    {
      attrok = 0;
      printf ("No closing quote (%s %s)?\n", s, n);
      return "";
    }

/* while (*(ptr-1)=='\\')  { ptr=strchr(ptr,'"'); } */
  *ptr = 0;
  return buff;
}

/**
 *
 * @todo Describe function
 */
char *
A4GL_find_contents (char *s)
{
  static char buff[20000];
  char *ptr;
  contentok = 0;
  ptr = strchr (s, '>');
  if (ptr == 0)
    return "";
  strcpy (buff, ptr + 1);
  ptr = strchr (buff, '<');
  if (ptr == 0)
    return "";
  *ptr = 0;
  contentok = 1;
  return buff;
}


/**
 *
 * @todo Describe function
 */
static void
chk (void *x)
{
  return;
  if ((int) x < 10000)
    {
      printf ("Suspect pointer... : %p\n", x);
      exit (0);
    }
}

/*
--------------------------------
--- API Functions
--------------------------------
*/

/*
-------------------------------------------------------------
 File IO routines
-------------------------------------------------------------
*/


int A4GLPacker_A4GL_pack_remove_file(char *fname) {
        char buff[512];
        sprintf (buff, "%s%s", fname,acl_getenv ("A4GL_XML_EXT"));
        return A4GL_delete_file(buff);
}

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_A4GL_open_packer (char *basename, char dir,char *packname,char *version)
{
  char buff[256];



  if (toupper (dir) == 'O')
    {        char *override;
        override=acl_getenv_not_set_as_0 ("OVERRIDE_PACKER_OUTPUT");
        if (override==NULL) {


                if (A4GL_isyes(acl_getenv("A4GL_LOCALOUTPUT"))) {
                        char *b;
                        b=strrchr(basename,'/');
                        if (b) basename=b+1;
                }

  	sprintf (buff, "%s%s", basename, acl_getenv ("A4GL_XML_EXT"));
	} else {
		strcpy(buff,override);
	}
  	A4GL_debug (buff);

      /* write XML file */
      outfile = fopen (buff, "w");
      if (outfile)
	{
	  A4GL_set_last_outfile (buff);
	  fprintf (outfile, "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n");
	  return 1;
	}
      else
	{
	  A4GL_exitwith ("Unable to open");
	  return 0;
	  //exit (46);
	}
    }

  if (toupper (dir) == 'I')
    {
	if (!A4GL_strendswith(basename,acl_getenv ("A4GL_XML_EXT"))) {
  		sprintf (buff, "%s%s", basename, acl_getenv ("A4GL_XML_EXT"));
	} else {
  		sprintf (buff, "%s", basename);
	}
  A4GL_debug (buff);
      /* read XML file */
      infile = A4GL_open_file_dbpath (buff);
	inlineno=0;
      if (infile == 0)
	{
	  A4GL_exitwith ("Unable to open");
	  return 0;
	  //exit (45);
	}

      /* Get rid of the ?xml line at the beginning */
      fgets (buff, sizeof (buff), infile);

      if (infile)
	return 1;

    }

  A4GL_debug ("Error in open_packer()\n");

  return 0;


}

/**
 *
 * @todo Describe function
 */
void
A4GLPacker_A4GL_close_packer (char dir)
{
  A4GL_debug ("In close_packer()");

  if (toupper (dir) == 'O')
    fclose (outfile);

  if (toupper (dir) == 'I')
    fclose (infile);

  A4GL_debug ("exiting close_packer()");
}

/*
----------------------------------------------------------------------------
 Output routines
----------------------------------------------------------------------------
*/

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_output_start_array (char *s, int type, int len)
{
  print_level ();
  fprintf (outfile, "<ARRAY NAME=\"%s\" TYPE=\"%s\" LENGTH=\"%d\">\n", s,
	   type == 1 ? "VARIABLE" : "NORMAL", len);
  level++;
  return 1;
}

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_output_end_array (char *s, int type,int len)
{
  level--;
  print_level ();
  fprintf (outfile, "</ARRAY>\n");
  return 1;
}

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_output_int (char *name, int val, int ptr, int isarr)
{
  print_level ();
  fprintf (outfile, "<ATTR NAME=\"%s\" TYPE=\"INTEGER\"%s>%d</ATTR>\n", name,
	   A4GL_pr_elem (isarr, ptr), val);
  return 1;
}

int
A4GLPacker_output_short (char *name, short val, int ptr, int isarr)
{
  print_level ();
  fprintf (outfile, "<ATTR NAME=\"%s\" TYPE=\"SHORT\"%s>%d</ATTR>\n", name,
	   A4GL_pr_elem (isarr, ptr), val);
  return 1;
}


int
A4GLPacker_output_char (char *name, char val, int ptr, int isarr)
{
  print_level ();
  fprintf (outfile, "<ATTR NAME=\"%s\" TYPE=\"CHAR\"%s>%d</ATTR>\n", name,
	   A4GL_pr_elem (isarr, ptr), val);
  return 1;
}


/**
 *
 * @todo Describe function
 */
int
A4GLPacker_output_long (char *name, long val, int ptr, int isarr)
{
  print_level ();
  fprintf (outfile, "<ATTR NAME=\"%s\" TYPE=\"LONG\"%s>%d</ATTR>\n", name,
	   A4GL_pr_elem (isarr, ptr), (int) val);
  return 1;
}


/**
 *
 * @todo Describe function
 */
int
A4GLPacker_output_bool (char *name, int val, int ptr, int isarr)
{
  print_level ();
  fprintf (outfile, "<ATTR NAME=\"%s\" TYPE=\"BOOL\"%s>%d</ATTR>\n", name,
	   A4GL_pr_elem (isarr, ptr), val);
  return 1;
}

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_output_string (char *name, char *val, int ptr, int isarr)
{
  int a;
//char buff[10];
  print_level ();
  if (val==0) val="";
  A4GL_debug ("in output_string() outfile=%p\n", outfile);

  fprintf (outfile, "<ATTR NAME=\"%s\" TYPE=\"STRING\"%s>", name,
	   A4GL_pr_elem (isarr, ptr));
  for (a = 0; a < strlen (val); a++)
    {
/* Special XML characters :
	&lt; < less than
	&gt; > greater than
	&amp; & ampersand
	&apos; ' apostrophe
	&quot; " quotation mark
*/
      if (val[a]=='<') { fprintf (outfile, "&lt;"); continue;}
      if (val[a]=='\n') { fprintf (outfile, "&nl;"); continue;}
      if (val[a]=='>') { fprintf (outfile, "&gt;"); continue;}
      if (val[a]=='&') { fprintf (outfile, "&amp;"); continue;}
      if (val[a]=='\'') { fprintf (outfile, "&apos;"); continue;}
      if (val[a]=='"') { fprintf (outfile, "&quot;"); continue;}


      fprintf (outfile, "%c", val[a]);
    }
  fprintf (outfile, "</ATTR>\n");

  A4GL_debug ("exit output_string()\n");

  return 1;
}

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_output_double (char *name, double val, int ptr, int isarr)
{
  print_level ();
  fprintf (outfile, "<ATTR NAME=\"%s\" TYPE=\"DOUBLE\"%s>%f</ATTR>\n", name,
	   A4GL_pr_elem (isarr, ptr), val);
  return 1;
}

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_output_start_struct (char *s, char *n, int ptr, int isarr)
{
  print_level ();
  fprintf (outfile, "<STRUCT NAME=\"%s\" TYPE=\"%s\"%s>\n", n, s,
	   A4GL_pr_elem (isarr, ptr));
  level++;
  return 1;
}

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_output_end_struct (char *s, char *n)
{
  level--;
  print_level ();
  fprintf (outfile, "</STRUCT>\n");	/* , n, s); */
  return 1;
}

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_output_start_union (char *s,char *en, int e, char *n, int ptr, int isarr, void* enumcallback)
{
  if (!output_int(en,e,ptr,isarr)) return 0;
  print_level ();
  fprintf (outfile, "<UNION NAME=\"%s\" TYPE=\"%s\"%s>\n", n, s,
	   A4GL_pr_elem (isarr, ptr));
  level++;
  return 1;
}


/**
 *
 * @todo Describe function
 */
int
A4GLPacker_output_nullptr (char *s,char *sname, int isunion)
{
  print_level ();
  fprintf (outfile, "<ATTR NAME=\"%s\" TYPE=\"NULLPTR\"/>\n", s);
  return 1;
}

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_output_okptr (char *s)
{
  print_level ();
  fprintf (outfile, "<ATTR NAME=\"%s\" TYPE=\"HASPTR\"/>\n", s);
  return 1;
}

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_output_end_union (char *s,char *en, int e, char *n)
{
  level--;
  print_level ();
  fprintf (outfile, "</UNION>\n");	/* , n , s); */
  return 1;
}

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_output_enum (char *rn, char *name, char *s, int d)
{
  print_level ();
  fprintf (outfile, "<ENUM NAME=\"%s\" TYPE=\"%s\" DESCRIPTION=\"%s\" VALUE=\"%d\"/>\n",rn, name, s, d);
  return 1;
}

/*
------------------------------------------------------------------------------
 Input Routines
------------------------------------------------------------------------------
*/

/**
 *
 * @todo Describe function
 */
static int
getaline (void)
{
  char *a;
	inlineno++;
  a = fgets (ibuff, sizeof (ibuff), infile);

  A4GL_debug("%d. %s", inlineno,ibuff);

  if (a == 0)
    {
      printf ("Unexpected end of file\n");
      return 0;
    }
  return 1;
}


/**
 *
 * @todo Describe function
 */
int
A4GLPacker_input_start_array (char *s, int type, int *len)
{
  /* <ARRAY NAME=".." TYPE=".." LENGTH=".."> */
  if (!getaline ())
    return 0;
  chk (len);
  *len = atoi (A4GL_find_attr (ibuff, "LENGTH"));
  return (attrok);
}

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_input_end_array (char *s, int type)
{
  /* </ARRAY> */
  if (!getaline ())
    return 0;
  return 1;
}


/**
 *
 * @todo Describe function
 */
int
A4GLPacker_input_int (char *name, int *val, int ptr, int isarr)
{
  int a;
  /*   <ATTR NAME=%s TYPE=INTEGER%s>%d</ATTR> */
  chk (val);
  if (!getaline ())
    return 0;
A4GL_debug("input_int : ptr=%d\n",ptr);
  a = atoi (A4GL_find_contents (ibuff));
  *val = a;


  return contentok;
}


int
A4GLPacker_input_short (char *name, short *val, int ptr, int isarr)
{
  int a;
  /*   <ATTR NAME=%s TYPE=SHORT%s>%d</ATTR> */
  chk (val);
  if (!getaline ())
    return 0;
A4GL_debug("input_int : ptr=%d\n",ptr);
  a = atoi (A4GL_find_contents (ibuff));
  *val = a;


  return contentok;
}

int
A4GLPacker_input_char (char *name, char *val, int ptr, int isarr)
{
  int a;
  /*   <ATTR NAME=%s TYPE=CHAR%s>%d</ATTR> */
  chk (val);
  if (!getaline ())
    return 0;
A4GL_debug("input_int : ptr=%d\n",ptr);
  a = atoi (A4GL_find_contents (ibuff));
  *val = a;


  return contentok;
}


/**
 *
 * @todo Describe function
 */
int
A4GLPacker_input_long (char *name, long *val, int ptr, int isarr)
{
  /* <ATTR NAME=\"%s\" TYPE=\"LONG\"%s>%d</ATTR> */

  chk (val);
A4GL_debug("input_long : ptr=%d\n",ptr);
  if (!getaline ())
    return 0;
  *val = atoi (A4GL_find_contents (ibuff));
  return contentok;
}


/**
 *
 * @todo Describe function
 */
int
A4GLPacker_input_bool (char *name, int *val, int ptr, int isarr)
{
  /* <ATTR NAME=\"%s\" TYPE=\"BOOL\"%s>%d</ATTR> */

  chk (val);
  if (!getaline ())
    return 0;
A4GL_debug("input_bool : ptr=%d\n",ptr);
  *val = atoi (A4GL_find_contents (ibuff));
  return contentok;
}


/**
 *
 * @todo Describe function
 */
int
A4GLPacker_input_string (char *name, char **val, int ptr, int isarr)
{
  char *buff;
  char *pptr;
  char buffer[3];
  char c;
  int b;
  int a;
  int blen;
  /* <ATTR NAME=\"%s\" TYPE=\"STRING\"%s>%s</ATTR> */
 A4GL_debug("input_string : ptr=%d\n",ptr);
  chk (val);
  if (!getaline ())
    return 0;
  buff = A4GL_find_contents (ibuff);
  A4GL_debug("buff=%s",buff);
  blen=strlen(buff);
  A4GL_debug("blen=%d",blen);
  //blen=blen/2;
  blen+=2;
  pptr = malloc (blen);
  memset(pptr,0,blen);
  buffer[2] = 0;
  b = 0;

  for (a = 0; a < strlen (buff); a ++)
    {
      c=buff[a];
      if (c=='&') {
		/* Special XML characters 
		&lt; < less than 
		&gt; > greater than
		&amp; & ampersand
		&apos; ' apostrophe
		&quot; " quotation mark */

		if (strncmp(&buff[a],"&lt;",4)==0)   { a+=3;pptr[b++]='<'; pptr[b]=0;continue;  }
		if (strncmp(&buff[a],"&nl;",4)==0)   { a+=3;pptr[b++]='\n'; pptr[b]=0;continue;  }
		if (strncmp(&buff[a],"&gt;",4)==0)   { a+=3;pptr[b++]='>'; pptr[b]=0;continue; }
		if (strncmp(&buff[a],"&amp;",5)==0)  { a+=4;pptr[b++]='&'; pptr[b]=0;continue; }
		if (strncmp(&buff[a],"&apos;",6)==0) { a+=5;pptr[b++]='\''; pptr[b]=0;continue; }
		if (strncmp(&buff[a],"&quot;",6)==0) { a+=5;pptr[b++]='"'; pptr[b]=0;continue; }

      } else {
      		pptr[b++] = c;
      		pptr[b] = 0;
      }
    }
  *val = pptr;
  return contentok;
}

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_input_double (char *name, double *val, int ptr, int isarr)
{
  /* <ATTR NAME=\"%s\" TYPE=\"DOUBLE\"%s>%f</ATTR> */
  chk (val);
 A4GL_debug("input_double : ptr=%d\n",ptr);
  if (!getaline ())
    return 0;
  *val = atof (A4GL_find_contents (ibuff));
  return contentok;
}

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_input_start_struct (char *s, char *n, int ptr, int isarr)
{
  /* <STRUCT NAME=".." TYPE=".."> */
  if (!getaline ())
    return 0;
  return 1;
}

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_input_end_struct (char *s, char *n)
{
  /* </STRUCT> */
  if (!getaline ())
    return 0;

  return 1;
}

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_input_start_union (char *s, char *en, int *e,char *n, int ptr, int isarr)
{
int a;
  /*   <UNION NAME=".." TYPE=".."> */
a=A4GLPacker_input_int (en, e, ptr, isarr);
if (!a) return 0;

if (!getaline ())
    return 0;


  return 1;
}

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_input_ptr_ok ()
{
/* Should be either :
       <ATTR NAME=".." TYPE="NULLPTR"/>
       <ATTR NAME=".." TYPE="PTR"/>
*/
  if (!getaline ())
    return 0;

  if (strstr (ibuff, "NULLPTR"))
    return 0;
  return 1;
}

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_input_end_union (char *s, char *en, int e,char *n)
{
  /* </UNION> */
  if (!getaline ())
    return 0;
  return 1;
}

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_input_enum (char *rn, char *name, int *d)
{
  chk (d);
  /* <ENUM TYPE=\"%s\" DESCRIPTION=\"%s\" VALUE=\"%d\"/> */
  if (!getaline ())
    return 0;
  *d = atoi (A4GL_find_attr (ibuff, "VALUE"));
  return attrok;
}

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_A4GL_can_pack_all (char *name)
{
  return 0;
}

char *A4GLPacker_A4GL_get_packer_ext(void) {
  	return acl_getenv ("A4GL_XML_EXT");
}

void A4GLPacker_A4GL_output_common_header(char* module,char* version) {
	fprintf (outfile,"<!-- Aubit4GL data file Type %s Version %s -->\n",module,version);
}

int A4GLPacker_A4GL_valid_common_header(char* module,char* version) {
	char m[200]="";
	char v[200]="";
	char buff[200]="Wrong header";
	int i;
	int ok=1;
	if (!getaline()) {
		return 0;
	}
	i=sscanf(ibuff,"<!-- Aubit4GL data file Type %s Version %s -->",m,v);
	if (i!=2) { 
		ok=0;
	} else {
		if (strcmp(module,m)!=0) {ok=0;strcpy(buff,"Wrong filetype");}
		if (strcmp(version,v)!=0) {ok=0; strcpy(buff,"Wrong version");}
	}
	if (!ok) {
		A4GL_set_errm(buff);
		A4GL_exitwith("Invalid file (%s)");
		return 0;
	} else {
        	return 1;
	}
	
}


/* ============================== EOF ================================ */
