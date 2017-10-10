/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-2005 Aubit Development Team (See Credits file)    |
# +----------------------------------------------------------------------+
# | This program is free software; you can redistribute it and/or modify |
# | it under the terms of one of the following licenses:                 |
# |                                                                      |
# |  A) the GNU General Public License as published by the Free Software |
# |     Foundation; either version 2 of the License, or (at your option) |
# |     any later version.                                               |
# |                                                                      |
# |  B) the Aubit License as published by the Aubit Development Team and |
# |     included in the distribution in the file: LICENSE                |
# |                                                                      |
# | This program is distributed in the hope that it will be useful,      |
# | but WITHOUT ANY WARRANTY; without even the implied warranty of       |
# | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        |
# | GNU General Public License for more details.                         |
# |                                                                      |
# | You should have received a copy of both licenses referred to here.   |
# | If you did not, or have any questions about Aubit licensing, please  |
# | contact licensing@aubit.com                                           |
# +----------------------------------------------------------------------+
#
# $Id: dump_scr.c,v 1.2 2012-06-18 16:44:47 mikeaubury Exp $
#*/

/**
 * @file
 *
 *
 *
 *
 *
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_fcompile_int.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/


char *desc_str[] = {
  "INCLUDE",
  "PICTURE",
  "FORMAT",
  "DEFAULT",
  "PROGRAM",
  "WIDGET",
  "CONFIG",
  "COMMENTS",
  "CLASS",
  "ACTION",
  0
};

char *desc_bool[] = {
  "AUTONEXT",
  "REVERSE",
  "INVISIBLE",
  "NOENTRY",
  "VERIFY",
  "WORDWRAP",
  "COMPRESS",
  "UPSHIFT",
  "DOWNSHIFT",
  "REQUIRED",
  "NOUPDATE",
  "QUERYCLEAR",
  "ZEROFILL",
  "RIGHT",
  0
};

struct struct_join_tables {
    u_int join_tables_len;
    struct s_join_tables {
	int master_tabno;
	char *master_tabname;
	int detail_tabno;
	char *detail_tabname;
	struct struct_join_fields {
	        u_int join_fields_len;
	        struct s_join_fields {
		    int master_colno;
		    char *master_colname;
		    int master_datatype;
		    int detail_colno;
		    char *detail_colname;
		    int detail_datatype;
	        } *join_fields_val;
	} join_fields;
    } *join_tables_val;
};
typedef struct struct_join_tables struct_join_tables;
typedef struct s_join_fields s_join_fields;
typedef struct s_join_tables s_join_tables;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

#define MAXSCREENS 20
char mscreen[MAXSCREENS][100][100];
int max_y[MAXSCREENS];

void dump_commands(struct_form *f, FILE *fout, int lvl, struct s_at_block *cmds) ;
char *get_field_name(struct_form *f, u_expression *field_tag_u, int col_only) ;
static void dump_attributes (FILE *fout, struct_form * f);
static void dump_metrics (struct_form * f);
static void dump_fields_desc (struct_form * f);
static void dump_records (struct_form * f);
static void dump_tables (FILE *fout,struct_form * f);
//andrej void dump_form_desc (struct_form * f);
void dump_expr (FILE *fout, t_expression * expr, int lvl);
void dump_expr_instructions (struct_form *f, FILE *fout, t_expression * expr, int lvl);
void print_lvl (int lvl);


char *find_tag_for(struct_form * f, int n) ;
static void dump_attribute(FILE *fout, struct_scr_field *a,char *tag) ;

void print_display_only(struct_form *f, FILE *fout, int s, int lvl);
void print_validation(struct_form *f, FILE *fout, int t, int s, int ba, int lvl) ;
void print_control_block(struct_form *f, FILE *fout);
void dump_attr_lookup (struct_form * f, FILE *fout);
int split_table_field(char *fullname, char *tablename, char *fieldname);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/


static char *decode_comparitor(char *s) {
	if (strcmp(s,"NOTIN")==0) return "NOT IN";
	return s;
}



#define TRIM_MUNG
char *mung(char *s) {
static char buff[2000];
char *ptr;
	strcpy(buff,s);
	ptr=strchr(buff,'.');
//
// If we've got some '.' - we can't use these as cursor names
// so we need to mung them
// we can do this by removing everything after the '.' or converting the '.'
// to a '_'
//
#ifdef TRIM_MUNG
	if (ptr) {
		*ptr=0;
	}
#else
	// Replace 
	while (ptr) {
		*ptr='_';
		ptr=strchr(buff,'.');
	}
#endif
	return buff;
}

void
make_screen (struct_form * f)
{
  int x, y;
  int spc;
  int screens;
  int a;
  int fno;
  int b;
  int fields[1000];
  int nfields;

for (a=0;a<1000;a++) fields[a]=-1;
for (a=0;a<MAXSCREENS;a++) max_y[a]=0;

  if (f->maxcol > 100 || f->maxline > 100)
    {
      printf ("Too wide or too long\n");
      exit (1);
    }
  for (screens=0;screens<MAXSCREENS;screens++) {
  for (y = 0; y < f->maxline; y++)
    {
      memset (mscreen[screens][y], ' ', f->maxcol);
      mscreen[screens][y][f->maxcol + 1] = 0;
    }
  }

  for (a = 0; a < f->metrics.metrics_len; a++)
    {
      int w;
	int screen;
      x = f->metrics.metrics_val[a].x;
      y = f->metrics.metrics_val[a].y;
      w = f->metrics.metrics_val[a].w;
      screen = f->metrics.metrics_val[a].scr-1;


      if (f->metrics.metrics_val[a].label[0] == '\n')
	continue;		// Ignore graphics characters-  line drawing


      if (strlen (f->metrics.metrics_val[a].label))
	{
	  strncpy (&mscreen[screen][y][x], f->metrics.metrics_val[a].label,
		   strlen (f->metrics.metrics_val[a].label));

		if (y>max_y[screen]) max_y[screen]=y;

	}
      else
	{
	char buff[2000];
	char *p;
	memset(buff,' ',2000);
	if (f->delim[0]==' ') {
		memset(buff+1,'_',w);
		buff[w+2]=0;
	} else {
	//p=find_tag_for(f,a);
	p=" ";
	buff[0]='[';
	memcpy(&buff[1],p,strlen(p));
		buff[w+1]=']';
		buff[w+2]=0;
	} 
	memcpy(&mscreen[screen][y][x-1], buff,strlen(buff));
	

		if (y>max_y[screen]) max_y[screen]=y;
	}
    }
}

char *find_tag_for(struct_form * f, int n) {
  int a, b;
  for (a = 0; a < f->fields.fields_len; a++)
    {
      //printf (" %d Tag '%s'\n", a, f->fields.fields_val[a].tag);
      for (b = 0; b < f->fields.fields_val[a].metric.metric_len; b++)
        {
		if (f->fields.fields_val[a].metric.metric_val[b]==n) return f->fields.fields_val[a].tag;
        }
    }
return "<unknown>";
}


void dump_command(struct_form *f, FILE *fout,int lvl, struct u_action *act, int setvar) {
int a;
for (a=0;a<lvl;a++) { fprintf(fout,"  "); }
switch (act->type) {

	case ACTION_TYPE_ABORT: 	fprintf(fout,"RETURN 0 # ABORT\n"); break;

	case ACTION_TYPE_NOP: 		fprintf(fout,"# NOP\n"); break;

        case ACTION_TYPE_COMMENTS:	fprintf(fout,"CALL show_comments(\"%s\",%d,%d)\n", 
						act->u_action_u.cmd_comment->comment,
						act->u_action_u.cmd_comment->hasbell,
						act->u_action_u.cmd_comment->isreverse);
					break;

        case ACTION_TYPE_NEXTFIELD:	
					if (act->u_action_u.cmd_nextfield->isexitnow) {
						fprintf(fout,"CALL exitnow()");
					} else {
//						fprintf(fout,"CALL set_next_field(\"%s\")\n", get_field_name(f, act->u_action_u.cmd_nextfield->field_tag,1));
						fprintf(fout,"NEXT FIELD %s\n", get_field_name(f, act->u_action_u.cmd_nextfield->field_tag,1));
					}
					break;

        case ACTION_TYPE_BLOCK: 
					fprintf(fout,"#\n");
					dump_commands(f, fout, lvl+1, act->u_action_u.cmd_block);
					break;
	
        case ACTION_TYPE_IF:
					fprintf(fout,"IF ");
					dump_expr_instructions (f, fout, act->u_action_u.cmd_if->test_condition,0);
					fprintf(fout," THEN\n");
					if (act->u_action_u.cmd_if->if_true) {
						dump_command(f, fout, lvl+1, act->u_action_u.cmd_if->if_true,setvar);
					}

					if (act->u_action_u.cmd_if->if_false) {
						for (a=0;a<lvl;a++) { fprintf(fout,"   "); }
						fprintf(fout,"ELSE\n");
						dump_command(f, fout, lvl+1, act->u_action_u.cmd_if->if_false,setvar);
					}
					for (a=0;a<lvl;a++) { fprintf(fout,"  "); }
					fprintf(fout,"END IF\n");
					break;
        case ACTION_TYPE_LET:
			    if (!setvar) {
				fprintf(fout,"DISPLAY ");
				dump_expr_instructions (f, fout, act->u_action_u.cmd_let->value,0);
				fprintf(fout," TO %s\n\t\tATTRIBUTE(gv_attribute)\n",
				get_field_name(f,act->u_action_u.cmd_let->field_tag,0));
			    } else {
				fprintf(fout,"LET gr_%s = ",
			get_field_name(f,act->u_action_u.cmd_let->field_tag,0));
				dump_expr_instructions (f, fout, act->u_action_u.cmd_let->value,0);
				fprintf(fout,"\n");
				for (a=0;a<lvl;a++) { fprintf(fout,"  "); }
				fprintf(fout,"DISPLAY BY NAME gr_%s ATTRIBUTE(gv_attribute)\n",
			get_field_name(f,act->u_action_u.cmd_let->field_tag,0));
			    }
				break;
			
        case ACTION_TYPE_FUNC_CALL:
				fprintf(fout,"CALL %s(", act->u_action_u.cmd_call->fname);
				for (a=0;a<act->u_action_u.cmd_call->list_parameters.list_parameters_len;a++) {
						if (a) fprintf(fout,",");
						dump_expr_instructions (f, fout, act->u_action_u.cmd_call->list_parameters.list_parameters_val[a],0);
				}
				fprintf(fout,")\n");
				break;
	default : 
		printf("UNKNOWN ACTION TYPE\n");
		exit(40);

}

}


char *get_field_name_var(struct_form *f, u_expression *field_tag_u) {
static char buff[200];
char *ptr;
ptr=get_field_name(f,field_tag_u,0);
if (strcmp(ptr,"TODAY")==0) return ptr;
sprintf(buff,"gr_%s",ptr);
return buff;
}

int get_attr_from_field(struct_form *f, u_expression *field_tag_u) {
int a;
int b;
char *field_tag=0;

    if (field_tag_u->itemtype != ITEMTYPE_FIELD) return 0;
    field_tag=field_tag_u->u_expression_u.field;

    for (a=0;a<f->fields.fields_len;a++) {
	if (strcmp(field_tag, f->fields.fields_val[a].tag)==0) {
		for (b=0;b<f->attributes.attributes_len;b++) {
			if (f->attributes.attributes_val[b].field_no==a) {
				// We've found it..
				return b;
			}
		}
	}
    }
}

char *get_field_name(struct_form *f, u_expression *field_tag_u, int col_only) {
int a;
int b;
char *field_tag=0;
static char buff[200];

switch (field_tag_u->itemtype) {
	case ITEMTYPE_FIELD: field_tag=field_tag_u->u_expression_u.field; break;
	case ITEMTYPE_COMPLEX: 
			A4GL_pause_execution();
			exit(2);
			break;
	case ITEMTYPE_SPECIAL: sprintf(buff,"SPECIAL_%s", field_tag_u->u_expression_u.special);
				field_tag=buff; break;
	default : 
		printf("Unhandled itemtype for get_field_name : %d\n", field_tag_u->itemtype);
		exit(20);
}


for (a=0;a<f->fields.fields_len;a++) {
	if (strcmp(field_tag, f->fields.fields_val[a].tag)==0) {
		for (b=0;b<f->attributes.attributes_len;b++) {
			if (f->attributes.attributes_val[b].field_no==a) {
				// We've found it..
				static char buff[200];
				if (strlen(f->attributes.attributes_val[b].tabname) && !col_only) {
					sprintf(buff,"%s.%s", f->attributes.attributes_val[b].tabname, f->attributes.attributes_val[b].colname);
				} else {
					sprintf(buff,"%s", f->attributes.attributes_val[b].colname);
				}
				return  buff;
			}
		}
	}
}

if (strcmp(field_tag,"today")==0) {
	return "TODAY";
}

sprintf(buff,"Unknown('%s')",field_tag);
return buff;
}

void dump_commands(struct_form *f, FILE *fout, int lvl, struct s_at_block *cmds) {
	int a;
	for (a=0;a<cmds->actions.actions_len;a++) {
		dump_command(f, fout,lvl,cmds->actions.actions_val[a].uaction,0);
	}
}

char *screen_has_attribute(struct_form * f, int scr, int attr_no) {
int fno;
int b;
int metric_no;
	fno=f->attributes.attributes_val[attr_no].field_no;
      for (b = 0; b < f->fields.fields_val[fno].metric.metric_len; b++)
        {
		metric_no=f->fields.fields_val[fno].metric.metric_val[b];
		if (f->metrics.metrics_val[metric_no].scr==scr+1) return f->fields.fields_val[fno].tag;
        }
	return 0;
}

void dump_control_block(struct_form *f, FILE *fout, s_control_block *blk) {
int a;
struct s_bef_aft *ba;
	switch (blk->cbtype) {
		
		case E_CB_BEFORE:
        	case E_CB_AFTER:   
				ba=blk->s_control_block_u.befaft;
				if (blk->cbtype==E_CB_BEFORE) {
					fprintf(fout,"IF lv_when=\"BEFORE\" THEN\n");
				} else {
					fprintf(fout,"IF lv_when=\"AFTER\" THEN\n");
				}
				fprintf(fout,"   IF ");
				for (a=0;a<ba->befaftlist.befaftlist_len;a++) {
					if (a) fprintf(fout,"OR ");
					switch ( ba->befaftlist.befaftlist_val[a]) {
         					case E_BA_EDITADD: 	fprintf(fout,"lv_action=\"EDITADD\" "); break;
         					case E_BA_REMOVE: 	fprintf(fout,"lv_action=\"REMOVE\" "); break;
         					case E_BA_ADD: 		fprintf(fout,"lv_action=\"ADD\" "); break;
         					case E_BA_UPDATE: 	fprintf(fout,"lv_action=\"UPDATE\" "); break;
         					case E_BA_QUERY: 	fprintf(fout,"lv_action=\"QUERY\" "); break;
         					case E_BA_DISPLAY: 	fprintf(fout,"lv_action=\"DISPLAY\" "); break;
         					case E_BA_EDITUPDATE: 	fprintf(fout,"lv_action=\"EDITUPDATE\" "); break;
					}
				}
				fprintf(fout, "THEN\n");
				fprintf(fout,"      IF ");
				for (a=0;a<ba->column_list->columns.columns_len;a++) {
					char *tab=0;
					if (a) fprintf(fout,"OR ");
					tab=ba->column_list->columns.columns_val[a].tabname;
					if (tab!=0) {
						if (strlen(tab)==0) tab=0;
					}
					if (tab) {
					fprintf(fout,"(lv_tab=\"%s\" AND lv_col=\"%s\") ", ba->column_list->columns.columns_val[a].tabname,ba->column_list->columns.columns_val[a].colname);
					} else {
					fprintf(fout,"lv_col=\"%s\" ", ba->column_list->columns.columns_val[a].colname);
					}
				}
				fprintf(fout,"THEN\n");
				fprintf(fout,"#COMMANDS\n");
				dump_commands(f, fout,3, ba->cmds);
				fprintf(fout,"      END IF\n");
				fprintf(fout,"   END IF\n");
				fprintf(fout,"END IF\n");
			break;

        	case E_CB_ONBEGINNING:
        	case E_CB_ONENDING:     
				if (blk->cbtype==E_CB_ONBEGINNING) {
					fprintf(fout,"IF lv_when=\"ON BEGINNING\" THEN\n");
				} else {
					fprintf(fout,"IF lv_when=\"ON ENDING\" THEN\n");
				}
				fprintf(fout,"CALL %s(", blk->s_control_block_u.onbegend->fname);
				for (a=0;a<blk->s_control_block_u.onbegend->list_parameters.list_parameters_len;a++) {
						if (a) fprintf(fout,",");
						dump_expr_instructions (f, fout, blk->s_control_block_u.onbegend->list_parameters.list_parameters_val[a],0);
				}
				fprintf(fout,")\n");
				fprintf(fout, "END IF\n");
			break;
	}
}



/**
 * Dumps a complete form description
 * It calls all the specific dumps(attributes, metrics, field description
 * and tables)
 *
 * @param f A pointer to the form description structure
 */
