#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "est_dat.h"
#include "herram.h"
#include "genera.h"


void escribir(FILE *f,char *s)
{
 fprintf(f,"%s",s);
}


void mayusculas(char *m,char *M)
{
 int i=0;

 while(m[i]!='\0')
  {
   M[i]=toupper(m[i]);
   i++;
  }
  M[i] = '\0';
}


void genera_comentario(FILE *f,char *s)
{
 int l,i;
 char cad[100]="\n/*";

 l = strlen(s);      
 for(i=3;i<=(34-l/2);i++)
    cad[i]=' ';
 cad[i]='\0';
 strcat(cad,s);
 for(i=strlen(cad);i<=69;i++)
    cad[i]=' ';
 cad[i]='\0';
 strcat(cad,"*/");
 fprintf(f,"\n/*---------------------------------");
 fprintf(f,"----------------------------------*/");
 fprintf(f,cad);
 fprintf(f,"\n/*---------------------------------");
 fprintf(f,"----------------------------------*/");
}

void genera_cabecera(char c)
{
 static int primera_vez = 1;

 if(primera_vez)
  {
   genera_comentario(f_cab,"CODIGO DE CABECERA");
   fprintf(f_cab,"\n\n");
   primera_vez = 0;
  }
 fprintf(f_cab,"%c",c);
}

void genera_union(lista_id *campos)
{
 int num_campos,i=1;
 lista_id *elem;
 tabla_id id_campo,id_tipo;

 fprintf(f_cab,"\n\n");
 genera_comentario(f_cab,"TIPO DE LOS ATRIBUTOS");
 fprintf(f_cab,"\n");
 num_campos = lista_longitud(campos);
 fprintf(f_cab,"\ntypedef ");
 if(num_campos>0)
   fprintf(f_cab,"union{");
 else
   fprintf(f_cab,"int ");
 while(i <= num_campos)
  {
   elem = identificador_iesimo(campos,i);
   id_campo = identificador_simbolo(elem);
   id_tipo = extrae_tipo(id_campo);
   genera_campo(id_tipo, id_campo);
   i++;
  } 
 if(num_campos>0)
   fprintf(f_cab,"\n }");
 fprintf(f_cab,"T_atributo;");
 fprintf(f_cab,"\n");
}

void genera_campo(tabla_id tipo, tabla_id campo)
{
 char cad_tipo[TAM_CAD],cad_campo[TAM_CAD];

 extrae_cadena(tipo,cad_tipo);
 extrae_cadena(campo,cad_campo);
 fprintf(f_cab,"\n  ");
 fprintf(f_cab,cad_tipo);
 fprintf(f_cab," ");
 fprintf(f_cab,cad_campo);
 fprintf(f_cab,";");
}

void genera_def_arbol(void)
{
 fprintf(f_cab,"\n");
 genera_comentario(f_cab,"NODO DEL ARBOL");
 fprintf(f_cab,"\n");
 fprintf(f_cab,"\ntypedef struct s_arbol{");
 fprintf(f_cab,"\n  int constructor;");
 fprintf(f_cab,"\n  T_atributo atributo;");
 fprintf(f_cab,"\n  struct s_arbol *hermano, *hijos;");
 fprintf(f_cab,"\n }*Arbol;");
 fprintf(f_cab,"\n\n#define VACIO NULL");


 fprintf(f_def,"\n\n");
 genera_comentario(f_def,"LISTAS, AGREGADOS, Y HOJAS DEL ARBOL");
}


void genera_definicion(tabla_id id)
{
 static int cont=2;
 char cadena_m[TAM_CAD],cadena_M[TAM_CAD];

 switch(extrae_clase(id))
  {
   case AGREGADO:
   case LISTA:
   case SELECCION:
   case RAIZ_SELECCION:
   case DESCONOCIDA:
     extrae_cadena(id,cadena_m);
     mayusculas(cadena_m,cadena_M);
     fprintf(f_cab,"\n#define %s %i",cadena_M,cont);
     cont++;
  }
}

