/*
 *  * This program connects to the socket named in the command line
 *   * and sends a one line message to that socket.  The form of the
 *    * command line is ustreamwrite pathname.
 *     */
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include "sock_xml.h"
#include "contexts.h"
#include <sys/time.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "json.h"


#define NOPROXY

#ifdef NOPROXY
#ifdef WIN32

#else
#endif /* win32 */
#endif /* NOPROXY */

#include "attr.h"
#include "../debug.h"
#include "../pipe.h"
#include "comms.h"

#define ID_SETYOURID -122
/*
 * Field 
 * SV -> FN (field Name), FT (Field Type),T (touched) + Value
*/


#define MAXLEVELSOFJSON 20
struct s_triggered_value
{
  int level;
  int cnt[MAXLEVELSOFJSON];
  char nextBuff[20];
  char levelId[MAXLEVELSOFJSON][20];
  char lastKey[200];
  struct s_attr attribute;
  int rowNum;
  //int fullPacket;
};

//static struct s_syncvalues syncValues= {0,0};
static struct s_syncvalue syncValue = { 0, 0, 0, -1 };

#ifdef TEST
int pipe_sock_gets (int sockfd, char *str, size_t count) {

 	int bytes_read=recv(sockfd,&str[0],1,0);
printf("%c\n",str[0]);
	return bytes_read;
}
#endif

static void
initialize_attr (struct s_attr *attr)
{
  //printf ("initialize_attr\n");
  attr->id = NULL;
  attr->envelopeId = NULL;
  attr->yourId = NULL;
  attr->data = NULL;
  attr->type = NULL;
  attr->arrline = -1;
  attr->scrline = -1;
  attr->arrcount = -1;
  attr->lastkey = NULL;
  attr->lastcursor = -1;
  attr->infield = NULL;
  attr->fileid = NULL;
  attr->filelen = -1;
  attr->programname = NULL;
  attr->bufferTouched = -1;
  attr->cnt = -1;
  attr->maxcnt = -1;


  attr->sync.nvalues = 0;
  attr->sync.vals = 0;
  attr->rows.nrows = 0;
  attr->rows.row = NULL;
}


static void
free_attr (struct s_attr *attr)
{
  if (attr->id)
    {
      free (attr->id);
      attr->id = NULL;
    }

  if (attr->envelopeId)
    {
      free (attr->envelopeId);
      attr->envelopeId = NULL;
    }

  if (attr->yourId)
    {
      free (attr->yourId);
      attr->yourId = NULL;
    }

  if (attr->data)
    {
      free (attr->data);
      attr->data = NULL;
    }

  if (attr->type)
    {
      free (attr->type);
      attr->type = NULL;
    }

  if (attr->lastkey)
    {
      free (attr->lastkey);
      attr->lastkey = NULL;
    }

  if (attr->infield)
    {
      free (attr->infield);
      attr->infield = NULL;
    }

  if (attr->fileid)
    {
      free (attr->fileid);
      attr->fileid = NULL;
    }

  if (attr->programname)
    {
      free (attr->programname);
      attr->programname = NULL;
    }


}

void
print_id (struct s_triggered_value *userdata)
{
  int a;
  for (a = 1; a <= userdata->level; a++)
    {
      if (a > 1)
	printf (".");
      printf ("%s", userdata->levelId[a]);
      //if (userdata->cnt[a]) { printf("[%d]",userdata->cnt[a]); }
    }
}

