#!/usr/bin/perl 
#-w

# falta substituir um fetchrow por um select

# MAIN

use DBI;
use CGI qw(:standard);
use CGI::Carp qw(fatalsToBrowser);

# ===========================================================================
# Parameters :
#    nao      : 
#    sim      :
#    database : Database name
#    server   : Informix server
#    table    : Table name
# ===========================================================================

  inicia_html();
  if (! param('nao')) {
    $dd = get_param();
    if ($dd == 1) {
  		ligacao_bd();
      if (param('sim')) {
			  cria_tabelas();
      }                        
      $dd = existem_tabelas();
      if ($dd == 0) {
        form_tabelas();
      }
      else {
       	if (param('submit')) { 
         	upd_tabelas();
       	}
       	get_dados();
       	faz_pagina();
      }
  		desliga_bd();
    }
  }
  else { 
   	print "<h1>As tabelas systableext e syscolumnext não existem!!</h1>"; 
  }
  fecha_html();

# END MAIN
          
###############################################################
#  Liga-se a Base de Dados
###############################################################
sub ligacao_bd
{
    #my $host = `hostname`;
	#if ( $host =~ /.*ninja.*/ ) { 
		$infxser = "unstable";
        #}
	#else { $infxser = "online_db1" }

    #$ENV{INFORMIXSERVER}="unstable";
    $ENV{INFORMIXSERVER}=$infxser;
    $ENV{INFORMIXDIR}="/usr/informix"; 

    $driver = "dbi:Informix:";
    $connection = DBI->connect("$driver$nome_bd")
                        or die "Connection Failed.\n";
}

###############################################################
#  Desliga-se da Base de Dados
###############################################################
sub desliga_bd
{
    $connection->disconnect; 
}

###############################################################
#  Recebe parametros - retorna True se parametros validos
###############################################################
sub get_param
{
    $nome_bd = param('database');
    $instancia = param('server');
    $tabname = param('table');
    $x = 0;

    if (! defined($nome_bd)) {
          print "Nome de BD não existente!<br>\n";
          $x = 1;
    }

    if (! defined($instancia)) {
          print "Nome de Instancia não existente!<br>\n";
          $x = 1;
    }

    if (! defined($tabname)) {
          print "Nome de Tabela não existente!<br>\n";
          $x = 1;
    }

    if ($x == 1) { return 0 }
    return 1 
}

###############################################################
#  Inicia o HTML
###############################################################
sub inicia_html
{
    print header;
    print start_html(-title=>'Alteração das Extensões',
                     -bgcolor=>'#FFFFFF',
                     -text=>'#000000',
                     -link=>'#FF0000',
                     -vlink=>'#0000FF',
                     -alink=>'#AA0000');
}

###############################################################
#  Fecha o HTML
###############################################################
sub fecha_html
{
    print end_html;
}

###############################################################
#  Busca dados a BD
###############################################################
sub get_dados
{ 
  $str_sel1 = "select * from systables where tabname = \"" . $tabname . "\"";
  $str_sel3 = "select * from systableext where tabname = \"" . $tabname . "\"";
  $str_sel2 = "select * from syscolumnext where tabname = \"" . $tabname . "\"";
  $st_sel1 = $connection->prepare($str_sel1);
  $st_sel3 = $connection->prepare($str_sel3);
  $st_sel2 = $connection->prepare($str_sel2);
  $st_sel1->execute or warn "Prolemas execução de Select systableext!\n";
  $st_sel3->execute or warn "Prolemas execução de Select systables!\n";
  $st_sel2->execute or warn "Prolemas execução de Select syscolumnext!\n";

  @systables = $st_sel1->fetchrow;
  @systableext = $st_sel3->fetchrow;

  $str_sel4 = "select * from syscolumns where tabid = \"" . 
               $systables[3] . "\"";
  $st_sel4 = $connection->prepare($str_sel4);
  $st_sel4->execute or warn "Prolemas execução de Select syscolumns!\n";
}

