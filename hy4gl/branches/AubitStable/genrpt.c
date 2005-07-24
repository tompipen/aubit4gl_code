/******** Generaci¢n  de c¢digo de funciones de listados .*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include <libpq-fe.h>
#include "global.h"
#include "asa.h"
#include "prototipos.h"

extern int indentacion, en_select;
extern Arbol lst_locales, lst_globales, lst_param, db;
static void genMascaraInsert(char *campo);
static void genDatoInsert(char *nomparam);
Arbol vars=NULL;

static void genLinCreate(int indice,char *nomparam)
{
   int i,cuantos;
   Arbol reg,campo;
   char nomcampo[256];
   char *sinpunto;

   /* Si estoy tratando un campo de un registro, le quito el 'punto' */
   if (rindex(nomparam,'.'))
      sinpunto=rindex(nomparam,'.')+1;
   else
      sinpunto=nomparam;
      
   switch(tipo_var(nomparam))
   {
      case TIPO_INT:
         vars=Variables(vars,Variable(Asigna_nombre(nomparam),NULL));
         genera(indentacion,"_%d_%s integer,\n",indice,sinpunto);
         break;
      case TIPO_STR:
         vars=Variables(vars,Variable(Asigna_nombre(nomparam),NULL));
         genera(indentacion,"_%d_%s char(%d),\n",indice,sinpunto,tam_var(nomparam));
         break;
      case TIPO_DATE:
         vars=Variables(vars,Variable(Asigna_nombre(nomparam),NULL));
         genera(indentacion,"_%d_%s date,\n",indice,sinpunto);
         break;
      case TIPO_TIME:
         vars=Variables(vars,Variable(Asigna_nombre(nomparam),NULL));
         genera(indentacion,"_%d_%s time,\n",indice,sinpunto);
         break;
      case TIPO_DATETIME:
         vars=Variables(vars,Variable(Asigna_nombre(nomparam),NULL));
         genera(indentacion,"_%d_%s datetime,\n",indice,sinpunto);
         break;
      case TIPO_INTERVAL:
         vars=Variables(vars,Variable(Asigna_nombre(nomparam),NULL));
         genera(indentacion,"_%d_%s tinterval,\n",indice,sinpunto);
         break;
      case TIPO_RECORD:
         reg=Existe_Var(nomparam);
         cuantos=Variables_longitud(Tipo_cam(Variable_tip(reg)));
         for (i=1;i<=cuantos;i++)
         {
            campo=Variables_elemento(Tipo_cam(Variable_tip(reg)),i);
            if (Constructor(campo))
            {
               sprintf(nomcampo,"%s.%s",nomparam,Identificador_nombre(Variable_nom(campo)));
               genLinCreate(indice,nomcampo);
            }
         }
         break;
      default:
         error("Tipo %d no soportado",tipo_var(nomparam));
   }
}

/* Funcion que prepara las tablas para un listado.
   Crea una tabla temporal donde se guardan los datos que se envian al listado
*/
void genInicReport(Arbol aux)
{
   char *nombre, *nomparam;
   int i,cuantos;
   indentacion=0;
   nombre=Identificador_nombre(Report_nom(aux));
   printf("Generando inicio de listado: %s\n",nombre); 
   genera(indentacion,"\n/**************************************************\n");
   genera(indentacion," * Inicio de listado: %-30.30s *\n",nombre);
   genera(indentacion,"***************************************************/\n");
   genera(indentacion,"void _Fn_STARTRPT_%s()\n",nombre);
   genera(indentacion,"{\n");
   indentacion++;
   genera(indentacion,"char SelTmp[8196];\n");
   genera(indentacion,"/* Compruebo si el listado ya estaba inicializado */\n");
   genera(indentacion,"if (_RPT_%s_inic==1)\n",nombre);
   genera(indentacion+1,"_4GLalert(\"El listado %s ya estaba inicializado\");\n",nombre);
   genera(indentacion,"else\n");
   genera(indentacion++,"{\n");
   genera(indentacion,"/* Genero la tabla temporal */\n");
   genera(indentacion,"sprintf(SelTmp,\"create table _rpt%%d_%s(\n",nombre);
   indentacion++;
   cuantos=Variables_longitud(lst_param);
   vars=NULL;
   for (i=1;i<=cuantos;i++)
   {
      nomparam=Identificador_nombre(Id_nom(ListaId_elemento(lst_param,i)));
      genLinCreate(i,nomparam);
   }
   genera(indentacion,"_%d_oid integer);\",getpid());\n");
   indentacion--;
   genera(indentacion,"_4GLexec(_conn,SelTmp);\n");
   genera(indentacion,"if (status!=ok)\n");
   genera(indentacion+1,"_4GLerror(\"No se puede crear tabla temporal para el listado %s\n%%s\",",nombre);
   genera(indentacion+2,"_4GLsqlErrorStr(_conn));\n",nombre);
   genera(indentacion,"/*** Pongo a 1 la var. que indica que el listado esta inicializado */\n");
   genera(indentacion,"_RPT_%s_inic=1;\n",nombre);
   indentacion--;
   genera(indentacion--,"}\n");
   genera(indentacion,"}\n");
}

