/*************************************************************
 *              Funciones de manejo de menus.                *
 *************************************************************/
#include <hy4gl.h>
#include <stdlib.h>
#include <malloc.h>
#include <menu.h>
 
extern WINDOW *curwin;
extern _WINDOW *_curwin;
 
int _4GLmueve_menu(_MENU m)
{
   int poner_desc=1,max_y,max_x;
   int c, salir;
   salir=0;
   c=0;
   redrawwin(m.sub);
   update_panels();
   doupdate();
   while (!salir)
   {
      if (poner_desc && item_description(current_item(m.menu)))
      {
      	if (m.format==0) /* Horizontal */
            wmove(m.sub,1,0);
         else /* Vertical o cuadrado */
         {
            getmaxyx(m.sub,max_y,max_x);
            wmove(m.sub,max_y-1,0);
            wclrtoeol(m.sub);
            wmove(m.sub,max_y-1,max(1,(max_x-strlen(item_description(current_item(m.menu))))/2));
         }
         wclrtoeol(m.sub);
         wprintw(m.sub,"%s",item_description(current_item(m.menu)));
         redrawwin(m.sub);
         update_panels();
         doupdate();
         poner_desc=0;
      }
      c=getch();
      switch(c)
      {
      	case KEY_PREVIOUS:
      	case KEY_UP:
            menu_driver(m.menu,REQ_UP_ITEM);
            poner_desc=1;
            break;
        case KEY_RIGHT:
            if (menu_driver(m.menu,REQ_RIGHT_ITEM)!=E_OK)
               if (menu_driver(m.menu,REQ_DOWN_ITEM)!=E_OK)
                  menu_driver(m.menu,REQ_FIRST_ITEM);
               else	
                  while (menu_driver(m.menu,REQ_LEFT_ITEM)==E_OK);
            poner_desc=1;
           break;
        case KEY_NEXT:
      	case KEY_DOWN:
            menu_driver(m.menu,REQ_DOWN_ITEM);
            poner_desc=1;
            break;
         case KEY_LEFT:
            if (menu_driver(m.menu,REQ_LEFT_ITEM)!=E_OK)
               if (menu_driver(m.menu,REQ_UP_ITEM)!=E_OK)
                  menu_driver(m.menu,REQ_LAST_ITEM);
               else
                  while (menu_driver(m.menu,REQ_RIGHT_ITEM)==E_OK);
            poner_desc=1;
            break;
         default: salir=1;
            break;
      }
      redrawwin(m.sub);
      update_panels();
      doupdate();
   }
   
   if (c==27)
     return 0;
   else if (c==13)
      return -1*(item_index(current_item(m.menu))+1);
   else
      return c;
}

/* Función que crea las ventanas asociadas al menu, y 
   las enlaza con el propio menu */
void _4GLset_menu(_MENU *m)
{
   attr_t attrib;
   short pair;
   char opts[1024];
   
   int max_y, max_x;
   int y,x;
   /* Miro cuanto ocuparia el menu */
   scale_menu(m->menu,&y,&x);
   /* Y el tamanno de la ventana */
   getmaxyx(curwin,max_y,max_x);

   m->win=_curwin->wb; 
   m->sub=_curwin->w;

   /* Si el menu es horizontal... */
   switch (m->format)
   {
   case 0: /* Horizontal */
      /* Caben max_x/x elementos en cada linea */
      /* Creo las ventanas para el menu */
      set_menu_format(m->menu,1,max(1,(int)(max_x/x)));
      break;
   case 1: /* vertical */
      /* Caben max_y-1 elementos en la ventana (una linea para la descripc)*/
      /* Creo las ventanas para el menu */
      set_menu_format(m->menu,max_y-1,1);
      break;
   case 2: /* Cuadrado */
      /* Caben max_x/x elementos en cada linea */
      /* Creo las ventanas para el menu */
      set_menu_format(m->menu,max_y-1,max(1,(int)(max_x/x)));
      break;
   }
   set_menu_win(m->menu,m->win);
   set_menu_sub(m->menu,m->sub);
   /* Pongo los mismos colores que la ventana */
   set_menu_back(m->menu,wattr_get(_curwin->wb, &attrib, &pair, opts));
   set_menu_fore(m->menu,wattr_get(_curwin->wb, &attrib, &pair, opts)|A_STANDOUT);
}
