#!/usr/bin/perl -w

#  =========================================================================
#  Objecto que efectua testes sobre o ambiente por forma a informar o mais
#  possivel sobre o funcionamento.
#
#  @todo - Testar criação e remoção de repositório
#  @todo - Testar deprecated de funções
#  @todo - Testar comentários de módulos
#  @todo - Passar a usar testes unitários OO do perl
#  @todo - Terminar a localização de mensagens de testes
#
#  $Id: Test.pm,v 1.2 2003-01-06 20:08:43 saferreira Exp $
#  =========================================================================

#use Carp;
use strict;
package FglDocumenter::Test;

use DBI;
use Test::Unit;
#use Test::Unit::TestCase;
#use Test::Unit::TestRunner;
use FglDocumenter::ImportFgl;
use FglDocumenter::FglDocLocation;

use constant DEBUG => 0;
my $objGlob;

sub new
{
 my $test = {
	  "log"                => 0,
	  "err"                => 0,
	  "driver"             => "Informix",
	  "repository"         => 0,
	  "repositoryUtil"     => 0,
	  "dbh"                => 0,
	  "lh"                 => 0,
	};
	bless $test, "FglDocumenter::Test";
	return $test;
}

#  =========================================================================
#  Afecta a conexão ao objecto
#  =========================================================================
sub setRepository
{
  my $obj = shift;
	my $repository = shift;
	$obj->{repository} = $repository;
	$obj->{dbh} = $repository->getConnection();
}

#  =========================================================================
#  Afecta com o objecto que contem funçoes utilitarias para gestao do 
#  repositorio.
#  =========================================================================
sub setRepositoryUtil
{
  my $obj = shift;
	my $repositoryUtil = shift;
	$obj->{repositoryUtil} = $repositoryUtil;
}

#  =========================================================================
#  Afecta com o objecto de log
#  =========================================================================
sub setLog
{
  my $obj = shift;
	$obj->{log} = shift;
}

#  =========================================================================
#  Afecta com o objecto de erro
#  =========================================================================
sub setError
{
  my $obj = shift;
	$obj->{err} = shift;
}

#  =========================================================================
#  Afecta com o objecto handler de localização, para se poder enviar 
#  mensagens em vários idiomas
#  =========================================================================
sub setLanguageHandler
{
  my $obj = shift;
	$obj->{lh} = shift;
}

#  =========================================================================
#  Extensão aos testes unitários, por forma a permitir uma contagem imediata
#  de registos sobre uma tabela.
#    @param tableName
#    @param count Numero de registos que deve existir na tabela
#    @param where Clausula de where para contagem
#    @param Mensagem para quando o registo não confere
#  =========================================================================
sub assertCountTable
{
	my $obj                 = shift;
	my $tableName           = shift;
	my $recordCountExpected = shift;
	my $whereStr            = shift;
	my $mesg                = shift;

	my $strSel = "";
  if ( $whereStr eq "" )
	{
	  $strSel = "SELECT count(*) FROM $tableName"
	}
	else
	{
	  $strSel = "SELECT count(*) FROM $tableName where $whereStr"
	}
	#print "Str : $strSel\n";
  my $sthCount = $obj->{dbh}->prepare($strSel);
	# @todo Retirar este die
  $sthCount->execute() || die "Can't count from $strSel : $!";
  my(@row);
	my $recordCountFound;
  while (@row = $sthCount->fetchrow_array())
  {
		$recordCountFound = $row[0];
  }
  undef $sthCount;
	assert($recordCountExpected == $recordCountFound,$mesg);
}

#  =========================================================================
#  Testar driver DBI::Informix
#  =========================================================================
sub test_driver
{
	my @drivers = DBI->available_drivers;
	my $driver;
	print "Test Driver : $driver\n" if DEBUG;
	foreach $driver ( @drivers )
	{
		if ( $driver eq $objGlob->{driver} )
		{
	    assert(1,"Driver $objGlob->{driver} not found");
			return;
		}
	  print "Driver : $driver\n" if DEBUG;
	}
	assert(0,"Database driver $objGlob->{driver} not found");
}

#  =========================================================================
#  Testar conexao ao repositorio
#  Os testes são efectuados com base na configuração definida nas opções
#  =========================================================================
sub test_connection
{
  print "Test Connection\n" if DEBUG;
	my $dbConnection = $objGlob->{repository};
	assert($dbConnection->connect() == 1,"Cant connect to repository");
	$objGlob->{dbh} = $dbConnection->getConnection();
	$dbConnection->disconnect();
}

