#include <time.h>
#include <ncurses.h>
#include <panel.h>
#include <menu.h>
#include <form.h>
#include <libpq-fe.h>

#define F1 KEY_F(1)
#define F2 KEY_F(2)
#define F3 KEY_F(3)
#define F4 KEY_F(4)
#define F5 KEY_F(5)
#define F6 KEY_F(6)
#define F7 KEY_F(7)
#define F8 KEY_F(8)
#define F9 KEY_F(9)
#define F10 KEY_F(10)
#define F11 KEY_F(11)
#define F12 KEY_F(12)

#ifndef NCURSES_VERSION
#define NCURSES_VERSION "0.0"
#endif

#ifndef wgetbkgd
#define wgetbkgd getbkgd
#endif

#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b

/*************** Funciones de manejo de ventanas ***************/
void _4GLexit(int);
long _4GLmin(long, long);
long _4GLmax(long, long);

struct _WINDOW
{
	int y,x,yy,xx;
	int fore, back, brillo, borde;
	WINDOW *w, *wb;
	PANEL *p, *pb;
   struct _4GLFORM *form;
};

typedef struct _WINDOW _WINDOW;


void _4GLinit();
void _4GLexit(int);
_WINDOW *_4GLnewwin(int, int, int, int, int, int, int, int, char *);
void _4GLdelwin(_WINDOW *);
void _4GLmovewin(_WINDOW *,int, int);
void _4GLerror(char *fmt,...);
void _4GLalert(char *fmt,...);

/*********** Funciones de manejo de menus ******************/
struct _MENU
{
	MENU *menu;
	WINDOW *win;
	WINDOW *sub;
   PANEL *panel;
   int opc;
   int format;
};

typedef struct _MENU _MENU;

int _4GLmueve_menu(_MENU m);
void _4GLset_menu(_MENU *m);

/*********** Funciones de interfaz con PostGres ************/
struct _CURSOR
{
	PGconn *conn;
	PGresult *res;
	int ntuples;
	int nfields;
	int actual;
	int status;
   char query[8196];
};

typedef struct _CURSOR _CURSOR;
PGconn *_4GLsetdb(char *);
_CURSOR *_4GLcursor(PGconn *,char *,_CURSOR *);
void _4GLexec(PGconn *,char *);
void _4GLclear(_CURSOR);
void _4GLbegin_transaction(PGconn *);
void _4GLend_transaction(PGconn *);
void _4GLcommit_transaction(PGconn *);
void _4GLabort_transaction(PGconn *);
char * _4GLsqlErrorStr(PGconn *_conn);
void _4GLchkInsert(char *sel);
void _4GLchkUpdate(char *sel);
void _4GLclosecursor(_CURSOR);

char *_4GLfieldByName(_CURSOR,char *);
void _4GLfetchNext(_CURSOR);
void _4GLfetchPrev(_CURSOR);
void _4GLfetch(_CURSOR);

/*********** Funciones de manejo de browsers ******************/
enum browse_acciones {BRW_SUBIR, BRW_BAJAR, BRW_REDRAW};
struct _BROWSE
{
   _CURSOR *cursor;
	WINDOW *win;
   int actual;
   int primero;
   int ultimo;
   int x_offset;
   int max_length;
   int y,x;
   int max_y, max_x;
   int tecla;
   char *titulo;
   char *linea;
   enum browse_acciones accion;
};
typedef struct _BROWSE _BROWSE;
void _4GLset_browse(_BROWSE *b);

/******** Funciones de manejo de forms *******/
enum tipo_campo {CAMPO_LABEL, CAMPO_TEXTO, CAMPO_BOTON, CAMPO_RADIO, CAMPO_CHECK, 
            	 CAMPO_SELECT};
struct _4GLFIELD
{
   enum tipo_campo objeto;
   char nombre[128];
   FIELD *campo;
   int grupo;
   int x,y,w,h;
   FIELDTYPE *tipo;
   chtype attr;
   int visible;   
   union
   {
      char mascara[128];
      char **valores;
   } rango;
   struct _4GLFIELD *anterior;
   struct _4GLFIELD *sgte;
};

typedef struct _4GLFIELD * _4GLFIELD;

struct _4GLFORM
{
   char nombre[128];
   struct _4GLFIELD *campos;
   struct _4GLFIELD *campo_activo;
   FORM *form;
   int tecla;
};

