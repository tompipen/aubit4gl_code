#!/usr/bin/perl -w

# ============================================================================
# 
# Métodos que executam a inserção dos comentários guardados no repositório
# nos sources de 4gl
#
# Esta acção é executada apenas para um source, no ambito desta classe
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
# Afecta a propriedade que define se deve substituir comentários fgldoc
# ============================================================================
sub setReplaceFgldoc
{
  my $obj = shift;
  $obj->{replaceFgldoc} = shift;
}

# ============================================================================
# Afecta a referência para o objecto que define a conexão ao repositório
# Este já deve estar devidamente conectado à BD
# ============================================================================
sub setRepository
{
  my $obj = shift;
  $obj->{repository} = $_[0];
	$obj->{dbh} = $obj->{repository}->getConnection();
}

#  ===========================================================================
#  Afecta o objecto de gestão de erros usado
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


# ============================================================================
# Afecta apenas um módulo para expprtação
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
#  Afecta a flag que indica se devem ou não ser inseridos comentários vazios
#  (sem descritivos de funções nem processos)
#  ===========================================================================
sub setInsertEmptyComment
{
  my $obj = shift;
  $obj->{insertEmptyComment} = shift;
}


#  ===========================================================================
#  Comenta um módulo 4gl com a informação sobre ele que existe no repositório
#    @param $_[0] Directório onde ele se encontra
#    @param $_[1] Nome do módulo 4gl
#
#    @todo Mudar aqui de directório 
#    @todo Comentário do módulo
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
#  Obtem o nome da função a partir da linha que contem a sua declaracao
#    @param $[0] Linha de texto que contem a declaração da função
#    @return nome da função
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
#  Estripa os comentários da linha de código enviada como parametro
#
#  O bjectivo de mandar comentarios a vida e descrobrir inicio de funcao
#
#    @param $_[0] Texto que contem o código 4gl
#    @return Texto com comentário estripado
#  ===========================================================================
sub stripComments
{
  my $obj = shift;
  my $codeTextLine = $_[0];
	my $strippedTextLine = $codeTextLine;

	# Retirar comentários com #
	$strippedTextLine =~ s/#.*$//;

	# Retirar comentários com --
	$strippedTextLine =~ s/--.*$//;

	# Retirar comentários com {}
	$strippedTextLine =~ s/{.*}//;

	$strippedTextLine = $obj->readBlockComments($strippedTextLine);

	# Se linha so com espaços
	$strippedTextLine =~ s/^ *$//;

	# Se linha so com TAB(s)
	$strippedTextLine =~ s/^	*$//;

	return $strippedTextLine;
}


