#!/usr/bin/perl
# This script generates the C header file "wantkw.c" from the yacc/bison
# rule/state output file "../rules/generated/y.ouput".
# The functions in wantkw.c are used by yylex() to determine whether words
# in 4GL source code are to be returned to yyparse() as reserved word
# tokens, or as names of identifiers.

$YOUTPUT = "./rules/generated/y.output";
$YTABH = "./rules/generated/y.tab.h";
$CSOURCE = "./wantkw.c";
$HSOURCE = "./wantkw.h";

print "Generating $CSOURCE from $YOUTPUT ... \n";

open(IN, $YOUTPUT ) or die "Cannot read file $YOUTPUT\n";

# Read the Grammar section, for lines of the form
# number  line  symbol1 -> symbol2
#
# where symbol2 is either "identifier" or represents a single word
# symbol that is declared an identifier via some other rule(s)
# eg.
#    9 892 remote_func -> identifier
#  181 1632 define_ident -> @30 identifier
#  897 4388 let_variable -> let_var
#  ...
#  901 4452 let_var -> identifier
#  ...

# all the potentially single-word identifier-type symbols ('seed' it initially)
%ident = ("identifier" => 1, "var_ident" => 1, "NAMED" => "",
          "var" => 1, "variable" => 1, "let_var" => 1, "fgl_expr" => 1, );

# symbols that may be window/label/form ... names but not necessarily variables
%idn = ("identifier" => 1, "var_ident" => 1, "NAMED" => 1);

# symbols that may be replaced with (defined) variables
%var = ("var" => 1, "variable" => 1, "let_var" => 1,
	"var_ident" => 1, "fgl_expr" => 1, );

# all the symbols that can be empty (blank)
%empty = ();

# keywords that begin a command
%cmdkw = ();

# single-word rules are saved for use in keyword/identifier conflicts
%rule = ();

# temp. working space to hold symbols being evaluated
%sym = ();

@kwlist = ();

