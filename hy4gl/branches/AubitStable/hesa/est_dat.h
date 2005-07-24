/* TAMA¥O DE LA TABLA */

#define NUM_ID 500

/* TAMA¥O DE LAS CADENAS */

#define TAM_CAD 50


/* CLASIFICACION DE LOS IDENTIFICADORES */

#define DESCONOCIDA    0
#define AGREGADO       1
#define SELECCION      2
#define RAIZ_SELECCION 3
#define LISTA          4
#define HOJA           5
#define ETIQUETA       6
#define CAMPO_UNION    7
#define DEF_TIPO       8 


/* DEFINICION DEL TIPO REFERENCIA A TABLA DE IDENTIFICADORES */

typedef int tabla_id;



/* DECLARACION DE LA ESTRUCTURA DE LA LISTA DE IDENTIFICADORES */

typedef struct lista_id
{
 tabla_id simbolo;
 struct lista_id *sig;
}lista_id;



/* DECLARACION DE LA ESTRUCTURA DEL ARBOL DE OPCIONES DE UN TIPO
   SELECCION */

typedef struct lista_s
{
 tabla_id tipo_sel;
 struct lista_s *p_hijo;
 struct lista_s *p_herm;
}lista_sel;



/* DECLARACION DE LA ESTRUCTURA DE LA TABLA DE IDENTIFICADORES */

typedef struct 
{
 char nombre[TAM_CAD];
 int  clase;
 lista_sel *arb_selec;
 tabla_id   tipo;
 tabla_id   campo; 
}regist_tabla;



/* PROTOTIPOS DE FUNCIONES DE MANIPULACION DE LA LISTA DE IDENTIFICADORES */

lista_id *une_listas(lista_id *l1, lista_id *l2);
lista_id *anade_identificador(lista_id *lista,tabla_id elem);    
int lista_longitud(lista_id *lista);
lista_id *identificador_iesimo(lista_id *lista,int i);
tabla_id identificador_simbolo(lista_id *elem);
void libera_lista(lista_id *lista);


/* PROTOTIPOS DE FUNCIONES DE MANIPULACION DEL ARBOL DE OPCIONES */

lista_sel *const_opc(tabla_id opcion);
tabla_id extrae_opc(lista_sel *opc);
lista_sel *anade_hijos(lista_sel *padre, lista_sel *hijos);
lista_sel *anade_herm(lista_sel *lista, lista_sel *elem);
lista_sel *primer_hijo(lista_sel *lista);
lista_sel *sig_herm(lista_sel *lista);
void libera_arbol(lista_sel *arbol);


/* PROTOTIPOS DE FUNCIONES DE MANIPULACION DE LA TABLA DE 
   IDENTIFICADORES */

tabla_id instala_simb(char *nombre);
tabla_id busca_simb(char *nombre);

void inicializa_tabla(void);

void recorre_tabla(void (*procesa)(tabla_id id));

void actualiza_clase(tabla_id simbolo, int clase);
void actualiza_arbol(tabla_id simbolo, lista_sel *arbol);
void actualiza_tipo(tabla_id simbolo, tabla_id tipo);
void actualiza_campo(tabla_id simbolo, tabla_id campo);

int extrae_clase(tabla_id simbolo);
lista_sel *extrae_arbol(tabla_id simbolo);
tabla_id extrae_tipo(tabla_id simbolo);
tabla_id extrae_campo(tabla_id simbolo);

void extrae_cadena(tabla_id simbolo, char *nombre);


