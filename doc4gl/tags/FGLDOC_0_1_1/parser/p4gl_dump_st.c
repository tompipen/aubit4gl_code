/**
 * @file 
 * Dump all the information in the abstract tree to the standard output.
 * Symbol table dump in html format. It have crossed links between
 * information.
 * It just works if p4gl was executed with -d option.
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
   fprintf(f_dump,"<HTML><HEAD>");
   fprintf(f_dump,"<B>%s</B>",FicheiroInput);
   fprintf(f_dump,"</HEAD><BODY>");
}

/**
 * Footer of the dump of the symbol table.
 */
static void DumpFooter(void)
{
   fprintf(f_dump,"</BODY></HTML>");
}

/**
 * Index of the dump information types
 */
static void DumpIndex(void)
{
   fprintf(f_dump,"<H2>Index</H2>");
   fprintf(f_dump,"<A HREF=#Functions>Functions declared</A><BR>");
   fprintf(f_dump,"<A HREF=#FunctionsCall>Functions called</A><BR>");
   fprintf(f_dump,"<A HREF=#Cursor>Cursors used</A><BR>");
   fprintf(f_dump,"<A HREF=#Table>Tables used</A><BR>");
   fprintf(f_dump,"<A HREF=#Modular>Modular variables</A><BR>");
   fprintf(f_dump,"<HR>");
}

/**
 * Dump Information about functions declared, is arguments and count(s)
 */
static void DumpFunctionsDeclaration(void)
{
  register int i,j;
  VAR_USAGE *Next;

	fprintf(f_dump,"<A NAME=Functions>");
  fprintf(f_dump,"<H2>Function List</H2>");
	fprintf(f_dump,"<TABLE BORDER>");
	fprintf(f_dump,"<TR><TH>Name</TH><TH>Line</TH><TH># Instructions</TH>");
	fprintf(f_dump,"<TH># Calls</TH><TH># SQL</TH><TH># Locals</TH></TR>");
	/* ??? Faltam cursorecount(s) s e utilizacao de globais */
	for (i=0 ; i < P4glCb.idx_funcoes ; i++)
	{
		fprintf(f_dump,"<TR><TD>");
		fprintf(f_dump,"<A HREF=#Func%s>%s</A>", P4glCb.functions[i].name,
		                                        P4glCb.functions[i].name);
		fprintf(f_dump,"</TD><TD>%d</TD><TD>%d</TD>",
		               P4glCb.functions[i].linha,
		               P4glCb.functions[i].NInstrucoes);
		fprintf(f_dump,"<TD>%d</TD><TD>%d</TD><TD>%d</TD></TR>",
		               P4glCb.functions[i].idx_function_call,
		               P4glCb.functions[i].idx_sql,
		               P4glCb.functions[i].idx_var);
	}
	fprintf(f_dump,"</TABLE><HR>");
}

/**
 * Show functions detail
 */
