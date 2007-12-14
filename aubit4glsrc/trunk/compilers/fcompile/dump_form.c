
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
# $Id: dump_form.c,v 1.7 2007-12-14 15:14:20 briantan Exp $
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
		    int detail_colno;
		    char *detail_colname;
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
	sprintf(fname_split,"f_%s%02d.per",fname,a+1);
	fout=fopen(fname_split,"w");
	if (!fout) {
		printf("Unable to open output file\n");
	exit(2);
	}
	printf("opened file %s\n",fname_split);
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
                        char *p2=0;
                        if (!printed_tag) {
                                fprintf(fout,"%s\t= ",ptr);
                                printed_tag++;
                        }
                
                        if (y<f->attributes.attributes_len-1) { p2=screen_has_attribute(f,a, y+1); } else {p2="";}
                        if (p2) {
                                fprintf (fout,"%s.%s=", f->attributes.attributes_val[a].tabname, f->attributes.attributes_val[a].colname);
                                if (strcmp(ptr,p2)==0) continue;
                       }
	 

			dump_attribute(fout, &f->attributes.attributes_val[y], ptr);
			fprintf(fout,";\n");
                        printed_tag=0;
  
                        if (f->attributes.attributes_val[y].lookup.lookups.lookups_len) {
                                int cnt;
                                // We've got some links..
                                for (cnt=0;cnt<f->attributes.attributes_val[y].lookup.lookups.lookups_len;cnt++) {
                                        struct s_lookups *p;
                                        int cnt1;
                                        p=f->attributes.attributes_val[y].lookup.lookups.lookups_val[cnt];
                                        for (cnt1=0;cnt1<p->lookups.lookups_len;cnt1++) {
                                                struct s_lookup *p2;
                                                has_lookups++;
                                                p2=p->lookups.lookups_val[cnt1];
                                                fprintf(fout,"%s=%s;\n",p2->fieldtag, p2->tabcol);
                                        }
        
                                }
                        }
  

		}
	}

  	fprintf (fout,"INSTRUCTIONS\n");
  	fprintf (fout,"  DELIMITERS '%s'\n\n", f->delim);
	fclose(fout);
  }

//  if (f->control_blocks.control_blocks_len || has_lookups) {
   	sprintf(fname_split,"%s.4gl",fname);
   	fout=fopen(fname_split,"w");
   	if (!fout) {
		printf("Unable to open output file\n");
		exit(2);
   	}
    printf("opened %s\n",fname_split);

    struct struct_join_tables j;

    int s,t,m,d,c,i,b;
    int max_table=0;
    i=0;
    j.join_tables_len = 0;
    j.join_tables_val = malloc(sizeof(s_join_tables));
printf("now in get_join_tables\n");
    for (t=0; t<f->tables.tables_len; t++) {
        int dt=0;
        for (m=0; m<f->master_of.master_of_len; m++) {
	    if (strcmp(f->master_of.master_of_val[m].tab_master,
		       f->tables.tables_val[t].tabname)==0) {
		if (t>max_table) max_table=t;
	        for (d=0; d<f->tables.tables_len; d++) {
		    if (strcmp(f->master_of.master_of_val[m].tab_detail,
		        f->tables.tables_val[d].tabname)==0) {
			if (d>max_table) max_table=d;
			j.join_tables_len++;
			j.join_tables_val =
			    realloc(j.join_tables_val,
			    sizeof(s_join_tables)*j.join_tables_len);
			j.join_tables_val[i].master_tabno = t;
			j.join_tables_val[i].master_tabname = 
			    f->tables.tables_val[t].tabname;
			j.join_tables_val[i].detail_tabno = d;
			j.join_tables_val[i].detail_tabname = 
			    f->tables.tables_val[d].tabname;
			dt = d+1;
			i++;
		        break;
		    }
	        }
	        break;
	    }
	}
    }
    for (t=0; t<j.join_tables_len;t++) {
        i=0;
	struct struct_join_fields *jf;
	jf = &(j.join_tables_val[t].join_fields);
	jf->join_fields_len = 0;
	jf->join_fields_val = malloc(sizeof(s_join_fields));
//	printf ("get t=%d master=%d %s detail=%d %s\n", t+1,
//		j.join_tables_val[t].master_tabno,
//		j.join_tables_val[t].master_tabname,
//		j.join_tables_val[t].detail_tabno,
//		j.join_tables_val[t].detail_tabname);
	for (a=0; a<f->attributes.attributes_len; a++) {
	    if (strcmp(j.join_tables_val[t].master_tabname,
		f->attributes.attributes_val[a].tabname)!=0) continue;
	    for (b=0; b<f->attributes.attributes_len; b++) {
		if (strcmp(j.join_tables_val[t].detail_tabname,
		    f->attributes.attributes_val[b].tabname)!=0) continue;
		if (f->attributes.attributes_val[a].field_no ==
		    f->attributes.attributes_val[b].field_no) {
		    jf->join_fields_len++;
		    jf->join_fields_val = realloc(jf->join_fields_val,
			sizeof(s_join_fields) * jf->join_fields_len);
		    jf->join_fields_val[i].master_colno = a;
		    jf->join_fields_val[i].master_colname =
			f->attributes.attributes_val[a].colname;
		    jf->join_fields_val[i].detail_colno = b;
		    jf->join_fields_val[i].detail_colname =
			f->attributes.attributes_val[b].colname;
//	printf ("   get i=%d master=%d %s detail=%d %s\n", i+1,
//		jf->join_fields_val[i].master_colno,
//		jf->join_fields_val[i].master_colname,
//		jf->join_fields_val[i].detail_colno,
//		jf->join_fields_val[i].detail_colname);
		    i++;
		    break;
		}
	    }
	}
    }

