#!/usr/bin/perl -w

# ============================================================================
# 
# M�todos que executam a inser��o dos coment�rios guardados no reposit�rio
# nos sources de 4gl
#
# Esta ac��o � executada apenas para um source, no ambito desta classe
#
# @todo Revisao de codigo e testes
# @todo Ser esta classe que se preocupa em mudar para o directorio onde o 
#       fonte esta
# @todo replaceFgldoc esta confuso por causa de usar true e ou 1
#
# $Author: afalout $
# $Id: ExportOneFgl.pm,v 1.1.1.1 2001-12-26 07:32:34 afalout Exp $
# 
# ============================================================================

package FglDocumenter::ExportOneFgl;

# Falta resolver o problema do IO
#use strict;
use POSIX;

#  =========================================================================
#  Constructor
#  =========================================================================
sub new
{
	my $exportOneFgl = {
    "outsideFunction"     => 1,
	  "haveFunctionComment" => 0,
    "replaceFgldoc"       => 0,
    "repository"          => 0,
    "dbh"                 => 0,
    "err"                 => 0,
    "log"                 => 0,
    "progressListener"    => 0,
		"originalLine"        => "",
		"fglDirectory"        => "",
		"sourceFile"          => "",
		"tmpFile"             => "",
		"currentDir"          => "",
		"commentText"         => "",
		"processList"         => (),
		"parametersList"      => (),
    "insertEmptyComment"  => 0,
	};
	bless $exportOneFgl, "FglDocumenter::ExportOneFgl";
	return $exportOneFgl;
}

# ============================================================================
# Afecta a propriedade que define se deve substituir coment�rios fgldoc
# ============================================================================
sub setReplaceFgldoc
{
  my $obj = shift;
  $obj->{replaceFgldoc} = shift;
}

# ============================================================================
# Afecta a refer�ncia para o objecto que define a conex�o ao reposit�rio
# Este j� deve estar devidamente conectado � BD
# ============================================================================
sub setRepository
{
  my $obj = shift;
  $obj->{repository} = $_[0];
	$obj->{dbh} = $obj->{repository}->getConnection();
}

#  ===========================================================================
#  Afecta o objecto de gest�o de erros usado
#  ===========================================================================
sub setError
{
  my $obj = shift;
  $obj->{err} = shift;
}

#  ===========================================================================
#  Afecta a refer�ncia para o objecto de gest�o de log(s)
#  ===========================================================================
sub setLog
{
  my $obj = shift;
  $obj->{log} = shift;
}


# ============================================================================
# Afecta apenas um m�dulo para expprta��o
# ============================================================================
sub setFglModule
{
  my $obj = shift;
	$obj->{fglModule} = shift;
}

# ============================================================================
# Afecta o directorio onde o 4gl se encontra
#  @param $_[0] Directorio onde o fonte se encontra
# ============================================================================
sub setFglDirectory
{
  my $obj = shift;
	$obj->{fglDirectory} = shift;
}

#  ===========================================================================
#  Afecta o pointer ( referencia ) para a rotina que afecta o progresso
#  ===========================================================================
sub addProgressListener
{
  my $obj = shift;
  $obj->{progressListener} = $_[0];
}

#  ===========================================================================
#  Afecta a flag que indica se devem ou n�o ser inseridos coment�rios vazios
#  (sem descritivos de fun��es nem processos)
#  ===========================================================================
sub setInsertEmptyComment
{
  my $obj = shift;
  $obj->{insertEmptyComment} = shift;
}


