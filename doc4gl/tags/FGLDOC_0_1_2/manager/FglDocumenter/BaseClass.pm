#!/usr/bin/perl -w

# ============================================================================
# 
# Classe base que disponibiliza m�todos para as ac��es que se repetem em
# todas as classes da aplica��o (log, error, etc)
#
# $Author: saferreira $
# $Id: BaseClass.pm,v 1.1 2003-01-06 20:07:00 saferreira Exp $
# 
# ============================================================================

package FglDocumenter::BaseClass;

use strict;

#  =========================================================================
#  Constructor da superclass
#  =========================================================================
sub allocate
{
	my $pkg = shift;
	my $baseClass = bless {
    "repository"        => 0,
    "dbh"               => 0,
    "err"               => 0,
    "log"               => 0,
    "lh"                => 0,
    "connection"        => 0,
    "repositoryUtil"    => 0,
	}, $pkg;
	return $baseClass;
}


# ============================================================================
# Afecta a refer�ncia para o objecto que define a conex�o ao reposit�rio
# Este j� deve estar devidamente conectado � BD
# ============================================================================
sub setRepository
{
  my $obj = shift;
  $obj->{repository} = shift;
	$obj->{dbh} = $obj->{repository}->getConnection();
}

#  ===========================================================================
#  Afecta o objecto de gest�o de erros usado
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
#  Afecta a refer�ncia para o language handler
#  ===========================================================================
sub setLanguageHandler
{
  my $obj = shift;
  $obj->{lh} = shift;
}

#  ===========================================================================
#  Afecta a refer�ncia para a conex�o � base de dados
#  ===========================================================================
sub setConnection
{
  my $obj = shift;
  $obj->{connection} = shift;
}

#  ===========================================================================
#  Afecta a refer�ncia para a o objecto que contem fun��es utilit�rias
#  para gest�o do reposit�rio
#  ===========================================================================
sub setRepositoryUtil
{
  my $obj = shift;
  $obj->{repositoryUtil} = shift;
}

1;
