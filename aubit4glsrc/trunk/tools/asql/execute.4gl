code


#include <stdio.h>
#include <stdlib.h>
$include sqltypes;
$int numberOfColumns=0;
int width;
int display_mode;
int fetchFirst=0;
#define DISPLAY_ACROSS 1
#define DISPLAY_DOWN   2
#define DISPLAY_LINES 18

FILE *out=0;
int outlines=0;

char outfname[255]="";

static int get_size(int dtype,int size) ;
static int field_widths(void) ;
char **columnNames=0;
int *columnWidths=0;

#define EXEC_MODE_INTERACTIVE   0
#define EXEC_MODE_FILE          1


struct element {
        int lineno;
        char type;
        char *stmt;
};

char *get_qry_msg(int qry_type,int n);

extern struct element *list;
extern int list_cnt;




int ec_check_and_report_error() {
	if (sqlca.sqlcode<0) {
		aclfgl_check_and_report_error(0);
		return 1;
	} else {
		return 0;
	}


		//return 1;
	//} else {
		//return 0;
	//}
}
endcode
define exec_mode integer


# Set execute mode
#
#    0 = interactive
#    1 = SQL being read from a file
#
function set_exec_mode(em) 
define em integer
let exec_mode=em
end function

function get_exec_mode()
return exec_mode
end function

function confirm(qry_type) 
define qry_type integer

	if exec_mode=1 then
		return 0
	end if

	if qry_type=32 or qry_type=33 then 
		return 1
	end if
	return 0
end function


function execute_queries()
define a integer
define msg char(80)
define qry_type integer
define lv_cont integer
define rpaginate integer
let msg=""
options message line last
code
	for (a=0;a<list_cnt;a++) {
		$char *p;

		//printf("%d %c - %s\n",list[a].lineno,list[a].type,list[a].stmt);
		p=list[a].stmt;

			$prepare stExec from $p;
			if (ec_check_and_report_error()) { break; }

			EXEC SQL ALLOCATE DESCRIPTOR "d1";
        		EXEC SQL DESCRIBE stExec USING SQL DESCRIPTOR "d1";
			qry_type=sqlca.sqlcode;
			EXEC SQL DEALLOCATE DESCRIPTOR "d1";
			if (ec_check_and_report_error()) { break; }


endcode
	let lv_cont=1
	IF confirm(qry_type) THEN
		MENU "Confirm "
			command "Yes" "Really do it" 
				let lv_cont=1
				exit menu
			command "No" "Don't do it" 
				return 0
		END MENU
	END IF

code
	

		

			// Is it a select statement ?
			// @todo - this needs refining as a select .. into temp would get caught..
			if (list[a].type!='S') {
				$execute stExec;
				a=sqlca.sqlerrd[0];
				if (ec_check_and_report_error()) { break; }
				$free stExec;
				if (ec_check_and_report_error()) { break; }
			} else {
				a=0;
				rpaginate=0;
repeat_query: ;
	A4GL_debug("Repeat query out=%p\n",out);
				if (execute_select_prepare()) {
					while (1) {
					int b;
					char buff[244];
						b=execute_sql_fetch();

					//printf("Got %d from fetch\n",b);
				
						if (exec_mode==EXEC_MODE_INTERACTIVE) {
							while (outlines>DISPLAY_LINES) {
								aclfgl_paginate(0);
								rpaginate=A4GL_pop_int();
								if (rpaginate!=0) break;
								fetchFirst=1;
							}
							if (rpaginate!=0) break;

							if (b!=0) break;

						} else {
							//printf("Non-interactive...");
							rpaginate=0;
							if (b!=0) break;
						}
						a++;
					}
					//printf("Here1\n");

					if (rpaginate==1) {
						//printf("Repeat\n");
						goto repeat_query;
					}


					if (rpaginate==2) {
			//printf("Return");
endcode
	
						return 0;
code
					}

	//printf("Close\n");

					if (out) {fclose(out);out=0;}
					if (outlines&& exec_mode==EXEC_MODE_INTERACTIVE) {
						aclfgl_paginate(0);
					}
					$close c1;
					if (ec_check_and_report_error()) { break; }
					$free c1;
					if (ec_check_and_report_error()) { break; }
					$free stExec;
					if (ec_check_and_report_error()) { break; }
					sqlca.sqlerrd[0]=a;
					
				} else {
					A4GL_push_char("Error executing select");
   					A4GL_display_error(0,0);
					sleep(1);
				}
			}

			if (ec_check_and_report_error()) { break; }
	}
	sprintf(msg,"Q:%d %d - ( %s )",qry_type, a,get_qry_msg(qry_type,a));
