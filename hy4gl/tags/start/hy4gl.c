#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdarg.h>
#include <ncurses.h>
#include "global.h"
#include "asa.h"
#include "prototipos.h"

int yylineno;
int yycolno;
extern char *yytext;
char yyfilename[255];
extern int yyparse();
extern FILE *yyin;
int numerrores=0;
Arbol raiz=NULL,lst_funciones=NULL,lst_param=NULL,db=NULL;
Arbol lst_extern=NULL,lst_globales=NULL,lst_locales=NULL;
FILE *fp;
int indentacion;
int sw_warning=1;
int sw_verfuente=0;

int yyerror(char *fmt,...)
{
   va_list args;
   char linea[256];
   /*Copio la lista de parámetros recibidos */
   va_start (args, fmt);
   vsprintf (linea, fmt, args);
   va_end (args);
   /* La imprimo */
   if (!strcmp(linea,"syntax error"))
   {
      sprintf(linea,"syntax error (%s)",yytext);
   }
   
   fprintf(stderr,"\r%s:%d: %s\n",yyfilename,yylineno,linea);
   numerrores++;
   return 0;
//  exit(0);  //sustituye al return.
}                  

/* Funcion que comprueba si existe una var
   tanto entre las vars locales, parametros y globales */
Arbol Existe_Var(char *id)
{
   Arbol aux=NULL;
   Arbol encontrado;
   /* Si estoy buscando un campo, es distinto... */
   if (strchr(id,'.'))
   {
      cadena reg,campo;
      /* Primero busco que exista el registro */
      memset(reg,0,sizeof(reg));
      memset(campo,0,sizeof(campo));
      
      strncpy(reg,id,strcspn(id,"."));
      strcpy(campo,id+strlen(reg)+1);
      encontrado=Existe_Var(reg);
      if (encontrado)
      {
          if (!strcmp(Identificador_nombre(Tipo_tip(Variable_tip(encontrado))),"record"))
          {  /* Busco el campo */
             aux=Busca_Var(campo,Tipo_cam(Variable_tip(encontrado)));
          }
      }
   }
   else
   {
       aux=Busca_Var(id,lst_locales);
       if (!aux)
          aux=Busca_Var(id,lst_globales);
       if (!aux)
          aux=Busca_Var(id,lst_extern);
   }
   return aux;
}
/* Funcion que busca un simbolo en una tabla de simbolos */
/* Si lo encuentra, devuelve un nodo con su desc. Si no, devuelve NULL */
Arbol Busca_Var(char *id,Arbol ptr)
{
   Arbol aux=NULL, encontrado=NULL;
   int i,cuantas;
   
   cuantas=Variables_longitud(ptr);
   for (i=0;i<cuantas;i++)
   {
      aux=Variables_elemento(ptr,i+1);
      if (!Constructor(aux))
         break;
      if (!strcmp(Identificador_nombre(Variable_nom(aux)),id))
      {
         encontrado=aux;
         break;
      }
   }
   return encontrado;
}

Arbol Busca_Fun(char *id)
{
   Arbol aux=NULL, encontrado=NULL;
   int i,cuantas;
   
   cuantas=Funciones_longitud(lst_funciones);
   for (i=0;i<cuantas;i++)
   {
      aux=Variables_elemento(lst_funciones,i+1);
      if (!Constructor(aux))
         break;
      if (!strcmp(Identificador_nombre(Funcion_nom(aux)),id))
      {
         encontrado=aux;
         break;
      }
   }
   return encontrado;
}


Arbol Asigna_valor(double b)
{
 Arbol aux;
 aux=Constante();
 aux->atributo.valor=b;
 return aux;
}

Arbol Asigna_nombre(char *b)
{
 Arbol aux;
 aux=Identificador();
 strcpy(aux->atributo.nombre,b);
 return aux;
}

void main(int argc, char *argv[])
{
    cadena fichero="";
    cadena generado="";
    cadena salida="";

    /* Preparo la lista de variables globales iniciales */
    lst_globales=Variables(lst_globales,
       Variable(Asigna_nombre("_i"),
       Tipo(Asigna_nombre("int"),
          Asigna_valor(0),NULL)));
    lst_extern=Variables(lst_extern,
       Variable(Asigna_nombre("status"),
       Tipo(Asigna_nombre("int"),
          Asigna_valor(0),NULL)));
    lst_extern=Variables(lst_extern,
       Variable(Asigna_nombre("notfound"),
       Tipo(Asigna_nombre("int"),
          Asigna_valor(0),NULL)));
    lst_extern=Variables(lst_extern,
       Variable(Asigna_nombre("found"),
       Tipo(Asigna_nombre("int"),
          Asigna_valor(0),NULL)));
    lst_extern=Variables(lst_extern,
       Variable(Asigna_nombre("ok"),
       Tipo(Asigna_nombre("int"),
          Asigna_valor(0),NULL)));
    lst_extern=Variables(lst_extern,
       Variable(Asigna_nombre("arg_count"),
       Tipo(Asigna_nombre("int"),
          Asigna_valor(0),NULL)));
    lst_extern=Variables(lst_extern,
       Variable(Asigna_nombre("_arg_val"),
       Tipo(Asigna_nombre("char **"),
          Asigna_valor(0),NULL)));
          
    if (getenv("HYVERB"))
       sw_verfuente=1;
       
    printf("\nhy4gl V.%s. (c)1998 David Prieto\n",VERSION);
    printf("------------------------------------------\n");
    
    if (argc<2 || !strlen(argv[1]))
    {
      fprintf(stderr,"Error. Debe indicar un nombre de fichero\n");
      exit(1);
    }
    strcpy(fichero,argv[1]);
    strncpy(salida,fichero,strcspn(fichero,"."));
    strcpy(generado,salida);
    strcat(generado,".c");
    if ((yyin=fopen(fichero,"r"))!=NULL)
    {
       yylineno=1;
       yycolno=1;
       strcpy(yyfilename,fichero);
       yyparse();
       printf("\r                          ");
       fclose(yyin);
    }
    else
    {
       strcat(fichero,".4gl");
       if ((yyin=fopen(fichero,"r"))!=NULL)
       {
          yylineno=1;
          yycolno=1;
          strcpy(yyfilename,fichero);
          yyparse();
          printf("\r                          ");
          fclose(yyin);
       }
       else
       {       
          fprintf(stderr,"\nError. No puede abrirse fichero de entrada.\n");
          exit(1);
       }
    }

    if (numerrores==0)
    {
       printf("\rPrograma sin errores sintacticos.\n");
       printf("Generando código...\n");
       genCodigo(generado);
    }
    else
    {
       printf("\nSe han encontrado errores.\n\n");
       exit(1);
    }
    printf("\n");
    exit(0);
}

