#!/usr/bin/perl

#  =========================================================================
#
#  Implements methods in Perl/Tk for a for to allow configuration of
#  global options.
#
#  Implementa métodos em Perl/Tk para um form que permite efectuar as
#  configurações das opções globais.
# 
#  As opções globais estão guardadas no módulo Options.
#
#  Autor : Sérgio Ferreira
#
#  =========================================================================

package FglDocumenter::FormOptions;

use Tk::ROText;

#  =========================================================================
#  Mostra valores e inicia a recepção de dados no form
#  =========================================================================
sub show
{
  $form = MainWindow->new;
  
  if ( 1 ) {
	  $form->title("Configuration of options");
    } else {
	  $form->title("Configuração de opções");
    }

  $height = 500;
  $width = 250;
	FglDocumenter::Utils::setWindowAtCenter($form,$width,$height);

	# Conexão à Base de dados para repositório 4gl
	$lbl4doc = $form->Label(-text => "4gl Doc Repository");
	$fgldocRepository = $FglDocumenter::Options::p4glRepository->getUrl();
	$txt4doc = $form->Entry(-width => 40, 
	  -textvariable => \$fgldocRepository,
		-state => 'disabled'
  );
  $fgldocButton = $form->Button(-text => "...", -command => \&fgldocRep);
	$lbl4doc->grid($txt4doc,$fgldocButton);

	# Conexão à Base de dados de syspgm
	$lblSyspgm = $form->Label(-text => "Syspgm 4gl Repository");
	$syspgmRepository = $FglDocumenter::Options::syspgmRepository->getUrl();
	$txtSyspgm = $form->Entry(-width => 40, 
	  -textvariable => \$syspgmRepository,
		-state => 'disabled'
  );
  $syspgmButton = $form->Button(-text => "...", -command => \&syspgmRep);
	$lblSyspgm->grid($txtSyspgm,$syspgmButton);

	# Nome de ficheiro para importação de CSV
	$csvImportFile = $FglDocumenter::Options::csvImportFile;
	$lblFlatFile = $form->Label(-text => "Flat file (CSV)");
	$flatFileRepository = "Flat File";
	$txtFlatFile = $form->Entry(-width => 20, 
	  -textvariable => \$csvImportFile,
		-state => 'disabled'
  );
  $flatFileButton = $form->Button(-text => "...", -command => \&selectCSVFile);
	$lblFlatFile->grid($txtFlatFile,$flatFileButton);

	$xmlImportFile = $FglDocumenter::Options::xmlImportFile;
	$lblFileXml = $form->Label(-text => "XML file");
	$flatFileRepository = "XML File";
	$txtFileXml = $form->Entry(-width => 20, 
	  -textvariable => \$xmlImportFile,
		-state => 'disabled'
  );
  $xmlFileButton = $form->Button(-text => "...", -command => \&selectXMLFile);
	$lblFileXml->grid($txtFileXml,$xmlFileButton);


	$csvExportFile = $FglDocumenter::Options::csvExportFile;
	$lblCsvExportFile = $form->Label(-text => "CSV Export File");
	$txtCsvExportFile = $form->Entry(-width => 20, 
	  -textvariable => \$csvExportFile,
		-state => 'disabled'
  );
  $csvExportFileButton = $form->Button(
	  -text => "...", -command => \&selectCSVExportFile
  );
	$lblCsvExportFile->grid($txtCsvExportFile,$csvExportFileButton);

	$xmlExportFile = $FglDocumenter::Options::xmlExportFile;
	$lblExportFileXml = $form->Label(-text => "XML file");
	$txtExportFileXml = $form->Entry(-width => 20, 
	  -textvariable => \$xmlExportFile,
		-state => 'disabled'
  );
  $xmlExportFileButton = $form->Button(
	  -text => "...", -command => \&selectXMLExportFile
  );
	$lblExportFileXml->grid($txtExportFileXml,$xmlExportFileButton);

  $okButton = $form->Button(-text => "OK", -command => \&ok);
	$cancelButton=$form->Button(-text => "Cancel", -command => \&cancel);
	$okButton->grid($cancelButton);
}

#  =========================================================================
#  Abre o form de configuração do acesso ao repositório de p4gl e permite 
#  a alteração dos respectivos dados
#    @todo - Resolver os probleas de variáveis curr
#  =========================================================================
sub fgldocRep
{
	FglDocumenter::FormDb::addOkListener(
	  \&repositoryEditListener
  );
	$currRepository = $FglDocumenter::Options::p4glRepository;
	$currRepositoryUrl = $fgldocRepository;
	FglDocumenter::FormDb::showDbForm(
	  $FglDocumenter::Options::p4glRepository
  );
}

#  =========================================================================
#  Abre o form relativo ao repositório de syspgm e permite a sua alteração
#  =========================================================================
sub syspgmRep
{
	FglDocumenter::FormDb::addOkListener(\&repositoryEditListener);
	$currRepository = $FglDocumenter::Options::syspgmRepository;
	$currRepositoryUrl = $syspgmRepository;
	FglDocumenter::FormDb::showDbForm($FglDocumenter::Options::p4glRepository);
}

#  =========================================================================
#  Listener para ser execuutado como callback quando o utilizador carrega 
#  no botão de OK do form
#  =========================================================================
sub repositoryEditListener
{
	$currRepositoryUrl = $currRepository->getUrl();
	$fgldocRepository  = $FglDocumenter::Options::p4glRepository->getUrl();
}

#  =========================================================================
#  Abre um file chooser para o utilizador escolher o ficheiro com CSV
#  =========================================================================
sub selectCSVFile
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
#  Abre um file chooser para o utilizador escolher o ficheiro de XML
#  =========================================================================
sub selectXMLFile
{
  my $types = [
            ['Text',              '.xml', 'XML'],
            ['All Files',        '*',             ],
        ];
  $xmlImportFile = $form->getOpenFile(
	  -title => "Seleccionar ficheiro XML",
	  -filetypes => $types
  );
}

#  =========================================================================
#  Abre um file chooser para o utilizador escolher o ficheiro com CSV para
#  onde vai exportar
#  =========================================================================
sub selectCSVFile
{
  my $types = [
            ['Text',              '.txt', 'TEXT'],
            ['All Files',        '*',             ],
        ];
  $csvExportFile = $form->getSaveFile(
	  -title => "Seleccionar ficheiro CSV",
	  -filetypes => $types
  );
}

#  =========================================================================
#  Abre um file chooser para o utilizador escolher o ficheiro de XML onde
#  irá gravar a informação
#  =========================================================================
sub selectXMLExportFile
{
  my $types = [
            ['Text',              '.xml', 'XML'],
            ['All Files',        '*',             ],
        ];
  $xmlExportFile = $form->getSaveFile(
	  -title => "Seleccionar ficheiro XML",
	  -filetypes => $types
  );
}

#  =========================================================================
#  Termina a execução da janela com a opção OK
#  Chama o call back registado para OK
#  =========================================================================
sub ok
{
	$form->destroy;
	$FglDocumenter::Options::csvImportFile = $csvImportFile;
	$FglDocumenter::Options::xmlImportFile = $xmlImportFile;
	$FglDocumenter::Options::csvExportFile = $csvExportFile;
	$FglDocumenter::Options::xmlExportFile = $xmlExportFile;
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
#  Regista o listener relativo à acção OK
#  =========================================================================
sub addOkListener
{
  $okListener = $_[0];
}

#  =========================================================================
#  Regista o listener relativo à acção Cancel
#  =========================================================================
sub addCancelListener
{
  $cancelListener = $_[0];
}

return true;
