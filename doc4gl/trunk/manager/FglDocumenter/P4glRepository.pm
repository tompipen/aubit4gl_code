#!/usr/bin/perl

#  =========================================================================
#
#  Métodos diversos para interação com um repositório de formato p4gl
#
#  Autor : Sérgio Ferreira
#
#  @todo Correcto tratamento de erros e mensagens
#
#  =========================================================================

package FglDocumenter::P4glRepository;

use DBI;

#  =========================================================================
#  Afecta uma variável local com uma referência para o objecto de erros
#  =========================================================================
sub setError
{
  $error = shift;
}

#  =========================================================================
#  Obtem a lista de packages existentes na BD (repositório)
#    @return Lista de packages
#  =========================================================================
sub selectPackages
{
  @packageList = ();
	if ( ($FglDocumenter::Options::p4glRepository)->connect() > 0 )
	{
	  $error->setErrorFlag(1,"Error connecting to the database");
	  return @packageList;
	}
	my $dbh = ($FglDocumenter::Options::p4glRepository)->getConnection();

  my $sth = $dbh->prepare("select id_package from p4gl_package")
	  || die "Can´t prepare insert into p4gl_fun_process: $! ";
  $sth->execute() || die "Can't insert into p4gl_fun_process: $!";
	while (@row = $sth->fetchrow_array())
  {
		$row[0] =~ s/ *$//;
		push(@packageList,$row[0]);
  }
  undef $sth;
	return @packageList;
}

#  =========================================================================
#  Obtem a lista de modulos no repositório para o 
#  package corrente
#  =========================================================================
sub selectModules
{
  @moduleList = ();
	($FglDocumenter::Options::p4glRepository)->connect();
	my $dbh = ($FglDocumenter::Options::p4glRepository)->getConnection();

  my $sth = $dbh->prepare("select module_name from p4gl_module")
	  || die "Can´t prepare insert into p4gl_fun_process: $! ";
  $sth->execute() || die "Can't insert into p4gl_fun_process: $!";
	while (@row = $sth->fetchrow_array())
  {
		$row[0] =~ s/ *$//;
		push(@moduleList,$row[0]);
  }
  undef $sth;
	return @moduleList;
}

#  =========================================================================
#  Obtem a lista de funções no repositório para o  package corrente e 
#  módulo(s) corrente(s)
#  =========================================================================
sub selectFunctions
{
  @functionList = ();
	($FglDocumenter::Options::p4glRepository)->connect();
	my $dbh = ($FglDocumenter::Options::p4glRepository)->getConnection();

  my $sth = $dbh->prepare("select function_name from p4gl_function")
	  || die "Can´t prepare insert into p4gl_fun_process: $! ";
  $sth->execute() || die "Can't insert into p4gl_fun_process: $!";
	while (@row = $sth->fetchrow_array())
  {
		$row[0] =~ s/ *$//;
		push(@functionList,$row[0]);
  }
  undef $sth;
	return @functionList;
}

return true;