void genera_definiciones(void)
{
 fprintf(f_cab,"\n\n");
 genera_comentario(f_cab,"DEFINICIONES DE LOS CONSTRUCTORES");
 fprintf(f_cab,"\n");
 fprintf(f_cab,"\n#define ARBOL_VACIO 0");
 fprintf(f_cab,"\n#define LISTA_GENERICA 1");
 recorre_tabla((void(*)(tabla_id))genera_definicion);
 fprintf(f_cab,"\n");
}

void genera_prototipos_h(void)
{
 fprintf(f_cab,"\n");
 genera_comentario(f_cab,"PROTOTIPOS DE FUNCIONES");
 fprintf(f_cab,"\n");
 fprintf(f_cab,"\nArbol _agregado(int constructor,int num_hijos,...);"); 
 fprintf(f_cab,"\nArbol _concatena(int constructor, Arbol lista, Arbol elem);");
 fprintf(f_cab,"\nArbol _hijo_iesimo(Arbol p, int orden);");
 fprintf(f_cab,"\nint _longitud(Arbol lista);");
 fprintf(f_cab,"\nArbol _siguiente(Arbol elem);"); 
 fprintf(f_cab,"\nint _ultimo(Arbol elem);");
 fprintf(f_cab,"\nint Es(int constructor, Arbol p);");
 fprintf(f_cab,"\nint Selector(int constructor, Arbol p);");
 fprintf(f_cab,"\nint Constructor(Arbol p);");
 fprintf(f_cab,"\nvoid Borra(Arbol a);");
 fprintf(f_cab,"\nvoid Parte(Arbol lista, Arbol *cabeza, Arbol *cola);");
 fprintf(f_cab,"\nint Vacia(Arbol lista);");
 fprintf(f_cab,"\nArbol Une(Arbol lista1, Arbol lista2);");
 fprintf(f_cab,"\nvoid Modifica(Arbol padre, Arbol hijo_ant, Arbol hijo_nuevo);");
 fprintf(f_cab,"\n");
}

void genera_lista_generica(void)
{
 fprintf(f_cab,"\n");
 genera_comentario(f_cab,"MACROS DE LISTAS GENERICAS");
 fprintf(f_cab,"\n");
 fprintf(f_cab,"\n#define  Concatena(lista,elem)   ");
 fprintf(f_cab,"_concatena(LISTA_GENERICA,lista,elem)");

 fprintf(f_cab,"\n#define  Longitud(lista)   ");
 fprintf(f_cab,"_longitud(lista)"); 

 fprintf(f_cab,"\n#define  Hijo_iesimo(lista,indice)   ");
 fprintf(f_cab,"_hijo_iesimo(lista,indice)" );

 fprintf(f_cab,"\n#define  Primero(lista)   ");
 fprintf(f_cab,"_hijo_iesimo(lista,1)"); 

 fprintf(f_cab,"\n#define  Siguiente(elemento)   ");
 fprintf(f_cab,"_siguiente(elem)"); 

 fprintf(f_cab,"\n#define  Ultimo(elemento)   ");
 fprintf(f_cab,"_ultimo(elem)"); 
}

void genera_lista(tabla_id simbolo)
{
 char cadena_m[TAM_CAD],cadena_M[TAM_CAD];

 extrae_cadena(simbolo,cadena_m);
 mayusculas(cadena_m,cadena_M);

 fprintf(f_def,"\n");
 fprintf(f_def,"\n#define  ");
 fprintf(f_def,cadena_m);
 fprintf(f_def,"(lista,elem) _concatena(");
 fprintf(f_def,cadena_M);
 fprintf(f_def,",lista,elem)"); 

 fprintf(f_def,"\n#define  ");
 fprintf(f_def,cadena_m);
 fprintf(f_def,"_longitud(lista) _longitud(lista)"); 

 fprintf(f_def,"\n#define  ");
 fprintf(f_def,cadena_m);
 fprintf(f_def,"_elemento(lista,indice) _hijo_iesimo(lista,indice)" );

 fprintf(f_def,"\n#define  ");
 fprintf(f_def,cadena_m);
 fprintf(f_def,"_primero(lista) _hijo_iesimo(lista,1)"); 

 fprintf(f_def,"\n#define  ");
 fprintf(f_def,cadena_m);
 fprintf(f_def,"_siguiente(elem) _siguiente(elem)"); 

 fprintf(f_def,"\n#define  ");
 fprintf(f_def,cadena_m);
 fprintf(f_def,"_ultimo(elem) _ultimo(elem)"); 

}