//    print_control_block(f, fout);

    fprintf(fout,"GLOBALS \"global.4gl\"\n");
    fprintf(fout,"\n");
    for (t = 0; t < f->tables.tables_len; t++) {
	fprintf (fout,"    DEFINE gr_%-20s RECORD LIKE %20s.*\n",
	    f->tables.tables_val[t].tabname,
	    f->tables.tables_val[t].tabname);
    }
    fprintf(fout,"    DEFINE ga_oid ARRAY[10] OF INTEGER\n");
    fprintf(fout,"    DEFINE gv_rec_found, gv_mode INTEGER\n");
    fprintf(fout,"    DEFINE gv_cursor, gv_statement CHAR(32)\n");
    fprintf(fout,"    DEFINE where_part, query_text VARCHAR(1000)\n");
    fprintf(fout,"\n");
    fprintf(fout,"MAIN\n");
    fprintf(fout,"    LET gv_module = \"%s\"\n", fname);
    fprintf(fout,"    LET gv_show_detail = FALSE\n");
    fprintf(fout,"    LET gv_screen_no = 1\n");
    fprintf(fout,"    LET gv_screen_max = %d\n", f->snames.snames_len);
    fprintf(fout,"    LET gv_table_no = 1\n");
    fprintf(fout,"    LET gv_table_max = %d\n", max_table + 1);
    fprintf(fout,"\n");

    fprintf (fout,"   # n,1 tablename n,2 tabledesc\n");
    for (t=0; t<f->tables.tables_len; t++) {
      	    fprintf (fout,"    LET ga_table_name[%d,1] = \"%s\"\n",
		t+1, f->tables.tables_val[t].tabname);
      	    fprintf (fout,"    LET ga_table_name[%d,2] =   \"%s\"\n",
		t+1, f->tables.tables_val[t].tabname);
    }
    fprintf(fout,"\n");

    for (m=0; m<f->tables.tables_len; m++) {
	int dt=0;
        for (t=0; t<j.join_tables_len;t++) {
	    if (j.join_tables_val[t].master_tabno != m) continue;
	    dt++;
	    struct struct_join_fields *jf;
	    jf = &(j.join_tables_val[t].join_fields);
	    fprintf (fout,"    LET ga_master_of[%d] = %d \t# %s->%s\n",
		j.join_tables_val[t].master_tabno+1,
		j.join_tables_val[t].detail_tabno+1,
		j.join_tables_val[t].master_tabname,
		j.join_tables_val[t].detail_tabname);
	    for (a=0; a<jf->join_fields_len;a++) {
	        fprintf (fout,"    # %d) (%02d) %s.%s\t= (%02d) %s.%s\n", a+1,
		    jf->join_fields_val[a].master_colno,
		    j.join_tables_val[t].master_tabname,
		    jf->join_fields_val[a].master_colname,
		    jf->join_fields_val[a].detail_colno,
		    j.join_tables_val[t].detail_tabname,
		    jf->join_fields_val[a].detail_colname);
	    }
	}
//	if (!dt) {
//	    fprintf (fout,"    LET ga_master_of[%d] = 0\n", m+1);
//	}
    }

    fprintf(fout,"\n");
	
    fprintf (fout,"   # n,1 formname n,2 formdesc n,3 formcolor\n");
    for (s=0; s<f->snames.snames_len; s++) {
      	    fprintf (fout,"    LET ga_screen_name[%d,1] = \"f_%s%02d\"\n",
		s+1, mung(fname), s+1);
      	    fprintf (fout,"    LET ga_screen_name[%d,2] = \"%s%02d\"\n",
		s+1, mung(fname), s+1);
      	    fprintf (fout,"    LET ga_screen_name[%d,3] = \"GREEN\"\n",
		s+1);
    }
    fprintf(fout,"\n");
	
    fprintf (fout,"    # define first screen for each table\n");
    // join fields not counted
