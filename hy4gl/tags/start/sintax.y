%{
/*****************************************************************
**
**      SINTAX.Y YACC para el hy4GL
**
******************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include <string.h>

#include "global.h"
#include "asa.h"
#include "prototipos.h"

extern Arbol raiz, lst_funciones,lst_globales;
extern Arbol lst_param,lst_locales,db;
extern int numerrores;
extern char *yyfilename;
int en_select=0;
int en_report=0;
extern int numMenu,numBrowse;
int in_menu=0;
%}

%union {
       cadena string;
       Arbol arbol;
       double valor;
}

%token TK_START TK_REPORT TK_FINISH TK_OUTPUT TK_FORMAT TK_BEFORE TK_AFTER TK_OF
%token TK_FIRST TK_PAGE TK_HEADER TK_LAST TK_EVERY TK_FOOTER TK_ROW TK_PIPE
%token TK_PRINT

%token TK_DB TK_DECLARE TK_LOCAL TK_CURSOR TK_FOREACH TK_INTO 
%token TK_FETCH TK_PREVIOUS TK_NEXT  TK_EXEC
%token TK_SELECT TK_AS TK_FROM TK_WHERE TK_ORDER TK_ASCENDING TK_DESCENDING TK_GROUP TK_BY 
%token TK_INSERT TK_VALUES TK_DELETE TK_UPDATE
%token TK_WHENEVER
%token TK_CREATE TK_DROP 

%token TK_BEGIN TK_TRANSACTION TK_COMMIT TK_ABORT
%token TK_OR TK_AND TK_IGUAL TK_DISTINTO TK_MENORIGUAL TK_MAYORIGUAL
%token TK_ADDADD TK_SUBSUB TK_DELAY TK_CURRENT TK_RECORD TK_LIKE
%token TK_PROMPT TK_FOR TK_CHAR TK_CLOSE TK_DEFINE TK_END TK_LET 
%token TK_CLIPPED TK_USING

%token TK_IF TK_THEN TK_ELSE TK_WHILE TK_CONTINUE 

%token TK_FUNCTION TK_MAIN TK_RETURN TK_CALL TK_RETURNING

%token TK_MENU TK_EXIT TK_COMMAND TK_HORIZ TK_VERT TK_CUAD
%token TK_ON TK_KEY

%token TK_BROWSE 

%token TK_WINDOW TK_OPEN TK_CLEAR TK_MOVE TK_TO TK_AT TK_WITH 
%token TK_COLS TK_ROWS TK_TITLE
%token TK_ATTR TK_BORDER TK_OVER TK_BRIGHT TK_DOBLE TK_DISPLAY 

%token TK_FORM TK_INPUT TK_LABEL TK_BUTTON TK_RADIO TK_LABEL TK_CHECK 
%token TK_VALIDATE TK_FIELD

%token TK_EXTERN
%token TK_FUENTE_C

%left TK_OR
%left TK_AND
%left '<' '>' TK_IGUAL TK_DISTINTO TK_MENORIGUAL TK_MAYORIGUAL
%left '+' '-'
%left '*' '/'
%right '^'
%left '[' ']'
%left TK_CLIPPED TK_USING
%nonassoc UMINUS '!'


%type <arbol> fich
%type <arbol> fichero

%type <arbol> funciones
%type <arbol> funcion
%type <arbol> acciones
%type <arbol> declaraciones
%type <arbol> declaracion
%type <arbol> tipo
%type <arbol> campos
%type <arbol> campo

%type <arbol> sentencias
%type <arbol> sentencia
%type <arbol> exit_program

%type <arbol> fuente_c
%type <arbol> sql
%type <arbol> database
%type <arbol> declare
%type <valor> decl_local
%type <arbol> open_cursor
%type <arbol> fetch_cursor
%type <arbol> fetch_dir
%type <arbol> close_cursor
%type <arbol> exec_sql
%type <arbol> select
%type <arbol> lst_campos
%type <arbol> campo_tabla
%type <arbol> lst_tablas
%type <arbol> into
%type <arbol> where
%type <arbol> orden
%type <arbol> lst_campos_orderby campo_orderby
%type <arbol> insert
%type <arbol> update 
%type <arbol> update_campos update_campo
%type <arbol> delete
%type <arbol> transacc_begin
%type <arbol> transacc_commit
%type <arbol> transacc_abort

%type <arbol> whenever

%type <arbol> sent_report
%type <arbol> start_r
%type <arbol> output_r
%type <arbol> finish_r
%type <arbol> rpt_print

%type <arbol> report
%type <arbol> rpt_salida
%type <arbol> rpt_formato
%type <arbol> rpt_formato_pg
%type <arbol> rpt_item_fmt
%type <arbol> rpt_first_pg_hd
%type <arbol> rpt_pg_hd
%type <arbol> rpt_before_gr
%type <arbol> rpt_item_before_gr
%type <arbol> rpt_every
%type <arbol> rpt_after_gr
%type <arbol> rpt_item_after_gr
%type <arbol> rpt_pg_ft
%type <arbol> rpt_last_rw

%type <arbol> sent_form
%type <arbol> form_create
%type <arbol> form_display
%type <arbol> form_def
%type <arbol> form_elementos
%type <arbol> form_elemento
%type <arbol> form_attribs
%type <arbol> form_dispByName
%type <arbol> form_inputByName
%type <arbol> form_onkeys
%type <arbol> form_onkey
%type <arbol> form_afterfields
%type <arbol> form_afterfield
%type <arbol> form_exit
%type <arbol> form_validate
%type <arbol> form_current

%type <arbol> exitmenu
%type <arbol> menu
%type <arbol> menuops
%type <arbol> menuop
%type <arbol> menuattr
%type <valor> menuformat

%type <arbol> sent_browse
%type <arbol> browse_exit
%type <arbol> browse
%type <arbol> browse_donde
%type <arbol> browse_titulo
%type <arbol> browseops
%type <arbol> browseop
%type <arbol> browsevacio

%type <arbol> opventana
%type <arbol> atributos_vent
%type <arbol> atributo_vent
%type <valor> color
%type <arbol> tit_ventana

%type <arbol> funcion
%type <arbol> retorno

%type <arbol> escribir
%type <arbol> lista_expr_disp
%type <arbol> expr_disp
%type <arbol> lectura lectura_onkeys lectura_onkey lectura_exit

%type <arbol> asignacion
%type <arbol> llamada

%type <arbol> bloquecontrol
%type <arbol> blqif
%type <arbol> blqwhile
%type <arbol> cont_while
%type <arbol> exit_while
%type <arbol> blqfor
%type <arbol> cont_for
%type <arbol> exit_for

%type <arbol> foreach
%type <arbol> cont_foreach
%type <arbol> exit_foreach


%type <arbol> listaexpresiones
%type <arbol> expresion
%type <arbol> binaria
%type <arbol> unaria

%type <arbol> lst_identif
%type <arbol> identif

%token <string> TK_ID
%token <string> TK_CADENA
%token <valor> TK_CONS
%token <valor> TK_REAL
%token <string> TK_FUENTE_C

%start fich

%%

fich: fichero {$$=$1;}
	| database fichero {$$=$2; db=$1;}
	;

fichero:  declaraciones {lst_globales=Une(lst_globales,$1);} funciones 
					{$$=raiz=Fichero(lst_globales,$3);}
    | funciones {$$=raiz=Fichero(lst_globales,$1);}
    ;

funciones: funciones funcion {$$=lst_funciones=Funciones($1,$2);}
	| funcion {$$=lst_funciones=Funciones(NULL,$1);}
   ;

funcion: TK_FUNCTION TK_ID '(' ')' acciones TK_END TK_FUNCTION
			{
				$$=Funcion(Asigna_nombre($2),NULL,$5,
					Tipo(Asigna_nombre("VOID"),Asigna_valor(0),NULL));
				lst_param=NULL;
				lst_locales=NULL;
			}
	|  TK_MAIN acciones TK_END TK_MAIN
			{
				$$=Funcion(Asigna_nombre("main"),NULL,$2,
					Tipo(Asigna_nombre("VOID"),Asigna_valor(0),NULL));
				lst_param=NULL;
				lst_locales=NULL;
			}
	| TK_FUNCTION TK_ID '(' {en_select=1;} 
			lst_identif {en_select=0;lst_param=$5;} ')' acciones 
		TK_END TK_FUNCTION
		{
				$$=Funcion(Asigna_nombre($2),$5,$8,
					Tipo(Asigna_nombre("VOID"),Asigna_valor(0),NULL));
				lst_param=NULL;
				lst_locales=NULL;
		}
	| TK_EXTERN TK_ID '(' ')' tipo
		{
			$$=Funcion(Asigna_nombre($2),NULL,NULL,$5);
		}
	| report {$$=$1;}
   | form_def {$$=$1;}
	;

acciones: declaraciones {lst_locales=$1;} sentencias {$$=Acciones(lst_locales,$3);}
    |  sentencias {$$=Acciones(lst_locales,$1);}
    ;

declaraciones:  declaracion {$$=$1;}
	 |  declaraciones declaracion {$$=Une($1,$2);}
    ;

declaracion: TK_DEFINE {en_select=1;} lst_identif {en_select=0;} tipo 
	{
		Arbol una,todas;
		int i;
		char *nomvar;
		todas=NULL;
		for (i=0;i<ListaId_longitud($3);i++)
		{
			nomvar=Identificador_nombre(Id_nom(ListaId_elemento($3,i+1)));
			if (Busca_Var(nomvar,lst_locales))
         {
				yyerror("Variable %s ya declarada",nomvar);
         }
			una=Variable(Asigna_nombre(nomvar),$5);
			todas=Variables(todas,una);
		}
		$$=todas;
	}
   ;

tipo: TK_ID 
    {
      if (!strcasecmp($1,"integer"))
         $$=Tipo(Asigna_nombre("int"),Asigna_valor(0),NULL);
      else if (!strcasecmp($1,"smallint"))
         $$=Tipo(Asigna_nombre("int"),Asigna_valor(0),NULL);
      else if (!strcasecmp($1,"float") || !strcasecmp($1,"decimal"))
         $$=Tipo(Asigna_nombre("float"),Asigna_valor(0),NULL);
      else if (!strcasecmp($1,"date"))
         $$=Tipo(Asigna_nombre("date"),Asigna_valor(1),NULL);
      else if (!strcasecmp($1,"time"))
         $$=Tipo(Asigna_nombre("time"),Asigna_valor(1),NULL);
      else if (!strcasecmp($1,"datetime"))
         $$=Tipo(Asigna_nombre("datetime"),Asigna_valor(1),NULL);
      else if (!strcasecmp($1,"interval"))
         $$=Tipo(Asigna_nombre("interval"),Asigna_valor(1),NULL);
      else 
         yyerror ("Tipo %s no reconocido.",$1);
    }
    | TK_CHAR
       {$$=Tipo(Asigna_nombre("char"),Asigna_valor(1),NULL);}
	 | TK_CHAR '(' TK_CONS ')' 
       {
       	$$=Tipo(Asigna_nombre("char"),Asigna_valor($3),NULL);
       }
	 | TK_RECORD campos TK_END TK_RECORD {$$=Tipo(Asigna_nombre("record"),Asigna_valor(0),$2);}
	 | TK_LIKE TK_ID '.' TK_ID
			{$$=tipo_campo_bd($2,$4);}
	 | TK_RECORD TK_LIKE TK_ID '.' '*'
			{$$=tipo_campo_bd($3,NULL);}
    ;

campos: campos campo
		{$$=Variables($1,$2);}
	| campo
		{$$=Variables(NULL,$1);}
	;
campo: TK_ID tipo
	{ $$=Variable(Asigna_nombre($1),$2);}
	;

sentencias: error {$$=NULL;}
	 | sentencia {$$=Sentencias(NULL,$1);}
    | sentencias sentencia {$$=Sentencias($1,$2);}
    ;

sentencia: fuente_c {$$=$1;}
    | exit_program {$$=$1;}
    | asignacion {$$=$1;}
    | llamada {$$=$1;}
    | retorno {$$=$1;}
    | lectura {$$=$1;}
    | lectura_exit {$$=$1;}
    | escribir {$$=$1;}
    | opventana {$$=$1;}
    | bloquecontrol {$$=$1;}
    | TK_DELAY expresion {$$=Delay($2);}
    | sql {$$=$1;}
    | whenever {$$=$1;}
    | menu {$$=$1;}
    | exitmenu {$$=$1;}
    | sent_browse {$$=$1;}
    | sent_report{$$=$1;}
    | sent_form{$$=$1;}
    ;

exit_program: TK_EXIT TK_ID
   {
      if (strcasecmp($2,"program"))
         yyerror("syntax error(%s)",$2);
      $$=ExitProgram();
   }
   ;
fuente_c: TK_FUENTE_C {$$=FuenteC(NULL,Asigna_nombre($1));}
   | fuente_c TK_FUENTE_C {$$=FuenteC($1,Asigna_nombre($2));}
   ;
	
opventana: TK_OPEN TK_WINDOW TK_ID  
				TK_AT expresion ',' expresion 
				TK_WITH expresion TK_ROWS ',' expresion TK_COLS
				tit_ventana
				{
					Arbol aux;
					cadena nombre;
					/* Creo una nueva var. local con el nombre de la ventana */
					sprintf(nombre,"_W%s",$3);
               if (!Existe_Var(nombre))
               {
               	aux=Variable(Asigna_nombre(nombre),Tipo(Asigna_nombre("WINDOW"),Asigna_valor(0),NULL));
                  lst_locales=Variables(lst_locales,aux);
               }
					$$=AbVentana(Asigna_nombre(nombre),$5,$7,$9,$12,NULL,$14);
				}
   |  TK_OPEN TK_WINDOW TK_ID  
				TK_AT expresion ',' expresion 
				TK_WITH expresion TK_ROWS ',' expresion TK_COLS
				TK_ATTR atributos_vent
				tit_ventana
				{
					Arbol aux;
					cadena nombre;
					/* Creo una nueva var. con el nombre de la ventana */
					sprintf(nombre,"_W%s",$3);
               if (!Existe_Var(nombre))
               {
               	aux=Variable(Asigna_nombre(nombre),Tipo(Asigna_nombre("WINDOW"),Asigna_valor(0),NULL));
                  lst_locales=Variables(lst_locales,aux);
               }
					$$=AbVentana(Asigna_nombre(nombre),$5,$7,$9,$12,$15,$16);
				}
	|	TK_CLOSE TK_WINDOW TK_ID 
				{
               cadena nombre;
               sprintf(nombre,"_W%s",$3);
					$$=CieVentana(Asigna_nombre(nombre));
				}
	|  TK_MOVE TK_WINDOW TK_ID TK_TO expresion ',' expresion 
				{
               cadena nombre;
               sprintf(nombre,"_W%s",$3);
					$$=MovVentana(Asigna_nombre(nombre),$5,$7);
				}
	| TK_CURRENT TK_WINDOW TK_ID
				{
               cadena nombre;
               sprintf(nombre,"_W%s",$3);
					$$=CurVentana(Asigna_nombre(nombre));
				}
   | TK_CLEAR TK_WINDOW
         	{
               $$=ClearWindow();
            }
   ;

