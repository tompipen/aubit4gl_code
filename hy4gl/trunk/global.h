/****************************************************************************
*   Archivo: GLOBAL.H                                                       *
* Contenido: Definiciones de tipos para las tablas de tipos, s¡mbolos       *
*                        y funciones.                                                   *
****************************************************************************/
#ifndef GLOBALH
#define MAXLONGID 255

typedef  char cadena[MAXLONGID+1];
struct tabla_sim
{
	char nombre[MAXLONGID+1];
	struct tabla_sim *sgte;
};

struct atributos
{
   int color, brillo, borde;
};

enum tipos {TIPO_VOID, TIPO_INT, TIPO_FLOAT, TIPO_STR, 
   TIPO_DATE, TIPO_TIME, TIPO_DATETIME, TIPO_INTERVAL,
   TIPO_RECORD};
#define GLOBALH
#endif