printf("now in table_screen\n");
    char *ptr;
    for (t=0; t<f->tables.tables_len; t++) {
      if (t>max_table) continue;
      int first_in_screen = 0;
      for (s=0; s<f->snames.snames_len; s++) {
	for (a=0; a<f->attributes.attributes_len; a++) {
	  if (strcmp(f->attributes.attributes_val[a].tabname,
	             f->tables.tables_val[t].tabname)!=0) continue;
	  int field_in_join=0;
	  for (m=0; m<j.join_tables_len; m++) {
	    struct struct_join_fields *jf;
	    jf = &(j.join_tables_val[m].join_fields);
	    for (b=0; b<jf->join_fields_len; b++) {
//printf("t=%d s=%d a=%d m=%d b=%d\n",t,s,a,m,b);
	      if (strcmp(j.join_tables_val[m].master_tabname,
			f->attributes.attributes_val[a].tabname)==0 &&
	          strcmp(jf->join_fields_val[b].master_colname,
			f->attributes.attributes_val[a].colname)==0) {
		field_in_join++;
		break;
	      }
	      if (strcmp(j.join_tables_val[m].detail_tabname,
			f->attributes.attributes_val[a].tabname)==0 &&
	          strcmp(jf->join_fields_val[b].detail_colname,
			f->attributes.attributes_val[a].colname)==0) {
		field_in_join++;
		break;
	      }
	    }
	    if (field_in_join) break;
	  }
	  if (field_in_join) continue;
	  ptr=screen_has_attribute(f,s,a);
	  if (ptr) {
	    first_in_screen = s+1;
	    break;
	  }
	}
	if (first_in_screen) break;
      }
      fprintf (fout,"    LET ga_table_screen[%d] = %d\n", t+1, first_in_screen);
    }
    fprintf(fout,"\n");
	
printf("now in main program\n");
    fprintf(fout,"    CALL prog_init()\n");
    fprintf(fout,"    DEFER INTERRUPT\n");
    fprintf(fout,"\n");
    fprintf(fout,"    CALL open_window()\n");

//    fprintf(fout,"    CALL form_validation(\"AFTER\",\"DISPLAY\",\"%s\")\n",
//	    f->tables.tables_val[0].tabname);
    fprintf(fout,"    CALL aclfgl_set_display_field_delimiters(\"  \")\n");
    print_display_only(f, fout, 0, 2);
    fprintf(fout,"    CALL aclfgl_set_display_field_delimiters(\"[]\")\n");

    fprintf(fout,"\n");
    fprintf(fout,"    WHILE gv_screen_no <> 0\n");
    fprintf(fout,"        CALL display_menu()\n");
    fprintf(fout,"    END WHILE\n");
    fprintf(fout,"\n");
    fprintf(fout,"    CALL close_window()\n");
    fprintf(fout,"END MAIN\n");

    fprintf(fout,"\n");
printf("now in display_record\n");
    fprintf(fout,"##################################################\n");
    fprintf(fout,"FUNCTION display_record()\n");
    fprintf(fout,"##################################################\n");
    fprintf(fout,"\n");
    fprintf(fout,"    IF ga_rec_found[gv_table_no] = 0 THEN\n");
    fprintf(fout,"        RETURN\n");
    fprintf(fout,"    END IF\n");
    fprintf(fout,"\n");

    fprintf(fout,"    CASE gv_screen_no\n");
    /* display individual screen x tables */
    for (s=0;s< f->snames.snames_len; s++) {
	fprintf(fout,"      WHEN %d\t# display screen %d\n", s+1, s+1);

	// char *ptr;
	int attr_found, printed;
	for (t=0;t< f->tables.tables_len; t++) {
	    attr_found = 0; printed = 0;
	    for (a=0;a<f->attributes.attributes_len;a++) {
		if (strcmp(f->attributes.attributes_val[a].tabname,
			       f->tables.tables_val[t].tabname)!=0) continue;
		ptr=screen_has_attribute(f,s, a);
		if (!ptr) continue;
		if (!attr_found) {
		    fprintf(fout,"        LET gv_attribute = get_color(%d)\n",
				t+1);
		    fprintf(fout,"        IF gv_table_no <> %d THEN\n", t+1);
		    fprintf(fout,
	"            CALL aclfgl_set_display_field_delimiters(\"  \")\n");
		    fprintf(fout,"        END IF\n", t+1);
		    fprintf(fout,"        DISPLAY BY NAME\n");
		    attr_found++;
		}
		if (printed) fprintf(fout, ",\n");
		fprintf(fout,"          gr_%s.%s",
			f->attributes.attributes_val[a].tabname,
			f->attributes.attributes_val[a].colname);
		printed++;
	    }
	    if (attr_found) {
		fprintf(fout,"\n");
		fprintf(fout,"          ATTRIBUTE(gv_attribute)\n");
		fprintf(fout,"        IF gv_table_no <> %d THEN\n", t+1);
		fprintf(fout,
	"            CALL aclfgl_set_display_field_delimiters(\"[]\")\n");
		fprintf(fout,"        END IF\n", t+1);
	    }


	}
	fprintf(fout,"        LET gv_attribute = \"BLACK\"\n");
	fprintf(fout,"        CALL aclfgl_set_display_field_delimiters(\"  \")\n");
//    print_control_block(f, fout);
	print_display_only(f, fout, s, 4);
	fprintf(fout,"        CALL aclfgl_set_display_field_delimiters(\"[]\")\n");
	fprintf(fout,"\n");
	int case_printed=0;
	for (m=0;m<f->tables.tables_len;m++) {
	      int printed=0;
	      for (a=0;a<j.join_tables_len;a++) {
		if (j.join_tables_val[a].master_tabno==m ||
		    j.join_tables_val[a].detail_tabno==m ) {
		  struct struct_join_fields *jf;
	    	  jf = &(j.join_tables_val[a].join_fields);
		  for (b=0;b<jf->join_fields_len;b++) {
		    ptr = screen_has_attribute(f,s,
			jf->join_fields_val[b].master_colno);
		    if (!ptr) continue;
		    ptr = screen_has_attribute(f,s,
			jf->join_fields_val[b].detail_colno);
		    if (!ptr) continue;
		    if (j.join_tables_val[a].master_tabno==m) {
		      if (!case_printed) {
			fprintf(fout,"        CASE gv_table_no\n");
			case_printed++;
		      }
		      if (!printed) {
		        fprintf(fout,"          WHEN %d\t# screen %d table %s\n",
			    m+1, s+1, f->tables.tables_val[m].tabname);
		        fprintf(fout,"            LET gv_attribute = get_color(%d)\n", m+1);
		        fprintf(fout,"            DISPLAY BY NAME\n");
		        printed++;
		      } else {
		        fprintf(fout,",\n");
		      }
		      fprintf(fout,"              gr_%s.%s",
			    j.join_tables_val[a].master_tabname,
			    jf->join_fields_val[b].master_colname);
		    }
		    if (j.join_tables_val[a].detail_tabno==m) {
		      if (!printed) {
		        fprintf(fout,"          WHEN %d\t# screen %d table %s\n",
			    m+1, s+1, f->tables.tables_val[m].tabname);
		        fprintf(fout,"            LET gv_attribute = get_color(%d)\n", m+1);
		        fprintf(fout,"            DISPLAY BY NAME\n");
		        printed++;
		      } else {
		        fprintf(fout,",\n");
		      }
		      fprintf(fout,"              gr_%s.%s",
			    j.join_tables_val[a].detail_tabname,
			    jf->join_fields_val[b].detail_colname);
		    }
		  }
		}
	      }
	      if (printed) {
		fprintf(fout,"\n");
		fprintf(fout,"            ATTRIBUTE(gv_attribute)\n");
	      }
	}
	if (case_printed) fprintf(fout,"        END CASE #gv_table_no\n");
	fprintf(fout,"\n");
    }
    fprintf(fout,"    END CASE #gv_screen_no\n");
    fprintf(fout,"    CALL recpos_msg()\n");
    fprintf(fout,"END FUNCTION\n");
    fprintf(fout,"\n");

    //char *ptr;
