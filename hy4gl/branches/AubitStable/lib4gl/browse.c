/*************************************************************
 *              Funciones de manejo de browses.              *
 *************************************************************/
#include <hy4gl.h>
#include <stdlib.h>
#include <malloc.h>
 
extern WINDOW *curwin;

 
/* Función que actualiza las variables de control */
void _4GLset_browse(_BROWSE *b)
{
   int max_x, max_y;
   int x,y;
   /* Miro el tamanno de la ventana */
   b->win=curwin;
   b->actual=0;
   b->accion=BRW_REDRAW;
   b->tecla=0;
   b->linea=NULL;
   b->max_length=0;
   b->x_offset=0;
   getbegyx(curwin,y,x);
   getmaxyx(curwin,max_y,max_x);
   if (b->max_x==0)
      b->max_x=max_x;
   else
      b->max_x=_4GLmin(b->max_x,max_x) - (b->x);
      
   if (b->max_y==0)
      b->max_y=(max_y)-(b->y);
   else
      b->max_y=(_4GLmin(b->max_y,max_y)) - (b->y);
}