void genera_agregado(tabla_id simbolo, lista_id *lista)
{
 lista_id *elem;
 tabla_id s_campo;
 int num_hijo,i=1;
 char cadena_m[TAM_CAD],n_campo[TAM_CAD];

 extrae_cadena(simbolo,cadena_m);
 num_hijo = lista_longitud(lista);
 fprintf(f_def,"\n");
 genera_funcion_agreg(cadena_m,num_hijo);
 while(i<=num_hijo)
  {
   elem = identificador_iesimo(lista,i);
   s_campo = identificador_simbolo(elem);
   extrae_cadena(s_campo,n_campo);
   genera_funcion_campo(cadena_m,n_campo,i);
   i++;
  }
}

void genera_funcion_agreg(char *cadena_m, int num_hijo)
{
 char cadena_M[TAM_CAD];
 int i;

 i = 1;
 mayusculas(cadena_m,cadena_M);
 fprintf(f_def,"\n#define  ");
 fprintf(f_def,cadena_m);
 fprintf(f_def,"(");
 while(i<=num_hijo)
  {
   fprintf(f_def,"p%i",i);
   if(i!=num_hijo)
     fprintf(f_def,",");
   i++;
  }
 fprintf(f_def,")   ");

 i=1;
 fprintf(f_def,"_agregado(");
 fprintf(f_def,cadena_M);
 fprintf(f_def,",%i,",num_hijo);
 while(i<=num_hijo)
  {
   fprintf(f_def,"p%i",i);
   if(i!=num_hijo)
     fprintf(f_def,",");
   i++;
  }
 fprintf(f_def,")");
}


void genera_funcion_campo(char *cadena_m, char * n_campo, int i)
{

 fprintf(f_def,"\n#define  ");
 fprintf(f_def,cadena_m);
 fprintf(f_def,"_");
 fprintf(f_def,n_campo);
 fprintf(f_def,"(p)  _hijo_iesimo(p,");
 fprintf(f_def,"%i",i);
 fprintf(f_def,")");
}

void genera_terminal(tabla_id id)
{
 char cadena_m[TAM_CAD],cadena_M[TAM_CAD];

 if(extrae_clase(id)==DESCONOCIDA)
 {
  extrae_cadena(id,cadena_m);
  mayusculas(cadena_m,cadena_M);
  fprintf(f_def,"\n#define  ");
  fprintf(f_def,cadena_m);
  fprintf(f_def,"()");
  fprintf(f_def,"   _agregado(");
  fprintf(f_def,cadena_M);
  fprintf(f_def,",0)");
 }
}

void genera_terminales(void)
{
 fprintf(f_def,"\n");
 recorre_tabla((void(*)(tabla_id))genera_terminal);
}

void genera_prototipos_c(void)
{
 fprintf(f_fil,"\n");
 genera_comentario(f_fil,"PROTOTIPOS DE FUNCIONES INTERNAS");
 fprintf(f_fil,"\n");
 fprintf(f_fil,"\nArbol _anade_al_final(Arbol lista, Arbol elem);");
 fprintf(f_fil,"\nArbol _nuevo_nodo(int constructor);");
 fprintf(f_fil,"\nint _busca_entrada_filiacion(int constructor);");
}


int nueva_entrada(void)
{
 static int cont=0;

 return(cont++);
}

void genera_opcion(tabla_id hijo, int ref_padre)
{
 char cadena_m[TAM_CAD],cadena_M[TAM_CAD];

 extrae_cadena(hijo,cadena_m);  
 mayusculas(cadena_m,cadena_M);
 fprintf(f_fil,"\n                       { ");
 fprintf(f_fil,cadena_M);
 fprintf(f_fil,",");
 fprintf(f_fil,"%i",ref_padre);
 fprintf(f_fil,"},");
}

void genera_seleccion(tabla_id id)
{
 if(extrae_clase(id)==RAIZ_SELECCION)
   recorre_nodos(extrae_arbol(id),-1);
}


void recorre_nodos(lista_sel *p, int ref_padre)
{
 lista_sel *hijo;

 genera_opcion(extrae_opc(p),ref_padre);
 ref_padre = nueva_entrada();
 hijo = primer_hijo(p);
 while(hijo != NULL)
  {
   recorre_nodos(hijo,ref_padre);
   hijo = sig_herm(hijo);
  }
}

