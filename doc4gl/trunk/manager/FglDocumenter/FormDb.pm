#!/usr/bin/perl

#  =========================================================================
#
#  Implements methods in Perl/Tk for the form to allow configuration of
#  connection parameters to connect to Informix database.
#
#  Implementa m�todos em Perl/Tk para um form que permite efectuar as
#  configura��es para estabelecimento de conex�es a uma BD Informix
#
#  Autor : S�rgio Ferreira
#
#  =========================================================================

package FglDocumenter::FormDb;

#  ===========================================================================
#  Afecta o objecto de gest�o de erros usado
#  ===========================================================================
sub setError
{
  $err = shift;
}

#  ===========================================================================
#  Afecta a refer�ncia para o objecto de gest�o de log(s)
#  ===========================================================================
sub setLog
{
  $log = shift;
}


#  =========================================================================
#  Afecta a propriedade relativa ao direct�rio onde o informix est� instalado
#  =========================================================================
sub setInformixDir
{
  $dbIfmxDir = $_[0];
}

#  =========================================================================
#  =========================================================================
sub getInformixDir
{
  return $dbIfmxDir;
}


#  =========================================================================
#  =========================================================================
sub setSqlHosts
{
  $sqlHosts = $_[0];
}

#  =========================================================================
#  =========================================================================
sub getSqlHosts
{
  return $sqlHosts;
}

#  =========================================================================
#  =========================================================================
sub setServer
{
  $server = $_[0];
}

#  =========================================================================
#  =========================================================================
sub getServer
{
  return $server;
}

#  =========================================================================
#  =========================================================================
sub setUser
{
  $user = $_[0];
}

#  =========================================================================
#  =========================================================================
sub getUser
{
  return $user;
}

#  =========================================================================
#  =========================================================================
sub setPassword
{
  $password = $_[0];
}

#  =========================================================================
#  =========================================================================
sub getPassword
{
  return $password;
}

#  =========================================================================
#  =========================================================================
sub setDatabase
{
  $database = $_[0];
}

#  =========================================================================
#  =========================================================================
sub getDatabase
{
  return $database;
}

#  =========================================================================
#  Abre e mostra o form para configura��o do acesso a uma base de dados
#    @param Refer�ncia ao objecto de conex�o
#  =========================================================================
sub showDbForm
{
	$dbConnection = shift;
  setInformixDir($dbConnection->getInformixDir());
  setSqlHosts($dbConnection->getHost());
  setServer($dbConnection->getServer());
  setDatabase($dbConnection->getDatabase());
  setUser($dbConnection->getUser());
  setPassword($dbConnection->getPassword());

  $dbForm = MainWindow->new;

  if ( 1 ) {
	  $dbForm->title("Database access configuration");
    } else {
	  $dbForm->title("Configura��o acesso a base de dados");
    }

  $height = 300;
  $width = 200;
	FglDocumenter::Utils::setWindowAtCenter($dbForm,$width,$height);

	$lblIfmxDir = $dbForm->Label(-text => "INFORMIXDIR");
	$txtIfmxDir = $dbForm->Entry(-width => 20, -textvariable => \$dbIfmxDir );
	$lblIfmxDir->grid($txtIfmxDir);

	$lblSqlHosts = $dbForm->Label(-text => "SQLHOST");
	$txtSqlHosts = $dbForm->Entry(-width => 20, -textvariable => \$sqlHosts );
	$lblSqlHosts->grid($txtSqlHosts);

	$lblServer = $dbForm->Label(-text => "SERVER");
	$txtServer = $dbForm->Entry(-width => 20, -textvariable => \$server );
	$lblServer->grid($txtServer);

	$lblUser = $dbForm->Label(-text => "Login");
	$txtUser = $dbForm->Entry(-width => 20, -textvariable => \$user );
	$lblUser->grid($txtUser);

	$lblPassword = $dbForm->Label(-text => "Password");
	$txtPassword = $dbForm->Entry(
		-show => '*',
	  -width => 20, 
		-textvariable => \$password
	);
	$lblPassword->grid($txtPassword);

	$lblDatabase = $dbForm->Label(-text => "Database");
	$txtDatabase = $dbForm->Entry(-width => 20, -textvariable => \$database);

	# Bot�o para teste da conex�o � BD
	$testButton = $dbForm->Button(-text => "Test",
	  -command => \&testDbConnection
  );
	$lblDatabase->grid($txtDatabase, $testButton);

	$okButton = $dbForm->Button(-text => "OK", -command => \&okFormDb);
	$cancelButton=$dbForm->Button(-text => "Cancel", -command => \&cancelFormDb);
	$okButton->grid($cancelButton);
}

