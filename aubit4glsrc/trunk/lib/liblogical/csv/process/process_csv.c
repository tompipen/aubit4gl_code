#include <stdlib.h>
#include <stdio.h>
#include "../../common/a4gl_lle.h"
int page_header = 0;

struct report_special
{
  int fill_in_later;
};


struct report_line_entry
{
  int type;
  union
  {
    char *txt;
    long rb_entry;
    struct report_special *special;
  }
  entry;
};

struct report_print_line
{
  int nentries;
  struct report_line_entry *entries;
};

struct report_print_blocks
{
  char where;
  char *why;
  int nlines;
  struct report_print_line *lines;
};



int
read_definition_file (char *fname)
{
  // 
}


struct rb_strings
{
  int nstrings;
  char **strings;
};


int nstrings = 0;
struct rb_strings *strings = 0;


int *block_list=0;
int block_list_cnt=0;

void ensure_block_is_in_list(int bid) {
int a;
for (a=0;a<block_list_cnt;a++) {
	if (block_list[a]==bid) return;
}
block_list_cnt++;
block_list=realloc(block_list,sizeof(int)*block_list_cnt);
block_list[block_list_cnt-1]=bid;
}



/* Clear down the list as we have some new ones... */
clr_rbstrings(int rb) {
int a;
	if (rb>=nstrings) return;
	for (a=0;a<strings[rb].nstrings;a++) {
		free(strings[rb].strings[a]);
	}
	strings[rb].nstrings=0;
	free(strings[rb].strings);
	strings[rb].strings=0;
}




void
add_rbstring (int rb, int entry, char *s)
{
  while (rb >= nstrings)
    {
      nstrings++;
      strings = realloc (strings, sizeof (struct rb_strings) * nstrings);
      strings[nstrings - 1].nstrings = 0;
      strings[nstrings - 1].strings = 0;
    }

  while (entry >= strings[rb].nstrings)
    {
      strings[rb].nstrings++;
      strings[rb].strings =
	realloc (strings[rb].strings, sizeof (char *) * strings[rb].nstrings);
      strings[rb].strings[strings[rb].nstrings - 1] = 0;
    }
  strings[rb].strings[entry] = s;
}



print_all_rbstrings() {
int a,b;
int bid;
int cnt;
print_row_start("All");
cnt=0;
for (a=0;a<block_list_cnt;a++) {
	bid=block_list[a];
	for (b=0;b<strings[bid].nstrings;b++) {
		if (strings[bid].strings[b])  {
			print_cell(cnt++,strings[bid].strings[b]);
		} else {
			print_cell(cnt++,"");
		}
		
	}
}
print_row_end();
}

struct element
{
  int rb;
  int entry;
  int print_line;
};

struct element_list
{
  int nelements;
  struct element *elements;
};






print_row_start (char *why)
{
}

print_row_end ()
{
  printf ("\n");
}


print_cell (int d, char *s)
{
  if (d)
    printf (",%s", s);
  else
    printf ("%s", s);
}

add_page_header_details (struct r_report_block *block)
{
  int entry;
  print_row_start ("PAGE HEADER");

  for (entry = 0; entry < block->nentries; entry++)
    {
      print_cell (entry, block->entries[entry].string);
    }
  print_row_end ();
}




setup_data (int block, struct r_report_block *b)
{
  int a;

  ensure_block_is_in_list(block);

  clr_rbstrings(block);
  for (a = 0; a < b->nentries; a++)
    {
      add_rbstring (block, b->entries[a].entry_id,b->entries[a].string);
    }
}


void
process_report (FILE * fout, struct r_report *r)
{
  int a;
  int block;
  int entry;
  char w;
  int was_every;
  struct r_report_block_entries *centry;
  was_every = 0;

  printf ("%d blocks\n", r->nblocks);

  for (block = 0; block < r->nblocks; block++)
    {
      w = r->blocks[block].where;
      //printf ("Block=%d w=%c\n", block, w);

      if (w == 'a' || w == 'A')
	{
	  // We'll ignore After groups for now - they are normally for subtotals anyway...
	  //
	  continue;
	}

      if (w == 'p' || w == 'P')
	{
	  if (page_header)
	    continue;

	  add_page_header_details (&r->blocks[block]);
	  page_header = 1;
	continue;
	}

      if (w == 'b' || w == 'B')
	{
	  setup_data (r->blocks[block].rb, &r->blocks[block]);
	  continue;
	}

      if (w != 'E')
	{
	  printf ("Unexpected block type : %c\n", w);
	  exit (3);
	}

        setup_data (r->blocks[block].rb, &r->blocks[block]);
	print_all_rbstrings();

    }
}