typedef struct _4GLFORM *_4GLFORM;
void _4GLinit_form(_4GLFORM f);
void _4GLloop_form(_4GLFORM f);
void _4GLshow_form(_4GLFORM f);
void _4GLdrive_form_input(_4GLFORM f, int tecla);
void _4GLFormClean(_4GLFORM f);
void _4GLFormAssign(_4GLFORM f,char *nomcampo, char *cadena);
void _4GLFormReadOnly(_4GLFORM f,char *nomcampo,int readonly);
char *_4GLFormFieldValue(_4GLFORM f, char *field);
_4GLFIELD _4GLcurrent_field(_4GLFORM f);

/******** Funciones de manejo de cadenas *****/
char *_4GLtrim(char *);
char *_4GLstrncpy(char *, char *, int);
char *_4GLint2str(long);
char *_4GLfloat2str(double);
char *_4GLstrcat(char *, char *);
char *_4GLdousing(double, char *);

/******** Funciones de fecha ************/
typedef struct {
   int year;
   int month;
   int day;
} _4GLDATE;

typedef struct {
   int hour;
   int min;
   int sec;
   int mil;
} _4GLTIME;

typedef struct {
   _4GLDATE date;
   _4GLTIME time;
} _4GLDATETIME;

typedef struct {
   long hours;
   int mins;
   int secs;
   int mils;
} _4GLINTERVAL;

bool _4GLchkDate(_4GLDATE);
bool _4GLchkTime(_4GLTIME);
bool _4GLchkDateTime(_4GLDATETIME);
bool _4GLchkInterval(_4GLINTERVAL);

_4GLDATE _4GLstr2date(char *fecha);
_4GLTIME _4GLstr2time(char *);
_4GLDATETIME _4GLstr2datetime(char *);
_4GLDATETIME _4GLiso2datetime(char *);
_4GLINTERVAL _4GLstr2interval(char *);
_4GLDATE _4GLDBstr2date(char *fecha);
_4GLTIME _4GLDBstr2time(char *);
_4GLDATETIME _4GLDBstr2datetime(char *);
_4GLDATETIME _4GLDBiso2datetime(char *);
_4GLINTERVAL _4GLDBstr2interval(char *);
char *_4GLdate2str(_4GLDATE fec);
char *_4GLdate2iso(_4GLDATE fec);
char *_4GLtime2str(_4GLTIME fec);
char *_4GLdatetime2str(_4GLDATETIME fec);
char *_4GLdatetime2iso(_4GLDATETIME fec);
char *_4GLinterval2str(_4GLINTERVAL fec);
int _4GLdatecmp(_4GLDATE f1, _4GLDATE f2);
long _4GLdate2julian(_4GLDATE);
long _4GLtime2sec(_4GLTIME);
_4GLTIME _4GLsec2time(long);
long _4GLinterval2sec(_4GLINTERVAL);
_4GLINTERVAL _4GLsec2interval(long);

_4GLDATE _4GLjulian2date(long);

/******** Funciones de pila *************/
enum tipos {TIPO_VOID, TIPO_INT, TIPO_FLOAT, TIPO_STR, 
   TIPO_DATE, TIPO_TIME, TIPO_DATETIME, TIPO_INTERVAL,
   TIPO_RECORD};

struct pila 
{
   enum tipos tipo;
   union
   {
      char *cadena;
      long entero;
      double real;
      _4GLDATE fecha;
      _4GLTIME time;
      _4GLDATETIME datetime;
      _4GLINTERVAL interval;
   } valor;
   struct pila *siguiente;
};

typedef struct pila pila;

pila *nueva_pila();
bool pila_vacia(pila *);

enum tipos tipo_pila(pila *);

void push_str(pila *, char*);
void push_int(pila *, long);
void push_float(pila *, double);
void push_date(pila *, _4GLDATE);
void push_time(pila *, _4GLTIME);
void push_datetime(pila *, _4GLDATETIME);
void push_interval(pila *, _4GLINTERVAL);

char *pop_str(pila *);
long pop_int(pila *);
double pop_float(pila *);
_4GLDATE pop_date(pila *);
_4GLTIME pop_time(pila *);
_4GLDATETIME pop_datetime(pila *);
_4GLINTERVAL pop_interval(pila *);

void op_suma(pila *);
void op_mult(pila *pila_exp);
void op_divide(pila *pila_exp);
void op_resta(pila *);
void op_cmp(pila *,int);
void op_and(pila *);
void op_or(pila *);
void op_negar(pila *);

