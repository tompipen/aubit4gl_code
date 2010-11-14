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
# $Id: function_call_stack.c,v 1.45 2010-06-30 17:34:58 mikeaubury Exp $
#*/

/**
 * @file
 * Functions to imlement the mechanism of registering the function call
 * stack during a 4gl program execution and to suport the ability of doing
 * a printStackTrace like Java
 *
 * This facility is very good at java to store in log(s) or see imediatly
 * without need a debugger, wich functions have been called.
 *
 * @todo : Modify the compiler and the error function to call this facility
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/



#include "a4gl_libaubit4gl_int.h"


/*
=====================================================================
                    Constants definitions
=====================================================================
*/

#define MAX_FUNCTION_CALL_STACK 1000

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

static const char * html_escape_int (const char *s);


/*
=====================================================================
                    Variables definitions
=====================================================================
*/

/**
 * The type definition of a function call 
 */
typedef struct FunctionCall
{
  const char *moduleName;   /**< Module where function was called */
  int lineNumber;	    /**< Line in the 4gl where function was called */
  const char *funcModuleName;   /**< Module where function was called */
  int funcLineNumber;	    /**< Line in the 4gl where function was called */
  const char *functionName; /**< The name of the function called */
  const char *params;	    /**< a list of parameters passed to the function */
  int functionCallCnt;
}
FunctionCall;


/** 
 * This is just a running count of all of the calls made so far 
 * we use it to keep track of which calls come from which function calls when the same function 
 * is called multiple (recursive) times in the stack 
 * */
static int currFunctionCallCnt=0; 

/** The current function call stack */
static FunctionCall *functionCallStack;

/** The function pointer index */
static int functionCallPointer;

/** The current module where the program is flowing */
static const char *currentModuleName = "";

/** The current 4gl line number in the source where the program is working */
static int currentFglLineNumber = 0;

/** The current module where the program is flowing */
static const char *lastModuleName = "";

/** The current 4gl line number in the source where the program is working */
static int lastFglLineNumber = 0;



/** Flag that indicate that the stack info is used */
static int stackInfoInitialized = 0;

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

static void print_node(FILE *execprog, int cnt ,int lineno, char *rets) ;

/**
 * Initialize the function call stack
 *
 * @return
 *   - 0 : No memory for initializing the stack
 *   - 1 : Stack initialized
 */
void
A4GLSTK_initFunctionCallStack (void)
{
#ifdef DEBUG
  A4GL_debug ("Initializing Function Call Stack");
#endif

  functionCallStack = (FunctionCall *) calloc (sizeof (FunctionCall), MAX_FUNCTION_CALL_STACK);
  functionCallPointer = 0;
  stackInfoInitialized = 1;
#ifdef DEBUG
  A4GL_debug ("Done Initializing Function Call Stack");
#endif
}

/**
 * Set the current 4gl line and module where the program flows.
 *
 * @param moduleName The name of the module where the program is.
 * @param lineNumber The line at 4gl source where the program is.
 */
void
A4GLSTK_setCurrentLine (const char *moduleName, int lineNumber)
{
if (moduleName!=NULL) {
#ifdef DEBUG
	A4GL_debug("A4GLSTK_setCurrentLine : %s %d\n", moduleName,lineNumber);
#endif
} 
  lastModuleName=currentModuleName;
  currentModuleName = moduleName;
  lastFglLineNumber=currentFglLineNumber;
  currentFglLineNumber = lineNumber;
}


void
A4GLSTK_getCurrentLine (char **moduleName, int *lineNumber)
{
  *moduleName = (char *) currentModuleName;
  *lineNumber = currentFglLineNumber;
}

char *
A4GLSTK_lastSeenLine (void)
{
  static char buff[2000];
  SPRINTF2 (buff, "Module : %s  Line : %d", currentModuleName, currentFglLineNumber);
  return buff;
}


