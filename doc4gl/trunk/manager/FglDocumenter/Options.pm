#!/usr/bin/perl

#  =========================================================================
#  Contem refer�ncias e(ou) vari�veis relativas a op��es executadas
#  
#   @todo Passar este funcionamento a objecto
#  =========================================================================

package FglDocumenter::Options;

use POSIX;
use XML::Dumper;
use Data::Dumper;

#  =========================================================================
#  Construtora.
#  Inicializa as op��es com valores de default ou apenas instancia��o
#  =========================================================================
sub BEGIN
{
	$home = $ENV{'HOME'} || die "You're homeless!\n";
	$optionsFile = "$home/.fgldocrc";
  #loadOptions();
}

#  =========================================================================
#  Afecta a referencia interna a janela principal da qual as outras 
#  (nomeadamente as modals) devem depender
#  =========================================================================
sub setParentWin
{
  $parentWin = shift;
}

#  =========================================================================
#  Carrega op��es de default
#  =========================================================================
sub loadDefaultOptions
{
  my $host = `hostname`;
  my $user = `whoami`;
	chomp($host);
	chomp($user);
	my $database = $ENV{"DATABASE"};
  if ( ! defined($database) )
	{
	  $database = "p4gl_repository";
	}

	# Parametros para execucao em CUI
	# Tipo de ac��o a executar
	#UI = "GUI";
	#action = "";
	#Andrej: the 2 above stmts cause the following error:
	#Can't modify constant item in scalar assignment at 
	#/usr/lib/perl5/5.6.0/FglDocumenter/Options.pm line 52, near ""GUI";"
    #So I commented them out

	# @todo - Mudar esta mecanica
  $importInformixDir    = $ENV{"INFORMIXDIR"};
  $importInformixServer = $ENV{"INFORMIXSERVER"};
  $importHost           = $host;
  $importDatabase       = $database;
  $importUser           = $user;

  $exportInformixDir    = $ENV{"INFORMIXDIR"};
  $exportInformixServer = $ENV{"INFORMIXSERVER"};
  $exportHost           = $host;
  $exportDatabase       = $database;
  $exportUser           = $user;

	initRepository();

	$csvImportFile  = "4gl_mapping.txt";
	$xmlImportFile  = "4gl_mapping.xml";

	$csvExportFile  = "4gl_mapping.txt";
	$xmlExportFile  = "4gl_mapping.xml";
	$htmlExportDir  = "";
	$ignoreExistDir = 1;

	$clearRepositoryOnImportCSV = 0;
	$normalize = 1;
	$sendLineToLog = 0;

	$clearRepositoryOnImportXML = false;

	# Do form de importa��o de dados de 4gl(s) por parsing
	$packageName        = 1;
	$loadComments       = 1;
	$parseOnly          = 0;
	$loadTableUsage     = 0;
	$loadParameters     = 1;
	$loadStrings        = 0;
	$loadFilesRecursive = 1;
	$loadLocalVariables = 0;
	$importFglLocation  = ".";
	$importFglModules   = ();
	$importFglDirs      = ();

	# Do form para exporta��o de coment�rios para os sources
	$sourceDir          = getcwd();
	$replaceFgldoc      = 1;
	$fglSource          = "";
	$insertEmptyComment = 0;

	$logShowed          = 1;
}

#  =========================================================================
#  Inicializa��o dos respositorios
#  =========================================================================
sub initRepository
{
  $p4glRepository = new FglDocumenter::DatabaseConnection(
		$importInformixDir,
		$importInformixServer,
		$importHost,
		$importDatabase,
		$importUser,
		""
	);

  $syspgmRepository = new FglDocumenter::DatabaseConnection(
		$exportInformixDir,
		$exportInformixServer,
		$exportHost,
		$exportDatabase,
		$exportUser,
		""
	);
}

#  =========================================================================
#  Carrega as op�oes gravadas e se n�o existirem carrega o default
#    @todo Garantir que o ficheiro de op��es tem permiss�es de leitura
#  =========================================================================
sub loadOptions
{
  if ( -f $optionsFile )
	{
	  openOptionsFile();
	  initRepository();
	}
	else
	{
	  loadDefaultOptions();
	}
}


#  =========================================================================
#  Afecta a vari�vel deste m�dulo que contem a refer�ncia para o reposit�rio
#  de p4gl
#  =========================================================================
sub setP4glRepository
{
  $p4glRepository = shift;
}

sub getP4glrepository
{
  return $p4glRepository;
}


#  =========================================================================
#  Afecta a vari�vel deste m�dulo que contem a refer�ncia para o reposit�rio
#  do syspgm4gl (gestor de compila��es da Informix)
#  =========================================================================
sub setSyspgmRepository
{
  $syspgmRepository = shift;
}

#  =========================================================================
#  Devolve refer�ncia ao objecto que identifica a conex�o ao reposit�rio
#  onde est� o syspgm
#  =========================================================================
sub getSyspgmRepository
{
  return $syspgmRepository;
}

