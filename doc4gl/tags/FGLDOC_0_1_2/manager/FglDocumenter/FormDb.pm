#!/usr/bin/perl

#  =========================================================================
#
#  Implementa métodos em Perl/Tk para um form que permite efectuar as
#  configurações para estabelecimento de conexões a uma BD Informix
#
#  @todo Passar a objecto
#
#  Autor : Sérgio Ferreira
#
#  =========================================================================

use strict;

package FglDocumenter::FormDb;

use FglDocumenter::BaseClass;
use FglDocumenter::DatabaseConnection;

use vars qw(@ISA);
@ISA = ("FglDocumenter::BaseClass");

sub new
{
	my $pkg = shift;
	my $formDb = $pkg->allocate();

	$formDb->{okListener} =0;

	$formDb->{form}           = 0;
  $formDb->{okListener}     = 0;
  $formDb->{cancelListener} = 0;
  $formDb->{dbIfmxDir}      = 0;
  $formDb->{sqlHosts}       = 0;
  $formDb->{server}         = 0;
  $formDb->{user}           = 0;
  $formDb->{password}       = 0;
  $formDb->{database}       = 0;
	return $formDb;
}

#  =========================================================================
#  Afecta a propriedade relativa ao directório onde o informix está instalado
#  =========================================================================
sub setInformixDir
{
	my $obj = shift;
  $obj->{dbIfmxDir} = shift;
}

#  =========================================================================
#  =========================================================================
sub getInformixDir
{
	my $obj = shift;
  return $obj->{dbIfmxDir};
}


#  =========================================================================
#  =========================================================================
sub setSqlHosts
{
	my $obj = shift;
  $obj->{sqlHosts} = shift;
}

#  =========================================================================
#  =========================================================================
sub getSqlHosts
{
	my $obj = shift;
  return $obj->{sqlHosts};
}

#  =========================================================================
#  Afecta o informixserver do objecto
#  =========================================================================
sub setServer
{
	my $obj = shift;
  $obj->{server} = shift;
}

#  =========================================================================
#  Devolve o informixserver afectado no objecto
#  =========================================================================
sub getServer
{
	my $obj = shift;
  return $obj->{server};
}

#  =========================================================================
#  Afecta o utilizador registado no objecto
#  =========================================================================
sub setUser
{
	my $obj = shift;
  $obj->{user} = shift;
}

#  =========================================================================
#  Devolve o utilizador registado no objecto
#  =========================================================================
sub getUser
{
	my $obj = shift;
  return $obj->{user};
}

#  =========================================================================
#  Afecta a passord do objecto
#  =========================================================================
sub setPassword
{
	my $obj = shift;
  $obj->{password} = shift;
}

#  =========================================================================
#  Devolve a password registada no objecto
#  =========================================================================
sub getPassword
{
	my $obj = shift;
  return $obj->{password};
}

#  =========================================================================
#  Afecta o nome da base de dados do objecto
#  =========================================================================
sub setDatabase
{
	my $obj = shift;
  $obj->{database} = shift;
}

#  =========================================================================
#  Devolve o nome da base de dados do objecto
#  =========================================================================
sub getDatabase
{
	my $obj = shift;
  return $obj->{database};
}

#  =========================================================================
#  Abre e mostra o form para configuração do acesso a uma base de dados
#    @param Referência ao objecto de conexão
#  =========================================================================
sub showDbForm
{
	my $obj = shift;
	$obj->{dbConnection} = shift;
	my $dbConnection = $obj->{dbConnection};
  $obj->setInformixDir($dbConnection->getInformixDir());
  $obj->setSqlHosts($dbConnection->getHost());
  $obj->setServer($dbConnection->getServer());
  $obj->setDatabase($dbConnection->getDatabase());
  $obj->setUser($dbConnection->getUser());
  $obj->setPassword($dbConnection->getPassword());

	my $lh = $obj->{lh};

  $obj->{dbForm} = MainWindow->new;
	my $dbForm = $obj->{dbForm};
  
  $dbForm->title( 
	  $lh->maketext("Database access configuration")
	);

	my $lblIfmxDir = $dbForm->Label(-text => "INFORMIXDIR");
	my $txtIfmxDir = $dbForm->Entry(-width => 20, 
	  -textvariable => \$obj->{dbIfmxDir}
	);
	$lblIfmxDir->grid($txtIfmxDir);

	my $lblSqlHosts = $dbForm->Label(-text => "SQLHOST");
	my $txtSqlHosts = $dbForm->Entry(-width => 20, 
	  -textvariable => \$obj->{sqlHosts}
	);
	$lblSqlHosts->grid($txtSqlHosts);

	my $lblServer = $dbForm->Label(-text => "SERVER");
	my $txtServer = $dbForm->Entry(-width => 20, 
	  -textvariable => \$obj->{server}
	);
	$lblServer->grid($txtServer);

	my $lblUser = $dbForm->Label(
	  -text => $lh->maketext("Login")
	);
	my $txtUser = $dbForm->Entry(-width => 20, 
	  -textvariable => \$obj->{user}
	);
	$lblUser->grid($txtUser);

	my $lblPassword = $dbForm->Label(
	  -text => $lh->maketext("Password")
	);
	my $txtPassword = $dbForm->Entry(
		-show => '*',
	  -width => 20, 
		-textvariable => \$obj->{password}
	);
	$lblPassword->grid($txtPassword);

	my $lblDatabase = $dbForm->Label(
	  -text => $lh->maketext("Database")
	);
	my $txtDatabase = $dbForm->Entry(-width => 20, 
	  -textvariable => \$obj->{database}
	);

	# Botão para teste da conexão à BD
	my $testButton = $dbForm->Button(
	  -text => $lh->maketext("Test") ,
	  -command => [ \&testDbConnection, $obj ]
  );
	$lblDatabase->grid($txtDatabase, $testButton);

	my $okButton = $dbForm->Button(
	  -text => $lh->maketext("OK"),
	  -command => [ \&okFormDb, $obj ]
	);
	my $cancelButton = $dbForm->Button(
	  -text => $lh->maketext("Cancel"),
		-command => [ \&cancelFormDb, $obj ]
	);
	$okButton->grid($cancelButton);
	$dbForm->Popup();
}

