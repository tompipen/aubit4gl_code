/*************************************************************
 * Funciones de manejo de las pilas en tiempo de ejecucion.
 *************************************************************/
#include <hy4gl.h>
#include <stdlib.h>
#include <malloc.h>

pila *nueva_pila()
{
   pila *nuevo;
   nuevo=(pila *)malloc(sizeof(pila));
   nuevo->tipo=TIPO_VOID;
   nuevo->valor.cadena=(char *)NULL;
   nuevo->siguiente=NULL;
   return nuevo;
}

bool pila_vacia(pila *p)
{
   if (p->siguiente==NULL)
      return TRUE;
   else
      return FALSE;
}

void push_int(pila *p, long n)
{
   pila *nuevo;
   nuevo=(pila *) malloc (sizeof(pila));
   if (nuevo==NULL)
      _4GLerror("Sin memoria para la pila.");
   nuevo->tipo=TIPO_INT;
   nuevo->valor.entero=n;
   nuevo->siguiente=p->siguiente;
   p->siguiente=nuevo;
} 

void push_float(pila *p, double n)
{
   pila *nuevo;
   nuevo=(pila *) malloc (sizeof(pila));
   if (nuevo==NULL)
      _4GLerror("Sin memoria para la pila.");
   nuevo->tipo=TIPO_FLOAT;
   nuevo->valor.real=n;
   nuevo->siguiente=p->siguiente;
   p->siguiente=nuevo;
} 

void push_str(pila *p, char *s)
{
   pila *nuevo;
   int tam;
   nuevo=(pila *) malloc (sizeof (pila));
   if (nuevo==NULL)
      _4GLerror("Sin memoria para la pila.");
   nuevo->tipo=TIPO_STR;
   tam=strlen(s);
   nuevo->valor.cadena=(char *)malloc(tam+1);
   if (nuevo->valor.cadena==NULL)
      _4GLerror("Sin memoria para la pila.");
   bzero(nuevo->valor.cadena,tam+1);
   strncpy(nuevo->valor.cadena,s,tam);
   nuevo->siguiente=p->siguiente;
   p->siguiente=nuevo;
} 

void push_date(pila *p, _4GLDATE f)
{
   pila *nuevo;
   nuevo=(pila *) malloc (sizeof (pila));
   if (nuevo==NULL)
      _4GLerror("Sin memoria para la pila.");
   nuevo->tipo=TIPO_DATE;
   nuevo->valor.fecha=f;
   nuevo->siguiente=p->siguiente;
   p->siguiente=nuevo;
} 

void push_time(pila *p, _4GLTIME t)
{
   pila *nuevo;
   nuevo=(pila *) malloc (sizeof (pila));
   if (nuevo==NULL)
      _4GLerror("Sin memoria para la pila.");
   nuevo->tipo=TIPO_TIME;
   nuevo->valor.time=t;
   nuevo->siguiente=p->siguiente;
   p->siguiente=nuevo;
} 


void push_datetime(pila *p, _4GLDATETIME dt)
{
   pila *nuevo;
   nuevo=(pila *) malloc (sizeof (pila));
   if (nuevo==NULL)
      _4GLerror("Sin memoria para la pila.");
   nuevo->tipo=TIPO_DATETIME;
   nuevo->valor.datetime=dt;
   nuevo->siguiente=p->siguiente;
   p->siguiente=nuevo;
} 

void push_interval(pila *p, _4GLINTERVAL i)
{
   pila *nuevo;
   nuevo=(pila *) malloc (sizeof (pila));
   if (nuevo==NULL)
      _4GLerror("Sin memoria para la pila.");
   nuevo->tipo=TIPO_INTERVAL;
   nuevo->valor.interval=i;
   nuevo->siguiente=p->siguiente;
   p->siguiente=nuevo;
} 

long pop_int(pila *p)
{
   pila *ptr;
   long res;
   
   ptr=p->siguiente;
   if (ptr==NULL)
      _4GLerror("Se ha sobrepasado la pila vacía");
   switch (ptr->tipo)
   {
      case TIPO_INT:
         res=ptr->valor.entero;
         break;
      case TIPO_FLOAT:
         res=ptr->valor.real;
         break;
      case TIPO_STR:
         res=atol(ptr->valor.cadena);
         break;
      case TIPO_DATE:
         res=_4GLdate2julian(ptr->valor.fecha);
         break;
      case TIPO_DATETIME:
         res=_4GLdate2julian(ptr->valor.datetime.date)*24*3600+
            _4GLtime2sec(ptr->valor.datetime.time);
         break;
      case TIPO_TIME:
         res=_4GLtime2sec(ptr->valor.time);
         break;
      case TIPO_INTERVAL:
         res=ptr->valor.interval.hours*3600+
            ptr->valor.interval.mins*60+
            ptr->valor.interval.secs;
         break;
   }
   p->siguiente=ptr->siguiente;
   free(ptr);
   return res;
}