tit_ventana: /* vacio */ {$$=NULL;}
	| TK_TITLE expresion {$$=$2;}
	;

atributos_vent: atributos_vent ',' atributo_vent {$$=AttsVentana($1,$3);}
   | atributo_vent {$$=AttsVentana(NULL,$1);}
	| '(' atributos_vent ')' {$$=$2;}
   ;

atributo_vent: color {$$=AtVentana(Asigna_nombre("COLOR"),Asigna_valor($1*8+1));}
	| color TK_OVER color {$$=AtVentana(Asigna_nombre("COLOR"),Asigna_valor($1*8+$3+1));}
	| TK_BORDER {$$=AtVentana(Asigna_nombre("BORDER"),Asigna_valor(1));} 
	| TK_DOBLE TK_BORDER {$$=AtVentana(Asigna_nombre("BORDER"),Asigna_valor(2));} 
	| TK_BRIGHT {$$=AtVentana(Asigna_nombre("BRIGHT"),Asigna_valor(1));} 
	;

color: TK_ID
   {
      if (!strncasecmp($1,"black",5))
         $$=COLOR_BLACK;
      else if (!strncasecmp($1,"blue",4))
         $$=COLOR_BLUE;
      else if (!strncasecmp($1,"red",3))
         $$=COLOR_RED;
      else if (!strncasecmp($1,"white",5))
         $$=COLOR_WHITE;
      else if (!strncasecmp($1,"cyan",4))
         $$=COLOR_CYAN;
      else if (!strncasecmp($1,"yellow",6))
         $$=COLOR_YELLOW;
      else if (!strncasecmp($1,"green",5))
         $$=COLOR_GREEN;
      else if (!strncasecmp($1,"magenta",7))
         $$=COLOR_MAGENTA;
      else
      {
         yyerror("No se reconoce el nombre del color (%s)",$1);
         $$=COLOR_BLACK;
      }
   };