#  =========================================================================
#  Testing 4gl import
#    @todo Testar parametros
#    @todo Testar returns
#    @todo Testar inserção de processo
#    @todo Testar utilização de tabelas
#    @todo Implementar e testar deprectaded(s)
#  =========================================================================
sub test_fglImport
{
  print "Test Fgl import" if DEBUG;
	my $dbConnection = $objGlob->{repository};
	$objGlob->{repositoryUtil}->clean();
	assert($dbConnection->connect() == 1,"Cant connect to repository");
	$objGlob->{dbh} = $dbConnection->getConnection();
	my $importFglObject = new FglDocumenter::ImportFgl();

	$importFglObject->setRepository($dbConnection);
	$importFglObject->setLog($objGlob->{log});
	$importFglObject->setError($objGlob->{err});
	my @mod;
	push(@mod,"TestSource.4gl");
	my $dir = FglDocumenter::FglDocLocation::getLocation() . "/test";
	my @dir;
	push(@dir,$dir);
	$importFglObject->setFglModules(\@mod);
	$importFglObject->setFglDirectoryList(\@dir);
	assert($importFglObject->parseSources() == 1,
	  $objGlob->{err}->getLastError()
	);
  $objGlob->assertCountTable(
	  "p4gl_module",
		1,
		"module_name='TestSource.4gl'",
		$objGlob->{lh}->maketext(
		  "Fgl IMPORT: Should be one record only in p4gl_module"
	  )
	);
  $objGlob->assertCountTable(
	  "p4gl_function",
		1,
		"function_name='onefunctiontotest'",
		$objGlob->{lh}->maketext(
		"Fgl IMPORT: Should be one function called OneFunctionTest in p4gl_function"
	  )
	);
  $objGlob->assertCountTable(
	  "p4gl_fun_todo",
		1,
		"function_name='onefunctiontotest'",
		$objGlob->{lh}->maketext(
		  "Fgl IMPORT: Should be one todo in p4gl_fun_todo"
	  )
	);
	# @todo : Mensagens localizadas so ficaram ate aqui
	# @todo Testar o resto das tabelas que devem ter dados, nomeadamente
	#   - p4gl_fun_parameter
	#   - p4gl_fun_return
	#   - p4gl_fun_process
	$dbConnection->disconnect();
}

#  =========================================================================
#  Testing CSV import.
#  Tenta carregar para o repositório, um ficheiro com caracter separador que
#  faz parte integrante da distribuição da ferramenta.
#  Após o carregamento efectua contagens nas tabelas do repositório para 
#  validar se os loads foram correctamente efectuados.
#  =========================================================================
sub test_csvImport
{
  print "Test Csv import\n" if DEBUG;
	my $dbConnection = $objGlob->{repository};
	assert($dbConnection->connect() == 1,"Cant connect to repository");
	$objGlob->{dbh} = $dbConnection->getConnection();
	my $importCsvObject = new FglDocumenter::ImportCSV();
	$importCsvObject->setRepository($dbConnection);
	$importCsvObject->setLog($objGlob->{log});
	$importCsvObject->setError($objGlob->{err});
	$importCsvObject->setInsertUndefProcess(1);
	my $sheetFile = FglDocumenter::FglDocLocation::getLocation() . 
	  "/test/TestCsv.txt"
	;
	$importCsvObject->setSheetFile($sheetFile);

	assert($importCsvObject->loadSheet() == 1, 
	  $objGlob->{err}->getLastError()
	);
  $objGlob->assertCountTable(
	  "p4gl_excel",
		2,
		"",
		$objGlob->{lh}->maketext(
		  "CSV IMPORT: Should be two records only in p4gl_excel"
	  )
	);
  $objGlob->assertCountTable(
	  "p4gl_excel",
		2,
		"module_name='CsvImportTest.4gl'",
		$objGlob->{lh}->maketext(
		  "CSV IMPORT: Should be two records from CsvImportTest.4gl in p4gl_excel"
	  )
	);
	assert($importCsvObject->normalize() == 1, 
	  $objGlob->{err}->getLastError()
	);
  $objGlob->assertCountTable(
	  "p4gl_module",
		1,
		"module_name='CsvImportTest.4gl'",
		"CSV IMPORT: Should be one module only in p4gl_module"
	);
  $objGlob->assertCountTable(
	  "p4gl_function",
		2,
		"module_name='CsvImportTest.4gl'",
		"CSV IMPORT: Should be two functions only in p4gl_function"
	);
  $objGlob->assertCountTable(
	  "p4gl_fun_process",
		2,
		"module_name='CsvImportTest.4gl' and id_process='PROC_ICSV'",
		$objGlob->{lh}->maketext(
		  "CSV IMPORT: Should be two functions in p4gl_fun_process"
	  )
	);
	$dbConnection->disconnect();
}

