#!/usr/bin/perl -w

#
# Generate the makefiles that does not exist in a test directory.
#

use strict;
use POSIX;

# A list of the test directory(s)
my @testDirList;
my @fglList;
my @perList;
my @msgList;

#
# Get the test directory(s) in the current one.
#
# @param The directory where to find.
sub getTestDirList
{
  my $dir = shift;
  my $dirs = `find $dir -type d -maxdepth 1`;
  @testDirList = split(/\n/,$dirs);
}

#
# Get the 4gl modules in the current one.
#
# @param The directory where to find.
sub getFglModules()
{
  my $fgls = `find . -name \*.4gl -type f`;
  @fglList = split(/\n/,$fgls);
}

#
# Get the forms in the current directory
#
# @param The directory where to find.
sub getPerModules()
{
  my $pers = `find . -name \*.per -type f`;
  @perList = split(/\n/,$pers);
}

#
# Get the messages in the current directory
#
# @param The directory where to find.
sub getMsgModules()
{
  my $msgs = `find . -name \*.msg -type f`;
  @msgList = split(/\n/,$msgs);
}

# Generate the makefile header until the form list
sub genMakefileHeader
{
  printf MAKEFILE qq|
#Sections you may need to modify are marked with <<<<<<<<<<<<<<<<<<<<<<<<<<<<(x)

################
#All common settings and rules are included:
include ../Makefile-common

## ======================================================================
##                  Local Setings - user modifiable
## ======================================================================
|;
}

sub genPerList() {
  printf MAKEFILE qq|
################
#List of all form files that need to be compiled. This is already set from
#included makefile, but you can override it here if you need to. By default, all
#.per files in current directory are automatically listed, and therfore compiled
#PER="|;
  my $per;
  foreach $per ( @perList ) {
	  printf MAKEFILE "$per ";
	}
  printf MAKEFILE "\"\n\n\n";
}


sub genFglList() {
  printf MAKEFILE qq|
################
#List of all 4GL modules that need to be compiled to objects. This is already set
#from included makefile, but you can overide it here if needed. By default, all
#.4gl files in current directory are automatically listed, and therfore compiled
#FGL="|;
  my $fgl;
  foreach $fgl ( @fglList ) {
	  printf MAKEFILE "$fgl ";
	}
  printf MAKEFILE "\"\n\n\n";
}

