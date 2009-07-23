#ifdef MKSTATESOPTS

static int compint(const void *v1,const void *v2) {
int *i1;
int *i2;
        i1=(int *)v1;
        i2=(int *)v2;
        if (*i1==*i2) return 0;
        if (*i1<*i2) return -1;
        return 1;
}

int get_nints(const int *n) {
int a=0;
for (a=0;n[a]!=-1;a++)  ;
return a;
}



main() {
int a;
int b=0;
int c;
int d=0;
int maxtok=0;
        for (a=0;token_groups[a];a++) {
		b++;
		for (c=0;token_groups[a][c]!=-1;c++) {
			if (c>d) d=c;
		}
	}
	maxtok=b;
	printf("#include <stdlib.h>\n");
        for (a=0;token_groups[a];a++) {
                int nc;
                static int *m=0;
                if (m) free(m);
	
                nc=get_nints(token_groups[a]);
                m=malloc(sizeof(int)*nc);
                memcpy(m,token_groups[a],sizeof(int)*nc);
                qsort(m, nc, sizeof(int), compint);
                printf("static const short arr_%d[]={%d",a,nc);
                for (b=0;b<nc;b++) {
                        printf(",%d",m[b]);
                        if (b%10==9) printf("\n   ");
                }
		printf("};\n");
        }

        printf("static const short *tok_groups[%d]={\n",maxtok+2);
        for (a=0;token_groups[a];a++) {
			printf("arr_%d,\n",a,a);
			
	}
	printf("0};");

	printf("static int compshort(const void *v1,const void *v2) {\n");
	printf("short *i1;\n");
	printf("short *i2;\n");
        printf("i1=(short *)v1;\n");
        printf("i2=(short *)v2;\n");
        printf("if (*i1==*i2) return 0;\n");
        printf("if (*i1<*i2) return -1;\n");
        printf("return 1;\n");
	printf("}\n\n");	
	//printf("#include \"mk_states_1.h\"\n");

	printf("int FGLPARSE_allow_token_state(int yystate,int yytoken) {\n");
	printf("const short *clist;\n");
	printf("short ytok;\n");
	printf("  if (yytoken<0) return 1;\n");
	printf("  clist=tok_groups[yystate];\n");
        printf("  if (clist[0]==0) return 0;\n");
	printf("ytok=(short)yytoken;\n");
	printf("  if ( bsearch(&ytok, &clist[1], clist[0],sizeof(short), compshort)) return 1;\n");
	printf("  return 0;\n");
	printf("}\n");
exit (0);
}

#endif