endcode

if sqlca.sqlcode>=0 then
	if exec_mode=0 then
		message msg clipped
	else
		display msg clipped
	end if
	return 1
else
	return 0
end if
end function




code
int isSqlError () {
	if (sqlca.sqlcode<0) return 1;
	return 0;
}

static int
printField (FILE * unloadFile, int idx, char *descName)
{
  EXEC SQL BEGIN DECLARE SECTION;
  int dataType;
  int index = idx;
  short indicator;
  char buffer[32000]="";

  char *descriptorName = descName;
  int length;
  loc_t blob;

  char *char_var;
  short smint_var;
  long int_var;
  double float_var;
  float smfloat_var;
  dec_t decimal_var;
  long date_var;
  dec_t money_var;
  dtime_t dtime_var;
  intrvl_t interval_var;
  /*
     fglbyte byte_var;
     fgltext text_var;
   */
  EXEC SQL END DECLARE SECTION;
  //FglDecimal *fgl_decimal;
  //FglMoney *fgl_money;
  //FglDatetime *fgl_dtime;
  //FglInterval *fgl_interval;
  char buff[255];
  int rc = 0;


A4GL_assertion(out==0,"No output file");




  EXEC SQL GET DESCRIPTOR 'descExec' VALUE:index:indicator =
    INDICATOR,:dataType = TYPE;


//printf("printField %d - dt=%d i=%d",idx,dataType,indicator);

  //if (indicator == -1) { return 0; }


if (indicator!=-1) {
  switch (dataType&0xf)
    {
    case SQLCHAR:
    case SQLVCHAR:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index:length =
        LENGTH;
      if (isSqlError ())
        {
          rc = 1;
          break;
        }
      char_var = (char *)malloc (length + 1);
      EXEC SQL GET DESCRIPTOR:descriptorName VALUE:index:char_var = DATA;
      A4GL_trim (char_var);
      sprintf (buffer, "%s", char_var);
      free (char_var);
      break;
    case SQLSMINT:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index: dataType = TYPE,:smint_var =
        DATA;
      if (isSqlError ())
        {
          rc = 1;
          break;
        }
      sprintf (buffer, "%d", smint_var);
      break;

    case 6:
    case SQLINT:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index: dataType = TYPE,:int_var =
        DATA;
      if (isSqlError ())
        {
          rc = 1;
          break;
        }
      sprintf (buffer, "%ld", int_var);
      break;
    case SQLFLOAT:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index: dataType = TYPE,:float_var =
        DATA;
      if (isSqlError ())
        {
          rc = 1;
          break;
        }
      sprintf (buffer, "%lf", float_var);
      break;
    case SQLSMFLOAT:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index: dataType = TYPE,:smfloat_var =
        DATA;
      if (isSqlError ())
        {
          rc = 1;
          break;
        }
      sprintf (buffer, "%f", smfloat_var);
      break;
    case SQLDECIMAL:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index: dataType = TYPE,:decimal_var =
        DATA;
      if (isSqlError ())
        {
          rc = 1;
          break;
        }
      //fgl_decimal = malloc (sizeof (fgldecimal));
      if (dectoasc (&decimal_var, buff, 64, -1))
        {
		A4GL_debug("BAD DECIMAL");
        /** @todo : Store the error somewhere */
          return 1;
        }
      sprintf (buffer, "%s", buff);
      //free (fgl_decimal);
      break;
    case SQLDATE:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index: dataType = TYPE,:date_var =
        DATA;
      if (isSqlError ())
        {
          rc = 1;
          break;
        }
      /** @todo : Print as date field */
      char_var = (char *)malloc (sizeof (char) * 10);
      A4GL_dtos (&date_var, char_var, 10);
      sprintf (buffer, "%s", char_var);
      free (char_var);
      break;
    case SQLMONEY:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index: dataType = TYPE,:money_var =
        DATA;
      if (isSqlError ())
        {
          rc = 1;
          break;
        }
      //fgl_money = malloc (sizeof (fglmoney));
      if (dectoasc (&money_var, buff, 64, -1))
        {
        /** @todo : Store the error somewhere */
	A4GL_debug("Bad money");
          return 1;
        }
      sprintf (buffer, "%s", buff);
      //free (fgl_money);
      break;
    case SQLDTIME:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index: dataType = TYPE,:dtime_var =
        DATA;
      if (isSqlError ())
        {
          rc = 1;
          break;
        }
      //fgl_dtime = malloc (sizeof (FglDatetime));
      if (dttoasc (&dtime_var, buff))
        {
        /** @todo : Store the error somewhere */
	A4GL_debug("Bad dtime");
          return 1;
        }
      sprintf (buffer, "%s", buff);
      //free (fgl_dtime);
      break;
    case SQLINTERVAL:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index: dataType = TYPE,:interval_var =
        DATA;
      if (isSqlError ())
        {
          rc = 1;
          break;
        }
      //fgl_interval = malloc (sizeof (FglInterval));
      if (intoasc (&interval_var, buff))
        {
        /** @todo : Store the error somewhere */
	A4GL_debug("Bad itime");
          return 1;
        }
      sprintf (buffer, "%s", buff);
      //free (fgl_interval);
      break;
    case SQLBYTES:
      break;
    case SQLTEXT:
      break;
    default:
	A4GL_debug("INVALID DATATYPE %d %x @ %d+++",dataType,dataType,idx);
      A4GL_exitwith ("Invalid data type\n");
    }
} else {
	strcpy(buffer,"");
}

//printf("PRINTING\n");




	if (display_mode==DISPLAY_DOWN) {
		fprintf(unloadFile,"%-20.20s %s\n",columnNames[idx-1],buffer);
		outlines++;
	} else {
		fprintf(unloadFile,"%*s",columnWidths[idx-1],buffer);
  	}


  return 0;
}


