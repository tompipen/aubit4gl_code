/******** Generaci¢n  de c¢digo para el compilador
 * Funciones para generar y manejar los forms de pantalla 
 ********/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include <postgres.h>
#include <libpq-fe.h>
#include "global.h"
#include "asa.h"
#include "prototipos.h"

extern char yyfilename[255];
extern int numerrores;
extern Arbol raiz,lst_funciones;
extern Arbol lst_globales, lst_locales, lst_param,db;
extern FILE *fp;
extern int indentacion;
extern int en_select;
extern int sw_warning;
extern int sw_verfuente;
int maxInputByName=0;
int numInputByName=0;
Arbol InputByNameArbol=NULL;

/* Funcion que genera el codigo para crear un form en memoria */
void genFormCreate(Arbol snt)
{
   char *nombre;
   nombre=Identificador_nombre(FormCreate_nom(snt));
   genera(indentacion,"/* Creo el form %s */\n",nombre);
   genera(indentacion,"_F%s=_GenForm_F%s();\n",nombre,nombre);
   genera(indentacion,"/* Lo asigno a esta ventana */\n");
   genera(indentacion,"_curwin->form=_F%s;\n\n",nombre);
}

/* Funcion que genera el codigo para mostrar un form en pantalla */
void genFormDisplay(Arbol snt)
{
   char *nombre;
   nombre=Identificador_nombre(FormDisplay_nom(snt));
   genera(indentacion,"/* Muestro el from %s en pantalla */\n",nombre);
   genera(indentacion,"if (!_F%s) _4GLerror(\"El form %s no se ha inicializado\");\n",nombre);
   genera(indentacion,"_4GLshow_form(_F%s);\n\n",nombre);
}

void genFormDispByName(Arbol snt)
{
   char *nombre;
   int i,cuantos;
   Arbol aux;
   
   /* Recorro la lista de variables que hay que mostrar en pantalla */
   cuantos=ListaId_longitud(FormDispByName_campos(snt));
   for (i=1;i<=cuantos;i++)
   {
      aux=ListaId_elemento(FormDispByName_campos(snt),i);
      genExpresion(aux);
      nombre=rindex(Identificador_nombre(Id_nom(aux)),'.');
      if (!nombre)
         nombre=Identificador_nombre(Id_nom(aux));
      else
         nombre++;
      genera(indentacion,"_4GLFormAssign(_curwin->form,\"%s\",pop_str(pila_exp));\n",nombre);
   }
   genera(indentacion,"touchwin(curwin);\n");
   genera(indentacion,"update_panels();\n");
   genera(indentacion,"doupdate();\n\n");
}

