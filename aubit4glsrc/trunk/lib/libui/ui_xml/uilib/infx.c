#ifndef INFX
int COLS=80;
int LINES=24;
void *stdscr;
void *curscr;





int fgl_start() {
}
int wmove() {
	return 0;
}

int winch () {
	return 0;
}

int wrefresh() {
	return 0;
}

int poplocator() {
	A4GL_assertion(1,"POP LOCATOR not implemented");
}





int eflastkey=-29;
int _hlpkey=-15;
int _inskey=-14;
int _nxtkey=-13;
int _prvkey=-12;
int _acckey=-11;
int _delkey=-10;


int gbtoolsc() {
	A4GL_assertion(1,"gbtoolsc not implemented");
}


CheckScans() {
	A4GL_assertion(1,"CheckScans not implemented");
}

InitScans () {
	A4GL_assertion(1,"InitScans not implemented");
}

SplitScans() {
	A4GL_assertion(1,"SplitScans not implemented");
}

int status=0;
#endif

