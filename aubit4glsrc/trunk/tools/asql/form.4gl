
code
  /* ========================== from a4gl_dtypes.h ==================== */
#define DTYPE_CHAR      0
#define DTYPE_SMINT     1
#define DTYPE_INT       2
#define DTYPE_FLOAT     3
#define DTYPE_SMFLOAT   4
#define DTYPE_DECIMAL   5
#define DTYPE_SERIAL    6
#define DTYPE_DATE      7
#define DTYPE_MONEY     8
#define DTYPE_DTIME     10
#define DTYPE_BYTE      11
#define DTYPE_TEXT      12
#define DTYPE_VCHAR     13
#define DTYPE_INTERVAL  14
endcode
define mv_lastform char(255)
define mv_editor char(255)
define mv_db char(255)

function form_menu()
        if not has_db() then
                call select_db()
        end if

        if not has_db() then
                return
        end if

	let mv_db=get_db()

  	call clear_screen_portion()

	menu "FORM"
		command "Run" "Run a form"
			call run_form()
	
		command "Modify" "Modify a form"
			if modify_form() then
				message ""
			else
				message ""
			end if
		
		command "Generate" "Generate a form"
			if generate_form() then
				message ""
			end if
	
		command "New" "Create a new form"
			call new_form()
	
		command "Compile" "Compile a form"
			call compile_form()
	
		command "Drop" "Drop a form"
			call drop_form()
	
		command "Exit" "Exit menu"
			exit menu
	end menu

end function



function run_form()
	error "Not implemented run_form"
end function





function modify_form()
define lv_fname char(255)
define a integer
define lv_runstr char(512)
define lv_backup char(255)

display "Choose a file to modify","" at 2,1

let a=0

code
{
        char **dir;
        dir=read_directory(".",".per");
        if (dir) {
                for (a=0;dir[a];a++) {
                        A4GL_debug("READ FILE: %s",dir[a]);
                        strcpy(lv_fname,dir[a]);
endcode
                        call set_pick(a+1,lv_fname);
code
                }
                free_directory(dir);
        }
}
endcode

call set_pick_cnt(a);
call prompt_pick("CHOOSE >> ","") returning lv_fname

if lv_fname is not null then
	let lv_backup=get_tmp_fname("PER")
	call copy_file(lv_fname,lv_backup)

        let lv_fname=lv_fname clipped,".per"
	if mv_editor is null or mv_editor=" " then
		prompt "Editor ?" for mv_editor
	end if
	if mv_editor is null or mv_editor=" " then
		return 0
	end if

	let lv_runstr=mv_editor clipped, " ",lv_fname
	run lv_runstr returning a

	let a=a/256

	if a=0 then
		display "OK " at 24,1
	else
		display "Bad" at 24,1
	end if


	menu "Modify Form"

		command "Compile"
			call compile_form(lv_fname)

		command "Save-and-exit"
			call remove_tmpfile("PER")
			return 1

		command "Discard-and-exit"
			call copy_file(lv_backup,lv_fname)
			return 1
	end menu
			

	return 1
end if

return 0
end function





function generate_form()
define lv_form char(255)
define lv_tables array[20] of char(255)
define lv_cnt integer
	let int_flag=false

	prompt "Generate Form > " for lv_form

	if int_flag then
		return false
	end if

	let lv_cnt=0

	while true
		let int_flag=false
		let lv_cnt=lv_cnt+1


		prompt "Choose Table > " for lv_tables[lv_cnt]


		if int_flag then
			if lv_cnt=1 then
				return false
			else
				exit while
			end if
		end if

		menu "Generate" 
			command "Table selection complete" 	exit while
			command "Select more" 			continue while
			command "Exit" 				return false
		end menu
	end while
code
	{
	int a;
	char *tables[20];
	for (a=0;a<lv_cnt;a++) {
		A4GL_trim(lv_tables[a]);
		tables[a]=lv_tables[a];
	}
	tables[lv_cnt]=0;
	A4GL_trim(lv_form);
	generate(lv_form,tables);
	}
endcode

end function



function new_form()
	error "Not implemented new_form"
end function

function compile_form()
	error "Not implemented compile_form"
end function

function drop_form()
	error "Not implemented drop_form"
end function


code
FILE *out;
char outfile[256];
char tabname[256][256];
int tabcnt=0;
char **attribs;
int attribs_cnt=0;

