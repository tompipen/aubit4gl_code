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


If you will be using source code, you will need to make the compiler:

		cd <where_you_unpack>
	    ./configure
	    make
	    make install


    If some library or program, that you know is on your system, is not 
	detected, it is porbably in non-standard location. Execute:

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
	    hello

    You should now see "hello.4gl" program, in GUI mode if you have GTK+
    installed, and are running GUI interface, or in CUI mode if you don't.

    Summary of commands:  (you can use this as shell script)

        #!/bin/sh
		mkdir MyAubitSource
		cd MyAubitSource
	    echo "When prompted for a password for anonymous, simply press the Enter key:"
		cvs -d:pserver:anonymous@cvs.aubit4gl.sourceforge.net:/cvsroot/aubit4gl login
		#echo "When prompted for a password for anonymous, simply press the Enter key:"
		cvs -z3 -d:pserver:anonymous@cvs.aubit4gl.sourceforge.net:/cvsroot/aubit4gl co aubit4glsrc
	    cd aubit4glsrc
	    ./configure
	    make
	    make install
	    cd ..
        #to make sure we are not picking anything up from source tree:
		mv MyAubitSource MyAubitSource-hide
		cd /opt/aubit4gl/tools/test
	    make
	    ./hello

    Do you see program running? Yes=Great! No=RTFM!


If you will be using binary distribution, you will need to install it:


a) RPM bynary distribution:


b) Debian bynary disrtibution:


c) tarball (.tar.gz) bynary distribution:


--------------------------------------------------------------------

Did not work? Please read the manual.

Good luck!

                   Aubit 4gl development team
