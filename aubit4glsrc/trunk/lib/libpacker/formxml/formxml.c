
#include "a4gl_libaubit4gl.h"


FILE *ofile;
void write_xml_form(char *fname, struct_form *f) ;
static char *get_sql_dtype ( int dtype);
void print_label_attr(struct_form *f, int metric_no, int attr_no,int oldstyle,char*why) ;
void print_buttonedit_attr(struct_form *f, int metric_no, int attr_no,int oldstyle,char*why) ;
void print_dateedit_attr(struct_form *f, int metric_no, int attr_no,int oldstyle,char*why) ;
void print_textedit_attr(struct_form *f, int metric_no, int attr_no,int oldstyle,char*why) ;
void print_entry (struct_form *f, int metric_no, int attr_no,char *why) ;
void print_unknown_widget_attr(struct_form *f, char *widget, int metric_no, int attr_no,int oldstyle,char *why) ;
void dump_layout(struct_form *f, struct s_layout *layout) ;

enum e_scrmodes {
	SCRMODE_GRID,
	SCRMODE_SCREEN
};
void dump_screen (struct_form * f, int scr, enum e_scrmodes scrmode,char *extra);

int printed_attributes[1000];
  static int tabIndex = 0;
  static int fieldNo = 0;
//int attributeFieldIDRef[1000];

int nprintedattributes=0;


/**
 *  *
 *   * @todo Describe function
 *    */
int
A4GLPACKER_initlib (void)
{
  return 1;
}

/**
 *  *
 *   * @todo Describe function
 *    */
int
A4GLPacker_A4GL_can_pack_all (char *name)
{
    return 1;
}

/*
 *    We don't need to worry about these two functions
 *       as we're doing the whole thing in one go using xdr
 *       */
int
A4GLPacker_A4GL_open_packer (char *fname, char dir,char *packname)
{
  return 1;
}

void
A4GLPacker_A4GL_close_packer (char dir)
{
  return;
}

/**
 *  *
 *   * @todo Describe function
 *    */
int
A4GLPacker_A4GL_pack_all (char *name, void *s, char *filename)
{

        if (strcmp(name,"struct_form")==0) {
                char buff[256];
                char *override;
                override=acl_getenv_not_set_as_0("OVERRIDE_OUTPUT");

                if (override) {
                        strcpy(buff,override);
                } else {
                        if (!A4GL_env_option_set ("A4GL_LOCALOUTPUT")) {
                                strcpy(buff,filename);
                        } else {
                                char *ptr;
                              ptr = filename;
                                if (rindex (ptr, '/')) {
                                        ptr = rindex (ptr, '/') + 1;
                                }
                                strcpy(buff,ptr);

                        }
                        strcat(buff,".xml");
                }
                ofile=fopen(buff,"wb");

                if (ofile) {
                        int c;
                        fprintf(ofile,"<?xml version=\"1.0\" encoding=\"utf-8\"?>\n");
                        int b=0;
			write_xml_form(filename, s);
                        fclose(ofile);
                } else {
                        return 0;
                }
        return 1;
        }


	A4GL_assertion(1,"Unhandled datatype for FORMXML packer");
	return 0;
}

int A4GLPacker_A4GL_pack_remove_file(char *fname) {
        char buff[512];
        sprintf (buff, "%s.xml",fname);
        return A4GL_delete_file(buff);
}

int hasPrintedAttribute(int n) {
int a;
	for (a=0;a<nprintedattributes;a++) {
		if (printed_attributes[a]==n) return 1;
	}
	return 0;
}

void addPrintedAttribute(int n) {
	if (hasPrintedAttribute(n)) return;

	nprintedattributes++;
	printed_attributes[nprintedattributes-1]=n;
}

int getNumberOfScreens(struct_form *f) {
	int a;
	int scr_no=-1;
	for (a=0;a<f->metrics.metrics_len;a++) {
		if (f->metrics.metrics_val[a].scr>scr_no) {
			scr_no=f->metrics.metrics_val[a].scr;
		}
	}
	return scr_no;
}


// Get the screen dimentioned for the specified screen...
void get_screen_size_dims(struct_form *f, int scr, int *width , int *height) {
int mw=0;
int mh=0;
int a;
        for (a=0;a<f->metrics.metrics_len;a++) {
		if (f->metrics.metrics_val[a].scr!=scr)  continue;
		if (f->metrics.metrics_val[a].y>mh) { mh=f->metrics.metrics_val[a].y; }
		if (f->metrics.metrics_val[a].x+ f->metrics.metrics_val[a].w>mw) { mw=f->metrics.metrics_val[a].x+ f->metrics.metrics_val[a].w; }

        }
	*width=mw;
	*height=mh+1;

}


// Check if a label is just a horizontal line..
int isline(char *s) {
int a;
for (a=0;a<strlen(s);a++) {
	if (s[a]!='-') return 0;
}
return 1;
}



// Flesh this out later ;-)
char *xml_escape(char *s) {
	return s;
}



// Check if a field uses a specified metric
int is_metric(struct_form *f, int field_no, int metric_no) {
int b;
      for (b = 0; b < f->fields.fields_val[field_no].metric.metric_len; b++)
        {
		if (f->fields.fields_val[field_no].metric.metric_val[b]==metric_no) {
				return 1;
		} 
        }
	return 0;
}


