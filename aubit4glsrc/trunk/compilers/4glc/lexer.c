#include <stdio.h>
#include "../../lib/libincl/debug.h"
#include "rules/generated/kw.h"
#include "rules/generated/y.tab.h"
#ifndef KWS_COMMENT
#define KWS_COMMENT COMMENT
#endif

extern struct s_kw kwords[];

char idents[256][256];
int idents_cnt=0;


FILE *yyin=0;
int yylineno=1;
extern int chk4var;
char *lastword;
int lastlex=-2;

int xccode=0;
int ccnt=0;
char xwords[256][256];
int word_cnt=0;
 
long fpos;
char *read_word(FILE *f,int *t);
int ccat(char *s,char a,int instr) ;
char *mk_word(int c) ;
#define stricmp strcasecmp

#define TYPE_EOF  -1
#define TYPE_USTRING  -2 /* unterminated string */
#define TYPE_NUM 3

#define DBG //

char *read_word2(FILE *f,int *t);


mja_fgetc(FILE *f) {
int a;
a=fgetc(f);
if (a=='\n') {
	yylineno++;
	fpos=ftell(f);
	}
return a;
}

mja_ungetc(int a,FILE *f) {
ungetc(a,f);
if (a=='\n')  {
	yylineno--;
	fpos=ftell(f);
	}
}

#define fgetc(x) mja_fgetc(x)
#define ungetc(x,y) mja_ungetc(x,y)

yylex() {
int a;
char buff[1024];
char buffval[20480];
debug("In yylex...");
if (yyin==0) {
	printf("No input...\n");
	exit(0);
}


a=chk_word(yyin,buff);

if (chk4var) a=NAMED_GEN;

if (a==2||a==NAMED_GEN) {
	debug("Word : %s",buff);
	debug("Constant check returns %d",check_for_constant (buff, buffval));
	switch(check_for_constant (buff, buffval)) {
	case 0: break;
	case 1: debug("Constant switch %s Char",buffval);strcpy(buff,buffval); a=CHAR_VALUE;break ;//'c'
	case 2: debug("Constant switch %s Float",buffval);strcpy(buff,buffval); a=NUMBER_VALUE;break ;//'f'
	case 3: debug("Constant switch %s Integer",buffval);strcpy(buff,buffval); a=INT_VALUE;break ;//'i'
	}
}
if (a==2) {
	to_lower_str(buff);
}

fix_bad_strings(buff);

set_str(buff);
lastword=buff;
lastlex=a;
if (acl_getenv("DEBUG")) {
    debug(">>>>>%04d %d (%4d) %s code=%d fpos=%d chk4var=%d\n",yylineno,ccnt,a,buff,xccode,fpos,chk4var);
}
word_cnt=0;
return a;
}

relex(int lc) {
int a;
fprintf(stderr,">>>> %d %s (%d)\n",lastlex,lastword,lc);

if (lastlex!=NAMED_GEN) return lc;
a=0;
while (kwords[a].id>0) {
	if (kwords[a].vals[1]==0) {
		if (strcasecmp(kwords[a].vals[0],lastword)==0) {
			if (kwords[a].mode>=1) {
				lastlex=kwords[a].id;
				return lastlex;
			}
		}
	}
	a++;
}
return lc;

}

char *read_word(FILE *f,int *t) {
char *ptr;
ptr=read_word2(f,t);
strcpy(xwords[word_cnt],ptr);
word_cnt++;
return ptr;
}