/* Funcion que genera la funcion a la que llama un 'output to report' */
void genOutputReport(Arbol rpt)
{
   char *nombre;
   char *nomcampo;
   int i,cuantos;
   
   indentacion=0;
   nombre=Identificador_nombre(Report_nom(rpt));
   genera(indentacion,"/** Insercion de datos en un listado **/\n");
   genera(indentacion,"void _Fn_OutputRpt_%s()\n",nombre);
   genera(indentacion,"{\n");
   indentacion++;
   genera(indentacion,"char SelTmp[8196];\n");
   /* Esta funcion recibe los datos que se envian al listado y los guarda 
      en la tabla temporal */
   /* Genero el 'insert into... '*/
   genera(indentacion,"sprintf(SelTmp,\"insert into _rpt%%d_%s values(\n",nombre);
   indentacion++;
   cuantos=ListaId_longitud(Report_par(rpt));
   for (i=1;i<=cuantos;i++)
   {
      nomcampo=Identificador_nombre(Id_nom(ListaId_elemento(Report_par(rpt),i)));
      genMascaraInsert(nomcampo);
   }
   genera(indentacion,"%%d)\",getpid(),\n");
   
   for (i=1;i<=cuantos;i++)
   {
      nomcampo=Identificador_nombre(Id_nom(ListaId_elemento(Report_par(rpt),i)));
      genDatoInsert(nomcampo);
   }
   genera(indentacion,"0);\n");
   indentacion--;
   genera(indentacion,"_4GLexec(_conn,SelTmp);\n");
   genera(indentacion,"if (status!=ok)\n");
   genera(indentacion+1,"_4GLerror(\"No se pudo insertar dato para el listado %s\n%%s\",PQerrorMessage(_conn));\n",nombre);
   indentacion--;
   genera(indentacion,"}\n");
}

static void genMascaraInsert(char *nomparam)
{
   Arbol reg,campo;
   int i,cuantos;
   char nomcampo[256];
   switch(tipo_var(nomparam))
   {
      case TIPO_INT:
         genera(indentacion,"%%d,\n");
         break;
      case TIPO_STR:
      case TIPO_DATE:
      case TIPO_TIME:
      case TIPO_DATETIME:
      case TIPO_INTERVAL:
         genera(indentacion,"'%%s',\n");
         break;
      case TIPO_FLOAT:
         genera(indentacion,"%%f,\n");
         break;
      case TIPO_RECORD:
         reg=Existe_Var(nomparam);
         cuantos=Variables_longitud(Tipo_cam(Variable_tip(reg)));
         for (i=1;i<=cuantos;i++)
         {
            campo=Variables_elemento(Tipo_cam(Variable_tip(reg)),i);
            if (Constructor(campo))
            {
            	sprintf(nomcampo,"%s.%s",nomparam,Identificador_nombre(Variable_nom(campo)));
               genMascaraInsert(nomcampo);
            }
         }
         break;
      default:
         error("Tipo %d no reconocido.");
   }   
}

static void genDatoInsert(char *nomparam)
{
   Arbol reg,campo;
   int i,cuantos;
   char nomcampo[256];
   switch(tipo_var(nomparam))
   {
      case TIPO_INT:
         genera(indentacion,"pop_int(pila_exp),\n");
         break;
      case TIPO_STR:
      case TIPO_DATE:
      case TIPO_TIME:
      case TIPO_DATETIME:
      case TIPO_INTERVAL:
         genera(indentacion,"pop_str(pila_exp),\n");
         break;
      case TIPO_FLOAT:
         genera(indentacion,"pop_float(pila_exp),\n");
         break;
      case TIPO_RECORD:
         reg=Existe_Var(nomparam);
         cuantos=Variables_longitud(Tipo_cam(Variable_tip(reg)));
         for (i=1;i<=cuantos;i++)
         {
            campo=Variables_elemento(Tipo_cam(Variable_tip(reg)),i);
            if (Constructor(campo))
            {
            	sprintf(nomcampo,"%s.%s",nomparam,Identificador_nombre(Variable_nom(campo)));
               genDatoInsert(nomcampo);
            }
         }
         break;
      default:
         error("Tipo %d no reconocido.");
   }   
}


