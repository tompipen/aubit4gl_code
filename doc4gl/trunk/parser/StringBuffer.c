
/**
 * @file
 * Functions to String Buffer management.
 */

#include "StringBuffer.h"

/**
 * Allocates and initialize a new string buffer
 *
 * @return A pointer to the allocated string buffer
 */
StringBuffer *newStringBuffer(void)
{
  StringBuffer *sb;
	sb = constructStringBuffer();
	initStringBuffer(sb);
	return sb;
}

/**
 * Allocate space to a new StringBuffer.
 *
 * @return A pointer to the allocated memory to the string buffer.
 */
StringBuffer *constructStringBuffer(void)
{
	StringBuffer *sb;

	sb = (StringBuffer *)malloc(sizeof(StringBuffer));
	return sb;
}

/**
 * Initialize all the information of a string buffer.
 *
 * To create a new one you shold call construct and init
 *
 * @param sb Pointer para o string buffer a inicializar
 */
void initStringBuffer(StringBuffer *sb)
{
  sb->increment   = sizeof(char) * 512;
	sb->currentSize = sb->increment;
	sb->buffer      = (char *)malloc(sb->currentSize);
	*sb->buffer     = '\0';
}

/**
 * Appends the string buffer with a string at the end of the buffer.
 *
 * If it needs more space allocate it with a realoc.
 *
 * You should play some atention to the factor in order that this be faster.
 *
 * @param sb The string buffer to be appended.
 * @param str The string that we want to append in the buffer.
 */
void appendStringBuffer(StringBuffer *sb,char *str)
{
	int neededSize;
	int multFactor;
	int nBytes;

	if ( sb->buffer == (char *)0 )
	  neededSize = strlen(str);
  else
	  neededSize = strlen(str) + strlen(sb->buffer);

  if ( neededSize > sb->currentSize )
	multFactor = neededSize / sb->increment;
	if ( multFactor <= 0 )
	  multFactor = 1;
	if ( neededSize % sb->increment != 0 )
	  multFactor++;

	nBytes = multFactor * sb->increment * sizeof(char);
	if ( sb->buffer == (char *)0 )
	{
	  sb->buffer = (char *)malloc(nBytes);
	}
	else
	{
    if ( neededSize > sb->currentSize )
		{
	    sb->buffer = (char *)realloc(sb->buffer,nBytes);
			sb->currentSize = nBytes;
	  }
	}
  strcat(sb->buffer,str);
}

/**
 * Appends a char at the end of the string buffer.
 *
 * @param sb A pointer to the string buffer.
 * @param ch The character to append at the end of the string buffer.
 */
void appendCharStringBuffer(StringBuffer *sb,char ch)
{
  char str[2];

	str[0] = ch;
	str[1] = (char)0;
	appendStringBuffer(sb,str);
}

/**
 * Clean all the memory used by a string buffer.
 *
 * @param sb A pointer to the string buffer to be cleaned.
 */
void destroyStringBuffer(StringBuffer *sb)
{
	if ( sb->buffer != (char *)0 )
    free(sb->buffer);
	free(sb);
}

