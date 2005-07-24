/* Funciones de manejo de forms */
#include "ncurses.h"
#include "form.h"
#include "hy4gl.h"


extern WINDOW *curwin;

/* Funcion _4GLcreate_form.
 * Recibe una lista de campos.
 * Crea el form en memoria, con llamadas a las funciones de las curses.
 * Devuelve un puntero al FORM creado.
 */
void _4GLinit_form(_4GLFORM f)
{
   _4GLFIELD campos;
   _4GLFIELD aux;
   int i;
   FIELD **array_campos;
   
   i=0;
   campos=f->campos;
   aux=campos;
   /* Recorro la lista de campos para ver cuantos hay */
   while (aux)
   { 
     aux=aux->sgte;
     i++;
   }
   /* Reservo memoria para el array de campos */
   array_campos=malloc((i+1)*sizeof(FIELD*));

   /* Recorro la lista de campos, y los voy creando */
   i=0;
   aux=campos;
   while (aux)
   { 
     switch(aux->objeto)
     {
        case CAMPO_TEXTO:
           array_campos[i]=aux->campo=new_field(aux->h,aux->w,aux->y,aux->x,0,0);
           set_field_fore(array_campos[i],aux->attr);
           set_field_back(array_campos[i],aux->attr);
           set_field_pad(array_campos[i],aux->attr);
           field_opts_off(array_campos[i],O_AUTOSKIP);
           field_opts_on(array_campos[i],O_PUBLIC|O_VISIBLE|O_EDIT|O_ACTIVE|O_NULLOK);
           set_field_userptr(array_campos[i],aux);
           /* El campo apunta al elemento de la lista de objetos del form */
           i++;
           break;
        case CAMPO_BOTON:
           array_campos[i]=aux->campo=new_field(1,strlen(aux->nombre),aux->y,aux->x,0,0);
           set_field_fore(array_campos[i],aux->attr);
           set_field_back(array_campos[i],aux->attr);
           set_field_pad(array_campos[i],aux->attr);
           field_opts_off(array_campos[i],O_AUTOSKIP|O_EDIT);
           field_opts_on(array_campos[i],O_PUBLIC|O_VISIBLE|O_ACTIVE|O_NULLOK);
           set_field_buffer(array_campos[i],0,aux->nombre);
           set_field_userptr(array_campos[i],aux);
           /* El campo apunta al elemento de la lista de objetos del form */
           i++;
           break;
        case CAMPO_CHECK:
           array_campos[i]=aux->campo=new_field(1,1,aux->y,aux->x,0,0);
           set_field_fore(array_campos[i],aux->attr);
           set_field_back(array_campos[i],aux->attr);
           set_field_pad(array_campos[i],aux->attr);
           field_opts_off(array_campos[i],O_AUTOSKIP);
           field_opts_on(array_campos[i],O_PUBLIC|O_EDIT|O_VISIBLE|O_ACTIVE|O_NULLOK);
           set_field_userptr(array_campos[i],aux);
           /* El campo apunta al elemento de la lista de objetos del form */
           i++;
           break;
        default:
           break;
     }
     aux=aux->sgte;
   }
   array_campos[i]=NULL;
   f->form=new_form(array_campos);
   if (f->form==NULL)
   {
      _4GLerror("Sin memoria para crear un nuevo form");
   }
   
}

/* Funcion que muestra un form en pantalla */
void _4GLshow_form(_4GLFORM f)
{
   set_form_win(f->form,curwin);
   set_form_sub(f->form,curwin);   
   if (post_form(f->form) != E_OK)
      _4GLerror ("Error. No se puede mostrar el form en pantalla.");
   update_panels();
   doupdate();
}

/* Funcion que oculta un form de pantalla */
void _4GLhide_form(_4GLFORM f)
{
   unpost_form(f->form);
}
/* Funcion que borra el contenido de un form (solo los campos de texto) */
void _4GLFormClean(_4GLFORM f)
{
   _4GLFIELD campo;
   campo=f->campos;
   while (campo)
   {
     if ((campo->objeto==CAMPO_TEXTO) || (campo->objeto==CAMPO_CHECK))
        set_field_buffer(campo->campo,0,"");     
     campo=campo->sgte;
   }
}


/* Funcion que asigna una cadena a un campo, segun el nombre */
void _4GLFormAssign(_4GLFORM f,char *nomcampo, char *cadena)
{
   bool sw_cambiado;
   _4GLFIELD campo;
   sw_cambiado=FALSE;
   campo=f->campos;
   while (campo)
   {
     if (!strcasecmp(campo->nombre, nomcampo))
     {
        sw_cambiado=TRUE;
        switch (campo->objeto)
        {
          case CAMPO_TEXTO:
             set_field_buffer(campo->campo,0,cadena);
             break;
          case CAMPO_CHECK:
             if (strcmp(cadena,"0"))
                set_field_buffer(campo->campo,0,"X");
             else
                set_field_buffer(campo->campo,0," ");
             break;
          default:
             set_field_buffer(campo->campo,0,cadena);
             break;
        }
     }
     campo=campo->sgte;
   }
   if (!sw_cambiado)
      _4GLerror("No se encuentra el campo '%s' en el form activo.",nomcampo);
}

