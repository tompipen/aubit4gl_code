
/*   ===========================================================================
 *   Module       : %M%
 *   Object       : 
 *   SCCS Id      : %W%
 *   Full Path    : %P%
 *   Release date : %D%
 *
 *
 *   p4glpp : Informix 4gl language pre-processor
 *
 *   Author : Sergio Ferreira
 *   ===========================================================================
 */

#include <stdio.h>

/// As funções iniciam-se em 10 que é o nº máximo de funções incluidas 
int  Functions=10;                   /* Number of Functions Found     */
FILE *param_out;
extern FILE *yyin;
extern FILE *yyout;

main(argc,argv)
int argc;
char *argv[];
{

	if ( argc != 4 )
	{
		printf("Usage : p4glpp source_file_name src_temp_file_name param_file\n");
		exit(1);
	}

  yyin = fopen(argv[1],"r");  //source_file_name
	if ( yyin == (FILE *)0 )
	{
		printf("p4glpp: Error opening file (%s)\n",argv[1]);
		perror("");
		exit(1);
	}

   yyout = fopen(argv[2],"w");  //src_temp_file_name
	if ( yyout == (FILE *)0 )
	{
		printf("p4glpp: %s, Error opening file (%s)\n", argv[1],argv[2]);
		perror("");
		exit(1);
	}

   param_out = fopen(argv[3],"w");  //param_file
	if ( param_out == (FILE *)0 )
	{
		printf("p4glpp: %s, Error opening file (%s)\n", argv[1],argv[3]);
		perror("");
		exit(1);
	}

	/* As funções iniciam-se em 10 que é o nº máximo de funções incluidas */
	/*`ISTO É TEMPORÁRIO */
  Functions = 10;

	if( yylex() !=0 )    /* Pre-processamento, feito pelo lex */
	{
		printf("P4glpp: %s Preprocessing failed\n", argv[1]);
		exit(1);
   }
	fclose(param_out);
	fclose(yyout);
}


/* 
 * Encontrou EOF
 */
yywrap()
{
  if ( Functions <= 0 ) Functions = 1;
  fprintf(param_out, "FUNCTIONS=%d\n",Functions);
  return(1);
}