#  ===========================================================================
#  Comenta um m�dulo 4gl com a informa��o sobre ele que existe no reposit�rio
#    @param $_[0] Direct�rio onde ele se encontra
#    @param $_[1] Nome do m�dulo 4gl
#
#    @todo Mudar aqui de direct�rio 
#    @todo Coment�rio do m�dulo
#  ===========================================================================
sub commentModule
{
  my $obj = shift;
	$obj->{fglDirectory} =  shift;
	$obj->{sourceFile} = shift;
	$obj->changeToSourceDir();
	$obj->{originalLine} = "";
  $obj->startModuleDocCommentInsert();

	while ( $obj->{originalLine} = $obj->readLine() )
	{
	  my $strippedLine = $obj->stripComments($obj->{originalLine});
		if ( $strippedLine eq "" )
		{
		  next;
		}

		if ( $obj->beginingFunction($strippedLine) == 1 )
		{
      my $functionName = $obj->getFunctionName($strippedLine);
		  $obj->insertComment($obj->{originalLine},$functionName);
		  $obj->{haveFunctionComment} = 0;
		}
		elsif ( $obj->endingAndBeginingFunction($strippedLine) )
		{
		  $obj->breakLineAndInsertComment($obj->{originalLine});
		  $obj->{haveFunctionComment} = 0;
		}
		else
		{
		  print OUT_FILE "$obj->{originalLine}";
		}
	}
  $obj->finishModuleDocCommentInsert();
	$obj->changeToOriginalDir();
}

#  ===========================================================================
#  Obtem o nome da fun��o a partir da linha que contem a sua declaracao
#    @param $[0] Linha de texto que contem a declara��o da fun��o
#    @return nome da fun��o
#  ===========================================================================
sub getFunctionName
{
  my $obj = shift;
	$_ = $_[0];
  if ( /.*function *(.*)/i )
	{
		# Estripar (params) se existirem
		my $funcName = $1;
		$funcName =~ s/\(.*\)//;
		# Passar para minusculas
		$funcName = lc $funcName;
		# Tirar 
		$funcName =~ s/ *$//;
		return $funcName;
	}
}

#  ===========================================================================
#  Estripa os coment�rios da linha de c�digo enviada como parametro
#
#  O bjectivo de mandar comentarios a vida e descrobrir inicio de funcao
#
#    @param $_[0] Texto que contem o c�digo 4gl
#    @return Texto com coment�rio estripado
#  ===========================================================================
sub stripComments
{
  my $obj = shift;
  my $codeTextLine = $_[0];
	my $strippedTextLine = $codeTextLine;

	# Retirar coment�rios com #
	$strippedTextLine =~ s/#.*$//;

	# Retirar coment�rios com --
	$strippedTextLine =~ s/--.*$//;

	# Retirar coment�rios com {}
	$strippedTextLine =~ s/{.*}//;

	$strippedTextLine = $obj->readBlockComments($strippedTextLine);

	# Se linha so com espa�os
	$strippedTextLine =~ s/^ *$//;

	# Se linha so com TAB(s)
	$strippedTextLine =~ s/^	*$//;

	return $strippedTextLine;
}


