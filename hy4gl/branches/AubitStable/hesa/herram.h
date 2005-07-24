#define ID_FICH 256

extern FILE *f_cab;
extern FILE *f_def;
extern FILE *f_fil;

void construye_nombre_raiz(char *nombre,char *nombre_raiz,int *valido);
void construye_nombres(char *nombre_raiz,char *nombre_c, char *nombre_h);
void abrir_temporales(char *cab, char *def, char *fil);
void construye_salida(char *nombre_c,char *cab, char *def, char *fil);