#  ===========================================================================
#  Lê e ignora (se fôr caso disso) os comentários de bloco que ocupam mais de
#  uma linha
#
#  Se a linha contiver um inicio de comentario de bloco consome os bytes que 
#  o conteem ate ao fim.
#
#  Se for um comentario do tipo fgldoc e estiver definida a sua substituiçao
#  nao a guarda e le ate ao fim destes.
#
#  @param strippedTextLine Linha de codigo estripada de comentarios
#  @return Linha ainda mais estripada
#  ===========================================================================
sub readBlockComments
{
  my $obj = shift;
	my $strippedTextLine = $_[0];

	# Comentário de documentação já existente 
	# (ignorar até ao fim se para substituir)
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

	# Comentário normal (não fgldoc) iniciado nesta linha (ignorar até ao fim)
	if ( $strippedTextLine =~ /\{.*/ )
	{
		$obj->readUntilCommentEnd(1);
	  $strippedTextLine =~ s/{.*s$//;
	}
	return $strippedTextLine;
}

#  ===========================================================================
#  Inicia a inserção de comentários de documentação num módulo de 4gl
#  @todo Nome de ficheiro temporário deve ser único
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
#  Lê até ao fim do comentário.
#
#  @todo Atenção que pode ficar posicionado no meio de uma linha
#
#  @param putInOriginalLine Define se copia o comentário para a linha de
#                           código original 
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
#  Devolve true se detectar que se está a iniciar uma nova função.
#  Esta detecção é efectuada de acordo com a máquina de estados e com a 
#  existência da palavra reservada FUNCTION fora de um comentário
#
#    @param linha de código com comentários removidos
#    @return 1 se detectar o inicio de funç~ao, 0 caso contr´ario
#  ===========================================================================
sub beginingFunction
{
  my $obj = shift;
	my $textCodeLine = $_[0];

	# ??? Cuidado com function no meio de label(s) ou nomes de variáveis
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
#  Devolve true se detectar que na mesma linha se está a terminar e a iniciar
#  uma função. Neste caso a linha terá de ser partida e colocado o comentário
#  entre as duas funções.
#
#    @todo Detectar se isto serve mesmo para alguma coisa.
#
#    @param linha de código com comentários removidos
#    @return true se terminar e começar linha, false caso contrário
#  ===========================================================================
sub endingAndBeginingFunction
{
  my $obj = shift;
	return 0;
}

#  ===========================================================================
#  Procura no repositório o comentário relativo a esta função (se houver) e 
#  insere-o no ficheiro de output para onde está a ser copiado o ficheiro 
#  original seguido da linha de código de declaração da função original.
#
#    @param linha de código original
#    @param nome da função
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
#  Parte a linha depois do fim da função e insere comentário
#  ===========================================================================
sub breakLineAndInsertComment
{
  my $obj = shift;
  # obter texto até fim de primeiro function
	my $textUntilFirstFunction = "";
	my $textAfterFirstFunction = "";
	print OUT_FILE "$textUntilFirstFunction\n";
	$obj->insertComment($textAfterFirstFunction);
}

#  ===========================================================================
#  Lê uma linha do ficheiro cujo source se está a alterar
#  ===========================================================================
sub readLine
{
  my $obj = shift;
  my $line = readline(SOURCE_FILE);
	return $line;
}

#  ===========================================================================
#  Faz um backup do ficheiro para um temporário
#    @todo - Temporário deve ser mesmo temporário
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
		# @todo Dar uma excepçao
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
#  Termina a inserção de comentários de documentação num módulo de 4gl
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
#  Selecciona o comentário associado à função
#    @param $_[0] Nome da função
#    @return Texto do comentário
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
		  "Seleção de comentários",
		  "Can't prepare select from comments\n$DBI::errstr"
    );
		return;
	}
  $sth->bind_param(1,$functionName);
  $sth->bind_param(2,$obj->{sourceFile});
  $sth->execute() || 
		$obj->{err}->error(
		  "Selecção de comentários",
	    "Can't select from p4gl_function\n$DBI::errstr"
    );
  my(@row);
  @row = $sth->fetchrow_array();
	my $functionComment; 
	if ( defined(@row) )
	{
		#$obj->{log}->log("Comentários : $row[0]");
		my $comment = $row[0];
		$comment =~ s/^ *//g; $comment =~ s/ *$//g;
		$comment =~ s/^	*//g; $comment =~ s/	*$//g;
	  $obj->{commentText} = $comment;
	}
	else
	{
		$obj->{log}->log("Não encontrou comentário para função %s\n",$functionName);
	}
  undef $sth;
}


#  ===========================================================================
#  Selecciona todos os processos associados a função
#    @param $_[0] Nome da função
#    @return Lista com processos da função
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
		  "Seleção de processo",
		  "Can't prepare select from function process\n$DBI::errstr"
    );
		return;
	}
  $sth->bind_param(1,$obj->{sourceFile});
  $sth->bind_param(2,$functionName);
  $sth->execute() || 
		$obj->{err}->error(
		  "Selecção de processo",
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
#  Selecciona ia informação sobre os parametros a função
#    @param $_[0] Nome da função
#    @return Lista com os parâmetros da função
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
		  "Seleção de parametros",
		  "Can't prepare select from function parameter\n$DBI::errstr"
    );
		return 0;
	}
  $sth->bind_param(1,$functionName);
  $sth->bind_param(2,$obj->{sourceFile});
  $sth->execute() || 
		$obj->{err}->error(
		  "Selecção de parametro",
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
		# @todo - Meter numa hash com os três campos
		#push($obj->{parametersList},\%parameter);
  }
  undef $sth;
}

#  ===========================================================================
#  Faz backup do directório corrente e muda-se para aquele onde o source 
#  se encontra.
#  ===========================================================================
sub changeToSourceDir
{
  my $obj = shift;
	$obj->{currentDir} = getcwd();
	if ( ! chdir $obj->{fglDirectory} )
	{
	  $obj->{err}->error(
		  "Mudança de directório",
		  "Can't change to ($obj->{fglDirectory}):\n$!"
    );
  }
}

#  ===========================================================================
#  Muda-se para o directório onde o programa estava antes de usar este 
#  objecto
#  ===========================================================================
sub changeToOriginalDir
{
  my $obj = shift;
	if ( ! chdir $obj->{currentDir} )
	{
	  $obj->{err}->error(
		  "Mudança de directório",
		  "Can't change to ($obj->{currentDir}):\n$!"
    );
  }
}

#  ===========================================================================
#  Formata devidamente o comentario da funçao:
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
			# @todo O separador é retirado e deve ser mantido
			push(@returningList,$tmpLine);
		}
	}
	return @returningList;
}

return 1;

