#!/usr/local/bin/perl -w

use DBI;
use CGI qw(:standard);
use CGI::Carp qw(fatalsToBrowser);

#  ===========================================================================
#  ??? Falam retirar espacos no fim das strings
#  ===========================================================================
#  debug(): prints arguments visibly for debug
#  ===========================================================================
sub debug()
{
   print "<TABLE BGCOLOR=#FF0000><TR><TD><FONT FACE='Courier' COLOR=#FFFFFF SIZE=-1>",
				 "<B>", @_, "</B></FONT><TD></TR></TABLE><BR>";
}

#  ===========================================================================
#  It  get(s) the environment for access to a specific database
#  It make(s) a query to Despodata Database
#  ===========================================================================
sub GetDBEnvironment()
{
	 # ??? This should no t be like this
	$server = param("server");
   if ( defined($server) ) {
		$ENV{INFORMIXSERVER}=$server;
	} else {
		$ENV{INFORMIXSERVER}="unstable";
	}
}

#  ===========================================================================
#  It set(s) the informix environment
#  ??? Isto deveria ser testado
#  ===========================================================================
sub InformixEnvironment()
{
   $ENV{INFORMIXDIR}="/usr/informix";
}

#  ===========================================================================
#  Obtain a string with the type of the column
#  It should use a specifi method od DBI or have versions to oracle.
#  For this version wee only convert integer(s) type and precision
#  in string
#  ===========================================================================
sub GetStrTipo
{
   $TipoInt = $_[0];
   if ( $TipoInt > 255 )
			{ $TipoInt -= 256; }

   if ( $TipoInt == 0 )
	    { return "Char($_[1])"; }
	 elsif ( $TipoInt == 1 )
	    { return "Smallint"; }
	 elsif ( $TipoInt == 2 )
	    { return "Integer"; }
	 elsif ( $TipoInt == 3 )
	    { return "Float"; }
	 elsif ( $TipoInt == 4 )
	    { return "Smallfloat"; }
	 elsif ( $TipoInt == 5 )
	 { 
			#$PREC = 
			#return "Decimal($PREC)"; 
			return "Decimal"; 
   }
	 elsif ( $TipoInt == 6 )
	    { return "Serial"; }
	 elsif ( $TipoInt == 7 )
	    { return "Date"; }
			#???
	 elsif ( $TipoInt == 8 )
	    { return "Money"; }
	 elsif ( $TipoInt == 9 )
	    { return "ERROR"; }
	 elsif ( $TipoInt == 10 )
	    { return "Datetime"; }
	 elsif ( $TipoInt == 11 )
	    { return "Byte"; }
	 elsif ( $TipoInt == 12 )
	    { return "Text"; }
	 elsif ( $TipoInt == 13 )
	    { return "Varchar"; }
	 elsif ( $TipoInt == 14 )
	    { return "Interval"; }
	 else 
	    { return "Error $TipoInt"; }
}

#  ===========================================================================
#  Verify if the database have extended dictionary tables
#  ===========================================================================
sub VerifyExtended
{
	 $ExistTableExt  = 0;
	 $ExistColumnExt = 0;
	 $ExistModules   = 0;

   # For now i use a query but i should use tabinfo
	 $st1=$db->prepare("select tabid from systables where tabname='systableext'");
	 $st1->execute or die "Cant execute statement";
	 @Linha = $st1->fetchrow;
	 # Maybe i should deallocate some resources (cursor close ???)
	 if ( defined(@Linha) )
	    { $ExistTableExt = 1; }
	 $st2=$db->prepare("select tabid from systables where ".
										 "tabname='syscolumnext'");
	 $st2->execute or die "Cant execute statement";
	 @Linha = $st2->fetchrow;
	 # Maybe i should deallocate some resources (cursor close ???)
	 if ( defined(@Linha) )
	    { $ExistColumnExt = 1; }
	 $st3=$db->prepare("select tabid from systables where ".
										 "tabname='d_modulos'");
	 $st3->execute or die "Cant execute statement";
	 @Linha = $st3->fetchrow;
	 # Maybe i should deallocate some resources (cursor close ???)
	 if ( defined(@Linha) )
	    { $ExistModules = 1; }
}