void genFormInputByName(Arbol snt)
{
   char *nombre, *dest;
   int i,cuantos;
   Arbol aux;
   Arbol asignacion;
   enum tipos tip;
   int tam=1;
   int antInputByName;
   Arbol antInputByNameArbol;
   antInputByName=numInputByName;
   numInputByName=maxInputByName++;
   antInputByNameArbol=InputByNameArbol;
   InputByNameArbol=snt;
      
   genera(indentacion,"/* Muestro los valores actuales */\n");
   genFormDispByName(snt);

   /* Pongo como 'ReadOnly' todos los campos */
   genera(indentacion,"_4GLFormReadOnly(_curwin->form,\"*\",1);\n");
   /* Recorro la lista de variables que hay que pedir 
      y los voy poniendo como editables */
   cuantos=ListaId_longitud(FormInputByName_campos(snt));
   for (i=1;i<=cuantos;i++)
   {
      aux=ListaId_elemento(FormInputByName_campos(snt),i);
      nombre=rindex(Identificador_nombre(Id_nom(aux)),'.');
      if (!nombre)
         nombre=Identificador_nombre(Id_nom(aux));
      else
         nombre++;
      genera(indentacion,"_4GLFormReadOnly(_curwin->form,\"%s\",0);\n",nombre,0);
   }

   genera(indentacion,"/* Bucle de control del form */\n");
   genera(indentacion++,"{\n");
   genera(indentacion,"int _tecla;\n");
   genera(indentacion,"_4GLFIELD _campo_anterior=NULL, _campo_actual=NULL;\n");
   genera(indentacion,"_curwin->form->campo_activo=_curwin->form->campos; /* Activo el primer campo */\n");
   genera(indentacion,"_tecla=getch();\n");
   genera(indentacion,"_campo_anterior=_campo_actual=_4GLcurrent_field(_curwin->form);\n");
   genera(indentacion,"while (1)\n");
   genera(indentacion++,"{\n");
   genera(indentacion,"/* Si el programador ha definido algunas acciones, \n");
   genera(indentacion,"   las tengo en cuenta ahora */\n");
   cuantos=FormOnKeys_longitud(FormInputByName_opc(snt));
   for (i=1;i<=cuantos;i++)
   {
      aux=FormOnKeys_elemento(FormInputByName_opc(snt),i);
      /* ON KEY... */
      nombre=Identificador_nombre(FormOnKey_nom(aux));
      if (nombre[0]=='K')
         genera(indentacion,"if ( _tecla == %s )\n",Identificador_nombre(FormOnKey_nom(aux))+1);
      /* ON BUTTON... */
      else if (nombre[0]=='B')
         genera(indentacion,"if ( !strcmp(_curwin->form->campo_activo->nombre,\"%s\") && (_tecla==' '))\n",
            Identificador_nombre(FormOnKey_nom(aux))+1);
      genera(indentacion++,"{\n");
      genera(indentacion,"_WINDOW *_prevwin;\n");
      genera(indentacion,"_prevwin=_curwin;\n");
      genSentencias(FormOnKey_cod(aux));
      genera(indentacion,"_tecla=getch();\n");
      genera(indentacion,"_curwin=_prevwin;\n");
      genera(indentacion,"continue;\n");
      genera(--indentacion,"}\n");
   }
   genera(indentacion,"if ( _tecla == KEY_F(8) ) /* Tecla por defecto para salir */\n");
   genera(indentacion+1,"goto _InputByName_1_%d;\n",numInputByName);
   genera(indentacion,"_4GLdrive_form_input(_curwin->form,_tecla);\n");

   genera(indentacion,"_InputByName_0_%d: /* Salto aqui en un CONTINUE INPUT */\n",numInputByName);

   genera(indentacion,"_campo_actual=_4GLcurrent_field(_curwin->form);\n");

   genera(indentacion,"/* Compruebo si he salido del campo en el que estaba */\n");

   genera(indentacion,"if (_campo_anterior!=_campo_actual)\n");
   genera(indentacion++,"{\n");
   genValidaCamposForm(snt);
   genera(indentacion,"_campo_anterior=_campo_actual;\n");
   genera(--indentacion,"}\n");   

   genera(indentacion,"update_panels(); doupdate(); _tecla=getch();\n");
   genera(--indentacion,"}\n");
   genera(indentacion,"_InputByName_1_%d: /* Salto hasta aqui en un EXIT INPUT */\n",numInputByName);
   genera(--indentacion,"}\n");
   genera(indentacion,"/* Recojo los valores del form */\n");

   cuantos=ListaId_longitud(FormInputByName_campos(snt));
   for (i=1;i<=cuantos;i++)
   {
      aux=ListaId_elemento(FormInputByName_campos(snt),i);
      dest=Identificador_nombre(Id_nom(aux));
      nombre=rindex(dest,'.');
      if (!nombre)
         nombre=dest;
      else
         nombre++;
      
      asignacion=Existe_Var(dest);
      tip=tipo_var(dest);
      tam=Constante_valor(Tipo_tam(Variable_tip(asignacion)));
      /* Apilo el contenido del campo en el form */
      genera(indentacion,"push_str(pila_exp,_4GLFormFieldValue(_curwin->form,\"%s\"));\n",nombre);
      /* Y ahora la asignacion */
      switch (tip)
      {
         case TIPO_STR:
            genera(indentacion,"_4GLstrncpy(%s,pop_str(pila_exp),%d);\n",
               dest,tam);
            break;
         case TIPO_DATE:
            genera(indentacion,"%s=pop_date(pila_exp);\n",dest);
            break;
         case TIPO_TIME:
            genera(indentacion,"%s=pop_time(pila_exp);\n",dest);
            break;
         case TIPO_DATETIME:
            genera(indentacion,"%s=pop_datetime(pila_exp);\n",dest);
            break;
         case TIPO_INTERVAL:
            genera(indentacion,"%s=pop_interval(pila_exp);\n",dest);
            break;
         case TIPO_INT:
            genera(indentacion,"%s=pop_int(pila_exp);\n",dest);
            break;
         case TIPO_FLOAT:
            genera(indentacion,"%s=pop_float(pila_exp);\n",dest);
            break;
         default:
            break;
      }
   }
   genera(indentacion,"_InputByName_2_%d: /* Salto hasta aqui si pulsa ESC */\n\n",numInputByName);
   numInputByName=antInputByName;
   InputByNameArbol=antInputByNameArbol;
}

