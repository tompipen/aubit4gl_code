#!/usr/bin/perl

#  =========================================================================
#
#  M�dulo que implementa fun��es diversas para gest�o de erros ocorridos
#  Com estes m�todos � possivel afectar e desafectar erros correntes
#  de uma forma global por forma a simular uma esp�cie de gest�o de excep��es
# 
#  Est� implementado sob a forma de objecto
#
#  Autor : S�rgio Ferreira
#
#  =========================================================================

package DbDocumenter::Error;


use Tk;

#  =========================================================================
#  Construtora
#  =========================================================================
sub new
{
  my ($pkg) = @_;

	my $error = {
	  "showGui"            => 0,
	  "log"                => 0,
	  "textLog"            => 0,
	  "errorListener"      => 0,
	  "warningListener"    => 0,
	  "errorFlag"          => 0,
	  "errorStr"           => "",
	  "UI"                 => "GUI",
	};
	bless $error, "DbDocumenter::Error";
	return $error;
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
#  Limpa o(s) erro(s) registados
#  =========================================================================
sub clearAllErrors
{
  my $obj = shift;
}

#  =========================================================================
#  Foi executada uma mensagem de erro fatal
#  Verifica se est� definida a utiliza��o de GUI, se existe log e Listener
#  registado
#  =========================================================================
sub fatalError
{
  my $obj    = shift;
	my $titulo = shift;
	my $text   = shift;

	if ( $obj->{UI} eq "CUI" )
	{
	  $obj->cuiFatalError($titulo,$text);
  }
	else
	{
	  $obj->guiFatalError($titulo,$text);
	}
}

#  =========================================================================
#  Envia para o ecran e d� um error em modo GUI
#  =========================================================================
sub guiFatalError
{
  my $obj    = shift;
	my $titulo = shift;
	my $text   = shift;
	if ( $obj->{log} != 0 )
	{
	  $log->log("ERRO FATAL: $titulo\n	$text");
	}

	$obj->openErrWindow($titulo,$text);
	#if ( $obj->{errorListener} != 0 )
	#{
	  #$obj->{errorListener}($titulo,$text) if $obj->{errorListener};
	#}
	if ( $obj->{showGui} == 1 )
	{
	  $obj->showError();
	}
}

#  =========================================================================
#  Envia para o ecran e d� um error em modo CUI (Command line User Interface)
#  =========================================================================
sub cuiFatalError
{
  my $obj    = shift;
	my $titulo = shift;
	my $text   = shift;

	if ( $obj->{log} != 0 )
	{
	  $log->log("ERRO FATAL: $titulo\n	$text");
	}

	#if ( $obj->{errorListener} != 0 )
	#{
	  #&$obj->{ErrorListener}($titulo,%text) if $obj->ErrorListener;
	#}
	printf("ERRO Fatal: $titulo\n");
	printf("\i$text\n");
}


#  =========================================================================
#  Apresenta um erro, regista-o e continua a execu��o
#  =========================================================================
sub error
{
  my $obj    = shift;
	my $title  = shift;
	my $text   = shift;
	if ( $obj->{UI} eq "CUI" )
	{
	  $obj->cuiError($title,$text);
  }
	else
	{
	  $obj->guiError($title,$text);
	}
}

#  =========================================================================
#  Apresenta um erro em modo GUI (Graphical User Interface)
#  =========================================================================
sub guiError
{
  my $obj    = shift;
	my $title  = shift;
	my $text   = shift;
	#if ( $obj->{log} != 0 )
	# ???? ISTO N�O EST� A FUNCIONAR
	#{
	  #$log->log("ERRO FATAL: $title\n	$text");
	#}
	$obj->openErrWindow($title,$text);
}

#  =========================================================================
#  Apresenta um erro em modo CUI (Command line User Interface)
#  =========================================================================
sub cuiError
{
  my $obj    = shift;
	my $title  = shift;
	my $text   = shift;
	printf("ERRO: $title :\n");
	printf("  $text\n");
}

#  =========================================================================
#  Abre a janela que mostra o erro
#  @todo Devia ser modal
#  =========================================================================
sub openErrWindow
{
  $obj    = shift;
	$titulo = shift;
	$text   = shift;

	# @todo Isto tem de fazer parte integrante do objecto e a refer�ncia para 
	#       a main window tambem
	# @todo - Isto aparentemente nao existe em todas as vers�es de TK
	#$form = $main::mw->Dialog(-title => "ERRO : $titulo",
	                          #-text => $text
  #);
	#$form->Show();
}

#  =========================================================================
#  O utilizador carregou em OK na janela de erro (ambiente GUI)
#  =========================================================================
sub ok
{
  $form->destroy();
}

#  =========================================================================
#  O utilizador carregou em Cancel na janela de erro (ambiente GUI)
#  =========================================================================
sub cancel
{
  $form->destroy();
}

#  =========================================================================
#  Mostra o erro numa dialog
#  @todo Decidir se serve para alguma coisa e se n�o remover
#  =========================================================================
sub showError
{
  my $obj = shift;
}

#  =========================================================================
#  Envia um warning 
#  =========================================================================
sub warning
{
  my $obj = shift;
}

#  =========================================================================
#  Mostra o erro numa dialog
#  =========================================================================
sub showWarning
{
  my $obj = shift;
}

#  =========================================================================
#  Define uma ac��o standrad a executar quando ocorrer um erro
#  As ac��es podem ser:
#    - Continue
#    - Stop
#    - Call Listener
#  =========================================================================
sub wheneverError
{
  my $obj = shift;
}

#  =========================================================================
#  Regista a refer�ncia para um listener de erros
#  =========================================================================
sub addErrorListener
{
  my $obj = shift;
	$obj->{errorListener} = shift;
}

#  =========================================================================
#  Remove a refer�ncia para um listener de erros
#  =========================================================================
sub  removeErrorListener
{
  my $obj = shift;
	$obj->{errorListener} = 0;
}


#  =========================================================================
#  Regista a refer�ncia para um listener de erros
#  =========================================================================
sub addWarningListener
{
  my $obj = shift;
	$obj->{warningListener} = shift;
}

#  =========================================================================
#  Regista a refer�ncia para um listener de erros
#  =========================================================================
sub  removeWarningListener
{
  my $obj = shift;
	$obj->{warningListener} = 0;
}

#  =========================================================================
#  Afecta o objecto de log usado pelos erros
#  =========================================================================
sub  setLog
{
  my $obj = shift;
	$obj->{log} = shift;
}

#  =========================================================================
#  Afecta a flag e mensagem de erros
#    @param flag Flag que define se h� ou n�o erro
#    @param mensagem Texto associado ao erro
#  =========================================================================
sub setErrorFlag
{
  my $obj = shift;
	$obj->{errorFlag} = shift;
	$obj->{errorStr}  = shift;
}

#  =========================================================================
#  Limpa a flag relativa ao erro corrente
#  =========================================================================
sub clearErrorFlag
{
  my $obj = shift;
	$obj->setErrorFlag(0,"");
}

#  =========================================================================
#  Devolve a flag de erros para o erro corrente (caso exista)
#  =========================================================================
sub isErrorFlag
{
  my $obj = shift;
	return $obj->{errorFlag};
}

#  =========================================================================
#  Devolve a string contendo o erro corrente
#  =========================================================================
sub getErrorStr
{
  my $obj = shift;
	return $obj->{errorStr};
}

return 1;
