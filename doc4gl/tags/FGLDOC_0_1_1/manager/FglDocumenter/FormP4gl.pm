#!/usr/bin/perl -w

#  =========================================================================
#
#  Implementa m�todos em Perl/Tk para um form para preenchimento das op��es
#  de importa��o dos dados de ficheiros 4gl (por parsing)
# 
#  As op��es globais est�o guardadas no m�dulo Options.
#
#  Autor : S�rgio Ferreira
#
#  =========================================================================

package FglDocumenter::FormP4gl;

use strict;
use Tk::Dialog;
use Tk::BrowseEntry;
use FglDocumenter::Utils;
use FglDocumenter::BaseClass;
use FglDocumenter::FormDb;

use vars qw(@ISA);
@ISA = ("FglDocumenter::BaseClass");

#  =========================================================================
#  Constructor
#  =========================================================================
sub new
{
	my $pkg = shift;
	my $formImportFgl = $pkg->allocate();

	$formImportFgl->{okListener} =0;
	return $formImportFgl;
}

#  =========================================================================
#  Afecta a propriedade que define se devem ou n�o ser carregados os 
#  coment�rios.
#  =========================================================================
sub setLoadComments
{
  my $obj = shift;
	$obj->{loadComments} = shift;
}

#  =========================================================================
#  Afecta a propriedade que define se deve ou n�o ser afectado o parse.
#  =========================================================================
sub setParseOnly
{
  my $obj = shift;
	$obj->{parseOnly} = shift;
}

#  =========================================================================
#  Afecta a propriedade que define se devemos ou carregar a utiliza��o de
#  tabelas.
#  =========================================================================
sub setLoadTableUsage
{
  my $obj = shift;
	$obj->{loadTableUsage} = shift;
}

#  =========================================================================
#  =========================================================================
sub setLoadParameters
{
  my $obj = shift;
	$obj->{loadParameters} = shift;
}

#  =========================================================================
#  =========================================================================
sub setLoadStrings
{
  my $obj = shift;
	$obj->{loadStrings} = shift;
}

#  =========================================================================
#  =========================================================================
sub setLoadLocalVariables
{
  my $obj = shift;
	$obj->{loadLocalVariables} = shift;
}

#  =========================================================================
#  =========================================================================
sub setImportFglLocation
{
  my $obj = shift;
	$obj->{importFglLocation} = shift;
}

#  =========================================================================
#  =========================================================================
sub setLoadFilesRecursive
{
  my $obj = shift;
	$obj->{loadFilesRecursive} = shift;
}

#  =========================================================================
#  =========================================================================
sub getPackage
{
  my $obj = shift;
	return $obj->{package};
}

#  =========================================================================
#  =========================================================================
sub getLoadComments
{
  my $obj = shift;
	return $obj->{loadComments};
}

#  =========================================================================
#  =========================================================================
sub getParseOnly
{
  my $obj = shift;
	return $obj->{parseOnly};
}

#  =========================================================================
#  =========================================================================
sub getLoadTableUsage
{
  my $obj = shift;
	return $obj->{loadTableUsage};
}

#  =========================================================================
#  =========================================================================
sub getLoadParameters
{
  my $obj = shift;
	return $obj->{loadParameters};
}

#  =========================================================================
#  =========================================================================
sub getLoadStrings
{
  my $obj = shift;
	return $obj->{loadStrings};
}

#  =========================================================================
#  @return The flag that indicates the parser to load the local variables
#  =========================================================================
sub getLoadLocalVariables
{
  my $obj = shift;
	return $obj->{loadLocalVariables};
}

#  =========================================================================
#  @return The directory used for 4gl import
#  =========================================================================
sub getImportFglLocation
{
  my $obj = shift;
	return $obj->{importFglLocation};
}

#  =========================================================================
#  =========================================================================
sub getLoadFilesRecursive
{
  my $obj = shift;
	return $obj->{loadFilesRecursive};
}

#  =========================================================================
#  @return the module list found and selected.
#  =========================================================================
sub getModuleList
{
  my $obj = shift;
	return $obj->{modules};
}

#  =========================================================================
#  @return The directory list for each source file to load to repository.
#  =========================================================================
sub getDirectoryList
{
  my $obj = shift;
	return $obj->{directoryList};
}


