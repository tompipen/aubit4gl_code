.1

Usage:
  4glpc sourcefile.type [...] [options] executablename.4ae
  4glpc sourcefile.4gl -c -o objectname.o
  4glpc sourcefile.4gl -o executablename.4ae

 For details, try:
 4glpc --help-options   - for command line options
 4glpc --help-env       - for environment variables recognised
 4glpc --help-types     - for file types
 4glpc --help-examples  - for examples



.2

Aubit 4GL compiler usage: 4glc [options] -oOutFile.ext file.ext [file.ext...]

Extensions (.ext):
  In files list, all .4gl files will be compield to C, other files passed to linker.
  In -o flag, extendion will decide type of linking:
    ao=object, aox=static library, aso=shared lib, 4ae=executable.

For more help
 4glpc --help-options   - for command line options
 4glpc --help-env       - for environment variables recognised
 4glpc --help-types     - for file types
 4glpc --help-examples  - for examples

.3
 4glc [options] -oOutFile.ext file.ext [file.ext ...]

Options:

When A4GL_LEXTYPE=C :
  -o[outfile] name outpout file
  (no flags) compile to C only

When A4GL_LEXTYPE=PERL :
  (no flags) compile to Perl only

Other options :
  -I -L -l : 
  -G     | --globals         : Generate the globals map file
  -S     | --silent          : no output other then errors
  -V     | --verbose         : Verbose output
  -N name| --namespace name  : Prefix all functions with name (default 'aclfgl_')
  -v     | --version         : Show compiler version and exit
  -f     | --version_full    : Show full compiler version and details
  -h|-?  | --help            : Show this help and exit
  -tTYPE | --lextype         : output language, TYPE=C(default) or PERL
  -k     | --keep            : keep intermediate files (defailt)
  -K     | --clean           : clean intermediate files when done
  -s0|1  | --stack_trace 0|1 : Include the stack trace in file:
                             : 0-Don't generate  1-Generate(Default)

If 'outfile' was not specified, it is generated from first 4gl file name
specified. All options that are not recognised, are passed to C compiler,
if -c -o -d or -l was specified.





.4

 4glc [options] -oOutFile.ext file.ext [file.ext ...]

More Options:
      -o
      -c : flag to C compiler (compile only, no linking)
      -shared/static ($USE_SHARED=Yes/no) compile with shared libraries
      -echo  ($DOIT=echo) display CC command only, do not execute
                  this inhibits C compiler only, not the 4gl compiler
      -debug  ($INCLLINES=Yes) include extra debuging code
      -map/nomap ($MAP4GL=Yes) generate additional map file code
      -maponly
      --verbose ($A4GLVERBOSE=yes) show additional info while compiling
      -noerrcode () do not show eeror code on compile errors
      -as-ddl
      -i ignore errors and continue

    All options unknown to Aubit compiler will be passed to C compiler
    Please see Aubit 4gl manual for more information.



.5

 4glc [options] -oOutFile.ext file.ext [file.ext ...]

Environment variables recognised:
  -shared/static ($USE_SHARED=Yes/no) compile with shared libraries
  -echo  ($DOIT=echo) display CC command only, do not execute
              this inhibits C compiler only, not the 4gl compiler
  -debug  ($INCLLINES=Yes) include extra debuging code
  -map/nomap ($MAP4GL=Yes) generate additional map file code
  -maponly
  --verbose ($A4GLVERBOSE=yes) show additional info while compiling
  -as-ddl
  $A4GLRC - full path to file to be used instead of .a4glrc

Note: $FGLCEXEC, cc and other compilers invoked by this script will
      recognise additional variables that might affect this script



.6

 4glc [options] -oOutFile.ext file.ext [file.ext ...]

File types:
      4gl - 4gl source file, compiled to .c and then to .o
      per - 4gl form file, compiled to .c and then to .o
      msg - 4gl message file, compiled to .iem
      a   -
      o   -
      c   -
      menu - Aubit 4gl GUI menu source, compiled to


.7

 4glc [options] -oOutFile.ext file.ext [file.ext ...]

Examples:
  4glpc sourcefile.4gl -o executablename.4ge
  4glpc sourcefile.4gl -c -o objectname.o
  4glpc -shared file.4gl -o file.4ge
  4glpc -static -echo file.4gl -o file.4ge
  4glpc -debug file.4gl -o file.debug
  4glpc -map -echo file.4gl'
  
  
