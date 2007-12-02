
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
# | contact afalout@ihug.co.nz                                           |
# +----------------------------------------------------------------------+
#
# $Id: dump_4gl.c,v 1.16 2007-12-02 05:24:59 briantan Exp $
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

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

#define MAXSCREENS 20
char mscreen[MAXSCREENS][100][100];
int max_y[MAXSCREENS];

void dump_commands(struct_form *f, FILE *fout, int lvl, struct s_at_block *cmds) ;
char *get_field_name(struct_form *f, u_expression *field_tag_u) ;
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
/*
=====================================================================
                    Functions definitions
=====================================================================
*/



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
	p=find_tag_for(f,a);
	buff[0]='[';
	memcpy(&buff[1],p,strlen(p));
		buff[w+1]=']';
		buff[w+2]=0;
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


void dump_command(struct_form *f, FILE *fout,int lvl, struct u_action *act) {
int a;
for (a=0;a<lvl;a++) { fprintf(fout,"   "); }
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
						fprintf(fout,"CALL set_next_field(\"%s\")\n", get_field_name(f, act->u_action_u.cmd_nextfield->field_tag));
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
						dump_command(f, fout, lvl+1, act->u_action_u.cmd_if->if_true);
					}

					if (act->u_action_u.cmd_if->if_false) {
						for (a=0;a<lvl;a++) { fprintf(fout,"   "); }
						fprintf(fout,"ELSE\n");
						dump_command(f, fout, lvl+1, act->u_action_u.cmd_if->if_false);
					}
					for (a=0;a<lvl;a++) { fprintf(fout,"   "); }
					fprintf(fout,"END IF\n");
					break;
        case ACTION_TYPE_LET:
				fprintf(fout,"CALL display_field(\"%s\",", get_field_name(f,act->u_action_u.cmd_let->field_tag));
				dump_expr_instructions (f, fout, act->u_action_u.cmd_let->value,0);
				fprintf(fout,",1)\n");
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
ptr=get_field_name(f,field_tag_u);
if (strcmp(ptr,"TODAY")==0) return ptr;
sprintf(buff,"gr_%s",ptr);
return buff;
}

