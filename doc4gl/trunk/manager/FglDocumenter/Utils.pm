#!/usr/bin/perl -w

#  =========================================================================
#
#  Subrotinas utilitárias diversas
# 
#  @todo - Meter strict a funcionar
#
#  Autor : Sérgio Ferreira
#
#  =========================================================================

use strict;

package FglDocumenter::Utils;

#  =========================================================================
#  Devolve a coordenada Y para que uma janela fique centrada
#  @param heigth (altura da janela)
#  =========================================================================
sub getCenterY
{
  my $winHeight = shift;
  my $screenHeight = $main::mw->screenheight();
  my $y = $screenHeight / 2 - $winHeight / 2;
  return $y;
}

#  =========================================================================
#  Devolve a coordenada X para que uma janela fique centrada
#  @param heigth (altura da janela)
#  =========================================================================
sub getCenterX
{
  my $winWidth = shift;
  my $screenWidth = $main::mw->screenwidth();
  my $x = $screenWidth / 2 - $winWidth / 2;
  return $x;
}

#  =========================================================================
#  Afecta a geometria da janela por forma a que esta fique ao centro
#    @param janela 
#    @param with - Largura da janela
#    @param height - Altura da janela
#  =========================================================================
sub setWindowAtCenter
{  
  my $win = shift;
  my $width = shift;
  my $height = shift;

  # So para ver se funciona
  # Temporariamente fica assim. Esta melhor pois nao fica com tamanhos de 
  # janelas hardcoded
  my $with = $main::mw->screenwidth();
  my $height = $main::mw->screenheight();
  my $x = getCenterX($width);
  my $y = getCenterY($height);
  $win->geometry("${height}x$width+$x+$y");

}


#  =========================================================================
#  Afecta a geometria da janela por forma a que esta fique ao centro
#    @param janela 
#    @param with - Largura da janela
#    @param height - Altura da janela
#  =========================================================================
sub setFormAtCenter
{  
  my $win = shift;
  #my $width = shift;
  #my $height = shift;

  # So para ver se funciona
  # Temporariamente fica assim. Esta melhor pois nao fica com tamanhos de 
  # janelas hardcoded
  my $width = $win->width;
  my $height = $win->height;
  my $x = getCenterX($width);
  my $y = getCenterY($height);
  $win->geometry("${height}x$width+$x+$y");
  $win->update();

}


#  =========================================================================
#  Get the name of all modules from the directory sended as parameter.
#
#  @todo - Insert error management an take die away
#  @param wantedDir - Directory from where we want the 4gl list.
#  @param loadFilesrecursive Flag that indicate if the behaviour should 
#    be recursive (follow all directories).
#  @return A Reference to the file List
#  =========================================================================
sub getModules
{
  my $wantedDir = shift;
  my $loadFilesRecursive = shift;
  my $currentDir = POSIX::getcwd();
  chdir $wantedDir || die "Cant change to $wantedDir : $!\n ";
  my $moduleDir = POSIX::getcwd();
  my @moduleList = ();
  my $file;
  foreach $file (<*>)
  {
    if ( isFglFile($file) )
    {
      chomp($file);
      push(@FglDocumenter::Utils::directoryList,$moduleDir);
      push(@moduleList,$file);
    }
    elsif ( $loadFilesRecursive == 1 )
    {
      if ( -d $file )
      {
        my $directory = "$file";
        #$directory = "$wantedDir/$file";
        my $refSubDirModules = getModules($directory,1);
        my @subDirModules = @$refSubDirModules;
        @moduleList    = (@moduleList,@subDirModules);
      }
    }
  }
  chdir $currentDir;
  return \@moduleList;
}

sub initDirectoryList 
{
  @FglDocumenter::Utils::directoryList = ();
}


sub getDirectoryList
{
  return \@FglDocumenter::Utils::directoryList;
}



#  =========================================================================
#  Test if a file is a 4gl file.
#
#  @param file The file to tested.
#  @return A code that tells if it is a 4gl file:
#    - 0 : Its not a fgl file.
#    - 1 : its a fgl file.
#  =========================================================================
sub isFglFile
{
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
