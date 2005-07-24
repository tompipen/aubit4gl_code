/**
 * @file
 * Dump all the information in the abstract tree to the standard output.
 * Symbol table dump in html format. It have crossed links between
 * information.
 *
 * It works only if p4gl was executed with --html option.
 *
 * FIXME: it does not show table names parsewd from comments (@table tag)
 *
 * See also: GenFglDoc.c - Generate the fgldoc in static html for this module.
 *
 * This action is also made by the manager (fgldoc Perl script)
 * but implies the existance of information in the repository.
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <stdio.h>
#include <ctype.h>
#include <varargs.h>
#include "p4gl_symtab.h"

static FILE *f_dump;

/**
 * Header of the dump of the symbol table.
 */
static void DumpHeader(void)
{
   fprintf(f_dump,"<HTML><HEAD>\n");
   fprintf(f_dump,"	<B>%s</B>\n",FicheiroInput);
   fprintf(f_dump,"</HEAD><BODY>\n");
}

/**
 * Footer of the dump of the symbol table.
 */
static void DumpFooter(void)
{
   fprintf(f_dump,"</BODY></HTML>\n");
}

/**
 * Index of the dump information types
 */
static void DumpIndex(void)
{
   fprintf(f_dump,"	<H2>Index</H2>\n");
   fprintf(f_dump,"		<A HREF=#Functions>Functions declared</A><BR>\n");
   fprintf(f_dump,"		<A HREF=#FunctionsCall>Functions called</A><BR>\n");
   fprintf(f_dump,"		<A HREF=#Cursor>Cursors used</A><BR>\n");
   fprintf(f_dump,"		<A HREF=#Table>Tables used</A><BR>\n");
   fprintf(f_dump,"		<A HREF=#Modular>Modular variables</A><BR>\n");
   fprintf(f_dump,"	<HR>\n");
}

/**
 * Dump Information about functions declared, is arguments and count(s)
 */
static void DumpFunctionsDeclaration(void)
{
  register int i,j;
  VAR_USAGE *Next;

	fprintf(f_dump,	"	<A NAME=Functions>\n");
	fprintf(f_dump,	"	<H2>Function List</H2>\n");

	fprintf(f_dump,	"	<TABLE BORDER>\n");
	fprintf(f_dump,	"		<TR><TH>Name</TH><TH>Line</TH><TH># Instructions</TH>\n");
	fprintf(f_dump,	"		<TH># Calls</TH><TH># SQL</TH><TH># Locals</TH></TR>\n");
	/* ??? Faltam cursorecount(s) s e utilizacao de globais */
	for (i=0 ; i < P4glCb.idx_funcoes ; i++)
	{
		fprintf(f_dump,"		<TR><TD>\n");
		fprintf(f_dump,"			<A HREF=#Func%s>%s</A>\n", P4glCb.functions[i].name,
		                                        P4glCb.functions[i].name);
		fprintf(f_dump,"		</TD><TD>%d</TD><TD>%d</TD>\n",
		               P4glCb.functions[i].linha,
		               P4glCb.functions[i].NInstrucoes);
		fprintf(f_dump,"		<TD>%d</TD><TD>%d</TD><TD>%d</TD></TR>\n",
		               P4glCb.functions[i].idx_function_call,
		               P4glCb.functions[i].idx_sql,
		               P4glCb.functions[i].idx_var);
	}
	fprintf(f_dump,"	</TABLE><HR>\n");
}

/**
 * Show functions detail
 */
