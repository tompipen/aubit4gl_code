#!/usr/bin/perl -w

#  =========================================================================
#
#  Módulo que implementa funções diversas para log de acções
# 
#  Está implementado sob a forma de objecto
#
#  Autor : Sérgio Ferreira
#
#  @todo Scroll automático da scrolbar durante adição do log
#  @todo - Meter strict a funcionar
#
#  =========================================================================

package FglDocumenter::Log;

#use strict;
use Tk;

#  =========================================================================
#  Construtora
#  =========================================================================
sub new 
{
  my ($pkg,$fileName,) = @_;

	my $log = {
	  "fileName"    => $fileName,
	  "showGui"     => false,
	  "fileHandler" => FILE_HANDLER,
	  "toStdout"    => 1,
	  "UI"          => "GUI",
	  #"textLog"      => 0,
	};
	bless $log, "FglDocumenter::Log";
	return $log;
}

#  =========================================================================
#  Afetca o nome do ficheiro a usar
#  =========================================================================
sub setFileName
{
  $obj = shift;
	$obj->{fileName} = shift
}

#  =========================================================================
#  @return the log file name
#  =========================================================================
sub getFileName
{
  $obj = shift;
	return $obj->{fileName};
}

#  =========================================================================
#  Afecta a variável que diz que a janela deve sre mostrada
#  =========================================================================
sub setShowGUI
{
  $obj = shift;
	$obj->{showGui} = shift;
}

#  =========================================================================
#  @return The flag that tells us if we are working in GUI mode.
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
#  Define se (quando em modo TUI) deve ou não enviar mensagens para o
#  standard output
#  =========================================================================
sub setToStdout
{
  $obj = shift;
	$obj->{toStdout} = shift;
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
#  @todo : Passar isto a panel.
#  =========================================================================
sub openLogWindow
{
  $obj = shift;

	# @todo Isto tem de fazer parte integrante do objecto
	$form = $main::mw;
  
  $height = 10;
  $width = $main::mw->screenwidth();


	$textLog = $form->Scrolled("Text",
	  -scrollbars => "se",
		-width => $width-100,
		-height => $height,
	)->pack;
}

#  =========================================================================
#  Mostra a janela que está a mostrar o log
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
#  Esconde a janela que está a mostrar o log
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

	if ( $obj->isShowGUI() == true )
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

  printf("[LOG] : $str $str2\n") if $obj->{toStdout};
}

return true;