void
dump_form_desc (struct_form * f,char *fname)
{
  int a;
  int y;
  int has_lookups=0;
  int printed_tag=0;
  FILE *fout;
  char fname_split[300];
  make_screen(f);

  for (a = 0; a < f->snames.snames_len; a++) {
	for (y=0;y<=max_y[a];y++) {
		A4GL_trim(mscreen[a][y]);
      		printf ("%s\n", mscreen[a][y]);
	}
	break;
    }
}

char *decode_dtype_formonly(int type, int n) {
static char buff[2000];
if ((type & DTYPE_MASK)==DTYPE_CHAR) return "";
if ((type & DTYPE_MASK)==DTYPE_SMINT) return " TYPE SMALLINT";
if ((type & DTYPE_MASK)==DTYPE_INT) return " TYPE INTEGER";
sprintf(buff,"TYPE(%d,%d)",type,n);
return buff;
}

/**
 * Make a text A4GL_dump of the form attributes
 *
 * @param f A pointer to a form description record
 */
static void
dump_attributes (FILE *fout, struct_form * f)
{
int a;
int b;
	printf ("\nAttributes %d\n", f->attributes.attributes_len);
	for (a = 0; a < f->attributes.attributes_len; a++) {
		printf ("Attribute %d\n", a);
		dump_attribute(fout, &f->attributes.attributes_val[a],"");
	}
}

