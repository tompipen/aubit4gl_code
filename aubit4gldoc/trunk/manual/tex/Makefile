L2H=latex2html
L2HARGS=-split 3 -link 4 -local_icons -show_section_numbers\
	 -html_version 4.0,frame

L2Hsingle=-split 0 -link 0 -show_section_numbers \
	-html_version 4.0,frame -nonavigation 

all: aubman.tex aubman.pdf a4glman.html qrbooklet.ps

clean:
	rm *.log

srcclean:
	rm *.pdf *.tex *.aux *.log
	
aubman.tex:aubman.lyx
	lyx -e latex aubman.lyx

a4glman.html: aubman.tex
	cat aubman.tex | sed '/^\usepackage{ifpdf}/,/^\fi/d' > a4glman.tex
	${L2H} ${L2HARGS} a4glman.tex

# If you cannot get lyx working properly, you can instead call pdflatex
# on the latex document. (Use vi on the aubman.tex)
# e.g.
#   pdflatex aubman.tex

aubman.pdf:aubman.lyx
	lyx -e pdf2 aubman.lyx
	cp aubman.pdf manual

aubitqref.pdf:aubitqref.lyx
	lyx -e pdf2 aubitqref.lyx
	cp aubitqref.pdf quick_ref

aubitqref.ps:aubitqref.lyx
	lyx -e ps aubitqref.lyx

# Booklet version of Quick Ref results in a Landscape 2up layout
#	effectively A5 book printable on A4 paper
#	To print it (replace inkjet with the mame of your printer):
#	lp -d inkjet -o sides=two-sided-short-edge qrbooklet.ps

qrbooklet.ps:aubitqref.ps
	psbook aubitqref.ps | psnup -2nup > qrbooklet.ps

tarball: 
	tar cvfz ../aubman.tar.gz .

