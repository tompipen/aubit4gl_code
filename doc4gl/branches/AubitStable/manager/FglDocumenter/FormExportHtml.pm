#!/usr/bin/perl

#  =========================================================================
#
#  Implementa métodos em Perl/Tk para um form que permite efectuar as
#  da exportação dos dados do repositório para uma hierarquia em html.
# 
#  As opções globais estão guardadas no módulo Options.
#
#  @todo : Incluir mensagens no L10N
#
#  $Author: saferreira $
#  $Id: FormExportHtml.pm,v 1.1 2003-01-06 20:07:41 saferreira Exp $
#
#  =========================================================================

use strict;
use Tk::Dialog;

package FglDocumenter::FormExportHtml;

#  =========================================================================
#  Constructor
#  =========================================================================
sub new
{
  my ($formExportHtml) = @_;

	my $formExportHtml = {
    "err"                => 0,
	  "log"                => 0,
    "progressListener"   => 0,
    "form"           => 0,
    "exportDir"      => "",
    "okListener"     => 0,
    "cancelListener" => 0,
    "lh"             => 0,
	};
	bless $formExportHtml, "FglDocumenter::FormExportHtml";
	return $formExportHtml;
}

#  ===========================================================================
#  Assign the object of error management used
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

#  ===========================================================================
#  Afecta o pointer ( referencia ) para a rotina que mostra o progresso
#  ou evolução do processo
#  ===========================================================================
sub addProgressListener
{
  my $obj = shift;
  $obj->{progressListener} = shift;
}

#  =========================================================================
#  Assign the object with default source directory
#  =========================================================================
sub setExportDir()
{
  my $obj = shift;
	$obj->{exportDir} = shift;
}

#  =========================================================================
#  =========================================================================
sub getExportDir
{
  my $obj = shift;
	return $obj->{exportDir};
}

#  =========================================================================
#  Assign the object language handler
#  =========================================================================
sub setLanguageHandler()
{
  my $obj = shift;
	$obj->{lh} = shift;
}

#  =========================================================================
#  Mostra valores e inicia a recepção de dados no form
#  =========================================================================
sub show
{
  my $obj = shift;
  $obj->{form} = $main::mw->Toplevel();
  
	my $lh = $obj->{lh};
  $obj->{form}->title(
    $lh->maketext("Html source export options")
	);

	my $lblDirectory = $obj->{form}->Label(
	  -text => $lh->maketext("Location")
	);
	my $txtDirectory = $obj->{form}->Entry(
    -width => 64, 
	  -textvariable => \$obj->{exportDir},
		-state => 'normal'
  );
  my $directoryButton = $obj->{form}->Button(-text => "...", 
	  -command => [ \&chooseDirectory, $obj ]
  );
	$lblDirectory->grid($txtDirectory,$directoryButton);
	$lblDirectory->grid(-sticky => "nw", -row => 1,-column => 0);
	$txtDirectory->grid(-row => 1,-column => 1);
	$directoryButton->grid(-row => 1,-column => 2);

	my $createDirectory;
	my $cb = $obj->{form}->Checkbutton(-text => "Create directory",
	  -variable => \$createDirectory
  );
	$cb->grid(-sticky => "w", -row => 4,-column => 0);

  my $okButton = $obj->{form}->Button(-text => "OK", 
	  -command => [ \&ok, $obj ]
  );
	my $cancelButton=$obj->{form}->Button(
	  -text => "Cancel",
	  -command => [ \&cancel, $obj ]
  );
	$okButton->grid($cancelButton);
	$obj->{form}->Popup();
}


#  =========================================================================
#  Termina a execução da janela com a opção OK
#  Chama o call back registado para OK
#   @todo Nao devia trabalhar directamente com options
#  =========================================================================
sub ok
{
  my $obj = shift;
	$obj->{form}->destroy;
  $obj->{okListener}() if $obj->{okListener} ;
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
  $obj->{okListener} = $_[0];
}

#  =========================================================================
#  Regista o listener relativo à acção Cancel
#  =========================================================================
sub addCancelListener
{
  my $obj = shift;
  $obj->{cancelListener} = $_[0];
}

#  =========================================================================
#  Abre um file chooser que permite escolher um directorio
#  =========================================================================
sub chooseDirectory
{
  my $obj = shift;
	my $fileSelect = $obj->{form}->FileSelect(
    -directory => $obj->{exportDir}
  );
	$fileSelect->configure(-verify => ["-d"]);
	$obj->{exportDir} = $fileSelect->Show;
	$obj->{form}->raise();
}

return 1;
