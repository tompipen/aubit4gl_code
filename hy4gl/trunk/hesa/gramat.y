%{
#include <stdio.h>

#include "est_dat.h"
#include "herram.h"
#include "genera.h"


void procesa_union(lista_id *lista);

tabla_id procesa_campo(tabla_id tipo, tabla_id campo);
void procesa_hojas(tabla_id campo, lista_id *lista);

lista_sel *procesa_opcion(lista_sel *opciones, tabla_id nueva_op);
void procesa_seleccion(tabla_id padre, lista_sel *opciones);

void procesa_lista(tabla_id id);

void procesa_componente(tabla_id etiq);
void procesa_agregado(tabla_id id, lista_id *lista);

void procesa_estructuras(void);

void libera_arboles_seleccion(void);
void libera_raiz_seleccion(tabla_id id);
%}
%union
 {
  tabla_id   id_ref;
  lista_sel  *p_sel;
  lista_id   *p_id;
  char       caract;
 }

%token TP_LLAVE_A TP_LLAVE_C TP_TP PROD TIPO UNION

%token <id_ref> ID 
%token <caract> CARACTER


%type <p_id>  lista_comp componente lista_id_ag lista_id_ty lista_id_ca
%type <id_ref> campo
%type <p_sel>  lista_opc

%%

fichero     : TP_LLAVE_A cabecera TP_LLAVE_C
	      union
	      {genera_def_arbol();} 
	      sec_tipos TP_TP reglas
	      {procesa_estructuras();}
	    ;

cabecera    :
	    | cabecera CARACTER {genera_cabecera($2);}
	    ;

union       : UNION '{' lista_id_ca '}'
	       {procesa_union($3);} 
	    ;

lista_id_ca : campo {$$ = anade_identificador(NULL,$1);}
	    | lista_id_ca campo {$$ = anade_identificador($1,$2);}
	    ;

campo       : ID  ID ';'
	      {$$ = procesa_campo($1,$2);}
	    ;

sec_tipos   :
	    | sec_tipos dec_tipo
	    ;

dec_tipo    : TIPO '<'ID '>' lista_id_ty
		 {procesa_hojas($3,$5);}
	    ;

lista_id_ty : ID  {$$ = anade_identificador(NULL,$1);}
	    | lista_id_ty ID {$$ = anade_identificador($1,$2);}
	    ;

reglas      : regla 
	    | reglas regla
	    ;

regla       : seleccion
	    | lista
	    | agregado
	    ;

seleccion   : ID PROD lista_opc
		 {procesa_seleccion($1,$3);}
	    ;

lista_opc   : ID 
		 {$$ = procesa_opcion(NULL,$1);}
	    | lista_opc '|' ID
		 {$$ = procesa_opcion($1,$3);}
	    ;


lista       : ID PROD ID '*'
		 {procesa_lista($1);}
	    ;

agregado    : ID PROD lista_comp
		 {procesa_agregado($1,$3);}
	    ;

lista_comp  : componente  
		 {$$ = $1;} 
	    | lista_comp ';' componente
		 {$$ = une_listas($1,$3);}
	    ;

componente  : lista_id_ag ':' ID  
		 {$$ = $1;}
	    ;

lista_id_ag : ID 
		{procesa_componente($1);
		 $$ = anade_identificador(NULL,$1);}
	    | lista_id_ag ',' ID
		{procesa_componente($3);
		 $$ = anade_identificador($1,$3);} 
	    ;

%%

void yyerror(char *s)
{
 printf("\nhesa: %s\n",s);
}


void procesa_union(lista_id *lista)
{
 genera_union(lista);
 libera_lista(lista);
}

tabla_id procesa_campo(tabla_id tipo, tabla_id campo)
{

 actualiza_clase(tipo,DEF_TIPO);
 actualiza_clase(campo,CAMPO_UNION);
 actualiza_tipo(campo,tipo);

 return(campo);
}


void procesa_hojas(tabla_id campo, lista_id *lista)
{
 lista_id *p;
 int longitud,i=1;
 tabla_id simbolo;

 longitud = lista_longitud(lista);
 while(i<=longitud)
 {
  p = identificador_iesimo(lista,i);
  simbolo = identificador_simbolo(p);
  actualiza_campo(simbolo,campo);
  i++;
 }
 libera_lista(lista);
}


lista_sel *procesa_opcion(lista_sel *opciones, tabla_id nueva_op)
{
 lista_sel *p;

 if(extrae_clase(nueva_op)==RAIZ_SELECCION)
   {
    p = extrae_arbol(nueva_op);
    actualiza_clase(nueva_op, SELECCION);
   }
 else
   {
    p = const_opc(nueva_op);
    actualiza_arbol(nueva_op,p);
   }
 return(anade_herm(opciones,p));
}


void procesa_seleccion(tabla_id padre, lista_sel *opciones)
{
 lista_sel *p_padre;

 actualiza_clase(padre,RAIZ_SELECCION);

 p_padre = extrae_arbol(padre);
 if(p_padre == NULL)
  {
   p_padre = const_opc(padre);
   actualiza_arbol(padre,p_padre);
  }
 else
   actualiza_clase(padre,SELECCION);
  
 anade_hijos(p_padre, opciones);
}


void procesa_lista(tabla_id id)
{
 actualiza_clase(id,LISTA);
 genera_lista(id);
}

void procesa_agregado(tabla_id id, lista_id *lista)
{
 actualiza_clase(id,AGREGADO);
 genera_agregado(id,lista);
 libera_lista(lista);
}

void procesa_componente(tabla_id etiq)
{
 actualiza_clase(etiq,ETIQUETA);
}

void procesa_estructuras(void)
{
 genera_prototipos_h();
 genera_definiciones();
 genera_lista_generica();
 genera_terminales();
 genera_atributos();
 genera_prototipos_c();
 genera_selecciones();
 libera_arboles_seleccion();
 genera_funciones();
}	      

void libera_arboles_seleccion(void)
{
 recorre_tabla((void(*)(tabla_id))libera_raiz_seleccion);
}

void libera_raiz_seleccion(tabla_id id)
{
 if(extrae_clase(id)==RAIZ_SELECCION)
   libera_arbol(extrae_arbol(id));
}