#  =========================================================================
#  Testa a conex�o � base de dados definida
#    @todo Limpar mem�ria obtida com inst�ncia��o do objecto
#  =========================================================================
sub testDbConnection
{
	$dbConn = new FglDocumenter::DatabaseConnection(
    $dbIfmxDir,
    $server,
    $sqlHosts,
    $database,
    $user,
    $password
	);
	$dbConn->setError($err);
	$dbConn->connect();
	if ( ! $DBI::err )
	{
		if ( 1 ) {
			$form = $main::mw->Dialog(
			  -title => "Test connection",
		    -text => "Connection established"
		    );

        } else {
			$form = $main::mw->Dialog(
			  -title => "Testar conex�o",
		    -text => "Conex�o estabelecida"
		    );
        }
	  $form->Show();
	} else {

		$form = $main::mw->Dialog(
		  -title => "Test connection",
	    -text => "Connection failed"
		    );

	  $form->Show();

    }
	$dbConn->disconnect();
}

#  =========================================================================
#  O utilizador carregou em OK para validar os dados relativos � BD
#  =========================================================================
sub okFormDb
{
  $dbConnection->setInformixDir(getInformixDir());
  $dbConnection->setHost(getSqlHosts());
  $dbConnection->setServer(getServer());
  $dbConnection->setDatabase(getDatabase());
  $dbConnection->setUser(getUser());
  $dbConnection->setPassword(getPassword());

	# ??? Eventualmente faltam destroys aos sub-widgets
  $dbForm->destroy;
  \&$okListener() if $okListener;

}

#  =========================================================================
#  O utilizador carregou no bot�o de cancel
#  =========================================================================
sub cancelFormDb
{
  $dbForm->destroy;
  \&$cancelListener() if $cancelListener;
}

#  =========================================================================
#  Abre e mostra um form para se conseguir fazer login na base de dados
#  @todo Bot�o de OK deve validar estabelecimento de conex�o � BD
#  =========================================================================
sub showLoginForm
{
  $dbForm = MainWindow->new;
  if ( 1 ) {
	  $dbForm->title("Database access configuration");
    } else {
	  $dbForm->title("Configura��o acesso a base de dados");
    }

  $height = 300;
  $width = 200;
	Utils::setWindowAtCenter($dbForm,$width,$height);

	$lblUser = $dbForm->Label(-text => "Login");
	$txtUser = $dbForm->Entry(-width => 20, -textvariable => $user );
	$lblUser->grid($txtUser);

	$lblPassword = $dbForm->Label(-text => "Password");
	$txtPassword = $dbForm->Entry(
		-show => '*',
	  -width => 20, 
	  -textvariable => $password
  );
	$lblPassword->grid($txtPassword);
}

#  =========================================================================
#  Adiciona um listener executado quando se carrega no bot�o de OK
#  =========================================================================
sub addOkListener
{
  $okListener = shift;
}

#  =========================================================================
#  Adiciona um listener executado quando se carrega no bot�o de Cancel
#  =========================================================================
sub addCancelListener
{
  $cancelListener = shift;
}

return true;

