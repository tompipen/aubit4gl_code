LIBRARY EXREPORT
VARIABLE A4GL_PDFTYPE

/* void A4GL_pdf_rep_print (void *rep, int a, int s, int right_margin) */
/* void A4GL_pdf_fputmanyc (FILE * f, int c, int cnt) */
/* void A4GL_pdf_set_column (void *rep) */
/* void A4GL_pdf_skip_to (void *rep, double a) */
/* void A4GL_pdf_skip_by (void *rep, double a) */
/* void A4GL_pdf_aclfgli_skip_lines (void *rep) */
/* void A4GL_pdf_need_lines (void *rep) */
/* void A4GL_pdf_skip_top_of_page (void *rep) */
/* void A4GL_pdf_set_info (void *p,char *creator)  */
/* void A4GL_pdf_rep_close (void *p) */
/* double A4GL_pdf_size (double f, char c, struct pdf_rep_structure *p) */
/* void A4GL_pdf_pdffunc (void *p, char *fname, int n) */
/* void A4GL_pdf_blob_print (void *p, void *blob, char *type, int cr) */


A4GL_pdf_rep_print void* rep, int a, int s, int right_margin,int why  -> void
A4GL_pdf_fputmanyc FILE* f, int c, int cnt -> void
A4GL_pdf_set_column void* rep -> void
A4GL_pdf_skip_to void* rep, double a -> void
A4GL_pdf_skip_by void* rep, double a -> void
A4GL_pdf_aclfgli_skip_lines void* rep -> void
A4GL_pdf_need_lines void* rep -> void
A4GL_pdf_skip_top_of_page void* rep -> void
A4GL_pdf_set_info void* p,char* creator  -> void
A4GL_pdf_rep_close void* p -> void
A4GL_pdf_size double f, char c, void* p -> double
A4GL_pdf_pdffunc void* p, char* fname, int n -> int
A4GL_pdf_blob_print void* p, void* blob, char* type, int cr -> void

