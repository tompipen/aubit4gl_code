#include "a4gl_lib_lex_esqlc_int.h"
#ifndef lint
	static char const module_id[] =
		"$Id: bad_idents.c,v 1.10 2008-02-11 17:13:11 mikeaubury Exp $";
#endif

char *reserved_words_in_c[] = {
  "asm",
  "auto",
  "break",
  "case",
  "char",
  "const",
  "continue",
  "default",
  "do",
  "double",
  "else",
  "enum",
  "extern",
  "float",
  "for",
  "goto",
  "if",
  "int",
  "long",
  "register",
  "return",
  "short",
  "signed",
  "sizeof",
  "static",
  "struct",
  "switch",
  "typedef",
  "union",
  "unsigned",
  "void",
  "volatile",
  "while",
  "bool",
#ifdef _cplusplus
  "catch",
  "inline",
  "template",
  "class",
  "new",
  "this",
  "delete",
  "operator",
  "throw",
  "except",
  "private",
  "try",
  "finally",
  "protected",
  "virtual",
  "friend",
  "public",
#endif
  0
};

int
A4GL_bad_identifiers (char *s)
{
  int a;
  for (a = 0; reserved_words_in_c[a]; a++)
    {
      if (strcasecmp (s, reserved_words_in_c[a]) == 0)
	return 1;
    }
  return 0;
}