void genera_selecciones(void)
{
 fprintf(f_fil,"\n\n");
 genera_comentario(f_fil,"TABLA DE FILIACION");
 fprintf(f_fil,"\n");
 fprintf(f_fil,"\nstatic struct");
 fprintf(f_fil,"\n       {int hijo;"); 
 fprintf(f_fil,"\n        int padre;");
 fprintf(f_fil,"\n       }filiacion[] = {"); 
 recorre_tabla((void(*)(tabla_id))genera_seleccion);
 fprintf(f_fil,"\n                       {-1,-1}};");
}

void genera_atributo(tabla_id id_nombre)
{
 static int primera_vez = 1;
 char nombre[TAM_CAD],campo[TAM_CAD];
 tabla_id id_campo;

 if(extrae_campo(id_nombre)!=0)
 {
  if(primera_vez)
   {
    fprintf(f_def,"\n");
    genera_comentario(f_def,"MANIPULACION DE ATRIBUTOS");
    fprintf(f_def,"\n");
    primera_vez = 0;
   }
  id_campo = extrae_campo(id_nombre);

  extrae_cadena(id_nombre,nombre);
  extrae_cadena(id_campo,campo);

  fprintf(f_def,"\n#define ");
  fprintf(f_def,nombre);
  fprintf(f_def,"_");
  fprintf(f_def,campo);
  fprintf(f_def,"(p) ");
  fprintf(f_def,"p->atributo.");
  fprintf(f_def,campo);
 }
}


void genera_atributos(void)
{
 recorre_tabla((void(*)(tabla_id))genera_atributo);
}


void genera_funciones(void)
{
 fprintf(f_fil,"\n");
 genera_comentario(f_fil,"CODIFICACION DE FUNCIONES");
 fprintf(f_fil,"\n");
 genera_func_anade_al_final();
 genera_func_nuevo_nodo();
 genera_func_agregado();
 genera_func_concatena();
 genera_func_hijo_iesimo();
 genera_func_longitud();
 genera_func_siguiente();
 genera_func_ultimo();
 genera_func_busca_entrada_filiacion();
 genera_func_Es();
 genera_func_Selector();
 genera_func_Constructor();
 genera_func_Borra();
 genera_func_Parte();
 genera_func_Vacia();
 genera_func_Une();
 genera_func_Modifica();
 fprintf(f_fil,"\n");
}


void genera_func_anade_al_final(void)
{
 fprintf(f_fil,"\nArbol _anade_al_final(Arbol lista, Arbol elem)");
 fprintf(f_fil,"\n{");
 fprintf(f_fil,"\n Arbol p;");
 fprintf(f_fil,"\n");
 fprintf(f_fil,"\n p = lista;");
 fprintf(f_fil,"\n if(p==NULL)");
 fprintf(f_fil,"\n   lista = elem;");
 fprintf(f_fil,"\n else");
 fprintf(f_fil,"\n  {");
 fprintf(f_fil,"\n   while(p->hermano!=NULL)");
 fprintf(f_fil,"\n     p = p->hermano;");
 fprintf(f_fil,"\n   p->hermano = elem;");
 fprintf(f_fil,"\n  }");
 fprintf(f_fil,"\n return(lista);");
 fprintf(f_fil,"\n}\n");
}

void genera_func_nuevo_nodo(void)
{
 fprintf(f_fil,"\nArbol _nuevo_nodo(int constructor)");
 fprintf(f_fil,"\n{");
 fprintf(f_fil,"\n Arbol p;");
 fprintf(f_fil,"\n");
 fprintf(f_fil,"\n p = (Arbol)malloc(sizeof(struct s_arbol));");
 fprintf(f_fil,"\n p->constructor = constructor;");
 fprintf(f_fil,"\n p->hermano = NULL;");
 fprintf(f_fil,"\n p->hijos = NULL;");
 fprintf(f_fil,"\n return(p);");
 fprintf(f_fil,"\n}\n");
}

