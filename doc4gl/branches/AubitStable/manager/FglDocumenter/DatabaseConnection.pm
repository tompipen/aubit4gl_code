#!/usr/bin/perl -w

#  =========================================================================
#  
#
#  Implementado sob a forma de objecTo o que permite reutilizar os métodos
#  para as diferentes conexões.
#
#  Gere a informação necessária para acesso aos repositórios bem como 
#  implementa as rotinas para abrir a(s) bases de dados
#
#
#  Author : Sérgio Ferreira
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
#  Afecta a variável que define onde o informix está instalado
#  =========================================================================
sub setInformixDir
{
	my $obj = shift;
  $obj->{INFORMIXDIR} = shift;
}

#  =========================================================================
#  @return Sitio onde o informix está instalado
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
#  Devolve o host (servidor fisico) que contem a instância da base de dados
#  =========================================================================
sub getHost
{
	my $obj = shift;
  return $obj->{host};
}

#  =========================================================================
#  Afecta o server (instância de informix) a usar
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
#  Afecta o utilizador para estabelecimento da conexão
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
# Afecta a variável que contem a base de dados
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
# @return URL representativa da base de dados
#  @todo A Url não está confirmada e correcta
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
# Constroi a URL necessária para.
# No caso de se pretender criar a base de dados o server nao pode fazer parte
# da URL (embora nao esteja a ver uma razao logica).
# @todo Validar a utilizaçao do server na conexao a base de dados
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
# Estabelece a conexão à instancia de informix sem base de dados
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
			$obj->{log}->log("Conexão à instancia estabelecida")
			  if $obj->{log};
		}
    else
		{
      $obj->{err}->error(
		    "Conexão à base de dados",
		    "Impossivel estabelecer conexão : $obj->{dbiUrl}\n$DBI::errstr"
      );
			return 0;
	  }
	}
	else
	{
    if ( ($obj->{connection} = DBI->connect($obj->{dbiUrl})) )
		{
			$obj->{log}->log("Conexão à instancia estabelecida")
			  if $obj->{log};
		}
    else
		{
      $obj->{err}->error(
		    "Conexão à base de dados",
		    "Impossivel estabelecer conexão\n$DBI::errstr"
      );
			return 0;
	  }
	}
	return 1;
}


# ============================================================================
# Estabelece a conexão à base de dados de acordo com as propriedades do objecto
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
			#$obj->{log}->log("Conexão à base de dados estabelecida")
            $obj->{log}->log("Database connection established")
			  if $obj->{log};
		}
    else
		{
      $obj->{err}->error(
		    #"Conexão à base de dados",
		    #"Impossivel estabelecer conexão\n$DBI::errstr"
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
			#$obj->{log}->log("Conexão à base de dados estabelecida")
			$obj->{log}->log("Database connection established")
			  if $obj->{log};
		}
    else
		{
      $obj->{err}->error(
		    #"Conexão à base de dados",
		    #"Impossivel estabelecer conexão\n$DBI::errstr"
		    "Database connection",
		    "Cannot establish connection\n$DBI::errstr"

      );
			return 0;
	  }
	}
	return 1;
}

#  ===========================================================================
#  Fecha uma conexão a base de dados
#  ===========================================================================
sub disconnect
{
	my $obj = shift;
  $obj->{connection}->disconnect if $obj->{connection};
}


# ============================================================================
# @return Referência para a conexão (em pricipio aberta)
# ============================================================================
sub getConnection
{
	my $obj = shift;
  return $obj->{connection};
}

return 1;
