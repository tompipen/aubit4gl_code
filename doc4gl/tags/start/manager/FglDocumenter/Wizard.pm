#!/usr/bin/perl

#  =========================================================================
#
#  Controlador para utilização de wizards no projecto do documentador de 
#  sources Informix 4gl.
#
#  Surge para permitir um interface fácil na exportação da documentação para
#  os sources
#
#  É implementado sob a forma de objecto
#
#  Autor : Sérgio Ferreira
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
#  Afecta a main window com base na qual os form(s) são construido(s)
#  =========================================================================
sub setMainWindow
{
  my $obj = shift;
	$obj->{mainWindow} = shift;
}

#  =========================================================================
#  Adiciona uma nova acção ao objecto controlador do wizard
#  @todo - Implementar o método
#  =========================================================================
sub addWizardAction
{
  my $obj = shift;
	my $action = shift;

	# Fica assim por causa da confusão das referências que ainda não tenho 
	# treino suficiente
	my $actionListRef = $obj->{actionList};
	my @actionList = @$actionListRef;
  push(@actionList,$action);
	$obj->{actionList} = \@actionList;
}

#  =========================================================================
#  Remove uma acção ao objecto controlador do wizard
#  @todo - Implementar o método
#  =========================================================================
sub removeWizardAction
{
  my $obj = shift;
}

#  =========================================================================
#  Adiciona um listener para o evento desencadeado quando o utilizador 
#  carrega no botão "Done"
#
#  @todo - Implementar o método
#  =========================================================================
sub addDoneListener
{
  my $obj = shift;
}

#  =========================================================================
#  Remove um listener para o evento desencadeado quando o utilizador 
#  carrega no botão "Done"
#
#  @todo - Implementar o método
#  =========================================================================
sub removeDoneListener
{
  my $obj = shift;
}

#  =========================================================================
#  Adiciona um listener para o evento desencadeado quando o utilizador 
#  carrega no botão "Cancel"
#
#  @todo - Implementar o método
#  =========================================================================
sub addCancelListener
{
  my $obj = shift;
}

#  =========================================================================
#  Remove um listener para o evento desencadeado quando o utilizador 
#  carrega no botão "Cancel"
#
#  @todo - Implementar o método
#  =========================================================================
sub removeCancelListener
{
  my $obj = shift;
}

#  =========================================================================
#  Inicia a execução do wizard abrindo a janela se necessário e iniciando 
#  na 1ª acção do wizard.
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
#  Inicia a execução da acção corrente
#
#  @todo - Obter as referências e variáveis no objecto
#  =========================================================================
sub startCurrentAction
{
	my $obj = shift;
	my $action = $obj->getCurrentAction();

	# Executar listeners da acção a adicionar 
  # Pintar form e novo comentário

	# Abrir form da acção 
	$action->openForm($formFrame);
  $form->title($action->getTitle());
}

#  =========================================================================
#  Limpa o form da acção anterior
#    @todo - Conseguir arranjar um método para fazer isto
#  =========================================================================
sub cleanForm
{
  my $obj = shift;
	#$formFrame
}

#  =========================================================================
#  Fecha a acção corrente executando os listeners necessários e limpando o 
#  form e comentários
#
#  @todo - Convem saber porque razão está a ser fechado (anterior, seguinte,
#          cancelar ou done
#  =========================================================================
sub finishCurrentAction
{
	my $obj = shift;
	# Limpar form e comentário
	$obj->cleanForm();
	# Executar listeners da acção a remover 
}

#  =========================================================================
#  Executar a acção done após o utilizador ter executado o botão 
#  correspondente
#  =========================================================================
sub done
{
  my $obj = shift;
}

#  =========================================================================
#  Executar a acção de cancelamento
#  =========================================================================
sub cancel
{
  my $obj = shift;
}

#  =========================================================================
#  Executar a acção seguinte, o utilizador clickou em >
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
#  Executar a acção anterior, o utilizador clickou em <
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
#  Pinta / Adiciona os objectos gráficos necessários para o ecrã funcionar
#  =========================================================================
sub paint
{
  my $obj = shift;

	$form = $obj->{mainWindow}->Toplevel(-container => false);
  $form->title("Opções de exportação para fontes 4gl");
  $height = 400;
  $width  = 300;
	# @todo - Retitar esta dependencia não genérica
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
	  -text => "Descrição \ncorrespondente\nà acção"
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
#  Pinta / adiciona os botões de interacção com o utilizador
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
#  Devolve a acção corrente.
#  Implementado devido à dificuldade de obter e resolver as referencias
#  para a acção.
#  =========================================================================
sub getCurrentAction
{
	my $obj = shift;
	my $action = $obj->{actionList}->[$currentAction];
}

#  =========================================================================
#  Devolve a lista de acções
#  =========================================================================
sub getActionList
{
	my $obj = shift;
	my $actionListRef = $obj->{actionList};
	my @actionList = @$actionListRef;
	return @actionList;
}

#  =========================================================================
#  Refresca o estado dos botões consoante o posicionamento na lista de 
#  acções a executar
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

