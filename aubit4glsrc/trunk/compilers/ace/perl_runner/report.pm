#!/usr/local/bin/perl  -w
#
# This is the main perl runner module
# it must be copied somewhere in the perl include path
# 
# (c) 2002 Aubit Computing Ltd
#
# NOTE : This code is not covered by the GPL and is not part of the core 
#        Aubit4gl system or maintained by the Aubit4GL team.
# 
#        If you wish to use this code the following condition applies :
# 
#             You must NOT use this code in any commercial application
#             without prior consent of Aubit Computing Ltd 
#
# For full details of the licensing terms - please contact Aubit Computing Ltd
#
use strict;
use DBI;
use using;
package report;

my($report,$pageno,$lineno,$colno,$printing_trailer);
my(%agg_vals,$processing_mode);






sub clr_agg {
	my ($agg_id,$type)=@_;

	if ($type eq "AGG_AVG") {
		undef($agg_vals{$agg_id}{total}) if (defined($agg_vals{$agg_id}{total}));
		undef($agg_vals{$agg_id}{count}) if (defined($agg_vals{$agg_id}{count}));
		return;
	}

	if ($type eq "AGG_MAX") {
		undef($agg_vals{$agg_id}{max}) if (defined($agg_vals{$agg_id}{max}));
		return;
	}

	if ($type eq "AGG_MIN") {
		undef($agg_vals{$agg_id}{min}) if (defined($agg_vals{$agg_id}{min}));
		return;
	}

	if ($type eq "AGG_PERCENT") {
		undef($agg_vals{$agg_id}{pcok}) if (defined($agg_vals{$agg_id}{pcok}));
		undef($agg_vals{$agg_id}{pcnotok}) if (defined($agg_vals{$agg_id}{pcnotok}));
		return;
	}

	if ($type eq "AGG_TOTAL") {
		undef($agg_vals{$agg_id}{total}) if (defined($agg_vals{$agg_id}{total}));
		return;
	}

	if ($type eq "AGG_COUNT") {
		undef($agg_vals{$agg_id}{count}) if (defined($agg_vals{$agg_id}{count}));
		return;
	}


die("Unknown aggregate type [$type]");
}

#------------------------------------------------------------
#-- Go through all the current aggregate values
#-- and determine if they need 'cleaning' - if they
#-- do - call the function to clean them
#------------------------------------------------------------
sub reset_aggs {
	my ($varid)=@_;
	my($fmtid,$fmtcat,$fmtcol,$j,$thisvar,$aggtype);
	$j=0; 
	$thisvar=$report->{"report"}{"variables"}{$varid}{"name"};
	while (defined($report->{report}{aggs}{$j})) {
		$fmtid=$report->{report}{aggs}{$j}{format_id};
		$aggtype=$report->{report}{aggs}{$j}{aggtypes};

		$fmtcat=$report->{"report"}{"fmt"}{$fmtid}{"formattype"};
		$fmtcol=$report->{"report"}{"fmt"}{$fmtid}{"column"};

	 	if (($fmtcat eq "FORMAT_AFTER_GROUP" or $fmtcat eq "FORMAT_BEFORE_GROUP") && ($thisvar eq $fmtcol)) {
			clr_agg($j,$aggtype);
		}
		$j++;
	}
}



#------------------------------------------------------------
#-- On each row of data, this gets called to update the
#-- values stored against each of the aggregates
#------------------------------------------------------------
sub add_to_agg {
my($j);
my ($type,$where,$val);
$j=0;

while (defined($report->{report}{aggs}{$j})) {
	$type=$report->{report}{aggs}{$j}{aggtypes};
	
	if ($type ne "AGG_COUNT" and $type ne "AGG_PERCENT") { 
		$val=eval_expr($report->{report}{aggs}{$j}{expr});
	}

	if (defined($report->{report}{aggs}{$j}{wexpr})) {
		$where=eval_expr($report->{report}{aggs}{$j}{wexpr});
	} else {
		$where=1;
	}

	if ($type eq "AGG_COUNT") { $agg_vals{$j}{count}++ if ($where); }

	if ($type eq "AGG_TOTAL") {$agg_vals{$j}{total}+=$val if ($where); }


	if ($type eq "AGG_PERCENT") { 
		if ($where) {$agg_vals{$j}{pcok}++; }
		else        {$agg_vals{$j}{pcnotok}++;}
	}

	if ($type eq "AGG_AVG") { 
		if ($where) {
			$agg_vals{$j}{total}+=$val; 
	 		$agg_vals{$j}{count}++; 
		}
	}


	if ($type eq "AGG_MIN" && $where ) { 
		if (!defined($agg_vals{$j}{min})) {
			$agg_vals{$j}{min}=$val;
		} else {
				# NEED TO ADD NUMERIC CHECK HERE

			if (&compare($val,"<",$agg_vals{$j}{min})) {
				$agg_vals{$j}{min}=$val;
			}
		}
	}

	if ($type eq "AGG_MAX" && $where ) { 
		if (!defined($agg_vals{$j}{max})) {
			$agg_vals{$j}{max}=$val;
		} else {
				# NEED TO ADD NUMERIC CHECK HERE

			if (&compare($val,">",$agg_vals{$j}{max})) {
				$agg_vals{$j}{max}=$val;
			}
		}
	}
				

				
$j++;
}

}

