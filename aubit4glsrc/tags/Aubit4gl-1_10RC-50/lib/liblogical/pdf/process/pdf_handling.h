// Fake music score rule
#define STYLE_NONE 0
#define STYLE_5BAR 1
#define STYLE_RECTANGLE 2

void setupPageSize(int w);
void start_pdf_page (PDF * p, int w, int h);
int select_font_for(int block,int entry) ;
void output_page (PDF * p, int w, int h, char **lines);
