/************ Funciones de manejo de fecha ***************
 *
 * Las operaciones de diferencias entre fechas se hacen 
 * pasando la fecha a 'dia juliano',
 * segun el algoritmo descrito en 'Numerical Recipes', de Press et al, 1988.
 * y que me lo ha pasado G.S.Cole, de Digital Burro, INC.
 *
 * Gracias mil. ;-)
 *
 */

#include "hy4gl.h"

#include <math.h> 
#define IGREG (15+31L*(10+12L*1582))
#define GREG 2299161L
#define JULIAN long
extern bool _4GLfechaEuro; 

long _4GLdate2julian(_4GLDATE candidate)
{
  JULIAN result;
  long temp1,temp2,temp3;
  /*
  ** There is no year zero
  */
  if (candidate.year == 0) {
    return(0);
  }

  if (candidate.year < 0) {
    ++candidate.year;
  }

  if (candidate.month > 2) {
    temp2 = candidate.year;
    temp3 = candidate.month + 1;
  } else {
    temp2 = candidate.year - 1;
    temp3 = candidate.month + 13;
  }

  result = (unsigned long)
    (floor(365.25*temp2)+floor(30.6001 * temp3) + candidate.day + 1720995L);

  if (candidate.day + 31L * (candidate.month+12L*candidate.year) >= IGREG) {
    temp1 = 0.01 * temp2;
    result += 2 - temp1 + (long)(0.25 * temp1);
  }

  return(result);
}

_4GLDATE _4GLjulian2date(JULIAN julian)
{
  _4GLDATE caltemp;
  long temp1, temp2, temp3, temp4, temp5, temp6;

  if (julian >= GREG) {
    temp2 = ((float)(julian-1867216L)-0.25)/36524.25;
    temp1 = julian+1L+temp2-(long)(0.25*temp2);
  } else {
    temp1 = julian;
  }

  temp3 = temp1+1524;
  temp4 = 6680.0+((float)(temp3-2439870L)-122.1)/365.25;
  temp5 = 365*temp4+(0.25*temp4);
  temp6 = (temp3-temp5)/30.6001;
 
  temp1 = temp3-temp5-(int)(30.6001*temp6);
  caltemp.day = (int) temp1;
  caltemp.month = (int) (temp6-1);
  if (caltemp.month > 12)
    caltemp.month -= 12;
  caltemp.year = (int) (temp4-4715);
  if (caltemp.month > 2)
    --(caltemp.year);
  if (caltemp.year <= 0)
    --(caltemp.year);

  return(caltemp);
}

bool _4GLleap_year(int year)
{
  int result;

  year = abs(year);        /* for B.C. years */
 
  if (year % 4) {
    result = FALSE;         /* not divisible by 4, not eligible */
  } else {
    if (year % 100) {       /* new century? */
      result = TRUE;        /* no, so this is a leap year */
    } else {
      if (year % 400) {     /* yes... */
        result = FALSE;     /* not divisible by 400, not leap year */
      } else {
        result = TRUE;      /* divisible by 400, leap year */
      }
    }
  }
  return(result);
}

bool _4GLchkDate(_4GLDATE candidate)
{

  if (candidate.year == 0) {
    return(FALSE);
  }

  if (candidate.day < 1) {
    return(FALSE);
  }

  switch (candidate.month) {
  case 1:
    if (candidate.day > 31) return(FALSE);
    break;
  case 2:
    if (candidate.day > 28) {
      if (!((candidate.day == 29) && (_4GLleap_year(candidate.year))))
	return(FALSE);
    }
    break;
  case 3:
    if (candidate.day > 31) return(FALSE);
    break;
  case 4:
    if (candidate.day > 30) return(FALSE);
    break;
  case 5:
    if (candidate.day > 31) return(FALSE);
    break;
  case 6:
    if (candidate.day > 30) return(FALSE);
    break;
  case 7:
    if (candidate.day > 31) return(FALSE);
    break;
  case 8:
    if (candidate.day > 31) return(FALSE);
    break;
  case 9:
    if (candidate.day > 30) return(FALSE);
    break;
  case 10:
    if (candidate.day > 31) return(FALSE);
    break;
  case 11:
    if (candidate.day > 30) return(FALSE);
    break;
  case 12:
    if (candidate.day > 31) return(FALSE);
    break;
  default:
    return(FALSE);
  }
  return(TRUE);
}

