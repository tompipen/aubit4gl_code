/* ######################################################################
   #                 FUNCIONES DE RUNTIME PARA HY4GL                    #
   #                         --------------                             #
   #       Copyright (C) 1998 Antonio Perez <aperez@poboxes.com>        #
   #                                                                    #
   #  NOTA: El tipo de distribucion todavia no se sabe si sera GPL o    #
   #        "copyrighted". Depende de lo que diga David... :)           #
   ###################################################################### */

#include "hy4gl.h"
#include <ctype.h>  /* toupper, tolower */
#include <string.h>
#include <math.h>

extern pila *pila_exp;

/* Funciona, pero al parecer las mayusculas acentuadas no se muestran en
   Linux, excepto la E. O por lo menos no en mi tipo de terminal y con el
   tipo de caracteres que estoy usando. */
static void op_toalgo(pila *pila_exp, int op)
{
  char *cadena;
  
  int cont;
  int tam;
  
  cadena=pop_str(pila_exp);
  tam=strlen(cadena);
  
  if (op)
  {
    for (cont=0;cont<tam;cont++)
    {
      if (cadena[cont]=='Á') cadena[cont]='á';
      else
      if (cadena[cont]=='É') cadena[cont]='é';
      else
      if (cadena[cont]=='Í') cadena[cont]='í';
      else
      if (cadena[cont]=='Ó') cadena[cont]='ó';
      else
      if (cadena[cont]=='Ú') cadena[cont]='ú';
      else
      if (cadena[cont]=='Ñ') cadena[cont]='ñ';
      else
      cadena[cont]=tolower(cadena[cont]);
    }
  }
  else
  {
    for (cont=0;cont<tam;cont++)
    {
      if (cadena[cont]=='á') cadena[cont]='Á';
      else
      if (cadena[cont]=='é') cadena[cont]='É';
      else
      if (cadena[cont]=='í') cadena[cont]='Í';
      else
      if (cadena[cont]=='ó') cadena[cont]='Ó';
      else
      if (cadena[cont]=='ú') cadena[cont]='Ú';
      else
      if (cadena[cont]=='ñ') cadena[cont]='Ñ';
      else
      cadena[cont]=toupper(cadena[cont]);
    }
  }
    
  push_str (pila_exp,cadena);
}

void _Fn_toupper ()
{
  op_toalgo (pila_exp,0);
}

void _Fn_tolower ()
{
  op_toalgo (pila_exp,1);
}

void _Fn_length ()
{
  union
  {
    char *cadena;
    long numero;
   _4GLDATE fecha;
  } p1;
  
  p1.cadena=pop_str (pila_exp);
  push_int (pila_exp,strlen(p1.cadena));
}

/* Centra la cadena en el espacio indicado */
void _Fn_center()
{
   char *cadena,*cad_tmp;
   int tam;
   tam=pop_int(pila_exp);
   cadena=(char *)malloc(tam+1);
   if (!cadena)
      _4GLerror("No hay memoria para centrar la cadena");
      
   memset(cadena,' ',tam);
   cadena[tam]='\0';
   cad_tmp=pop_str(pila_exp);

   /* Compruebo si la cadena que me dan cabe o no cabe */
   if (strlen(cad_tmp)<=tam)
      strncpy(cadena+(tam/2)-(strlen(cad_tmp)/2),cad_tmp,strlen(cad_tmp));
   else
      strncpy(cadena,cad_tmp,tam);
      
   push_str(pila_exp,cadena);
   free(cad_tmp);
   return;
}

void _Fn_pos ()
{
  union
  {
    char *cadena;
    long numero;
   _4GLDATE fecha;
  } p1,p2;
  
  char *aux;
  
  p2.cadena=pop_str(pila_exp);
  p1.cadena=pop_str(pila_exp);
  
  aux=(char *)strstr(p1.cadena,p2.cadena);
  if (aux==NULL)
    push_int (pila_exp,0);
  else
    push_int(pila_exp,aux-p1.cadena+1);
}

static void yearmonthday (int op)
{
  _4GLDATE fecha;
  
  enum tipos t1;
  
  t1=tipo_pila(pila_exp);
  
  switch(t1)
  {
    case TIPO_INT:
    case TIPO_FLOAT:
    case TIPO_STR:
    case TIPO_DATETIME:
    case TIPO_DATE:
      fecha=pop_date(pila_exp);
      switch(op)
      {
        case 0:
          push_int (pila_exp,fecha.year);
          break;
        case 1:
          push_int (pila_exp,fecha.month);
          break;
        case 2:
          push_int (pila_exp,fecha.day);
          break;
      }
      break;
    default:
      _4GLerror("Operacion no permitida.");
  }
}

