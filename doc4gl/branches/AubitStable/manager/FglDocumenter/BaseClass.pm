#!/usr/bin/perl -w

# ============================================================================
# 
# Classe base que disponibiliza métodos para as acções que se repetem em
# todas as classes da aplicação (log, error, etc)
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
#  Afecta a referência para o language handler
#  ===========================================================================
sub setLanguageHandler
{
  my $obj = shift;
  $obj->{lh} = shift;
}

#  ===========================================================================
#  Afecta a referência para a conexão à base de dados
#  ===========================================================================
sub setConnection
{
  my $obj = shift;
  $obj->{connection} = shift;
}

#  ===========================================================================
#  Afecta a referência para a o objecto que contem funções utilitárias
#  para gestão do repositório
#  ===========================================================================
sub setRepositoryUtil
{
  my $obj = shift;
  $obj->{repositoryUtil} = shift;
}

1;
