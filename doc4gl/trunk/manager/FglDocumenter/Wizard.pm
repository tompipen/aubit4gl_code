#!/usr/bin/perl

#  =========================================================================
#
#  Controlador para utiliza��o de wizards no projecto do documentador de 
#  sources Informix 4gl.
#
#  Surge para permitir um interface f�cil na exporta��o da documenta��o para
#  os sources
#
#  � implementado sob a forma de objecto
#
#  Autor : S�rgio Ferreira
#
#
#  =========================================================================

package FglDocumenter::Wizard;

use Tk;
use FglDocumenter::Utils;

#  =========================================================================
#  Construtora
#  =========================================================================
sub new
{	
  my ($pkg,) = @_;

	my $wizard = {
	  "actionList"  => [],
	  "mainWindow"  => 0
	};
  bless $wizard, "FglDocumenter::Wizard";
	return $wizard;
}

#  =========================================================================
#  Afecta a main window com base na qual os form(s) s�o construido(s)
#  =========================================================================
sub setMainWindow
{
  my $obj = shift;
	$obj->{mainWindow} = shift;
}

#  =========================================================================
#  Adiciona uma nova ac��o ao objecto controlador do wizard
#  @todo - Implementar o m�todo
#  =========================================================================
sub addWizardAction
{
  my $obj = shift;
	my $action = shift;

	# Fica assim por causa da confus�o das refer�ncias que ainda n�o tenho 
	# treino suficiente
	my $actionListRef = $obj->{actionList};
	my @actionList = @$actionListRef;
  push(@actionList,$action);
	$obj->{actionList} = \@actionList;
}

#  =========================================================================
#  Remove uma ac��o ao objecto controlador do wizard
#  @todo - Implementar o m�todo
#  =========================================================================
sub removeWizardAction
{
  my $obj = shift;
}

#  =========================================================================
#  Adiciona um listener para o evento desencadeado quando o utilizador 
#  carrega no bot�o "Done"
#
#  @todo - Implementar o m�todo
#  =========================================================================
sub addDoneListener
{
  my $obj = shift;
}

#  =========================================================================
#  Remove um listener para o evento desencadeado quando o utilizador 
#  carrega no bot�o "Done"
#
#  @todo - Implementar o m�todo
#  =========================================================================
sub removeDoneListener
{
  my $obj = shift;
}

#  =========================================================================
#  Adiciona um listener para o evento desencadeado quando o utilizador 
#  carrega no bot�o "Cancel"
#
#  @todo - Implementar o m�todo
#  =========================================================================
sub addCancelListener
{
  my $obj = shift;
}

#  =========================================================================
#  Remove um listener para o evento desencadeado quando o utilizador 
#  carrega no bot�o "Cancel"
#
#  @todo - Implementar o m�todo
#  =========================================================================
sub removeCancelListener
{
  my $obj = shift;
}

#  =========================================================================
#  Inicia a execu��o do wizard abrindo a janela se necess�rio e iniciando 
#  na 1� ac��o do wizard.
# 
#  @todo - Guardar os dados no objecto
#  =========================================================================
sub start
{
  my $obj = shift;
	$currentAction = 0;
	$obj->startCurrentAction();
}

#  =========================================================================
#  Inicia a execu��o da ac��o corrente
#
#  @todo - Obter as refer�ncias e vari�veis no objecto
#  =========================================================================
sub startCurrentAction
{
	my $obj = shift;
	my $action = $obj->getCurrentAction();

	# Executar listeners da ac��o a adicionar 
  # Pintar form e novo coment�rio

	# Abrir form da ac��o 
	$action->openForm($formFrame);
  $form->title($action->getTitle());
}

#  =========================================================================
#  Limpa o form da ac��o anterior
#    @todo - Conseguir arranjar um m�todo para fazer isto
#  =========================================================================
sub cleanForm
{
  my $obj = shift;
	#$formFrame
}

#  =========================================================================
#  Fecha a ac��o corrente executando os listeners necess�rios e limpando o 
#  form e coment�rios
#
#  @todo - Convem saber porque raz�o est� a ser fechado (anterior, seguinte,
#          cancelar ou done
#  =========================================================================
sub finishCurrentAction
{
	my $obj = shift;
	# Limpar form e coment�rio
	$obj->cleanForm();
	# Executar listeners da ac��o a remover 
}