int need_quote(int dtype) {
if ((dtype&DTYPE_MASK)==DTYPE_CHAR) return 1;
return 0;
}

char *decode_include(char *s,int dtype) {
static char buff[200000];
char smbuff[200];
char sm[2];
int a;
int to_used;
sm[0]=0;
sm[1]=0;
sprintf(buff,"INCLUDE=(");
to_used = 0;
if (need_quote(dtype)) {
	strcat(buff,"\"");
}

for (a=0;a<strlen(s);a++)  {
	if (s[a]=='\n') {
		if (need_quote(dtype)) {
			strcat(buff,"\"");
		}
		if (strlen(buff)>5) {
			int l;
			l=strlen(buff)-6;
			if (strcmp(&buff[l],"\"NULL\"")==0) {
				buff[l]=0;
				strcat(buff,"\"\"");
			}
		}
		strcat(buff,",");
		if (need_quote(dtype)) {
			strcat(buff,"\"");
		}
	} else {
		if (s[a]=='\t') {
			if (need_quote(dtype)) {
				strcat(buff,"\"");
			}
			strcat(buff," TO ");
			if (need_quote(dtype)) {
				strcat(buff,"\"");
			}
			to_used = 1;
		} else {
			sm[0]=s[a];
			strcat(buff,sm);
		}
	}
}

		if (need_quote(dtype)) {
			int l;
			to_used = 0;
			l=strlen(buff)-5;
			if (strcmp(&buff[l],"\"NULL")==0) {
				buff[l]=0;
				strcat(buff,"\"\")");
			} else {
				strcat(buff,"\")");
			}
		}
if (to_used) {
  strcat(buff,")");
}
return buff;
}

