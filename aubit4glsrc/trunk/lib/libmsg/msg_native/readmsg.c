/**
 * @file
 * Functions for reading help message file in native format
 *
 *
 * @todo Add Doxygen comments to file
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
 */

#include <stdio.h>

//from extfile.c :
char helpbuff[10000];
char disp[24][81];
int max_width;
FILE *helpfile = 0;


int
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