_4GLDATE _4GLstr2date(char *fecha_in)
{
   _4GLDATE fec;
   char cadena[12];
   char *fecha;
   int i;

   fecha=fecha_in;
   /* Troceo la fecha, para sacar dia/mes/anno */
   if (strlen(_4GLtrim(fecha))==0) /* Las cadenas vacias no deben dar error, 
        sino tomarlas como 1-1-1 */
   {
      fec.day=1;
      fec.month=1;
      fec.year=1;      
   }
   else
   {
      if ( (strspn(fecha,"0123456789")==strlen(fecha))
         	&& (strlen(fecha)>4)) 
      /* Solo hay numeros del estilo 290490 convierto a 29-04-1990 */
      {
         if (strlen(fecha)==6)
         {
            fec.year=atol(fecha+4);
            if (fec.year>=50)
               sprintf(cadena,"%2.2s-%2.2s-19%2.2s",fecha,fecha+2,fecha+4);
            else
               sprintf(cadena,"%2.2s-%2.2s-20%2.2s",fecha,fecha+2,fecha+4);           
            fecha=cadena;
         }
         else
         {
            sprintf(cadena,"%2.2s-%2.2s-%s",fecha,fecha+2,fecha+4);
            fecha=cadena;
         }
      }
      if (_4GLfechaEuro)
         i=sscanf(fecha,"%d%*[/-]%d%*[/-]%d",&fec.day,&fec.month,&fec.year);
      else
         i=sscanf(fecha,"%d%*[/-]%d%*[/-]%d",&fec.month,&fec.day,&fec.year);
      if (i!=3)
      {
         _4GLalert("No se puede convertir la fecha %s.",fecha);
          fec.day=fec.month=1;
          fec.year=1;
      }
   }
   if (!_4GLchkDate(fec))
   {
      _4GLalert("Fecha no valida: %s",fecha);
      fec.day=fec.month=1;
      fec.year=1;
   }
   return fec;
}

char *_4GLdate2str(_4GLDATE fec)
{
   char *res;
   res=(char *)malloc(15);
   if (_4GLfechaEuro)
      sprintf(res,"%02d-%02d-%04d",fec.day, fec.month, fec.year);
   else
      sprintf(res,"%02d-%02d-%04d",fec.month, fec.day, fec.year);
   return res;
}

_4GLDATE _4GLDBstr2date(char *fecha_in)
{
   _4GLDATE fec;
   char cadena[12];
   char *fecha;
   int i;

   fecha=fecha_in;
   /* Troceo la fecha, para sacar dia/mes/anno */
   if (strlen(_4GLtrim(fecha))==0) /* Las cadenas vacias no deben dar error, 
        sino tomarlas como 1-1-1 */
   {
      fec.day=1;
      fec.month=1;
      fec.year=1;      
   }
   else
   {
      i=sscanf(fecha,"%d%*[/-]%d%*[/-]%d",&fec.year,&fec.month,&fec.day);
      if (i!=3)
      {
         _4GLalert("No se puede convertir la fecha %s.",fecha);
          fec.day=fec.month=1;
          fec.year=1;
      }
   }
   if (!_4GLchkDate(fec))
   {
      _4GLalert("Fecha no valida: %s",fecha);
      fec.day=fec.month=1;
      fec.year=1;
   }
   return fec;
}


int _4GLdatecmp(_4GLDATE f1,_4GLDATE f2)
{
   JULIAN fec1,fec2;
   fec1=_4GLdate2julian(f1);
   fec2=_4GLdate2julian(f2);
   if (fec1<fec2)
      return -1;
   else if (fec1==fec2)
      return 0;
   else
      return 1;
}