printf("now in query_by_example\n");
    int attr_found, printed;
    fprintf(fout,"##################################################\n");
    fprintf(fout,"FUNCTION query_by_example()\n");
    fprintf(fout,"##################################################\n");
    fprintf(fout,"\n");
    fprintf(fout,"  LET int_flag = FALSE\n");
    fprintf(fout,"  CASE gv_table_no\n");
    for (t=0;t< f->tables.tables_len; t++) {
	if (t>max_table) continue;
	fprintf(fout,"    WHEN %d\t# query table %s\n",
		t+1, f->tables.tables_val[t]);
	int mt = 0;
	for (d=0; d<f->master_of.master_of_len; d++) {
	    if (strcmp(f->master_of.master_of_val[d].tab_detail,
		       f->tables.tables_val[t].tabname)==0) {
		for (m=0; m<f->tables.tables_len; m++) {
		    if (strcmp(f->master_of.master_of_val[d].tab_master,
		       f->tables.tables_val[m].tabname)==0) {
		        mt = m+1;
			break;
		    }
		}
		break;
	    }
	}
	if (mt) {
          fprintf(fout,"      IF gv_show_detail THEN\n");
	    int printed=0;
	    for (m=0; m<j.join_tables_len;m++) {
		struct struct_join_fields *jf;
		jf = &(j.join_tables_val[m].join_fields);
		if (j.join_tables_val[m].master_tabno != t-1) continue;
		if (j.join_tables_val[m].detail_tabno != t) continue;
		for (a=0; a<jf->join_fields_len;a++) {
		    if (!printed) {
			fprintf(fout,"        LET where_part =\n");
			printed++;
		    } else {
			fprintf(fout,",\n");
			fprintf(fout,"            \"AND \",\n");
		    }
		    fprintf (fout,"            \"%s.%s = '\", gr_%s.%s CLIPPED, \"'\"",
			j.join_tables_val[m].detail_tabname,
			jf->join_fields_val[a].detail_colname,
			j.join_tables_val[m].master_tabname,
			jf->join_fields_val[a].master_colname);
		}
		if (printed) {
		    fprintf(fout,"\n");
		}
		break;
	    }
          fprintf(fout,"      ELSE\n");
	}
        fprintf(fout,"        CASE gv_screen_no\n");
        for (s=0;s< f->snames.snames_len; s++) {
	    fprintf(fout,"        WHEN %d\t# table %s screen %d\n",
		s+1, f->tables.tables_val[t], s+1);
	    attr_found = 0; printed = 0;
	    for (a=0;a<f->attributes.attributes_len;a++) {
		if (strcmp(f->attributes.attributes_val[a].tabname,
			       f->tables.tables_val[t].tabname)!=0) continue;
		ptr=screen_has_attribute(f,s, a);
		if (!ptr) continue;
		if (!attr_found) {
		    fprintf(fout,"          CONSTRUCT BY NAME where_part ON\n");
		    attr_found++;
		}
		if (printed) fprintf(fout, ",\n");
		fprintf(fout,"            %s.%s",
			f->attributes.attributes_val[a].tabname,
			f->attributes.attributes_val[a].colname);
		printed++;
	    }
	    if (attr_found) {
	      fprintf(fout,"\n");
	    }
        }
        fprintf(fout,"        END CASE # gv_screen_no\n");
        fprintf(fout,"        IF int_flag THEN\n");
        fprintf(fout,"          LET int_flag = FALSE\n");
        fprintf(fout,"          RETURN\n");
        fprintf(fout,"        END IF\n");
	if (mt) {
          fprintf(fout,"      END IF\n");
	}
        fprintf(fout,"      LET query_text = \"SELECT oid,* from %s\",\n",
			       f->tables.tables_val[t].tabname);
        fprintf(fout,"          \" WHERE \", where_part CLIPPED\n");
        fprintf(fout,"         #\" ORDER BY aaa, bbb\"\n");
    }
    fprintf(fout,"  END CASE # gv_table_no\n");
    fprintf(fout,"\n");
    fprintf(fout,"  LET gv_statement = \"s_\", gv_module CLIPPED, ");
    fprintf(fout,"		gv_table_no using \"&&&\"\n");
    fprintf(fout,"  LET gv_cursor    = \"c_\", gv_module CLIPPED, ");
    fprintf(fout,"		gv_table_no using \"&&&\"\n");
    fprintf(fout,"  PREPARE _variable(gv_statement) FROM query_text\n");
    fprintf(fout,"  DECLARE _variable(gv_cursor) SCROLL CURSOR FOR _variable(gv_statement)\n");
    fprintf(fout,"  LET gv_rec_found = 0\n");
    fprintf(fout,"  FOREACH _variable(gv_cursor)\n");
    fprintf(fout,"    LET gv_rec_found = gv_rec_found + 1\n");
    fprintf(fout,"  END FOREACH\n");
    fprintf(fout,"  IF gv_rec_found = 0 THEN\n");
    fprintf(fout,"    CALL notfound_msg()\n");
    fprintf(fout,"    RETURN\n");
    fprintf(fout,"  END IF\n");
    fprintf(fout,"  CLOSE _variable(gv_cursor)\n");
    fprintf(fout,"  LET ga_rec_found[gv_table_no] = gv_rec_found\n");
    fprintf(fout,"  LET ga_rec_no[gv_table_no] = 1\n");
    fprintf(fout,"  CALL get_record()\n");
    fprintf(fout,"  \n");
    fprintf(fout,"END FUNCTION\n");
    fprintf(fout,"\n");

