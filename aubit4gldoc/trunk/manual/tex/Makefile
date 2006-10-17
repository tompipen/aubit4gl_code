#This makefile generates documentation in end-user formats, from 
#source documents.

#
# $Id: Makefile,v 1.4 2006-10-17 06:03:17 afalout Exp $
#

## ==================================================================
##                              Options
## ==================================================================

#Turn on logginf to files, instead overwelming the user with hundred screens of 
#output scooling by at 1000 miles a second
LOG=1
ifeq "${LOG}" "1"
	LOGFILE_NAME	=${notdir $@}.log
	LOGFILE_CMD		=>> ${LOGFILE_NAME} 2>&1

endif

#Default printer name; change here as needed, or pass as a parameter
#when invoking 'make' (eg. make PRINTER=MyPrinter <target>) Note:
#you can this way override any variable specified in this makefile)
PRINTER		=inkjet

#Version number of doccumentation set; to be included in all file names
#of end-user documents created, including tar archive:
DOC_VERSION	=1.0
VER_STR		=-${DOC_VERSION}

#Find out if we have programs we need:
LATEX2HTML	=${shell which latex2html}
LYX			=${shell which lyx}
LATEX		=${shell which latex}
PSBOOK		=${shell which psbook}
PSNUP		=${shell which psnup}
PDFLATEX	=${shell which pdflatex}
CAT			=${shell which cat}
SED			=${shell which sed}
TAR			=${shell which tar}
LP			=${shell which lp}

#Set defaults:
CAN_DO_TEX	=no
CAN_DO_PDF	=no
CAN_DO_HTML	=no
CAN_DO_PS	=no

#Define list of targets by output format:
ALL_TEX		=aubman.tex
ALL_PDF		=aubman${VER_STR}.pdf aubitqref${VER_STR}.pdf
ALL_HTML	=a4glman.html
ALL_PS		=qrbooklet${VER_STR}.ps

#Depending on available programs, decide what FORMATS we can buid:

#-----------------------------------------------------
#tex needs lyx
ifneq "${LYX}" ""
	CAN_DO_TEX=yes
endif
#-----------------------------------------------------
#PDF needs lyx -OR- pdflatex + all tex needs
ifneq "${LYX}" ""
	CAN_DO_PDF=yes
else
	ifneq "${PDFLATEX}" ""
		ifeq "${CAN_DO_TEX}" "yes"
			CAN_DO_PDF=yes
		endif
	endif
endif
#-----------------------------------------------------
#HTML needs cat sed latex LATEX2HTML + all that tex needs
ifneq "${LATEX}" ""
	ifeq "${CAN_DO_TEX}" "yes"
		ifneq "${CAT}" ""
			ifneq "${SED}" ""
				ifneq "${LATEX2HTML}" ""
					CAN_DO_HTML=yes
				endif
			endif
		endif
	endif
endif

#-----------------------------------------------------
#PS needs lyx -OR- psbook and psnup
ifneq "${LYX}" ""
		CAN_DO_PS=yes
else
	ifneq "${PSBOOK}" ""
		ifneq "${PSNUP}" ""
			CAN_DO_PS=yes
		endif
	endif
endif
#-----------------------------------------------------
#Depending on formats we can build, define what we build by default (all target):
ifeq "${CAN_DO_PDF}" "yes"
	ALL		+=${ALL_PDF}
	ALL_TAR +=${ALL_PDF}
else
	NO_ALL	+=${ALL_PDF}
endif
ifeq "${CAN_DO_HTML}" "yes"
	ALL		+=${ALL_HTML}
	#Note: this is a directory, not a file:
	ALL_TAR +=a4glman
else
	NO_ALL	+=${ALL_HTML}
endif
ifeq "${CAN_DO_PS}" "yes"
	#Do we want to build PS by default at all?
	ALL		+=${ALL_PS}
	#Users really don't care about PS this days, do they?
	#ALL_TAR	+=${ALL_PS}
else
	NO_ALL	+=${ALL_PS}
endif

#Set various options to pass to programs:

#LATEX2HTML arguments for ???
L2HARGS=-split 3 -link 4 -local_icons -show_section_numbers\
	 -html_version 4.0,frame

#LATEX2HTML arguments for ??? (not used)
L2Hsingle=-split 0 -link 0 -show_section_numbers \
	-html_version 4.0,frame -nonavigation 

#Extension to be used for tar file
TAR_EXT=.tar.gz
	