void
A4GLSTK_program_end (char*errMsg)
{
  if (acl_getenv_not_set_as_0 ("TRACE4GLEXEC"))
    {
      char *fname;
      fname = acl_getenv_not_set_as_0 ("TRACE4GLEXEC");

      if (functionCallPointer >= 1)
	{
	  FILE *execprog;
	  execprog = fopen (fname, "a");


	  if (execprog)
	    {
	      int a;

		if (errMsg) {
	      		fprintf (execprog,
		       "node_%d->ABEND [ fontsize=8 label=< <table border=\"0\"><tr><td>Line %d</td></tr></table> > ]\n",
		       functionCallStack[functionCallPointer - 1].functionCallCnt, currentFglLineNumber );

	      		fprintf (execprog,
		       		"ABEND [ fontsize=8 shape=record, label=< <table border=\"0\"><tr><td>ABNORMAL EXIT</td></tr><tr><td>%s</td></tr></table> > ]\n",
		       		html_escape_int(errMsg) );
		} else {
	      	fprintf (execprog,
		       "node_%d->EXITPROGRAM [ fontsize=8 label=< <table border=\"0\"><tr><td>Line %d</td></tr></table> > ]\n",
		       functionCallStack[functionCallPointer - 1].functionCallCnt, currentFglLineNumber);
		}


	      if (functionCallPointer > 1)
		{
		  for (a = functionCallPointer - 1; a >= 1; a--)
		    {
		      print_node (execprog, a, 0, NULL);
		    }

		  for (a = functionCallPointer; a >= 1; a--)
		    {

		      if (a > 1)
			{
			  fprintf (execprog, "node_%d->node_%d [ fontsize=8 label= <  Line:%d > ]\n",
				   functionCallStack[a - 2].functionCallCnt, functionCallStack[a - 1].functionCallCnt,
				   functionCallStack[a - 1].lineNumber);
			}
		    }
		}


	      fprintf (execprog, "}\n");
	      fclose (execprog);
	    }
	}
      else
	{
	  FILE *execprog;
	  execprog = fopen (fname, "a");


	  if (execprog)
	    {
	      fprintf (execprog, "node_%d->END [ fontsize=8 label=< <table border=\"0\"><tr><td>Line %d</td></tr></table> > ]\n",
		       functionCallStack[0].functionCallCnt, currentFglLineNumber);

	      fprintf (execprog, "}\n");
	      fclose (execprog);
	    }
	}
    }
}



static const char * html_escape_int (const char *s)
{
  static char *buff = 0;
  static int last_len = 0;
  int c;
  int a;
  int l;
  int b;
  int allocated;


  c = 0;
  //if (s==0) return "";

  if (strchr (s, '&'))
    c++;
  if (strchr (s, '<'))
    c++;
  if (strchr (s, '>'))
    c++;
  if (strchr (s, '"'))
    c++;
  if (strchr (s, '\''))
    c++;
  if (strchr (s, '\n'))
    c++;
  if (strchr (s, '\r'))
    c++;


  if (c == 0)
    {
      return s;
    }

  l = strlen (s);
  allocated = (l * 6) + 1;

  if (l > last_len)
    {
      buff = realloc (buff, allocated);
      last_len = l;
    }

  b = 0;
  for (a = 0; a < l; a++)
    {
      if (s[a] == '>')
	{
	  buff[b++] = '&';
	  buff[b++] = 'g';
	  buff[b++] = 't';
	  buff[b++] = ';';
	  continue;
	}
      if (s[a] == '<')
	{
	  buff[b++] = '&';
	  buff[b++] = 'l';
	  buff[b++] = 't';
	  buff[b++] = ';';
	  continue;
	}
      if (s[a] == '&')
	{
	  buff[b++] = '&';
	  buff[b++] = 'a';
	  buff[b++] = 'm';
	  buff[b++] = 'p';
	  buff[b++] = ';';
	  continue;
	}
      if (s[a] == '"')
	{
	  buff[b++] = '&';
	  buff[b++] = 'q';
	  buff[b++] = 'u';
	  buff[b++] = 'o';
	  buff[b++] = 't';
	  buff[b++] = ';';
	  continue;
	}
      if (s[a] == '\'')
	{
	  buff[b++] = '&';
	  buff[b++] = 'a';
	  buff[b++] = 'p';
	  buff[b++] = 'o';
	  buff[b++] = 's';
	  buff[b++] = ';';
	  continue;
	}
      if (s[a] < 31 || s[a] > 126)
	{
	  int z1;
	  char buff2[20];
	  z1 = ((unsigned char) s[a]);
	  sprintf (buff2, "&#x%02X;", z1);
	  for (z1 = 0; z1 < strlen (buff2); z1++)
	    {
	      buff[b++] = buff2[z1];
	    }
	  continue;
	}
      buff[b++] = s[a];
    }
if (b>=allocated) {

fprintf(stderr,"b=%d allocated=%d l=%d\n", b,allocated,l);
}
  A4GL_assertion (b >= allocated, "XML escape buffer too small");
  buff[b] = 0;
  return buff;
}



