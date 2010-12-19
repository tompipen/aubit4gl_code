/* 
	mkmess - message help file compiler, Informix 4gl style formated
*/

#include <stdio.h>
#include <string.h>
FILE *hlp;
FILE *msg;
FILE *tmp;
char fname_hlp[20];
char fname_msg[20];
char fname_tmp[20];
int offset;
int offset2;
int flg;
int num;
char tmpbuf[80];
char tmpnum[6];
main(int argc,char *argv[])
{
        if (argc!=2)
                {
                printf("Usage: mkmess help-file (no .msg extension)\n");
                exit(0);
                }
        sprintf(fname_msg,"%s.msg",argv[1]);
        sprintf(fname_hlp,"%s.hlp",argv[1]);
        sprintf(fname_tmp,"%s.tmp",argv[1]);
        msg=fopen(fname_msg,"r");
        if (msg==0)
                {
                printf("Error opening File %s\n",fname_msg);
                exit(0);
                }
        hlp=fopen(fname_hlp,"wb");
        tmp=fopen(fname_tmp,"wb");
        offset=0;
        while (1)
                {
                if (feof(msg)) break;
                fgets(tmpbuf,80,msg);
                if (tmpbuf[0]=='#') continue;
                if (tmpbuf[0]=='.') offset=offset+4;
                }
        if (offset==0)
                {
                printf("Cannot process this file\nThere are no help
numbers\n");
                exit(0);
                }
        rewind(msg);
        tmpbuf[0]=0;
        offset2=offset;
        flg=0;
        while (1)
                {
                if(feof(msg)) {
                        if (flg==1) {
                        if (tmpbuf[strlen(tmpbuf)]!='\n'&& tmpbuf[0]!='#') {
                        fprintf(tmp,"\n");   }
                        offset++;}
                        break;
                        }
                tmpbuf[0]=0;
                fgets(tmpbuf,80,msg);
                if (feof(msg)) break;
                if (tmpbuf[0]=='.')
                        {
                        if (flg==1) {fprintf(tmp,"%c",127);}
                        offset++;
                        num=atoi(&tmpbuf[1]);
                        fwrite(&num,2,1,hlp);
                        fwrite(&offset,2,1,hlp);
                        flg=1;
                        continue;
                        }
                if (flg==1)
                        {
                        fprintf(tmp,"%s",tmpbuf);
                        offset=offset+strlen(tmpbuf);
                        }
        }

num=-1;
fwrite(&num,2,1,hlp);
fwrite(&offset,2,1,hlp);
fclose(tmp);
tmp=fopen(fname_tmp,"rb");
while (1==1)
{
num=fgetc(tmp);
if (feof(tmp)) break;
fputc(num,hlp);
}
fclose(hlp);
fclose(tmp);
unlink(fname_tmp);
}

read_help_f(int no)
{
int pos;
hlp=fopen(fname_hlp,"rb");
while (1)
{
fread(&pos,2,1,hlp);
if (pos==-1 || pos>no) break;
if (feof(hlp)) break;
fread(&num,2,1,hlp);
if (pos==no)
        {
        fseek(hlp,(long)num+3,SEEK_SET);
        while(1==1)
        {
        if (feof(hlp)) break;
        fgets(tmpbuf,80,hlp);
        printf("%s",tmpbuf);
        num=fgetc(hlp);
        if (num==127) break;
        else
        ungetc(num,hlp);
        }
        }
if (pos==no) break;
}
}