llamada: TK_ID '(' listaexpresiones ')' 
			{
/*--------- Este bloque lo quito. Permito llamar a funciones 
 *--------- que se encuentran en otros fuentes.

				if (!en_select && !Busca_Fun($1))
				{
				  yyerror("Funcion %s no declarada\n",$1);
				}
*/
			   $$=Llamada(Asigna_nombre($1), $3);
			}

    | TK_ID '(' ')' 
			{
/*-----
				 if (!en_select && !Busca_Fun($1))
				 {
					 yyerror("Funcion %s no declarada\n",$1);
					 $$=NULL;
				 }
				 else
*/
		 	    $$=Llamada(Asigna_nombre($1),NULL);
			}
    | TK_CALL llamada {$$=$2;}
    ;

escribir: TK_DISPLAY lista_expr_disp {$$=Escribir($2);}
    ;

lista_expr_disp: expr_disp {$$=Displays(NULL,$1);}
	| lista_expr_disp ',' expr_disp{$$=Displays($1,$3);}
	;

expr_disp: listaexpresiones {$$=Display(NULL,NULL,$1,NULL);}
	| listaexpresiones TK_AT expresion ',' expresion {$$=Display($3,$5,$1,NULL);}
	| listaexpresiones TK_ATTR atributos_vent 
		{
			$$=Display(NULL,NULL,$1,$3);
		}
	| listaexpresiones TK_AT expresion ',' expresion TK_ATTR atributos_vent 
		{
			$$=Display($3,$5,$1,$7);
		}
	;

lectura: TK_PROMPT TK_FOR identif {$$=Leer(NULL,$3,Asigna_valor(0),NULL);}
    |    TK_PROMPT expresion TK_FOR identif 
			{
				$$=Leer($2,$4,Asigna_valor(0),NULL);
			}
	 |    TK_PROMPT expresion TK_FOR TK_CHAR identif 
			{
				$$=Leer($2,$5,Asigna_valor(1),NULL);
			}
    |    TK_PROMPT expresion TK_FOR TK_CHAR identif
         	lectura_onkeys
         TK_END TK_PROMPT
         {
            if (tipo_var(Identificador_nombre(Id_nom($5)))!=TIPO_STR)
            {
            	yyerror("La variable %s debe ser de tipo CHAR",Identificador_nombre(Id_nom($5)));
            }
         	$$=Leer($2,$5,Asigna_valor(1),$6);
         }
    ;

