Aubit 4gl compiler readme
-------------------------

Instalation:

	Please see doccumentation.

Doccumentation:

	Please see online manual at http://aubit4gl.sourceforge.net

Change log:

    See CVS logs. changelog.txt is now obsolete.

Development:

    Please visit http://aubit4gl.sourceforge.net

License:

    GNU and LGNU, see details in files COPYING and LICENSE

Contact:

    Mike Aubury (mike@aubit.com) or Andrej Falout (afalout@ihug.co.nz)

Discuss & Support:

    Please direct all questions to discussion list at:

	    http://aubit4gl.sourceforge.net

	This old lists are now obsolete:
		http://www.egroups.com/group/aubit4gl
		http://www.falout.com/projects/Aubit4gl

=========================================================================

Feel lucky?

Following are short instruction on how to obtain source files
and make the compiler. THIS IS NOT A REPLACEMENT FOR READING THE MANUAL!

Using binary builds is recomended, if you do not intend to change
compiler's source code. However, since Aubit 4gl is in intensive
developemnt, it is much easier to follow new developments if you get
source code form CVS, and then just do updates to that base ("cvs update")

Obtaining the Aubit compiler
----------------------------

1) Using command line CVS to get sources

	See instructions at:

	http://sourceforge.net/cvs/?group_id=32409

- OR -

2) Obtain source code using source file distribution package

    Reelased versions source code download (can be out of date)

        http://sourceforge.net/project/showfiles.php?group_id=32409

    Nightly builds source code (current)

		http://aubit4gl.sourceforge.net/files/aubitdownload.htm

- OR -

3) Obtain binary distribution

    See same locations as in b)


Installation
------------

1) From source code

	If you will be using source code, you will need to make (compile) the
	compiler, and then install it. Basically:

		cd <where_you_unpack>
	    ./configure
	    make
	    make install


    If some library or program, that you know is on your system, is not
	detected, it is probably in non-standard location. Execute:

		./configure --help

    for list of options, and how to specify package and it's path. General
    rule is to add "--with-xxxx=<path>" to "configure" command line, for
    example:

		./configure --with-iodbc=/usr/iodbc_3.0

    Note: in most cases, you will have to add this path to your PATH and/or
    LD_LIBRARY_PATH in your run-time environment, for Aubit compilers and
    compiler programs to be able to find nedded prgrams and/or libraries
    that belong to this way specified package in non-standard place.

    By default, compiler will be installed in /opt/aubit4gl (with "aubit"
    and "aubit-config" links to /usr/bin and libraries linked to /usr/lib,
    and configuration file placed in /etc/opt/aubit4gl/aubitrc)

    To test the compiler, execute:

	    cd /opt/aubit4gl/tools/test (using default install location)
	    make
	    ./hello

    You should now see "hello.4gl" program, in GUI mode if you have GTK+
    installed, and are running GUI interface, or in CUI mode if you don't.

    Summary of commands:  (you can use this as shell script)

        #---------------- cut here -------------------
		#!/bin/sh
		#"MyAubitSource" is just for example - you can of cource change this
		mkdir MyAubitSource
		cd MyAubitSource
	    echo "When prompted for a password for anonymous, simply press the Enter key:"
		cvs -d:pserver:anonymous@cvs.aubit4gl.sourceforge.net:/cvsroot/aubit4gl login
		cvs -z3 -d:pserver:anonymous@cvs.aubit4gl.sourceforge.net:/cvsroot/aubit4gl co aubit4glsrc
	    cd aubit4glsrc
	    ./configure
	    make
	    make install
	    cd ..
        #to make sure we are not picking anything up from source tree,
        #we will rename it; just in case.
		mv MyAubitSource MyAubitSource-hide
		#if you did not use PREFIX, compiler will be by default installed here:
		cd /opt/aubit4gl/tools/test
	    make
	    ./hello
        #---------------- cut here -------------------

    Do you see program running? Yes=Great! No=RTFM!

2) From binary distribution

	If you will be using binary distribution, you will need to install it:


	a) RPM binary distribution:

        Sorry, not yet available

	b) Debian binary disrtibution:

        Sorry, not yet available

	c) tarball (.tar.gz / .tgz) binary distribution:

        #---------------- cut here -------------------
		#!/bin/sh
        #/opt is default - you can of course change this:
		cd /opt
        #aubit4gl is default - you can of course change this:
		mkdir aubit4gl
        cd aubit4gl
		#<path/to/tarball> us location where you downloaded Aubit tar file:
		tar xvzf <path/to/tarball>/aubit-bin-*
        make
        cd tools/test
        make
        ./hello
        #---------------- cut here -------------------

		Do you see program running? Yes=Great! No=RTFM!

		"make" command above will do 2 things:
	        * invoke "configure" script to detect installed programs, libraries
	            and other options, paths, etc, and create Aubit main
				configuration file, "aubitrc". If it already exists as
	            /etc/opt/aubit4gl/aubitrc IT WILL NOT BE OVERWRITEN, but insetad
	            storred as etc/aubitrc.original for you to manually merge,
				if needed.
	        * Install links to /usr/bin and usr/lib, for binary files and
				libraries, respecively.

	    You can supply parameters to 'configure' usign CPARAM, for example:

			make CPARAM=--with-iodbc[=<path>]

        Note that same warning about LD_LIBRARY_PATH as stated in section
	    about compiling source cide applies: if you specify an option to
	    configure that includes non-standard path, in most cases, you will
	    need to include this path to your PATH and/or LD_LIBRARY_PATH, for
	    Aubit compiler and Aubit compiled 4gl programs to be able to find them.

	    Running 'configure' alone, not via 'make', will create etc/aubitrc
        BUT IT WILL NOT INSTALL IT to /etc/opt/aubit4gl. You should be
        aware that Aubit configuration is read sequentially from several
        locations, starting with /etc/opt/aubit4gl, then $AUBITDIR/etc,
        overriding specified options as it goes (see aubitrc file for full
        list and order).

		See "make help" for other options.


NOTES:

Only binary files that will be in your path after installing Aubit compiler
are 'aubit' and 'aubit-config'. 'aubit' is a warper script, that you are
supposed to use to invoke ALL aubit compilers/programs. For example:

    aubit 4glpc hello.4gl -o hello

If you wish to invoke compilers/programs directly, you will need to add
<Aubit installation directorty>/bin to your PATH, for example:

	export PATH=`aubit-config AUBITDIR`/bin:$PATH



--------------------------------------------------------------------

Did not work? Please read the manual.

Good luck!

                   Aubit 4gl development team
