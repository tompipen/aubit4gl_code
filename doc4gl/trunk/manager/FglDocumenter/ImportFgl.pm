#!/usr/bin/perl -w

# ============================================================================
# 
# Métodos que executam o parser de carregamento em Repositório da informação
# existente nos sources de 4gl
#
# $Author: saferreira $
# $Id: ImportFgl.pm,v 1.2 2003-01-06 20:08:19 saferreira Exp $
# 
# ============================================================================

package FglDocumenter::ImportFgl;

use strict;
use POSIX;

#  =========================================================================
#  Constructor
#  =========================================================================
sub new
{
	my $importFgl = {
    "repository"         => 0,
    "dbh"                => 0,
    "err"                => 0,
    "log"                => 0,
    "fglModules"         => 0,
	  "fglDirectoryList"   => 0,
    "progressListener"   => 0,
	  "parseOnly"          => 0,
	  "loadComments"       => 1,
	  "loadTableUsage"     => 0,
	  "loadParameters"     => 1,
	  "loadStrings"        => 0,
	  "loadLocalVariables" => 0,
	};
	bless $importFgl, "FglDocumenter::ImportFgl";
	return $importFgl;
}


# ============================================================================
# Afecta a referência para o objecto que define a conexão ao repositório
# Este já deve estar devidamente conectado à BD
# ============================================================================
sub setRepository
{
  my $obj = shift;
  $obj->{repository} = shift;
	$obj->{dbh} = $obj->{repository}->getConnection();
}

#  ===========================================================================
#  Afecta o objecto de gestão de erros usado
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
#  Afecta a flag que indica se os comentarios devem ou nao ser carregados
#  ===========================================================================
sub setLoadComments
{
  my $obj = shift;
  $obj->{loadComments} = shift;
}

#  ===========================================================================
#  Afecta a flag que indica se as utilizaçoes de tabelas devem ou nao ser 
#  carregadas
#  ===========================================================================
sub loadTableUsage
{
  my $obj = shift;
  $obj->{loadTableUsage} = shift;
}

#  ===========================================================================
#  Afecta a flag que indica se os parametros devem ou nao ser carregados
#  ===========================================================================
sub loadParameters
{
  my $obj = shift;
  $obj->{loadParameters} = shift;
}

#  ===========================================================================
#  Afecta a flag que indica se as strings devem ou nao ser carregadas
#  ===========================================================================
sub loadStrings
{
  my $obj = shift;
  $obj->{loadStrings} = shift;
}

#  ===========================================================================
#  Afecta a flag que indica se as variaveis locais devem ou nao ser carregados
#  ===========================================================================
sub loadLocalVariables
{
  my $obj = shift;
  $obj->{loadLocalVariables} = shift;
}

# ============================================================================
# Afecta a lista de módulos de 4gl para os quais os comentários serão 
# importados
# ============================================================================
sub setFglModules
{
  my $obj = shift;
	#my $refModList = shift;
  #$obj->{fglModules} = $refModList;
  $obj->{fglModules} = shift;
}

# ============================================================================
# Afecta a lista de directórios correspondente aos 4gl 
# ============================================================================
sub setFglDirectoryList
{
  my $obj = shift;
	#my $refDirList = shift;
	#$obj->{fglDirectoryList} = @$refDirList;
	$obj->{fglDirectoryList} = shift;
}

