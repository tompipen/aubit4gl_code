#include <stdio.h>
#define  _NO_WINDOWS_H_
#define NOSTRCPYMAP
#include "a4gl_libaubit4gl.h"
#include "../common/csv_io.h"
#include "../../common/a4gl_lle.h"
#include "../../processor/API_process.h"

//extern int rbs;
//extern struct s_rbx *rbx;

struct csv_report_layout *layout;

FILE *rep_fout = 0;


int
A4GLLOGREPPROC_initlib (void)
{
  return 1;
}



int
RP_default_file (void *report, char *buff, void *rbx, int rbs)
{
  layout = default_csv (buff, rbx, rbs);
  if (layout)
    return 1;
  else
    return 0;
}



int
RP_import_file (FILE * fin, FILE *fout)
{
  char buff[1024];
  int nblocks;
  char type[300] = "";
  int lineno = 0;
  char **cptr;
  int blockno;
int a;

  fgets (buff, sizeof (buff), fin);
  lineno++;
  cptr = RP_split_on_delimiter (buff, &a);
  if (a != 2)
    {
      printf ("Invalid header\n");
      return 0;
    }

  nblocks = atoi (cptr[1]);
  strcpy (type, cptr[0]);

  if (strcmp (type, "CSV") != 0)
    {
      printf ("Invalid input file - not a csv\n");
      return 0;
    }
  printf ("Blocks: %d\n", nblocks);
  layout = malloc (sizeof (struct csv_report_layout));
  layout->nblocks = nblocks;
  layout->blocks = malloc (nblocks * sizeof (struct csv_blocks));

  for (blockno = 0; blockno < nblocks; blockno++)
    {
      fgets (buff, sizeof (buff), fin);
      lineno++;
      //printf ("Process line %d : %s\n", lineno, buff);

      if (sscanf (buff, "%d|%d\n", &layout->blocks[blockno].nrows, &layout->blocks[blockno].ncols) != 2)
	{
	  printf ("Error reading block@ line %d\n", lineno);
	  return 0;
	}

      //printf ("...rows=%d cols=%d\n", layout->blocks[blockno].nrows, layout->blocks[blockno].ncols);
      int row;
      int col;

      layout->blocks[blockno].matrix = malloc (sizeof (struct csv_entry *) * layout->blocks[blockno].nrows);
      for (row = 0; row < layout->blocks[blockno].nrows; row++)
	{

	  layout->blocks[blockno].matrix[row] = malloc (sizeof(struct csv_entry)*layout->blocks[blockno].ncols);
	  for (col = 0; col < layout->blocks[blockno].ncols; col++)
	    {
	      struct csv_entry *ce;

	      ce = &layout->blocks[blockno].matrix[row][col];

	      fgets (buff, sizeof (buff), fin);
	      lineno++;
	      //printf ("Process line %d : %s\n", lineno, buff);

	      cptr = RP_split_on_delimiter (buff, &a);
	      //printf ("SPlit : %d\n", a);
	      a=8;
	      if (a != 8)
		{
			printf("Bad @ line %d\n", lineno);
			return 0;
		}
		row=0;
		col=0;
		ce->rb=0;
		ce->entry=0;

	      row = atoi (cptr[0]);
	      col = atoi (cptr[1]);
	      ce->rb = atoi (cptr[2]);
	      ce->entry = atoi (cptr[3]);

	      printf ("%d:%d:%d:%d:", row, col, ce->rb, ce->entry);

	      if (strlen (cptr[4]))
		{
		  ce->special = strdup (cptr[4]);
		  printf ("s=%s:", ce->special);
		}
	      else
		{
		  ce->special = 0;
		}
	      if (strlen (cptr[5]))
		{
		  ce->last_value = strdup (cptr[5]);
		  printf ("lv=%s:", ce->last_value);
		}
	      else
		{
		  ce->last_value = 0;
		}
	      if (strlen (cptr[6]))
		{
		  ce->fixed_text = strdup (cptr[6]);
		  printf ("ft=%s:", ce->fixed_text);
		}
	      else
		{
		  ce->fixed_text = 0;
		}
		printf("\n");
	    }
	}
    }
write_csv(fout,layout);
  return 1;
}

int
RP_dump_file (FILE * fin, FILE *fout)
{
  int a;
  layout = read_csv (fin);
  if (layout == 0)
    {
      return 0;
    }
  fprintf (fout, "CSV|%d\n", layout->nblocks);
  for (a = 0; a < layout->nblocks; a++)
    {
      fprintf (fout, "%d|%d\n", layout->blocks[a].nrows, layout->blocks[a].ncols);
      int row;
      int col;
      for (row = 0; row < layout->blocks[a].nrows; row++)
	{
	  for (col = 0; col < layout->blocks[a].ncols; col++)
	    {
	      struct csv_entry *ce;
	      ce = &layout->blocks[a].matrix[row][col];
	      fprintf (fout, "%d|%d|%d|%d|", row, col, ce->rb, ce->entry);


	      if (ce->special)
		{
		  fprintf (fout, "%s|", (ce->special));
		}
	      else
		{
		  fprintf (fout, "|");
		}
	      if (ce->last_value)
		{
		  fprintf (fout, "%s|", (ce->last_value));
		}
	      else
		{
		  fprintf (fout, "|");
		}
	      if (ce->fixed_text)
		{
		  fprintf (fout, "%s|", (ce->fixed_text));
		}
	      else
		{
		  fprintf (fout, "|");
		}
	      fprintf (fout, "\n");
	    }
	}
    }
  fclose (fout);
  return 1;
}