/******************************************************************************/
int execute_select_prepare() {
int cnt;
fetchFirst=1;
strcpy(outfname,"out.txt");

if (out) {
	fclose(out);
	out=0;
}


if (out==0) {
	out=fopen(outfname,"w");
	A4GL_assertion(out==0,"Unable to open output file");
}


$whenever error continue;
$deallocate descriptor 'descExec';

$allocate descriptor 'descExec' ;
	if (sqlca.sqlcode<0) return 0;

$describe stExec USING SQL DESCRIPTOR 'descExec';
	if (sqlca.sqlcode<0) return 0;

$get descriptor 'descExec' :numberOfColumns=COUNT;
	if (sqlca.sqlcode<0) return 0;

$declare crExec CURSOR FOR stExec;
	if (sqlca.sqlcode<0) return 0;

$open crExec ;
	if (sqlca.sqlcode<0) return 0;


if (exec_mode==0) {
	if (field_widths()>A4GL_get_curr_width()) {
		display_mode=DISPLAY_DOWN;
	} else {
		display_mode=DISPLAY_ACROSS;
	}
} else {

	if (field_widths()>132) {
		display_mode=DISPLAY_DOWN;
	} else {
		display_mode=DISPLAY_ACROSS;
	}
}



}




/******************************************************************************/
int execute_sql_fetch() {
int a;
	
	$FETCH crExec USING SQL DESCRIPTOR 'descExec';

	if (sqlca.sqlcode<0) {
		A4GL_push_char("Fetch error...");
		A4GL_display_error(0,0);
		sleep(1);
		return sqlca.sqlcode;
	}

	if (sqlca.sqlcode==100) {
		//printf("100\n");
		return 100;
	}


	if (display_mode==DISPLAY_ACROSS&&fetchFirst==1) {
		for (a=0;a<numberOfColumns;a++) {
			fprintf(out,"%-*.*s ",columnWidths[a],columnWidths[a],columnNames[a]);
		}
		fprintf(out,"\n\n");
		outlines+=2;
		fetchFirst=0;
	}
	

	for (a=1;a<=numberOfColumns;a++) {
		//printf("Print %d of %d - %s\n",a,numberOfColumns,columnNames[a-1]);
		if (printField(out,a,"descExec")==1) {
			A4GL_debug("Break Early %d of %d",a,numberOfColumns);
			break;
		}
	}

	if (display_mode==DISPLAY_ACROSS) {
		fprintf(out,"\n");
		outlines++;
	}

	if (display_mode==DISPLAY_DOWN) {
		fprintf(out,"\n");
		outlines++;
	}

	return sqlca.sqlcode;
}



