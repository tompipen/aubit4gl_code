:	"@(#)$Id: i4glxref.sh,v 1.1 2002-11-28 06:40:47 afalout Exp $"
#
#	Cross-reference for Informix-4GL

case $# in
0|1)	names=no;;
*)		names=yes;;
esac

# It is necessary to apply two separate sort criteria to the +2 field.
# -- The first groups case-insensitive collections of a word;
# -- the second groups case-sensitive collections of the same word.
# Beware the quotes in the second line of the AWK program.
# Note: this uses a version of AWK which understands functions.

fglxref $* |
sort -u -t: +2fd -3 +2 -3 +0 -1 +1n -2 |
${AWK:-nawk} -F: 'BEGIN {
	names="'$names'";
	if (names == "yes")
		refs_per_line = 8;
	else
		refs_per_line = 11;
}
function flushref(   n, i, items)
{
	# Do not output anything on first line of input
	if (lastref == "")
		return;
	if (names == "yes")
		printf("%-20s: %-14s:", lastref, lastfile);
	else
		printf("%-20s:", lastref);
	n = split(linedata, items, " *");
	for (i = 1; i <= n; i++)
	{
		if ((i - 1) % refs_per_line == 0 && i > 1)
		{
			if (names == "yes")
				printf("\n%-20s  %-14s ", "", "");
			else
				printf("\n%-20s ", "");
		}
		if (items[i] == "")
			continue;
		x = split(items[i], parts, "/");
		if (x == 1 || parts[2] == "") parts[2] = " ";
		printf("%4d%s", parts[1], parts[2]);
	}
	printf("\n");
}
{
	# Decode flag
	if ($4 == "D----")
		flag = "D";
	else if ($4 == "D--L-")
		flag = "L";
	else if ($4 == "-F---")
		flag = "F";
	else if ($4 == "-R---")
		flag = "R";
	else if ($4 == "-M---")
		flag = "M";
	else if ($4 == "--D--")
		flag = "B";
	else if ($4 == "----F")
		flag = "f";
	else if ($4 == "----W")
		flag = "w";
	else if ($4 == "----P")
		flag = "p";
	else if ($4 == "----D")
		flag = "d";
	else if ($4 == "-----")
		flag = " ";
	else
	{
		print $0;
		next;
	}

	if ($3 != lastref)
	{
		flushref();
		lastref  = $3;
		lastfile = $1;
		linedata = $2 "/" flag;
	}
	else if ($1 != lastfile)
	{
		flushref();
		lastfile = $1;
		linedata = $2 "/" flag;
	}
	else
	{
		linedata = linedata " " $2 "/" flag;
	}
	# print "<<" linedata ">>"
}
END			{ flushref(); }'