static void dump_attribute(FILE *fout, struct_scr_field *a,char *tag) {
int b;
/*
		if (strcmp(a->tabname,"displayonly")==0) {
				char buff[300];
				a->tabname="formonly";
				sprintf(buff,"fld_%s",tag);
				a->colname=buff;
		}
*/

		fprintf (fout,"%s.%s", a->tabname, a->colname);
		if (a->subscripts[0]>0) {
			fprintf (fout,"[%d",a->subscripts[0]);
			if (a->subscripts[1]) {
				fprintf (fout, ",%d",a->subscripts[1]);
				if (a->subscripts[2]) {
					fprintf (fout,",%d", a->subscripts[2]);
				}
			}
			fprintf(fout,"]");
		}

		if (strcmp(a->tabname,"formonly")==0 ) {
			fprintf (fout,"%s", decode_dtype_formonly(a->datatype, a->dtype_size));
		}

		for (b = 0; b < a->str_attribs.str_attribs_len; b++) {
			if (a->str_attribs.str_attribs_val[b].type==FA_S_INCLUDE) {
				fprintf(fout,", %s", decode_include(a->str_attribs.str_attribs_val[b].value, a->datatype));
			} else {
			fprintf (fout,", %s=\"%s\"",
				desc_str[a->str_attribs.str_attribs_val[b].type], a->str_attribs.str_attribs_val[b].value);
			}
		}
		for (b = 0; b < a->bool_attribs.bool_attribs_len; b++){
			/* Skip any isql form attributes */
			if (a->bool_attribs.bool_attribs_val[b]==FA_B_NOUPDATE) continue;
			if (a->bool_attribs.bool_attribs_val[b]==FA_B_QUERYCLEAR) continue;
			if (a->bool_attribs.bool_attribs_val[b]==FA_B_ZEROFILL) continue;
			if (a->bool_attribs.bool_attribs_val[b]==FA_B_RIGHT) continue;
			fprintf (fout,", %s",desc_bool[a->bool_attribs.bool_attribs_val[b]]);
		}
		if (a->colours.colours_len) {
			int b;
			for (b = 0; b < a->colours.colours_len;b++){
				fprintf (fout,"        colour=%d WHERE ",
					(int)a->colours.colours_val[b].colour);
				dump_expr (fout,a->colours.colours_val[b].whereexpr, 0);
			}
		}
}

/**
 * Make a text A4GL_dump of all text elements from the screen image
 *
 * @param f A pointer to a form description record
 */
static void
dump_metrics (struct_form * f)
{
  int a;
  printf ("\nMetrics %d\n", f->metrics.metrics_len);
  for (a = 0; a < f->metrics.metrics_len; a++)
    {
      printf ("a=%d x=%d y=%d w=%d h=%d scr=%d del=%d label='%s'\n", a,
	      f->metrics.metrics_val[a].x,
	      f->metrics.metrics_val[a].y,
	      f->metrics.metrics_val[a].w,
	      f->metrics.metrics_val[a].h,
	      f->metrics.metrics_val[a].scr,
	      f->metrics.metrics_val[a].delim_code,
	      f->metrics.metrics_val[a].label);
    }
}

/**
 * Text dumps screen record field information
 *
 * @param f A pointer to a form description record
 */
static void
dump_fields_desc (struct_form * f)
{
  int a, b;
  printf ("\nFields %d\n", f->fields.fields_len);
  for (a = 0; a < f->fields.fields_len; a++)
    {
      printf (" %d Tag '%s'\n", a, f->fields.fields_val[a].tag);
      for (b = 0; b < f->fields.fields_val[a].metric.metric_len; b++)
	{
	  printf ("   %d\n", f->fields.fields_val[a].metric.metric_val[b]);
	}
    }
}

