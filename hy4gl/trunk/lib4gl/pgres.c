/*****************************************************************/
/* Libreria de funciones de interfaz con Postgres para el 4GL    */
/*****************************************************************/
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <panel.h>
#include <libpq-fe.h>
#include <hy4gl.h>

extern int status, notfound, found, ok;
extern bool _4GLfechaEuro;
extern bool _4GLChkErrores;
static int _4GLTransaction=0;

PGconn *_4GLsetdb(char *db)
{
   static PGconn *conn;
   conn=PQsetdb(getenv("_4GLHOST"),getenv("_4GLPORT"),getenv("_4GLOPTIONS"),
      	getenv("_4GLTTY"),db);
   if (PQstatus(conn)==CONNECTION_BAD)
      _4GLerror("Error. No puede conectarse con la base de datos %s\n\n%s",
         db,PQerrorMessage(conn));
   if (getenv("HYDEBUG"))
      PQtrace(conn,stderr);
   return conn;
}

void _4GLclosecursor(_CURSOR cur)
{
   PQclear(cur.res);
}

char * _4GLsqlErrorStr(PGconn *_conn)
{
   return PQerrorMessage(_conn);
}


_CURSOR *_4GLcursor(PGconn *_conn,char *query, _CURSOR *res)
{
   if (res==NULL)
   {
      res=(_CURSOR *)malloc(sizeof (_CURSOR));
   }            

   _4GLstrncpy(res->query,query,sizeof(res->query)-1);
   res->conn=_conn;
   res->res=PQexec(_conn,query);
   if (res->res)
   {
      res->status=PQresultStatus(res->res);
      res->ntuples=PQntuples(res->res);
      if ((res->ntuples==0) && (!strncasecmp(query,"select",6)))
         res->status=PGRES_EMPTY_QUERY;
      else if ((res->ntuples==0) && (!strncasecmp(query,"fetch",5)))
         res->status=PGRES_EMPTY_QUERY;
      res->nfields=PQnfields(res->res);
      res->actual=1;
      if ((res->status==PGRES_BAD_RESPONSE)||(res->status==PGRES_FATAL_ERROR))
      {
         _4GLerror("Error del servidor de bases de datos\n%s\n",PQerrorMessage(_conn));
      }
   }
   else
   {
      res->status=PGRES_EMPTY_QUERY;
      res->ntuples=0;
      res->nfields=0;
      res->actual=0;
   }
   status=res->status;
   return res;
}

/* Funcion que ejecuta una query y no devuelve nada. 
   (para los 'insert', 'delete', 'begin' y esas cosas)
   Actualiza la variable 'status' */
void _4GLexec(PGconn *_conn,char *query)
{
   _CURSOR res;
   res.conn=_conn;
   res.res=PQexec(_conn,query);
   if (res.res)
   {
      res.status=PQresultStatus(res.res);
      res.ntuples=PQntuples(res.res);
      if ((res.ntuples==0) && (!strncasecmp(query,"select",6)))
         res.status=PGRES_EMPTY_QUERY;
      else if ((res.ntuples==0) && (!strncasecmp(query,"fetch",5)))
         res.status=PGRES_EMPTY_QUERY;
      res.nfields=PQnfields(res.res);
      res.actual=1;
      if ((res.status==PGRES_BAD_RESPONSE)||(res.status==PGRES_FATAL_ERROR))
      {
         _4GLerror("Error del servidor de bases de datos\n%s\n",PQerrorMessage(_conn));
      }
   }
   else
   {
      res.status=PGRES_EMPTY_QUERY;
      res.ntuples=0;
      res.nfields=0;
      res.actual=0;
   }
   status=res.status;
   if (_4GLChkErrores && (status!=ok) )
      _4GLalert("La peticion '%s' ha devuelto un error\n%s",query,_4GLsqlErrorStr(_conn));
   _4GLclear(res);
   return;
}

void _4GLclear(_CURSOR cur)
{
   PQclear(cur.res);
}

void _4GLbegin_transaction(PGconn *c)
{
   if (_4GLTransaction!=0)
      _4GLalert("'BEGIN TRANSACTION' anidados.\nSe ignora este");
   else
      _4GLexec(c,"begin transaction;");

   _4GLTransaction++;
}

void _4GLend_transaction(PGconn *c)
{
   if (_4GLTransaction!=1)
      _4GLalert("'END TRANSACTION' anidados.\nSe ignora este");
   else
      _4GLexec(c,"end transaction;");
   
   _4GLTransaction--;
}

void _4GLcommit_transaction(PGconn *c)
{
   if (_4GLTransaction!=1)
      _4GLalert("'END TRANSACTION' anidados.\nSe ignora este");
   else
      _4GLexec(c,"commit;");
   
   _4GLTransaction--;
}

void _4GLabort_transaction(PGconn *c)
{
   if (_4GLTransaction!=1)
      _4GLalert("'END TRANSACTION' anidados.\nSe ignora este");
   else
      _4GLexec(c,"abort transaction;");
   
   _4GLTransaction--;
}

/************ Comprobación de errores *******************/
void _4GLchkInsert(char *sel)
{
   if (status!=PGRES_COMMAND_OK)
      _4GLerror("Error al ejecutar\n\n%s\n\nNo se ha insertado el registro.",sel);
}
void _4GLchkUpdate(char *sel)
{
   if (status!=PGRES_COMMAND_OK)
      _4GLerror("Error al ejecutar\n\n%s\n\nNo se ha modificado la tabla.",sel);
}