printf("now in get_record\n");
    fprintf(fout,"##################################################\n");
    fprintf(fout,"FUNCTION get_record()\n");
    fprintf(fout,"##################################################\n");
    fprintf(fout,"\n");
    fprintf(fout,"  LET gv_cursor    = \"c_\", gv_module CLIPPED, ");
    fprintf(fout,"gv_table_no using \"&&&\"\n");
    fprintf(fout,"message \"get_record:\", ");
    fprintf(fout,"\"oid=\", ga_oid[gv_table_no],\n");
    fprintf(fout,"\t\" table=\", gv_table_no using \"<<\",\n");
    fprintf(fout,"\t\" screen=\", gv_screen_no using \"<<\",\n");
    fprintf(fout,"\t\" rec=\", ga_rec_no[gv_table_no] using \"<<<<<<\",\n");
    fprintf(fout,"\t\" of \", ga_rec_found[gv_table_no] using \"<<<<<<\"\n");
    fprintf(fout,"  CASE gv_table_no\n");
    for (t=0;t< f->tables.tables_len; t++) {
	if (t>max_table) continue;
	fprintf(fout,"    WHEN %d\n", t+1);
	fprintf(fout,"      OPEN _variable(gv_cursor)\n");
	fprintf(fout,"      FETCH ABSOLUTE ga_rec_no[gv_table_no] ");
	fprintf(fout,"_variable(gv_cursor)\n");
	fprintf(fout,"        INTO ga_oid[%d], gr_%s.*\n",
		t+1, f->tables.tables_val[t].tabname);
	fprintf(fout,"      IF STATUS <> 0 THEN\n");
	fprintf(fout,"        CLOSE _variable(gv_cursor)\n");
	fprintf(fout,"        CALL notfound_msg()\n");
	fprintf(fout,"        RETURN\n");
	fprintf(fout,"      END IF\n");
	fprintf(fout,"      CLOSE _variable(gv_cursor)\n");
	fprintf(fout,"      { get the derived tables row }\n");
	for (s=t+1; s<f->tables.tables_len; s++) {
//	    if (s<t) continue;
	    int printed=0;
	    for (m=0; m<j.join_tables_len;m++) {
		struct struct_join_fields *jf;
		jf = &(j.join_tables_val[m].join_fields);
		if (j.join_tables_val[m].master_tabno != s-1) continue;
		if (j.join_tables_val[m].detail_tabno != s) continue;
		for (a=0; a<jf->join_fields_len;a++) {
		    if (!printed) {
			fprintf(fout,"      # get table %d\n",s+1);
			fprintf(fout,"      DECLARE c_%s%02d%02d CURSOR FOR\n", mung(fname),t+1,s+1);
			fprintf(fout,"          SELECT * FROM %s\n",
			f->tables.tables_val[s].tabname);
			fprintf(fout,"          WHERE ");
			printed++;
		    } else {
			fprintf(fout,"          AND ");
		    }
		    fprintf (fout,"%s.%s = gr_%s.%s\n",
			j.join_tables_val[m].detail_tabname,
			jf->join_fields_val[a].detail_colname,
			j.join_tables_val[m].master_tabname,
			jf->join_fields_val[a].master_colname);
		}
		fprintf(fout,"      OPEN c_%s%02d%02d\n", mung(fname),t+1,s+1);
		fprintf(fout,"      FETCH FIRST c_%s%02d%02d INTO gr_%s.*\n",
			mung(fname),t+1,s+1, f->tables.tables_val[s].tabname);
		fprintf(fout,"      CLOSE c_%s%02d%02d\n", mung(fname),t+1,s+1);
		fprintf(fout,"\n");
		break;
	    }
	}
	for (s=t-1; s>=0; s--) {
//	    if (s>t) continue;
	    int printed=0;
	    for (m=0; m<j.join_tables_len;m++) {
		struct struct_join_fields *jf;
		jf = &(j.join_tables_val[m].join_fields);
		if (j.join_tables_val[m].master_tabno != s) continue;
		if (j.join_tables_val[m].detail_tabno != s+1) continue;
		for (a=0; a<jf->join_fields_len;a++) {
		    if (!printed) {
			fprintf(fout,"      # get table %d\n",s+1);
			fprintf(fout,"      DECLARE c_%s%02d%02d CURSOR FOR\n", mung(fname),t+1,s+1);
			fprintf(fout,"          SELECT * FROM %s\n",
			f->tables.tables_val[s].tabname);
			fprintf(fout,"          WHERE ");
			printed++;
		    } else {
			fprintf(fout,"          AND ");
		    }
		    fprintf (fout,"%s.%s = gr_%s.%s\n",
			j.join_tables_val[m].master_tabname,
			jf->join_fields_val[a].master_colname,
			j.join_tables_val[m].detail_tabname,
			jf->join_fields_val[a].detail_colname);
		}
		fprintf(fout,"      OPEN c_%s%02d%02d\n", mung(fname),t+1,s+1);
		fprintf(fout,"      FETCH FIRST c_%s%02d%02d INTO gr_%s.*\n",
			mung(fname),t+1,s+1, f->tables.tables_val[s].tabname);
		fprintf(fout,"      CLOSE c_%s%02d%02d\n", mung(fname),t+1,s+1);
		fprintf(fout,"\n");
		break;
	    }
	}
    }

    fprintf(fout,"  END CASE # gv_table_no\n");
    fprintf(fout,"  CALL display_record()\n");
    fprintf(fout,"END FUNCTION\n");
    fprintf(fout,"\n");

