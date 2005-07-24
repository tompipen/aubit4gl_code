#!/usr/bin/perl

#  ==================================================================
#  Generate a the C declaration of the toklens to the lexer and
#  the %token declaration to the bison parser.
#  ==================================================================

sub openFile
{
  open(KEYWORDS,"< kwords");
}

sub readToList
	my $keywordRow;
	foreach $keywordRow ( <KEYWORDS> )
	{
    if $keywordRow =~/^#/ {next}
		// Fazer split por espaços
		// Carregar uma tabela com token, id, lista de palavras
	}
}

sub genHFile
{
  open(H_FILE,"> generated/new_kw.h");
	print H_FILE "#include \"kw.h\"" ;
	print H_FILE "struct s_kw {" ;
	print H_FILE "    int id;" ;
	print H_FILE "	   int mode;" ;
	print H_FILE "    char *vals[20];" ;
	print H_FILE "};" ;

	my $i = 1;
	# Para cada token
		$i++;
	  print H_FILE "#define $token $i";

  close(H_FILE);
}

sub genTokenFile
{
  open(TOKEN_FILE,"> generated/new_kw.yh");
	my $i = 1;
	# Para cada token
		$i++;
	  print TOKEN_FILE "%token $token $i";
  close(TOKEN_FILE);
}

sub genCFile
{
  open(C_FILE,"> generated/new_kw.c");
	print C_FILE "#include generated/new_kw.h\n";

	# Para cada letra (elemento de tabela de letras)
	  print C_FILE "struct s_kw kwlist_$letter[] {";
		printStructTokens();
    print C_FILE "{0}";
    print C_FILE "};";
	
  close(C_FILE);
}

# Print the strcture of each element of the table 
sub printStructTokens
{
  print C_FILE "{$token,$id,{
	# For each reserved word
	  print C_FILE "\"$reservedWord\"";
	print C_FILE "0},";
}

sub closeFile
{
  close(KEYWORDS);
}

awk '
BEGIN {
doverbose="0"

a=1000
	print "#include \"kw.h\"" > "generated/kw.c"
	print "struct s_kw {" > "generated/kw.h"
	print "    int id;" > "generated/kw.h"
	print "	   int mode;" > "generated/kw.h"
	print "    char *vals[20];" > "generated/kw.h"
	print "};" > "generated/kw.h"

}

function get_kwhash(s) {
	s=substr(s,1,1)
	s=toupper(s)
	return index("ABCDEFGHIJKLMNOPQRSTUVWXYZ",s);
}

/^#/ {next}
(NF>=1) {
kw= $1
if (NF==1) {s=1} else {s=2}
issingle=0
if (single_words[kw]==1)  {kw="KWS_" kw
issingle=1
}
if (doverbose == "1") {
print "Check : " kw " - "  def[kw]
}

if (def[kw]!=1) {
		print "#define " kw " " a > "generated/kw.h"
		print "%token " kw " " a > "generated/kw.yh"
		def[kw]=1
		a++
}



kwclass=get_kwhash($s);
arr_cnt[kwclass]++;
cnt=arr_cnt[kwclass]
class_kw[kwclass,cnt]=kw;

lines[kwclass,cnt]="";


# Este ciclo lê a lista de palavras reservadas de um token.
for (z=s;z<=NF;z++) {
	lines[kwclass,cnt]=lines[kwclass,cnt] "\"" $z "\", " 
}

}


END {

for (a=0;a<=26;a++) {
	print "struct s_kw kwlist_" a "[]={" > "generated/kw.c"
	for (b=1;b<=arr_cnt[a];b++) {
		printf "   {" class_kw[a,b] ",1,{" > "generated/kw.c"
		printf "         " lines[a,b]  > "generated/kw.c"
	printf " 0} " > "generated/kw.c"
	printf "},\n" > "generated/kw.c"
	}
	
print "{0}" > "generated/kw.c"
print "};" > "generated/kw.c"
}

print "/* This an hash organized by the first character of the keywords */"
print "struct s_kw *hashed_list[]={" > "generated/kw.c"

for (a=0;a<=26;a++) {
	print "kwlist_" a "," > "generated/kw.c"
}
print "0};" > "generated/kw.c"


}
' < $1

echo $0 : Done


openFile();
genHFile();
genTokenFile();
genCFile();
readFile();
closeFile();
