#include "hy4gl.h"

extern pila *pila_param, *pila_exp;
extern int _4GLfechaEuro;

/* Funcion que devuelve el dia de la semana de una fecha que recibe
   como parametro */
void _Fn_dow()
{
   _4GLDATE fecha;
   long julian;
   char *dias[]={"Domingo","Lunes","Martes","Miercoles","Jueves","Viernes","Sabado"};
   fecha=pop_date(pila_exp);
   julian=_4GLdate2julian(fecha);
   push_str(pila_exp,dias[++julian % 7]);
   return;
}

/* Funcion que devuelve el dia de la semana de una fecha que recibe
   como parametro (EN NUMERO)
   
   Si _4GLfechaEuro = 1 -> Lunes=1; Domingo=7 
   Si _4GLfechaEuro = 0 -> Domingo=1; Sabado=7
   
*/  
   
void _Fn_ndow()
{
   _4GLDATE fecha;
   long julian;
   fecha=pop_date(pila_exp);
   julian=_4GLdate2julian(fecha);
   if (_4GLfechaEuro)
      push_int(pila_exp,(julian % 7)+1);
   else
      push_int(pila_exp,(++julian % 7)+1);
   return;
}

void _Fn_today()
{  
   time_t t;
   struct tm *str_tm;
   _4GLDATE fecha;

   t=time(NULL);
   str_tm=localtime(&t);   
   fecha.day=str_tm->tm_mday;
   fecha.month=str_tm->tm_mon+1;
   fecha.year=str_tm->tm_year+1900;
   push_date(pila_exp,fecha);
   return;
}

void _Fn_date()
{
   _Fn_today();
}

void _Fn_time()
{  
   time_t t;
   struct tm *str_tm;
   _4GLTIME hora;

   t=time(NULL);
   str_tm=localtime(&t);   
   hora.hour=str_tm->tm_hour;
   hora.min=str_tm->tm_min;
   hora.sec=str_tm->tm_sec;
   hora.mil=0; 
   push_time(pila_exp,hora);
   return;
}

void _Fn_datetime()
{
   time_t t;
   struct tm *str_tm;
   _4GLDATETIME dt;
   t=time(NULL);
   str_tm=localtime(&t);   
   dt.time.hour=str_tm->tm_hour;
   dt.time.min=str_tm->tm_min;
   dt.time.sec=str_tm->tm_sec;
   dt.time.mil=0;
   dt.date.day=str_tm->tm_mday;
   dt.date.month=str_tm->tm_mon+1;
   dt.date.year=str_tm->tm_year+1900;
   push_datetime(pila_exp,dt);
   return;
}