static int get_size(int dtype,int size);
static char *spaces(int dtype,int size,char *id);

static void incbuff(char *s);
static char *get_id(int dtype,int size);


static int get_size(int dtype,int size) {
switch(dtype ) {
        case DTYPE_CHAR:        return size;
        case DTYPE_SMINT:       return  5;
        case DTYPE_INT:         return  10;
        case DTYPE_FLOAT:       return  10;
        case DTYPE_SMFLOAT:     return  10;
        case DTYPE_DECIMAL:     return  16;
        case DTYPE_SERIAL:      return  10;
        case DTYPE_DATE:        return  12;
        case DTYPE_MONEY:       return  17;
        case DTYPE_DTIME:       return  17;
        case DTYPE_BYTE:        return  20;
        case DTYPE_TEXT:        return  20;
        case DTYPE_VCHAR:       return size;
        case DTYPE_INTERVAL:    return 20;
}
return 10;

}


static char *spaces(int dtype,int size,char *id) {
static char buff[1024];
int n;
n=get_size(dtype,size);
n-=strlen(id);
if (n>=1023) n=1023;
memset(buff,' ',1024);
buff[n]=0;
return buff;
}


static void incbuff(char *s) {
int a;
int b;
char buff[256];

if (strlen(s)==1) {
        if (s[0]=='z') {
                printf("Too many one length fields\n");
                exit (1);
        }
        s[0]=s[0]+1;
        return;
}


b=atoi(&s[1]);
b++;

sprintf(buff,"%c%*d",s[0],strlen(s)-1,b);

if (strlen(buff)>strlen(s)) {
        if (s[0]=='z') {
                printf("Run out of %d length fields\n",strlen(s));
                exit(1);
        }
        s[0]++;
        b=0;
        sprintf(buff,"%c%*d",s[0],strlen(s)-1,b);
}

strcpy(s,buff);
for (a=0;a<strlen(s);a++) {
        if (s[a]==' ') s[a]='0';
}

}



char *get_id(int dtype,int size) {
static char buff[4][20]={"a","a0","a00","f000"};
static int used[4]={0,0,0,0};
size=get_size(dtype,size);
size--;
if (size>3) size=3;

if (used[size]) incbuff(buff[size]);

used[size]=1;

return buff[size];
}




int generate(char *outfilex,char **tabname) {
int a;
char outfile[255];
for (a=0;tabname[a];a++) ;
tabcnt=a;
strcpy(outfile,outfilex);
if (!strstr(outfile,".per")) {
	strcat(outfile,".per");
}


if (strlen(outfile)) {
        out=fopen(outfile,"w");
        if (out==0) {
                printf("Unable to open output file (%s)\n",outfile);
                exit(2);
        }
} else {
        out=stdout;
}


fprintf(out,"database %s\n",mv_db);

if (strlen(outfile)) {
        fclose(out);
}


for (a=0;a<tabcnt;a++) {
        int idtype;
        int isize;
        char *ccol;
        char *id;
        char buff[256];
        int rval;

        rval = A4GLSQL_get_columns (tabname[a], "", &idtype, &isize);
        if (rval==0) {
                printf("Can't find table %s in database\n",tabname[a]);
                exit(0);
        }
        fprintf(out,"screen\n");
        fprintf(out,"{\n");

        while (1) {
                rval = A4GLSQL_next_column (&ccol, &idtype, &isize);
                A4GL_trim(ccol);
                if (rval==0) break;
                fprintf(out,"%-19.19s",ccol);
                fprintf(out,"[");
                id=get_id(idtype,isize);
                fprintf(out,"%s",id);
                fprintf(out,spaces(idtype,isize,id));
                fprintf(out,"]\n");
                sprintf(buff,"%s = %s.%s;",id,tabname[a],ccol);
                attribs_cnt++;
                attribs=realloc(attribs,sizeof(char *)*attribs_cnt);
                attribs[attribs_cnt-1]=strdup(buff);
        }

        fprintf(out,"}\n");

}


fprintf(out,"end\n");
fprintf(out,"tables\n");

for (a=0;a<tabcnt;a++) {
        fprintf(out,"%s\n",tabname[a]);
}
fprintf(out,"attributes\n");
for (a=0;a<attribs_cnt;a++) {
        fprintf(out,"%s\n",attribs[a]);
}
fprintf(out,"end\n");
return 0;
}


endcode