lectura_onkeys: lectura_onkey {$$=LeerKeys(NULL,$1);}
   | lectura_onkeys lectura_onkey {$$=LeerKeys($1,$2);}
   ;

lectura_onkey: TK_ON TK_KEY '(' TK_ID ')' sentencias
		{$$=LeerKey(Asigna_nombre($4),$6);}
	|
		TK_ON TK_KEY '(' TK_CADENA ')' sentencias
		{
			cadena buffer;
			if (strlen($4)>1)
				yyerror("'%s' no es un caracter de teclado.",$4);
			else
			{ 
				sprintf(buffer,"'%s'",$4);
				$$=LeerKey(Asigna_nombre(buffer),$6);
			}
		}
	|
		TK_ON TK_KEY '(' TK_CONS ')' sentencias
		{
			cadena buffer;
			sprintf(buffer,"%d",(int)$4);
			$$=LeerKey(Asigna_nombre(buffer),$6);
		}
	; 

lectura_exit: TK_EXIT TK_PROMPT
   {$$=LeerExit();}
    ;
retorno: TK_RETURN listaexpresiones {$$=Retorno($2);}
	 | TK_RETURN 							{$$=Retorno(NULL);}
    ;

asignacion: TK_LET lst_identif TK_IGUAL listaexpresiones {$$=Asignacion($2,$4);}
   | llamada TK_RETURNING lst_identif {$$=Asignacion($3,Expresiones(NULL,$1));}
   ;

listaexpresiones: expresion {$$=Expresiones(NULL,$1);}
    | listaexpresiones ',' expresion {$$=Expresiones($1,$3);}
	 | '(' listaexpresiones ')' {$$=$2;}
	 | TK_ID '.' '*' 
			{
				$$=Campos_reg($1);
			}
	 | listaexpresiones ',' TK_ID '.' '*'
		{
			$$=Une($1,Campos_reg($3));
		}
    ;

expresion: identif {$$=$1;}
    | expresion '[' expresion ']' {$$=Subcadena($1,$3,$3);}
    | expresion '[' expresion ',' expresion ']' {$$=Subcadena($1,$3,$5);}
    | TK_REAL { $$=Const(Asigna_valor($1),Asigna_nombre("REAL")); }
    | '+' TK_REAL { $$=Const(Asigna_valor($2),Asigna_nombre("REAL")); }
    | TK_CONS {
                $$=Const(Asigna_valor((long) $1),Asigna_nombre("ENTERO"));
              }
    | '+' TK_CONS {
                $$=Const(Asigna_valor((long) $2),Asigna_nombre("ENTERO"));
              }
    | TK_CADENA {$$=Cadena(Asigna_nombre($1));}
    | binaria {$$=$1;}
    | unaria {$$=$1;}
    | '(' expresion ')' {$$=$2;}
    | llamada {$$=$1;}
    | expresion TK_USING TK_CADENA {$$=Using($1,Asigna_nombre($3));}
    | expresion TK_CLIPPED {$$=Clipped($1);}
    ;

lst_identif: lst_identif ',' identif
			{$$=ListaId($1,$3);}
    |  identif  {$$=ListaId(NULL,$1);}
	 |  lst_identif ',' TK_ID '.' '*'
			{
				Arbol aux;
				$$=NULL;
				/* Busco el registro */
            aux=Existe_Var($3);
				if (!aux)
					yyerror("No existe el registro (%s)",$3);
				else
				{
					$$=Une($1,Campos_reg($3));
				}
			}
	 |  TK_ID '.' '*'
			{
            Arbol aux;
            /* Busco el registro */
            aux=Existe_Var($1);
            if ((!aux) || (tipo_var($1)!=TIPO_RECORD))
               yyerror ("No se encuentra el registro %s",$1);
            else
               $$=Campos_reg($1);
			}
    ;

identif:  TK_ID {/* Busco la variable, para comprobar que esta declarada */
                  Arbol encontrado;
						encontrado = Existe_Var($1);
						if (!en_select && !encontrado)
						{
							yyerror("Variable no declarada (%s)",$1);
						}
                  else
                  {
                  	if (!en_select && (tipo_var($1)==TIPO_RECORD))
                        yyerror("No puede usar un registro en esta sentencia (%s)",$1);
                  }
						$$=Id(Asigna_nombre($1));
					 }
	| TK_ID '.' TK_ID 
		{ 
			Arbol encontrado;
			$$=NULL;

			if (!en_select)
			{
			   encontrado = Existe_Var($1);
			
			   if (!encontrado || 
			     strcmp(Identificador_nombre(Tipo_tip(Variable_tip(encontrado))),
				      "record"))
			   {
			      yyerror("No existe el registro %s",$1);
			   }
			   else
			   {
			     encontrado=Busca_Var($3,Tipo_cam(Variable_tip(encontrado)));
			     if (!encontrado)
			      yyerror("No existe el campo %s en el registro %s",$3,$1);
			     else
			     {
			      char *nombre;
			      nombre=(char *) malloc(strlen($1)+strlen($3)+5);
			      sprintf(nombre,"%s.%s",$1,$3);
			      $$=Id(Asigna_nombre(nombre));
 					free(nombre);
			     }
			   }
			}
			else	 /* Si estoy en una Select, no compruebo los datos */
			{
			      char *nombre;
			      nombre=(char *) malloc(strlen($1)+strlen($3)+5);
			      sprintf(nombre,"%s.%s",$1,$3);
			      $$=Id(Asigna_nombre(nombre));
			}		
		}
    ;


binaria: expresion '+' expresion {$$=Binaria($1,$3,Suma());}
    | expresion '-' expresion {$$=Binaria($1,$3,Resta());}
    | expresion '*' expresion {$$=Binaria($1,$3,Multiplica());}
    | expresion '/' expresion {$$=Binaria($1,$3,Divide());}
    | expresion TK_AND expresion {$$=Binaria($1,$3,And());}
    | expresion TK_OR expresion {$$=Binaria($1,$3,Or());}
    | expresion '>' expresion {$$=Binaria($1,$3,Mayor());}
    | expresion TK_MAYORIGUAL expresion {$$=Binaria($1,$3,Mayorigual());}
    | expresion TK_MENORIGUAL expresion {$$=Binaria($1,$3,Menorigual());}
    | expresion '<' expresion {$$=Binaria($1,$3,Menor());}
    | expresion TK_DISTINTO expresion {$$=Binaria($1,$3,Distinto());}
    | expresion TK_IGUAL expresion {$$=Binaria($1,$3,Igual());}
    ;

