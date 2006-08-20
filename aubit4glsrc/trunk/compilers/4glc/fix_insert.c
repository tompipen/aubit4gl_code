//#include "a4gl_4glc_int.h"
#include "a4gl_libaubit4gl.h"


char *fix_insert_expr (int mode);
void do_yyerror (char *s);
//void push_gen (int a, char *s);

#include <ctype.h>
#include <errno.h>

int A4GL_db_used(void);

#include "gen_stack.h"
#ifndef DEFINED_INS_TABLE
extern char current_ins_table[256];
#endif



#ifndef IS_SERIAL
#define IS_SERIAL 'V'
#endif

static int is_serial_column(char *tabname,char *colname) {
	char buff[256];
	SPRINTF2(buff,"%s.%s",tabname,colname);
	if (A4GL_has_pointer(buff,'V')) {
		return 1;
	}
	return 0;
}

static void
dump_insvals (void)
{
  int a;
  int c;
  c=A4GL_4glc_gen_cnt(INSCOL);
  for (a = 0; a < c; a++)
    {
      PRINTF ("INSCOL[%d] : %s\n", a, A4GL_4glc_get_gen(INSCOL,a));
    }

  for (a = 0; a < c; a++)
    {
	if (a<A4GL_4glc_gen_cnt(INSVAL)) {
      			PRINTF ("INSVAL[%d] : %s\n", a,A4GL_4glc_get_gen(INSVAL,a));
	} else {
			PRINTF ("INSVAL[%d] : ...\n",a);
	}
    }
}


static void
trim_spaces (char *s)
{
  int l;
  for (l = strlen (s) - 1; l >= 0; l--)
    {
      if (s[l] == ' ')
        s[l] = 0;
      else
        break;
    }
}