void get_attribs(struct_form *f, int attr_no, char *buff,int mode) {
struct struct_scr_field *fprop;
char smbuff[200];
strcpy(buff, "");
int formonly;

fprop=&f->attributes.attributes_val[attr_no];

        if (strcmp(f->attributes.attributes_val[attr_no].tabname,"formonly")!=0) {
		formonly=1;
	} else {
		formonly=0;
	}

if (mode==0) { // FormField 
        if (formonly) {
		sprintf(smbuff," sqlType=\"%s\"", get_sql_dtype(f->attributes.attributes_val[attr_no].datatype+(f->attributes.attributes_val[attr_no].dtype_size<<16)));
		strcat(buff,smbuff);
	}
	if (A4GL_has_bool_attribute(fprop, FA_B_NOENTRY)) { strcat(buff, " noEntry=\"1\""); }
	if (A4GL_has_bool_attribute(fprop, FA_B_REQUIRED)) { strcat(buff, " required=\"1\""); }
	if (A4GL_has_bool_attribute(fprop, FA_B_HIDDEN)) { strcat(buff, " hidden=\"1\""); }
	if (f->attributes.attributes_val[attr_no].not_null) {
	 	strcat(buff, " notNull=\"1\""); 
	}

}

if (mode==1) { // the label/button/field itself
	if (A4GL_has_bool_attribute(fprop, FA_B_UPSHIFT)) { strcat(buff, " shift=\"up\""); }
	if (A4GL_has_bool_attribute(fprop, FA_B_DOWNSHIFT)) { strcat(buff, " shift=\"down\""); }
	if (A4GL_has_bool_attribute(fprop, FA_B_AUTONEXT)) { strcat(buff, " autoNext=\"1\""); }
	if (A4GL_has_str_attribute(fprop, FA_S_ACTION)) { sprintf(smbuff, " action=\"%s\"", A4GL_get_str_attribute (fprop, FA_S_ACTION)); strcat(buff,smbuff);}
	if (A4GL_has_str_attribute(fprop, FA_S_IMAGE)) { sprintf(smbuff, " image=\"%s\"", A4GL_get_str_attribute (fprop, FA_S_IMAGE)); strcat(buff,smbuff);}
	if (A4GL_has_str_attribute(fprop, FA_S_STYLE)) { sprintf(smbuff, " style=\"%s\"", A4GL_get_str_attribute (fprop, FA_S_STYLE)); strcat(buff,smbuff);}
	if (A4GL_has_str_attribute(fprop, FA_S_COMMENTS)) { sprintf(smbuff, " comments=\"%s\"", A4GL_get_str_attribute (fprop, FA_S_COMMENTS)); strcat(buff,smbuff);}
	if (A4GL_has_str_attribute(fprop, FA_S_PICTURE)) { sprintf(smbuff, " picture=\"%s\"", A4GL_get_str_attribute (fprop, FA_S_PICTURE)); strcat(buff,smbuff);}
	if (A4GL_has_str_attribute(fprop, FA_S_CONFIG)) { sprintf(smbuff, " config=\"%s\"", A4GL_get_str_attribute (fprop, FA_S_CONFIG)); strcat(buff,smbuff);}
	if (A4GL_has_bool_attribute(fprop, FA_B_SCROLL)) { strcat(buff, " scroll=\"1\""); }
	if (A4GL_has_bool_attribute(fprop, FA_B_WANTTABS)) { strcat(buff, " wantTabs=\"1\""); }
	if (A4GL_has_bool_attribute(fprop, FA_B_WANTNORETURNS)) { strcat(buff, " wantReturns=\"0\""); }
	if (A4GL_has_bool_attribute(fprop, FA_B_FONTPITCHFIXED)) { strcat(buff, " fontPitch=\"fixed\""); }
	if (A4GL_has_bool_attribute(fprop, FA_B_FONTPITCHVARIABLE)) { strcat(buff, " fontPitch=\"variable\""); }
}


}




int isLabel(struct_form *f,int attr_no) {
char *s;
struct struct_scr_field *fprop;
fprop=&f->attributes.attributes_val[attr_no];
	if (!A4GL_has_str_attribute(fprop, FA_S_WIDGET) && !A4GL_has_str_attribute(fprop, FA_S_WIDGETTYPE)) return 0;
	if (A4GL_has_str_attribute(fprop, FA_S_WIDGET)) {
		s= A4GL_get_str_attribute (fprop, FA_S_WIDGET);
		if (A4GL_aubit_strcasecmp(s,"label")==0) return 1;
	}
	if (A4GL_has_str_attribute(fprop, FA_S_WIDGETTYPE)) {
		s= A4GL_get_str_attribute (fprop, FA_S_WIDGETTYPE);
		if (A4GL_aubit_strcasecmp(s,"label")==0) return 1;
	}
return 0;
}




