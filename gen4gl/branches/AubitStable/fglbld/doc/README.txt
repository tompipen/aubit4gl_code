@(#)$Id: README.txt,v 1.2 2002-06-21 05:43:50 afalout Exp $

:FGLBLDVER:

*********************************************
* Welcome to the wonderful world of FGLBLD. *
*********************************************

From the email in which code was set to Aubit project:

Here's the code.  I don't like the format I'm sending it to you in - it
probably won't build out of the box, but getting it to do so is going to
take me time - lots of elapsed time, rather less actual work time.  It
is not helped by FGLBLD having been developed when I used SCCS and not
having been updated since I switched (still somewhat reluctantly) to
RCS.  That makes extracting the code harder than I'd like.

What you've got is both RCS and SCCS files containing 'the same' history
for the file specific to FGLBLD.  You also have extracted and version
stamped versions of all the source code that I used to distribute.  What
I've not formally verified in the last decade is that the distribution
actually distributes everything you need.  You're probably OK, but not
guaranteed.

--
Jonathan Leffler                         #include <disclaimer.h>
STSM, IBM Data Management Solutions.      Phone: +1 650-926-6921
Email: Jonathan.Leffler@Informix.com, jleffler@us.ibm.com
Guardian of DBD::Informix v1.00.PC1 -- http://dbi.perl.org
     "I don't suffer from insanity; I enjoy every minute of it!"


Changes made to the code I received, before importing to SourceForge:

1. Code in RCS directory, that was already in root was deleted.
2. Remaining files where extracted in last RCS version, and directory
    was remaned in only_in_RCS
3. All files in SCCS directory where deleted, since they already existed
    elsewhere. Except for fglbld.sh, that was moved into only_in_RCS
4. All .man files where moved in new directorry called "man"
5. All .4pr files where renamed in .per and moved in new directorry
	called "per"
6. *.RDS and *.4GL files where renamed to *-RDS.lst and *-4GL.lst
7. Aubitconf "configure" script was added.
8. .c and .4gl source code was isolated to new directory "source"

=========================================================================


PREREQUISITES
*************

Either: Informix-4GL (compiled I4GL)
Or:     Informix-RDS (interpreted I4GL)

Notes:  if you are using Informix-RDS and ESQL/C is not available, you
        will have to modify the makefile: the line which currently reads:
            CFLAGS=-O -I${INFORMIXDIR}/incl
        should be modified to read:
            CFLAGS=-O -I${INFORMIXDIR}/incl -I.
        This uses the dummy versions of the files decimal.h and sqltypes.h
        which are provided with this software.

INSTALLATION
************

To install this software, decide on:
    FGLBLDDIR -- a directory to contain the files specific to FGLBLD
              -- default: /usr/fglbld
    FGLBLDBIN -- a bin directory already on people's paths
              -- default: ${INFORMIXDIR:-/usr/informix}/bin
    FGLUSR    -- a user to own the software
              -- default: informix
    FGLGRP    -- a group to own the software
              -- default: informix
    FGLTYPE   -- type of I4GL to use
                 C4GL -- compiled Informix-4GL
                 RDS  -- interpreted Informix-4GL

0.  Always set INFORMIXDIR, even if the value is /usr/informix.
    Also set the rest of your environment to allow you to use Informix.
    This means that $INFORMIXDIR/bin must be on your path.
1.  Set the environment variable FGLTYPE to the correct value and export it.
2.  Extract the software from the shell archive:
    Run:    sh fglbld.sa
3.  Type: make -k
    More sensibly, type: make -k >log 2>&1 & tail -f log
4.  Check that the compilation worked.
5.  Become superuser.
    Type: su root
6.  Change into the distribution directory.
    Type: cd Distribution
7.  Set and export the variables FGLBLDDIR, FGLBLDBIN, FGLUSR, FGLGRP
    unless the default is acceptable.
8.  Run install script.
    Type: ./install
9.  Exit from superuser.
    Type: exit
10. Assuming all went well, clean up the mess.
    Type: make cleanup
    Beware -- this removes the shell archive fglbld.sa if it exists

Variant on installation process.
If you cannot become root, or do not wish to become root, you will
need to omit step 5, add step 7a, and omit step 9.

7a. Make the script install writeable.  Edit the line which reads:
        uid=`id | sed 's/uid=\([0-9][0-9]*\)[^0-9].*/\1/'`
    so that it reads:
        uid=0
    Make sure that you can write in $FGLBLDDIR and $FGLBLDBIN, or create
    them if they do not already exist.

Please let me know if you run into any trouble with this process.


CUSTOMISING
***********

If you want to modify the code which is generated (e.g. to suit
a particular project), you will want to fiddle with the materials
under $FGLBLDDIR/bin and $FGLBLDDIR/src.

Before you start, execute the following commands:
    cd ${FGLBLDDIR:-/usr/fglbld}
    if [ ! -d Originals ]
    then
        mkdir Originals
        cp src/* Originals
        cp bin/* Originals
        chmod 000 Originals
    fi

The template files are:
    $FGLBLDDIR/src/informix.mk      -- rules for compiling I4GL etc
    $FGLBLDDIR/src/perform.mk       -- skeleton makefile for particular program
    $FGLBLDDIR/src/perform.msg      -- standard help message file
    $FGLBLDDIR/src/performc.4gl     -- code fiddling with cursors
    $FGLBLDDIR/src/performg.4gl     -- globals file
    $FGLBLDDIR/src/performm.4gl     -- main module and unchanging code
    $FGLBLDDIR/src/repdest.4gl      -- used to select a report destination
    $FGLBLDDIR/src/repdest.4pr      -- used to select a report destination

The other template code is embedded in the `.alt' files:
    $FGLBLDDIR/bin/cpopup.alt
    $FGLBLDDIR/bin/fglbld.alt
    $FGLBLDDIR/bin/mkselect.alt
    $FGLBLDDIR/bin/upopup.alt

Good Luck with your modifications.

Jonathan Leffler
Sphinx Ltd
1st December 1989

