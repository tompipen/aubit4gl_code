/**
 * @file
 * Header for types and function prototypes of String Buffer implementation
 */


/** 
 * Dynamic String buffer 
 */
typedef struct
{
	int increment;
  int currentSize;
	char *buffer;
}StringBuffer;

StringBuffer *newStringBuffer(void);
StringBuffer *constructStringBuffer(void);
void initStringBuffer(StringBuffer *sb);
void appendStringBuffer(StringBuffer *sb,char *str);
void appendCharStringBuffer(StringBuffer *sb,char ch);
void destroyStringBuffer(StringBuffer *sb);
