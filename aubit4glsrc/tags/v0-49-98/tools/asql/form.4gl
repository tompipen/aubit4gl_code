
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

define mv_lastused char(255)


################################################################################
function form_menu()

	if mv_editor is null then
		let mv_editor=fgl_getenv("DBEDIT") 
	end if

  	call clear_screen_portion()
	call init_filename()

	menu "FORM"
		command "Run" "Run a form"
			call run_form("")
	
		command "Modify" "Modify a form"
			if modify_form("") then
				message ""
			else
				message ""
			end if
		
		command "Generate" "Generate a form"
        		if not has_db() then 
				call select_db() 
			end if 
			
			let mv_db=get_db()

			if mv_db is null or mv_db matches " " then
			else
				if generate_form() then
					message ""
					next option "Run"
				end if
			end if


		command "New" "Create a new form"
			call new_form()
	
		command "Compile" "Compile a form"
			if compile_form("") then
				# Good..
			end if

	
		command "Drop" "Drop a form"
			call drop_form()
	
		command "Exit" "Exit menu"
			exit menu
	end menu

end function



################################################################################
function run_form(lv_ofname)
define lv_ofname char(255)
define lv_fname char(255)
define lv_runstr char(512)
define a integer
define lv_ext char(255)

let lv_ext=work_out_ext()

display "Choose a file to run","" at 2,1