void print_widget(struct_form *f, int metric_no, int attr_no,char *why) {
char *old_style_widget=0;
char *new_style_widget=0;
struct struct_scr_field *fprop;
fprop=&f->attributes.attributes_val[attr_no];

if (A4GL_has_str_attribute(fprop, FA_S_WIDGET)) {
	old_style_widget=A4GL_get_str_attribute (fprop, FA_S_WIDGET);
}

if (A4GL_has_str_attribute(fprop, FA_S_WIDGETTYPE)) {
	new_style_widget=A4GL_get_str_attribute (fprop, FA_S_WIDGETTYPE);
}




if (new_style_widget) {
	if (A4GL_aubit_strcasecmp(new_style_widget,"label")==0) {
		print_label_attr(f,metric_no,attr_no,0,why);
		return;
	}
	if (A4GL_aubit_strcasecmp(new_style_widget,"ButtonEdit")==0) {
		print_buttonedit_attr(f,metric_no,attr_no,0,why);
		return;
	}
	if (A4GL_aubit_strcasecmp(new_style_widget,"DateEdit")==0) {
		print_dateedit_attr(f,metric_no,attr_no,0,why);
		return;
	}
	if (A4GL_aubit_strcasecmp(new_style_widget,"TextEdit")==0) {
		print_textedit_attr(f,metric_no,attr_no,0,why);
		return;
	}
	print_unknown_widget_attr(f,new_style_widget, metric_no,attr_no,0,why);
	return;

	//printf("Unhandled widget : %s\n", new_style_widget);
	//exit(2);
}


if (old_style_widget) {
	if (A4GL_aubit_strcasecmp(old_style_widget,"label")==0) {
		print_label_attr(f,metric_no,attr_no,1,why);
		return;
	}
	if (A4GL_aubit_strcasecmp(old_style_widget,"ButtonEdit")==0) {
		print_buttonedit_attr(f,metric_no,attr_no,1,why);
		return;
	}
	if (A4GL_aubit_strcasecmp(old_style_widget,"DateEdit")==0) {
		print_dateedit_attr(f,metric_no,attr_no,1,why);
		return;
	}
	if (A4GL_aubit_strcasecmp(old_style_widget,"TextEdit")==0) {
		print_textedit_attr(f,metric_no,attr_no,1,why);
		return;
	}
	print_unknown_widget_attr(f,old_style_widget, metric_no,attr_no,0,why);
	return;
	//printf("Unhandled widget : %s\n", old_style_widget);
	//exit(2);
}


print_entry(f,metric_no,attr_no,why);

}


void print_entry (struct_form *f, int metric_no, int attr_no,char *why) {
char buff[2000];
char posbuf[200];
	sprintf(posbuf," posY=\"%d\" posX=\"%d\" gridWidth=\"%d\"", f->metrics.metrics_val[metric_no].y, f->metrics.metrics_val[metric_no].x, f->metrics.metrics_val[metric_no].w);
	if (strcmp(why,"Table")==0) {
		strcpy(posbuf,""); // posX and posY are not used for tables...
	}

	if (A4GL_has_bool_attribute(&f->attributes.attributes_val[attr_no], FA_B_WORDWRAP)) {
		print_textedit_attr(f,metric_no,attr_no,2,why);
		return;
	}

	get_attribs(f, attr_no, buff,1);

	fprintf(ofile, "<Edit width=\"%d\" %s %s/>\n",
                        f->metrics.metrics_val[metric_no].w,
			buff, posbuf);

}

// Prints a field thats defined as a label widgettype
void print_buttonedit_attr(struct_form *f, int metric_no, int attr_no,int oldstyle,char *why) {
char *s;
char buff[2000];
 get_attribs(f, attr_no, buff,1);
char posbuf[200];
	sprintf(posbuf," posY=\"%d\" posX=\"%d\" gridWidth=\"%d\"", f->metrics.metrics_val[metric_no].y, f->metrics.metrics_val[metric_no].x, f->metrics.metrics_val[metric_no].w);
	if (strcmp(why,"Table")==0) {
		strcpy(posbuf,""); // posX and posY are not used for tables...
	}


	if (oldstyle) {
			fprintf(ofile, "<ButtonEdit %s width=\"%d\" %s />\n", buff, f->metrics.metrics_val[metric_no].w, posbuf);

        } else {
			fprintf(ofile, "<ButtonEdit %s width=\"%d\" %s/>\n", buff, f->metrics.metrics_val[metric_no].w, posbuf);
        }
	return ;
}


// Prints a field thats defined as a label widgettype
void print_unknown_widget_attr(struct_form *f, char *widget, int metric_no, int attr_no,int oldstyle,char *why) {
char *s;
char buff[2000];
 get_attribs(f, attr_no, buff,1);
char posbuf[200];
	sprintf(posbuf," posY=\"%d\" posX=\"%d\" gridWidth=\"%d\"", f->metrics.metrics_val[metric_no].y, f->metrics.metrics_val[metric_no].x, f->metrics.metrics_val[metric_no].w);
	if (strcmp(why,"Table")==0) {
		strcpy(posbuf,""); // posX and posY are not used for tables...
	}


	if (oldstyle) {
			fprintf(ofile, "<%s %s width=\"%d\" %s />\n",widget,  buff, f->metrics.metrics_val[metric_no].w, posbuf);

        } else {
			fprintf(ofile, "<%s %s width=\"%d\" %s/>\n", widget, buff, f->metrics.metrics_val[metric_no].w, posbuf);
        }
	return ;
}





