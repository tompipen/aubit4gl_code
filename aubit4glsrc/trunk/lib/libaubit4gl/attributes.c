// This should be a complete list of all possible attributes anything
// can have - some are not applicable to certain areas....

#include "a4gl_libaubit4gl_int.h"



struct all_attributes {
	int color;
	int reverse;
	int blink;
	int underline;
	int border;
	int normal;
	int invisible;
	int bold;
	int dim;

	int comment_line;
	int form_line;
	int menu_line;
	int message_line;
	int prompt_line;
	int error_line;

	int accept_key;
	int delete_key;
	int insert_key;
	int next_key;
	int previous_key;
	int help_key;
	char *help_file;

	int display_attrib;
	int display_attrib_type;
	int input_attrib;
	int input_attrib_type;

	int input_wrapmode;
	int field_order_mode;
	int sql_interrupt;
};



/**
* Get a string representation of an attribute
*
* @param attr  Attribute to decode
* @param col_str Pointer to character string to store the colour
* @param col_str Pointer to character string to store the attributes
*/
void
get_strings_from_attr(int attr,char *col_str,char *attr_str)
{
int col_int;

        strcpy(col_str,"WHITE");
        strcpy(attr_str,"");

        col_int=(attr&0xf00);
        debug("col_int=%x\n",col_int);
        /* Work out the colours first */
        switch(col_int) {
                case AUBIT_COLOR_BLACK:         strcpy(col_str,"BLACK");break;
                case AUBIT_COLOR_RED:           strcpy(col_str,"RED");break;
                case AUBIT_COLOR_GREEN:         strcpy(col_str,"GREEN");break;
                case AUBIT_COLOR_YELLOW:        strcpy(col_str,"YELLOW");break;
                case AUBIT_COLOR_BLUE:          strcpy(col_str,"BLUE");break;
                case AUBIT_COLOR_MAGENTA:       strcpy(col_str,"MAGENTA");break;
                case AUBIT_COLOR_CYAN:          strcpy(col_str,"CYAN");break;
                case AUBIT_COLOR_WHITE:         strcpy(col_str,"WHITE");break;
        }

        /* Now for the attributes */
        if (attr&AUBIT_ATTR_NORMAL)             strcat(attr_str,"NORMAL ");
        if (attr&AUBIT_ATTR_REVERSE)            strcat(attr_str,"REVERSE ");
        if (attr&AUBIT_ATTR_UNDERLINE)          strcat(attr_str,"UNDERLINE ");
        if (attr&AUBIT_ATTR_BOLD)               strcat(attr_str,"BOLD ");
        if (attr&AUBIT_ATTR_BLINK)              strcat(attr_str,"BLINK ");
        if (attr&AUBIT_ATTR_DIM)                strcat(attr_str,"DIM ");
        debug("get_strings returning %s %s",col_str,attr_str);
}

/**
 *  Decode a string attribute into an Aubit internal attribute
 *
 *  @param s The string to decode - should contain a single colour or attribute
 *
 */
int
get_attr_from_string(char *s)
{
        if (strcasecmp(s,"BLACK")==0)     return AUBIT_COLOR_BLACK;
        if (strcasecmp(s,"RED")==0)       return AUBIT_COLOR_RED;
        if (strcasecmp(s,"GREEN")==0)     return AUBIT_COLOR_GREEN;
        if (strcasecmp(s,"YELLOW")==0)    return AUBIT_COLOR_YELLOW;
        if (strcasecmp(s,"BLUE")==0)      return AUBIT_COLOR_BLUE;
        if (strcasecmp(s,"MAGENTA")==0)   return AUBIT_COLOR_MAGENTA;
        if (strcasecmp(s,"CYAN")==0)      return AUBIT_COLOR_CYAN;
        if (strcasecmp(s,"WHITE")==0)     return AUBIT_COLOR_WHITE;

        if (strcasecmp(s,"NORMAL")==0)    return AUBIT_ATTR_NORMAL;
        if (strcasecmp(s,"REVERSE")==0)   return AUBIT_ATTR_REVERSE;
        if (strcasecmp(s,"UNDERLINE")==0) return AUBIT_ATTR_UNDERLINE;
        if (strcasecmp(s,"BOLD")==0)      return AUBIT_ATTR_BOLD;
        if (strcasecmp(s,"BLINK")==0)     return AUBIT_ATTR_BLINK;
        if (strcasecmp(s,"DIM")==0)       return AUBIT_ATTR_DIM;
        printf("Unknown attribute : %s\n",s);
        return -1;
}
