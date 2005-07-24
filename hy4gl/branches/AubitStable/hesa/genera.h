void escribir_c(FILE *f,char *s);
void mayusculas(char *m, char *M);

void genera_comentario(FILE *f, char *s);

void genera_cabecera(char c);

void genera_def_arbol(void);

void genera_union(lista_id *campos);
void genera_campo(tabla_id tipo, tabla_id campo);

void genera_prototipos_h(void);

void genera_definicion(tabla_id id);
void genera_definiciones(void);

void genera_lista_generica(void);

void genera_lista(tabla_id simbolo);

void genera_agregado(tabla_id simbolo, lista_id *lista);
void genera_funcion_agreg(char *cadena, int num_hijo);
void genera_funcion_campo(char *cadena_m, char *n_campo, int i);

void genera_terminal(tabla_id id);
void genera_terminales(void);

void genera_prototipos_c(void);

int nueva_entrada(void);
void recorre_nodos(lista_sel *p, int ref_padre);
void genera_opcion(tabla_id hijo, int ref_padre);
void genera_seleccion(tabla_id id);
void genera_selecciones(void);

void genera_extrac_atr(char *nombre,char *campo);
void genera_atributo(tabla_id id_nombre);
void genera_atributos(void);

void genera_funciones(void);
void genera_func_anade_al_final(void);
void genera_func_nuevo_nodo(void);
void genera_func_agregado(void);
void genera_func_concatena(void);
void genera_func_longitud(void);
void genera_func_siguiente(void);
void genera_func_ultimo(void);
void genera_func_hijo_iesimo(void);
void genera_func_busca_entrada_filiacion(void);
void genera_func_Es(void);
void genera_func_Selector(void);
void genera_func_Constructor(void);
void genera_func_Borra(void);
void genera_func_Parte(void);
void genera_func_Vacia(void);
void genera_func_Une(void);
void genera_func_Modifica(void);