void genera_func_agregado(void)
{
 fprintf(f_fil,"\nArbol _agregado(int constructor,int num_hijos,...)");
 fprintf(f_fil,"\n{");
 fprintf(f_fil,"\n va_list p;");
 fprintf(f_fil,"\n Arbol padre,hijo,hijos=NULL;");
 fprintf(f_fil,"\n int i;");
 fprintf(f_fil,"\n");
 fprintf(f_fil,"\n va_start(p,num_hijos);");
 fprintf(f_fil,"\n padre = _nuevo_nodo(constructor);");
 fprintf(f_fil,"\n for(i=1;i<=num_hijos;i++)");
 fprintf(f_fil,"\n  {");
 fprintf(f_fil,"\n   hijo = va_arg(p,Arbol);");
 fprintf(f_fil,"\n   if(hijo==NULL)");
 fprintf(f_fil,"\n     hijo = _nuevo_nodo(ARBOL_VACIO);");
 fprintf(f_fil,"\n   hijos = _anade_al_final(hijos,hijo);");
 fprintf(f_fil,"\n  }");
 fprintf(f_fil,"\n padre->hijos = hijos;");
 fprintf(f_fil,"\n return(padre);");
 fprintf(f_fil,"\n}\n");
}

void genera_func_concatena(void)
{
 fprintf(f_fil,"\nArbol _concatena(int constructor, Arbol lista, Arbol elem)");
 fprintf(f_fil,"\n{");
 fprintf(f_fil,"\n Arbol hijos;");
 fprintf(f_fil,"\n");
 fprintf(f_fil,"\n if(lista==NULL)");
 fprintf(f_fil,"\n   lista = _nuevo_nodo(constructor);");
 fprintf(f_fil,"\n hijos = lista->hijos;");
 fprintf(f_fil,"\n hijos = _anade_al_final(hijos,elem);");
 fprintf(f_fil,"\n lista->hijos = hijos;");
 fprintf(f_fil,"\n return(lista);");
 fprintf(f_fil,"\n}\n");
}

void genera_func_hijo_iesimo(void)
{
 fprintf(f_fil,"\nArbol _hijo_iesimo(Arbol p, int orden)");
 fprintf(f_fil,"\n{");
 fprintf(f_fil,"\n Arbol hijo = NULL;");
 fprintf(f_fil,"\n int i=1;");
 fprintf(f_fil,"\n");
 fprintf(f_fil,"\n if(_longitud(p) >= orden)");
 fprintf(f_fil,"\n  {");
 fprintf(f_fil,"\n   hijo = p->hijos;");
 fprintf(f_fil,"\n   while(i<orden)");
 fprintf(f_fil,"\n    {");
 fprintf(f_fil,"\n     hijo = hijo->hermano;");
 fprintf(f_fil,"\n     i++;");
 fprintf(f_fil,"\n    }");
 fprintf(f_fil,"\n  }");
 fprintf(f_fil,"\n return(hijo);");
 fprintf(f_fil,"\n}\n");
}

void genera_func_longitud(void)
{
 fprintf(f_fil,"\nint _longitud(Arbol lista)");
 fprintf(f_fil,"\n{");
 fprintf(f_fil,"\n Arbol p;");
 fprintf(f_fil,"\n int i=0;");
 fprintf(f_fil,"\n");
 fprintf(f_fil,"\n if(lista!=NULL)");
 fprintf(f_fil,"\n  {");
 fprintf(f_fil,"\n   p = lista->hijos;");
 fprintf(f_fil,"\n   while(p!=NULL)");
 fprintf(f_fil,"\n    {");
 fprintf(f_fil,"\n     p = p->hermano;");
 fprintf(f_fil,"\n     i++;");
 fprintf(f_fil,"\n    }");
 fprintf(f_fil,"\n   }");
 fprintf(f_fil,"\n return(i);");
 fprintf(f_fil,"\n}\n");
}

void genera_func_siguiente(void)
{
 fprintf(f_fil,"\nArbol _siguiente(Arbol elem)"); 
 fprintf(f_fil,"\n{");
 fprintf(f_fil,"\n return(elem->hermano);");
 fprintf(f_fil,"\n}\n");
}

