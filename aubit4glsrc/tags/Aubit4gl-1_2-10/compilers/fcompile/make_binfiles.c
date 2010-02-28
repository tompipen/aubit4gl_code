#include <stdio.h>

int main(int argc,char *argv[]) {
	int a;
	int cnt;
	FILE *f;
	
	if (argc!=3) {
		printf("Usage : %s file buffname\n",argv[0]);
		exit(2);
	}
	f=fopen(argv[1],"r");
	if (!f) {
		printf("Unable to open file : %s\n",argv[1]);
		exit(2);
	}
	printf("char %s[]={\n",argv[2]);
	cnt=0;
	while (1) {
		cnt++;
		a=fgetc(f);
		if (a==EOF) break;
		printf("0x%02x, ",a);
		if ((cnt%16)==0) printf("\n");
	}
	printf("0};\n");
	exit(0);
}