printf("now in add_record\n");
    fprintf(fout,"##################################################\n");
    fprintf(fout,"FUNCTION add_record()\n");
    fprintf(fout,"##################################################\n");
    fprintf(fout,"\n");
    fprintf(fout,"  CASE gv_table_no\n");
    for (t=0;t< f->tables.tables_len; t++) {
	if (t>max_table) continue;
	fprintf(fout,"    WHEN %d\n", t+1);
	fprintf(fout,"      INITIALIZE gr_%s.* TO NULL\n",
		f->tables.tables_val[t].tabname);
	fprintf(fout,"      CALL display_record()\n");
	fprintf(fout,"      CALL add_msg(\"%s\")\n",
		f->tables.tables_val[t].tabname);
	fprintf(fout,"      LET gv_mode = 1\n");
	fprintf(fout,"      CALL input_record()\n");
	fprintf(fout,"      IF abort_flag THEN\n");
	fprintf(fout,"        CALL abort_msg(\"%s\")\n",
		f->tables.tables_val[t].tabname);
	fprintf(fout,"        EXIT CASE\n");
	fprintf(fout,"      END IF\n");
	fprintf(fout,"      INSERT INTO %s VALUES (gr_%s.*)\n",
		f->tables.tables_val[t].tabname,
		f->tables.tables_val[t].tabname);
	fprintf(fout,"      IF status <> 0 THEN\n");
	fprintf(fout,"        CALL err_msg(\"Error adding %s record\")\n",
		f->tables.tables_val[t].tabname);
	fprintf(fout,"        EXIT CASE\n");
	fprintf(fout,"      END IF\n");
        fprintf(fout,"      CALL err_msg(\"%s record added\")\n",
		f->tables.tables_val[t].tabname);
	fprintf(fout,"\n");
    }
    fprintf(fout,"  END CASE #gv_table_no\n");
    fprintf(fout,"  IF abort_flag THEN\n");
    fprintf(fout,"    CALL get_record()\n");
    fprintf(fout,"  END IF\n");
    fprintf(fout,"  CALL display_record()\n");
    fprintf(fout,"END FUNCTION\n");
    fprintf(fout,"\n");

