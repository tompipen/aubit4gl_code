#!/usr/bin/perl

#  =========================================================================
#
#  M�dulo que implementa fun��es diversas para log de ac��es
# 
#  Est� implementado sob a forma de objecto
#
#  Autor : S�rgio Ferreira
#
#  @todo Scroll autom�tico da scrolbar durante adi��o do log
#
#  =========================================================================

package DbDocumenter::Log;


use Tk;

#  =========================================================================
#  Construtora
#  =========================================================================
sub new 
{
  my ($pkg,$fileName,) = @_;

	my $log = {
	  "fileName"    => $fileName,
	  "showGui"     => 0,
	  "fileHandler" => FILE_HANDLER,
	  "UI"          => "GUI",
	  #"textLog"      => 0,
	};
	bless $log, "DbDocumenter::Log";
	return $log;
}

#  =========================================================================
#  Afecta o nome do ficheiro onde ser� guardado o log
#  =========================================================================
sub setFileName
{
  $obj = shift;
	$obj->{fileName} = shift
}

#  =========================================================================
#  =========================================================================
sub getFileName
{
  $obj = shift;
	return $obj->{fileName};
}

#  =========================================================================
#  Afecta a vari�vel que diz que a janela deve sre mostrada
#  =========================================================================
sub setShowGUI
{
  $obj = shift;
	$obj->{showGui} = shift;
}

#  =========================================================================
#  =========================================================================
sub isShowGUI
{
  $obj = shift;
	return $obj->{showGui};
}

#  =========================================================================
#  Afecta o user interface usado
#  =========================================================================
sub setUI
{
  $obj = shift;
	$obj->{UI} = shift;
}

#  =========================================================================
#  Abre o ficheiro de log
#  @todo Gerir melhor os erros
#  =========================================================================
sub openLogFile
{
  $obj = shift;
	open($obj->{fileHandler},">$obj->{fileName}")
	  || print "Error opening log file ($obj->{fileName}) : $!\n";
	$fh = $obj->{fileHandler};
	print $fh "Log started at\n";
}

#  =========================================================================
#  Fecha o ficheiro de log
#  =========================================================================
sub closeLogFile
{
  $obj = shift;
	$fh = $obj->{fileHandler};
	print $fh "Log finished at\n";
	close($obj->{fileHandler});
}

#  =========================================================================
#  Abre a janela que mostra o log
#  =========================================================================
sub openLogWindow
{
  $obj = shift;

	# @todo Isto tem de fazer parte integrante do objecto
	$form = $main::mw->Toplevel();
  
  $form->title("LOG");
  #$width  = 650;
  #$height = 400;
	#Utils::setWindowAtCenter($form,$height,$width);

	#$height = $mw->screenheight();
  $height = 150;
  $width = $main::mw->screenwidth();
	my $y = $main::mw->screenheight() - $height-1;
	# print("Y = $y\n");
	$y = 600;
  $form->geometry("${width}x${height}+0+$y");


	$textLog = $form->Scrolled("Text",
	  -scrollbars => "se",
		-width => $width-50,
		-height => $height-50,
	)->pack;
	#->pack(-side => 'left',
		#-fill => 'both', -expand => 1
  #);
	#$textLog->grid(-sticky => "w", -row => 1,-column => 0);

  #$hideButton = $form->Button(-text => "HIDE", -command => \&hideLogWindow);
	#$hideButton->grid;
}

#  =========================================================================
#  Mostra a janela que est� a mostrar o log
#  @todo Implementar
#  =========================================================================
sub showLogWindow
{
  $obj = shift;
	if ( !$form )
	{
		openLogWindow();
	}
	else
	{
		$form->deiconify();
		$form->raise();
	}
}


#  =========================================================================
#  Esconde a janela que est� a mostrar o log
#  @todo Implementar
#  =========================================================================
sub hideLogWindow
{
  $obj = shift;
	if ( $form )
	{
    $form->withdraw();
  }
}


#  =========================================================================
#  Envia a string recebida como parametro para a janela de log
#  @todo Guardar objectos visuais no objecto
#  =========================================================================
sub sendLogToWindow
{
  my $obj = shift;
	my $str = shift;
	$textLog->insert('end',"$str\n");
}

#  =========================================================================
#  Envia uma string para o log file
#  @todo Meter a janela de log a funcionar bem
#  =========================================================================
sub log
{
  my $obj = shift;
	my $str = shift;
	my $str2 = shift;
	my $fh = $obj->{fileHandler};

	if ( $obj->{UI} eq "CUI" )
	{
	  $obj->cuiLog($str,$str2);
  }
	else
	{
	  $obj->guiLog($str,$str2);
	}

	print $fh "$str\n";
}

#  =========================================================================
#  Envia mensagem para log em modo GUI (Grafical User Interface)
#  =========================================================================
sub guiLog
{
  my $obj = shift;
	my $str = shift;
	my $str2 = shift;

	if ( $obj->isShowGUI() == 1 )
	{
	  $obj->sendLogToWindow($str);
	}
}

#  =========================================================================
#  Envia mensagem para log em modo CUI (Command line User Interface)
#  =========================================================================
sub cuiLog
{
  my $obj = shift;
	my $str = shift;
	my $str2 = shift;
	if ( !defined($str2) )
	{
	  $str2 = "";
	}

  printf("[LOG] : $str $str2\n");
}

return 1;