#  =========================================================================
#  Mostra valores e inicia a recep��o de dados no form
#  =========================================================================
sub show
{
  my $obj = shift;

  my $lh = $obj->{lh};

	if ( $obj->selectPackages() == 1 )
	{
	  return 0;
	}

  $obj->{form} = $main::mw->Toplevel();
  my $form = $obj->{form};
  
  $form->title(
	  $lh->maketext("4gl source import options")
	);

	my $lblPackage = $form->Label(
	  -text => $lh->maketext("Package")
	);

	my $lbPackages = $form->BrowseEntry(-variable => \$obj->{package});
	$lbPackages->insert('end',$obj->{packages});
	#$lbPackages->configure(-width => 62);
	#$lbPackages->configure(-height => 1);
	#$lbPackages->configure(-selectmode => "multiple");
	#$lbPackages->configure(-takefocus  => 1);
	$lblPackage->grid(-sticky => "nw", -row => 0,-column => 0);
	$lbPackages->grid(-sticky => "nw", -row => 0,-column => 1);
	#$lbPackages->bind("<FocusOut>", sub { print "FOCUS OUT"; });

	#@bindings = $lbPackages->bind();


	my $lblLocation = $form->Label(
	  -text => $lh->maketext("Location (Directory)")
	);
	my $txtLocation = $form->Entry(-width => 64, 
	  -textvariable => \$obj->{importFglLocation},
		-state => 'disabled'
  );
  my $locationButton = $form->Button(-text => "...", 
	  -command => [ \&chooseLocation, $obj ]
	);
	$lblLocation->grid($txtLocation,$locationButton);
	$lblLocation->grid(-sticky => "w", -row => 1,-column => 0);
	$txtLocation->grid(-row => 1,-column => 1);
	$locationButton->grid(-row => 1,-column => 2);


	my $lblModules = $form->Label(
	  -text => $lh->maketext("Modules")
	);
	my $modulesRef = $obj->getModules($obj->{importFglLocation});
	my @modules = @$modulesRef;
	$obj->{modules} = \@modules;
	my $lbModules = $form->Scrolled("Listbox", -scrollbars => "osoe");
	$obj->{lbModules} = $lbModules;
	$lbModules->insert('end',@modules);
	$lbModules->configure(-width => 62);
	$lbModules->configure(height => 1);
	$lblModules->grid(-sticky => "nw", -row => 2,-column => 0);
	$lbModules->grid(-row => 2,-column => 1);
	# @todo Janela para Selec��o de m�dulos

	my $cbLoadComments = $form->Checkbutton(
	  -text => $lh->maketext("Load comments"),
	  -variable => \$obj->{loadComments}
  );
	$cbLoadComments->grid(-sticky => "nw");

	my $cbParseOnly = $form->Checkbutton(
	  -text => $lh->maketext("Parse Only"),
	  -variable => \$obj->{parseOnly}
  );
	$cbParseOnly->grid(-sticky => "nw");


	my $lblRepository = $form->Label(
	  -text => $lh->maketext("Repository")
	);
	$obj->{fgldocRepository} = 
	  $obj->{connection}->getUrl()
	;
	my $txtRepository = $form->Entry(-width => 64, 
	  -textvariable => \$obj->{fgldocRepository},
		-state => 'disabled'
  );
  my $fgldocButton = $form->Button(-text => "...", 
	  -command => [ \&configureRepository, $obj ]
  );
	$lblRepository->grid($txtRepository,$fgldocButton);
	$lblRepository->grid(-sticky => "w", -row => 5,-column => 0);
	$txtRepository->grid(-row => 5,-column => 1);
	$fgldocButton->grid(-row => 5,-column => 2);


	my $cbLoadTableUsage = $form->Checkbutton(
	  -text => $lh->maketext("Load Table Usage"),
	  -variable => \$obj->{loadTableusage}
  );
	$cbLoadTableUsage->grid(-sticky => "nw");

	my $cbLoadParameters = $form->Checkbutton(
	  -text => $lh->maketext("Load Parameters"),
	  -variable => \$obj->{loadParameters}
  );
	$cbLoadParameters->grid(-sticky => "nw");

	my $cbLoadStrings = $form->Checkbutton(
	  -text => $lh->maketext("Load Strings"),
	  -variable => \$obj->{loadStrings}
  );
	$cbLoadStrings->grid(-sticky => "nw");

	my $cbLoadLocalVariables = $form->Checkbutton(
	  -text => $lh->maketext("Load Local Variables"),
	  -variable => \$obj->{loadLocalVariables}
  );
	$cbLoadLocalVariables->grid(-sticky => "nw");

	my $cbRecursive = $form->Checkbutton(
	  -text => $lh->maketext("Recursive"),
	  -variable => \$obj->{loadFilesRecursive}
  );
	$cbRecursive->grid(-sticky => "nw");

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
	return 1;
}