code
{
        char **dir;
	A4GL_trim(lv_ext);
        dir=read_directory(".",lv_ext);
        if (dir) {
                for (a=0;dir[a];a++) {
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

if lv_ofname is null or lv_ofname matches " " then
	#error "SET PICK 1:",mv_lastused
	call set_picked_option(mv_lastused)
else
	#error "SET PICK 2:",lv_ofname
	call set_picked_option(lv_ofname)
end if
sleep 1

call prompt_pick("RUN >> ","") returning lv_fname


if lv_fname is not null then
	let lv_runstr=fgl_getenv("RUNFORMS")
	if lv_runstr is null or lv_runstr matches " " then
		LET lv_runstr=fgl_getenv("AUBITDIR") clipped,"/bin/runforms"
	end if
	LET lv_runstr=lv_runstr clipped," ",lv_fname

	let mv_lastused=lv_fname

	run lv_runstr clipped

end if

end function





################################################################################
function modify_form(lv_fname)
define lv_fname char(255)
define a integer
define lv_runstr char(512)
define lv_backup char(255)


if lv_fname is null or lv_fname matches "" then
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
end if

if lv_fname is not null then
	let lv_backup=get_tmp_fname("PER")
	call copy_file(lv_fname,lv_backup,".per")

	if lv_fname not matches "*.[Pp][Ee][Rr]" then
        	let lv_fname=lv_fname clipped,".per"
	end if

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


	let mv_lastused=lv_fname
	menu "Modify Form"

		command "Compile" "Compile the form"
			return compile_form(lv_fname) 

		command "Save-and-exit" "Save the form"
			call remove_tmpfile("PER")
			return 1

		command "Discard-and-exit"
			call copy_file(lv_backup,lv_fname,".per")
			return 1
	end menu
			

	return 1
end if

return 0
end function


################################################################################
function compile_form(lv_fname)
define lv_fname char(255)
define a integer
define lv_runstr char(512)
define lv_backup char(255)

if lv_fname is null or lv_fname matches " " then
	display "Choose a file to compile","" at 2,1
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
end if

if lv_fname is null or lv_fname matches " " then
	return 0
end if


if lv_fname is not null then
	let mv_lastused=lv_fname
	let lv_backup=get_tmp_fname("PER")
	call copy_file(lv_fname,lv_backup,".per")

	if lv_fname not matches "*.[Pp][Ee][Rr]" then
        	let lv_fname=lv_fname clipped,".per"
	end if

	let lv_runstr=fgl_getenv("AUBITDIR") clipped,"/bin/fcompile ",lv_fname
	run lv_runstr returning a

	let a=a/256

	if a=0 then
		display "The screen form specification was successfully compiled." at 24,1 attribute(reverse)
		return 1
	else
		menu "COMPILE FORM"
			command "Correct"
				return modify_form(lv_fname)
				exit menu
			command "Exit"
				return 0
				exit menu
		end menu
	end if
end if
return 0
end function




################################################################################
function generate_form()
define lv_form char(255)
define lv_tables array[20] of char(255)
define lv_cnt integer
define lv_tabname char(200)
	let int_flag=false

	prompt "Generate Form > " for lv_form

	if int_flag then
		return false
	end if

	if file_exists(lv_form clipped||".per") then
		error "A form with that name already exists"
		return false
	end if

	let lv_cnt=0

	while true
		let int_flag=false
		let lv_cnt=lv_cnt+1

                call table_select("SELECT TABLE >>") returning lv_tabname

                if lv_tabname is not null and lv_tabname not matches " " THEN
                else
                       let int_flag=true
                end if

		if int_flag then
			if lv_cnt=1 then
				return false
			else
				exit while
			end if
		end if

		let lv_tables[lv_cnt]=lv_tabname

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

let mv_lastused=lv_form
return true
end function



################################################################################
function new_form()
define lv_fname char(255)
	let int_flag=false
	prompt "Form name >>" for lv_fname

	if int_flag=true or lv_fname is null or lv_fname matches " " then
		return
	else
		call modify_form(lv_fname)
	end if

end function


################################################################################
function drop_form()
define lv_fname char(255)
define lv_fname_frm char(255)
define lv_fname_per char(255)
define a integer
display "Choose a file to drop","" at 2,1
code
{
        char **dir;
        dir=read_directory(".",".per");
        if (dir) {
                for (a=0;dir[a];a++) {
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

call prompt_pick("DROP >> ","") returning lv_fname


if lv_fname is not null then
        let lv_fname_per=lv_fname clipped,".per"
        let lv_fname_frm=lv_fname clipped,work_out_ext()

menu "CONFIRM"
        command "No" "No - I don't want to drop it"
                exit menu
        command "Yes" "Yes - I do want to drop it"

code
        A4GL_trim(lv_fname_per);
        A4GL_trim(lv_fname_frm);
        unlink(lv_fname_per);
        unlink(lv_fname_frm);
endcode
        exit menu
end menu
end if

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
if (strlen(outfile)) { fclose(out); A4GL_push_char(outfile); aclfgl_compile_form(1);}
return 0;
}


endcode



function work_out_ext()
define lv_formtype char(255)
define lv_packer char(255)
define lv_ext char(255)

let lv_ext=".frm"

let lv_formtype=fgl_getenv("A4GL_FORMTYPE")

if lv_formtype is null or lv_formtype matches " " then
	let lv_formtype=fgl_getenv("FORMTYPE")
end if

if lv_formtype="GENERIC" THEN
	let lv_packer=fgl_getenv("A4GL_PACKER")

	if lv_packer is null or lv_packer matches " " then
		let lv_packer=fgl_getenv("PACKER")
	end if

	case lv_packer
		when "PACKED" 		let lv_ext=fgl_getenv("A4GL_FRM_BASE_EXT") clipped,fgl_getenv("A4GL_PACKED_EXT")
		when "GZPACKED" 	let lv_ext=fgl_getenv("A4GL_FRM_BASE_EXT") clipped,fgl_getenv("A4GL_PACKED_EXT")
		when "XML" 		let lv_ext=fgl_getenv("A4GL_FRM_BASE_EXT") clipped,fgl_getenv("A4GL_XML_EXT")
	end case
else
	# Assume XDR or compatible
	let lv_ext=fgl_getenv("A4GL_FRM_BASE_EXT")
end if
message "looking for extension : Ext='",lv_ext clipped,"'"
sleep 2
return lv_ext clipped

end function
