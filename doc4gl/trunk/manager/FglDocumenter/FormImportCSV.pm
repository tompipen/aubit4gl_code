#!/usr/bin/perl -w

#  =========================================================================
#
#  Implementa métodos em Perl/Tk para um form que permite efectuar as
#  da importação de um ficheiro CSV
# 
#  As opções globais estão guardadas no módulo Options.
#
#  @todo - Inserir mais uma opção (Inserção de processos indefinidos)
#
#  Autor : Sérgio Ferreira
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
#  Afecta a propriedade do objecto que define se se pretende ou não limpar
#  o repositório
#  =========================================================================
sub setClearRepository
{
	my $obj = shift;
  $obj->{clearRepository}   = shift;
}

#  =========================================================================
#  Retorna a propriedade do objecto que define se se pretende ou não limpar
#  o repositório
#  =========================================================================
sub getClearRepository
{
	my $obj = shift;
  return $obj->{clearRepository};
}

#  =========================================================================
#  Afecta a propriedade do objecto que define se se pretende ou não 
#  normalizar a informaçao
#  =========================================================================
sub setNormalize
{
	my $obj = shift;
  $obj->{normalize}   = shift;
}

#  =========================================================================
#  Retorna a propriedade do objecto que define se se pretende ou não 
#  normalizar a informaçao
#  =========================================================================
sub getNormalize
{
	my $obj = shift;
  return $obj->{normalize};
}

#  =========================================================================
#  Afecta a propriedade do objecto que define se se pretende ou não 
#  enviar a linha carregada para o log
#  =========================================================================
sub setSendLineToLog
{
	my $obj = shift;
  $obj->{sendLineToLog}   = shift;
}

#  =========================================================================
#  Retorna a propriedade do objecto que define se se pretende ou não 
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
#  Mostra valores e inicia a recepção de dados no form
#  =========================================================================
sub show
{
	my $obj = shift;

  my $lh = $obj->{lh};
  my $form = $main::mw->Toplevel();
	$obj->{form} = $form;
  
  $form->title(
	  $lh->maketext("Opções de importação")
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
#  @todo Fazer uma rotina num módulo de Utils que faça isto e devolva o que
#  nome do ficheiro
#  @todo Resolver o problema de a janela ficar atrás da principal
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
#  Termina a execução da janela com a opção OK
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
#  Regista o listener relativo à acção OK
#  =========================================================================
sub addOkListener
{
	my $obj = shift;
  $obj->{okListener} = shift;
}

#  =========================================================================
#  Regista o listener relativo à acção Cancel
#  =========================================================================
sub addCancelListener
{
	my $obj = shift;
  $obj->{cancelListener} = shift;
}

return 1;
