#!/usr/bin/perl -w

# ============================================================================
# 
#  Geração da documentação de um package ou conjunto de 4gl(s)
#
#  @todo A toolbar podia ser reutilizada
#
#  $Author: afalout $
#  $Date: 2001-12-26 07:32:37 $
#  $Id: ExportHtml.pm,v 1.1.1.1 2001-12-26 07:32:37 afalout Exp $
#
# ============================================================================

package FglDocumenter::ExportHtml;

use strict;
use File::Find;
use File::stat;
use POSIX;
use Shell;       
use FglDocumenter::FglDocLocation;


#  =========================================================================
#  Constructor
#
#  @todo - Ler as strings do objecto de internacionalizaçao
#  =========================================================================
sub new
{
	my $exportHtml = {
    "err"                => 0,
	  "log"                => 0,
    "progressListener"   => 0,
	  "dbh"                => 0,
		"originalDir"        => "",
    "destinationDir"     => "",
    "ignoreExistDir"     => 1,
    "flagErro"           => 0,
    "paramPackages"      => 0,
    "paramFiles"         => 0,
    "packages"           => 0,
    "processes"          => 0,
    "files"              => 0,
	  "packageMethods"     => 0,
	  "methods"            => 0,
	  "methodSummaryStr"   => "Resumo de Funções",
	  "packageStr"         => "Directório",
	  "packagesStr"        => "Directórios",
	  "allModulesStr"      => "Todos os módulos",
	  "moduleStr"          => "Módulo",
	  "modulesStr"         => "Módulos",
	  "overviewStr"        => "Introdução",
	  "methodDetail"       => "Descrição de funções",
	  "moduleInformation"  => 0,
	};
	bless $exportHtml, "FglDocumenter::ExportHtml";
	return $exportHtml;
}


