#!/usr/bin/perl

#  =========================================================================
#
#  Manter as op��es correctas
# 
#  Est� implementado sob a forma de objecto
#
#  Autor : S�rgio Ferreira
#
#  =========================================================================

package DbDocumenter::Options;

use strict;
use Tk;

#  =========================================================================
#  Construtora
#  =========================================================================
sub new
{
  my ($pkg) = @_;

	my $error = {
	  "UI"                 => "CUI",
	  "action"             => "export2Unl",
	  "dir"                => "/tmp",
	  "database"           => "",
	  "connection"         => 0,
	};
	bless $error, "DbDocumenter::Options";
	return $error;
}

#  =========================================================================
#  Afecta o user interface usado
#  =========================================================================
sub setUI
{
  my $obj = shift;
	$obj->{UI} = shift;
}

#  =========================================================================
#  Devolve o user interface usado
#  =========================================================================
sub getUI
{
  my $obj = shift;
	return $obj->{UI};
}

#  =========================================================================
#  Afecta a ac��o a executar
#  =========================================================================
sub setAction
{
  my $obj = shift;
	$obj->{action} = shift;
}

#  =========================================================================
#  Devolve a ac��o a executar
#  =========================================================================
sub getAction
{
  my $obj = shift;
	return $obj->{action};
}

#  =========================================================================
#  Afecta o direct�rio para onde se exporta ou importa
#  =========================================================================
sub setDir
{
  my $obj = shift;
	$obj->{dir} = shift;
}

#  =========================================================================
#  Devolve o direct�rio para onde se exporta ou importa
#  =========================================================================
sub getDir
{
  my $obj = shift;
	return $obj->{dir};
}

#  =========================================================================
#  Afecta a conex�o de acesso � base de dados
#  =========================================================================
sub setConnection
{
  my $obj = shift;
	$obj->{connection} = shift;
}

#  =========================================================================
#  Devolve a conex�o de acesso � base de dados
#  =========================================================================
sub getConnection
{
  my $obj = shift;
	return $obj->{connection};
}


return 1;
