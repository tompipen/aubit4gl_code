/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-1 Aubit Development Team (See Credits file)       |
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
# | contact afalout@ihug.co.nz                                           |
# +----------------------------------------------------------------------+
#
# $Id: pack_xml.c,v 1.11 2003-05-12 14:24:23 mikeaubury Exp $
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

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

char *find_attr (char *s, char *n);	/* Extract a specified attribute from a string */
char *find_contents (char *s);	/* Extract the tag contents from a string */

/*
--------------------------------
 Internal helper functions
--------------------------------
*/
static void chk (void *x);

void print_level (void);
char *pr_elem (int a, int p);


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
pr_elem (int a, int p)
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
find_attr (char *s, char *n)
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
find_contents (char *s)
{
  static char buff[2000];
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


/**
 *
 * @todo Describe function
 */
int
open_packer (char *basename, char dir)
{
  char buff[256];

  sprintf (buff, "Basename=>%s< dir=%c\n", basename, dir);
  debug (buff);
  sprintf (buff, "%s%s", basename, acl_getenv ("A4GL_XML_EXT"));
  debug (buff);

  if (toupper (dir) == 'O')
    {
      /* write XML file */
      outfile = fopen (buff, "w");
      if (outfile)
	{
	  set_last_outfile (buff);
	  fprintf (outfile, "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n");
	  return 1;
	}
      else
	{
	  exitwith ("Unable to open form");
	  return 0;
	  //exit (46);
	}
    }

  if (toupper (dir) == 'I')
    {
      /* read XML file */
      infile = open_file_dbpath (buff);
      if (infile == 0)
	{
	  exitwith ("Unable to open form");
	  return 0;
	  //exit (45);
	}

      /* Get rid of the ?xml line at the beginning */
      fgets (buff, sizeof (buff), infile);

      if (infile)
	return 1;

    }

  debug ("Error in open_packer()\n");

  return 0;


}

/**
 *
 * @todo Describe function
 */
void
close_packer (char dir)
{
  debug ("In close_packer()");

  if (toupper (dir) == 'O')
    fclose (outfile);

  if (toupper (dir) == 'I')
    fclose (infile);

  debug ("exiting close_packer()");
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
output_start_array (char *s, int type, int len)
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
output_end_array (char *s, int type)
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
output_int (char *name, int val, int ptr, int isarr)
{
  print_level ();
  fprintf (outfile, "<ATTR NAME=\"%s\" TYPE=\"INTEGER\"%s>%d</ATTR>\n", name,
	   pr_elem (isarr, ptr), val);
  return 1;
}

/**
 *
 * @todo Describe function
 */
int
output_long (char *name, long val, int ptr, int isarr)
{
  print_level ();
  fprintf (outfile, "<ATTR NAME=\"%s\" TYPE=\"LONG\"%s>%d</ATTR>\n", name,
	   pr_elem (isarr, ptr), (int) val);
  return 1;
}


/**
 *
 * @todo Describe function
 */
int
output_bool (char *name, int val, int ptr, int isarr)
{
  print_level ();
  fprintf (outfile, "<ATTR NAME=\"%s\" TYPE=\"BOOL\"%s>%d</ATTR>\n", name,
	   pr_elem (isarr, ptr), val);
  return 1;
}

/**
 *
 * @todo Describe function
 */
int
output_string (char *name, char *val, int ptr, int isarr)
{
  int a;
//char buff[10];
  print_level ();
  debug ("in output_string() outfile=%p\n", outfile);

  fprintf (outfile, "<ATTR NAME=\"%s\" TYPE=\"STRING\"%s>", name,
	   pr_elem (isarr, ptr));
  for (a = 0; a < strlen (val); a++)
    {
      fprintf (outfile, "%02x", val[a]);
    }
  fprintf (outfile, "</ATTR>\n");

  debug ("exit output_string()\n");

  return 1;
}

/**
 *
 * @todo Describe function
 */
int
output_double (char *name, double val, int ptr, int isarr)
{
  print_level ();
  fprintf (outfile, "<ATTR NAME=\"%s\" TYPE=\"DOUBLE\"%s>%f</ATTR>\n", name,
	   pr_elem (isarr, ptr), val);
  return 1;
}

/**
 *
 * @todo Describe function
 */
int
output_start_struct (char *s, char *n, int ptr, int isarr)
{
  print_level ();
  fprintf (outfile, "<STRUCT NAME=\"%s\" TYPE=\"%s\"%s>\n", n, s,
	   pr_elem (isarr, ptr));
  level++;
  return 1;
}

/**
 *
 * @todo Describe function
 */
int
output_end_struct (char *s, char *n)
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
output_start_union (char *s, char *n, int ptr, int isarr)
{
  print_level ();
  fprintf (outfile, "<UNION NAME=\"%s\" TYPE=\"%s\"%s>\n", n, s,
	   pr_elem (isarr, ptr));
  level++;
  return 1;
}

/**
 *
 * @todo Describe function
 */
int
output_nullptr (char *s)
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
output_okptr (char *s)
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
output_end_union (char *s, char *n)
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
output_enum (char *name, char *s, int d)
{
  print_level ();
  fprintf (outfile, "<ENUM TYPE=\"%s\" DESCRIPTION=\"%s\" VALUE=\"%d\"/>\n",
	   name, s, d);
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
  a = fgets (ibuff, sizeof (ibuff), infile);

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
input_start_array (char *s, int type, int *len)
{
  /* <ARRAY NAME=".." TYPE=".." LENGTH=".."> */
  if (!getaline ())
    return 0;
  chk (len);
  *len = atoi (find_attr (ibuff, "LENGTH"));
  return (attrok);
}

/**
 *
 * @todo Describe function
 */
int
input_end_array (char *s, int type)
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
input_int (char *name, int *val, int ptr, int isarr)
{
  int a;
  /*   <ATTR NAME=%s TYPE=INTEGER%s>%d</ATTR> */
  chk (val);
  if (!getaline ())
    return 0;
  a = atoi (find_contents (ibuff));
  *val = a;


  return contentok;
}

/**
 *
 * @todo Describe function
 */
int
input_long (char *name, long *val, int ptr, int isarr)
{
  /* <ATTR NAME=\"%s\" TYPE=\"LONG\"%s>%d</ATTR> */

  chk (val);

  if (!getaline ())
    return 0;
  *val = atoi (find_contents (ibuff));
  return contentok;
}


/**
 *
 * @todo Describe function
 */
int
input_bool (char *name, int *val, int ptr, int isarr)
{
  /* <ATTR NAME=\"%s\" TYPE=\"BOOL\"%s>%d</ATTR> */

  chk (val);
  if (!getaline ())
    return 0;
  *val = atoi (find_contents (ibuff));
  return contentok;
}


/**
 *
 * @todo Describe function
 */
int
input_string (char *name, char **val, int ptr, int isarr)
{
  char *buff;
  char *pptr;
  char buffer[3];
  char c;
  int b;
  int a;
  /* <ATTR NAME=\"%s\" TYPE=\"STRING\"%s>%s</ATTR> */

  chk (val);
  if (!getaline ())
    return 0;
  buff = find_contents (ibuff);
  pptr = malloc ((strlen (buff) / 2) + 1);
  buffer[2] = 0;
  b = 0;
  for (a = 0; a < strlen (buff); a += 2)
    {
      buffer[0] = buff[a];
      buffer[1] = buff[a + 1];
      sscanf (buffer, "%02x", &c);
      pptr[b++] = c;
      pptr[b] = 0;
    }
  *val = pptr;
  return contentok;
}

/**
 *
 * @todo Describe function
 */
int
input_double (char *name, double *val, int ptr, int isarr)
{
  /* <ATTR NAME=\"%s\" TYPE=\"DOUBLE\"%s>%f</ATTR> */
  chk (val);
  if (!getaline ())
    return 0;
  *val = atof (find_contents (ibuff));
  return contentok;
}

/**
 *
 * @todo Describe function
 */
int
input_start_struct (char *s, char *n, int ptr, int isarr)
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
input_end_struct (char *s, char *n)
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
input_start_union (char *s, char *n, int ptr, int isarr)
{
  /*   <UNION NAME=".." TYPE=".."> */
  if (!getaline ())
    return 0;
  return 1;
}

/**
 *
 * @todo Describe function
 */
int
input_ptr_ok ()
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
input_end_union (char *s, char *n)
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
input_enum (char *name, int *d)
{
  chk (d);
  /* <ENUM TYPE=\"%s\" DESCRIPTION=\"%s\" VALUE=\"%d\"/> */
  if (!getaline ())
    return 0;
  *d = atoi (find_attr (ibuff, "VALUE"));
  return attrok;
}

/**
 *
 * @todo Describe function
 */
int
can_pack_all (char *name)
{
  return 0;
}

/* ============================== EOF ================================ */
