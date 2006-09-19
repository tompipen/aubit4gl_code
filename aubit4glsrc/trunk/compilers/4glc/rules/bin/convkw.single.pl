#!/usr/bin/perl
eval 'exec /usr/bin/perl -S $0 ${1+"$@"}'
    if $running_under_some_shell;
			# this emulates #! processing on NIH machines.
			# (remove #! line above if indigestible)

eval '$'.$1.'$2;' while $ARGV[0] =~ /^([A-Za-z_0-9]+=)(.*)/ && shift;
			# process any FOO=bar switches

open(GENERATED_SINGLE_WORDS, '>generated/single_words') ||

  die 'Cannot create file "generated/single_words".';

$[ = 1;			# set array base to 1
$, = ' ';		# set output field separator
$\ = "\n";		# set output record separator

line: while (<>) {
    chomp;	# strip record separator
    @Fld = split(' ', $_, -1);
    if (/^#/) {
	next line;
    }
    if (/FKEY/) {
	next line;
    }
    if (/SINGLE_KEY/) {
	next line;
    }
    if (/CONTROL_KEY/) {
	next line;
    }
    if (($#Fld >= 1)) {
	$kw = $Fld[1];
	if ($def{$kw}) {
	    next line;
	}
	$def{$kw} = 1;
	if (length($Fld[2]) > 1) {
	    if ($#Fld <= 2) {
		print GENERATED_SINGLE_WORDS $kw;
	    }
	}
    }
}