#  ===========================================================================
#  Informix SE have number of columns possible in index diferent of On Line
#  ===========================================================================
sub SeeNumIdxColumns
{
	 $st=$db->prepare("select colname from syscolumns,systables".
										 " where tabname='syscolumns' and " .
										 " systables.tabid=syscolumns.tabid");
	 $st->execute or die "Cant execute statement";
	 @Linha = $st3->fetchrow;
	 if ( defined ( @Linha ))
	    { $NumIdxColumns = 7; }
   else
	    { $NumIdxColumns = 16; }
}

#  ===========================================================================
#  Show the columns of the index wich name was passed as parameter
#  ===========================================================================
sub ShowColumnsOfIndex
{
   @IdxColumns = GetColumnsOfIndex($_[0]);
	 foreach ( ${@IdxColumns} )
	 {
			if ( defined($_) )
			   { print "COLUNA $_<P>";}
	 }
}

#  ===========================================================================
#  Get the columns wich ar part of the index
#  ===========================================================================
sub GetColumnsOfIndex
{
	 my $SelectList = "";
	 # Construction of query in the fuckin table sysindexes 
	 # (i hope the designer was allready fired)
	 $From = "sysindexes";
	 $Where = "sysindexes.idxname='$_[0]'";
	 $Join = "";
	 for ( $i = 1 ; $i <= $NumIdxColumns ; $i++ )
	 {
			$From .= ",";
			if ( $i > 1 ) 
			{ 
				 $SelectList .= ","; 
				 $Join .= " and "; 
				 $From .= "outer ";
      }
			$SelectList .= "scol$i.colname";
			$Join .= "sysindexes.part$i=scol$i.colno and ".
							 "sysindexes.tabid=scol$i.tabid";
			$From .= "syscolumns scol$i";
	 }
	 $str = "select $SelectList from $From where $Where and $Join";
	 #print "<p>SQL Colunas de indice : $str<p>";
   $stidx = $db->prepare($str);
	 $stidx->execute or die "Cant execute statement";
	 @linha = $stidx->fetchrow ;
	 if (!defined(@linha))
			{ print "<B>ERRO !... Index inexistente</B>\n"; }
	 return \@linha;
}