#------------------------------------------------------------
#-- Get the aggregate value accumulated.
#-- 
#------------------------------------------------------------
sub process_expr_agg {
	my ($expr)=shift @_;
	my ($agg_id,$agg,$type,$val);
	$agg_id=$expr->{"aggid"};
	$agg=$report->{"report"}{aggs}{$agg_id};

	$type=$agg->{"aggtypes"};

	if ($type eq "AGG_TOTAL") { $val=$agg_vals{$agg_id}{total}; }
	if ($type eq "AGG_COUNT") { $val=$agg_vals{$agg_id}{count}; }
	if ($type eq "AGG_MAX") { $val=$agg_vals{$agg_id}{max}; }
	if ($type eq "AGG_MIN") { $val=$agg_vals{$agg_id}{min}; }

	if ($type eq "AGG_AVG") { 
		if ($agg_vals{$agg_id}{count}!=0) {
			$val=$agg_vals{$agg_id}{total}/$agg_vals{$agg_id}{count};
		} else {
			$val=0;
			warn("Divide by zero");
		}
 	}

	if ($type eq "AGG_PERCENT") {
		if (!defined( $agg_vals{$agg_id}{pcok})) {
			$agg_vals{$agg_id}{pcok}=0;
		}

		if (!defined( $agg_vals{$agg_id}{pcnotok})) {
			$agg_vals{$agg_id}{pcnotok}=0;
		}

		if ( $agg_vals{$agg_id}{pcok}+$agg_vals{$agg_id}{pcnotok} !=0) {
			$val=(100*$agg_vals{$agg_id}{pcok})/( $agg_vals{$agg_id}{pcok}+ $agg_vals{$agg_id}{pcnotok});
		} else {
			$val=0;
			warn("Divide by zero");
		}
	}

	return $val;
}


#------------------------------------------------------------
#-- Process a complex expression - ie one that has the form
#-- expr1 OP expr2
#------------------------------------------------------------
sub process_expr_complex {
	my ($expr)=shift @_;
	my ($left,$right,$op);

	$left=eval_expr($expr->{"expr"}{"expr1"});

	$op=$expr->{"expr"}{"expr_operands"};

	$right=eval_expr($expr->{"expr"}{"expr2"});

# following 2 lines to fix concation problem
if ( ! defined $right ) { $right=""; }
if ( ! defined $left ) { $left=""; }
	if ($op eq "EXPR_CONCAT") {return $left.$right;}
	if ($op eq "EXPR_MUL") {return do_math($left,'*',$right);}
	if ($op eq "EXPR_ADD") {return do_math($left,'+',$right);}
	if ($op eq "EXPR_SUB") {return do_math($left,'-',$right);}
	if ($op eq "EXPR_DIV") {return do_math($left,'/',$right);}
	if ($op eq "EXPR_MOD") {return do_math($left,'%',$right);}
	if ($op eq "EXPR_POW") {return do_math($left,'**',$right);}
	if ($op eq "EXPR_AND") {return $left && $right;}
	if ($op eq "EXPR_OR") {return $left || $right;}
	if ($op eq "EXPR_USING") {
		return using::using($left,$right);

	}

die "Unknown COMPLEX expression operator $op";
}

sub do_math {
my ($left,$op,$right)=@_;

# take out commas they botch the math
$left =~ s/,//g;
$right =~ s/,//g;

my $math;
my $add_currency=0;
if ($left =~ m/^ *?[\$](-?[0-9]+(\.[0-9]*)?)$/ ||
    $right =~ m/^ *?[\$](-?[0-9]+(\.[0-9]*)?)$/ ) {

   ($math = $left.$op.$right) =~ s/\$//g;
   $add_currency=1;
   }
else {
   $math = $left.$op.$right;
   }

$math=~s/ //g;
my $res = eval $math;

if ( $add_currency ) { $res = "\$".$res; }

return $res;
}