// Prints a field thats defined as a label widgettype
void print_dateedit_attr(struct_form *f, int metric_no, int attr_no,int oldstyle,char *why) {
char *s;
char buff[2000];
char posbuf[200];
	sprintf(posbuf," posY=\"%d\" posX=\"%d\" ", f->metrics.metrics_val[metric_no].y, f->metrics.metrics_val[metric_no].x, f->metrics.metrics_val[metric_no].w);
	if (strcmp(why,"Table")==0) {
		strcpy(posbuf,""); // posX and posY are not used for tables...
	}
 get_attribs(f, attr_no, buff,1);

	if (oldstyle) {
			fprintf(ofile, "<DateEdit %s width=\"%d\" %s gridWidth=\"%d\"/>\n", 
				buff,
			f->metrics.metrics_val[metric_no].w, posbuf,
			f->metrics.metrics_val[metric_no].w);

        } else {
			fprintf(ofile, "<DateEdit %s width=\"%d\" gridWidth=\"%d\"/>\n", 
				buff,
				f->metrics.metrics_val[metric_no].w, posbuf,
				f->metrics.metrics_val[metric_no].w);
        }
	return ;
}

// Prints a field thats defined as a label widgettype
void print_textedit_attr(struct_form *f, int metric_no, int attr_no,int oldstyle,char *why) {
char *s;
char buff[2000];
char posbuf[200];
	sprintf(posbuf," posY=\"%d\" posX=\"%d\" ", f->metrics.metrics_val[metric_no].y, f->metrics.metrics_val[metric_no].x,  f->metrics.metrics_val[metric_no].w);
	if (strcmp(why,"Table")==0) {
		strcpy(posbuf,""); // posX and posY are not used for tables...
	}
        get_attribs(f, attr_no, buff,1);
 	if (strstr(buff, " scroll=")==0 && oldstyle!=2) { 
		// Seems to always have scroll=1
		strcat(buff," scroll=\"1\"");
	}
	if (f->metrics.metrics_val[metric_no].h!=1) {
		char smbuff[200];
		sprintf(smbuff," height=\"%d\"", f->metrics.metrics_val[metric_no].h);
		strcat(buff,smbuff);
	}

	if (oldstyle) {
			fprintf(ofile, "<TextEdit %s width=\"%d\" %s />\n", 
				buff,
			f->metrics.metrics_val[metric_no].w,posbuf);

        } else {
			fprintf(ofile, "<TextEdit %s width=\"%d\" %s />\n", 
				buff,
				f->metrics.metrics_val[metric_no].w, posbuf);
        }
	return ;
}


// Prints a field thats defined as a label widgettype
void print_label_attr(struct_form *f, int metric_no, int attr_no,int oldstyle,char *why) {
char *s;
char posbuf[200];
	sprintf(posbuf," posY=\"%d\" posX=\"%d\" ", f->metrics.metrics_val[metric_no].y, f->metrics.metrics_val[metric_no].x,  f->metrics.metrics_val[metric_no].w);
	if (strcmp(why,"Table")==0) {
		strcpy(posbuf,""); // posX and posY are not used for tables...
	}
	if (oldstyle) {
			fprintf(ofile, "<RipLABEL width=\"%d\" %s />\n", 
			f->metrics.metrics_val[metric_no].w,posbuf);

        } else {
			fprintf(ofile, "<Label width=\"%d\" %s />\n", 
				f->metrics.metrics_val[metric_no].w,posbuf);
        }
	return ;
}



int isInScreenArray(struct_form *f, int attr_no,int *dim,char *scrname) {
int a;
int b;
for (a=0;a<f->records.records_len;a++) {
	if (f->records.records_val[a].dim<=1) continue; // Single dimensions we dont care about..
	for (b=0;b<f->records.records_val[a].attribs.attribs_len;b++) {
		if (f->records.records_val[a].attribs.attribs_val[b]==attr_no) {
				*dim=f->records.records_val[a].dim;
				if (scrname) {
				strcpy(scrname,f->records.records_val[a].name);
				}
				return 1;
		}
	}
}
return 0;
}



void printRecordView(struct_form *f) {
int a;
int b;
for (a=0;a<f->records.records_len;a++) {
	fprintf(ofile,"<RecordView tabName=\"%s\">\n", f->records.records_val[a].name);
	for (b=0;b<f->records.records_val[a].attribs.attribs_len;b++) {
		int attr_no;
		attr_no=f->records.records_val[a].attribs.attribs_val[b];
		fprintf(ofile,"   <Link colName=\"%s\" fieldIdRef=\"%d\"/>\n", f->attributes.attributes_val[attr_no].colname,
				attr_no);
	}
	fprintf(ofile,"</RecordView>\n");
}
}

