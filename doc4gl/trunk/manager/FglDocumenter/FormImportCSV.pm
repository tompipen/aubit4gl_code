#!/usr/bin/perl

#  =========================================================================
#
#  Implementa m�todos em Perl/Tk para um form que permite efectuar as
#  da importa��o de um ficheiro CSV
# 
#  As op��es globais est�o guardadas no m�dulo Options.
#
#  @todo - Passar este m�dulo a objecto
#
#  Autor : S�rgio Ferreira
#
#  =========================================================================

package FglDocumenter::FormImportCSV;

use Tk::Dialog;

#  =========================================================================
#  Mostra valores e inicia a recep��o de dados no form
#  =========================================================================
sub show
{
  $csvImportFile   = $FglDocumenter::Options::csvImportFile;	
	$clearRepository = $FglDocumenter::Options::clearRepositoryOnImportCSV;
	$normalize       = $FglDocumenter::Options::normalize;
	$sendLineToLog   = $FglDocumenter::Options::sendLineToLog;

  $form = $main::mw->Toplevel();
  
  $form->title("Op��es de importa��o");
  $height = 650;
  $width = 200;
	FglDocumenter::Utils::setWindowAtCenter($form,$width,$height);

	$lblCsvFile = $form->Label(-text => "File to Import");

	$txtCsvFile = $form->Entry(-width => 64, 
	  -textvariable => \$csvImportFile,
		#-state => 'enabled'
  );
  $csvFileButton = $form->Button(-text => "...", -command => \&chooseCsvFile);
	$lblCsvFile->grid($txtCsvFile,$csvFileButton);

	$cb = $form->Checkbutton(-text => "Clear Repository",
	  -variable => \$clearRepository
  );
	$cb->grid(-sticky => "nw");

	# @todo A vari�vel n�o est� bem ligada � check box
	$cbNormalize = $form->Checkbutton(-text => "Normalize",
	  -variable => \$normalize
  );
	$cbNormalize->grid(-sticky => "nw");

	$cbNormalize = $form->Checkbutton(-text => "Send line to Log",
	  -variable => \$sendLineToLog
  );
	$cbNormalize->grid(-sticky => "nw");

  $okButton = $form->Button(-text => "OK", -command => \&ok);
	$cancelButton=$form->Button(-text => "Cancel", -command => \&cancel);
	$okButton->grid($cancelButton);
}

#  =========================================================================
#  @todo Fazer uma rotina num m�dulo de Utils que fa�a isto e devolva o que
#  nome do ficheiro
#  @todo Resolver o problema de a janela ficar atr�s da principal
#  =========================================================================
sub chooseCsvFile
{
  my $types = [
            ['Text',              '.txt', 'TEXT'],
            ['All Files',        '*',             ],
        ];
  $csvImportFile = $form->getOpenFile(
	  -title => "Seleccionar ficheiro CSV",
	  -filetypes => $types
  );
}

#  =========================================================================
#  Termina a execu��o da janela com a op��o OK
#  Chama o call back registado para OK
#  =========================================================================
sub ok
{
	$form->destroy;
	$FglDocumenter::Options::csvImportFile = $csvImportFile;
	$FglDocumenter::Options::clearRepositoryOnImportCSV = $clearRepository;
	$FglDocumenter::Options::normalize     = $normalize;
	$FglDocumenter::Options::sendLineToLog = $sendLineToLog;
  \&$okListener() if $okListener ;
}


#  =========================================================================
#  Chama o call back registado para Cancel
#  =========================================================================
sub cancel
{
	$form->destroy;
  \&$cancelListener() if $cancelListener;
}


#  =========================================================================
#  Regista o listener relativo � ac��o OK
#  =========================================================================
sub addOkListener
{
  $okListener = $_[0];
}

#  =========================================================================
#  Regista o listener relativo � ac��o Cancel
#  =========================================================================
sub addCancelListener
{
  $cancelListener = $_[0];
}



return true;
