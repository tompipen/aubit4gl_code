/**
 * @file 
 * 4gl language documentation parser.
 *
 * Main 
 *
 * @author : Sergio Ferreira
 */

extern int exit_stat;

//static char *rcsid = "$Id: m_p4gl.c,v 1.4 2003-12-10 11:48:07 afalout Exp $";

/**
 * The main entry function.
 *
 * @param argc The argument count
 * @param argv The argument values
 */
main(int argc,char *argv[])
{
	initP4glPhaseOne();
	initArguments(argc,argv);
	initP4glPhaseTwo();
	P4glVerbose("4gl Parsing\n");
	if( parseFgl())    /* Parse a source .4gl - Nao tem recup. de erros */
	{
	  OrderSymtab();       /* Orderna os arrays da tabela or nome */
	  DumpSymtab();
		executeActions();
	} else {
		printf("P4gl Parsing failed\n");
        if ( ! exit_stat) {
            exit_stat = 1;
        }
    }
	CleanP4gl();
	exit(exit_stat);
}