###############################################################
#  Faz o display da pagina HTML
###############################################################
sub faz_pagina
{
    print start_form;
    print "<table align='center' width=800 border=1 cellpadding=4>\n";
    print "<tr><td width=100>\n";
    print "<font size=+1><strong>Tabela: </strong></font>";
    print "</td><td width=700>\n";
    print "<b>$tabname</b>\n";
    print "</td></tr>\n";
    print "<tr><td width=100>";
    print "<font size=+1><strong>Owner: </strong></font>";
    print "</td><td width=700>\n";
    if (! defined($systables[1])) { 
        print "-"       
    }  
    else { 
        print "<b>$systables[1]</b>\n";
    }
    print hidden(-name=>'owner',
                 -default=>$systables[1]);  
    print "</td></tr>\n";
    print "</table>"; 

    print "<br>";

    print "<table align='center' width=800 border=0>\n";
    print "<tr><td>\n";
    print hidden(-name=>'extowner',
                 -default=>$systableext[2]);  
    print "<b>Alias: </b><br>";
    print textfield(-name=>'alias',
                    -default=>$systableext[3]);
    print "</td></tr>\n";
    print "<tr><td>\n";
    print "<b>Observações: </b><br>";
    print textarea(-name=>'obs',
                   -default=>$systableext[4],
                   -rows=>5,
                   -columns=>110);
    print "</td></tr>\n";
    print "</table>"; 

    print "<br>";

    print "<table align='center' width=800 border=1 cellpadding=2>\n";
    print "<tr><th>Coluna</th>";
    print "<th>Alias</th>";
    print "<th>Label</th>";
    print "<th>Title</th>";
    print "<th>Observações</th>";
    print "</tr>";
   
    $i = 0; 
    #while (@syscolumnext = $st_sel2->fetchrow) {  
    while (@syscolumns = $st_sel4->fetchrow) {  
        
        # criar select para dados de coluna de syscolumnext       
 
        @syscolumnext = $st_sel2->fetchrow;
        $i++;
        $alias_col = "alias_col" . $i;
        $label = "label" . $i;
        $title = "title" . $i;
        $obs_col = "obs_col" . $i;
        $coluna = "coluna" . $i;
    	print "<tr><td align='center'>\n";
 	print "<b>$syscolumns[0]</b>\n";
 	#print "<b>$syscolumnext[2]</b>\n";
	print "</td><td align='center'>";
        print textfield(-name=>$alias_col,
                        -value=>$syscolumnext[4]);
	print "</td><td align='center'>";
        print textfield(-name=>$label,
                        -default=>$syscolumnext[5]);
	print "</td><td align='center'>";
        print textfield(-name=>$title,
                        -default=>$syscolumnext[6]);
	print "</td><td align='center'>";
        print textarea(-name=>$obs_col,
                       -default=>$syscolumnext[7],
                       -rows=>1,
                       -columns=>30);
        print hidden(-name=>$coluna,
                     -default=>$syscolumns[0]);  
	print "</td></tr>";
    } 
    print hidden(-name=>'indice',
                 -default=>$i);  
    print "</table>\n"; 

    print "<br>";

    print "<table align='center' width=800 border=0>\n";
    print "<tr><td>\n";
    print submit(-name=>'submit',
                 -value=>'Gravar');
    print reset(-value=>'Refrescar');
    print "</td></tr>\n";
    print "</table>\n"; 

    print hidden(-name=>'database',
                 -default=>$nome_bd);  
    print hidden(-name=>'table',
                 -default=>$tabname);  
    print hidden(-name=>'server',
                 -default=>$instancia);  
 
    print end_form;
}

###############################################################
#  Faz o update das tabelas
###############################################################
sub upd_tabelas
{
   $str_del1 = "delete from systableext where tabname = \"" . param('table') .
               "\"";
   $st_del1 = $connection->do($str_del1);
   $extowner = param('extowner');
   $extowner =~ s/ *$//;
   $obs = param('obs');
   $obs =~ s/ *$//;
   if ($extowner eq '') { $extowner = param('owner') }
   $str_ins1 = "insert into systableext values (\"" . param('owner') . "\",\"" .
               param('table') . "\",\"" . $extowner . "\",\"" . 
               param('alias') . "\",\"" . $obs . "\")";
   #print "$str_del1\n<br>";
   #print length($str_ins1);
   #print "\n";
   $st_ins1 = $connection->do($str_ins1);

   $str_del2 = "delete from syscolumnext where tabname = \"" . 
                param('table') . "\"";
   $str_ins2 = "insert into syscolumnext values (\"" . 
                param('owner') . "\",\"" . param('table') . "\",?,\"" .
                $extowner . "\",?,?,?,?,\"\",\"\")";

  $st_del2 = $connection->do($str_del2);
  $st_ins2 = $connection->prepare($str_ins2) 
	  or die "Error : " .  $connection->errstr;
 
  for ($j=1;$j<=param('indice');$j++) 
  {
           $alias_col = "alias_col" . $j;
           $label = "label" . $j;
           $title = "title" . $j;
           $obs_col = "obs_col" . $j;
           $coluna = "coluna" . $j;
           $obs_col_aux = param($obs_col);
   	   $obs_col_aux =~ s/ *$//;

     $st_ins2->execute(param($coluna),
		                   param($alias_col),
											 param($label),
											 param($title),
											 $obs_col_aux)
    or die "Error : " .  $db->errstr;
  }
}