void
print_field_attribute (struct_form * f, int metric_no, int attr_no)
{
  char buff[2000];
  int dim;


  get_attribs (f, attr_no, buff, 0);

fieldNo=attr_no;
  if (isInScreenArray (f, attr_no, &dim,NULL))
    {

	if (hasPrintedAttribute(attr_no)) return;
	addPrintedAttribute(attr_no);
  tabIndex++;

//printf("field no = %d  attr_no=%d\n",fieldNo,attr_no);
  //if (!isLabel (f, attr_no)) { fieldNo++; }
	//attributeFieldIDRef[attr_no]=fieldNo;
      fprintf (ofile,
	       "<Matrix pageSize=\"%d\" name=\"%s.%s\" colName=\"%s\" fieldId=\"%d\" sqlTabName=\"%s\" %s tabIndex=\"%d\" >\n", dim,
	       f->attributes.attributes_val[attr_no].tabname, f->attributes.attributes_val[attr_no].colname,
	       f->attributes.attributes_val[attr_no].colname, fieldNo, f->attributes.attributes_val[attr_no].tabname, buff,
	       tabIndex);

      print_widget (f, metric_no, attr_no,"Matrix");

      fprintf (ofile, "</Matrix>\n");
    }
  else
    {
	if (hasPrintedAttribute(attr_no)) return;
	addPrintedAttribute(attr_no);

  tabIndex++;
  //if (!isLabel (f, attr_no)) { fieldNo++; }

	//attributeFieldIDRef[attr_no]=fieldNo;
      fprintf (ofile, "<FormField name=\"%s.%s\" colName=\"%s\" fieldId=\"%d\" sqlTabName=\"%s\" %s tabIndex=\"%d\" >\n",
	       f->attributes.attributes_val[attr_no].tabname,
	       f->attributes.attributes_val[attr_no].colname,
	       f->attributes.attributes_val[attr_no].colname,
	       fieldNo, f->attributes.attributes_val[attr_no].tabname, buff, tabIndex);

      print_widget (f, metric_no, attr_no,"FormField");

      fprintf (ofile, "</FormField>\n");
    }
  	//fieldNo++;
}


int get_attrno_for_metric(struct_form *f, int metric_no) {
int a;
int found=0;

for (a=0;a<f->attributes.attributes_len;a++) {
	//if ( f->attributes.attributes_val[a].field_no==0) continue;
	if (is_metric(f, f->attributes.attributes_val[a].field_no, metric_no)) {
		return a;
	}

}
return -1;
}


void print_field(struct_form *f, int metric_no) {
int a;
int found=0;

for (a=0;a<f->attributes.attributes_len;a++) {
	//if ( f->attributes.attributes_val[a].field_no==0) continue;
	if (is_metric(f, f->attributes.attributes_val[a].field_no, metric_no)) {
		// We've found our attribute..
		print_field_attribute(f, metric_no, a);
		found++;
		break;
	}
}
if (!found) {
	// probably a continuation - like a WORDWRAP...
	//A4GL_pause_execution();
	//printf("Unable to find metric %d\n", metric_no);
	//exit(2);
	return;
}
}


void get_layout_attribs(struct s_layout *layout, char *buff) {
int a;
char smbuff[200];
struct struct_scr_field fprop1;
struct struct_scr_field *fprop;

strcpy(buff,"");
	if (layout->attrib==0) return;
	fprop=&fprop1;
	fprop1.bool_attribs.bool_attribs_len=layout->attrib->bool_attribs.bool_attribs_len;
	fprop1.bool_attribs.bool_attribs_val=layout->attrib->bool_attribs.bool_attribs_val;
	
	fprop1.str_attribs.str_attribs_len=layout->attrib->str_attribs.str_attribs_len;
	fprop1.str_attribs.str_attribs_val=layout->attrib->str_attribs.str_attribs_val;


	if (A4GL_has_bool_attribute(fprop, FA_B_NOENTRY)) { strcat(buff, " noEntry=\"1\""); }
	if (A4GL_has_bool_attribute(fprop, FA_B_REQUIRED)) { strcat(buff, " required=\"1\""); }
	if (A4GL_has_bool_attribute(fprop, FA_B_HIDDEN)) { strcat(buff, " hidden=\"1\""); }
	if (A4GL_has_bool_attribute(fprop, FA_B_UPSHIFT)) { strcat(buff, " shift=\"up\""); }
	if (A4GL_has_bool_attribute(fprop, FA_B_DOWNSHIFT)) { strcat(buff, " shift=\"down\""); }
	if (A4GL_has_bool_attribute(fprop, FA_B_AUTONEXT)) { strcat(buff, " autoNext=\"1\""); }
	if (A4GL_has_str_attribute(fprop, FA_S_ACTION)) { sprintf(smbuff, " action=\"%s\"", A4GL_get_str_attribute (fprop, FA_S_ACTION)); strcat(buff,smbuff);}
	if (A4GL_has_str_attribute(fprop, FA_S_IMAGE)) { sprintf(smbuff, " image=\"%s\"", A4GL_get_str_attribute (fprop, FA_S_IMAGE)); strcat(buff,smbuff);}
	if (A4GL_has_str_attribute(fprop, FA_S_STYLE)) { sprintf(smbuff, " style=\"%s\"", A4GL_get_str_attribute (fprop, FA_S_STYLE)); strcat(buff,smbuff);}
	if (A4GL_has_str_attribute(fprop, FA_S_COMMENTS)) { sprintf(smbuff, " comments=\"%s\"", A4GL_get_str_attribute (fprop, FA_S_COMMENTS)); strcat(buff,smbuff);}
	if (A4GL_has_str_attribute(fprop, FA_S_PICTURE)) { sprintf(smbuff, " picture=\"%s\"", A4GL_get_str_attribute (fprop, FA_S_PICTURE)); strcat(buff,smbuff);}
	if (A4GL_has_str_attribute(fprop, FA_S_CONFIG)) { sprintf(smbuff, " config=\"%s\"", A4GL_get_str_attribute (fprop, FA_S_CONFIG)); strcat(buff,smbuff);}
	if (A4GL_has_bool_attribute(fprop, FA_B_SCROLL)) { strcat(buff, " scroll=\"1\""); }
	if (A4GL_has_bool_attribute(fprop, FA_B_WANTTABS)) { strcat(buff, " wantTabs=\"1\""); }
	if (A4GL_has_bool_attribute(fprop, FA_B_WANTNORETURNS)) { strcat(buff, " wantReturns=\"0\""); }
	if (A4GL_has_bool_attribute(fprop, FA_B_FONTPITCHFIXED)) { strcat(buff, " fontPitch=\"fixed\""); }
	if (A4GL_has_bool_attribute(fprop, FA_B_FONTPITCHVARIABLE)) { strcat(buff, " fontPitch=\"variable\""); }

}