static char *
html_escape (const char *s) {
char *rval;
static int n=0;
static char *buff[5]={NULL,NULL,NULL,NULL,NULL};

if (buff[n]) {
	free(buff[n]); 
	buff[n]=0;
}

buff[n]=strdup(html_escape_int(s));


rval=buff[n];
n++;
if (n>=5)  n=0;
return rval;

}
//* print a node (a function call) into the trace file (only if TRACE4GLEXEC is set) */
static void print_node(FILE *execprog, int cnt ,int lineno, char *rets) {
char funcname[60000];

	if (execprog) {
			char *color;
			if (cnt==0) { // MAIN
				color="#e0e0ff";
				sprintf(funcname,"MAIN(%s)", A4GL_get_args_string());
			} else {
				color="#c0c0f0";
				sprintf(funcname,"%s(%s)",functionCallStack[cnt].functionName, html_escape(functionCallStack[cnt].params?functionCallStack[cnt].params:""));
			}

			if (rets) {
				fprintf(execprog,"node_%d [  fontsize=8 shape=record, label=< <table border=\"0\"  ><tr><td bgcolor=\"%s\">%s</td></tr><tr><td align=\"left\">%s:%d</td></tr><tr><td align=\"left\">Returns Line %d</td></tr><tr><td align=\"left\">%s</td></tr></table> > ]\n",
				functionCallStack[cnt].functionCallCnt,
				color,
				funcname,
				functionCallStack[cnt].funcModuleName,
				functionCallStack[cnt].funcLineNumber,
				lineno,rets
				);
			} else {
			fprintf(execprog,"node_%d [  fontsize=8 shape=record, label=< <table border=\"0\" ><tr><td bgcolor=\"%s\">%s</td></tr><tr><td align=\"left\">%s:%d</td></tr></table> > ]\n",
				functionCallStack[cnt].functionCallCnt,
				color,
				funcname,
				functionCallStack[cnt].funcModuleName,
				functionCallStack[cnt].funcLineNumber);
			}
	}
				

}

/**
 * Push a function called to the function stack.
 *
 * @param functionName The name of the function called.
 */
void
A4GLSTK_pushFunction (const char *functionName, char *params[], int n,char *this_module, int this_line_number)
{
	char *fname;

  if (!A4GL_has_initialized ())
    {
      A4GL_fgl_start (0, 0);
      A4GLSTK_initFunctionCallStack ();
    }

  if (functionCallStack==0) {
	A4GLSTK_initFunctionCallStack();
	}

#ifdef DEBUG 
{
  int a=0;
  A4GL_debug ("Call from Module : %s line %d", A4GL_null_as_null(currentModuleName), currentFglLineNumber, this_line_number);
  A4GL_debug ("=====&&&&&&============PUSH %s %d,\n", functionName, n);

  for (a = 0; a < n; a++)
    {
      if (params[a] == 0)
	{
	  A4GL_debug ("Theres gonna be trouble - wasn't expecting this one..");
	}
      else
	{
	  A4GL_debug (" Param %d (%s)", a + 1, params[a]);
	}
    }
}
#endif
  A4GL_assertion (functionCallPointer >= MAX_FUNCTION_CALL_STACK, "Function calls too deep (perhaps a missing popFunction ?");

  currFunctionCallCnt++;
  functionCallStack[functionCallPointer].functionName = functionName;

  functionCallStack[functionCallPointer].funcModuleName = this_module;
  functionCallStack[functionCallPointer].funcLineNumber = this_line_number;

  functionCallStack[functionCallPointer].moduleName = currentModuleName;
  functionCallStack[functionCallPointer].lineNumber = currentFglLineNumber;
  functionCallStack[functionCallPointer].functionCallCnt = currFunctionCallCnt;



  if (n && params[0] == 0)
    {
      functionCallStack[functionCallPointer].params = A4GL_params_on_stack (params, 0);
    }
  else
    {
      functionCallStack[functionCallPointer].params = A4GL_params_on_stack (params, n);
    }

  fname=acl_getenv_not_set_as_0("TRACE4GLEXEC");
  if (fname) {
	if (functionCallPointer==0) {
		FILE *execprog;
		execprog=fopen(fname,"w");
		if (execprog) {
			fprintf(execprog,"digraph { // process with 'dot' - eg :   dot -o callgraph.gif -Tgif callgraph.dot\n");
			fprintf(execprog,"rankdir=LR;\n");
			fprintf(execprog,"ratio=fill;\n");
			print_node(execprog, 0,0, NULL);
			fclose(execprog);
		}
	}
  }


#ifdef DEBUG
  A4GL_debug ("%s(%s)", functionName, A4GL_null_as_null ((char *) functionCallStack[functionCallPointer].params));
#endif
  functionCallPointer++;
  A4GLSTK_setCurrentLine(this_module,this_line_number);
}

