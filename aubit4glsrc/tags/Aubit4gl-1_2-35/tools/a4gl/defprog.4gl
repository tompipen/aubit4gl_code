#database syspgma4gl

define lc_maxfiles constant 2000
define lc_strlen constant 256

define lv_names array[lc_maxfiles] of char(lc_strlen)
define lv_types array[lc_maxfiles] of char(1)
define lv_dirs array[lc_maxfiles] of char(lc_strlen)

main
define lv_str char(lc_strlen)
define c integer
define lv_deffile char(lc_strlen)
define lv_runstr char(lc_strlen)
define lv_dbname char(256)

let lv_dbname=get_syspgma4gl_dbname()
database lv_dbname
# Get the name of the program from the last portion of the current directory
let lv_str=basename(aclfgl_getcwd())

if aclfgl_file_exists("L_"||lv_str) then
        let lv_deffile="L_"||lv_str
else
        let lv_deffile=" "
end if
#generate a program - with the
        if generate_program_def(lv_str,lv_deffile) then
                displaY "created program definition for ",lv_str clipped
                display "generating makefile for ",lv_str clipped
                let lv_runstr="a4gl -p "||lv_str
                display "running:",lv_runstr clipped

                run lv_runstr clipped
                display "generating tmp makefile for ",lv_str clipped,"_tmp"
                let lv_runstr= "a4gl -p "||lv_str clipped||"_tmp"
                  display "running:",lv_runstr clipped
                 run lv_runstr clipped

        else
                display "Failed to generate program ",lv_str clipped
        end if

end main

function generate_program_def(lv_progname, lv_deffile)
define lv_progname char(128)
define lv_progname_tmp char(128) # The program when using local files
define lv_vrun, lv_deffile  char(lc_strlen)
define a,c integer
define lv_handle integer
define lv_stat integer
define lv_builddir, lv_outpath,lv_outpath_tmp char(lc_strlen)
define lv_getcwd char(lc_strlen)
define lv_lfile_dir char(255)
define lv_v4gl char(255)
define lv_now integer
define lv_val char(100)

let lv_progname_tmp=lv_progname clipped,"_tmp"

for c=1 to lc_maxfiles
        let lv_names[c]= " "
        let lv_dirs[c]= " "
        let lv_types[c]= " "
end for
let lv_getcwd=aclfgl_getcwd()

let lv_lfile_dir="$V4GL"
let lv_v4gl=fgl_getenv("V4GL")

if lv_v4gl != " " then
   if lv_getcwd[1,length(lv_v4gl)]=lv_v4gl then
      let lv_lfile_dir="$V4GL",lv_getcwd[length(lv_v4gl),lc_strlen]
   end if
end if

code 
lv_now=time(0);
endcode



if lv_deffile is null or lv_deffile matches " " then
display "Using files in directory"
# Get the current list of 4gls and pers and use them instead...
code
{
char **names;
        names=A4GL_read_directory(".",".4gl");
        if (names!=0) {
                for (c=0;names[c];c++) {
                     strcpy(lv_names[a++],names[c]);
                }
                free(names);
        }
        names=A4GL_read_directory(".",".per");
        if (names!=0) {
                for (c=0;names[c];c++) {
                     strcpy(lv_names[a++],names[c]);
                }
                free(names);
        }
}

endcode
else
display "Using supplied file list"
        # read the list of the files instead
        let lv_handle=A4GL_file::fopen(lv_deffile,"r");
        let a=1

        if lv_handle then
                while not A4GL_file::feof(lv_handle)
                        let lv_names[a]=A4GL_file::fgets(lv_handle)
code
{
   char *ptr;
   /* find "-" */
   ptr=strchr(lv_names[a-1],'-');
   if (ptr) {
      if (strstr(ptr, "--!") == ptr) {
         /* replace "--!" with "   " */
         strncpy(ptr, "   ",3);
      } else
         if (strstr(ptr, "--#") == ptr) {
            /* cut after "--#" */
            *ptr=0;
         }
   }
   /* remove spaces at the beginning */
   while (strncmp(lv_names[a-1]," ", 1) == 0) {
	char buff[3000];
	strcpy(buff, lv_names[a-1]+1);
        strcpy(lv_names[a-1], buff);
   }
   /* cut on '#' */
   ptr=strchr(lv_names[a-1],'#');
   if (ptr) *ptr=0;
}
endcode

                        # We wont count blank lines..
                        if lv_names[a] is not null and lv_names[a] not matches " " then
                              if lv_names[a][1]!="$" and lv_names[a][1]!="/" then
                                let lv_names[a]="$V4GL/",lv_names[a]
                              end if
                              let a=a+1
                        end if
                end while
        end if
        let a=a-1
end if

if a=0 then
        display "No 4gls or pers found"
        return false
end if



