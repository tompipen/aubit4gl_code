BEGIN {
    FS = "[ \t,]+"
    print ""
    print "/*"
    print " * lib=" lib " env=" env " lib_prefix=" lib_prefix " api_prefix=" api_prefix 
    print " * @file" 
    print " * Function prototypes" 
    print " *"
    print " * This file was created from .spec file of same name, using dlmagic script"
    print " * - if you need to edit it, edit .spec file instad, and use [make filename.h]"
    print " * to re-create it." 
    print " *" 
    print " * @todo See if the functions are static" 
    print " * or to be externally seen" 
    print " */" 
    print "" 
    print "/*******************************************************************"
    print "* (c) 1997-2005 Aubit Computing Ltd." 
    print "*" 
    print "*" 
    print "********************************************************************/"
    print "" 
    print "/*" 
    print "====================================================================="
    print "                    Functions prototypes" 
    print "====================================================================="
    print "*/" 
    print "" 
    print "#ifdef DEBUG" 
    print "#define DEBUG_SPEC" 
    print "#endif" 

    if (use_prefix == 0) {
        print "#ifndef __" lib "_H__" 
        print "#define __" lib "_H__"
    } else {
        print "#ifndef __" lib "_LIB_H__" 
        print "#define __" lib "_LIB_H__"
    }
    print "#ifdef __cplusplus"
    print "extern \"C\""
    print "{" 
    print "#endif" 
    print "" 
    if (use_prefix == 0) { 
       print "int A4GL" lib "_initlib (void);" 
    } 
}


/^LIBRARY / 	{next}
/^VARIABLE / 	{next}
/^HEADER_FILE / {next}
/^API_PREFIX / 	{next}
/^LIB_PREFIX / 	{next}
/^MAP / 	{map[$2]=$3; next}
/^#/ 		{print; next }
/^\// 		{print; next }
/^extern/ 	{print; next }
/^!/ 		{next}
/^\/\*/		{print; next }
/^ \*/ 		{print; next }
/^\*\// 	{print; next }
/^$/ 		{next}
/^\*/ 		{next}
/^[     ]*$/ 	{next}




{
  fname = $1 
  if (use_prefix)
    {
    print "#ifdef LIBTOOL_PREFIX"
    print "#define " lib_prefix fname " PRELOADED_LTX_ ## " lib_prefix fname 
    print "#endif"
  }


  rtype = "void" 
  c = 0 
  for (a = 2; a <= NF; a++)
    {
      if ($a == " " || $a == "\t" || $a == ",") continue;

      param_type[c] = $a 

      if (param_type[c] == "->") { param_type[c] = "";a++;rtype = $a;break }

      if (param_type[c] == "...") { param_name[c] = "";a++;c++;break }

      a++ 
      param_name[c] = $a   
      c++;
    }

  if (c == 0) { param_name[c] = "";param_type[c] = "void";c++ }

  if (use_prefix == 0) { printf rtype " " api_prefix fname "(" }
  else { printf rtype " " lib_prefix fname "(" }

  va_start = "" 
  args = "" 
  for (b = 0; b < c; b++)
    {
      printf ("%s %s", param_type[b], param_name[b]);

      if (param_type[b] == "...") { va_start = last; args = args ",&ap" }
      else { args = args "," param_name[b] } 

      last = param_name[b] 

      if (b < c - 1) { printf (","); }
    }

  args = substr (args, 2) 
  print ");" 
  print ""
}
