function ring(rtype) {
	if (rtype=="char*") { print "A4GL_debug(\"Returning (%s)\",A4GL_null_as_null(rval));"; return;}
	if (rtype=="void*") { print "A4GL_debug(\"Returning (%p)\",rval);"; return;}
	if (rtype=="int") { print "A4GL_debug(\"Returning '%d'\",rval);"; return;}
	print "A4GL_debug(\"Returning Unknown '%p'\",rval);"
	}
	
	function ping(rtype,name) {
	if (rtype=="char*")  return "(%s))"
	if (rtype=="char")  return "(%c)"
	if (rtype=="void*")  return "%p"
	if (rtype=="va_list*")  return "%p"
	if (rtype=="int") return "%d"
	return "%p" 
	#print "Unknown type : " rtype > "dlmagic.log"
}

function pind(rtype,rname) {
	
	if (rtype=="char*")  return sprintf("A4GL_null_as_null(%s)",rname);
	return rname;
	#print "Unknown type : " rtype > "dlmagic.log"
}



BEGIN {
FS="[ 	,]+"
print "/*"
print " * lib=" lib " env=" env " lib_prefix=" lib_prefix " api_prefix=" api_prefix
print " * @file"
print " * File definition"
print " *"
print " * This file was created from .spec file of same name, using dlmagic script"
print " * - if you need to edit it, edit .spec file instad, and use [make filename.c]"
print " * to re-create it."
print " *"
print " * @todo Add Doxygen comments to file"
print " * @todo Take the prototypes here declared. See if the functions are static"
print " * or to be externally seen"
print " * @todo Doxygen comments to add to functions"
print " */"
print ""
print "/*******************************************************************"
print "* (c) 1997-2005 Aubit Computing Ltd."
print "*"
print "*"
print "********************************************************************/"
print ""
print ""
if (HEADER_FILE=="") print "#include \"a4gl_libaubit4gl_int.h\""
else print "#include " HEADER_FILE 
print ""
print "#ifdef DEBUG"
print "#ifndef DEBUG_SPEC"
print "#define DEBUG_SPEC"
print "#endif"
print "#endif"
print "static void *libptr=0;"
print "void A4GL" lib "_clrlibptr (void);"
print "int dlclose (void *__handle);"
print ""
print "/**"
print " * Library init function."
print " *"
print " * @todo : explain ussage and parameters."
print " * @return ."
print " */"
print ""
print "void A4GL" lib "_clrlibptr (void) {"
if (selfonly) {
	print "libptr=0;"
} else {
	print "    if (libptr) {dlclose(libptr);}"
	print "    libptr=0;"
}
print "}"
print ""
print "int A4GL" lib "_initlib (void) {"
if (selfonly) {
	print "libptr=1;"
	print "return " lib_prefix "A4GL" lib "_initlib();"
} else {
	print "typedef int (*x_func)(void);"
	print "static x_func func;";
	print "   libptr=(void *)A4GL_dl_openlibrary(\"" lib "\",acl_getenv(\"" env "\"));"
	print "   if (libptr==0) {"
	print "      A4GL_exitwith(\"Unable to open " lib " library...\");"
	print "      return 0;"
	print "   }"
	print "   func=(x_func)A4GL_find_func_allow_missing(libptr,\"" lib_prefix "A4GL" lib "_initlib\");"
	print ""
	print "   if (func)"
	print "      return func();"
	print "   else"
	print "      return 1;"
}
print "}"
print ""
print ""
}
/^LIBRARY / {next}
/^VARIABLE / {next}
/^HEADER_FILE / {next}
/^API_PREFIX / {next}
/^LIB_PREFIX / {next}
/MAP / { map[$2]=$3; next}
/^#/ {print
	next
}
/^\// {print
	next
}
/^extern/ {print
	next
}
/^ \*/ {print
	next
}
/^\*\// {print
	next
}
/^\*/ {next}
/^$/ {next}

/^[ 	]*$/ {next}
{
fname=$1
call_fname=$1
rtype="void"

c=0
for (a=2;a<=NF;a++) {

param_type[c]=$a
if (param_type[c]=="->") {
	param_type[c]=""
	a++
	rtype=$a
	break
}

if (param_type[c]=="...") {
	param_name[c]=""
    call_fname="internal_"fname
	a++
	c++
	break
}


a++
param_name[c]=$a
c++;
}


printf rtype " " api_prefix fname "("
va_start=""
args=""
dargs=""
debug_args="Call to " rtype " " api_prefix fname "("

for (b=0;b<c;b++) {
	printf("%s %s",param_type[b],param_name[b]);
	if (param_type[b]=="...") {
		va_start=last;
		args=args ",&ap"
		dargs=dargs ",&ap"
		if (b) debug_args=debug_args "," 
		debug_args=debug_args ping("va_list*",param_name[b]);
	} else {
		if (b) debug_args=debug_args "," 
		debug_args=debug_args ping(param_type[b],param_name[b])
		args=args "," param_name[b]
		dargs=dargs "," pind(param_type[b],param_name[b])
	}
	last=param_name[b]
	if (b<c-1) {
		printf(",");
	}
}
args=substr(args,2)
dargs=substr(dargs,2)
print ") {"

if (va_start!="") {print "va_list ap;"}
if (rtype!="void") {
	print rtype " rval;"
}

funccnt++;
if (!selfonly) {
	printf("typedef %s(*x_func_%d)(",rtype,funccnt)


for (b=0;b<c;b++) {
	xxtype=param_type[b]
	gsub("[*]"," * ",xxtype)
	gsub("  "," ",xxtype)
	if (b) printf(",")
	printf("%s ",xxtype) 
}


if (c==0) {
	printf("void");
}
print ");"

printf("static x_func_%s func_%s;\n",funccnt,funccnt)
}

print "#ifdef DEBUG_SPEC"
debug_args=debug_args ")"
if (args!="")
print "A4GL_debug(\"" debug_args "\\n\"," dargs ");"
else
print "A4GL_debug(\"" debug_args "\\n\");"
print "#endif"
print "   if (libptr==0) A4GL" lib "_initlib();"
if (map[call_fname]) cfname=map[call_fname];
else cfname=call_fname;

	if (va_start!="") {
		print "   va_start(ap," va_start ");"
	}

if (selfonly) {
	selfname= lib_prefix cfname 
	

	if (rtype=="void")
		print "   " selfname "(" args ");"
	else {
		print "   rval=(" rtype ")" selfname "(" args ");"
		print "#ifdef DEBUG_SPEC"
		ring(rtype)
		print "#endif"
		print "return rval;"
	}
} else {
	print "   func_" funccnt "=(x_func_" funccnt ")A4GL_find_func(libptr,\"" lib_prefix cfname "\");"
	

	if (rtype=="void")
		print "   func_" funccnt "(" args ");"
	else {
		print "   rval=(" rtype ")func_" funccnt " (" args ");"
		print "#ifdef DEBUG_SPEC"
		ring(rtype)
		print "#endif"
		print "return rval;"
	}
}
print "}"
print ""

}
