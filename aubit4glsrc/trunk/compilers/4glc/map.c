/**
 * @file
 * Generation of map file.
 *
 * The map file is used to put in a file some mapping between the elements
 * in the 4gl source code and the line number module, etc.
 *
 * It is a file with pipe separated columns and \n separated records
 */

#include <stdio.h>
#include "a4gl_aubit_lib.h"
#include "../../lib/libincl/debug.h"

/// The map file pointer opened file
static FILE *mapfile = 0;

/**
 * Open the map file.
 *
 * If the environment variable MAP4GL is assigned with Y open the file
 * Downt do nothing otherwise
 *
 * @param s The map file name
 */
void openmap (char *s)
{
  char buff[256];
  debug ("openmap...");
  if (strcmp (acl_getenv ("MAP4GL"), "Y") == 0 && mapfile==0)
    {
      debug ("Opening map file..%s \n", acl_getenv ("MAP4GL"));
      debug ("Yep...\n");
      sprintf (buff, "%s.map", s);
      mapfile = fopen (buff, "w");

      if (mapfile == 0)
	{
	  debug ("Unable to open map file");
	  printf ("Unable to open map file\n");
	  exit (1);
	}
      debug ("Mapfile=%p", mapfile);
    }
}

/**
 * Add a new map to the opened file.
 *
 * Just adds if the mapfile was opened (controled by environment variable
 * MAP4GL)
 *
 * @param t The x4gl element type
 * @param s The name of the element
 * @param w The scope where the element was declared
 *    - MAIN 
 *    - MODULE
 *    - Function name
 * @param l The line number in the source code where the implementation was
 *          started.
 * @param m The x4gl module name
 */
addmap (char *t, char *s, char *w, int l, char *m)
{
  debug ("Adding to map... %p", mapfile);
  if (mapfile)
    fprintf (mapfile, "%s|%s|%s|%d|%s|\n", t, s, w, l, m);
}

/**
 * Close the map file
 */
void closemap (void)
{
  if (mapfile)
    fclose (mapfile);
}
