#!/usr/bin/perl

#  =========================================================================
#  Objecto que efectua testes sobre o ambiente por forma a informar o mais
#  possivel sobre o funcionamento.
#
#  @todo Meter a funcionar com testes unitários de perl
#
#  $Id: Test.pm,v 1.1.1.1 2001-12-26 07:32:37 afalout Exp $
#  =========================================================================

package FglDocumenter::Test;

use DBI;
use Test::Unit;
use FglDocumenter::ImportFgl;
use FglDocumenter::FglDocLocation;

use constant DEBUG => 0;

sub new
{
 $test = {
	  "log"                => 0,
	  "err"                => 0,
	  "driver"             => "Informix",
	  "repository"         => 0,
	  "dbh"                => 0,
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
#  Testar driver DBI::Informix
#  =========================================================================
sub test_driver
{
	print "Test Driver : $driver\n" if DEBUG;
	@drivers = DBI->available_drivers;
	my $driver;
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
	$dbConnection = $objGlob->{repository};
	assert($dbConnection->connect() == 1,"Cant connect to repository");
}

#  =========================================================================
#  Testing 4gl import
#  =========================================================================
sub test_fglImport
{
  print "Test Fgl import\n" if DEBUG;
	$dbConnection = $objGlob->{repository};
	assert($dbConnection->connect() == 1,"Cant connect to repository");
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
	assert($importFglObject->parseSources() == 1,"Cant parse 4gl sources");
	# Ver se dados do modulo foram carregados na BD
}

#  =========================================================================
#  Testing CSV import
#  =========================================================================

#  =========================================================================
#  Testing 4gl export
#  =========================================================================

#  =========================================================================
#  Testing CSV export
#  =========================================================================

#  =========================================================================
#  Testing Html export
#  =========================================================================

#  =========================================================================
#
#  =========================================================================
sub set_up
{
  print "Set Up\n" if DEBUG;
}

#  =========================================================================
#
#  =========================================================================
sub tear_down
{
  print "Tear Down\n" if DEBUG;
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
  create_suite("FglDocumenter::Test");
	run_suite("FglDocumenter::Test");
}

my $objGlob;

return 1;
