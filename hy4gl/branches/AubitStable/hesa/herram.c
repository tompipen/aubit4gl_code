#include <stdio.h>
#include <string.h>
#include <ctype.h>


#include "est_dat.h"
#include "herram.h"

FILE *f_cab;
FILE *f_def;
FILE *f_fil;
extern FILE *yyin;

void main(int argc,char *argv[])
{
 char cab[ID_FICH];
 char def[ID_FICH];
 char fil[ID_FICH];
 char nombre_raiz[ID_FICH];
 int correcto;
  
 printf("HESA. Herramienta de Especificaci¢n de Sintaxis Abstracta.\n");
 printf("Versi¢n 1.1  1993.\n");
 printf("Departamento de Lenguajes y Sistemas Inform ticos.\n");
 printf("Universidad de Sevilla.\n");
 if(argc==1)
   {
    fprintf(stderr,"\nUtilizaci¢n: hesa <fichero>\n");
    exit(0);
   }
  construye_nombre_raiz(argv[1],nombre_raiz,&correcto);
  if(!correcto)
   {
    fprintf(stderr,"\nhesa: La extensi¢n del fichero debe ser \".esa\"\n");
    exit(1);
   }
  yyin = fopen(argv[1],"r");
  if(yyin == NULL)
   {
    fprintf(stderr,"\nhesa: Error al abrir el fichero de entrada\n");
    exit(1);
   }  
  abrir_temporales(cab,def,fil);
  inicializa_tabla();
  yyparse();
  fclose(f_cab);
  fclose(f_def);
  fclose(f_fil);
  fclose(yyin);
  construye_salida(nombre_raiz,cab,def,fil);
  printf("\n");
}


void construye_nombre_raiz(char *nombre,char *nombre_raiz,int *valido)
{
char *p,*p_ult=NULL;
char sufijo[ID_FICH];
int i;

*valido=1;
strcpy(nombre_raiz,nombre);
p=strchr(nombre_raiz,'.');
while(p!=NULL)  /* para los nombres en UNIX, que permiten mas de un punto */
{
 p_ult=p;
 p=strchr(p+1,'.');
}
if(p_ult!=NULL)
  strcpy(sufijo,p_ult);
for(i=0;sufijo[i]!='\0';i++)
  sufijo[i]=toupper(sufijo[i]);
if(p_ult==NULL || strcmp(sufijo,".ESA"))
  *valido=0;
else
  *p_ult='\0';
}

void construye_nombres(char *nombre_raiz, char *nombre_c, char *nombre_h)
{
 strcpy(nombre_c,nombre_raiz);
 strcpy(nombre_h,nombre_raiz);
 strcat(nombre_c,".c");
 strcat(nombre_h,".h");
}

void abrir_temporales(char *cab, char *def, char *fil)
{
 tmpnam(cab);
 tmpnam(def);
 tmpnam(fil);

 f_cab = fopen(cab,"w");
 f_def = fopen(def,"w");
 f_fil = fopen(fil,"w");

 if((f_cab==NULL)||(f_def==NULL)||(f_fil==NULL))
  {
   fprintf(stderr,"\nhesa: Error en la apertura de ficheros temporales\n");
   exit(1);
  }
}

void construye_salida(char *nombre,char *cab, char *def, char *fil)
{
 char nombre_c[ID_FICH];
 char nombre_h[ID_FICH];
 FILE *f_c, *f_h;
 int ch;

 construye_nombres(nombre, nombre_c, nombre_h);
 f_c = fopen(nombre_c,"w");
 f_h = fopen(nombre_h,"w");
 if((f_c==NULL)||(f_h==NULL))
  { 
   fprintf(stderr,"\nhesa: Error en la apertura de ficheros de salida\n");
   exit(1);
  }
 f_cab = fopen(cab,"r");
 f_def = fopen(def,"r");
 f_fil = fopen(fil,"r");
 while((ch=fgetc(f_cab))!=EOF)
   fputc(ch,f_h);
 while((ch=fgetc(f_def))!=EOF)
   fputc(ch,f_h);
 fprintf(f_c,"#include <stdio.h>"); 
 fprintf(f_c,"\n#include <stdarg.h>");
 fprintf(f_c,"\n#include <stdlib.h>");
 fprintf(f_c,"\n#include \"%s\"",nombre_h);
 while((ch=fgetc(f_fil))!=EOF)
   fputc(ch,f_c);
 fclose(f_cab);
 fclose(f_def);
 fclose(f_fil);
 remove(cab);
 remove(def);
 remove(fil);
 fclose(f_c);
 fclose(f_h);
}