#Declare targets that are not resulting in files with same name:
.PHONY: all a4glman.html clean.all clean srcclean srcclean.html clean.html \
	tarball print.qrbooklet show all.pdf all.html all.ps help

## ==================================================================
##                              Targets
## ==================================================================
	
all: ${ALL}
	@echo "Done: $^"
	
all.html: ${ALL_HTML}
	@echo "Done: $^"
	
all.pdf: ${ALL_PDF}
	@echo "Done: $^"

all.ps: ${ALL_PS}
	@echo "Done: $^"
	
#----------------------------------
#Targets to build end-user formats:
#----------------------------------

#----------- HTML ---------------------
a4glman.html: ./a4glman/a4glman.html
./a4glman/a4glman.html: aubman.tex
ifeq "${CAN_DO_HTML}" "yes"
ifeq "${LOG}" "1"
	@echo "NOTE: Logging output to ${LOGFILE_NAME}"
	rm -f ${LOGFILE_NAME}
endif
	${CAT} $^ | ${SED} '/^\usepackage{ifpdf}/,/^\fi/d' > ${notdir ${basename $@}}.tex
	${LATEX} ${notdir ${basename $@}}.tex ${LOGFILE_CMD}
	${LATEX2HTML} ${L2HARGS} ${notdir ${basename $@}}.tex ${LOGFILE_CMD}
else
	@echo "ERROR: Cannot make HTML - don't have needed utilities"
	exit 1
endif

#----------- PDF ----------------------

ifeq "${CAN_DO_PDF}" "yes"
ifneq "${LYX}" ""

#Rule to make .pdf using lyx:
%${VER_STR}.pdf: %.lyx
ifeq "${LOG}" "1"
	@echo "NOTE: Logging output to ${LOGFILE_NAME}"
	rm -f ${LOGFILE_NAME}
endif
	${LYX} -e pdf2 $^ ${LOGFILE_CMD}
	mv ${basename $^}.pdf $@

else	
# If you cannot get lyx working properly, you can instead call pdflatex
# on the latex document. (Use vi on the aubman.tex) 
#FIXME: use vi to do what?

#Rule to make .pdf using pdflatex:
%${VER_STR}.pdf: %${VER_STR}.tex
ifeq "${LOG}" "1"
	@echo "NOTE: Logging output to ${LOGFILE_NAME}"
	rm -f ${LOGFILE_NAME}	
endif
	${PDFLATEX} $^ ${LOGFILE_CMD}
endif
else

%.pdf:
	@echo "ERROR: Cannot make PDF - don't have needed utilities"
	exit 1

endif

#----------- PS -----------------------

ifeq "${CAN_DO_PDF}" "yes"

aubitqref${VER_STR}.ps: aubitqref.lyx
ifeq "${LOG}" "1"
	@echo "NOTE: Logging output to ${LOGFILE_NAME}"
	rm -f ${LOGFILE_NAME}
endif
	${LYX} -e ps $^ ${LOGFILE_CMD}

qrbooklet${VER_STR}.ps: aubitqref.ps
#ifeq "${LOG}" "1"
#	@echo "NOTE: Logging output to ${LOGFILE_NAME}"
#	rm -f ${LOGFILE_NAME}
#endif
	${PSBOOK} $^ | ${PSNUP} -2nup > $@
	
else

%.ps:
	@echo "ERROR: Cannot make PS - don't have needed utilities"
	exit 1

endif
	
## ==================================================================
##                              Sub-targets
## ==================================================================

#--------------------------------------
#Targets to build intermediate formats:
#--------------------------------------

#Rule for making .tex:
%.tex: %.lyx
ifeq "${CAN_DO_TEX}" "yes"
ifeq "${LOG}" "1"
	@echo "NOTE: Logging output to ${LOGFILE_NAME}"
	rm -f ${LOGFILE_NAME}
endif
	${LYX} -e latex $^ ${LOGFILE_CMD}
else
	@echo "ERROR: Cannot make TEX - don't have needed utilities"
	exit 1
endif
	
## ==================================================================
##                              Package
## ==================================================================

#Make distribution archave containing end-user documentation formats:
tarball: ../aubman${VER_STR}${TAR_EXT}
../aubman${VER_STR}${TAR_EXT}: clean.html ${ALL_TAR}
ifneq "${TAR}" ""
	${TAR} -czf $@ ${ALL_TAR}
	@echo "Created archive $@"
