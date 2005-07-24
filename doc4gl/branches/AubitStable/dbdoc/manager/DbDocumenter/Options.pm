#!/usr/bin/perl

#  =========================================================================
#
#  Manter as opções correctas
# 
#  Está implementado sob a forma de objecto
#
#  Autor : Sérgio Ferreira
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
#  Afecta a acção a executar
#  =========================================================================
sub setAction
{
  my $obj = shift;
	$obj->{action} = shift;
}

#  =========================================================================
#  Devolve a acção a executar
#  =========================================================================
sub getAction
{
  my $obj = shift;
	return $obj->{action};
}

#  =========================================================================
#  Afecta o directório para onde se exporta ou importa
#  =========================================================================
sub setDir
{
  my $obj = shift;
	$obj->{dir} = shift;
}

#  =========================================================================
#  Devolve o directório para onde se exporta ou importa
#  =========================================================================
sub getDir
{
  my $obj = shift;
	return $obj->{dir};
}

#  =========================================================================
#  Afecta a conexão de acesso à base de dados
#  =========================================================================
sub setConnection
{
  my $obj = shift;
	$obj->{connection} = shift;
}

#  =========================================================================
#  Devolve a conexão de acesso à base de dados
#  =========================================================================
sub getConnection
{
  my $obj = shift;
	return $obj->{connection};
}


return 1;
