#!/usr/bin/perl

#  =========================================================================
#
#  Implementa métodos em Perl/Tk para um form para preenchimento das opções
#  de importação dos dados de ficheiros 4gl (por parsing)
# 
#  As opções globais estão guardadas no módulo Options.
#
#  @todo Passar a objecto
#
#  Autor : Sérgio Ferreira
#
#  =========================================================================

package FglDocumenter::FormP4gl;

use Tk::Dialog;
use Tk::BrowseEntry;
use FglDocumenter::Utils;

#  =========================================================================
#  Mostra valores e inicia a recepção de dados no form
#  =========================================================================
sub show
{

	$loadComments       = $FglDocumenter::Options::loadComments;
	$parseOnly          = $FglDocumenter::Options::parseOnly;
	$loadTableusage     = $FglDocumenter::Options::loadTableUsage;
	$loadParameters     = $FglDocumenter::Options::loadParameters;
	$loadStrings        = $FglDocumenter::Options::loadStrings;
	$loadLocalVariables = $FglDocumenter::Options::loadLocalVariables;
	$importFglLocation  = $FglDocumenter::Options::importFglLocation;
	$loadFilesRecursive = $FglDocumenter::Options::loadFilesRecursive;

	if ( selectPackages() == 1 )
	{
	  return false;
	}

  $form = $main::mw->Toplevel();
  
  $form->title("Opções de importação de fontes 4gl");
  $height = 400;
  $width  = 700;
	FglDocumenter::Utils::setWindowAtCenter($form,$height,$width);

	$lblPackage = $form->Label(-text => "Package");

	$lbPackages = $form->BrowseEntry(-variable => \$package);
	$lbPackages->insert('end',@packages);
	#$lbPackages->configure(-width => 62);
	#$lbPackages->configure(-height => 1);
	#$lbPackages->configure(-selectmode => "multiple");
	#$lbPackages->configure(-takefocus  => 1);
	$lblPackage->grid(-sticky => "nw", -row => 0,-column => 0);
	$lbPackages->grid(-sticky => "nw", -row => 0,-column => 1);
	#$lbPackages->bind("<FocusOut>", sub { print "FOCUS OUT"; });

	#@bindings = $lbPackages->bind();


	$lblLocation = $form->Label(-text => "Location (Directory)");
	$txtLocation = $form->Entry(-width => 64, 
	  -textvariable => \$importFglLocation,
		-state => 'disabled'
  );
  $locationButton = $form->Button(-text => "...", -command => \&chooseLocation);
	$lblLocation->grid($txtLocation,$locationButton);
	$lblLocation->grid(-sticky => "w", -row => 1,-column => 0);
	$txtLocation->grid(-row => 1,-column => 1);
	$locationButton->grid(-row => 1,-column => 2);


	$lblModules = $form->Label(-text => "Modules");
	@directoryList = ();
	@modules = getModules($importFglLocation);
	$lbModules = $form->Scrolled("Listbox", -scrollbars => "osoe");
	$lbModules->insert('end',@modules);
	$lbModules->configure(-width => 62);
	$lbModules->configure(height => 1);
	$lblModules->grid(-sticky => "nw", -row => 2,-column => 0);
	$lbModules->grid(-row => 2,-column => 1);
	# @todo Janela para Selecção de módulos

	$cbLoadComments = $form->Checkbutton(-text => "Load comments",
	  -variable => \$loadComments
  );
	$cbLoadComments->grid(-sticky => "nw");

	$cbParseOnly = $form->Checkbutton(-text => "Parse Only",
	  -variable => \$parseOnly
  );
	$cbParseOnly->grid(-sticky => "nw");


	$lblRepository = $form->Label(-text => "Repository");
	$fgldocRepository = $FglDocumenter::Options::p4glRepository->getUrl();
	$txtRepository = $form->Entry(-width => 64, 
	  -textvariable => \$fgldocRepository,
		-state => 'disabled'
  );
  $fgldocButton = $form->Button(-text => "...", 
	  -command => \&configureRepository
  );
	$lblRepository->grid($txtRepository,$fgldocButton);
	$lblRepository->grid(-sticky => "w", -row => 5,-column => 0);
	$txtRepository->grid(-row => 5,-column => 1);
	$fgldocButton->grid(-row => 5,-column => 2);


	$cbLoadTableUsage = $form->Checkbutton(-text => "Load Table Usage",
	  -variable => \$loadTableusage
  );
	$cbLoadTableUsage->grid(-sticky => "nw");

	$cbLoadParameters = $form->Checkbutton(-text => "Load Parameters",
	  -variable => \$loadParameters
  );
	$cbLoadParameters->grid(-sticky => "nw");

	$cbLoadStrings = $form->Checkbutton(-text => "Load Strings",
	  -variable => \$loadStrings
  );
	$cbLoadStrings->grid(-sticky => "nw");

	$cbLoadLocalVariables = $form->Checkbutton(-text => "Load Local Variables",
	  -variable => \$loadLocalVariables
  );
	$cbLoadLocalVariables->grid(-sticky => "nw");

	$cbRecursive = $form->Checkbutton(-text => "Recursive",
	  -variable => \$loadFilesRecursive
  );
	$cbRecursive->grid(-sticky => "nw");

  $okButton = $form->Button(-text => "OK", -command => \&ok);
	$cancelButton=$form->Button(-text => "Cancel", -command => \&cancel);
	$okButton->grid($cancelButton);
	return true;
}