#  ===========================================================================
#  L� e ignora (se f�r caso disso) os coment�rios de bloco que ocupam mais de
#  uma linha
#
#  Se a linha contiver um inicio de comentario de bloco consome os bytes que 
#  o conteem ate ao fim.
#
#  Se for um comentario do tipo fgldoc e estiver definida a sua substitui�ao
#  nao a guarda e le ate ao fim destes.
#
#  @param strippedTextLine Linha de codigo estripada de comentarios
#  @return Linha ainda mais estripada
#  ===========================================================================
sub readBlockComments
{
  my $obj = shift;
	my $strippedTextLine = $_[0];

	# Coment�rio de documenta��o j� existente 
	# (ignorar at� ao fim se para substituir)
	if ( $strippedTextLine =~ /\{\*\*/ )
	{
		$obj->{haveFunctionComment} = 1;
		if ( $obj->{replaceFgldoc} == true )
		{
			$obj->{originalLine} =~ s/\{\*\*.*$//;
			chomp($obj->{originalLine});
			$obj->readUntilCommentEnd(0);
	  }
    else
    {
			$obj->readUntilCommentEnd(1);
		}
		return $strippedTextLine;
	}

	# Coment�rio normal (n�o fgldoc) iniciado nesta linha (ignorar at� ao fim)
	if ( $strippedTextLine =~ /\{.*/ )
	{
		$obj->readUntilCommentEnd(1);
	  $strippedTextLine =~ s/{.*s$//;
	}
	return $strippedTextLine;
}

#  ===========================================================================
#  Inicia a inser��o de coment�rios de documenta��o num m�dulo de 4gl
#  @todo Nome de ficheiro tempor�rio deve ser �nico
#  ===========================================================================
sub startModuleDocCommentInsert
{
  my $obj = shift;
	$obj->backup($obj->{sourceFile});
	if ( ! open(SOURCE_FILE,"< $obj->{sourceFile}") )
	{
		$obj->{err}->error(
		  "Abertura de ficheiro",
		  "Can't open sourcefile \n($obj->{sourceFile}):$!"
    );
	}
	$obj->{tmp_file} = "fgldocumenter.$$.tmp";
	if ( ! open(OUT_FILE,"> $obj->{tmp_file}") ) 
	{
		$obj->{err}->error(
		  "Abertura de ficheiro",
		  "Can't open temporary destination file\n($obj->{tmp_file}):$!"
    );
  }
}

#  ===========================================================================
#  L� at� ao fim do coment�rio.
#
#  @todo Aten��o que pode ficar posicionado no meio de uma linha
#
#  @param putInOriginalLine Define se copia o coment�rio para a linha de
#                           c�digo original 
#      0 - Guarda na linha original.
#      1 - Nao guarda fazendo com que o ficheiro de destino
#          fique sem ela.
#  ===========================================================================
sub readUntilCommentEnd
{
  my $obj = shift;
	my $putInOriginalLine = $_[0];
  my $ch = "";
	while ( ! ($ch eq "}") )
	{
		$ch = getc(SOURCE_FILE);
		if ( $putInOriginalLine == 1 )
		{
		  $obj->{originalLine} .= $ch;
		}
	}

	# Retirar new line do fim do doc comment
	if ( $putInOriginalLine == 0 )
	{
    $ch = getc(SOURCE_FILE);
	  if ( !($ch eq "\n") )
		{
			# @todo Para usar o strict tenho de trabalhar com isto de outra forma
		  IO::Handle::ungetc(SOURCE_FILE, "\n")
		}
	}
}

#  ===========================================================================
#  Devolve true se detectar que se est� a iniciar uma nova fun��o.
#  Esta detec��o � efectuada de acordo com a m�quina de estados e com a 
#  exist�ncia da palavra reservada FUNCTION fora de um coment�rio
#
#    @param linha de c�digo com coment�rios removidos
#    @return 1 se detectar o inicio de fun�~ao, 0 caso contr�ario
#  ===========================================================================
sub beginingFunction
{
  my $obj = shift;
	my $textCodeLine = $_[0];

	# ??? Cuidado com function no meio de label(s) ou nomes de vari�veis
	#print("TextCode line $textCodeLine\n");
	if ( !($textCodeLine =~ /function/i) )
	{
	  return 0;
  }

	#  ??? Como testar se existe mais de uma FUNCTION na mesma linha ???
  if ( $obj->{outsideFunction} == 1)
	{
		$obj->{outsideFunction} = 0;
	  return 1;
	}
	$obj->{outsideFunction} = 1;
	return 0;
}

#  ===========================================================================
#  Devolve true se detectar que na mesma linha se est� a terminar e a iniciar
#  uma fun��o. Neste caso a linha ter� de ser partida e colocado o coment�rio
#  entre as duas fun��es.
#
#    @todo Detectar se isto serve mesmo para alguma coisa.
#
#    @param linha de c�digo com coment�rios removidos
#    @return true se terminar e come�ar linha, false caso contr�rio
#  ===========================================================================
sub endingAndBeginingFunction
{
  my $obj = shift;
	return 0;
}

#  ===========================================================================
#  Procura no reposit�rio o coment�rio relativo a esta fun��o (se houver) e 
#  insere-o no ficheiro de output para onde est� a ser copiado o ficheiro 
#  original seguido da linha de c�digo de declara��o da fun��o original.
#
#    @param linha de c�digo original
#    @param nome da fun��o
#  ===========================================================================
sub insertComment
{
  my $obj = shift;
	my $functionDeclaration = shift;
	my $functionName        = shift;
	if ( $obj->{haveFunctionComment} == 1 && $obj->{replaceFgldoc} == 1 )
	{
    print OUT_FILE "$functionDeclaration";
	  return;
	}
	$obj->selectFunctionComment($functionName);
	$obj->selectFunctionProcess($functionName);

	my $commentText = $obj->formatFunctionComment();

	# @todo : Falta gerar @param, @return, @todo 

	if ( !($commentText eq "") )
	{
		print OUT_FILE $commentText;
	}
  print OUT_FILE "$functionDeclaration";
}

#  ===========================================================================
#  Parte a linha depois do fim da fun��o e insere coment�rio
#  ===========================================================================
sub breakLineAndInsertComment
{
  my $obj = shift;
  # obter texto at� fim de primeiro function
	my $textUntilFirstFunction = "";
	my $textAfterFirstFunction = "";
	print OUT_FILE "$textUntilFirstFunction\n";
	$obj->insertComment($textAfterFirstFunction);
}

#  ===========================================================================
#  L� uma linha do ficheiro cujo source se est� a alterar
#  ===========================================================================
sub readLine
{
  my $obj = shift;
  my $line = readline(SOURCE_FILE);
	return $line;
}

#  ===========================================================================
#  Faz um backup do ficheiro para um tempor�rio
#    @todo - Tempor�rio deve ser mesmo tempor�rio
#  ===========================================================================
sub backup
{
  my $obj = shift;
	my $sourceFile = $_[0];
	my $backupFileName = $sourceFile . ".$$.back";
	if ( ! open(BACK_FILE,"> $backupFileName") )
	{
		$obj->{err}->error(
		  "Abertura de ficheiro",
		  "Can't open backup file\n($backupFileName):$!"
    );	
	}

	if ( ! open(SOURCE_FILE,"<$sourceFile") )
	{
		$obj->{err}->error(
		  "Abertura de ficheiro",
		  "Can't open sourcefile for making backup:\i$sourceFile) in " .
	    getcwd() .  "\n\i$!"
    );
		# @todo Dar uma excep�ao
	}

	my $line;
	foreach  $line ( <SOURCE_FILE> )
	{
	  print(BACK_FILE "$line");
	}

	if ( ! close(SOURCE_FILE) )
	{
		$obj->{err}->warning(
		  "Fechar ficheiro",
		  "Can't close sourcefile\n($sourceFile):$!"
    );	
  }

	if ( ! close(BACK_FILE) )
	{
		$obj->{err}->warning(
		  "Fechar ficheiro",
		  "Can't close backup file\n($backupFileName):$!"
    );	
  }
}


#  ===========================================================================
#  Termina a inser��o de coment�rios de documenta��o num m�dulo de 4gl
#  ===========================================================================
sub finishModuleDocCommentInsert
{
  my $obj = shift;
  if( ! close(SOURCE_FILE) )
	{
		$obj->{err}->warning(
		  "Fechar ficheiro",
		  "Can't close sourcefile\n($obj->{sourceFile}):$!"
    );	
	}

  if( ! close(OUT_FILE) )
	{
		$obj->{err}->warning(
		  "Fechar ficheiro",
		  "Can't close sourcefile\n($obj->{temp_file}):$!"
    );	
	}
	$obj->moveFile();
}

#  ===========================================================================
#  Move o ficheiro temporariamente criado para cime do original
#  ===========================================================================
sub moveFile
{
  my $obj = shift;
	if ( ! rename($obj->{tmp_file},$obj->{sourceFile}) )
	#if ( ! `mv ($obj->{tmp_file} $obj->{sourceFile})` )
	{
		$obj->{err}->error(
		  "Mover ficheiro",
		  "Can't move temp file to source file\n
			($obj->{tmp_file} => $obj->{source_file}):$!"
    );
	}
}

#  ===========================================================================
#  Selecciona o coment�rio associado � fun��o
#    @param $_[0] Nome da fun��o
#    @return Texto do coment�rio
#  ===========================================================================
sub selectFunctionComment
{
  my $obj = shift;
	my $functionName = $_[0];

	$obj->{commentText} = "";
  my $sth = $obj->{dbh}->prepare(q%
	  SELECT comments FROM p4gl_function 
		where function_name=? and module_name=?
	%);
  if ( ! $sth )
	{
		$obj->{err}->error(
		  "Sele��o de coment�rios",
		  "Can't prepare select from comments\n$DBI::errstr"
    );
		return;
	}
  $sth->bind_param(1,$functionName);
  $sth->bind_param(2,$obj->{sourceFile});
  $sth->execute() || 
		$obj->{err}->error(
		  "Selec��o de coment�rios",
	    "Can't select from p4gl_function\n$DBI::errstr"
    );
  my(@row);
  @row = $sth->fetchrow_array();
	my $functionComment; 
	if ( defined(@row) )
	{
		#$obj->{log}->log("Coment�rios : $row[0]");
		my $comment = $row[0];
		$comment =~ s/^ *//g; $comment =~ s/ *$//g;
		$comment =~ s/^	*//g; $comment =~ s/	*$//g;
	  $obj->{commentText} = $comment;
	}
	else
	{
		$obj->{log}->log("N�o encontrou coment�rio para fun��o %s\n",$functionName);
	}
  undef $sth;
}


#  ===========================================================================
#  Selecciona todos os processos associados a fun��o
#    @param $_[0] Nome da fun��o
#    @return Lista com processos da fun��o
#  ===========================================================================
sub selectFunctionProcess
{
  my $obj = shift;
	my $functionName = shift;

	$obj->{processList} = ();
  my $sth = $obj->{dbh}->prepare(q%
	  SELECT id_process FROM p4gl_fun_process
		WHERE module_name=? and function_name=?
	%);
  if ( ! $sth )
	{
		$obj->{err}->error(
		  "Sele��o de processo",
		  "Can't prepare select from function process\n$DBI::errstr"
    );
		return;
	}
  $sth->bind_param(1,$obj->{sourceFile});
  $sth->bind_param(2,$functionName);
  $sth->execute() || 
		$obj->{err}->error(
		  "Selec��o de processo",
	    "Can't select from p4gl_fun_process\n$DBI::errstr"
    );
  my(@row);
  my(@processList);
  while (@row = $sth->fetchrow_array())
  {
					#$obj->{log}->log("PROCESSO : $row[0]");
		push(@processList,$row[0]);
  }
	$obj->{processList} = \@processList;
  undef $sth;
}

#  ===========================================================================
#  Selecciona ia informa��o sobre os parametros a fun��o
#    @param $_[0] Nome da fun��o
#    @return Lista com os par�metros da fun��o
#  ===========================================================================
sub selectFunctionParameters
{
  my $obj = shift;
	my $functionName = $_[0];
	$obj->{parametersList} = ();
  my $sth = $obj->{dbh}->prepare(q%
	  SELECT var_name, data_type, comments FROM p4gl_fun_parameter
		WHERE module_name=? and function_name=?
	%);
  if ( ! $sth )
	{
		$obj->{err}->error(
		  "Sele��o de parametros",
		  "Can't prepare select from function parameter\n$DBI::errstr"
    );
		return 0;
	}
  $sth->bind_param(1,$functionName);
  $sth->bind_param(2,$obj->{sourceFile});
  $sth->execute() || 
		$obj->{err}->error(
		  "Selec��o de parametro",
	    "Can't select from p4gl_fun_parameter\n$DBI::errstr"
    );
  my(@row);
  @row = $sth->fetchrow_array();
	my $functionComment; 
  my(@row);
  while (@row = $sth->fetchrow_array())
  {
		$obj->{log}->log("Parametro : $row[0]");
		$obj->{log}->log("            $row[1]");
		$obj->{log}->log("            $row[2]");
		my %parameter = { 'var_name'  => $row[0],
		                  'data_type' => $row[1],
		                  'comments'  => $row[2]
		};
		# @todo - Meter numa hash com os tr�s campos
		#push($obj->{parametersList},\%parameter);
  }
  undef $sth;
}

#  ===========================================================================
#  Faz backup do direct�rio corrente e muda-se para aquele onde o source 
#  se encontra.
#  ===========================================================================
sub changeToSourceDir
{
  my $obj = shift;
	$obj->{currentDir} = getcwd();
	if ( ! chdir $obj->{fglDirectory} )
	{
	  $obj->{err}->error(
		  "Mudan�a de direct�rio",
		  "Can't change to ($obj->{fglDirectory}):\n$!"
    );
  }
}

#  ===========================================================================
#  Muda-se para o direct�rio onde o programa estava antes de usar este 
#  objecto
#  ===========================================================================
sub changeToOriginalDir
{
  my $obj = shift;
	if ( ! chdir $obj->{currentDir} )
	{
	  $obj->{err}->error(
		  "Mudan�a de direct�rio",
		  "Can't change to ($obj->{currentDir}):\n$!"
    );
  }
}

#  ===========================================================================
#  Formata devidamente o comentario da fun�ao:
#    - Nao deixa passar das 80 colunas.
#    - Mete * antes de cada linha
#    - Parte linhas com <BR>
#    @todo Meter a partir pelas 80 colunas
#
#    @return The comment formatted or empty string if not
#  ===========================================================================
sub formatFunctionComment
{
  my $obj = shift;
	my $existeComentario = 0;

	my $commentStr = "";

  $commentStr = "{**\n";

	# Partir linhas
	$obj->{commentText} =~ s/^ *//g;
	$obj->{commentText} =~ s/	*$//g;
	if ( (defined($obj->{commentText}) && !($obj->{commentText} eq "")) ||
	     $obj->{insertEmptyComment} == 1)
	{
		$existeComentario = 1;
	  my $comentario = $obj->splitLines($obj->{commentText});
	  $commentStr .= " * " . $comentario . "\n *";
	}

	# Meter processos
	my $arrayRef = $obj->{processList};
	my @array = @$arrayRef;
	my $processCode;
	foreach $processCode ( @array )
	{
		$existeComentario = 1;
	  $commentStr .= "\n *  \@process $processCode";
	}
  $commentStr .= "\n *}\n";
	if ( $existeComentario == 0 )
	{
	  $commentStr = "";
	}
	return $commentStr;
}

#  ===========================================================================
#  Parte as linhas de acordo com o criterio definido e volta a junta-las
#  por form que cada uma nao tenha mais de 80 colunas
#  ===========================================================================
sub splitLines
{
	my $obj = shift;
	my $comentario = shift;
	chomp($comentario);
	my @commentLines = ($comentario);
  # Partir por <BR>
	@commentLines = splitList("<BR>",\@commentLines);
	# Partir por ". "
	@commentLines = splitList("\\\. ",\@commentLines);
	# @todo - Partir todas aquelas que tenham mais de 80 colunas 
	#@commentLines = split80Cols(\@commentLines);
	# @todo - Fazer um leftTrim
	
	# Meter join com "\n *", para ir tudo para uma string grande
	my $strFinal = join("\n * ",@commentLines);
	return $strFinal;
}

#  ===========================================================================
#  Parte todas as strings de uma lista passada de acordo com um separador
#    @param separator Separador usado para partir
#    @param list Array cujas strings se querem partir
#    @return Lista final toda partida
#  ===========================================================================
sub splitList
{
	my $separator = shift;
	my $listRef = shift;
	my @list = @$listRef;

	my @returningList = ();
	my $line;
	foreach $line ( @list )
	{
		my @tmpList = split(/$separator/,$line);
		my $tmpLine;
		foreach $tmpLine ( @tmpList )
		{
			# @todo O separador � retirado e deve ser mantido
			push(@returningList,$tmpLine);
		}
	}
	return @returningList;
}

return 1;