void _Fn_year ()
{
  yearmonthday (0);
}

void _Fn_month ()
{
  yearmonthday (1);
}

void _Fn_day ()
{
  yearmonthday (2);
}

static void hourminsec (int op)
{
  _4GLTIME hora;
  
  enum tipos t1;
  
  t1=tipo_pila(pila_exp);
  
  switch(t1)
  {
    case TIPO_STR:
    case TIPO_TIME:
    case TIPO_DATETIME:
      hora=pop_time(pila_exp);
      switch(op)
      {
        case 0:
          push_int (pila_exp,hora.hour);
          break;
        case 1:
          push_int (pila_exp,hora.min);
          break;
        case 2:
          push_int (pila_exp,hora.sec);
          break;
        case 3:
          push_int (pila_exp,hora.mil);
          break;
      }
      break;
    default:
      _4GLerror("Operacion no permitida.");
  }
}

void _Fn_hour ()
{
  hourminsec (0);
}

void _Fn_minute ()
{
  hourminsec (1);
}

void _Fn_second ()
{
  hourminsec (2);
}

void _Fn_milisecond ()
{
  hourminsec (3);
}

void _Fn_min ()
{
  union
  {
    char *cadena;
    double numero;
    _4GLTIME hora;
    _4GLDATE fecha;
    _4GLDATETIME fechahora;
  }p1, p2;
  
  enum tipos t1, t2;
  
  t1=tipo_pila(pila_exp);
  
  switch(t1)
  {
    case TIPO_INT:
    case TIPO_FLOAT:
      p1.numero=pop_float(pila_exp);
      break;
    case TIPO_TIME:
      p1.hora=pop_time(pila_exp);
      break;
    case TIPO_DATE:
      p1.fecha=pop_date(pila_exp);
      break;
    case TIPO_DATETIME:
      p1.fechahora=pop_datetime(pila_exp);
      break;
    case TIPO_STR:
      p1.cadena=pop_str(pila_exp);
      break;
    default:
      _4GLerror("Operacion no permitida.");
  }
  
  t2=tipo_pila(pila_exp);
  switch (t1)
  {
    case TIPO_INT:
      switch (t2)
      {
        case TIPO_INT:
          p2.numero=pop_int(pila_exp);
          if (p2.numero>p1.numero)
            push_int(pila_exp,p1.numero);
          else
            push_int(pila_exp,p2.numero);
          break;
        case TIPO_STR:
        case TIPO_FLOAT:
          p2.numero=pop_float(pila_exp);
          if (p2.numero>p1.numero)
            push_float(pila_exp,p1.numero);
          else
            push_float(pila_exp,p2.numero);
          break;
        case TIPO_DATE:
          p2.numero=pop_float(pila_exp);
          if (p2.numero>p1.numero)
            push_date(pila_exp,_4GLjulian2date(p1.numero));
          else
            push_date(pila_exp,_4GLjulian2date(p2.numero));
          break;
        default:
          _4GLerror("Operacion no permitida.");
      }
      break;
    case TIPO_FLOAT:
      switch(t2)
      { 
        case TIPO_INT:
        case TIPO_STR:
        case TIPO_FLOAT:
          p2.numero=pop_float(pila_exp);
          if (p2.numero>p1.numero)
            push_float(pila_exp,p1.numero);
          else
            push_float(pila_exp,p2.numero);
          break;
        case TIPO_DATE:
          p2.numero=pop_float(pila_exp);
          if (p2.numero>p1.numero)
            push_date(pila_exp,_4GLjulian2date(p1.numero));
          else
            push_date(pila_exp,_4GLjulian2date(p2.numero));
          break;
        default:
          _4GLerror("Operacion no permitida.");
      }
      break;
    case TIPO_TIME:
      switch(t2)
      {
        case TIPO_STR:
        case TIPO_TIME:
          p2.hora=pop_time(pila_exp);
          if (p2.hora.hour<p1.hora.hour)
            push_time(pila_exp,p2.hora);
          else
          if (p2.hora.hour>p1.hora.hour)
            push_time(pila_exp,p1.hora);
          else
          if (p2.hora.min<p1.hora.min)
            push_time(pila_exp,p2.hora);
          else
          if (p2.hora.min>p1.hora.min)
            push_time(pila_exp,p1.hora);
          else
          if (p2.hora.sec<p1.hora.sec)
            push_time(pila_exp,p2.hora);
          else
          if (p2.hora.sec>p1.hora.sec)
            push_time(pila_exp,p1.hora);
          else
          if (p2.hora.mil<p1.hora.mil)
            push_time(pila_exp,p2.hora);
          else
            push_time(pila_exp,p1.hora);
          break;
        default:
          _4GLerror("Operacion no permitida.");
      }
      break;
    case TIPO_DATE:
      switch(t2)
      {
        _4GLDATETIME aux; /* Variable auxiliar para devolver datetime */
        
        case TIPO_DATETIME:
          memset (&aux,0,sizeof(_4GLDATETIME)); /* Pongo a 0 toda la estructura */
          p2.fechahora=pop_datetime(pila_exp);
          if (p2.fechahora.date.year<p1.fecha.year)
            push_datetime(pila_exp,p2.fechahora);
          else
          if (p2.fechahora.date.year>p1.fecha.year)
          {
            aux.date=p1.fecha;
            push_datetime(pila_exp,aux);
          }
          else
          if (p2.fechahora.date.month<p1.fecha.month)
            push_datetime(pila_exp,p2.fechahora);
          else
          if (p2.fechahora.date.month>p1.fecha.month)
          {
            aux.date=p1.fecha;
            push_datetime(pila_exp,aux);
          }
          else
          if (p2.fechahora.date.day<p1.fecha.day)
            push_datetime(pila_exp,p2.fechahora);
          else
          {
            aux.date=p1.fecha;
            push_datetime(pila_exp,aux);
          }
          break;        
        case TIPO_STR:
        case TIPO_INT:
        case TIPO_FLOAT:
        case TIPO_DATE:
          p2.fecha=pop_date(pila_exp);
          if (p2.fecha.year<p1.fecha.year)
            push_date(pila_exp,p2.fecha);
          else
          if (p2.fecha.year>p1.fecha.year)
            push_date(pila_exp,p1.fecha);
          else
          if (p2.fecha.month<p1.fecha.month)
            push_date(pila_exp,p2.fecha);
          else
          if (p2.fecha.month>p1.fecha.month)
            push_date(pila_exp,p1.fecha);
          else
          if (p2.fecha.day<p1.fecha.day)
            push_date(pila_exp,p2.fecha);
          else
            push_date(pila_exp,p1.fecha);
          break;
        default:
          _4GLerror("Operacion no permitida.");
      }
      break;
    case TIPO_DATETIME:
      switch (t2)
      {
        case TIPO_DATE:
        case TIPO_STR:
        case TIPO_DATETIME:
          p2.fechahora=pop_datetime(pila_exp);
          if (p2.fechahora.date.year<p1.fechahora.date.year)
            push_datetime(pila_exp,p2.fechahora);
          else
          if (p2.fechahora.date.year>p1.fechahora.date.year)
            push_datetime(pila_exp,p1.fechahora);
          else
          if (p2.fechahora.date.month<p1.fechahora.date.month)
            push_datetime(pila_exp,p2.fechahora);
          else
          if (p2.fechahora.date.month>p1.fechahora.date.month)
            push_datetime(pila_exp,p1.fechahora);
          else
          if (p2.fechahora.date.day<p1.fechahora.date.day)
            push_datetime(pila_exp,p2.fechahora);
          else
          if (p2.fechahora.date.day>p1.fechahora.date.day)
            push_datetime(pila_exp,p1.fechahora);
          else
          if (p2.fechahora.time.hour<p1.fechahora.time.hour)
            push_datetime(pila_exp,p2.fechahora);
          else
          if (p2.fechahora.time.hour>p1.fechahora.time.hour)
            push_datetime(pila_exp,p1.fechahora);
          else
          if (p2.fechahora.time.min<p1.fechahora.time.min)
            push_datetime(pila_exp,p2.fechahora);
          else
          if (p2.fechahora.time.min>p1.fechahora.time.min)
            push_datetime(pila_exp,p1.fechahora);
          else
          if (p2.fechahora.time.sec<p1.fechahora.time.sec)
            push_datetime(pila_exp,p2.fechahora);
          else
          if (p2.fechahora.time.sec>p1.fechahora.time.sec)
            push_datetime(pila_exp,p1.fechahora);
          else
          if (p2.fechahora.time.mil<p1.fechahora.time.mil)
            push_datetime(pila_exp,p2.fechahora);
          else
            push_datetime(pila_exp,p1.fechahora);
          break;
        default:
          _4GLerror("Operacion no permitida.");
      }
      break;
    case TIPO_STR:
      switch (t2)
      {
        case TIPO_INT:
        case TIPO_FLOAT:
          p2.numero=pop_float(pila_exp);
          if (p2.numero<atof(p1.cadena))
            push_float(pila_exp,p2.numero);
          else
            push_float(pila_exp,atof(p1.cadena));
          break;
        case TIPO_TIME:
        {
          _4GLTIME aux; /* Variable auxiliar para operaciones */

          memset (&aux,0,sizeof(_4GLTIME)); /* Relleno con 0 la estructura */
          aux=_4GLstr2time(p1.cadena);
          p2.hora=pop_time(pila_exp);
          if (p2.hora.hour<aux.hour)
            push_time(pila_exp,p2.hora);
          else
          if (p2.hora.hour>aux.hour)
            push_time(pila_exp,aux);
          else
          if (p2.hora.min<aux.min)
            push_time(pila_exp,p2.hora);
          else
          if (p2.hora.min>aux.min)
            push_time(pila_exp,aux);
          else
          if (p2.hora.sec<aux.sec)
            push_time(pila_exp,p2.hora);
          else
          if (p2.hora.sec>aux.sec)
            push_time(pila_exp,aux);
          else
          if (p2.hora.mil<aux.mil)
            push_time(pila_exp,p2.hora);
          else
            push_time(pila_exp,aux);
        }
        break;
        case TIPO_DATE:
        {
          _4GLDATE aux;
          
          memset (&aux,0,sizeof(_4GLDATE)); /* Relleno con 0 la estructura */
          aux=_4GLstr2date(p1.cadena);
          p2.fecha=pop_date(pila_exp);
          if (p2.fecha.year<aux.year)
            push_date(pila_exp,p2.fecha);
          else
          if (p2.fecha.year>aux.year)
            push_date(pila_exp,aux);
          else
          if (p2.fecha.month<aux.month)
            push_date(pila_exp,p2.fecha);
          else
          if (p2.fecha.month>aux.month)
            push_date(pila_exp,aux);
          else
          if (p2.fecha.day<aux.day)
            push_date(pila_exp,p2.fecha);
          else
            push_date(pila_exp,aux);
        }
        break;
        case TIPO_DATETIME:
        {
          _4GLDATETIME aux;
          
          memset (&aux,0,sizeof(_4GLDATETIME)); /* Relleno con 0 la estructura */
          aux=_4GLstr2datetime(p1.cadena);
          p2.fechahora=pop_datetime(pila_exp);
          if (p2.fechahora.date.year<aux.date.year)
            push_datetime(pila_exp,p2.fechahora);
          else
          if (p2.fechahora.date.year>aux.date.year)
            push_datetime(pila_exp,aux);
          else
          if (p2.fechahora.date.month<aux.date.month)
            push_datetime(pila_exp,p2.fechahora);
          else
          if (p2.fechahora.date.month>aux.date.month)
            push_datetime(pila_exp,aux);
          else
          if (p2.fechahora.date.day<aux.date.day)
            push_datetime(pila_exp,p2.fechahora);
          else
          if (p2.fechahora.date.day>aux.date.day)
            push_datetime(pila_exp,aux);
          else
          if (p2.fechahora.time.hour<aux.time.hour)
            push_datetime(pila_exp,p2.fechahora);
          else
          if (p2.fechahora.time.hour>aux.time.hour)
            push_datetime(pila_exp,aux);
          else
          if (p2.fechahora.time.min<aux.time.min)
            push_datetime(pila_exp,p2.fechahora);
          else
          if (p2.fechahora.time.min>aux.time.min)
            push_datetime(pila_exp,aux);
          else
          if (p2.fechahora.time.sec<aux.time.sec)
            push_datetime(pila_exp,p2.fechahora);
          else
          if (p2.fechahora.time.sec>aux.time.sec)
            push_datetime(pila_exp,aux);
          else
          if (p2.fechahora.time.mil<aux.time.mil)
            push_datetime(pila_exp,p2.fechahora);
          else
            push_datetime(pila_exp,aux);
        }
        break;
        case TIPO_STR:
        {
          int res;
          
          p2.cadena=pop_str(pila_exp);
          res=strcmp(p1.cadena,p2.cadena);
          if (res<0)
            push_str(pila_exp,p1.cadena);
          else
            push_str(pila_exp,p2.cadena);
        }  
        break;
        default:
          _4GLerror("Operacion no permitida.");
      }
      break;
    default:
      _4GLerror("Operacion no permitida.");
  }
}

