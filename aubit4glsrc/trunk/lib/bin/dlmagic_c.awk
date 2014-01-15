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
print "/*" > "header.dlmagic"
print " * lib=" xlib " env=" env " lib_prefix=" lib_prefix " api_prefix=" api_prefix > "header.dlmagic"
print " * @file" > "header.dlmagic"
print " * File definition" > "header.dlmagic"
print " *" > "header.dlmagic"
print " * This file was created from .spec file of same name, using dlmagic script" > "header.dlmagic"
print " * - if you need to edit it, edit .spec file instad, and use [make filename.c]" > "header.dlmagic"
print " * to re-create it." > "header.dlmagic"
print " *" > "header.dlmagic"
print " * @todo Add Doxygen comments to file" > "header.dlmagic"
print " * @todo Take the prototypes here declared. See if the functions are static" > "header.dlmagic"
print " * or to be externally seen" > "header.dlmagic"
print " * @todo Doxygen comments to add to functions" > "header.dlmagic"
print " */" > "header.dlmagic"
print "" > "header.dlmagic"
print "/*******************************************************************" > "header.dlmagic"
print "* (c) 1997-2005 Aubit Computing Ltd." > "header.dlmagic"
print "*" > "header.dlmagic"
print "*" > "header.dlmagic"
print "********************************************************************/" > "header.dlmagic"
print "" > "header.dlmagic"
print "" > "header.dlmagic"
if (HEADER_FILE=="") print "#include \"a4gl_libaubit4gl_int.h\"" > "header.dlmagic"
else print "#include " HEADER_FILE  > "header.dlmagic"
print "" > "header.dlmagic"
print "#ifdef DEBUG" > "header.dlmagic"
print "#ifndef DEBUG_SPEC" > "header.dlmagic"
print "#define DEBUG_SPEC" > "header.dlmagic"
print "#endif" > "header.dlmagic"
print "#endif" > "header.dlmagic"
print "static void *libptr=0;" > "header.dlmagic"
print "static void clrcachedptrs(void);" > "header.dlmagic"
print "void A4GL" xlib "_clrlibptr (void);" > "header.dlmagic"
print "int dlclose (void *__handle);" > "header.dlmagic"
print "" > "header.dlmagic"
print "/**"
print " * Library init function."
print " *"
print " * @todo : explain ussage and parameters."
print " * @return ."
print " */"
print ""
print "static char currentLib[512]=\"\";"
print "void A4GL" xlib "_clrlibptr (void) {"
if (selfonly) {
	print "libptr=(void *)0;"
} else {
	if (multiload_library) {
		#print "    if (libptr) {dlclose(libptr);}" 
		print "    libptr=0;"
        } else {
		print "    if (libptr) {dlclose(libptr);}"
		print "    libptr=0;"
		print "    strcpy(currentLib,\"\");"
	}
	print "    clrcachedptrs();"
}
print "}"
print ""
print "int A4GL" xlib "_initlib (void) {"
if (selfonly) {
	print "libptr=(void *)1;"
	print "return " lib_prefix xlib "_initlib();"
} else {
	print "typedef int (*x_func)(void);"
	print "static x_func func=0;";
        print "   char *newlib;"
	print "   newlib=acl_getenv(\"" env "\");"
        print "   if (strcmp(newlib,currentLib)!=0) {A4GL" xlib "_clrlibptr ();}"

	if (multiload_library) {
		print "   libptr=(void *)A4GL_dl_openlibrary_cached(\"" xlib "\",newlib);"
	} else {
		print "   libptr=(void *)A4GL_dl_openlibrary(\"" xlib "\",newlib);"
	}

	print "   if (libptr==0) {"
	print "      A4GL_exitwith(\"Unable to open " xlib " library...\");"
	print "      return 0;"
	print "   }"
	print "   strcpy(currentLib, newlib);"
	print "   func=(x_func)A4GL_find_func_allow_missing(libptr,\"" lib_prefix xlib "_initlib\");"
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
/^MULTILOAD_LIBRARY/ {next}

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
	str=sprintf("typedef %s(*x_func_%d)(",rtype,funccnt)

for (b=0;b<c;b++) {
	xxtype=param_type[b]
	gsub("[*]"," * ",xxtype)
	gsub("  "," ",xxtype)
	if (b) str=str ","
	str=str xxtype " "
}


if (c==0) {
	str=str "void"
}
str=str ");"
print str > "header.dlmagic"

printf("static x_func_%s func_%s=0;\n",funccnt,funccnt) > "header.dlmagic"
printf("   func_%s=NULL;\n", funccnt) > "clrptr.dlmagic"
}

print "#ifdef DEBUG_SPEC"
debug_args=debug_args ")"
if (args!="")
print "A4GL_debug(\"" debug_args "\\n\"," dargs ");"
else
print "A4GL_debug(\"" debug_args "\\n\");"
print "#endif"
print "   if (libptr==0) A4GL" xlib "_initlib();"
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
	print "   if (func_" funccnt "==0 || A4GL_never_dlmagic_cache(\"" lib_prefix cfname "\")) {"
	print "        func_" funccnt "=(x_func_" funccnt ")A4GL_find_func(libptr,\"" lib_prefix cfname "\");"
        print "   }"
	

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
