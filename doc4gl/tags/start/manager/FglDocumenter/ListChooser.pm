#!/usr/bin/perl

#  =========================================================================
#
#  Objecto que abre uma janela que contem duas listas e permitem 
#  escolher de uma das listas para a outra
# 
#  $Author: afalout $
#  $Revision: 1.1.1.1 $
#
#  =========================================================================

package FglDocumenter::ListChooser;

use Tk;
use Tk::Frame;
use FglDocumenter::Utils;

#  =========================================================================
#  Construtora
#  =========================================================================
sub new 
{
  my ($pkg,) = @_;

	my $listChooser = {
	  "leftList"    => 0,
	  "rightList"   => 0,
	  "parentComponent" => 0,
		# Meter aqui a lista de objectos visuais (se é que é necessário manter
		# as referências para eles)
	};
	bless $listChooser, "FglDocumenter::ListChooser";
	return $listChooser;
}

#  =========================================================================
#  Abre e mostra a janela e mete as duas listBox(s) carregando-as com os 
#  valores que tem
#  =========================================================================
sub show
{
	$obj = shift;

	# Na realidade o que é afectado é uma frame
  $form = $obj->{parentComponent};
	printf("ref " . ref($form) . "\n");
  
	# @todo - Isto tem de passar para quem abre o(s) form(s)
  #$form->title("Opções de exportação para fontes 4gl");
  #$height = 400;
  #$width  = 300;
	# @todo - Retitar esta dependencia não genérica
	#FglDocumenter::Utils::setWindowAtCenter($form,$width,$height);

	$obj->{leftList} = qw/AAA BBB CCC/;
	@leftList = qw/AAA BBB CCC/;
	@rightList = qw/DDD EEE FFF/;

	$leftListBox = $form->Scrolled("Listbox", -scrollbars => "osoe");

	$leftListBox->insert('end',@leftList);
	$leftListBox->grid(-row => 0,-column => 0, -rowspan => 4);

  $rightToLeftButton = $form->Button(
	  -text => "<", 
	  -command => \&rightToLeft
	);
	$rightToLeftButton->grid(-row => 0,-column => 1);

  $rightToLeftAllButton = $form->Button(
	  -text => "<<", 
	  -command => \&rightToLeftAll
	);
	$rightToLeftAllButton->grid(-row => 1,-column => 1);

  $leftToRightAllButton = $form->Button(
	  -text => ">>", 
	  -command => \&leftToRightAll
	);
	$leftToRightAllButton->grid(-row => 2,-column => 1);

  $leftToRightButton = $form->Button(
	  -text => ">", 
	  -command => \&leftToRight
	);
	$leftToRightButton->grid(-row => 3,-column => 1);

	$rightListBox = $form->Scrolled("Listbox", -scrollbars => "osoe");
	$rightListBox->insert('end',@rightList);
	$rightListBox->grid(-row => 0,-column => 2, -rowspan => 4);

}

#  =========================================================================
#  Copia objecto(s) seleccionado(s) do lado direito para o lado esquerdo
#  =========================================================================
sub rightToLeft
{
	$obj = shift;
  # Conseguir obter elemento seleccionado na lista da direita
	@selected = $rightListBox->curselection();
	# Inserir o elemento na listBox da esquerda
  $leftListBox->insert('end',$rightList[$selected[0]]);
	# Apagar o elemento da listBox da direita
  $rightListBox->delete($selected[0]);
	# Inserir o elemento na lista da esquerda
  push(@leftList,$rightList[$selected[0]]);
	# Apagar o elemento da lista da direita
	@rightList = removeArrayElement(\@rightList,$selected[0]);
	actualizaBotoes();
}


#  =========================================================================
#  Actualiza os botoes
#  =========================================================================
sub actualizaBotoes
{
	$obj = shift;
	if ( $#rightList == -1 )
	{
    $rightToLeftButton->configure(-state => 'disabled');
    $rightToLeftAllButton->configure(-state => 'disabled');
	}
  else
	{
    $rightToLeftButton->configure(-state => 'normal');
    $rightToLeftAllButton->configure(-state => 'normal');
  }
	if ( $#leftList == -1 )
	{
    $leftToRightButton->configure(-state => 'disabled');
    $leftToRightAllButton->configure(-state => 'disabled');
	}
  else
	{
    $leftToRightButton->configure(-state => 'normal');
    $leftToRightAllButton->configure(-state => 'normal');
  }
}

#  =========================================================================
#  Passa todos os elementos da lista do lado direito para a lista do lado
#  esquerdo.
#  =========================================================================
sub rightToLeftAll
{
	$obj = shift;
  $rightListBox->delete(0,'end');
  $leftListBox->insert('end',@rightList);
	push(@leftList,@rightList);
	@rightList = ();
	actualizaBotoes();
}

#  =========================================================================
#  Passa o elemento corrente da lista da esquerda para a da direita
#  =========================================================================
sub leftToRight
{
	$obj = shift;
  # Conseguir obter elemento seleccionado na lista da esquerda
	@selected = $leftListBox->curselection();
	# Inserir o elemento da listBox da direita
  $rightListBox->insert('end',$leftList[$selected[0]]);
	# Apagar o elemento da listBox da esquerda
  $leftListBox->delete($selected[0]);
	# Inserir o elemento na lista da direita
  push(@rightList,$leftList[$selected[0]]);
	# Apagar o elemento da lista da esquerda
	@leftList = removeArrayElement(\@leftList,$selected[0]);
	actualizaBotoes();
}

sub printListas
{
	$obj = shift;
	printf("\n=======\nArray da esquerda \n");
	printArray(\@leftList);
	printf("\nArray da direita \n");
	printArray(\@rightList);
}

#  =========================================================================
#  Remove o elemento de um array
#  =========================================================================
sub removeArrayElement
{
	$obj = shift;
  $rArray       = shift;
  @arrayOrigem  = @$rArray;
  @arrayDestino = ();
  $toRemove     = shift;
	if ( $toRemove > 0 )
	{
	  for ( $i = 0 ; $i <= $toRemove - 1 ; $i++ )
	  {
	    push(@arrayDestino,$arrayOrigem[$i]);
	  }
	}
	for ( $i = $toRemove + 1 ; $i <= $#arrayOrigem ; $i++ )
	{
	  push(@arrayDestino,$arrayOrigem[$i]);
	}
	return @arrayDestino;
}

#  =========================================================================
#  Mostra o conteudo do array
#  =========================================================================
sub printArray
{
	$obj = shift;
  $rArray = shift;
  @array = @$rArray;
  for ( $i = 0 ; $i <= $#array ; $i++ )
	{
	  printf("Array [$i] = $array[$i]\n");
	}
}

#  =========================================================================
#  =========================================================================
sub leftToRightAll
{
	$obj = shift;
  $leftListBox->delete(0,'end');
  $rightListBox->insert('end',@leftList);
	push(@rightList,@leftList);
	@leftList = ();
  actualizaBotoes();
}

#  =========================================================================
#  Afecta o componente onde os objectos gráficos serão adicionados
#  =========================================================================
sub setParentComponent
{
  $obj = shift;
	$obj->{parentComponent} = shift;
}

#  =========================================================================
#  Afecta a lista do lado esquerdo
#  =========================================================================
sub setLeftList
{
  $obj = shift;
	$obj->{leftList} = shift;
}

#  =========================================================================
#  Afecta a lista do lado direito
#  =========================================================================
sub setRightList
{
  $obj = shift;
	$obj->{rightList} = shift;
}

return 1;