printf("now in update_record\n");
    fprintf(fout,"##################################################\n");
    fprintf(fout,"FUNCTION update_record()\n");
    fprintf(fout,"##################################################\n");
    fprintf(fout,"\n");
    fprintf(fout,"  CASE gv_table_no\n");
    for (t=0;t< f->tables.tables_len; t++) {
	if (t>max_table) continue;
	fprintf(fout,"    WHEN %d\n", t+1);
	fprintf(fout,"      CALL update_msg(\"%s\")\n",
		f->tables.tables_val[t].tabname);
	fprintf(fout,"      LET gv_mode = 2\n");
	fprintf(fout,"      CALL input_record()\n");
	fprintf(fout,"      IF abort_flag THEN\n");
	fprintf(fout,"        CALL abort_msg(\"%s\")\n",
		f->tables.tables_val[t].tabname);
	fprintf(fout,"        EXIT CASE\n");
	fprintf(fout,"      END IF\n");
	fprintf(fout,"      UPDATE %s SET * = gr_%s.*\n",
		f->tables.tables_val[t].tabname,
		f->tables.tables_val[t].tabname);
	fprintf(fout,"        WHERE oid = ga_oid[%d]\n", t+1);
	fprintf(fout,"      IF status <> 0 THEN\n");
	fprintf(fout,"        CALL err_msg(\"Error updating %s record\")\n",
		f->tables.tables_val[t].tabname);
	fprintf(fout,"        EXIT CASE\n");
	fprintf(fout,"      END IF\n");
	fprintf(fout,"      CALL err_msg(\"%s updated\")\n",
		f->tables.tables_val[t].tabname);
	fprintf(fout,"\n");
    }
    fprintf(fout,"  END CASE #gv_table_no\n");
    fprintf(fout,"  IF abort_flag THEN\n");
    fprintf(fout,"    CALL get_record()\n");
    fprintf(fout,"  END IF\n");
    fprintf(fout,"  CALL display_record()\n");
    fprintf(fout,"END FUNCTION\n");
    fprintf(fout,"\n");

printf("now in remove_record\n");
    fprintf(fout,"##################################################\n");
    fprintf(fout,"FUNCTION remove_record()\n");
    fprintf(fout,"##################################################\n");
    fprintf(fout,"\n");
    fprintf(fout,"  CASE gv_table_no\n");
    for (t=0;t< f->tables.tables_len; t++) {
	if (t>max_table) continue;
	fprintf(fout,"    WHEN %d\n", t+1);
	fprintf(fout,"      IF NOT ok_to_delete() THEN\n");
	fprintf(fout,"        EXIT CASE\n");
	fprintf(fout,"      END IF\n");
	fprintf(fout,"      DELETE FROM %s\n",
		f->tables.tables_val[t].tabname);
	fprintf(fout,"        WHERE oid = ga_oid[%d]\n", t+1);
	fprintf(fout,"      IF status <> 0 THEN\n");
	fprintf(fout,"        CALL err_msg(\"Error removing %s record\")\n",
		f->tables.tables_val[t].tabname);
	fprintf(fout,"        EXIT CASE\n");
	fprintf(fout,"      END IF\n");
	fprintf(fout,"      CALL err_msg(\"%s removed\")\n",
		f->tables.tables_val[t].tabname);
	fprintf(fout,"\n");
    }
    fprintf(fout,"  END CASE #gv_table_no\n");
    fprintf(fout,"  IF abort_flag THEN\n");
    fprintf(fout,"    CALL get_record()\n");
    fprintf(fout,"  END IF\n");
    fprintf(fout,"  CALL display_record()\n");
    fprintf(fout,"END FUNCTION\n");
    fprintf(fout,"\n");

