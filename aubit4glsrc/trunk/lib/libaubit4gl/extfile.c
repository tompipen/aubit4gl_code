#include <stdio.h>
#include <string.h>
FILE *helpfile = 0;
FILE *langfile = 0;
char *language_file_contents=0;
//char helpbuff[10000];
char disp[24][81];
int max_width;

// Callable from 4GL
void set_help_file (char *fname)
{
  if (helpfile != 0)
    fclose (helpfile);
  helpfile = (FILE *)open_file_dbpath(fname);
  if (helpfile==0) {
        exitwith("Unable to open help file");
  }
debug("Helpfile=%p",helpfile);
}


// Callable from 4GL
void set_lang_file (char *fname_orig)
{
long l;
long a;
char *fname;
fname=strdup(fname_orig);
trim(fname);
debug("Language file='%s'",fname);

if (language_file_contents!=0) free(language_file_contents);
langfile = (FILE *)open_file_dbpath(fname);

if (langfile==0) {
        language_file_contents=0;
        exitwith("Unable to open language file");
        free(fname);
        return;
}

fseek(langfile,0,SEEK_END);
l=ftell(langfile);
rewind(langfile);
language_file_contents=malloc(l+1);
fread(language_file_contents,l,1,langfile);

language_file_contents[l]=0x0;

fclose(langfile);
debug("langfile=%p",langfile);

for (a=0;a<l;a++) {
        if ( language_file_contents[a]=='\n') {
                language_file_contents[a]=0;
        }
}

free(fname);
}

aclfgl_fgl_show_help(int a) {
        a=pop_int();
        show_help(a);
return 0;
}


/* moved to libmsg/msg_native/readmsg.c

read_help_f (int no,int *maxwidth)
{
  short pos;
  int cnt;
  short num;
  char tmpbuf[80];
  max_width = 0;
  cnt = 0;
  rewind (helpfile);
  helpbuff[0]=0;
  *maxwidth=0;
  debug("Reading : %d (%p)",no,helpfile);
  while (1)
    {
      fread (&pos, 2, 1, helpfile);
      debug("pos=%d",pos);

      if (pos == -1 || pos > no) {
         debug("Out of range 1");
         exitwith("Help message not found");
        break;
      }

      if (feof (helpfile)) {
         debug("End of file");
         exitwith("Help message not found");
        return 0;
        break;
      }

      fread (&num, 2, 1, helpfile);

      debug("num=%d",num);

      if (pos == no)
        {
debug("Got it...");
          fseek (helpfile, (long) num + 3, SEEK_SET);
          while (1 == 1)
            {
              if (feof (helpfile))
                break;
              fgets (tmpbuf, 80, helpfile);
debug("Buff=%s",tmpbuf);
              strcat(helpbuff,tmpbuf);
              stripnl (tmpbuf);
              strcpy (disp[cnt++], tmpbuf);
              if (strlen (tmpbuf) > max_width)
                max_width = strlen (tmpbuf);
              if (cnt > 20)
                break;
              num = fgetc (helpfile);
              if (num == 127)
                break;
              else
                ungetc (num, helpfile);
            }
        }

      *maxwidth=max_width;
      if (pos == no) {
           debug("Got it...");
           return cnt;
      }
    }
  exitwith("Could not read help message");
  return 0;

}
*/


char *get_translated_id (char * no_c)
{
  short pos;
  int cnt;
  short num;
  short *ptr;
int no;
  char *cptr;
  max_width = 0;
  cnt = 0;
no=atoi(no_c);

  cptr=language_file_contents;
  if (cptr==0) {
        exitwith("No language file");
        return "<unknown>";
  }


  ptr=(short *)language_file_contents;

  while (1)
    {
      pos=*(short *)cptr;
      debug("pos=%d",pos);

      cptr+=2;

      if (pos == -1 || pos > no) {
         debug("Out of range 1");
         exitwith("message not found");
        return;
        break;
      }

      num=*(short *)cptr;
      cptr+=2;
      debug("num=%d",num);

      if (pos == no)
        {
          cptr=language_file_contents+num+3;
        debug("returning %p",cptr);
          return cptr;

        }
    }
  exitwith("Could not read lang text");
  return "<unknown>";

}


has_helpfile() {
	if (helpfile) return 1;
	else return 0;
}

char *get_help_disp(int n) {
	return disp[n];
}