#  =========================================================================
#  Generate the 4gl where the comments are to be exported
#  =========================================================================
sub genTestExportFgl()
{
  unless ( open(TEST_EXPFGL, "> /tmp/TestExportFgl.4gl") )
	{
	  printf "Cant open $/tmp/TestExportFgl : $!";
	}
  printf TEST_EXPFGL qq|

#
# File generated by fgldoc --test for testing comment export to 4gl source
#

function EFglFuncA()
  display "Function A for exporting comments to Fgl"
end function

{**
 * This is comments that should be replaced by export
 *}
function EFglFuncB()
  display "Function B for exporting comments to Fgl"
end function

	|;
  close(TEST_EXPFGL);
}

#  =========================================================================
#  Insere dados no repositório que deverão ser depois exportados 
#  correctamente para o 4gl
#    @todo : Inserir mais funçao com deprecated
#    @todo : Inserir processos
#    @todo : Inserir parametros
#    @todo : Inserir retornos
#    @todo : Inserir todos
#  =========================================================================
sub genTestExportData
{
	$objGlob->{repositoryUtil}->insertPackage(
	  "exportFglTest","Test of comments export to 4gl"
	);
	$objGlob->{repositoryUtil}->insertModule(
	  "exportFglTest","TestExportFgl.4gl"
	);
	$objGlob->{repositoryUtil}->insertFunction(
	  "exportFglTest","TestExportFgl.4gl",
    "efglfunca","F","N","Test function comment for FuncA"
	);
	$objGlob->{repositoryUtil}->insertProcess(
	  "PROCESS","This is a process",
    "","This are comments for process"
	);
	$objGlob->{repositoryUtil}->insertFunctionProcess(
	  "PROCESS","exportFglTest",
    "TestExportFgl.4gl","efglfunca"
	);
}

#  =========================================================================
#  Testing 4gl export
#    @todo : Teste sem replace do fgldoc
#    @todo : Apagar o lixo que se faz (ficheiro gerado e backups)
#    @todo : Testar processos
#    @todo : Testar parametros
#    @todo : Testar retornos
#    @todo : Testar todos
#  =========================================================================
sub test_4glExport
{
  print "Test 4gl export\n" if DEBUG;
	my $dbConnection = $objGlob->{repository};
	assert($dbConnection->connect() == 1,"Cant connect to repository");
	$objGlob->{dbh} = $dbConnection->getConnection();
	$objGlob->{repositoryUtil}->setDbh($objGlob->{dbh});
	my $exportFglObject = new FglDocumenter::ExportFgl();
	$exportFglObject->setRepository($dbConnection);
	$exportFglObject->setLog($objGlob->{log});
	$exportFglObject->setError($objGlob->{err});
	$exportFglObject->setReplaceFgldoc(1);
	$exportFglObject->setInsertEmptyComment(1);

	genTestExportFgl();
	genTestExportData();
	my @mod = ("TestExportFgl.4gl");
	my @dir = ("/tmp");
	$exportFglObject->setFglModules(\@mod);
	$exportFglObject->setFglDirectoryList(\@dir);
	$exportFglObject->setReplaceFgldoc(1);
	assert(
	  $exportFglObject->insertDocComments(),
	  $objGlob->{err}->getLastError()
	);

	# Fazer grep para ver se o código ficou lá com os dados
	my $TestFile = "/tmp/TestExportFgl.4gl";
	if ( ! `grep FuncA $TestFile` )
	{
	  assert(1==0,
		  $objGlob->{lh}->maketext(
		    "File [_1] does not contain correct values",$TestFile
		  )
	  );
	}

	# Testar processo
	if ( ! `grep "\@process PROCESS" $TestFile` )
	{
	  assert(1==0,
		  $objGlob->{lh}->maketext(
		    "File [_1] does not contain correct values",$TestFile
		  )
	  );
	}

	# @todo : Testar parametros
	# @todo : Testar retornos
	# @todo : Testar todos
	# @todo : Testar deprecated
	$dbConnection->disconnect();
}

