#!/usr/bin/perl -w

#  =========================================================================
#
#  Implementa métodos em Perl/Tk para um form que permite efectuar as
#  configurações das opções globais.
# 
#  As opções globais estão guardadas no módulo Options.
#
#  @todo : Passar a objecto
#  @todo : Meter strict a funcionar
#  @todo : Localizar mensagens
#
#  Autor : Sérgio Ferreira
#
#  =========================================================================

use strict;

package FglDocumenter::FormOptions;

use Tk::ROText;
use FglDocumenter::FormDb;
use FglDocumenter::BaseClass;

use vars qw(@ISA);
@ISA = ("FglDocumenter::BaseClass");

my $objGlob;

#  =========================================================================
#  Constructor
#  =========================================================================
sub new
{
	my $pkg = shift;
	my $formOptions = $pkg->allocate();

	$formOptions->{okListener}       = 0;
	$formOptions->{form}             = 0;
	$formOptions->{fgldocRepository} = 0;
	return $formOptions;
}

#  =========================================================================
#  Mostra valores e inicia a recepção de dados no form
#  =========================================================================
sub show
{
	my $obj = shift;

  $obj->{form} = MainWindow->new;
	my $form = $obj->{form};
  my $lh = $obj->{lh};
  
  $form->title(
	  $lh->maketext("Options configuration")
	);

	# Conexão à Base de dados para repositório 4gl
	my $lbl4doc = $form->Label(
	  -text => $lh->maketext("4gl Doc Repository")
	);
	$obj->{fgldocRepository} = $FglDocumenter::Options::p4glRepository->getUrl();
	my $txt4doc = $form->Entry(-width => 40, 
	  -textvariable => \$obj->{fgldocRepository},
		-state => 'disabled'
  );
  my $fgldocButton = $form->Button(-text => "...", 
	  -command => [ \&fgldocRep, $obj ]
	);
	$lbl4doc->grid($txt4doc,$fgldocButton);


	# Nome de ficheiro para importação de CSV
	$obj->{csvImportFile} = $FglDocumenter::Options::csvImportFile;
	my $lblFlatFile = $form->Label(-text => "Flat file (CSV)");
	$obj->{flatFileRepository} = "Flat File";
	my $txtFlatFile = $form->Entry(
	  -width => 20, 
	  -textvariable => \$obj->{csvImportFile},
		-state => 'disabled'
  );
  my $flatFileButton = $form->Button(-text => "...", 
	  -command => [ \&selectCSVFile, $obj ]
	);
	$lblFlatFile->grid($txtFlatFile,$flatFileButton);

	$obj->{xmlImportFile} = $FglDocumenter::Options::xmlImportFile;
	my $lblFileXml = $form->Label(
	  -text => $lh->maketext("XML file")
	);
	$obj->{flatFileRepository} = "XML File";
	my $txtFileXml = $form->Entry(-width => 20, 
	  -textvariable => \$obj->{xmlImportFile},
		-state => 'disabled'
  );
  my $xmlFileButton = $form->Button(-text => "...", 
	  -command => [ \&selectXMLFile, $obj ]
	);
	$lblFileXml->grid($txtFileXml,$xmlFileButton);


	my $csvExportFile = $FglDocumenter::Options::csvExportFile;
	my $lblCsvExportFile = $form->Label(
	  -text => "CSV Export File"
	);
	my $txtCsvExportFile = $form->Entry(-width => 20, 
	  -textvariable => \$obj->{csvExportFile},
		-state => 'disabled'
  );
  my $csvExportFileButton = $form->Button(
	  -text => "...", -command => [ \&selectCSVExportFile, $obj ]
  );
	$lblCsvExportFile->grid($txtCsvExportFile,$csvExportFileButton);

	$obj->{xmlExportFile} = $FglDocumenter::Options::xmlExportFile;
	my $lblExportFileXml = $form->Label(
	  -text => $lh->maketext("XML file")
	);
	my $txtExportFileXml = $form->Entry(-width => 20, 
	  -textvariable => \$obj->{xmlExportFile},
		-state => 'disabled'
  );
  my $xmlExportFileButton = $form->Button(
	  -text => "...", 
	  -command => [ \&selectXMLExportFile, $obj ]
  );
	$lblExportFileXml->grid($txtExportFileXml,$xmlExportFileButton);

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
#  Abre o form de configuração do acesso ao repositório de p4gl e permite 
#  a alteração dos respectivos dados
#    @todo - Resolver os probleas de variáveis curr
#  =========================================================================
sub fgldocRep
{
	my $obj = shift;
	my $formDbObject = new FglDocumenter::FormDb();
	$formDbObject->addOkListener(
	  \&repositoryEditListener
  );
	$formDbObject->setLanguageHandler($obj->{lh});
	$obj->{currRepository} = $FglDocumenter::Options::p4glRepository;
	$obj->{currRepositoryUrl} = $obj->{fgldocRepository};
	$formDbObject->showDbForm(
	  $FglDocumenter::Options::p4glRepository
  );
}

#  =========================================================================
#  Listener para ser execuutado como callback quando o utilizador carrega 
#  no botão de OK do form
#  =========================================================================
sub repositoryEditListener
{
	my $obj = shift;
	$obj->{currRepositoryUrl} = $obj->{currRepository}->getUrl();
	$obj->{fgldocRepository}  = $FglDocumenter::Options::p4glRepository->getUrl();
}

#  =========================================================================
#  Abre um file chooser para o utilizador escolher o ficheiro com CSV
#  =========================================================================
sub selectCSVFile
{
	my $obj = shift;
  my $types = [
            ['Text',              '.txt', 'TEXT'],
            ['All Files',        '*',             ],
        ];
  $obj->{csvImportFile} = $obj->{form}->getOpenFile(
	  -title => $obj->{lh}->maketext("Select CSV File"),
	  -filetypes => $types
  );
}

#  =========================================================================
#  Abre um file chooser para o utilizador escolher o ficheiro de XML
#  =========================================================================
sub selectXMLFile
{
	my $obj = shift;
  my $types = [
            ['Text',              '.xml', 'XML'],
            ['All Files',        '*',             ],
        ];
  $obj->{xmlImportFile} = $obj->{form}->getOpenFile(
	  -title => $obj->{lh}->maketext("Select XML File"),
	  -filetypes => $types
  );
}

#  =========================================================================
#  Abre um file chooser para o utilizador escolher o ficheiro com CSV para
#  onde vai exportar
#  =========================================================================
sub selectCSVFile
{
	my $obj = shift;
  my $types = [
            ['Text',              '.txt', 'TEXT'],
            ['All Files',        '*',             ],
        ];
  $obj->{csvExportFile} = $obj->{form}->getSaveFile(
	  -title => $obj->{lh}->maketext("Select CSV File"),
	  -filetypes => $types
  );
}

#  =========================================================================
#  Abre um file chooser para o utilizador escolher o ficheiro de XML onde
#  irá gravar a informação
#  =========================================================================
sub selectXMLExportFile
{
	my $obj = shift;
  my $types = [
            ['Text',              '.xml', 'XML'],
            ['All Files',        '*',             ],
        ];
  $obj->{xmlExportFile} = $obj->{form}->getSaveFile(
	  -title => $obj->{lh}->maketext("Select XML File"),
	  -filetypes => $types
  );
}

#  =========================================================================
#  Termina a execução da janela com a opção OK
#  Chama o call back registado para OK
#  =========================================================================
sub ok
{
	my $obj = shift;
	$obj->{form}->destroy;
	$FglDocumenter::Options::csvImportFile = $obj->{csvImportFile};
	$FglDocumenter::Options::xmlImportFile = $obj->{xmlImportFile};
	$FglDocumenter::Options::csvExportFile = $obj->{csvExportFile};
	$FglDocumenter::Options::xmlExportFile = $obj->{xmlExportFile};
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


1;
