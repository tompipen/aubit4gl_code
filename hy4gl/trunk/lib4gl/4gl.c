/*************************************/
/* Libreria de funciones para el 4GL */
/*************************************/
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <libpq-fe.h>
#include <hy4gl.h>

/* Variables globales */
int _4GLy, _4GLx;
WINDOW *curwin=NULL;
_WINDOW *_curwin=NULL;
pila *pila_param=NULL;
pila *pila_exp=NULL;
PGconn *_conn=NULL;
_CURSOR _CurTmp;
char _SelTmp[8196];
char _WhereTmp[8196];
bool _4GLfechaEuro;
bool _4GLChkErrores=1; /* Se pone a 0 con 'whenever error continue' */

int arg_count; /* Para contener los parametros recibidos por el programa */
char **_arg_val;

/* Variables de estado de transacciones de BBDD */
int status, ok, notfound, found;

/* Funcion a la que llaman todos los programas al empezar.
   Inicializa las curses y prepara algunas variables. 
   */
void _4GLinit()
{
   int i,j;
   /*Preparo las curses */
   initscr();
   start_color();
   nonl();                      /* No traduce CR en CR+LF */
   keypad(stdscr,TRUE);         /* Teclado en condiciones */
   cbreak();   /* Procesa las teclas sueltas; no espera ENTER */
   raw();      /* la teclas sueltas */
   noecho();   /* No saca las teclas que pulso por pantalla */
   meta(stdscr,TRUE); /* Admito caracteres de 8 bits */

   /* Cargo el locale */
   setlocale(LC_COLLATE,"");
   setlocale(LC_CTYPE,"");
   setlocale(LC_MESSAGES,"");
   setlocale(LC_TIME,"");
   setlocale(LC_NUMERIC,"C");
   setlocale(LC_MONETARY,"C");
   
   curwin=stdscr;
   _curwin=(_WINDOW *)malloc(sizeof(struct _WINDOW));
   _curwin->w=_curwin->wb=stdscr;
   scrollok(stdscr,TRUE);
   set_panel_userptr(new_panel(stdscr),_curwin);
   menu_opts_off(NULL,O_SHOWDESC);
   /* Genero las 64 combinaciones de color posibles */
   for (i=0; i<8; i++)          /* Fore */
      for (j=0; j<8; j++)       /* Back */
         init_pair((i*8)+j+1,i,j);
   _4GLfechaEuro=1; /* El formato de fecha es dd-mm-aaaa por defecto. */
}

void _4GLexit(int i)
{
   /* Si estamos conectados a una Base de Datos, cierro la conexion */
   if (_conn)
      PQfinish(_conn);
   /* Termino con las curses */
   endwin();
   /* Y salgo por fin */
   exit(i);
}

_WINDOW *_4GLnewwin(int yy, int xx, int y, int x, int b, 
   int fore, int back, int brillo, char *titulo)
{
   _WINDOW *w;
   int br=0;
   int pos=0;
      
   w=(_WINDOW *)malloc(sizeof(_WINDOW));
   if (!w)
      _4GLerror("Sin memoria para crear nueva ventana.");
      
   if (brillo==1)
      br=A_BOLD;
      
   if ((y+yy>LINES) || (x+xx>COLS))
   {
      _4GLalert("La ventana es demasiado grande para caber en pantalla\n%s",
            	"Se ajusta su tamaño...");
      if ((y+yy)>LINES)
         yy=LINES-y;
      if ((x+xx)>COLS)
         xx=COLS-y;
   }
   
   if (b==1)
   {
      w->wb=newwin(yy,xx,y,x);
      meta(w->wb,TRUE);
      scrollok(w->wb,TRUE);
      wbkgdset(w->wb,' '|(COLOR_PAIR(fore*8+back+1))|br);
      wclear(w->wb);
      w->pb=new_panel(w->wb);
      set_panel_userptr(w->pb,w);
      box(w->wb,0,0);
      if (titulo!=NULL)
      {
         if (strlen(titulo) < w->xx-2)
         {
            pos = (xx-strlen(titulo)) / 2;
            mvwprintw(w->wb,0,pos,"%s",titulo);
         }
         else
            mvwprintw(w->wb,0,1,"%*.*s",xx-2, xx-2,titulo);
      }
   	w->w=newwin(yy-2,xx-2,y+1,x+1);
   }
   else
   {
      w->w=newwin(yy,xx,y,x);
   }

   scrollok(w->w,TRUE);

   wbkgdset(w->w,' '|(COLOR_PAIR(fore*8+back+1))|br);
   meta(w->w,TRUE);
   wclear(w->w);
   w->p=new_panel(w->w);
   
   if (!w->p)
      _4GLalert("No se puede crear panel para la nueva ventana");
   else
      set_panel_userptr(w->p,w);
   w->x=x;
   w->y=y;
   w->xx=xx;
   w->yy=yy;
   w->borde=b;
   w->fore=fore;
   w->back=back;
   w->brillo=brillo;
   update_panels();
   doupdate();
   curwin=w->w;
   _curwin=w;
   return w;
}