_4GLTIME _4GLstr2time(char *cadena)
{
   _4GLTIME hora;
   int i;
   /* Troceo la fecha, para sacar dia/mes/anno */
   hora.hour=hora.min=hora.sec=hora.mil=0;
   
   i=sscanf(cadena,"%d:%d:%d.%d",&hora.hour,&hora.min,&hora.sec,&hora.mil);
   if (!_4GLchkTime(hora))
      _4GLalert("Hora no valida: %s",cadena);
   return hora;
}

char *_4GLtime2str(_4GLTIME tim)
{
   char *res;
   char *formato;
   if (getenv("HYMILLISECONDS"))
      formato="%02d:%02d:%02d.%03d";
   else
      formato="%02d:%02d:%02d";
   
   res=(char *)malloc(15);
   sprintf(res,formato,tim.hour,tim.min,tim.sec,tim.mil);
   return res;
}


/* Calcula el numero de segundos que han pasado desde las 00:00:00 */
long _4GLtime2sec(_4GLTIME tim)
{
   long res;
   res=(tim.hour*3600)+(tim.min*60)+(tim.sec);
   return res;
}

/* Funcion que convierte un nº de segundos en un TIME */
_4GLTIME _4GLsec2time(long sec)
{
   _4GLTIME t;
   t.hour=(int)sec/3600;
   sec=sec%3600;
   t.min=(int)sec/60;
   sec=sec%60;
   t.sec=sec;
   t.mil=0;
   return t;
}

/* Comprueba que el formato de hora sea correcto */
bool _4GLchkTime(_4GLTIME tim)
{
   bool res=TRUE;
   if (tim.hour<0 || tim.hour>23 || tim.min<0 || tim.min>59 || tim.sec <0
      || tim.sec>59 || tim.mil<0 || tim.mil>999)
      res=FALSE;
   return res;
}

_4GLDATETIME _4GLstr2datetime(char *cadena)
{
   _4GLDATETIME fec;
   int i;
   
   /* Troceo la fecha y hora, para sacar dia/mes/anno */
   fec.time.hour=fec.time.min=fec.time.sec=fec.time.mil=0;
   
   if (_4GLfechaEuro)
      i=sscanf(cadena,"%d%*[/-]%d%*[/-]%d %d:%d:%d.%d",
         &fec.date.day,&fec.date.month,&fec.date.year,
         &fec.time.hour,&fec.time.min,&fec.time.sec,&fec.time.mil);
   else
      i=sscanf(cadena,"%d%*[/-]%d%*[/-]%d %d:%d:%d.%d",
         &fec.date.month,&fec.date.day,&fec.date.year,
         &fec.time.hour,&fec.time.min,&fec.time.sec,&fec.time.mil);

   if (i<3)
   {
      _4GLalert("No se puede convertir la fecha/hora %s.",cadena);
   }
   if (!_4GLchkDate(fec.date) || !_4GLchkTime(fec.time))
      _4GLalert("Fecha/Hora no valida: %s",cadena);
   return fec;
}

char *_4GLdatetime2str(_4GLDATETIME tim)
{
   char *res;
   char *formato;

   if (getenv("HYMILLISECONDS"))
      formato="%02d-%02d-%04d %02d:%02d:%02d.%03d";
   else
      formato="%02d-%02d-%04d %02d:%02d:%02d";

   res=(char *)malloc(35);
   if (_4GLfechaEuro)
      sprintf(res,formato,
         tim.date.day, tim.date.month, tim.date.year,
         tim.time.hour,tim.time.min,tim.time.sec,tim.time.mil);
   else
      sprintf(res,formato,
         tim.date.month, tim.date.day, tim.date.year,
         tim.time.hour,tim.time.min,tim.time.sec,tim.time.mil);
   return res;
}

char *_4GLdatetime2iso(_4GLDATETIME tim)
{
   char *res;
   res=(char *)malloc(35);
   sprintf(res,"%04d-%02d-%02d %02d:%02d:%02d.%03d",
         tim.date.year, tim.date.month, tim.date.day,
         tim.time.hour,tim.time.min,tim.time.sec,tim.time.mil);
   return res;
}

