
/**
 * @file
 *
 * This class reads a file into memory and then it can serve the file
 * caracter by caracter.
 *
 * It was converted to OO from the original code of Mike Aubury in 
 * aubit 4gl memfile.c
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MemFile.h"


/**
 * Default constructor
 */
MemFile::MemFile() 
{
  opened = 0;
	pos = 0;
}

/**
 * Open the file and readit all to a buffer in memory.
 * When it arrives here assume that validations are allready made.
 *
 * @param f The name of the file to be readed.
 * @param mode The mode to open the file.
 * @return A pointer to the FILE structure.
 */
int MemFile::fopen (const char *f)
{
  in = ::fopen (f, "rb");

	// @todo : This should be an exception and not a return
  if (in == 0) 
    return 0;

  ::fseek (in, 0, SEEK_END);
  buff_len = ::ftell (in);
  buff = (char *) malloc (buff_len + 1);
  ::rewind (in);

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
int MemFile::fseek (long offset, int whence)
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
int MemFile::getchar(void)
{
  int a;
  a = buff[pos];
  pos++;
  return a;
}


/**
 *  The destruction of the object.
 *  Free(s) the buffer to where the source was readed.
 */
MemFile::~MemFile()
{
  free (buff);
}

/**
 *  Position in the begining of the buffer that contains the loaded file
 */
void MemFile::rewind (void)
{
  pos = 0;
}

/**
 * Return the position in the input memeory source where it positioned at
 * a specific time
 */
long
MemFile::ftell (void)
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
MemFile::ungetchar(int c)
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
MemFile::feof (void)
{
   return pos > buff_len;
}

/**
 * Get the length of caracters of the source loaded to the buffer.
 *
 * @return The length of the buffer
 */
int
MemFile::getLength()
{
  return pos;
}
