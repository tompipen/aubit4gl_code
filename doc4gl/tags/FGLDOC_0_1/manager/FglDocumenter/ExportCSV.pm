#!/usr/bin/perl -w

#  =========================================================================
#
#  Implementa os métodos / funções que efectuam importações e exportações
#  dos dados de / para CSV 
#
#  Autor : Sérgio Ferreira
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
#  Afecta a variável com o nome do ficheiro para onde será efectuada a
#  exportação
#  =========================================================================
sub setFileName
{
  my $obj = shift;
  $obj->{exportFileName} = shift;
}

#  ===========================================================================
#  Afecta a referência para o repositório
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
#  Afecta a referência para o objecto de gestão de log(s)
#  ===========================================================================
sub setLog
{
  my $obj = shift;
	$obj->{log} = shift;
}

#  ===========================================================================
#  Afecta o pointer ( referencia ) para a rotina que mostra o progresso
#  ou evolução do processo
#  ===========================================================================
sub addProgressListener
{
  my $obj = shift;
  $obj->{progressListener} = shift;
}



#  =========================================================================
#  Executa a exportação para o ficheiro
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
#  Desnormaliza a informação do repositório e export para o ficheiro já 
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
#  Desnormaliza a informação para a tabela que reflecte o flat file a gerar
#  =========================================================================
sub unNormalize
{
	
  my $obj = shift;
  $obj->{progressListener}("Desnormalização") if $obj->{progressListener};

	# ??? Isto devia ser uma tabela temporária
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