char *read_word2(FILE *f,int *t) {
static char word[1024]="";
int escp=0;
int instrs=0;
int instrd=0;
int a;
strcpy(word,"");
*t=NAMED_GEN;
	while (1) {
		a=fgetc(f);
		if (feof(f)) {
			*t=TYPE_EOF;
			return word;
			}

		if (xccode==2) {
			while (1) {
				if (feof(f)) break;
				if (a=='\n'||a=='\r') {
					if (strcasecmp(word,"endcode")==0) break;
					a=fgetc(f);
					continue;
				}
			
				if (a==';') {
					break;
				}
				ccat(word,a, instrs||instrd);
				a=fgetc(f);
			}
			*t=CLINE;
			return word;
		}

                if (xccode==1) {
                        while (1) {
                                if (feof(f)) break;
                                if (a=='\n'||a=='\r') {
                                        break;
                                }
                                ccat(word,a,instrs||instrd);
                                a=fgetc(f);
                        }
                        *t=CLINE;
                        return word;
                }  



		//DBG printf("Read %c\n",a);

		if (a=='#'&&instrs==0&&instrd==0&&xccode==0) {
			if (strlen(word)>0) {
				ungetc(a,f);
				return word;
			}
	
			while (1) {
				a=fgetc(f);
				if (feof(f)) break;
				if (a=='\n'||a=='\r') {
					break;
				}
				ccat(word,a,instrs||instrd);
			}
			*t=KWS_COMMENT;
			return word;

		}

		if (a=='-'&&instrs==0&&instrd==0&&xccode==0) {
			int z;
			z=fgetc(f);
			ungetc(z,f);
			if (z=='-') {
				while (1) {
					a=fgetc(f);
					if (feof(f)) break;
					if (a=='\n'||a=='\r') break;
					ccat(word,a,instrs||instrd);
				}
				*t=KWS_COMMENT;
				return word;
			}
		}


		if (a=='!'&&instrs==0&&instrd==0&&xccode==0) { 
			char c;
			c=fgetc(f);
			if (c=='}') {
				strcpy(word,"!}");
				*t=KWS_COMMENT;
				return word;
			} else {
				ungetc(c,f);
			}
		}

		if (a=='{'&&instrs==0&&instrd==0&&xccode==0) {
				a=fgetc(f);
				if(a!='!')   {
					while (1) {
						a=fgetc(f);
						if (feof(f)) break;
						if (a=='}') break;
						//ccat(word,a,instrs||instrd);
					}
				}
			*t=KWS_COMMENT;
			return word;
		}
		

		

		if ((a=='\n'||a=='\r')&&escp==0) {
			if (instrs||instrd) {
				printf("Unterminated string escp=%d?\n",escp);
				*t=TYPE_USTRING;
			}
			if (strlen(word)>0) return word;
			else continue;
		}


		if (instrs==0&&instrd==0&&(a==' '||a=='	')) {
			if (strlen(word)>0) {
				return word;
			}
			else continue;
		}

		if (ispunct(a)&&a!='.'&&a!='_'&&instrs==0&&instrd==0) {
			if (strlen(word)>0) {
				ungetc(a,f);
				return word;
			}
		}

		if (instrs==0&&instrd==0&&(ispunct(a))&&a!='"'&&a!='\''&&a!='_') {
			if (strlen(word)>0) {
				if (isnum(word)&&a=='.')  ;
				else  {
					ungetc(a,f);
					return word;
				}
			} else {
				ccat(word,a,instrs||instrd);
				return word;
			}
		}

		if (a=='\\'&&!escp) {
			ccat(word,a,instrs||instrd);
			if  (escp==0) {escp=1;continue;}
			else {escp==0;}
		}

		if (a=='"'&&!escp&&instrs==0) {
			if (instrd==1) {
				ccat(word,'"',instrs||instrd);
				*t=CHAR_VALUE;
				return word;
			}
			ccat(word,'"',instrs||instrd);
			instrd=1;
			continue;
		}
		if (a=='\"'&&instrs==1) {
			ccat(word,'\\',instrs||instrd);
			ccat(word,'\"',instrs||instrd);
			continue;
		}
		if (a=='\''&&!escp&&instrd==0) {
			if (instrs==1) {
				ccat(word,'"',instrs||instrd);
				*t=CHAR_VALUE;
				return word;
			}
			ccat(word,'"',instrs||instrd);
			instrs=1;
			continue;
		}
		ccat(word,a,instrs||instrd);
		escp=0;
	}

}

ccat(char *s,char a,int instr) {
char buff[3];
if (instr==0||(a!='\n'&&a!='\r'&&a!='\t')) {
	buff[0]=a;
	buff[1]=0;
	strcat(s,buff);
} else {
	buff[0]='\\';
	if (a=='\n') buff[1]='n';
	if (a=='\t') buff[1]='t';
	if (a=='\r') buff[1]='r';
	buff[2]=0;
	strcat(s,buff);
}

}


chk_word(FILE *f,char *str){
long a;
int cnt;
char *p;
int t;
char buff[256];
int oline;
int ocharno;
cnt=0;

p=read_word(f,&t);

if (strcmp(p,"sql_code")==0&&xccode==0) {
		xccode=2;
		return KW_CSTART;
}

if (strcmp(p,"code")==0&&xccode==0) {
		xccode=1;
		return KW_CSTART;
}

if (strcmp(p,"endcode")==0&&xccode) {
		printc("/* End of code */");
		xccode=0;
		return KW_CEND;
}


if (xccode==1) {
			strcpy(str,p);
			return CLINE;
	}

if (xccode==2) {
			strcpy(str,p);
			strcat(str,"*");
			return SQLLINE;
	}

if (t==KWS_COMMENT) {
		strcpy(str,p);
		return chk_word(f,str);
		/* dont return comments */
}
oline=yylineno;
a=ftell(f);
strcpy(buff,p);

if (t==TYPE_EOF)  {strcpy(str,""); return -1;}

//printf("Read word %s\n",p);

while (kwords[cnt].id>0) {
	strcpy(p,buff);
        //debug("Check %s against ID %d (%s) (%d)\n",p,kwords[cnt].id,kwords[cnt].vals[0],kwords[cnt].mode);
	if (kwords[cnt].mode>=1) {
		idents_cnt=0;
		if (words(cnt,0,f,p)) {
			//printf("Matches to %d\n",kwords[cnt].id);
			strcpy(str,mk_word(cnt));
			return kwords[cnt].id;
		}
	}

	fseek(f,a,SEEK_SET);
	yylineno=oline;
	cnt++;
}

strcpy(str,p);
a=isnum(str);
if (a==1) t=INT_VALUE;
if (a==2) t=NUMBER_VALUE;
return t;
}



