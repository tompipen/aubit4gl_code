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
    #FIXME: get this from Autoconf:
   $ENV{INFORMIXDIR} = "/opt/informix";
   $ENV{INFORMIXSERVER} = "aptiva_ids";
}

sub DbDocError
{
   print header,start_html, "$_", end_html;
}


# MAIN
   print header,start_html('DB Documenter - Database selecction');

	ValInformixEnv();

  $serversfile="$ENV{INFORMIXDIR}/etc/sqlhosts";

  @servers = `cat $serversfile|grep -v '^#'|grep -v '^ *\$'|  sed -e 's/	/ /g' | cut -d' ' -f1`;

  if (defined($DEBUG)) {
  	print "Servers: ", @servers,br;
  }
  print h1("AVAILABLE DATABASES");

  foreach $server ( @servers )
  {
	 chomp($server);
     $ENV{INFORMIXSERVER} = $server;
     $Database = "sysmaster";

	 if (defined($DEBUG)) {
		 print br,"Server: $server",br,"Database: $Database<BLOCKQUOTE>";
     }

     $dbh = DBI->connect("dbi:Informix:$Database")
		or die "Error connecting to DB.";
		#or die "Error connecting to DB: " .  $dbh->errstr;

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