static void DumpFunctions(void)
{
   register int i,j;
   VAR_USAGE *Next;

   fprintf(f_dump,"<H2>Functions Detail</H2>");
	for (i=0 ; i < P4glCb.idx_funcoes ; i++)
	{
		fprintf(f_dump,"<HR>");
		fprintf(f_dump,"<A NAME=Func%s>", P4glCb.functions[i].name);
		fprintf(f_dump,"Name : <B>%s</B><BR>Line : %d<BR>Instructions : %d\n", 
											 P4glCb.functions[i].name,
		                            P4glCb.functions[i].linha,
		                            P4glCb.functions[i].NInstrucoes);

      fprintf(f_dump,"<H3>Parameters</H3>");
		/* Parametros / Argumentos */
		for (j = 0 ; j< IDX_ARG(i) ; j++)
		{
			printf("   PARAMETRO : %s\n", FUNCAO(i).parametros[j]);
		}

		/* Funcoes executadas */
      fprintf(f_dump,"<H3>CALL(S)</H3>");
		fprintf(f_dump,"<TABLE BORDER>");
		fprintf(f_dump,"<TR><TH>Name</TH><TH>Line</TH></TR>");
		for (j = 0 ; j< IDX_FC(i) ; j++)
		{
			printf("<TR><TD>%s</TD><TD>%d</TD></TR>", 
				FUNC_CALL(i,j).name,
				FUNC_CALL(i,j).linha);
		}
		fprintf(f_dump,"</TABLE>");
		
		/* Utilizacao de globais */
      fprintf(f_dump,"<H3>Globals Usage</H3>");
	   Next = FUNCAO(i).var_usage;
		printf("<TABLE BORDER><TR><TH>Name</TH><TH>Line</TH><TH>Type</TH></TR>");
      while (Next != (VAR_USAGE *)0)
		{
			printf("<TR>");
			if ( Next->utilizacao == READ_VAR )
	         printf("<TD>%s</TD><TD>%d</TD><TD>Usage</TD>",
						 Next->nome,Next->linha);
		  else
	         printf("<TD>%s</TD><TD>%d</TD><TD>Assignment</TD>",
						 Next->nome,Next->linha);
		   Next = Next->next;
			printf("</TR>");
		}
		printf("</TABLE>");
	}
	fprintf(f_dump,"<HR>");
}

/**
 *  Dump in HTML the query(s) used in the source
 */
static void DumpSql(void)
{
  register int i,j,k;

	fprintf(f_dump,"<H2><A NAME=Sql>SQL</A></H2>");
	fprintf(f_dump,"<table border><TR><TH>Funcyion</TH><TH>Operation</TH>",
			  "<TH>Table name</TH></TR>");
	for (k=0 ; k < P4glCb.idx_funcoes ; k++)
	{
	   for (i=0 ; i < FUNCAO(k).idx_sql ; i++)
	   {
		   for (j = 0 ; j  < IDX_TAB(k,i) ; j++)
		   {
		      fprintf(f_dump,"<TR>");
			   fprintf(f_dump,"<TD><A HREF=#Func%s>%s</A></TD>",
					FUNCAO(k).name,
					FUNCAO(k).name);
			   switch (SQL_STMT(k,i).operacao)
			   {
				   case SQL_SELECT:
					   fprintf(f_dump,"<TD>SELECT</TD>");
					   break;
				   case SQL_INSERT:
					   fprintf(f_dump,"<TD>INSERT</TD>");
					   break;
				   case SQL_UPDATE:
					   fprintf(f_dump,"<TD>UPDATE</TD>");
					   break;
				   case SQL_DELETE:
					   fprintf(f_dump,"<TD>DELETE</TD>");
					   break;
			      }
			   printf("<TD>%s</TD>",SQL_STMT(k,i).tabelas[j]);
		      fprintf(f_dump,"</TR>");
		   }
	   }
	 }
	 fprintf(f_dump,"</table>");
}

/**
 * Modular variables of the module
 */
static void DumpModuleVariable(void)
{
  register short i;

	printf("<TABLE BORDER>");
	printf("<TR><TH>Name</TH><TH>Declaration line</TH></TR>");
	for ( i = 0 ; i < P4glCb.idx_var_mod ; i++)
		printf("<TR><TD>%s</TD><TD>%d</TD></TR>",
				 P4glCb.variaveis_mod[i].nome,
		       P4glCb.variaveis_mod[i].linha);
	printf("</TR>");
	printf("</TABLE>");
}

/**
 * Entry point to abstract tree dump.
 */
void DumpSymtab(void)
{

   f_dump = stdout;
   if ( dbug )
	{
		DumpHeader();
		DumpIndex();
		/*DumpGlobals();*/
		DumpFunctionsDeclaration();
		DumpFunctions();
		DumpSql();
		DumpFooter();
		DumpModuleVariable();
	}

}
