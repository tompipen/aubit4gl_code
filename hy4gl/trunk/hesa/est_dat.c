#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "est_dat.h"

regist_tabla tabla[NUM_ID];
tabla_id indice=0;



/* FUNCIONES DE MANIPULACION DE LA LISTA DE IDENTIFICADORES */

lista_id *une_listas(lista_id *l1, lista_id *l2)
{
 lista_id *lista;

 if(l1==NULL)
   lista = l2;
 else
  {
   lista = l1;
   while(l1->sig!=NULL)
     l1 = l1->sig;
   l1->sig = l2;
  }
 return(lista);
}



lista_id *anade_identificador(lista_id *lista, tabla_id elem)
{
 lista_id *p,*p_final;

 p = (lista_id *) malloc(sizeof(lista_id));
 p->simbolo = elem;
 p->sig = NULL;

 if(lista != NULL)
  {
   p_final = lista;
   while(p_final->sig!=NULL)
     p_final = p_final->sig;
   p_final->sig = p;
  }
 else
  lista = p;
 return(lista);
}



int lista_longitud(lista_id *lista)
{
 int i=0;

 while(lista!=NULL)
  { 
   i++;
   lista = lista->sig;
  }
 return(i);
}

lista_id *identificador_iesimo(lista_id *lista,int i)
{
 if(i > lista_longitud(lista))
   printf("\nError no existe dicho hijo agregado");
 else
   while(i!=1)
    {
     i--;
     lista = lista->sig;
    }
 return(lista);
}



tabla_id identificador_simbolo(lista_id *elem)
{
 return(elem->simbolo);
}

void libera_lista(lista_id *lista)
{
 lista_id *resto;
 while(lista!=NULL)
  {
   resto=lista->sig;
   free(lista);
   lista= resto;
  }
}


/* FUNCIONES DE MANIPULACION DEL ARBOL DE OPCIONES */

lista_sel *const_opc(tabla_id opcion)
{
 lista_sel *p;

 p = (lista_sel *) malloc (sizeof(lista_sel));

 p->tipo_sel = opcion;
 p->p_hijo = NULL;
 p->p_herm = NULL;

 return(p);
}


tabla_id extrae_opc(lista_sel *opc)
{
 if(opc == NULL)
   printf("\nError no puedo extraer opcion");

 return(opc->tipo_sel);
}


lista_sel *anade_hijos(lista_sel *padre, lista_sel *hijos)
{
 lista_sel *p;

 if(padre == NULL)
   printf("\nError no puedo a¤adir hijo sin padre");
 else
  {
   if(padre->p_hijo==NULL)
     padre->p_hijo = hijos;
   else
    {
     p = padre;
     while(p->p_hijo!=NULL)
       p=p->p_hijo;
     p->p_hijo = hijos;
    }
  }
 return(padre);
}


lista_sel *anade_herm(lista_sel *lista, lista_sel *elem)
{
 lista_sel *p_final;

 if(lista != NULL)
  {
   p_final = lista;
   while(p_final->p_herm!=NULL)
     p_final = p_final->p_herm;
   p_final->p_herm = elem;
  }
 else
  lista = elem;
 return(lista);
}


lista_sel *primer_hijo(lista_sel *lista)
{
 if(lista==NULL)
   printf("\nError no puedo extraer hijo sin padre");

 return(lista->p_hijo);
}



lista_sel *sig_herm(lista_sel *lista)
{
 if(lista == NULL)
   printf("\nError no puedo extraer siguiente opcion");

 return(lista->p_herm);
}


void libera_arbol(lista_sel *arbol)
{
 lista_sel *padre,*hijo,*hijos;
 padre = arbol;
 hijo = padre->p_hijo;
 free(padre);
 while(hijo!=NULL)
  {
   hijos = hijo->p_herm;
   libera_arbol(hijo);
   hijo = hijos;
  }
}

/* FUNCIONES DE MANIPULACION DE LA TABLA DE IDENTIFICADORES */

tabla_id instala_simb(char *nombre)
{
 tabla_id ref;

 ref = busca_simb(nombre);

 if(ref == -1)
  {
   if(indice==NUM_ID)
    {
     fprintf(stderr,"\nhesa: Sobrepasado el n£mero m ximo de identificadores\n");
     exit(1);
    }  
   ref = indice++;
   strcpy(tabla[ref].nombre,nombre);
  }
 return(ref);
}
									    

tabla_id busca_simb(char *nombre)
{
 tabla_id id_ref=0;

 while((id_ref <= indice) && 
       strcmp(nombre, tabla[id_ref].nombre))
   id_ref ++;
 if(id_ref>indice)
   id_ref = -1;

 return(id_ref);
}


void inicializa_tabla(void)
{
 tabla_id i;
 for(i=0;i<NUM_ID;i++)
  {
   strcpy(tabla[i].nombre,"");
   tabla[i].clase = DESCONOCIDA;
   tabla[i].arb_selec = NULL;
   tabla[i].tipo = 0;
   tabla[i].campo = 0;
  }
}

void recorre_tabla(void (*procesa)(tabla_id id))
{
tabla_id i;
 for(i=0;i<indice;i++)
   (*procesa)(i);
}

void actualiza_clase(tabla_id simbolo, int clase)
{
 tabla[simbolo].clase = clase;
}


void actualiza_arbol(tabla_id simbolo, lista_sel *arbol)
{
 tabla[simbolo].arb_selec = arbol;
}


void actualiza_tipo(tabla_id simbolo, tabla_id tipo)
{
 tabla[simbolo].tipo = tipo;
}

void actualiza_campo(tabla_id simbolo, tabla_id campo)
{
 tabla[simbolo].campo = campo;
}


int extrae_clase(tabla_id simbolo)
{
 return(tabla[simbolo].clase);
}


lista_sel *extrae_arbol(tabla_id simbolo)
{
 return(tabla[simbolo].arb_selec);
}


tabla_id extrae_tipo(tabla_id simbolo)
{
 return(tabla[simbolo].tipo);
}

tabla_id extrae_campo(tabla_id simbolo)
{
 return(tabla[simbolo].campo);
}


void extrae_cadena(tabla_id simbolo, char *nombre)
{
 strcpy(nombre,tabla[simbolo].nombre);
}