#------------------------------------------------------------
#-- Check to see if a value is numeric
#--
#------------------------------------------------------------
sub isnumeric {
  return 0 if ($_[0] !~ m/^([\d\s\+\-\.]+)$/);
  return 1 if ($1 eq $_[0]);
  return 0;
}


#------------------------------------------------------------
#-- Simple compare, idea is that parameters
#-- can be strings or numbers and they'll compare
#-- using the right Perl operators
#------------------------------------------------------------
sub compare {
my ($left,$op,$right)=@_;
        if (isnumeric($left)&&isnumeric($right)) {
                if ($op eq "=") {return $left==$right;}
                if ($op eq "!=") {return $left!=$right;}
                if ($op eq "<>") {return $left!=$right;}
                if ($op eq "<") {return $left<$right;}
                if ($op eq ">") {return $left>$right;}
                if ($op eq "<=") {return $left<=$right;}
                if ($op eq ">=") {return $left>=$right;}

        } else {
                if ($op eq "=") {return $left eq $right;}
                if ($op eq "!=") {return $left ne $right;}
                if ($op eq "<>") {return $left ne $right;}
                if ($op eq "<") {return $left lt $right;}
                if ($op eq ">") {return $left gt $right;}

                if ($op eq "<=") {
                        return $left le $right;
                }
                if ($op eq ">=") {
                        return $left ge $ right;
                }

# FIXME - Need to implement LIKE and MATCHES as REGEXPR @TODO
                #if ($op eq "like") {return $left>=$right;}
                #if ($op eq "matches") {return $left>=$right;}
        }
die "Unknown comparison operator '$op'\n";
}

#------------------------------------------------------------
#-- Wrapper for compare to get the values from the expression
#--
#------------------------------------------------------------
sub process_expr_compare {
	my ($expr)=shift @_;
	my($left,$right,$op);

	$left=eval_expr($expr->{"cexpr"}{"expr1"});
	$right=eval_expr($expr->{"cexpr"}{"expr2"});
	$op=$expr->{"cexpr"}{"method"};

	return (compare($left,$op,$right));
}



#------------------------------------------------------------
#-- Plain string
#--
#------------------------------------------------------------
sub process_expr_string {
	my ($expr)=shift @_;
	my($s);
	$s=$expr->{"s"};
	return $s;
}

#------------------------------------------------------------
#-- Simple expressions ie. ones that have the form
#-- expr OP
#-- Eg SPACES, IS NULL, CLIPPED etc.
#------------------------------------------------------------
sub process_expr_simple {
	my ($expr)=shift @_;
	my($left,$op);
	$left=eval_expr( $expr->{"sexpr"}{"expr"});
	$op=$expr->{"sexpr"}{"expr_operands"};

        if ($op eq "EXPR_ASCII")  { my $r=sprintf("%c",$left); return $r; }
        if ($op eq "EXPR_COLUMN") { return "%AARC_COLUMN{".$left."}"; }
        if ($op eq "EXPR_SPACES") { return " " x $left;}
        if ($op eq "EXPR_ISNULL") { return defined($left);}
        if ($op eq "EXPR_ISNOTNULL") { return !defined($left);}
        if ($op eq "EXPR_CLIP") { return trim($left);}

die "Unknown SIMPLE expression operator $op\n";
}

sub trim {
    my $string = shift;
    for ($string) {
        s/\s+$//;
    }
    return $string;
}


#------------------------------------------------------------
#-- Plain integer
#--
#------------------------------------------------------------
sub process_expr_int {
	my ($expr)=shift @_;
	my($a);
	$a=$expr->{"i"};
	return $a;
}


sub get_today {
#@TODO - interpret DBDATE to get the right day month year formatting
	my ($now,$r,$today);
	$now=time;
	my($sec ,$min,$hr,$day,$mon,$year,$wday,$yday,$isdat)=localtime($now);

# Months are store 0-11 (go figure...)
	$mon++;

	$today=sprintf("%02d/%02d/%04d",$mon,$day,$year+1900);
	return $today;
}

