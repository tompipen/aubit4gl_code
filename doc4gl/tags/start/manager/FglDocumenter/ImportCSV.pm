#!/usr/bin/perl -w

# ============================================================================
# 
# Importação de informação sobre programas de 4gl de um ficheiro com separador
# CSV.
#
# Insere a informação num repositório do tipo p4gl.
#
# Todo o acesso ao repositório é efectuado por intermédio de uma conexão 
# definida por um objecto do tipo DatabaseConnection.
#
# Pode, opcionalmente efectuar a conversão dos dados numa tabela desnormalizada
# que tem origem numa folha de cáclulo, carregar os dados na estrutura 
# normalizada. A estrutura não normalizada tem uma estrutura especifica
#
# Os erros são geridos através da execução de métodos do objecto de erro(s)
# entretanto afectado a este módulo
#
# As colunas esperadas na tabela (Ficheiro CSV) são (por ordem sequencial):
#   moduleName
#   idProcess
#   functionName
#   parametro 
#   retorno
#   call 
#   comments
#
# Autor: Sérgio Ferreira
# 
# ============================================================================

package FglDocumenter::ImportCSV;


use DBI;        

use IO::File;
use File::Find;
use File::stat;
use POSIX;
use Shell;       

#  =========================================================================
#  Constructor
#  =========================================================================
sub new
{
				#my ($pkg) = @_;

	my $importCSV = {
	  "substDocComment"     => 0,
	  "haveFunctionComment" => 0,
	  "normalize"           => 0,
	  "sheetFile"           => "",
	  "err"                 => 0,
	  "log"                 => 0,
	  "sendLineToLog"       => 0,
	  "repository"          => 0,
	  "dbh"                 => 0,
    "progressListener"    => 0
	};
	bless $importCSV, "FglDocumenter::ImportCSV";
	return $importCSV;
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
#  Assigns the flag that indicates if we want to show each line loaded to log
#  window / file.
#    @param sendLineToLog : If 1 is to send the line
#  ===========================================================================
sub setSendLineToLog
{
  my $obj = shift;
	$obj->{sendLineToLog} = shift;
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
#  Afecta o conteudo da variável que contem o nome do ficheiro
#  ===========================================================================
sub setSheetFile
{
  my $obj = shift;
  $obj->{sheetFile} = $_[0];
}

#  ===========================================================================
#  Devolve a propriedade que contem o nome do ficheiro
#  ===========================================================================
sub getSheetFile
{
  my $obj = shift;
  return $obj->{sheetFile};
}

#  ===========================================================================
#  Afecta o pointer ( referencia ) para a rotina que afecta o progresso
#  ===========================================================================
sub addProgressListener
{
  my $obj = shift;
  $obj->{progressListener} = shift;
}

#  ===========================================================================
#  Calcula o numero de acções para carregamento do ficheiro CSV
#  ===========================================================================
sub getNumActions
{
  my $obj = shift;
	my $numLines = lineCount($sheetFile);
	my $numActions = $numLines * 2;
	my $numActions++;
	my $numActions++;
	return $numActions;
}

#  ===========================================================================
#  Conta o numero de linhas do ficheiro
#  ===========================================================================
sub lineCount
{
  my $obj = shift;
	my $numLines = 0;
  open(SHEET,"< $obj->{sheetFile}");
	foreach $sheetRow ( <SHEET> )
	{
	  $numLines++;
  }
	close(SHEET);
	return $numLines
}

#  ===========================================================================
#  Carrega os dados existentes na folha de cálculo excel com separador <TAB>
#  e insere na tabela desnormalizada
#  ===========================================================================
sub loadSheet
{
  my $obj = shift;
	if ( $obj->{sheetFile} eq "" )
	{
		$obj->{err}->error(
		  "Carregamento de ficheiro",
		  "Sheet file not defined...not loaded"
    );
	  return 0;
	}

	my $sheetColumns = 7;
	my $line = 1;
  if ( !open(SHEET,"< $obj->{sheetFile}") )
	{
		$obj->{err}->error(
		  "Abertura de ficheiro",
		  "Impossivel abrir ficheiro CSV\n($obj->{sheetFile}):$!"
    );
	  return 0;
	}

  $obj->deleteAllFromTable("p4gl_excel");
	foreach $sheetRow ( <SHEET> )
	{
		my @row = split(/\	/,$sheetRow);
	  $obj->{progressListener}(
		  "Loading File to DB",$row[0]) if $obj->{progressListener};
	  if ( $#row + 1 != $sheetColumns )
		{
			if ( $obj->{log} ) 
			{
		    $obj->{log}->log(
			    "Error : Number of columns $#row+1 != $sheetColumns in line $line", 
        );
		  }
		}
    else
		{
		  if ( ! $obj->insertRowSheet(@row) )
			{
			  return 0;
			}
		}
	  $line++;
	}

	if ( !close(SHEET) )
	{
		$obj->{err}->error(
		  "Encerramento de ficheiro",
		  "Impossivel fechar ficheiro CSV\n($sheetFile):$!"
    );
  }
	return 1;
}

#  ===========================================================================
#  Insere uma linha na tabela relativa á folha de cálculo
#  Faz uma serie de limpezas a linha, nomeadamente trim()
#  ===========================================================================
sub insertRowSheet
{
  my $obj = shift;
  my $moduleName   = $_[0];
	$moduleName =~ s/^ *//g;
	$moduleName =~ s/ *$//g;
	if ( $moduleName eq "" )
	{
    return;
	}
  my $idProcess    = $_[1];
  $idProcess =~ s/^ *//g;
  $idProcess =~ s/ *$//g;
	if ( length($idProcess) > 10 )
	{
		$obj->{err}->error(
		  "Carregar linha de CSV",
		  "ID de processo > 10 : ($idProcess)"
    );
	}
  my $functionName = $_[2];
  $functionName =~ s/^ *//g;
  $functionName =~ s/ *$//g;
  my $comments     = $_[6];
	if ( $comments =~ "^-.*" ) { $comments = "" }

  my $sth = $obj->{dbh}->prepare(q%
	  insert into p4gl_excel (
		  module_name,id_process,function_name,comments
    ) values (?,?,?,?)
	%);
  if ( !$sth )
	{
		$obj->{err}->error(
		  "Inserção de registo",
	    "Can't prepare insert into p4gl_excel\n$DBI::errstr\n"
    );
		return 0;
	}

	if ( $obj->{sendLineToLog} == 1 )
	{
	  $obj->{log}->log("LINE $moduleName, $idProcess, $functionName, $comments");
  }
	$sth->bind_param(1,$moduleName);
	$sth->bind_param(2,$idProcess);
	$sth->bind_param(3,$functionName);
	$sth->bind_param(4,$comments);
  if ( !$sth->execute() )
	{
		$obj->{err}->error(
		  "Inserção de registo",
	    "Can't insert into p4gl_excel\n$!\n"
    );
		return 0;
	}
  undef $sth;
	return 1;
}

#  ===========================================================================
#  Normaliza os dados de uma tabela que reflecte exactamente a folha de
#  cálculo na estrutura relacional normalizada
#  ===========================================================================
sub normalize
{
  my $obj = shift;
	$obj->insertPackages();
	$obj->insertModules();
	$obj->insertFunctions();
  $obj->completeFunctionsInformation();
  $obj->dropTempTables();
}

#  ===========================================================================
#  Limpa o repositório 
#  ===========================================================================
sub cleanRepository
{
  my $obj = shift;
	$obj->{progressListener}(
		  "Cleaning repository","p4gl_fun_process") if $obj->{progressListener};
  $obj->deleteAllFromTable("p4gl_fun_process");
	$obj->{progressListener}(
		  "Cleaning repository","p4gl_fun_parameter") if $obj->{progressListener};
  $obj->deleteAllFromTable("p4gl_fun_parameter");
	$obj->{progressListener}(
		  "Cleaning repository","p4gl_funtion") if $obj->{progressListener};
  $obj->deleteAllFromTable("p4gl_function");
	$obj->{progressListener}(
		  "Cleaning repository","p4gl_module") if $obj->{progressListener};
  $obj->deleteAllFromTable("p4gl_module");
	$obj->{progressListener}(
		  "Cleaning repository","p4gl_excel") if $obj->{progressListener};
}

#  ===========================================================================
#  Apaga tudo da tabela 
#    @param nome da tabela de onde se pretende apagar
#  ===========================================================================
sub deleteAllFromTable
{
  my $obj = shift;
	my $tableName = $_[0];
  my $numDeleted = $obj->{dbh}->do("delete from $tableName") ||
		$obj->{err}->error(
		  "Remoção da tabela",
	    "Can't delete from $tableName\n$DBI::errstr\n"
    );
}

#  ===========================================================================
#  Insere todos os packages que estão definidos na folha de cálculo
#  Nesta fase apenas insere o default package, caso não exista
#    @todo Terminar a definição correcta do(s) package(s)
#
#  ===========================================================================
sub insertPackages
{
  my $obj = shift;
	$obj->{progressListener}(
		  "Normalization","Inserting packages") if $obj->{progressListener};


  if ( $obj->isPackage(".") == 1 )
	{
	  $obj->{log}->log("Default package exists");
		return;
	}

	$obj->{log}->log("Default package inserted");
	my $sth = $obj->{dbh}->prepare(q%
	  insert into p4gl_package (id_package,comments) 
		values ('.','Default Package')
	%);
	

  if ( !$sth )
	{
		$obj->{err}->error(
		  "Inserção de linha",
	    "Can't prepare insert into p4gl_package\n$DBI::errstr\n"
    );
		return false;
	}

  $sth->execute() || 
		$obj->{err}->error(
		  "Inserção de linha",
	    "Can't insert into p4gl_package\n$DBI::errstr\n"
    );
  undef $sth;
	$obj->{log}->log("Packages inserted");
}

#  ===========================================================================
#  Valida se o package passado como parametro existe na tabela p4gl_package
#  ===========================================================================
sub isPackage
{
  my $obj = shift;
	my $idPackage = shift;
  my $sthPack = $obj->{dbh}->prepare(q%
	  SELECT count(*) FROM p4gl_package where id_package != '$idPackage'
	%);
  if ( !$sthPack )
	{
		$obj->{err}->error(
		  "Selecção de package",
	    "Can't prepare select from p4gl_package\n$DBI::errstr\n"
    );
		return false;
	}
  $sthPack->execute() || 
		$obj->{err}->error(
		  "Selecção de package",
	    "Can't select from p4gl_package\n$DBI::errstr\n"
    );
  my(@row);
	my $numPackages = 0;
  while (@row = $sthPack->fetchrow_array())
  {
		$numPackages = $row[0];
  }
  undef $sthPack;

	if ( $numPackages > 0 )
	{
	  return 1;
	}
	else
	{
	  return 0;
	}
}

#  ===========================================================================
#  Insere os módulos que estão definidos na folha de cálculo
#  Adapta-se se o repositório não estiver limpo faz update e não insert.
#  ===========================================================================
sub insertModules
{
  my $obj = shift;
	$obj->{progressListener}(
		  "Normalization","Inserting modules") if $obj->{progressListener};

	# Meter os inexistentes numa temporaria
	$obj->insertNonExistantModules();

  # Inserir os não existentes a partir da temporária
  my $numMods = $obj->{dbh}->do(q%
	  insert into p4gl_module (id_package,module_name) 
		  select id_package, module_name from missing_modules
  %) || 
		$obj->{err}->error(
		  "Inserçao de modulos",
	    "Impossivel inserir em p4gl_module\n$DBI::errstr\n"
    );
	$obj->{log}->log("Modules inserted in p4gl_modules : $numMods");
}

#  ===========================================================================
#  Insere os módulos não existentes numa tabela temporaria
#  ===========================================================================
sub insertNonExistantModules
{
  my $obj = shift;
  $obj->{dbh}->do(q%
	  create temp table missing_modules (
		  id_package char(64),
		  module_name char(64)
		)
  %) || 
		$obj->{err}->error(
		  "Criação de temporária",
	    "Impossivel criar tabela temporária missing_modules\n$DBI::errstr\n"
    );
  my $numMods = $obj->{dbh}->do(qq%
	  insert into missing_modules (id_package,module_name)
		  SELECT '.' , module_name FROM p4gl_excel
			where module_name not in ( select module_name from p4gl_module )
			group by module_name
  %) || 
		$obj->{err}->error(
		  "Criação de temporária",
	    "Impossivel criar tabela temporária missing_modules\n$DBI::errstr\n"
    );
	$obj->{log}->log("Modules inserted in temp : $numMods");
}

#  ===========================================================================
#  Apaga todas as funções existentes (e respectivos details) e insere as
#  funções defindas na folha de cálculo
#
#    @todo Inserção do 1º comentário da função
#  ===========================================================================
sub insertFunctions
{
  my $obj = shift;

	$obj->insertNonExistantFunctions();
	$obj->{progressListener}(
		  "Normalization","Inserting functions") if $obj->{progressListener};
  my $numMods = $obj->{dbh}->do(qq%
	  insert into p4gl_function (
		  id_package, module_name, function_name, function_type
     ) 
		 select id_package, module_name, function_name, function_type 
		 from missing_functions
  %) || 
		$obj->{err}->error(
		 "inserir funçoes",
	   "Impossivel inserir de tabela temporária em p4gl_function\n$DBI::errstr\n"
    );
	$obj->{log}->log("Functions inserted in p4gl_function: $numMods");
}

#  ===========================================================================
#  Insere as funçoes não existentes numa tabela temporaria
#  ===========================================================================
sub insertNonExistantFunctions
{
  my $obj = shift;
  $obj->{dbh}->do(q%
	  create temp table missing_functions (
		  id_package char(64),
		  module_name char(64),
		  function_name char(50),
			function_type char(1)
		)
  %) || 
		$obj->{err}->error(
		  "Criação de temporária",
	    "Impossivel criar tabela temporária missing_functions\n$DBI::errstr\n"
    );
  my $numFuncs = $obj->{dbh}->do(qq%
	  insert into missing_functions (
		    id_package,module_name,function_name,function_type
			)
      select distinct ".",module_name, function_name, "F" FROM p4gl_excel
			  where trim(module_name)||":"||trim(function_name) not in
				  ( select trim(module_name)||":"||trim(function_name)
					  from p4gl_function 
		      )
  %) || 
		$obj->{err}->error(
		 "Criação de temporária",
	   "Impossivel inserir em tabela temporária missing_functions\n$DBI::errstr\n"
    );
	$obj->{log}->log("Functions inserted in temporary : $numFuncs");
}

#  ===========================================================================
#  Apaga as tabelas temporarias criadas para trabalhar a informaçao
#  ===========================================================================
sub dropTempTables
{
  my $obj = shift;
  $obj->{dbh}->do(q%
	  drop table missing_functions;
	  drop table missing_modules;
  %) || 
		$obj->{err}->error(
		  "Limpeza de temporárias",
	    "Impossivel limpar tabelas temporária missing_modules e functions \n$DBI::errstr\n"
    );
}

#  ===========================================================================
#  Termina e completa a informação sobre a função
#    @todo Nunca estragar informaçao mas sim completa-la
#  ===========================================================================
sub completeFunctionsInformation
{
  my $obj = shift;
	$obj->validateProcesses();
  my $sthFI = $obj->{dbh}->prepare(q%
	  SELECT unique p4gl_function.module_name, p4gl_function.function_name 
		  FROM p4gl_function, p4gl_excel
		  where p4gl_excel.module_name   = p4gl_function.module_name 
			  and p4gl_excel.function_name = p4gl_function.function_name
	%);
  if ( !$sthFI )
	{
		$obj->{err}->error(
		  "Selecção de linha",
	    "Can't prepare select from p4gl_function\n$DBI::errstr\n"
    );
		return false;
	}

  $sthFI->execute() || 
		$obj->{err}->error(
		  "Selecção de linha",
	    "Can't select from p4gl_function\n$DBI::errstr\n"
    );
  my(@row);
  while (@row = $sthFI->fetchrow_array())
  {
		chomp($row[0]);
		$row[0] =~ s/ *$//;
		$row[0] =~ s/^ *//;
		chomp($row[1]);
		$row[1] =~ s/^ *//;
		$row[1] =~ s/ *$//;
	  $obj->{progressListener}(
		  "Normalization - Function","$row[0]:$row[1]") if $obj->{progressListener};
	  $obj->completeFunctionInformation($row[0],$row[1]);
  }
  undef $sthFI;
}


#  ===========================================================================
#  Completa a informação sobre a função
#    @param 0 nome do módulo a que a função pertence
#    @param 1 nome da função a ser completada
#  ===========================================================================
sub completeFunctionInformation
{
  my $obj = shift;
  my $moduleName   = shift;
  my $functionName = shift;
	$obj->insertFunctionProcesses($moduleName,$functionName);
	$obj->insertFunctionParameters($moduleName,$functionName);
	$obj->insertFunctionComments($moduleName,$functionName);
}

#  ===========================================================================
#  Insere os processos relativos a uma função no repositório relacional 
#  normalizado
#
#  Antes de inserir remove-os pois considera-se que os processos na folha
#  de calculo sao os correctos
#
#  @todo - Meter esta acçao configuravel
#
#    @param 0 nome do módulo a que a função pertence
#    @param 1 nome da função a ser completada
#  ===========================================================================
sub insertFunctionProcesses
{
  my $obj = shift;
  my $moduleName   = shift;
  my $functionName = shift;
  $obj->deleteFunctionProcesses($moduleName,$functionName);
  my $numProc = $obj->{dbh}->do(qq%
	  insert into p4gl_fun_process (
			id_process,
		  id_package,
			module_name,
			function_name
     ) 
		 select distinct id_process, ".",module_name,function_name
		   from p4gl_excel
			 where module_name = '$moduleName' and 
			       function_name = '$functionName'  and
						 id_process != 'ND' and 
						 id_process in ( select id_process from p4gl_process ) and
						 id_process is not null
	%) || $obj->{err}->error(
		  "Inserção de linha",
	    "Can't insert into p4gl_fun_process\n$DBI::errstr\n"
    );
}

#  ===========================================================================
#  Apaga os processos da funcao enviada como parametro
#  ===========================================================================
sub deleteFunctionProcesses
{
  my $obj = shift;
  my $modName   = shift;
  my $funcName = shift;
  $procsDeleted = $obj->{dbh}->do(qq%
	  delete from p4gl_fun_process 
	    where module_name='$modName' and function_name='$funcName'
    %) || 
		$obj->{err}->error(
		  "Limpeza de processos",
	    "Impossivel limpar processos de funçoes\n$DBI::errstr\n"
    );
	$obj->{log}->log("Processes of functions deleted: $procsDeleted");
}

#  ===========================================================================
#  Valida os processos não inseridos na tabela
#  ===========================================================================
sub validateProcesses
{
  my $obj = shift;
  my $sthVP = $obj->{dbh}->prepare(qq%
	  SELECT unique id_process FROM p4gl_excel 
		  where id_process not in ( select id_process from p4gl_process ) and
			  id_process != "ND"
	%);
  if ( !$sthVP )
	{
		$obj->{err}->error(
		  "Selecção de linha",
	    "Can't prepare select from p4gl_excel\n$DBI::errstr\n"
    );
		return false;
	}
  $sthVP->execute() || 
		$obj->{err}->error(
		  "Selecção de linha",
	    "Can't select from p4gl_excel\n$DBI::errstr\n"
    );
  my(@row);
	my $i = 0;
  while (@row = $sthVP->fetchrow_array())
  {
		if ( $i == 0 ) 
		{ 
		  $obj->{log}->log(
				"Processes used on sheet file but not found in p4gl_process:"
      );
		}
		$obj->{log}->log("    $row[0]\n");
		$i++;
  }
  undef $sthVP;
}

#  ===========================================================================
#  Insere os parametros relativos a uma função no repositório relacional 
#  normalizado
#    @param 0 nome do módulo a que a função pertence
#    @param 1 nome da função a ser completada
#    @todo Implementar a funcionalidade
#  ===========================================================================
sub insertFunctionParameters
{
  my $obj = shift;
  my $moduleName   = $_[0];
  my $functionName = $_[1];

	# Não implementado
}

#  ===========================================================================
#  Insere os comentários relativos a uma função no repositório relacional 
#  normalizado
#    @param 0 nome do módulo a que a função pertence
#    @param 1 nome da função a ser completada
#  ===========================================================================
sub insertFunctionComments
{
  my $obj = shift;
  my $moduleName   = $_[0];
  my $functionName = $_[1];
  my $sthSel = $obj->{dbh}->prepare(qq%
		 select comments
		   from p4gl_excel
			 where module_name = "$moduleName" and 
			       function_name = "$functionName" and
						 comments is not null
	%);

  if ( !$sthSel )
	{
		$obj->{err}->error(
		  "Selecção de linha",
	    "Can't prepare select comments from p4gl_excel\n$DBI::errstr\n"
    );
		return false;
	}
  $sthSel->execute() || 
		$obj->{err}->error(
		  "Selecção de linha",
	    "Can't select comments from p4gl_excel\n$DBI::errstr\n"
    );
  my(@row);
	my $functionComment = "";
	if ( @row = $sthSel->fetchrow_array() )
	{
	  $functionComment = $row[0];
	}
  undef $sthSel;

  my $sth = $obj->{dbh}->prepare(qq%
	  update p4gl_function set comments = ?
	    where module_name = "$moduleName" and function_name = "$functionName"
	%);
  if ( !$sth )
	{
		$obj->{err}->error(
		  "Alteração de linha",
	    "Can't prepare update p4gl_function\n$DBI::errstr\n"
    );
		return false;
	}
  $sth->bind_param(1,$functionComment);
  $sth->execute() ||
		$obj->{err}->error(
		  "Alteração de linha",
	    "Can't update p4gl_function\n$DBI::errstr\n"
    );
  undef $sth;
}


return 1;