open(PP,">t");
# locate the Grammar section and find any symbols that can be /* empty */,
# also look for keywords that appear at the start of a command
$grammar = 0;
while(<IN>) {
  chomp;
  if ( $grammar )
  {
    # some older y.output's have 'rule' at starrt of rule line
    if ( /^\s*rule\s+\d/i ) { s/rule/123/i }
    # rule lines begin with space or digits
    # - anything else and we stop
    if ( /^[_a-z]/i )
     {
	last;
     }
    elsif (/^\s*\d+[\s\d]*\s+([_a-z]\w+)\s*->\s*\/.*empty.*\//)
     {
        $empty{$1} = 1;
     }
    elsif ( /(_command|_cmd)\s*->\s*([A-Z0-9_]+)\b/ )
     {
        $cmdkw{$2} = 1;
     }
    elsif ( /(_command|_cmd)\s*->\s*opt_use\s+([A-Z0-9_]+)\b/ )
     {
        $cmdkw{$2} = 1;
     }
  }
  elsif ( /^\s*Grammar\s*$/i ) {
	$grammar = tell IN;
  }
  print PP $_,"\n";
}
close(PP);

# re-read the Grammar section, we are now looking for any rules where
# the right hand side is potentially a single word identifier, ie.
# it is either 'NAMED' or a lower case word (after stripping empties)

seek IN, $grammar, 0;
while(<IN>) {
  chomp;
    # some older y.output's have 'rule' at start of rule line
    if ( /^\s*rule\s+\d/i ) { s/rule/123/i }

    # rule lines begin with space or digits - anything else and we stop
    last if /^[_a-z]/i;

    # is this a rule does with a left- and right-hand side ?
    if
    (/^\s*\d+[\s\d]*\s+([_a-z]\w+)\s*->\s*(@\d+\s+|\s*)(\w.*)$/)
    {
        ($left,$right) = ($1, $3);
    }
    else { next }

    # skip these, we know about them ...
    next if $left =~ /(var|variable|var_ident|identifier|NAMED)/;

    # remove leading/trailing spaces from right-hand side of rule
    $right =~ s/^\s+//;
    $right =~ s/\s+$//;

    # remove empty symbols from the right-hand side of the rule
    for $e ( keys %empty ) {
        if ( $right =~ /\b$e\b/ ) { $right =~ s/\b$e\b//g; }
    }

    # if this is a NAMED, its definitely an identifier
    if ( $right eq "NAMED" ) {
       $ident{$left} = 1;
       $idn{$left} = 1;
       if ( is_var($right) ) {
           $var{$left} = 1;
           next;
       }
       goto savesym
    }

    # save single-word rules for later use
    if ( $right =~ /^(\w+)$/ ) {
       if ( $rule{$left} ) { $rule{$left} .= "\n$right" }
       else { $rule{$left} = $right }
    }

    # only lower-case words are possible identifiers
    next unless ( $right =~ /^\s*([_a-z]\w+)\s*$/ );

    # if right-hand side is a known identifier, so is the left
    if ( is_ident($right) )
    {
       $ident{$left} = 1;
       $var{$left} = 1 if is_var($right);
       $idn{$left} = 1 if is_idn($right);
       next if ( $var{$left} && $idn{$left} );
    }

    # save to %sym if we're not yet fully decided whether
    # the rule describes an identifier and/or variable
    savesym: {
	if ( exists $sym{$left} ) {
             $sym{$left} .= "\n$right";
        }
	else {
             $sym{$left} = $right;
        }
     }
}

$pass=0;
# keep checking %sym for identifiers/vars, until we find no more
while ( 1 )
{
$pass++;
  my $n = 0;
  # test each entry, if the right is an identifier, so is the left
  while ( ($left,$right) = each %sym ) {
   if ( (! exists $ident{$left}) && is_ident($right) )
   {
      $ident{$left} = 1;
      $n++;
   }
   if ( (! exists $idn{$left}) && is_idn($right) )
   {
      $idn{$left} = 1;
      $n++;
   }
   if ( (! exists $var{$left}) && is_var($right) )
   {
      $var{$left} = 1;
      $n++;
   }
   delete $sym{$left} if ( $var{$left} && $idn{$left} );
  }
  last unless $n;
}

# at this point, we have the following lists:
# %ident - all known symbols that are, or can be, single word identifiers
# %idn   - identifiers that are names other than variables (window,cursor,...)
# %var   - identifiers that are defined 4gl variables
# %empty - symbols that can be empty
# %cmdkw - keywords that begin a 4GL command
# %rule  - single-word rules, for keyword/identifier resolution

# now, we continue reading y.output, looking for the "state" sections.
# we want to output a list of states which can accept an identifier
# as a valid next token, accompanied by a list of reserved words that
# are also valid next tokens for that state.

open(OUT,">$CSOURCE") or die "Cannot write file $CSOURCE\n";

print_head();

$state = -1;
$rule = "";
@words = "";
@kw = ();

while ( <IN> ) {
  chomp;
  if ( /^\s*state\s+(\d+)\s*$/ )
  {
      # state block starts with "state <number>" by itself on a line

      # output anything in the buffer
      print_state($state, $rule, join(",",@words), @kw);
      $state = $1;
      $rule = "";
      @words = ();
      @kw = ();
  }
  elsif ( $state < 0 )
  {
      next;
  }
  # look for rule like "left-side -> some-stuff  .  identifier other-stuff "
  elsif ( /^\s*\w+.*->.* \.\s+([_a-z]\w+)\b/ )
  {
      $rule = $_;
      $rule_has_ident = (exists $ident{$1} );
      if ( $rule_has_ident ) {
           push @words, $1;
           push @kw, rule_kwords( $1, 0 );
      }
  }
  elsif ( $rule && /^\s*([_a-z]\w+)\s+.*\bto\s+state\s+\d/ )
  {
      # state accepts lower case symbol as next token,
      # check if it is an identifier type
      if ( exists $ident{$1} ) {
           push @kw, rule_kwords( $1, 0 );
           push @words, $1 unless $rule_has_ident;
      }
  }
  elsif ( $rule && /^\s*([_A-Z]+)\s+.*(shift|reduce)/ )
  {
      # state can accept the named keyword token, save for later
	push @kw, $1;
  }
}
# output anything still in the buffer
print_state( $state, $rule, join(",",@words), @kw );

print_tail();

close(OUT);

close(IN);

print_dot_h();

print("Done\n");

#-----------------------------------
sub print_head {
#-----------------------------------

print OUT <<EOF;
/*
# This file is generated by $0, from ./rules/generated/y.output
# Do not edit it directly.
#*/

#include "$YTABH"
#include "$HSOURCE"

/**
 * Called from yylex().
 * Determines if a word in 4GL source code naming a keyword should
 * be returned to yyparse() as its keyword token, or treated as
 * just a user defined identifier/variable.
 *
 * \@param state  Current state of the parser (yystate)
 * \@param kw  The token value for the keyword to be checked
 * \@return
 *   - 0 : Return keyword token value
 *   - 1 : Return as variable identifier
 *   - 2 : Return as non-variable identifier
 *   - 3 : Return as either
 */
int
wants_kw_token( int state, int kw )
{

EOF

}

#-----------------------------------
sub print_state {
#-----------------------------------
 my $state = shift;  # parser state number
 my $rule  = shift;  # the rule being parsed (as text)
 my $words = shift;  # comma-separated list of identifier names

 return unless ( $state > 0 && $words && $rule );

 # return value : 0 = use keyword token, 1 = wants variable name,
 #                2 = wants identifier name, 3 = variable or identifier
 my $ret = 0;
 for $_ ( split(/,/, $words) ) {
   if ( $var{$_} ) { $ret |= 1 }
   if ( $idn{$_} ) { $ret |= 2 }
 }

 $rule =~ s/^\s+//;
 $rule =~ s/\(\s*rule\s+[^\(]*\)\s*$//;
 $rule =~ s/\s+$//;
 print OUT " /* $state: $rule\n */\n";

 # simplest case, no keyword token is expected at all
 if ( $#_ < 0 ) {
    print OUT " if ( state == $state ) return $ret;\n";
    return;
 }

 # the remaining args are a list of keyword tokens that this state
 # explicitly expects - build a sorted unique list from these

 my %kw = ();
 for ( @_ ) { $kw{$_} = 1 }
 my @kw = (sort keys %kw);

 # also simple case, there is only one possible keyword token
 if ( $#kw == 0 ) {
    print OUT " if ( state == $state ) return (kw==",$kw[0]," ? 0 : $ret);\n";
    return;
 }
 
 # More complex - there is a list of possible allowed tokens.
 # if the one passed is not in this list, then use identifier.
 # Many states/rules share the same lists, so for efficiency the
 # checking is done in separate functions.

 my $kwl = join ( ",", @kw );

 for ( $n = 0; $n <= $#kwlist,; $n++ ) {
     last if $kwlist[$n] eq $kwl;
 }
 if ( $n > $#kwlist ) { push @kwlist, $kwl }

 print OUT " if ( state == $state ) return (inkwlist$n(kw) ? 0 : $ret);\n";
}

#-----------------------------------
sub print_tail {
#-----------------------------------
# outputs the bottom part of the C source

print OUT <<EOF;

 // if we got here, no identifier is expected at all
 return 0;
}

EOF

# define the functions that check for keyword in some list

 for ( $n = 0; $n <= $#kwlist,; $n++ ) {

   print OUT
     "int inkwlist$n( int kw ) {\n",
     " switch (kw) {\n";

   for ( split( /,/, $kwlist[$n] ) ) { print OUT "\tcase $_:\n" }

   print OUT
     "\treturn 1;\n",
     " }\n",
     "\treturn 0;\n",
     "}\n";
 }

# append a function that checks if a keyword begins a command

print OUT
     "int is_commandkw( int kw ) {\n",
     " switch (kw) {\n";
for ( sort keys %cmdkw ) { print OUT "\tcase $_:\n" }
print OUT
     "\treturn 1;\n",
     " }\n",
     "\treturn 0;\n",
     "}\n";

# dump a list of the symbols we detected, ie. those that appear
# in the syntax rules and can be a single-word identifier/variable

 print OUT "\/* symbols that can be identifiers/variables\n";
 for $i ( sort keys %ident ) {
   my $txt = "";
   if ( $idn{$i} && $var{$i} ) { $txt = "VAR or IDENT" }
   elsif ( $idn{$i} )  { $txt = "IDENT" }
   elsif ( $var{$i} )  { $txt = "VAR" }
   $i .= " " while length($i) < 30;
   print OUT " $i  $txt\n";
 }
 print OUT "*/\n";
}

#-----------------------------------
sub print_dot_h {
#-----------------------------------

 open(OUT,">$HSOURCE") or die "Cannot write file $HSOURCE\n";

 print OUT <<EOF;
/*
# This file is generated by $0  -  Do not edit it directly.
#*/

#include "rules/generated/kw.h"

int wants_kw_token( int state, int kw );
int is_commandkw( int kw );

EOF

 for ( $n = 0; $n <= $#kwlist,; $n++ ) {
   print OUT
     "int inkwlist$n(int kw);\n";
 }

 close OUT;
}



#------------------------------
sub is_ident {
#------------------------------
  for ( split(/\n/, $_[0]) ) {
      if ( exists $ident{$_} ) { return 1 }
  }
  return 0;  
}

#------------------------------
sub is_idn {
#------------------------------
  for ( split(/\n/, $_[0]) ) {
      if ( exists $idn{$_} ) { return 1 }
  }
  return 0;  
}

#------------------------------
sub is_var {
#------------------------------
  for ( split(/\n/, $_[0]) ) {
      if ( exists $var{$_} ) { return 1 }
  }
  return 0;  
}

#------------------------------
sub rule_kwords {
#------------------------------
 my $left = shift;
 my $level = shift;

 my @w = ();

 # look for any single-word token names on right,
 # recursively descend into other lower-case names
 for $right ( split(/\n/, $rule{$left}) ) {
     if ( $right =~ /^[_A-Z].*[_A-Z]$/ )
     {
        push @w, $right;
     }
     elsif ( ($level < 10) && ($right =~ /^[_a-z]/) )
     {
        push @w, rule_kwords($right, $level+1);
     }
 }

 # sort/uniq the results
 my %w = ();
 for $_ ( @w ) { $w{$_} = 1 }

 return (sort keys %w);
}