void dump_vbox(struct_form *f, struct s_layout *layout) {
char buff[2000];
int a;
	get_layout_attribs(layout,buff);
	fprintf(ofile,"<VBox %s>\n",buff);
	for (a=0;a<layout->children.children_len;a++) {
		dump_layout(f, layout->children.children_val[a]);
	}
	fprintf(ofile,"</VBox>\n");
}

void dump_hbox(struct_form *f, struct s_layout *layout) {
char buff[2000];
int a;
	get_layout_attribs(layout,buff);
	fprintf(ofile,"<HBox %s>\n",buff);
	for (a=0;a<layout->children.children_len;a++) {
		dump_layout(f, layout->children.children_val[a]);
	}
	fprintf(ofile,"</HBox>\n");
}

void dump_grid(struct_form *f, struct s_layout *layout) {
char buff[2000];
int a;
	
	get_layout_attribs(layout,buff);
	if (layout->children.children_len!=0) {
		A4GL_assertion(1,"not expecting children in a grid");
	}
	dump_screen (f, layout->screen_no, SCRMODE_GRID,buff);
}

void dump_table(struct_form *f, struct s_layout *layout) {
char buff[2000];
int a;
int scr;
int dim=-1;
char scrname[200];
	
	get_layout_attribs(layout,buff);

 	scr=layout->screen_no;
	if (layout->children.children_len!=0) {
		A4GL_assertion(1,"not expecting children in a table");
	}

  for (a = 0; a < f->metrics.metrics_len; a++) {
		int attr_no;
      		if (f->metrics.metrics_val[a].scr != scr) continue;
		if (strlen(f->metrics.metrics_val[a].label)) continue;
		attr_no=get_attrno_for_metric(f,a);
		if (isInScreenArray (f, attr_no, &dim,scrname)) {
			break;
		}
   }
   if (dim<=1) {
		printf("Unable to get table size");
		exit(2);
   }
		


    	fprintf (ofile, "<Table pageSize=\"%d\" tabName=\"%s\">\n",dim, scrname);


  for (a = 0; a < f->metrics.metrics_len; a++) {
		int attr_no;
      		if (f->metrics.metrics_val[a].scr != scr) continue;
		if (strlen(f->metrics.metrics_val[a].label)) continue;
		attr_no=get_attrno_for_metric(f,a);
		if (hasPrintedAttribute(attr_no)) continue;
		addPrintedAttribute(attr_no);
  		tabIndex++;
      		fprintf (ofile, "<TableColumn name=\"%s.%s\" colName=\"%s\" fieldId=\"%d\" sqlTabName=\"%s\" %s tabIndex=\"%d\" >\n", 
	       			f->attributes.attributes_val[attr_no].tabname, f->attributes.attributes_val[attr_no].colname,
	       			f->attributes.attributes_val[attr_no].colname, fieldNo, f->attributes.attributes_val[attr_no].tabname, buff,
	       			tabIndex);

      		print_widget (f, a, attr_no,"Table");

      		fprintf (ofile, "</TableColumn>\n");
   }
  fprintf (ofile, "</Table>\n");
	
}


void dump_layout(struct_form *f, struct s_layout *layout) {
	switch (layout->layout_type) {
		case LAYOUT_GRID:
			dump_grid(f,layout);
			break;
        	case LAYOUT_HBOX:
			dump_hbox(f,layout);
			break;
        	case LAYOUT_VBOX:
			dump_vbox(f,layout);
			break;
        	case LAYOUT_GROUP:
			dump_group(f,layout);
			break;
        	case LAYOUT_FOLDER:
			dump_folder(f,layout);
			break;
        	case LAYOUT_PAGE:
			dump_page(f,layout);
			break;
        	case LAYOUT_TABLE:
			dump_table(f,layout);
			break;
        	case LAYOUT_NOTSET:
			A4GL_assertion(1,"Layout not set");
			break;
	}
}


void dump_form_layout(struct_form *f) {
 	dump_layout(f, f->layout);
}