double pop_float(pila *p)
{
   pila *ptr;
   double res;
   
   ptr=p->siguiente;
   if (ptr==NULL)
      _4GLerror("Se ha sobrepasado la pila vacía");
   switch (ptr->tipo)
   {
      case TIPO_FLOAT:
         res=ptr->valor.real;
         break;
      case TIPO_INT:
         res=ptr->valor.entero;
         break;
      case TIPO_STR:
         res=atof(ptr->valor.cadena);
         break;
      case TIPO_DATE:
         res=_4GLdate2julian(ptr->valor.fecha);
         break;
      case TIPO_DATETIME:
         res=_4GLdate2julian(ptr->valor.datetime.date)*24*3600+
            _4GLtime2sec(ptr->valor.datetime.time);
         break;
      case TIPO_TIME:
         res=_4GLtime2sec(ptr->valor.time);
         break;
      case TIPO_INTERVAL:
         res=ptr->valor.interval.hours*3600+
            ptr->valor.interval.mins*60+
            ptr->valor.interval.secs;
         break;
   }
   p->siguiente=ptr->siguiente;
   free(ptr);
   return res;
}

char *pop_str(pila *p)
{
   pila *ptr;
   char *res;
   
   ptr=p->siguiente;
   if (ptr==NULL)
      _4GLerror("Se ha sobrepasado la pila vacía");
   switch (ptr->tipo)
   {
      case TIPO_INT:
         res=_4GLint2str(ptr->valor.entero);
         break;
      case TIPO_FLOAT:
         res=_4GLfloat2str(ptr->valor.real);
         break;
      case TIPO_STR:
         res=ptr->valor.cadena;
         break;
      case TIPO_DATE:
         res=_4GLdate2str(ptr->valor.fecha);
         break;
      case TIPO_TIME:
         res=_4GLtime2str(ptr->valor.time);
         break;
      case TIPO_DATETIME:
         res=_4GLdatetime2str(ptr->valor.datetime);
         break;
      case TIPO_INTERVAL:
         res=_4GLinterval2str(ptr->valor.interval);
         break;
   }
   p->siguiente=ptr->siguiente;
   free(ptr);
   return res;
}

_4GLDATE pop_date(pila *p)
{
   pila *ptr;
   _4GLDATE res;
   
   ptr=p->siguiente;
   if (ptr==NULL)
      _4GLerror("Se ha sobrepasado la pila vacía");
   switch (ptr->tipo)
   {
      case TIPO_INT:
         res=_4GLjulian2date(ptr->valor.entero);
         break;
      case TIPO_FLOAT:
         res=_4GLjulian2date((long)(ptr->valor.real));
         break;
      case TIPO_STR:
         res=_4GLstr2date(ptr->valor.cadena);
         break;
      case TIPO_DATE:
         res=ptr->valor.fecha;
         break;
      case TIPO_DATETIME:
         res=ptr->valor.datetime.date;
         break;
      default:
         _4GLerror("No se puede convertir el tipo a DATE");
         break;
   }
   p->siguiente=ptr->siguiente;
   free(ptr);
   return res;
}

_4GLTIME pop_time(pila *p)
{
   pila *ptr;
   _4GLTIME res;
   
   ptr=p->siguiente;
   if (ptr==NULL)
      _4GLerror("Se ha sobrepasado la pila vacía");
   switch (ptr->tipo)
   {
      case TIPO_STR:
         res=_4GLstr2time(ptr->valor.cadena);
         break;
      case TIPO_TIME:
         res=ptr->valor.time;
         break;
      case TIPO_DATETIME:
         res=ptr->valor.datetime.time;
         break;
      default:
         _4GLerror ("No se puede convertir el tipo a TIME");
         break;
   }
   p->siguiente=ptr->siguiente;
   free(ptr);
   return res;
}

_4GLDATETIME pop_datetime(pila *p)
{
   pila *ptr;
   _4GLDATETIME res;
   
   ptr=p->siguiente;
   if (ptr==NULL)
      _4GLerror("Se ha sobrepasado la pila vacía");
   switch (ptr->tipo)
   {
      case TIPO_STR:
         res=_4GLstr2datetime(ptr->valor.cadena);
         break;
      case TIPO_DATETIME:
         res=ptr->valor.datetime;
         break;
      case TIPO_DATE:
         res.date=ptr->valor.fecha;
         res.time.hour=0;
         res.time.min=0;
         res.time.sec=0;
         res.time.mil=0;
         break;
      case TIPO_TIME:
         res.time=ptr->valor.time;
         res.date.day=1;
         res.date.month=1;
         res.date.year=0;
         break;
      default:
         _4GLerror("No se puede convertir el tipo a DATETIME");
         break;
   }
   p->siguiente=ptr->siguiente;
   free(ptr);
   return res;
}