else
	@echo "ERROR: Cannot make tar archive - don't have needed utilities"
	exit 1
endif
	
#TODO: add relase target using sf-release script

## ==================================================================
##                              Print
## ==================================================================

# Booklet version of Quick Ref results in a Landscape 2up layout
#	effectively A5 book printable on A4 paper
#	To print it set varialbe PRINTER to the mame of your printer
#	when invoking make (eg. make PRINTER=myprinter print.qrbooklet) 
print.qrbooklet: qrbooklet${VER_STR}.ps
ifneq "${LP}" ""
	${LP} -d ${PRINTER} -o sides=two-sided-short-edge $^
else
	@echo "ERROR: Cannot print - don't have needed utilities"
	exit 1
endif
	
## ==================================================================
##                              Misc
## ==================================================================
	
show:
	@echo "LATEX2HTML     =${LATEX2HTML}"
	@echo "LYX            =${LYX}"
	@echo "LATEX          =${LATEX}"
	@echo "PSBOOK         =${PSBOOK}"
	@echo "PSNUP          =${PSNUP}"
	@echo "PDFLATEX       =${PDFLATEX}"
	@echo " "
	@echo "ALL            =${ALL}"
	@echo "NO_ALL         =${NO_ALL}"
	@echo "ALL_TAR        =${ALL_TAR}"	
	@echo "CAN_DO_PS      =${CAN_DO_PS}"
	@echo "CAN_DO_TEX     =${CAN_DO_TEX}"
	@echo "CAN_DO_PDF     =${CAN_DO_PDF}"
	@echo "CAN_DO_HTML    =${CAN_DO_HTML}"
	@echo " "
	
## ==================================================================
##                              Help
## ==================================================================
help:
	@echo "Aubit 4GL documentation end-user formats creation makefile"
	@echo " "
	@echo "Main targets: "	
	@echo " all:      Create all formats we can, depending on available utilities"
	@echo " all.html: Create all HTML documents"
	@echo " all.pdf:  Create all PDF (Adobe Acrobat) documents"
	@echo " all.ps:   Create all PS (PostScript) ducuments"
	@echo " "
	@echo "Clean targets:"
	@echo " clean.all:      Clean everything not in CVS"
	@echo " clean:          Clean intermediate and temporary files in current directory"
	@echo " srcclean:       Clean everything from current directory, that is not in CVS"
	@echo " srcclean.html:  Clean everything from HTML output directory, that is not in CVS"
	@echo " clean.html:     Clean intermediate and temporary files in HTML output directory"
	@echo " "
	@echo "Misc targets:"
	@echo " show:            Show state of various make settings and variables"
	@echo " help:            Show this help"
	@echo " print.qrbooklet: Print QuickRef booklet to printer PRINTER"
	@echo " tarball:         Create compresed distruibution archive of end-user formats"
	@echo " "
	@echo "Settings:"
	@echo "(Change by declaring on make command line: 'make PRINTER=MyPrinter <target>')"
	@echo " LOG=[1|0]     Enable or disable logging command outout to files"
	@echo " PRINTER=x     Set UNIX printer name to x (Default=${PRINTER})"
	@echo " DOC_VERSION=x Version number of doccumentation set (Current=${DOC_VERSION})"
	@echo " See also: variables displayed with 'make show'"
	@echo " "
	@echo "Please report bugs to appropriate Aubit project mailing list"
	@echo " "
	@echo " "	
	
## ==================================================================
##                              Clean
## ==================================================================

clean.all: srcclean srcclean.html
	@echo "Everything not in CVS removed"

#Clean intermediate and temporary files in current directory:
clean:
	rm -f *.log *~ *.bak #Makefile#

#Clean everything from current directory, that is not in CVS:
srcclean: clean
	rm -f *.pdf *.tex *.aux *.dvi *.out *.toc

#Files we need to remove form CVS, and then add to clean targets:
#aubitqref.ps aubman.ps qrbooklet.ps aubman.txt table.lyx WARNINGS

#Directories in which nothing ends up:
#quick_ref bin manual

#Clean everything from HTML output directory, that is not in CVS:
srcclean.html: clean.html
	cd a4glman; rm -f *.html *.png *.css

#Clean intermediate and temporary files from HTML output directory:
clean.html:
	cd a4glman; rm -f *.aux *.log *.out *.pl *.tex WARNINGS 

# ------------------------------- EOF -------------------------------
