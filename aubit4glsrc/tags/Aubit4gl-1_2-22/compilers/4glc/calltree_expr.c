
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"
//#include "cmds.x.h"
#include "a4gl_4glc_int.h"
#include "lint.h"
char *expr_get_variable_usage_as_string (struct variable_usage *var_usage) ;
//static char *local_field_name_list_as_char(struct fh_field_list *fl) ;

char *
upshift (char *a)
{
  int i;
  static char buff[256];
  strcpy (buff, a);
  for (i = 0; i < strlen (buff); i++)
    {
      buff[i] = a4gl_toupper (buff[i]);
    }
  return buff;
}

/**
 *  * Downshift a string.
 *   *
 *    * @param a The string to be downshifted.
 *     * @return A pointer to a staic buffer where the string downshifted is putted.
 *      */
char *
downshift (char *a)
{
  int i;
  static char buff[256];
  strcpy (buff, a);
  for (i = 0; i < strlen (buff); i++)
    {
      buff[i] = a4gl_tolower (buff[i]);
    }
  return buff;
}





#define ET_EXPR_VARIABLE_USAGE_call expr_get_variable_usage_as_string


#include "expr_as_string_when_possible.c"


char *expr_get_variable_usage_as_string (struct variable_usage *var_usage) {
        char buff[2000];


        sprintf(buff, "%s",var_usage->variable_name);
        if (var_usage->subscripts.subscripts_len) {
                int a;
                strcat(buff, "[");
                for (a=0;a<var_usage->subscripts.subscripts_len;a++) {
                        if(a) strcat(buff, ",");
                        strcat(buff, expr_as_string_when_possible(var_usage->subscripts.subscripts_val[a]));
                }
                strcat(buff, "]");
        }
        if (var_usage->substrings_start.substrings_start) {
                strcat(buff, "[");
                strcat(buff, expr_as_string_when_possible(var_usage->substrings_start.substrings_start));
                if (var_usage->substrings_end.substrings_end) {
                        strcat(buff, ",");
                        strcat(buff, expr_as_string_when_possible(var_usage->substrings_end.substrings_end));
                }
                strcat(buff, "]");
        }
        if (var_usage->next) {
                char *ptr;
                strcat(buff,".");
                ptr=expr_get_variable_usage_as_string(var_usage->next);
                strcat(buff, ptr);
                free(ptr);
        }

        return strdup(buff);
}