void _4GLdelwin(_WINDOW *w)
{
   if (w)
   {
      del_panel(w->p);
      delwin(w->w);
      if (w->borde==1)
      {
         del_panel(w->pb);
         delwin(w->wb);
      }
      update_panels();
      doupdate();
      curwin=panel_window(panel_below((PANEL *)0));
      _curwin=(_WINDOW *)panel_userptr(panel_below((PANEL *)0));
      if (!_curwin)
         curwin=stdscr;
      free(w);
   }
   else
      _4GLalert("No puede cerrar una ventana que no esta anierta.");
}

void _4GLmovewin(_WINDOW *w,int y,int x)
{
   if (w->borde==1)
   {
      move_panel(w->pb,y,x);
      move_panel(w->p,y+1,x+1);
      mvwin(w->wb,y,x);
      mvwin(w->w,y+1,x+1);
   }
   else
   {
      move_panel(w->p,y,x);
      mvwin(w->w,y,x);
   }
   update_panels();
   doupdate();
}

long _4GLmin(long a, long b)
{
   if (a<b)
      return a;
   else
      return b;
}
long _4GLmax(long a, long b)
{
   if (a>b)
      return a;
   else
      return b;
}

char *_4GLint2str(long i)
{
   static char buff[40];
   char *res;
   sprintf(buff,"%ld",i);
   res=(char *)malloc(strlen(buff)+1);
   strcpy(res,buff);
   return res;
}

char *_4GLfloat2str(double i)
{
   static char buff[40];
   char *res;
   sprintf(buff,"%f",i);
   res=(char *)malloc(strlen(buff)+1);
   strcpy(res,buff);
   return res;
}

char *_4GLstrncpy(char *s1, char *s2, int tam)
{
   strncpy(s1,s2,tam);
   s1[tam]='\0';
   return s1;
}

char *_4GLstrcat(char *s1, char *s2)
{
   static char *res;
   res=(char *)malloc(strlen(s1)+strlen(s2)+1);
   sprintf(res,"%s%s",s1,s2);
   return res;
}

char *_4GLtrim(char *s)
{  
   int i;
   for (i=strlen(s);i>0 && s[i-1]==' ';i--)
      s[i-1]='\0';
   return s;
}

void _4GLerror(char *fmt,...)
{
   va_list args;
   char linea[256];
   _WINDOW *w;
   /*Copio la lista de parámetros recibidos */
   va_start (args, fmt);
   vsprintf (linea, fmt, args);
   va_end (args);
   w=_4GLnewwin(8,70,8,5,1,COLOR_WHITE,COLOR_RED,1,"ERROR");
   wprintw(w->w,"%s",linea);
   wrefresh(w->w);
   doupdate();
   getch();
   _4GLdelwin(w);
   endwin(); /* Cierro las curses */

   /* La imprimo */
   fprintf(stderr,"%s\n",linea);
   exit(1);  //sustituye al return.
}                  
void _4GLalert(char *fmt,...)
{
   va_list args;
   char linea[256];
   _WINDOW *w;
   /*Copio la lista de parámetros recibidos */
   va_start (args, fmt);
   vsprintf (linea, fmt, args);
   va_end (args);
   w=_4GLnewwin(8,70,8,5,1,COLOR_WHITE,COLOR_GREEN,1,"ATENCION");
   wprintw(w->w,"%s",linea);
   wrefresh(w->w);
   doupdate();
   getch();
   _4GLdelwin(w);
}                  

void _4GLdoclipped(void)
{
   char *cadena;
   int i;
   cadena=pop_str(pila_exp);
   i=strlen(cadena)-1;
   while (i>=0 && cadena[i]==' ')
      cadena[i--]='\0';
   push_str(pila_exp,cadena);
}

void _Fn_arg_val(void)
{
   int i;
   i=pop_int(pila_exp);
   if (i<=arg_count)
      push_str(pila_exp,_arg_val[i]);
   else
      push_str(pila_exp,"");
}