char *
fix_insert_expr (int mode)
{
  static char big_buff[20000];
  int a;
  int b;
  int rval;
  int isize = 0;
  int idtype = 0;
  int added;
  int found;
  char colname[256] = "";
  static int *idtypes=0;
  static int *idtypes_t=0;
  /*char csize[20]; */
  /*char cdtype[20]; */
  char buff[1000];
  char *ccol;
  int copy_ids=0;
  strcpy (big_buff, "");
  A4GL_4glc_clr_gen(TCOL);

  if (idtypes) { free(idtypes); idtypes=0; }
  if (idtypes_t) { free(idtypes_t); idtypes_t=0; }


  if (mode == 1)
    {
      if (A4GL_db_used() == 0)
	{
	  SPRINTF0 (buff, "You appear to have 'FULL_INSERT' set.\nBecause of this - you cannot INSERT into this table without specifying a database");
	  do_yyerror (buff);
	  return 0;
	}


	if (A4GL_4glc_gen_cnt(INSCOL)==1 && strcmp(A4GL_4glc_get_gen(INSCOL,0),"*")==0) {
      		/* It will only be a '*' anyway.... */
		A4GL_4glc_clr_gen(INSCOL);
      		rval = A4GLSQL_get_columns (current_ins_table, colname, &idtype, &isize);
      		strcpy (colname, "");
      		if (rval == 0) {
	  		FPRINTF (stderr,"Warning: Can't fix insert statement - Table %s is not in the database(1)\n",current_ins_table);
	  		return 0;
	  		//do_yyerror ("Table is not in the database");
	  		//return 0;
		}


      		while (1) {
	  		colname[0] = 0;
	  		rval = A4GLSQL_next_column (&ccol, &idtype, &isize);
	  		strcpy (colname, ccol);
	  		if (rval == 0)
	    		break;
	  		trim_spaces (colname);
			if (is_serial_column(current_ins_table, colname)) idtype=DTYPE_SERIAL;
	  		A4GL_4glc_push_gen (INSCOL, colname);
			idtypes=acl_realloc(idtypes,sizeof(int)*  A4GL_4glc_gen_cnt(INSCOL));
			idtypes[A4GL_4glc_gen_cnt(INSCOL)-1]=idtype;
		}
      		A4GLSQL_end_get_columns ();

    	} else {
      		strcpy (colname, "");
      		rval = A4GLSQL_get_columns (current_ins_table, colname, &idtype, &isize);


      		if (rval == 0) {
	  		FPRINTF (stderr,"Warning: Can't fix insert statement - Table %s is not in the database (2)\n",current_ins_table);
	  		return 0;
		}


      		while (1) {
	  		colname[0] = 0;
	  		rval = A4GLSQL_next_column (&ccol, &idtype, &isize);
	  		strcpy (colname, ccol);
	  		if (rval == 0)
	    		break;
	  		trim_spaces (colname);
			if (is_serial_column(current_ins_table, colname)) idtype=DTYPE_SERIAL;
	  		A4GL_4glc_push_gen (TCOL, colname);


			idtypes_t=acl_realloc(idtypes_t,sizeof(int)*A4GL_4glc_gen_cnt(TCOL));
			idtypes_t[A4GL_4glc_gen_cnt(TCOL)-1]=idtype;
		}
      		A4GLSQL_end_get_columns ();
	}

  }



  if (A4GL_4glc_gen_cnt(INSCOL) != A4GL_4glc_gen_cnt(INSVAL))
    {
	    char buff[256];
	    SPRINTF2 (buff,"Number of columns in insert not the same as number of values (%d!=%d)",A4GL_4glc_gen_cnt(INSCOL),A4GL_4glc_gen_cnt(INSVAL));
      		dump_insvals ();
      		do_yyerror (buff);
    }
  strcpy (big_buff, "(");


  // Lets do a quick check that our column names exist

  if (A4GL_4glc_gen_cnt(TCOL)) {
	for (b=0;b<A4GL_4glc_gen_cnt(INSCOL);b++) {
		found=0;
  		for (a=0;a<A4GL_4glc_gen_cnt(TCOL);a++) {
			if (strcasecmp(A4GL_4glc_get_gen(INSCOL,b),A4GL_4glc_get_gen(TCOL,a))==0) {

				found++;
				break;
			}
			if (strcasecmp(A4GL_4glc_get_gen(INSCOL,b),A4GL_confirm_colname (current_ins_table,A4GL_4glc_get_gen(TCOL,a)))==0) {
				found++;
				break;
			}
		}
	
			if (!found) {
				FPRINTF(stderr,"Warning : Table %s Column %s not found for insert\n",current_ins_table,A4GL_4glc_get_gen(INSCOL,b));
		}
  	}


	copy_ids=0;

	if (idtypes_t && idtypes==0) {
		copy_ids=1;
		idtypes=acl_realloc(idtypes,sizeof(int)*A4GL_4glc_gen_cnt(TCOL));
		for (a=0;a<A4GL_4glc_gen_cnt(TCOL);a++) { 
			idtypes[a]=-1; 
		}
	}


  	// As we're doing a full insert - lets add any missing columns along with 
  	// their value (which is a null)
  	for (a=0;a<A4GL_4glc_gen_cnt(TCOL);a++) {
		found=0;
		for (b=0;b<A4GL_4glc_gen_cnt(INSCOL);b++) {
			if (strcmp(A4GL_4glc_get_gen(INSCOL,b),A4GL_4glc_get_gen(TCOL,a))==0) {
				found++;
				break;
			}

			if (strcmp(A4GL_4glc_get_gen(INSCOL,b),A4GL_confirm_colname (current_ins_table,A4GL_4glc_get_gen(TCOL,a)))==0) {
				found++;
				break;
			}
		}
	
		if (!found) {
	  			A4GL_4glc_push_gen (INSCOL, A4GL_4glc_get_gen(TCOL,a));
	  			A4GL_4glc_push_gen (INSVAL, "NULL");
		}
	}



  	for (a=0;a<A4GL_4glc_gen_cnt(TCOL);a++) {
		found=0;
		A4GL_assertion(idtypes==0,"idtypes=0");
		A4GL_assertion(idtypes_t==0,"idtypes_t=0");
		for (b=0;b<A4GL_4glc_gen_cnt(INSCOL);b++) {
			idtypes=acl_realloc(idtypes,sizeof(int)*  A4GL_4glc_gen_cnt(INSCOL));
			if (strcmp(A4GL_4glc_get_gen(INSCOL,b),A4GL_4glc_get_gen(TCOL,a))==0) {
				idtypes[b]=idtypes_t[a];
				found++;
				break;
			}
			if (strcmp(A4GL_4glc_get_gen(INSCOL,b),
				A4GL_confirm_colname (
					current_ins_table,
					A4GL_4glc_get_gen(TCOL,a)
				))==0) {
				idtypes[b]=idtypes_t[a];
				found++;
				break;
		}
			
		}
	
		// This is a worry - it should have been added already
		A4GL_assertion(!found,"Column not added for full insert");
  	}







  }



  for (a = 0; a < A4GL_4glc_gen_cnt(INSVAL); a++)
    {
      SPRINTF1 (buff, "%s", A4GLSQLCV_insert_alias_value (current_ins_table, A4GL_4glc_get_gen(INSCOL,a), 
			      		A4GL_4glc_get_gen(INSVAL,a),idtypes[a]));
	strcpy(A4GL_4glc_get_gen(INSVAL,a),buff);
    }

  added=0;
  for (a = 0; a < A4GL_4glc_gen_cnt(INSCOL); a++)
    {
      SPRINTF1 (buff, "%s", A4GLSQLCV_insert_alias_column (current_ins_table, 
			      		A4GL_4glc_get_gen(INSCOL,a), 
					A4GL_4glc_get_gen(INSVAL,a),idtypes[a]));
	if (strlen(buff)) {
      		if (added) strcat (big_buff, ",");
      		strcat (big_buff, buff);
		added++;
	} else {
		strcpy(A4GL_4glc_get_gen(INSVAL,a),""); // We're removing thing column from the INSERT, so remove the value too
	}

    }


  strcat (big_buff, ") VALUES (");

  added=0;
  for (a = 0; a < A4GL_4glc_gen_cnt(INSVAL); a++)
    {
	if (strlen(A4GL_4glc_get_gen(INSVAL,a))) {
      		if (added) strcat (big_buff, ",");
      		strcat (big_buff, A4GL_4glc_get_gen(INSVAL,a));
		added++;
	}
	
    }

  strcat (big_buff, ")");
  return big_buff;
}