#  ===========================================================================
#  Getting unique key(s) of the table passed as parameter
#  All key(s) stay in an array
#  The structure of the array of hashes is:
#     @UniqueKeys = (
#           {
#             Name => 'constraname',
#             IdxName => 'xpto1',
#             Type    => 'P' or 'U' or 'I' (primary, unique or index
#             Columns => [ 'col_a', 'col_b', ... ]
#           },
#        ...
#  ===========================================================================
sub GetKeys
{
	 # Explicit (primary key constraint)
	 $str = qq/select sysconstraints.constrname, sysconstraints.idxname 
			from sysconstraints 
	    where sysconstraints.tabid=$_[0] and sysconstraints.constrtype="P"
/;
	 # Garbage for debug
	 #printf("SQL $str\n");
   $StPK = $db->prepare($str);
	 $StPK->execute or die "Cant execute statement";
	 @UniqueKeys = ();                 # Array of hashes 
	 my @PK = ();
	 $nPK = 0;
	 print "<p>";
	 while ( @PK = $StPK->fetchrow )
	 {
	    if (defined(@PK))
	    {
				 $UniqueKeys[$nPK]            = {};
				 $UniqueKeys[$nPK]->{Name}    = $PK[0];
				 $UniqueKeys[$nPK]->{IdxName} = $PK[1];
				 $UniqueKeys[$nPK]->{Type}    = "P";
         #ShowColumnsOfIndex($PK[1]);
         $UniqueKeys[$nPK]->{Columns} = GetColumnsOfIndex($PK[1]);
				 $nPK++;
      }
	 }


   # First unique constraint
	 $str = qq/select sysconstraints.constrname, sysconstraints.idxname 
	 		from sysconstraints 
	  	where sysconstraints.tabid=$_[0] and sysconstraints.constrtype="U"
/;
	 #printf("SQL $str<P>");
   $StUN = $db->prepare($str);
	 $StUN->execute or die "Cant execute statement";
	 while ( @UN = $StUN->fetchrow )
	 {
	    if (defined(@UN))
	    {
				 $UniqueKeys[$nPK]            = {};
				 $UniqueKeys[$nPK]->{Name}    = $UN[0];
				 $UniqueKeys[$nPK]->{IdxName} = $UN[1];
				 $UniqueKeys[$nPK]->{Type}    = "U";
         $UniqueKeys[$nPK]->{Columns} = GetColumnsOfIndex($UN[1]);
				 $nPK++;
      }
	 }

	 # Unique index
	 $str = qq/select sysindexes.idxname from sysindexes
	 where sysindexes.tabid=$_[0] and sysindexes.idxtype="U"
/;
	 for ( $j = 0 ; $j < $nPK ; $j++ )
	    { $str .= " and sysindexes.idxname <> \'$UniqueKeys[$j]->{IdxName}\'"; }
	 #printf("SQL $str\n");
   $StIU = $db->prepare($str) or print "Error";
	 $StIU->execute or die "Cant execute statement";
	 while ( @IU = $StIU->fetchrow )
	 {
	    if (defined(@IU))
	    {
				 $UniqueKeys[$nPK]            = {};
				 $UniqueKeys[$nPK]->{Name}    = $IU[0];
				 $UniqueKeys[$nPK]->{IdxName} = $IU[0];
				 $UniqueKeys[$nPK]->{Type}    = "IDX";
         $UniqueKeys[$nPK]->{Columns} = GetColumnsOfIndex($IU[0]);
				 $nPK++;
      }
	 }
}