static void
setData (struct s_attr *attr, const char *key, int type, const char *value)
{
  if (strcmp (key, "ID") == 0)
    {
      attr->id = strdup (value);
      return;
    }
  if (strcmp (key, "ENVELOPEID") == 0)
    {
      attr->envelopeId = strdup (value);
      return;
    }
  if (strcmp (key, "YOURID") == 0)
    {
      attr->yourId = strdup (value);
      return;
    }
  if (strcmp (key, "TYPE") == 0)
    {
      attr->type = strdup (value);
      return;
    }
  if (strcmp (key, "DATA") == 0)
    {
      attr->data = strdup (value);
      return;
    }
  if (strcmp (key, "SCRLINE") == 0)
    {
      attr->scrline = atoi (value);
      return;
    }
  if (strcmp (key, "ARRLINE") == 0)
    {
      attr->arrline = atoi (value);
      return;
    }
  if (strcmp (key, "ARRCOUNT") == 0)
    {
      attr->arrcount = atoi (value);
      return;
    }
  if (strcmp (key, "LASTKEY") == 0)
    {
      attr->lastkey = strdup (value);
      return;
    }
  if (strcmp (key, "LASTCURSOR") == 0)
    {
      attr->lastcursor = atol (value);
      return;
    }
  if (strcmp (key, "INFIELD") == 0)
    {
      attr->infield = strdup (value);
      return;
    }
  if (strcmp (key, "FILEID") == 0)
    {
      attr->fileid = strdup (value);
      return;
    }
  if (strcmp (key, "BUFFERTOUCHED") == 0)
    {
      attr->bufferTouched = atoi (value);
      return;
    }
  if (strcmp (key, "PROGRAMNAME") == 0)
    {
      attr->programname = strdup (value);
      return;
    }
  if (strcmp (key, "FILELEN") == 0)
    {
      attr->filelen = atoi (value);
      return;
    }
  if (strcmp (key, "CNT") == 0)
    {
      attr->cnt = atoi (value);
      return;
    }
  if (strcmp (key, "MAXCNT") == 0)
    {
      attr->maxcnt = atoi (value);
      return;
    }

  fprintf (stderr, "Unhandled tag on setData : %s\n", key);
  exit (20);
}


static int
parentIs (struct s_triggered_value *userdata, char *s)
{
  int rval = 0;
  if (userdata->level > 1)
    {
      //printf("CHK PARENT userdata->level=%d\n",userdata->level);
      //printf("s=%s\n",s);
      rval = (strcmp (userdata->levelId[userdata->level - 1], s) == 0);
    }
  /*
     if (!rval) {
     printf("%s not parent of ",s);
     print_id(userdata);
     }
   */

  return rval;

}

static void
setSyncData (const char *key, int type, const char *value)
{
  //printf ("setSyncData\n");
  if (strcmp (key, "FN") == 0)
    {
      syncValue.fieldname = strdup (value);
      return;
    }
  if (strcmp (key, "FT") == 0)
    {
      syncValue.fieldtype = atoi (value);
      return;
    }
  if (strcmp (key, "T") == 0)
    {
      syncValue.touched = atoi (value);
      return;
    }
  if (strcmp (key, "Value") == 0)
    {
      syncValue.value = strdup (value);
      return;
    }

  fprintf (stderr, "Unhandled tag on setSyncData : %s\n", key);
  exit (20);
}



