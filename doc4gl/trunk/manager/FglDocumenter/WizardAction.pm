#!/usr/bin/perl

#  =========================================================================
#
#  Definição genérica de uma acção de um wizard.
#  O seu objectivo é implementar um comportamento minimo a usar depois 
#  com a "herditariadade" dos objectos do perl
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

package FglDocumenter::WizardAction;

use Tk;

#  =========================================================================
#  Construtora
#  =========================================================================
sub new
{	
  my ($pkg,) = @_;

	my $wizard = {
	  "xpto"  => 0
	};
  bless $wizard, "FglDocumenter::WizardAction";
	return $wizard;
}

#  =========================================================================
#  Abre o form da acção especifica
#
#  @param $parentComponent Container no qual o form vai ser desenhado
#
#  @todo - Implementar o método
#  =========================================================================
sub openForm
{
  my $obj   = shift;
	my $frame = shift;
	$lblCsvFile = $frame->Label(-text => "File to Import");

	$txtCsvFile = $frame->Entry(-width => 64, 
	  -textvariable => \$csvImportFile,
		#-state => 'enabled'
  );
  $csvFileButton = $frame->Button(-text => "...", -command => \&chooseCsvFile);
	$lblCsvFile->pack;
	$txtCsvFile->pack;
	$csvFileButton->pack;
	#$lblCsvFile->grid($txtCsvFile,$csvFileButton);
}

return true;