void _Fn_max ()
{
  union
  {
    char *cadena;
    double numero;
    _4GLTIME hora;
    _4GLDATE fecha;
    _4GLDATETIME fechahora;
  }p1, p2;
  
  enum tipos t1, t2;
  
  t1=tipo_pila(pila_exp);
  
  switch(t1)
  {
    case TIPO_INT:
    case TIPO_FLOAT:
      p1.numero=pop_float(pila_exp);
      break;
    case TIPO_TIME:
      p1.hora=pop_time(pila_exp);
      break;
    case TIPO_DATE:
      p1.fecha=pop_date(pila_exp);
      break;
    case TIPO_DATETIME:
      p1.fechahora=pop_datetime(pila_exp);
      break;
    case TIPO_STR:
      p1.cadena=pop_str(pila_exp);
      break;
    default:
      _4GLerror("Operacion no permitida.");
  }
  
  t2=tipo_pila(pila_exp);
  switch (t1)
  {
    case TIPO_INT:
      switch (t2)
      {
        case TIPO_INT:
          p2.numero=pop_int(pila_exp);
          if (p2.numero<p1.numero)
            push_int(pila_exp,p1.numero);
          else
            push_int(pila_exp,p2.numero);
          break;
        case TIPO_STR:
        case TIPO_FLOAT:
          p2.numero=pop_float(pila_exp);
          if (p2.numero<p1.numero)
            push_float(pila_exp,p1.numero);
          else
            push_float(pila_exp,p2.numero);
          break;
        case TIPO_DATE:
          p2.numero=pop_float(pila_exp);
          if (p2.numero<p1.numero)
            push_date(pila_exp,_4GLjulian2date(p1.numero));
          else
            push_date(pila_exp,_4GLjulian2date(p2.numero));
          break;
        default:
          _4GLerror("Operacion no permitida.");
      }
      break;
    case TIPO_FLOAT:
      switch(t2)
      { 
        case TIPO_INT:
        case TIPO_STR:
        case TIPO_FLOAT:
          p2.numero=pop_float(pila_exp);
          if (p2.numero<p1.numero)
            push_float(pila_exp,p1.numero);
          else
            push_float(pila_exp,p2.numero);
          break;
        case TIPO_DATE:
          p2.numero=pop_float(pila_exp);
          if (p2.numero<p1.numero)
            push_date(pila_exp,_4GLjulian2date(p1.numero));
          else
            push_date(pila_exp,_4GLjulian2date(p2.numero));
          break;
        default:
          _4GLerror("Operacion no permitida.");
      }
      break;
    case TIPO_TIME:
      switch(t2)
      {
        case TIPO_STR:
        case TIPO_TIME:
          p2.hora=pop_time(pila_exp);
          if (p2.hora.hour>p1.hora.hour)
            push_time(pila_exp,p2.hora);
          else
          if (p2.hora.hour<p1.hora.hour)
            push_time(pila_exp,p1.hora);
          else
          if (p2.hora.min>p1.hora.min)
            push_time(pila_exp,p2.hora);
          else
          if (p2.hora.min<p1.hora.min)
            push_time(pila_exp,p1.hora);
          else
          if (p2.hora.sec>p1.hora.sec)
            push_time(pila_exp,p2.hora);
          else
          if (p2.hora.sec<p1.hora.sec)
            push_time(pila_exp,p1.hora);
          else
          if (p2.hora.mil<p1.hora.mil)
            push_time(pila_exp,p2.hora);
          else
            push_time(pila_exp,p1.hora);
          break;
        default:
          _4GLerror("Operacion no permitida.");
      }
      break;
    case TIPO_DATE:
      switch(t2)
      {
        _4GLDATETIME aux; /* Variable auxiliar para devolver datetime */
        
        case TIPO_DATETIME:
          memset (&aux,0,sizeof(_4GLDATETIME)); /* Pongo a 0 toda la estructura */
          p2.fechahora=pop_datetime(pila_exp);
          if (p2.fechahora.date.year>p1.fecha.year)
            push_datetime(pila_exp,p2.fechahora);
          else
          if (p2.fechahora.date.year<p1.fecha.year)
          {
            aux.date=p1.fecha;
            push_datetime(pila_exp,aux);
          }
          else
          if (p2.fechahora.date.month>p1.fecha.month)
            push_datetime(pila_exp,p2.fechahora);
          else
          if (p2.fechahora.date.month<p1.fecha.month)
          {
            aux.date=p1.fecha;
            push_datetime(pila_exp,aux);
          }
          else
          if (p2.fechahora.date.day>p1.fecha.day)
            push_datetime(pila_exp,p2.fechahora);
          else
          {
            aux.date=p1.fecha;
            push_datetime(pila_exp,aux);
          }
          break;        
        case TIPO_STR:
        case TIPO_INT:
        case TIPO_FLOAT:
        case TIPO_DATE:
          p2.fecha=pop_date(pila_exp);
          if (p2.fecha.year>p1.fecha.year)
            push_date(pila_exp,p2.fecha);
          else
          if (p2.fecha.year<p1.fecha.year)
            push_date(pila_exp,p1.fecha);
          else
          if (p2.fecha.month>p1.fecha.month)
            push_date(pila_exp,p2.fecha);
          else
          if (p2.fecha.month<p1.fecha.month)
            push_date(pila_exp,p1.fecha);
          else
          if (p2.fecha.day>p1.fecha.day)
            push_date(pila_exp,p2.fecha);
          else
            push_date(pila_exp,p1.fecha);
          break;
        default:
          _4GLerror("Operacion no permitida.");
      }
      break;
    case TIPO_DATETIME:
      switch (t2)
      {
        case TIPO_DATE:
        case TIPO_STR:
        case TIPO_DATETIME:
          p2.fechahora=pop_datetime(pila_exp);
          if (p2.fechahora.date.year>p1.fechahora.date.year)
            push_datetime(pila_exp,p2.fechahora);
          else
          if (p2.fechahora.date.year<p1.fechahora.date.year)
            push_datetime(pila_exp,p1.fechahora);
          else
          if (p2.fechahora.date.month>p1.fechahora.date.month)
            push_datetime(pila_exp,p2.fechahora);
          else
          if (p2.fechahora.date.month<p1.fechahora.date.month)
            push_datetime(pila_exp,p1.fechahora);
          else
          if (p2.fechahora.date.day>p1.fechahora.date.day)
            push_datetime(pila_exp,p2.fechahora);
          else
          if (p2.fechahora.date.day<p1.fechahora.date.day)
            push_datetime(pila_exp,p1.fechahora);
          else
          if (p2.fechahora.time.hour>p1.fechahora.time.hour)
            push_datetime(pila_exp,p2.fechahora);
          else
          if (p2.fechahora.time.hour<p1.fechahora.time.hour)
            push_datetime(pila_exp,p1.fechahora);
          else
          if (p2.fechahora.time.min>p1.fechahora.time.min)
            push_datetime(pila_exp,p2.fechahora);
          else
          if (p2.fechahora.time.min<p1.fechahora.time.min)
            push_datetime(pila_exp,p1.fechahora);
          else
          if (p2.fechahora.time.sec>p1.fechahora.time.sec)
            push_datetime(pila_exp,p2.fechahora);
          else
          if (p2.fechahora.time.sec<p1.fechahora.time.sec)
            push_datetime(pila_exp,p1.fechahora);
          else
          if (p2.fechahora.time.mil>p1.fechahora.time.mil)
            push_datetime(pila_exp,p2.fechahora);
          else
            push_datetime(pila_exp,p1.fechahora);
          break;
        default:
          _4GLerror("Operacion no permitida.");
      }
      break;
    case TIPO_STR:
      switch (t2)
      {
        case TIPO_INT:
        case TIPO_FLOAT:
          p2.numero=pop_float(pila_exp);
          if (p2.numero>atof(p1.cadena))
            push_float(pila_exp,p2.numero);
          else
            push_float(pila_exp,atof(p1.cadena));
          break;
        case TIPO_TIME:
        {
          _4GLTIME aux; /* Variable auxiliar para operaciones */

          memset (&aux,0,sizeof(_4GLTIME)); /* Relleno con 0 la estructura */
          aux=_4GLstr2time(p1.cadena);
          p2.hora=pop_time(pila_exp);
          if (p2.hora.hour>aux.hour)
            push_time(pila_exp,p2.hora);
          else
          if (p2.hora.hour<aux.hour)
            push_time(pila_exp,aux);
          else
          if (p2.hora.min>aux.min)
            push_time(pila_exp,p2.hora);
          else
          if (p2.hora.min<aux.min)
            push_time(pila_exp,aux);
          else
          if (p2.hora.sec>aux.sec)
            push_time(pila_exp,p2.hora);
          else
          if (p2.hora.sec<aux.sec)
            push_time(pila_exp,aux);
          else
          if (p2.hora.mil>aux.mil)
            push_time(pila_exp,p2.hora);
          else
            push_time(pila_exp,aux);
        }
        break;
        case TIPO_DATE:
        {
          _4GLDATE aux;
          
          memset (&aux,0,sizeof(_4GLDATE)); /* Relleno con 0 la estructura */
          aux=_4GLstr2date(p1.cadena);
          p2.fecha=pop_date(pila_exp);
          if (p2.fecha.year>aux.year)
            push_date(pila_exp,p2.fecha);
          else
          if (p2.fecha.year<aux.year)
            push_date(pila_exp,aux);
          else
          if (p2.fecha.month>aux.month)
            push_date(pila_exp,p2.fecha);
          else
          if (p2.fecha.month<aux.month)
            push_date(pila_exp,aux);
          else
          if (p2.fecha.day>aux.day)
            push_date(pila_exp,p2.fecha);
          else
            push_date(pila_exp,aux);
        }
        break;
        case TIPO_DATETIME:
        {
          _4GLDATETIME aux;
          
          memset (&aux,0,sizeof(_4GLDATETIME)); /* Relleno con 0 la estructura */
          aux=_4GLstr2datetime(p1.cadena);
          p2.fechahora=pop_datetime(pila_exp);
          if (p2.fechahora.date.year>aux.date.year)
            push_datetime(pila_exp,p2.fechahora);
          else
          if (p2.fechahora.date.year<aux.date.year)
            push_datetime(pila_exp,aux);
          else
          if (p2.fechahora.date.month>aux.date.month)
            push_datetime(pila_exp,p2.fechahora);
          else
          if (p2.fechahora.date.month<aux.date.month)
            push_datetime(pila_exp,aux);
          else
          if (p2.fechahora.date.day>aux.date.day)
            push_datetime(pila_exp,p2.fechahora);
          else
          if (p2.fechahora.date.day<aux.date.day)
            push_datetime(pila_exp,aux);
          else
          if (p2.fechahora.time.hour>aux.time.hour)
            push_datetime(pila_exp,p2.fechahora);
          else
          if (p2.fechahora.time.hour<aux.time.hour)
            push_datetime(pila_exp,aux);
          else
          if (p2.fechahora.time.min>aux.time.min)
            push_datetime(pila_exp,p2.fechahora);
          else
          if (p2.fechahora.time.min<aux.time.min)
            push_datetime(pila_exp,aux);
          else
          if (p2.fechahora.time.sec>aux.time.sec)
            push_datetime(pila_exp,p2.fechahora);
          else
          if (p2.fechahora.time.sec<aux.time.sec)
            push_datetime(pila_exp,aux);
          else
          if (p2.fechahora.time.mil>aux.time.mil)
            push_datetime(pila_exp,p2.fechahora);
          else
            push_datetime(pila_exp,aux);
        }
        break;
        case TIPO_STR:
        {
          int res;
          
          p2.cadena=pop_str(pila_exp);
          res=strcmp(p1.cadena,p2.cadena);
          if (res<0)
            push_str(pila_exp,p2.cadena);
          else
            push_str(pila_exp,p1.cadena);
        }  
        break;
        default:
          _4GLerror("Operacion no permitida.");
      }
      break;
    default:
      _4GLerror("Operacion no permitida.");
  }
}

/* Devuelve la parte entera del numero que se le pasa como parametro */
void _Fn_int()
{
   push_int(pila_exp,pop_int(pila_exp));
}

void _Fn_round()
{
   long decimales;
   double numero;
   decimales=pop_int(pila_exp);
   numero=pop_float(pila_exp);
   numero=(long)((numero)*(pow(10,decimales))+.5);
   numero=numero/(pow(10,decimales));
   push_float(pila_exp,numero);
}