/******************************************************************************/
static int field_widths() {
$int index;
$int datatype;
$int size;
$char columnName[64];
int totsize=0;

if (columnNames) {
	int a;
	for (a=0;columnNames[a];a++) free(columnNames[a]);
	free(columnNames);
	columnNames=0;
}

if (columnWidths) {
	free(columnWidths);
	columnWidths=0;
}


columnNames=malloc(sizeof(char*) * (numberOfColumns+1));
columnWidths=malloc(sizeof(int) * (numberOfColumns+1));


for(index=1;index<=numberOfColumns;index++) {
	$GET DESCRIPTOR 'descExec' VALUE: index :size=LENGTH , :datatype=TYPE,
		:columnName=NAME
	;
	A4GL_trim(columnName);
	columnNames[index-1]=strdup(columnName);

	size=get_size(datatype,size);
	if (size<strlen(columnNames[index-1])) size=strlen(columnNames[index-1]);


	if (strlen(columnName)>size) {
		size=strlen(columnName);
	}
	columnWidths[index-1]=size;
	totsize+=size+1;
}

columnNames[numberOfColumns]=0;
return totsize;

}





/******************************************************************************/
static int get_size(int dtype,int size) {
	switch(dtype ) {
		case SQLCHAR: 	return size;
		case SQLSMINT: 	return  5;
		case SQLINT: 	return  10;
		case SQLFLOAT: 	return  10;
		case SQLSMFLOAT: 	return  10;
		case SQLDECIMAL: 	return  16;
		case SQLSERIAL: 	return  10;
		case SQLDATE: 	return  12;
		case SQLMONEY: 	return  17;
		case SQLDTIME: 	return  17;
		case SQLBYTES: 	return  20;
		case SQLTEXT: 	return  20;
		case SQLVCHAR: 	return size; 
		case SQLINTERVAL: 	return 20; 
	}
return 10;
}







#define MAX_QRY  50


char *qry_strings[255]={

"%d Rows found", // 0
"Database selected",
"%d Rows found",
"%d rows selected into temp table",
"%d rows updated",
"%d rows deleted",
"row inserted",
0,
0,
0,
"Table Locked", // 10



"Table Unlocked",
"Database Created",
"Database Dropped",
"Table Created",
"Table Dropped",
"Index Created",
"Index Dropped",
"Permissions granted",
"Permissions revoked",
"Table renamed", // 20

"Column renamed",
0,
0,
0,
0,
0,
0,
0,
"Table altered",
"Statistics updated", // 30


"Database closed",
"%d rows deleted",
"%d rows updated",
"Transaction started",
"Transaction committed",
"Transaction rolled back",
0,
0,
0,
"View Created", //40


"View Dropped",
0,
"Synonym created",
"Synonym dropped",
"Temp table created",
"Lock mode set",
"Index Altered",
"Isolation set",
"Log set"
"Explain mode set", // 50





0};





char *get_qry_msg(int qry_type,int n) {
static buff[256];
	if (qry_type<=MAX_QRY) {
		sprintf(buff,qry_strings[qry_type],n);
	} else {
		sprintf(buff,"Operation successed (%d) rows affected",n);
	}
	return buff;
}
endcode


