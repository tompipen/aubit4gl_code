#!/usr/bin/perl -w

# ============================================================================
# 
# Métodos que executam a inserção dos comentários guardados no repositório
# nos sources de 4gl
#
# @todo Revisao de codigo e testes
# @todo Ser esta classe que se preocupa em mudar para o directorio onde o 
#       fonte está
# @todo Rever valores de retorno
#
# $Author: saferreira $
# $Id: ExportFgl.pm,v 1.2 2003-01-06 20:07:17 saferreira Exp $
# 
# ============================================================================

package FglDocumenter::ExportFgl;

use strict;
use FglDocumenter::ExportOneFgl;

#  =========================================================================
#  Constructor
#  =========================================================================
sub new
{
				#my ($exportFgl) = @_;

	my $exportFgl = {
    "replaceFgldoc"       => 0,
    "repository"          => 0,
    "dbh"                 => 0,
    "err"                 => 0,
    "log"                 => 0,
	  "fglModules"          => (),
	  "fglDirectoryList"    => (),
    "progressListener"    => 0,
    "insertEmptyComment"  => 0,
	};
	bless $exportFgl, "FglDocumenter::ExportFgl";
	return $exportFgl;
}

# ============================================================================
# Afecta a propriedade que define se deve substituir comentários fgldoc
# ============================================================================
sub setReplaceFgldoc
{
  my $obj = shift;
  $obj->{replaceFgldoc} = shift;
}

# ============================================================================
# Afecta a referência para o objecto que define a conexão ao repositório
# Este já deve estar devidamente conectado à BD
# ============================================================================
sub setRepository
{
  my $obj = shift;
  $obj->{repository} = $_[0];
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


# ============================================================================
# Afecta a lista de módulos de 4gl para os quais os comentários serão 
# exportados
# ============================================================================
sub setFglModules
{
  my $obj = shift;
	#$obj->{fglModules} = $_[0];
	#$var = shift;
	#$var = $_[0];
	$obj->{fglModules} = shift;
}

# ============================================================================
# Devolve a lista de módulos nos quais os comentários serão inseridos
# ============================================================================
sub getFglModules
{
  my $obj = shift;
  return $obj->{fglModules};
}

# ============================================================================
# Afecta a lista de directórios correspondente aos 4gl 
#  @param $_[0] Lista de directórios a alterar
# ============================================================================
sub setFglDirectoryList
{
  my $obj = shift;
	$obj->{fglDirectoryList} = shift;
}

#  ===========================================================================
#  Afecta a flag que indica se devem ou não ser inseridos comentários vazios
#  (sem descritivos de funções nem processos)
#  ===========================================================================
sub setInsertEmptyComment
{
  my $obj = shift;
  $obj->{insertEmptyComment} = shift;
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
#    @todo Implementar correctamente
#  ===========================================================================
sub getNumActions
{
  my $obj = shift;
	my $refMod = $obj->{fglModules};
  my @mods = \$refMod;
	return $#mods;
}

#  ===========================================================================
#  Selecciona os dados do repositório de comentários e para cada módulo 
#  insere os comentários que encontra de cada função no local correcto do
#  source correspondente
#  ===========================================================================
sub insertDocComments
{
  my $obj = shift;
	my $fglModule = "";
	# Isto esta aos bocados pois eh mais simples
	my $arrayRef = $obj->{fglModules};
	my @array = @$arrayRef;
	foreach $fglModule ( @array )
	{
		my $exportOneFglObject = new FglDocumenter::ExportOneFgl();
		# @todo Resolver este problema
    my $directory = $obj->{fglDirectoryList}[0];
		$exportOneFglObject->setError($obj->{err});
		$exportOneFglObject->setLog($obj->{log});
		$exportOneFglObject->setRepository($obj->{repository});
		$exportOneFglObject->setFglModule($fglModule);
		$exportOneFglObject->setFglDirectory($directory);
		$exportOneFglObject->setReplaceFgldoc($obj->{replaceFgldoc});
		$exportOneFglObject->setInsertEmptyComment(
		  $obj->{insertEmptyComment}
		);
		$obj->{progressListener}(
						"Inserting coments on source", $fglModule) if $obj->{progressListener};
	  $exportOneFglObject->commentModule($directory,$fglModule);
	}
  return 1;
}

return 1;

