


%{

/* C code */

#define YY_INPUT(buf,result,max_size) \
{\
  int c = getCommentChar(); \
	result = ( c==EOF) ? YY_NULL: (buf[0] = c,1); \
}


%}

separator [ \t]+
alpha [a-zA-Z_]
alnum [a-zA-Z_0-9]


%%

"@process" { startProcess(); }

"@param" { startParameter(); }

"@return" { startReturn(); }

"@todo" { startTodo(); }

"@"[aA]"uthor" { startAuthor(); }

"@revision" { startRevision(); }
"@version" { startRevision(); }

{alpha}{alnum}* { writeCommentIdentifier(yytext); }

{separator}  { writeSeparator(yytext); }
"\n" { writeNewLine(); }
. { writeOtherComment(yytext); }

%%


yyCommentwrap()
{
  return(1);
}
