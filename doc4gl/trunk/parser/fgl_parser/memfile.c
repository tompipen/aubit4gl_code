
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
# $Id: memfile.c,v 1.3 2004-01-06 22:50:00 saferreira Exp $
#
*/

/**
 * @file
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "memfile.h"

static int opened = 0;

/** The buffer where the file is loaded to */
static char *buff;

/** Length of the buffer where the file was readed to */
long buff_len;

/** The FILE structure where the file is opened */
static FILE *in;

/** The current position in the buffer */
long pos = 0;


/**
 * Open the file and readit all to a buffer in memory.
 * When it arrives here assume that validations are allready made.
 *
 * @param f The name of the file to be readed.
 * @param mode The mode to open the file.
 * @return A pointer to the FILE structure.
 */
int A4GL_memfile_fopen (const char *f)
{
  in = fopen (f, "rb");

	// @todo : When in C++ this should be an exception
  if (in == 0)
    return 0;

  fseek (in, 0, SEEK_END);
  buff_len = ftell (in);
  buff = (char *) malloc (buff_len + 1);
  rewind (in);

  if (fread (buff, buff_len, 1, in) != 1)
	{
	  // @todo : When in C++ this should be an exception
	  printf ("Unable to read file into buffer\n");
		return 0;
	}

  pos = 0;
	opened++;
  return 1;
}


/**
 *  FSeek a position in the file or the memory buffer.
 *  @todo : The read from the FILE it is not necessary. Remove the code
 *
 *  @param f The file pointer. To remove because it is not necessary
 *  @param offset The offset position where it want to be positioned.
 *  @param whence A flag that defines the relativity of the position.
 *  @return 
 *    0 - Seeked.
 *    1 - Whence error.
 */
int A4GL_memfile_fseek (long offset, int whence)
{
  if (whence == SEEK_SET)
	{
	  pos = offset;
	  return 0;
	}
  if (whence == SEEK_END)
	{
	  pos = buff_len - offset;
	  return 0;
	}
  if (whence == SEEK_CUR)
	{
	  pos += offset;
	  return 0;
	}
  return 1;
}


/**
 * Get a caracter from the buffer from where the file was loaded.
 *
 * @return The caracter readed.
 */
int A4GL_memfile_getc (void)
{
  int a;
  a = buff[pos];
  pos++;
  return a;
}


/**
 *  Acts like if the file was closed.
 */
void
A4GL_memfile_fclose (void)
{
  opened--;
  free (buff);
}

/**
 *  Position in the begining of the buffer that contains the loaded file
 */
void A4GL_memfile_rewind (void)
{
  pos = 0;
}

/**
 * Return the position in the input memeory source where it positioned at
 * a specific time
 */
long
A4GL_memfile_ftell (void)
{
  return pos;
}

/**
 * Unget a caracter from the memory buffer.
 * It just decrement the current position counter
 *
 * @param c The caracter to be ungeted.
 * @return Allaways 0
 */
int
A4GL_memfile_ungetc (int c)
{
  pos--;
  return 0;
}

/**
 * Checks if the position is outside the buffer 
 *
 * @return
 *   0 - It is inside the buffer.
 *   1 - It is outside the buffer
 */
int
A4GL_memfile_feof (void)
{
   return pos > buff_len;
}

/**
 * Get the length of caracters of the source loaded to the buffer.
 *
 * @return The length of the buffer
 */
int
A4GL_memfile_getLength()
{
  return pos;
}
