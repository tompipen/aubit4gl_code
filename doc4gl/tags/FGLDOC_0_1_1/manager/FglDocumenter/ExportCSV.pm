#!/usr/bin/perl -w

#  =========================================================================
#
#  Implementa os m�todos / fun��es que efectuam importa��es e exporta��es
#  dos dados de / para CSV 
#
#  Autor : S�rgio Ferreira
# 
#  =========================================================================

package FglDocumenter::ExportCSV;

use strict;

#  =========================================================================
#  Constructor
#  =========================================================================
sub new
{
	my $exportCSV = {
    "exportFileName"     => "",
    "err"                => 0,
	  "log"                => 0,
    "progressListener"   => 0,
	  "dbh"                => 0,
	};
	bless $exportCSV, "FglDocumenter::ExportCSV";
	return $exportCSV;
}


#  =========================================================================
#  Afecta a vari�vel com o nome do ficheiro para onde ser� efectuada a
#  exporta��o
#  =========================================================================
sub setFileName
{
  my $obj = shift;
  $obj->{exportFileName} = shift;
}

#  ===========================================================================
#  Afecta a refer�ncia para o reposit�rio
#  ===========================================================================
sub setRepository
{
  my $obj = shift;
	$obj->{repository} = shift;
	$obj->{dbh} = $obj->{repository}->getConnection();
}


#  ===========================================================================
#  Assign the object of error management used
#  ===========================================================================
sub setError
{
  my $obj = shift;
	$obj->{err} = shift;
}

#  ===========================================================================
#  Afecta a refer�ncia para o objecto de gest�o de log(s)
#  ===========================================================================
sub setLog
{
  my $obj = shift;
	$obj->{log} = shift;
}

#  ===========================================================================
#  Afecta o pointer ( referencia ) para a rotina que mostra o progresso
#  ou evolu��o do processo
#  ===========================================================================
sub addProgressListener
{
  my $obj = shift;
  $obj->{progressListener} = shift;
}



#  =========================================================================
#  Executa a exporta��o para o ficheiro
#  =========================================================================
sub export2CSV
{
  my $obj = shift;
  if ( !(defined($obj->{exportFileName}) ) || $obj->{exportFileName} eq "" )
	{
	  printf("Cant export to undefined fileName\n");
		return;
	}
	open(CSVFILE,"> $obj->{exportFileName}");
	$obj->export2CSVFile();
	close(CSVFILE);
}

#  =========================================================================
#  Desnormaliza a informa��o do reposit�rio e export para o ficheiro j� 
#  aberto
#  =========================================================================
sub export2CSVFile
{
  my $obj = shift;
	$obj->unNormalize();
  my $sthExp = $obj->{dbh}->prepare(q%
	  SELECT trim(module_name), trim(id_process), trim(function_name), 
		    trim(parameters), trim(returns), trim(called), trim(comments)
		  FROM p4gl_excel
			ORDER BY 1, 3, 7
	%);
  $sthExp->execute() || die "Can't select from p4gl_excel: $!";
  my(@row);
  while (@row = $sthExp->fetchrow_array())
  {
    print CSVFILE
		  "$row[0]	$row[1]	$row[2]	$row[3]	$row[4]	$row[5]	$row[6]\n"
		;
  }
  undef $sthExp;
}

#  =========================================================================
#  Desnormaliza a informa��o para a tabela que reflecte o flat file a gerar
#  =========================================================================
sub unNormalize
{
	
  my $obj = shift;
  $obj->{progressListener}("Desnormaliza��o") if $obj->{progressListener};

	# ??? Isto devia ser uma tabela tempor�ria
  my $numRecords = $obj->{dbh}->do("delete from p4gl_excel") || 
	  die "Can't delete from p4gl_excel: $!";

	# ??? Os parametros ficam para depois
	my $queryStr = qq|
		insert into p4gl_excel
	  select p4gl_function.module_name, id_process, p4gl_function.function_name, 
		    "", "", "", p4gl_function.comments
		  FROM p4gl_function, outer p4gl_fun_process
			WHERE p4gl_function.id_package = p4gl_fun_process.id_package
			  AND p4gl_function.module_name = p4gl_fun_process.module_name
			  AND p4gl_function.function_name = p4gl_fun_process.function_name
|;
  my $sthIns = $obj->{dbh}->prepare($queryStr) || die "Can't prepare : $!";
  $sthIns->execute() || die "Can't insert into p4gl_excel: $!";
  undef $sthIns;
}

return 1;
