/******** Generaci¢n  de c¢digo para el compilador.*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <ncurses.h>

#ifdef KEEPNCURSESBOOL
//To prevent redeclaration of bool in PostgreSQL c.h:
#define bool
#endif

#include <postgres.h>
#undef bool


#include <libpq-fe.h>
#include "global.h"
#include "asa.h"
#include "prototipos.h"

extern char yyfilename[255];
extern int numerrores;
extern Arbol raiz,lst_funciones;
extern Arbol lst_extern,lst_globales, lst_locales, lst_param,db;
extern FILE *fp;
extern int indentacion;
extern int en_select;
extern int sw_warning;
extern int sw_verfuente;
extern int numInputByName;
extern Arbol InputByNameArbol;
int numFor=0, maxFor=0;
int numWhile=0,maxWhile=0;
int numForeach=0,maxForeach=0;
int numBrowse=0,maxBrowse=0;
int numMenu=0,maxMenu=0;
int numPrompt=0,maxPrompt=0;

char *nom_menu="";

/* Devuelve una cadena con el tipo de una expresion */
enum tipos tipo_exp(Arbol exp)
{
   enum tipos res;
   enum tipos t1,t2;
   res=TIPO_VOID;
   switch (Constructor(exp))
   {
      case LLAMADA:
         res=tipo_fun(Identificador_nombre(Llamada_nom(exp)));
         break;
      case ID:
         res=tipo_var(Identificador_nombre(Id_nom(exp)));
         break;
      case CADENA:
      case SUBCADENA:
      case USING:
      case CLIPPED:
         res=TIPO_STR;
         break;
      case CONST:
         if (!strcmp(Identificador_nombre(Const_tip(exp)),"ENTERO"))
            res=TIPO_INT;
         else if (!strcmp(Identificador_nombre(Const_tip(exp)),"REAL"))
            res=TIPO_FLOAT;
         break;
      case BINARIA:
         t1=tipo_exp(Binaria_termi(exp));
         t2=tipo_exp(Binaria_termd(exp));
         switch(t1)
         {
         	case TIPO_INT:
               res=t2;
               break;
         	case TIPO_FLOAT:
               switch (t2)
               {
                  case TIPO_INT:
                  case TIPO_FLOAT:
                     res=TIPO_FLOAT;
                     break;
                  default: 
                     res=t2;
               }
               break;
            case TIPO_STR:
               res=TIPO_STR;
               break;
            case TIPO_DATE:
               switch (t2)
               {
               	case TIPO_INT:
                  case TIPO_FLOAT:
                     res=TIPO_DATE;
                     break;
                  case TIPO_STR:
                     res=TIPO_STR;
                     break;
                  case TIPO_DATE:
                     res=TIPO_INT;
                     break;
               }
         }
         break;
   }
   return res;
}

enum tipos tipo_fun(char *fun)
{
   Arbol aux;
   enum tipos res;
   res=TIPO_VOID;
   aux=Busca_Fun(fun);
   if (aux!=NULL)
   {
     	if (!strcmp(Identificador_nombre(Tipo_tip(Funcion_tip(aux))),"int"))
         res=TIPO_INT;
      else if (!strcmp(Identificador_nombre(Tipo_tip(Funcion_tip(aux))),"float"))
         res=TIPO_FLOAT;
      else if (!strcmp(Identificador_nombre(Tipo_tip(Funcion_tip(aux))),"char"))
         res=TIPO_STR;
   }
   return res;
}

enum tipos tipo_var(char *var)
{
   char *tipo;
   enum tipos res=TIPO_VOID;

   tipo=chr_tipo_var(var);
   if (tipo!=NULL)
   {
      if (!strcmp(tipo,"int"))
      	res=TIPO_INT;
      else if (!strcmp(tipo,"float"))
      	res=TIPO_FLOAT;
      else if (!strcmp(tipo,"char"))
         res=TIPO_STR;
      else if (!strcmp(tipo,"date"))
         res=TIPO_DATE;
      else if (!strcmp(tipo,"time"))
         res=TIPO_TIME;
      else if (!strcmp(tipo,"datetime"))
         res=TIPO_DATETIME;
      else if (!strcmp(tipo,"interval"))
         res=TIPO_INTERVAL;
      else if (!strcmp(tipo,"record"))
         res=TIPO_RECORD;
   }
   return res;   
}

char *chr_tipo_var(char *var)
{
   Arbol aux;
   char *res;
   aux=Existe_Var(var);
   if (aux!=NULL)
      res=Identificador_nombre(Tipo_tip(Variable_tip(aux)));
   else
      res=NULL;
   return res;
}

int tam_var(char *var)
{
   Arbol aux;
   int res=0;
   aux=Existe_Var(var);
   if (aux!=NULL)
   {
      res=Constante_valor(Tipo_tam(Variable_tip(aux)));
   }

   return res;   
}


