%{
#include <string.h>
#include <stdio.h>

#include "est_dat.h"
#include "gramat.h"

tabla_id procesa_identificador(char *s);
%}

blanco [ \t\n]+
digito [0-9]
letra  [a-zA-Z_]
ident  {letra}({letra}|{digito})*

%x CODIGO
%%

{blanco}                 ;

\%union            {return(UNION);}

\%type             {return(TIPO);}

\%\{               {BEGIN(CODIGO);
		    return(TP_LLAVE_A);}

::                 {return(PROD);}

\%\%               {return(TP_TP);}

{ident}            {yylval.id_ref = procesa_identificador(yytext);
		    return(ID);}

.                  {return(yytext[0]);}

<CODIGO>\%\}       {BEGIN(0);
		    return(TP_LLAVE_C);}

<CODIGO>.          {yylval.caract = yytext[0];
		    return(CARACTER);} 

<CODIGO>\n         {yylval.caract = yytext[0];
		    return(CARACTER);} 
				   
%%
		              
tabla_id procesa_identificador(char *s)
{
 tabla_id id_ref;

 if(strlen(s) >= TAM_CAD)
  {
   fprintf(stderr,"\nhesa: El tama¤o m ximo de los identificadores es %i\n",
		  TAM_CAD);
   exit(1);
  }
 id_ref = instala_simb(s);
 return(id_ref);
}