char *get_field_name(struct_form *f, u_expression *field_tag_u) {
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
				if (strlen(f->attributes.attributes_val[b].tabname)) {
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
		dump_command(f, fout,lvl,cmds->actions.actions_val[a].uaction);
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
  FILE *fout;
char fname_split[300];
  make_screen(f);

  for (a = 0; a < f->snames.snames_len; a++)
    {
	sprintf(fname_split,"Split_%s_%d.per",fname,a);
	fout=fopen(fname_split,"w");
	if (!fout) {
		printf("Unable to open output file\n");
	exit(2);
	}
  	fprintf (fout, "{-------------------- Screen %d / %d --------------------}\n", (a+1), f->snames.snames_len);
  	fprintf (fout,"DATABASE %s\n", f->dbname);
	fprintf (fout,"SCREEN\n");
	fprintf (fout,"{\n");
	for (y=0;y<=max_y[a];y++) {
		A4GL_trim(mscreen[a][y]);
      		fprintf (fout,"%s\n", mscreen[a][y]);
	}
	fprintf (fout,"}\nend\n");
  	dump_tables (fout,f);
	fprintf(fout,"ATTRIBUTES\n");
	for (y=0;y<f->attributes.attributes_len;y++) {
		char *ptr;
		ptr=screen_has_attribute(f,a, y);
		if (ptr) {
			fprintf(fout,"%s\t= ",ptr);
			dump_attribute(fout, &f->attributes.attributes_val[y], ptr);
			fprintf(fout,";\n");
		}
	}

  	fprintf (fout,"INSTRUCTIONS\n");
  	fprintf (fout,"  DELIMITERS '%s'\n\n", f->delim);
    }

   if (f->control_blocks.control_blocks_len) {
   	sprintf(fname_split,"Split_%s.4gl",fname);
   	fout=fopen(fname_split,"w");
   	if (!fout) {
		printf("Unable to open output file\n");
		exit(2);
   	}
	fprintf(fout,"DATABASE %s\n",f->dbname);
	fprintf(fout,"GLOBALS\n");
  	for (a = 0; a < f->tables.tables_len; a++)
    	{
      		fprintf (fout,"   DEFINE gr_%-20s RECORD LIKE %20s.*\n", f->tables.tables_val[a].tabname, f->tables.tables_val[a].tabname);
    	}
	fprintf(fout,"   DEFINE gv_screen_no INTEGER\n");
	fprintf(fout,"   DEFINE gv_attribute CHAR(32)\n\n");
	fprintf(fout,"END GLOBALS\n\n");

   	fprintf(fout,"FUNCTION form_validation(lv_when, lv_action, lv_col)\n");
   	fprintf(fout,"DEFINE lv_when, lv_action,lv_col CHAR(20)\n");
   	for (a=0;a< f->control_blocks.control_blocks_len;a++) {
		fprintf(fout,"\n\n#%d\n",a);
		dump_control_block(f, fout, &f->control_blocks.control_blocks_val[a]);
   	}
   	fprintf(fout,"# RETURN 1\n");
   	fprintf(fout,"END FUNCTION\n\n");

   	fprintf(fout,"FUNCTION display_form(lv_scr_no)\n");
	fprintf(fout,"DEFINE lv_scr_no INTEGER\n");
	fprintf(fout,"DEFINE lv_form_file CHAR(200)\n");
	fprintf(fout,"   LET gv_screen_no=lv_scr_no\n");
	fprintf(fout,"   LET lv_form_file=\"Split_%s_\", lv_scr_no USING \"<<<<<\"\n",fname);
	fprintf(fout,"   OPEN FORM f_form FROM lv_form_file\n");
	fprintf(fout,"   DISPLAY FORM f_form\n");
   	fprintf(fout,"END FUNCTION\n\n");

	

	fprintf(fout,"FUNCTION display_field(lv_field,lv_value,lv_set_variable)\n");
	fprintf(fout,"DEFINE lv_field CHAR(20)\n");
	fprintf(fout,"DEFINE lv_value CHAR(255)\n");
	fprintf(fout,"DEFINE lv_set_variable SMALLINT\n");


	fprintf(fout,"CASE \n");
	for (a=0;a<f->attributes.attributes_len;a++) {
		fprintf(fout,"   WHEN lv_field=\"%s.%s\"\n", f->attributes.attributes_val[a].tabname,  f->attributes.attributes_val[a].colname, f->attributes.attributes_val[a].tabname);
		fprintf(fout,"     CALL form_validation(\"BEFORE\",\"DISPLAY\", \"%s\")\n",  f->attributes.attributes_val[a].colname);
		if (strcmp(f->attributes.attributes_val[a].tabname,"formonly")!=0) {
			fprintf(fout,"     IF lv_set_variable THEN\n        LET gr_%s.%s=lv_value\n     END IF\n", f->attributes.attributes_val[a].tabname,  f->attributes.attributes_val[a].colname);
			fprintf(fout,"     IF field_on_screen(\"%s\",\"%s\",gv_screen_no) THEN\n",f->attributes.attributes_val[a].tabname,  f->attributes.attributes_val[a].colname);
			fprintf(fout,"        DISPLAY BY NAME gr_%s.%s ATTRIBUTE(gv_attribute)\n", f->attributes.attributes_val[a].tabname,  f->attributes.attributes_val[a].colname);
			fprintf(fout,"     END IF\n");
		} else {
			fprintf(fout,"     IF field_on_screen(\"%s\",\"%s\",gv_screen_no) THEN\n", f->attributes.attributes_val[a].tabname,  f->attributes.attributes_val[a].colname);
			fprintf(fout,"     DISPLAY lv_value TO %s.%s ATTRIBUTE(gv_attribute)\n", f->attributes.attributes_val[a].tabname,  f->attributes.attributes_val[a].colname);
			fprintf(fout,"     END IF\n");
		}
		fprintf(fout,"     CALL form_validation(\"AFTER\",\"DISPLAY\", \"%s\")\n", f->attributes.attributes_val[a].colname);
		fprintf(fout,"\n");
		
	}

	fprintf(fout,"END CASE\n");
   	fprintf(fout,"END FUNCTION\n\n");


	fprintf(fout,"FUNCTION field_on_screen(lv_tab,lv_col,lv_scr)\n");
	fprintf(fout,"DEFINE lv_tab,lv_col CHAR(20)\n");
	fprintf(fout,"DEFINE lv_scr INTEGER\n");
	
	for (y=0;y<f->attributes.attributes_len;y++) {
		char *ptr;
		int printed;
		printed=0;
		fprintf(fout,"IF lv_tab=\"%s\" and lv_col=\"%s\" THEN\n", f->attributes.attributes_val[y].tabname, f->attributes.attributes_val[y].colname);
		for (a=0;a< f->snames.snames_len; a++) {
			ptr=screen_has_attribute(f,a, y);
			if (ptr) {
				if (!printed) {
					fprintf(fout,"   IF lv_scr=%d", a+1);	
					printed++;
				} else {
					fprintf(fout," OR lv_scr=%d",a+1);
				}
			}
		}
		if (printed) {
			fprintf(fout," THEN\n");
			fprintf(fout,"      RETURN TRUE\n");
			fprintf(fout,"   ELSE\n");
			fprintf(fout,"      RETURN FALSE\n");
			fprintf(fout,"   END IF\n");
		}
		fprintf(fout,"END IF\n");
	
	}
   	fprintf(fout,"RETURN FALSE\n");
   	fprintf(fout,"END FUNCTION\n\n");

  	for (a = 0; a < f->tables.tables_len; a++) {
		int b;
      		fprintf (fout,"FUNCTION display_%s()\n",f->tables.tables_val[a].tabname);
		fprintf(fout,"  CALL form_validation(\"BEFORE\",\"DISPLAY\", \"%s\")\n", f->tables.tables_val[a].tabname);
		fprintf(fout,"  SET PAUSE MODE ON\n");
		for (b=0;b<f->attributes.attributes_len;b++) {
			if (strcmp(f->attributes.attributes_val[b].tabname, f->tables.tables_val[a].tabname)==0) {
				fprintf(fout,"  CALL display_field(\"%s.%s\", gr_%s.%s,0)\n", f->attributes.attributes_val[b].tabname, f->attributes.attributes_val[b].colname, f->attributes.attributes_val[b].tabname, f->attributes.attributes_val[b].colname);
			}
		}
		fprintf(fout,"  SET PAUSE MODE OFF\n");
		fprintf(fout,"  CALL form_validation(\"AFTER\",\"DISPLAY\", \"%s\")\n", f->tables.tables_val[a].tabname);
      		fprintf (fout,"END FUNCTION\n\n");
	}

	fprintf(fout,"FUNCTION display_table(lv_table)\n");
	fprintf(fout,"DEFINE lv_table CHAR(20)\n");
	fprintf(fout,"CASE \n");
  	for (a = 0; a < f->tables.tables_len; a++) {
      		fprintf (fout,"   WHEN lv_table=\"%s\" CALL display_%s()\n", f->tables.tables_val[a].tabname, f->tables.tables_val[a].tabname);
	}
	fprintf(fout,"END CASE\n");
	fprintf(fout,"END FUNCTION\n\n");
	fclose(fout);
    }


  //dump_attributes (f);
  //dump_metrics (f);
  //dump_fields_desc (f);
  //dump_records (f);
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
bool to_used;
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
// need to know if field not to be updated 
//			if (a->bool_attribs.bool_attribs_val[b]==FA_B_NOUPDATE) continue;
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
      fprintf (fout, "[");
      for (a = 0; a < expr->u_expression_u.listy.listy_len; a++)
	{
	  dump_expr (fout, expr->u_expression_u.listy.listy_val[a].listx, lvl + 1);
	}
      fprintf (fout, "]");
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
      fprintf (fout," %s ", ptr2->comparitor);
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
		fprintf (fout, "NULL");
	} else {
		fprintf (fout, "get_value(%s)", expr->u_expression_u.special);
	}
    }

  if (expr->itemtype == ITEMTYPE_LIST)
    {
      fprintf (fout, "[");
      for (a = 0; a < expr->u_expression_u.listy.listy_len; a++)
	{
	  dump_expr_instructions (f, fout, expr->u_expression_u.listy.listy_val[a].listx, lvl + 1);
	}
      fprintf (fout, "]");
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
		if (strcmp(ptr2->comparitor,"ISNOTNULL")==0) {
			dump_expr_instructions (f, fout,ptr2->item1, lvl + 1);
			fprintf(fout," IS NOT NULL");
		}
		if (strcmp(ptr2->comparitor,"ISNULL")==0 ) {
			dump_expr_instructions (f, fout,ptr2->item1, lvl + 1);
			fprintf(fout," IS NULL");
		}
	} else {
      		fprintf (fout,"(");
      		ptr2 = expr->u_expression_u.complex_expr;
      		dump_expr_instructions (f, fout,ptr2->item1, lvl + 1);
      		fprintf (fout," %s ", ptr2->comparitor);
      		dump_expr_instructions (f, fout,ptr2->item2, lvl + 1);
      		fprintf (fout,")");
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


/* ================================ EOF ============================= */
