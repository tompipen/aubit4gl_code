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

1;
