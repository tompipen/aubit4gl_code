/*


Logical Layout Engine header file


*/

/*
-----------------------------------------------------------------------------
 PORTABLE
   Set if we are going to use network style integers
   Not set if we are going to use native integers
 (On some platforms these may be the same, on others they won't be)
-----------------------------------------------------------------------------
*/

#if (defined (PORTABLE) && ! defined (__MINGW32__)) || (defined (hpux))
	#include <netinet/in.h>
#else
	#ifndef htonl
		#define htonl(x) (x)
	#endif
	#ifndef htons
		#define htons(x) (x)
	#endif
	#ifndef ntohl
		#define ntohl(x) (x)
	#endif
	#ifndef ntohs
		#define ntohs(x) (x)
	#endif
#endif



#define ENTRY_START 1
#define ENTRY_BLOCK 2
#define ENTRY_BLOCK_END 3
#define ENTRY_DATA 4
#define ENTRY_ENTRY_START 5
#define ENTRY_ENTRY_END 6

struct r_report_block_entries
{
  int page_no;
  int line_no;
  int col_no;
  int entry_id;
  char *string;
};

struct r_report_block
{
  int line;
  char where;
  char *why;
  int rb;
  int nentries;
  struct r_report_block_entries *entries;
};

struct r_report
{
  int version_no;
  int ctime;
  int top_margin;
  int bottom_margin;
  int left_margin;
  int right_margin;
  int page_length;
  int max_page;
  int max_line;
  char *repName;
  char *modName;
  int max_col;
  int nblocks;
  struct r_report_block *blocks;
};

struct s_rbx
{
  int rb;
  char where;
  char *why;
  char *desc;
  int max_entry;
  int nentry_nos;
  int *entry_nos;
  int *max_size_entry;
};

struct r_report *read_report_output(char *fname);

void obtain_rbs_rbx(struct r_report *report, int *ptr_rbs, struct s_rbx **ptr_rbx);

int load_filter_file_header(char *fname, FILE **fin, char*msgbuff);