#  =========================================================================
#  Selecciona o ficheiro onde os par�metros ser�o guardados e deixa-o no 
#  ficheiro chamado $optionsFile
#  =========================================================================
sub openFileToWrite
{
	open(OPTIONS,"> $optionsFile");
}

#  =========================================================================
#  Selecciona e abre o ficheiro para leitura das op��es
#  =========================================================================
sub openFileToRead
{
	open(OPTIONS,"< $optionsFile");
}

#  =========================================================================
#  Abre um file chooser (se UI = GUI) para que o utilizador escolha qual o 
#  ficheiro onde quer gravar op�oes
#  =========================================================================
sub save
{
  my $types = [
    ['Text',             '.txt', 'TEXT'],
    ['Fgldoc',           '.fgldocrc', 'TEXT'],
    ['All Files',        '*',             ],
  ];
	my $initDir = getcwd();
  $tmpOptionsFile = $parentWin->getSaveFile(
		-initialdir => $initDir,
		-initialfile => $optionsFile,
	  -title => "Seleccionar ficheiro de parametros",
	  -filetypes => $types
  );
	if ( !defined($tmpOptionsFile) )
	{
	  return;
	}
	$optionsFile = $tmpOptionsFile;
	saveOptions();
}

#  =========================================================================
#  Salva o objecto num ficheiro de XML
#  @todo Terminar a grava��o de todas as op��es
#  =========================================================================
sub saveOptions
{
	openFileToWrite();
	$dataToDump = Data::Dumper->Dump(
	  [$csvImportFile,
		 $xmlImportFile,
	   $UI,
	   $action,
	   $importInformixDir,
		 $importInformixServer,
		 $importHost,
		 $importDatabase,
		 $importUser,
	   $exportInformixDir,
		 $exportInformixServer,
		 $exportHost,
		 $exportDatabase,
		 $exportUser,
	   $csvExportFile,
	   $xmlExportFile,
	   $htmlExportDir,
	   $ignoreExistDir,
	   $clearRepositoryOnImportCSV,
	   $normalize,
	   $clearRepositoryOnImportXML,
	   $packageName,
	   $loadComments,
	   $parseOnly,
	   $loadTableUsage,
	   $loadParameters,
	   $loadStrings,
	   $loadLocalVariables,
	   $sourceDir,
	   $replaceFgldoc,
	   $fglSource,
	   $insertEmptyComment,
	   $logShowed,
	   $importFglLocation,
	   $importFglModules,
	   $importFglDirs,
	   $loadFilesRecursive
    ],
	  [
		 "csvImportFile",
		 "xmlImportFile",
	   "UI",
	   "action",
	   "importInformixDir",
		 "importInformixServer",
		 "importHost",
		 "importDatabase",
		 "importUser",
	   "exportInformixDir",
		 "exportInformixServer",
		 "exportHost",
		 "exportDatabase",
		 "exportUser" ,
	   "csvExportFile",
	   "xmlExportFile",
	   "htmlExportDir",
	   "ignoreExistDir",
	   "clearRepositoryOnImportCSV",
	   "normalize",
	   "clearRepositoryOnImportXML",
	   "packageName",
	   "loadComments",
	   "parseOnly",
	   "loadTableUsage",
	   "loadParameters",
	   "loadStrings",
	   "loadLocalVariables",
	   "sourceDir",
	   "replaceFgldoc",
	   "fglSource",
	   "insertEmptyComment",
	   "logShowed",
	   "importFglLocation",
	   "importFglModules",
	   "importFglDirs",
	   "loadFilesRecursive"
    ]
  );
	print OPTIONS "$dataToDump";
	close(OPTIONS);
}

#  =========================================================================
#  Abre um file chooser (se UI = GUI) para que o utilizador escolha qual o 
#  ficheiro que pretende carregar
#  =========================================================================
sub open
{
  my $types = [
    ['Text',             '.txt', 'TEXT'],
    ['Fgldoc',           '.fgldocrc', 'TEXT'],
    ['All Files',        '*',             ],
  ];
	my $initDir = getcwd();
  $tmpOptionsFile = $parentWin->getOpenFile(
		-initialdir => $initDir,
		-initialfile => $optionsFile,
	  -title => "Seleccionar ficheiro de parametros",
	  -filetypes => $types
  );
	if ( !defined($tmpOptionsFile) )
	{
	  return;
	}
	$optionsFile = $tmpOptionsFile;
	openOptionsFile();
}

#  =========================================================================
#  Abre o ficheiro de op��es e mete os valores nas vari�veis
#    @todo Terminar a leitura de todas as op��es exaustivamente
#  =========================================================================
sub openOptionsFile
{
	openFileToRead();
	my $line = "";
	my $str = "";
	while ( $line = <OPTIONS> )
	{
	   $str .= $line;
	}
	eval $str;
	close(OPTIONS);
}

return true;