void genera_func_ultimo(void)
{
 fprintf(f_fil,"\nint _ultimo(Arbol elem)");
 fprintf(f_fil,"\n{");
 fprintf(f_fil,"\n if(elem->hermano==NULL)");
 fprintf(f_fil,"\n   return(1);");
 fprintf(f_fil,"\n else");
 fprintf(f_fil,"\n   return(0);");
 fprintf(f_fil,"\n}\n");
}


void genera_func_busca_entrada_filiacion(void)
{
 fprintf(f_fil,"\nint _busca_entrada_filiacion(int constructor)");
 fprintf(f_fil,"\n{");
 fprintf(f_fil,"\n int i=0;");
 fprintf(f_fil,"\n while(filiacion[i].hijo!=-1)");
 fprintf(f_fil,"\n   if(filiacion[i].hijo==constructor)");
 fprintf(f_fil,"\n     return(i);");
 fprintf(f_fil,"\n   else");
 fprintf(f_fil,"\n     i++;");
 fprintf(f_fil,"\n return(-1);");
 fprintf(f_fil,"\n}\n");
}

void genera_func_Es(void)
{
 fprintf(f_fil,"\nint Es(int constructor, Arbol p)");
 fprintf(f_fil,"\n{");
 fprintf(f_fil,"\n int i,j,result=0;");
 fprintf(f_fil,"\n");
 fprintf(f_fil,"\n i = _busca_entrada_filiacion(constructor);");
 fprintf(f_fil,"\n j = _busca_entrada_filiacion(p->constructor);");
 fprintf(f_fil,"\n while(j!=-1)");
 fprintf(f_fil,"\n  if(j==i)");
 fprintf(f_fil,"\n   {");
 fprintf(f_fil,"\n    result=1;");
 fprintf(f_fil,"\n    break;");
 fprintf(f_fil,"\n   }");
 fprintf(f_fil,"\n  else");
 fprintf(f_fil,"\n   j = filiacion[j].padre;");
 fprintf(f_fil,"\n return(result);");
 fprintf(f_fil,"\n}\n");
}

void genera_func_Selector(void)
{
 fprintf(f_fil,"\nint Selector(int constructor, Arbol p)");
 fprintf(f_fil,"\n{");
 fprintf(f_fil,"\n int i,j,result=-1;");
 fprintf(f_fil,"\n");
 fprintf(f_fil,"\n if(Es(constructor,p))");
 fprintf(f_fil,"\n  {");
 fprintf(f_fil,"\n   i = _busca_entrada_filiacion(constructor);");
 fprintf(f_fil,"\n   j = _busca_entrada_filiacion(p->constructor);");
 fprintf(f_fil,"\n   while(filiacion[j].padre!=i)");
 fprintf(f_fil,"\n     j = filiacion[j].padre;");
 fprintf(f_fil,"\n   result = filiacion[j].hijo;");
 fprintf(f_fil,"\n  }");
 fprintf(f_fil,"\n return(result);");
 fprintf(f_fil,"\n}\n");
}

void genera_func_Constructor(void)
{
 fprintf(f_fil,"\nint Constructor(Arbol p)");
 fprintf(f_fil,"\n{");
 fprintf(f_fil,"\n return(p->constructor);");
 fprintf(f_fil,"\n}\n");
}


void genera_func_Borra(void)
{
 fprintf(f_fil,"\nvoid Borra(Arbol a)");
 fprintf(f_fil,"\n{");
 fprintf(f_fil,"\n Arbol padre,hijo,hijos;");
 fprintf(f_fil,"\n");
 fprintf(f_fil,"\n padre = a;");
 fprintf(f_fil,"\n hijo = padre->hijos;");
 fprintf(f_fil,"\n free(padre);");
 fprintf(f_fil,"\n while(hijo!=NULL)");
 fprintf(f_fil,"\n  {");
 fprintf(f_fil,"\n   hijos = hijo->hermano;");
 fprintf(f_fil,"\n   Borra(hijo);");
 fprintf(f_fil,"\n   hijo = hijos;");
 fprintf(f_fil,"\n  }");
 fprintf(f_fil,"\n}\n");
}

