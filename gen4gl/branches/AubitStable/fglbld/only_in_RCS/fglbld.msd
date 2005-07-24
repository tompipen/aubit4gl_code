#   @(#)$Id: fglbld.msd,v 1.1.1.1 2002-06-15 05:07:13 afalout Exp $
#   @(#)FGLBLD -- Informix-4GL Program Generator
#   @(#):FGLBLDVER:
#   @(#)Definitive list of files -- Modifiable Source Distribution
#
#   -- The MSD SCCS file column contains the name of the SCCS file to be
#      created.  The name is quoted relative to the destination directory.
#   -- The master file column contains the name of the master file.
#      Relative names are quoted relative to the source directory.
#
#   -- It is assumed that all files are under SCCS control.
#      Despite this, the `s.' prefix and the SCCS sub-directory name
#      MUST be specified.
#
#   -- Note that it is possible to rename files using this mechanism.
#
#   -- Note that it is possible to include variable definitions as in a
#      shell script.  If necessary, these can include defaults such as
#      ${JH:-/u/j/h} but not termination constructs such as: ${XYZ:?}
#      Note that spaces are not allowed in definitions.
#
#   -- Comment lines start with a hash (#)
#   -- Blank lines are ignored
#   -- Tabs are non-preferred characters
##################################################################

##################################################################
# Definitions                                                    #
##################################################################
JL=/u/consult/john
JL4L=${JL}/i4gl/lib/src/SCCS
JLDS=${JL}/i4gl/lib/dlist/SCCS

##################################################################
# MSD SCCS file                 Master SCCS file                 #
##################################################################

SCCS/s.decformat.c				${JL4L}/s.decformat.c
SCCS/s.editstr.c				${JL4L}/s.editstr.c
SCCS/s.exec.c					${JL4L}/s.exec.c
SCCS/s.fgiusr.c					${JL4L}/s.fgiusr.c
SCCS/s.getenv.c					${JL4L}/s.getenv.c
SCCS/s.interr.c					${JL4L}/s.interr.c
SCCS/s.isdir.c					${JL4L}/s.isdir.c
SCCS/s.mkfile.c					${JL4L}/s.mkfile.c
SCCS/s.opendb.4gl				${JL4L}/s.opendb.4gl
SCCS/s.popstr.c					${JL4L}/s.popstr.c
SCCS/s.rdscurses.h				${JL4L}/s.rdscurses.h
SCCS/s.redraw.c					${JL4L}/s.redraw.c
SCCS/s.repdest.4gl				${JL4L}/s.repdest.4gl
SCCS/s.repdest.4pr				${JL4L}/s.repdest.4pr
SCCS/s.report.c					${JL4L}/s.report.c
SCCS/s.round.c					${JL4L}/s.round.c
SCCS/s.scrdump.c				${JL4L}/s.scrdump.c
SCCS/s.scrndump.4gl				${JL4L}/s.scrndump.4gl
SCCS/s.scrndump.4pr				${JL4L}/s.scrndump.4pr
SCCS/s.security.4gl				${JL4L}/s.security.4gl
SCCS/s.shell.4gl				${JL4L}/s.shell.4gl
SCCS/s.sqltype.c				${JL4L}/s.sqltype.c
SCCS/s.stdopt.4gl				${JL4L}/s.stdopt.4gl
SCCS/s.uname.c					${JL4L}/s.uname.c

SCCS/s.dlist.c					${JLDS}/s.dlist.c
SCCS/s.dlist.h					${JLDS}/s.dlist.h
SCCS/s.dlistdbl.c				${JLDS}/s.dlistdbl.c
SCCS/s.dlistdec.c				${JLDS}/s.dlistdec.c
SCCS/s.dlistint.c				${JLDS}/s.dlistint.c
SCCS/s.dliststr.c				${JLDS}/s.dliststr.c
