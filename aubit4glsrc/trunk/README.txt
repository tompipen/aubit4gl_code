Aubit 4gl compiler readme
-------------------------


Instalation:

	Please see doccumentation.

Doccumentation:

	Please see online manual at aubit4gl.sourceforge.net

Change log:

    See CVS logs. changelog.txt is now obsolete.

Development:

    Please visit aubit4gl.sourceforge.net

License:

    GNU and LGNU, see details in files COPYING and LICENSE

Contact:

    Mike Aubury (mike@aubit.com) or Andrej Falout (afalout@ihug.co.nz)

Discuss:

    Please direct all questions to discussion list at:

	    aubit4gl.sourceforge.net

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
	bin/4glpc -config
	. /etc/opt/aubit4gl/aubitenv
	make

If you will be using bunary distribution, you will need to install it:


a) RPM bynary distribution:


b) Debian bynary disrtibution:


c) tarball (.tar.gz) bynary distribution:


--------------------------------------------------------------------

Did not work? Please read the manual.

Good luck!

                                    Aubit 4gl development team