static void DumpFunctions(void)
{
   register int i,j;
   VAR_USAGE *Next;

   fprintf(f_dump,"	<H2>Functions Detail</H2>\n");
	for (i=0 ; i < P4glCb.idx_funcoes ; i++)
	{
		fprintf(f_dump,"	<HR>\n");
		fprintf(f_dump,"	<A NAME=Func%s>\n", P4glCb.functions[i].name);
		fprintf(f_dump,"		Name : <B>%s</B><BR>Line : %d<BR>Instructions : %d\n",
											 P4glCb.functions[i].name,
		                            P4glCb.functions[i].linha,
		                            P4glCb.functions[i].NInstrucoes);

      fprintf(f_dump,"		<H3>Parameters</H3>\n");
		/* Parametros / Argumentos */
		for (j = 0 ; j< IDX_ARG(i) ; j++)
		{
			printf("			PARAMETER : %s\n", FUNCAO(i).parametros[j]);
		}

		/* Funcoes executadas */
      fprintf(f_dump,"		<H3>CALL(S)</H3>\n");
		fprintf(f_dump,"		<TABLE BORDER>\n");
		fprintf(f_dump,"			<TR><TH>Name</TH><TH>Line</TH></TR>\n");
		for (j = 0 ; j< IDX_FC(i) ; j++)
		{
			printf("			<TR><TD>%s</TD><TD>%d</TD></TR>\n",
				FUNC_CALL(i,j).name,
				FUNC_CALL(i,j).linha);
		}
		fprintf(f_dump,"		</TABLE>\n");

		/* Utilizacao de globais */
      fprintf(f_dump,"	<H3>Globals Usage</H3>\n");
	   Next = FUNCAO(i).var_usage;
		printf("		<TABLE BORDER><TR><TH>Name</TH><TH>Line</TH><TH>Type</TH></TR>\n");
      while (Next != (VAR_USAGE *)0)
		{
			printf("		<TR>\n");
			if ( Next->utilizacao == READ_VAR )
	         printf("		<TD>%s</TD><TD>%d</TD><TD>Usage</TD>\n",
						 Next->nome,Next->linha);
		  else
	         printf("		<TD>%s</TD><TD>%d</TD><TD>Assignment</TD>\n",
						 Next->nome,Next->linha);
		   Next = Next->next;
			printf("		</TR>\n");
		}
		printf("		</TABLE>\n");
	}
	fprintf(f_dump,"	<HR>\n");
}

/**
 *  Dump in HTML the query(s) used in the source
 */
static void DumpSql(void)
{
  register int i,j,k;

	fprintf(f_dump,"	<H2><A NAME=Sql>SQL</A></H2>\n");
	fprintf(f_dump,"		<table border><TR><TH>Funcyion</TH><TH>Operation</TH>\n",
			  "<TH>Table name</TH></TR>"); //<<<<<<<<<<<<<<<<<<<<<<< !!!
	for (k=0 ; k < P4glCb.idx_funcoes ; k++)
	{
	   for (i=0 ; i < FUNCAO(k).idx_sql ; i++)
	   {
		   for (j = 0 ; j  < IDX_TAB(k,i) ; j++)
		   {
		      fprintf(f_dump,"			<TR>\n");
			   fprintf(f_dump,"			<TD><A HREF=#Func%s>%s</A></TD>\n",
					FUNCAO(k).name,
					FUNCAO(k).name);
			   switch (SQL_STMT(k,i).operacao)
			   {
				   case SQL_SELECT:
					   fprintf(f_dump,"				<TD>SELECT</TD>\n");
					   break;
				   case SQL_INSERT:
					   fprintf(f_dump,"				<TD>INSERT</TD>\n");
					   break;
				   case SQL_UPDATE:
					   fprintf(f_dump,"				<TD>UPDATE</TD>\n");
					   break;
				   case SQL_DELETE:
					   fprintf(f_dump,"				<TD>DELETE</TD>\n");
					   break;
			      }
			   printf("			<TD>%s</TD>\n",SQL_STMT(k,i).tabelas[j]);
		      fprintf(f_dump,"		</TR>\n");
		   }
	   }
	 }
	 fprintf(f_dump,"	</table>\n");
}

/**
 * Modular variables of the module
 */
static void DumpModuleVariable(void)
{
  register short i;

	printf("	<TABLE BORDER>\n");
	printf("		<TR><TH>Module Variable Name</TH><TH>Declaration line</TH></TR>\n");
	for ( i = 0 ; i < P4glCb.idx_var_mod ; i++)
		printf("			<TR><TD>%s</TD><TD>%d</TD></TR>\n",
				 P4glCb.variaveis_mod[i].nome,
		       P4glCb.variaveis_mod[i].linha);
	printf("		</TR>\n");
	printf("	</TABLE>\n");
}

/**
 * Entry point to abstract tree dump.
 */
void DumpSymtab(void)
{

   f_dump = stdout;
   if ( htmlDump )
	{
		DumpHeader();
			DumpIndex();
			/*DumpGlobals();*/
			DumpFunctionsDeclaration();
			DumpFunctions();
			DumpSql();
			DumpModuleVariable();
		DumpFooter();

	}

}

/* ============================== EOF ============================= */

