	Readme doccument for 4glworks aplication framework
    -------------------------------------------------

Users Manual
------------

Please see www.4glworks.com for now. Soon on aubit4gl.sourceforge.net
There is also a number of readme files all over the place, that will 
eventually end up in manual.


For developers: what is where, what is what
-------------------------------------------

Please see "allfiles.txt" doccument describing tree structure, and each
file in 4glworks application framework

For users and developers: how to configure, compile install and use it.
-----------------------------------------------------------------------

 The easiest thing still is to just use the shell archives availabe on
 www.4glworks.com with which tools are distributed - each will unpack the
 tool, configure it, compile it & display the readme's with almost no 
 intervention (a few hit a key or y/n along the way).

 Or you could:

a) get hold of the application framework/module/tool from the cvs repository
    For now I'll recoment to check out everything under "appframework".
	See CVS instructions at https://sourceforge.net/cvs/?group_id=32409

b) run the configure script, if there is one

	Prerequisites: i4gl rds or i4gl c-compiled, C compiler.

c) run the install script

	Which is called xxx and can be found where?

 Specifically, per module:

	Compiling in "4glworks":

	    Do this,
	    Then, do that.


	Compiling in "4glapps":
	    -4gwdemo:

	    -4gwed:

	    -maildemo:

	    -menusdemo:

	Compiling in "4gwmods""

	    -mail:

	    -menus:

Testing the installation, and running programs:
-----------------------------------------------

To test is compilation and installing of compiled programs was successfull,
do this.

To run compiled programs:

	Running "4glworks":

	    Do this,
	    Then, do that.

	Running "4glapps":
	    -4gwdemo:

	    -4gwed:

	    -maildemo:

	    -menusdemo:

	Running "4gwmods""

	    -mail:

	    -menus:



4glworks inter-dependencies
---------------------------

 4gwapps/4gwdemo & 4gwapps/4gwed: 4glworks
 4gwapps/maildemo: 4glworks & 4gwmods/mail
 4gwapps/menusdemo: 4glworks & 4gwmods/menus

NOTE:
-----

- 4glworks will not work with aubit4gl as it is - there are at least two c
hacks that need to be fixed

- currently you can copile and use this code ONLY with Informix 4gl compiler(s)
Compiling with other compilers (Aubit, 4js, Querix) is planed

- I have not yet tested building stuff taken from the CVS repository. I do not
see a problem as everything compiles on my box, nonetheless this is something
that needs to be formally tested

- the extended sql interpreter is only in partial (sic) working order: I have
scraped the layer I had implemented in 4gl in 2.0b10 (for performance reasons
and as a means to implement the new functionality), and the new grammar is only
partly implemented

- if you want to sample the full sql interpreter, get hold of the shell archive
at www.4glworks.com


- development plan:

 each project has a todo file in its own etc directory (eg 4glworks/etc/todo).
 Note that in general those are not proper development plan documents, but an
 informal outline of what I might consider doing. 4glworks/etc/todo is best
 described as a blurb, but it does contain everything that I need to
 consider/fix/implement in the next release(s). It might be somewhat out of date
 in the sense that a few minor things have already been implemented, but not
 taken out of the todo file.

This needs to be merged in one doccument, since it depends on each other, 
and prioritized. IT will then be posted on Aubit project site.


Code and instructions that are needed to make distribution archives is NOT
currently in CVS

3) Development plan needs to be put together from existing todo filse, and prioritized.
Suggested for the top of priority list includes:

	a) Consolidation of existing documentation, inclusion in Aubit manual/web site.
	b) Autoconf
	c) Swithch to using amake/make in preparation to compiling with non-ifmx compilers
	d) Compiling with Aubit
	e) Compiling with 4Js and Querix.



                                Aubit development team

