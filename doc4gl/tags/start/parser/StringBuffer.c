

#include "StringBuffer.h"

/**
 * Métodos que permitem o manuseamento de string buffers
 */

/**
 * Inicializações de default do string buffer
 */
StringBuffer *constructStringBuffer()
{
	StringBuffer *sb;

	sb = (StringBuffer *)malloc(sizeof(StringBuffer));
	return sb;
}

/**
 * Inicialização 
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
 * Concatena uma string no final do string buffer alocando, se necessário
 * mais espaço em memória
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
 * Concatena um carater a um string buffer 
 */
void appendCharStringBuffer(StringBuffer *sb,char ch)
{
  char str[2];

	str[0] = ch;
	str[1] = (char)0;
	appendStringBuffer(sb,str);
}

/**
 * Limpa a memória ocupada por um string buffer e reinicializa-o com 
 * os defaults
 */
void destroyStringBuffer(StringBuffer *sb)
{
	if ( sb->buffer != (char *)0 )
    free(sb->buffer);
	initStringBuffer(sb);
}