/**
 * Make a text A4GL_dump of the screen record information
 *
 * @param f A pointer to a form description record
 */
static void
dump_records (struct_form * f)
{
  int a, b;
  printf ("\nRecords %d\n", f->records.records_len);
  for (a = 0; a < f->records.records_len; a++)
    {
      printf ("%d '%s' %d\n", a, f->records.records_val[a].name,
	      f->records.records_val[a].dim);
      for (b = 0; b < f->records.records_val[a].attribs.attribs_len; b++)
	{
	  printf ("    %d\n",
		  f->records.records_val[a].attribs.attribs_val[b]);
	}
    }
}

/**
 * Dumps a text representation of tables loaded from the parser
 *
 * @param f A pointer to a form description record
 */
static void
dump_tables (FILE *fout,struct_form * f)
{
  int a;
  fprintf (fout,"tables\n");
  for (a = 0; a < f->tables.tables_len; a++)
    {
	if (strcmp(f->tables.tables_val[a].tabname, f->tables.tables_val[a].alias)==0) {
      		fprintf (fout,"   %s\n", f->tables.tables_val[a].tabname);
	} else {
      		fprintf (fout,"   %s %s\n", f->tables.tables_val[a].tabname, f->tables.tables_val[a].alias);
	}
    }
}



/**
 *
 *
 * @param
 */
void
dump_expr (FILE *fout, t_expression * expr, int lvl)
{
  t_complex_expr *ptr2;
  int a;


  if (expr->itemtype == ITEMTYPE_INT)
    {
      fprintf (fout, "%%%d", expr->u_expression_u.intval);
    }

  if (expr->itemtype == ITEMTYPE_SPECIAL)
    {
      fprintf (fout, "*%s", expr->u_expression_u.special);
    }

  if (expr->itemtype == ITEMTYPE_LIST)
    {
      fprintf (fout, "(");
      for (a = 0; a < expr->u_expression_u.listy.listy_len; a++)
	{
		if (a) fprintf (fout, ",");
	  dump_expr (fout, expr->u_expression_u.listy.listy_val[a].listx, lvl + 1);
	}
      fprintf (fout, ")");
    }

  if (expr->itemtype == ITEMTYPE_FIELD)
    {
      fprintf (fout,"$%s", expr->u_expression_u.field);
    }

  if (expr->itemtype == ITEMTYPE_CHAR)
    {
      fprintf (fout,"'%s'", expr->u_expression_u.charval);
    }

  if (expr->itemtype == ITEMTYPE_NOT)
    {
      fprintf (fout,"!(");
      dump_expr (fout, expr->u_expression_u.notexpr, lvl + 1);
      fprintf (fout,")");

    }

  if (expr->itemtype == ITEMTYPE_COMPLEX)
    {
      fprintf (fout,"(");
      ptr2 = expr->u_expression_u.complex_expr;
      dump_expr (fout,ptr2->item1, lvl + 1);
      fprintf (fout," %s ", decode_comparitor(ptr2->comparitor));
      dump_expr (fout,ptr2->item2, lvl + 1);
      fprintf (fout,")");

    }

  if (lvl == 0)
    fprintf (fout, "\n");

}

void
dump_expr_instructions (struct_form *f, FILE *fout, t_expression * expr, int lvl)
{
  t_complex_expr *ptr2;
  int a;


  if (expr->itemtype == ITEMTYPE_INT)
    {
      fprintf (fout, "%d", expr->u_expression_u.intval);
    }

  if (expr->itemtype == ITEMTYPE_SPECIAL)
    {
	if (strcmp(expr->u_expression_u.special,"NULL")==0) {
		// fprintf (fout, "NULL");
		fprintf (fout, "\"\"");
	} else {
		fprintf (fout, "get_value(%s)", expr->u_expression_u.special);
	}
    }

  if (expr->itemtype == ITEMTYPE_LIST)
    {
      fprintf (fout, "(");
      for (a = 0; a < expr->u_expression_u.listy.listy_len; a++)
	{
      	if (a) fprintf (fout, ",");
	  dump_expr_instructions (f, fout, expr->u_expression_u.listy.listy_val[a].listx, lvl + 1);
	}
      fprintf (fout, ")");
    }

  if (expr->itemtype == ITEMTYPE_FIELD)
    {
	
      fprintf (fout,"%s", get_field_name_var(f,expr));
    }

  if (expr->itemtype == ITEMTYPE_CHAR)
    {
      fprintf (fout,"\"%s\"", expr->u_expression_u.charval);
    }

  if (expr->itemtype == ITEMTYPE_NOT)
    {
      fprintf (fout,"NOT (");
      dump_expr_instructions (f, fout, expr->u_expression_u.notexpr, lvl + 1);
      fprintf (fout,")");

    }

  if (expr->itemtype == ITEMTYPE_COMPLEX)
    {
	ptr2 = expr->u_expression_u.complex_expr;
	if (strcmp(ptr2->comparitor,"ISNOTNULL")==0 || strcmp(ptr2->comparitor,"ISNULL")==0 ) {
//      		fprintf (fout,"(");
		if (strcmp(ptr2->comparitor,"ISNOTNULL")==0) {
			dump_expr_instructions (f, fout,ptr2->item1, lvl + 1);
			fprintf(fout," IS NOT NULL");
		}
		if (strcmp(ptr2->comparitor,"ISNULL")==0 ) {
			dump_expr_instructions (f, fout,ptr2->item1, lvl + 1);
			fprintf(fout," IS NULL");
		}
//      		fprintf (fout,")");
	} else {
	    if (strcmp(ptr2->comparitor,"+")==0 ||
		strcmp(ptr2->comparitor,"-")==0) {
      		fprintf (fout,"(");
	    }
//      		ptr2 = expr->u_expression_u.complex_expr;
      		dump_expr_instructions (f, fout,ptr2->item1, lvl + 1);
      		fprintf (fout," %s ", decode_comparitor(ptr2->comparitor));
      		dump_expr_instructions (f, fout,ptr2->item2, lvl + 1);
	    if (strcmp(ptr2->comparitor,"+")==0 ||
		strcmp(ptr2->comparitor,"-")==0) {
      		fprintf (fout,")");
	    }
	}

    }


}