#  ===========================================================================
#  Show the primary key of the table witch rowid is passed as parameter
#  ===========================================================================
sub ShowKeys
{
	 print "<table border>";
	 my $NoPK = 0;
	 for ( $j = 0 ; $j <= $#UniqueKeys ; $j++ )
	 {
			if ( $j == 0 || $NoPK )
			{
				 print "<br><tr><th>Chave primaria ";
				 $NoPK = 1;
      }
      else
				 { print "<tr><td>Chave candidata "; }
			if ( $UniqueKeys[$j]->{Type} eq "P" )
				 { print "(explicita)"; }
			elsif ( $UniqueKeys[$j]->{Type} eq "U" )
				 { print "(unique constraint)"; }
			elsif ( $UniqueKeys[$j]->{Type} eq "IDX" )
				 { print "(Indice unico)"; }
			else 
				 { print "(Indeterminado)"; }
      print "</th><td>";
			# For a link that get more information about the index
			$k = 0;
	    foreach ( @{$UniqueKeys[$j]->{Columns}} )
	    {
				 if ( defined( $_ ))
				 {
				    if ( $k != 0 ) { print ","; }
						print "$_";
				 }
				 $k++;
			}
			print "</td></tr>";
	 }
	 if ( $j == 0 )
			{print "<br><font color=red>TABELA SEM CHAVE PRIMARIA</font>";}
	 print "</table>";
}

#  ===========================================================================
#  Obtain the foreign key(s) of the table
#  The foreign keys gone to be stored in an hash array with te folowing 
#  structure:
#     
#     @ForeignKeys = (
#           {
#             Name => 'constraname',
#             IdxName => 'xpto1',
#             Columns => [ 'col_a', 'col_b', ... ]
#             ReferencedTable => 'constraname',
#             ReferencedTableID => 111,
#             ReferencedIdxName => 'tabreferenced',
#             ReferencedColumns => [ 'col_a', 'col_b', ... ]
#           },
#        ...
#     ARGUMENTS:
#         0 - tabid ; Table ID
#  ===========================================================================
sub GetFKS
{
   my $str = qq/
     select sysconstraints.idxname, sysconstraints.constrid,
            systables.tabname, systables.tabid,
            Const_ref.idxname
     from sysconstraints, sysconstraints const_ref, sysreferences, systables
     where sysconstraints.tabid = \'$_[0]\' and
           sysconstraints.constrid = sysreferences.constrid and
           const_ref.constrid  = sysreferences.primary and
           sysreferences.ptabid = systables.tabid and
           sysconstraints.constrtype = 'R'
/;
	 #print "SQL : $str<p>";
	 @ForeignKeys = ();                 # Array of hashes 
	 my @PK = ();
	 $StFK = $db->prepare($str);
	 $StFK->execute or die "Cant execute statement";
	 $nFK = 0;
	 while ( @FKS = $StFK->fetchrow )
	 {
			$ForeignKeys[$nFK]            = {};
			$ForeignKeys[$nFK]->{Name}    = $FKS[1];
			$ForeignKeys[$nFK]->{IdxName} = $FKS[0];
      $ForeignKeys[$nFK]->{Columns} = GetColumnsOfIndex($FKS[0]);
			$ForeignKeys[$nFK]->{ReferencedTable}   = $FKS[2];
			$ForeignKeys[$nFK]->{ReferencedTableID} = $FKS[3];
			$ForeignKeys[$nFK]->{ReferencedIdxName} = $FKS[4];
      $ForeignKeys[$nFK]->{ReferencedColumns} = GetColumnsOfIndex($FKS[4]);
			$nFK++;
	 }
}

#  ===========================================================================
#  Show the foreign key(s) of the current table
#  ===========================================================================
sub ShowFK
{
	 if ( $#ForeignKeys < 0 ) { return; }

	 print "<table border>";
	 print "<br><tr><th>Chaves estrangeiras</th>";
	 for ( $j = 0 ; $j <= $#ForeignKeys ; $j++ )
	 {
			if ( $j > 0 ) { print "<tr><td></td>"; }
			print "<td>(";
			$k=0;
	    foreach ( @{$ForeignKeys[$j]->{Columns}} )
	    {
				 if ( defined( $_ ))
				 {
				    if ( $k != 0 ) { print ","; }
						print "$_";
				 }
				 $k++;
			}
			printf ") referencia $ForeignKeys[$j]->{ReferencedTable} (";
			$k = 0;
	    foreach ( @{$ForeignKeys[$j]->{ReferencedColumns}} )
	    {
				 if ( defined( $_ ))
				 {
				    if ( $k != 0 ) { print ","; }
						print "$_";
				 }
				 $k++;
			}
			print ")</td></tr>";
	 }
	 print "</table>"
}


#  ===========================================================================
#  Get the default value for table id and colnumber
#  ===========================================================================
sub GetDefault
{

   my $str = qq/
   select type, default
			from sysdefaults
			where tabid=$_[0] and colno = $_[1]
/;
	 #print "SQL : $str<p>";
	 $StDef = $db->prepare($str);
	 $StDef->execute or die "Cant execute statement";
	 my $Val = "-";
	 while ( @Def = $StDef->fetchrow )
	 {
		 if ( $Def[0] eq "U" )
				{ $Val = "Utilizador"; }
		 elsif ( $Def[0] eq "C" )
				{ $Val = "Hora do sistema"; }
		 elsif ( $Def[0] eq "N" )
				{ $Val = "Nulo"; }
		 elsif ( $Def[0] eq "T" )
				{ $Val = "Data e hora do sistema"; }
		 elsif ( $Def[0] eq "S" )
				{ $Val = "Nome do servidor"; }
     else
				{ $Val = $Def[0] }
   }
	 return $Val;
}

#  ===========================================================================
#  Get the checks of a table to an array.
#  The, passing the colno must be possible to see the checks where the colummn
#  enter
# ??? This is not tested
#     ARGUMENTS
#         0 - tabid : Table id of the table we want
#  ===========================================================================
sub GetChecks
{
   $str = qq/select sysconstraints.constrid, checktext , seqno 
		 from syschecks, sysconstraints 
		 where tabid = $_[0] and 
			 syschecks.constrid = sysconstraints.constrid  and type='T' 
			 order by sysconstraints.constrid, seqno 
/;
	 #print "SQL : $str<p>";
	 $StCheck = $db->prepare($str);
	 $StCheck->execute or die "Cant execute statement";
	 $ChkID = -1;
	 $CheckNum = 0;
	 $CheckTxt = "";
	 while ( @Check = $StCheck->fetchrow )
	 {
			$ChkID = $Check[0];
			if ( $ChkID != $Check[0] and $ChkID != -1)
			{
				 $Checks[$CheckNum] = $CheckTxt;
				 print "Check $Checks[$CheckNum]<P>";
				 $CheckNum++;
			}
      else
			{
				 $CheckTxt .= $Check[1];
			}
	 }
}

#  ===========================================================================
#  Documentation of the table passed as parameter (tabid just for informix)
#  for the first version
#  Getting Column information. For now wee use the good old method ! 
#  There is no table info for dbi::Informix
#  ===========================================================================
sub DocTable
{
   GetKeys($_[0]);
	 GetChecks($_[0]);
	 my $SelectList = "syscolumns.colname, syscolumns.coltype, ".
								 "syscolumns.collength, syscolumns.colno";
	 my $From = "syscolumns";
	 my $Where = "syscolumns.tabid='$_[0]'";
	 my $Order = " order by syscolumns.colno ";
	 my $Join  = "";

	 if ( $ExistColumnExt )
	 {
			$SelectList .= ",syscolumnext.remarks";
			$From       .= ",outer syscolumnext";
			if ( defined($Where) )       
			{
				 $Where .= " and syscolumnext.tabname='$_[1]'";
			   $Join  = " and syscolumnext.colname=syscolumns.colname";
      }
	 }
	 $str = "select $SelectList from $From where $Where $Join $Order";
	 # &debug($str);
	 $st_tab = $db->prepare($str) or die "Error : " .  $db->errstr;
	 $st_tab->execute or die "Cant execute statement";

	 print q|
<table border>
<tr><th>Nome</th><th>Tipo</th><th>Nulos</th><th>Default</th>
<th>Validação</th><th>Descrição</th></tr>
|;
	 while ( @Coluna = $st_tab->fetchrow )
	 {
			# ??? Se coluna faz parte da PK <font color=green>"
			print "<tr><td>$Coluna[0]</td>";
			# ??? Se coluna faz parte da PK </font>"
			print "<td>". GetStrTipo($Coluna[1],$Coluna[2]) . "</td>";
			if ( $Coluna[1] > 255 )
				 { print "<td>Não</td>"; }
      else
				 { print "<td>Sim</td>"; }
			my $Default = GetDefault($_[0],$Coluna[3]);
			print "<td>$Default</td>";   # Just for now
			print "<td>-</td>";
			if ( $ExistColumnExt )
			{
			   if (defined($Coluna[4]))
			         { print "<td>$Coluna[4]</td>"; }
						else
			         { print "<td>-</td>"; }
			}
			print "</tr>";
	 }
	 print "</table>";

	 # Chaves primarias , secundarias . ver no date se nao sera candidata)
	 ShowKeys($_[0]);

	 # Chaves estrangeiras
	 GetFKS($_[0]);
	 ShowFK();
}

#  ===========================================================================
#  Main
#  ===========================================================================
   # Tenho de receber o DBName como Parametro (metodo post)
	 GetDBEnvironment();
	 InformixEnvironment();

	 # This should be possible to configure with some .ini
	 my $ModTabTableName = "d_mod_tab";
	 my $ModPK        = "codmod";
	 my $TabPK        = "tabname";
	 my $TablesTableName = "systables";
	 my $TablesPK        = "tabid";
	 my $ModuleDesc      = "tabname";

	 $Module = param("module_code");

	 $DBName = param("database");
	 if (!defined($DBName))
	    { $DBName = "despodata"; }

   $db = DBI->connect ( "dbi:Informix:".$DBName ) or die "Error connecting to DB";

	 VerifyExtended();
	 SeeNumIdxColumns();

   print header, start_html('Estrutura de tabelas da BD ' . $DBName ),
         h1('Indice de Tabelas da BD ' . $DBName );

	 # Construcao do query
	 $SelectList = "systables.tabid,systables.tabname";
	 $StrFrom    = " systables ";
	 $StrWhere   = " systables.tabname not like 'sys%' " .
								 " and systables.tabname not like '%VERSION%'" .
								 " and systables.tabname not like '%GL_%'";
	 $OrderBy    = "systables.tabname";

   if ( $ExistTableExt )
	 {
			$SelectList .= ",remarks";
			$StrFrom    .= ", outer systableext";
			$StrJoin     = " systables.tabname=systableext.tabname ";
   }

	 # ??? The configuration of module table should be after this version
	 if ( defined($Module) and $ExistModules )
	 {
			if ( $Module eq "NOMODULE" ) {
			  if (defined($StrWhere) ) { $StrWhere .= " and "; }
			  $StrWhere   .= " systables.tabname not in (select d_mod_tab.tabname from " .
				               " d_mod_tab )";
        print h2('Tabelas nao associadas a modulos' . $Module );
			}
			else {
			  $StrFrom    .= ",d_mod_tab";
			  if (defined($StrJoin) ) { $StrJoin .= " and "; }
			  $StrJoin    .= " systables.tabname=d_mod_tab.tabname ";
			  if (defined($StrWhere) ) { $StrWhere .= " and "; }
			  $StrWhere   .= " d_mod_tab.codmod='" . $Module . "'";
  
        print h2('Módulo ' . $Module );
			}
	 }

	 
	 $str = "select $SelectList from $StrFrom where $StrWhere ";
	 if ( defined($StrJoin) ) {
	    $str = $str . " and $StrJoin";
	 }
	 $str = $str . " order by $OrderBy";
	 #print "$str";

	 #Just debug to go to garbage later on
	 print "SQL : $str", br;
	 $st = $db->prepare($str) or die "Error : " .  $db->errstr;
	 $st->execute or die "Cant execute statement";
	 @NomeTabela = ();
	 @IdTabela   = ();
	 while ( @Linha = $st->fetchrow )
	 {
			if (defined(@Linha))
			{
			   @IdTabela =   (@IdTabela, $Linha[0]);
			   @NomeTabela = (@NomeTabela, $Linha[1]);
				 if ( $ExistTableExt )
				 {
			      if (defined($Linha[2]))
			         { @DescTabela = (@DescTabela, $Linha[2]); }
						else
			         { @DescTabela = (@DescTabela, "-"); }
				 }
				 else 
			      { @DescTabela = "Descrição"; }
			}
	 }


	 print q|
<table border>
<tr><th>Nome</th><th>Descrição</th></tr>
|;
	 for ( $i = 0 ; $i <= $#NomeTabela ; $i++ )
	 {
			print "<tr>";
			print "<td><a href=#$NomeTabela[$i]>$NomeTabela[$i]</a></td>";
			if ( $ExistTableExt )
			   {print "<td>$DescTabela[$i]</td>";}
      else
			   {print "<td align=center>-</td>";}
			print "</tr>";
	 }
	 print qq|
</table>
|;
   $st->finish;


	 print h1('Definição das tabelas');
         $num_tabelas = $#NomeTabela + 1;
	 print " Existem $num_tabelas tabelas\n";
	 for ( $Tab = 0 ; $Tab <= $#NomeTabela ; $Tab++ )
	 {
			# The alternate name should be the alias of the table. Not remarks
			if ( $DescTabela[$Tab] eq "-" ) 
				 { $Desc=""; } 
			else 
				 { $Desc="- $DescTabela[$Tab]";}
			print "<a name=$NomeTabela[$Tab]></a>";
			# ??? Ainda falta aqui qualquer coisa
			print "<a href=/cgi-bin/DbDocUpdDescription.cgi?server=$server&" .
				 "database=$DBName&table=$NomeTabela[$Tab]>";
	    print h2("$NomeTabela[$Tab] $Desc </a>");
			DocTable($IdTabela[$Tab],$NomeTabela[$Tab]);
	 }
   $db->disconnect ;
#  End main
