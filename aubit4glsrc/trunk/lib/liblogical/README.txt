When a report is run with Meta-data output, a report output file is generated which contains:
a header
each print statement, along with the data printed, where in the 4GL it was generated, and the block it was printed in.


This data can be used to modify the report into a series of alternate report outputs using a conversion routine.

The conversion normally consists of 3 parts


1) The layout description
This is a file describing how to interpret the input meta-data. The layout engine is the tool used to maintain this file.

2) The renderer
This is a program which takes the description file and the meta-data and produces the output.



Common Stuff
------------

The meta data is read from a file into a struct r_report structure using the 

	struct r_report *read_report_output(char *fname);

function



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


The header information is available, and the 'nblocks' variable indicates the number of 'blocks' in the report.
Each block :

struct r_report_block
{
  int line;
  char where;
  char *why;
  int rb;
  int nentries;
  struct r_report_block_entries *entries;
};


Is basically a "print" statement, with each item printed as a separate "entry".
The rb variable uniquely identifies the block.


The entries are stored as :

struct r_report_block_entries
{
  int page_no;
  int line_no;
  int col_no;
  int entry_id;
  char *string;
};


Where page_no, line_no and col_no are from the text report, entry_id is taken from the 4gl and is sequential within a block...




Renderer
--------

Renderers are expected to be written for the following outputs :
	CSV
	EXCEL
	HTML
	PDF
	TEXT
	XML

with a GUI report viewer also available.

The report viewer can be used in conjunction with the layout engine to design the layout description file.





Layout Engine
-------------

The layout engine consists of 3 components

1) The report viewer.
2) The generic layout engine program.
3) A specific layout file for the output type (some types may share a layout file)



