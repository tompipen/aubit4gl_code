#!/usr/bin/perl

#  =========================================================================
#  Contem referências e(ou) variáveis relativas a opções executadas
#  
#   @todo Passar este funcionamento a objecto
#  =========================================================================

package FglDocumenter::Options;

use POSIX;
use XML::Dumper;
use Data::Dumper;

#  =========================================================================
#  Construtora.
#  Inicializa as opções com valores de default ou apenas instanciação
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
#  Carrega opções de default
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
	# Tipo de acção a executar
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

	# Do form de importação de dados de 4gl(s) por parsing
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

	# Do form para exportação de comentários para os sources
	$sourceDir          = getcwd();
	$replaceFgldoc      = 1;
	$fglSource          = "";
	$insertEmptyComment = 0;

	$logShowed          = 1;
}

#  =========================================================================
#  Inicialização dos respositorios
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
#  Carrega as opçoes gravadas e se não existirem carrega o default
#    @todo Garantir que o ficheiro de opções tem permissões de leitura
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
#  Afecta a variável deste módulo que contem a referência para o repositório
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
#  Afecta a variável deste módulo que contem a referência para o repositório
#  do syspgm4gl (gestor de compilações da Informix)
#  =========================================================================
sub setSyspgmRepository
{
  $syspgmRepository = shift;
}

#  =========================================================================
#  Devolve referência ao objecto que identifica a conexão ao repositório
#  onde está o syspgm
#  =========================================================================
sub getSyspgmRepository
{
  return $syspgmRepository;
}

#  =========================================================================
#  Selecciona o ficheiro onde os parâmetros serão guardados e deixa-o no 
#  ficheiro chamado $optionsFile
#  =========================================================================
sub openFileToWrite
{
	open(OPTIONS,"> $optionsFile");
}

#  =========================================================================
#  Selecciona e abre o ficheiro para leitura das opções
#  =========================================================================
sub openFileToRead
{
	open(OPTIONS,"< $optionsFile");
}

#  =========================================================================
#  Abre um file chooser (se UI = GUI) para que o utilizador escolha qual o 
#  ficheiro onde quer gravar opçoes
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
#  @todo Terminar a gravação de todas as opções
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
#  Abre o ficheiro de opções e mete os valores nas variáveis
#    @todo Terminar a leitura de todas as opções exaustivamente
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
