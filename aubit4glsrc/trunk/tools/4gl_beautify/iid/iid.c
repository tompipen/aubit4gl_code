/*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/*****************************************************************************/
#define BUFSIZE     2048
#define RESLEFT     6
#define RESRIGHT    8
#define RESSPEC     3
#define RESJUMP     1
#define MAXWORD     20
#define NUMSPACES   3
#define MAXFILENAME 256
#define EXTFILEIN   ".4gl"
#define EXTFILEOUT  ".iid"

/*****************************************************************************/
char *jump_spaces(char *, int *);
char *trata_linha(char *, int *, int);
char *put_spaces(char *, int);
char *put_spaces_pos(char *, int, int);
char *get_next_word(char *, char *);
char *first_word(char *, char *, int *, int, int *, int *, int *);
char *next_word(char *, char *, int *, int, int *, int *, int *);
char *jump_word(char *);
char *make_spaces( char *, int);

void get_file_names(char *str,char *f1,char *f2);


/*****************************************************************************/
char res_right[RESRIGHT][MAXWORD]={
    "then\0","while\0","function\0",
    "main\0","case\0","input\0","report\0","for\0"
                  };
char res_left[RESLEFT][MAXWORD]={
    "end\0","endfunction\0","endwhile\0","endfor\0",
    "endif\0","endcase\0"
                };
char res_spec[RESSPEC][MAXWORD] ={
    "else\0","when\0","otherwise\0"
                };
char res_jump[RESJUMP][MAXWORD] ={
    "exit\0"
                };
FILE *fp_input,*fp_copy,*fp_aux;

/*****************************************************************************/
main(int argc,char *argv[])
{
 char buffer[BUFSIZE],*buf,frase[BUFSIZE];
int fix_spaces = NUMSPACES, n_keys = 0, js, len;
//int n;
char out_name[MAXFILENAME],in_name[MAXFILENAME];
//char wcmd[200];

        
		if (!teste_args(argc,argv,&fix_spaces)) return(1);
        get_file_names(argv[1],in_name,out_name);
		
		#ifdef HUH_WHAT
			strcpy(wcmd,"ksh /users/wetc/sediid ");
    	    strcat(wcmd,in_name);
        	len=strlen(wcmd);
	        wcmd[len-4]='\0';
			n=system("ls -l");
        #endif

        fp_input=fopen(in_name,"r");
        fp_copy=fopen(out_name,"w");
        fp_aux=fopen("aux","w");
        while( fgets(buffer,BUFSIZE,fp_input)!=NULL )
        {
            buf=buffer;
            fputs(buf,fp_copy);
            if (dont_touch(jump_spaces(buf,&js)))
			{
            	fputs(buf,fp_aux);
	            continue;
    		}
			if (is_comment(jump_spaces(buf,&js)))
			{
	            buf=jump_spaces(buf,&js);
	            buf=put_spaces(buf,n_keys*fix_spaces);
	            fputs(buf,fp_aux);
	            continue;
			}

			buf=trata_linha(buf,&n_keys,fix_spaces);
	        fputs(buf,fp_aux);
    	}
	    fclose(fp_input);
    	fclose(fp_copy);
	    fclose(fp_aux);
    	fp_input=fopen(in_name,"w");
	    fp_aux=fopen("aux","r");
    	fseek(fp_aux,0,SEEK_SET);

		while( fgets(buf,BUFSIZE,fp_aux)!=NULL )
        {
            fputs(buf,fp_input);
		}

		fclose(fp_input);
	    fclose(fp_aux);

		#ifdef HUH_WHAT
			strcpy(wcmd,"/users/wetc/sediid1 ");
		    strcat(wcmd,in_name);
		    system(wcmd);
        #endif

	    unlink("aux");

}

