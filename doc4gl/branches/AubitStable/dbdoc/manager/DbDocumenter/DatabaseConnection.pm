#!/usr/bin/perl -w

#  =========================================================================
#  
#
#  Implementado sob a forma de objecTo o que permite reutilizar os m�todos
#  para as diferentes conex�es.
#
#  Gere a informa��o necess�ria para acesso aos reposit�rios bem como 
#  implementa as rotinas para abrir a(s) bases de dados
#
#  $Author: afalout $
#  $Id: DatabaseConnection.pm,v 1.1 2003-05-22 08:48:23 afalout Exp $
#  =========================================================================

use strict;
use DBI;

package DbDocumenter::DatabaseConnection;


#  =========================================================================
#  Construtora
#  =========================================================================
sub new 
{
  my ($pkg,$INFORMIXDIR,$server,$host,$database,$user,$password) = @_;

	print "INFORMIXDIR  = $INFORMIXDIR\n";
	my $dbConnection = {
	  "INFORMIXDIR" => $INFORMIXDIR,
	  "server"      => $server,
	  "host"        => $host,
	  "database"    => $database,
	  "user"        => $user,
	  "password"    => $password,
	  "dbiUrl"      => "",
	  "connection"  => "",
	  "log"         => 0,
	  "err"         => 0,
	};
	bless $dbConnection, "DbDocumenter::DatabaseConnection";
	return $dbConnection;
}

#  =========================================================================
#  Afecta a vari�vel que define onde o informix est� instalado
#  =========================================================================
sub setInformixDir
{
	my $obj = shift;
  $obj->{INFORMIXDIR} = shift;
}

#  =========================================================================
#  @return Sitio onde o informix est� instalado
#  =========================================================================
sub getInformixDir
{
	my $obj = shift;
  return $obj->{INFORMIXDIR};
}


#  =========================================================================
#  =========================================================================
sub setHost
{
	my $obj = shift;
  $obj->{host} = shift;
}

#  =========================================================================
#  Devolve o host (servidor fisico) que contem a inst�ncia da base de dados
#  =========================================================================
sub getHost
{
	my $obj = shift;
  return $obj->{host};
}

#  =========================================================================
#  Afecta o server (inst�ncia de informix) a usar
#  =========================================================================
sub setServer
{
	my $obj = shift;
  $obj->{server} = shift;
}

#  =========================================================================
#  =========================================================================
sub getServer
{
	my $obj = shift;
  return $obj->{server};
}

#  =========================================================================
#  Afecta o utilizador para estabelecimento da conex�o
#  =========================================================================
sub setUser
{
	my $obj = shift;
  $obj->{user} = shift;
}

#  =========================================================================
#  Devolve o utilizador configurado
#  =========================================================================
sub getUser
{
	my $obj = shift;
  return $obj->{user};
}

#  =========================================================================
#  =========================================================================
sub setPassword
{
	my $obj = shift;
  $obj->{password} = shift;
}

#  =========================================================================
#  =========================================================================
sub getPassword
{
	my $obj = shift;
  return $obj->{password};
}


# ============================================================================
# Afecta a vari�vel que contem a base de dados
# ============================================================================
sub setDatabase
{
	my $obj = shift;
  $obj->{database} = shift;
}

# ============================================================================
# Devolve o nome da base de dados
# ============================================================================
sub getDatabase
{
	my $obj = shift;
  return $obj->{database};
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

# ============================================================================
# @return URL representativa da base de dados
#  @todo A Url n�o est� confirmada e correcta
# ============================================================================
sub getUrl
{
	my $obj = shift;
  my $url = "DBI::";
	$url .= "$obj->{host}:" if $obj->{host};
	$url .= "$obj->{server}/" if $obj->{server};
	$url .= "$obj->{database}&" if $obj->{database};
	$url .= "INFORMIXDIR=$obj->{INFORMIXDIR};" if $obj->{INFORMIXDIR};
	$url .= "user=$obj->{user};" if $obj->{user};
	$url .= "password=$obj->{password}" if $obj->{password};
	return $url;
}

# ============================================================================
# Constroi a URL necess�ria para acesso � base de dados
# @todo Resolver o problema do server na URL
# ============================================================================
sub buildDbiUrl
{
	my $obj = shift;
  my $dbUrl = "DBI:Informix:" . $obj->getDatabase();
	if ( defined($obj->{server}) && !($obj->{server}) )
	{
	  $dbUrl .= $obj->getServer();
	}
  $obj->{dbiUrl} = $dbUrl;
}

# ============================================================================
# Estabelece a conex�o � base de dados de acordo com as propriedades do objecto
# ============================================================================
sub connect
{
	my $obj = shift;
	$obj->buildDbiUrl();
	my $user = $obj->getUser();
	if ( defined($user)  )
	{
    if ( $obj->{connection} = DBI->connect(
		  $obj->{dbiUrl},
		  $obj->getUser(),
			$obj->getPassword()) 
    ){
			$obj->{log}->log("Connected to $obj->{database}")
			  if $obj->{log};
		}
    else
		{
      $obj->{err}->error(
		    "Conex�o � base de dados",
		    "Impossivel estabelecer conex�o ($obj->{dbiUrl})\n$DBI::errstr"
      );
			return 0;
	  }
	}
	else
	{
    if ( ($obj->{connection} = DBI->connect($obj->{dbiUrl})) )
		{
			$obj->{log}->log("Connected to $obj->{database}")
			  if $obj->{log};
		}
    else
		{
      $obj->{err}->error(
		    "Conex�o � base de dados",
		    "Impossivel estabelecer conex�o ($obj->{dbiUrl})\n$DBI::errstr"
      );
			return 0;
	  }
	}
	return 1;
}

#  ===========================================================================
#  Fecha uma conex�o a base de dados
#  ===========================================================================
sub disconnect
{
	my $obj = shift;
  $obj->{connection}->disconnect if $obj->{connection};
}


# ============================================================================
# @return Refer�ncia para a conex�o (em pricipio aberta)
# ============================================================================
sub getConnection
{
	my $obj = shift;
  return $obj->{connection};
}

return 1;
