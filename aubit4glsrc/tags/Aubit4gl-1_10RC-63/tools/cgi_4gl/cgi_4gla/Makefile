INSTALL_DIR =	/users/httpserv/cgi-bin
ALL =		circinfo
CFLAGS =	-O2

all: $(ALL)

# circulation lookup program
circinfo:
	c4gl circinfo.4gl 4gl_wrapper.c formsproc.c -o circinfo

# install section
install:
	make all
	installbsd -c -g web -m 750 -o httpserv circinfo $(INSTALL_DIR)

# clean section
clean:
	rm -f $(ALL)
	rm -f *.o
	rm -f *~
	rm -f *.ec
	rm -f *.frm