unaria : '-' expresion  %prec UMINUS 
   	{
           /* Si es un numero, entonces solo le cambio el signo */
           if (Es(CONST,$2)) 
           {
              $$=Const(Asigna_valor(Constante_valor(Const_val($2))*(-1)),
                 	Const_tip($2));
           }
           else
              $$=Unaria($2,Menos());
        }
    | '!' expresion  %prec UMINUS {$$=Unaria($2,Negacion());}
    ;

bloquecontrol: blqif {$$=$1;}
    |          blqwhile {$$=$1;}
    |          cont_while {$$=$1;}
    |          exit_while {$$=$1;}
    |          blqfor {$$=$1;}
    |          cont_for {$$=$1;}
    |          exit_for {$$=$1;}
	 |          foreach  {$$=$1;}
    |          cont_foreach {$$=$1;};
    |          exit_foreach {$$=$1;};
    ;


foreach:	TK_FOREACH TK_ID TK_INTO lst_identif sentencias TK_END TK_FOREACH
		{$$=Foreach(Asigna_nombre($2),$4,$5);}
	;
cont_foreach: TK_CONTINUE TK_FOREACH {$$=ContinueForeach();}
   ;
exit_foreach: TK_EXIT TK_FOREACH {$$=ExitForeach();}
   ;

blqif: TK_IF expresion then sentencias TK_END TK_IF {$$=If($2,$4,NULL);}
    |  TK_IF expresion then sentencias TK_ELSE sentencias TK_END TK_IF {$$=If($2,$4,$6);}
    ;

then: 
   | TK_THEN
   ;
   
blqwhile: TK_WHILE expresion sentencias TK_END TK_WHILE {$$=While($2,$3);}
    ;
cont_while: TK_CONTINUE TK_WHILE {$$=ContinueWhile();}
   ;
exit_while: TK_EXIT TK_WHILE {$$=ExitWhile();}
   ;

blqfor: TK_FOR identif TK_IGUAL expresion TK_TO expresion sentencias TK_END TK_FOR
   {
      enum tipos tip;
      if (!Existe_Var(Identificador_nombre(Id_nom($2))))
         yyerror("No existe la variable %s.\n",$2);
      tip=tipo_var(Identificador_nombre(Id_nom($2)));
      if ((tip!=TIPO_INT) && (tip!=TIPO_FLOAT) && (tip!=TIPO_DATE))
         yyerror("La variable de un bucle 'for' debe ser numerica o de tipo fecha.\n");
      $$=For($2,$4,$6,$7);
   }
   ;
cont_for: TK_CONTINUE TK_FOR {$$=ContinueFor();}
   ;
exit_for: TK_EXIT TK_FOR {$$=ExitFor();}
   ;   

/******* Whenever error ******/
whenever: TK_WHENEVER TK_ID TK_CONTINUE
   	{
           if (strcasecmp($2,"error"))
           {
              yyerror("Syntax error (%s)",$2);
           }
           $$=WhenEver(Asigna_nombre("continue"));
        }
   |
      TK_WHENEVER TK_ID TK_ID
   	{
           if (strcasecmp($2,"error"))
           {
              yyerror("Syntax error (%s)",$2);
           }
           if (strcasecmp($3,"stop"))
           {
              yyerror("Syntax error (%s)",$2);
           }
           $$=WhenEver(Asigna_nombre($3));
        }
   | TK_WHENEVER TK_ID llamada
      {
           if (strcasecmp($2,"error"))
           {
              yyerror("Syntax error (%s)",$2);
           }
           $$=WhenEver($3);
      }
   ;
/*********************** Sintaxis de los comandos SQL ******************/

sql: database {$$=$1;}
	 | declare {$$=$1;}
	 | select  {$$=$1;}
	 | insert  {$$=$1;}
	 | delete  {$$=$1;}
         | update  {$$=$1;}
     | transacc_begin {$$=$1;}
     | transacc_commit {$$=$1;}
     | transacc_abort {$$=$1;}
     | open_cursor {$$=$1;}
     | close_cursor {$$=$1;}
     | fetch_cursor {$$=$1;}
     | exec_sql {$$=$1;}
	;

database: TK_DB TK_ID
		{ 
			$$=db=Database(Asigna_nombre($2));
		}
		;

declare: TK_DECLARE TK_ID decl_local TK_CURSOR TK_FOR select
	{
		if (Existe_Var($2))
		{
			yyerror("Error. Variable ya definida (%s)\n",$2);
			$$=NULL;
		}
		else
		{
			$$=Declare(Asigna_nombre($2),Asigna_valor($3),$6,Asigna_valor(1));
			if ($3==1)
				lst_globales=Variables(lst_globales,
					Variable(Asigna_nombre($2),Tipo(Asigna_nombre("LCURSOR"),0,$6)));
			else
				lst_globales=Variables(lst_globales,
					Variable(Asigna_nombre($2),Tipo(Asigna_nombre("CURSOR"),0,$6)));
		}
	}
   | TK_DECLARE TK_ID decl_local TK_CURSOR TK_FOR expresion
   {
		if (Existe_Var($2))
		{
			yyerror("Error. Variable ya definida (%s)\n",$2);
			$$=NULL;
		}
		else
		{
			$$=Declare(Asigna_nombre($2),Asigna_valor($3),$6,Asigna_valor(0));
			if ($3==1)
				lst_globales=Variables(lst_globales,
					Variable(Asigna_nombre($2),Tipo(Asigna_nombre("LCURSOR"),0,$6)));
			else
				lst_globales=Variables(lst_globales,
					Variable(Asigna_nombre($2),Tipo(Asigna_nombre("CURSOR"),0,$6)));
		}
   }
	;

decl_local: {$$=0;}
	| TK_LOCAL {$$=1;}
	;

open_cursor: TK_OPEN TK_CURSOR TK_ID {$$=OpenCursor(Asigna_nombre($3));}
   ;
close_cursor: TK_CLOSE TK_CURSOR TK_ID {$$=CloseCursor(Asigna_nombre($3));}
   ;
fetch_cursor: TK_FETCH fetch_dir TK_ID TK_INTO lst_identif
   { $$=FetchCursor(Asigna_nombre($3),$2,$5);}
   ;
fetch_dir: {$$=Asigna_valor(1);}
   | TK_NEXT {$$=Asigna_valor(1);}
   | TK_PREVIOUS {$$=Asigna_valor(-1);}
   ;

exec_sql: TK_EXEC expresion into
   { $$=ExecSQL($2,$3);}
   ;
   