void A4GLSTK_popFunction (void) {
	A4GLSTK_popFunction_nl (0,0);
}



/**
 * Pop the last function from the stack.
 */
void
A4GLSTK_popFunction_nl (int nrets,int lineno )
{

      char *fname;
      fname = acl_getenv_not_set_as_0 ("TRACE4GLEXEC");

      if (fname)
	{

	  if (functionCallPointer > 1)
	    {
	      FILE *execprog;
	      execprog = fopen (fname, "a");
	      if (execprog)
		{

		if (nrets) {
			print_node(execprog, functionCallPointer-1, lineno, html_escape(A4GL_params_on_stack (NULL,nrets)));
		  fprintf (execprog, "node_%d->node_%d [ fontsize=8 dir=both label= < Line:%d > ]\n",
			   functionCallStack[functionCallPointer - 2].functionCallCnt,
			   functionCallStack[functionCallPointer-1].functionCallCnt, 
			   	functionCallStack[functionCallPointer-1].lineNumber
			);
		} else {
			print_node(execprog, functionCallPointer-1, 0, NULL);
		  fprintf (execprog, "node_%d->node_%d [ fontsize=8 label= <  Line:%d > ]\n",
			   functionCallStack[functionCallPointer - 2].functionCallCnt,
			   functionCallStack[functionCallPointer-1].functionCallCnt, 
			   	functionCallStack[functionCallPointer-1].lineNumber
				);

		}
		  fclose (execprog);
		}
	    }
	}

  if (functionCallStack[functionCallPointer - 1].params)
    {
      free ((void *) functionCallStack[functionCallPointer - 1].params);
      functionCallStack[functionCallPointer - 1].params = 0;
    }

  functionCallPointer--;
  if (functionCallPointer < 0)
    functionCallPointer = 0;
}


char *
A4GLSTK_topFunction (void)
{
  if (functionCallPointer)
    {
      return (char *) functionCallStack[functionCallPointer - 1].functionName;
    }
  else
    {
      return "MAIN";
    }
}


/**
 * Generate a string with the current 4gl stack trace.
 *
 * @return A pointer to a static char buffer where the stack trace was printed.
 */
char *
A4GLSTK_getStackTrace (void)
{
  static char stackTrace[6400];
  static char tmpStackTrace[6400];
  int i;

  strcpy (stackTrace, "4gl function call stack :\n");
  for (i = functionCallPointer - 1; i >= 0; i--)
    {
      strcat (stackTrace, "    ");
      if (functionCallStack[i].moduleName == '\0')
	strcat (stackTrace, (char *) functionCallStack[i].functionName);
      else
	{
	  SPRINTF3 (tmpStackTrace,
		    "%s (Line %d) calls  %s",
		    functionCallStack[i].moduleName, functionCallStack[i].lineNumber,
		    //functionCallStack[i].funcModuleName, functionCallStack[i].funcLineNumber,
 			functionCallStack[i].functionName
			);

	  if (strlen (stackTrace) + strlen (tmpStackTrace) < sizeof (stackTrace) + 5)
	    {
	      strcat (stackTrace, tmpStackTrace);
	    }
	  else
	    {
	      strcat (stackTrace, "\n...");
	    }
	}

      /* Don't put the brackets on for a MAIN */
      if (strcmp (functionCallStack[i].functionName, "MAIN") != 0)
	{
	  strcat (stackTrace, "(");

	  if (functionCallStack[i].params)
	    {
	      char buff[90];
	      strncpy (buff, functionCallStack[i].params, 81);
	      buff[81] = 0;
	      if (strlen (buff) >= 80)
		{
		  strcat (buff, "...");
		}
	      if (strlen (stackTrace) + strlen (buff) < sizeof (stackTrace) + 5)
		{
		  strcat (stackTrace, buff);
		}
	    }
	  strcat (stackTrace, ")");
	}
      strcat (stackTrace, "\n");


    }
  return stackTrace;
}

/**
 * To verify that the stack info is allready initialized.
 * 
 * @return 
 *   - 0 : Stack info not initialized.
 *   - 1 : Stack info initialized.
 */
int
A4GLSTK_isStackInfo (void)
{
  return stackInfoInitialized;
}

/* ============================= EOF ================================ */