#  ===========================================================================
#  Afecta a referência para o repositório
#  ===========================================================================
sub setRepository
{
  my $obj = shift;
	$obj->{repository} = shift;
	$obj->{dbh} = $obj->{repository}->getConnection();
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


#  ===========================================================================
#  Afecta o directorio destino onde a arvore de html sera gerada
#  ===========================================================================
sub setDestinationDir
{
  my $obj = shift;
  $obj->{destinationDir}  = shift;
}

#  ===========================================================================
#  Afecta a flag que indica se se ignora ou nao a existencia de directorios
#  ===========================================================================
sub setIgnoreExistDir
{
  my $obj = shift;
  $obj->{ignoreExistDir} = shift;
}

#  ===========================================================================
#  Afecta a listade packages para os quais se pretende gerar a documentação
#  ===========================================================================
sub setParamPackages
{
  my $obj = shift;
  $obj->{paramPackages}  => (),
}

#  ===========================================================================
#  
#  ===========================================================================
sub setParamFiles
{
  my $obj = shift;
  $obj->{paramFiles}     = shift;
}

#  ===========================================================================
#  
#  ===========================================================================
sub setPackages
{
  my $obj = shift;
  $obj->{packages}       = shift;
}

#  ===========================================================================
#  
#  ===========================================================================
sub setProcesses
{
  my $obj = shift;
  $obj->{processes}      = shift;
}

#  ===========================================================================
#  
#  ===========================================================================
sub setFiles
{
  my $obj = shift;
  $obj->{files}          = shift;
}

#  ===========================================================================
#  
#  ===========================================================================
sub setPackageMethods
{
  my $obj = shift;
  $obj->{packageMethods} = shift;
}

#  ===========================================================================
#  
#  ===========================================================================
sub setMethods
{
  my $obj = shift;
  $obj->{methods}        = shift;
}

#  ===========================================================================
#  Obtem o nome do package a partir no nome do ficheiro
#  ===========================================================================
sub getPackageName
{
  my $obj = shift;
  my $dirName = dirname($_[0]);
	chomp($dirName);
	return $dirName;
}

#  ===========================================================================
#  Selecciona os packages existentes no repositorio e guarda-os numa lista
#  ===========================================================================
sub selectPackages
{
  my $obj = shift;
	$obj->{packages} = ();
  my $sth = $obj->{dbh}->prepare(q% SELECT id_package FROM p4gl_package %);
  if ( ! $sth )
	{
		$obj->{err}->error(
		  "Seleção de package",
		  "Can't prepare select from p4gl_package\n$DBI::errstr"
    );
		return;
	}
  $sth->execute() || 
		$obj->{err}->error(
		  "Selecção de package",
	    "Can't select from p4gl_package\n$DBI::errstr"
    );
  my(@row);
  my(@packageList);
  while (@row = $sth->fetchrow_array())
  {
		push(@packageList,$row[0]);
  }
	$obj->{packages} = \@packageList;
  undef $sth;
}

#  ===========================================================================
#  Selecciona todos os módulos e carrega-os numa lista da classe
#  ===========================================================================
sub selectProcesses
{
  my $obj = shift;
	$obj->{processes} = ();
  my $sth = $obj->{dbh}->prepare(q%
	  SELECT id_process FROM p4gl_process
	%);
  if ( ! $sth )
	{
		$obj->{err}->error(
		  "Seleção de processos",
		  "Can't prepare select from processes\n$DBI::errstr"
    );
		return;
	}
  $sth->execute() || 
		$obj->{err}->error(
		  "Selecção de processos",
	    "Can't select from p4gl_process\n$DBI::errstr"
    );
  my(@row);
  my(@processList);
  while (@row = $sth->fetchrow_array())
  {
		my $processId = $row[0];
	  $processId =~ s/^ *//g; $processId =~ s/ *$//g;
		push(@processList,$processId);
  }
	$obj->{processes} = \@processList;
  undef $sth;
}

#  ===========================================================================
#  Selecciona os processos por pai
#  @param $parentProcess O código do processo pai
#  @return Lista de processos filhos
#  ===========================================================================
sub selectDetailProcesses
{
  my $obj = shift;
  my $parentProcess = shift;
  my $sth;
	if ( $parentProcess eq "top" )
	{
    $sth = $obj->{dbh}->prepare(qq%
	    SELECT id_process FROM p4gl_process 
		    where sub_process_of is null
	  %);
	}
	else
	{
    $sth = $obj->{dbh}->prepare(qq%
	    SELECT id_process FROM p4gl_process 
		    where sub_process_of = '$parentProcess'
	  %);
	}
  if ( ! $sth )
	{
		$obj->{err}->error(
		  "Seleção de processos",
		  "Can't prepare select from processes\n$DBI::errstr"
    );
		return;
	}
  $sth->execute() || 
		$obj->{err}->error(
		  "Selecção de processos",
	    "Can't select from p4gl_process\n$DBI::errstr"
    );
  my(@row);
  my(@processList);
  while (@row = $sth->fetchrow_array())
  {
		my $processId = $row[0];
	  $processId =~ s/^ *//g; $processId =~ s/ *$//g;
		push(@processList,$processId);
  }
  undef $sth;
	return \@processList;
}

#  ===========================================================================
#  Devolve o nome do ficheiro
#  ===========================================================================
sub getFileName
{
  my $obj = shift;
  my $fileName = basename($_[0]);
	chomp($fileName);
	return $fileName;
}

#  ===========================================================================
#  Testa se existe e cria o directorio enviado como parametro
#
#  @return 1 - OK, 0 caso contrario
#  ===========================================================================
sub testCreateDir
{
  my $obj = shift;
  my $dir = shift;
	if ( -d $dir )
	{
		if ( $obj->{ignoreExistDir} == 0 )
		{
		  return 0;
		}
    $obj->{log}->log("Directory $dir exists allready \n");
		return 1;
	}

	unless (mkdir($dir) )
	{
	  $obj->{err}->error(
			"Criaçao de directorio para gerar html",
		  "Error creating $dir :$!"
    );		
		return 0;
  }
  $obj->{log}->log("Directory $dir created \n");
  return 1;
}

#  ===========================================================================
#  Cria a arvore de directorios onde sera colocada a documentaçao estatica a 
#  gerar.
#
#  Se ja existir para ja da erro.
#
#  A estrutura do directorio  e seu conteudo sera:
#    - Dir html
#       index.html
#       processList.html e(ou) javascript com tree
#       packageList.html e(ou) javascript com tree
#       allModules.html
#       allTodos.html
#       alphabetic_list.html
#       fgldoc.css
#       - Processo A:
#          Descricao.html
#          Modulos.html
#       - Processo B
#          Descricao.html
#          Modulos.html
#       - Modulo A
#          Descricao.html
#          ListaTarefas.html
#       - Modulo B
#          Descricao.html
#          ListaTarefas.html
#       - Package A
#          Descricao.html
#          Modulos.html
#       - Package B
#          Descricao.html
#          Modulos.html
#
#  Para efectuar esta criaçao assume carregado:
#    - Lista de processos
#    - Lista de packages
#  ===========================================================================
sub createDirTree
{
  my $obj = shift;
  $obj->{log}->log("Creating directory tree in %s\n",
	  $obj->{destinationDir}
	);

	# mkdir dest_dir
	if ( $obj->testCreateDir($obj->{destinationDir}) == 0 )
	{
	  return 0;
	}

	# mkdir html
	if ( $obj->testCreateDir($obj->{destinationDir} . "/html" ) == 0 )
	{
	  return 0;
	}

	# Para cada processo mkdir $processName
	my $arrayRef = $obj->{processes};
	my @array = @$arrayRef;
	my $process;
	foreach $process ( @array )
	{
	  if ( $obj->testCreateDir($obj->{destinationDir} . "/$process" ) == 0 )
	  {
	    return 0;
	  }
	}
	
	# Para cada package mkdir $processName
	my $arrayRef = $obj->{packages};
	my @array = @$arrayRef;
	my $package;
	foreach $package ( @array )
	{
	  if ( $obj->testCreateDir($obj->{destinationDir} . "/$package" ) == 0 )
	  {
	    return 0;
	  }
	}
}

#  ===========================================================================
#  Gera o html com a lista de modulos para o processo enviado como parametro
#    @todo Terminar esta implementaçao
#  ===========================================================================
sub genModulesForProcess
{
  my $obj = shift;
	my $processId = shift;
  my $modListRef = $obj->selectModulesForProcess($processId);
	my @moduleList = @$modListRef;
	my $modulesHtmlName;
	if ( $processId eq "AllModules" )
	{
	  $modulesHtmlName = $obj->{destinationDir} . "/AllModules.html";
  }
	else
	{
	  $modulesHtmlName = $obj->{destinationDir} . "/$processId/modules.html";
	}
  open(MODPROCHTML, "> $modulesHtmlName") || 
	  die "Cant open $modulesHtmlName : $!";
  printf MODPROCHTML qq|
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Frameset//EN""http://www.w3.org/TR/REC-html40/frameset.dtd">
<!--NewPage-->
<HTML>
  <HEAD><!-- Generated by fgldoc on ??? TODO ???? -->
    <TITLE>All Processes</TITLE>
    <LINK REL ="stylesheet" TYPE="text/css" HREF="stylesheet.css" TITLE="Style">
  </HEAD>

<BODY BGCOLOR="white">
<TABLE BORDER="0" WIDTH="100%">
  <TR>
    <TD NOWRAP><FONT size="+1" CLASS="FrameTitleFont"><B></B></FONT></TD>
  </TR>
</TABLE>

<TABLE BORDER="0" WIDTH="100%">
  <TR><TD NOWRAP><FONT CLASS="FrameItemFont">
		  <A HREF="AllModules.html" TARGET="modulesFrame">
			  $obj->{allModulesStr}
			</A>
	</FONT>
  <P>

  <FONT size="+1" CLASS="FrameHeadingFont">$obj->{packagesStr}</FONT>
|;

  my $module;
  foreach $module (@moduleList)
	{
    printf(MODPROCHTML qq|
<BR>
<FONT CLASS="FrameItemFont">
<A HREF="../%s.html" TARGET="descriptionsFrame">%s</A></FONT>
|,
		  $module,$module
    );
  }

  print MODPROCHTML qq|
    <BR>
    </TD>
  </TR>
</TABLE>

<P>
&nbsp;
</BODY>
</HTML>
|;
}

#  ===========================================================================
#  Selecciona os modulos do processo e guarda-os numa lista, devolvendo-a
#    @todo - Terminar isto
#  ===========================================================================
sub selectModulesForProcess
{
  my $obj = shift;
	my $processId = shift;
	my $sth;
	if ( $processId eq "AllModules" )
	{
    $sth = $obj->{dbh}->prepare(qq% 
	    SELECT unique module_name FROM p4gl_module 
	  %);
	}
	else
	{
    $sth = $obj->{dbh}->prepare(qq% 
	    SELECT unique module_name FROM p4gl_fun_process 
		  WHERE id_process = '$processId'
	  %);
	}
  if ( ! $sth )
	{
		$obj->{err}->error(
		  "Selecção de package",
		  "Can't prepare select from p4gl_package\n$DBI::errstr"
    );
		return;
	}
  $sth->execute() || 
		$obj->{err}->error(
		  "Selecção de package",
	    "Can't select from p4gl_packaghe\n$DBI::errstr"
    );
  my(@row);
  my(@moduleList);
  while (@row = $sth->fetchrow_array())
  {
		my $module = $row[0];
	  $module =~ s/^ *//g; $module =~ s/ *$//g;
		push(@moduleList,$module);
  }
  undef $sth;
	return \@moduleList;
}

#  ===========================================================================
#  Gera o html com a descriçao do processo enviado como parametro
#  @todo Implementar
#  ===========================================================================
sub genDescriptionForProcess($object,$process)
{
  my $obj = shift;
	my $processId = shift;
}

#  ===========================================================================
#  Gera a documentaçao para todos os processos carregados na respectiva lista
#  ===========================================================================
sub genProcessesDocumentation
{
  my $obj = shift;
	my $arrayRef = $obj->{processes};
	my @array = @$arrayRef;
	my $process;
	foreach $process ( @array )
	{
	  $obj->genModulesForProcess($process);
	  $obj->genDescriptionForProcess($process);
	}
}

#  ===========================================================================
#  Gera a documentaçao para todos os packages carregados na respectiva lista
#  ===========================================================================
sub genPackagesDocumentation
{
  my $obj = shift;
}

#  ===========================================================================
#  Gera a documentação para os packages e(ou sources definidos
#  Pode ser pedida a geraçao de uma das seguintes formas:
#    - Para todo o conteudo do repositorio
#    - Para um processo e(ou) sub-processos
#    - Para um package
#  Existem as seguintes opçoes que podera ser gerada:
#    - Gerar lista de tarefas
#    - Gerar indice(s) alfabetico(s) de nomes de funçoes
#  ===========================================================================
sub genHtml
{
  my $obj = shift;
	$obj->genBaseDocumentation();
	$obj->genProcessesDocumentation();
	$obj->genPackagesDocumentation();
}


#  ===========================================================================
#  Gera os documentos da base da documentação e que tem referências para
#  os diferentes packages e(ou) métodos
#  ===========================================================================
sub genBaseDocumentation
{
  my $obj = shift;
	$obj->genCss();
	$obj->genTreeviewJs();
	$obj->genTreeHtml();
	$obj->genTreeJs();
	$obj->copyGifs();
  $obj->genIndexHtml();
	$obj->genIndexAllHtml();
	$obj->genAllProcessesHtml();
	$obj->genModulesForProcess("AllModules");
	# @todo Meter a gerar all modules ????
	#$obj->genAllModulesFrameHtml();
	$obj->genHtmlForeachModule();
}

#  ===========================================================================
#  Gera o cascade style sheet usado para a documentação
#  ===========================================================================
sub genCss()
{
  my $obj = shift;
	my $cssName = $obj->{destinationDir} . "/stylesheet.css";
  open(CSS, "> $cssName") || die "Cant open $cssName";
  printf CSS qq|
/* Fgldoc style sheet */

/* Define colors, fonts and other style attributes here to override the defaults  */

/* Page background color */
body { background-color: #FFFFFF }

/* Table colors */
.TableHeadingColor     { background: #CCCCFF } /* Dark mauve */
.TableSubHeadingColor  { background: #EEEEFF } /* Light mauve */
.TableRowColor         { background: #FFFFFF } /* White */

/* Font used in left-hand frame lists */
.FrameTitleFont   { font-size: normal; font-family: normal }
.FrameHeadingFont { font-size: normal; font-family: normal }
.FrameItemFont    { font-size: normal; font-family: normal }

/* Example of smaller, sans-serif font in frames */
/* .FrameItemFont  { font-size: 10pt; font-family: Helvetica, Arial, sans-serif } */

/* Navigation bar fonts and colors */
.NavBarCell1    { background-color:#EEEEFF;}/* Light mauve */
.NavBarCell1Rev { background-color:#00008B;}/* Dark Blue */
.NavBarFont1    { font-family: Arial, Helvetica, sans-serif; color:#000000;}
.NavBarFont1Rev { font-family: Arial, Helvetica, sans-serif; color:#FFFFFF;}

.NavBarCell2    { font-family: Arial, Helvetica, sans-serif; background-color:#FFFFFF;}
.NavBarCell3    { font-family: Arial, Helvetica, sans-serif; background-color:#FFFFFF;}
|;
  close(CSS);
}

#  ===========================================================================
#  Gera o html que mostra o javascript da arvore
#  ===========================================================================
sub genTreeHtml
{
  my $obj = shift;
	my $treehtmName = $obj->{destinationDir} . "/tree.html";
  open(TREEHTM, "> $treehtmName") || die "Cant open $treehtmName";
  print TREEHTM qq|
<html><head>
<link rel="stylesheet" href="doxygen.css">
<script src="treeview.js"></script>
<script src="tree.js"></script>
<script>
initializeDocument()
</script>
</head>
<body bgcolor="#ffffff">
</body>
</html>
|;
}

#  ===========================================================================
#  Gera o Javascript para mostrar os sources organizados numa arvore em 
#  Javascript
#  Optou-se pela geraçao aqui pois fica mais compacto.
#  ===========================================================================
sub genTreeJs
{
  my $obj = shift;
	my $treejsName = $obj->{destinationDir} . "/tree.js";
  open(TREEJS, "> $treejsName") || die "Cant open $treejsName";
  printf TREEJS qq|
  foldersTree = gFld("<b>Processos</b>", "", "")
  insDoc(foldersTree, 
	  gLnk("$obj->{allModulesStr}", "", "all_processes.html", "modulesFrame"))
|;
	$obj->genJsForProcess("top","foldersTree");
}

#  ===========================================================================
#  Gera o javascript para o processo
#    @todo Resolver o problema do(s) link(s).
#    @param Processo para o qual se vai detalhar a arvore
#  ===========================================================================
sub genJsForProcess
{
  my $obj = shift;
  my $parentProcess = shift;
  my $lastFolder = shift;
  my $refProcs = $obj->selectDetailProcesses($parentProcess);
	my @processList = @$refProcs;
	if ( $#processList >= 0 )
	{
		my $processName = $parentProcess;
		if ( $parentProcess eq "top" )
		{
		  #$processName = "Processos";
		}
		else
		{
	    print TREEJS qq%
  $parentProcess = insFld($lastFolder, gFld("$processName", "", "files.html"))
%;
	    $lastFolder = $parentProcess;
		}
	}
	else
	{
	  print TREEJS qq%
  insDoc($lastFolder, 
	  gLnk("$parentProcess", "", "$parentProcess/modules.html","modulesFrame"))
%;
	}
	my $i = 0;
	while ( $i <= $#processList )
	{
    $obj->genJsForProcess($processList[$i],$lastFolder);
		$i++;
	}
}

#  ===========================================================================
#  Copia os gif(s) para o directório onde a documentação em html será gerada
#  ===========================================================================
sub copyGifs
{
  my $obj = shift;
	my $destinationDir = $obj->{destinationDir};
	my $sourceDir      = FglDocumenter::FglDocLocation::getLocation() . "/img";
  system "cp $sourceDir/ftv2blank.gif        $destinationDir" 
	  || die "Cant copy file : $!";
  system "cp $sourceDir/ftv2doc.gif          $destinationDir" 
	  || die "Cant copy file : $!";
  system "cp $sourceDir/ftv2folderclosed.gif $destinationDir" 
	  || die "Cant copy file : $!";
  system "cp $sourceDir/ftv2folderopen.gif   $destinationDir" 
	  || die "Cant copy file : $!";
  system "cp $sourceDir/ftv2lastnode.gif     $destinationDir" 
	  || die "Cant copy file : $!";
  system "cp $sourceDir/ftv2link.gif         $destinationDir" 
	  || die "Cant copy file : $!";
  system "cp $sourceDir/ftv2mlastnode.gif    $destinationDir" 
	  || die "Cant copy file : $!";
  system "cp $sourceDir/ftv2mnode.gif        $destinationDir" 
	  || die "Cant copy file : $!";
  system "cp $sourceDir/ftv2node.gif         $destinationDir" 
	  || die "Cant copy file : $!";
  system "cp $sourceDir/ftv2plastnode.gif    $destinationDir" 
	  || die "Cant copy file : $!";
  system "cp $sourceDir/ftv2pnode.gif        $destinationDir" 
	  || die "Cant copy file : $!";
  system "cp $sourceDir/ftv2vertline.gif     $destinationDir" 
	  || die "Cant copy file : $!";
}

#  ===========================================================================
#  Gera o Javascript para mostrar os sources organizados numa arvore em 
#  Javascript
#  Optou-se pela geraçao aqui pois fica mais compacto.
#  ===========================================================================
sub genTreeviewJs
{
  my $obj = shift;
	my $tvjsName = $obj->{destinationDir} . "/treeview.js";
  open(TVJS, "> $tvjsName") || die "Cant open $tvjsName";
  printf TVJS qq^
//**************************************************************** 
// You are free to copy the "Folder-Tree" script as long as you  
// keep this copyright notice: 
// Script found in: http://www.geocities.com/Paris/LeftBank/2178/ 
// Author: Marcelino Alves Martins (martins\@hks.com) December '97. 
//**************************************************************** 
 
//Log of changes: 
//       17 Feb 98 - Fix initialization flashing problem with Netscape
//       
//       27 Jan 98 - Root folder starts open; support for USETEXTLINKS; 
//                   make the ftien4 a js file 
//       
// DvH:  Dec 2000 -  Made some minor changes to support external 
//                   references
 
// Definition of class Folder 
// ***************************************************************** 
 
function Folder(folderDescription, tagName, hreference) //constructor 
{ 
  //constant data 
  this.desc = folderDescription 
  this.tagName = tagName
  this.hreference = hreference 
  this.id = -1   
  this.navObj = 0  
  this.iconImg = 0  
  this.nodeImg = 0  
  this.isLastNode = 0 
 
  //dynamic data 
  this.isOpen = true 
  this.iconSrc = "ftv2folderopen.gif"   
  this.children = new Array 
  this.nChildren = 0 
 
  //methods 
  this.initialize = initializeFolder 
  this.setState = setStateFolder 
  this.addChild = addChild 
  this.createIndex = createEntryIndex 
  this.hide = hideFolder 
  this.display = display 
  this.renderOb = drawFolder 
  this.totalHeight = totalHeight 
  this.subEntries = folderSubEntries 
  this.outputLink = outputFolderLink 
} 
 
function setStateFolder(isOpen) 
{ 
  var subEntries 
  var totalHeight 
  var fIt = 0 
  var i=0 
 
  if (isOpen == this.isOpen) 
    return 
 
  if (browserVersion == 2)  
  { 
    totalHeight = 0 
    for (i=0; i < this.nChildren; i++) 
      totalHeight = totalHeight + this.children[i].navObj.clip.height 
      subEntries = this.subEntries() 
    if (this.isOpen) 
      totalHeight = 0 - totalHeight 
    for (fIt = this.id + subEntries + 1; fIt < nEntries; fIt++) 
      indexOfEntries[fIt].navObj.moveBy(0, totalHeight) 
  }  
  this.isOpen = isOpen 
  propagateChangesInState(this) 
} 
 
function propagateChangesInState(folder) 
{   
  var i=0 
 
  if (folder.isOpen) 
  { 
    if (folder.nodeImg) 
      if (folder.isLastNode) 
        folder.nodeImg.src = "ftv2mlastnode.gif" 
      else 
	  folder.nodeImg.src = "ftv2mnode.gif" 
    folder.iconImg.src = "ftv2folderopen.gif" 
    for (i=0; i<folder.nChildren; i++) 
      folder.children[i].display() 
  } 
  else 
  { 
    if (folder.nodeImg) 
      if (folder.isLastNode) 
        folder.nodeImg.src = "ftv2plastnode.gif" 
      else 
	  folder.nodeImg.src = "ftv2pnode.gif" 
    folder.iconImg.src = "ftv2folderclosed.gif" 
    for (i=0; i<folder.nChildren; i++) 
      folder.children[i].hide() 
  }  
} 
 
function hideFolder() 
{ 
  if (browserVersion == 1 || browserVersion == 3) { 
    if (this.navObj.style.display == "none") 
      return 
    this.navObj.style.display = "none" 
  } else { 
    if (this.navObj.visibility == "hidden") 
      return 
    this.navObj.visibility = "hidden" 
  } 
   
  this.setState(0) 
} 
 
function initializeFolder(level, lastNode, leftSide) 
{ 
var j=0 
var i=0 
var numberOfFolders 
var numberOfDocs 
var nc 
      
  nc = this.nChildren 
   
  this.createIndex() 
 
  var auxEv = "" 
 
  if (browserVersion > 0) 
    auxEv = "<a href='javascript:clickOnNode("+this.id+")'>" 
  else 
    auxEv = "<a>" 
 
  if (level>0) 
    if (lastNode) //the last 'brother' in the children array 
    { 
      this.renderOb(leftSide + auxEv + "<img name='nodeIcon" + this.id + "' src='ftv2mlastnode.gif' width=16 height=22 border=0></a>") 
      leftSide = leftSide + "<img src='ftv2blank.gif' width=16 height=22>"  
      this.isLastNode = 1 
    } 
    else 
    { 
      this.renderOb(leftSide + auxEv + "<img name='nodeIcon" + this.id + "' src='ftv2mnode.gif' width=16 height=22 border=0></a>") 
      leftSide = leftSide + "<img src='ftv2vertline.gif' width=16 height=22>" 
      this.isLastNode = 0 
    } 
  else 
    this.renderOb("") 
   
  if (nc > 0) 
  { 
    level = level + 1 
    for (i=0 ; i < this.nChildren; i++)  
    { 
      if (i == this.nChildren-1) 
        this.children[i].initialize(level, 1, leftSide) 
      else 
        this.children[i].initialize(level, 0, leftSide) 
      } 
  } 
} 
 
function drawFolder(leftSide) 
{ 
  if (browserVersion == 2) { 
    if (!doc.yPos) 
      doc.yPos=8 
    doc.write("<layer id='folder" + this.id + "' top=" + doc.yPos + " visibility=hidden>") 
  } 
  if (browserVersion == 3) 
  {
    doc.write("<div id='folder" + this.id + "' style='visibility:hide;'>") 
  }
   
  doc.write("\\n<table ") 
  if (browserVersion == 1) 
    doc.write(" id='folder" + this.id + "' style='position:block;' ") 
  doc.write(" border=0 cellspacing=0 cellpadding=0>") 
  doc.write("\\n<tr><td>") 
  doc.write(leftSide) 
  this.outputLink() 
  doc.write("<img name='folderIcon" + this.id + "' ") 
  doc.write("src='" + this.iconSrc+"' border=0></a>") 
  doc.write("</td>\\n<td valign=middle nowrap>") 
  if (USETEXTLINKS) 
  { 
    this.outputLink() 
    doc.write(this.desc + "</a>") 
  } 
  else 
    doc.write(this.desc) 
  if (this.tagName!="")
  {
    doc.write(" [external]")
  }
  doc.write("</td>")  
  doc.write("\\n</table>\\n") 
   
  if (browserVersion == 2) { 
    doc.write("</layer>") 
  } 
  if (browserVersion == 3) { 
    doc.write("</div>") 
  } 
 
  if (browserVersion == 1) { 
    this.navObj = doc.all["folder"+this.id] 
    this.iconImg = doc.all["folderIcon"+this.id] 
    this.nodeImg = doc.all["nodeIcon"+this.id] 
  } else if (browserVersion == 2) { 
    this.navObj = doc.layers["folder"+this.id] 
    this.iconImg = this.navObj.document.images["folderIcon"+this.id] 
    this.nodeImg = this.navObj.document.images["nodeIcon"+this.id] 
    doc.yPos=doc.yPos+this.navObj.clip.height 
  } else if (browserVersion == 3) {
    this.navObj = doc.getElementById("folder"+this.id)
    this.iconImg = doc.images.namedItem("folderIcon"+this.id)
    this.nodeImg = doc.images.namedItem("nodeIcon"+this.id)
  }
} 
 
function outputFolderLink() 
{ 
  if (this.hreference) 
  { 
    doc.write("<a ")
    if (this.tagName)
    {
      doc.write("doxygen='" + this.tagName + "' ");
    }
    doc.write("href='" + this.hreference + "' TARGET=\\"basefrm\\" ") 
    if (browserVersion > 0) 
      doc.write("onClick='javascript:clickOnFolder("+this.id+")'") 
    doc.write(">") 
  } 
  else 
    doc.write("<a>") 
} 
 
function addChild(childNode) 
{ 
  this.children[this.nChildren] = childNode 
  this.nChildren++ 
  return childNode 
} 
 
function folderSubEntries() 
{ 
  var i = 0 
  var se = this.nChildren 
 
  for (i=0; i < this.nChildren; i++){ 
    if (this.children[i].children) //is a folder 
      se = se + this.children[i].subEntries() 
  } 
 
  return se 
} 
 
 
// Definition of class Item (a document or link inside a Folder) 
// ************************************************************* 
 
function Item(itemDescription, tagName, itemLink) // Constructor 
{ 
  // constant data 
  this.desc = itemDescription 
  this.tagName = tagName
  this.link = itemLink 
  this.id = -1 //initialized in initalize() 
  this.navObj = 0 //initialized in render() 
  this.iconImg = 0 //initialized in render() 
  this.iconSrc = "ftv2doc.gif" 
 
  // methods 
  this.initialize = initializeItem 
  this.createIndex = createEntryIndex 
  this.hide = hideItem 
  this.display = display 
  this.renderOb = drawItem 
  this.totalHeight = totalHeight 
} 
 
function hideItem() 
{ 
  if (browserVersion == 1 || browserVersion == 3) { 
    if (this.navObj.style.display == "none") 
      return 
    this.navObj.style.display = "none" 
  } else { 
    if (this.navObj.visibility == "hidden") 
      return 
    this.navObj.visibility = "hidden" 
  }     
} 
 
function initializeItem(level, lastNode, leftSide) 
{  
  this.createIndex() 
 
  if (level>0) 
    if (lastNode) //the last 'brother' in the children array 
    { 
      this.renderOb(leftSide + "<img src='ftv2lastnode.gif' width=16 height=22>") 
      leftSide = leftSide + "<img src='ftv2blank.gif' width=16 height=22>"  
    } 
    else 
    { 
      this.renderOb(leftSide + "<img src='ftv2node.gif' width=16 height=22>") 
      leftSide = leftSide + "<img src='ftv2vertline.gif' width=16 height=22>" 
    } 
  else 
    this.renderOb("")   
} 
 
function drawItem(leftSide) 
{ 
  if (browserVersion == 2) 
    doc.write("<layer id='item" + this.id + "' top=" + doc.yPos + " visibility=hidden>") 
  if (browserVersion == 3) 
    doc.write("<div id='item" + this.id + "' style='display:block;'>") 
     
  doc.write("\\n<table ") 
  if (browserVersion == 1) 
    doc.write(" id='item" + this.id + "' style='position:block;' ") 
  doc.write(" border=0 cellspacing=0 cellpadding=0>\\n") 
  doc.write("<tr><td>") 
  doc.write(leftSide) 
  if (this.link!="")
  {
    doc.write("<a href=" + this.link + ">") 
  }
  doc.write("<img id='itemIcon"+this.id+"' ") 
  doc.write("src='"+this.iconSrc+"' border=0>") 
  if (this.link!="")
  {
    doc.write("</a>")
  } 
  doc.write("</td>\\n<td valign=middle nowrap>") 
  if (USETEXTLINKS && this.link!="") 
    doc.write("<a href=" + this.link + ">" + this.desc + "</a>") 
  else 
    doc.write(this.desc) 
  if (this.tagName!="")
  {
    doc.write(" [external]");
  }
  doc.write("\\n</table>\\n") 
   
  if (browserVersion == 2) 
    doc.write("</layer>") 
  if (browserVersion == 3) 
    doc.write("</div>")
 
  if (browserVersion == 1) { 
    this.navObj = doc.all["item"+this.id] 
    this.iconImg = doc.all["itemIcon"+this.id] 
  } else if (browserVersion == 2) { 
    this.navObj = doc.layers["item"+this.id] 
    this.iconImg = this.navObj.document.images["itemIcon"+this.id] 
    doc.yPos=doc.yPos+this.navObj.clip.height 
  } else if (browserVersion == 3) {
    this.navObj = doc.getElementById("item"+this.id)
    this.iconImg = doc.images.namedItem("itemIcon"+this.id)
  }
} 
 
 
// Methods common to both objects (pseudo-inheritance) 
// ******************************************************** 
 
function display() 
{ 
  if (browserVersion == 1 || browserVersion == 3) 
    this.navObj.style.display = "block" 
  else 
    this.navObj.visibility = "show" 
} 
 
function createEntryIndex() 
{ 
  this.id = nEntries 
  indexOfEntries[nEntries] = this 
  nEntries++ 
} 
 
// total height of subEntries open 
function totalHeight() //used with browserVersion == 2 
{ 
  var h = this.navObj.clip.height 
  var i = 0 
   
  if (this.isOpen) //is a folder and _is_ open 
    for (i=0 ; i < this.nChildren; i++)  
      h = h + this.children[i].totalHeight() 
 
  return h 
} 
 
 
// Events 
// ********************************************************* 
 
function clickOnFolder(folderId) 
{ 
  var clicked = indexOfEntries[folderId] 
 
  if (!clicked.isOpen) 
    clickOnNode(folderId) 
 
  return  
 
  if (clicked.isSelected) 
    return 
} 
 
function clickOnNode(folderId) 
{ 
  var clickedFolder = 0 
  var state = 0 
 
  clickedFolder = indexOfEntries[folderId] 
  state = clickedFolder.isOpen 
 
  clickedFolder.setState(!state) //open<->close  
} 
 
function initializeDocument() 
{ 
  doc = document;
  if (doc.all) 
    browserVersion = 1 //IE4   
  else 
    if (doc.layers) 
      browserVersion = 2 //NS4 
    else if(navigator.userAgent.toLowerCase().indexOf('gecko') != -1)
        browserVersion = 3 //mozilla
      else 
        browserVersion = 0 //other 

  foldersTree.initialize(0, 1, "") 
  foldersTree.display()
  
  if (browserVersion > 0) 
  { 
    if(browserVersion != 3)
      doc.write("<layer top="+indexOfEntries[nEntries-1].navObj.top+">&nbsp;</layer>") 
 
    // close the whole tree 
    clickOnNode(0) 
    // open the root folder 
    clickOnNode(0) 
  } 
} 
 
// Auxiliary Functions for Folder-Treee backward compatibility 
// ********************************************************* 
 
function gFld(description, tagName, hreference) 
{ 
  folder = new Folder(description, tagName, hreference) 
  return folder 
} 
 
function gLnk(description, tagName, linkData, target) 
{ 
  fullLink = "" 
 
  if (linkData!="")
  {
    fullLink = "'"+linkData+"' target=\\"" + target + "\\"" 
  } 
 
  linkItem = new Item(description, tagName, fullLink)   
  return linkItem 
} 
 
function insFld(parentFolder, childFolder) 
{ 
  return parentFolder.addChild(childFolder) 
} 
 
function insDoc(parentFolder, document) 
{ 
  parentFolder.addChild(document) 
} 
 
// Global variables 
// **************** 
 
USETEXTLINKS = 1
indexOfEntries = new Array 
nEntries = 0 
doc = document 
browserVersion = 0 
selectedFolder=0
^;
}


#  ===========================================================================
#  Gera o index global das frames tratando de fazer a referência às diferentes 
#  frames
#  ===========================================================================
sub genIndexHtml
{
  my $obj = shift;
	my $indexHtmlName = $obj->{destinationDir} . "/index.html";
  open(INDEXHTML, "> $indexHtmlName") || die "Cant open $indexHtmlName";
  printf INDEXHTML qq|
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN""http://www.w3.org/TR/REC-html40/loose.dtd>
<!--NewPage-->
<HTML>
<HEAD>
  <!-- Generated by fgldoc on ??? TODO ???? -->
  <TITLE> Generated Documentation (Untitled) </TITLE>
</HEAD>

<FRAMESET cols="20%%,80%%">
  <FRAMESET rows="30%%,70%%">
    <!-- <FRAME src="all_processes.html" name="agregatorFrame"> -->
    <FRAME src="tree.html" name="agregatorFrame">
    <FRAME src="AllModules.html" name="modulesFrame">
  </FRAMESET>
  <FRAME src="overview-summary.html" name="descriptionsFrame">
</FRAMESET>
<NOFRAMES>
<H2>
Frame Alert</H2>

<P>
This document is designed to be viewed using the frames feature. If you see this message, you are using a non-frame-capable web client.
<BR>
Link to <A HREF="overview-summary.html">Non-frame version.</A></NOFRAMES>
</HTML>
|;
  close (INDEXHTML);
}

#  ===========================================================================
#  Gera o indice global de todos os métodos dos módulos analisados
#    @todo Implementar esta feature
#  ===========================================================================
sub genIndexAllHtml
{
  my $obj = shift;
}


# ============================================================================
# Gera a frame de overview que é aquela o mais à esquerda possivel
# Contem uma referencia para modificar a lista de métodos para todos ou de
# cada package especifico
# ============================================================================
sub genAllProcessesHtml()
{
  my $obj = shift;
	my $allProcessesHtmlName = $obj->{destinationDir} . "/all_processes.html";
  open(ALLPROCHTML, "> $allProcessesHtmlName") || 
	  die "Cant open $allProcessesHtmlName $!";
  print ALLPROCHTML qq|
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Frameset//EN""http://www.w3.org/TR/REC-html40/frameset.dtd">
<!--NewPage-->
<HTML>

  <HEAD>
	  <!-- Generated by fgldoc on ??? TODO ???? -->
    <TITLE>All Processes</TITLE>
    <LINK REL ="stylesheet" TYPE="text/css" HREF="stylesheet.css" TITLE="Style">
  </HEAD>

<BODY BGCOLOR="white">

<TABLE BORDER="0" WIDTH="100%">
  <TR>
    <TD NOWRAP><FONT size="+1" CLASS="FrameTitleFont"><B></B></FONT></TD>
  </TR>
</TABLE>

<TABLE BORDER="0" WIDTH="100%">
  <TR><TD NOWRAP><FONT CLASS="FrameItemFont">
		<A HREF="AllModules.html" TARGET="modulesFrame">
		  $obj->{allModulesStr}
		</A>
	</FONT>
  <P>

  <FONT size="+1" CLASS="FrameHeadingFont">$obj->{packageStr}</FONT>
|;

	my $arrayRef = $obj->{processes};
	my @array = @$arrayRef;
	my $process;
	foreach $process ( @array )
	{
    printf(ALLPROCHTML qq|
<BR>
<FONT CLASS="FrameItemFont">
<A HREF="%s/modules.html" TARGET="modulesFrame">%s</A></FONT>
|,
		  $process,$process
    );
  }

  print ALLPROCHTML qq|
<BR>
</TD>
</TR>
</TABLE>

<P>
&nbsp;
</BODY>
</HTML>
|;

  close(OVERVIEWHTML);
}

# ============================================================================
# Gera a navbar de acordo com os parametros definidos
#   @param 1 - Location (bottom ou top) anchor
#   @param 2 - URL path
#   @param 3 - Opção corrente da navbar
# ============================================================================
sub genNavBar
{
  my $obj = shift;
  my $locationAnchor = shift;
	my $urlPath = shift;
	my $dumm = shift;
	my $overviewBgColor = "#EEEEFF";
	my $packageBgColor  = "#EEEEFF";
	my $moduleBgColor   = "#EEEEFF";
	if ( $_[2] eq "OVERVIEW" )
	{
	  $overviewBgColor = "#FFFFFF";
	}
	elsif ( $_[2] eq "PACKAGE" )
	{
	  $packageBgColor = "#FFFFFF";
	}
	elsif ( $_[2] eq "MODULE" )
	{
	  $moduleBgColor = "#FFFFFF";
	}
  my $navString = qq|
<!-- ========== START OF NAVBAR ========== -->
<A NAME="$locationAnchor"><!-- --></A>
<TABLE BORDER="0" WIDTH="100%" CELLPADDING="1" CELLSPACING="0">
  <TR>
    <TD COLSPAN=2 BGCOLOR="#EEEEFF" CLASS="NavBarCell1">
      <A NAME="navbar_top_firstrow"><!-- --></A>

  <TABLE BORDER="0" CELLPADDING="0" CELLSPACING="3">
    <TR ALIGN="center" VALIGN="top">

      <TD BGCOLOR="$overviewBgColor" CLASS="NavBarCell1Rev"> &nbsp;
		    <FONT CLASS="NavBarFont1Rev"><B>$obj->{overviewStr}</B></FONT>&nbsp;</TD>
  
      <TD BGCOLOR="#EEEEFF" CLASS="NavBarCell1">    
		    <FONT CLASS="$packageBgColor">$obj->{packageStr}</FONT>&nbsp;</TD>
  
      <TD BGCOLOR="#EEEEFF" CLASS="NavBarCell1">    
		    <FONT CLASS="$moduleBgColor">$obj->{moduleStr}</FONT>&nbsp;</TD>
  
		<!-- Por enquanto nenhum destes se usa
      <TD BGCOLOR="#EEEEFF" CLASS="NavBarCell1">    
		    <A HREF="overview-tree.html">
			  <FONT CLASS="NavBarFont1"><B>Tree</B></FONT></A>&nbsp;</TD>
  
      <TD BGCOLOR="#EEEEFF" CLASS="NavBarCell1">    
		    <A HREF="deprecated-list.html">
				  <FONT CLASS="NavBarFont1"><B>Deprecated</B></FONT></A>&nbsp;</TD>
  
      <TD BGCOLOR="#EEEEFF" CLASS="NavBarCell1">    
		    <A HREF="index-all.html"><FONT CLASS="NavBarFont1">
			    <B>Index</B></FONT></A>&nbsp;</TD>
  
      <TD BGCOLOR="#EEEEFF" CLASS="NavBarCell1">    
		    <A HREF="help-doc.html"><FONT CLASS="NavBarFont1">
			    <B>Help</B></FONT></A>&nbsp;</TD>
				-->
    </TR>
  </TABLE>

</TD>

<TD ALIGN="right" VALIGN="top" ROWSPAN=3><EM>
</EM>
</TD>
</TR>

		<!-- Por enquanto nenhum destes se usa
  <TR>
    <TD BGCOLOR="white" CLASS="NavBarCell2"><FONT SIZE="-2">
      &nbsp;PREV&nbsp;
      &nbsp;NEXT</FONT></TD>
  
    <TD BGCOLOR="white" CLASS="NavBarCell2">
	    <FONT SIZE="-2">
        <A HREF="index.html" TARGET="_top"><B>FRAMES</B></A>  &nbsp;&nbsp;
		    <A HREF="overview-summary.html" TARGET="_top"><B>NO FRAMES</B></A>
		  </FONT>
    </TD>
  </TR>
	-->
</TABLE>
<!-- =========== END OF NAVBAR =========== -->
|;

  return $navString;
}

# ============================================================================
# Com base na string com o pathname do package gera os .. necessarios
#   @param 0 - Path do package
# ============================================================================
sub getPackageRef
{
  my $obj = shift;
  my $dotDot = $_[0];
	$dotDot =~ s|/.*/|/../|g;
	$dotDot =~ s|^.[^/]/|../|g;
	$dotDot =~ s|/.[^/]$|/..|g;
	return $dotDot;
}

#  ===========================================================================
#  selecciona todos os modulos e mete num array
#  ===========================================================================
sub selectAllModules
{
  my $obj = shift;
	my $module = shift;

  my $sth = $obj->{dbh}->prepare(q% 
	  SELECT module_name FROM p4gl_module 
  %);
  if ( ! $sth )
	{
		$obj->{err}->error(
		  "Selecção de modulo",
		  "Can't prepare select from p4gl_module\n$DBI::errstr"
    );
		return;
	}
  $sth->execute() || 
		$obj->{err}->error(
		  "Selecção de modulo",
	    "Can't select from p4gl_module\n$DBI::errstr"
    );
  my(@row);
  my(@moduleList);
  while (@row = $sth->fetchrow_array())
  {
		my $module = $row[0];
	  $module =~ s/^ *//g; $module =~ s/ *$//g;
		push(@moduleList,$module);
  }
  undef $sth;
	return \@moduleList;
}

#  ===========================================================================
#  Gera o html relativo a documentaçao de um modulo
#  ===========================================================================
sub genHtmlForeachModule
{
  my $obj = shift;
	my $modListRef = $obj->selectAllModules();
	my @moduleList = @$modListRef;
	my $module;
	foreach $module ( @moduleList )
	{
	  $obj->genHtmlForModule($module);
	}
}

#  ===========================================================================
#  selecciona toda a informaçao do modulo e carrega numa hash de listas
#  ===========================================================================
sub selectModuleInformation
{
  my $obj = shift;
	my $module = shift;

	my $str = qq%
	  SELECT module_name,comments 
		FROM p4gl_module 
		WHERE module_name='$module'
  %;
  my $sth = $obj->{dbh}->prepare(qq% 
	  SELECT module_name,comments FROM p4gl_module WHERE module_name='$module'
  %);
  if ( ! $sth )
	{
		$obj->{err}->error(
		  "Seleção de modulo",
		  "Can't prepare select from p4gl_module\n$DBI::errstr"
    );
		return;
	}
  $sth->execute() || 
		$obj->{err}->error(
		  "Selecção de modulo",
	    "Can't select from p4gl_module\n$DBI::errstr"
    );
  my(@row);
	my %moduleInformation;
  if (@row = $sth->fetchrow_array())
  {
		%moduleInformation = (
		  'moduleName' => $row[0],
		  'comments'   => $row[1]
    );
  }
  undef $sth;
	$obj->{moduleInformation} = \%moduleInformation;

	$obj->selectModuleFunctions();
	$obj->selectModuleVariables();
}

#  ===========================================================================
#  Selecciona a informaçao sobre as funçoes de um modulo
#  ===========================================================================
sub selectModuleFunctions
{
  my $obj = shift;
	my $modRef = $obj->{moduleInformation};
	my $module = $modRef->{moduleName};
  my $sth = $obj->{dbh}->prepare(qq% 
	  SELECT function_name, function_type, comments 
		FROM p4gl_function
		WHERE module_name = '$module'
	%);
  if ( ! $sth )
	{
		$obj->{err}->error(
		  "Seleção de modulo",
		  "Can't prepare select from p4gl_module\n$DBI::errstr"
    );
		return;
	}
  $sth->execute() || 
		$obj->{err}->error(
		  "Selecção de modulo",
	    "Can't select from p4gl_module\n$DBI::errstr"
    );
  my(@row);
  my(@functionList);
  while (@row = $sth->fetchrow_array())
  {
		my %functionInformation = (
		  'function_name'    => $row[0],
		  'function_type'    => $row[1],
		  'comments'         => $row[2]
		);
		push(@functionList,\%functionInformation);
  }

	$modRef->{functionList} = \@functionList;
	$obj->{moduleInformation} = $modRef;
  undef $sth;
}

#  ===========================================================================
#  Selecciona a informaçao sobre as variaveis modulares 
#  ===========================================================================
sub selectModuleVariables
{
  my $obj = shift;
}


#  ===========================================================================
#  Gera o html todo para um modulo
#  ===========================================================================
sub genHtmlForModule
{
  my $obj = shift;
	my $module = shift;
	$obj->selectModuleInformation($module);
	my $moduleHtmlName = $obj->{destinationDir} . "/${module}.html";
  open(MODULEHTML, "> $moduleHtmlName") || 
	  die "Cant open $moduleHtmlName : $!";
	$obj->printModuleHeader($module);
	$obj->printFieldSummary($module);
	$obj->printMethodsSummary($module);
	$obj->printMethodsDetail($module);
	$obj->printFieldDetail($module);
	$obj->printDocTrailer($module);
  close(MODULEHTML);
}

#  ===========================================================================
#  Faz print do header de html
#  @todo Reutilizar na geração dos outros html(s)
#  ===========================================================================
sub printHeader
{
  my $obj = shift;
  my $module = shift;
  print MODULEHTML qq|
<!DOCTYPE HTML PUBLIC '-//W3C//DTD HTML 4.0 Frameset//EN''
http://www.w3.org/tr/rec-html40/frameset.dtd'>
<HTML>
<HEAD>
  <!-- Generated by fgldoc on \@todo Meter date -->
  <TITLE> Documentation for 4gl Module: $module </TITLE>
  <LINK REL ='stylesheet' TYPE='text/css' 
	HREF='stylesheet.css' TITLE='Style'>
</HEAD>

<BODY BGCOLOR='white'>
|;
}

#  ===========================================================================
#  Imprime o html do header do modulo 
#  @param module O nome do modulo corrente
#  ===========================================================================
sub printModuleHeader
{
  my $obj = shift;
  my $module = shift;
  $obj->printHeader($module);
	my $navBar = $obj->genNavBar("navbar_top","","OVERVIEW");
  print MODULEHTML "$navBar";
	$obj->printHeaderModuleData($module);
}

#  ===========================================================================
#  Gera para o ficheiro a informação contida no header relativo ao módulo
#  ===========================================================================
sub printHeaderModuleData
{
  my $obj = shift;
  my $module = shift;
  print MODULEHTML qq|
  <!-- ======== START OF MODULE DATA ======== -->
  <HR>
  <H2>Module  $module</H2>
  <P> $obj->{moduleInformation}->{comments}
  <HR>
  <P>
|;
}


#  ===========================================================================
#  Gera o html que contem a lista de variáveis modulares do módulo
#  @todo Implementar correctamente
#  ===========================================================================
sub printFieldSummary
{
  my $obj = shift;
  print MODULEHTML "<!-- =========== FIELD SUMMARY =========== -->\n";
}

#  ===========================================================================
#  Escreve a tabela de resumo com os respectivos links de todos os métodos
#  do módulo
#  @todo Resolver o problema do acesso aos dados
#  ===========================================================================
sub printMethodsSummary
{
  my $obj = shift;

	# Desreferenciar / desempacotar informaçao
	my $modRef = $obj->{moduleInformation};
	my %moduleInformation = %$modRef;
	my $funcRef = $moduleInformation{functionList};
	my @functionList = @$funcRef;

  $obj->printMethodSummaryHeader();
	my $i;
  for ( $i = 0 ; $i < $#functionList ; $i++ )
	{
		my $funcInfRef = $functionList[$i];
    $obj->printMethodSummaryBody($funcInfRef);
	}
  print MODULEHTML "</TABLE>\n";
}

#  ===========================================================================
#  Imprime o header do sumario dos metodos
#  ===========================================================================
sub printMethodSummaryHeader
{
  my $obj = shift;
	my $str = $obj->{methodSummaryStr};

  print MODULEHTML qq|
  &nbsp;
  <!-- ========== METHOD SUMMARY =========== -->

  <A NAME='method_summary'><!-- --></A>
  <TABLE BORDER='1' CELLPADDING='3' CELLSPACING='0' WIDTH='100%'>
    <TR BGCOLOR='#CCCCFF' CLASS='TableHeadingColor'>
      <TD COLSPAN=2><FONT SIZE='+2'><B>$str</B></FONT>
			</TD>
    </TR>
|;
}

#  ===========================================================================
# Imprime a descrição do sumário de um metodo
#  ===========================================================================
sub printMethodSummaryBody
{
  my $obj = shift;
  my $funcInfRef = shift;
	my %functionInformation = %$funcInfRef;

	my $functionName = $functionInformation{function_name};
	my $comments     = $functionInformation{comments};

  print MODULEHTML qq|
  <TR BGCOLOR='white' CLASS='TableRowColor'>
		<TD><CODE><B>
	    <A HREF='#$functionName()'>$functionName()</A></B></CODE>
      <BR>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
	    $comments
		</TD>
  </TR>
|;
}

#  ===========================================================================
#  Escreve a documentação de uma método
#  @param idxFunction Indice da função que se está a documentar
#  ===========================================================================
sub printMethodsDetail
{
  my $obj = shift;

	# Desreferenciar / desempacotar informaçao
	my $modRef = $obj->{moduleInformation};
	my %moduleInformation = %$modRef;
	my $funcRef = $moduleInformation{functionList};
	my @functionList = @$funcRef;

  $obj->printMethodDetailHeader();
	my $i;
  for ( $i = 0 ; $i < $#functionList ; $i++ )
	{
		my $funcInfRef = $functionList[$i];
    $obj->printMethodDetailBody($funcInfRef);
	}
  print MODULEHTML "<!-- ========= END OF CLASS DATA ========= --> <HR>\n";
}

#  ===========================================================================
#  Imprime o header para a informaçao detalhada dos metodosa
#  ===========================================================================
sub printMethodDetailHeader
{
  my $obj = shift;
  print MODULEHTML qq|
  <!-- ============ METHOD DETAIL ========== -->
  <HR>
  <A NAME='method_detail'><!-- --></A>
  <TABLE BORDER='1' CELLPADDING='3' CELLSPACING='0' WIDTH='100%'>
  <TR BGCOLOR='#CCCCFF' CLASS='TableHeadingColor'>
  <TD COLSPAN=1><FONT SIZE='+2'>
  <B>$obj->{methodDetail}</B></FONT></TD>
  </TR>
  </TABLE>
|;
}


#  ===========================================================================
#  Preenche os dados relativos ao detalhe de cada método 
#  @param idxFunction Indice da função na tabela de simbolos
#  @todo Parametros
#  @todo Lista de tarefas
#  @todo Valores de retorno
#  ===========================================================================
sub printMethodDetailBody
{
  my $obj = shift;
  my $funcInfRef = shift;
	my %functionInformation = %$funcInfRef;

	my $functionName = $functionInformation{function_name};
	my $comments     = $functionInformation{comments};

  print MODULEHTML qq|
	<HR>
  <A NAME='$functionName()'><!-- --></A><H3>$functionName</H3>
  <DL>
    <DD>$comments</DD>
  </DL>
|;
}

#  ===========================================================================
#  Gera o html com a descriçao das variaveis modulares
#  @todo Implementar a lista de variaveis
#  ===========================================================================
sub printFieldDetail
{
  my $obj = shift;
  print MODULEHTML "<!-- =========== FIELD SUMMARY =========== -->\n";
}

#  ===========================================================================
#  Imprime o fim do documento
#  ===========================================================================
sub printDocTrailer
{
  my $obj = shift;
	my $navBar = $obj->genNavBar("navbar_bottom","","OVERVIEW");
  print MODULEHTML qq|$navBar
  <HR>
  </BODY>
  </HTML>
|;
}

#  ===========================================================================
#  Executa a geraçao/exportaçao da informaçao para html de acordo com os 
#  parametros preenchidos
#  ===========================================================================
sub export
{
  my $obj = shift;
	$obj->selectPackages();
	$obj->selectProcesses();
	$obj->{originalDir} = getcwd();
	$obj->createDirTree();
  $obj->genHtml();
	chdir($obj->{originalDir}) || die "Can go again to original directory";
}

return 1;