/* Funcion que genera el codigo para validar los campos de un form.*/
void genValidaCamposForm(Arbol snt)
{
   int i,cuantos;
   Arbol aux;
   char *nombre;


   /* 
    *
    * Primero genero el codigo para la validacion de los campos 
    *
    */
   genFormValidate(snt,FALSE);

   /* 
    *
    * Y ahora los 'AFTER FIELD', si los hay
    *
    */

   cuantos=FormAfterFields_longitud(FormInputByName_after(snt));

   for (i=1;i<=cuantos;i++)
   {
      aux=FormAfterFields_elemento(FormInputByName_after(snt),i);
      nombre=rindex(Identificador_nombre(FormAfterField_nom(aux)),'.');
      if (!nombre)
         nombre=Identificador_nombre(FormAfterField_nom(aux));
      else
         nombre++;
      genera(indentacion,"/* AFTER FIELD %s */\n",nombre);
      genera(indentacion,"if (!strcmp(_campo_anterior->nombre,\"%s\"))\n",nombre);
      genera(indentacion++,"{\n");
      genSentencias(FormAfterField_cod(aux));
      genera(--indentacion,"}\n");
   }
}

void genFormExit(Arbol snt)
{
   genera(indentacion,"goto _InputByName_1_%d; /* EXIT INPUT */\n",numInputByName);
}

void genFormCurrent(Arbol snt)
{
   char *nombre;
   nombre=rindex(Identificador_nombre(FormCurrentField_nom(snt)),'.');
   if (!nombre)
      nombre=Identificador_nombre(FormCurrentField_nom(snt));
   else
       nombre++;
   genera(indentacion,"/** CURRENT FIELD %s **/\n",nombre);
   genera(indentacion,"_4GLset_current_field(_curwin->form,\"%s\");\n",nombre);
   genera(indentacion,"_campo_anterior=_campo_actual=_4GLcurrent_field(_curwin->form);\n");
}