void genReport(Arbol rpt)
{
   char *nombre;
   int i,cuantas;
   Arbol aux;
   char *salida="";
   char tiposalida=' ';
   char *opcion;
   int lineas=66,cols=80; /* Valores por defecto */

   lst_param=Report_par(rpt);
   lst_locales=Report_var(rpt);
   
   indentacion=0;
   nombre=Identificador_nombre(Report_nom(rpt));
   printf("Generando Listado: %s\n",nombre);
   if (vars!=NULL)
      Borra(vars);
   vars=NULL;
   genInicReport(rpt); /* Aqui me crea la lista 'vars' */
   genOutputReport(rpt);
   genera(indentacion,"\n/*****************************************************\n");   
   genera(indentacion," * Listado: %-30.30s           *\n",nombre);
   genera(indentacion,"/*****************************************************/\n");   
   genera(indentacion,"void _Fn_RPT_%s()\n",nombre);
   genera(indentacion,"{\n");
   indentacion=1;

   /* Primero genero las vars locales */
   if (Constructor(Report_var(rpt)))
      genVariables(Report_var(rpt),"");
      
   /* Leo las opciones del listado (salida, lineas, columnas... */
   cuantas=RptOutput_longitud(Report_out(rpt));
   genera(indentacion,"/*--- %d opciones ---*/\n",cuantas);
   for (i=1;i<=cuantas;i++)
   {
      aux=RptOutput_elemento(Report_out(rpt),i);
      opcion=Identificador_nombre(Id_nom(aux));
      if (opcion[0]=='F') /* La salida es a un fichero. Aqui tengo el nombre */
      {  
         tiposalida='F';
	      salida=opcion+1;
	   }
	   else if (opcion[0]=='P') /* Salida a un proceso */
	   {
	      tiposalida='P';
	      salida=opcion+1;
	   }
      else if (opcion[0]=='X') /* ancho de pagina */
      {
      	cols=atol(opcion+1);	
      }
      else if (opcion[0]=='Y') /* Lineas por pagina */
      {
      	lineas=atol(opcion+1);
      }
   }

   /* Las vars. temporales que necesito para el report... */
   genera(indentacion,"/* vars temporales */\n");
   genera(indentacion,"char _Query[8192];\n");
   genera(indentacion,"_CURSOR _Cursor;\n");
   genera(indentacion,"int _4GLcols=%d;\n",cols);
   genera(indentacion,"int _4GLlineas=%d;\n",lineas);
   genera(indentacion,"char _4GLlinea[%d]; /* Var. donde monto la linea que se va a imprimir */\n",cols+1);
   genera(indentacion,"int _4GLfph=1; /* flag que indica si hay que hacer el first page header */\n");
   genera(indentacion,"FILE *_4GLsalida;\n\n");
   
   /* Las vars. para los 'before/after group' */
   genVarBeforeGrp(FormatoRpt_bg(Report_fmt(rpt)));
   genera(indentacion,"\n");   
   
   /* Inicializo las vars internas */
   genera(indentacion,"/* Valores iniciales de las vars */\n");
   genera(indentacion,"pageno=0;\n");
   genera(indentacion,"lineno=%d;\n",lineas);
   
   /* Abro el fichero de salida */
   genera(indentacion,"/* Abro el fichero/proceso de salida... */\n");
   if (tiposalida=='F')
      genera(indentacion,"_4GLsalida=fopen(\"%s\",\"w\");\n",salida);
   else if (tiposalida=='P')
      genera(indentacion,"_4GLsalida=popen(\"%s\",\"w\");\n",salida);
   else 
      yyerror("No se ha especificado salida para el listado %s.",nombre);
      
   genera(indentacion,"if (!_4GLsalida)\n");
   genera(indentacion+1,"_4GLerror(\"No se pudo abrir la salida del listado.\");\n");
   
   /* Genero la Query */
   genera(indentacion,"/* leo la tabla temporal */\n");
   genera(indentacion,"sprintf(_Query,\"select * from _rpt%%d_%s;\",getpid());\n",nombre);
   genera(indentacion,"(void)_4GLcursor(_conn,_Query,&(_Cursor));\n\n");
   
   /* Genero el bucle que lee todos los registros... */
   genera(indentacion,"/* recorro los registros... */\n");
   genera(indentacion,"for(_Cursor.actual=0;_Cursor.actual<_Cursor.ntuples;_Cursor.actual++)\n");
   genera(indentacion++,"{\n");
   genera(indentacion,"/* cargo el contenido de cada uno... */\n");
   cuantas=ListaId_longitud(vars);
   for (i=0;i<cuantas;i++)
   {
      cadena var;
      aux=ListaId_elemento(vars,i+1);
      if (!Constructor(aux))
         break;
      strcpy(var,Identificador_nombre(Id_nom(aux)));
      switch (tipo_var(var))
      {
         case TIPO_INT:
             genera(indentacion,"%s=atol(PQgetvalue(_Cursor.res,_Cursor.actual,%d));\n",
             var,i);
             break;
         case TIPO_FLOAT:
                genera(indentacion,"%s=atof(PQgetvalue(_Cursor.res,_Cursor.actual,%d));\n",
                var,i);
             break;
          case TIPO_STR:
             genera(indentacion,"_4GLstrncpy(%s,PQgetvalue(_Cursor.res,_Cursor.actual,%d),%d);\n",
                var,i,tam_var(var));
             break;
          case TIPO_DATE:
             genera(indentacion,"%s=_4GLstr2date(PQgetvalue(_Cursor.res,_Cursor.actual,%d));\n",
                var,i);
             break;
          case TIPO_TIME:
             genera(indentacion,"%s=_4GLstr2time(PQgetvalue(_Cursor.res,_Cursor.actual,%d));\n",
                var,i);
             break;
          case TIPO_DATETIME:
             genera(indentacion,"%s=_4GLstr2datetime(PQgetvalue(_Cursor.res,_Cursor.actual,%d));\n",
                var,i);
             break;
          case TIPO_INTERVAL:
             genera(indentacion,"%s=_4GLDBstr2interval(PQgetvalue(_Cursor.res,_Cursor.actual,%d));\n",
                var,i);
             break;
       }
    }
   /* Genero el 'first page header' */
   if (Constructor(FormatoRpt_fph(Report_fmt(rpt))))
   {
      genera(indentacion,"\n");
      genera(indentacion,"/* first page header... */\n");
      genera(indentacion,"if (_4GLfph)\n");
      genera(indentacion++,"{\n");
      genera(indentacion,"pageno++;\n");
      genera(indentacion,"_4GLfph=0;\n");
      genera(indentacion,"lineno=0;\n");
      genSentencias(FormatoRpt_fph(Report_fmt(rpt)));
      genera(--indentacion,"} /* Fin del 'first page header' */\n\n");
   }

   if (Constructor(FormatoRpt_ph(Report_fmt(rpt))))
   {
      /* Genero el 'page header' */
      genera(indentacion,"/* page header... */\n");
      genera(indentacion,"if (lineno>=%d)\n",lineas);
      genera(indentacion++,"{\n");
      genera(indentacion,"pageno++;lineno=0;\n");
      genSentencias(FormatoRpt_ph(Report_fmt(rpt)));
      genera(--indentacion,"} /* fin del page header */\n\n");
   }
   
   /* Genero los 'before group of... ' */
   genBeforeGrp(FormatoRpt_bg(Report_fmt(rpt)));
   /* Genero el 'on every row... ' */
   genera(indentacion,"/* on every row... */\n");
   genera(indentacion++,"{\n");
   genSentencias(FormatoRpt_ev(Report_fmt(rpt)));
   genera(--indentacion,"} /* Fin del 'on every row' */\n\n");

   genera(--indentacion,"}\n\n");

   /* Genero el 'on last row... */
   if (Constructor(FormatoRpt_lr(Report_fmt(rpt))))
   {
      genera(indentacion,"/* on last row... */\n");
      genera(indentacion++,"{\n");
      genSentencias(FormatoRpt_lr(Report_fmt(rpt)));
      genera(--indentacion,"}\n\n");
   }
   genera(indentacion,"fclose(_4GLsalida);\n");
   genera(indentacion,"/* Y al final, borro la tabla temporal */\n");
   genera(indentacion,"sprintf(_Query,\"drop table _rpt%%d_%s;\",getpid());\n",nombre);
   genera(indentacion,"_4GLexec(_conn,_Query);\n");
   genera(indentacion,"if (status!=ok)\n");
   genera(indentacion,"_4GLerror(\"No se puede borrar la tabla temporal _rpt%%d_%s\n%%s\",getpid(),PQerrorMessage(_conn));\n",nombre);
   genera(indentacion,"_RPT_%s_inic=0;\n",nombre);  
   indentacion=0;
   genera(indentacion,"} /* Fin del listado %s */\n\n",Identificador_nombre(Report_nom(rpt)));
}