char *_4GLdousing (double numero, char *mascara)
{
  int cont=0;
  int cont2=0;
  int final=0;      /* Posicion del final de la cadena resultado */
  int ppnum=0;      /* Posicion del punto en el numero */
  int ppmasc=0;     /* Posicion del punto en la mascara */
  int lmasc;        /* Longitud de la mascara, para no hacer tantas consultas
                       a strlen(mascara) */
  int lnum;         /* Longitud del numero, para lo mismo que la otra */  
  static char result[40]; /* Pon el tamaño que quieras */
  char numstr[40];        /* Numero en formato cadena */
  struct lconv *datosloc;  /* Datos del Locale */

  datosloc=localeconv();  /* Leemos los datos del locale */

  /* Datos de locale por defecto, por si hay problemas */  
  if (!strcmp(datosloc->mon_decimal_point,"") || !strcmp(datosloc->mon_thousands_sep,""))
  {
    datosloc->mon_decimal_point=(char *) malloc (2);
    datosloc->mon_thousands_sep=(char *) malloc (2);
    strcpy (datosloc->mon_decimal_point,".");
    strcpy (datosloc->mon_thousands_sep,",");
  }

  sprintf (numstr,"%f",numero);  /* Convierto el numero a cadena */
  lmasc=strlen(mascara);
  lnum=strlen(numstr);  

   if (getenv("HYDEBUG"))
   {
    _4GLalert("lmasc=%d lnum=%d",lmasc,lnum);
    _4GLalert("mascara='%s' numero='%f'",mascara,numero);
    _4GLalert("punto='%s' miles='%s'",datosloc->mon_decimal_point,datosloc->mon_thousands_sep);
   }

  /* Localizo el punto decimal en el numero*/
  ppnum=strcspn(numstr,datosloc->mon_decimal_point);
    
  /* Localizo el punto en la mascara */
  if (index(mascara,'.')!=NULL)
  {
    ppmasc=strcspn(mascara,".");
    cont=ppmasc-1;  /* Si tiene punto */
  }
  else
    cont=lmasc-1;   /* Si no tiene punto */
    
  cont2=ppnum-1;
  final=cont+1;  /* Posicion del final de la cadena */

  /* Primero la parte entera */  
  while (cont>=0)
  {
    if (mascara[cont]=='&')
    {
      if (numstr[cont2]!='-')
      {
        if (cont2<0)
          result[cont]='0';
        else
          result[cont]=numstr[cont2];
        cont--;
      }
      cont2--;
    } 
    else if (mascara[cont]=='#')
    {
      if (numstr[cont2]!='-')
      {
        if (cont2<0)
          result[cont]=' ';
        else
          result[cont]=numstr[cont2];
        cont--;
      }
      cont2--;
    } 
    else if (mascara[cont]=='-')
    {
      if (cont2<0)
        result[cont]=' ';
      else
        result[cont]=numstr[cont2];
      cont--;
      cont2--;
    }
    else if (mascara[cont]==',')
    {
      /* Mientras queden numeros */
      if (((cont2>=0) || (mascara[cont-1]=='&')) && (numstr[cont2]!='-'))
        result[cont]=datosloc->mon_thousands_sep[0];
      else
        result[cont]=' ';
      cont--;
    }
    else /* Si es cualquier otro caracter */
    {
      result[cont]=mascara[cont];
      cont--;
    }
  }

  /* Si quedan numeros y no caben en la mascara, ponemos los asteriscos
     que parece que le gustan mucho a JLuis "Gurruñuño"... :) */
  if (cont2>=0) 
  {
    cont=0;
    while (cont<=lmasc)
    {
      if ((mascara[cont]=='&')||(mascara[cont]=='#')||(mascara[cont]=='-'))
          result[cont]='*';
      else
        result[cont]=mascara[cont];
      cont++;
    }
    return result;
  }
  
  if (ppmasc>0)  /* Si tenemos punto hacemos la parte decimal */
  {
    result[ppmasc]=datosloc->mon_decimal_point[0]; /* Antes de nada ponemos el punto */
    cont=ppmasc+1;
    cont2=ppnum+1;
    
    /* Ahora recorremos desde punto hasta el final */
    while (cont<lmasc)
    {
      if (mascara[cont]=='&')
      {
        if (cont2>lnum)
          result[cont]='0';
        else
          result[cont]=numstr[cont2];
        cont++;
        cont2++;
      } 
      else if (mascara[cont]=='#')
      {
        if (cont2>lnum)
          result[cont]=' ';
        else
          result[cont]=numstr[cont2];
        cont++;
        cont2++;
      } 
      else if (mascara[cont]=='-')
      {
        if (cont2>=lnum)
          result[cont]=' ';
        else
          result[cont]=numstr[cont2];
        cont++;
        cont2++;
      }
      else
      {
        result[cont]=mascara[cont];
        cont++;
      }
    }
    final=lmasc;
  }

  result[final]='\0';
  return result;
}