static int
my_callback (void *vuserdata, int type, const char *data, uint32_t length)
{
  struct s_triggered_value *userdata;
  userdata = (struct s_triggered_value *) vuserdata;

  switch (type)
    {
    case JSON_OBJECT_BEGIN:
      if (userdata->level == -1)
	{
	  userdata->level = 1;
	}
      else
	{
	  userdata->level++;
	}
      userdata->cnt[userdata->level] = -1;
      break;

    case JSON_ARRAY_BEGIN:
      userdata->level++;
      userdata->cnt[userdata->level] = 0;
      sprintf (userdata->levelId[userdata->level], "%s[]", userdata->lastKey);
	//printf("Array Begin : %s\n", userdata->lastKey);

	/*
      if (strcmp (userdata->lastKey, "SYNCROWS[]") == 0) {
	printf("Init syncrows\n");
      }
	*/

	/*
      if (strcmp (userdata->lastKey, "SVS[]") == 0)
	{
	printf("Here\n");
	  if (userdata->attribute.sync.vals)
	    {
	      int a;
	      for (a = 0; a < userdata->attribute.sync.nvalues; a++)
		{
		  if (userdata->attribute.sync.vals[a].value)
		    free (userdata->attribute.sync.vals[a].value);
		  if (userdata->attribute.sync.vals[a].fieldname)
		    free (userdata->attribute.sync.vals[a].fieldname);
		}
	      free (userdata->attribute.sync.vals);
	    }
	  userdata->attribute.sync.vals = 0;
	  userdata->attribute.sync.nvalues = 0;
	}
	*/
      break;

    case JSON_ARRAY_END:
      userdata->level--;
      break;

    case JSON_OBJECT_END:
      userdata->level--;


/*
      if (userdata->level > 0)
	{
	  printf ("OBJECT END - parent=%s\n", userdata->levelId[userdata->level - 1]);
	}
      print_id (userdata);
*/

      if (parentIs (userdata, "SYNCROWS"))
        {

	  userdata->attribute.rows.nrows++;
	  userdata->attribute.rows.row = realloc (userdata->attribute.rows.row, sizeof (struct s_row) * userdata->attribute.rows.nrows);
		printf("Adding row got %d values @ %d subscript is %d\n", userdata->attribute.sync.nvalues, userdata->attribute.rows.nrows - 1, userdata->rowNum);
	  userdata->attribute.rows.row[userdata->attribute.rows.nrows - 1].rownum=userdata->rowNum;
	  userdata->attribute.rows.row[userdata->attribute.rows.nrows - 1].sync.nvalues=userdata->attribute.sync.nvalues;
	  userdata->attribute.rows.row[userdata->attribute.rows.nrows - 1].sync.vals=userdata->attribute.sync.vals;
	  userdata->attribute.sync.nvalues=0;
	  userdata->attribute.sync.vals=0;
	}

      if (parentIs (userdata, "SVS"))
	{
	  userdata->attribute.sync.nvalues++;
	  userdata->attribute.sync.vals = realloc (userdata->attribute.sync.vals, sizeof (struct s_syncvalue) * userdata->attribute.sync.nvalues);
	  userdata->attribute.sync.vals[userdata->attribute.sync.nvalues - 1].fieldname = syncValue.fieldname;
	  userdata->attribute.sync.vals[userdata->attribute.sync.nvalues - 1].value = syncValue.value;
	  userdata->attribute.sync.vals[userdata->attribute.sync.nvalues - 1].fieldtype = syncValue.fieldtype;
	  userdata->attribute.sync.vals[userdata->attribute.sync.nvalues - 1].touched = syncValue.touched;

	  syncValue.touched = 0;
	  syncValue.fieldtype = -1;
	  syncValue.value = 0;
	  syncValue.fieldname = 0;
	}
      break;


    case JSON_KEY:

      strcpy (userdata->lastKey, data);
      strcpy (userdata->levelId[userdata->level], data);
      break;

    case JSON_STRING:
    case JSON_INT:
    case JSON_FLOAT:
      if (userdata->level == 1)
	{
	  setData (&userdata->attribute, userdata->lastKey, type, data);
	}
      else
	{
	  if (parentIs (userdata, "SVS[]"))
	    {
	      setSyncData (userdata->lastKey, type, data);
	    }
	  else
	    {
	  if (parentIs (userdata, "SYNCROWS[]"))
	    {
	      userdata->rowNum=atol(data);
	      //....
	    } else {
		}
}
	}
      //print_id (userdata);
      //userdata->cnt[userdata->level]++;
      //printf ("   = %*s\n", length, data);
      break;

    case JSON_NULL:
      //print_id (userdata);
      if (userdata->level == 1)
	{
	  setData (&userdata->attribute, userdata->lastKey, type, "");
	}
      else
	{
	  if (parentIs (userdata, "SVS[]"))
	    {
	      setSyncData (userdata->lastKey, type, "");
	    }
	}
      //printf("%s value @ %d - level %d\n", userdata->lastKey, userdata->cnt[userdata->level], userdata->level);
      //userdata->cnt[userdata->level]++;
      //printf ("   =constant null\n");
      break;

    case JSON_TRUE:
      //print_id (userdata);
      if (userdata->level == 1)
	{
	  setData (&userdata->attribute, userdata->lastKey, type, "1");
	}
      else
	{
	  if (parentIs (userdata, "SVS[]"))
	    {
	      setSyncData (userdata->lastKey, type, "1");
	    }
	}

      //printf("%s value @ %d - level %d\n",  userdata->lastKey,userdata->cnt[userdata->level], userdata->level);
      //userdata->cnt[userdata->level]++;
      //printf ("  =constant true\n");
      break;

    case JSON_FALSE:
      //print_id (userdata);
      if (userdata->level == 1)
	{
	  setData (&userdata->attribute, userdata->lastKey, type, "0");
	}
      else
	{
	  if (parentIs (userdata, "SVS[]"))
	    {
	      setSyncData (userdata->lastKey, type, "0");
	    }
	}
      //printf("%s value @ %d - level %d\n",  userdata->lastKey,userdata->cnt[userdata->level], userdata->level);
      //userdata->cnt[userdata->level]++;
      //printf ("  =constant false\n");
      break;
    }


  return 0;
}