/**
 *
 *
 * @param
 */
void
print_lvl (int lvl)
{
  int a;
  return;
  for (a = 0; a < lvl; a++)
    {
      printf ("   ");
    }
}

/* print display only fields for screen s */
void print_display_only(struct_form *f, FILE *fout, int s, int lvl) {
    int a,b,c,d,t;
printf("now in print_display_only s=%d\n",s);
	for (c=0;c< f->control_blocks.control_blocks_len;c++) {
//printf("\n#c=%d of %d\n",c, f->control_blocks.control_blocks_len);
	    switch (f->control_blocks.control_blocks_val[c].cbtype) {
		case E_CB_BEFORE:
		case E_CB_AFTER:
		    break;
		default:
		    continue;
	    }
	    struct s_bef_aft *ba;
	    ba=f->control_blocks.control_blocks_val[c].s_control_block_u.befaft;
	    int found_ba_display = 0;
	    for (b=0;b<ba->befaftlist.befaftlist_len;b++) {
		if (ba->befaftlist.befaftlist_val[b] == E_BA_DISPLAY) {
		    found_ba_display = 1;
		    break;
		}
	    }
	    if (!found_ba_display) continue;
//	    for (d=0; d<ba->column_list->columns.columns_len; d++) {
//	      fprintf(fout,"# c=%d, b=%d columns[%d]=%s.%s\n",c,b,d,
//	                ba->column_list->columns.columns_val[d].tabname,
//	                ba->column_list->columns.columns_val[d].colname);
//	      printf("# c=%d, b=%d columns[%d]=%s.%s\n",c,b,d,
//	                ba->column_list->columns.columns_val[d].tabname,
//	                ba->column_list->columns.columns_val[d].colname);
//	    }

	    for (t=0;t<ba->cmds->actions.actions_len;t++) {
	        struct u_action *act;
	        act=ba->cmds->actions.actions_val[t].uaction;
		fprintf(fout,"#   c=%d b=%d actions[%d] type=",c,b,t);
//		printf("#   actions[%d] type=",t);
		switch (act->type) {
		    case ACTION_TYPE_IF:
			fprintf(fout,"IF\n");
//			printf("IF\n");
//	  printf("     field type %d\n",
//		act->u_action_u.cmd_if->test_condition->itemtype);
			switch (act->u_action_u.cmd_if->test_condition->itemtype) {
			  case 3:
	    a= get_attr_from_field(f, act->u_action_u.cmd_if->if_true->u_action_u.cmd_let->field_tag);
				break;
			  case 4:
	    a= get_attr_from_field(f, act->u_action_u.cmd_if->test_condition->u_expression_u.complex_expr->item1);
				break;
		        }
			if (!a) continue;
			break;
		    case ACTION_TYPE_LET:
			fprintf(fout,"LET\n");
//			printf("LET\n");
			a= get_attr_from_field(f, act->u_action_u.cmd_let->field_tag);
			if (!a) continue;
			break;
		}
	        if (!screen_has_attribute(f,s, a)) continue;
//	    dump_expr_instructions (f, fout, act->u_action_u.cmd_let->value,0);
//	        fprintf(fout,"\n#%d\n",c);
//	    fprintf(fout,"field=%s.%s value=%$\n", 
//		ba->cmds->actions.actions_val[0].uaction->u_action_u.cmd_let->value);
//		dump_commands(f, fout, lvl, ba->cmds);
		dump_command(f, fout,lvl,ba->cmds->actions.actions_val[t].uaction,0);
	    }
	}
}

void print_control_block(struct_form *f, FILE *fout) {
  int a,b,c,d,e,m;
  for (c=0; c<f->control_blocks.control_blocks_len; c++) {
    fprintf(fout,"c=%d ",c);
    switch (f->control_blocks.control_blocks_val[c].cbtype) {
	case E_CB_BEFORE:	fprintf(fout,"BEFORE "); break;
	case E_CB_AFTER:	fprintf(fout,"AFTER "); break;
	case E_CB_ONBEGINNING:	fprintf(fout,"ONBEGINNING "); break;
	case E_CB_ONENDING:	fprintf(fout,"ONENDING "); break;
    }
    struct s_bef_aft *ba;
    ba=f->control_blocks.control_blocks_val[c].s_control_block_u.befaft;
    for (b=0; b<ba->befaftlist.befaftlist_len; b++) {
      fprintf(fout," ");
      switch (ba->befaftlist.befaftlist_val[b]) {
	case E_BA_EDITADD:	fprintf(fout,"EDITADD\n"); break;
	case E_BA_ADD:		fprintf(fout,"ADD\n"); break;
	case E_BA_EDITUPDATE:	fprintf(fout,"EDITUPDATE\n"); break;
	case E_BA_UPDATE:	fprintf(fout,"UPDATE\n"); break;
	case E_BA_REMOVE:	fprintf(fout,"REMOVE\n"); break;
	case E_BA_QUERY:	fprintf(fout,"QUERY\n"); break;
	case E_BA_DISPLAY:	fprintf(fout,"DISPLAY\n"); break;
      }
    }
    for (d=0; d<ba->column_list->columns.columns_len; d++) {
      fprintf(fout,"    columns[%d]=%s.%s\n",d,
		ba->column_list->columns.columns_val[d].tabname,
		ba->column_list->columns.columns_val[d].colname);
    }
    for (e=0; e<ba->cmds->actions.actions_len; e++) {
      struct u_action *act;
      act=ba->cmds->actions.actions_val[e].uaction;
      fprintf(fout,"    actions[%d] type=", e);
      switch (act->type) {
	case ACTION_TYPE_ABORT:	fprintf(fout,"ABORT\n"); break;
	case ACTION_TYPE_NOP:	fprintf(fout,"NOP\n"); break;
	case ACTION_TYPE_COMMENTS:	fprintf(fout,"COMMENTS\n"); break;
	case ACTION_TYPE_IF:	fprintf(fout,"IF\n");
	    a= get_attr_from_field(f, act->u_action_u.cmd_if->test_condition->u_expression_u.complex_expr->item1);
	  fprintf(fout,"     field type %d=%s.%s\n",
		act->u_action_u.cmd_if->test_condition->itemtype,
		f->attributes.attributes_val[a].tabname,
		f->attributes.attributes_val[a].colname);
					fprintf(fout,"IF ");
					dump_expr_instructions (f, fout, act->u_action_u.cmd_if->test_condition,0);
					fprintf(fout," THEN\n");
					if (act->u_action_u.cmd_if->if_true) {
						dump_command(f, fout, 4, act->u_action_u.cmd_if->if_true,0);
					}

					if (act->u_action_u.cmd_if->if_false) {
						fprintf(fout,"ELSE\n");
						dump_command(f, fout, 4, act->u_action_u.cmd_if->if_false,0);
					}
					fprintf(fout,"END IF\n");
					break;
	case ACTION_TYPE_LET:	fprintf(fout,"LET\n"); break;
	case ACTION_TYPE_NEXTFIELD:	fprintf(fout,"NEXTFIELD\n"); break;
	case ACTION_TYPE_FUNC_CALL:	fprintf(fout,"FUNC_CALL\n"); break;
	case ACTION_TYPE_BLOCK:	fprintf(fout,"BLOCK\n"); break;
      }
    }
  }
}

