/**
 * @file
 * GUI user interface IO with a thin client.
 *
 * The purpose of this file is to implement a comunication layer with a 
 * thin client.
 *
 * It is necessary make some restructuring in order to put this to work.
 * In the meanwhile this is a begining.
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
 */


#include <stdarg.h>
#include <stdio.h>
#include "../libincl/debug.h"
//#include "form.h"


/**
 * Send a message to the TCP client.
 * @param c The comand to send.
 * @param s The parameters of the comand.
 */
gui_send(char *c,char *s) {
  char buff[25600];
  sprintf(buff,"%s %s\n",c,s);
  proc_it(buff);

  /*
  strcat(buffer,buff);
  if (strcmp(c,"REFRESH")==0||strcmp(c,"WREFRESH")==0||strcmp(c,"ERROR")==0) {
     debug("Calling proc_it with %s",buff);
     proc_it(buffer);
     buffer[0]=0;
  }
  */
  debug("Sent");
}

/**
 * Send the COLOUR modification to the client.
 *
 * @param a The color code to send to the client.
 */
gui_setcolor(int a) {
  char buff[256];
  sprintf(buff,"%d",a);
  gui_send("COLOUR",buff);
  debug("Set color..");
}

gui_actmenu(long ld) {
char buff[256];
sprintf(buff,"%lx",ld);
gui_send("MENUACT",buff);
}

gui_mkfield(int h,int w,int y,int x,void *p) {
char buff[256];
sprintf(buff,"%lx %d %d %d %d",p,x,y,w,h);
debug("gui_mkfield:Make field");
gui_send("MKFIELD",buff);
}

gui_mklabel(int h,int w,int y,int x,char *s) {
char buff[256];
sprintf(buff,"\"%s\" %d %d %d %lx",s,x,y,w,h);
gui_send("MKLABEL",buff);
}


gui_wrefresh(void *d) {
char buff[256];
sprintf(buff,"%lx",d);
#ifdef DEBUG
/* {DEBUG} */ {debug("gui_refresh");
}
#endif
     gui_send("WREFRESH",buff);
}


gui_refresh() {
#ifdef DEBUG
/* {DEBUG} */ {debug("gui_refresh");
}
#endif
      gui_send("REFRESH","");
}

gui_print (int a,char *fmt,...)
{
  va_list args;
  char buff[25600];
  char buff2[25600];
#ifdef DEBUG
/* {DEBUG} */ {  debug("Format =%s",fmt);
}
#endif
  va_start (args, fmt);
  vsprintf (buff,fmt, args);
  va_end(args);
  sprintf(buff2,"%d \"%s\"",a,buff);
#ifdef DEBUG
/* {DEBUG} */ {  debug("Sending %s",buff2);
}
#endif
  gui_send("PRINT",buff2);
}


gui_move(int x,int y) {
char buff[256];
sprintf(buff,"%d %d",x,y);
gui_send("MOVE",buff);
}

gui_win(char *name,int h,int w,int y,int x,int b,long d) {
char buff[256];
sprintf(buff,"%s %d %d %d %d %d %lx",name,x,y,w,h,b,d);
debug("Sending %s",buff);
gui_send("MKWIN",buff);
}

gui_endmenu(long ld) {
char buff[256];
sprintf(buff,"%lx",ld);
gui_send("ENDMENU",buff);
}

gui_startform(char *name) {
char buff[256];

sprintf(buff,"%s",name);

gui_send("STARTFORM",buff);
}

gui_endform() {
gui_send("ENDFORM","");
}

gui_startmenu(char *mnname,long mn) {
char buff[256];
sprintf(buff,"\"%s\" %lx",mnname,mn);
gui_send("MKMENU",buff);
}

gui_rmmenu(long ld) {
char buff[256];
sprintf(buff,"%lx",ld);
gui_send("RMMENU",buff);
}


gui_menuopt(char *title,long id) {
char buff[256];

sprintf(buff,"\"%s\" %lx",title,id);
debug("Menu opt %s ",buff);
gui_send("MKOPT",buff);
}

gui_dispform(char *s,int line) {
char buff[256];
sprintf(buff,"%s %d",s,line);
gui_send("DISPFORM",buff);
}

gui_setbuff(void *a,char *n) {
char buff[1024];
sprintf(buff,"%lx %s",a,n);
gui_send("SETBUFF",buff);
}

gui_closewin(char *name) {
gui_send("RMWIN",name);
}

gui_currwin(long a) {
char buff[1024];
sprintf(buff,"%lx",a);
gui_send("CURRWIN",buff);
}

gui_scroll(int a) {
char buff[1024];
sprintf(buff,"%d",a);
gui_send("SCROLL",buff);
}

gui_scrollpos(int a) {
char buff[1024];
sprintf(buff,"%d",a);
gui_send("SCROLLPOS",buff);
}

gui_setattr(long a,int f,int b) {
char buff[256];
sprintf(buff,"%lx %d %d",a,f,b);
gui_send("SETATTR",buff);
}

gui_startprompt(long ld) {
char buff[256];
sprintf(buff,"%lx",ld);
gui_send("STARTPROMPT",buff);
}
gui_endprompt(long ld) {
char buff[256];
sprintf(buff,"%lx",ld);
gui_send("ENDPROMPT",buff);
}

gui_setfocus(long ld) {
char buff[256];
debug("gui_set focus %lx",ld);
sprintf(buff,"%lx",ld);
gui_send("SETFOCUS",buff);
}

gui_setposition(long ld) {
char buff[256];
debug("gui_set position %lx",ld);
sprintf(buff,"%lx",ld);
gui_send("SETPOSITION",buff);
}

gui_message(char *txt,int msgline) {
char buff[256];
char buff2[256];
strcpy(buff2,txt);
trim(buff2);
sprintf(buff,"\"%s\" %d",buff2,msgline);
gui_send("MESSAGE",buff);
}


/**
 * Send an error to the client.
 * 
 * @param txt The error text.
 * @param errline The place where the error ocurred.
 */
gui_error(char *txt,int errline) {
char buff[256];
char buff2[256];
strcpy(buff2,txt);
trim(buff2);
debug("In gui_error");
sprintf(buff,"\"%s\" %d",buff2,errline);
gui_send("ERROR",buff);
}


gui_user(char *txt) {
char buff[256];
gui_send("USER",txt);
}




