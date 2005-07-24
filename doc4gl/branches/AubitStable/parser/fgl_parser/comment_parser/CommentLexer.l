


%{

/** 
 * @file
 * Lexer for fgldoc comment parsing.
 */

/**
 * Redifinition of default YY_INPUT to read from a string instead a file.
 */
#define YY_INPUT(buf,result,max_size) \
{\
  int c = getCommentChar(); \
	result = ( c==EOF) ? YY_NULL: (buf[0] = c,1); \
}


%}

separator [ \t]+
alpha [a-zA-Z_]
alnum [a-zA-Z_0-9]

%option c++

%%

"@file" { setModuleDocument(); }

"@process" { startProcess(); }

"@param" { startParameter(); }

"@return" { startReturn(); }

"@todo" { startTodo(); }

"@table" { startTable(); }

"@see" { startSee(); }
"@since" { startSince(); }

"@"[aA]"uthor" { startAuthor(); }

"@revision" { startRevision(); }
"@version" { startRevision(); }
"@deprecated" { markAsDeprecated(); }

{alpha}{alnum}* { writeCommentIdentifier(yytext); }

{separator}  { writeSeparator(yytext); }
"\n" { writeNewLine(); }
. { writeOtherComment(yytext); }

%%


yyCommentwrap()
{
  return(1);
}