static void
printPacket (struct s_attr *attribute)
{
int a;
int b;
printf("id=%s envelopeid=%s yourid=%s data=%s type=%s\n",attribute->id, attribute->envelopeId, attribute->yourId, attribute->data, attribute->type);
printf("arrline=%d scrline=%d arrcount=%d\n", attribute->arrline, attribute->scrline, attribute->arrcount);
printf("lastcursor=%d lastkey=%s infield=%s bufferTouched=%d\n", attribute->lastcursor ,attribute->lastkey,attribute->infield, attribute->bufferTouched);
printf("fileid=%s filelen=%d\n",attribute->fileid,attribute->filelen);
printf("programname=%s\n",attribute->programname);
printf("Cnt=%d of %d\n", attribute->cnt, attribute->maxcnt);

if (attribute->sync.nvalues) {
	for (a=0;a<attribute->sync.nvalues;a++) {
		printf("%s %s %d %d\n", attribute->sync.vals[a].value, attribute->sync.vals[a].fieldname, attribute->sync.vals[a].touched, attribute->sync.vals[a].fieldtype);
	}
}
if (attribute->rows.nrows) {
	for (b=0;b<attribute->rows.nrows;b++) {
		printf("Row : %d\n",attribute->rows.row[b].rownum);
		for (a=0;a<attribute->rows.row[b].sync.nvalues;a++) {
			printf("   %s %s %d %d\n", attribute->rows.row[b].sync.vals[a].value, attribute->rows.row[b].sync.vals[a].fieldname, attribute->rows.row[b].sync.vals[a].touched, attribute->rows.row[b].sync.vals[a].fieldtype);
		}
		
	}
}
printf("-----------------\n");
}

struct s_attr *
getTriggeredAttribute (int  sock_read)
{
  static char *localbuff_f = 0;
  int containsslashTriggered = 0;
  static char buff[25600];
  int l;
  static json_parser parser;
  int initParser = 0;

  static struct s_triggered_value triggeredValue;
  triggeredValue.level = -1;


  static int firstOne=1;
  if (firstOne) {
      initialize_attr (&triggeredValue.attribute);
      firstOne=0;
      triggeredValue.cnt[0] = 0;
      strcpy (triggeredValue.levelId[0], "root");
  } else {
	  if (triggeredValue.attribute.sync.vals)
	    {
	      int a;
	      for (a = 0; a < triggeredValue.attribute.sync.nvalues; a++)
		{
		  if (triggeredValue.attribute.sync.vals[a].value) {
		    free (triggeredValue.attribute.sync.vals[a].value); 
                    triggeredValue.attribute.sync.vals[a].value=0;
                  }
		  if (triggeredValue.attribute.sync.vals[a].fieldname) {
		    free (triggeredValue.attribute.sync.vals[a].fieldname);
                    triggeredValue.attribute.sync.vals[a].fieldname=0;
                  }
		}
	      free (triggeredValue.attribute.sync.vals);
	      triggeredValue.attribute.sync.vals=0;
	    }
	  triggeredValue.attribute.sync.vals = 0;
	  triggeredValue.attribute.sync.nvalues = 0;
	  free_attr(&triggeredValue.attribute);
	}
      triggeredValue.rowNum=-1;

  

      if (json_parser_init (&parser, NULL, my_callback, &triggeredValue))
	{
	  fprintf (stderr, "Internal error - unable to initialze json parser\n");
	  exit (2);
	}
    



  int ret;
  while (1)
    {
      if (!pipe_sock_gets (sock_read, buff, 25500))
      //if (!fgets (buff, 25500, fin))
	{
	  //cleanup ();
	  fprintf (stderr, "Internal error - unable to read fin");
	  exit (0);
	}
      //strcpy(buff, "{ \"key\": 123 }");
      //printf("Forcing to --->%s<---\n", buff);
	fprintf(stderr,"READ : %s\n", buff);
      ret = json_parser_string (&parser, buff, strlen (buff), NULL);
      if (ret)
	{
	  fprintf (stderr, "Internal error - unable to parse string \n");
	  fprintf (stderr, "%s\n", buff);
	  exit (2);
	}
      if (json_parser_is_done (&parser))
	break;
    }
  printf ("Got full packet\n");
  //printPacket (&triggeredValue.attribute);

  json_parser_free(&parser);

  return &triggeredValue.attribute;
}


#ifdef TEST



FILE *f;
main ()
{
  f = fopen ("input3.json", "r");
  while (!feof(f)) {
	struct s_attr *attr;
	attr=getTriggeredAttribute (fileno(f));
        printPacket (attr);
  }
}



#endif