###############################################################
#  Verifica se a tabelas systableext e syscolumnext existem na BD
###############################################################
sub existem_tabelas
{
   $str_sel_tab = "select tabname from systables where " . 
                  "tabname = \"systableext\""; 

   $st_tab = $connection->prepare($str_sel_tab);
   $st_tab->execute();

   $systab = $st_tab->fetchrow;
   if (! defined($systab)) { return 0 }  

   $str_sel_col = "select tabname from systables where " . 
                  "tabname = \"syscolumnext\""; 

   $st_col = $connection->prepare($str_sel_col);
   $st_col->execute();

   $syscolumn = $st_col->fetchrow;
   if (! defined($syscolumn)) { return 0 }  

   return 1
}

###############################################################
#  Faz o form das tabelas systableext e syscolumnext
###############################################################
sub form_tabelas
{
   print "<h1>As tabelas systableext e syscolumnext não existem!!</h1>"; 

   # verificar se utilizador DBA
   $user = $ENV{REMOTE_USER};
   #print "$user\n<br>";
   $str_user = "select usertype from sysusers where username = \"" . 
               $user . "\""; 
   $st_user = $connection->prepare($str_user);
   $st_user->execute;
   $usertype = $st_user->fetchrow;
   if ($usertype eq 'D') {
   
   	print "<h3>Deseja criar as tabelas?</h3>"; 

   	print start_form;
   	print submit(-name=>'sim',
       	        -value=>'Sim');
   	print submit(-name=>'nao',
                -value=>'Não');
   	print hidden(-name=>'database',
                -default=>$nome_bd);  
   	print hidden(-name=>'table',
                -default=>$tabname);  
   	print hidden(-name=>'server',
                -default=>$instancia);  
   	print end_form;
   }
}

###############################################################
#  Cria as tabelas systableext e syscolumnext
###############################################################
sub cria_tabelas
{
   $user = $ENV{REMOTE_USER};
	 # ??? We should test if the database use Primary and foreign keys
   $str_cria1 = qq/
create table systableext 
  (
    owner char(32),
    tabname char(32),
    extowner char(32),
    tabalias char(32),
    remarks char(254)
  );
/;

  $str_rev1 = qq/revoke all on systableext from "public"/;
  $str_index1 = qq/create unique index tableext1 on systableext (owner,
    tabname)/;

  print "$str_cria1\n<br>";
  #$st_cria1 = $connection->do($str_cria1);
  $ans = $connection->do($str_cria1);

	if ( ! $ans ) {
	  $sqlcode=$connection->{ix_sqlcode};
	  $sqlerrm=$connection->{ix_sqlerrm};
		print "Sql error : $sqlcode - $sqlerrm\n";
		die "ERROR";
	}
  $st_rev11 = $connection->do($str_rev1);
  $st_index11 = $connection->do($str_index1);

   $str_cria2 = qq/ 
create table syscolumnext 
  (
    owner char(32),
    tabname char(32),
    colname char(32),
    extowner char(32),
    colalias char(32),
    collabel char(32),
    coltitle char(32),
    remarks char(254),
    subtype char(4),
    class char(32)
  );
/;
  $str_rev2 = qq/revoke all on syscolumnext from "public";/;
  $str_index2 = qq/ create unique index columnext1 on syscolumnext (owner,
 tabname,colname);/;

  print "$str_cria2\n<br>";
  $st_cria2 = $connection->do($str_cria2);
  $st_rev2 = $connection->do($str_rev2);
  $st_index2 = $connection->do($str_index2);
}