words(int cnt,int pos,FILE *f,char *p) {
int f_pos;
int z;
int t;
char buff[132];
int states=-1;

	strcpy(buff,kwords[cnt].vals[pos]);

	if (buff[0]=='*'&&strlen(buff)>1) {
		strcpy(buff,&kwords[cnt].vals[pos][1]);
		states=1;
	}

	if (stricmp(buff,"<ident>")==0)  {
		strcpy(idents[idents_cnt++],p);
		//printf("check %s\n",p);
		if (isident(p)==0) return 0;
	} else {
		if (stricmp(p,buff)!=0) {
			return 0;
		}
	}
	if (states!=-1) start_state(buff,states);

	if (kwords[cnt].vals[pos+1]==0) {
		return 1;
	}
	p=read_word(f,&t);

	z=words(cnt,pos+1,f,p);

	if (z==0) {
		//fseek(f,f_pos,SEEK_SET);
		return 0;
	}
}

#ifdef OLD
words(int cnt,int pos,FILE *f,char *p) {
int f_pos;
int z;
int t;
	//if (kwords[cnt].vals[pos]==0) {
		////DBG printf("End of list\n");
		//return 1;
	//}

	//f_pos=ftell(f);

	//printf("Check word %s against %s\n",p,kwords[cnt].vals[pos]);
	if (stricmp(p,kwords[cnt].vals[pos])!=0) {
		return 0;
	}

	//printf("Get Next word\n");
	if (kwords[cnt].vals[pos+1]==0) {
		//DBG printf("End of list\n");
		return 1;
	}
	p=read_word(f,&t);

	z=words(cnt,pos+1,f,p);

	if (z==0) {
		//fseek(f,f_pos,SEEK_SET);
		return 0;
	}
}
#endif

char *mk_word(int c) {
static char buff[256];
int a;
int icnt=0;
strcpy(buff,"");
for (a=0;kwords[c].vals[a];a++) {
	if (a>0) strcat(buff, " ");

	if (stricmp(kwords[c].vals[a],"<ident>")==0) {
		strcat(buff,idents[icnt++]);
	} else {
		strcat(buff,kwords[c].vals[a]);
	}
}
return buff;
}

to_lower_str(char *s) {
int a;
for (a=0;a<strlen(s);a++) {
	s[a]=tolower(s[a]);
}
}

isnum(char *s) {
int a;
int dp=0;

for (a=0;a<strlen(s);a++) {
	if (a==0&&(s[a]=='-'||s[a]=='+')) continue;
	if (s[a]=='.'&&dp==0) {dp++;continue;}
	if  (s[a]>='0'&&s[a]<='9') continue;
	return 0;
}
if (strchr(s,'.')) return 2;
return 1;
}

turn_state(int kw,int v) {
int a;
//debug("State changes %d to %d\n",kw,v);
for (a=0;kwords[a].id>0;a++) {
		if (kwords[a].id==kw) {

			//debug("a=%d kw=%d\n",a,kw);
				if (v) kwords[a].mode++;
				else kwords[a].mode--;
			//return;
		}
}
}






isident(char *p) {
int a;
for (a=0;a<strlen(p);a++) {
	if (isalnum(p[a])||p[a]=='_') continue;
	return 0;
}
return 1;
}


fix_bad_strings(char *s) {
char buff[10000];
int c;
int a;
if (s[0]!='"') return s;

buff[0]=s[0];
c=1;

for (a=1;a<strlen(s);a++) {
	if (s[a]!='\\') {
		buff[c++]=s[a];continue;
	}

	if (s[a+1]=='['||s[a+1]==']'||s[a+1]=='^') {
		buff[c++]=s[a+1];
		a++;
		continue;
	}
	buff[c++]='\\';
}

buff[c]=0;
debug("Fixstring changed %s to %s",s,buff);
strcpy(s,buff);
return s;
}