void genFormValidate(Arbol snt,bool actual)
{
   int i,cuantos,tam;
   Arbol aux,var;
   char *nombre,*nombre_var;
   enum tipos tip;

   cuantos=ListaId_longitud(FormInputByName_campos(snt));

   for (i=1;i<=cuantos;i++)
   {
      aux=ListaId_elemento(FormInputByName_campos(snt),i);
      nombre=rindex(Identificador_nombre(Id_nom(aux)),'.');
      if (!nombre)
         nombre=Identificador_nombre(Id_nom(aux));
      else
         nombre++;
      genera(indentacion,"/** VALIDATE FIELD **/\n");
      if (actual)
         genera(indentacion,"if (!strcmp(_campo_actual->nombre,\"%s\"))\n",nombre);
      else
         genera(indentacion,"if (!strcmp(_campo_anterior->nombre,\"%s\"))\n",nombre);
      genera(indentacion++,"{\n");
      nombre_var=Identificador_nombre(Id_nom(aux));
      var=Existe_Var(nombre_var);
      tip=tipo_var(nombre_var);
      tam=Constante_valor(Tipo_tam(Variable_tip(var)));
      /* Apilo el contenido del campo en el form */
      genera(indentacion,"push_str(pila_exp,_4GLFormFieldValue(_curwin->form,\"%s\"));\n",nombre);
      /* Y ahora la asignacion */
      switch (tip)
      {
         case TIPO_STR:
            genera(indentacion,"_4GLstrncpy(%s,pop_str(pila_exp),%d);\n",
               nombre_var,tam);
            genera(indentacion,"push_str(pila_exp,%s);\n",nombre_var);
            genera(indentacion,"_4GLFormAssign(_curwin->form,\"%s\",pop_str(pila_exp));\n",nombre);
            break;
         case TIPO_DATE:
            genera(indentacion,"%s=pop_date(pila_exp);\n",nombre_var);
            genera(indentacion,"push_date(pila_exp,%s);\n",nombre_var);
            genera(indentacion,"_4GLFormAssign(_curwin->form,\"%s\",pop_str(pila_exp));\n",nombre);
            break;
         case TIPO_TIME:
            genera(indentacion,"%s=pop_time(pila_exp);\n",nombre_var);
            genera(indentacion,"push_time(pila_exp,%s);\n",nombre_var);
            genera(indentacion,"_4GLFormAssign(_curwin->form,\"%s\",pop_str(pila_exp));\n",nombre);
            break;
         case TIPO_DATETIME:
            genera(indentacion,"%s=pop_datetime(pila_exp);\n",nombre_var);
            genera(indentacion,"push_datetime(pila_exp,%s);\n",nombre_var);
            genera(indentacion,"_4GLFormAssign(_curwin->form,\"%s\",pop_str(pila_exp));\n",nombre);
            break;
         case TIPO_INTERVAL:
            genera(indentacion,"%s=pop_interval(pila_exp);\n",nombre_var);
            genera(indentacion,"push_interval(pila_exp,%s);\n",nombre_var);
            genera(indentacion,"_4GLFormAssign(_curwin->form,\"%s\",pop_str(pila_exp));\n",nombre);
            break;
         case TIPO_INT:
            genera(indentacion,"%s=pop_int(pila_exp);\n",nombre_var);
            genera(indentacion,"push_int(pila_exp,%s);\n",nombre_var);
            genera(indentacion,"_4GLFormAssign(_curwin->form,\"%s\",pop_str(pila_exp));\n",nombre);
            break;
         case TIPO_FLOAT:
            genera(indentacion,"%s=pop_float(pila_exp);\n",nombre_var);
            genera(indentacion,"push_float(pila_exp,%s);\n",nombre_var);
            genera(indentacion,"_4GLFormAssign(_curwin->form,\"%s\",pop_str(pila_exp));\n",nombre);
            break;
         default:
            break;
      }
      genera(--indentacion,"}\n");
   }
}

