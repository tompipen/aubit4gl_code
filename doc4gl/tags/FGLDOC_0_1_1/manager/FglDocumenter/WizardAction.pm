#!/usr/bin/perl

#  =========================================================================
#
#  Defini��o gen�rica de uma ac��o de um wizard.
#  O seu objectivo � implementar um comportamento minimo a usar depois 
#  com a "herditariadade" dos objectos do perl
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
#  Abre o form da ac��o especifica
#
#  @param $parentComponent Container no qual o form vai ser desenhado
#
#  @todo - Implementar o m�todo
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
