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
#
#  Author : S�rgio Ferreira
# 
#  =========================================================================

use strict;
use DBI;

package FglDocumenter::DatabaseConnection;


#  =========================================================================
#  Construtora
#  =========================================================================
sub new 
{
  my ($pkg,$INFORMIXDIR,$server,$host,$database,$user,$password,$dbiUrl,
	    $connection) = @_;

	my $dbConnection = {
	  "INFORMIXDIR" => $INFORMIXDIR,
	  "server"      => $server,
	  "host"        => $host,
	  "database"    => $database,
	  "user"        => $user,
	  "password"    => $password,
	  "dbiUrl"      => $dbiUrl,
	  "connection"  => $connection,
	  "log"         => 0,
	  "err"         => 0,
	};
	bless $dbConnection, "FglDocumenter::DatabaseConnection";
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

sub setPassword
{
	my $obj = shift;
  $obj->{password} = shift;
}

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
# Constroi a URL necess�ria para.
# No caso de se pretender criar a base de dados o server nao pode fazer parte
# da URL (embora nao esteja a ver uma razao logica).
# @todo Validar a utiliza�ao do server na conexao a base de dados
# ============================================================================
sub buildDbiUrl
{
	my $obj = shift;
	my $withDatabase = shift;
  my $dbUrl;
	if ($withDatabase )
	{
    $dbUrl = "DBI:Informix:" . $obj->getDatabase();
	}
	else
	{
    $dbUrl = "DBI:Informix:";
	}
  #if ( defined($obj->{server}) )
	#{
	  #$dbUrl .= $obj->getServer();
	#}
  $obj->{dbiUrl} = $dbUrl;
}

# ============================================================================
# Estabelece a conex�o � instancia de informix sem base de dados
# ============================================================================
sub connectWithoutDatabase
{
	my $obj = shift;
	$obj->buildDbiUrl(0);
	my $user = $obj->getUser();
	if ( defined($user)  )
	{
    if ( $obj->{connection} = DBI->connect(
		  $obj->{dbiUrl},
		  $obj->getUser(),
			$obj->getPassword()) 
    ){
			$obj->{log}->log("Conex�o � instancia estabelecida")
			  if $obj->{log};
		}
    else
		{
      $obj->{err}->error(
		    "Conex�o � base de dados",
		    "Impossivel estabelecer conex�o : $obj->{dbiUrl}\n$DBI::errstr"
      );
			return 0;
	  }
	}
	else
	{
    if ( ($obj->{connection} = DBI->connect($obj->{dbiUrl})) )
		{
			$obj->{log}->log("Conex�o � instancia estabelecida")
			  if $obj->{log};
		}
    else
		{
      $obj->{err}->error(
		    "Conex�o � base de dados",
		    "Impossivel estabelecer conex�o\n$DBI::errstr"
      );
			return 0;
	  }
	}
	return 1;
}


# ============================================================================
# Estabelece a conex�o � base de dados de acordo com as propriedades do objecto
# ============================================================================
sub connect
{
	my $obj = shift;
	$obj->buildDbiUrl(1);
	my $user = $obj->getUser();
	if ( defined($user)  )
	{
    if ( $obj->{connection} = DBI->connect(
		  $obj->{dbiUrl},
		  $obj->getUser(),
			$obj->getPassword()) 
    ){
			#$obj->{log}->log("Conex�o � base de dados estabelecida")
            $obj->{log}->log("Database connection established")
			  if $obj->{log};
		}
    else
		{
      $obj->{err}->error(
		    #"Conex�o � base de dados",
		    #"Impossivel estabelecer conex�o\n$DBI::errstr"
		    "Database connection",
		    "Cannot establish connection\n$DBI::errstr"

      );
			return 0;
	  }
	}
	else
	{
    if ( ($obj->{connection} = DBI->connect($obj->{dbiUrl})) )
		{
			#$obj->{log}->log("Conex�o � base de dados estabelecida")
			$obj->{log}->log("Database connection established")
			  if $obj->{log};
		}
    else
		{
      $obj->{err}->error(
		    #"Conex�o � base de dados",
		    #"Impossivel estabelecer conex�o\n$DBI::errstr"
		    "Database connection",
		    "Cannot establish connection\n$DBI::errstr"

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