select: TK_SELECT lst_campos into TK_FROM lst_tablas where orden
	{
	 en_select=1;
	 $$=Select($2,$3,$5,$6,$7);
	 en_select=0;
	}
	;

delete: TK_DELETE TK_FROM TK_ID where
	{
		$$=Delete(Asigna_nombre($3),$4);
		if ($4==NULL)
		{
			warning("'delete from %s' sin 'where'",$3);
		}
	}
	;

lst_campos: campo_tabla
		{
			$$=ListaId(NULL,$1);
		}
	| lst_campos ',' campo_tabla
		{
			$$=ListaId($1,$3);
		}
	;

campo_tabla: '*' {$$=Id(Asigna_nombre("*"));}
	| TK_ID {$$=Id(Asigna_nombre($1));} 
	| TK_ID '(' lst_campos ')' 
		{
			char tmp[512];
			sprintf(tmp,"%s(%s)",$1,charListaId($3));
			$$=Id(Asigna_nombre(tmp));
		}
	;

into: {$$=NULL;}
	| TK_INTO lst_identif {$$=$2;}
	;

where: {$$=NULL;} 
	| TK_WHERE {en_select=1;} expresion  {$$=$3; en_select=0;}
	;


orden: {$$=NULL;}
	| TK_ORDER TK_BY lst_campos_orderby {$$=$3;}
	;

lst_campos_orderby: campo_orderby {$$=ListaId(NULL,$1);}
   	| lst_campos_orderby ',' campo_orderby {$$=ListaId($1,$3);}
        ;

campo_orderby: TK_ID {$$=Id(Asigna_nombre($1));}
   	| TK_ID TK_ASCENDING
           {
                char cadena[512];
           	sprintf(cadena,"%s ASC",$1);
                $$=Id(Asigna_nombre(cadena));
           }
   	| TK_ID TK_DESCENDING
           {
                char cadena[512];
                sprintf(cadena,"%s DESC",$1);
                $$=Id(Asigna_nombre(cadena));
           }
        ;
        
lst_tablas: TK_ID
	{
		$$=ListaId(NULL,Id(Asigna_nombre($1)));
	}
	| lst_tablas ',' TK_ID
	{
		$$=ListaId($1,Id(Asigna_nombre($3)));
	}
	;

insert: TK_INSERT TK_INTO TK_ID TK_VALUES '(' listaexpresiones ')'
		{
			$$=Insert(Asigna_nombre($3),$6);
		}
	;
update: TK_UPDATE TK_ID TK_ID 
   		{if (strcasecmp($3,"set"))
                    yyerror("syntax error");
                 en_select=1;
                }
                update_campos
                where
                {$$=Update(Asigna_nombre($2),$5,$6);}
	;
update_campos: update_campo {$$=UpdateCampos(NULL,$1);}
   | update_campos ',' update_campo {$$=UpdateCampos($1,$3);}
   ;
update_campo: TK_ID TK_IGUAL expresion
   {$$=UpdateCampo(Asigna_nombre($1),$3);}
   ;
   
transacc_begin: TK_BEGIN TK_TRANSACTION {$$=Transacc(Asigna_nombre("BEGIN"));}
   ;
transacc_abort: TK_ABORT TK_TRANSACTION {$$=Transacc(Asigna_nombre("ABORT"));}
   ;
transacc_commit: TK_COMMIT TK_TRANSACTION {$$=Transacc(Asigna_nombre("COMMIT"));}
   ;


/********************* Menus en pantalla **************************/

menu: TK_MENU {in_menu++;} expresion menuformat menuattr menuops {in_menu--;} TK_END TK_MENU
	{
		char nomMenu[10];
		int numOps;
		numOps=MenuOps_longitud($6);
		sprintf(nomMenu,"_M%d",numMenu++);
		/* Creo una nueva variable local para el menu */
		lst_locales=Variables(lst_locales,
			Variable(Asigna_nombre(nomMenu),
						Tipo(Asigna_nombre("MENU"),
						Asigna_valor(numOps),NULL)));
		$$=Menu(Asigna_nombre(nomMenu),$3,Asigna_valor($4),$5,$6);
	}
	|
	TK_MENU {in_menu++;} menuformat menuattr menuops {in_menu--;} TK_END TK_MENU
	{ 
		char nomMenu[10];
		int numOps;
		numOps=MenuOps_longitud($5);
		sprintf(nomMenu,"_M%d",numMenu++);
		/* Creo una nueva variable local para el menu */
		lst_locales=Variables(lst_locales,
			Variable(Asigna_nombre(nomMenu),
						Tipo(Asigna_nombre("MENU"),
						Asigna_valor(numOps),NULL)));
		$$=Menu(Asigna_nombre(nomMenu),NULL,Asigna_valor($3),$4,$5);
	}
	;

menuops: menuops menuop
	{
		$$=MenuOps($1,$2);
	}
	| menuop
	{
		$$=MenuOps(NULL,$1);
	}
	;

menuop: TK_COMMAND expresion ',' expresion sentencias 
	{
		$$=MenuOp($2,$4,$5,Asigna_valor(0));
	}
	| TK_COMMAND expresion sentencias 
	{
		$$=MenuOp($2,NULL,$3,Asigna_valor(0));
	}
	| TK_ON TK_KEY '(' TK_ID ')' sentencias
	{
		$$=MenuOp(Asigna_nombre($4),NULL,$6,Asigna_valor(1));
	}
	;

exitmenu: TK_EXIT TK_MENU
	{
		if (in_menu==0)
			yyerror("EXIT MENU fuera de un menu");
		$$=ExitMenu();
	}
	;

menuattr: TK_ATTR atributos_vent ';' atributos_vent
	{	
		$$=MenuAttr($2,$4);
	}
	| TK_ATTR atributos_vent
	{	
		$$=MenuAttr($2,NULL);
	}
	|	{$$=NULL;}
	;

menuformat: {$$=0;}
	|	TK_HORIZ {$$=0;}
	|  TK_VERT  {$$=1;}
	| TK_VERT TK_HORIZ {$$=2;}
	| TK_HORIZ TK_VERT {$$=2;}
	;

/************************* Browsers ********************************/
sent_browse: browse {$$=$1;}
   | browse_exit {$$=$1;}
   ;
browse_exit: TK_EXIT TK_BROWSE {$$=BrowseExit();}
   ;