# ============================================================================
# Devolve uma referencia para a lista de módulos nos quais os comentários 
# serão inseridos.
# ============================================================================
sub getFglModules
{
  my $obj = shift;
  return $obj->{fglModules};
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
#  Calcula o numero de acções para exportação para sources 4gl
#    @todo Implementar
#  ===========================================================================
sub getNumActions
{
  my $obj = shift;
	my $refFglMod = $obj->{fglModules};
	my @refFglList = @$refFglMod;;
	return $#refFglList;
}

#  ===========================================================================
#  Inicializa as opções para execução do p4gl
#
#  @todo - Scan do 4gl com destino num ficheiro. Linha de comando:
#  my $p4glCommand = "p4gl $p4glOp -l $docDir -c -f $_[1]
#  ===========================================================================
sub initP4glOptions
{
  my $obj = shift;
	my $p4glOptions = "";
	if ( $obj->{loadComments} == 1)
	{
	  $p4glOptions .= " --document";
	}

	if ( $obj->{parseOnly} == 0 )
	{
	  $p4glOptions = " --insert";
	}

	my $repOptions = "";
	if ( $obj->{loadTableUsage} == 1)
	{
	  $repOptions .= "t";
	}

	if ( $obj->{loadParameters} == 1)
	{
	  $repOptions .= "p";
	}

	if ( $obj->{loadStrings} == 1)
	{
	  $repOptions .= "s";
	}

	if ( $obj->{loadLocalVariables} == 1)
	{
	  $repOptions .= "l";
	}

	# @todo Validar se isto está ou não correcto
	#$p4glOptions .= " --repository_options=$repOptions";
	return $p4glOptions;
}

# ============================================================================
# Executa o parsing dos sources registados
# ============================================================================
sub parseSources
{
  my $obj = shift;
	my $p4glOptions = $obj->initP4glOptions();
	my $module;
	my $refModules = $obj->{fglModules};
	my @fglModules = @$refModules;
	my $retval = 1;

	my $refDirList = $obj->{fglDirectoryList};
	my @fglDirectoryList = @$refDirList;

	my $i = 0;
	$obj->{log}->log("Parsing $#fglModules");
	foreach $module ( @fglModules )
	{
		my $directory = @fglDirectoryList[$i];

		$obj->{progressListener}("Parsing source 4gl",
		  "$directory : $module"
    ) if $obj->{progressListener};

		my $p4glRetval;
		$p4glRetval = $obj->executeP4glFile(
			$directory,
			$module,
			$p4glOptions
    );
		if ( $p4glRetval == 0 )
		{
		  $retval = 0;
		}
		$i++;
	}
	return $retval;
}

#  =========================================================================
#  Executa o p4gl para o ficheiro passado como parametro
#    @param directory
#    @param nome do módulo 4gl
#    @param opções de execução
#  =========================================================================
sub executeP4glFile
{
  my $obj = shift;
	my $wantedDir   = shift;
	my $module      = shift;
	my $p4glOptions = shift;
  my $retval = 1;

  my $currentDir = getcwd();
	unless (chdir $wantedDir)
	{
		$obj->{err}->error(
		  "Mudar de directório para parsing de $module",
		  "Error changing to $wantedDir :$!"
    );		
	  return 0;
  }

  # @todo Retirar dependencia de opçoes
	my $rep = $obj->{repository};
	my $databaseName = $rep->getDatabase();
	my $p4glCommand = "p4gl --file=$module --database=$databaseName" .
	  " $p4glOptions"
  ;

	$obj->{log}->log("$p4glCommand em " . getcwd() . "\n");
	my $result;
	# Isto não está a detectar eventuais erros correctamente
	# @todo Conseguir detectar se tenho p4gl algures no PATH
	$result = `$p4glCommand`;
	if ( $result =~ "^\$" )
  {
	  $obj->{log}->log("$module Parsed");
	}
	else
	{
	  $obj->{log}->log("Error executing p4gl :\n		$! $result");
		$obj->{err}->error(
		  "Parsing de ficheiro",
		  "Error parsing $module :$result"
    );		
		$retval = 0;
	}

	# Still missing
  #{"file", 1, 0, 'f'},
  #{"database", 1, 0, 'b'},
  #{"debug", 0, 0, 'd'},
  #{"verbose", 0, 0, 'v'},
  #{"insert", 0, 0, 'i'},
  #{"warning_level", 1, 0, 'w'},
  #{"help", 0, 0, 'h'},
  #{"document", 0, 0, 'c'},
  #{"std_comment", 0, 0, 's'},
  #{"document_directory", 1, 0, 'l'},
  #{"package", 1, 0, 'p'},
  #{"repository_options", 1, 0, 'o'},
	unless (chdir $currentDir)
	{
		$obj->{err}->error(
		  "Mudar para directório original $currentDir",
		  "Error changing to $currentDir :$!"
    );		
	  return 0;
	}
	return $retval;
}

return 1;