void
dump_screen (struct_form * f, int scr, enum e_scrmodes scrmode,char *extra)
{
  int mw = 0;
  int a;
  int mh = 0;
  get_screen_size_dims (f, scr, &mw, &mh);

  switch (scrmode) {
	case SCRMODE_SCREEN:
      		fprintf (ofile, "<Screen width=\"%d\" height=\"%d\">\n", mw, mh);
			break;

	case SCRMODE_GRID:
      		fprintf (ofile, "<Grid width=\"%d\" height=\"%d\">\n", mw, mh);
			break;
    }

  for (a = 0; a < f->metrics.metrics_len; a++)
    {
      if (f->metrics.metrics_val[a].scr != scr)
	continue;
      if (strlen (f->metrics.metrics_val[a].label))
	{
	  if (isline (f->metrics.metrics_val[a].label))
	    {
	      fprintf (ofile, "<HLine posY=\"%d\" posX=\"%d\" gridWidth=\"%d\"/>\n", f->metrics.metrics_val[a].y,
		       f->metrics.metrics_val[a].x, strlen (f->metrics.metrics_val[a].label));
	    }
	  else
	    {
	      fprintf (ofile, "<Label text=\"%s\" posY=\"%d\" posX=\"%d\" gridWidth=\"%d\"/>\n",
		       xml_escape (f->metrics.metrics_val[a].label), f->metrics.metrics_val[a].y, f->metrics.metrics_val[a].x,
		       strlen (f->metrics.metrics_val[a].label));
	    }
	}
      else
	{
	  // Its a field...
	  print_field (f, a);
	}
    }

   switch(scrmode) {
	case SCRMODE_SCREEN:
      		fprintf (ofile, "</Screen>\n");
		break;
  	case SCRMODE_GRID:
      		fprintf (ofile, "</Grid>\n");
		break;
    }
}





void dump_form_screen(struct_form *f) {
int scr;
int max_scr;

max_scr=getNumberOfScreens(f);
A4GL_assertion(max_scr<0,"No screens");

for (scr=1; scr<=max_scr;scr++) {
	dump_screen(f,scr,SCRMODE_SCREEN,"");
#ifdef MOVED
	get_screen_size_dims(f, scr, &mw,&mh);
	fprintf(ofile,"<Screen width=\"%d\" height=\"%d\">\n",  mw,mh);
	for (a=0;a<f->metrics.metrics_len;a++) { 	
		if (f->metrics.metrics_val[a].scr!=scr)  continue;
		if (strlen(f->metrics.metrics_val[a].label)) {
			if (isline(f->metrics.metrics_val[a].label)) {
				fprintf(ofile,"<HLine posY=\"%d\" posX=\"%d\" gridWidth=\"%d\"/>\n",f->metrics.metrics_val[a].y, f->metrics.metrics_val[a].x, strlen(f->metrics.metrics_val[a].label));
			} else {
				fprintf(ofile,"<Label text=\"%s\" posY=\"%d\" posX=\"%d\" gridWidth=\"%d\"/>\n",xml_escape(f->metrics.metrics_val[a].label), f->metrics.metrics_val[a].y, f->metrics.metrics_val[a].x, strlen(f->metrics.metrics_val[a].label));
			}
		} else {
			// Its a field...
			print_field(f, a);
		}
	}
	fprintf(ofile,"</Screen>\n");
#endif
}
}




void write_xml_form(char *fname, struct_form *f) {
	fprintf(ofile,"<Form name=\"%s\" sqlDbName=\"%s\" width=\"%d\" height=\"%d\" delimiters=\"%s\">\n",fname, f->dbname, f->maxcol, f->maxline, f->delim);
	if (f->layout==0) {
		// Its a screen not a layout
		dump_form_screen(f);
	} else {
		dump_form_layout(f);
	}
	printRecordView(f);
 	fprintf(ofile,"</Form>\n");
				
}







static char *
decode_dt (int a, int b)
{
  static char buff1[200];
  static char buff2[200];
  int c;
  if (a == 0)
    {
      if (b == 1)
	return "YEAR";
      return "SECOND";
    }

  if (b == 1)
    {
      c = a >> 4;
      sprintf (buff1, "%x %x (b=%d)", c, a, b);
      switch (c)
	{
	case 1:
	  strcpy (buff1, "YEAR");
	  break;
	case 2:
	  strcpy (buff1, "MONTH");
	  break;
	case 3:
	  strcpy (buff1, "DAY");
	  break;
	case 4:
	  strcpy (buff1, "HOUR");
	  break;
	case 5:
	  strcpy (buff1, "MINUTE");
	  break;
	case 6:
	  strcpy (buff1, "SECOND");
	  break;
	case 7:
	  strcpy (buff1, "FRACTION(1)");
	  break;
	case 8:
	  strcpy (buff1, "FRACTION(2)");
	  break;
	case 9:
	  strcpy (buff1, "FRACTION(3)");
	  break;
	case 10:
	  strcpy (buff1, "FRACTION(4)");
	  break;
	case 11:
	  strcpy (buff1, "FRACTION(5)");
	  break;
	}
      return buff1;
    }
  else
    {
      c = a & 0xf;
      sprintf (buff2, "%x %x (b=%d)", c, a, b);
      switch (c)
	{
	case 1:
	  strcpy (buff2, "YEAR");
	  break;
	case 2:
	  strcpy (buff2, "MONTH");
	  break;
	case 3:
	  strcpy (buff2, "DAY");
	  break;
	case 4:
	  strcpy (buff2, "HOUR");
	  break;
	case 5:
	  strcpy (buff2, "MINUTE");
	  break;
	case 6:
	  strcpy (buff2, "SECOND");
	  break;
	case 7:
	  strcpy (buff2, "FRACTION(1)");
	  break;
	case 8:
	  strcpy (buff2, "FRACTION(2)");
	  break;
	case 9:
	  strcpy (buff2, "FRACTION(3)");
	  break;
	case 10:
	  strcpy (buff2, "FRACTION(4)");
	  break;
	case 11:
	  strcpy (buff2, "FRACTION(5)");
	  break;
	}
      return buff2;
    }
}

