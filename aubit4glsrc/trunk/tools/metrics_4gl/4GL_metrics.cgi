#!/usr/bin/perl

# ---------------------------------------------------
# Simple metrics to evaluate informix 4GL-code.
# Analysis : 
#   1. if number of lines > 250 raise a warning
#   2. if complexity > 10 raise warning
#
# AUTHOR : Renaat Van Hee
#
# ---------------------------------------------------
# CALL : 4GL_metrics UIT FILE1 FILE2 FILE3 FILE4 ...
#           UIT = csv = output to delimited file
#                 ... = output for printer
#           FILE? = List of files to evaluate
# ---------------------------------------------------
# HISTORY
#  1997       : original LOC-metric
#  18/01/1998 : added cyclomatic complexity (V(G)) metric
# ---------------------------------------------------

$UIT = shift @ARGV;

foreach $BESTAND (@ARGV) {
  process();
  if ($UIT eq "csv") {
   Dump_csv();
  }
  else {
   Print_Rapport();
  }
}

### -------------------------------------
### de eigenlijke verwerking
### -------------------------------------
sub process {

$teller = 0;
$RESULTAAT[$teller]{"blanco"}=0;
$RESULTAAT[$teller]{"comment"}=0;
$RESULTAAT[$teller]{"totaal"}=0;
$RESULTAAT[$teller]{"control"}=0;
 
$TOTAAL1 = 0;
$TOTAAL2 = 0;
$TOTAAL3 = 0;

# lijnen voor de scheiding
$teller = 1;
$naam = "separator";
Init();

# lijnen voor de hoofding
$teller = 2;
$naam = "header";
Init();
$over = 2;

# inlezen van het bestand
$BEST = "<$BESTAND";
open(BEST) ;
while (<BEST>) {
    $lijn= $_;
    chomp($lijn);

    # type van lijn gaan bepalen
    SWITCH: {
       # een commentaar lijn ?
       # ---------------------
       if ((($cnt = $lijn =~ s/(^[\#][\#]*)/$1/) > 0) ||
           (($cnt = $lijn =~ s/--/--/g) > 0) ||
	   (($cnt = $lijn =~ s/^\{/^\{/g) > 0)) {

	   $RESULTAAT[$over]{"comment"}++;

	   last SWITCH;
       }
       # een commentaar lijn ?
       # ---------------------
       if (length($lijn) < 2) {


	   $RESULTAAT[$over]{"blanco"}++;

	   last SWITCH;
       }
       # een nieuwe functie ?
       # ----------------------------
       if (($cnt = $lijn =~ s/^FUNCTION (\w)(..*)/FUNCTION $1$2/i) > 0) {

	   $naam = $lijn;
	   $naam =~ s/FUNCTION //gi;
	   $naam =~ s/\(.*//gi;

	   $teller++;
	   Init();
	   $over = $teller;
	   last SWITCH;
       }
       # een nieuw rapport ?
       # ----------------------------
       if (($cnt = $lijn =~ s/^REPORT (\w)(..*)/REPORT $1$2/i) > 0) {

	   $naam = $lijn;
	   $naam =~ s/REPORT //gi;
	   $naam =~ s/\(.*//gi;
	   $teller++;
	   Init();
	   $over = $teller;
	   last SWITCH;
       }
       # einde rapport/functie
       # ----------------------------
       if ((($cnt = $lijn =~ s/(^END REPORT)/$1/i) > 0) || 
	   (($cnt = $lijn =~ s/(^END FUNCTION)/$1/i) >0)) {

           $RESULTAAT[$teller]{"totaal"}++;
           $over=1;
           $RESULTAAT[$over]{"totaal"}--;
	   last SWITCH;
       }
       # een control flow commando ?
       # ----------------------------
       if ((($cnt = $lijn =~ s/(IF (..*))/$1/i) > 0) ||
           (($cnt = $lijn =~ s/(FOR[ ][ ]*)/$1/i) > 0) ||
           (($cnt = $lijn =~ s/(WHILE (..*))/$1/i) > 0) ||
           (($cnt = $lijn =~ s/(^[ ]* CASE)/$1/i) > 0)) {

           $RESULTAAT[$teller]{"control"}++; 
	   last SWITCH;
       }

    }
       $RESULTAAT[$over]{"totaal"}++;

}
close(BEST);

Afsluiten();


}

### ------------------------------------
### RAPPORT
### ------------------------------------
sub Print_Rapport {

   # init 
   $tijd = localtime;
   $risico = 0;

   # de hoofding
   print "Module : $BESTAND\n";
   print "Generated : $tijd\n";
   print '-' x 85, "\n\n";
   print chr(27),"\(s3B FUNC/REP\t\t\tBLNC\t\tCMNT\t\tLN\t\tV(G)",chr(27),"\(s0B\n";

   # de body
   for $i (1..$teller) {
   print $RESULTAAT[$i]{"naam"};
   if (length($RESULTAAT[$i]{"naam"}) > 23) { print "\t" }
   else {
   if (length($RESULTAAT[$i]{"naam"}) > 15) { print "\t\t" }
     else { print "\t\t\t" }
   }
   print $RESULTAAT[$i]{"blanco"},"\t\t";

   print $RESULTAAT[$i]{"comment"},"\t\t";
   if ($RESULTAAT[$i]{"totaal"} > 250) {
     print chr(27),"\(s3B",$RESULTAAT[$i]{"totaal"},chr(27),"\(s0B\t\t"
     }
     else {
     print $RESULTAAT[$i]{"totaal"},"\t\t"
   }
   if ($RESULTAAT[$i]{"control"} > 10) {
      ++$risico;
      print chr(27),"\(s3B",$RESULTAAT[$i]{"control"} ,chr(27),"\(s0B";
     }
     else {
     print $RESULTAAT[$i]{"control"}
   }
   print "\n";
   }
   print '-' x 85, "\n\n";
   print "TOTAL \t\t\t\t $TOTAAL1 \t\t $TOTAAL2 \t\t $TOTAAL3 \n\n";
   print "Number functions : ",$teller-2,"\n";
   if ($teller > 2) {
     print "Avg. #lines/function : ",int (($TOTAAL3-$RESULTAAT[1]{"totaal"}-$RESULTAAT[2]{"totaal"})/($teller-2)),"\n\n";

     print "Percentages : blanco ", int ($TOTAAL1 / ($TOTAAL3 / 100))," %\n";
     print " " x 14,"comment ", int ($TOTAAL2 / ($TOTAAL3 / 100))," %\n\n";
     print "Possible risk-functions : ",$risico," ( V(G)>10 )\n\n";
   }

   print "4GL metrics \t\t\t Renaat Van Hee \n\n";
}

### ----------------------------------------
### een csv - bestand aanmaken
### ----------------------------------------
sub Dump_csv {

   # de hoofding
   print "Module : $BESTAND\|\|\|\n";
   print "FUNC/REP\|BLNC\|CMNT\|LN\|V(G)\n";
   for $i (1..$teller) {
     print $RESULTAAT[$i]{"naam"},"\|";
     print $RESULTAAT[$i]{"blanco"},"\|";
     print $RESULTAAT[$i]{"comment"},"\|";
     print $RESULTAAT[$i]{"totaal"},"\|";
     print $RESULTAAT[$i]{"control"},"\n";
   }

}


### -----------------------------------------
### initialisatie
### -----------------------------------------
sub Init {

    # de totalen aanpassen
    $TOTAAL1 += $RESULTAAT[$teller-1]{"blanco"};
    $TOTAAL2 += $RESULTAAT[$teller-1]{"comment"};
    $TOTAAL3 += $RESULTAAT[$teller-1]{"totaal"};

    # nieuwe structuur aanmaken
    $RESULTAAT[$teller]{"naam"} = $naam;
    $RESULTAAT[$teller]{"blanco"} = 0;
    $RESULTAAT[$teller]{"comment"}= 0;
    $RESULTAAT[$teller]{"totaal"} = 0;
    $RESULTAAT[$teller]{"control"}= 1;
}
### -----------------------------------------
### afsluiten
### -----------------------------------------
sub Afsluiten {

   # laatste functie nog bijtellen
   $TOTAAL1 += $RESULTAAT[$teller]{"blanco"};
   $TOTAAL2 += $RESULTAAT[$teller]{"comment"};
   $TOTAAL3 += $RESULTAAT[$teller]{"totaal"};

   # de scheiding nog bijtellen
   $TOTAAL1 += $RESULTAAT[1]{"blanco"};
   $TOTAAL2 += $RESULTAAT[1]{"comment"};
   $TOTAAL3 += $RESULTAAT[1]{"totaal"};

}
