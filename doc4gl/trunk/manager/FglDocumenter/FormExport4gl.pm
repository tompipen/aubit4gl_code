#!/usr/bin/perl

#  =========================================================================
#
#  Implementa métodos em Perl/Tk para um form que permite efectuar as
#  da importação de um ficheiro CSV
# 
#  As opções globais estão guardadas no módulo Options.
#
#  @todo - Backup file
#  @todo - Temp file name
#  @todo - Strict a funcionar
#
#  $Author: saferreira $
#  $Id: FormExport4gl.pm,v 1.2 2003-01-06 20:07:38 saferreira Exp $
#
#  =========================================================================

#use strict;
use Tk::Dialog;

package FglDocumenter::FormExport4gl;

#  =========================================================================
#  Constructor
#  =========================================================================
sub new
{
  my ($formExport4gl) = @_;

	my $formExport4gl = {
    "err"                => 0,
	  "log"                => 0,
    "progressListener"   => 0,
    "form"           => 0,
    "sourceDir"      => "",
    "fglSource"      => "",
    "replaceFgldoc"  => 0,
    "okListener"     => 0,
    "cancelListener" => 0,
    "lh"             => 0,
	};
	bless $formExport4gl, "FglDocumenter::FormExport4gl";
	return $formExport4gl;
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
sub setSourceDir()
{
  my $obj = shift;
	$obj->{sourceDir} = shift;
}

#  =========================================================================
#  Assign the object with default fglSource to replace
#  =========================================================================
sub setFglSource()
{
  my $obj = shift;
	$obj->{fglSource} = shift;
}

#  =========================================================================
#  Assign the object with default flag that indicates if we want to replace
#  eventual existing fgldoc(s) in the source
#  =========================================================================
sub setReplaceFglDoc()
{
  my $obj = shift;
	$obj->{replaceFglDoc} = shift;
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
    $lh->maketext("4gl source export options")
	);

	my $lblDirectory = $obj->{form}->Label(
	  -text => $lh->maketext("Location")
	);
	my $txtDirectory = $obj->{form}->Entry(
    -width => 64, 
	  -textvariable => \$obj->{sourceDir},
		-state => 'disabled'
  );
  my $directoryButton = $obj->{form}->Button(-text => "...", 
	  -command => [ \&chooseDirectory, $obj ]
  );
	$lblDirectory->grid($txtDirectory,$directoryButton);
	$lblDirectory->grid(-sticky => "nw", -row => 1,-column => 0);
	$txtDirectory->grid(-row => 1,-column => 1);
	$directoryButton->grid(-row => 1,-column => 2);

	my $lblModules = $obj->{form}->Label(-text => "Modules");
	@modules = $obj->getFglModules($obj->{sourceDir});
	$lbModules = $obj->{form}->Scrolled("Listbox", -scrollbars => "osoe");
	$lbModules->insert('end',@modules);
	$lbModules->configure(-width => 62);
	$lbModules->configure(height => 1);
	$lblModules->grid(-sticky => "nw", -row => 2,-column => 0);
	$lbModules->grid(-row => 2,-column => 1);

	my $cb = $obj->{form}->Checkbutton(-text => "Replace fgldoc(s)",
	  -variable => \$replaceFgldoc
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

	# @todo : Retirar dependencia de options
	$FglDocumenter::Options::replaceFgldoc = $obj->{replaceFgldoc};
	$FglDocumenter::Options::sourceDir     = $obj->{sourceDir};
	@selected = $lbModules->curselection();
	# @todo : Teste de existencia de elemento seleccionado
	# @todo : Selecção multipla
	if ( $#selected == -1 )
	{
	  $obj->{err}->error(
		  "Export to Fgl source",
		  "Não foi marcado nenhum source"
    );	
	  $obj->cancel();
	}
	$FglDocumenter::Options::fglSource = $lbModules->get(
	  $selected[0],$selected[0]
  );
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
    -directory => $obj->{sourceDir}
  );
	$fileSelect->configure(-verify => ["-d"]);
	$obj->{sourceDir} = $fileSelect->Show;
	# Actualizar lista de ficheiros
	# @todo : Meter comportamento recursivo
	#@directoryList = ();
	my @modules = $obj->getFglModules($obj->{sourceDir});
	$lbModules->delete(0,$lbModules->size);
	$lbModules->insert('end',@modules);
	$obj->{form}->raise();
}

#  =========================================================================
#  Procura no directorio corrente uma lista de 4gl(s) e devolve-a
#    @todo Esta funçao esta repetida em FormP4gl. Tentar mais reutilizaçao
#  =========================================================================
sub getFglModules
{
  my $obj = shift;
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

return true;