#  =========================================================================
#  Abre o form para que o utilizador possa efcetuar a configuração do 
#  repositório
#  =========================================================================
sub configureRepository
{
	FglDocumenter::FormDb::addOkListener(
	  \&repositoryEditListener
  );
	FglDocumenter::FormDb::showDbForm(
	  $FglDocumenter::Options::p4glRepository
  );
}

#  =========================================================================
#  Listener para ser execuutado como callback quando o utilizador carrega 
#  no botão de OK do form de configuração de acesso a BD
#  =========================================================================
sub repositoryEditListener
{
	$fgldocRepository  = $FglDocumenter::Options::p4glRepository->getUrl();
}



#  =========================================================================
#  Trata de efectuar a selecção de packages validando se tudo correu bem
#    @return 1 - Erro a seleccionar packages, 0 se tudo bem.
#  =========================================================================
sub selectPackages
{
	$error->clearErrorFlag();
	@packages = FglDocumenter::P4glRepository::selectPackages();
	if ( $error->isErrorFlag() == 1 )
	{
	  return 1;
	}
	return 0;
}

#  =========================================================================
#  Termina a execução da janela com a opção OK
#  Chama o call back registado para OK
#  =========================================================================
sub ok
{
	$form->destroy;
	$FglDocumenter::Options::packageName        = $package;
	$FglDocumenter::Options::loadComments       = $loadComments;
	$FglDocumenter::Options::parseOnly          = $parseOnly;
	$FglDocumenter::Options::loadTableUsage     = $loadTableUsage;
	$FglDocumenter::Options::loadParameters     = $loadParameters;
	$FglDocumenter::Options::loadStrings        = $loadStrings;
	$FglDocumenter::Options::loadLocalVariables = $loadLocalVariables;
	$FglDocumenter::Options::importFglLocation  = $importFglLocation;
	$FglDocumenter::Options::loadFilesRecursive = $loadFilesRecursive;
	$FglDocumenter::Options::importFglModules   = $modules;
	$FglDocumenter::Options::importFglDirs      = $directoryList;
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

#  =========================================================================
#  Abre um file chooser que permite escolher um directorio e(ou) módulo(s)
#  =========================================================================
sub chooseLocation
{
	$FileSelect = $form->FileSelect();
	$FileSelect->configure(-verify => ["-d"]);
	$importFglLocation = $FileSelect->Show;
	@directoryList = ();
	@modules = getModules($importFglLocation);
	$lbModules->delete(0,$lbModules->size);
	$lbModules->insert('end',@modules);
}

#  =========================================================================
#  Obtem o nome de todos os módulos do directório enviado como parametro
#  Fiz batota com a lista de directórios que não é local
#    @todo - Inserir gestão de erros em vez de die
#  =========================================================================
sub getModules
{
	my $wantedDir = shift;
  my $currentDir = POSIX::getcwd();
	chdir $wantedDir || die "Cant change to $wantedDir : $!\n ";
  my $moduleDir = POSIX::getcwd();
	my @moduleList = ();
	foreach $file (<*>)
	{
		if ( $file =~ / *.4gl/ && -f $file )
		{
		  chomp($file);
	    push(@directoryList,$moduleDir);
	    push(@moduleList,$file);
		}
		elsif ( $loadFilesRecursive == 1 )
		{
		  if ( -d $file )
		  {
				$directory = "$file";
				#$directory = "$wantedDir/$file";
		    @subDirModules = getModules($directory);
	      @moduleList    = (@moduleList,@subDirModules);
		  }
		}
	}
  chdir $currentDir;
	return @moduleList;
}

#  =========================================================================
#  Afecta a variável local com uma referência para o objecto de erros
#  =========================================================================
sub setError
{
  $error = shift;
}

return true;