#------------------------------------------------------------
#-- A variable
#--
#------------------------------------------------------------
sub process_expr_variable {
	my ($expr)=shift @_;
	my ($varid,$val);
	
	$varid=-1;

	$varid=$expr->{"varid"};


	if ($report->{"report"}{"variables"}{$varid}{"name"} eq "pageno") {
		$report->{"report"}{"variables"}{$varid}{"dataspace"}=$pageno;
	}


	if ($report->{"report"}{"variables"}{$varid}{"name"} eq "lineno") {
		print "reading lineno - $lineno\n";
		$report->{"report"}{"variables"}{$varid}{"dataspace"}=$lineno;
	}

	if ($report->{"report"}{"variables"}{$varid}{"name"} eq "today") {
		$report->{"report"}{"variables"}{$varid}{"dataspace"}=get_today();
	}
	
	$val=$report->{"report"}{"variables"}{$varid}{"dataspace"};


	if ($report->{"report"}{"variables"}{$varid}{"datatype"} == 1) {
		$val=using::using($val,"-----&");
	}

	if ( $report->{"report"}{"variables"}{$varid}{"datatype"} == 6 || $report->{"report"}{"variables"}{$varid}{"datatype"} == 2) {
		$val=using::using($val,"----------&");
	}

	#print "val = $val\n";
	return $val;
}


#------------------------------------------------------------
#-- Evaluate an expression.
#--
#------------------------------------------------------------
sub eval_expr {
	my ($expr)=shift @_;
	my($et);

	if (!defined($expr)) {
		die("No expression passed in!");
	}

	$et=$expr->{"exprtype"};
	if (!defined($et)) {
		die("No expression type specified");
	}
	if ($et eq "EXPRTYPE_NULL") { return process_expr_null($expr); }
	if ($et eq "EXPRTYPE_INT")  { return process_expr_int($expr); }
	if ($et eq "EXPRTYPE_DOUBLE")  { return process_expr_double($expr); }
	if ($et eq "EXPRTYPE_STRING")  { return process_expr_string($expr); }
	if ($et eq "EXPRTYPE_VARIABLE")  { return process_expr_variable($expr); }
	if ($et eq "EXPRTYPE_BUILTIN")  { return process_expr_builtin($expr); }
	if ($et eq "EXPRTYPE_COMPLEX")  { return process_expr_complex($expr); }
	if ($et eq "EXPRTYPE_SIMPLE")  { return process_expr_simple($expr); }
	if ($et eq "EXPRTYPE_LIST")  { return process_expr_list($expr); }
	if ($et eq "EXPRTYPE_COMPARE")  { return process_expr_compare($expr); }
	if ($et eq "EXPRTYPE_FCALL")  { return process_expr_fcall($expr); }
	if ($et eq "EXPRTYPE_AGG")  { return process_expr_agg($expr); }

die "Unknown expression $et\n";
	
}



sub skip_to_top_of_page() {
	my($lpageno);
	$lpageno=$pageno;
	while ($lpageno==$pageno) {
		report_print("\n");
	}
}


#------------------------------------------------------------
#-- This does absolutely nothing
#-- We need it for blank commands (like an else of an if that 
#-- isn't defined etc.
#------------------------------------------------------------
sub cmd_null 		{
# This does nothing
1;
}

#------------------------------------------------------------
#-- Execute an IF statement
#--
#------------------------------------------------------------
sub cmd_if 		{
	my($p)=@_;
	my($s);
	$s=eval_expr($p->{"condition"});
	if ($s)  {
		do_command($p->{"command"});
	} else {
		do_command($p->{"elsecommand"});
	}
}

#------------------------------------------------------------
#-- Execute a WHILE loop
#--
#------------------------------------------------------------
sub cmd_while 		{ 
	my($p)=@_;
	my($expr);

	while (1) {
		$expr=eval_expr($p->{condition});
		if (!($expr)) {last;}
		do_command($p->{"command"});
	}

}

#------------------------------------------------------------
#-- Assign an expression to a variable
#--
#------------------------------------------------------------
sub cmd_let 	{ 
	my($p)=@_;
	my($exprsub1,$exprsub2,$exprval);
	
	$exprsub1=eval_expr($p->{sub1});
	$exprsub2=eval_expr($p->{sub2});
	$exprval=eval_expr($p->{value});
	set_var($p->{varid},$exprval);
}


