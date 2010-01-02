When a report is run with Meta-data output, a report output file is generated which contains:



	*) a header

	*) each print statement, along with the data printed, where in the 4GL it was generated, 
           and the block it was printed in.


This data can be used to modify the report into a series of alternate report outputs using a conversion routine.



The conversion normally consists of 3 parts


1) The layout description
	This is a file describing how to interpret the input meta-data. The layout engine is the tool used to maintain this file.

2) The renderer
	This is a program which takes the description file and the meta-data and produces the output.

3) The source meta-data





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



Each renderer requires two parts :
	A layout engine library
	A render engine library






Layout Engine
-------------

The layout engine consists of 4 components

1) The report viewer.
2) The generic layout engine program.
3) A specific layout engine library for the specified type
4) A specific layout file for the output type (some types may share a layout file)



Specific Layout Engine Library
------------------------------

The specific layout engine library would normally be written to use GTK to aid layouts - as thats what the report viewer
and layout engine are written with.

Each library would be expected to handle the following calls :

	LR_default_file -> void
		Called when the 'File/Default' menu option is called

	LR_preview_file -> void
		Called when the 'File/Preview' menu option is called

	LR_show_layout_rest void* vbox -> void
		Called when the bulk of the layout engine window has been drawn
		vbox is a pregenerated gtk_vbox used to store the output for the layout

	LR_setup_entry int b int e void* evt void* label -> void
		This is called from the report viewer when it creates a new entry on a report view
		The b is the block (rb) id, the e is the entry id, evt is an event box which contains a label, label is the label on the report viewer
		
	LR_setup_block int b void* evt void* label -> void
		This is called from the report viewer when it creates a new block on a report view (the '>' on the left hand side)
		The b is the block (rb) id, evt is an event box which contains a label, label is the label on the report viewer

	LR_save_file FILE* fout -> int
		This is called to save the specific report layout details
		(Returns 1 for ok, 0 for failure)

	LR_load_file FILE* fin -> int
		This is called to load the specific report layout details 
		(Returns 1 for ok, 0 for failure)
		This should also populate anything generated using the LR_show_layout_rest
		



The layout engine provides a few useful functions/variables:

	void msgbox(char *title,char *txt) ;

		Displays a message box with an 'OK' button


The simplest report layout library would thus be something like :


	void LR_default_file() {
        	msgbox("Cannot create default","There are no configurable options to create a default file for!");
	}
	
	
	void LR_preview_file() {
        	msgbox("Cannot Preview","Use the report viewer as a preview");
	}
	
	
	void LR_show_layout_rest(void *sb) {
        	gtk_container_add(sb,gtk_label_new("No configurable options"));
	}
	

	void LR_setup_entry(int b,int e, void *evt, void *label) {
        	//
	}
	
	
	void LR_setup_block(int b, void *evt, void *label) {
        	//
	}
	
	int LR_save_file(FILE *fin) {
        	// We don't need to add anything to the output file
        	return 1;
	}
	
	int LR_load_file(FILE *fin) {
        	// We don't need to add anything to the output file
        	return 1;
	}


As there are no configurable options for the TXT output - this is the layout library for the TXT renderer...