int
RP_load_file (void *report, FILE * fin)
{
  layout = read_csv (fin);
  if (layout == 0)
    {
      return 0;
    }
  return 1;
}


static void
start_block (int rb)
{
  int x;
  int y;
  int a;
  struct csv_blocks *block;
  struct csv_entry *centry;

//printf("Start block %d\n",rb);

  for (a = 0; a < layout->nblocks; a++)
    {
      block = &layout->blocks[a];
      // Lets clear everything down...
      for (y = 0; y < block->nrows; y++)
	{
	  centry = block->matrix[y];
	  for (x = 0; x < block->ncols; x++)
	    {
	      if (centry[x].rb == rb)
		{
		  //printf("Cleared %d\n",x);
		  centry[x].special = 0;

		  if (centry[x].fixed_text)
		    {
		      //printf("set %d to %s\n",x, centry[x].fixed_text);
		      centry[x].special = centry[x].fixed_text;
		    }
		}
	    }
	}
    }

}

static void
end_block (int rb, struct s_rbx *rbx)
{
  int a;
  int x;
  int y;
  int last;
  struct csv_blocks *block;
  struct csv_entry *centry;
  int printed = 0;

// First - we need to find our block to print...
  for (a = 0; a < layout->nblocks; a++)
    {
      if (rbx[a].rb != rb)
	continue;

      block = &layout->blocks[a];

      // We may need to print somethings...
      for (y = 0; y < block->nrows; y++)
	{
	  centry = block->matrix[y];
	  last = -1;

	  // First - find out how many cells are actually used...
	  for (x = 0; x < block->ncols; x++)
	    {

	      if (centry[x].special && strlen (centry[x].special) && centry[x].rb >= 0 && centry[x].entry >= 0)
		{
		  last = x;
		}
	    }

	  if (last != -1)
	    {
	      // Print all of these cells...
	      for (x = 0; x <= last; x++)
		{

		  if (x || y)
		    {
		      fprintf (rep_fout, ",");
		    }

		  if (centry[x].special && strlen (centry[x].special) && centry[x].rb >= 0 && centry[x].entry >= 0)
		    {
		      fprintf (rep_fout, "\"%s\"", centry[x].special);
		      printed++;
		    }
		  else
		    {
		      fprintf (rep_fout, "\"\"");
		      printed++;
		    }
		}
	    }
	}
    }
  if (printed)
    {
      fprintf (rep_fout, "\n");
    }

}


static void
process_block (int block_id, int entry_id, char *s)
{
  int a;
  int x;
  int y;
  struct csv_blocks *block;
  struct csv_entry *centry;


  for (a = 0; a < layout->nblocks; a++)
    {
      block = &layout->blocks[a];
      for (y = 0; y < block->nrows; y++)
	{
	  centry = block->matrix[y];
	  for (x = 0; x < block->ncols; x++)
	    {
	      if (centry[x].entry == entry_id && centry[x].rb == block_id)
		{
		  if (!centry[x].fixed_text)
		    centry[x].special = s;
		}
	    }
	}
    }


}

int
RP_process_report (void *vreport, char *buff, void *vrbx, int rbs)
{
  struct r_report *report;
  char fname[1024];
  int a;
  int b;
  struct s_rbx *rbx = 0;
  rbx = vrbx;
  report = vreport;
  rep_fout = 0;

  if (layout == 0 || report == 0)
    {
      // We're missing something..
      printf ("Missing layout or report : Layout=%p report=%p\n", layout, report);
      return 0;
    }

  // buff should contain a filename to store the output in or ""
  if (buff)
    {
      strcpy (fname, buff);
      A4GL_trim (fname);
    }
  else
    {
      strcpy (fname, "");
    }

  if (strlen (fname) == 0)
    {
      tmpnam (fname);
      strcpy (buff, fname);
      rep_fout = fopen (fname, "w");
    }
  else
    {
      if (strcmp (fname, "-") == 0)
	{
	  rep_fout = stdout;
	}
      else
	{
	  rep_fout = fopen (fname, "w");
	}
    }


  if (rep_fout == 0)
    {
      printf ("Can't open output : %s\n", fname);
      return 0;
    }
  // If we've got to here....

  //printf("Total of %d blocks\n", report->nblocks);
  for (a = 0; a < report->nblocks; a++)
    {
      if (report->blocks[a].nentries)
	{
	  start_block (report->blocks[a].rb);
	  for (b = 0; b < report->blocks[a].nentries; b++)
	    {
	      process_block (report->blocks[a].rb, report->blocks[a].entries[b].entry_id, report->blocks[a].entries[b].string);
	    }
	  end_block (report->blocks[a].rb, rbx);
	}
    }

  if (strcmp (buff, "-") != 0)
    {
      fclose (rep_fout);
    }
  return 1;
}