/* print field validation for input */
/* ba = 1 before field, =2 after field =3 after input*/
void print_validation(struct_form *f, FILE *fout, int t, int s, int beaf, int lvl) {
if (beaf==1) printf("now in print_validation t=%d s=%d beaf=%d lvl=%d\n", t,s,beaf,lvl);
    int a,b,c,d,e,g,h,l;
	for (c=0;c< f->control_blocks.control_blocks_len;c++) {
	    switch (f->control_blocks.control_blocks_val[c].cbtype) {
		case E_CB_BEFORE:
		    if (beaf==1) break;
		    continue;
		case E_CB_AFTER:
		    if (beaf==2 || beaf==3) break;
		    continue;
		default:
		    continue;
	    }
	    struct s_bef_aft *ba;
	    ba=f->control_blocks.control_blocks_val[c].s_control_block_u.befaft;
	    int found_ba_input = 0;
	    for (b=0;b<ba->befaftlist.befaftlist_len;b++) {
		switch (ba->befaftlist.befaftlist_val[b]) {
		  case E_BA_EDITADD:
		  case E_BA_ADD:
		  case E_BA_EDITUPDATE:
		  case E_BA_UPDATE:
		  // case E_BA_REMOVE:
		      found_ba_input = 1;
		      break;
		  default:
		    continue;
		}
		if (found_ba_input) break;
	    }
	    if (!found_ba_input) continue;
	    int istable=0;
	    for (d=0; d<ba->column_list->columns.columns_len; d++) {
	      for (l=0; l<f->tables.tables_len; l++) {
		if (strcmp(ba->column_list->columns.columns_val[d].colname,
		    f->tables.tables_val[l].tabname)==0) {
		    istable = 1;
		    break;
		}
	      }
//	      printf("# c=%d b=%d d=%d columns[%d]=%s.%s istable=%d\n",
//			c,b,d,d,
//			ba->column_list->columns.columns_val[d].tabname,
//			ba->column_list->columns.columns_val[d].colname,
//			istable);
	      if (beaf==3 && l!=t) continue;
	      if (istable && beaf!=3) continue;
	      if (!istable && beaf==3) continue;
//printf("c=%d b=%d d=%d %s\n",c,b,d,
//		ba->column_list->columns.columns_val[d].colname);
//	      if (ba->column_list->columns.columns_val[d].tabname==0) {
		  for (a=0;a<f->attributes.attributes_len;a++) {
		    if (strcmp(f->attributes.attributes_val[a].colname,
			ba->column_list->columns.columns_val[d].colname)==0) {
			break;
		    }
		  }
//	      }
	      for (g=0;g<ba->cmds->actions.actions_len; g++) {
	          struct u_action *act;
	          act = ba->cmds->actions.actions_val[g].uaction;
		  switch (act->type) {
		    case ACTION_TYPE_COMMENTS:
			break;

		    case ACTION_TYPE_IF:
			switch (act->u_action_u.cmd_if->test_condition->itemtype) {
			  case 3:
	    a= get_attr_from_field(f, act->u_action_u.cmd_if->if_true->u_action_u.cmd_let->field_tag);
				break;
			  case 4:
	    a= get_attr_from_field(f, act->u_action_u.cmd_if->test_condition->u_expression_u.complex_expr->item1);
				break;
		        }
			if (!a) continue;
			break;
		    case ACTION_TYPE_LET:
//printf("c=%d b=%d d=%d LET\n",c,b,d);
			a= get_attr_from_field(f, act->u_action_u.cmd_let->field_tag);
			if (!a) continue;
			break;
		  }
		  if (!a) continue;
		  if (strcmp(f->attributes.attributes_val[a].tabname,
			f->tables.tables_val[t].tabname)!=0) continue;
		  if (!screen_has_attribute(f,s, a)) continue;
		  int reject_field=0;
		  for (b=0; b<f->attributes.attributes_val[a].bool_attribs.bool_attribs_len; b++) {
		    switch (f->attributes.attributes_val[a].bool_attribs.bool_attribs_val[b]) {
//		      case FA_B_NOENTRY: reject_field++; break;
		      case FA_B_NOUPDATE: reject_field++; break;
		    }
		  }
		  if (reject_field) continue;
fprintf(fout,"#  cb[%d] ba[%d] column[%d] action[%d]\n",c,b,d,g);
		  switch (beaf) {
		    case 1: fprintf(fout,"            BEFORE FIELD %s\n",
			ba->column_list->columns.columns_val[d].colname);
			break;
		    case 2: fprintf(fout,"            AFTER FIELD %s\n",
			ba->column_list->columns.columns_val[d].colname);
			break;
		    case 3: 
			break;
		  }
		  dump_command(f, fout,lvl,act,1);
	      }
	    }
//	    if (!screen_has_attribute(f,s, a)) continue;
//	    dump_expr_instructions (f, fout, act->u_action_u.cmd_let->value,0);
//	    fprintf(fout,"field=%s.%s value=%$\n", 
//		ba->cmds->actions.actions_val[0].uaction->u_action_u.cmd_let->value);

	}
    if (beaf!=2) return;	// only after field validation
    for (a=0; a<f->attributes.attributes_len; a++) {
	if (strcmp(f->attributes.attributes_val[a].tabname,
		f->tables.tables_val[t].tabname)!=0) continue;
	if (!screen_has_attribute(f,s, a)) continue;
	int cnt;
	int lookup_printed=0;
	for (cnt=0;cnt<f->attributes.attributes_val[a].lookup.lookups.lookups_len;cnt++) {
	    struct s_lookups *p;
	    int cnt1;
	    p=f->attributes.attributes_val[a].lookup.lookups.lookups_val[cnt];
	    for (cnt1=0;cnt1<p->lookups.lookups_len;cnt1++) {
		struct s_lookup *p2;
		p2=p->lookups.lookups_val[cnt1];
fprintf(fout,"# LOOKUP %s DISPLAY %s\n", p->joincol, p2->tabcol);
		char look_tablename[32], look_fieldname[32];
		char disp_tablename[32], disp_fieldname[32];
		int star;
		star = split_table_field(p->joincol, look_tablename, look_fieldname);
		star = split_table_field(p2->tabcol, disp_tablename, disp_fieldname);
		fprintf(fout,"            AFTER FIELD %s\n",
		    f->attributes.attributes_val[a].colname);
		fprintf(fout,"              IF gr_%s.%s IS NOT NULL THEN\n",
		    f->attributes.attributes_val[a].tabname,
		    f->attributes.attributes_val[a].colname);
		fprintf(fout,"                ");
		if (strcmp(p2->fieldtag,"<<FROM>>")!=0) {
		    fprintf(fout,"SELECT %s INTO gr_display.%s FROM %s\n",
			disp_fieldname, p2->fieldtag, disp_tablename);
		    fprintf(fout,"                  WHERE %s = gr_%s.%s\n",
		        look_fieldname, f->attributes.attributes_val[a].tabname,
		        f->attributes.attributes_val[a].colname);
		} else {
		    fprintf(fout,"SELECT %s FROM %s\n",
			disp_fieldname, disp_tablename);
		    fprintf(fout,"                  WHERE %s = gr_%s.%s\n",
		        disp_fieldname, f->attributes.attributes_val[a].tabname,
		        f->attributes.attributes_val[a].colname);
		}
		fprintf(fout,"                IF STATUS <> 0 THEN\n");
		if (strcmp(p2->fieldtag,"<<FROM>>")!=0) {
		    fprintf(fout,"                  CALL show_comments(\"Data entered not found in %s table (field %s) \",0,1)\n", look_tablename, look_fieldname);
		} else {
		    fprintf(fout,"                  CALL show_comments(\"Data entered not found in %s table (field %s) \",0,1)\n", disp_tablename, disp_fieldname);
		}
		fprintf(fout,"                  NEXT FIELD %s\n",
		    f->attributes.attributes_val[a].colname);
		fprintf(fout,"                END IF\n");
		if (strcmp(p2->fieldtag,"<<FROM>>")!=0) {
		    fprintf(fout,"                DISPLAY BY NAME gr_display.%s ATTRIBUTE(BLACK)\n", p2->fieldtag);
		}

		fprintf(fout,"              END IF\n");
	    }
	}
    }
}

