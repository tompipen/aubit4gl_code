#ifndef __A4GL_CURL__
#define __A4GL_CURL__
#include <curl/curl.h>

enum fcurl_type_e
{ CFTYPE_NONE = 0, CFTYPE_FILE = 1, CFTYPE_CURL = 2 };

struct fcurl_data
{
  enum fcurl_type_e type;       /* type of handle */
  union
  {
    CURL *curl;
    FILE *file;
  } handle;                     /* handle */

  char *buffer;                 /* buffer to store cached data */
  int buffer_len;               /* currently allocated buffers length */
  int buffer_pos;               /* end of data in buffer */
  int still_running;            /* Is background url fetch still in progress */
};

typedef struct fcurl_data URL_FILE;

URL_FILE *url_fopen (char *url, const char *operation);
int url_fclose (URL_FILE * file);
int url_feof (URL_FILE * file);
size_t url_fread (void *ptr, size_t size, size_t nmemb, URL_FILE * file);
char *url_fgets (char *ptr, int size, URL_FILE * file);
void url_rewind (URL_FILE * file);

#endif