Arbol tipo_campo_bd(char *tabla, char *campo)
{
   Arbol res=NULL;
   Arbol aux=NULL;
   PGconn *conn;
   PGresult *ress;
   cadena tipo,nombre;
   char query[8196];
   int longit,i,atttypmod;
   
   if (!db)
   {
      yyerror("No se ha especificado una base de datos");
      return res;
   }
     
   conn=PQsetdb(getenv("HY4GLHOST"),getenv("HY4GLPORT"),getenv("HY4GLOPTIONS"),
      getenv("4GLTTY"),Identificador_nombre(Database_nom(db)));
   if (PQstatus(conn)==CONNECTION_BAD)
   {
      yyerror("No se puede conectar con la base de datos '%s'\n%s",
         	Identificador_nombre(Database_nom(db)),
            PQerrorMessage(conn));
     
      exit(1);
   }
   
   if (campo!=NULL)	/* Pido un solo campo */
   {
      /* Busco este campo en el catalogo del sistema */
      sprintf(query,"select t.typname, a.attlen, a.atttypmod, a.oid from pg_class c, pg_attribute a, pg_type t
         where c.relname = '%s' and a.attname = '%s'
         and a.attnum > 0
         and a.attrelid = c.oid
         and a.atttypid = t.oid",tabla, campo);
      ress=PQexec(conn,query);
      if (PQresultStatus(ress)==PGRES_TUPLES_OK
         && PQntuples(ress)==1)
      {
      	strcpy(tipo,PQgetvalue(ress,0,0));
         longit=atol(PQgetvalue(ress,0,1));
         atttypmod=atol(PQgetvalue(ress,0,2));
        
         if ((!strncmp(tipo,"bpchar",6)) || (!strncmp(tipo,"varchar",7))) 
            longit = ((atttypmod != -1) ? atttypmod - VARHDRSZ : 0);
            
         if (!strncmp(tipo,"cha",3) || !strncmp(tipo,"bpchar",6))
            res=Tipo(Asigna_nombre("char"),Asigna_valor(longit),NULL);
         else if (!strncmp(tipo,"varchar",7))
            res=Tipo(Asigna_nombre("char"),Asigna_valor(1024),NULL);
         else if (!strncmp(tipo,"int",3) || !strncmp(tipo,"oid",3))
            res=Tipo(Asigna_nombre("int"),Asigna_valor(longit),NULL);
         else if (!strcmp(tipo,"date"))
            res=Tipo(Asigna_nombre("date"),Asigna_valor(0),NULL);
         else if (!strncmp(tipo,"float",5))
            res=Tipo(Asigna_nombre("float"),Asigna_valor(longit),NULL);
         else if (!strcmp(tipo,"datetime"))
            res=Tipo(Asigna_nombre("datetime"),Asigna_valor(longit),NULL);
         else if (!strcmp(tipo,"time"))
            res=Tipo(Asigna_nombre("time"),Asigna_valor(longit),NULL);
         else if (!strcmp(tipo,"tinterval") || !strcmp(tipo,"timespan"))
            res=Tipo(Asigna_nombre("interval"),Asigna_valor(longit),NULL);
         else 
         {
         	printf("Tipo %s no soportado (%s.%s)\n",tipo,tabla,campo);
            res=NULL;
         }
      }
      else
         yyerror("No se encuentra el campo %s en la tabla %s",campo,tabla);
   }
   else /* Si quiero el tipo del REGISTRO */
   {
      /* Busco esta tabla en el catalogo del sistema */
      sprintf(query,"select a.attname, t.typname, a.attlen, a.atttypmod, a.attnum from pg_class c, pg_attribute a, pg_type t
         where c.relname = '%s'
         and a.attnum > 0
         and a.attrelid = c.oid
         and a.atttypid = t.oid
         order by a.attnum",tabla);
      ress=PQexec(conn,query);
      if (PQresultStatus(ress)==PGRES_TUPLES_OK)
      {
         for (i=0; i<=PQntuples(ress)-1; i++)
         {
      	   strcpy(nombre,PQgetvalue(ress,i,0));
      	   strcpy(tipo,PQgetvalue(ress,i,1));
            longit=atol(PQgetvalue(ress,i,2));
            atttypmod=atol(PQgetvalue(ress,i,3));
            if ((!strncmp(tipo,"bpchar",6)) || (!strncmp(tipo,"varchar",7))) 
               longit=(atttypmod != -1 ? atttypmod - VARHDRSZ : 0);
            if (!strncmp(tipo,"cha",3) || !strncmp(tipo,"bpchar",6))
               aux=Variable(Asigna_nombre(nombre),
                  Tipo(Asigna_nombre("char"),Asigna_valor(longit),NULL));
            else if (!strncmp(tipo,"varchar",7))
               aux=Variable(Asigna_nombre(nombre),
                  Tipo(Asigna_nombre("char"),Asigna_valor(1024),NULL));
            else if (!strncmp(tipo,"int",3) || !strncmp(tipo,"oid",3))
               aux=Variable(Asigna_nombre(nombre),
                  Tipo(Asigna_nombre("int"),Asigna_valor(longit),NULL));
            else if (!strncmp(tipo,"float",3))
               aux=Variable(Asigna_nombre(nombre),
                  Tipo(Asigna_nombre("float"),Asigna_valor(longit),NULL));
            else if (!strcmp(tipo,"date"))
               aux=Variable(Asigna_nombre(nombre),
                  Tipo(Asigna_nombre("date"),Asigna_valor(longit),NULL));
            else if (!strcmp(tipo,"datetime"))
               aux=Variable(Asigna_nombre(nombre),
                  Tipo(Asigna_nombre("datetime"),Asigna_valor(longit),NULL));
            else if (!strcmp(tipo,"time"))
               aux=Variable(Asigna_nombre(nombre),
                  Tipo(Asigna_nombre("time"),Asigna_valor(longit),NULL));
            else if (!strcmp(tipo,"tinterval") || !strcmp(tipo,"timespan"))
               aux=Variable(Asigna_nombre(nombre),
                  Tipo(Asigna_nombre("interval"),Asigna_valor(longit),NULL));
            else 
            {
               printf("Tipo %s no soportado (%s.%s)\n",tipo,tabla,nombre);
               aux=NULL;
            }
            res=Variables(res,aux);
         }
         res=Tipo(Asigna_nombre("record"),Asigna_valor(0),res);
      }
      else
         yyerror("No se encuentra la tabla %s",tabla);
   }
   PQclear(ress);
   PQfinish(conn);
   return res;
}

/* Devuelve la lista de campos de un registro.
   Una lista de variables con los nombres: reg.campo1, reg.campo2...*/
Arbol Campos_reg(char *reg)
{
   Arbol aux,var,res;
   int i,cuantas;
   cadena nombre;
   
   res=NULL;
   var=Existe_Var(reg);
   if (var)
   {
      cuantas=Variables_longitud(Tipo_cam(Variable_tip(var)));
      for (i=0;i<cuantas;i++)
      {
         aux=Variables_elemento(Tipo_cam(Variable_tip(var)),i+1);
         if (!Constructor(aux))
            break;
         sprintf(nombre,"%s.%s",reg,Identificador_nombre(Variable_nom(aux)));
         res=ListaId(res,Id(Asigna_nombre(nombre)));
      }
   }
   return res;
}

void genCodigo(char *salida)
{
   en_select=0;
   if ((fp=fopen(salida,"w"))==NULL)

   {
      fprintf(stderr,"Error al abrir el fichero de salida (%s)\n",salida);
      exit(1);
   }

   genera(0,"/********************************************************/\n");
   genera(0,"/* Fuente: %-30.30s               */\n",yyfilename);
   genera(0,"/*------------------------------------------------------*/\n"); 
   genera(0,"/* Codigo generado por hy4gl.                           */\n");
   genera(0,"/* (c) 1998 David Prieto <davidp@sgth.es>               */\n");
   genera(0,"/********************************************************/\n\n\n");   
   genera(0,"#include <stdio.h>\n");
   genera(0,"#include <stdlib.h>\n");   
   genera(0,"#include <hy4gl.h>\n");
   genera(0,"#include <locale.h>\n");
   genera(0,"#include <ncurses.h>\n");   
   genera(0,"#include <panel.h>\n");
   genera(0,"#include <form.h>\n");
   genera(0,"#include <menu.h>\n");
   genera(0,"#include <libpq-fe.h>\n\n");

   genera(0,"/* Variables internas */\n");
   genera(0,"extern int _4GLy, _4GLx;\n");
   genera(0,"extern WINDOW *curwin;\n");
   genera(0,"extern _WINDOW *_curwin;\n");
   genera(0,"extern pila *pila_param;\n");
   genera(0,"extern pila *pila_exp;\n");
   genera(0,"extern int status, ok, notfound, found;\n");
   genera(0,"extern bool _4GLfechaEuro;\n");
   genera(0,"extern bool _4GLChkErrores;\n");
  
   if (db!=NULL)
   {
      genera(0,"extern PGconn *_conn;\n");
      genera(0,"extern _CURSOR _CurTmp;\n");
      genera(0,"extern char _SelTmp[8196];\n");
      genera(0,"extern char _WhereTmp[8196];\n\n");
   }
   
   if (lst_extern!=NULL)
   {
      genera(indentacion,"/* Variables de otros modulos */\n");
      genVariables(lst_extern,"extern ");
   }
   if (Fichero_var(raiz)!=NULL)
   {      
      genera(indentacion,"/* Variables Globales del Programa */\n");
		genera(0,"char _StrTmp[8196];\n");
      genVariables(Fichero_var(raiz),"");
   }  
   if (Fichero_fun(raiz)!=NULL)
      genFunciones();
   fclose(fp);
}

/* Esta función genera el código para desapilar los parámetros que
   recibe una función */
void genParams(Arbol vars)
{
   Arbol aux;
   int i,cuantas;
   int nargs;
   
   cuantas=ListaId_longitud(vars);

   /* Veo cuántos parámetros debe recibir la funcion
      (contanto cada campo de los registros que hubiera) */
   nargs=0;
   for (i=cuantas;i>=1;i--)
   {
      aux=ListaId_elemento(vars,i);
      if (!Constructor(aux))
         break;
      nargs+=cuenta_elem_param(Identificador_nombre(Id_nom(aux)));
   }
   

   genera(indentacion,"/* Primero compruebo el numero de parametros */\n");
   genera(indentacion,"if (_nargs!=%d) _4GLerror (\"La función %%s ha recibido un numero incorrecto de parametros \",_func_name);\n",nargs);
   for (i=cuantas;i>=1;i--)
   {
      aux=ListaId_elemento(vars,i);
      if (!Constructor(aux))
         break;
      genParam(Identificador_nombre(Id_nom(aux)));
   }
}

void genParam(char *nombre)
{
   enum tipos tipo;
   int tamanno;
   tipo=tipo_var(nombre);
   tamanno=tam_var(nombre);
   switch (tipo)
   {
      case TIPO_INT:
         genera(indentacion,"%s=pop_int(pila_exp);\n",nombre);
         break;
      case TIPO_FLOAT:
         genera(indentacion,"%s=pop_float(pila_exp);\n",nombre);
         break;
      case TIPO_DATE:
         genera(indentacion,"%s=pop_date(pila_exp);\n",nombre);
         break;
      case TIPO_TIME:
         genera(indentacion,"%s=pop_time(pila_exp);\n",nombre);
         break;
      case TIPO_DATETIME:
         genera(indentacion,"%s=pop_datetime(pila_exp);\n",nombre);
         break;
      case TIPO_INTERVAL:
         genera(indentacion,"%s=pop_interval(pila_exp);\n",nombre);
         break;
      case TIPO_STR:
         genera(indentacion,"_4GLstrncpy(%s,pop_str(pila_exp),%d);\n",nombre,tamanno);
         break;
      case TIPO_RECORD:
         genera(indentacion,"/*** registro %s ***/\n",nombre);
         genParamRecord(nombre);
         genera(indentacion,"/*** fin registro %s ***/\n",nombre);
         break;
   }
}

void genParamRecord(char *nombre)
{
   Arbol aux, var;
   int i,cuantas;
   cadena nomcampo;
   var=Existe_Var(nombre);
   cuantas=Variables_longitud(Tipo_cam(Variable_tip(var)));
   indentacion++;
   for (i=cuantas;i>=1;i--)
   {
      aux=Variables_elemento(Tipo_cam(Variable_tip(var)),i);
      if (!Constructor(aux))
         break;
      sprintf(nomcampo,"%s.%s",nombre,Identificador_nombre(Variable_nom(aux)));
      genParam(nomcampo);
   }
   indentacion--;
}

int cuenta_elem_param(char *nombre)
{
   enum tipos tipo;
   int cuantos;
   tipo=tipo_var(nombre);
   
   switch (tipo)
   {
      case TIPO_RECORD:
         cuantos=cuenta_elem_record(nombre);
         break;
      default:
         cuantos=1;
         break;
   }
   return cuantos;
}

int cuenta_elem_record(char *nombre)
{
   Arbol aux, var;
   int i,cuantas;
   int cuantos;
   cadena nomcampo;
   var=Existe_Var(nombre);
   cuantas=Variables_longitud(Tipo_cam(Variable_tip(var)));

   cuantos=0;
   for (i=cuantas;i>=1;i--)
   {
      aux=Variables_elemento(Tipo_cam(Variable_tip(var)),i);
      if (!Constructor(aux))
         break;
      sprintf(nomcampo,"%s.%s",nombre,Identificador_nombre(Variable_nom(aux)));
      cuantos+=cuenta_elem_param(nomcampo);
   }
   return cuantos;
}

void genVariables(Arbol vars, char *prefijo)
{
   Arbol aux;
   int i,cuantas;
   cuantas=Variables_longitud(vars);
   for (i=0;i<cuantas;i++)
   {
      aux=Variables_elemento(vars,i+1);
      if (!Constructor(aux))
         break;
      genVariable(aux,prefijo);
   }
}

void genVariable(Arbol var, char *prefijo)
{
   cadena tipo,nombre;
   int tamanno;
   strcpy(nombre, Identificador_nombre(Variable_nom(var)));
   strcpy(tipo, Identificador_nombre(Tipo_tip(Variable_tip(var))));
   tamanno=Constante_valor(Tipo_tam(Variable_tip(var)));

   if (!strcmp(tipo,"WINDOW"))
      genera(indentacion,"%s _WINDOW *%s=NULL;\n",prefijo,nombre);
   else if (!strcmp(tipo,"FORM"))
   {
      genera(indentacion,"%s _4GLFORM %s=NULL;\n",prefijo,nombre);
      genera(indentacion,"%s _4GLFORM _GenForm%s();\n",prefijo,nombre);
   }
   else if (!strcmp(tipo,"CURSOR"))
      genera(indentacion,"%s _CURSOR _C%s;\n",prefijo,nombre);
   else if (!strcmp(tipo,"LCURSOR"))
      genera(indentacion,"%s _CURSOR _C%s;\n",prefijo,nombre);
   else if (!strcmp(tipo,"MENU"))
   {
      genera(indentacion,"%s _MENU %s;\n",prefijo,nombre);
      genera(indentacion,"%s ITEM *%s_items[%d];\n",prefijo,nombre,tamanno);
   }
   else if (!strcmp(tipo,"BROWSE"))
      genera(indentacion,"%s _BROWSE %s;\n",prefijo,nombre);
   else if (!strcmp(tipo,"REPORT"))
   {
      genera(indentacion,"/* Funciones del report %s */\n",nombre);
      genera(indentacion,"%s int _RPT_%s_inic;\n",prefijo,nombre);
      genera(indentacion,"void _Fn_STARTRPT_%s();\n",nombre);
      genera(indentacion,"void _Fn_OutputRpt_%s();\n",nombre);
      genera(indentacion,"void _Fn_RPT_%s();\n",nombre);
      genera(indentacion,"/*---*/\n");
   }
   else if (!strcmp(tipo,"int"))
      genera(indentacion,"%s int %s;\n",prefijo,nombre);
   else if (!strcmp(tipo,"float"))
      genera(indentacion,"%s double %s;\n",prefijo,nombre);
   else if (!strcmp(tipo,"date"))
      genera(indentacion,"%s _4GLDATE %s;\n",prefijo,nombre);
   else if (!strcmp(tipo,"time"))
      genera(indentacion,"%s _4GLTIME %s;\n",prefijo,nombre);
   else if (!strcmp(tipo,"datetime"))
      genera(indentacion,"%s _4GLDATETIME %s;\n",prefijo,nombre);
   else if (!strcmp(tipo,"interval"))
      genera(indentacion,"%s _4GLINTERVAL %s;\n",prefijo,nombre);
   else if (!strcmp(tipo,"char"))
      genera(indentacion,"%s char %s[%d];\n",prefijo,nombre,tamanno+1);
   else if (!strcmp(tipo,"record"))
      genRecord(var);
   else 
      genera(indentacion,"%s %s %s;\n",prefijo,tipo,nombre);
}

void genRecord(Arbol var)
{
   Arbol aux;
   int i,cuantas;
   cuantas=Variables_longitud(Tipo_cam(Variable_tip(var)));
   genera(indentacion,"struct\n");
   genera(indentacion,"{\n");
   indentacion++;

   for (i=0;i<cuantas;i++)
   {
      aux=Variables_elemento(Tipo_cam(Variable_tip(var)),i+1);
      if (!Constructor(aux))
         break;
      genVariable(aux,"");
   }

   indentacion--;
   genera(indentacion,"} %s;\n",Identificador_nombre(Variable_nom(var)));
}

void genFunciones()
{
   Arbol aux;
   int i,cuantas;
   cuantas=Funciones_longitud(Fichero_fun(raiz));
   for (i=0;i<cuantas;i++)
   {
      aux=Funciones_elemento(Fichero_fun(raiz),i+1);
      if (!Constructor(aux))
         break;
      /* Me salto las funciones 'externas'; los 'reports' se hacen aparte */
      if (Constructor(aux)==REPORT)
         genReport(aux);
      else if (Constructor(aux)==FORM)
         genForm(aux);
      else if (Constructor(Funcion_cod(aux)))
      {
         genFuncion(aux);
      }
   }
}

void genFuncion(Arbol fn)
{
   indentacion=0;
   lst_locales=Acciones_var(Funcion_cod(fn));
   printf("Generando función: %s\n",Identificador_nombre(Funcion_nom(fn)));
   genera(indentacion,"\n/*****************************************************\n");   
   genera(indentacion," * Función: %-30.30s           *\n",Identificador_nombre(Funcion_nom(fn)));
   genera(indentacion,"/*****************************************************/\n");   
   if (strcmp(Identificador_nombre(Funcion_nom(fn)),"main"))
      genera(indentacion,"int _Fn_%s(int _nargs)\n",Identificador_nombre(Funcion_nom(fn)));
   else
      genera(indentacion,"main(int argc, char *argv[])\n");
   genera(indentacion,"{\n");
   indentacion=1;

   /* Todas las funciones tienen una variable local '_func_name' que 
      contiene el nombre de la funcion. Se usa para imprimir errores. */
   genera(indentacion,"char *_func_name=\"%s\";\n",Identificador_nombre(Funcion_nom(fn)));

   /* Primero genero las vars locales */
   if (Constructor(Acciones_var(Funcion_cod(fn))))
      genVariables(Acciones_var(Funcion_cod(fn)),"");

   /* La funcion 'main' es un caso especial... */
   if (!strcmp(Identificador_nombre(Funcion_nom(fn)),"main"))
   {
      genera(indentacion,"int _i,_j; /* Usadas para inicializar los colores */\n");
      genera(indentacion,"arg_count=argc-1; _arg_val=argv;  /* Variables globales que guardan los parametros */\n");
      genera(indentacion,"/* Preparo las curses y el 'locale'*/\n");
      genera(indentacion,"_4GLinit();\n");
      if (db!=NULL)
      {
      	genera(indentacion,"/* Preparo los valores de los flags de estado */\n");
        genera(indentacion,"notfound=PGRES_EMPTY_QUERY;\n");
        genera(indentacion,"found=PGRES_TUPLES_OK;\n");
        genera(indentacion,"ok=PGRES_COMMAND_OK;\n");
      	genera(indentacion,"/* Conecto con la base de datos */\n");
        genera(indentacion,"_conn=_4GLsetdb(\"%s\");\n\n",
        Identificador_nombre(Database_nom(db)));
        genera(indentacion,"if (_4GLfechaEuro==1)\n");
        genera(indentacion,"{\n");
        genera(indentacion+1,"_4GLexec(_conn,\"set DateStyle to 'European';\");\n");
        genera(indentacion+1,"_4GLexec(_conn,\"set DateStyle to 'SQL';\");\n");
        genera(indentacion,"}\n");
      }
      genera(indentacion,"pila_param=nueva_pila();\n");
      genera(indentacion,"pila_exp=nueva_pila();\n\n");
   }

   /* Leo los parámetros recibidos */
   if (Constructor(Funcion_par(fn)))
      genParams(Funcion_par(fn));

   /* Genero las acciones */
   genSentencias(Acciones_cod(Funcion_cod(fn)));
   if (!strcmp(Identificador_nombre(Funcion_nom(fn)),"main"))
   {
      genera(indentacion,"_4GLexit(0);    /* Terminamos */\n");
   }
   genera(indentacion,"return 0; /* Por si la funcion no devuelve nada */\n ");
   indentacion=0;
   genera(indentacion,"} /* Fin de la función %s */\n\n",Identificador_nombre(Funcion_nom(fn)));
}

void genSentencias(Arbol fn)
{
   Arbol aux;
   int i,cuantas;
   cuantas=Sentencias_longitud(fn);
   for (i=0;i<cuantas;i++)
   {
      aux=Sentencias_elemento(fn,i+1);
      if (!Constructor(aux))
         break;
      genSentencia(aux);
   }
}

void genSentencia(Arbol snt)
{
   switch(Constructor(snt))
   {
      case FUENTEC:
         	genFuenteC(snt);
            break;
      case EXITPROGRAM:
         	genExitProgram(snt);
            break;
      case IF:
         	genIf(snt);
            break;
      case FOR:
         	genFor(snt);
            break;
      case CONTINUEFOR:
         	genContinueFor(snt);
            break;
      case EXITFOR:
         	genExitFor(snt);
            break;
      case WHILE:
         	genWhile(snt);
            break;
      case CONTINUEWHILE:
         	genContinueWhile(snt);
            break;
      case EXITWHILE:
         	genExitWhile(snt);
            break;
      case FOREACH:
         	genForeach(snt);
            break;
      case CONTINUEFOREACH:
         	genContinueForeach(snt);
            break;
      case EXITFOREACH:
         	genExitForeach(snt);
            break;
      case TRANSACC:
         	genTransacc(snt);
            break;
      case ASIGNACION:
         	genAsignacion(snt);
            break;
      case LLAMADA:
         	genLlamada(snt);
            break;
      case RETORNO:
         	genRetorno(snt);
            break;
      case ABVENTANA:
         	genAbVentana(snt);
            break;
      case CIEVENTANA:
         	genCieVentana(snt);
            break;
      case MOVVENTANA:
         	genMovVentana(snt);
            break;
      case CLEARWINDOW:
         	genClearWindow(snt);
            break;
      case CURVENTANA:
         	genCurVentana(snt);
            break;
      case ESCRIBIR:
         	genEscribir(snt);
            break;
      case LEER:
         	genLeer(snt);
            break;
      case LEEREXIT:
         	genLeerExit(snt);
            break;
      case DELAY:
         	genDelay(snt);
            break;
      case DECLARE:
         	genDeclare(snt);
            break;
      case OPENCURSOR:
         	genOpenCursor(snt);
            break;
      case FETCHCURSOR:
         	genFetchCursor(snt);
            break;
      case CLOSECURSOR:
         	genCloseCursor(snt);
            break;
      case EXECSQL:
         	genExecSQL(snt);
            break;
      case SELECT:
         	genSelect(snt);
            break;
      case INSERT:
         	genInsert(snt);
            break;
      case DELETE:
         	genDelete(snt);
            break;
      case UPDATE:
         	genUpdate(snt);
            break;
      case WHENEVER:
         	genWhenever(snt);
            break;
      case MENU:
         	genMenu(snt);
            break;
      case EXITMENU:
         	genera(indentacion,"goto _FinM%s;\n",nom_menu);
            break;
      case BROWSE:
         	genBrowse(snt);
            break;
      case BROWSEEXIT:
         	genera(indentacion,"goto _FinB%d;\n",numBrowse);
            break;
      case FORMDISPLAY:
         	genFormDisplay(snt);
            break;
      case FORMCREATE:
         	genFormCreate(snt);
            break;
      case FORMDISPBYNAME:
         	genFormDispByName(snt);
            break;
      case FORMINPUTBYNAME:
         	genFormInputByName(snt);
            break;
      case FORMEXIT:
         	genFormExit(snt);
            break;
      case FORMCURRENTFIELD:
         	genFormCurrent(snt);
            break;
      case FORMVALIDATEFIELD:
         	genFormValidate(InputByNameArbol,TRUE);
            break;
	  case PRINTREPORT:
	        genPrint(snt);
	        break;
      default:
         yyerror("Sentencia del tipo %d desconocida",Constructor(snt));
   }   
}

void genFuenteC(Arbol snt)
{
   Arbol aux;
   int i,cuantas;
   
   genera(indentacion,"/* Fuente en C embebido */\n");
   genera(indentacion++,"{\n");
   cuantas=FuenteC_longitud(snt);
   for (i=1; i<=cuantas; i++)
   {
      aux=FuenteC_elemento(snt,i);
      genera(indentacion,"%s",Identificador_nombre(aux));
   }
   genera(--indentacion,"}\n");
}

void genExitProgram(Arbol snt)
{
   genera(indentacion,"/* EXIT PROGRAM */\n");
   genera(indentacion,"_4GLexit(0);\n");
}

void genMenu(Arbol snt)
{
   int i,cuantas,num_ops;
   char *nombre;
   char *opc,*desc;
   char *nom_menu_ant;
   struct atributos attrs;
   Arbol aux;
   
   nombre=Identificador_nombre(Menu_nom(snt));
   cuantas=MenuOps_longitud(Menu_opc(snt));

   /* Guardo el nombre del ultimo menu procesado */
   nom_menu_ant=nom_menu;
   nom_menu=nombre;
   genera(indentacion,"%s.format=%ld;\n",nombre,(long)Constante_valor(Menu_fmt(snt)));
   
   /* Primero genero los 'items' del menu */
   genera(indentacion,"/****  Genero un menu ****/\n");
   num_ops=0;
   for (i=1; i<=cuantas; i++)
   {
      aux=MenuOps_elemento(Menu_opc(snt),i);
      /* Si no es un ON KEY... */
      if (Constante_valor(MenuOp_key(aux))==0)
      {
      	genExpresion(MenuOp_nom(aux));
         if (Constructor(MenuOp_desc(aux)))
            genExpresion(MenuOp_desc(aux));
         else
            genera(indentacion,"push_str(pila_exp,\"\");\n");
         genera(indentacion,"%s_items[%d]=new_item(pop_str(pila_exp),pop_str(pila_exp));\n",
            nombre,num_ops,opc,desc);
         num_ops++;
      }
   }
   genera(indentacion,"%s_items[%d]=NULL;\n",nombre,num_ops);
   genera(indentacion,"%s.menu=new_menu(%s_items);\n",nombre,nombre);
   genera(indentacion,"_4GLset_menu(&%s);\n",nombre);

   /* Si se indican atributos, los preparo */
   if (Constructor(Menu_att(snt)))
   {
      if (Constructor(MenuAttr_fore(Menu_att(snt))))
      {
      	attrs=lee_atributos(MenuAttr_fore(Menu_att(snt)));
         if (attrs.brillo == 0)
            genera(indentacion,"set_menu_fore(%s.menu,COLOR_PAIR(%d));\n",nombre,attrs.color);
         else
            genera(indentacion,"set_menu_fore(%s.menu,COLOR_PAIR(%d)|A_BOLD);\n",nombre,attrs.color);
      }
      if (Constructor(MenuAttr_back(Menu_att(snt))))
      {
      	attrs=lee_atributos(MenuAttr_back(Menu_att(snt)));
         if (attrs.brillo == 0)
            genera(indentacion,"set_menu_back(%s.menu,COLOR_PAIR(%d));\n",nombre,attrs.color);
         else
            genera(indentacion,"set_menu_back(%s.menu,COLOR_PAIR(%d)|A_BOLD);\n",nombre,attrs.color);
      }
   }
   
   genera(indentacion,"/****  menu creado. Ahora lo planto en pantalla ****/\n");
   genera(indentacion,"if ((_4GLy=post_menu(%s.menu))!=E_OK)\n",nombre);
   genera(indentacion+1,"_4GLerror(\"No puede mostrarse el menu. Error %%d\",_4GLy);\n");
   genera(indentacion,"while ((%s.opc=_4GLmueve_menu(%s))!=0)\n",nombre,nombre);
   genera(indentacion,"{\n");
   indentacion++;
   genera(indentacion,"switch(%s.opc)\n",nombre);
   genera(indentacion,"{\n");
   for (i=1; i<=cuantas; i++)
   {
      aux=MenuOps_elemento(Menu_opc(snt),i);
      /* Si no es un 'on key' */
      if (Constante_valor(MenuOp_key(aux))==0)
      {
      	opc=Identificador_nombre(MenuOp_nom(aux));
         desc=Identificador_nombre(MenuOp_desc(aux));
         genera(indentacion,"case -%d: /**** opcion %d ***/\n",i,i);
         indentacion++;
         genSentencias(MenuOp_cod(aux));
         genera(indentacion,"break;\n");
         indentacion--;
      }
      else /* Si es un 'on key' */
      {
         genera(indentacion,"case %s: /**** tecla %s ***/\n",Identificador_nombre(MenuOp_nom(aux)),Identificador_nombre(MenuOp_nom(aux)) );
         indentacion++;
         genSentencias(MenuOp_cod(aux));
         genera(indentacion,"break;\n");
         indentacion--;
      }
   }
   genera(indentacion,"}\n");
   indentacion--;
   genera(indentacion,"}\n");
   genera(indentacion,"_FinM%s:\n",nombre);
   genera(indentacion,"unpost_menu(%s.menu);\n",nombre);
   /* Al final, libero la memoria de los 'items' del menu */
   genera(indentacion,"/****  Borro el menu de memoria ****/\n");
   for (i=1; i<=num_ops; i++)
   {
      genera(indentacion,"free_item(%s_items[%d]);\n",nombre,i-1);
   }
   genera(indentacion,"/**** Y de pantalla ****/\n");
   genera(indentacion,"update_panels();\n");
   genera(indentacion,"doupdate();\n");
   nom_menu=nom_menu_ant;
   nom_menu_ant="";
}

void genBrowse(Arbol snt)
{
   char nombre[25], *cursor;
   int cuantas, i;
   Arbol aux;
   int numBrowseAnt;
   numBrowseAnt=numBrowse;
   numBrowse=maxBrowse++;
   
   sprintf(nombre,"_Br%d",numBrowse);
   
   cursor=Identificador_nombre(Browse_cur(snt));
   genera(indentacion,"/***** Browse %s****/\n",nombre);
   indentacion++;
   if (Constructor(Browse_donde(snt)))
   {
      genExpresion(Rect_x(Browse_donde(snt)));
      genera(indentacion,"%s.x=pop_int(pila_exp);\n",nombre);
      genExpresion(Rect_y(Browse_donde(snt)));
      genera(indentacion,"%s.y=pop_int(pila_exp);\n",nombre);
      genExpresion(Rect_xx(Browse_donde(snt)));
      genera(indentacion,"%s.max_x=pop_int(pila_exp);\n",nombre);
      genExpresion(Rect_yy(Browse_donde(snt)));
      genera(indentacion,"%s.max_y=pop_int(pila_exp);\n",nombre);
   }
   else
   {
      genera(indentacion,"%s.x=%s.max_x=%s.y=%s.max_y=0;\n",nombre,nombre,nombre,nombre);
   }   
   genera(indentacion,"_4GLset_browse(&%s);\n",nombre);

   if (Constructor(Browse_titulo(snt)))
   {
      genera(indentacion,"/** El titulo del browse... */\n");
      genExpresion(Browse_titulo(snt));
      genera(indentacion,"%s.titulo=pop_str(pila_exp);\n",nombre);
      genera(indentacion,"%s.y+=2;\n",nombre);
      genera(indentacion,"%s.max_y-=2;\n",nombre);
   }
   else
      genera(indentacion,"%s.titulo=NULL;\n",nombre);
   
   genera(indentacion,"/** Preparo la query **/\n");
   generaOpenCursor(cursor);
   genera(indentacion,"%s.cursor=&_C%s;\n",nombre,cursor);
   genera(indentacion,"if (%s.cursor->ntuples>0) \n",nombre);
   genera(indentacion++,"{\n");
   genera(indentacion,"%s.accion=BRW_REDRAW;\n",nombre);
   genera(indentacion,"%s.primero=%s.actual=%s.x_offset=0;\n",nombre,nombre,nombre);
   genera(indentacion,"while (%s.tecla!=27)\n",nombre);
   genera(indentacion,"{\n");
   indentacion++;
   genera(indentacion,"switch (%s.accion)\n",nombre);
   genera(indentacion,"{\n");
   indentacion++;
   genera(indentacion," case BRW_REDRAW:\n");
   indentacion++;
//   genera(indentacion,"/***** Borro la ventana ****/\n");
//   genera(indentacion,"werase(%s.win);\n",nombre);*/
   if (Constructor(Browse_titulo(snt)))
   {
      genera(indentacion,"if (strlen(%s.titulo)>=%s.x_offset)\n",nombre,nombre);
      genera(indentacion+1,"mvwprintw(curwin,%s.y-2,%s.x,\"%%-*.*s \",%s.max_x-1,%s.max_x-1,%s.titulo+%s.x_offset);\n",
         nombre,nombre,nombre,nombre,nombre,nombre,nombre);
      genera(indentacion,"mvwhline(curwin,%s.y-1,%s.x,ACS_HLINE,%s.max_x-1);\n",nombre,nombre,nombre);
   }
   genera(indentacion,"/***** Imprimo las primeras lineas ****/\n");
   genera(indentacion,"for (_i=%s.primero;_i-%s.primero<%s.max_y && _i<%s.cursor->ntuples;_i++)\n",nombre,nombre,nombre,nombre);
   genera(indentacion++,"{\n");
   cuantas=ListaId_longitud(Browse_vars(snt));
   for (i=0;i<cuantas;i++)
   {
      cadena var;
      aux=ListaId_elemento(Browse_vars(snt),i+1);
      if (!Constructor(aux))
         break;
      strcpy(var,Identificador_nombre(Id_nom(aux)));
      switch (tipo_var(var))
      {
      	case TIPO_INT:
            genera(indentacion,"%s=atol(PQgetvalue(%s.cursor->res,_i,%d));\n",
               var,nombre,i);
            break;
      	case TIPO_FLOAT:
            genera(indentacion,"%s=atof(PQgetvalue(%s.cursor->res,_i,%d));\n",
               var,nombre,i);
            break;
         case TIPO_STR:
            genera(indentacion,"_4GLstrncpy(%s,PQgetvalue(%s.cursor->res,_i,%d),%d);\n",
               var,nombre,i,tam_var(var));
            break;
         case TIPO_DATE:
            genera(indentacion,"%s=_4GLstr2date(PQgetvalue(%s.cursor->res,_i,%d));\n",
               var,nombre,i);
            break;
         case TIPO_TIME:
            genera(indentacion,"%s=_4GLstr2time(PQgetvalue(%s.cursor->res,_i,%d));\n",
               var,nombre,i);
            break;
         case TIPO_DATETIME:
            genera(indentacion,"%s=_4GLstr2datetime(PQgetvalue(%s.cursor->res,_i,%d));\n",
               var,nombre,i);
            break;
         case TIPO_INTERVAL:
            genera(indentacion,"%s=_4GLDBstr2interval(PQgetvalue(%s.cursor->res,_i,%d));\n",
               var,nombre,i);
            break;
      }
   }
   genExpresion(Browse_exp(snt));
   genera(indentacion,"%s.linea=pop_str(pila_exp);\n",nombre);
   genera(indentacion,"if (strlen(%s.linea)>=%s.max_length) %s.max_length=strlen(%s.linea);\n",
      nombre,nombre,nombre,nombre);
   genera(indentacion,"if (_i!=%s.actual)\n",nombre);
   genera(indentacion+1,"mvwprintw(curwin,_i-%s.primero+%s.y,%s.x,\"%%-*.*s\",%s.max_x-1,%s.max_x-1,%s.linea+%s.x_offset);\n",
      nombre,nombre,nombre,nombre,nombre,nombre,nombre);
   genera(--indentacion,"}\n");	/* Fin del for 1..max_y */

   genera(indentacion,"/* Borro hasta el final de la ventana */\n");
   genera(indentacion,"for (_i=_i;_i-%s.primero<%s.max_y;_i++)\n",nombre,nombre);
   genera(indentacion+1,"mvwprintw(curwin,_i-%s.primero+%s.y,%s.x,\"%%*.*s\",%s.max_x-1,%s.max_x-1,\" \");\n",
      nombre,nombre,nombre,nombre,nombre);

   genera(indentacion,"/**** Ahora imprimo la línea seleccionada ****/\n");
   cuantas=ListaId_longitud(Browse_vars(snt));
   for (i=0;i<cuantas;i++)
   {
      cadena var;
      aux=ListaId_elemento(Browse_vars(snt),i+1);
      if (!Constructor(aux))
         break;
      strcpy(var,Identificador_nombre(Id_nom(aux)));
      switch (tipo_var(var))
      {
      	case TIPO_INT:
            genera(indentacion,"%s=atol(PQgetvalue(%s.cursor->res,%s.actual,%d));\n",
               var,nombre,nombre,i);
            break;
      	case TIPO_FLOAT:
            genera(indentacion,"%s=atof(PQgetvalue(%s.cursor->res,%s.actual,%d));\n",
               var,nombre,nombre,i);
            break;
         case TIPO_STR:
            genera(indentacion,"_4GLstrncpy(%s,PQgetvalue(%s.cursor->res,%s.actual,%d),%d);\n",
               var,nombre,nombre,i,tam_var(var));
            break;
         case TIPO_DATE:
            genera(indentacion,"%s=_4GLstr2date(PQgetvalue(%s.cursor->res,%s.actual,%d));\n",
               var,nombre,nombre,i);
            break;
         case TIPO_TIME:
            genera(indentacion,"%s=_4GLstr2time(PQgetvalue(%s.cursor->res,%s.actual,%d));\n",
               var,nombre,nombre,i);
            break;
         case TIPO_DATETIME:
            genera(indentacion,"%s=_4GLstr2datetime(PQgetvalue(%s.cursor->res,%s.actual,%d));\n",
               var,nombre,nombre,i);
            break;
         case TIPO_INTERVAL:
            genera(indentacion,"%s=_4GLstr2datetime(PQgetvalue(%s.cursor->res,%s.actual,%d));\n",
               var,nombre,nombre,i);
            break;
      }
   }
   genera(indentacion,"push_int(pila_param,wgetbkgd(curwin));\n");
   genExpresion(Browse_exp(snt));
   genera(indentacion,"wbkgdset(curwin,wgetbkgd(curwin)|A_REVERSE);\n");
   genera(indentacion+1,"mvwprintw(curwin,%s.actual-%s.primero+%s.y,%s.x,\"%%-*.*s\",%s.max_x-1,%s.max_x-1,pop_str(pila_exp)+%s.x_offset);\n",
      nombre,nombre,nombre,nombre,nombre,nombre,nombre);
   genera(indentacion,"wbkgdset(curwin,pop_int(pila_param));\n");
   genera(indentacion,"update_panels(); doupdate();\n");
   genera(indentacion,"break;\n");
   indentacion--;
   /* Case accion = bajar */
   
   /* Fin del switch accion */
   indentacion--;
   genera(indentacion,"}\n");
   
   genera(indentacion,"%s.tecla=getch();\n",nombre);   
   /* Fin del while tecla != 27 */
   genera(indentacion,"switch(%s.tecla)\n",nombre);
   genera(indentacion,"{\n");
   indentacion++;
   /* Primero genero el código que ponga el progamador */
   cuantas=BrowseOps_longitud(Browse_opc(snt));
   for (i=1;i<=cuantas;i++)
   {
      aux=BrowseOps_elemento(Browse_opc(snt),i);
      genera(indentacion,"case %s:\n",Identificador_nombre(BrowseOp_nom(aux)));
      indentacion++;
      genSentencias(BrowseOp_cod(aux));
      genera(indentacion,"break;\n");
      indentacion--;
   }
   
   genera(indentacion,"case KEY_DOWN:\n");
   indentacion++;
   genera(indentacion,"if (%s.actual<%s.cursor->ntuples-1)\n",nombre,nombre);
   genera(indentacion+1,"%s.actual++; %s.accion=BRW_BAJAR;\n",nombre,nombre);
   genera(indentacion,"if (%s.actual-%s.primero>%s.max_y-1)\n",nombre,nombre,nombre);
   genera(indentacion+1,"%s.primero++; %s.accion=BRW_REDRAW;\n",nombre,nombre);
   genera(indentacion,"break;\n");
   indentacion--;

   genera(indentacion,"case KEY_UP:\n");
   indentacion++;
   genera(indentacion,"if (%s.actual>0)\n",nombre);
   genera(indentacion+1,"%s.actual--; %s.accion=BRW_SUBIR;\n",nombre,nombre);
   genera(indentacion,"if (%s.actual<%s.primero)\n",nombre,nombre);
   genera(indentacion+1,"%s.primero--; %s.accion=BRW_REDRAW;\n",nombre,nombre);
   genera(indentacion,"break;\n");
   indentacion--;

   genera(indentacion,"case KEY_RIGHT:\n");
   indentacion++;
   genera(indentacion,"if (%s.x_offset<%s.max_length)\n",nombre,nombre);
   genera(indentacion+1,"%s.x_offset++; %s.accion=BRW_REDRAW;\n",nombre,nombre);
   genera(indentacion,"break;\n");
   indentacion--;

   genera(indentacion,"case KEY_LEFT:\n");
   indentacion++;
   genera(indentacion,"if (%s.x_offset>0)\n",nombre);
   genera(indentacion+1,"%s.x_offset--; %s.accion=BRW_REDRAW;\n",nombre,nombre);
   genera(indentacion,"break;\n");
   indentacion--;   

   genera(indentacion,"case KEY_HOME:\n");
   indentacion++;
   genera(indentacion,"%s.x_offset=%s.actual=%s.primero=0; %s.accion=BRW_REDRAW;\n",nombre,nombre,nombre,nombre);
   genera(indentacion,"break;\n");
   indentacion--;
   
   genera(indentacion,"case KEY_END:\n");
   indentacion++;
   genera(indentacion,"%s.x_offset=0;\n",nombre);
   genera(indentacion,"%s.actual=%s.cursor->ntuples-1;\n",nombre,nombre);
   genera(indentacion,"%s.primero=%s.actual-%s.max_y+1;\n",nombre,nombre,nombre);
   genera(indentacion,"if (%s.primero<0) %s.primero=0;\n",nombre,nombre);
   genera(indentacion,"%s.accion=BRW_REDRAW;\n",nombre);
   genera(indentacion,"break;\n");
   indentacion--;

   genera(indentacion,"case KEY_PPAGE:\n");
   indentacion++;
   genera(indentacion,"if (%s.actual!=%s.primero)\n",nombre,nombre);
   genera(indentacion+1,"%s.actual=%s.primero;\n",nombre,nombre);
   genera(indentacion,"else\n");
   genera(indentacion,"%s.primero=%s.primero-%s.max_y;\n",nombre,nombre,nombre);
   genera(indentacion,"if (%s.primero<0) %s.primero=0;\n", nombre, nombre);
   genera(indentacion,"%s.actual=%s.primero;\n",nombre,nombre);
   genera(indentacion,"%s.accion=BRW_REDRAW;\n",nombre);
   genera(indentacion,"break;\n");
   indentacion--;

   genera(indentacion,"case KEY_NPAGE:\n");
   indentacion++;
   genera(indentacion,"if (%s.actual==%s.primero+%s.max_y-1)\n",nombre,nombre,nombre);
   genera(indentacion+1,"%s.primero=%s.actual;\n",nombre,nombre);
   genera(indentacion,"%s.actual=%s.primero+%s.max_y-1;\n",nombre,nombre,nombre);
   genera(indentacion,"if (%s.actual>=%s.cursor->ntuples) %s.actual=%s.cursor->ntuples-1;",nombre,nombre,nombre,nombre);
   genera(indentacion,"%s.accion=BRW_REDRAW;\n",nombre);
   genera(indentacion,"break;\n");
   indentacion--;

   indentacion--;
   genera(indentacion,"}\n");
   indentacion--;
   genera(indentacion,"}\n");
   indentacion--;
   genera(indentacion--,"}\n");
   if (Constructor(Browse_sino(snt)))
   {
      genera(indentacion,"else /* Si no ha encontrado registros para el browse... */\n");
      genera(indentacion++,"{\n");
      genSentencias(Browse_sino(snt));
      genera(--indentacion,"}\n");
   }
   genera(indentacion,"_FinB%d:\n",numBrowse);
   genera(indentacion,"_4GLclear(*(%s.cursor));\n",nombre);
   genera(indentacion,"/***** Fin del browse ****/\n\n");
   numBrowse=numBrowseAnt;
}

char *charListaId(Arbol lst)
{
   static char res[8196];
   Arbol aux;
   int i,cuantas;

   strcpy(res,"");
   cuantas=ListaId_longitud(lst);
   for (i=0;i<cuantas;i++)
   {
      aux=ListaId_elemento(lst,i+1);
      if (!Constructor(aux))
         break;
      if (i>0)
         strcat(res,", ");
      strcat(res,Identificador_nombre(Id_nom(aux)));
   }
   return res;
}

void genTransacc(Arbol snt)
{
   char *operacion;
   operacion=Identificador_nombre(Transacc_op(snt));
   if (!strcmp(operacion,"BEGIN"))
   {
      genera(indentacion,"/***** BEGIN TRANSACTION *****/\n");
      genera(indentacion,"_4GLbegin_transaction(_conn);\n");
   }
   else if (!strcmp(operacion,"END"))
   {
      genera(indentacion,"/***** END TRANSACTION *****/\n");
      genera(indentacion,"_4GLend_transaction(_conn);\n");
   }
   else if (!strcmp(operacion,"COMMIT"))
   {
      genera(indentacion,"/***** COMMIT TRANSACTION *****/\n");
      genera(indentacion,"_4GLcommit_transaction(_conn);\n");
   }
   else if (!strcmp(operacion,"ABORT"))
   {
      genera(indentacion,"/***** ABORT TRANSACTION *****/\n");
      genera(indentacion,"_4GLabort_transaction(_conn);\n");
   }
}

void genSelTmp(Arbol snt)
{
   char campos[512], from[512], order[512];
   
   en_select = 1;
   strcpy(campos, charListaId(Select_cam(snt)));
   strcpy(from, charListaId(Select_from(snt)));
   if (Constructor(Select_where(snt)))
   {
      genera(indentacion,"_WhereTmp[0]='\\0';\n");
      genWhere(Select_where(snt)); 
      genera(indentacion,"sprintf(_SelTmp,\"select %s from %s where %%s\",_WhereTmp);\n",
         campos, from);
      indentacion++;
      genera(indentacion,"_WhereTmp[0]='\\0';\n");
   }
   else
   {
      genera(indentacion,"sprintf(_SelTmp,\"select %s from %s\");\n",
         campos, from);
      indentacion++;
   }
   if (Constructor(Select_order(snt)))
   {
      strcpy(order,charListaId(Select_order(snt)));
      genera(indentacion,"strcat(_SelTmp,\" order by \");\n");
      genera(indentacion,"strcat(_SelTmp,\"%s\");\n",order);
   }
   indentacion--;
   genera(indentacion,"strcat(_SelTmp,\";\");\n");
}

void genExecSQL(Arbol snt)
{
   genera(indentacion,"/**** ExecSQL *****/\n");
   genExpresion(ExecSQL_comando(snt));
   genera(indentacion,"_4GLstrncpy(_CurTmp.query,pop_str(pila_exp),sizeof(_CurTmp.query)-1);\n");
   genera(indentacion,"(void)_4GLcursor(_conn,_CurTmp.query,&_CurTmp);\n");
   if (Constructor(ExecSQL_into(snt)))
   	genSelInto(ExecSQL_into(snt));
   genera(indentacion,"_4GLclear(_CurTmp);\n");
}

void genSelect(Arbol snt)
{
   en_select = 1;

   genera(indentacion,"/**** Select ****/\n");   
   genSelTmp(snt);
   
   genera(indentacion,"_4GLstrncpy(_CurTmp.query,_SelTmp,sizeof(_CurTmp.query)-1);\n");
   genera(indentacion,"(void)_4GLcursor(_conn,_CurTmp.query,&(_CurTmp));\n");
   /* Comprobamos si hay resultado */
   if (Select_into(snt))
   {
      genSelInto(Select_into(snt));
   }
   genera(indentacion,"_4GLclear(_CurTmp);\n");
   genera(indentacion,"/**** Fin de select ****/\n\n");   
   en_select=0;
}

void genSelInto(Arbol vars)
{
    int i,cuantas;
    Arbol aux;
    char *nombre;
    
    genera(indentacion,"if (_CurTmp.ntuples == 0)\n");
    genera(indentacion+1,"status=notfound;\n");
    genera(indentacion,"else\n");
    genera(indentacion++,"{\n");

    genera(indentacion,"if (_4GLChkErrores && (_CurTmp.ntuples > 1))\n");
    genera(indentacion,"{\n");
    genera(indentacion+1,"_4GLalert(\"La query '%%s' ha devuelto más de una tupla\\n%%s\\n\",
       _CurTmp.query,\"Se usa la primera de ellas para el 'select into'\");\n");
    genera(indentacion,"}\n");
    /* Asigna el resultado a variables */
    cuantas=ListaId_longitud(vars);
    for (i=0;i<cuantas;i++)
    {
       aux=ListaId_elemento(vars,i+1);
       if (!Constructor(aux))
          break;
       nombre=Identificador_nombre(Id_nom(aux));
       switch (tipo_var(nombre))
       {
      	 case TIPO_INT:
             genera(indentacion,"%s=atol(PQgetvalue(_CurTmp.res,0,%d));\n",
                nombre,i);
             break;
      	 case TIPO_FLOAT:
             genera(indentacion,"%s=atof(PQgetvalue(_CurTmp.res,0,%d));\n",
                nombre,i);
             break;
          case TIPO_STR:
             genera(indentacion,"_4GLstrncpy(%s,PQgetvalue(_CurTmp.res,0,%d),sizeof(%s)-1);\n",
                nombre,i,nombre);
             break;
          case TIPO_DATE:
             genera(indentacion,"%s=_4GLstr2date(PQgetvalue(_CurTmp.res,0,%d));\n",
                nombre,i);
             break;
          case TIPO_TIME:
             genera(indentacion,"%s=_4GLstr2time(PQgetvalue(_CurTmp.res,0,%d));\n",
                nombre,i);
             break;
          case TIPO_DATETIME:
             genera(indentacion,"%s=_4GLstr2datetime(PQgetvalue(_CurTmp.res,0,%d));\n",
                nombre,i);
             break;
          case TIPO_INTERVAL:
             genera(indentacion,"%s=_4GLDBstr2interval(PQgetvalue(_CurTmp.res,0,%d));\n",
                nombre,i);
             break;
       }
    }
    genera(--indentacion,"}\n");
}

void genWhere(Arbol snt)
{
   int i,cuantas;
   Arbol aux;
   char *nombre;
   switch(Constructor(snt))
   {
      case BINARIA:
         genera(indentacion,"strcat(_WhereTmp,\" ( \");\n");
         genBinWhere(snt);
         genera(indentacion,"strcat(_WhereTmp,\" ) \");\n");
         break;
      case CONST:
         if (!strcmp(Identificador_nombre(Const_tip(snt)),"ENTERO"))
            genera(indentacion,"strcat(_WhereTmp,\"%ld\");\n",(long)Constante_valor(Const_val(snt)));
         else if (!strcmp(Identificador_nombre(Const_tip(snt)),"REAL"))
         {
            genera(indentacion,"strcat(_WhereTmp,\"%f\");\n",Constante_valor(Const_val(snt)));
         }
         break;
      case ID:
         nombre=Identificador_nombre(Id_nom(snt));
         if (Existe_Var(nombre))
         {
            switch (tipo_var(nombre))
            {
            	case TIPO_INT:
                  genera(indentacion,"strcat(_WhereTmp,_4GLint2str(%s));\n",
                     nombre);
                  break;
            	case TIPO_FLOAT:
                  genera(indentacion,"strcat(_WhereTmp,_4GLfloat2str(%s));\n",
                     nombre);
                  break;
               case TIPO_STR:
                  genera(indentacion,"strcat(_WhereTmp,\"'\");\n");
                  genera(indentacion,"strcat(_WhereTmp,%s);\n",nombre);
                  genera(indentacion,"strcat(_WhereTmp,\"'\");\n");
                  break;
               case TIPO_DATE:
                  genera(indentacion,"strcat(_WhereTmp,\"'\");\n");
                  genera(indentacion,"strcat(_WhereTmp,_4GLdate2str(%s));\n",nombre);
                  genera(indentacion,"strcat(_WhereTmp,\"'\");\n");
                  break;
               case TIPO_TIME:
                  genera(indentacion,"strcat(_WhereTmp,\"'\");\n");
                  genera(indentacion,"strcat(_WhereTmp,_4GLtime2str(%s));\n",nombre);
                  genera(indentacion,"strcat(_WhereTmp,\"'\");\n");
                  break;
               case TIPO_DATETIME:
                  genera(indentacion,"strcat(_WhereTmp,\"'\");\n");
                  genera(indentacion,"strcat(_WhereTmp,_4GLdatetime2str(%s));\n",nombre);
                  genera(indentacion,"strcat(_WhereTmp,\"'\");\n");
                  break;
               case TIPO_INTERVAL:
                  genera(indentacion,"strcat(_WhereTmp,\"'\");\n");
                  genera(indentacion,"strcat(_WhereTmp,_4GLinterval2str(%s));\n",nombre);
                  genera(indentacion,"strcat(_WhereTmp,\"'\");\n");
                  break;
               default:
                  yyerror("Error. No se encuentra el tipo de la variable %s",nombre);
                  break;
            }
         }
         else
            genera(indentacion,"strcat(_WhereTmp,\"%s\");\n",nombre);
         break;
      case CADENA:
         genera(indentacion,"strcat(_WhereTmp,\"'%s'\");\n",
            Identificador_nombre(Cadena_val(snt)));      
         break;
      case SUBCADENA:
      case USING:
      case CLIPPED:
         genExpresion(snt);
         genera(indentacion,"strcat(_WhereTmp,\"'\");\n");
         genera(indentacion,"strcat(_WhereTmp,pop_str(pila_exp));\n");
         genera(indentacion,"strcat(_WhereTmp,\"'\");\n");
         break;
      case LLAMADA:
         if (Busca_Fun(Identificador_nombre(Funcion_nom(snt))))
         {
            genLlamada(snt);
            genera(indentacion,"strcat(_WhereTmp,pop_str(pila_exp));\n");
         }
         else
         {
            genera(indentacion,"strcat(_WhereTmp,\"%s(\");\n",Identificador_nombre(Llamada_nom(snt)));
            indentacion++;
               cuantas=Expresiones_longitud(Llamada_arg(snt));
               for (i=0;i<cuantas;i++)
               {
                  aux=Expresiones_elemento(Llamada_arg(snt),i+1);
                  if (!Constructor(aux))
                     break;
                  else
                  {
                     if (i>0)
                     {
                        genera(indentacion,"strcat(_WhereTmp,\",\");\n");
                     }
                     genWhere(aux);
                  }
               }
            indentacion--;
            genera(indentacion,"strcat(_WhereTmp,\")\");\n");
         }
         break;
      default:
         yyerror("Error: No se como generar la expresion del where.\n");
         exit(1);
   }
}

void genBinWhere(Arbol snt)
{
   genWhere(Binaria_termi(snt));
   switch(Constructor(Binaria_op(snt)))
   {
      case SUMA:
         genera(indentacion,"strcat(_WhereTmp,\"+\");\n");
         break;
      case RESTA:
         genera(indentacion,"strcat(_WhereTmp,\"-\");\n");
         break;
      case MULTIPLICA:
         genera(indentacion,"strcat(_WhereTmp,\"*\");\n");
         break;
      case DIVIDE:
         genera(indentacion,"strcat(_WhereTmp,\"/\");\n");
         break;
      case MENOR:
         genera(indentacion,"strcat(_WhereTmp,\"<\");\n");
         break;
      case MAYOR:
         genera(indentacion,"strcat(_WhereTmp,\">\");\n");
         break;
      case IGUAL:
         genera(indentacion,"strcat(_WhereTmp,\"=\");\n");
         break;
      case MAYORIGUAL:
         genera(indentacion,"strcat(_WhereTmp,\">=\");\n");
         break;
      case MENORIGUAL:
         genera(indentacion,"strcat(_WhereTmp,\"<=\");\n");
         break;
      case DISTINTO:
         genera(indentacion,"strcat(_WhereTmp,\"!=\");\n");
         break;
      case AND:
         genera(indentacion,"strcat(_WhereTmp,\" and \");\n");
         break;
      case OR:
         genera(indentacion,"strcat(_WhereTmp,\" or \");\n");
         break;
   }
   genWhere(Binaria_termd(snt));
}

void genInsert(Arbol snt)
{
   int cuantas, i;
   Arbol aux;
      
   genera(indentacion," /***** insert into %s *****/\n",
      Identificador_nombre(Insert_tabla(snt)));

   /* Apilo primero todas las expresiones */
   cuantas=Expresiones_longitud(Insert_valores(snt));
   for (i=0;i<cuantas;i++)
   {
      aux=Expresiones_elemento(Insert_valores(snt),i+1);
      genExpresion(aux);
   }

   /* Ahora genero el 'insert into' */
   genera(indentacion,"sprintf(_SelTmp,\"insert into %s values (",
      Identificador_nombre(Insert_tabla(snt)));
   indentacion++;
   /* Genero el formato del sprintf segun el tipo de los campos */
   for (i=0;i<cuantas;i++)
   {
      aux=Expresiones_elemento(Insert_valores(snt),i+1);
      if (!Constructor(aux))
         break;
      switch(tipo_exp(aux))
      {
      	case TIPO_INT: genera(0," %%d");
            break;
      	case TIPO_FLOAT: genera(0," %%f");
            break;
         case TIPO_STR: genera(0," '%%s'");
            break;
         case TIPO_DATE: 
         case TIPO_TIME: 
         case TIPO_DATETIME: 
         case TIPO_INTERVAL: 
            genera(0," '%%s'");
            break;
         default:
            warning("Se convierte una expresion de un 'insert into' a tipo cadena. Pueden aparecer problemas en tiempo de ejecucion");
            genera(0," '%%s'");
            break;
      }
      if (i<cuantas-1)
         genera(0,",");
   }
   genera(0,")\",\n");
   
   for (i=0;i<cuantas;i++)
   {
      aux=Expresiones_elemento(Insert_valores(snt),i+1);
      if (!Constructor(aux))
         break;
      if (i>0)
      {
         genera(0,", \n");
      }
      genera(indentacion,"");
      switch (tipo_exp(aux))
      {
      	case TIPO_STR:
            genera(indentacion,"pop_str(pila_exp)");
            break;
      	case TIPO_INT:
            genera(indentacion,"pop_int(pila_exp)");
            break;
      	case TIPO_FLOAT:
            genera(indentacion,"pop_float(pila_exp)");
            break;
      	case TIPO_DATE:
            genera(indentacion,"_4GLdate2str(pop_date(pila_exp))");
            break;
      	case TIPO_TIME:
            genera(indentacion,"_4GLtime2str(pop_time(pila_exp))");
            break;
      	case TIPO_DATETIME:
            genera(indentacion,"_4GLdatetime2str(pop_datetime(pila_exp))");
            break;
      	case TIPO_INTERVAL:
            genera(indentacion,"_4GLinterval2str(pop_interval(pila_exp))");
            break;
        default:
            genera(indentacion,"pop_str(pila_exp)");
            break;
      }            
   }
   indentacion--;
   genera(indentacion,");\n");

   genera(indentacion,"_4GLexec(_conn,_SelTmp);\n");
   genera(indentacion,"if (_4GLChkErrores) _4GLchkInsert(_SelTmp);\n");
   genera(indentacion,"/***** Fin del insert into %s *****/\n\n",
      Identificador_nombre(Insert_tabla(snt)));
}

void genUpdate(Arbol snt)
{
   int cuantas, i;
   Arbol aux,expr;
      
   genera(indentacion," /***** update %s *****/\n",
      Identificador_nombre(Update_tabla(snt)));

   /* Genero el 'Where' */
   if (Constructor(Update_where(snt)))
   {
      genera(indentacion,"_WhereTmp[0]='\\0';\n");
      genWhere(Update_where(snt)); 
   }

   /* Apilo primero todas las expresiones */
   cuantas=Expresiones_longitud(Update_updates(snt));
   for (i=0;i<cuantas;i++)
   {
      aux=UpdateCampos_elemento(Update_updates(snt),i+1);
      genExpresion(UpdateCampo_valor(aux));
   }

   /* Ahora genero el 'update' */
   genera(indentacion,"sprintf(_SelTmp,\"update %s set \n",
      Identificador_nombre(Update_tabla(snt)));
   indentacion++;
   /* Genero el formato del sprintf segun el tipo de los campos */
   for (i=0;i<cuantas;i++)
   {
      aux=UpdateCampos_elemento(Update_updates(snt),i+1);
      genera(indentacion,"%s=",Identificador_nombre(UpdateCampo_campo(aux)));
      expr=UpdateCampo_valor(aux);
      if (!Constructor(expr))
         break;
      switch(tipo_exp(expr))
      {
      	case TIPO_INT: genera(0,"%%d");
            break;
      	case TIPO_FLOAT: genera(0,"%%f");
            break;
         case TIPO_STR: genera(0,"'%%s'");
            break;
         case TIPO_DATE: 
         case TIPO_TIME: 
         case TIPO_DATETIME: 
         case TIPO_INTERVAL: 
            genera(0,"'%%s'");
            break;
         default:
            warning("Se convierte una expresion de un 'update' a tipo cadena. Pueden aparecer problemas en tiempo de ejecucion");
            genera(0,"'%%s'");
            break;
      }
      if (i<cuantas-1)
         genera(0,",\n");
   }

   
   if (Constructor(Update_where(snt)))
      genera(0," where %%s;\",\n");
   else
      genera(0,";\",\n");
   
   for (i=0;i<cuantas;i++)
   {
      aux=UpdateCampos_elemento(Update_updates(snt),i+1);
      expr=UpdateCampo_valor(aux);
      if (!Constructor(expr))
         break;
      if (i>0)
      {
         genera(0,", \n");
      }
      genera(indentacion,"");
      switch (tipo_exp(expr))
      {
      	case TIPO_STR:
            genera(indentacion,"pop_str(pila_exp)");
            break;
      	case TIPO_INT:
            genera(indentacion,"pop_int(pila_exp)");
            break;
      	case TIPO_FLOAT:
            genera(indentacion,"pop_float(pila_exp)");
            break;
      	case TIPO_DATE:
            genera(indentacion,"_4GLdate2str(pop_date(pila_exp))");
            break;
      	case TIPO_TIME:
            genera(indentacion,"_4GLtime2str(pop_time(pila_exp))");
            break;
      	case TIPO_DATETIME:
            genera(indentacion,"_4GLdatetime2str(pop_datetime(pila_exp))");
            break;
      	case TIPO_INTERVAL:
            genera(indentacion,"_4GLinterval2str(pop_interval(pila_exp))");
            break;
        default:
            genera(indentacion,"pop_str(pila_exp)");
            break;
      }            
   }
   indentacion--;
   if (Constructor(Update_where(snt)))
      genera(indentacion,", _WhereTmp);\n");
   else
      genera(indentacion,");\n");

   genera(indentacion,"_4GLexec(_conn,_SelTmp);\n");
   genera(indentacion,"if (_4GLChkErrores) _4GLchkUpdate(_SelTmp);\n");
   genera(indentacion,"/***** Fin del update %s *****/\n\n",
      Identificador_nombre(Update_tabla(snt)));
}

void genWhenever(Arbol snt)
{
   char *que_hago;
   if (Es(SENTENCIA,WhenEver_accion(snt)))
   {
      genera(indentacion,"/**** whenever error call function */\n");
   }
   else
   {
      que_hago=Identificador_nombre(WhenEver_accion(snt));
      genera(indentacion,"/**** whenever error %s */\n",que_hago);
      if (!strcasecmp(que_hago,"stop"))
         genera(indentacion,"_4GLChkErrores=1;\n");
      else
         genera(indentacion,"_4GLChkErrores=0;\n");
   }

}

void genDelete(Arbol snt)
{
   genera(indentacion," /***** delete from  %s *****/\n",
      Identificador_nombre(Delete_tabla(snt)));
   genera(indentacion,"sprintf(_SelTmp,\"delete from %s \");\n",
      Identificador_nombre(Delete_tabla(snt)));
   if (Constructor(Delete_where(snt)))
   {
      genera(indentacion,"strcpy(_WhereTmp,\" where \");\n");
      genWhere(Delete_where(snt));
      genera(indentacion,"strcat(_SelTmp,_WhereTmp);\n");
   }
   genera(indentacion,"_4GLexec(_conn,_SelTmp);\n");
   /* xxxxxxxxxxxxxxx comprobar errores xxxxxxxxxxxxxxxx */
   genera(indentacion,"/***** Fin del delete from  %s *****/\n\n",
      Identificador_nombre(Delete_tabla(snt)));
}

void genDeclare(Arbol snt)
{
   /* el declare cursor no hace nada; se crea la variable y punto. */
}

void generaOpenCursor(char *c)
{
   Arbol aux;
   aux=OpenCursor(Asigna_nombre(c));
   genOpenCursor(aux);
}

void genOpenCursor(Arbol snt)
{  
   char * nombre;
   int cursor_local=0,es_select=0;
   Arbol aux;
   
   nombre=Identificador_nombre(OpenCursor_nom(snt));
   aux=Existe_Var(nombre);
   if (!aux)
      yyerror ("No se encuentra el cursor %s\n",nombre);
      
   if (!strcmp(Identificador_nombre(Tipo_tip(Variable_tip(aux))),"LCURSOR"))
      cursor_local=1;
   else
      cursor_local=0;
      
   if (Es(EXPRESION,Tipo_cam(Variable_tip(aux))))
      es_select=0;
   else
      es_select=1;
      
   nombre=Identificador_nombre(OpenCursor_nom(snt));

   genera(indentacion,"/* open cursor %s (local=%d; select=%d) */\n",nombre,cursor_local,es_select);
   if (cursor_local) /* declare LOCAL cursor... */
   {
      if (es_select)
      {
         genSelTmp(Tipo_cam(Variable_tip(aux)));
         genera(indentacion,"_4GLstrncpy(_C%s.query,_SelTmp,sizeof(_C%s.query)-1);\n",nombre,nombre);
         genera(indentacion,"(void)_4GLcursor(_conn,_C%s.query,&(_C%s));\n\n",nombre,nombre);
      }
      else
      {
      	genExpresion(Tipo_cam(Variable_tip(aux)));
         genera(indentacion,"_4GLstrncpy(_C%s.query,pop_str(pila_exp),sizeof(_C%s.query)-1);\n",nombre,nombre);
         genera(indentacion,"(void)_4GLcursor(_conn,_C%s.query,&(_C%s));\n\n",nombre,nombre);
      }         
   }
   else
   {
      /*Este es un 'declare cursor...*/
      if (es_select)
      {
         genSelTmp(Tipo_cam(Variable_tip(aux)));
         genera(indentacion,"snprintf(_C%s.query,sizeof(_C%s.query),\"declare %s cursor for %%s\",_SelTmp);\n",nombre,nombre,nombre);
         genera(indentacion,"_4GLexec(_conn,_C%s.query);\n\n",nombre,nombre);
      }
      else
      {
      	genExpresion(Tipo_cam(Variable_tip(aux)));
         genera(indentacion,"snprintf(_C%s.query,sizeof(_C%s.query),\"declare %s cursor for %%s\",pop_str(pila_exp));\n",nombre,nombre,nombre);
         genera(indentacion,"_4GLexec(_conn,_C%s.query);\n\n",nombre,nombre);
      }         
   }
}

void genCloseCursor(Arbol snt)
{  
   char * nombre;
   int cursor_local=0;
   Arbol aux;
   
   nombre=Identificador_nombre(OpenCursor_nom(snt));
   aux=Existe_Var(nombre);
   if (!strcmp(Identificador_nombre(Tipo_tip(Variable_tip(aux))),"LCURSOR"))
      cursor_local=1;
   
   nombre=Identificador_nombre(OpenCursor_nom(snt));
   genera(indentacion,"/* close cursor %s */\n",nombre);

   if (cursor_local)
      genera(indentacion,"_4GLclear(_C%s);\n",nombre);
   else
      genera(indentacion,"_4GLexec(_conn,\"close %s;\");\n",nombre);
   /*xxxxxxxxxxxxx comprobar errores xxxxxxxxxxxxxxxxxx*/
}

void genFetchCursor(Arbol snt)
{
   Arbol aux;
   int cursor_local=0;
   int i,cuantos;
   char *nombre,*nombre_var;
   bool avanzar=FALSE;
   
   nombre=Identificador_nombre(FetchCursor_nom(snt));
   aux=Existe_Var(nombre);
   if (!strcmp(Identificador_nombre(Tipo_tip(Variable_tip(aux))),"LCURSOR"))
      cursor_local=1;
   avanzar = Constante_valor(FetchCursor_next(snt)) > 0 ? 1:0 ;
   genera(indentacion,"/*** fetch cursor %s **/\n",nombre);
   genera(indentacion++,"{\n");  
   if (!cursor_local)
   {
      genera(indentacion,"_CURSOR _FetchTmp;\n");
      if (avanzar)
         genera(indentacion,"(void)_4GLcursor(_conn,\"fetch 1 in %s;\",&_FetchTmp);\n",nombre);
      else
         genera(indentacion,"(void)_4GLcursor(_conn,\"fetch backward 1 in %s;\",&_FetchTmp);\n",nombre);
   }
   else
   {
      genera(indentacion,"if (avanzar && (_C%s.actual==_C%s.ntuples)) || \
         (!avanzar && (_C%s.actual==0))\n",nombre,nombre);
      genera(indentacion+1,"status=notfound;\n");
   }
   
   genera(indentacion,"if (status!=notfound)\n");
   genera(indentacion++,"{\n");

   cuantos=ListaId_longitud(FetchCursor_vars(snt));
   for (i=0;i<cuantos;i++)
   {
     aux=ListaId_elemento(FetchCursor_vars(snt),i+1);
     nombre_var=Identificador_nombre(Id_nom(aux));
     genera(indentacion,"/* cargo la var. %s */\n",nombre_var);
     if (cursor_local)
     {
       switch (tipo_var(nombre_var))
       {
          case TIPO_INT:
             genera(indentacion,"%s=atol(PQgetvalue(_C%s.res,_C%s.actual,%d));\n",
               nombre_var,nombre,nombre,i);
             break;
          case TIPO_FLOAT:
             genera(indentacion,"%s=atof(PQgetvalue(_C%s.res,_C%s.actual,%d));\n",
                nombre_var,nombre,nombre,i);
             break;
          case TIPO_STR:
             genera(indentacion,"_4GLstrncpy(%s,PQgetvalue(_C%s.res,_C%s.actual,%d),%d);\n",
                nombre_var,nombre,nombre,i,tam_var(nombre_var));
             break;
          case TIPO_DATE:
             genera(indentacion,"%s=_4GLstr2date(PQgetvalue(_C%s.res,_C%s.actual,%d));\n",
                nombre_var,nombre,nombre,i);
             break;
          case TIPO_TIME:
             genera(indentacion,"%s=_4GLstr2time(PQgetvalue(_C%s.res,_C%s.actual,%d));\n",
                nombre_var,nombre,nombre,i);
             break;
          case TIPO_DATETIME:
             genera(indentacion,"%s=_4GLstr2datetime(PQgetvalue(_C%s.res,_C%s.actual,%d));\n",
                nombre_var,nombre,nombre,i);
             break;
          case TIPO_INTERVAL:
             genera(indentacion,"%s=_4GLDBstr2interval(PQgetvalue(_C%s.res,_C%s.actual,%d));\n",
                nombre_var,nombre,nombre,i);
             break;
       }
     }
     else
     {
       switch (tipo_var(nombre_var))
       {
          case TIPO_INT:
             genera(indentacion,"%s=atol(PQgetvalue(_FetchTmp.res,0,%d));\n",
                nombre_var,i);
             break;
          case TIPO_FLOAT:
             genera(indentacion,"%s=atof(PQgetvalue(_FetchTmp.res,0,%d));\n",
                nombre_var,i);
             break;
          case TIPO_STR:
             genera(indentacion,"_4GLstrncpy(%s,PQgetvalue(_FetchTmp.res,0,%d),%d);\n",
                nombre_var,i,tam_var(nombre_var));
             break;
          case TIPO_DATE:
             genera(indentacion,"%s=_4GLstr2date(PQgetvalue(_FetchTmp.res,0,%d));\n",
                nombre_var,i);
             break;
          case TIPO_TIME:
             genera(indentacion,"%s=_4GLstr2time(PQgetvalue(_FetchTmp.res,0,%d));\n",
                nombre_var,i);
             break;
          case TIPO_DATETIME:
             genera(indentacion,"%s=_4GLstr2datetime(PQgetvalue(_FetchTmp.res,0,%d));\n",
                nombre_var,i);
             break;
          case TIPO_INTERVAL:
             genera(indentacion,"%s=_4GLDBstr2interval(PQgetvalue(_FetchTmp.res,0,%d));\n",
                nombre_var,i);
             break;
       }
     }
   }

   if (cursor_local)
   {
      if (avanzar)
         genera(indentacion,"_C%s.actual++;\n",nombre);
      else
         genera(indentacion,"_C%s.actual--;\n",nombre);
   }
   else
   {
      genera(indentacion,"_4GLclear(_FetchTmp);\n");
   }
   genera(--indentacion,"}\n");

   genera(--indentacion,"} /* fin de fetch %s */\n\n",nombre);         
}

void genForeach(Arbol snt)
{
   Arbol aux;
   int i, cuantas;
   cadena nombre;
   int cursor_local=0;
   int numForeachAnterior;
   numForeachAnterior=numForeach; /* Por si hay un 'foreach' dentro de otro */
   numForeach=maxForeach++;
   
   strcpy(nombre,Identificador_nombre(Foreach_nom(snt)));

   /* Compruebo si se declara el cursor como 'local' */
   aux=Existe_Var(nombre);
   if (!strcmp(Identificador_nombre(Tipo_tip(Variable_tip(aux))),"LCURSOR"))
      cursor_local=1;

   genera(indentacion,"/******** foreach %s *********/\n",nombre);   
   genera(indentacion,"/** Preparo la query **/\n");
   generaOpenCursor(nombre);

   if (cursor_local)
   {
      genera(indentacion,"for(_C%s.actual=0;_C%s.actual<_C%s.ntuples;_C%s.actual++)\n",nombre,nombre,nombre,nombre);
   }
   else
   {
      genera(indentacion,"(void)_4GLcursor(_conn,\"fetch 1 in %s;\",&_CurTmp);\n",nombre);
      genera(indentacion,"while(_CurTmp.ntuples==1)\n",
         nombre);
   }
   genera(indentacion,"{\n");
   indentacion++;
   cuantas=ListaId_longitud(Foreach_vars(snt));
   for (i=0;i<cuantas;i++)
   {
      cadena var;
      aux=ListaId_elemento(Foreach_vars(snt),i+1);
      if (!Constructor(aux))
         break;
      strcpy(var,Identificador_nombre(Id_nom(aux)));
      if (cursor_local)
      {
         switch (tipo_var(var))
         {
         	case TIPO_INT:
               genera(indentacion,"%s=atol(PQgetvalue(_C%s.res,_C%s.actual,%d));\n",
                  var,nombre,nombre,i);
               break;
         	case TIPO_FLOAT:
               genera(indentacion,"%s=atof(PQgetvalue(_C%s.res,_C%s.actual,%d));\n",
                  var,nombre,nombre,i);
               break;
            case TIPO_STR:
               genera(indentacion,"_4GLstrncpy(%s,PQgetvalue(_C%s.res,_C%s.actual,%d),%d);\n",
                  var,nombre,nombre,i,tam_var(var));
               break;
            case TIPO_DATE:
               genera(indentacion,"%s=_4GLstr2date(PQgetvalue(_C%s.res,_C%s.actual,%d));\n",
                  var,nombre,nombre,i);
               break;
            case TIPO_TIME:
               genera(indentacion,"%s=_4GLstr2time(PQgetvalue(_C%s.res,_C%s.actual,%d));\n",
                  var,nombre,nombre,i);
               break;
            case TIPO_DATETIME:
               genera(indentacion,"%s=_4GLstr2datetime(PQgetvalue(_C%s.res,_C%s.actual,%d));\n",
                  var,nombre,nombre,i);
               break;
            case TIPO_INTERVAL:
               genera(indentacion,"%s=_4GLDBstr2interval(PQgetvalue(_C%s.res,_C%s.actual,%d));\n",
                  var,nombre,nombre,i);
               break;
         }
      }
      else
      {
         switch (tipo_var(var))
         {
         	case TIPO_INT:
               genera(indentacion,"%s=atol(PQgetvalue(_CurTmp.res,0,%d));\n",
                  var,i);
               break;
         	case TIPO_FLOAT:
               genera(indentacion,"%s=atof(PQgetvalue(_CurTmp.res,0,%d));\n",
                  var,i);
               break;
            case TIPO_STR:
               genera(indentacion,"_4GLstrncpy(%s,PQgetvalue(_CurTmp.res,0,%d),%d);\n",
                  var,i,tam_var(var));
               break;
            case TIPO_DATE:
               genera(indentacion,"%s=_4GLstr2date(PQgetvalue(_CurTmp.res,0,%d));\n",
                  var,i);
               break;
            case TIPO_TIME:
               genera(indentacion,"%s=_4GLstr2time(PQgetvalue(_CurTmp.res,0,%d));\n",
                  var,i);
               break;
            case TIPO_DATETIME:
               genera(indentacion,"%s=_4GLstr2datetime(PQgetvalue(_CurTmp.res,0,%d));\n",
                  var,i);
               break;
            case TIPO_INTERVAL:
               genera(indentacion,"%s=_4GLDBstr2interval(PQgetvalue(_CurTmp.res,0,%d));\n",
                  var,i);
               break;
         }
      }
   }

   /* Genero el bloque que hay dentro del foreach */
   genSentencias(Foreach_cod(snt));
   
   genera(indentacion,"_Foreach_%d_0: /* Salto aqui en un CONTINUE FOREACH */\n",numForeach);

   if (!cursor_local)
   {
      genera(indentacion,"_4GLclear(_CurTmp);\n");
      genera(indentacion,"(void)_4GLcursor(_conn,\"fetch 1 in %s;\",&_CurTmp);\n",nombre);
   }
   indentacion--;
   genera(indentacion,"} /****** fin del Foreach *******/ \n");
   genera(indentacion,"_Foreach_%d_1: /* Salto aqui en un EXIT FOREACH */\n",numForeach);
   if (!cursor_local)
   {
      genera(indentacion,"_4GLclear(_CurTmp);\n");
      genera(indentacion,"_4GLexec(_conn,\"close %s ;\");\n",nombre);
   }
   else
      genera(indentacion,"_4GLclear(_C%s);\n",nombre);

   numForeach=numForeachAnterior;   
}

void genContinueForeach(Arbol snt)
{
   genera(indentacion,"goto _Foreach_%d_0; /* CONTINUE FOREACH */\n",numForeach);
}
void genExitForeach(Arbol snt)
{
   genera(indentacion,"goto _Foreach_%d_1; /* EXIT FOREACH */\n",numForeach);
}

void genLlamada(Arbol snt)
{
   Arbol aux;
   int i,cuantas;
   enum tipos tipo;
   tipo=tipo_fun(Identificador_nombre(Llamada_nom(snt)));
   cuantas=Expresiones_longitud(Llamada_arg(snt));
   /* Apilo los parámetros */
   for (i=0;i<cuantas;i++)
   {
      aux=Expresiones_elemento(Llamada_arg(snt),i+1);
      if (!Constructor(aux))
         break;
      genExpresion(aux);
   }
   /* Si es una funcion de 4GL... */
   if (tipo==TIPO_VOID)
      genera(indentacion,"(void)_Fn_%s(%d);\n",Identificador_nombre(Llamada_nom(snt)),cuantas);
   else /* Si es una funcion externa, de C... */
   {
      switch (tipo)
      {
      	case TIPO_INT:
            genera(indentacion,"push_int(pila_exp, %s(", Identificador_nombre(Llamada_nom(snt)));
            break;
      	case TIPO_FLOAT:
            genera(indentacion,"push_float(pila_exp, %s(", Identificador_nombre(Llamada_nom(snt)));
            break;
      	case TIPO_STR:
            genera(indentacion,"push_str(pila_exp, %s(", Identificador_nombre(Llamada_nom(snt)));
            break;
      	case TIPO_DATE:
            genera(indentacion,"push_date(pila_exp, %s(", Identificador_nombre(Llamada_nom(snt)));
            break;
      	case TIPO_TIME:
            genera(indentacion,"push_time(pila_exp, %s(", Identificador_nombre(Llamada_nom(snt)));
            break;
      	case TIPO_DATETIME:
            genera(indentacion,"push_datetime(pila_exp, %s(", Identificador_nombre(Llamada_nom(snt)));
            break;
      	case TIPO_INTERVAL:
            genera(indentacion,"push_interval(pila_exp, %s(", Identificador_nombre(Llamada_nom(snt)));
            break;
      }
      /* Y le mando los params que he apilado */
      for (i=0;i<cuantas;i++)
      {
         aux=Expresiones_elemento(Llamada_arg(snt),i+1);
         if (!Constructor(aux))
            break;
         tipo=tipo_exp(aux);
         if (i>0)
            genera(0,", ");
         switch (tipo)
         {
         	case TIPO_INT:
               genera(0,"pop_int(pila_exp)");
               break;
         	case TIPO_FLOAT:
               genera(0,"pop_float(pila_exp)");
               break;
         	case TIPO_DATE:
               genera(0,"pop_date(pila_exp)");
               break;
         	case TIPO_TIME:
               genera(0,"pop_time(pila_exp)");
               break;
         	case TIPO_DATETIME:
               genera(0,"pop_datetime(pila_exp)");
               break;
         	case TIPO_INTERVAL:
               genera(0,"pop_interval(pila_exp)");
               break;
         	case TIPO_STR:
               genera(0,"pop_str(pila_exp)");
               break;
         }
      }
      genera(0,"));\n");
   }
      
}

void genRetorno(Arbol snt)
{
   int i, cuantas;
   Arbol aux;

   cuantas=Expresiones_longitud(Retorno_exp(snt));
   if (cuantas>0) 
      genera (indentacion,"/***** Apilo los valores de retorno *****/\n");
   for (i=1;i<=cuantas;i++)
   {
      aux=Expresiones_elemento(Retorno_exp(snt),i);
      genExpresion(aux);
   }
   genera(indentacion,"/***** Salgo de la funcion *****/\n");
   genera(indentacion,"return %d; /* Devuelvo el numero de valores realmente devueltos */\n",cuantas);
}

void genIf(Arbol snt)
{
   genExpresion(If_con(snt));
   genera(indentacion,"if (pop_int(pila_exp))\n");
   genera(indentacion,"{\n");
   indentacion++;
   genSentencias(If_codsi(snt));
   indentacion--;
   genera(indentacion,"}\n");
   if (Constructor(If_codelse(snt)))
   {
      genera(indentacion,"else\n");
      genera(indentacion,"{\n");
      indentacion++;
      genSentencias(If_codelse(snt));
      indentacion--;
      genera(indentacion,"}\n");
   }
}

void genFor(Arbol snt)
{
   Arbol aux;
   char *nombre;
   enum tipos tip;
   int tam;
   int numForAnterior;
   numForAnterior=numFor;
   numFor=maxFor++;

   nombre=Identificador_nombre(Id_nom(For_cont(snt)));
   /* genero la asignacion del valor inicial */
   aux=Existe_Var(nombre);
   tip=tipo_var(nombre);
   tam=tam_var(nombre);
   genera(indentacion,"/* bucle for %s */\n",nombre);
   genExpresion(For_desde(snt));
   /* Y ahora la asignacion */
   switch (tip)
   {
      case TIPO_DATE:
         genera(indentacion,"%s=pop_date(pila_exp);\n",nombre);
         break;
      case TIPO_INT:
         genera(indentacion,"%s=pop_int(pila_exp);\n",nombre);
         break;
      case TIPO_FLOAT:
         genera(indentacion,"%s=pop_float(pila_exp);\n",nombre);
         break;
   }
   /* Genero la comparacion */
   aux=Id(Asigna_nombre(nombre));
   genExpresion(For_hasta(snt));
   genExpresion(aux);
   genera(indentacion,"op_cmp(pila_exp,-1);\n");
   /* Y ahora de verdad el bucle */
   genera(indentacion,"while (pop_int(pila_exp))\n");
   genera(indentacion++,"{\n");
   genSentencias(For_cod(snt));
   genera(indentacion,"\n");
   genera(indentacion,"_ContinueFor_%d: /* Salto aqui en un CONTINUE FOR */\n",numFor);
   genera(indentacion,"/* incremento el contador %s */\n",nombre);
   genera(indentacion,"push_int(pila_exp,1);\n");
   genExpresion(aux);
   genera(indentacion,"op_suma(pila_exp);\n");
   switch (tip)
   {
      case TIPO_DATE:
         genera(indentacion,"%s=pop_date(pila_exp);\n",nombre);
         break;
      case TIPO_INT:
         genera(indentacion,"%s=pop_int(pila_exp);\n",nombre);
         break;
      case TIPO_FLOAT:
         genera(indentacion,"%s=pop_float(pila_exp);\n",nombre);
         break;
   }
   /* vuelvo a comparar */
   genExpresion(For_hasta(snt));
   genExpresion(aux);
   genera(indentacion,"op_cmp(pila_exp,-1);\n");
   genera(--indentacion,"}\n");
   genera(indentacion,"_ExitFor_%d: /* Salto aqui en un EXIT FOR */\n",numFor);
   numFor=numForAnterior;
}

void genContinueFor(Arbol snt)
{
   genera(indentacion,"goto _ContinueFor_%d; /* CONTINUE FOR */\n",numFor);
}
void genExitFor(Arbol snt)
{
   genera(indentacion,"goto _ExitFor_%d; /* EXIT FOR */\n",numFor);
}

void genWhile(Arbol snt)
{
   int numWhileAnterior;
   numWhileAnterior=numWhile;
   numWhile=maxWhile++;
   
   genExpresion(While_con(snt));
   genera(indentacion,"while (pop_int(pila_exp))\n");
   genera(indentacion,"{\n");
   indentacion++;
   genSentencias(While_cod(snt));
   genera(indentacion,"_ContWhile_%d: /* Salto aqui en un CONTINUE WHILE */\n",numWhile); 
   genExpresion(While_con(snt));
   indentacion--;
   genera(indentacion,"}\n");
   genera(indentacion,"_ExitWhile_%d: /* Salto aqui en un EXIT WHILE */\n",numWhile);
   numWhile=numWhileAnterior;
}


void genContinueWhile(Arbol snt)
{
   genera(indentacion,"goto _ContWhile_%d; /* CONTINUE WHILE */\n",numWhile);
}
void genExitWhile(Arbol snt)
{
   genera(indentacion,"goto _ExitWhile_%d; /* EXIT WHILE */\n",numWhile);
}

void genDelay(Arbol snt)
{
   genExpresion(Delay_tiempo(snt));
   genera(indentacion,"sleep(pop_int(pila_exp));\n\n");
}

void genAsignacion(Arbol snt)
{
   enum tipos tip;
   int tam=1;
   Arbol aux, parte;
   char *dest;
   int i,cuantas;

   cuantas=Expresiones_longitud(Asignacion_fue(snt));
   /* Primero apilo las expresiones */
   for (i=1; i<=cuantas;i++)
   {
      genExpresion(Expresiones_elemento(Asignacion_fue(snt),i));
   }

   cuantas=ListaId_longitud(Asignacion_des(snt));
   /* Y ahora las desapilo y las asigno las asignaciones */
   for (i=cuantas; i>=1; i--)
   {
      parte=ListaId_elemento(Asignacion_des(snt),i);
      dest=Identificador_nombre(Id_nom(parte));
      aux=Existe_Var(dest);
      if (!aux)
         yyerror("No se encuentra la variable %s",dest);
         
      tip=tipo_var(dest);
      tam=Constante_valor(Tipo_tam(Variable_tip(aux)));
      /* Y ahora la asignacion */
      switch (tip)
      {
         case TIPO_STR:
            genera(indentacion,"_4GLstrncpy(%s,pop_str(pila_exp),%d);\n",
               dest,tam);
            break;
         case TIPO_DATE:
            genera(indentacion,"%s=pop_date(pila_exp);\n",dest);
            break;
         case TIPO_TIME:
            genera(indentacion,"%s=pop_time(pila_exp);\n",dest);
            break;
         case TIPO_DATETIME:
            genera(indentacion,"%s=pop_datetime(pila_exp);\n",dest);
            break;
         case TIPO_INTERVAL:
            genera(indentacion,"%s=pop_interval(pila_exp);\n",dest);
            break;
         case TIPO_INT:
            genera(indentacion,"%s=pop_int(pila_exp);\n",dest);
            break;
         case TIPO_FLOAT:
            genera(indentacion,"%s=pop_float(pila_exp);\n",dest);
            break;
      }
   }
}

void genAbVentana(Arbol snt)
{
   cadena nom_ventana;
   struct atributos attrs;
   /* Leo los atributos de la ventana */
   attrs=lee_atributos(AbVentana_attr(snt));
   strcpy(nom_ventana,Identificador_nombre(AbVentana_nom(snt)));
   /* Apilo los parametros */
   genera(indentacion,"/**** Apilo parametros para nueva ventana *****/\n");
   indentacion++;

   genExpresion(AbVentana_h(snt));
   genExpresion(AbVentana_w(snt));
   genExpresion(AbVentana_y(snt));
   genExpresion(AbVentana_x(snt));
   genera(indentacion,"push_int(pila_exp,%d);\n",attrs.borde);
   genera(indentacion,"push_int(pila_exp,%d);\n",(attrs.color-1)/8);
   genera(indentacion,"push_int(pila_exp,%d);\n",(attrs.color-1)%8);
   genera(indentacion,"push_int(pila_exp,%d);\n",attrs.brillo);
   if (Constructor(AbVentana_tit(snt)))
      genExpresion(AbVentana_tit(snt));
   else
      genera(indentacion,"push_str(pila_exp,\"\");\n");
   indentacion--;
   /* Crea la ventana */
   genera(indentacion,"/* Abrir Ventana %s*/\n",nom_ventana);
   genera(indentacion,"%s=_4GLnewwin(pop_int(pila_exp),\n",nom_ventana);
   genera(indentacion+1,"pop_int(pila_exp),\n");
   genera(indentacion+1,"pop_int(pila_exp),\n");
   genera(indentacion+1,"pop_int(pila_exp),\n");
   genera(indentacion+1,"pop_int(pila_exp),\n");
   genera(indentacion+1,"pop_int(pila_exp),\n");
   genera(indentacion+1,"pop_int(pila_exp),\n");
   genera(indentacion+1,"pop_int(pila_exp),\n");
   genera(indentacion+1,"pop_str(pila_exp));\n",nom_ventana);
}

struct atributos lee_atributos(Arbol attrs)
{
   int i,cuantas;
   struct atributos resultado;
   Arbol aux;
   /* Si no tiene, le pongo unos por defecto */
   resultado.color=COLOR_WHITE*8+COLOR_BLACK+1;
   resultado.brillo=0;
   resultado.borde=0;
   /* Recorro la lista de atributos */
   cuantas=AttsVentana_longitud(attrs);
   for (i=0;i<cuantas;i++)
   {
      aux=AttsVentana_elemento(attrs,i+1);
      if (!Constructor(aux))
         break;
      else
         if (!strcmp(Identificador_nombre(AtVentana_nom(aux)),"COLOR"))
            resultado.color=Constante_valor(AtVentana_val(aux));
      else
         if (!strcmp(Identificador_nombre(AtVentana_nom(aux)),"BORDER"))
            resultado.borde=Constante_valor(AtVentana_val(aux));
      else
         if (!strcmp(Identificador_nombre(AtVentana_nom(aux)),"BRIGHT"))
            resultado.brillo=1;
   }
   return resultado;
}

void genCieVentana(Arbol snt)
{
   cadena nombre;
   strcpy(nombre,Identificador_nombre(CieVentana_nom(snt)));
   genera(indentacion,"_4GLdelwin(%s); %s=NULL;\n",nombre,nombre);
   
}

void genMovVentana(Arbol snt)
{
   cadena nombre;
   genExpresion(MovVentana_y(snt));
   genExpresion(MovVentana_x(snt));

   strcpy(nombre,Identificador_nombre(MovVentana_nom(snt)));
   genera(indentacion,"_4GLmovewin(%s,(int)pop_int(pila_exp),(int)pop_int(pila_exp));\n",nombre);
}

void genClearWindow(Arbol snt)
{
   genera(indentacion,"wclear(curwin); /* CLEAR WINDOW */\n");
   genera(indentacion,"update_panels(); doupdate();\n");
}

void genCurVentana(Arbol snt)
{
   cadena nombre;
   strcpy(nombre,Identificador_nombre(CurVentana_nom(snt)));
   genera(indentacion,"curwin=%s->w;\n",nombre);
   genera(indentacion,"_curwin=%s;\n",nombre);
   genera(indentacion,"if (%s->borde==1)\n",nombre);
   genera(indentacion+1,"top_panel(%s->pb);\n",nombre);
   genera(indentacion,"top_panel(%s->p);\n",nombre);
   genera(indentacion,"update_panels();\n");
   genera(indentacion,"doupdate();\n");
}

void genLeer(Arbol snt)
{
   int numPromptAnt;
   char *nombre;
   
   nombre=Identificador_nombre(Id_nom(Leer_var(snt)));

   numPromptAnt=numPrompt;
   numPrompt=maxPrompt++;
   if (Constructor(Leer_esc(snt)))
   {
      genExpresion(Leer_esc(snt));
      genera(indentacion,"wprintw(curwin,\"%%s\",pop_str(pila_exp));\n");
      genera(indentacion,"update_panels();\n");
      genera(indentacion,"doupdate();\n");
   }

   /* Si tiene 'on key... */
   genera(indentacion,"_Prompt%d:\n",numPrompt);
   genera(indentacion++,"{\n");
   /* Si era un 'PROMPT ... FOR CHAR ...' */
   
   if (Constante_valor(Leer_cha(snt)) == 1)
   {
      genera(indentacion,"int _tecla%d;\n\n",numPrompt);
      genera(indentacion,"_tecla%d=getch();\n",numPrompt);
      genera(indentacion,"sprintf(%s,\"%%c\",_tecla%d);\n\n",nombre,numPrompt);
   }   
   else
   {
      genera(indentacion,"echo();\n");      
      switch (tipo_var(nombre))
      {
      	case TIPO_INT:
            genera(indentacion,"wgetnstr(curwin,_StrTmp,255);\n");
            genera(indentacion,"%s=atol(_StrTmp);\n",nombre);
            break;
      	case TIPO_FLOAT:
            genera(indentacion,"wgetnstr(curwin,_StrTmp,255);\n");
            genera(indentacion,"%s=atof(_StrTmp);\n",nombre);
            break;
      	case TIPO_DATE:
            genera(indentacion,"wgetnstr(curwin,_StrTmp,255);\n");
            genera(indentacion,"%s=_4GLstr2date(_StrTmp);\n",nombre);
            break;
      	case TIPO_TIME:
            genera(indentacion,"wgetnstr(curwin,_StrTmp,255);\n");
            genera(indentacion,"%s=_4GLstr2time(_StrTmp);\n",nombre);
            break;
      	case TIPO_DATETIME:
            genera(indentacion,"wgetnstr(curwin,_StrTmp,255);\n");
            genera(indentacion,"%s=_4GLstr2datetime(_StrTmp);\n",nombre);
            break;
      	case TIPO_INTERVAL:
            genera(indentacion,"wgetnstr(curwin,_StrTmp,255);\n");
            genera(indentacion,"%s=_4GLstr2interval(_StrTmp);\n",nombre);
            break;
         case TIPO_STR:
            genera(indentacion,"wgetnstr(curwin,%s,%d);\n",nombre,
               tam_var(nombre));
            break;
      }
      genera(indentacion,"noecho();\n");
   }
   /* Genero los 'on key' */
   if (Constructor(Leer_keys(snt)))
   {
      int i,cuantas;
      Arbol aux;
      cuantas=LeerKeys_longitud(Leer_keys(snt));
      genera(indentacion,"switch(_tecla%d)\n",numPrompt);
      genera(indentacion++,"{\n");
      for (i=1;i<=cuantas;i++)
      {
         aux=LeerKeys_elemento(Leer_keys(snt),i);
         genera(indentacion,"case %s:\n",Identificador_nombre(LeerKey_nom(aux)));
         indentacion++;
         genSentencias(LeerKey_cod(aux));
         genera(indentacion,"break;\n");
         indentacion--;
      }
      genera(--indentacion,"}\n");
      genera(indentacion,"goto _Prompt%d;\n",numPrompt);
   }
   genera(--indentacion,"}\n");
   genera(indentacion,"_Fin_Prompt%d:\n",numPrompt);
   numPrompt=numPromptAnt;
}

void genLeerExit(Arbol snt)
{
   genera(indentacion,"goto _Fin_Prompt%d;\n",numPrompt);
}

void genEscribir(Arbol snt)
{
   Arbol aux;
   int i,cuantas;
   struct atributos attrs;
   bool sw_salto=TRUE;
   
   cuantas=Displays_longitud(Escribir_lst(snt));
   for (i=0;i<cuantas;i++)
   {
      aux=Displays_elemento(Escribir_lst(snt),i+1);
      if (!Constructor(aux))
         break;
      /* Si se indican atributos, guardo los de la ventana */
      if (Constructor(Display_attr(aux)))
      {
         attrs=lee_atributos(Display_attr(aux));
         genera(indentacion,"_i=wgetbkgd(curwin);\n");
         if (attrs.brillo == 0)
            genera(indentacion,"wbkgdset(curwin,COLOR_PAIR(%d));\n",attrs.color);
         else
            genera(indentacion,"wbkgdset(curwin,COLOR_PAIR(%d)|A_BOLD);\n",attrs.color);
      }
      { /* Imprimo las expresiones */
     	   int j,cuantas_exp;
         cuantas_exp=Expresiones_longitud(Display_exp(aux));
         for (j=1; j<=cuantas_exp;j++)
         {
            if ((j==1) && (Constructor(Display_y(aux))))
            { /* La primera expresion de la lista la imprimo 
                 en las coordenadas indicadas por el programador */
               sw_salto=FALSE;
               genExpresion(Display_y(aux));
               genExpresion(Display_x(aux));
               genExpresion(Expresiones_elemento(Display_exp(aux),j));
               genera(indentacion,"mvwprintw(curwin,pop_int(pila_exp),pop_int(pila_exp),pop_str(pila_exp));\n");
            }
            else            
            {
               genExpresion(Expresiones_elemento(Display_exp(aux),j));
               genera(indentacion,"wprintw(curwin,\"%%s\",pop_str(pila_exp));\n");
            }
         }
      }
      /* Si se indican atributos, recupero los de la ventana */

      if (Constructor(Display_attr(aux)))
         genera(indentacion,"wbkgdset(curwin,_i);\n");
      
   }
   /* Salto de linea al final de todas las expresiones */ 
   if (sw_salto)
      genera(indentacion,"wprintw(curwin,\"\\n\");\n");

   /* Refresco la pantalla una sola vez, al final */
   genera(indentacion,"update_panels();\n");
   genera(indentacion,"doupdate();\n");
}

void genExpresion(Arbol exp)
{
   switch(Constructor(exp))
   {
      case CONST:
         genConstante(exp);
         break;
      case SUBCADENA:
         genSubcadena(exp);
         break;
      case USING:
         genUsing(exp);
         break;
      case CLIPPED:
         genClipped(exp);
         break;
      case CADENA:
         genCadena(exp);
         break;
      case BINARIA:
         genBinaria(exp);
         break;
      case UNARIA:
         genUnaria(exp);
         break;
      case LLAMADA:
         genLlamada(exp);
         break;
      case ID:
			genNombre(exp);
         break;
      default: 
         yyerror("Expresion del tipo %d no reconocida\n");
         break;
   }
}

void genConstante(Arbol cte)
{
   if (!strcmp(Identificador_nombre(Const_tip(cte)),"ENTERO"))
		genera(indentacion,"push_int(pila_exp, %ld);\n",(long)Constante_valor(Const_val(cte)));
   else if (!strcmp(Identificador_nombre(Const_tip(cte)),"REAL"))
		genera(indentacion,"push_float(pila_exp, %f);\n",Constante_valor(Const_val(cte)));
}

void genNombre(Arbol var)
{
   char *nombre;
   nombre=Identificador_nombre(Id_nom(var));
   switch (tipo_var(nombre))
   {
      case TIPO_INT:
         genera(indentacion,"push_int(pila_exp, %s);\n",nombre);
         break;
      case TIPO_FLOAT:
         genera(indentacion,"push_float(pila_exp, %s);\n",nombre);
         break;
      case TIPO_STR:
         genera(indentacion,"push_str(pila_exp, %s);\n",nombre);
         break;
      case TIPO_DATE:
         genera(indentacion,"push_date(pila_exp, %s);\n",nombre);
         break;
      case TIPO_TIME:
         genera(indentacion,"push_time(pila_exp, %s);\n",nombre);
         break;
      case TIPO_DATETIME:
         genera(indentacion,"push_datetime(pila_exp, %s);\n",nombre);
         break;
      case TIPO_INTERVAL:
         genera(indentacion,"push_interval(pila_exp, %s);\n",nombre);
         break;
      default: 
         yyerror("No se encuentra el tipo de la variable %s",nombre);
         exit(1);
   }
}


void genCadena(Arbol cad)
{
   genera(indentacion,"push_str(pila_exp, \"%s\");\n",Identificador_nombre(Cadena_val(cad)));
}

void genSubcadena(Arbol expr)
{
   /* Apilo la variable completa, y luego le corto el trozo que me interesa */
   genExpresion(Subcadena_desde(expr));
   genExpresion(Subcadena_hasta(expr));
   genExpresion(Subcadena_exp(expr));
   genera(indentacion,"_4GLstrncpy(_StrTmp,pop_str(pila_exp),sizeof(_StrTmp)-1);\n");
   genera(indentacion,"_StrTmp[_4GLmin(pop_int(pila_exp),strlen(_StrTmp))]='\\0';\n");
   genera(indentacion,"push_str(pila_exp,_StrTmp+pop_int(pila_exp)-1);\n");
}
   
void genUsing(Arbol expr)
{
   genExpresion(Using_exp(expr));
   genera(indentacion,"push_str(pila_exp,\"%s\");\n",Identificador_nombre(Using_mascara(expr)));
   genera(indentacion,"setlocale(LC_NUMERIC,\"\");\n");
   genera(indentacion,"setlocale(LC_MONETARY,\"\");\n");
   genera(indentacion,"push_str(pila_exp,_4GLdousing(pop_float(pila_exp),pop_str(pila_exp)));\n");
   genera(indentacion,"setlocale(LC_MONETARY,\"C\");\n");
   genera(indentacion,"setlocale(LC_NUMERIC,\"C\");\n");
}

void genClipped(Arbol expr)
{
   genExpresion(Clipped_exp(expr));
   genera(indentacion,"_4GLdoclipped();\n");
}

void genUnaria(Arbol expr)
{
   genExpresion(Unaria_term(expr));
   switch(Constructor(Unaria_op(expr)))
   {
      case MENOS:
         genera(indentacion,"push_int(pila_exp,-1);\n");
         genera(indentacion,"op_mult(pila_exp);\n");
         break;
      case NEGACION:
         genera(indentacion,"op_negar(pila_exp);\n");
         break;
   }
}

void genBinaria(Arbol bin)
{
   /* Apila los dos valores y luego realiza la operacion */
   
   /* APILO EN ORDEN INVERSO, PARA QUE LUEGO AL DESAPILAR APAREZCAN ORDENADOS */
   genExpresion(Binaria_termd(bin));
   genExpresion(Binaria_termi(bin));
   switch (Constructor(Binaria_op(bin)))
   {
      case SUMA:
         genera(indentacion,"op_suma(pila_exp);\n");
         break;
      case RESTA:
         genera(indentacion,"op_resta(pila_exp);\n");
         break;
      case MULTIPLICA:
         genera(indentacion,"op_mult(pila_exp);\n");
         break;
      case DIVIDE:
         genera(indentacion,"op_divide(pila_exp);\n");
         break;
      case MAYOR:
         genera(indentacion,"op_cmp(pila_exp,2);\n");
         break;
      case MAYORIGUAL:
         genera(indentacion,"op_cmp(pila_exp,1);\n");
         break;
      case MENORIGUAL:
         genera(indentacion,"op_cmp(pila_exp,-1);\n");
         break;
      case MENOR:
         genera(indentacion,"op_cmp(pila_exp,-2);\n");
         break;
      case IGUAL:
         genera(indentacion,"op_cmp(pila_exp,0);\n");
         break;
      case DISTINTO:
         genera(indentacion,"op_cmp(pila_exp,0);\n");
         genera(indentacion,"op_negar(pila_exp);\n");
         break;
      case AND:
         genera(indentacion,"op_and(pila_exp);\n");
         break;
      case OR:
         genera(indentacion,"op_or(pila_exp);\n");
         break;
   }
}

void error(char *fmt,...)
{
   va_list args;
   char linea[256];

   /*Copio la lista de parámetros recibidos */
   va_start (args, fmt);
   vsprintf (linea, fmt, args);
   va_end (args);
   /* La imprimo */
   fprintf(stderr,"ERROR: %s\n",linea);
}                  

void warning(char *fmt,...)
{
   va_list args;
   char linea[1024];

   /*Copio la lista de parámetros recibidos */
   va_start (args, fmt);
   vsprintf (linea, fmt, args);
   va_end (args);
   /* La imprimo */
   if (sw_warning == 1)
      fprintf(stderr,"WARNING: %s\n",linea);
}                  

void genera(int indent, char *fmt,...)
{
   va_list args;
   char linea[1024];

   /*Copio la lista de parámetros recibidos */
   va_start (args, fmt);
   vsprintf (linea, fmt, args);
   va_end (args);
   /* La grabo en el fichero, con la indentacion adecuada */
   fprintf(fp,"%*.*s%s",indent*3,indent*3," ",linea);
   if (sw_verfuente)
      fprintf(stdout,"%*.*s%s",indent*3,indent*3," ",linea);
}                  