#  =========================================================================
#  Testa a conexão à base de dados definida
#    @todo Limpar memória obtida com instânciação do objecto
#  =========================================================================
sub testDbConnection
{
	my $obj = shift;
	my $lh = $obj->{lh};
	$obj->{dbConn} = new FglDocumenter::DatabaseConnection(
    $obj->{dbIfmxDir},
    $obj->{server},
    $obj->{sqlHosts},
    $obj->{database},
    $obj->{user},
    $obj->{password}
	);
	$obj->{dbConn}->setError($obj->{err});
	$obj->{dbConn}->connect();
	if ( ! $DBI::err )
	{
		my $form = $main::mw->Dialog(
		  -title => $lh->maketext("Connection test"),
	    -text => $lh->maketext("Connection established")
    );
	  $form->Show();
	}
	$obj->{dbConn}->disconnect();
	$obj->{dbForm}->raise();
}

#  =========================================================================
#  O utilizador carregou em OK para validar os dados relativos à BD
#  =========================================================================
sub okFormDb
{
	my $obj = shift;
  $obj->{dbConnection}->setInformixDir(getInformixDir());
  $obj->{dbConnection}->setHost(getSqlHosts());
  $obj->{dbConnection}->setServer(getServer());
  $obj->{dbConnection}->setDatabase(getDatabase());
  $obj->{dbConnection}->setUser(getUser());
  $obj->{dbConnection}->setPassword(getPassword());

	# ??? Eventualmente faltam destroys aos sub-widgets
  $obj->{dbForm}->destroy;
  $obj->{okListener}() if $obj->{okListener};

}

#  =========================================================================
#  O utilizador carregou no botão de cancel
#  =========================================================================
sub cancelFormDb
{
	my $obj = shift;
  $obj->{dbForm}->destroy;
  $obj->{cancelListener}() if $obj->{cancelListener};
}

#  =========================================================================
#  Abre e mostra um form para se conseguir fazer login na base de dados
#  @todo Botão de OK deve validar estabelecimento de conexão à BD
#  =========================================================================
sub showLoginForm
{
	my $obj = shift;
	my $lh = $obj->{lh};
  $obj->{loginForm} = MainWindow->new;
  
	my $dbForm = $obj->{loginForm};
  $dbForm->title(
	  $lh->maketext("Login")
	);
  my $height = 300;
  my $width = 200;
	Utils::setWindowAtCenter($dbForm,$width,$height);

	my $lblUser = $dbForm->Label(
	  -text => $lh->maketext("Login to database")
	);
	my $txtUser = $dbForm->Entry(-width => 20, -textvariable => $obj->{user} );
	$lblUser->grid($txtUser);

	my $lblPassword = $dbForm->Label(
	  -text => $lh->maketext("Password")
	);
	my $txtPassword = $dbForm->Entry(
		-show => '*',
	  -width => 20, 
	  -textvariable => $obj->{password}
  );
	$lblPassword->grid($txtPassword);
}

#  =========================================================================
#  Adiciona um listener executado quando se carrega no botão de OK
#  =========================================================================
sub addOkListener
{
	my $obj = shift;
  $obj->{okListener} = shift;
}

#  =========================================================================
#  Adiciona um listener executado quando se carrega no botão de Cancel
#  =========================================================================
sub addCancelListener
{
	my $obj = shift;
  $obj->{cancelListener} = shift;
}

1;

