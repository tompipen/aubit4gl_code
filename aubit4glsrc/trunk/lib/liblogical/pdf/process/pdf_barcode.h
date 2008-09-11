void generate_barcode(PDF *p, double xpos,double ypos,double x,double y,char *str,float p_page_height,int incl_text);

void generate_qrcode(PDF *p,char *str, double xpos,double ypos,double pdfwidth, double pdfheight,double p_page_height ) ;

void set_barcode_type(char *s) ;