bool _4GLchkDateTime(_4GLDATETIME tim)
{
   bool res=TRUE;
   if (_4GLchkDate(tim.date) && _4GLchkTime(tim.time))
      res=TRUE;
   else
      res=FALSE;
   return res;
}

char *_4GLinterval2str(_4GLINTERVAL inter)
{
   char *res;
   res=(char *)malloc(40);
   if (inter.hours<0 || inter.mins<0 || inter.secs<0 || inter.mils<0)
      sprintf(res,"-%03d:%02d:%02d.%02d",abs(inter.hours),abs(inter.mins),
         abs(inter.secs),abs(inter.mils));
   else
      sprintf(res,"%03ld:%02d:%02d.%02d",inter.hours,inter.mins,
      inter.secs,inter.mils);
   return res;
}

_4GLINTERVAL _4GLstr2interval(char *cadena)
{
   _4GLINTERVAL hora;
   int i;
   /* Troceo la fecha, para sacar horas/minutos/segundos */
   hora.hours=hora.mins=hora.secs=hora.mils=0;
   if (cadena[0]=='-')
   {
      i=sscanf(cadena+1,"%ld:%d:%d.%d",&hora.hours,&hora.mins,&hora.secs,&hora.mils);
      hora.hours=hora.hours*(-1);
      hora.mins=hora.mins*(-1);
      hora.secs=hora.secs*(-1);
      hora.mils=hora.mils*(-1);
   }
   else
      i=sscanf(cadena,"%ld:%d:%d.%d",&hora.hours,&hora.mins,&hora.secs,&hora.mils);
   if (!_4GLchkInterval(hora))
      _4GLalert("Intervalo no válido: %s",cadena);
   return hora;
}

_4GLINTERVAL _4GLDBstr2interval(char *cadena)
{
   float i;
   _4GLINTERVAL hora;
   char cad[255];
   char *tk;
   
   hora.hours=hora.mins=hora.secs=hora.mils=0;
   strcpy(cad,cadena);
   tk=strtok(cad," ");
   while (tk)
   {
      if ((tk[0]>='0') && (tk[0]<='9'))
      {
         i=atol(tk);
      }
      else
      {
         if (!strncmp(tk,"day",3))
            hora.hours=hora.hours+(i*24);
         else if (!strncmp(tk,"hour",4))
            hora.hours=hora.hours+i;
         else if (!strncmp(tk,"min",3))
            hora.mins=i;
         else if (!strncmp(tk,"sec",3))
            hora.secs=i;
         else if (!strncmp(tk,"ago",3))
         {
            hora.hours=hora.hours*(-1);
            hora.mins=hora.mins*(-1);
            hora.secs=hora.secs*(-1);
            hora.mils=hora.mils*(-1);
         }
      }
      tk=strtok(NULL," ");
   }
   printf("%s -> %d*%d*%d\n",cadena,hora.hours,hora.mins,hora.secs);
   return hora;
}

bool _4GLchkInterval(_4GLINTERVAL tim)
{
   bool res=TRUE;
   if (tim.mins<-59 || tim.mins>59 || tim.secs <-59
      || tim.secs>59 || tim.mils<-999 || tim.mils>999)
      res=FALSE;
   return res;
}
/* Calcula el numero de segundos que contiene un intervalo */
long _4GLinterval2sec(_4GLINTERVAL tim)
{
   long res;
   res=(tim.hours*3600)+(tim.mins*60)+(tim.secs);
   return res;
}

/* Funcion que convierte un nº de segundos en un INTERVAL */
_4GLINTERVAL _4GLsec2interval(long sec)
{
   _4GLINTERVAL t;
   t.hours=(long)sec/3600;
   sec=sec%3600;
   t.mins=(long)sec/60;
   sec=sec%60;
   t.secs=sec;
   t.mils=0;
   return t;
}