void genera_func_Parte(void)
{
 fprintf(f_fil,"\nvoid Parte(Arbol lista, Arbol *cabeza, Arbol *cola)");
 fprintf(f_fil,"\n{");
 fprintf(f_fil,"\n if(!Vacia(lista))");
 fprintf(f_fil,"\n {");
 fprintf(f_fil,"\n  *cola = lista;");
 fprintf(f_fil,"\n  *cabeza = lista->hijos;");
 fprintf(f_fil,"\n  (*cola)->hijos = (*cabeza)->hermano;");
 fprintf(f_fil,"\n  (*cabeza)->hermano = NULL;");
 fprintf(f_fil,"\n }");
 fprintf(f_fil,"\n}\n");
}

void genera_func_Vacia(void)
{
 fprintf(f_fil,"\nint Vacia(Arbol lista)");
 fprintf(f_fil,"\n{");
 fprintf(f_fil,"\n int res=0;");
 fprintf(f_fil,"\n");
 fprintf(f_fil,"\n if(lista==NULL)");
 fprintf(f_fil,"\n   res=1;");
 fprintf(f_fil,"\n else if(lista->hijos==NULL)");
 fprintf(f_fil,"\n   res=1;");
 fprintf(f_fil,"\n return(res);");
 fprintf(f_fil,"\n}\n");
}

void genera_func_Une(void)
{
 fprintf(f_fil,"\nArbol Une(Arbol lista1, Arbol lista2)");
 fprintf(f_fil,"\n{");
 fprintf(f_fil,"\n Arbol l_union,p;");
 fprintf(f_fil,"\n");
 fprintf(f_fil,"\n if (Vacia(lista1))");
 fprintf(f_fil,"\n   l_union = lista2;");
 fprintf(f_fil,"\n else if(Vacia(lista2))");
 fprintf(f_fil,"\n   l_union = lista1;");
 fprintf(f_fil,"\n else");
 fprintf(f_fil,"\n  {");
 fprintf(f_fil,"\n   l_union = lista1;");
 fprintf(f_fil,"\n   p = lista1->hijos;");
 fprintf(f_fil,"\n   while(!_ultimo(p))");
 fprintf(f_fil,"\n    {");
 fprintf(f_fil,"\n     p = _siguiente(p);");
 fprintf(f_fil,"\n    }   ");
 fprintf(f_fil,"\n   p->hermano = lista2->hijos;");
 fprintf(f_fil,"\n  }");
 fprintf(f_fil,"\nreturn(l_union);");
 fprintf(f_fil,"\n}\n");
}


void genera_func_Modifica(void)
{
 fprintf(f_fil,"\nvoid Modifica(Arbol padre, Arbol hijo_ant, Arbol hijo_nuevo)");
 fprintf(f_fil,"\n{");
 fprintf(f_fil,"\n Arbol p,p_ant,p_post;");
 fprintf(f_fil,"\n");
 fprintf(f_fil,"\n if(!Vacia(padre))");
 fprintf(f_fil,"\n  {");
 fprintf(f_fil,"\n   p = padre->hijos;");
 fprintf(f_fil,"\n   if(p ==hijo_ant)");
 fprintf(f_fil,"\n    {");
 fprintf(f_fil,"\n     p_post = p->hermano;");
 fprintf(f_fil,"\n     p->hermano = NULL;");
 fprintf(f_fil,"\n     padre->hijos=hijo_nuevo;");
 fprintf(f_fil,"\n     hijo_nuevo->hermano= p_post;");
 fprintf(f_fil,"\n    }");
 fprintf(f_fil,"\n   else");
 fprintf(f_fil,"\n    {");
 fprintf(f_fil,"\n     do{");
 fprintf(f_fil,"\n       p_ant = p;");
 fprintf(f_fil,"\n       p = p->hermano;");
 fprintf(f_fil,"\n     }while(p != hijo_ant && p!=NULL);");
 fprintf(f_fil,"\n     if(p!=NULL)");
 fprintf(f_fil,"\n      {");
 fprintf(f_fil,"\n       p_post = p->hermano;");
 fprintf(f_fil,"\n       p->hermano = NULL;");
 fprintf(f_fil,"\n       hijo_nuevo->hermano = p_post;");
 fprintf(f_fil,"\n       p_ant->hermano = hijo_nuevo;");
 fprintf(f_fil,"\n      }");
 fprintf(f_fil,"\n    }");
 fprintf(f_fil,"\n  }");
 fprintf(f_fil,"\n}\n");
}
