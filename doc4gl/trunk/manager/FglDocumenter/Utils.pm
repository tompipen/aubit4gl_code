#!/usr/bin/perl

#  =========================================================================
#
#  Subrotinas utilitárias diversas
# 
#
#  Autor : Sérgio Ferreira
#
#  =========================================================================

package FglDocumenter::Utils;

#  =========================================================================
#  Devolve a coordenada Y para que uma janela fique centrada
#  @param heigth (altura da janela)
#  =========================================================================
sub getCenterY
{
  $winHeight = shift;
	$screenHeight = $main::mw->screenheight();
  $y = $screenHeight / 2 - $winHeight / 2;
	return $y;
}

#  =========================================================================
#  Devolve a coordenada X para que uma janela fique centrada
#  @param heigth (altura da janela)
#  =========================================================================
sub getCenterX
{
  $winWidth = shift;
	$screenWidth = $main::mw->screenwidth();
  $x = $screenWidth / 2 - $winWidth / 2;
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
	$with = $main::mw->screenwidth();
	$height = $main::mw->screenheight();
  $x = getCenterX($width);
	$y = getCenterY($height);
	$win->geometry("${height}x$width+$x+$y");

}

return true;