#------------------------------------------------------------
#-- Checks to see if we have enough room
#-- to print a block of text
#------------------------------------------------------------
sub cmd_need  	{ 
	my ($p)=shift @_;
	my($bottom_margin,$page_length,$nlines);

  	$bottom_margin=$report->{"report"}{"output"}{"bottom_margin"};
  	$page_length=$report->{"report"}{"output"}{"page_length"};

	$nlines=$p->{nlines};
	
	if ($lineno+$nlines+$bottom_margin > $page_length -1) {
		skip_to_top_of_page();
	}

}


#------------------------------------------------------------
#-- Pause execution until the user presses a key
#--
#------------------------------------------------------------
sub cmd_pause 		{ 
	my ($p)=shift @_;
	my ($response);
	print $p->{"message"}; $response=<STDIN>;
}


#------------------------------------------------------------
#-- Skip a specified number of lines (may need  expression parsing ?)
#-- a value of -1 for nlines means top of page
#------------------------------------------------------------
sub cmd_skip 		{ 
	my($p)=shift @_;
	my($e,$a);
	$e=$p->{"nlines"};

	if ($e==-1) {
		skip_to_top_of_page();
	} else {

		for ($a=0;$a<$e;$a++) {
			report_print("\n");
		}
	}

}

#------------------------------------------------------------
#-- print a value.
#--
#------------------------------------------------------------
sub cmd_print 		{ 
	my ($p)=shift @_;
	my($s);
	$s=eval_expr($p->{"print"});

	report_print($s); 
	if ($p->{"printnl"}) {
		report_print("\n");
	}
}

#------------------------------------------------------------
#-- Does anyone actually use this ?
#--
#------------------------------------------------------------
sub cmd_printfile 	{ die "PRINTFILE is not yet implemented" }


#------------------------------------------------------------
#-- Executes a block of commands
#-- (eg between a BEGIN and an END)
#------------------------------------------------------------
sub cmd_block 		{ 
	my ($p)=shift @_;
	my ($a);
	$a=0;
	
	while (defined($p->{commands}{$a})) {
			do_command($p->{commands}{$a});
			$a++;
	}
}


#------------------------------------------------------------
#-- @TODO
#--
#------------------------------------------------------------
sub cmd_call 		{ 
	die "You can't call external functions";
}


#------------------------------------------------------------
#--
#--
#------------------------------------------------------------
sub do_command {
	my ($cmd)=shift @_;
	my ($ct);
	$ct=$cmd->{"cmdtypes"};
	if ($ct eq "CMD_NULL") {return cmd_null($cmd->{"cmd_null"}); }
	if ($ct eq "CMD_IF") {return cmd_if($cmd->{"cmd_if"});}
	if ($ct eq "CMD_WHILE") {return cmd_while($cmd->{"cmd_while"});}
	if ($ct eq "CMD_LET") {return cmd_let($cmd->{"cmd_let"});}
	if ($ct eq "CMD_NEED") {return cmd_need($cmd->{"cmd_need"});}
	if ($ct eq "CMD_PAUSE") {return cmd_pause($cmd->{"cmd_pause"});}
	if ($ct eq "CMD_SKIP") {return cmd_skip($cmd->{"cmd_skip"});}
	if ($ct eq "CMD_PRINT") {return cmd_print($cmd->{"cmd_print"});}
	if ($ct eq "CMD_PRINTFILE") {return cmd_printfile($cmd->{"cmd_printfile"});}
	if ($ct eq "CMD_BLOCK") {return cmd_block($cmd->{"commands"});}
	if ($ct eq "CMD_CALL") {return cmd_call($cmd->{"cmd_call"});}

die "Unknown command : $ct";

}

#------------------------------------------------------------
#-- Set a variable (referenced by its ID to be a set value
#-- Should also check if datatype is ok.
#------------------------------------------------------------
sub set_var {
	my($varid,$val)=@_;
	$report->{"report"}{"variables"}{$varid}{"dataspace"}=$val;
	return 1;
}

#------------------------------------------------------------
#-- Prompts the user for any variables required
#------------------------------------------------------------
sub process_inputs {
my($response);
$a=0;
while ($report->{"report"}{"inputs"}{$a}) {
	print "\n";
	print $report->{"report"}{"inputs"}{$a}{"prompt"}."";
	$response=<STDIN>;
	chomp($response);
	if (!set_var($report->{"report"}{"inputs"}{$a}{"varid"},$response))  {
		print "Invalid response - please re-enter\n";
	} else {
		$a++;
	}
}

}