void dump_attr_lookup(struct_form * f, FILE *fout) {
  int a, b, c, l, ls;
  int has_lookups;
    fprintf (fout, "\n");
    fprintf (fout, "# Total Attributes %d\n", f->attributes.attributes_len);
    for (a = 0; a < f->attributes.attributes_len; a++) {
	fprintf (fout, "# %d fld=%d %s.%s ty=%d ptr=%d flg=%d\n", a,
	    f->attributes.attributes_val[a].field_no,
	    f->attributes.attributes_val[a].tabname,
	    f->attributes.attributes_val[a].colname,
	    f->attributes.attributes_val[a].datatype,
	    f->attributes.attributes_val[a].general_ptr,
	    f->attributes.attributes_val[a].flags);
	for (b = 0; b < f->attributes.attributes_val[a].lookup.lookups.lookups_len; b++) {
	    struct s_lookups *ls;
	    ls = f->attributes.attributes_val[a].lookup.lookups.lookups_val[b];
	    fprintf(fout, "#  joincol=%s\n", ls->joincol);
	    for (c = 0; c < ls->lookups.lookups_len; c++) {
	        struct s_lookup *l;
	        has_lookups++;
	        l = ls->lookups.lookups_val[c];
	        fprintf (fout, "#  lookup[%d] fieldtag=%s tabcol=%s\n", c,
		    l->fieldtag, l->tabcol);
	    }
	}
  }
}

int split_table_field(char *fullname, char *tablename, char *fieldname) {
    int i, idx=0, infield=0;
    int star = 0;
    for (i=0;i<strlen(fullname);i++) {
	if (fullname[i]=='*') {
	    star = 1;
	    continue;
	}
	if (fullname[i]=='.') {
		tablename[idx] = 0;
		infield = 1;
		idx = 0;
		continue;
	}
	if (!infield) tablename[idx++] = fullname[i];
	if (infield) fieldname[idx++] = fullname[i];
    }
    fieldname[idx] = 0;
    return star;
}

/* ================================ EOF ============================= */