/*****************************************************************************/
char *trata_linha(char * str,int * keys, int f_spaces)
{
    int num_word = 0, cont, jumps, partiu, estado;
    char aux[BUFSIZE], aux1[BUFSIZE], word[BUFSIZE], *frase, *out=aux1;

    str=jump_spaces(str,&jumps);
    frase=strcpy(aux,str);
    cont=1;
    *str='\0';
    jumps=0;
    partiu=0;
    estado=0;
    while (!is_return(frase) && cont==1)
    {
        *out='\0';
        if (!partiu)
        {
            out=make_spaces(out,jumps);
            strcat(str,out);
        }
        frase=get_next_word(frase,word);
        num_word++;
        if (estado)
        {
            estado=examina_estado(word,estado);
            strcat(str,word);
            frase=jump_spaces(frase,&jumps);
            continue;
        }
        if (!(num_word - 1))
        {

            out=first_word(frase,word,keys,f_spaces,&cont,&partiu,&estado);
            strcat(str,out);
        }
        else
        {

            out=next_word(frase,word,keys,f_spaces,&cont,&partiu,&estado);
            strcat(str,out);
        }
        frase=jump_spaces(frase,&jumps);
    }
    if (!cont)
    {
        out=make_spaces(out,jumps);
        strcat(str,out);
        strcat(str,frase);
    }
    else
        strcat(str,"\n");
    return(str);
}
/*****************************************************************************/
char *
first_word(char * str,char * word,int * keys,int f_spaces,int * cont,int * partiu,int *estado)
{
    char aux3[BUFSIZE],aux4[BUFSIZE],*aux1,*aux2;
    int js;

    aux1=strcpy(aux3,word);
    aux2=strcpy(aux4,str);
    *estado=0;
    *partiu=0;
    if (is_word_jump(word))
    {
        aux1=put_spaces(aux1,*keys*f_spaces);
        *cont=0;
        return(aux1);
    }
    if (is_word_right(word))
    {
        aux1=put_spaces(aux1,*keys*f_spaces);
        (*keys)++;
        if (!strcmp(word,"function"))
                    (*keys)=1;
        *cont=1;
        if (!strcmp(word,"then") && !is_return(jump_spaces(aux2,&js)))
        {
            *partiu=1;
            *aux2='\0';
            aux2=put_spaces(aux2,*keys*f_spaces);
            aux1=strcat(aux1,"\n");
            aux1=strcat(aux1,aux2);
        }
        return(aux1);
    }
    if (is_word_left(word))
    {
        (*keys)--;
        aux1=put_spaces(aux1,*keys*f_spaces);
        *cont=0;
        return(aux1);
    }
    if (is_word_spec(word))
    {
            if (!is_return(jump_spaces(aux2,&js)))
        {
            *partiu=1;
            aux1=put_spaces(aux1,(*keys-1)*f_spaces);
            *aux2='\0';
            aux2=put_spaces(aux2,*keys*f_spaces);
            aux1=strcat(aux1,"\n");
            aux1=strcat(aux1,aux2);
            return(aux1);
        }
        else
        {
            aux1=put_spaces(aux1,(*keys-1)*f_spaces);
            return(aux1);
        }
    }
    aux1=put_spaces(aux1,*keys*f_spaces);
    *cont=1;
    *estado=examina_estado(word,*estado);
    return(aux1);
}
/*****************************************************************************/
char *
next_word( str, word, keys, f_spaces, cont, partiu, estado)
char *str,*word;
int *keys,f_spaces,*cont,*partiu,*estado;
{
    char aux3[BUFSIZE],aux4[BUFSIZE],*aux1,*aux2,ret[BUFSIZE]="\n\0";


    char word_aux1[BUFSIZE],*word_aux=word_aux1;
    int js;

    aux1=strcpy(aux3,word);
    aux2=strcpy(aux4,str);
    *estado=0;
    *partiu=0;
    *cont=1;
    if (is_word_jump(word))
    {
        *cont=0;
        return(aux1);
    }
    if (is_word_right(word))
    {
        if (!strcmp(word,"input") || !strcmp(word,"report"))
        {
                return(aux1);
        }
        (*keys)++;
        *cont=1;
        if (!strcmp(word,"then"))
            if (!is_return(jump_spaces(aux2,&js)))
            {
                *partiu=1;
                *aux2='\0';
                aux2=put_spaces(aux2,*keys*f_spaces);
                aux1=strcat(aux1,"\n");
                aux1=strcat(aux1,aux2);
                return(aux1);
            }
            else
                return(aux1);
        aux1=put_spaces(aux1,((*keys)-1)*f_spaces);
        aux1=strcat(ret,aux1);
        return(aux1);
    }
    if (is_word_left(word))
    {
        (*keys)--;
        aux1=put_spaces(aux1,*keys*f_spaces);
        aux1=strcat(ret,aux1);
        *cont=0;
        return(aux1);
    }
    if (is_word_spec(word))
    {
            if (!is_return(jump_spaces(aux2,&js)))
        {
            *partiu=1;
            aux1=put_spaces(aux1,(*keys-1)*f_spaces);
            *aux2='\0';
            aux2=put_spaces(aux2,*keys*f_spaces);
            aux1=strcat(aux1,"\n");
            aux1=strcat(aux1,aux2);
            aux1=strcat(ret,aux1);
            return(aux1);
        }
        else
        {
            aux1=put_spaces(aux1,(*keys-1)*f_spaces);
            aux1=strcat(ret,aux1);
            return(aux1);
        }
    }
    *estado=examina_estado(word,*estado);
    return(aux1);
}
/*****************************************************************************/
char *
get_next_word(str,word)
char *str,*word;
{
    while (*str!='\n' && *str!=' ' && *str!='\t')
        *word++=*str++;
    *word='\0';
    return(str);
}
/*****************************************************************************/
char *
jump_word(str)
char *str;
{
    while (*str!='\n' && *str!=' ' && *str!='\t')
        str++;
    return(str);
}
/*****************************************************************************/
char *
jump_spaces(str,jumps)
char *str;
int *jumps;
{
    *jumps=0;
    while (*str==' ' || *str=='\t' )
    {
        if (*str==' ')
            (*jumps)++;
        else
            (*jumps)=+8;
        str++;
    }
    return(str);
}
/*****************************************************************************/
char *
make_spaces(str,spaces)
char *str;
int spaces;
{
    char *aux;
    int i;

    aux=str;
    for (i=1;i<=spaces;i++)
        *str++=' ';
    *str='\0';
    return(aux);
}
/*****************************************************************************/
char *
put_spaces(str,spaces)
char *str;
int spaces;
{
    char aux[BUFSIZE],*aux1,*aux2;
    int i;

    aux1=strcpy(aux,str);
    aux2=str;
    for (i=1;i<=spaces;i++)
        *str++=' ';
    *str='\0';
    return(strcat(aux2,aux1));
}
/*****************************************************************************/
char *
put_spaces_pos(str,spaces,pos)
char *str;
int spaces;
int pos;
{
    char aux1[BUFSIZE],*aux=aux1;
    int i;

    for (i=1;i<=pos;i++)
        *aux++=*str++;
    *aux++='\n';
    for (i=1;i<=spaces;i++)
        *aux++=' ';
    *aux='\0';
    return(strcat(aux1,str));
}
/*****************************************************************************/
int 
is_word_left(str)
char *str;
{
    int i;

    for (i=0;i<RESLEFT;i++)
        if (!strcmp(str,res_left[i]))
            return(1);
    return(0);
}
/*****************************************************************************/
int 
is_word_right(str)
char *str;
{
    int i;

    for (i=0;i<RESRIGHT;i++)
        if (!strcmp(str,res_right[i]))
            return(1);
    return(0);
}
/*****************************************************************************/
int 
is_word_jump(str)
char *str;
{
    int i;

    for (i=0;i<RESJUMP;i++)
        if (!strcmp(str,res_jump[i]))
            return(1);
    return(0);
}
/*****************************************************************************/
int 
is_word_spec(str)
char *str;
{
    int i;

    for (i=0;i<RESSPEC;i++)
        if (!strcmp(str,res_spec[i]))
            return(1);
    return(0);
}
/*****************************************************************************/
int 
teste_args(nargs,args,spaces)
int nargs;
char *args[];
int *spaces;
{
    char fname[MAXFILENAME],*f_name=fname;

    if ((nargs==1) || (nargs==2 && !strcmp(args[1],"-h")))
    {
        printf("iid - indents informix 4gl code\n");
        printf("    Format : iid file(.4gl) [-i n]\n");
        printf("              -i : n spaces for each indentacion\n");
        printf("                   default 3\n");
        printf("    Input   : file.4gl - file to indent\n");
        printf("    Output  : file.4gl - indented file\n");
        printf("              file.iid - backup copy\n");
        return(0);
    }
    if (nargs==4)
    {
        if (!strcmp(args[2],"-i"))
            *spaces=atoi(args[3]);
    }
    strcpy(f_name,args[1]);
    if (fopen(args[1],"r")==(FILE *)NULL )
    {
        strcat(args[1],".4gl");
        if (fopen(args[1],"r")==(FILE *)NULL )
        {
            perror(f_name);
            return(0);
        }
    }
    return(1);
}
/*****************************************************************************/
int 
dont_touch(ptr)
char *ptr;
{
    return(*ptr=='\'' || *ptr =='\"' || *ptr ==',');
}
/*****************************************************************************/
int 
is_comment(ptr)
char *ptr;
{
    return(*ptr=='#');
}
/*****************************************************************************/
int 
is_return(str)
char *str;
{
    return(*str=='\n');
}
/*****************************************************************************/
int
examina_estado(word,estado)
char *word;
int estado;
{
    int aux,pos;

    aux=estado;
    pos=0;
    while (*word!='\0')
    {
        pos++;
        switch(*word)
        {
            case '\\':
                if (*(word+1)!='\0')
                    word++;
                break;
            case '\"':
                if (aux!=2)
                    aux=!aux;
                break;
            case '\'':
                if (aux!=1)
                    aux=(!aux)*2;
                break;
        }
        word++;
    }
    return(aux);
}
/*****************************************************************************/
void
get_file_names(char *str,char *f1,char *f2)
{
    int find=0;

    while( *str!='\0')
    {
        if (*str=='.')
            find = 1;
        *f1++=*str;
        if (!find)
            *f2++=*str;
        str++;
    }
/*  strcat(f1,EXTFILEIN);*/
    strcat(f2,EXTFILEOUT);
}
/*****************************************************************************/