#------------------------------------------------------------
#-- Checks to see if the specified format definition is  in
#-- the report
#-- eg - does it have a 'FORMAT_PAGE_HEADER' 
#------------------------------------------------------------
sub has_format {

my ($category,$data)=@_;
my($a);
$a=0;

while ($report->{"report"}{"fmt"}{$a}) {
	if ($report->{"report"}{"fmt"}{$a}{"formattype"} eq $category) {


		if (!defined($data)) {
			return $a;
		}

		if ($data eq $report->{"report"}{"fmt"}{$a}{"column"}) {
			return $a;
		}
	}
	$a++;
}
return -1;

}


#------------------------------------------------------------
#-- Process a format section (if applicable)
#--
#------------------------------------------------------------
sub process_format {
my ($category,$data)=@_;
my ($fmt,$a);


$a=has_format($category,$data);

if ($category eq "FORMAT_FIRST_PAGE_HEADER" && $a==-1) { 
	$a=has_format("FORMAT_PAGE_HEADER"); 
}


if ($a!=-1) {
	$fmt=$report->{"report"}{"fmt"}{$a};
	$a=0;
	while (defined($fmt->{"commands"}{"commands"}{$a})) {
			do_command($fmt->{"commands"}{"commands"}{$a});
			$a++;
	}

} else {
	#print "Nothing to do\n";
}

if ($category eq "FORMAT_PAGE_TRAILER") { 
	  my($page_length,$top_of_page);

  	  $page_length=$report->{"report"}{"output"}{"page_length"};
  	  $top_of_page=$report->{"report"}{"output"}{"top_of_page"};
	
	   if (!defined($top_of_page) || !length($top_of_page)) {
	   	while ($lineno < $page_length)  { 
				report_print("\n"); 
	   	}
		#print "lineno was $lineno - clearing\n";
 	   	$lineno=0;
	   } else {
		#print "2.lineno was $lineno - clearing\n";
			$lineno=0;
			report_print($top_of_page);
	   }
}

}