sub genMakefileTrailer() {

  printf MAKEFILE qq|
################
#You can add additional files to be cleand with "clean" target to the default
#ones, by listing them here:
#ADD_CLEAN=""

################
#This is set in comon make file; overide it if you need to here
#A4GL_KEYFILE=keys.in
#A4GL_KEYDELAY=10000

## ======================================================================
##                  Local Setings - automatic
## ======================================================================

################
#replace .per/.4gl with appropriate extesion in forms and modules list
FORMS=\${PER:.per=\${A4GL_FORMEXT}}
MODULES=\${FGL:.4gl=\${OBJ_EXT}}

################
#export to environment:
ifneq "\${A4GL_KEYFILE}" ""
	export A4GL_KEYFILE A4GL_KEYDELAY
endif

## ======================================================================
##                 	Local Targets
## ======================================================================

################
#Default target - link objects into program
#Change "progname" to real program name (if different) <<<<<<<<<<<<<<<<<<<<<<(1)
#Replace "\${MODULES}" with list of actual modules constituting this program if
#this test needs more then one program <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<(2)
progname\${TARGET_EXT}: \${MODULES}
#see included makefile for definition of DEFAULT_LINK. Overide it here if you
#need to with something like:
#	\${FGLC} \$^ -o \$@
	\${DEFAULT_LINK}


#Add one or more of above targets here, if test uses more then one program
#<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<(3)

################
#Synonim to invoke compilation of the test by using uniform target name
#Change "progname" to real program name (if different) <<<<<<<<<<<<<<<<<<<<<<(4)
#Add more "progname\${TARGET_EXT}" items if test uses more then one program <<(5)
compile: progname\${TARGET_EXT} \${FORMS}

################
#Run the compiled test
run: compile
#see included makefile for definition of DEFAULT_RUN. Overide it here if you
#need to.
#To run program and test for exit code:
	\${DEFAULT_RUN}
#To run program and diff the stdout output against a file, testing for difference:
#	\${DEFAULT_DIFF}
#If you need to explicitly state program name to run (eg. when test have more then
#one program that needs to be executed), try this:
#	\${DBG} ./progname\${NAMED_[DIFF\|RUN]}
#If you need to set specific options for that program, you can do it like this:
#(example shows how to specify key file):
#	export A4GL_KEYFILE=somekeyfile.in; \${DBG} ./anotherprogname\${NAMED_[DIFF\|RUN]}
#Add more actions here (if needed) <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<(7)

## ======================================================================
##                  Test desctiptions
## ======================================================================

#This section is used by run_tests script to obtain information about the
#nature and requirementent of this test, and use this information to
#decide when is appropriate to run this test

################
#Text to describe functionality tested:
#Change to actual description text" <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<(8)
desc:
	\@echo "This is not a test but a Testing template"
	\@echo "Please provide brief description of functionality tested here."

#All targets below: change to appropriate 1 or 0 settings <<<<<<<<<<<<<<<<<<<(9)

################
#If this test needs database, return 1
db_test:
	\@echo "0"

################
#return 1 if tests use/require ESQL compiler output, instead of C output
ec_test:
	\@echo "0"

################
#Test will fail if not running on screen (curses):
nosilent_test:
	\@echo "0"

################
#Test uses curses and/or screeen dump and may fail when TERM!=xterm
#Anything that uses a screen dump may have specific attributes set which may
#fail if TERM!=xterm
#This core dumps on MinGW and messes up the terminal completely.
#On Cygwin they don't core dump, but this tests fail:
tui_test:
	\@echo "0"

################
#Test uses .per form files:
form_test:
	\@echo "0"

################
#Test uses REPORT section
report_test:
	\@echo "0"

################
#Test that use graphic characters in forms that may be platform dependent
graphic_test:
	\@echo "0"

################
#Test waits for user's input in CONSOLE mode, because automated testing
#was not implemented there, so we must skip them untill this is implemented
console_prompt_test:
	\@echo "0"

################
#test uses aclfgl_aclfgl_dump_screen, A4GL_clr_window or aclfgl_fgl_drawbox, so
#it won't work in CONSOLE mode
dump_screen_test:
	\@echo "0"

################
#Test takes more then 10 minutes to compile or run
long_test:
	\@echo "0"

################
#Tests is certified to run (with -eci) If it fails, something was probably broken
#in current code.
cert_test:
	\@echo "0"

################
#test is superceeded or obsoleted and should be silently skipped
obsolete_test:
	\@echo "0"

################
#Test can be run using any 4GL compatible compiler, not just Aubit
compat_test:
	\@echo "0"

################
#All other tests not belonging to any of the above groups should be listed here:
unknown_test:
	\@echo "0"

# ============================= EOF ================================
|;
}

sub genMsgList
{
}


# Generate a makefile for the test
# 
# @param dir The directory where to generate
sub genMakefile {
	my $wantedDir = shift;
  unless (chdir $wantedDir)
  {
	  printf("Error changing to $wantedDir :$!");    
    return;
  }

  open(MAKEFILE, "> Makefile") || 
    die "Cant open Makefile : $!";
  getFglModules();
  getPerModules();
  getMsgModules();
	genMakefileHeader();
	genPerList();
	genFglList();
	genMsgList();
	genMakefileTrailer();

  close(MAKEFILE);
  chdir "..";
}

# Iterate in the directory list and for each one generate a makefile if
# does not exist
sub genMakefiles() {
  my $dir;
  foreach $dir ( @testDirList )
  {
		if ( -f "$dir/Makefile" || -f "$dir/makefile" ) {
		  print("Makefile allready exist in $dir\n");
		}
		else {
		  printf("Generate makefile for $dir\n");
		  genMakefile($dir);
		}
  }
}


getTestDirList(".");
genMakefiles();