/* Funcion que devuelve el contenido de un campo, segun el nombre */
char *_4GLFormFieldValue(_4GLFORM f,char *nomcampo)
{
   bool sw_encontrado;
   _4GLFIELD campo;
   char *res;

   sw_encontrado=FALSE;
   campo=f->campos;
   while (campo)
   {
     if (!strcasecmp(campo->nombre, nomcampo))
     {
        sw_encontrado=TRUE;
        switch (campo->objeto)
        {
          case CAMPO_CHECK:
             if (!strcmp(field_buffer(campo->campo,0),"X"))
                res="1";
             else
                res="0";
             break;
          case CAMPO_TEXTO:
          default:
             res=field_buffer(campo->campo,0);
             break;
        }
     }
     campo=campo->sgte;
   }
   if (!sw_encontrado)
      _4GLerror ("No se encuentra el campo '%s' en el form activo.",nomcampo);
   return res;
}

/* Funcion que pone un campo como ReadOnly o como editable */
void _4GLFormReadOnly(_4GLFORM f,char *nomcampo,int readonly)
{
   bool sw_cambiado;
   _4GLFIELD campo;

   sw_cambiado=FALSE;
   campo=f->campos;
   
   while (campo)
   {
     if (!strcasecmp(campo->nombre, nomcampo) || !strcmp(nomcampo,"*"))
     {
        sw_cambiado=TRUE;
        switch (campo->objeto)
        {
          case CAMPO_TEXTO:
          case CAMPO_CHECK:
             if (readonly!=0)
                field_opts_off(campo->campo,O_ACTIVE);
             else 
                field_opts_on(campo->campo,O_ACTIVE);
             break;
          default:
             break;
        }
     }
     campo=campo->sgte;
   }
   if (!sw_cambiado)
      _4GLerror ("No se encuentra el campo '%s' en el form activo.",nomcampo);
}

/* _4GLdrive_form_input(Form, tecla) 
   Funcion de manejo de las teclas pulsadas dentro de un campo tipo 'input'
   Esta función recibe como parametro un form y un codigo de una tecla.
   Segun la tecla pulsada realiza una accion en el form. */
void _4GLdrive_form_input(_4GLFORM f, int tecla)
{
   int comando;

   switch(tecla)
   {
      case KEY_UP: 
         comando=REQ_PREV_FIELD;
         break;

      case KEY_DOWN: 
         comando=REQ_NEXT_FIELD;
         break;

      case KEY_LEFT: 
         comando=REQ_PREV_CHAR;
         break;

      case KEY_RIGHT: 
         comando=REQ_NEXT_CHAR;
         break;

      case KEY_END: 
         comando=REQ_END_FIELD;
         break;

      case KEY_HOME: 
         comando=REQ_BEG_FIELD;
         break;

      case KEY_ENTER:
      case 13:
         comando=REQ_NEXT_FIELD;
         break;
      case KEY_BACKSPACE:
         comando=REQ_DEL_PREV;
         break;
      case 27:
         set_field_buffer(f->campo_activo->campo,0,field_buffer(f->campo_activo->campo,0));
         break;            
      default: 
         if (f->campo_activo->objeto==CAMPO_CHECK)
         {
            if (*field_buffer((f->campo_activo)->campo,0)=='X')
            {
               tecla=' ';
               set_field_buffer(f->campo_activo->campo,0," ");
            }
            else
            {
               tecla='X';
               set_field_buffer(f->campo_activo->campo,0,"X");
            }
         }
         comando=tecla;
         break;
   }
   form_driver(f->form,comando);
   form_driver(f->form,REQ_VALIDATION);
   f->campo_activo=_4GLcurrent_field(f);   
   touchwin(curwin);
}

/* Funcion que devuelve el campo activo en un form */
_4GLFIELD _4GLcurrent_field(_4GLFORM f)
{
   return (_4GLFIELD)field_userptr(current_field(f->form));
}
/* Funcion que activa un campo en un form (le pasa el 'focus') */
void _4GLset_current_field(_4GLFORM f, char *campo)
{
   _4GLFIELD c;
   c=f->campos;
   while (c)
   {
      if (!strcmp(c->nombre,campo))
      {
      	f->campo_activo=c;
         set_current_field(f->form,c->campo);
      }
      c=c->sgte;
   }
}