#------------------------------------------------------------
#-- Copy any command line arguments into the right variables
#------------------------------------------------------------
sub chk_params {
my($a,$mz,$z);
  $a=0;
  $mz=-1;
  while ($report->{"report"}{"variables"}{$a}) {
   if ($report->{"report"}{"variables"}{$a}{"param_no"} ne 0) {

     $z=$report->{"report"}{"variables"}{$a}{"param_no"};

     if ($z > $mz) {
	$mz=$z;
     }

     if ($z>$#ARGV) {
       die "You have not supplied enough arguments\n";
     }

     if (!set_var($a,$ARGV[$z]))  {
	die "Unable to set parameter $z from the data you gave me '".$ARGV[$z]."'\n";
     }

   }
   $a++;
  }

  if ($mz < $#ARGV) {
	print "WARNING : extra command line arguments have been ignored\n";
	print "(was expecting ".($mz+1)." got ".($#ARGV+1).")\n";
  }

}

#------------------------------------------------------------
#-- Get the variables associated with a select statement
#-- and return them as an array so we can use them on the
#-- execute statement
#------------------------------------------------------------
sub get_sql_vals {
my($sql_no)=@_;
my(@sql_vals,$a);
$a=0;
while ($report->{"report"}{"getdata"}{"selects"}{$sql_no}{"varids"}{$a}) {
	my $varid=$report->{"report"}{"getdata"}{"selects"}{$sql_no}{"varids"}{$a};
	$sql_vals[$a]=$report->{"report"}{"variables"}{$varid}{"dataspace"};
	$a++;
}
return @sql_vals;
}




#-------------------------------------------------------------
#-- Print something out to a report
#-------------------------------------------------------------
sub report_print  {
my ($data)=@_;
my($left_margin,$top_margin);
if (!defined($data)) { $data="<NULL>"; }

  if ($lineno==0) { 

	$processing_mode="PAGE_HEADER";
  	$top_margin=$report->{"report"}{"output"}{"top_margin"};

  	if ($top_margin) {
	  while ($lineno < $top_margin) {
		print OUTFILE "\n";
		$lineno++;
	  }
	}

	$colno=1;

	if ($pageno==0) {
		$pageno++;
		set_var(0,$pageno);
        	process_format("FORMAT_FIRST_PAGE_HEADER");
	} else {
		$pageno++;
		set_var(0,$pageno);
        	process_format("FORMAT_PAGE_HEADER");
	}

  }

  if ($colno<=1) {
  	$left_margin=$report->{"report"}{"output"}{"left_margin"};
  	if ($left_margin) {
	  while ($colno <= $left_margin) {
		print OUTFILE " ";
		$colno++;
	  }
	}

  }

  if ($data eq "\n") {
	my($bottom_margin,$page_length);
	  $lineno++;
	  $colno=1;
	  print OUTFILE "\n";

  	  $bottom_margin=$report->{"report"}{"output"}{"bottom_margin"};
  	  $page_length=$report->{"report"}{"output"}{"page_length"};

	  if ($lineno>($page_length-$bottom_margin) && $processing_mode ne "PAGE_TRAILER") {
		$processing_mode="PAGE_TRAILER";
		process_format("FORMAT_PAGE_TRAILER");
	  }

	  return;
  } 


# Do we have any embedded column positioning ?
  $a=index($data,"%AARC_COLUMN");

  if ($a!=-1) {
	my($next_brace,$rdata,$cdata);
	$a=index($data,"%AARC_COLUMN");
	last if ($a==-1) ;
	$rdata=substr($data,0,$a);
	$cdata=substr($data,$a+length("%AARC_COLUMN")+1,4);
	$next_brace=index($cdata,"}");
	$cdata=substr($cdata,0,$next_brace);
	$data=substr($data,$a+length("%AARC_COLUMN")+2+$next_brace,1000);
	report_print($rdata);
	report_print_column($cdata);
	report_print($data);
	return;
  }

  $colno+=length($data);
  print OUTFILE $data;
  
}
  

#-------------------------------------------------------------
#-- Print up to a given column number
#-------------------------------------------------------------
sub report_print_column {
  my ($column)=@_;
  my $left_margin=$report->{"report"}{"output"}{"left_margin"};

        $column+=$left_margin;

	while ($colno<=$column) {
		report_print " ";
	}
}

#-------------------------------------------------------------
#-- Print a given number of spaces
#-------------------------------------------------------------
sub report_print_spaces {
  my ($spaces)=@_;
  #print "report_spaces\n";
  report_print " " x $spaces;
}


#-------------------------------------------------------------
#-- Shorthand for printing an end of line
#-------------------------------------------------------------
sub report_print_nl {
        #print "report_print_nl\n";
	report_print "\n";
}

#-------------------------------------------------------------
#-- Goes through each piece of the data and calls the relevant
#-- formatting instructions
#-------------------------------------------------------------

sub process_data_set {
my($ref,$sql_no)=@_;
my($a,$b,$i,$j,$oldval,$newval,@diff,@sql_columns,@varids,$varid,$no_of_keys);

$b=0;
for ($a=0;defined($report->{"report"}{variables}{$a});$a++) {
	if ($report->{"report"}{variables}{$a}{category}==4) {
		$sql_columns[$b]=$report->{"report"}{variables}{$a}{name};
		$varids[$b]=$a;
		$b++;
	}
}

for ($j=0;defined($report->{report}{getdata}{selects}{$sql_no}{orderby_list}{$j});$j++) {}; $no_of_keys=$j;



for $i (0 .. $#{$ref} ) {

# Work out any differences in values
	for $j ( 0.. $#{$ref->[$i]} ) {

		$oldval=$report->{"report"}{variables}{$varids[$j]}{dataspace};

		if (!defined($oldval)) { $oldval="<AARC_REP_NULL>"; }

		$newval=$ref->[$i][$j];

		if (!defined($newval)) { $newval="<AARC_REP_NULL>"; }

		if ($oldval ne $newval) {
			$diff[$varids[$j]]=1;
		} else {
			$diff[$varids[$j]]=0;
		}
	}


	# Do after group
	#
	#
	# We only need to do this if something has changed
	# It may look like its changed on the first row too - but we'll ignore this...
	#
	if ($i!=0) {

		for ($a=0;$a<$no_of_keys;$a++) {
			$varid=$report->{report}{getdata}{selects}{$sql_no}{orderby_list}{$a};
			if ($diff[$varid]) {
				for ($b=$no_of_keys-1;$b>=$a;$b--) {
					$varid=$report->{report}{getdata}{selects}{$sql_no}{orderby_list}{$b};
					process_format("FORMAT_AFTER_GROUP", $report->{"report"}{"variables"}{$varid}{"name"});
				}
				last;
			}
		}


	}



	for $j ( 0.. $#{$ref->[$i]} ) {
		$report->{"report"}{variables}{$varids[$j]}{dataspace}=$ref->[$i][$j];
	}

	add_to_agg();

	for ($a=0;$a<$no_of_keys;$a++) {
			$varid=$report->{report}{getdata}{selects}{$sql_no}{orderby_list}{$a};
			if ($diff[$varid]) {
				reset_aggs($varid);
				for ($b=$a;$b<$no_of_keys;$b++) {
					$varid=$report->{report}{getdata}{selects}{$sql_no}{orderby_list}{$b};
					process_format("FORMAT_BEFORE_GROUP", $report->{"report"}{"variables"}{$varid}{"name"});
				}
				last;
			}
	}

	# Do before group ofs
	#
	#

	# Do the current row...
	process_format("FORMAT_ON_EVERY_ROW","");


}




for ($a=0;$a<$no_of_keys;$a++) {
	$varid=$report->{report}{getdata}{selects}{$sql_no}{orderby_list}{$a};
		if ($diff[$varid] || 1) {
				for ($b=$no_of_keys-1;$b>=$a;$b--) {
					$varid=$report->{report}{getdata}{selects}{$sql_no}{orderby_list}{$b};
					process_format("FORMAT_AFTER_GROUP", $report->{"report"}{"variables"}{$varid}{"name"});
				}
				last;
			}
		}




	process_format("FORMAT_ON_LAST_ROW","");
}


#------------------------------------------------------------
#-- This is the main entry point
#-- This should be called from the main definition file
#-- 
#-- Eg
#--   #!/usr/local/bin/perl  -w
#--   use DBI;
#--   require report;
#--   
#--   %report=(
#--           "report"=> {"magic"=>"AACE",
#--                       "report_name"=>"somename",
#--                       "dbname"=>"somedb",
#--                       "ascii"=> {"variables"=>{
#--                       }
#--                      }
#--            .
#--            .
#--   );
#--
#--   report::run_report(\%report,1);
#--
#--
#------------------------------------------------------------
sub run_report {
my ($this_report,$verbose)=@_;
my ($ref,$sth,@sql_variables,$dbtype,$dbh,$z,$sql,$rfile,$rwhere);

$report=$this_report;

$verbose=1;
$colno=1;
$pageno=0;
$lineno=0;
$processing_mode=0;


if ($verbose) {
	print "\nAubit Report Runner (c) 2002 Aubit Computing Ltd\n";
	print "\n\n";
}

if ($report->{"report"}{"magic"} ne "AACE") {
	print "report=$report\n";
	print "report->report=".$report->{"report"}."\n";
	print "report->report.magic=".$report->{"report"}{"magic"}."\n";

	die "This does not look like a report I can run...\n";
}

# Put any command line parameters where they should go..

&chk_params;

# Get any values that need prompting for...
&process_inputs;


if ( defined($ENV{'AACE_DB'})  ) {
	$dbtype=$ENV{'AACE_DB'};
} else {
	$dbtype="Informix";
}


# Connect to database...
$dbh = DBI->connect("DBI:$dbtype:".$report->{"report"}{"dbname"});

$rfile=$report->{"report"}{"output"}{"report_to_filename"};
$rwhere=$report->{"report"}{"output"}{"report_to_where"};

if ($rwhere==1) { $rfile="|lp"; }
if ($rwhere==2) { $rfile="|lp -P$rfile"; }
if ($rwhere==3) { $rfile=">$rfile"; }
if ($rwhere==4) { $rfile="|$rfile"; }


if ($rwhere==0) { 
	*OUTFILE=*STDOUT;
}
else  {
	open OUTFILE, $rfile
	or die("Unable to open report output: $!\n");
}



$z=$report->{"report"}{"getdata"}{"selects"}{0}{"statement"};


$a=0;

if ($verbose) {
	print "\nThe reading of the database will now begin.\n";
}

while (defined($report->{"report"}{"getdata"}{"selects"}{$a}{"statement"})) {
	if ($verbose) {
		print "\nExecuting select statement ".($a+1)."\n";
	}
	$sql=$report->{"report"}{"getdata"}{"selects"}{$a}{statement};
	if ($report->{"report"}{"getdata"}{"selects"}{$a}{temp_tab_name} eq "") {
		@sql_variables=&get_sql_vals($a);
		$sth = $dbh->prepare($sql);
		$sth->execute(@sql_variables);

		$ref=$sth->fetchall_arrayref();

		if ($verbose) {
			print "\nThe reading of the database has now finished.\n\n";
		}
		process_data_set($ref,$a);
		close OUTFILE;
		last;

	} else {
		@sql_variables=&get_sql_vals($a);
		$sth = $dbh->prepare($sql);
		$sth->execute(@sql_variables);
	}
	$a++;
}

}

1;