/* Funcion para generar el codigo necesario para crear un form */
void genForm(Arbol snt)
{
   struct atributos attr;
   Arbol aux;
   char *nombre;
   int i,cuantos;
   nombre=Identificador_nombre(Form_nom(snt));
   genera(indentacion,"/************************************************\n");
   genera(indentacion," * Generacion del Form %-20.20s *\n",nombre);
   genera(indentacion," ************************************************/\n");
   genera(indentacion,"_4GLFORM _GenForm_F%s()\n",nombre);
   genera(indentacion++,"{\n");
   genera(indentacion,"_4GLFORM frm;\n");
   genera(indentacion,"_4GLFIELD fld_ptr;\n");
   genera(indentacion,"/* Reservo memoria para el form */\n");
   genera(indentacion,"frm=(_4GLFORM)malloc(sizeof(struct _4GLFORM));\n");
   genera(indentacion,"if (!frm) _4GLerror(\"Sin memoria para crear el form.\");\n");
   genera(indentacion,"frm->campos=NULL;\n");
   genera(indentacion++,"/* Creo los campos */\n");
   cuantos=FormCampos_longitud(Form_campos(snt));
   for (i=1;i<=cuantos;i++)
   {
      aux=FormCampos_elemento(Form_campos(snt),i);
      genera(indentacion++,"/* Campo %d - %s */\n",i,Identificador_nombre(FormCampo_nom(aux)));
      if (i==1)
      {
      	genera(indentacion,"fld_ptr=frm->campos=(_4GLFIELD)malloc(sizeof(struct _4GLFIELD));\n");
        genera(indentacion,"if (!fld_ptr) _4GLerror(\"Sin memoria para crear el form.\");\n");
        genera(indentacion,"fld_ptr->anterior=NULL;\n");
      } 
      else 
      {
      	genera(indentacion,"fld_ptr->sgte=(_4GLFIELD)malloc(sizeof(struct _4GLFIELD));\n");
        genera(indentacion,"if (!fld_ptr->sgte) _4GLerror(\"Sin memoria para crear el form.\");\n");
        genera(indentacion,"fld_ptr->sgte->anterior=fld_ptr;\n");
        genera(indentacion,"fld_ptr=fld_ptr->sgte;\n");
        
      }
      switch(Constructor(FormCampo_tipo(aux)))
      {
      	case FORMINPUT:
            genera(indentacion,"fld_ptr->objeto=CAMPO_TEXTO;\n");
            genera(indentacion,"_4GLstrncpy(fld_ptr->nombre,\"%s\",sizeof(fld_ptr->nombre)-1);\n",Identificador_nombre(FormCampo_nom(aux)));
            genera(indentacion,"fld_ptr->grupo=0;\n");
            genExpresion(FormCampo_y(aux));
            genera(indentacion,"fld_ptr->y=pop_int(pila_exp);\n");
            genExpresion(FormCampo_x(aux));
            genera(indentacion,"fld_ptr->x=pop_int(pila_exp);\n");
            genExpresion(FormCampo_yy(aux));
            genera(indentacion,"fld_ptr->h=pop_int(pila_exp)-(fld_ptr->y)+1;\n");
            genExpresion(FormCampo_xx(aux));
            genera(indentacion,"fld_ptr->w=pop_int(pila_exp)-(fld_ptr->x)+1;\n");
            if (FormCampo_attr(aux)!=NULL)
            {
      	      attr=lee_atributos(FormCampo_attr(aux));
              if (attr.brillo==0)
                 genera(indentacion,"fld_ptr->attr=COLOR_PAIR(%d);\n",attr.color);
              else
                 genera(indentacion,"fld_ptr->attr=COLOR_PAIR(%d)|A_BOLD;\n",attr.color);
            }
            break;
      	case FORMBUTTON:
            genera(indentacion,"fld_ptr->objeto=CAMPO_BOTON;\n");
            genera(indentacion,"_4GLstrncpy(fld_ptr->nombre,\"%s\",sizeof(fld_ptr->nombre)-1);\n",Identificador_nombre(FormCampo_nom(aux)));
            genera(indentacion,"fld_ptr->grupo=0;\n");
            genExpresion(FormCampo_y(aux));
            genera(indentacion,"fld_ptr->y=pop_int(pila_exp);\n");
            genExpresion(FormCampo_x(aux));
            genera(indentacion,"fld_ptr->x=pop_int(pila_exp);\n");
            if (FormCampo_attr(aux)!=NULL)
            {
      	      attr=lee_atributos(FormCampo_attr(aux));
              if (attr.brillo==0)
                 genera(indentacion,"fld_ptr->attr=COLOR_PAIR(%d);\n",attr.color);
              else
                 genera(indentacion,"fld_ptr->attr=COLOR_PAIR(%d)|A_BOLD;\n",attr.color);
            }
            break;
      	case FORMCHECK:
            genera(indentacion,"fld_ptr->objeto=CAMPO_CHECK;\n");
            genera(indentacion,"_4GLstrncpy(fld_ptr->nombre,\"%s\",sizeof(fld_ptr->nombre)-1);\n",Identificador_nombre(FormCampo_nom(aux)));
            genera(indentacion,"fld_ptr->grupo=0;\n");
            genExpresion(FormCampo_y(aux));
            genera(indentacion,"fld_ptr->y=pop_int(pila_exp);\n");
            genExpresion(FormCampo_x(aux));
            genera(indentacion,"fld_ptr->x=pop_int(pila_exp);\n");
            if (FormCampo_attr(aux)!=NULL)
            {
      	      attr=lee_atributos(FormCampo_attr(aux));
              if (attr.brillo == 0)
                 genera(indentacion,"fld_ptr->attr=COLOR_PAIR(%d);\n",attr.color);
              else
                 genera(indentacion,"fld_ptr->attr=COLOR_PAIR(%d)|A_BOLD;\n",attr.color);
            }
            break;
      }
      if (i==cuantos)
         genera(indentacion,"fld_ptr->sgte=NULL;\n");
      indentacion--;
   }
   genera(--indentacion,"/* Todos los campos estan generados */\n");
   genera(indentacion,"/* Llamo a las funciones de la interfaz de usuario (curses/X) \n");
   genera(indentacion,"   para crear las estructuras del sistema */\n");
   genera(indentacion,"_4GLinit_form(frm);\n");
   genera(indentacion,"/* Devuelvo el form recien creado */\n");
   genera(indentacion,"return frm;\n");
   genera(--indentacion,"}\n\n");
}