_4GLINTERVAL pop_interval(pila *p)
{
   pila *ptr;
   _4GLINTERVAL res;
   long num;
   
   ptr=p->siguiente;
   if (ptr==NULL)
      _4GLerror("Se ha sobrepasado la pila vacía");
   switch (ptr->tipo)
   {
      case TIPO_STR:
         res=_4GLstr2interval(ptr->valor.cadena);
         break;
      case TIPO_INTERVAL:
         res=ptr->valor.interval;
         break;
      case TIPO_INT:
         num=ptr->valor.entero;
         res.hours=num/3600;
         num=num%3600;
         res.mins=num/60;
         num=num%60;
         res.secs=num;
         break;
      case TIPO_FLOAT: /* convierto segundos a interval */
         num=ptr->valor.real;
         res.hours=num/3600;
         num=num%3600;
         res.mins=num/60;
         num=num%60;
         res.secs=num;
         break;
      default:
         _4GLerror("No se puede convertir el tipo a INTERVAL");
         break;
   }
   p->siguiente=ptr->siguiente;
   free(ptr);
   return res;
}


enum tipos tipo_pila(pila *p)
{
   return (p->siguiente)->tipo;
}

void op_suma(pila *pila_exp)
{
   char *tmp;
   union
   {
      char *cadena;
      float numero;
      _4GLDATE fecha;
      _4GLTIME time;
      _4GLDATETIME dt;
      _4GLINTERVAL inter;
   }p1, p2;
   enum tipos t1,t2;

   t1=tipo_pila(pila_exp);
   
   switch(t1)
   {
      case TIPO_INT:
      case TIPO_FLOAT:
         p1.numero=pop_float(pila_exp);
         break;
      case TIPO_STR:
         p1.cadena=pop_str(pila_exp);
         break;
      case TIPO_DATE:
         p1.fecha=pop_date(pila_exp);
         break;
      case TIPO_DATETIME:
         p1.dt=pop_datetime(pila_exp);
         break;
      case TIPO_TIME:
         p1.time=pop_time(pila_exp);
         break;
      case TIPO_INTERVAL:
         p1.inter=pop_interval(pila_exp);
         break;
      default:
         _4GLerror("Operacion no permitida.");
   }   

   t2=tipo_pila(pila_exp);
   switch(t1)
   {
      case TIPO_INT:
         switch (t2)
         {
            case TIPO_INT: /* num+num = num */
               p2.numero=pop_int(pila_exp);
               push_int(pila_exp,p1.numero+p2.numero);
               break;
            case TIPO_FLOAT:
               p2.numero=pop_float(pila_exp);
               push_float(pila_exp,p1.numero+p2.numero);
               break;
            case TIPO_STR: /* num+str = str */
               p2.cadena=pop_str(pila_exp);
               tmp=(char *)malloc(strlen(p2.cadena)+25);
               sprintf(tmp,"%ld%s",(long)p1.numero,p2.cadena);
               push_str(pila_exp,tmp);
               free(tmp);
               break;
            case TIPO_DATE: /* num + date = date */
               p2.fecha=pop_date(pila_exp);
               p1.numero+=_4GLdate2julian(p2.fecha);
               push_date(pila_exp,_4GLjulian2date(p1.numero));
               break;
            case TIPO_TIME: /* num + time = time */
               p2.time=pop_time(pila_exp);
               p1.numero+=_4GLtime2sec(p2.time);
               p1.numero=((long)p1.numero)%(24*3600);
               push_time(pila_exp,_4GLsec2time(p1.numero));
               break;
            case TIPO_INTERVAL: /* num + interval = interval */
               p2.inter=pop_interval(pila_exp);
               p1.numero+=_4GLinterval2sec(p2.inter);
               push_interval(pila_exp,_4GLsec2interval(p1.numero));
               break;
            case TIPO_DATETIME: /* num + datetime = datetime */
               /* Lo transformo a datetime+num */
               p2.dt=pop_datetime(pila_exp);
               push_int(pila_exp,p1.numero);
               push_datetime(pila_exp,p2.dt);
               op_suma(pila_exp);
               break;
            default: 
               _4GLerror("Operacion no permitida. (%d + %s)",p1.numero,pop_str(pila_exp));
         }
         break;
      case TIPO_FLOAT:
         switch (t2)
         {
         	case TIPO_INT: /* num+num = num */
               p2.numero=pop_int(pila_exp);
               push_float(pila_exp,p1.numero+p2.numero);
               break;
            case TIPO_FLOAT:
               p2.numero=pop_float(pila_exp);
               push_float(pila_exp,p1.numero+p2.numero);
               break;
         	case TIPO_STR: /* num+str = str */
               p2.cadena=pop_str(pila_exp);
               tmp=(char *)malloc(strlen(p2.cadena)+25);
               sprintf(tmp,"%f%s",p1.numero,p2.cadena);
               push_str(pila_exp,tmp);
               free(tmp);
               break;
            case TIPO_DATE: /* num + date = date */
               p2.fecha=pop_date(pila_exp);
               p1.numero+=_4GLdate2julian(p2.fecha);
               push_date(pila_exp,_4GLjulian2date(p1.numero));
               break;
            case TIPO_TIME: /* num + time = time */
               p2.time=pop_time(pila_exp);
               p1.numero+=_4GLtime2sec(p2.time);
               p1.numero=((long)p1.numero)%(24*3600);
               push_time(pila_exp,_4GLsec2time(p1.numero));
               break;
            case TIPO_INTERVAL: /* num + interval = interval */
               p2.inter=pop_interval(pila_exp);
               p1.numero+=_4GLinterval2sec(p2.inter);
               push_interval(pila_exp,_4GLsec2interval(p1.numero));
               break;
            case TIPO_DATETIME: /* num + datetime = datetime */
               /* Lo transformo a datetime+num */
               p2.dt=pop_datetime(pila_exp);
               push_int(pila_exp,p1.numero);
               push_datetime(pila_exp,p2.dt);
               op_suma(pila_exp);
               break;
            default: 
               _4GLerror("Operacion no permitida. (%d + %s)",p1.numero,pop_str(pila_exp));
         }
         break;
      case TIPO_STR:
         switch (t2)
         {
            case TIPO_INT:  /* str + x = str */
            case TIPO_FLOAT:
            case TIPO_STR:
            case TIPO_DATE:
            case TIPO_DATETIME:
            case TIPO_TIME:
            case TIPO_INTERVAL:
               p2.cadena=pop_str(pila_exp);
               push_str(pila_exp,_4GLstrcat(p1.cadena,p2.cadena));
               break;
            default:
               _4GLerror("Operacion no permitida.");
         }
         break;
      case TIPO_DATE:
         switch(t2)
         {
            case TIPO_INT: /* date + num = date */
            case TIPO_FLOAT:
               p2.numero=pop_int(pila_exp);
               p2.numero+=_4GLdate2julian(p1.fecha);
               push_date(pila_exp,_4GLjulian2date(p2.numero));
               break;
         	case TIPO_STR: /* date + str = str */
               p2.cadena=pop_str(pila_exp);
               push_str(pila_exp,_4GLstrcat(_4GLdate2str(p1.fecha),p2.cadena));
               break;
            case TIPO_TIME: /* date + time = datetime, esta claro, no? */
               p2.time=pop_time(pila_exp);
               p1.dt.date=p1.fecha;
               p1.dt.time=p2.time;
               push_datetime(pila_exp,p1.dt);
               break;
            default:
               _4GLerror("Operacion no permitida.");
         }
         break;
      case TIPO_TIME:
         switch(t2)
         {
         	case TIPO_STR: /* time+str=str */
               p2.cadena=pop_str(pila_exp);
               push_str(pila_exp,_4GLstrcat(_4GLtime2str(p1.time),p2.cadena));
               break;
            case TIPO_INT:
            case TIPO_FLOAT:
            case TIPO_INTERVAL:
               p2.numero=pop_int(pila_exp);
               p1.numero=_4GLtime2sec(p1.time);
               p1.numero+=p2.numero;
               p1.numero=((long)p1.numero)%(24*3600);
               push_time(pila_exp,_4GLsec2time(p1.numero));
               break;
            case TIPO_DATE:
               p2.dt.date=pop_date(pila_exp);
               p2.dt.time=p1.time;
               push_datetime(pila_exp,p2.dt);
               break;
            default:
               _4GLerror("Operacion no permitida.");
         
         }
         break;
      case TIPO_INTERVAL:
         switch(t2)
         {
         	case TIPO_STR: /* interval+str=str */
               p2.cadena=pop_str(pila_exp);
               push_str(pila_exp,_4GLstrcat(_4GLinterval2str(p1.inter),p2.cadena));
               break;
            case TIPO_INT:
            case TIPO_FLOAT:
            case TIPO_INTERVAL:
               p2.numero=pop_int(pila_exp);
               p1.numero=_4GLinterval2sec(p1.inter);
               p1.numero+=p2.numero;
               push_interval(pila_exp,_4GLsec2interval(p1.numero));
               break;
            case TIPO_TIME:
               p2.numero=pop_int(pila_exp);
               p1.numero=_4GLinterval2sec(p1.inter);
               p1.numero+=p2.numero;
               p1.numero=((long)p1.numero)%(24*3600);
               push_time(pila_exp,_4GLsec2time(p1.numero));
               break;
            case TIPO_DATETIME: /*interval+datetime = datetime+interval */
               p2.dt=pop_datetime(pila_exp);
               push_interval(pila_exp,p1.inter);
               push_datetime(pila_exp,p2.dt);
               op_suma(pila_exp);
               break;
            default:
               _4GLerror("Operacion no permitida.");
         
         }
         break;
      case TIPO_DATETIME:
         switch(t2)
         {
         	case TIPO_STR:
               p2.cadena=pop_str(pila_exp);
               push_str(pila_exp,_4GLstrcat(_4GLdatetime2str(p1.dt),p2.cadena));
               free(p2.cadena);
               break;
            case TIPO_INT:      /* datetime + num = datetime (sumo segundos) */
            case TIPO_FLOAT:
            case TIPO_INTERVAL: /* el interval lo convierto a segundos */
               p2.numero=pop_int(pila_exp); 
               if (p2.numero<0)	/* numero negativo -> restar */
               {
               		long hora,diajul;
                    hora=_4GLtime2sec(p1.dt.time);
                    diajul=_4GLdate2julian(p1.dt.date);
                    p2.numero=-1*p2.numero;
                    /* Miro si me quedo dentro del mismo dia */
                    if (p2.numero < hora)
                    {
                    	p1.dt.time=_4GLsec2time(hora-p2.numero);
                        push_datetime(pila_exp,p1.dt);
                    }
                    else /* Resto más de la hora actual */
                    {
                    	/* Resto hasta las 00:00:00 */
                        p1.dt.time.hour=23;
                        p1.dt.time.min=59;
                        p1.dt.time.sec=59;
                        p1.dt.time.mil=0;
                        diajul--;
                        p2.numero-=(hora+1);
                        
                        hora=(24*3600)-1;
                        p1.dt.date=_4GLjulian2date(diajul-(long)(p2.numero/(24*3600)));
                        p1.dt.time=_4GLsec2time(hora-((long)p2.numero)%(24*3600));
                        push_datetime(pila_exp,p1.dt);
                    }
               }
               else /* numero positivo */
               {
               		long hora,diajul;
                    hora=_4GLtime2sec(p1.dt.time);
                    diajul=_4GLdate2julian(p1.dt.date);
                    /* Miro si me quedo dentro del mismo dia */
                    if (hora+p2.numero < (24*3600))
                    {
                    	p1.dt.time=_4GLsec2time(hora+p2.numero);
                        push_datetime(pila_exp,p1.dt);
                    }
                    else /* pasamos del dia actual */
                    {
                    	/* Resto hasta las 00:00:00 */
                        p1.dt.time.hour=0;
                        p1.dt.time.min=0;
                        p1.dt.time.sec=0;
                        p1.dt.time.mil=0;
                        diajul++;
                        p2.numero-=(24*3600)-hora;
                        
                        hora=0;
                        p1.dt.date=_4GLjulian2date(diajul+(long)(p2.numero/(24*3600)));
                        p1.dt.time=_4GLsec2time(((long)p2.numero)%(24*3600));
                        push_datetime(pila_exp,p1.dt);
                    }
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

void op_resta(pila *pila_exp)
{
   union
   {
      char *cadena;
      double numero;
      _4GLDATE fecha;
      _4GLDATETIME dt;
      _4GLTIME time;
      _4GLINTERVAL inter;
   }p1, p2;
   enum tipos t1,t2;

   t1=tipo_pila(pila_exp);
   
   switch(t1)
   {
      case TIPO_INT:
         p1.numero=pop_int(pila_exp);
         break;
      case TIPO_FLOAT:
         p1.numero=pop_float(pila_exp);
         break;
      case TIPO_STR:
         p1.cadena=pop_str(pila_exp);
         break;
      case TIPO_DATE:
         p1.fecha=pop_date(pila_exp);
         break;
      case TIPO_DATETIME:
         p1.dt=pop_datetime(pila_exp);
         break;
      case TIPO_TIME:
         p1.time=pop_time(pila_exp);
         break;
      case TIPO_INTERVAL:
         p1.inter=pop_interval(pila_exp);
         break;
      default:
         _4GLerror("Operacion no permitida.");
         break;
   }   

   t2=tipo_pila(pila_exp);
   switch(t1)
   {
      case TIPO_INT:
         switch (t2)
         {
         	case TIPO_INT: /* num-num = num */
               p2.numero=pop_int(pila_exp);
               push_int(pila_exp,p1.numero-p2.numero);
               break;
         	case TIPO_FLOAT: /* num-num = num */
               p2.numero=pop_float(pila_exp);
               push_float(pila_exp,p1.numero-p2.numero);
               break;
         	case TIPO_STR: /* num-str = num */
               p2.numero=pop_float(pila_exp);
               push_float(pila_exp,p1.numero-p2.numero);
               break;
            default:	/* num-x = error */
               _4GLerror("Operacion no permitida.");
         }
         break;
      case TIPO_FLOAT: /* float - loquesea */
         switch (t2)
         {
         	case TIPO_INT: /* num-num = num */
               p2.numero=pop_int(pila_exp);
               push_float(pila_exp,p1.numero-p2.numero);
               break;
         	case TIPO_FLOAT: /* num-num = num */
               p2.numero=pop_float(pila_exp);
               push_float(pila_exp,p1.numero-p2.numero);
               break;
         	case TIPO_STR: /* num-str = num */
               p2.numero=pop_float(pila_exp);
               push_float(pila_exp,p1.numero-p2.numero);
               break;
            default:	/* num-x = error */
               pop_str(pila_exp);
               _4GLerror("Operacion no permitida.");
         }
         break;
      case TIPO_STR: 
         switch (t2)
         {
         	case TIPO_INT: /* str - x = error */
            case TIPO_FLOAT:
         	case TIPO_STR:
            case TIPO_DATE:
            default:
               _4GLerror("Operacion no permitida.");
         }
         break;
      case TIPO_DATE:
         switch(t2)
         {
            case TIPO_INT:
               p2.numero=pop_int(pila_exp);
               p2.numero=_4GLdate2julian(p1.fecha)-p2.numero;
               p2.fecha=_4GLjulian2date(p2.numero);
               push_date(pila_exp,p2.fecha);
               break;
            case TIPO_FLOAT:
               p2.numero=pop_float(pila_exp);
               p2.numero=_4GLdate2julian(p1.fecha)-p2.numero;
               p2.fecha=_4GLjulian2date(p2.numero);
               push_date(pila_exp,p2.fecha);
               break;
            case TIPO_DATE:
            case TIPO_DATETIME:
               p2.fecha=pop_date(pila_exp);
               push_int(pila_exp,_4GLdate2julian(p1.fecha)-_4GLdate2julian(p2.fecha));
               break;
            default:
               pop_int(pila_exp);
               _4GLerror("Operacion no permitida.");
         }
         break;
      case TIPO_TIME:
         switch(t2)
         {
            case TIPO_INT:
            case TIPO_FLOAT:
            case TIPO_TIME:
            case TIPO_INTERVAL:
               p2.numero=pop_int(pila_exp);
               p1.numero=_4GLtime2sec(p1.time);
               p1.numero-=p2.numero;
               p1.numero=((long)p1.numero)%(24*3600);
               if (p1.numero<0)
                  p1.numero=(24*3600)+p1.numero;
               push_time(pila_exp,_4GLsec2time(p1.numero));
               break;
            default:
               _4GLerror("Operacion no permitida.");
         
         }
         break;
      case TIPO_INTERVAL:
         switch(t2)
         {
            case TIPO_INT:
            case TIPO_FLOAT:
            case TIPO_INTERVAL:
               p2.numero=pop_int(pila_exp);
               p1.numero=_4GLinterval2sec(p1.inter);
               p1.numero-=p2.numero;
               push_interval(pila_exp,_4GLsec2interval(p1.numero));
               break;
            default:
               _4GLerror("Operacion no permitida.");
         
         }
         break;
      case TIPO_DATETIME:
         switch(t2)
         {
            case TIPO_INT:      /* datetime - num = datetime (resto segundos) */
            case TIPO_FLOAT:
            case TIPO_INTERVAL:
            case TIPO_TIME:
               p2.numero=pop_int(pila_exp);
               if (p2.numero>0)
               {
                    long hora,diajul;
                    hora=_4GLtime2sec(p1.dt.time);
                    diajul=_4GLdate2julian(p1.dt.date);
                    /* Miro si me quedo dentro del mismo dia */
                    if (p2.numero <= hora)
                    {
                    	p1.dt.time=_4GLsec2time(hora-p2.numero);
                        push_datetime(pila_exp,p1.dt);
                    }
                    else /* Resto más de la hora actual */
                    {
                    	/* Resto hasta las 00:00:00 */
                        p1.dt.time.hour=23;
                        p1.dt.time.min=59;
                        p1.dt.time.sec=59;
                        p1.dt.time.mil=0;
                        diajul--;
                        p2.numero-=(hora+1);
                        
                        hora=(24*3600)-1;
                        p1.dt.date=_4GLjulian2date(diajul-(long)(p2.numero/(24*3600)));
                        p1.dt.time=_4GLsec2time(hora-((long)p2.numero)%(24*3600));
                        push_datetime(pila_exp,p1.dt);
                    }
               }
               else /* Resto un numero negativo = sumar */
               {
               		long hora,diajul;
                    hora=_4GLtime2sec(p1.dt.time);
                    diajul=_4GLdate2julian(p1.dt.date);
                    p2.numero=(-1*p2.numero);
                    /* Miro si me quedo dentro del mismo dia */
                    if (hora+p2.numero < (24*3600))
                    {
                    	p1.dt.time=_4GLsec2time(hora+p2.numero);
                        push_datetime(pila_exp,p1.dt);
                    }
                    else /* pasamos del dia actual */
                    {
                    	/* Resto hasta las 00:00:00 */
                        p1.dt.time.hour=0;
                        p1.dt.time.min=0;
                        p1.dt.time.sec=0;
                        p1.dt.time.mil=0;
                        diajul++;
                        p2.numero-=(24*3600)-hora;
                        
                        hora=0;
                        p1.dt.date=_4GLjulian2date(diajul+(long)(p2.numero/(24*3600)));
                        p1.dt.time=_4GLsec2time(((long)p2.numero)%(24*3600));
                        push_datetime(pila_exp,p1.dt);
                    }
               }
               break;
            case TIPO_DATE:		/* datetime - date/datetime = interval */
            case TIPO_DATETIME:
               {
                  _4GLINTERVAL inter;
                  long segundos,sec1,sec2;
                  long dias,dia1,dia2;
                  
               	p2.dt=pop_datetime(pila_exp);
                  dia1=_4GLdate2julian(p1.dt.date);
                  dia2=_4GLdate2julian(p2.dt.date);
                  sec1=_4GLtime2sec(p1.dt.time);
                  sec2=_4GLtime2sec(p2.dt.time);
                  if (dia1-dia2>24850)
                  {
                  	_4GLalert("Intervalo demasiado grande.");
                     inter.hours=0;
                     inter.mins=0;
                     inter.secs=0;
                     inter.mils=0;
                  }
                  else
                  {
                  	dias=dia1-dia2;
                     segundos=(dias*24*3600)+(sec1-sec2);
                     inter.hours=segundos/3600;
                     segundos=segundos%3600;
                     inter.mins=segundos/60;
                     segundos=segundos%60;
                     inter.secs=segundos;
                     inter.mils=0;
                  }
                  push_interval(pila_exp,inter);
               }
               break;
            default:
               pop_int(pila_exp);
               _4GLerror("Operacion no permitida.");
         }
         break;
      default:
         /* Saco lo que hay en la pila */
         pop_int(pila_exp);
         _4GLerror("Operacion no permitida.");
         break;
   }   
}

void op_mult(pila *pila_exp)
{
   union
   {
      char *cadena;
      double numero;
      _4GLDATE fecha;
   }p1, p2;

   p2.numero=pop_float(pila_exp);
   p1.numero=pop_float(pila_exp);
   push_float(pila_exp, p1.numero*p2.numero);
}

void op_divide(pila *pila_exp)
{
   union
   {
      char *cadena;
      double numero;
      _4GLDATE fecha;
   }p1, p2;

   p1.numero=pop_float(pila_exp);
   p2.numero=pop_float(pila_exp);
   if (p2.numero==0)
      _4GLerror("Division por 0.");
   push_float(pila_exp, p1.numero/p2.numero);
}

void op_cmp(pila *pila_exp, int compara)
{
   union
   {
      char *cadena;
      double numero;
      _4GLDATE fecha;
      _4GLTIME t;
      _4GLDATETIME dt;
   }p1, p2;

   enum tipos t1;

   bool res;
   
   t1=tipo_pila(pila_exp);
   
   switch(t1)
   {
      case TIPO_INT:
      case TIPO_FLOAT:			/* Numero comparado con cualquier cosa */
         p1.numero=pop_float(pila_exp);
         p2.numero=pop_float(pila_exp);
         switch (compara)
         {
         	case -2:
               res=(p1.numero<p2.numero)?1:0;
               break;
         	case -1:
               res=(p1.numero<=p2.numero)?1:0;
               break;
         	case -0:
               res=(p1.numero==p2.numero)?1:0;
               break;
         	case 1:
               res=(p1.numero>=p2.numero)?1:0;
               break;
         	case 2:
               res=(p1.numero>p2.numero)?1:0;
               break;
         }
         break;
      case TIPO_STR:
         p1.cadena=pop_str(pila_exp);
         p2.cadena=pop_str(pila_exp);
         switch (compara)
         {
         	case -2:
               res=(strcmp(p1.cadena,p2.cadena)<0)?1:0;
               break;
         	case -1:
               res=(strcmp(p1.cadena,p2.cadena)<=0)?1:0;
               break;
         	case -0:
               res=(strcmp(p1.cadena,p2.cadena)==0)?1:0;
               break;
         	case 1:
               res=(strcmp(p1.cadena,p2.cadena)>=0)?1:0;
               break;
         	case 2:
               res=(strcmp(p1.cadena,p2.cadena)>=0)?1:0;
               break;
         }
         break;
      case TIPO_DATE:
         p1.fecha=pop_date(pila_exp);
         p2.fecha=pop_date(pila_exp);
         switch (compara)
         {
         	case -2:
               res=(_4GLdatecmp(p1.fecha,p2.fecha)<0)?1:0;
               break;
         	case -1:
               res=(_4GLdatecmp(p1.fecha,p2.fecha)<=0)?1:0;
               break;
         	case -0:
               res=(_4GLdatecmp(p1.fecha,p2.fecha)==0)?1:0;
               break;
         	case 1:
               res=(_4GLdatecmp(p1.fecha,p2.fecha)>=0)?1:0;
               break;
         	case 2:
               res=(_4GLdatecmp(p1.fecha,p2.fecha)>0)?1:0;
               break;
         }
         break;
      case TIPO_TIME:			/* Hora comparado con cualquier cosa */
         p1.numero=pop_int(pila_exp);
         p2.numero=_4GLtime2sec(pop_time(pila_exp));
         switch (compara)
         {
         	case -2:
               res=(p1.numero<p2.numero)?1:0;
               break;
         	case -1:
               res=(p1.numero<=p2.numero)?1:0;
               break;
         	case -0:
               res=(p1.numero==p2.numero)?1:0;
               break;
         	case 1:
               res=(p1.numero>=p2.numero)?1:0;
               break;
         	case 2:
               res=(p1.numero>p2.numero)?1:0;
               break;
         }
         break;
      case TIPO_DATETIME:			/* Datetime comparado con cualquier cosa */
         p1.cadena=_4GLdatetime2iso(pop_datetime(pila_exp));
         p2.cadena=_4GLdatetime2iso(pop_datetime(pila_exp));
         switch (compara)
         {
         	case -2:
               res=(strcmp(p1.cadena,p2.cadena)<0)?1:0;
               break;
         	case -1:
               res=(strcmp(p1.cadena,p2.cadena)<=0)?1:0;
               break;
         	case -0:
               res=(strcmp(p1.cadena,p2.cadena)==0)?1:0;
               break;
         	case 1:
               res=(strcmp(p1.cadena,p2.cadena)>=0)?1:0;
               break;
         	case 2:
               res=(strcmp(p1.cadena,p2.cadena)>=0)?1:0;
               break;
         }
         break;
      case TIPO_INTERVAL:			/* Interval comparado con cualquier cosa */
         p1.numero=pop_int(pila_exp);
         p2.numero=_4GLinterval2sec(pop_interval(pila_exp));
         switch (compara)
         {
         	case -2:
               res=(p1.numero<p2.numero)?1:0;
               break;
         	case -1:
               res=(p1.numero<=p2.numero)?1:0;
               break;
         	case -0:
               res=(p1.numero==p2.numero)?1:0;
               break;
         	case 1:
               res=(p1.numero>=p2.numero)?1:0;
               break;
         	case 2:
               res=(p1.numero>p2.numero)?1:0;
               break;
         }
         break;

   }   
   push_int(pila_exp,res);
}

void op_and(pila *pila_exp)
{
   union
   {
      char *cadena;
      double numero;
      _4GLDATE fecha;
   }p1, p2;

   p2.numero=pop_int(pila_exp);
   p1.numero=pop_int(pila_exp);
   push_int(pila_exp,p1.numero * p2.numero);
}

void op_or(pila *pila_exp)
{
   union
   {
      char *cadena;
      double numero;
      _4GLDATE fecha;
   }p1, p2;

   p2.numero=pop_int(pila_exp);
   p1.numero=pop_int(pila_exp);
   push_int(pila_exp,((p1.numero+p2.numero)>0)?1:0);
   
}

void op_negar(pila *pila_exp)
{
   int i;
   i=pop_int(pila_exp);
   if (i)
      push_int(pila_exp,0);
   else
      push_int(pila_exp,1);
}