browse: TK_BROWSE TK_ID TK_INTO lst_identif
        browse_donde
        browse_titulo
        TK_DISPLAY expresion
        browseops
        browsevacio
        TK_END TK_BROWSE
        {
           if (!Existe_Var($2))
           {
           		yyerror("El cursor %s no esta declarado",$2);
               $$=NULL;
           }
           else
           {
				 if (strcmp(chr_tipo_var($2),"LCURSOR"))
				 {
					 yyerror("Debe declarar %s como 'LOCAL CURSOR'",$2);
                $$=NULL;
				 }
				 else
				 {
		          char nomBrowse[10];
		          sprintf(nomBrowse,"_Br%d",numBrowse++);
		          /* Creo una nueva variable local para el browse */
		          lst_locales=Variables(lst_locales,
			          Variable(Asigna_nombre(nomBrowse),
						          Tipo(Asigna_nombre("BROWSE"),
						          Asigna_valor(0),NULL)));
					 $$=Browse(Asigna_nombre(nomBrowse),Asigna_nombre($2),
							 $4,$5,$6,$8,$9,$10);
				 }
           }
        }
	;

browse_donde: {$$=NULL;}
   | TK_FROM expresion ',' expresion TK_TO expresion ',' expresion
      {$$=Rect($2,$4,$6,$8);}
   ;
browse_titulo: {$$=NULL;}
   | TK_TITLE expresion {$$=$2;}
   ;

browseops:  browseop {$$=BrowseOps(NULL,$1);}
	|  browseops browseop
		{$$=BrowseOps($1,$2);}
	;
browsevacio: {$$=NULL;}
   |	TK_ELSE sentencias {$$=$2;}
   ;
browseop: TK_ON TK_KEY '(' TK_ID ')' sentencias
		{$$=BrowseOp(Asigna_nombre($4),$6);}
	|
		TK_ON TK_KEY '(' TK_CADENA ')' sentencias
		{
			cadena buffer;
			if (strlen($4)>1)
				yyerror("'%s' no es un caracter de teclado.",$4);
			else
			{ 
				sprintf(buffer,"'%s'",$4);
				$$=BrowseOp(Asigna_nombre(buffer),$6);
			}
		}
	|
		TK_ON TK_KEY '(' TK_CONS ')' sentencias
		{
			cadena buffer;
			sprintf(buffer,"%d",(int)$4);
			$$=BrowseOp(Asigna_nombre(buffer),$6);
		}
	; 


/************************ Generador de listados ************************/
sent_report: start_r {$$=$1;}
	| output_r {$$=$1;}
	| finish_r {$$=$1;}
	| rpt_print {$$=$1;}
	;

start_r:  TK_START TK_REPORT TK_ID 
      	{
            char nomfunc[256];
            sprintf(nomfunc,"STARTRPT_%s",$3);
            $$=Llamada(Asigna_nombre(nomfunc),NULL);
         };
         
output_r: TK_OUTPUT TK_TO TK_REPORT TK_ID '(' listaexpresiones ')' 
      	{
            char nomfunc[256];
            sprintf(nomfunc,"OutputRpt_%s",$4);
            $$=Llamada(Asigna_nombre(nomfunc),$6);
        };
         
finish_r: TK_FINISH TK_REPORT TK_ID
      	{
            char nomfunc[256];
            sprintf(nomfunc,"RPT_%s",$3);
            $$=Llamada(Asigna_nombre(nomfunc),NULL);
        };
         
rpt_print: TK_PRINT expresion
   {
      if (en_report)
         $$=PrintReport($2);
	   else
	      yyerror("Sentencia 'print' no permitida fuera de un listado.");
	 }
	 ;

report:   TK_REPORT TK_ID '(' {en_select=1;en_report=1;} lst_identif 
            	{en_select=0;lst_param=$5;} 
               ')' 
            declaraciones 
               {lst_locales=$8;
                lst_locales=Variables(lst_locales,
                   Variable(Asigna_nombre("pageno"),Tipo(Asigna_nombre("int"),0,NULL)));
                lst_locales=Variables(lst_locales,
                   Variable(Asigna_nombre("lineno"),Tipo(Asigna_nombre("int"),0,NULL)));
                }
		      rpt_salida
            rpt_formato
			 TK_END TK_REPORT 
          {
				lst_globales=Variables(lst_globales,
					Variable(Asigna_nombre($2),Tipo(Asigna_nombre("REPORT"),0,NULL)));
            $$=Report(Asigna_nombre($2),$5,$8,$10,$11);
	         en_report=0;
          };
	  
rpt_salida: TK_OUTPUT rpt_formato_pg {$$=$2;}
   ;
   
rpt_formato_pg: {$$=NULL;}
   | rpt_item_fmt {$$=RptOutput(NULL,$1);}  
   | rpt_formato_pg rpt_item_fmt {$$=RptOutput($1,$2);}
   ;
   
rpt_item_fmt: TK_REPORT TK_TO TK_CADENA
    {
       cadena nombre;
       sprintf(nombre,"F%s",$3);
       $$=Id(Asigna_nombre(nombre));
    }
   | TK_REPORT TK_TO TK_PIPE TK_CADENA
    {
       cadena nombre;
       sprintf(nombre,"P%s",$4);
       $$=Id(Asigna_nombre(nombre));
    }
	| TK_PAGE TK_ID TK_CONS
	{
		cadena tam;
		if (!strcasecmp($2,"width"))
		{
			sprintf(tam,"X%d",(int)$3);
			$$=Id(Asigna_nombre(tam));
		}
		else if (!strcasecmp($2,"heigth") || !(strcasecmp($2,"length")))
		{
			sprintf(tam,"Y%d",(int)$3);
			$$=Id(Asigna_nombre(tam));
		}
		else
		{
			$$=NULL;
			yyerror("Se esperaba 'width' o 'heigth'.");
		}
	}
   ;

rpt_formato: TK_FORMAT
   rpt_first_pg_hd
   rpt_pg_hd
   rpt_before_gr
   rpt_every
   rpt_after_gr
   rpt_pg_ft
   rpt_last_rw
   {$$=FormatoRpt($2,$3,$4,$5,$6,$7,$8);};
   
rpt_first_pg_hd: {$$=NULL;}
   | TK_FIRST TK_PAGE TK_HEADER sentencias {$$=$4;}
   ;

rpt_pg_hd: {$$=NULL;}
   | TK_PAGE TK_HEADER sentencias {$$=$3;}
   ;

rpt_before_gr: {$$=NULL;}
   | rpt_item_before_gr {$$=RptGrupos(NULL,$1);}
   | rpt_before_gr rpt_item_before_gr {$$=RptGrupos($1,$2);}
   ;

rpt_item_before_gr: TK_BEFORE TK_GROUP TK_OF lst_identif sentencias {$$=RptGrupo($4,$5);}
   ;