static char *
decode_ival_define1 (int n)
{
  static char buff[256];
  int l;

  if (n == 0x602)
    return "YEAR";
  if (n == 0x84a)
    return "DAY";
  if (n == 0xa6d)
    return "HOUR(3)";

  //printf("-->%x (n==0x602)=%d \n",n, n==0x602);

  l = (n >> 8) & 0xf;
  if (l == 6)
    {
      switch ((n >> 4) & 0xf)
	{
	case 1:
	  return "YEAR";
	case 2:
	  return "MONTH";
	case 3:
	  return "DAY";
	case 4:
	  return "HOUR";
	case 5:
	  return "MINUTE";
	case 6:
	  return "SECOND";
	case 7:
	  return "FRACTION(1)";
	case 8:
	  return "FRACTION(2)";
	case 9:
	  return "FRACTION(3)";
	case 10:
	  return "FRACTION(4)";
	case 11:
	  return "FRACTION(5)";
	}
    }
  else
    {
      switch ((n >> 4) & 0xf)
	{
	case 1:
	  sprintf (buff, "YEAR(%d)", l);
	  return buff;
	case 2:
	  sprintf (buff, "MONTH(%d)", l);
	  return buff;
	case 3:
	  sprintf (buff, "DAY(%d)", l);
	  return buff;
	case 4:
	  sprintf (buff, "HOUR(%d)", l);
	  return buff;
	case 5:
	  sprintf (buff, "MINUTE(%d)", l);
	  return buff;
	case 6:
	  sprintf (buff, "SECOND(%d)", l);
	  return buff;

	}

    }
  A4GL_assertion (1, "Unknown CURRENT 9.1");
  return "";
}


static char *
decode_ival_define2 (int n)
{
  if (n == 0x602)
    return "MONTH";
  if (n == 0x84a)
    return "SECOND";
  if (n == 0xa6d)
    return "FRACTION(3)";
  switch (n & 0xf)
    {
    case 1:
      return "YEAR";
    case 2:
      return "MONTH";
    case 3:
      return "DAY";
    case 4:
      return "HOUR";
    case 5:
      return "MINUTE";
    case 6:
      return "SECOND";
    case 7:
      return "FRACTION(1)";
    case 8:
      return "FRACTION(2)";
    case 9:
      return "FRACTION(3)";
    case 10:
      return "FRACTION(4)";
    case 11:
      return "FRACTION(5)";
    }
  A4GL_assertion (1, "Unknown CURRENT 8.1");
  return "";
}



static char * get_sql_dtype ( int dtype)
{
  int a;
  int cnt;
  char buff[256];
  static char buff_dtype[256];
  int dtype_sz;

  dtype_sz = dtype >> 16;
  dtype = dtype & 0xffff;
  switch (dtype)
    {
    case DTYPE_CHAR:
      sprintf (buff_dtype, "CHAR(%d)", dtype_sz);
      break;
    case DTYPE_VCHAR:
      sprintf (buff_dtype, "VARCHAR(%d)", dtype_sz);
      break;
    case DTYPE_INT:
      sprintf (buff_dtype, "INTEGER");
      break;
    case DTYPE_SMINT:
      sprintf (buff_dtype, "SMALLINT");
      break;
    case DTYPE_DATE:
      sprintf (buff_dtype, "DATE");
      break;
    case DTYPE_FLOAT:
      sprintf (buff_dtype, "FLOAT");
      break;
    case DTYPE_SMFLOAT:
      sprintf (buff_dtype, "SMALLFLOAT");
      break;
    case DTYPE_SERIAL:
      sprintf (buff_dtype, "SERIAL");
      break;

    case DTYPE_DECIMAL:
      sprintf (buff_dtype, " DECIMAL(%d,%d)", dtype_sz >> 8, dtype_sz & 255);
      break;

    case DTYPE_DTIME:
      sprintf (buff_dtype, " DATETIME %s TO %s", decode_dt (dtype_sz, 1), decode_dt (dtype_sz, 2));
      break;

    case DTYPE_INTERVAL:
      sprintf (buff_dtype, " INTERVAL %s TO %s", decode_ival_define1 (dtype_sz), decode_ival_define2 (dtype_sz));
      break;


    default:
      printf ("Unhandled define in module variable removal... variable dtype : %d (%x)\n", dtype, dtype);
      A4GL_assertion (1, "Unhandled define in module variable removal...");

    }


return buff_dtype;


}

