#!/usr/bin/perl -w

#  =========================================================================
#
#  Implementa m�todos em Perl/Tk para um form que permite efectuar as
#  da importa��o de um ficheiro CSV
# 
#  As op��es globais est�o guardadas no m�dulo Options.
#
#  @todo - Inserir mais uma op��o (Inser��o de processos indefinidos)
#
#  Autor : S�rgio Ferreira
#
#  =========================================================================

package FglDocumenter::FormImportCSV;

use strict;
use Tk::Dialog;

#  =========================================================================
#  Constructor
#  =========================================================================
sub new
{
  my ($formImportCsv) = @_;

	my $formImportCsv = {
    "err"                => 0,
	  "log"                => 0,
	  "lh"                 => 0,
    "okListener"         => 0,
    "cancelListener"     => 0,
    "progressListener"   => 0,
    "form"               => 0,
    "csvImportFile"      => "",
	  "clearRepository"    => 0,
	  "normalize"          => 1,
	};
	bless $formImportCsv, "FglDocumenter::FormImportCSV";
	return $formImportCsv;
}

#  =========================================================================
#  Afecta a propriedade do objecto que define o ficheiro de onde se importa
#  =========================================================================
sub setCsvImportFile
{
	my $obj = shift;
  $obj->{csvImportFile}   = shift;
}

#  =========================================================================
#  Devolve a propriedade do objecto que define o ficheiro de onde se importa
#  =========================================================================
sub getCsvImportFile
{
	my $obj = shift;
  return $obj->{csvImportFile};
}

#  =========================================================================
#  Afecta a propriedade do objecto que define se se pretende ou n�o limpar
#  o reposit�rio
#  =========================================================================
sub setClearRepository
{
	my $obj = shift;
  $obj->{clearRepository}   = shift;
}

#  =========================================================================
#  Retorna a propriedade do objecto que define se se pretende ou n�o limpar
#  o reposit�rio
#  =========================================================================
sub getClearRepository
{
	my $obj = shift;
  return $obj->{clearRepository};
}

#  =========================================================================
#  Afecta a propriedade do objecto que define se se pretende ou n�o 
#  normalizar a informa�ao
#  =========================================================================
sub setNormalize
{
	my $obj = shift;
  $obj->{normalize}   = shift;
}

#  =========================================================================
#  Retorna a propriedade do objecto que define se se pretende ou n�o 
#  normalizar a informa�ao
#  =========================================================================
sub getNormalize
{
	my $obj = shift;
  return $obj->{normalize};
}

#  =========================================================================
#  Afecta a propriedade do objecto que define se se pretende ou n�o 
#  enviar a linha carregada para o log
#  =========================================================================
sub setSendLineToLog
{
	my $obj = shift;
  $obj->{sendLineToLog}   = shift;
}

#  =========================================================================
#  Retorna a propriedade do objecto que define se se pretende ou n�o 
#  enviar a linha carregada para o log
#  =========================================================================
sub getSendLineToLog
{
	my $obj = shift;
  return $obj->{sendLineToLog};
}

sub setLog
{
	my $obj = shift;
  $obj->{log}   = shift;
}

sub setError
{
	my $obj = shift;
  $obj->{err}   = shift;
}

#  =========================================================================
#  Afecta o language handler que esta a ser usado
#  =========================================================================
sub setLh
{
	my $obj = shift;
  $obj->{lh}   = shift;
}

#  =========================================================================
#  Mostra valores e inicia a recep��o de dados no form
#  =========================================================================
sub show
{
	my $obj = shift;

  my $lh = $obj->{lh};
  my $form = $main::mw->Toplevel();
	$obj->{form} = $form;
  
  $form->title(
	  $lh->maketext("Op��es de importa��o")
	);

	my $lblCsvFile = $form->Label(
	  -text => $lh->maketext("File to Import")
	);

	my $txtCsvFile = $form->Entry(-width => 64, 
	  -textvariable => \$obj->{csvImportFile},
		#-state => 'enabled'
  );
  my $csvFileButton =$form->Button(-text => "...", 
	  -command => [ \&chooseCsvFile, $obj ]
	);

	$lblCsvFile->grid($txtCsvFile,$csvFileButton);

	my $cb = $form->Checkbutton(
	  -text => $lh->maketext("Clear Repository"),
	  -variable => \$obj->{clearRepository}
  );
	$cb->grid(-sticky => "nw");

	my $cbNormalize = $form->Checkbutton(
	  -text => $lh->maketext("Normalize"),
	  -variable => \$obj->{normalize}
  );
	$cbNormalize->grid(-sticky => "nw");

	$cbNormalize = $form->Checkbutton(
	  -text => $lh->maketext("Send line to Log"),
	  -variable => \$obj->{sendLineToLog}
  );
	$cbNormalize->grid(-sticky => "nw");

  my $okButton = $form->Button(
	  -text => $lh->maketext("OK"), 
		-command => [ \&ok, $obj ]
	);
	my $cancelButton=$form->Button(
	  -text => $lh->maketext("Cancel"), 
		-command => [ \&cancel, $obj ]
	);
	$okButton->grid($cancelButton);
	$form->Popup();
}

#  =========================================================================
#  @todo Fazer uma rotina num m�dulo de Utils que fa�a isto e devolva o que
#  nome do ficheiro
#  @todo Resolver o problema de a janela ficar atr�s da principal
#  =========================================================================
sub chooseCsvFile
{
	my $obj = shift;
	my $lh = $obj->{lh};
  my $types = [
            [ $lh->maketext('Text'),              '.txt', 'TEXT'],
            [ $lh->maketext('All Files'),        '*',             ],
        ];
  $obj->{csvImportFile} = $obj->{form}->getOpenFile(
	  -title => $lh->maketext("Select CSV File"),
	  -filetypes => $types,
		-initialdir => "/tmp/",
  );
	$obj->{form}->raise();
}

#  =========================================================================
#  Termina a execu��o da janela com a op��o OK
#  Chama o call back registado para OK
#  =========================================================================
sub ok
{
	my $obj = shift;
	$obj->{form}->destroy;
  $obj->{okListener}() if $obj->{okListener};
}


#  =========================================================================
#  Chama o call back registado para Cancel
#  =========================================================================
sub cancel
{
	my $obj = shift;
	$obj->{form}->destroy;
  $obj->{cancelListener}() if $obj->{cancelListener};
}


#  =========================================================================
#  Regista o listener relativo � ac��o OK
#  =========================================================================
sub addOkListener
{
	my $obj = shift;
  $obj->{okListener} = shift;
}

#  =========================================================================
#  Regista o listener relativo � ac��o Cancel
#  =========================================================================
sub addCancelListener
{
	my $obj = shift;
  $obj->{cancelListener} = shift;
}

return 1;
