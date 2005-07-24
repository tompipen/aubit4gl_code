#!/usr/bin/perl -pi.cface
# Copyright (C) 1992-2000 Sanderson Australia Pty. Limited

# blow away existing lines with CFACE
$_ = '' if m:^\Q/*JFACE*/:;
$_ = '' if m:^CFACE\(:;		# sanderson hystorical

# detect function definitions
if($x = /^function\((\w+),(\d+),(\d+),(\d+),(-?\d+)\)/ .. /^}/)
{
    if($x == 1)
    {
	($name, $min, $max, $step, $ret) = ($1, $2, $3, $4, $5);
	$target = $name;
    }

    # look for RUNNER macros only in the function header
    if(/^function/ .. /^\{/)
    {
	# get possible function name override for Four J's
	if(/^\s*RUNNER\("?.*\bfglext(?:\s+|:)(\w+).*"?\)/)
	{
	    $target = $1;
	}
    }

    if($x =~ /E0$/)
    {
	for($i = abs $min; $i <= abs $max; $i += $step)
	{
	    s:$:\n/*JFACE*/ int ${target}_${i}(int nargs) { return $name(nargs); }:;
	}
    }
}
