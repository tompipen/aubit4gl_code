Aubit 4gl compiler readme
-------------------------


Instalation:

	Please see doccumentation.

Doccumentation:

	Manual at the time of this release is included in this distribution, 
	but please also see online manual at www.falout.com for updates and 
	corrections.

Change log:

    See CVS on www.falout.com. changelog.txt is now obsolete.

Development:

    Please visit www.falout.com and www.aubit.com

License:

    GNU and LGNU, see details in files COPYING and LICENSE

Contact:

    Mike Aubury (mike@aubit.com) or Andrej Falout (afalout@ihug.co.nz)

Discuss:

    Please direct all questions to discussion list at:

	http://www.egroups.com/group/aubit4gl
	http://www.falout.com/projects/Aubit4gl is now obsolete.

=========================================================================

Feel lucky?

Following are short version instruction on how to obtain source files
and make the compiler. THIS IS NOT A REPLACEMENT FOR READING THE MANUAL!

-------- Using jCVS servlet web page to get sources -----------------

This option will work for everyone. All you need is web browser.

Go to www.falout.com,
select Projects->Version controll from tree menu in left frame

Click on cake picture marked:
	"Open repositories in web browser via jCVS servlet"

(Direct link: http://www.falout.com/servlets/JCVSlet/list/Aubit4gl)

When your path on top of the page looks like this:
	"HOME / Projects / Aubit-4gl / Aubit4gl"

...click on "Checkout Latest" link to refresh jCVS servlet repository from
central CVS files. Then, click BACK in your browser.

Now click on "Download" link. This should start download of file
"Aubit4gl.zip" in your browser.

create working directory, like MyWorkDir.
unzip Aubit4gl.zip to MyWorkDir
cd Aubit4gl

---------------------------------------------------------------------

<OR>

-------- Using command line CVS to get sources --------------------

Fro this option you need CVS login to falout.com, and CVS command line
utillities installed on your system:

execute "export CVSROOT=':pserver:username@falout.com:/data/cvs'"
execute "cvs login"
	(enter your password)

execute "mkdir MyWorkDir"
execute "cd MyWorkDir"
execute "cvs -z3 checkout Aubit4gl"
execute "cd Aubit4gl"

--------------------------------------------------------------------

<OR>

--------------- Using jCVS Java client to get sources --------------

Fot this option you need CVS login to falout.com, and jCVS Java client
application installed.

I cannot emphasise enough that this is the tool you want to check out
if you will also need to do some work on your local system and want to
return this changes back to central CVS repository, unless you are
already familiar and happy with your current CVS client.

jCVS II is wonderfully simple GUI client to CVS server, and ig GUI is good
for something, it is good for managing files. This is Java app, meaning
it will run on any system with Java run-time engine, and several installers
are provided at:

http://www.trustice.com/java/jcvs/

--------------------------------------------------------------------

-------------------- make the compiler -----------------------------

edit aubitenv:
    - change export AUBITDIR=<path to MyWorkDir>/Aubit4gl
    - enable call to appropriate script you use to set ODBC manager
		environment
    - edit ODBC libraries setings, as per your system

execute ".aubitenv"
execute "cd $AUBITDIR"
execute "make"
--------------------------------------------------------------------

Did not work? Please read the manual.

Good luck!

                                    Aubit 4gl development team
