#!/usr/bin/perl -w

#  =========================================================================
#
#  Implementa a toolbar para execução das acções sem ser por menu.
#  Só para modo GUI.
# 
#  Autor : Sérgio Ferreira
#
#  $Revision: 1.1 $
#  $Id: Toolbar.pm,v 1.1 2003-01-06 20:08:49 saferreira Exp $
#
#  =========================================================================

package FglDocumenter::Toolbar;

use strict;
use Tk::Pane;

use vars qw(@ISA);
@ISA = ("FglDocumenter::BaseClass");

#  =========================================================================
#  Constructor
#  =========================================================================
sub new
{
	my $pkg = shift;
	my $toolbar = $pkg->allocate();

	return $toolbar;
}

#  =========================================================================
#  Inicializa e mostra a toolbar
#  =========================================================================
sub show
{
	my $obj = shift;

  $obj->{frame} = $main::mw->Frame(-relief => 'ridge', -borderwidth => 2);
	$obj->{frame}->pack(
	  -side => 'top', 
		-anchor => 'n', 
		-expand => 1, 
		-fill => 'x'
	);

	my $imgLocation = FglDocumenter::FglDocLocation::getLocation() . "/img";
  my $importCsvImage = $main::mw->Photo(
	  -file => "$imgLocation/importcsv.gif",
  );
  my $importCSVButton = $obj->{frame}->Button(
	  -text => "Import CSV", 
		-image => $importCsvImage,
	  -command => [ \&main::importCSV, $obj ]
	);
	$importCSVButton->pack(
		-side => 'left' 
  );

  my $importFglImage = $main::mw->Photo(
	  -file => "$imgLocation/import4gl.gif"
  );
  my $importFglButton = $obj->{frame}->Button(
	  -text => "Import 4gl", 
		-image => $importFglImage,
	  -command => [ \&main::importFgl, $obj ]
	);
	$importFglButton->pack(
		-side => 'left' 
  );

  my $exportCsvImage = $main::mw->Photo(
	  -file => "$imgLocation/importcsv.gif"
  );
  my $exportCsvButton = $obj->{frame}->Button(
	  -text => "Export CSV", 
		-image => $exportCsvImage,
	  -command => [ \&main::export2CSV, $obj ]
	);
	$exportCsvButton->pack(
		-side => 'left' 
  );

  my $exportFglImage = $main::mw->Photo(
	  -file => "$imgLocation/export4gl.gif"
  );
  my $exportFglButton = $obj->{frame}->Button(
	  -text => "Export 4gl", 
		-image => $exportFglImage,
	  -command => [ \&main::export2FglGui, $obj ]
	);
	$exportFglButton->pack(
		-side => 'left' 
  );

  my $exportHtmlImage = $main::mw->Photo(
	  -file => "$imgLocation/exporthtml.gif"
  );
  my $exportHtmlButton = $obj->{frame}->Button(
	  -text => "Export Html", 
		-image => $exportHtmlImage,
	  -command => [ \&main::export2Html, $obj ]
	);
	$exportHtmlButton->pack(
		-side => 'left' 
  );
}