rpt_every: {$$=NULL;}
   | TK_ON TK_EVERY TK_ROW sentencias {$$=$4;}
   ;

rpt_after_gr: {$$=NULL;}
   | rpt_item_after_gr {$$=RptGrupos(NULL,$1);}
   | rpt_after_gr rpt_item_after_gr {$$=RptGrupos($1,$2);}
   ;

rpt_item_after_gr: TK_AFTER TK_GROUP TK_OF lst_identif sentencias {$$=NULL;}
   ;

rpt_pg_ft: {$$=NULL;}
   | TK_PAGE TK_FOOTER sentencias {$$=$3;}
   ;

rpt_last_rw: {$$=NULL;}
   | TK_ON TK_LAST TK_ROW sentencias {$$=$4;}
   ;


/************************** Forms de pantalla **************************/   
sent_form: form_create {$$=$1;}
   | form_display {$$=$1;}
   | form_dispByName {$$=$1;}
   | form_inputByName {$$=$1;}
   | form_exit {$$=$1;}
   | form_validate {$$=$1;}
   | form_current {$$=$1;}
   ;
   
form_create: TK_CREATE TK_FORM TK_ID
   	{
      Arbol aux;
      cadena nombre;
	  sprintf(nombre,"_F%s",$3);
      /* Si no existe la variable para el form, la creo. */
      if (!Busca_Var(nombre,lst_locales))
      {
      	aux=Variable(Asigna_nombre(nombre),Tipo(Asigna_nombre("FORM"),Asigna_valor(0),NULL));
        lst_locales=Variables(lst_locales,aux);
      }
      $$=FormCreate(Asigna_nombre($3));
    }
    ;
form_display: TK_DISPLAY TK_FORM TK_ID {$$=FormDisplay(Asigna_nombre($3));}
   ;

form_dispByName: TK_DISPLAY TK_BY TK_ID lst_identif 
   {
      if (!strcasecmp($3,"NAME"))
         $$=FormDispByName($4);
      else
      {
         yyerror("Error de sintaxis");
      }
   }
   ;

form_inputByName: TK_INPUT TK_BY TK_ID lst_identif 
   {
      if (!strcasecmp($3,"NAME"))
         $$=FormInputByName($4,NULL,NULL);
      else
      {
         yyerror("Error de sintaxis");
      }
   }
   |TK_INPUT TK_BY TK_ID lst_identif form_onkeys form_afterfields
      TK_END TK_INPUT
   {
      if (!strcasecmp($3,"NAME"))
         $$=FormInputByName($4,$5,$6);
      else
      {
         yyerror("Error de sintaxis");
      }
   }
   |TK_INPUT TK_BY TK_ID lst_identif form_afterfields
      TK_END TK_INPUT
   {
      if (!strcasecmp($3,"NAME"))
         $$=FormInputByName($4,NULL,$5);
      else
      {
         yyerror("Error de sintaxis");
      }
   }
   |TK_INPUT TK_BY TK_ID lst_identif form_onkeys
      TK_END TK_INPUT
   {
      if (!strcasecmp($3,"NAME"))
         $$=FormInputByName($4,$5,NULL);
      else
      {
         yyerror("Error de sintaxis");
      }
   }
   ;

form_onkeys: form_onkey {$$=FormOnKeys(NULL,$1);}
	|  form_onkeys form_onkey
		{$$=FormOnKeys($1,$2);}
	;

form_afterfields: form_afterfield {$$=FormAfterFields(NULL,$1);}
   | form_afterfields form_afterfield {$$=FormAfterFields($1,$2);}
   ;

form_onkey: TK_ON TK_KEY '(' TK_ID ')' sentencias
		{
         cadena buffer;
         sprintf(buffer,"K%s",$4);
         $$=FormOnKey(Asigna_nombre(buffer),$6);
      }
	|
		TK_ON TK_KEY '(' TK_CADENA ')' sentencias
		{
			cadena buffer;
			if (strlen($4)>1)
				yyerror("'%s' No puede indicar mas de un caracter.",$4);
			else
			{ 
				sprintf(buffer,"K'%s'",$4);
				$$=FormOnKey(Asigna_nombre(buffer),$6);
			}
		}
	|
		TK_ON TK_KEY '(' TK_CONS ')' sentencias
		{
			cadena buffer;
			sprintf(buffer,"K%d",(int)$4);
			$$=FormOnKey(Asigna_nombre(buffer),$6);
		}
   | 
      TK_ON TK_BUTTON TK_ID sentencias
      {
      	cadena buffer;
         sprintf(buffer,"B%s",$3);
         $$=FormOnKey(Asigna_nombre(buffer),$4);
      }
	; 

form_afterfield: TK_AFTER TK_FIELD TK_ID sentencias 
      {
      	$$=FormAfterField(Asigna_nombre($3),$4);
      }
   ;
   
form_exit: TK_EXIT TK_INPUT {$$=FormExit();}
   ;

form_validate: TK_VALIDATE TK_FIELD {$$=FormValidateField();}
   ;

form_current: TK_CURRENT TK_FIELD TK_ID {$$=FormCurrentField(Asigna_nombre($3));}
   | TK_NEXT TK_FIELD TK_ID {$$=FormCurrentField(Asigna_nombre($3));}
   ;

form_def: TK_FORM TK_ID form_elementos TK_END TK_FORM
   	{$$=Form(Asigna_nombre($2),$3);}
   ;

form_elementos: form_elemento {$$=FormCampos(NULL,$1);}
   | form_elementos form_elemento {$$=FormCampos($1,$2);}
   ;

form_elemento: {/* Vacio */} {$$=NULL;}
   | TK_INPUT TK_ID TK_FROM expresion ',' expresion TK_TO expresion ',' expresion form_attribs
      {$$=FormCampo(FormInput(),Asigna_nombre($2),$4,$6,$8,$10,$11);}
   | TK_BUTTON TK_ID TK_AT expresion ',' expresion form_attribs
      {$$=FormCampo(FormButton(),Asigna_nombre($2),$4,$6,NULL,NULL,$7);}
   | TK_RADIO TK_ID TK_AT expresion ',' expresion form_attribs
      {$$=NULL;}
   | TK_CHECK TK_ID TK_AT expresion ',' expresion form_attribs
      {$$=FormCampo(FormCheck(),Asigna_nombre($2),$4,$6,NULL,NULL,$7);}
   ;

form_attribs: {$$=NULL;}
   | TK_ATTR atributos_vent {$$=$2;}
   ;

   
