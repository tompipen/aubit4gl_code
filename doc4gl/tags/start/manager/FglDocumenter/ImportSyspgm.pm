#!/usr/bin/perl -w

# ============================================================================
# 
# Converte os dados da base de dados de definição de programas do 4gl 
# (syspg4gl) no formato do repositório p4gl
# 
# Funciona de forma integrada com fgldoc (interactivo com GUI em Tk)
# Fica depois a faltar a hipótese de usar por linha de comando
# 
# Está a ser desenvolvido no âmbito do projecto de outsourcing para a TMN
# 
# ============================================================================

use DBI;        

use IO::File;
use Getopt::Long;
use File::Find;
use File::stat;
use POSIX;
use Shell;       

# ============================================================================
# Initialization of variables
# ============================================================================
sub initVars()
{
  $syspgmDbName = "syspgm4gl";
  $p4glDbName   = "p4gl_repository";
	$silent       = 0;
	$noLog        = 0;
	$logDir       = "/tmp";
	$logFile      = "syspg2p4gl";
}


# ============================================================================
# Inicializações diversas
# ============================================================================
sub init
{
	$log = "";
  $log = $logDir . "/" . $logFile
}


#  ===========================================================================
#  Abre as bases de dados
#  ===========================================================================
sub openDatabases
{
	# ???? Isto ainda não está lá muito correcto por causa dos diferentes env(s)
	# e hosts da(s) bases de dados
  $syspgmDbh = DBI->connect("DBI:Informix:$syspgmDbName");
  $p4glDbh = DBI->connect("DBI:Informix:$p4glDbName");
}

#  ===========================================================================
#  Fecha as bases de dados
#  ===========================================================================
sub closeDatabases
{
  $syspgmDbh->disconnect;
  $p4glDbh->disconnect;
}

#  ===========================================================================
#  Selecciona os programas existentes em syspgm4gl:source4gl e insere-os em
#  p4gl_program
#  ===========================================================================
sub insertPrograms
{
  $selSth = $syspgmDbh->prepare("SELECT distinct progname FROM source4gl");
  $selSth->execute();

  #$insSth = $p4glDbh->prepare(qq|
	  #insert into p4gl_program (program_name) values (?)
	#|);

  my(@row);
  while (@row = $selSth->fetchrow_array())
  {
		printf("Programa %s\n",$row[0]);
		#insSth->bind_param(1,$row[0]);
		#insSth->execute();
		insertFglModules();
  }
  undef $selSth;
  #undef $insSth;
}

#  ===========================================================================
#  Insere os módulos de 4gl dos quais um programa depende
#  ===========================================================================
sub insertFglModules
{
}

#  ===========================================================================
#  It display(s) documentfgl usage
#  ===========================================================================
sub syspg2p4glUsage()
{ 
   print qq{Usage: syspg3p4gl switches 
      --database=database_name  Specify repository database.
      --no_substitute           Do not substitute documentation comentary
      --base_dir=dir            Application base directory
      --src_dir=dir             4gl source base directory
      --help                    This message
      --no_log                  Do not log modifications
      --log_dir=dir             Directory to write log file(s)
      --clear_log               Clear all files in the log directory
      --create_log              Create log directory if does not exist
      --silent                  Do not show any messages (not working yet)
};
}


#  Main program

	initVars();
  if ( ! GetOptions("database=s" => \$p4glDbName,
		 "log_dir"          => \$logDir,
		 "no_log"           => \$noLog,
		 "help"             => \$HELP,
		 "silent"           => \$silent) )
      { syspg2p4glUsage(); }

	if ( $HELP )                 
	{ 
	  syspg2p4glUsage(); 
		exit;
  }

	init();
	openDatabases();
	insertPrograms();
	closeDatabases();

# End Main

return true;