#  =========================================================================
#  Testing CSV export
#  =========================================================================
sub test_csvExport
{
  print "Test Csv export\n" if DEBUG;
	my $dbConnection = $objGlob->{repository};
	assert($dbConnection->connect() == 1,"Cant connect to repository");
	$objGlob->{dbh} = $dbConnection->getConnection();
	$objGlob->{repositoryUtil}->setDbh($objGlob->{dbh});
	my $exportCSVObject = new FglDocumenter::ExportCSV();
	$exportCSVObject->setRepository($dbConnection);
	$exportCSVObject->setLog($objGlob->{log});
	$exportCSVObject->setError($objGlob->{err});
	$exportCSVObject->setFileName("/tmp/CsvExportTest.txt");

	genTestExportData();
	assert($exportCSVObject->export2CSV()==1,
		$objGlob->{lh}->maketext("Cant export information to CSV")
	);

	# Fazer grep para ver se o código ficou lá com os dados
	my $testFile = "/tmp/CsvExportTest.txt";
	if ( ! `grep FuncA $testFile` )
	{
	  assert(1==0,
		  $objGlob->{lh}->maketext(
			  "File [_1] File does not contain correct values",$testFile
			)
		);
	}

	# @todo : Fazer grep a processos
	# @todo : Limpar lixo que para aqui está
	$dbConnection->disconnect();
}

#  =========================================================================
#  Testing Html export
#    @todo : Para alem de ver se executa bem tem de se ver se os html(s) 
#            conteem dados minimos
#  =========================================================================
sub test_htmlExport
{
	# @todo - Limpar e Carregar dados no repositorio
  print "Test Html export\n" if DEBUG;
	my $dbConnection = $objGlob->{repository};
	assert($dbConnection->connect() == 1,"Cant connect to repository");
	$objGlob->{dbh} = $dbConnection->getConnection();
	$objGlob->{repositoryUtil}->setDbh($objGlob->{dbh});
	my $exportHtmlObject = new FglDocumenter::ExportHtml();
	$exportHtmlObject->setRepository($dbConnection);
	$exportHtmlObject->setLog($objGlob->{log});
	$exportHtmlObject->setError($objGlob->{err});
	$exportHtmlObject->setDestinationDir("/tmp/TestFgldocExportHtml");
	$exportHtmlObject->setIgnoreExistDir(1);

	genTestExportData();
	assert($exportHtmlObject->export() == 1, 
		$objGlob->{lh}->maketext("Cant generate html documentation")
	);

	# @todo Testar se os ficheiros existem de acordo com os dados
	# Fazer grep para ver se o código ficou lá com os dados
	my $testDir = "/tmp/TestFgldocExportHtml";
	my $testFile = "$testDir/TestExportFgl.4gl.html";
	if ( ! `grep FuncA $testFile` )
	{
    assert(1==0,
		  $objGlob->{lh}->maketext(
			  "File [_1] File does not contain correct values",$testFile
			)
		);
	}
	$dbConnection->disconnect();
}

#  =========================================================================
#  Inicializaçao, nomeadamente criar o repositorio para testes
#  =========================================================================
sub set_up
{
  print "Set Up\n" if DEBUG;
	$objGlob->{repositoryUtil}->createRepositoryFromScrach();
	$objGlob->{repository}->disconnect();
}

#  =========================================================================
#  nomeadamente apagar o repositorio de testes
#  =========================================================================
sub tear_down
{
  print "Tear Down\n" if DEBUG;
	$objGlob->{repository}->disconnect();
	$objGlob->{repositoryUtil}->dropRepository();
}

#  =========================================================================
#  Executing the tests
#  =========================================================================
sub runTests
{
	my $obj = shift;

	if ( $obj->{log} )
	{
	  my $log = $obj->{log};
	  $log->setToStdout(0);
  }

	$objGlob = $obj;
	$obj->{err}->setDisplayError(0);
	$objGlob->{repository}->setDatabase("fgldoc_test");
	#$objGlob->{repositoryUtil}->createRepositoryFromScrach();
	#$objGlob->{repository}->disconnect();

	# Infelizmente está a morrer quando os testes falham não me dando
	# a possibilidade de terminar
	# @todo Terminar implementaçao de testes OO
	#$testObj = new Test::Unit::TestCase;
	#my $testRunner = new Test::Unit::TestRunner();
	#$testRunner->start($obj);

  create_suite("FglDocumenter::Test");
	run_suite("FglDocumenter::Test");
	#$objGlob->{repositoryUtil}->dropRepository();
	print "\nTests terminated\n";
}

return 1;
