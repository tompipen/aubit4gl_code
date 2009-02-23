#include <stdio.h>

main() {
char buff[2000];
	FILE *f;
	f=fopen("/home/aubit4gl/aubit4glsrc/lib/libui/ui_xml/bin/replay.txt","r");
	while (1) {
		if (feof(f)) break;
		fgets(buff,sizeof(buff),f);
		printf("%s",buff);
		if (strstr(buff,"WAITFOREV")) {
			sleep(3);
		}
	}
	fclose(f);
}
