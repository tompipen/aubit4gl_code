#!/usr/bin/perl

#  =========================================================================
#
#  Implements methods in Perl/Tk for the form to allow configuration of
#  connection parameters to connect to Informix database.
#
#  Implementa métodos em Perl/Tk para um form que permite efectuar as
#  configurações para estabelecimento de conexões a uma BD Informix
#
#  Autor : Sérgio Ferreira
#
#  =========================================================================

package FglDocumenter::FormDb;

#  ===========================================================================
#  Afecta o objecto de gestão de erros usado
#  ===========================================================================
sub setError
{
  $err = shift;
}

#  ===========================================================================
#  Afecta a referência para o objecto de gestão de log(s)
#  ===========================================================================
sub setLog
{
  $log = shift;
}


#  =========================================================================
#  Afecta a propriedade relativa ao directório onde o informix está instalado
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
#  Abre e mostra o form para configuração do acesso a uma base de dados
#    @param Referência ao objecto de conexão
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
	  $dbForm->title("Configuração acesso a base de dados");
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

	# Botão para teste da conexão à BD
	$testButton = $dbForm->Button(-text => "Test",
	  -command => \&testDbConnection
  );
	$lblDatabase->grid($txtDatabase, $testButton);

	$okButton = $dbForm->Button(-text => "OK", -command => \&okFormDb);
	$cancelButton=$dbForm->Button(-text => "Cancel", -command => \&cancelFormDb);
	$okButton->grid($cancelButton);
}

#  =========================================================================
#  Testa a conexão à base de dados definida
#    @todo Limpar memória obtida com instânciação do objecto
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
			  -title => "Testar conexão",
		    -text => "Conexão estabelecida"
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
#  O utilizador carregou em OK para validar os dados relativos à BD
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
#  O utilizador carregou no botão de cancel
#  =========================================================================
sub cancelFormDb
{
  $dbForm->destroy;
  \&$cancelListener() if $cancelListener;
}

#  =========================================================================
#  Abre e mostra um form para se conseguir fazer login na base de dados
#  @todo Botão de OK deve validar estabelecimento de conexão à BD
#  =========================================================================
sub showLoginForm
{
  $dbForm = MainWindow->new;
  if ( 1 ) {
	  $dbForm->title("Database access configuration");
    } else {
	  $dbForm->title("Configuração acesso a base de dados");
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
#  Adiciona um listener executado quando se carrega no botão de OK
#  =========================================================================
sub addOkListener
{
  $okListener = shift;
}

#  =========================================================================
#  Adiciona um listener executado quando se carrega no botão de Cancel
#  =========================================================================
sub addCancelListener
{
  $cancelListener = shift;
}

return true;

