#!/usr/bin/perl -w

# ===========================================================================
# Db Documenter routines to get database from an Informix instance
# and execute dbdocumenter
# ===========================================================================

# Autor : Sergio Ferreira

use POSIX;
use CGI qw/:standard/;
use CGI::Carp qw(fatalsToBrowser);
use DBI;

#  This should be more generic but for now it stays 
sub ValInformixEnv
{
   $ENV{INFORMIXDIR} = "/usr/informix";
   $ENV{INFORMIXSERVER} = "unstable";
}

sub DbDocError
{
   print header,start_html, "$_", end_html;
}


# MAIN
   print header,start_html('DB Documenter - Database selecction');

	ValInformixEnv();

  $serversfile="$ENV{INFORMIXDIR}/etc/sqlhosts";
  @servers = `cat $serversfile|grep -v '^#'|grep -v '^ *\$'|cut -d' ' -f1`;
  #print "Servers: ", @servers,br;
  print h1("AVAILABLE DATABASES");

  foreach $server ( @servers )
  {
	  chomp($server);
	  #print br,"Server: $server",br,"<BLOCKQUOTE>";
     $ENV{INFORMIXSERVER} = $server;
     $Database = "sysmaster";

     $dbh = DBI->connect("dbi:Informix:$Database");

	   print "<HR><H2>Server: $ENV{INFORMIXSERVER}</H2>";
	   print "<BLOCKQUOTE>";
	   $StrSql = "select name from sysdatabases where name not like 'sys%' ";
	   $sth = $dbh->prepare($StrSql);
	   $ans = $sth->execute();
	   while ( $ans )
	   {
	      @ary = $sth->fetchrow_array;
		   if ( $#ary < 0 )
		   {
			   last;
		   }
		   print "<P>", 
					a({href=>"/cgi-bin/DbDocModules.cgi?server=$server&database=$ary[0]"},
					"$ary[0]");
      }
	   print "</BLOCKQUOTE>";
 }
 print end_html;
   
# END MAIN