# Go through and set the file types
for c=1 to a

        if lv_names[c] matches "*.4gl" then
                let lv_types[c]="M"
                let lv_names[c]=lv_names[c][1,length(lv_names[c])-4]
                continue for
        end if

        if lv_names[c] matches "*.per" then
                let lv_types[c]="F"
                let lv_names[c]=lv_names[c][1,length(lv_names[c])-4]
                continue for
        end if


        # We'll need to guess - lets see if files exist with these names..
        if aclfgl_file_exists(lv_names[c] clipped||".4gl") then
                let lv_types[c]="M"
                continue for
        end if
        if aclfgl_file_exists(lv_names[c] clipped||".per") then
                let lv_types[c]="F"
                continue for
        end if

        display "Unable to get the file type for : ",lv_names[c]
        return false

end for




        let lv_outpath=lv_lfile_dir clipped,"/make_"||lv_progname clipped
        let lv_outpath_tmp="make_"||lv_progname clipped,"_tmp"

        let lv_vrun="$VMAKE" #,lv_progname clipped


        # theres no specific one for this user...
        # get rid of any old program definition
        delete from program where progname=lv_progname
        delete from entity where progname=lv_progname
        delete from afglsettings where progname=lv_progname


        delete from program where progname=lv_progname_tmp
        delete from entity where progname=lv_progname_tmp
        delete from afglsettings where progname=lv_progname_tmp

        let lv_val=fgl_getenv("A4GL_C_COMP")
        if lv_val != " " then
           insert into afglsettings values(lv_progname, " ","A4GL_C_COMP",lv_val)
        else
           insert into afglsettings values(lv_progname, " ","A4GL_C_COMP","ccache gcc")
        end if

        insert into afglsettings values(lv_progname, " ","A4GL_C_COMP","ccache gcc")
        insert into afglsettings values(lv_progname_tmp, " ","A4GL_C_COMP","ccache gcc")

        insert into afglsettings values(lv_progname, " ","A4GL_EXE_PREFIX","p_")
        insert into afglsettings values(lv_progname_tmp, " ","A4GL_EXE_PREFIX","p_")

        insert into afglsettings values(lv_progname, " ","A4GL_USE_FORMXML","Y")
        insert into afglsettings values(lv_progname_tmp, " ","A4GL_USE_FORMXML","Y")

        insert into afglsettings values(lv_progname, " ","LFILE_DIR",lv_lfile_dir)
         LET lv_lfile_dir="$"||lv_lfile_dir
        insert into afglsettings values(lv_progname, " ","LFILE_DIR_NOT_EXPANDED",lv_lfile_dir)

        insert into afglsettings values(lv_progname_tmp, " ","TRY_LOCAL_GLOBALS_FIRST","Y")

         # We'll use the current directory for the tmp version...
        insert into afglsettings values(lv_progname_tmp, " ","LFILE_DIR",".")

        # create a new program definition
        insert into program (
                progname    ,
                justuser   ,
                progoutdir ,
                progmakefile,
                linkflags  ,
                compflags ,
                lastupd  ,
                genmakefile) values (lv_progname, " ", lv_vrun, lv_outpath, " "," ",lv_now ,0)

        # create a new program definition for the 'tmp' version - no other directories used...
        insert into program (
                progname    ,
                justuser   ,
                progoutdir ,
                progmakefile,
                linkflags  ,
                compflags ,
                lastupd  ,
                genmakefile) values (lv_progname_tmp, " ", ".", lv_outpath_tmp,  " "," ",lv_now,0)


for c=1 to a
   
        if lv_types[c]="M" then
            # Is it really a globals file ?
            # in reality - this just adds a dependency anyway...
            if lv_names[c] matches "*glob*" or lv_names[c] matches "g_*" then
                        let lv_types[c]="G"
            else
                run "grep -y 'end globals' "||lv_names[c] clipped||".4gl > /dev/null" returning lv_stat
                if lv_stat=0 then
                        let lv_types[c]="G"
                end if
            end if
        end if

        let lv_outpath=dirname(lv_names[c])
        let lv_names[c]=basename(lv_names[c])

        insert into entity values(0,lv_types[c],lv_progname, " ",lv_names[c],lv_outpath)
        insert into entity values(0,lv_types[c],lv_progname_tmp, " ",lv_names[c]," ")
        #display "Adding ",  lv_types[c], " ", lv_names[c] clipped, " " ,lv_outpath clipped
end for
return true
end function



function dirname(lv_s) 
define lv_s char(512)
define a integer
define l integer
let l=length(lv_s)
for a=l to 1 step -1
 if lv_s[a]='/' then
   return lv_s[1,a-1]
 end if
end for

return ""
end function


function basename(lv_s) 
define lv_s char(512)
define a integer
define l integer
let l=length(lv_s)
for a=l to 1 step -1
 if lv_s[a]='/' then
   return lv_s[a+1,512] clipped
 end if
end for

return lv_s
end function