#  =========================================================================
#  Executar a ac��o done ap�s o utilizador ter executado o bot�o 
#  correspondente
#  =========================================================================
sub done
{
  my $obj = shift;
}

#  =========================================================================
#  Executar a ac��o de cancelamento
#  =========================================================================
sub cancel
{
  my $obj = shift;
}

#  =========================================================================
#  Executar a ac��o seguinte, o utilizador clickou em >
#  =========================================================================
sub next
{
  my $obj = shift;
	$obj->finishCurrentAction();
	$currentAction++;
	$obj->startCurrentAction();
	$obj->refreshButtons();
}

#  =========================================================================
#  Executar a ac��o anterior, o utilizador clickou em <
#  =========================================================================
sub previous
{
  my $obj = shift;
	$obj->finishCurrentAction();
	$currentAction--;
	$obj->startCurrentAction();
	$obj->refreshButtons();
}

#  =========================================================================
#  Pinta / Adiciona os objectos gr�ficos necess�rios para o ecr� funcionar
#  =========================================================================
sub paint
{
  my $obj = shift;

	$form = $obj->{mainWindow}->Toplevel(-container => false);
  $form->title("Op��es de exporta��o para fontes 4gl");
  $height = 400;
  $width  = 300;
	# @todo - Retitar esta dependencia n�o gen�rica
	FglDocumenter::Utils::setWindowAtCenter($form,$width,$height);

	# Frames: Button, Comments, Form
	$commentFrame = $form->Frame(-relief => "sunken", -bd =>4,
		-height => 50,
	);

	$formFrame    = $form->Frame(-relief => "sunken", -bd =>4,
		-label => "Form",
	);

	$buttonFrame  = $form->Frame(-relief => "groove", -bd =>2,
		#-container => true,
		#-height => 10,
		#-width	 => 500,
	);

	$commentFrame->grid(-sticky => "nw");
	$lblComments = $commentFrame->Label(
	  -text => "Descri��o \ncorrespondente\n� ac��o"
  );
	$lblComments->pack(-side => 'left');

	$formFrame->grid(-row => 0, -sticky => "ne");
	$buttonFrame->grid(-columnspan => 2, -sticky => "sew");
	$form->gridRowconfigure(0,-weight => 200);
	$form->gridRowconfigure(1,-weight => 100);
	$form->gridColumnconfigure(0,-weight => 100);
	$form->gridColumnconfigure(1,-weight => 300);
	$obj->paintButtons();
}

#  =========================================================================
#  Pinta / adiciona os bot�es de interac��o com o utilizador
#  =========================================================================
sub paintButtons
{
  my $obj = shift;
	$previousButton = $buttonFrame->Button(-text => "<", 
	  -command => [ \&previous, $obj ]
  );
	$previousButton->pack(-side => 'left');
	$nextButton     = $buttonFrame->Button(-text => ">", 
	  -command => [ \&next, $obj ]
  );
	$nextButton->pack(-side => 'left');
	$cancelButton   = $buttonFrame->Button(-text => "Cancel",
	  -command=> \&cancel
  );
	$cancelButton->pack(-side => 'left');
	$doneButton     = $buttonFrame->Button(-text => "Done", 
	  -command => \&done
  );
	$doneButton->pack(-side => 'left');
	$obj->refreshButtons();
}

#  =========================================================================
#  Devolve a ac��o corrente.
#  Implementado devido � dificuldade de obter e resolver as referencias
#  para a ac��o.
#  =========================================================================
sub getCurrentAction
{
	my $obj = shift;
	my $action = $obj->{actionList}->[$currentAction];
}

#  =========================================================================
#  Devolve a lista de ac��es
#  =========================================================================
sub getActionList
{
	my $obj = shift;
	my $actionListRef = $obj->{actionList};
	my @actionList = @$actionListRef;
	return @actionList;
}

#  =========================================================================
#  Refresca o estado dos bot�es consoante o posicionamento na lista de 
#  ac��es a executar
#  =========================================================================
sub refreshButtons
{
  my $obj = shift;
	my @actionList = $obj->getActionList();
	if  ( $currentAction == 0 )
	{
	  $previousButton->configure(-state => 'disabled');
	}
	else
	{
	  $previousButton->configure(-state => 'active');
	}

	if ( $currentAction == $#actionList )
	{
	  $nextButton->configure(-state => 'disabled');
	}
  else
	{
	  $nextButton->configure(-state => 'active');
	}
}

return 1;