void genVarBeforeGrp(Arbol lst)
{
   int i, cuantosGr, j, cuantasVar;
   Arbol Gr;
   Arbol Var;
   Arbol aux;
   cadena nom;
   cuantosGr=RptGrupos_longitud(lst);
   /* Recorro los 'before group' */
   for (i=1;i<=cuantosGr;i++)
   {
      genera(indentacion,"/**** Vars para el Before Group nº %d ***/\n",i);
      Gr=RptGrupos_elemento(lst,i);
      cuantasVar=ListaId_longitud(RptGrupo_ids(Gr));
      /* Recorro las variables de este grupo */
      for (j=1;j<=cuantasVar;j++)
      {
         sprintf(nom,"_4RptBg%d_%d",i,j);
         Var=Existe_Var(Identificador_nombre(Id_nom(ListaId_elemento(RptGrupo_ids(Gr),j))));
         aux=Variable(Asigna_nombre(nom),Variable_tip(Var));
         /* Creo variables temporales del mismo tipo */
         genVariable(aux,"");
         lst_locales=Variables(lst_locales,aux);
      }
   }
}

void genBeforeGrp(Arbol lst)
{
   int i, cuantosGr, j, cuantasVar;
   Arbol Gr;
   Arbol aux1,aux2,Aux;
   cadena nom;
   cuantosGr=RptGrupos_longitud(lst);
   /* Recorro los 'before group' */
   for (i=1;i<=cuantosGr;i++)
   {
      genera(indentacion,"/**** Before Group nº %d ***/\n",i);
      indentacion++;
      Gr=RptGrupos_elemento(lst,i);
      cuantasVar=ListaId_longitud(RptGrupo_ids(Gr));
      /* Recorro las variables de este grupo */
      for (j=1;j<=cuantasVar;j++)
      {
         sprintf(nom,"_4RptBg%d_%d",i,j);
         aux1=Id(Asigna_nombre(nom));
         aux2=ListaId_elemento(RptGrupo_ids(Gr),j);
         genExpresion(aux1);
         genExpresion(aux2);
         genera(indentacion,"op_cmp(pila_exp,0);\n");
      }
      while (j>2)
      {
      	genera(indentacion,"op_and(pila_exp);\n");
        j--;
      }
      genera(indentacion,"/* Si ha cambiado el grupo... */\n");
      genera(indentacion,"if (!pop_int(pila_exp))\n");
      genera(indentacion++,"{\n");
      genSentencias(RptGrupo_cod(Gr));
      genera(indentacion,"/* asigno a la vars. temporales el nuevo valor del grupo */\n");
      for (j=1;j<=cuantasVar;j++)
      {
         sprintf(nom,"_4RptBg%d_%d",i,j);
         aux1=ListaId(NULL,Id(Asigna_nombre(nom)));
         aux2=Expresiones(NULL,ListaId_elemento(RptGrupo_ids(Gr),j));
         Aux=Asignacion(aux1,aux2);
         genAsignacion(Aux);
      }
      genera(--indentacion,"} /* Fin del 'before group' nº %d\n\n",i);
      indentacion--;
   }
}


void genPrint(Arbol exp)
{
   genExpresion(PrintReport_exp(exp));
   genera(indentacion,"_4GLstrncpy(_4GLlinea,pop_str(pila_exp),_4GLcols); /* Leo la expresion sobre la var. linea */\n");
   genera(indentacion,"fprintf(_4GLsalida,\"%%s\\n\",_4GLlinea); /* Imprimo la var. linea */\n");
   genera(indentacion,"lineno++;\n");
}
