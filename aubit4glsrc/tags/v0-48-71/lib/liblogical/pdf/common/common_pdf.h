#define PAPER_TYPE_A0 		0
#define PAPER_TYPE_A1 		1
#define PAPER_TYPE_A2 		2
#define PAPER_TYPE_A3 		3
#define PAPER_TYPE_A4 		4
#define PAPER_TYPE_A5 		5
#define PAPER_TYPE_A6 		6
#define PAPER_TYPE_B5 		7
#define PAPER_TYPE_LETTER 	8
#define PAPER_TYPE_LEGAL 	9
#define PAPER_TYPE_LEDGER 	10
#define PAPER_TYPE_P11x17 	11

#define PAPER_ORIENT_LANDSCAPE 	1
#define PAPER_ORIENT_PORTRAIT 	2
#define PAPER_ORIENT_AUTO 	3

struct pdf_layout {
	char fontname[100];
	int fontsize;
	float leftmargin;
	float topmargin;
	int paper_type;
	int paper_orient;
};