printf("now in input_record\n");
    fprintf(fout,"##################################################\n");
    fprintf(fout,"FUNCTION input_record()\n");
    fprintf(fout,"##################################################\n");
    fprintf(fout,"\n");
    int fo_printed=0;
    for (a=0;a<f->attributes.attributes_len;a++) {
	if (strcmp(f->attributes.attributes_val[a].tabname,"formonly")==0) {
	    if (!fo_printed) {
		fprintf(fout,"  DEFINE gr_formonly RECORD\n");
		fo_printed++;
	    } else {
		fprintf(fout,",\n");
	    }
	    fprintf(fout,"\t%s\t", f->attributes.attributes_val[a].colname);
	    switch (f->attributes.attributes_val[a].datatype & DTYPE_MASK) {
		case DTYPE_CHAR:	fprintf(fout,"VARCHAR(100)"); break;
		case DTYPE_SMINT:	fprintf(fout,"SMALLINT"); break;
		case DTYPE_INT:		fprintf(fout,"INTEGER"); break;
		case DTYPE_SMFLOAT:	fprintf(fout,"SMALLFLOAT"); break;
		case DTYPE_FLOAT:	fprintf(fout,"FLOAT"); break;
		case DTYPE_DECIMAL:	fprintf(fout,"DECIMAL"); break;
		case DTYPE_DATE:	fprintf(fout,"DATE"); break;
		default:		fprintf(fout,"VARCHAR(300)"); break;
	    }
	}
    }
    if (fo_printed) {
	fprintf(fout,"\n\tEND RECORD\n");
	fprintf(fout,"\n");
    }
    fprintf(fout,"  LET int_flag = FALSE\n");
    fprintf(fout,"  LET abort_flag = FALSE\n");
    fprintf(fout,"  LET gv_attribute = get_color(0)\n");
    fprintf(fout,"  CASE gv_table_no\n");
    for (t=0;t< f->tables.tables_len; t++) {
	if (t>max_table) continue;
	fprintf(fout,"    WHEN %d\t# %s table\n", t+1,
		f->tables.tables_val[t].tabname);
        fprintf(fout,"      CASE gv_screen_no\n");
        for (s=0;s< f->snames.snames_len; s++) {
	    fprintf(fout,"        WHEN %d\t# %s screen %d\n", s+1,
		f->tables.tables_val[t].tabname, s+1);
	    attr_found = 0; printed = 0;
	    for (a=0;a<f->attributes.attributes_len;a++) {
		if (strcmp(f->attributes.attributes_val[a].tabname,
			       f->tables.tables_val[t].tabname)!=0) continue;
		int reject_field=0;
		for (b=0; b<f->attributes.attributes_val[a].bool_attribs.bool_attribs_len; b++) {
		  switch (f->attributes.attributes_val[a].bool_attribs.bool_attribs_val[b]) {
//		    case FA_B_NOENTRY: reject_field++; break;
		    case FA_B_NOUPDATE: reject_field++; break;
		    default: break;
		  }
		}
		if (reject_field) continue;
		ptr=screen_has_attribute(f,s, a);
		if (!ptr) continue;
		if (!attr_found) {
		    fprintf(fout,"          INPUT BY NAME\n");
		    attr_found++;
		}
		if (printed) fprintf(fout, ",\n");
		fprintf(fout,"            gr_%s.%s",
			f->attributes.attributes_val[a].tabname,
			f->attributes.attributes_val[a].colname);
		printed++;
	    }
	    if (attr_found) {
	      fprintf(fout,"\n");
	      fprintf(fout,"            WITHOUT DEFAULTS\n");
	      fprintf(fout,"            ON KEY (INTERRUPT)\n");
	      fprintf(fout,"                LET int_flag = TRUE\n");
	      fprintf(fout,"                LET abort_flag = TRUE\n");
	      fprintf(fout,"                EXIT INPUT\n");
	      fprintf(fout,"# before field validation\n");
//	print_control_block(f, fout);
	      print_validation(f, fout, t, s, 1, 7);
	      fprintf(fout,"# after field validation\n");
	      print_validation(f, fout, t, s, 2, 7);
	      fprintf(fout,"            AFTER INPUT\n");
	      print_validation(f, fout, t, s, 3, 7);
	      fprintf(fout,"              IF int_flag THEN\n");
	      fprintf(fout,"                LET int_flag = FALSE\n");
	      fprintf(fout,"                LET abort_flag = TRUE\n");
	      fprintf(fout,"              END IF\n");
	      fprintf(fout,"          END INPUT\n");
	      fprintf(fout,"\n");
	    }
        }
        fprintf(fout,"        END CASE # gv_screen_no\n");
        fprintf(fout,"        IF int_flag THEN\n");
        fprintf(fout,"          LET int_flag = FALSE\n");
	fprintf(fout,"          LET abort_flag = TRUE\n");
        fprintf(fout,"          RETURN\n");
        fprintf(fout,"        END IF\n");
	fprintf(fout,"\n");
    }
    fprintf(fout,"  END CASE # gv_table_no\n");

    fprintf(fout,"END FUNCTION\n");
    fprintf(fout,"\n");

    fprintf(fout,"##################################################\n");
    fprintf(fout,"FUNCTION print_report()\n");
    fprintf(fout,"##################################################\n");
    fprintf(fout,"END FUNCTION\n");
    fprintf(fout,"\n");
    dump_attr_lookup(f, fout);

    fclose(fout);
//  }


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
//      	if (a) fprintf (fout, ",");
      	  fprintf (fout, ",");
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
		if (strcmp(ptr2->comparitor,"ISNOTNULL")==0) {
			dump_expr_instructions (f, fout,ptr2->item1, lvl + 1);
			fprintf(fout," IS NOT NULL");
		}
		if (strcmp(ptr2->comparitor,"ISNULL")==0 ) {
			dump_expr_instructions (f, fout,ptr2->item1, lvl + 1);
			fprintf(fout," IS NULL");
		}
	} else {
//      		fprintf (fout,"(");
      		ptr2 = expr->u_expression_u.complex_expr;
      		dump_expr_instructions (f, fout,ptr2->item1, lvl + 1);
      		fprintf (fout," %s ", decode_comparitor(ptr2->comparitor));
      		dump_expr_instructions (f, fout,ptr2->item2, lvl + 1);
//      		fprintf (fout,")");
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
printf("\n#c=%d of %d\n",c, f->control_blocks.control_blocks_len);
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
		  if (!screen_has_attribute(f,s, a)) continue;
		  if (strcmp(f->attributes.attributes_val[a].tabname,
			f->tables.tables_val[t].tabname)!=0) continue;
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

/* ================================ EOF ============================= */