#  =========================================================================
#  Abre o form para que o utilizador possa efcetuar a configura��o do 
#  reposit�rio
#  =========================================================================
sub configureRepository
{
	my $obj = shift;

	my $objFormDb = new FglDocumenter::FormDb();

	$objFormDb->setError($obj->{err});
	$objFormDb->setLanguageHandler($obj->{lh});
	$objFormDb->addOkListener(
	  \&repositoryEditListener
  );
	$objFormDb->showDbForm(
		$obj->{connection}
  );
}

#  =========================================================================
#  Listener para ser executado como callback quando o utilizador carrega 
#  no bot�o de OK do form de configura��o de acesso a BD
#  =========================================================================
sub repositoryEditListener
{
	my $obj = shift;
	$obj->{fgldocRepository} = 
	  $obj->{connection}->getUrl()
	;
}



#  =========================================================================
#  Trata de efectuar a selec��o de packages validando se tudo correu bem
#    @return 1 - Erro a seleccionar packages, 0 se tudo bem.
#  =========================================================================
sub selectPackages
{
	my $obj = shift;
	$obj->{err}->clearErrorFlag();
	$obj->{packages} = $obj->{repositoryUtil}->selectPackages();
	if ( $obj->{err}->isErrorFlag() == 1 )
	{
	  return 1;
	}
	return 0;
}

#  =========================================================================
#  Termina a execu��o da janela com a op��o OK
#  Chama o call back registado para OK
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

#  =========================================================================
#  Open a file chooser so the user can choose the directory from where to
#  load the information.
#  =========================================================================
sub chooseLocation
{
	my $obj = shift;
	my $FileSelect = $obj->{form}->FileSelect();
	$FileSelect->configure(-verify => ["-d"]);
	$obj->{importFglLocation} = $FileSelect->Show;
	my $modulesRef = $obj->getModules($obj->{importFglLocation});
	my @modules = @$modulesRef;
	$obj->{modules} = \@modules;
	$obj->{lbModules}->delete(0,$obj->{lbModules}->size);
	$obj->{lbModules}->insert('end',@modules);
	$obj->{form}->raise();
}

#  =========================================================================
#  Obtem o nome de todos os m�dulos do direct�rio enviado como parametro
#    @todo - Inserir gest�o de erros em vez de die
#  =========================================================================
sub getModules
{
	my $obj = shift;
	my $wantedDir = shift;
  my $currentDir = POSIX::getcwd();
	chdir $wantedDir || die "Cant change to $wantedDir : $!\n ";
  my $moduleDir = POSIX::getcwd();
	my @moduleList = ();
	my @directoryList;
  my $file;
	foreach $file (<*>)
	{
		if ( $obj->isFglFile($file) )
		{
		  chomp($file);
	    push(@directoryList,$moduleDir);
	    push(@moduleList,$file);
		}
		elsif ( $obj->{loadFilesRecursive} == 1 )
		{
		  if ( -d $file )
		  {
				my $directory = "$file";
				#$directory = "$wantedDir/$file";
		    my $refSubDirModules = $obj->getModules($directory);
		    my @subDirModules = @$refSubDirModules;
	      @moduleList    = (@moduleList,@subDirModules);
		  }
		}
	}
  chdir $currentDir;
	$obj->{directoryList} = \@directoryList;
	return \@moduleList;
}


#  =========================================================================
#  Testa se um ficheiro eh um ficheiro de 4gl
#  @return A code that tells if it is a 4gl file.
#    - 0 : Its not a fgl file.
#    - 1 : its a fgl file.
#  =========================================================================
sub isFglFile
{
	my $obj = shift;
	my $file = shift;

  if ( $file =~ /.*\.4gl$/ )
	{
	  if ( -f $file )
	  {
	    return 1;
    }
	}
	return 0;
}
1;

